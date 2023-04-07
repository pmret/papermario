#include "common.h"
#include "ld_addrs.h"
#include "sprite.h"

#if VERSION_IQUE
// TODO: remove if section is split in iQue release
extern Addr fold_gfx_data_ROM_START;
#endif

typedef union FoldIntVars {
    s32 raw[2][4];
    Color4i color[2];
    s32 savedArgs[2][4];
    struct {
        s32 type;
    } anim;
    struct {
        Vec3i mag;
    } wavy;
    struct {
        char unk_00[0x10];
        s32 mode;
        s32 noiseAmt;
        char unk_18[4];
        s32 alphaAmt;
    } hologram;
} FoldIntVars;

typedef union FoldFloatVars {
    f32 raw[2][4];
    struct {
        f32 curFrame;
        f32 curIdx;
    } anim;
    struct {
        f32 phase1;
        f32 phase2;
        f32 phase3;
    } wavy;
} FoldFloatVars;

typedef struct {
    /* 0x00 */ u8 arrayIdx;
    /* 0x01 */ u8 meshType;
    /* 0x02 */ u8 renderType;
    /* 0x03 */ u8 subdivX;
    /* 0x04 */ u8 subdivY;
    /* 0x05 */ s8 savedType1;
    /* 0x06 */ s8 savedType2;
    /* 0x07 */ char unk_07[0x1];
    /* 0x08 */ u16 firstVtxIdx;
    /* 0x0A */ u16 lastVtxIdx;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ s32 flags;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ FoldIntVars ints;
    /* 0x3C */ FoldFloatVars floats;
    /* 0x5C */ Color_RGBA8* colorBuf;
    /* 0x60 */ u16 colorBufCount;
    /* 0x62 */ char unk_62[0x2];
    /* 0x64 */ u8* curAnimOffset;
    /* 0x68 */ Vtx* vtxBufs[2];
    /* 0x70 */ Gfx* gfxBufs[2];
    /* 0x78 */ s32 otherModeL;
} FoldState; // size = 0x7C

typedef struct FoldDataCache {
    /* 0x00 */ s32* data;
    /* 0x04 */ u8 staleCooldownTimer;
    /* 0x05 */ u8 usingContextualHeap;
    /* 0x06 */ char unk_06[0x2];
} FoldDataCache; // size = 0x8

typedef struct FoldAnimHeader {
    /* 0x00 */ s32 keyframesOffset;
    /* 0x04 */ Gfx* gfxOffset; // Gfx for creating mesh from vertices
    /* 0x08 */ u16 vtxCount; // conserved across keyframes
    /* 0x0A */ u16 gfxCount;
    /* 0x0C */ u16 keyframesCount;
    /* 0x0E */ u16 flags;
} FoldAnimHeader; // size = 0x10

enum FoldAnimFlags {
    FOLD_ANIM_FLAG_ABSOLUTE_COORDS  = 1, // image-relative (in percent) when unset
};

typedef struct FoldRenderMode {
    /* 0x0 */ s32 mode1;
    /* 0x4 */ s32 mode2;
    /* 0x8 */ u8 flags; // only checks TRUE so far. some kind of switch?
} FoldRenderMode; // size = 0xC

typedef struct UnkFoldStruct {
    /* 0x00 */ s32 raster;
    /* 0x04 */ s32 palette;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Gfx* unk_14;
} UnkFoldStruct; // size = 0x18

// 'compressed' vertex data for animated fold keyframes
typedef struct FoldVtx {
    /* 0x00 */ s16 ob[3];
    /* 0x06 */ u8 tc[2];
    /* 0x08 */ s8 cn[3];
    /* 0x0B */ char unk_0B;
} FoldVtx; // size = 0x0C

typedef FoldState FoldStateList[MAX_FOLD_STATES];

extern HeapNode heap_spriteHead;

// BSS
extern FoldImageRec D_80156920;
extern Vtx* D_80156948[2];
extern Vtx* fold_vtxBuf;
extern FoldStateList* D_80156954;
extern s8 D_80156958[2];
extern s32 D_80156960[2];
extern s32 D_80156968[2];
extern s8 D_80156970;
extern FoldAnimHeader FoldAnimHeaders[4];

// Data
FoldImageRec* fold_currentImage = &D_80156920;

u16 fold_vtxCount = 0;

Lights2 FoldLights = gdSPDefLights2(144, 144, 144, 255, 255, 255, 0, 0, 120, 255, 255, 255, 0, 0, 136);

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

u16 FoldVtxBufferCapacity = 300;

Gfx DefaultFoldSetupGfx[] = {
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 18,
                     G_AD_DISABLE | G_CD_DISABLE | G_TC_FILT | G_TF_BILERP | G_TP_PERSP),
    gsSPEndDisplayList(),
};

//TODO figure out bits
FoldRenderMode D_8014EE98[17] = {
    [FOLD_RENDER_TYPE_0]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_TYPE_1]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_TYPE_2]     { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_3]     { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_4]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_TYPE_5]     { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_6]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_TYPE_7]     { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_8]     { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_9]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_TYPE_A]     { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_B]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_HOLOGRAM]   { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_D]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_TYPE_E]     { 0x00441208, 0x00111208, FALSE },
    [FOLD_RENDER_TYPE_F]     { 0x00404B40, 0x00104B40, TRUE },
    [FOLD_RENDER_TYPE_10]    { 0x00441208, 0x00111208, FALSE },
};

// all relative to fold_gfx_data_ROM_START
s32 FoldAnimOffsets[] = {
    [FOLD_ANIM_SHOCK]                 0x14358,
    [FOLD_ANIM_SHIVER]                0x18200,
    [FOLD_ANIM_VERTICAL_PIPE_CURL]    0x1A858,
    [FOLD_ANIM_HORIZONTAL_PIPE_CURL]  0x1E830,
    [FOLD_ANIM_STARTLE]               0x29458,
    [FOLD_ANIM_FLUTTER_DOWN]          0x314E0,
    [FOLD_ANIM_UNFURL]                0x33498,
    [FOLD_ANIM_GET_IN_BED]            0x38988,
    [FOLD_ANIM_SPIRIT_CAPTURE]        0x39228,
    [FOLD_ANIM_UNUSED_1]              0x5B7A8,
    [FOLD_ANIM_UNUSED_2]              0x7CF10,
    [FOLD_ANIM_UNUSED_3]              0x86490,
    [FOLD_ANIM_TUTANKOOPA_GATHER]     0x96258,
    [FOLD_ANIM_TUTANKOOPA_SWIRL_2]    0xA1820,
    [FOLD_ANIM_TUTANKOOPA_SWIRL_1]    0xACDE8,
    [FOLD_ANIM_SHUFFLE_CARDS]         0xBBF68,
    [FOLD_ANIM_FLIP_CARD_1]           0xC0490,
    [FOLD_ANIM_FLIP_CARD_2]           0xC49B8,
    [FOLD_ANIM_FLIP_CARD_3]           0xC6150,
    [FOLD_ANIM_CYMBAL_CRUSH]          0xCA380,
};

extern FoldDataCache fold_gfxDataCache[8];

void fold_clear_state_gfx(FoldState* state);
void fold_clear_state_data(FoldState* state);
void fold_init_state(FoldState* state);
void func_8013B0EC(FoldState* state);
void func_8013B1B0(FoldState* state, Matrix4f mtx);
void fold_mesh_make_strip(FoldState* state);
void fold_mesh_make_grid(FoldState* state);
//FoldAnimHeader* fold_load_anim(FoldState* state);
void fold_mesh_anim_update(FoldState* state);
void func_8013CFA8(FoldState*, Matrix4f mtx);
void func_8013DAB4(FoldState*, Matrix4f mtx);
void func_8013E2F0(FoldState*, Matrix4f mtx);
void func_8013E904(FoldState*, Matrix4f mtx);
void fold_wavy_init(FoldState* state);
void fold_mesh_wavy_update(FoldState* state);
void fold_mesh_load_colors(FoldState* state);

void fold_set_vtx_buf_capacity(s16 arg0) {
    FoldVtxBufferCapacity = arg0;
}

void fold_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156948); i++) {
        D_80156948[i] = _heap_malloc(&heap_spriteHead, FoldVtxBufferCapacity * sizeof(Vtx));
    }

    D_80156954 = (FoldStateList*)_heap_malloc(&heap_spriteHead, ARRAY_COUNT(*D_80156954) * sizeof((*D_80156954)[0]));

    for (i = 0; i < ARRAY_COUNT(*D_80156954); i++) {
        fold_init_state(&(*D_80156954)[i]);
        fold_clear_state_data(&(*D_80156954)[i]);
    }

    for (i = 0; i < ARRAY_COUNT(D_80156958); i++) {
        D_80156958[i] = -1;
        D_80156960[i] = 0;
        D_80156968[i] = 0;
        D_80156970 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(fold_gfxDataCache); i++) {
        fold_gfxDataCache[i].data = NULL;
        fold_gfxDataCache[i].staleCooldownTimer = 0;
        fold_gfxDataCache[i].usingContextualHeap = FALSE;
    }

    fold_vtxCount = 0;
    fold_vtxBuf = D_80156948[gCurrentDisplayContextIndex];
}

void func_8013A4D0(void) {
    s32 i;

    fold_vtxBuf = D_80156948[gCurrentDisplayContextIndex];
    fold_vtxCount = 0;
    fold_init_state(&(*D_80156954)[0]);

    (*D_80156954)[0].flags |= FOLD_STATE_FLAG_ENABLED;

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (((*D_80156954)[i].flags & FOLD_STATE_FLAG_ENABLED) && (*D_80156954)[i].savedType1 != FOLD_UPD_SET_ANIM) {
            fold_clear_state_gfx(&(*D_80156954)[i]);
        }
    }

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if ((*D_80156954)[i].flags & FOLD_STATE_FLAG_ENABLED && (*D_80156954)[i].colorBuf != NULL) {
            if ((*D_80156954)[i].savedType2 == FOLD_UPD_COLOR_BUF_SET_B) {
                continue;
            }
            if ((*D_80156954)[i].savedType2 == FOLD_UPD_COLOR_BUF_SET_C) {
                continue;
            }
            general_heap_free((*D_80156954)[i].colorBuf);
            (*D_80156954)[i].colorBuf = NULL;
            (*D_80156954)[i].colorBufCount = 0;
        }
    }
}

void fold_add_to_gfx_cache(void* data, s8 usingContextualHeap) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(fold_gfxDataCache); i++) {
        if (fold_gfxDataCache[i].data == NULL) {
            fold_gfxDataCache[i].data = data;
            fold_gfxDataCache[i].staleCooldownTimer = 4;
            fold_gfxDataCache[i].usingContextualHeap = usingContextualHeap;
            return;
        }
    }
}

void fold_update_gfx_cache(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(fold_gfxDataCache); i++) {
        if (fold_gfxDataCache[i].data != NULL) {
            fold_gfxDataCache[i].staleCooldownTimer--;

            if (fold_gfxDataCache[i].staleCooldownTimer == 0) {
                if (fold_gfxDataCache[i].usingContextualHeap) {
                    heap_free(fold_gfxDataCache[i].data);
                    fold_gfxDataCache[i].data = NULL;
                } else {
                    general_heap_free(fold_gfxDataCache[i].data);
                    fold_gfxDataCache[i].data = NULL;
                }

                fold_gfxDataCache[i].staleCooldownTimer = 0;
                fold_gfxDataCache[i].usingContextualHeap = FALSE;
            }
        }
    }
}

void func_8013A6E8(void) {
    fold_update_gfx_cache();
}

s32 func_8013A704(s32 arg0) {
    s32 count;
    s32 cond;
    s32 iPrev;
    s32 ret;
    s32 i;

    count = 0;
    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (!((*D_80156954)[i].flags & FOLD_STATE_FLAG_ENABLED)) {
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
    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (!((*D_80156954)[i].flags & FOLD_STATE_FLAG_ENABLED)) {
            if (!cond) {
                ret = i;
                cond = TRUE;
            } else {
                (*D_80156954)[iPrev].unk_10 = i;
            }

            (*D_80156954)[i].arrayIdx = i;
            fold_init_state(&(*D_80156954)[i]);
            count++;
            (*D_80156954)[i].flags |= FOLD_STATE_FLAG_ENABLED;
            iPrev = i;
            if (count == arg0) {
                (*D_80156954)[i].unk_10 = -1;
                break;
            }
        }
    }

    return ret;
}

void func_8013A854(u32 idx) {
    if (idx < MAX_FOLD_STATES) {
        (*D_80156954)[idx].flags = 0;
        (*D_80156954)[idx].unk_10 = -1;
    }
}

void func_8013A888(u32 idx) {
    if (idx < MAX_FOLD_STATES) {
        s32 temp_s0;

        do {
            temp_s0 = (*D_80156954)[idx].unk_10;
            func_8013A854(idx);
            idx = temp_s0;
        } while (temp_s0 != -1);
    }
}

s16 func_8013A8E0(s32 idx) {
    if (idx < 0 || idx >= MAX_FOLD_STATES) {
        return -1;
    }

    if (idx >= MAX_FOLD_STATES) {
        return 0xFF;
    } else {
        return (*D_80156954)[idx].unk_10;
    }
}

FoldState* fold_get_state(s32 idx) {
    return &(*D_80156954)[idx];
}

void fold_clear_state_gfx(FoldState* state) {
    if (state->curAnimOffset != NULL) {
        state->curAnimOffset = NULL;
    }
    if (state->vtxBufs[0] != NULL) {
        fold_add_to_gfx_cache(state->vtxBufs[0], TRUE);
        state->vtxBufs[0] = NULL;
    }
    if (state->vtxBufs[1] != NULL) {
        fold_add_to_gfx_cache(state->vtxBufs[1], TRUE);
        state->vtxBufs[1] = NULL;
    }
    if (state->gfxBufs[0] != NULL) {
        fold_add_to_gfx_cache(state->gfxBufs[0], TRUE);
        state->gfxBufs[0] = NULL;
    }
    if (state->gfxBufs[1] != NULL) {
        fold_add_to_gfx_cache(state->gfxBufs[1], TRUE);
        state->gfxBufs[1] = NULL;
    }
}

void fold_clear_state_data(FoldState* state) {
    state->curAnimOffset = NULL;
    state->vtxBufs[0] = NULL;
    state->vtxBufs[1] = NULL;
    state->gfxBufs[0] = NULL;
    state->gfxBufs[1] = NULL;
    state->colorBuf = NULL;
    state->colorBufCount = 0;
}

void fold_init_state(FoldState* state) {
    s32 i;
    s32 j;

    state->unk_10 = -1;
    state->savedType1 = FOLD_UPD_CLEAR;
    state->savedType2 = FOLD_UPD_CLEAR;
    state->flags = 0;
    state->meshType = FOLD_MESH_TYPE_0;
    state->renderType = FOLD_RENDER_TYPE_0;
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

void fold_update(u32 idx, FoldType type, s32 foldArg1, s32 foldArg2, s32 foldArg3, s32 foldArg4, s32 flags) {
    FoldState* state = &(*D_80156954)[idx];
    s32 oldFlags;
    s32 t1;
    u8 r, g, b, a;

    if (!(state->flags & FOLD_STATE_FLAG_ENABLED) || (idx >= MAX_FOLD_STATES)) {
        return;
    }

    switch (type) {
        case FOLD_UPD_CLEAR:
        case FOLD_TYPE_3:
            oldFlags = state->flags;
            fold_clear_state_gfx(state);
            fold_init_state(state);
            state->flags = oldFlags;
            state->savedType1 = FOLD_UPD_CLEAR;
            state->savedType2 = FOLD_UPD_CLEAR;
            state->meshType = FOLD_MESH_TYPE_0;
            state->renderType = FOLD_RENDER_TYPE_0;
            state->ints.raw[0][0] = -1;
            state->ints.raw[1][0] = -1;

            state->flags &= FOLD_STATE_FLAG_ENABLED;
            if (flags != 0) {
                state->flags |= flags;
            } else {
                state->flags |= flags; // required to match
            }
            return;
        case FOLD_TYPE_1:
            state->savedType1 = FOLD_UPD_CLEAR;
            state->renderType = FOLD_RENDER_TYPE_0;
            state->ints.raw[0][0] = -1;
            return;
        case FOLD_TYPE_2:
            state->savedType2 = FOLD_UPD_CLEAR;
            state->meshType = FOLD_MESH_TYPE_0;
            state->ints.raw[1][0] = -1;
            return;
        case FOLD_UPD_ALLOC_COLOR_BUF:
            if (state->colorBuf != NULL) {
                heap_free(state->colorBuf);
            }
            state->colorBufCount = foldArg1 * 4;
            state->colorBuf = heap_malloc(state->colorBufCount);
            return;
        case FOLD_TYPE_F:
        case FOLD_TYPE_10:
            if (type == state->savedType2 && foldArg1 == state->ints.raw[1][0] && foldArg2 == state->ints.raw[1][1]) {
                return;
            }
            break;
        case FOLD_UPD_SET_ANIM:
            if (state->savedType1 == type && state->ints.raw[0][0] == foldArg1 && state->ints.raw[0][1] == foldArg2 &&
                state->ints.raw[0][2] == foldArg3)
            {
                return;
            }
            break;
        default:
            if (type != FOLD_UPD_HOLOGRAM && state->savedType2 == FOLD_UPD_HOLOGRAM) {
                state->meshType = FOLD_MESH_TYPE_0;
                state->subdivX = 1;
                state->subdivY = 1;
            }
            break;
    }

    if (type != FOLD_UPD_SET_ANIM && state->savedType1 == FOLD_UPD_SET_ANIM) {
        state->savedType1 = FOLD_UPD_CLEAR;
    }

    if (type == FOLD_UPD_WAVY || type == FOLD_UPD_SET_ANIM) {
        state->savedType1 = type;
        state->ints.savedArgs[0][0] = foldArg1;
        state->ints.savedArgs[0][1] = foldArg2;
        state->ints.savedArgs[0][2] = foldArg3;
        state->ints.savedArgs[0][3] = foldArg4;
    } else if (type >= FOLD_UPD_SET_COLOR && type <= FOLD_TYPE_10) {
        state->savedType2 = type;
        state->ints.savedArgs[1][0] = foldArg1;
        state->ints.savedArgs[1][1] = foldArg2;
        state->ints.savedArgs[1][2] = foldArg3;
        state->ints.savedArgs[1][3] = foldArg4;
    }

    state->flags &= FOLD_STATE_FLAG_ENABLED;
    if (flags != 0) {
        state->flags |= flags;
    }
    state->meshType = FOLD_MESH_TYPE_0;

    switch (type) {
        case FOLD_TYPE_3:
            state->meshType = FOLD_MESH_TYPE_0;
            state->renderType = FOLD_RENDER_TYPE_0;
            break;
        case FOLD_UPD_WAVY:
            state->subdivX = 4;
            state->subdivY = 4;
            state->meshType = FOLD_MESH_TYPE_1;
            fold_wavy_init(state);
            break;
        case FOLD_UPD_SET_ANIM:
            state->meshType = FOLD_MESH_ANIMATED;
            state->renderType = FOLD_RENDER_TYPE_B;
            state->floats.anim.curFrame = 0.0f;
            state->floats.anim.curIdx = 0.0f;
            state->flags |= FOLD_STATE_FLAG_200;
            break;
        case FOLD_UPD_SET_COLOR:
        case FOLD_UPD_SET_ALPHA:
        case FOLD_UPD_SET_TINT:
            if (foldArg1 >= 255 && foldArg2 >= 255 && foldArg3 >= 255 && foldArg4 >= 255) {
                // no color + no transparency
                state->renderType = FOLD_RENDER_TYPE_0;
            } else if (foldArg4 >= 255) {
                // some color + no transparency
                state->renderType = FOLD_RENDER_TYPE_1;
            } else if (foldArg1 >= 255 && foldArg2 >= 255 && foldArg3 >= 255) {
                // no color + transparency
                state->renderType = FOLD_RENDER_TYPE_2;
            } else {
                // some color + transparency
                state->renderType = FOLD_RENDER_TYPE_3;
            }
            break;
        case FOLD_TYPE_9:
        case FOLD_TYPE_A:
            if (foldArg4 == 255.0) {
                state->renderType = FOLD_RENDER_TYPE_4;
            } else {
                state->renderType = FOLD_RENDER_TYPE_5;
            }
            break;
        case FOLD_UPD_COLOR_BUF_SET_B:
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

                state->meshType = FOLD_MESH_TYPE_0;

                if (a == 255) {
                    state->renderType = FOLD_RENDER_TYPE_6;
                } else {
                    state->renderType = FOLD_RENDER_TYPE_8;
                }
            }
            break;
        case FOLD_UPD_COLOR_BUF_SET_C:
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

                state->meshType = FOLD_MESH_TYPE_0;

                if (a == 255) {
                    state->renderType = FOLD_RENDER_TYPE_9;
                } else {
                    state->renderType = FOLD_RENDER_TYPE_A;
                }
            }
            break;
        case FOLD_UPD_HOLOGRAM:
            state->renderType = FOLD_RENDER_HOLOGRAM;
            break;
        case FOLD_TYPE_E:
            state->renderType = FOLD_RENDER_TYPE_D;
            break;
        case FOLD_TYPE_F:
        case FOLD_TYPE_10:
            state->meshType = FOLD_MESH_TYPE_4;
            if (foldArg2 >= 255) {
                state->renderType = FOLD_RENDER_TYPE_E;
            } else {
                state->renderType = FOLD_RENDER_TYPE_F;
            }
            state->floats.raw[1][0] = 0.0f;
            state->floats.raw[1][1] = 0.0f;
            break;
    }
}

void fold_set_state_flags(s32 idx, u16 flagBits, s32 mode) {
    if ((*D_80156954)[idx].flags & FOLD_STATE_FLAG_ENABLED) {
        if (mode) {
            (*D_80156954)[idx].flags |= flagBits;
        } else {
            (*D_80156954)[idx].flags &= ~flagBits;
        }
    }
}

s32 fold_appendGfx_component(s32 idx, FoldImageRecPart* image, u32 flagBits, Matrix4f mtx) {
    FoldState* state = &(*D_80156954)[idx];
    s32 ret = 0;

    if (image->opacity == 0) {
        return 0;
    }

    state->arrayIdx = idx;
    state->flags |= flagBits;
    fold_currentImage->raster = image->raster;
    fold_currentImage->palette = image->palette;
    fold_currentImage->width = image->width;
    fold_currentImage->height = image->height;
    fold_currentImage->xOffset = image->xOffset;
    fold_currentImage->yOffset =  image->yOffset;
    fold_currentImage->unk_18 = 0;
    fold_currentImage->unk_1E = 0;
    fold_currentImage->alphaMultiplier = image->opacity;

    if ((u32)idx >= MAX_FOLD_STATES) {
        return 0;
    }

    if (idx >= MAX_FOLD_STATES || state == NULL) {
        return 0;
    }

    func_8013B0EC(state);
    func_8013B1B0(state, mtx);

    if (state->flags & FOLD_STATE_FLAG_ANIM_DONE) {
        state->ints.raw[0][0] = -1;
        state->ints.raw[1][0] = -1;
        state->savedType1 = FOLD_UPD_CLEAR;
        state->meshType = 0;
        state->renderType = FOLD_RENDER_TYPE_0;
        state->flags &= ~(FOLD_STATE_FLAG_ANIM_DONE | FOLD_STATE_FLAG_800 | FOLD_STATE_FLAG_REVERSE_ANIM | FOLD_STATE_FLAG_LOOP_ANIM);
        fold_clear_state_gfx(state);
        ret = 1;
    } else if (state->flags & FOLD_STATE_FLAG_4000) {
        ret = 2;
    } else if (state->flags & FOLD_STATE_FLAG_20000) {
        state->savedType1 = FOLD_UPD_CLEAR;
        state->savedType2 = FOLD_UPD_CLEAR;
        state->meshType = FOLD_MESH_TYPE_0;
        state->renderType = FOLD_RENDER_TYPE_0;
        state->ints.raw[0][0] = -1;
        state->ints.raw[1][0] = -1;
        state->flags &= FOLD_STATE_FLAG_ENABLED;
        ret = 1;
    }
    return ret;
}

void func_8013B0EC(FoldState* state) {
    switch (state->meshType) {
        case FOLD_MESH_TYPE_3:
            if (state->ints.raw[1][2] == 0) {
                state->subdivX = 1;
                state->subdivY = 16;
            } else {
                state->subdivX = 1;
                state->subdivY = 1;
            }
        case FOLD_MESH_TYPE_1:
            fold_mesh_make_grid(state);
            break;
        case FOLD_MESH_ANIMATED:
            fold_mesh_anim_update(state);
            break;
        case FOLD_MESH_TYPE_0:
        case FOLD_MESH_TYPE_4:
            fold_mesh_make_strip(state);
            break;
        default:
            return;
    }

    if (state->savedType1 == FOLD_UPD_WAVY) {
        fold_mesh_wavy_update(state);
    }

    switch (state->savedType2) {
        case FOLD_UPD_COLOR_BUF_SET_B:
        case FOLD_UPD_COLOR_BUF_SET_C:
            fold_mesh_load_colors(state);
            break;
    }
}

void func_8013B1B0(FoldState* state, Matrix4f mtx) {
    s16 cond = FALSE;
    s32 primAlpha = state->ints.color[1].a;
    s32 renderType = state->renderType;
    s8 angle1;
    s8 angle2;
    f32 foldImgAlpha;
    FoldRenderMode* fold;
    s32 mode1;
    s32 mode2;
    s32 dirX1;
    s32 dirZ2;

    gDPPipeSync(gMainGfxPos++);

    if (!(state->flags & FOLD_STATE_FLAG_SKIP_GFX_SETUP)) {
        gSPDisplayList(gMainGfxPos++, DefaultFoldSetupGfx);
        if (state->flags & FOLD_STATE_FLAG_NO_FILTERING) {
            gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
        }
        if (state->flags & FOLD_STATE_FLAG_G_CULL_BACK) {
            gSPSetGeometryMode(gMainGfxPos++, G_CULL_BACK);
        }
        if (state->flags & FOLD_STATE_FLAG_G_CULL_FRONT) {
            gSPSetGeometryMode(gMainGfxPos++, G_CULL_FRONT);
        }

        fold = &D_8014EE98[state->renderType];

        mode1 = fold->mode1;
        mode2 = fold->mode2;
        if (fold->flags & FOLD_STATE_FLAG_ENABLED) {
            cond = TRUE;
        }

        foldImgAlpha = (f32) fold_currentImage->alphaMultiplier / 255.0;

        if (!cond && (fold_currentImage->alphaMultiplier < 255)) {
            state->ints.color[1].a = 255;
            switch (state->renderType) {
                case FOLD_RENDER_TYPE_0:
                case FOLD_RENDER_TYPE_B:
                    renderType = FOLD_RENDER_TYPE_2;
                    break;
                case FOLD_RENDER_TYPE_1:
                case FOLD_RENDER_TYPE_4:
                    renderType = FOLD_RENDER_TYPE_3;
                    break;
                case FOLD_RENDER_TYPE_9:
                    renderType = FOLD_RENDER_TYPE_A;
                    break;
            }
            primAlpha = state->ints.color[1].a * foldImgAlpha;
            //TODO figure out bits
            mode1 = 0x404B40;
            mode2 = 0x104B40;
            cond = TRUE;
        }

        if ((state->flags & FOLD_STATE_FLAG_400) && !cond) {
            mode1 &= ~CVG_DST_FULL;
            mode2 &= ~CVG_DST_FULL;
            mode1 |= (ALPHA_CVG_SEL | IM_RD);
            mode2 |= (ALPHA_CVG_SEL | IM_RD);
        }

        if (state->flags & FOLD_STATE_FLAG_40) {
            gSPClearGeometryMode(gMainGfxPos++, G_ZBUFFER);
        } else {
            gSPSetGeometryMode(gMainGfxPos++, G_ZBUFFER);
            if (cond) {
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
            case FOLD_RENDER_TYPE_1:
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color[1].r, state->ints.color[1].g,
                                state->ints.color[1].b, 0);
                break;
            case FOLD_RENDER_TYPE_2:
                if (primAlpha <= 0) {
                    return;
                }
                gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0,
                                  TEXEL0, 0, PRIMITIVE, 0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                break;
            case FOLD_RENDER_TYPE_3:
                if (primAlpha <= 0) {
                    return;
                }
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color[1].r, state->ints.color[1].g,
                                state->ints.color[1].b, primAlpha);
                break;
            case FOLD_RENDER_TYPE_4:
                gDPSetCombineLERP(gMainGfxPos++, 1, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0, 1, PRIMITIVE,
                                  TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color[1].r, state->ints.color[1].g,
                                state->ints.color[1].b, 0);
                break;
            case FOLD_RENDER_TYPE_5:
                if (primAlpha <= 0) {
                    return;
                }
                gDPSetCombineLERP(gMainGfxPos++, 1, 0, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 1, 0, TEXEL0,
                                  PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color[1].r, state->ints.color[1].g,
                                state->ints.color[1].b, primAlpha);
                break;
            case FOLD_RENDER_TYPE_6:
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case FOLD_RENDER_TYPE_9:
                gDPSetCombineLERP(gMainGfxPos++, 1, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0, 1, SHADE, TEXEL0, SHADE,
                                  0, 0, 0, TEXEL0);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case FOLD_RENDER_TYPE_7:
                gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0,
                                  SHADE, 0);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case FOLD_RENDER_TYPE_8:
                gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case FOLD_RENDER_TYPE_A:
                gDPSetCombineLERP(gMainGfxPos++, 1, SHADE, TEXEL0, SHADE, TEXEL0, 0, SHADE, 0, 1, SHADE, TEXEL0,
                                  SHADE, TEXEL0, 0, SHADE, 0);
                gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_SHADING_SMOOTH);
                gSPClearGeometryMode(gMainGfxPos++, G_LIGHTING);
                break;
            case FOLD_RENDER_TYPE_B:
                if (state->flags & (FOLD_STATE_FLAG_2000 | FOLD_STATE_FLAG_8000)) {
                    Camera* currentCam = &gCameras[gCurrentCameraID];

                    gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
                    gSPSetGeometryMode(gMainGfxPos++, G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);

                    angle1 = cosine(currentCam->currentYaw) * 120.0f;
                    angle2 = cosine(currentCam->currentYaw + 90.0f) * 120.0f;
                    dirX1 = -angle1;
                    dirZ2 = -angle2;
                    FoldLights.l[0].l.dir[0] = dirX1;
                    FoldLights.l[1].l.dir[0] = angle1;
                    FoldLights.l[0].l.dir[2] = angle2;
                    FoldLights.l[1].l.dir[2] = dirZ2;
                    gSPSetLights2(gMainGfxPos++, FoldLights);
                    break;
                }
                gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                break;
            case FOLD_RENDER_HOLOGRAM:
                if (state->ints.hologram.mode == 0) {
                    primAlpha = state->ints.hologram.alphaAmt * foldImgAlpha;
                    gDPSetCombineLERP(gMainGfxPos++, NOISE, PRIMITIVE, PRIMITIVE, TEXEL0, TEXEL0, 0, PRIMITIVE, 0,
                                      NOISE, PRIMITIVE, PRIMITIVE, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0,
                                    state->ints.hologram.noiseAmt,
                                    state->ints.hologram.noiseAmt,
                                    state->ints.hologram.noiseAmt,
                                    primAlpha);
                } else if (state->ints.hologram.mode == 1) {
                    primAlpha = state->ints.hologram.alphaAmt * foldImgAlpha;
                    gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0,
                                      TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_DITHER);
                } else if (state->ints.hologram.mode == 2) {
                    s32 blendAlpha = state->ints.hologram.alphaAmt + state->ints.hologram.noiseAmt;
                    if (blendAlpha > 255) {
                        blendAlpha = 255;
                    }

                    primAlpha = state->ints.hologram.alphaAmt * foldImgAlpha;
                    gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0,
                                      TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetAlphaDither(gMainGfxPos++, G_AD_NOISE);
                    gDPSetAlphaCompare(gMainGfxPos++, G_AC_THRESHOLD);
                    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, primAlpha);
                    gDPSetBlendColor(gMainGfxPos++, 0, 0, 0, blendAlpha);
                }
                break;
            case FOLD_RENDER_TYPE_D:
                gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0,
                                  TEXEL0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, state->ints.color[1].r, state->ints.color[1].g,
                                state->ints.color[1].b, 0);
                break;
            case FOLD_RENDER_TYPE_0:
            case FOLD_RENDER_TYPE_E:
            case FOLD_RENDER_TYPE_10:
                gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                break;
            case FOLD_RENDER_TYPE_F:
                gDPSetCombineLERP(gMainGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0,
                                  PRIMITIVE, 0);
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, state->ints.raw[1][1]);
                break;
        }
    }

    switch (state->meshType) {
        case FOLD_MESH_TYPE_0:
            func_8013CFA8(state, mtx);
            break;
        case FOLD_MESH_TYPE_1:
        case FOLD_MESH_TYPE_3:
            func_8013DAB4(state, mtx);
            break;
        case FOLD_MESH_ANIMATED:
            func_8013E2F0(state, mtx);
            break;
        case FOLD_MESH_TYPE_4:
            func_8013CFA8(state, mtx);
            gDPPipeSync(gMainGfxPos++);
            func_8013E904(state, mtx);
            break;
    }

    gDPPipeSync(gMainGfxPos++);

    if (state->renderType == FOLD_RENDER_HOLOGRAM) {
        gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
        gDPSetAlphaDither(gMainGfxPos++, G_AD_DISABLE);
    }
}

void fold_mesh_make_strip(FoldState* state) {
    s32 yOffset;
    s32 xOffset;
    s32 widthIncrement;
    s32 heightIncrement;
    s32 heightIncrement120;
    s32 temp2;
    s32 i;

    widthIncrement = 0x1000 / fold_currentImage->width;
    if (widthIncrement > fold_currentImage->height) {
        widthIncrement = fold_currentImage->height;
    }

    xOffset = fold_currentImage->xOffset;
    yOffset = fold_currentImage->yOffset;
    state->firstVtxIdx = fold_vtxCount;

    fold_vtxBuf[fold_vtxCount].v.ob[0] = xOffset;
    fold_vtxBuf[fold_vtxCount].v.ob[1] = yOffset;
    fold_vtxBuf[fold_vtxCount].v.ob[2] = 0;
    fold_vtxBuf[fold_vtxCount].v.tc[0] = 0x2000;
    fold_vtxBuf[fold_vtxCount].v.tc[1] = temp2 = 0x2000; // required to match
    fold_vtxBuf[fold_vtxCount].v.cn[0] = 240;
    fold_vtxBuf[fold_vtxCount].v.cn[1] = 240;
    fold_vtxBuf[fold_vtxCount].v.cn[2] = 240;
    fold_vtxBuf[fold_vtxCount + 1].v.ob[0] = fold_currentImage->width + xOffset;
    fold_vtxBuf[fold_vtxCount + 1].v.ob[1] = yOffset;
    fold_vtxBuf[fold_vtxCount + 1].v.ob[2] = 0;
    fold_vtxBuf[fold_vtxCount + 1].v.tc[0] = (fold_currentImage->width + 256) * 32;
    fold_vtxBuf[fold_vtxCount + 1].v.tc[1] = temp2;
    fold_vtxBuf[fold_vtxCount + 1].v.cn[0] = 120;
    fold_vtxBuf[fold_vtxCount + 1].v.cn[1] = 120;
    fold_vtxBuf[fold_vtxCount + 1].v.cn[2] = 120;

    for (i = widthIncrement; ; i += widthIncrement) {
        heightIncrement = (i * 120) / fold_currentImage->height;
        heightIncrement120 = heightIncrement + 120;
        fold_vtxCount += 2;
        fold_vtxBuf[fold_vtxCount].v.ob[0] = xOffset;
        fold_vtxBuf[fold_vtxCount].v.ob[1] = yOffset - widthIncrement;
        fold_vtxBuf[fold_vtxCount].v.ob[2] = 0;
        fold_vtxBuf[fold_vtxCount].v.tc[0] = 0x2000;
        fold_vtxBuf[fold_vtxCount].v.tc[1] = (i + 256) * 32;
        fold_vtxBuf[fold_vtxCount].v.cn[0] = heightIncrement120;
        fold_vtxBuf[fold_vtxCount].v.cn[1] = heightIncrement120;
        fold_vtxBuf[fold_vtxCount].v.cn[2] = heightIncrement120;
        fold_vtxBuf[fold_vtxCount + 1].v.ob[0] = fold_currentImage->width + xOffset;
        fold_vtxBuf[fold_vtxCount + 1].v.ob[1] = yOffset - widthIncrement;
        fold_vtxBuf[fold_vtxCount + 1].v.ob[2] = 0;
        fold_vtxBuf[fold_vtxCount + 1].v.tc[0] = (fold_currentImage->width + 256) * 32;
        fold_vtxBuf[fold_vtxCount + 1].v.tc[1] = (i + 256) * 32;
        fold_vtxBuf[fold_vtxCount + 1].v.cn[0] = heightIncrement;
        fold_vtxBuf[fold_vtxCount + 1].v.cn[1] = heightIncrement;
        fold_vtxBuf[fold_vtxCount + 1].v.cn[2] = heightIncrement;

        if (i != fold_currentImage->height) {
            yOffset -= widthIncrement;
            if (fold_currentImage->height < i + widthIncrement) {
                widthIncrement = fold_currentImage->height - i;
            }
        } else {
            fold_vtxCount += 2;
            break;
        }
    }

    state->lastVtxIdx = fold_vtxCount - 1;
    state->subdivX = 1;
    state->subdivY = ((state->lastVtxIdx - state->firstVtxIdx) - 1) / 2;
}

void fold_mesh_make_grid(FoldState* state) {
    f32 divSizeX;
    f32 divSizeY;
    f32 posX;
    f32 posY;
    f32 texU;
    f32 texV;
    Vtx* vtx;
    s32 i;

    state->firstVtxIdx = fold_vtxCount;
    divSizeX = fold_currentImage->width / (f32) state->subdivX;
    divSizeY = fold_currentImage->height / (f32) state->subdivY;
    posY = fold_currentImage->yOffset;
    texV = 0.0f;
    vtx = &fold_vtxBuf[fold_vtxCount];

    for (i = 0; i <= state->subdivY; i++) {
        s32 j;

        if (i == state->subdivY) {
            texV = fold_currentImage->height;
            posY = fold_currentImage->yOffset - fold_currentImage->height;
        }

        posX = fold_currentImage->xOffset;
        texU = 0.0f;
        for (j = 0; j <= state->subdivX; vtx++, j++) {
            if (j == state->subdivX) {
                texU = fold_currentImage->width;
                posX = fold_currentImage->xOffset + fold_currentImage->width;
            }
            vtx->n.ob[0] = posX;
            vtx->n.ob[1] = posY;
            vtx->n.ob[2] = 0;
            vtx->n.tc[0] = ((s32) texU + 256) * 32;
            vtx->n.tc[1] = ((s32) texV + 256) * 32;
            fold_vtxCount++;
            posX += divSizeX;
            texU += divSizeX;
        }
        posY -= divSizeY;
        texV += divSizeY;
    }
    state->lastVtxIdx = fold_vtxCount - 1;
}

FoldAnimHeader* fold_load_anim(FoldState* state) {
    u8* romStart = FoldAnimOffsets[state->ints.anim.type] + fold_gfx_data_ROM_START;
    FoldAnimHeader* anim = &FoldAnimHeaders[state->arrayIdx];

    if (state->curAnimOffset != romStart) {
        u8* romEnd;
        s32 i;

        state->curAnimOffset = romStart;

        dma_copy(state->curAnimOffset, state->curAnimOffset + sizeof(*anim), anim);

        if (state->vtxBufs[0] != NULL) {
            fold_add_to_gfx_cache(state->vtxBufs[0], 1);
            state->vtxBufs[0] = NULL;
        }
        if (state->vtxBufs[1] != NULL) {
            fold_add_to_gfx_cache(state->vtxBufs[1], 1);
            state->vtxBufs[1] = NULL;
        }
        if (state->gfxBufs[0] != NULL) {
            fold_add_to_gfx_cache(state->gfxBufs[0], 1);
            state->gfxBufs[0] = NULL;
        }
        if (state->gfxBufs[1] != NULL) {
            // fold_add_to_gfx_cache(state->gfxBufs[1], 1);
            romEnd = (u8*) state->gfxBufs[1]; // required to match
            fold_add_to_gfx_cache(state->gfxBufs[1], 1);
            state->gfxBufs[1] = NULL;
        }
        state->vtxBufs[0] = heap_malloc(anim->vtxCount * sizeof(Vtx));
        state->vtxBufs[1] = heap_malloc(anim->vtxCount * sizeof(Vtx));
        state->gfxBufs[0] = heap_malloc(anim->gfxCount * sizeof(Gfx));
        state->gfxBufs[1] = heap_malloc(anim->gfxCount * sizeof(Gfx));

        romStart = fold_gfx_data_ROM_START + (s32)anim->gfxOffset;
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
                    gfxBuffer[j-1].words.w1 = ((((s32) gfxBuffer[j-1].words.w1 - anim->keyframesOffset) / 3) * 4) +
                                              (s32) state->vtxBufs[i];
                }
            } while (cmd != G_ENDDL);
        }
    }

    return anim;
}

void fold_mesh_anim_update(FoldState* state) {
    s32 absKeyframeInterval;
    s32 nextKeyIdx;
    s32 curKeyIdx;
    FoldVtx* curKeyframe = NULL;
    FoldVtx* nextKeyframe = NULL;
    s32 keyframeInterval = state->ints.raw[0][1];
    s32 animStep = state->ints.raw[0][2];
    s32 curSubframe = state->floats.anim.curFrame;
    FoldAnimHeader* header = fold_load_anim(state);
    u8* romStart;
    f32 lerpAlpha;
    s32 i;

    if (header == NULL) {
        return;
    }

    if (state->flags & FOLD_STATE_FLAG_200) {
        state->flags &= ~FOLD_STATE_FLAG_200;
        if (state->flags & FOLD_STATE_FLAG_REVERSE_ANIM) {
            state->floats.anim.curIdx = header->keyframesCount - 1;
        }
    }
    curKeyIdx = state->floats.anim.curIdx;
    absKeyframeInterval = abs(keyframeInterval);
    if (state->flags & FOLD_STATE_FLAG_4000) {
        nextKeyIdx = curKeyIdx;
    } else {
        if (state->flags & FOLD_STATE_FLAG_REVERSE_ANIM) {
            nextKeyIdx = curKeyIdx - 1;
            if (nextKeyIdx < 0) {
                nextKeyIdx = curKeyIdx;
                if (state->flags & FOLD_STATE_FLAG_LOOP_ANIM) {
                    nextKeyIdx = header->keyframesCount - 1;
                }
            }
        } else {
            nextKeyIdx = curKeyIdx + 1;
            if (nextKeyIdx == header->keyframesCount) {
                nextKeyIdx = curKeyIdx;
                if (state->flags & FOLD_STATE_FLAG_LOOP_ANIM) {
                    nextKeyIdx = 0;
                }
            }
        }
    }

    // find the current + next keyframe vertex data
    curKeyframe = heap_malloc(header->vtxCount * sizeof(FoldVtx));
    romStart = (u8*)((s32)fold_gfx_data_ROM_START + header->keyframesOffset + curKeyIdx * header->vtxCount * sizeof(FoldVtx));
    dma_copy(romStart, romStart + header->vtxCount * sizeof(FoldVtx), curKeyframe);
    if (keyframeInterval > 1) {
        nextKeyframe = heap_malloc(header->vtxCount * sizeof(*nextKeyframe));
        romStart = (u8*)((s32)fold_gfx_data_ROM_START + header->keyframesOffset + nextKeyIdx * header->vtxCount * sizeof(FoldVtx));
        dma_copy(romStart, romStart + header->vtxCount * sizeof(FoldVtx), nextKeyframe);
    }

    lerpAlpha = (f32) curSubframe / (f32) keyframeInterval;
    for (i = 0; i < header->vtxCount; i++) {
        if (state->meshType != FOLD_MESH_ANIMATED) {
            return;
        }

        if (keyframeInterval > 1) {
            // get vertex position
            if (header->flags & FOLD_ANIM_FLAG_ABSOLUTE_COORDS) {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = (s16)(curKeyframe[i].ob[0] + (nextKeyframe[i].ob[0] - curKeyframe[i].ob[0]) * lerpAlpha);
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = (s16)(curKeyframe[i].ob[1] + (nextKeyframe[i].ob[1] - curKeyframe[i].ob[1]) * lerpAlpha);
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = (s16)(curKeyframe[i].ob[2] + (nextKeyframe[i].ob[2] - curKeyframe[i].ob[2]) * lerpAlpha);
            } else {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = (s16)(curKeyframe[i].ob[0] + (nextKeyframe[i].ob[0] - curKeyframe[i].ob[0]) * lerpAlpha) * 0.01 * fold_currentImage->width;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = (s16)(curKeyframe[i].ob[1] + (nextKeyframe[i].ob[1] - curKeyframe[i].ob[1]) * lerpAlpha) * 0.01 * fold_currentImage->height;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = (s16)(curKeyframe[i].ob[2] + (nextKeyframe[i].ob[2] - curKeyframe[i].ob[2]) * lerpAlpha) * 0.01 * ((fold_currentImage->width + fold_currentImage->height) / 2);
            }
            // get vertex color
            if (state->flags & (FOLD_STATE_FLAG_8000 | FOLD_STATE_FLAG_2000)) {
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
            if (header->flags & FOLD_ANIM_FLAG_ABSOLUTE_COORDS) {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = curKeyframe[i].ob[0];
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = curKeyframe[i].ob[1];
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = curKeyframe[i].ob[2];
            } else {
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[0] = curKeyframe[i].ob[0] * 0.01 * fold_currentImage->width;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[1] = curKeyframe[i].ob[1] * 0.01 * fold_currentImage->height;
                state->vtxBufs[gCurrentDisplayContextIndex][i].v.ob[2] = curKeyframe[i].ob[2] * 0.01 * ((fold_currentImage->width + fold_currentImage->height) / 2);
            }
            // get vertex color
            if (state->flags & (FOLD_STATE_FLAG_8000 | FOLD_STATE_FLAG_2000)) {
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
        if (header->flags & FOLD_ANIM_FLAG_ABSOLUTE_COORDS) {
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[0] = (curKeyframe[i].tc[0] + 256) * 32;
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[1] = (curKeyframe[i].tc[1] + 256) * 32;
        } else {
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[0] = ((s32)(curKeyframe[i].tc[0] * 0.01 * fold_currentImage->width) + 256) * 32;
            state->vtxBufs[gCurrentDisplayContextIndex][i].v.tc[1] = ((s32)(curKeyframe[i].tc[1] * 0.01 * fold_currentImage->height) + 256) * 32;
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
            if (state->flags & FOLD_STATE_FLAG_REVERSE_ANIM) {
                curKeyIdx--;
                if (curKeyIdx < 0) {
                    if (state->flags & FOLD_STATE_FLAG_LOOP_ANIM) {
                        curKeyIdx = header->keyframesCount - 1;
                    } else {
                        if (state->flags & FOLD_STATE_FLAG_800) {
                            curKeyIdx = 0;
                            state->flags |= FOLD_STATE_FLAG_4000;
                        } else {
                            state->flags |= FOLD_STATE_FLAG_ANIM_DONE;
                        }
                    }
                }
            } else {
                curKeyIdx++;
                if (curKeyIdx >= header->keyframesCount) {
                    if (state->flags & FOLD_STATE_FLAG_LOOP_ANIM) {
                        curKeyIdx = 0;
                    } else {
                        if (state->flags & FOLD_STATE_FLAG_800) {
                            curKeyIdx--;
                            state->flags |= FOLD_STATE_FLAG_4000;
                        } else {
                            state->flags |= FOLD_STATE_FLAG_ANIM_DONE;
                        }
                    }
                }
            }
            curSubframe = 0;
        }
    } else if (keyframeInterval < 0) {
        if (state->flags & FOLD_STATE_FLAG_REVERSE_ANIM) {
            curKeyIdx -= absKeyframeInterval;
            if (curKeyIdx < 0) {
                if (state->flags & FOLD_STATE_FLAG_LOOP_ANIM) {
                    curKeyIdx += header->keyframesCount;
                } else {
                    if (state->flags & FOLD_STATE_FLAG_800) {
                        curKeyIdx = 0;
                        state->flags |= FOLD_STATE_FLAG_4000;
                    } else {
                        state->flags |= FOLD_STATE_FLAG_ANIM_DONE;
                    }
                }
            }
        } else {
            curKeyIdx += absKeyframeInterval;
            if (curKeyIdx >= header->keyframesCount) {
                if (state->flags & FOLD_STATE_FLAG_LOOP_ANIM) {
                    curKeyIdx %= header->keyframesCount;
                } else {
                    if (state->flags & FOLD_STATE_FLAG_800) {
                        curKeyIdx = header->keyframesCount - 1;
                        state->flags |= FOLD_STATE_FLAG_4000;
                    } else {
                        state->flags |= FOLD_STATE_FLAG_ANIM_DONE;
                    }
                }
            }
        }
    }

    state->floats.anim.curFrame = curSubframe;
    state->floats.anim.curIdx = curKeyIdx;
}

void func_8013CFA8(FoldState* state, Matrix4f mtx) {
    s32 i;

    if (!(state->flags & FOLD_STATE_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, fold_currentImage->palette);
    }

    i = state->firstVtxIdx;

    while (TRUE) {
        Camera* cam;
        s32 uls = (fold_vtxBuf[i + 0].v.tc[0] >> 0x5) - 0x100;
        s32 ult = (fold_vtxBuf[i + 0].v.tc[1] >> 0x5) - 0x100;
        s32 lrs = (fold_vtxBuf[i + 3].v.tc[0] >> 0x5) - 0x100;
        s32 lrt = (fold_vtxBuf[i + 3].v.tc[1] >> 0x5) - 0x100;
        s32 someFlags = FOLD_STATE_FLAG_100000 | FOLD_STATE_FLAG_80000;
        s32 alpha;
        s32 alpha2;

        if (!(state->flags & FOLD_STATE_FLAG_SKIP_TEX_SETUP)) {
            if ((gSpriteShadingProfile->flags & 1)
                && (state->arrayIdx != 0)
                && (state->flags & someFlags)
                && (   state->renderType == FOLD_RENDER_TYPE_0
                    || state->renderType == FOLD_RENDER_TYPE_2
                    || state->renderType == FOLD_RENDER_TYPE_F
                    || state->renderType == FOLD_RENDER_TYPE_7)
            ) {
                gDPScrollMultiTile2_4b(gMainGfxPos++,
                    fold_currentImage->raster, G_IM_FMT_CI,
                    fold_currentImage->width, fold_currentImage->height, // img size
                    uls, ult, // top left
                    lrs - 1, lrt - 1, // bottom right
                    0, // palette
                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, // clamp wrap mirror
                    8, 8, // mask
                    G_TX_NOLOD, G_TX_NOLOD, // shift,
                    0x100, 0x100); // scroll
                gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOLOD);
                gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 252, 0);

                alpha = 255;
                switch (state->renderType) {
                    case FOLD_RENDER_TYPE_0:
                        break;
                    case FOLD_RENDER_TYPE_2:
                    case FOLD_RENDER_TYPE_F:
                        alpha = state->ints.color[1].a;
                        break;
                    case FOLD_RENDER_TYPE_7:
                        alpha = -1;
                        break;
                }

                if ((gSpriteShadingProfile->flags & 2) && (D_80156954[0][0].arrayIdx != 0) && (state->flags & someFlags)) {
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

                    gSPVertex(gMainGfxPos++, &fold_vtxBuf[i], 4, 0);
                    gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
                    gDPPipeSync(gMainGfxPos++);
                }
                create_shading_palette(mtx, uls, ult, lrs, lrt, alpha, state->otherModeL);
            } else {
                gDPScrollTextureTile_4b(gMainGfxPos++,
                    fold_currentImage->raster, G_IM_FMT_CI,
                    fold_currentImage->width, fold_currentImage->height, // img size
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
                        case FOLD_RENDER_TYPE_0:
                            alpha2 = 255;
                            break;
                        case FOLD_RENDER_TYPE_2:
                        case FOLD_RENDER_TYPE_F:
                            alpha2 = state->ints.color[1].a;
                            break;
                        case FOLD_RENDER_TYPE_7:
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

                    gSPVertex(gMainGfxPos++, &fold_vtxBuf[i], 4, 0);
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

        if ((gSpriteShadingProfile->flags & 2) && D_80156954[0][0].arrayIdx != 0 && (state->flags & someFlags)) {
            cam = &gCameras[gCurrentCamID];
            if (gGameStatusPtr->isBattle == 2) {
                gSPViewport(gMainGfxPos++, &D_8014EE40);
                D_8014EE50.vp.vtrans[0] = D_8014EE40.vp.vtrans[0] + gGameStatusPtr->unk_82;
                D_8014EE50.vp.vtrans[1] = D_8014EE40.vp.vtrans[1] + gGameStatusPtr->unk_83;
            } else {
                gSPViewport(gMainGfxPos++, &cam->vp);
            }
        }

        gSPVertex(gMainGfxPos++, &fold_vtxBuf[i], 4, 0);
        gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);

        if (i + 3 >= state->lastVtxIdx) {
            break;
        }

        i += 2;
    }
}

void func_8013DAB4(FoldState* state, Matrix4f mtx) {
    s32 i, j;
    s32 firstVtxIdx;

    if (!(state->flags & FOLD_STATE_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, fold_currentImage->palette);
    }

    firstVtxIdx = state->firstVtxIdx;
    for (i = 0; i < state->subdivY; i++) {
        for (j = 0; j < state->subdivX; j++) {
            s32 ulIdx = firstVtxIdx + i * (state->subdivX + 1) + j;
            s32 urIdx = firstVtxIdx + i * (state->subdivX + 1) + j + 1;
            s32 llIdx = firstVtxIdx + (i + 1) * (state->subdivX + 1) + j;
            s32 lrIdx = firstVtxIdx + (i + 1) * (state->subdivX + 1) + j + 1;
            if (!(state->flags & FOLD_STATE_FLAG_SKIP_TEX_SETUP)) {
                if ((gSpriteShadingProfile->flags & 1) &&
                    (*D_80156954)[0].arrayIdx != 0 &&
                    (state->flags & (FOLD_STATE_FLAG_100000 | FOLD_STATE_FLAG_80000)) &&
                    (state->renderType == FOLD_RENDER_TYPE_0
                    || state->renderType == FOLD_RENDER_TYPE_2
                    || state->renderType == FOLD_RENDER_TYPE_7)) {
                    s32 alpha = 255;
                    gDPScrollMultiTile2_4b(gMainGfxPos++,
                        fold_currentImage->raster, G_IM_FMT_CI,
                        fold_currentImage->width, fold_currentImage->height, // img size
                        (fold_vtxBuf[ulIdx].v.tc[0] >> 5) - 0x100, (fold_vtxBuf[ulIdx].v.tc[1] >> 5) - 0x100, // top left
                        (fold_vtxBuf[lrIdx].v.tc[0] >> 5) - 0x100 - 1, (fold_vtxBuf[lrIdx].v.tc[1] >> 5) - 0x100 - 1, // bottom right
                        0, // palette
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, // clamp wrap mirror
                        8, 8, // mask
                        G_TX_NOLOD, G_TX_NOLOD, // shift,
                        0x100, 0x100); // scroll
                    gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                    gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 63 << 2, 0);
                    switch (state->renderType) {
                        case FOLD_RENDER_TYPE_0:
                            alpha = 255;
                            break;
                        case FOLD_RENDER_TYPE_2:
                            alpha = state->ints.color[1].a;
                            break;
                        case FOLD_RENDER_TYPE_7:
                            alpha = -1;
                            break;

                    }
                    create_shading_palette(mtx,
                                           (fold_vtxBuf[ulIdx].v.tc[0] >> 5) - 0x100, (fold_vtxBuf[ulIdx].v.tc[1] >> 5) - 0x100,
                                           (fold_vtxBuf[lrIdx].v.tc[0] >> 5) - 0x100, (fold_vtxBuf[lrIdx].v.tc[1] >> 5) - 0x100,
                                           alpha, state->otherModeL);
                } else {
                    gDPScrollTextureTile_4b(gMainGfxPos++,
                        fold_currentImage->raster, G_IM_FMT_CI,
                        fold_currentImage->width, fold_currentImage->height, // img size
                        (fold_vtxBuf[ulIdx].v.tc[0] >> 5) - 0x100, (fold_vtxBuf[ulIdx].v.tc[1] >> 5) - 0x100, // top left
                        (fold_vtxBuf[lrIdx].v.tc[0] >> 5) - 0x100 - 1, (fold_vtxBuf[lrIdx].v.tc[1] >> 5) - 0x100 - 1, // bottom right
                        0, // palette
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, // clamp wrap mirror
                        8, 8, // mask
                        G_TX_NOLOD, G_TX_NOLOD, // shift,
                        0x100, 0x100); // scroll
                }
            }

            gSPVertex(gMainGfxPos++, &fold_vtxBuf[ulIdx], 1, 0);
            gSPVertex(gMainGfxPos++, &fold_vtxBuf[urIdx], 1, 1);
            gSPVertex(gMainGfxPos++, &fold_vtxBuf[llIdx], 1, 2);
            gSPVertex(gMainGfxPos++, &fold_vtxBuf[lrIdx], 1, 3);
            gSP2Triangles(gMainGfxPos++, 0, 2, 1, 0, 1, 2, 3, 0);
        }
    }
}

void func_8013E2F0(FoldState* state, Matrix4f mtx) {
    if (state->vtxBufs[gCurrentDisplayContextIndex] == NULL || state->gfxBufs[gCurrentDisplayContextIndex] == NULL) {
        return;
    }

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], 0.1f, 0.1f, 0.1f);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (!(state->flags & FOLD_STATE_FLAG_SKIP_TEX_SETUP)) {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMainGfxPos++, 0, fold_currentImage->palette);
        if ((gSpriteShadingProfile->flags & 1)
            && (state->flags & (FOLD_STATE_FLAG_100000 | FOLD_STATE_FLAG_80000))
            && (state->renderType == FOLD_RENDER_TYPE_0
                || state->renderType == FOLD_RENDER_TYPE_2
                || state->renderType == FOLD_RENDER_TYPE_7
                || state->renderType == FOLD_RENDER_TYPE_B)
        ) {
            s32 alpha = 255;
            gDPScrollMultiTile2_4b(gMainGfxPos++, fold_currentImage->raster, G_IM_FMT_CI,
                                    fold_currentImage->width, fold_currentImage->height,
                                    0, 0, fold_currentImage->width - 1, fold_currentImage->height - 1, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD,
                                    256, 256);
            gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 2, 0,
                            G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(gMainGfxPos++, 2, 0, 0, 252, 0);

            switch (state->renderType) {
                case FOLD_RENDER_TYPE_0:
                case FOLD_RENDER_TYPE_B:
                    alpha = 255;
                    break;
                case FOLD_RENDER_TYPE_2:
                    alpha = state->ints.color[1].a;
                    break;
                case FOLD_RENDER_TYPE_7:
                    alpha = -1;
                    break;

            }
            create_shading_palette(mtx, 0, 0, fold_currentImage->width, fold_currentImage->height, alpha, state->otherModeL);
        } else {
            gDPScrollTextureTile_4b(gMainGfxPos++, fold_currentImage->raster, G_IM_FMT_CI,
                                    fold_currentImage->width, fold_currentImage->height,
                                    0, 0, fold_currentImage->width - 1, fold_currentImage->height - 1, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, 8, 8, G_TX_NOLOD, G_TX_NOLOD,
                                    256, 256);
        }
    }
    gSPDisplayList(gMainGfxPos++, state->gfxBufs[gCurrentDisplayContextIndex]);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void func_8013E904(FoldState* state, Matrix4f mtx) {
    UnkFoldStruct* ufs = (UnkFoldStruct*)state->ints.raw[1][0];
    s32 shifts = integer_log(ufs->width, 2);
    s32 shiftt = integer_log(ufs->height, 2);
    s32 uls, ult;
    s32 lrs, lrt;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (f32)fold_currentImage->width / 100.0, (f32)fold_currentImage->height / 100.0, 1.0f);
    gSPMatrix(gMainGfxPos++, VIRTUAL_TO_PHYSICAL(&gDisplayContext->matrixStack[gMatrixListPos++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gMainGfxPos++, G_RM_ZB_XLU_DECAL, G_RM_ZB_XLU_DECAL2);

    if (state->renderType == FOLD_RENDER_TYPE_F) {
        s32 temp = state->ints.raw[1][1];
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, temp);
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

    uls = state->floats.raw[1][0];
    ult = state->floats.raw[1][1];
    lrs = ufs->width * 4 + state->floats.raw[1][0];
    lrt = ufs->height * 4 + state->floats.raw[1][1];
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, uls, ult, lrs, lrt);

    state->floats.raw[1][0] = (s32)(state->floats.raw[1][0] + ufs->unk_0C) % (ufs->width * 4);
    state->floats.raw[1][1] = (s32)(state->floats.raw[1][1] + ufs->unk_10) % (ufs->height * 4);
    gSPDisplayList(gMainGfxPos++, ufs->unk_14);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void fold_wavy_init(FoldState* state) {
    state->floats.wavy.phase1 = 0.0f;
    state->floats.wavy.phase2 = 50.0f;
    state->floats.wavy.phase3 = 30.0f;
}

void fold_mesh_wavy_update(FoldState* state) {
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
        v1 = (Vtx*)((state->firstVtxIdx + i) * sizeof(Vtx) + (s32)fold_vtxBuf);
        vx = v1->v.ob[0];
        v1->v.ob[0] = (vx + (sin_rad(angle1) * state->ints.wavy.mag.x)); // @bug? should be sin_deg?

        v2 = (Vtx*)((state->firstVtxIdx + i) * sizeof(Vtx) + (s32)fold_vtxBuf);
        vy = v2->v.ob[1];
        v2->v.ob[1] = (vy + (sin_rad(angle2) * state->ints.wavy.mag.y));

        v3 = (Vtx*)((state->firstVtxIdx + i) * sizeof(Vtx) + (s32)fold_vtxBuf);
        vz = v3->v.ob[2];
        v3->v.ob[2] = (vz + (sin_rad(angle3) * state->ints.wavy.mag.z));

        angleInc++;
        if (i % (state->subdivX + 1) == 0) {
            angleInc = 0;
            sign = !sign;
        }
    }
}

void fold_mesh_load_colors(FoldState* state) {
    f32 alpha = (f32)fold_currentImage->alphaMultiplier / 255.0;
    s32 vtxCount = state->lastVtxIdx - state->firstVtxIdx;
    s32 i;

    for (i = 0; i <= vtxCount; i++) {
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[0] = state->colorBuf[i].r;
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[1] = state->colorBuf[i].g;
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[2] = state->colorBuf[i].b;
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[3] = state->colorBuf[i].a * alpha;
    }
}
