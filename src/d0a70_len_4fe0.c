#include "common.h"
#include "ld_addrs.h"
#include "sprite.h"

#if VERSION_IQUE
// TODO: remove if section is split in iQue release
extern Addr imgfx_gfx_data_ROM_START;
#endif

typedef union ImgfxIntVars {
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
        UnkImgfxStruct* pattern;
        s32 alpha;
    } overlay;
} ImgfxIntVars;

typedef union ImgfxFloatVars {
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
} ImgfxFloatVars;

typedef struct ImgfxState {
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
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ s32 flags;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ ImgfxIntVars ints;
    /* 0x3C */ ImgfxFloatVars floats;
    /* 0x5C */ Color_RGBA8* colorBuf;
    /* 0x60 */ u16 colorBufCount;
    /* 0x62 */ char unk_62[0x2];
    /* 0x64 */ u8* curAnimOffset;
    /* 0x68 */ Vtx* vtxBufs[2];
    /* 0x70 */ Gfx* gfxBufs[2];
    /* 0x78 */ s32 otherModeL;
} ImgfxState; // size = 0x7C

typedef struct ImgfxCacheEntry {
    /* 0x00 */ s32* data;
    /* 0x04 */ u8 staleCooldownTimer;
    /* 0x05 */ u8 usingContextualHeap;
    /* 0x06 */ char unk_06[0x2];
} ImgfxCacheEntry; // size = 0x8

typedef struct ImgfxAnimHeader {
    /* 0x00 */ s32 keyframesOffset;
    /* 0x04 */ Gfx* gfxOffset; // Gfx for creating mesh from vertices
    /* 0x08 */ u16 vtxCount; // conserved across keyframes
    /* 0x0A */ u16 gfxCount;
    /* 0x0C */ u16 keyframesCount;
    /* 0x0E */ u16 flags;
} ImgfxAnimHeader; // size = 0x10

enum ImgfxAnimFlags {
    IMGFX_ANIM_FLAG_ABSOLUTE_COORDS  = 1, // image-relative (in percent) when unset
};

typedef struct ImgfxRenderMode {
    /* 0x0 */ s32 mode1;
    /* 0x4 */ s32 mode2;
    /* 0x8 */ u8 flags; // only checks TRUE so far. some kind of switch?
} ImgfxRenderMode; // size = 0xC

// 'compressed' vertex data for animated fold keyframes
typedef struct ImgfxVtx {
    /* 0x00 */ s16 ob[3];
    /* 0x06 */ u8 tc[2];
    /* 0x08 */ s8 cn[3];
    /* 0x0B */ char unk_0B;
} ImgfxVtx; // size = 0x0C

typedef ImgfxState ImgfxInstanceList[MAX_IMGFX_STATES];

extern HeapNode heap_spriteHead;

// BSS
extern ImgfxImageRec D_80156920;
extern Vtx* ImgfxVtxBuffers[2];
extern Vtx* imgfx_vtxBuf;
extern ImgfxInstanceList* ImgfxInstances;
extern s8 D_80156958[2];
extern s32 D_80156960[2];
extern s32 D_80156968[2];
extern s8 D_80156970;
extern ImgfxAnimHeader ImgfxAnimHeaders[4];

// Data
ImgfxImageRec* imgfx_currentImage = &D_80156920;

u16 imgfx_vtxCount = 0;

Lights2 ImgfxLights = gdSPDefLights2(144, 144, 144, 255, 255, 255, 0, 0, 120, 255, 255, 255, 0, 0, 136);

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

u16 ImgfxVtxBufferCapacity = 300;

Gfx DefaultImgfxSetupGfx[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18,
                     G_AD_DISABLE | G_CD_DISABLE | G_TC_FILT | G_TF_BILERP | G_TP_PERSP),
    gsSPEndDisplayList(),
};

//TODO figure out bits
ImgfxRenderMode ImgfxRenderModes[] = {
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

// all relative to imgfx_gfx_data_ROM_START
s32 ImgfxAnimOffsets[] = {
    [IMGFX_ANIM_SHOCK]                 0x14358,
    [IMGFX_ANIM_SHIVER]                0x18200,
    [IMGFX_ANIM_VERTICAL_PIPE_CURL]    0x1A858,
    [IMGFX_ANIM_HORIZONTAL_PIPE_CURL]  0x1E830,
    [IMGFX_ANIM_STARTLE]               0x29458,
    [IMGFX_ANIM_FLUTTER_DOWN]          0x314E0,
    [IMGFX_ANIM_UNFURL]                0x33498,
    [IMGFX_ANIM_GET_IN_BED]            0x38988,
    [IMGFX_ANIM_SPIRIT_CAPTURE]        0x39228,
    [IMGFX_ANIM_UNUSED_1]              0x5B7A8,
    [IMGFX_ANIM_UNUSED_2]              0x7CF10,
    [IMGFX_ANIM_UNUSED_3]              0x86490,
    [IMGFX_ANIM_TUTANKOOPA_GATHER]     0x96258,
    [IMGFX_ANIM_TUTANKOOPA_SWIRL_2]    0xA1820,
    [IMGFX_ANIM_TUTANKOOPA_SWIRL_1]    0xACDE8,
    [IMGFX_ANIM_SHUFFLE_CARDS]         0xBBF68,
    [IMGFX_ANIM_FLIP_CARD_1]           0xC0490,
    [IMGFX_ANIM_FLIP_CARD_2]           0xC49B8,
    [IMGFX_ANIM_FLIP_CARD_3]           0xC6150,
    [IMGFX_ANIM_CYMBAL_CRUSH]          0xCA380,
};

extern ImgfxCacheEntry ImgfxDataCache[8];

void imgfx_clear_state_gfx(ImgfxState* state);
void imgfx_clear_state_data(ImgfxState* state);
void imgfx_init_state(ImgfxState* state);
void func_8013B0EC(ImgfxState* state);
void func_8013B1B0(ImgfxState* state, Matrix4f mtx);
void imgfx_mesh_make_strip(ImgfxState* state);
void imgfx_mesh_make_grid(ImgfxState* state);
//ImgfxAnimHeader* imgfx_load_anim(ImgfxState* state);
void imgfx_mesh_anim_update(ImgfxState* state);
void func_8013CFA8(ImgfxState*, Matrix4f mtx);
void func_8013DAB4(ImgfxState*, Matrix4f mtx);
void func_8013E2F0(ImgfxState*, Matrix4f mtx);
void func_8013E904(ImgfxState*, Matrix4f mtx);
void imgfx_wavy_init(ImgfxState* state);
void imgfx_mesh_wavy_update(ImgfxState* state);
void imgfx_mesh_load_colors(ImgfxState* state);

void imgfx_set_vtx_buf_capacity(s16 arg0) {
    ImgfxVtxBufferCapacity = arg0;
}

void imgfx_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ImgfxVtxBuffers); i++) {
        ImgfxVtxBuffers[i] = _heap_malloc(&heap_spriteHead, ImgfxVtxBufferCapacity * sizeof(Vtx));
    }

    ImgfxInstances = (ImgfxInstanceList*)_heap_malloc(&heap_spriteHead, sizeof(ImgfxInstanceList));

    for (i = 0; i < ARRAY_COUNT(*ImgfxInstances); i++) {
        imgfx_init_state(&(*ImgfxInstances)[i]);
        imgfx_clear_state_data(&(*ImgfxInstances)[i]);
    }

    for (i = 0; i < ARRAY_COUNT(D_80156958); i++) {
        D_80156958[i] = -1;
        D_80156960[i] = 0;
        D_80156968[i] = 0;
        D_80156970 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(ImgfxDataCache); i++) {
        ImgfxDataCache[i].data = NULL;
        ImgfxDataCache[i].staleCooldownTimer = 0;
        ImgfxDataCache[i].usingContextualHeap = FALSE;
    }

    imgfx_vtxCount = 0;
    imgfx_vtxBuf = ImgfxVtxBuffers[gCurrentDisplayContextIndex];
}

void func_8013A4D0(void) {
    s32 i;

    imgfx_vtxBuf = ImgfxVtxBuffers[gCurrentDisplayContextIndex];
    imgfx_vtxCount = 0;
    imgfx_init_state(&(*ImgfxInstances)[0]);

    (*ImgfxInstances)[0].flags |= IMGFX_STATE_FLAG_ENABLED;

    for (i = 1; i < ARRAY_COUNT(*ImgfxInstances); i++) {
        if (((*ImgfxInstances)[i].flags & IMGFX_STATE_FLAG_ENABLED) && (*ImgfxInstances)[i].lastAnimCmd != IMGFX_UPD_SET_ANIM) {
            imgfx_clear_state_gfx(&(*ImgfxInstances)[i]);
        }
    }

    for (i = 1; i < ARRAY_COUNT(*ImgfxInstances); i++) {
        if ((*ImgfxInstances)[i].flags & IMGFX_STATE_FLAG_ENABLED && (*ImgfxInstances)[i].colorBuf != NULL) {
            if ((*ImgfxInstances)[i].lastColorCmd == IMGFX_UPD_COLOR_BUF_SET_B) {
                continue;
            }
            if ((*ImgfxInstances)[i].lastColorCmd == IMGFX_UPD_COLOR_BUF_SET_C) {
                continue;
            }
            general_heap_free((*ImgfxInstances)[i].colorBuf);
            (*ImgfxInstances)[i].colorBuf = NULL;
            (*ImgfxInstances)[i].colorBufCount = 0;
        }
    }
}

void imgfx_add_to_gfx_cache(void* data, s8 usingContextualHeap) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ImgfxDataCache); i++) {
        if (ImgfxDataCache[i].data == NULL) {
            ImgfxDataCache[i].data = data;
            ImgfxDataCache[i].staleCooldownTimer = 4;
            ImgfxDataCache[i].usingContextualHeap = usingContextualHeap;
            return;
        }
    }
}

void imgfx_update_gfx_cache(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ImgfxDataCache); i++) {
        if (ImgfxDataCache[i].data != NULL) {
            ImgfxDataCache[i].staleCooldownTimer--;

            if (ImgfxDataCache[i].staleCooldownTimer == 0) {
                if (ImgfxDataCache[i].usingContextualHeap) {
                    heap_free(ImgfxDataCache[i].data);
                    ImgfxDataCache[i].data = NULL;
                } else {
                    general_heap_free(ImgfxDataCache[i].data);
                    ImgfxDataCache[i].data = NULL;
                }

                ImgfxDataCache[i].staleCooldownTimer = 0;
                ImgfxDataCache[i].usingContextualHeap = FALSE;
            }
        }
    }
}

void func_8013A6E8(void) {
    imgfx_update_gfx_cache();
}

s32 func_8013A704(s32 arg0) {
    s32 count;
    s32 cond;
    s32 iPrev;
    s32 ret;
    s32 i;

    count = 0;
    for (i = 1; i < ARRAY_COUNT(*ImgfxInstances); i++) {
        if (!((*ImgfxInstances)[i].flags & IMGFX_STATE_FLAG_ENABLED)) {
            count++;
        }
    }

    if (count < arg0) {
        return -1;
    }

    ret = 0;
    cond = FALSE;
    count = 0;
    iPrev = -1;
    for (i = 1; i < ARRAY_COUNT(*ImgfxInstances); i++) {
        if (!((*ImgfxInstances)[i].flags & IMGFX_STATE_FLAG_ENABLED)) {
            if (!cond) {
                ret = i;
                cond = TRUE;
            } else {
                (*ImgfxInstances)[iPrev].unk_10 = i;
            }

            (*ImgfxInstances)[i].arrayIdx = i;
            imgfx_init_state(&(*ImgfxInstances)[i]);
            count++;
            (*ImgfxInstances)[i].flags |= IMGFX_STATE_FLAG_ENABLED;
            iPrev = i;
            if (count == arg0) {
                (*ImgfxInstances)[i].unk_10 = -1;
                break;
            }
        }
    }

    return ret;
}

void func_8013A854(u32 idx) {
    if (idx < MAX_IMGFX_STATES) {
        (*ImgfxInstances)[idx].flags = 0;
        (*ImgfxInstances)[idx].unk_10 = -1;
    }
}

void func_8013A888(u32 idx) {
    if (idx < MAX_IMGFX_STATES) {
        s32 temp_s0;

        do {
            temp_s0 = (*ImgfxInstances)[idx].unk_10;
            func_8013A854(idx);
            idx = temp_s0;
        } while (temp_s0 != -1);
    }
}

s16 func_8013A8E0(s32 idx) {
    if (idx < 0 || idx >= MAX_IMGFX_STATES) {
        return -1;
    }

    if (idx >= MAX_IMGFX_STATES) {
        return 0xFF;
    } else {
        return (*ImgfxInstances)[idx].unk_10;
    }
}

ImgfxState* imgfx_get_state(s32 idx) {
    return &(*ImgfxInstances)[idx];
}

void imgfx_clear_state_gfx(ImgfxState* state) {
    if (state->curAnimOffset != NULL) {
        state->curAnimOffset = NULL;
    }
    if (state->vtxBufs[0] != NULL) {
        imgfx_add_to_gfx_cache(state->vtxBufs[0], TRUE);
        state->vtxBufs[0] = NULL;
    }
    if (state->vtxBufs[1] != NULL) {
        imgfx_add_to_gfx_cache(state->vtxBufs[1], TRUE);
        state->vtxBufs[1] = NULL;
    }
    if (state->gfxBufs[0] != NULL) {
        imgfx_add_to_gfx_cache(state->gfxBufs[0], TRUE);
        state->gfxBufs[0] = NULL;
    }
    if (state->gfxBufs[1] != NULL) {
        imgfx_add_to_gfx_cache(state->gfxBufs[1], TRUE);
        state->gfxBufs[1] = NULL;
    }
}

void imgfx_clear_state_data(ImgfxState* state) {
    state->curAnimOffset = NULL;
    state->vtxBufs[0] = NULL;
    state->vtxBufs[1] = NULL;
    state->gfxBufs[0] = NULL;
    state->gfxBufs[1] = NULL;
    state->colorBuf = NULL;
    state->colorBufCount = 0;
}

void imgfx_init_state(ImgfxState* state) {
    s32 i;
    s32 j;

    state->unk_10 = -1;
    state->lastAnimCmd = IMGFX_UPD_CLEAR;
    state->lastColorCmd = IMGFX_UPD_CLEAR;
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

void imgfx_update(u32 idx, ImgfxType type, s32 foldArg1, s32 foldArg2, s32 foldArg3, s32 foldArg4, s32 flags) {
    ImgfxState* state = &(*ImgfxInstances)[idx];
    s32 oldFlags;
    s32 t1;
    u8 r, g, b, a;

    if (!(state->flags & IMGFX_STATE_FLAG_ENABLED) || (idx >= MAX_IMGFX_STATES)) {
        return;
    }

    switch (type) {
        case IMGFX_UPD_CLEAR:
        case IMGFX_TYPE_3:
            oldFlags = state->flags;
            imgfx_clear_state_gfx(state);
            imgfx_init_state(state);
            state->flags = oldFlags;
            state->lastAnimCmd = IMGFX_UPD_CLEAR;
            state->lastColorCmd = IMGFX_UPD_CLEAR;
            state->meshType = IMGFX_MESH_DEFAULT;
            state->renderType = IMGFX_RENDER_DEFAULT;
            state->ints.raw[0][0] = -1;
            state->ints.raw[1][0] = -1;

            state->flags &= IMGFX_STATE_FLAG_ENABLED;
            if (flags != 0) {
                state->flags |= flags;
            } else {
                state->flags |= flags; // required to match
            }
            return;
        case IMGFX_TYPE_1:
            state->lastAnimCmd = IMGFX_UPD_CLEAR;
            state->renderType = IMGFX_RENDER_DEFAULT;
            state->ints.raw[0][0] = -1;
            return;
        case IMGFX_TYPE_2:
            state->lastColorCmd = IMGFX_UPD_CLEAR;
            state->meshType = IMGFX_MESH_DEFAULT;
            state->ints.raw[1][0] = -1;
            return;
        case IMGFX_UPD_ALLOC_COLOR_BUF:
            if (state->colorBuf != NULL) {
                heap_free(state->colorBuf);
            }
            state->colorBufCount = foldArg1 * 4;
            state->colorBuf = heap_malloc(state->colorBufCount);
            return;
        case IMGFX_UPD_OVERLAY:
        case IMGFX_UPD_OVERLAY_XLU:
            if (type == state->lastColorCmd
                && foldArg1 == (s32) state->ints.overlay.pattern
                && foldArg2 == state->ints.overlay.alpha
            ) {
                // no paramaters have changed
                return;
            }
            break;
        case IMGFX_UPD_SET_ANIM:
            if (state->lastAnimCmd == type
                && state->ints.anim.type == foldArg1
                && state->ints.anim.interval == foldArg2
                && state->ints.anim.step == foldArg3
            ) {
                // no paramaters have changed
                return;
            }
            break;
        default:
            if (type != IMGFX_UPD_HOLOGRAM && state->lastColorCmd == IMGFX_UPD_HOLOGRAM) {
                state->meshType = IMGFX_MESH_DEFAULT;
                state->subdivX = 1;
                state->subdivY = 1;
            }
            break;
    }

    if (type != IMGFX_UPD_SET_ANIM && state->lastAnimCmd == IMGFX_UPD_SET_ANIM) {
        state->lastAnimCmd = IMGFX_UPD_CLEAR;
    }

    if (type == IMGFX_UPD_WAVY || type == IMGFX_UPD_SET_ANIM) {
        state->lastAnimCmd = type;
        state->ints.args.anim[0] = foldArg1;
        state->ints.args.anim[1] = foldArg2;
        state->ints.args.anim[2] = foldArg3;
        state->ints.args.anim[3] = foldArg4;
    } else if (type >= IMGFX_UPD_SET_COLOR && type <= IMGFX_UPD_OVERLAY_XLU) {
        state->lastColorCmd = type;
        state->ints.args.color[0] = foldArg1;
        state->ints.args.color[1] = foldArg2;
        state->ints.args.color[2] = foldArg3;
        state->ints.args.color[3] = foldArg4;
    }

    state->flags &= IMGFX_STATE_FLAG_ENABLED;
    if (flags != 0) {
        state->flags |= flags;
    }
    state->meshType = IMGFX_MESH_DEFAULT;

    switch (type) {
        case IMGFX_TYPE_3:
            state->meshType = IMGFX_MESH_DEFAULT;
            state->renderType = IMGFX_RENDER_DEFAULT;
            break;
        case IMGFX_UPD_WAVY:
            state->subdivX = 4;
            state->subdivY = 4;
            state->meshType = IMGFX_MESH_GRID_WAVY;
            imgfx_wavy_init(state);
            break;
        case IMGFX_UPD_SET_ANIM:
            state->meshType = IMGFX_MESH_ANIMATED;
            state->renderType = IMGFX_RENDER_ANIM;
            state->floats.anim.curFrame = 0.0f;
            state->floats.anim.curIdx = 0.0f;
            state->flags |= IMGFX_STATE_FLAG_200;
            break;
        case IMGFX_UPD_SET_COLOR:
        case IMGFX_UPD_SET_ALPHA:
        case IMGFX_UPD_SET_TINT:
            if (foldArg1 >= 255 && foldArg2 >= 255 && foldArg3 >= 255 && foldArg4 >= 255) {
                // no color + no transparency
                state->renderType = IMGFX_RENDER_DEFAULT;
            } else if (foldArg4 >= 255) {
                // some color + no transparency
                state->renderType = IMGFX_RENDER_MULTIPLY_RGB;
            } else if (foldArg1 >= 255 && foldArg2 >= 255 && foldArg3 >= 255) {
                // no color + transparency
                state->renderType = IMGFX_RENDER_MULTIPLY_ALPHA;
            } else {
                // some color + transparency
                state->renderType = IMGFX_RENDER_MULTIPLY_RGBA;
            }
            break;
        case IMGFX_TYPE_9:
        case IMGFX_TYPE_A:
            if (foldArg4 == 255.0) {
                state->renderType = IMGFX_RENDER_MODULATE_PRIM_RGB;
            } else {
                state->renderType = IMGFX_RENDER_MODULATE_PRIM_RGBA;
            }
            break;
        case IMGFX_UPD_COLOR_BUF_SET_B:
            if (foldArg1 < state->colorBufCount) {
                // unpack and store color
                r = (foldArg2 & 0xFF000000) >> 24;
                g = (foldArg2 & 0xFF0000) >> 16;
                b = (foldArg2 & 0xFF00) >> 8;
                a = (foldArg2 & 0xFF);
                state->colorBuf[foldArg1].r = r;
                state->colorBuf[foldArg1].g = g;
                state->colorBuf[foldArg1].b = b;
                state->colorBuf[foldArg1].a = a;

                state->meshType = IMGFX_MESH_DEFAULT;

                if (a == 255) {
                    state->renderType = IMGFX_RENDER_MULTIPLY_SHADE_RGB;
                } else {
                    state->renderType = IMGFX_RENDER_MULTIPLY_SHADE_RGBA;
                }
            }
            break;
        case IMGFX_UPD_COLOR_BUF_SET_C:
            if (foldArg1 < state->colorBufCount) {
                // unpack and store color
                r = (foldArg2 & 0xFF000000) >> 24;
                g = (foldArg2 & 0xFF0000) >> 16;
                b = (foldArg2 & 0xFF00) >> 8;
                a = (foldArg2 & 0xFF);
                state->colorBuf[foldArg1].r = r;
                state->colorBuf[foldArg1].g = g;
                state->colorBuf[foldArg1].b = b;
                state->colorBuf[foldArg1].a = a;

                state->meshType = IMGFX_MESH_DEFAULT;

                if (a == 255) {
                    state->renderType = IMGFX_RENDER_MODULATE_SHADE_RGB;
                } else {
                    state->renderType = IMGFX_RENDER_MODULATE_SHADE_RGBA;
                }
            }
            break;
        case IMGFX_UPD_HOLOGRAM:
            state->renderType = IMGFX_RENDER_HOLOGRAM;
            break;
        case IMGFX_UPD_FILL_COLOR:
            state->renderType = IMGFX_RENDER_COLOR_FILL;
            break;
        case IMGFX_UPD_OVERLAY:
        case IMGFX_UPD_OVERLAY_XLU:
            state->meshType = IMGFX_MESH_STRIP;
            if (foldArg2 >= 255) {
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
    if ((*ImgfxInstances)[idx].flags & IMGFX_STATE_FLAG_ENABLED) {
        if (mode) {
            (*ImgfxInstances)[idx].flags |= flagBits;
        } else {
            (*ImgfxInstances)[idx].flags &= ~flagBits;
        }
    }
}

s32 imgfx_appendGfx_component(s32 idx, ImgfxImageRecPart* image, u32 flagBits, Matrix4f mtx) {
    ImgfxState* state = &(*ImgfxInstances)[idx];
    s32 ret = 0;

    if (image->opacity == 0) {
        return 0;
    }

    state->arrayIdx = idx;
    state->flags |= flagBits;
    imgfx_currentImage->raster = image->raster;
    imgfx_currentImage->palette = image->palette;
    imgfx_currentImage->width = image->width;
    imgfx_currentImage->height = image->height;
    imgfx_currentImage->xOffset = image->xOffset;
    imgfx_currentImage->yOffset =  image->yOffset;
    imgfx_currentImage->unk_18 = 0;
    imgfx_currentImage->unk_1E = 0;
    imgfx_currentImage->alphaMultiplier = image->opacity;

    if ((u32)idx >= MAX_IMGFX_STATES) {
        return 0;
    }

    if (idx >= MAX_IMGFX_STATES || state == NULL) {
        return 0;
    }

    func_8013B0EC(state);
    func_8013B1B0(state, mtx);

    if (state->flags & IMGFX_STATE_FLAG_ANIM_DONE) {
        state->ints.raw[0][0] = -1;
        state->ints.raw[1][0] = -1;
        state->lastAnimCmd = IMGFX_UPD_CLEAR;
        state->meshType = 0;
        state->renderType = IMGFX_RENDER_DEFAULT;
        state->flags &= ~(IMGFX_STATE_FLAG_ANIM_DONE | IMGFX_STATE_FLAG_800 | IMGFX_STATE_FLAG_REVERSE_ANIM | IMGFX_STATE_FLAG_LOOP_ANIM);
        imgfx_clear_state_gfx(state);
        ret = 1;
    } else if (state->flags & IMGFX_STATE_FLAG_4000) {
        ret = 2;
    } else if (state->flags & IMGFX_STATE_FLAG_20000) {
        state->lastAnimCmd = IMGFX_UPD_CLEAR;
        state->lastColorCmd = IMGFX_UPD_CLEAR;
        state->meshType = IMGFX_MESH_DEFAULT;
        state->renderType = IMGFX_RENDER_DEFAULT;
        state->ints.raw[0][0] = -1;
        state->ints.raw[1][0] = -1;
        state->flags &= IMGFX_STATE_FLAG_ENABLED;
        ret = 1;
    }
    return ret;
}

void func_8013B0EC(ImgfxState* state) {
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

    if (state->lastAnimCmd == IMGFX_UPD_WAVY) {
        imgfx_mesh_wavy_update(state);
    }

    switch (state->lastColorCmd) {
        case IMGFX_UPD_COLOR_BUF_SET_B:
        case IMGFX_UPD_COLOR_BUF_SET_C:
            imgfx_mesh_load_colors(state);
            break;
    }
}

void func_8013B1B0(ImgfxState* state, Matrix4f mtx) {
    s16 skipModeChange = FALSE;
    s32 primAlpha = state->ints.color.a;
    s32 renderType = state->renderType;
    s8 angle1;
    s8 angle2;
    f32 foldImgAlpha;
    ImgfxRenderMode* renderMode;
    s32 mode1;
    s32 mode2;
    s32 dirX1;
    s32 dirZ2;

    gDPPipeSync(gMainGfxPos++);

    if (!(state->flags & IMGFX_STATE_FLAG_SKIP_GFX_SETUP)) {
        gSPDisplayList(gMainGfxPos++, DefaultImgfxSetupGfx);
        if (state->flags & IMGFX_STATE_FLAG_NO_FILTERING) {
            gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
        }
        if (state->flags & IMGFX_STATE_FLAG_G_CULL_BACK) {
            gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);
        }
        if (state->flags & IMGFX_STATE_FLAG_G_CULL_FRONT) {
            gSPSetGeometryMode(gMainGfxPos++, G_CULL_FRONT);
        }

        renderMode = &ImgfxRenderModes[state->renderType];

        mode1 = renderMode->mode1;
        mode2 = renderMode->mode2;
        if (renderMode->flags & IMGFX_RENDER_NO_OVERRIDE) {
            skipModeChange = TRUE;
        }

        foldImgAlpha = (f32) imgfx_currentImage->alphaMultiplier / 255.0;

        // some modes dont support alpha < 255 and must be replaced
        if (!skipModeChange && (imgfx_currentImage->alphaMultiplier < 255)) {
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
            primAlpha = state->ints.color.a * foldImgAlpha;
            //TODO figure out bits
            mode1 = 0x404B40;
            mode2 = 0x104B40;
            skipModeChange = TRUE;
        }

        if ((state->flags & IMGFX_STATE_FLAG_400) && !skipModeChange) {
            mode1 &= ~CVG_DST_FULL;
            mode2 &= ~CVG_DST_FULL;
            mode1 |= (ALPHA_CVG_SEL | IM_RD);
            mode2 |= (ALPHA_CVG_SEL | IM_RD);
        }

        if (state->flags & IMGFX_STATE_FLAG_40) {
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
                gDPSetCombineLERP(gMainGfxPos++,
                    0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0,
                    0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
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
                gDPSetCombineLERP(gMainGfxPos++,
                    0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0,
                    0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
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
                if (state->flags & (IMGFX_STATE_FLAG_2000 | IMGFX_STATE_FLAG_8000)) {
                    Camera* currentCam = &gCameras[gCurrentCameraID];

                    gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
                    gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);

                    angle1 = cosine(currentCam->currentYaw) * 120.0f;
                    angle2 = cosine(currentCam->currentYaw + 90.0f) * 120.0f;
                    dirX1 = -angle1;
                    dirZ2 = -angle2;
                    ImgfxLights.l[0].l.dir[0] = dirX1;
                    ImgfxLights.l[1].l.dir[0] = angle1;
                    ImgfxLights.l[0].l.dir[2] = angle2;
                    ImgfxLights.l[1].l.dir[2] = dirZ2;
                    gSPSetLights2(gMainGfxPos++, ImgfxLights);
                    break;
                }
                gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                break;
            case IMGFX_RENDER_HOLOGRAM:
                if (state->ints.hologram.mode == IMGFX_HOLOGRAM_NOISE) {
                    primAlpha = state->ints.hologram.alphaAmt * foldImgAlpha;
                    // color: blend texure and noise
                    // alpha: texure * prim
                    gDPSetCombineLERP(gMainGfxPos++,
                        NOISE, PRIMITIVE, PRIMITIVE, TEXEL0, TEXEL0, 0, PRIMITIVE, 0,
                        NOISE, PRIMITIVE, PRIMITIVE, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0,
                                    state->ints.hologram.noiseAmt,
                                    state->ints.hologram.noiseAmt,
                                    state->ints.hologram.noiseAmt,
                                    primAlpha);
                } else if (state->ints.hologram.mode == IMGFX_HOLOGRAM_DITHER) {
                    primAlpha = state->ints.hologram.alphaAmt * foldImgAlpha;
                    // color: texture
                    // alpha: texture * prim
                    gDPSetCombineLERP(gMainGfxPos++,
                        0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0,
                        0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_DITHER);
                } else if (state->ints.hologram.mode == IMGFX_HOLOGRAM_THRESHOLD) {
                    s32 blendAlpha = state->ints.hologram.alphaAmt + state->ints.hologram.noiseAmt;
                    if (blendAlpha > 255) {
                        blendAlpha = 255;
                    }
                    primAlpha = state->ints.hologram.alphaAmt * foldImgAlpha;
                    // color: texture
                    // alpha: texture * prim
                    gDPSetCombineLERP(gMainGfxPos++,
                        0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0,
                        0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetAlphaDither(gMainGfxPos++, G_AD_NOISE);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_THRESHOLD);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                    gDPSetBlendColor(gMainGfxPos++, 0, 0, 0, blendAlpha);
                }
                break;
            case IMGFX_RENDER_COLOR_FILL:
                // color: prim
                // alpha: texture
                gDPSetCombineLERP(gMainGfxPos++,
                    0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0,
                    0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
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
                gDPSetCombineLERP(gMainGfxPos++, 
                    0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0,
                    0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, state->ints.overlay.alpha);
                break;
        }
    }

    switch (state->meshType) {
        case IMGFX_MESH_DEFAULT:
            func_8013CFA8(state, mtx);
            break;
        case IMGFX_MESH_GRID_WAVY:
        case IMGFX_MESH_GRID_UNUSED:
            func_8013DAB4(state, mtx);
            break;
        case IMGFX_MESH_ANIMATED:
            func_8013E2F0(state, mtx);
            break;
        case IMGFX_MESH_STRIP:
            func_8013CFA8(state, mtx);
            gDPPipeSync(gMainGfxPos++);
            func_8013E904(state, mtx);
            break;
    }

    gDPPipeSync(gMainGfxPos++);

    if (state->renderType == IMGFX_RENDER_HOLOGRAM) {
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
        gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    }
}

void imgfx_mesh_make_strip(ImgfxState* state) {
    s32 offsetY;
    s32 offsetX;
    s32 stepY;
    s32 rightColor;
    s32 leftColor;
    s32 temp2;
    s32 nextY;

    stepY = (128 * 32) / imgfx_currentImage->width;
    if (stepY > imgfx_currentImage->height) {
        stepY = imgfx_currentImage->height;
    }

    offsetX = imgfx_currentImage->xOffset;
    offsetY = imgfx_currentImage->yOffset;
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
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[0] = imgfx_currentImage->width + offsetX;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[1] = offsetY;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[2] = 0;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[0] = (imgfx_currentImage->width + 256) * 32;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[1] = temp2;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[0] = 120;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[1] = 120;
    imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[2] = 120;

    // create remaining pairs of vertices along the strip
    nextY = stepY;
    while (TRUE) {
        rightColor = (nextY * 120) / imgfx_currentImage->height;
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
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[0] = imgfx_currentImage->width + offsetX;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[1] = offsetY - stepY;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.ob[2] = 0;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[0] = (imgfx_currentImage->width + 256) * 32;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.tc[1] = (nextY + 256) * 32;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[0] = rightColor;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[1] = rightColor;
        imgfx_vtxBuf[imgfx_vtxCount + 1].v.cn[2] = rightColor;

        if (nextY != imgfx_currentImage->height) {
            offsetY -= stepY;
            if (imgfx_currentImage->height < nextY + stepY) {
                stepY = imgfx_currentImage->height - nextY;
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

void imgfx_mesh_make_grid(ImgfxState* state) {
    f32 divSizeX;
    f32 divSizeY;
    f32 posX;
    f32 posY;
    f32 texU;
    f32 texV;
    Vtx* vtx;
    s32 i;

    state->firstVtxIdx = imgfx_vtxCount;
    divSizeX = imgfx_currentImage->width / (f32) state->subdivX;
    divSizeY = imgfx_currentImage->height / (f32) state->subdivY;
    posY = imgfx_currentImage->yOffset;
    texV = 0.0f;
    vtx = &imgfx_vtxBuf[imgfx_vtxCount];

    for (i = 0; i <= state->subdivY; i++) {
        s32 j;

        if (i == state->subdivY) {
            texV = imgfx_currentImage->height;
            posY = imgfx_currentImage->yOffset - imgfx_currentImage->height;
        }

        posX = imgfx_currentImage->xOffset;
        texU = 0.0f;
        for (j = 0; j <= state->subdivX; vtx++, j++) {
            if (j == state->subdivX) {
                texU = imgfx_currentImage->width;
                posX = imgfx_currentImage->xOffset + imgfx_currentImage->width;
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

ImgfxAnimHeader* imgfx_load_anim(ImgfxState* state) {
    u8* romStart = ImgfxAnimOffsets[state->ints.anim.type] + imgfx_gfx_data_ROM_START;
    ImgfxAnimHeader* anim = &ImgfxAnimHeaders[state->arrayIdx];

    if (state->curAnimOffset != romStart) {
        u8* romEnd;
        s32 i;

        state->curAnimOffset = romStart;

        dma_copy(state->curAnimOffset, state->curAnimOffset + sizeof(*anim), anim);

        if (state->vtxBufs[0] != NULL) {
            imgfx_add_to_gfx_cache(state->vtxBufs[0], 1);
            state->vtxBufs[0] = NULL;
        }
        if (state->vtxBufs[1] != NULL) {
            imgfx_add_to_gfx_cache(state->vtxBufs[1], 1);
            state->vtxBufs[1] = NULL;
        }
        if (state->gfxBufs[0] != NULL) {
            imgfx_add_to_gfx_cache(state->gfxBufs[0], 1);
            state->gfxBufs[0] = NULL;
        }
        if (state->gfxBufs[1] != NULL) {
            // imgfx_add_to_gfx_cache(state->gfxBufs[1], 1);
            romEnd = (u8*) state->gfxBufs[1]; // required to match
            imgfx_add_to_gfx_cache(state->gfxBufs[1], 1);
            state->gfxBufs[1] = NULL;
        }
        state->vtxBufs[0] = heap_malloc(anim->vtxCount * sizeof(Vtx));
        state->vtxBufs[1] = heap_malloc(anim->vtxCount * sizeof(Vtx));
        state->gfxBufs[0] = heap_malloc(anim->gfxCount * sizeof(Gfx));
        state->gfxBufs[1] = heap_malloc(anim->gfxCount * sizeof(Gfx));

        romStart = imgfx_gfx_data_ROM_START + (s32)anim->gfxOffset;
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
                    // ImgfxVtx structs are 0xC bytes while Vtx are 0x10, so we need a (4/3) scaling factor
                    // to compute a new, equivalent Vtx[i] address for an existing ImgfxVtx[i] address.
                    // Unfortunately, using sizeof here does not match.
                    gfxBuffer[j-1].words.w1 = ((((s32) gfxBuffer[j-1].words.w1 - anim->keyframesOffset) / 3) * 4) +
                                              (s32) state->vtxBufs[i];
                }
            } while (cmd != G_ENDDL);
        }
    }

    return anim;
}

void imgfx_mesh_anim_update(ImgfxState* state) {
    s32 absKeyframeInterval;
    s32 nextKeyIdx;
    s32 curKeyIdx;
    ImgfxVtx* curKeyframe = NULL;
    ImgfxVtx* nextKeyframe = NULL;
    s32 keyframeInterval = state->ints.anim.interval;
    s32 animStep = state->ints.anim.step;
    s32 curSubframe = state->floats.anim.curFrame;
    ImgfxAnimHeader* header = imgfx_load_anim(state);
    u8* romStart;
    f32 lerpAlpha;
    s32 i;

    if (header == NULL) {
        return;
    }

    if (state->flags & IMGFX_STATE_FLAG_200) {
        state->flags &= ~IMGFX_STATE_FLAG_200;
        if (state->flags & IMGFX_STATE_FLAG_REVERSE_ANIM) {
            state->floats.anim.curIdx = header->keyframesCount - 1;
        }
    }
    curKeyIdx = state->floats.anim.curIdx;
    absKeyframeInterval = abs(keyframeInterval);
    if (state->flags & IMGFX_STATE_FLAG_4000) {
        nextKeyIdx = curKeyIdx;
    } else {
        if (state->flags & IMGFX_STATE_FLAG_REVERSE_ANIM) {
            nextKeyIdx = curKeyIdx - 1;
            if (nextKeyIdx < 0) {
                nextKeyIdx = curKeyIdx;
                if (state->flags & IMGFX_STATE_FLAG_LOOP_ANIM) {
                    nextKeyIdx = header->keyframesCount - 1;
                }
            }
        } else {
            nextKeyIdx = curKeyIdx + 1;
            if (nextKeyIdx == header->keyframesCount) {
                nextKeyIdx = curKeyIdx;
                if (state->flags & IMGFX_STATE_FLAG_LOOP_ANIM) {
                    nextKeyIdx = 0;
                }
            }
        }
    }

    // find the current + next keyframe vertex data
    curKeyframe = heap_malloc(header->vtxCount * sizeof(ImgfxVtx));
    romStart = (u8*)((s32)imgfx_gfx_data_ROM_START + header->keyframesOffset + curKeyIdx * header->vtxCount * sizeof(ImgfxVtx));
    dma_copy(romStart, romStart + header->vtxCount * sizeof(ImgfxVtx), curKeyframe);
    if (keyframeInterval > 1) {
        nextKeyframe = heap_malloc(header->vtxCount * sizeof(*nextKeyframe));
        romStart = (u8*)((s32)imgfx_gfx_data_ROM_START + header->keyframesOffset + nextKeyIdx * header->vtxCount * sizeof(ImgfxVtx));
        dma_copy(romStart, romStart + header->vtxCount * sizeof(ImgfxVtx), nextKeyframe);
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
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = (s16)(curKeyframe[i].ob[0] + (nextKeyframe[i].ob[0] - curKeyframe[i].ob[0]) * lerpAlpha) * 0.01 * imgfx_currentImage->width;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = (s16)(curKeyframe[i].ob[1] + (nextKeyframe[i].ob[1] - curKeyframe[i].ob[1]) * lerpAlpha) * 0.01 * imgfx_currentImage->height;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = (s16)(curKeyframe[i].ob[2] + (nextKeyframe[i].ob[2] - curKeyframe[i].ob[2]) * lerpAlpha) * 0.01 * ((imgfx_currentImage->width + imgfx_currentImage->height) / 2);
            }
            // get vertex color
            if (state->flags & (IMGFX_STATE_FLAG_2000 | IMGFX_STATE_FLAG_8000)) {
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
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = curKeyframe[i].ob[0] * 0.01 * imgfx_currentImage->width;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = curKeyframe[i].ob[1] * 0.01 * imgfx_currentImage->height;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = curKeyframe[i].ob[2] * 0.01 * ((imgfx_currentImage->width + imgfx_currentImage->height) / 2);
            }
            // get vertex color
            if (state->flags & (IMGFX_STATE_FLAG_2000 | IMGFX_STATE_FLAG_8000)) {
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
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[0] = ((s32)(curKeyframe[i].tc[0] * 0.01 * imgfx_currentImage->width) + 256) * 32;
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[1] = ((s32)(curKeyframe[i].tc[1] * 0.01 * imgfx_currentImage->height) + 256) * 32;
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
            if (state->flags & IMGFX_STATE_FLAG_REVERSE_ANIM) {
                curKeyIdx--;
                if (curKeyIdx < 0) {
                    if (state->flags & IMGFX_STATE_FLAG_LOOP_ANIM) {
                        curKeyIdx = header->keyframesCount - 1;
                    } else {
                        if (state->flags & IMGFX_STATE_FLAG_800) {
                            curKeyIdx = 0;
                            state->flags |= IMGFX_STATE_FLAG_4000;
                        } else {
                            state->flags |= IMGFX_STATE_FLAG_ANIM_DONE;
                        }
                    }
                }
            } else {
                curKeyIdx++;
                if (curKeyIdx >= header->keyframesCount) {
                    if (state->flags & IMGFX_STATE_FLAG_LOOP_ANIM) {
                        curKeyIdx = 0;
                    } else {
                        if (state->flags & IMGFX_STATE_FLAG_800) {
                            curKeyIdx--;
                            state->flags |= IMGFX_STATE_FLAG_4000;
                        } else {
                            state->flags |= IMGFX_STATE_FLAG_ANIM_DONE;
                        }
                    }
                }
            }
            curSubframe = 0;
        }
    } else if (keyframeInterval < 0) {
        if (state->flags & IMGFX_STATE_FLAG_REVERSE_ANIM) {
            curKeyIdx -= absKeyframeInterval;
            if (curKeyIdx < 0) {
                if (state->flags & IMGFX_STATE_FLAG_LOOP_ANIM) {
                    curKeyIdx += header->keyframesCount;
                } else {
                    if (state->flags & IMGFX_STATE_FLAG_800) {
                        curKeyIdx = 0;
                        state->flags |= IMGFX_STATE_FLAG_4000;
                    } else {
                        state->flags |= IMGFX_STATE_FLAG_ANIM_DONE;
                    }
                }
            }
        } else {
            curKeyIdx += absKeyframeInterval;
            if (curKeyIdx >= header->keyframesCount) {
                if (state->flags & IMGFX_STATE_FLAG_LOOP_ANIM) {
                    curKeyIdx %= header->keyframesCount;
                } else {
                    if (state->flags & IMGFX_STATE_FLAG_800) {
                        curKeyIdx = header->keyframesCount - 1;
                        state->flags |= IMGFX_STATE_FLAG_4000;
                    } else {
                        state->flags |= IMGFX_STATE_FLAG_ANIM_DONE;
                    }
                }
            }
        }
    }

    state->floats.anim.curFrame = curSubframe;
    state->floats.anim.curIdx = curKeyIdx;
}

void func_8013CFA8(ImgfxState* state, Matrix4f mtx) {
    s32 i;

    if (!(state->flags & IMGFX_STATE_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, imgfx_currentImage->palette);
    }

    i = state->firstVtxIdx;

    while (TRUE) {
        Camera* cam;
        s32 uls = (imgfx_vtxBuf[i + 0].v.tc[0] >> 0x5) - 256;
        s32 ult = (imgfx_vtxBuf[i + 0].v.tc[1] >> 0x5) - 256;
        s32 lrs = (imgfx_vtxBuf[i + 3].v.tc[0] >> 0x5) - 256;
        s32 lrt = (imgfx_vtxBuf[i + 3].v.tc[1] >> 0x5) - 256;
        s32 someFlags = IMGFX_STATE_FLAG_100000 | IMGFX_STATE_FLAG_80000;
        s32 alpha;
        s32 alpha2;

        if (!(state->flags & IMGFX_STATE_FLAG_SKIP_TEX_SETUP)) {
            if ((gSpriteShadingProfile->flags & 1)
                && (state->arrayIdx != 0)
                && (state->flags & someFlags)
                && (   state->renderType == IMGFX_RENDER_DEFAULT
                    || state->renderType == IMGFX_RENDER_MULTIPLY_ALPHA
                    || state->renderType == IMGFX_RENDER_OVERLAY_RGBA
                    || state->renderType == IMGFX_RENDER_MULTIPLY_SHADE_ALPHA)
            ) {
                gDPScrollMultiTile2_4b(gMainGfxPos++,
                    imgfx_currentImage->raster, G_IM_FMT_CI,
                    imgfx_currentImage->width, imgfx_currentImage->height, // img size
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

                if ((gSpriteShadingProfile->flags & 2) && ((*ImgfxInstances)[0].arrayIdx != 0) && (state->flags & someFlags)) {
                    cam = &gCameras[gCurrentCamID];

                    if (gGameStatusPtr->isBattle == 2) {
                        gSPViewport(gMainGfxPos++, &D_8014EE50);
                    } else {
                        gSPViewport(gMainGfxPos++, &cam->vpAlt);
                    }

                    gDPSetRenderMode(gMainGfxPos++, G_RM_PASS, state->otherModeL);

                    if (alpha == -1) {
                        gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, 0, SHADE, 0, TEXEL1, 0, 0, 0, 0, 0, 0,
                                            0, 0, COMBINED);
                    } else {
                        gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, alpha);
                        gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, 0, ENVIRONMENT, 0, TEXEL1, 0, 0, 0, 0,
                                            0, 0, 0, 0, COMBINED);
                    }

                    gSPVertex(gMainGfxPos++, &imgfx_vtxBuf[i], 4, 0);
                    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
                    gDPPipeSync(gMainGfxPos++);
                }
                create_shading_palette(mtx, uls, ult, lrs, lrt, alpha, state->otherModeL);
            } else {
                gDPScrollTextureTile_4b(gMainGfxPos++,
                    imgfx_currentImage->raster, G_IM_FMT_CI,
                    imgfx_currentImage->width, imgfx_currentImage->height, // img size
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
                        gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, 0, ENVIRONMENT, 0, TEXEL0, 0, 0, 0, 0, 0,
                                        ENVIRONMENT, 0, TEXEL0, 0);
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
                    gDPSetCombineLERP(gMainGfxPos++, SHADE, ENVIRONMENT, TEXEL0, TEXEL0, 0, 0, 0, TEXEL0, SHADE,
                                    ENVIRONMENT, TEXEL0, TEXEL0, 0, 0, 0, TEXEL0);
                    gDPSetColorDither(gMainGfxPos++, G_CD_MAGICSQ);
                }
            }
        }

        if ((gSpriteShadingProfile->flags & 2) && (*ImgfxInstances)[0].arrayIdx != 0 && (state->flags & someFlags)) {
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

void func_8013DAB4(ImgfxState* state, Matrix4f mtx) {
    s32 i, j;
    s32 firstVtxIdx;

    if (!(state->flags & IMGFX_STATE_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, imgfx_currentImage->palette);
    }

    firstVtxIdx = state->firstVtxIdx;
    for (i = 0; i < state->subdivY; i++) {
        for (j = 0; j < state->subdivX; j++) {
            s32 ulIdx = firstVtxIdx + i * (state->subdivX + 1) + j;
            s32 urIdx = firstVtxIdx + i * (state->subdivX + 1) + j + 1;
            s32 llIdx = firstVtxIdx + (i + 1) * (state->subdivX + 1) + j;
            s32 lrIdx = firstVtxIdx + (i + 1) * (state->subdivX + 1) + j + 1;
            if (!(state->flags & IMGFX_STATE_FLAG_SKIP_TEX_SETUP)) {
                if ((gSpriteShadingProfile->flags & 1) &&
                    (*ImgfxInstances)[0].arrayIdx != 0 &&
                    (state->flags & (IMGFX_STATE_FLAG_100000 | IMGFX_STATE_FLAG_80000)) &&
                    (state->renderType == IMGFX_RENDER_DEFAULT
                    || state->renderType == IMGFX_RENDER_MULTIPLY_ALPHA
                    || state->renderType == IMGFX_RENDER_MULTIPLY_SHADE_ALPHA)) {
                    s32 alpha = 255;
                    gDPScrollMultiTile2_4b(gMainGfxPos++,
                        imgfx_currentImage->raster, G_IM_FMT_CI,
                        imgfx_currentImage->width, imgfx_currentImage->height, // img size
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
                        imgfx_currentImage->raster, G_IM_FMT_CI,
                        imgfx_currentImage->width, imgfx_currentImage->height, // img size
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

void func_8013E2F0(ImgfxState* state, Matrix4f mtx) {
    if (state->vtxBufs[gCurrentDisplayContextIndex] == NULL || state->gfxBufs[gCurrentDisplayContextIndex] == NULL) {
        return;
    }

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], 0.1f, 0.1f, 0.1f);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (!(state->flags & IMGFX_STATE_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, imgfx_currentImage->palette);
        if ((gSpriteShadingProfile->flags & 1)
            && (state->flags & (IMGFX_STATE_FLAG_100000 | IMGFX_STATE_FLAG_80000))
            && (state->renderType == IMGFX_RENDER_DEFAULT
                || state->renderType == IMGFX_RENDER_MULTIPLY_ALPHA
                || state->renderType == IMGFX_RENDER_MULTIPLY_SHADE_ALPHA
                || state->renderType == IMGFX_RENDER_ANIM)
        ) {
            s32 alpha = 255;
            gDPScrollMultiTile2_4b(gMainGfxPos++, imgfx_currentImage->raster, G_IM_FMT_CI,
                                    imgfx_currentImage->width, imgfx_currentImage->height,
                                    0, 0, imgfx_currentImage->width - 1, imgfx_currentImage->height - 1, 0,
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
            create_shading_palette(mtx, 0, 0, imgfx_currentImage->width, imgfx_currentImage->height, alpha, state->otherModeL);
        } else {
            gDPScrollTextureTile_4b(gMainGfxPos++, imgfx_currentImage->raster, G_IM_FMT_CI,
                                    imgfx_currentImage->width, imgfx_currentImage->height,
                                    0, 0, imgfx_currentImage->width - 1, imgfx_currentImage->height - 1, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD,
                                    256, 256);
        }
    }
    gSPDisplayList(gMainGfxPos++, state->gfxBufs[gCurrentDisplayContextIndex]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void func_8013E904(ImgfxState* state, Matrix4f mtx) {
    UnkImgfxStruct* ufs = state->ints.overlay.pattern;
    s32 shifts = integer_log(ufs->width, 2);
    s32 shiftt = integer_log(ufs->height, 2);
    s32 uls, ult;
    s32 lrs, lrt;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (f32)imgfx_currentImage->width / 100.0, (f32)imgfx_currentImage->height / 100.0, 1.0f);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_XLU_DECAL, G_RM_ZB_XLU_DECAL2);

    if (state->renderType == IMGFX_RENDER_OVERLAY_RGBA) {
        s32 alpha = state->ints.overlay.alpha;
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
        gDPSetCombineLERP(gMainGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0);
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

void imgfx_wavy_init(ImgfxState* state) {
    state->floats.wavy.phase1 = 0.0f;
    state->floats.wavy.phase2 = 50.0f;
    state->floats.wavy.phase3 = 30.0f;
}

void imgfx_mesh_wavy_update(ImgfxState* state) {
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

void imgfx_mesh_load_colors(ImgfxState* state) {
    f32 alpha = (f32)imgfx_currentImage->alphaMultiplier / 255.0;
    s32 vtxCount = state->lastVtxIdx - state->firstVtxIdx;
    s32 i;

    for (i = 0; i <= vtxCount; i++) {
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[0] = state->colorBuf[i].r;
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[1] = state->colorBuf[i].g;
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[2] = state->colorBuf[i].b;
        imgfx_vtxBuf[state->firstVtxIdx + i].v.cn[3] = state->colorBuf[i].a * alpha;
    }
}
