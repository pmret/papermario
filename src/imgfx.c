#include "common.h"
#include "ld_addrs.h"
#include "sprite.h"
#include "imgfx.h"

#if VERSION_IQUE
// TODO: remove if section is split in iQue release
extern Addr imgfx_data_ROM_START;
#endif

typedef union ImgFXIntVars {
    s32 raw[2][4];
    struct {
        s32 anim[4];
        s32 color[4];
    } args;
    // type-specific anim args (sharing first 0x10 bytes)
    struct {
        s32 type;
        s32 interval;   // always 1 or 2 in practice
        s32 step;       // always 1 in practice
    } anim;
    struct {
        Vec3i mag;
    } wavy;
    // type-specific color args (sharing second 0x10 bytes)
    struct {
        char unk_00[0x10];
        s32 r;
        s32 g;
        s32 b;
        s32 a;
    } color;
    struct {
        char unk_00[0x10];
        s32 mode;
        s32 noiseAmt;
        char unk_18[4];
        s32 alphaAmt;
    } hologram;
    struct {
        char unk_00[0x10];
        ImgFXOverlayTexture* pattern;
        s32 alpha;
    } overlay;
} ImgFXIntVars;

typedef union ImgFXFloatVars {
    f32 raw[2][4];
    // type-specific anim state (sharing first 0x10 bytes)
    struct {
        f32 curFrame;
        f32 curIdx;
    } anim;
    struct {
        f32 phase1;
        f32 phase2;
        f32 phase3;
    } wavy;
    // type-specific color state (sharing second 0x10 bytes)
    struct {
        char unk_00[0x10];
        f32 posX;
        f32 posY;
    } overlay;
} ImgFXFloatVars;

typedef struct ImgFXState {
    /* 0x00 */ u8 arrayIdx;
    /* 0x01 */ u8 meshType;
    /* 0x02 */ u8 renderType;
    /* 0x03 */ u8 subdivX;
    /* 0x04 */ u8 subdivY;
    /* 0x05 */ s8 lastAnimCmd;
    /* 0x06 */ s8 lastColorCmd;
    /* 0x07 */ char unk_07[0x1];
    /* 0x08 */ u16 firstVtxIdx;
    /* 0x0A */ u16 lastVtxIdx;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 nextIdx;
    /* 0x14 */ s32 flags;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ ImgFXIntVars ints;
    /* 0x3C */ ImgFXFloatVars floats;
    /* 0x5C */ Color_RGBA8* colorBuf;
    /* 0x60 */ u16 colorBufCount;
    /* 0x62 */ char unk_62[0x2];
    /* 0x64 */ u8* curAnimOffset;
    /* 0x68 */ Vtx* vtxBufs[2];
    /* 0x70 */ Gfx* gfxBufs[2];
    /* 0x78 */ s32 otherModeL;
} ImgFXState; // size = 0x7C

typedef struct ImgFXCacheEntry {
    /* 0x00 */ s32* data;
    /* 0x04 */ u8 staleCooldownTimer;
    /* 0x05 */ u8 usingContextualHeap;
    /* 0x06 */ char unk_06[0x2];
} ImgFXCacheEntry; // size = 0x8

enum ImgFXAnimFlags {
    IMGFX_ANIM_FLAG_ABSOLUTE_COORDS  = 1, // image-relative (in percent) when unset
};

typedef struct ImgFXRenderMode {
    /* 0x0 */ s32 mode1;
    /* 0x4 */ s32 mode2;
    /* 0x8 */ u8 flags; // only checks TRUE so far. some kind of switch?
} ImgFXRenderMode; // size = 0xC

typedef ImgFXState ImgFXInstanceList[MAX_IMGFX_INSTANCES];

extern HeapNode heap_spriteHead;

SHIFT_BSS ImgFXWorkingTexture ImgFXCurrentTexture;
SHIFT_BSS Vtx* ImgFXVtxBuffers[2];
SHIFT_BSS Vtx* imgfx_vtxBuf;
SHIFT_BSS ImgFXInstanceList* ImgFXInstances;
SHIFT_BSS s8 D_80156958[2];
SHIFT_BSS s32 D_80156960[2];
SHIFT_BSS s32 D_80156968[2];
SHIFT_BSS s8 D_80156970;
SHIFT_BSS ImgFXAnimHeader ImgFXAnimHeaders[MAX_IMGFX_INSTANCES];
SHIFT_BSS ImgFXCacheEntry ImgFXDataCache[8];

// Data
ImgFXWorkingTexture* ImgFXCurrentTexturePtr = &ImgFXCurrentTexture;

u16 imgfx_vtxCount = 0;

Lights2 ImgFXLights = gdSPDefLights2(144, 144, 144, 255, 255, 255, 0, 0, 120, 255, 255, 255, 0, 0, 136);

Vp D_8014EE40 = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 },
    }
};

Vp D_8014EE50 = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 512, 0 },
    }
};

u16 ImgFXVtxBufferCapacity = 300;

Gfx DefaultImgFXSetupGfx[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18,
                     G_AD_DISABLE | G_CD_DISABLE | G_TC_FILT | G_TF_BILERP | G_TP_PERSP),
    gsSPEndDisplayList(),
};

//TODO figure out bits
ImgFXRenderMode ImgFXRenderModes[] = {
    [IMGFX_RENDER_DEFAULT]               { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_MULTIPLY_RGB]          { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_MULTIPLY_ALPHA]        { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_MULTIPLY_RGBA]         { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_MODULATE_PRIM_RGB]     { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_MODULATE_PRIM_RGBA]    { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_MULTIPLY_SHADE_RGB]    { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_MULTIPLY_SHADE_ALPHA]  { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_MULTIPLY_SHADE_RGBA]   { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_MODULATE_SHADE_RGB]    { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_MODULATE_SHADE_RGBA]   { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_ANIM]                  { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_HOLOGRAM]              { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_COLOR_FILL]            { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_OVERLAY_RGB]           { 0x00441208, 0x00111208, 0 },
    [IMGFX_RENDER_OVERLAY_RGBA]          { 0x00404B40, 0x00104B40, IMGFX_RENDER_NO_OVERRIDE },
    [IMGFX_RENDER_UNUSED]                { 0x00441208, 0x00111208, 0 },
};

extern Addr shock_header;
extern Addr shiver_header;
extern Addr vertical_pipe_curl_header;
extern Addr horizontal_pipe_curl_header;
extern Addr startle_header;
extern Addr flutter_down_header;
extern Addr unfurl_header;
extern Addr get_in_bed_header;
extern Addr spirit_capture_header;
extern Addr unused_1_header;
extern Addr unused_2_header;
extern Addr unused_3_header;
extern Addr tutankoopa_gather_header;
extern Addr tutankoopa_swirl_2_header;
extern Addr tutankoopa_swirl_1_header;
extern Addr shuffle_cards_header;
extern Addr flip_card_1_header;
extern Addr flip_card_2_header;
extern Addr flip_card_3_header;
extern Addr cymbal_crush_header;

// all relative to imgfx_data_ROM_START
u8* ImgFXAnimOffsets[] = {
    [IMGFX_ANIM_SHOCK]                 shock_header,
    [IMGFX_ANIM_SHIVER]                shiver_header,
    [IMGFX_ANIM_VERTICAL_PIPE_CURL]    vertical_pipe_curl_header,
    [IMGFX_ANIM_HORIZONTAL_PIPE_CURL]  horizontal_pipe_curl_header,
    [IMGFX_ANIM_STARTLE]               startle_header,
    [IMGFX_ANIM_FLUTTER_DOWN]          flutter_down_header,
    [IMGFX_ANIM_UNFURL]                unfurl_header,
    [IMGFX_ANIM_GET_IN_BED]            get_in_bed_header,
    [IMGFX_ANIM_SPIRIT_CAPTURE]        spirit_capture_header,
    [IMGFX_ANIM_UNUSED_1]              unused_1_header,
    [IMGFX_ANIM_UNUSED_2]              unused_2_header,
    [IMGFX_ANIM_UNUSED_3]              unused_3_header,
    [IMGFX_ANIM_TUTANKOOPA_GATHER]     tutankoopa_gather_header,
    [IMGFX_ANIM_TUTANKOOPA_SWIRL_2]    tutankoopa_swirl_2_header,
    [IMGFX_ANIM_TUTANKOOPA_SWIRL_1]    tutankoopa_swirl_1_header,
    [IMGFX_ANIM_SHUFFLE_CARDS]         shuffle_cards_header,
    [IMGFX_ANIM_FLIP_CARD_1]           flip_card_1_header,
    [IMGFX_ANIM_FLIP_CARD_2]           flip_card_2_header,
    [IMGFX_ANIM_FLIP_CARD_3]           flip_card_3_header,
    [IMGFX_ANIM_CYMBAL_CRUSH]          cymbal_crush_header,
};

void imgfx_cache_instance_data(ImgFXState* state);
void imgfx_clear_instance_data(ImgFXState* state);
void imgfx_init_instance(ImgFXState* state);
void imgfx_make_mesh(ImgFXState* state);
void imgfx_appendGfx_mesh(ImgFXState* state, Matrix4f mtx);
void imgfx_mesh_make_strip(ImgFXState* state);
void imgfx_mesh_make_grid(ImgFXState* state);
//ImgFXAnimHeader* imgfx_load_anim(ImgFXState* state);
void imgfx_mesh_anim_update(ImgFXState* state);
void imgfx_appendGfx_mesh_basic(ImgFXState*, Matrix4f mtx);
void imgfx_appendGfx_mesh_grid(ImgFXState*, Matrix4f mtx);
void imgfx_appendGfx_mesh_anim(ImgFXState*, Matrix4f mtx);
void imgfx_appendGfx_mesh_strip(ImgFXState*, Matrix4f mtx);
void imgfx_wavy_init(ImgFXState* state);
void imgfx_mesh_make_wavy(ImgFXState* state);
void imgfx_mesh_load_colors(ImgFXState* state);

void imgfx_set_vtx_buf_capacity(s16 arg0) {
    ImgFXVtxBufferCapacity = arg0;
}

void imgfx_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ImgFXVtxBuffers); i++) {
        ImgFXVtxBuffers[i] = _heap_malloc(&heap_spriteHead, ImgFXVtxBufferCapacity * sizeof(Vtx));
    }

    ImgFXInstances = (ImgFXInstanceList*)_heap_malloc(&heap_spriteHead, sizeof(ImgFXInstanceList));

    for (i = 0; i < ARRAY_COUNT(*ImgFXInstances); i++) {
        imgfx_init_instance(&(*ImgFXInstances)[i]);
        imgfx_clear_instance_data(&(*ImgFXInstances)[i]);
    }

    for (i = 0; i < ARRAY_COUNT(D_80156958); i++) {
        D_80156958[i] = -1;
        D_80156960[i] = 0;
        D_80156968[i] = 0;
        D_80156970 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(ImgFXDataCache); i++) {
        ImgFXDataCache[i].data = NULL;
        ImgFXDataCache[i].staleCooldownTimer = 0;
        ImgFXDataCache[i].usingContextualHeap = FALSE;
    }

    imgfx_vtxCount = 0;
    imgfx_vtxBuf = ImgFXVtxBuffers[gCurrentDisplayContextIndex];
}

void func_8013A4D0(void) {
    s32 i;

    imgfx_vtxBuf = ImgFXVtxBuffers[gCurrentDisplayContextIndex];
    imgfx_vtxCount = 0;
    imgfx_init_instance(&(*ImgFXInstances)[0]);

    (*ImgFXInstances)[0].flags |= IMGFX_FLAG_VALID;

    for (i = 1; i < ARRAY_COUNT(*ImgFXInstances); i++) {
        if (((*ImgFXInstances)[i].flags & IMGFX_FLAG_VALID) && (*ImgFXInstances)[i].lastAnimCmd != IMGFX_SET_ANIM) {
            imgfx_cache_instance_data(&(*ImgFXInstances)[i]);
        }
    }

    for (i = 1; i < ARRAY_COUNT(*ImgFXInstances); i++) {
        if ((*ImgFXInstances)[i].flags & IMGFX_FLAG_VALID && (*ImgFXInstances)[i].colorBuf != NULL) {
            if ((*ImgFXInstances)[i].lastColorCmd == IMGFX_COLOR_BUF_SET_MULTIPLY) {
                continue;
            }
            if ((*ImgFXInstances)[i].lastColorCmd == IMGFX_COLOR_BUF_SET_MODULATE) {
                continue;
            }
            general_heap_free((*ImgFXInstances)[i].colorBuf);
            (*ImgFXInstances)[i].colorBuf = NULL;
            (*ImgFXInstances)[i].colorBufCount = 0;
        }
    }
}

void imgfx_add_to_cache(void* data, s8 usingContextualHeap) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ImgFXDataCache); i++) {
        if (ImgFXDataCache[i].data == NULL) {
            ImgFXDataCache[i].data = data;
            ImgFXDataCache[i].staleCooldownTimer = 4;
            ImgFXDataCache[i].usingContextualHeap = usingContextualHeap;
            return;
        }
    }
}

void imgfx_update_cache_impl(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ImgFXDataCache); i++) {
        if (ImgFXDataCache[i].data != NULL) {
            ImgFXDataCache[i].staleCooldownTimer--;

            if (ImgFXDataCache[i].staleCooldownTimer == 0) {
                if (ImgFXDataCache[i].usingContextualHeap) {
                    heap_free(ImgFXDataCache[i].data);
                    ImgFXDataCache[i].data = NULL;
                } else {
                    general_heap_free(ImgFXDataCache[i].data);
                    ImgFXDataCache[i].data = NULL;
                }

                ImgFXDataCache[i].staleCooldownTimer = 0;
                ImgFXDataCache[i].usingContextualHeap = FALSE;
            }
        }
    }
}

void imgfx_update_cache(void) {
    imgfx_update_cache_impl();
}

// request some number of imgfx instances. returns the id of the first assigned instance, or -1 if not enough are free.
s32 imgfx_get_free_instances(s32 count) {
    s32 numAssigned;
    s32 foundAny;
    s32 iPrev;
    s32 firstIdx;
    s32 i;

    numAssigned = 0;
    for (i = 1; i < ARRAY_COUNT(*ImgFXInstances); i++) {
        if (!((*ImgFXInstances)[i].flags & IMGFX_FLAG_VALID)) {
            numAssigned++;
        }
    }

    if (numAssigned < count) {
        return -1;
    }

    firstIdx = 0;
    foundAny = FALSE;
    numAssigned = 0;
    iPrev = -1;
    for (i = 1; i < ARRAY_COUNT(*ImgFXInstances); i++) {
        if ((*ImgFXInstances)[i].flags & IMGFX_FLAG_VALID) {
            continue;
        }

        if (!foundAny) {
            firstIdx = i;
            foundAny = TRUE;
        } else {
            (*ImgFXInstances)[iPrev].nextIdx = i;
        }

        (*ImgFXInstances)[i].arrayIdx = i;
        imgfx_init_instance(&(*ImgFXInstances)[i]);
        numAssigned++;
        (*ImgFXInstances)[i].flags |= IMGFX_FLAG_VALID;
        iPrev = i;
        if (numAssigned == count) {
            (*ImgFXInstances)[i].nextIdx = -1;
            break;
        }
    }

    return firstIdx;
}

void imgfx_release_instance(u32 idx) {
    if (idx < MAX_IMGFX_INSTANCES) {
        (*ImgFXInstances)[idx].flags = 0;
        (*ImgFXInstances)[idx].nextIdx = -1;
    }
}

void imgfx_release_instance_chain(u32 idx) {
    if (idx < MAX_IMGFX_INSTANCES) {
        s32 next;

        do {
            next = (*ImgFXInstances)[idx].nextIdx;
            imgfx_release_instance(idx);
            idx = next;
        } while (next != -1);
    }
}

s32 imgfx_get_next_instance(s32 idx) {
    if (idx < 0 || idx >= MAX_IMGFX_INSTANCES) {
        return -1;
    }

    if (idx >= MAX_IMGFX_INSTANCES) {
        return 0xFF;
    } else {
        return (*ImgFXInstances)[idx].nextIdx;
    }
}

ImgFXState* imgfx_get_instance(s32 idx) {
    return &(*ImgFXInstances)[idx];
}

void imgfx_cache_instance_data(ImgFXState* state) {
    if (state->curAnimOffset != NULL) {
        state->curAnimOffset = NULL;
    }
    if (state->vtxBufs[0] != NULL) {
        imgfx_add_to_cache(state->vtxBufs[0], TRUE);
        state->vtxBufs[0] = NULL;
    }
    if (state->vtxBufs[1] != NULL) {
        imgfx_add_to_cache(state->vtxBufs[1], TRUE);
        state->vtxBufs[1] = NULL;
    }
    if (state->gfxBufs[0] != NULL) {
        imgfx_add_to_cache(state->gfxBufs[0], TRUE);
        state->gfxBufs[0] = NULL;
    }
    if (state->gfxBufs[1] != NULL) {
        imgfx_add_to_cache(state->gfxBufs[1], TRUE);
        state->gfxBufs[1] = NULL;
    }
}

void imgfx_clear_instance_data(ImgFXState* state) {
    state->curAnimOffset = NULL;
    state->vtxBufs[0] = NULL;
    state->vtxBufs[1] = NULL;
    state->gfxBufs[0] = NULL;
    state->gfxBufs[1] = NULL;
    state->colorBuf = NULL;
    state->colorBufCount = 0;
}

void imgfx_init_instance(ImgFXState* state) {
    s32 i;
    s32 j;

    state->nextIdx = -1;
    state->lastAnimCmd = IMGFX_CLEAR;
    state->lastColorCmd = IMGFX_CLEAR;
    state->flags = 0;
    state->meshType = IMGFX_MESH_DEFAULT;
    state->renderType = IMGFX_RENDER_DEFAULT;
    state->firstVtxIdx = 0;
    state->lastVtxIdx = 0;
    state->unk_0C = 0;
    state->unk_0E = 0;
    state->ints.raw[0][3] = 255;
    state->ints.raw[1][3] = 255;
    state->subdivX = 0;
    state->subdivY = 0;
    state->firstVtxIdx = 0;
    state->lastVtxIdx = 0;

    for (i = 0; i < ARRAY_COUNT(state->ints.raw); i++) {
        for (j = 0; j < ARRAY_COUNT(state->ints.raw[0]); j++) {
            state->ints.raw[i][j] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(state->floats.raw); i++) {
        for (j = 0; j < ARRAY_COUNT(state->floats.raw[0]); j++) {
            state->floats.raw[i][j] = 0;
        }
    }
}

void imgfx_update(u32 idx, ImgFXType type, s32 imgfxArg1, s32 imgfxArg2, s32 imgfxArg3, s32 imgfxArg4, s32 flags) {
    ImgFXState* state = &(*ImgFXInstances)[idx];
    s32 oldFlags;
    s32 t1;
    u8 r, g, b, a;

    if (!(state->flags & IMGFX_FLAG_VALID) || (idx >= MAX_IMGFX_INSTANCES)) {
        return;
    }

    switch (type) {
        case IMGFX_CLEAR:
        case IMGFX_RESET:
            oldFlags = state->flags;
            imgfx_cache_instance_data(state);
            imgfx_init_instance(state);
            state->flags = oldFlags;
            state->lastAnimCmd = IMGFX_CLEAR;
            state->lastColorCmd = IMGFX_CLEAR;
            state->meshType = IMGFX_MESH_DEFAULT;
            state->renderType = IMGFX_RENDER_DEFAULT;
            state->ints.raw[0][0] = -1;
            state->ints.raw[1][0] = -1;

            state->flags &= IMGFX_FLAG_VALID;
            if (flags != 0) {
                state->flags |= flags;
            } else {
                state->flags |= flags; // required to match
            }
            return;
        case IMGFX_UNK_1:
            state->lastAnimCmd = IMGFX_CLEAR;
            state->renderType = IMGFX_RENDER_DEFAULT;
            state->ints.raw[0][0] = -1;
            return;
        case IMGFX_UNK_2:
            state->lastColorCmd = IMGFX_CLEAR;
            state->meshType = IMGFX_MESH_DEFAULT;
            state->ints.raw[1][0] = -1;
            return;
        case IMGFX_ALLOC_COLOR_BUF:
            if (state->colorBuf != NULL) {
                heap_free(state->colorBuf);
            }
            state->colorBufCount = imgfxArg1 * 4;
            state->colorBuf = heap_malloc(state->colorBufCount);
            return;
        case IMGFX_OVERLAY:
        case IMGFX_OVERLAY_XLU:
            if (type == state->lastColorCmd
                && imgfxArg1 == (s32) state->ints.overlay.pattern
                && imgfxArg2 == state->ints.overlay.alpha
            ) {
                // no paramaters have changed
                return;
            }
            break;
        case IMGFX_SET_ANIM:
            if (state->lastAnimCmd == type
                && state->ints.anim.type == imgfxArg1
                && state->ints.anim.interval == imgfxArg2
                && state->ints.anim.step == imgfxArg3
            ) {
                // no paramaters have changed
                return;
            }
            break;
        default:
            if (type != IMGFX_HOLOGRAM && state->lastColorCmd == IMGFX_HOLOGRAM) {
                state->meshType = IMGFX_MESH_DEFAULT;
                state->subdivX = 1;
                state->subdivY = 1;
            }
            break;
    }

    if (type != IMGFX_SET_ANIM && state->lastAnimCmd == IMGFX_SET_ANIM) {
        state->lastAnimCmd = IMGFX_CLEAR;
    }

    if (type == IMGFX_SET_WAVY || type == IMGFX_SET_ANIM) {
        state->lastAnimCmd = type;
        state->ints.args.anim[0] = imgfxArg1;
        state->ints.args.anim[1] = imgfxArg2;
        state->ints.args.anim[2] = imgfxArg3;
        state->ints.args.anim[3] = imgfxArg4;
    } else if (type >= IMGFX_SET_COLOR && type <= IMGFX_OVERLAY_XLU) {
        state->lastColorCmd = type;
        state->ints.args.color[0] = imgfxArg1;
        state->ints.args.color[1] = imgfxArg2;
        state->ints.args.color[2] = imgfxArg3;
        state->ints.args.color[3] = imgfxArg4;
    }

    state->flags &= IMGFX_FLAG_VALID;
    if (flags != 0) {
        state->flags |= flags;
    }
    state->meshType = IMGFX_MESH_DEFAULT;

    switch (type) {
        case IMGFX_RESET:
            state->meshType = IMGFX_MESH_DEFAULT;
            state->renderType = IMGFX_RENDER_DEFAULT;
            break;
        case IMGFX_SET_WAVY:
            state->subdivX = 4;
            state->subdivY = 4;
            state->meshType = IMGFX_MESH_GRID_WAVY;
            imgfx_wavy_init(state);
            break;
        case IMGFX_SET_ANIM:
            state->meshType = IMGFX_MESH_ANIMATED;
            state->renderType = IMGFX_RENDER_ANIM;
            state->floats.anim.curFrame = 0.0f;
            state->floats.anim.curIdx = 0.0f;
            state->flags |= IMGFX_FLAG_200;
            break;
        case IMGFX_SET_COLOR:
        case IMGFX_SET_ALPHA:
        case IMGFX_SET_TINT:
            if (imgfxArg1 >= 255 && imgfxArg2 >= 255 && imgfxArg3 >= 255 && imgfxArg4 >= 255) {
                // no color + no transparency
                state->renderType = IMGFX_RENDER_DEFAULT;
            } else if (imgfxArg4 >= 255) {
                // some color + no transparency
                state->renderType = IMGFX_RENDER_MULTIPLY_RGB;
            } else if (imgfxArg1 >= 255 && imgfxArg2 >= 255 && imgfxArg3 >= 255) {
                // no color + transparency
                state->renderType = IMGFX_RENDER_MULTIPLY_ALPHA;
            } else {
                // some color + transparency
                state->renderType = IMGFX_RENDER_MULTIPLY_RGBA;
            }
            break;
        case IMGFX_SET_WHITE_FADE:
        case IMGFX_SET_CREDITS_FADE:
            if (imgfxArg4 == 255.0) {
                state->renderType = IMGFX_RENDER_MODULATE_PRIM_RGB;
            } else {
                state->renderType = IMGFX_RENDER_MODULATE_PRIM_RGBA;
            }
            break;
        case IMGFX_COLOR_BUF_SET_MULTIPLY:
            if (imgfxArg1 < state->colorBufCount) {
                // unpack and store color
                r = (imgfxArg2 & 0xFF000000) >> 24;
                g = (imgfxArg2 & 0xFF0000) >> 16;
                b = (imgfxArg2 & 0xFF00) >> 8;
                a = (imgfxArg2 & 0xFF);
                state->colorBuf[imgfxArg1].r = r;
                state->colorBuf[imgfxArg1].g = g;
                state->colorBuf[imgfxArg1].b = b;
                state->colorBuf[imgfxArg1].a = a;

                state->meshType = IMGFX_MESH_DEFAULT;

                if (a == 255) {
                    state->renderType = IMGFX_RENDER_MULTIPLY_SHADE_RGB;
                } else {
                    state->renderType = IMGFX_RENDER_MULTIPLY_SHADE_RGBA;
                }
            }
            break;
        case IMGFX_COLOR_BUF_SET_MODULATE:
            if (imgfxArg1 < state->colorBufCount) {
                // unpack and store color
                r = (imgfxArg2 & 0xFF000000) >> 24;
                g = (imgfxArg2 & 0xFF0000) >> 16;
                b = (imgfxArg2 & 0xFF00) >> 8;
                a = (imgfxArg2 & 0xFF);
                state->colorBuf[imgfxArg1].r = r;
                state->colorBuf[imgfxArg1].g = g;
                state->colorBuf[imgfxArg1].b = b;
                state->colorBuf[imgfxArg1].a = a;

                state->meshType = IMGFX_MESH_DEFAULT;

                if (a == 255) {
                    state->renderType = IMGFX_RENDER_MODULATE_SHADE_RGB;
                } else {
                    state->renderType = IMGFX_RENDER_MODULATE_SHADE_RGBA;
                }
            }
            break;
        case IMGFX_HOLOGRAM:
            state->renderType = IMGFX_RENDER_HOLOGRAM;
            break;
        case IMGFX_FILL_COLOR:
            state->renderType = IMGFX_RENDER_COLOR_FILL;
            break;
        case IMGFX_OVERLAY:
        case IMGFX_OVERLAY_XLU:
            state->meshType = IMGFX_MESH_STRIP;
            if (imgfxArg2 >= 255) {
                state->renderType = IMGFX_RENDER_OVERLAY_RGB;
            } else {
                state->renderType = IMGFX_RENDER_OVERLAY_RGBA;
            }
            state->floats.overlay.posX = 0.0f;
            state->floats.overlay.posY = 0.0f;
            break;
    }
}

void imgfx_set_state_flags(s32 idx, u16 flagBits, s32 mode) {
    if ((*ImgFXInstances)[idx].flags & IMGFX_FLAG_VALID) {
        if (mode) {
            (*ImgFXInstances)[idx].flags |= flagBits;
        } else {
            (*ImgFXInstances)[idx].flags &= ~flagBits;
        }
    }
}

s32 imgfx_appendGfx_component(s32 idx, ImgFXTexture* ifxImg, u32 flagBits, Matrix4f mtx) {
    ImgFXState* state = &(*ImgFXInstances)[idx];
    s32 ret = 0;

    if (ifxImg->alpha == 0) {
        return 0;
    }

    state->arrayIdx = idx;
    state->flags |= flagBits;
    ImgFXCurrentTexturePtr->tex.raster  = ifxImg->raster;
    ImgFXCurrentTexturePtr->tex.palette = ifxImg->palette;
    ImgFXCurrentTexturePtr->tex.width   = ifxImg->width;
    ImgFXCurrentTexturePtr->tex.height  = ifxImg->height;
    ImgFXCurrentTexturePtr->tex.xOffset = ifxImg->xOffset;
    ImgFXCurrentTexturePtr->tex.yOffset = ifxImg->yOffset;
    ImgFXCurrentTexturePtr->unk_18  = 0;
    ImgFXCurrentTexturePtr->unk_1E  = 0;
    ImgFXCurrentTexturePtr->alphaMultiplier = ifxImg->alpha;

    if (idx < 0 || idx >= MAX_IMGFX_INSTANCES) {
        return 0;
    }

    if (idx >= MAX_IMGFX_INSTANCES || state == NULL) {
        return 0;
    }

    imgfx_make_mesh(state);
    imgfx_appendGfx_mesh(state, mtx);

    if (state->flags & IMGFX_FLAG_ANIM_DONE) {
        state->ints.raw[0][0] = -1;
        state->ints.raw[1][0] = -1;
        state->lastAnimCmd = IMGFX_CLEAR;
        state->meshType = 0;
        state->renderType = IMGFX_RENDER_DEFAULT;
        state->flags &= ~(IMGFX_FLAG_ANIM_DONE | IMGFX_FLAG_800 | IMGFX_FLAG_REVERSE_ANIM | IMGFX_FLAG_LOOP_ANIM);
        imgfx_cache_instance_data(state);
        ret = 1;
    } else if (state->flags & IMGFX_FLAG_4000) {
        ret = 2;
    } else if (state->flags & IMGFX_FLAG_20000) {
        state->lastAnimCmd = IMGFX_CLEAR;
        state->lastColorCmd = IMGFX_CLEAR;
        state->meshType = IMGFX_MESH_DEFAULT;
        state->renderType = IMGFX_RENDER_DEFAULT;
        state->ints.raw[0][0] = -1;
        state->ints.raw[1][0] = -1;
        state->flags &= IMGFX_FLAG_VALID;
        ret = 1;
    }
    return ret;
}

void imgfx_make_mesh(ImgFXState* state) {
    switch (state->meshType) {
        case IMGFX_MESH_GRID_UNUSED:
            if (state->ints.raw[1][2] == 0) {
                state->subdivX = 1;
                state->subdivY = 16;
            } else {
                state->subdivX = 1;
                state->subdivY = 1;
            }
            // fallthrough
        case IMGFX_MESH_GRID_WAVY:
            imgfx_mesh_make_grid(state);
            break;
        case IMGFX_MESH_ANIMATED:
            imgfx_mesh_anim_update(state);
            break;
        case IMGFX_MESH_DEFAULT:
        case IMGFX_MESH_STRIP:
            imgfx_mesh_make_strip(state);
            break;
        default:
            return;
    }

    if (state->lastAnimCmd == IMGFX_SET_WAVY) {
        imgfx_mesh_make_wavy(state);
    }

    switch (state->lastColorCmd) {
        case IMGFX_COLOR_BUF_SET_MULTIPLY:
        case IMGFX_COLOR_BUF_SET_MODULATE:
            imgfx_mesh_load_colors(state);
            break;
    }
}

void imgfx_appendGfx_mesh(ImgFXState* state, Matrix4f mtx) {
    s16 skipModeChange = FALSE;
    s32 primAlpha = state->ints.color.a;
    s32 renderType = state->renderType;
    s8 angle1;
    s8 angle2;
    f32 ifxImgAlpha;
    ImgFXRenderMode* renderMode;
    s32 mode1;
    s32 mode2;
    s32 dirX1;
    s32 dirZ2;

    gDPPipeSync(gMainGfxPos++);

    if (!(state->flags & IMGFX_FLAG_SKIP_GFX_SETUP)) {
        gSPDisplayList(gMainGfxPos++, DefaultImgFXSetupGfx);
        if (state->flags & IMGFX_FLAG_NO_FILTERING) {
            gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
        }
        if (state->flags & IMGFX_FLAG_G_CULL_BACK) {
            gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);
        }
        if (state->flags & IMGFX_FLAG_G_CULL_FRONT) {
            gSPSetGeometryMode(gMainGfxPos++, G_CULL_FRONT);
        }

        renderMode = &ImgFXRenderModes[state->renderType];

        mode1 = renderMode->mode1;
        mode2 = renderMode->mode2;
        if (renderMode->flags & IMGFX_RENDER_NO_OVERRIDE) {
            skipModeChange = TRUE;
        }

        ifxImgAlpha = (f32) ImgFXCurrentTexturePtr->alphaMultiplier / 255.0;

        // some modes dont support alpha < 255 and must be replaced
        if (!skipModeChange && (ImgFXCurrentTexturePtr->alphaMultiplier < 255)) {
            state->ints.color.a = 255;
            switch (state->renderType) {
                case IMGFX_RENDER_DEFAULT:
                case IMGFX_RENDER_ANIM:
                    renderType = IMGFX_RENDER_MULTIPLY_ALPHA;
                    break;
                case IMGFX_RENDER_MULTIPLY_RGB:
                case IMGFX_RENDER_MODULATE_PRIM_RGB:
                    renderType = IMGFX_RENDER_MULTIPLY_RGBA;
                    break;
                case IMGFX_RENDER_MODULATE_SHADE_RGB:
                    renderType = IMGFX_RENDER_MODULATE_SHADE_RGBA;
                    break;
            }
            primAlpha = state->ints.color.a * ifxImgAlpha;
            //TODO figure out bits
            mode1 = 0x404B40;
            mode2 = 0x104B40;
            skipModeChange = TRUE;
        }

        if ((state->flags & IMGFX_FLAG_400) && !skipModeChange) {
            mode1 &= ~CVG_DST_FULL;
            mode2 &= ~CVG_DST_FULL;
            mode1 |= (ALPHA_CVG_SEL | IM_RD);
            mode2 |= (ALPHA_CVG_SEL | IM_RD);
        }

        if (state->flags & IMGFX_FLAG_40) {
            gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER);
        } else {
            gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER);
            if (skipModeChange) {
                mode1 |= Z_CMP;
                mode2 |= Z_CMP;
            } else {
                mode1 |= (Z_CMP | Z_UPD);
                mode2 |= (Z_CMP | Z_UPD);
            }
        }
        state->otherModeL = mode2;
        gDPSetRenderMode(gMainGfxPos++, mode1, mode2);

        switch (renderType) {
            case IMGFX_RENDER_MULTIPLY_RGB:
                // color: texture * prim
                // alpha: texture
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color.r, state->ints.color.g,
                                state->ints.color.b, 0);
                break;
            case IMGFX_RENDER_MULTIPLY_ALPHA:
                // color: texture
                // alpha: texture * prim
                if (primAlpha <= 0) {
                    return;
                }
                gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                break;
            case IMGFX_RENDER_MULTIPLY_RGBA:
                // color: texture * prim
                // alpha: texture * prim
                if (primAlpha <= 0) {
                    return;
                }
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color.r, state->ints.color.g,
                                state->ints.color.b, primAlpha);
                break;
            case IMGFX_RENDER_MODULATE_PRIM_RGB:
                // color: lerp from prim color to 1 based on texture intensity
                // alpha: texture
                gDPSetCombineLERP(gMainGfxPos++,
                    1, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0,
                    1, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color.r, state->ints.color.g,
                                state->ints.color.b, 0);
                break;
            case IMGFX_RENDER_MODULATE_PRIM_RGBA:
                // color: lerp from prim color to 1 based on texture intensity
                // alpha: texture * vtx
                if (primAlpha <= 0) {
                    return;
                }
                gDPSetCombineLERP(gMainGfxPos++,
                    1, 0, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
                    1, 0, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color.r, state->ints.color.g,
                                state->ints.color.b, primAlpha);
                break;
            case IMGFX_RENDER_MULTIPLY_SHADE_RGB:
                // color: modulate vtx color by texture intensity
                // alpha: texture
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case IMGFX_RENDER_MODULATE_SHADE_RGB:
                // color: lerp from vtx color to 1 based on texture intensity
                // alpha: texture
                gDPSetCombineLERP(gMainGfxPos++,
                    1, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0,
                    1, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case IMGFX_RENDER_MULTIPLY_SHADE_ALPHA:
                // color: texture
                // alpha: texture * vtx color
                gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case IMGFX_RENDER_MULTIPLY_SHADE_RGBA:
                // color: modulate vtx color by texture intensity
                // alpha: modulate vtx alpha by texture intensity
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case IMGFX_RENDER_MODULATE_SHADE_RGBA:
                // color: lerp from vtx color to 1 based on texture intensity
                // alpha: vtx color * texture
                gDPSetCombineLERP(gMainGfxPos++,
                    1, SHADE, TEXEL0, SHADE, TEXEL0, 0, SHADE, 0,
                    1, SHADE, TEXEL0, SHADE, TEXEL0, 0, SHADE, 0);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case IMGFX_RENDER_ANIM:
                if (state->flags & (IMGFX_FLAG_2000 | IMGFX_FLAG_8000)) {
                    Camera* currentCam = &gCameras[gCurrentCameraID];

                    gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
                    gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);

                    angle1 = cosine(currentCam->curYaw) * 120.0f;
                    angle2 = cosine(currentCam->curYaw + 90.0f) * 120.0f;
                    dirX1 = -angle1;
                    dirZ2 = -angle2;
                    ImgFXLights.l[0].l.dir[0] = dirX1;
                    ImgFXLights.l[1].l.dir[0] = angle1;
                    ImgFXLights.l[0].l.dir[2] = angle2;
                    ImgFXLights.l[1].l.dir[2] = dirZ2;
                    gSPSetLights2(gMainGfxPos++, ImgFXLights);
                    break;
                }
                gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                break;
            case IMGFX_RENDER_HOLOGRAM:
                if (state->ints.hologram.mode == IMGFX_HOLOGRAM_NOISE) {
                    primAlpha = state->ints.hologram.alphaAmt * ifxImgAlpha;
                    // color: blend texure and noise
                    // alpha: texure * prim
                    gDPSetCombineMode(gMainGfxPos++, PM_CC_IMGFX_HOLOGRAM, PM_CC_IMGFX_HOLOGRAM);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0,
                                    state->ints.hologram.noiseAmt,
                                    state->ints.hologram.noiseAmt,
                                    state->ints.hologram.noiseAmt,
                                    primAlpha);
                } else if (state->ints.hologram.mode == IMGFX_HOLOGRAM_DITHER) {
                    primAlpha = state->ints.hologram.alphaAmt * ifxImgAlpha;
                    // color: texture
                    // alpha: texture * prim
                    gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_DITHER);
                } else if (state->ints.hologram.mode == IMGFX_HOLOGRAM_THRESHOLD) {
                    s32 blendAlpha = state->ints.hologram.alphaAmt + state->ints.hologram.noiseAmt;
                    if (blendAlpha > 255) {
                        blendAlpha = 255;
                    }
                    primAlpha = state->ints.hologram.alphaAmt * ifxImgAlpha;
                    // color: texture
                    // alpha: texture * prim
                    gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
                    gDPSetAlphaDither(gMainGfxPos++, G_AD_NOISE);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_THRESHOLD);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                    gDPSetBlendColor(gMainGfxPos++, 0, 0, 0, blendAlpha);
                }
                break;
            case IMGFX_RENDER_COLOR_FILL:
                // color: prim
                // alpha: texture
                gDPSetCombineMode(gMainGfxPos++, PM_CC_IMGFX_COLOR_FILL, PM_CC_IMGFX_COLOR_FILL);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color.r, state->ints.color.g,
                                state->ints.color.b, 0);
                break;
            case IMGFX_RENDER_DEFAULT:
            case IMGFX_RENDER_OVERLAY_RGB:
            case IMGFX_RENDER_UNUSED:
                // color: texture
                // alpha: texture
                gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                break;
            case IMGFX_RENDER_OVERLAY_RGBA:
                // color: texture
                // alpha: texture * prim
                gDPSetCombineMode(gMainGfxPos++, PM_CC_02, PM_CC_02);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, state->ints.overlay.alpha);
                break;
        }
    }

    switch (state->meshType) {
        case IMGFX_MESH_DEFAULT:
            imgfx_appendGfx_mesh_basic(state, mtx);
            break;
        case IMGFX_MESH_GRID_WAVY:
        case IMGFX_MESH_GRID_UNUSED:
            imgfx_appendGfx_mesh_grid(state, mtx);
            break;
        case IMGFX_MESH_ANIMATED:
            imgfx_appendGfx_mesh_anim(state, mtx);
            break;
        case IMGFX_MESH_STRIP:
            imgfx_appendGfx_mesh_basic(state, mtx);
            gDPPipeSync(gMainGfxPos++);
            imgfx_appendGfx_mesh_strip(state, mtx);
            break;
    }

    gDPPipeSync(gMainGfxPos++);

    if (state->renderType == IMGFX_RENDER_HOLOGRAM) {
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
        gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    }
}

void imgfx_mesh_make_strip(ImgFXState* state) {
    s32 offsetY;
    s32 offsetX;
    s32 stepY;
    s32 rightColor;
    s32 leftColor;
    s32 temp2;
    s32 nextY;

    stepY = (128 * 32) / ImgFXCurrentTexturePtr->tex.width;
    if (stepY > ImgFXCurrentTexturePtr->tex.height) {
        stepY = ImgFXCurrentTexturePtr->tex.height;
    }

    offsetX = ImgFXCurrentTexturePtr->tex.xOffset;
    offsetY = ImgFXCurrentTexturePtr->tex.yOffset;
    state->firstVtxIdx = imgfx_vtxCount;

    // create first pair of vertices to begin the strip
    // 'left' side
    imgfx_vtxBuf[imgfx_vtxCount].v.ob[0] = offsetX;
    imgfx_vtxBuf[imgfx_vtxCount].v.ob[1] = offsetY;
    imgfx_vtxBuf[imgfx_vtxCount].v.ob[2] = 0;
    imgfx_vtxBuf[imgfx_vtxCount].v.tc[0] = (0 + 256) * 32;
    imgfx_vtxBuf[imgfx_vtxCount].v.tc[1] = temp2 = (0 + 256) * 32; // required to match
    imgfx_vtxBuf[imgfx_vtxCount].v.cn[0] = 240;
    imgfx_vtxBuf[imgfx_vtxCount].v.cn[1] = 240;
    imgfx_vtxBuf[imgfx_vtxCount].v.cn[2] = 240;
    // 'right' side
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[0] = ImgFXCurrentTexturePtr->tex.width + offsetX;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[1] = offsetY;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[2] = 0;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[0] = (ImgFXCurrentTexturePtr->tex.width + 256) * 32;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[1] = temp2;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[0] = 120;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[1] = 120;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[2] = 120;

    // create remaining pairs of vertices along the strip
    nextY = stepY;
    while (TRUE) {
        rightColor = (nextY * 120) / ImgFXCurrentTexturePtr->tex.height;
        leftColor = rightColor + 120;
        imgfx_vtxCount += 2;

        // 'left' side
        imgfx_vtxBuf[imgfx_vtxCount].v.ob[0] = offsetX;
        imgfx_vtxBuf[imgfx_vtxCount].v.ob[1] = offsetY - stepY;
        imgfx_vtxBuf[imgfx_vtxCount].v.ob[2] = 0;
        imgfx_vtxBuf[imgfx_vtxCount].v.tc[0] = (0 + 256) * 32;
        imgfx_vtxBuf[imgfx_vtxCount].v.tc[1] = (nextY + 256) * 32;
        imgfx_vtxBuf[imgfx_vtxCount].v.cn[0] = leftColor;
        imgfx_vtxBuf[imgfx_vtxCount].v.cn[1] = leftColor;
        imgfx_vtxBuf[imgfx_vtxCount].v.cn[2] = leftColor;

        // 'right' side
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[0] = ImgFXCurrentTexturePtr->tex.width + offsetX;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[1] = offsetY - stepY;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[2] = 0;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[0] = (ImgFXCurrentTexturePtr->tex.width + 256) * 32;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[1] = (nextY + 256) * 32;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[0] = rightColor;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[1] = rightColor;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[2] = rightColor;

        if (nextY != ImgFXCurrentTexturePtr->tex.height) {
            offsetY -= stepY;
            if (ImgFXCurrentTexturePtr->tex.height < nextY + stepY) {
                stepY = ImgFXCurrentTexturePtr->tex.height - nextY;
            }
        } else {
            imgfx_vtxCount += 2;
            break;
        }
        nextY += stepY;
    }

    state->lastVtxIdx = imgfx_vtxCount - 1;
    state->subdivX = 1;
    state->subdivY = ((state->lastVtxIdx - state->firstVtxIdx) - 1) / 2;
}

void imgfx_mesh_make_grid(ImgFXState* state) {
    f32 divSizeX;
    f32 divSizeY;
    f32 posX;
    f32 posY;
    f32 texU;
    f32 texV;
    Vtx* vtx;
    s32 i;

    state->firstVtxIdx = imgfx_vtxCount;
    divSizeX = ImgFXCurrentTexturePtr->tex.width / (f32) state->subdivX;
    divSizeY = ImgFXCurrentTexturePtr->tex.height / (f32) state->subdivY;
    posY = ImgFXCurrentTexturePtr->tex.yOffset;
    texV = 0.0f;
    vtx = &imgfx_vtxBuf[imgfx_vtxCount];

    for (i = 0; i <= state->subdivY; i++) {
        s32 j;

        if (i == state->subdivY) {
            texV = ImgFXCurrentTexturePtr->tex.height;
            posY = ImgFXCurrentTexturePtr->tex.yOffset - ImgFXCurrentTexturePtr->tex.height;
        }

        posX = ImgFXCurrentTexturePtr->tex.xOffset;
        texU = 0.0f;
        for (j = 0; j <= state->subdivX; vtx++, j++) {
            if (j == state->subdivX) {
                texU = ImgFXCurrentTexturePtr->tex.width;
                posX = ImgFXCurrentTexturePtr->tex.xOffset + ImgFXCurrentTexturePtr->tex.width;
            }
            vtx->n.ob[0] = posX;
            vtx->n.ob[1] = posY;
            vtx->n.ob[2] = 0;
            vtx->n.tc[0] = ((s32) texU + 256) * 32;
            vtx->n.tc[1] = ((s32) texV + 256) * 32;
            imgfx_vtxCount++;
            posX += divSizeX;
            texU += divSizeX;
        }
        posY -= divSizeY;
        texV += divSizeY;
    }
    state->lastVtxIdx = imgfx_vtxCount - 1;
}

ImgFXAnimHeader* imgfx_load_anim(ImgFXState* state) {
    u8* romStart = (s32) ImgFXAnimOffsets[state->ints.anim.type] + imgfx_data_ROM_START;
    ImgFXAnimHeader* anim = &ImgFXAnimHeaders[state->arrayIdx];

    if (state->curAnimOffset != romStart) {
        u8* romEnd;
        s32 i;

        state->curAnimOffset = romStart;

        dma_copy(state->curAnimOffset, state->curAnimOffset + sizeof(*anim), anim);

        if (state->vtxBufs[0] != NULL) {
            imgfx_add_to_cache(state->vtxBufs[0], 1);
            state->vtxBufs[0] = NULL;
        }
        if (state->vtxBufs[1] != NULL) {
            imgfx_add_to_cache(state->vtxBufs[1], 1);
            state->vtxBufs[1] = NULL;
        }
        if (state->gfxBufs[0] != NULL) {
            imgfx_add_to_cache(state->gfxBufs[0], 1);
            state->gfxBufs[0] = NULL;
        }
        if (state->gfxBufs[1] != NULL) {
            // imgfx_add_to_cache(state->gfxBufs[1], 1);
            romEnd = (u8*) state->gfxBufs[1]; // required to match
            imgfx_add_to_cache(state->gfxBufs[1], 1);
            state->gfxBufs[1] = NULL;
        }
        state->vtxBufs[0] = heap_malloc(anim->vtxCount * sizeof(Vtx));
        state->vtxBufs[1] = heap_malloc(anim->vtxCount * sizeof(Vtx));
        state->gfxBufs[0] = heap_malloc(anim->gfxCount * sizeof(Gfx));
        state->gfxBufs[1] = heap_malloc(anim->gfxCount * sizeof(Gfx));

        romStart = imgfx_data_ROM_START + (s32)anim->gfxOffset;
        romEnd = romStart + anim->gfxCount * sizeof(Gfx);
        dma_copy(romStart, romEnd, state->gfxBufs[0]);
        dma_copy(romStart, romEnd, state->gfxBufs[1]);

        // Search through the state's displaylists for vertex commands
        // and adjust their addresses to point into the vertex buffers
        for (i = 0; i < ARRAY_COUNT(state->gfxBufs); i++) {
            Gfx* gfxBuffer = state->gfxBufs[i];
            s32 j = 0;
            u32 cmd;

            // Loop over the displaylist commands until we hit an ENDDL
            do {
                u32 w0 = gfxBuffer[j++].words.w0;
                cmd = w0 >> 0x18;

                // If this command is a vertex command, adjust the vertex buffer address
                if (cmd == G_VTX) {
                    // ImgFXVtx structs are 0xC bytes while Vtx are 0x10, so we need a (4/3) scaling factor
                    // to compute a new, equivalent Vtx[i] address for an existing ImgFXVtx[i] address.
                    // Unfortunately, using sizeof here does not match.
                    gfxBuffer[j-1].words.w1 = ((((s32) gfxBuffer[j-1].words.w1 - (s32) anim->keyframesOffset) / 3) * 4) +
                                              (s32) state->vtxBufs[i];
                }
            } while (cmd != G_ENDDL);
        }
    }

    return anim;
}

void imgfx_mesh_anim_update(ImgFXState* state) {
    s32 absKeyframeInterval;
    s32 nextKeyIdx;
    s32 curKeyIdx;
    ImgFXVtx* curKeyframe = NULL;
    ImgFXVtx* nextKeyframe = NULL;
    s32 keyframeInterval = state->ints.anim.interval;
    s32 animStep = state->ints.anim.step;
    s32 curSubframe = state->floats.anim.curFrame;
    ImgFXAnimHeader* header = imgfx_load_anim(state);
    u8* romStart;
    f32 lerpAlpha;
    s32 i;

    if (header == NULL) {
        return;
    }

    if (state->flags & IMGFX_FLAG_200) {
        state->flags &= ~IMGFX_FLAG_200;
        if (state->flags & IMGFX_FLAG_REVERSE_ANIM) {
            state->floats.anim.curIdx = header->keyframesCount - 1;
        }
    }
    curKeyIdx = state->floats.anim.curIdx;
    absKeyframeInterval = abs(keyframeInterval);
    if (state->flags & IMGFX_FLAG_4000) {
        nextKeyIdx = curKeyIdx;
    } else {
        if (state->flags & IMGFX_FLAG_REVERSE_ANIM) {
            nextKeyIdx = curKeyIdx - 1;
            if (nextKeyIdx < 0) {
                nextKeyIdx = curKeyIdx;
                if (state->flags & IMGFX_FLAG_LOOP_ANIM) {
                    nextKeyIdx = header->keyframesCount - 1;
                }
            }
        } else {
            nextKeyIdx = curKeyIdx + 1;
            if (nextKeyIdx == header->keyframesCount) {
                nextKeyIdx = curKeyIdx;
                if (state->flags & IMGFX_FLAG_LOOP_ANIM) {
                    nextKeyIdx = 0;
                }
            }
        }
    }

    // find the current + next keyframe vertex data
    curKeyframe = heap_malloc(header->vtxCount * sizeof(ImgFXVtx));
    romStart = (u8*)((s32)imgfx_data_ROM_START + (s32) header->keyframesOffset + curKeyIdx * header->vtxCount * sizeof(ImgFXVtx));
    dma_copy(romStart, romStart + header->vtxCount * sizeof(ImgFXVtx), curKeyframe);
    if (keyframeInterval > 1) {
        nextKeyframe = heap_malloc(header->vtxCount * sizeof(*nextKeyframe));
        romStart = (u8*)((s32)imgfx_data_ROM_START + (s32) header->keyframesOffset + nextKeyIdx * header->vtxCount * sizeof(ImgFXVtx));
        dma_copy(romStart, romStart + header->vtxCount * sizeof(ImgFXVtx), nextKeyframe);
    }

    lerpAlpha = (f32) curSubframe / (f32) keyframeInterval;
    for (i = 0; i < header->vtxCount; i++) {
        if (state->meshType != IMGFX_MESH_ANIMATED) {
            return;
        }

        if (keyframeInterval > 1) {
            // get vertex position, interpolated between keyframes
            if (header->flags & IMGFX_ANIM_FLAG_ABSOLUTE_COORDS) {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = (s16)(curKeyframe[i].ob[0] + (nextKeyframe[i].ob[0] - curKeyframe[i].ob[0]) * lerpAlpha);
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = (s16)(curKeyframe[i].ob[1] + (nextKeyframe[i].ob[1] - curKeyframe[i].ob[1]) * lerpAlpha);
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = (s16)(curKeyframe[i].ob[2] + (nextKeyframe[i].ob[2] - curKeyframe[i].ob[2]) * lerpAlpha);
            } else {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = (s16)(curKeyframe[i].ob[0] + (nextKeyframe[i].ob[0] - curKeyframe[i].ob[0]) * lerpAlpha) * 0.01 * ImgFXCurrentTexturePtr->tex.width;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = (s16)(curKeyframe[i].ob[1] + (nextKeyframe[i].ob[1] - curKeyframe[i].ob[1]) * lerpAlpha) * 0.01 * ImgFXCurrentTexturePtr->tex.height;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = (s16)(curKeyframe[i].ob[2] + (nextKeyframe[i].ob[2] - curKeyframe[i].ob[2]) * lerpAlpha) * 0.01 * ((ImgFXCurrentTexturePtr->tex.width + ImgFXCurrentTexturePtr->tex.height) / 2);
            }
            // get vertex color
            if (state->flags & (IMGFX_FLAG_2000 | IMGFX_FLAG_8000)) {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[0] = (s16)(curKeyframe[i].cn[0] + (nextKeyframe[i].cn[0] - curKeyframe[i].cn[0]) * lerpAlpha);
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[1] = (s16)(curKeyframe[i].cn[1] + (nextKeyframe[i].cn[1] - curKeyframe[i].cn[1]) * lerpAlpha);
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[2] = (s16)(curKeyframe[i].cn[2] + (nextKeyframe[i].cn[2] - curKeyframe[i].cn[2]) * lerpAlpha);
            } else {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[0] =
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[1] =
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[2] = 240.0 - (curKeyframe[i].tc[0] + curKeyframe[i].tc[1]) * 1.2;
            }
        } else {
            // get vertex position
            if (header->flags & IMGFX_ANIM_FLAG_ABSOLUTE_COORDS) {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = curKeyframe[i].ob[0];
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = curKeyframe[i].ob[1];
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = curKeyframe[i].ob[2];
            } else {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = curKeyframe[i].ob[0] * 0.01 * ImgFXCurrentTexturePtr->tex.width;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = curKeyframe[i].ob[1] * 0.01 * ImgFXCurrentTexturePtr->tex.height;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = curKeyframe[i].ob[2] * 0.01 * ((ImgFXCurrentTexturePtr->tex.width + ImgFXCurrentTexturePtr->tex.height) / 2);
            }
            // get vertex color
            if (state->flags & (IMGFX_FLAG_2000 | IMGFX_FLAG_8000)) {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[0] = curKeyframe[i].cn[0];
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[1] = curKeyframe[i].cn[1];
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[2] = curKeyframe[i].cn[2];
            } else {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[0] =
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[1] =
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.cn[2] = 240.0 - (curKeyframe[i].tc[0] + curKeyframe[i].tc[1]) * 1.2;
            }
        }
        // get vertex tex coords
        if (header->flags & IMGFX_ANIM_FLAG_ABSOLUTE_COORDS) {
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[0] = (curKeyframe[i].tc[0] + 256) * 32;
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[1] = (curKeyframe[i].tc[1] + 256) * 32;
        } else {
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[0] = ((s32)(curKeyframe[i].tc[0] * 0.01 * ImgFXCurrentTexturePtr->tex.width) + 256) * 32;
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[1] = ((s32)(curKeyframe[i].tc[1] * 0.01 * ImgFXCurrentTexturePtr->tex.height) + 256) * 32;
        }
    }

    state->firstVtxIdx = 0;
    state->lastVtxIdx = header->vtxCount - 1;

    heap_free(curKeyframe);
    if (nextKeyframe != NULL) {
        heap_free(nextKeyframe);
    }

    if (animStep == 0 || gGameStatusPtr->frameCounter % animStep != 0) {
        return;
    }

    if (keyframeInterval > 0) {
        curSubframe++;
        if (curSubframe >= keyframeInterval) {
            if (state->flags & IMGFX_FLAG_REVERSE_ANIM) {
                curKeyIdx--;
                if (curKeyIdx < 0) {
                    if (state->flags & IMGFX_FLAG_LOOP_ANIM) {
                        curKeyIdx = header->keyframesCount - 1;
                    } else {
                        if (state->flags & IMGFX_FLAG_800) {
                            curKeyIdx = 0;
                            state->flags |= IMGFX_FLAG_4000;
                        } else {
                            state->flags |= IMGFX_FLAG_ANIM_DONE;
                        }
                    }
                }
            } else {
                curKeyIdx++;
                if (curKeyIdx >= header->keyframesCount) {
                    if (state->flags & IMGFX_FLAG_LOOP_ANIM) {
                        curKeyIdx = 0;
                    } else {
                        if (state->flags & IMGFX_FLAG_800) {
                            curKeyIdx--;
                            state->flags |= IMGFX_FLAG_4000;
                        } else {
                            state->flags |= IMGFX_FLAG_ANIM_DONE;
                        }
                    }
                }
            }
            curSubframe = 0;
        }
    } else if (keyframeInterval < 0) {
        if (state->flags & IMGFX_FLAG_REVERSE_ANIM) {
            curKeyIdx -= absKeyframeInterval;
            if (curKeyIdx < 0) {
                if (state->flags & IMGFX_FLAG_LOOP_ANIM) {
                    curKeyIdx += header->keyframesCount;
                } else {
                    if (state->flags & IMGFX_FLAG_800) {
                        curKeyIdx = 0;
                        state->flags |= IMGFX_FLAG_4000;
                    } else {
                        state->flags |= IMGFX_FLAG_ANIM_DONE;
                    }
                }
            }
        } else {
            curKeyIdx += absKeyframeInterval;
            if (curKeyIdx >= header->keyframesCount) {
                if (state->flags & IMGFX_FLAG_LOOP_ANIM) {
                    curKeyIdx %= header->keyframesCount;
                } else {
                    if (state->flags & IMGFX_FLAG_800) {
                        curKeyIdx = header->keyframesCount - 1;
                        state->flags |= IMGFX_FLAG_4000;
                    } else {
                        state->flags |= IMGFX_FLAG_ANIM_DONE;
                    }
                }
            }
        }
    }

    state->floats.anim.curFrame = curSubframe;
    state->floats.anim.curIdx = curKeyIdx;
}

void imgfx_appendGfx_mesh_basic(ImgFXState* state, Matrix4f mtx) {
    s32 i;

    if (!(state->flags & IMGFX_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, ImgFXCurrentTexturePtr->tex.palette);
    }

    i = state->firstVtxIdx;

    while (TRUE) {
        Camera* cam;
        s32 uls = (imgfx_vtxBuf[i + 0].v.tc[0] >> 0x5) - 256;
        s32 ult = (imgfx_vtxBuf[i + 0].v.tc[1] >> 0x5) - 256;
        s32 lrs = (imgfx_vtxBuf[i + 3].v.tc[0] >> 0x5) - 256;
        s32 lrt = (imgfx_vtxBuf[i + 3].v.tc[1] >> 0x5) - 256;
        s32 someFlags = IMGFX_FLAG_100000 | IMGFX_FLAG_80000;
        s32 alpha;
        s32 alpha2;

        if (!(state->flags & IMGFX_FLAG_SKIP_TEX_SETUP)) {
            if ((gSpriteShadingProfile->flags & 1)
                && (state->arrayIdx != 0)
                && (state->flags & someFlags)
                && (   state->renderType == IMGFX_RENDER_DEFAULT
                    || state->renderType == IMGFX_RENDER_MULTIPLY_ALPHA
                    || state->renderType == IMGFX_RENDER_OVERLAY_RGBA
                    || state->renderType == IMGFX_RENDER_MULTIPLY_SHADE_ALPHA)
            ) {
                gDPScrollMultiTile2_4b(gMainGfxPos++,
                    ImgFXCurrentTexturePtr->tex.raster, G_IM_FMT_CI,
                    ImgFXCurrentTexturePtr->tex.width, ImgFXCurrentTexturePtr->tex.height, // img size
                    uls, ult, // top left
                    lrs - 1, lrt - 1, // bottom right
                    0, // palette
                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, // clamp wrap mirror
                    8, 8, // mask
                    G_TX_NOLOD, G_TX_NOLOD, // shift,
                    0x100, 0x100); // scroll
                gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x100, 2, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOLOD);
                gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 252, 0);

                alpha = 255;
                switch (state->renderType) {
                    case IMGFX_RENDER_DEFAULT:
                        break;
                    case IMGFX_RENDER_MULTIPLY_ALPHA:
                    case IMGFX_RENDER_OVERLAY_RGBA:
                        alpha = state->ints.color.a;
                        break;
                    case IMGFX_RENDER_MULTIPLY_SHADE_ALPHA:
                        alpha = -1;
                        break;
                }

                if ((gSpriteShadingProfile->flags & 2) && ((*ImgFXInstances)[0].arrayIdx != 0) && (state->flags & someFlags)) {
                    cam = &gCameras[gCurrentCamID];

                    if (gGameStatusPtr->isBattle == 2) {
                        gSPViewport(gMainGfxPos++, &D_8014EE50);
                    } else {
                        gSPViewport(gMainGfxPos++, &cam->vpAlt);
                    }

                    gDPSetRenderMode(gMainGfxPos++, G_RM_PASS, state->otherModeL);

                    if (alpha == -1) {
                        gDPSetCombineMode(gMainGfxPos++, PM_CC_0D, PM_CC_0C);
                    } else {
                        gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, alpha);
                        gDPSetCombineMode(gMainGfxPos++, PM_CC_0B, PM_CC_0C);
                    }

                    gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[i], 4, 0);
                    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
                    gDPPipeSync(gMainGfxPos++);
                }
                create_shading_palette(mtx, uls, ult, lrs, lrt, alpha, state->otherModeL);
            } else {
                gDPScrollTextureTile_4b(gMainGfxPos++,
                    ImgFXCurrentTexturePtr->tex.raster, G_IM_FMT_CI,
                    ImgFXCurrentTexturePtr->tex.width, ImgFXCurrentTexturePtr->tex.height, // img size
                    uls, ult, // top left
                    lrs - 1, lrt - 1, // bottom right
                    0, // palette
                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, // clamp wrap mirror
                    8, 8, // mask
                    G_TX_NOLOD, G_TX_NOLOD, // shift,
                    0x100, 0x100); // scroll

                if ((gSpriteShadingProfile->flags & 2) && state->arrayIdx != 0 && (state->flags & someFlags)) {
                    alpha2 = 255;
                    cam = &gCameras[gCurrentCamID];

                    if (gGameStatusPtr->isBattle == 2) {
                        gSPViewport(gMainGfxPos++, &D_8014EE50);
                    } else {
                        gSPViewport(gMainGfxPos++, &cam->vpAlt);
                    }

                    if (alpha2 == 255) {
                        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
                    } else {
                        gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
                    }

                    switch (state->renderType) {
                        case IMGFX_RENDER_DEFAULT:
                            alpha2 = 255;
                            break;
                        case IMGFX_RENDER_MULTIPLY_ALPHA:
                        case IMGFX_RENDER_OVERLAY_RGBA:
                            alpha2 = state->ints.color.a;
                            break;
                        case IMGFX_RENDER_MULTIPLY_SHADE_ALPHA:
                            alpha2 = -1;
                            break;
                    }

                    if (alpha2 == -1) {
                        gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, 0, SHADE, 0, TEXEL0, 0, 0, 0, 0, 0, SHADE, 0, TEXEL0, 0);
                    } else {
                        gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, alpha2);
                        gDPSetCombineMode(gMainGfxPos++, PM_CC_0A, PM_CC_0A);
                    }

                    gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[i], 4, 0);
                    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
                    gDPPipeSync(gMainGfxPos++);

                    if (alpha2 == 255) {
                        gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
                    } else {
                        gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
                    }

                    gDPSetEnvColor(gMainGfxPos++, 100, 100, 100, 255);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha2);
                    gDPSetCombineLERP(gMainGfxPos++, SHADE, ENVIRONMENT, TEXEL0, TEXEL0, 0, 0, 0, TEXEL0, SHADE, ENVIRONMENT, TEXEL0, TEXEL0, 0, 0, 0, TEXEL0);
                    gDPSetColorDither(gMainGfxPos++, G_CD_MAGICSQ);
                }
            }
        }

        if ((gSpriteShadingProfile->flags & 2) && (*ImgFXInstances)[0].arrayIdx != 0 && (state->flags & someFlags)) {
            cam = &gCameras[gCurrentCamID];
            if (gGameStatusPtr->isBattle == 2) {
                gSPViewport(gMainGfxPos++, &D_8014EE40);
                D_8014EE50.vp.vtrans[0] = D_8014EE40.vp.vtrans[0] + gGameStatusPtr->unk_82;
                D_8014EE50.vp.vtrans[1] = D_8014EE40.vp.vtrans[1] + gGameStatusPtr->unk_83;
            } else {
                gSPViewport(gMainGfxPos++, &cam->vp);
            }
        }

        gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[i], 4, 0);
        gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);

        if (i + 3 >= state->lastVtxIdx) {
            break;
        }

        i += 2;
    }
}

void imgfx_appendGfx_mesh_grid(ImgFXState* state, Matrix4f mtx) {
    s32 i, j;
    s32 firstVtxIdx;

    if (!(state->flags & IMGFX_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, ImgFXCurrentTexturePtr->tex.palette);
    }

    firstVtxIdx = state->firstVtxIdx;
    for (i = 0; i < state->subdivY; i++) {
        for (j = 0; j < state->subdivX; j++) {
            s32 ulIdx = firstVtxIdx + i * (state->subdivX + 1) + j;
            s32 urIdx = firstVtxIdx + i * (state->subdivX + 1) + j + 1;
            s32 llIdx = firstVtxIdx + (i + 1) * (state->subdivX + 1) + j;
            s32 lrIdx = firstVtxIdx + (i + 1) * (state->subdivX + 1) + j + 1;
            if (!(state->flags & IMGFX_FLAG_SKIP_TEX_SETUP)) {
                if ((gSpriteShadingProfile->flags & 1) &&
                    (*ImgFXInstances)[0].arrayIdx != 0 &&
                    (state->flags & (IMGFX_FLAG_100000 | IMGFX_FLAG_80000)) &&
                    (state->renderType == IMGFX_RENDER_DEFAULT
                    || state->renderType == IMGFX_RENDER_MULTIPLY_ALPHA
                    || state->renderType == IMGFX_RENDER_MULTIPLY_SHADE_ALPHA)) {
                    s32 alpha = 255;
                    gDPScrollMultiTile2_4b(gMainGfxPos++,
                        ImgFXCurrentTexturePtr->tex.raster, G_IM_FMT_CI,
                        ImgFXCurrentTexturePtr->tex.width, ImgFXCurrentTexturePtr->tex.height, // img size
                        (imgfx_vtxBuf[ulIdx].v.tc[0] >> 5) - 0x100, (imgfx_vtxBuf[ulIdx].v.tc[1] >> 5) - 0x100, // top left
                        (imgfx_vtxBuf[lrIdx].v.tc[0] >> 5) - 0x100 - 1, (imgfx_vtxBuf[lrIdx].v.tc[1] >> 5) - 0x100 - 1, // bottom right
                        0, // palette
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, // clamp wrap mirror
                        8, 8, // mask
                        G_TX_NOLOD, G_TX_NOLOD, // shift,
                        0x100, 0x100); // scroll
                    gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                    gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 63 << 2, 0);
                    switch (state->renderType) {
                        case IMGFX_RENDER_DEFAULT:
                            alpha = 255;
                            break;
                        case IMGFX_RENDER_MULTIPLY_ALPHA:
                            alpha = state->ints.color.a;
                            break;
                        case IMGFX_RENDER_MULTIPLY_SHADE_ALPHA:
                            alpha = -1;
                            break;

                    }
                    create_shading_palette(mtx,
                                           (imgfx_vtxBuf[ulIdx].v.tc[0] >> 5) - 0x100, (imgfx_vtxBuf[ulIdx].v.tc[1] >> 5) - 0x100,
                                           (imgfx_vtxBuf[lrIdx].v.tc[0] >> 5) - 0x100, (imgfx_vtxBuf[lrIdx].v.tc[1] >> 5) - 0x100,
                                           alpha, state->otherModeL);
                } else {
                    gDPScrollTextureTile_4b(gMainGfxPos++,
                        ImgFXCurrentTexturePtr->tex.raster, G_IM_FMT_CI,
                        ImgFXCurrentTexturePtr->tex.width, ImgFXCurrentTexturePtr->tex.height, // img size
                        (imgfx_vtxBuf[ulIdx].v.tc[0] >> 5) - 0x100, (imgfx_vtxBuf[ulIdx].v.tc[1] >> 5) - 0x100, // top left
                        (imgfx_vtxBuf[lrIdx].v.tc[0] >> 5) - 0x100 - 1, (imgfx_vtxBuf[lrIdx].v.tc[1] >> 5) - 0x100 - 1, // bottom right
                        0, // palette
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, // clamp wrap mirror
                        8, 8, // mask
                        G_TX_NOLOD, G_TX_NOLOD, // shift,
                        0x100, 0x100); // scroll
                }
            }

            gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[ulIdx], 1, 0);
            gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[urIdx], 1, 1);
            gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[llIdx], 1, 2);
            gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[lrIdx], 1, 3);
            gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
        }
    }
}

void imgfx_appendGfx_mesh_anim(ImgFXState* state, Matrix4f mtx) {
    if (state->vtxBufs[gCurrentDisplayContextIndex] == NULL || state->gfxBufs[gCurrentDisplayContextIndex] == NULL) {
        return;
    }

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], 0.1f, 0.1f, 0.1f);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (!(state->flags & IMGFX_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, ImgFXCurrentTexturePtr->tex.palette);
        if ((gSpriteShadingProfile->flags & 1)
            && (state->flags & (IMGFX_FLAG_100000 | IMGFX_FLAG_80000))
            && (state->renderType == IMGFX_RENDER_DEFAULT
                || state->renderType == IMGFX_RENDER_MULTIPLY_ALPHA
                || state->renderType == IMGFX_RENDER_MULTIPLY_SHADE_ALPHA
                || state->renderType == IMGFX_RENDER_ANIM)
        ) {
            s32 alpha = 255;
            gDPScrollMultiTile2_4b(gMainGfxPos++, ImgFXCurrentTexturePtr->tex.raster, G_IM_FMT_CI,
                                    ImgFXCurrentTexturePtr->tex.width, ImgFXCurrentTexturePtr->tex.height,
                                    0, 0, ImgFXCurrentTexturePtr->tex.width - 1, ImgFXCurrentTexturePtr->tex.height - 1, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD,
                                    256, 256);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0,
                            G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 252, 0);

            switch (state->renderType) {
                case IMGFX_RENDER_DEFAULT:
                case IMGFX_RENDER_ANIM:
                    alpha = 255;
                    break;
                case IMGFX_RENDER_MULTIPLY_ALPHA:
                    alpha = state->ints.color.a;
                    break;
                case IMGFX_RENDER_MULTIPLY_SHADE_ALPHA:
                    alpha = -1;
                    break;

            }
            create_shading_palette(mtx, 0, 0, ImgFXCurrentTexturePtr->tex.width, ImgFXCurrentTexturePtr->tex.height, alpha, state->otherModeL);
        } else {
            gDPScrollTextureTile_4b(gMainGfxPos++, ImgFXCurrentTexturePtr->tex.raster, G_IM_FMT_CI,
                                    ImgFXCurrentTexturePtr->tex.width, ImgFXCurrentTexturePtr->tex.height,
                                    0, 0, ImgFXCurrentTexturePtr->tex.width - 1, ImgFXCurrentTexturePtr->tex.height - 1, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD,
                                    256, 256);
        }
    }
    gSPDisplayList(gMainGfxPos++, state->gfxBufs[gCurrentDisplayContextIndex]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void imgfx_appendGfx_mesh_strip(ImgFXState* state, Matrix4f mtx) {
    ImgFXOverlayTexture* ufs = state->ints.overlay.pattern;
    s32 shifts = integer_log(ufs->width, 2);
    s32 shiftt = integer_log(ufs->height, 2);
    s32 uls, ult;
    s32 lrs, lrt;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (f32)ImgFXCurrentTexturePtr->tex.width / 100.0, (f32)ImgFXCurrentTexturePtr->tex.height / 100.0, 1.0f);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_XLU_DECAL, G_RM_ZB_XLU_DECAL2);

    if (state->renderType == IMGFX_RENDER_OVERLAY_RGBA) {
        s32 alpha = state->ints.overlay.alpha;
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
        gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_05);
    } else {
        gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    }
    gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMainGfxPos++, 0, ufs->palette);
    gDPScrollTextureTile_4b(gMainGfxPos++, ufs->raster, G_IM_FMT_CI, ufs->width, ufs->height,
                          0, 0, ufs->width - 1, ufs->height - 1, 0,
                          G_TX_WRAP, G_TX_WRAP, shifts, shiftt, G_TX_NOLOD, G_TX_NOLOD,
                          256, 256);

    uls = state->floats.overlay.posX;
    ult = state->floats.overlay.posY;
    lrs = ufs->width * 4 + state->floats.overlay.posX;
    lrt = ufs->height * 4 + state->floats.overlay.posY;
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls, ult, lrs, lrt);

    state->floats.overlay.posX = (s32)(state->floats.overlay.posX + ufs->offsetX) % (ufs->width * 4);
    state->floats.overlay.posY = (s32)(state->floats.overlay.posY + ufs->offsetY) % (ufs->height * 4);
    gSPDisplayList(gMainGfxPos++, ufs->displayList);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void imgfx_wavy_init(ImgFXState* state) {
    state->floats.wavy.phase1 = 0.0f;
    state->floats.wavy.phase2 = 50.0f;
    state->floats.wavy.phase3 = 30.0f;
}

void imgfx_mesh_make_wavy(ImgFXState* state) {
    Vtx* v1;
    Vtx* v2;
    Vtx* v3;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 angle1;
    f32 angle2;
    f32 angle3;
    f32 phase1;
    f32 phase2;
    f32 phase3;
    s32 angleInc;
    s32 amt;
    s32 sign;
    s32 i;

    phase1 = (f32) gGameStatusPtr->frameCounter / 10.3;
    while (phase1 > 360.0) {
        phase1 -= 360.0;
    }

    phase2 = (f32) (gGameStatusPtr->frameCounter + 40) / 11.2;
    while (phase2 > 360.0) {
        phase2 -= 360.0;
    }

    phase3 = (f32) (gGameStatusPtr->frameCounter + 25) / 10.8;
    while (phase3 > 360.0) {
        phase3 -= 360.0;
    }

    state->floats.wavy.phase1 = phase1;
    state->floats.wavy.phase2 = phase2;
    state->floats.wavy.phase3 = phase3;

    if (state->floats.wavy.phase1 >= 360.0) {
        state->floats.wavy.phase1-= 360.0;
    }

    if (state->floats.wavy.phase2 >= 360.0) {
        state->floats.wavy.phase2 -= 360.0;
    }

    if (state->floats.wavy.phase3 >= 360.0) {
        state->floats.wavy.phase3 -= 360.0;
    }

    sign = 0;
    angleInc = 0;
    amt = (state->lastVtxIdx - state->firstVtxIdx) - state->subdivX;

    for (i = 0; i < amt; i++) {
        angle1 = state->floats.wavy.phase1 + (angleInc * 45) + (sign * 180);
        angle2 = state->floats.wavy.phase2 + (angleInc * 45) + (sign * 180);
        angle3 = state->floats.wavy.phase3 + (angleInc * 45) + (sign * 180);

        //TODO find better match
        v1 = (Vtx*)((state->firstVtxIdx + i) * sizeof(Vtx) + (s32)imgfx_vtxBuf);
        vx = v1->v.ob[0];
        v1->v.ob[0] = (vx + (sin_rad(angle1) * state->ints.wavy.mag.x)); // @bug? should be sin_deg?

        v2 = (Vtx*)((state->firstVtxIdx + i) * sizeof(Vtx) + (s32)imgfx_vtxBuf);
        vy = v2->v.ob[1];
        v2->v.ob[1] = (vy + (sin_rad(angle2) * state->ints.wavy.mag.y));

        v3 = (Vtx*)((state->firstVtxIdx + i) * sizeof(Vtx) + (s32)imgfx_vtxBuf);
        vz = v3->v.ob[2];
        v3->v.ob[2] = (vz + (sin_rad(angle3) * state->ints.wavy.mag.z));

        angleInc++;
        if (i % (state->subdivX + 1) == 0) {
            angleInc = 0;
            sign = !sign;
        }
    }
}

void imgfx_mesh_load_colors(ImgFXState* state) {
    f32 alpha = (f32)ImgFXCurrentTexturePtr->alphaMultiplier / 255.0;
    s32 vtxCount = state->lastVtxIdx - state->firstVtxIdx;
    s32 i;

    for (i = 0; i <= vtxCount; i++) {
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[0] = state->colorBuf[i].r;
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[1] = state->colorBuf[i].g;
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[2] = state->colorBuf[i].b;
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[3] = state->colorBuf[i].a * alpha;
    }
}
