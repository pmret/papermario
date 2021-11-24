#include "common.h"
#include "ld_addrs.h"

typedef struct {
    /* 0x00 */ s8 arrayIdx;
    /* 0x01 */ u8 meshType;
    /* 0x02 */ s8 renderType;
    /* 0x03 */ u8 subdivX;
    /* 0x04 */ u8 subdivY;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ char unk_07[0x1];
    /* 0x08 */ u16 firstVtxIdx;
    /* 0x0A */ u16 lastVtxIdx;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ s32 flags;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ s32 unk_1C[2][4];
    /* 0x3C */ f32 unk_3C[2][4];
    /* 0x5C */ u8* buf;
    /* 0x60 */ u16 bufSize;
    /* 0x62 */ char unk_62[0x2];
    /* 0x64 */ s32* unk_64;
    /* 0x68 */ s32* unk_68[2];
    /* 0x70 */ s32* unk_70[2];
    /* 0x78 */ char unk_78[0x4];
} FoldState; // size = 0x7C

typedef struct FoldDataCache {
    /* 0x00 */ s32* data;
    /* 0x04 */ u8 staleCooldownTimer;
    /* 0x05 */ u8 usingContextualHeap;
    /* 0x06 */ char unk_06[0x2];
} FoldDataCache; // size = 0x8

typedef struct FoldImageRec {
    /* 0x00 */ s8* raster;
    /* 0x04 */ s8* palette;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ s16 xOffset;
    /* 0x0E */ s16 yOffset;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ char unk_11[0x7];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ char unk_1A[0x4];
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ char unk_20[0x4];
    /* 0x24 */ u8 gfxOtherModeD;
} FoldImageRec; // size = 0x25

typedef struct FoldGfxDescriptor {
    /* 0x00 */ Vtx* vtx;
    /* 0x04 */ Gfx* gfx;
    /* 0x08 */ u16 vtxCount;
    /* 0x0A */ u16 gfxCount;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ s8 unk_0D;
    /* 0x0E */ s8 unk_0E;
    /* 0x0F */ s8 unk_0F;
} FoldGfxDescriptor; // size = 0x10

typedef FoldState FoldStateList[90];

// BSS
extern FoldImageRec D_80156920; // todo not sure on the type
extern Vtx* D_80156948[2];
extern Vtx* fold_vtxBuf;
extern FoldStateList* D_80156954;
extern s8 D_80156958[2];
extern s32 D_80156960[2];
extern s32 D_80156968[2];
extern s8 D_80156970;
extern FoldGfxDescriptor fold_groupDescriptors[4];

// Data
FoldImageRec* fold_currentImage = &D_80156920;

u16 fold_vtxCount = 0;

// padding?
s16 D_8014EE16 = 0;

s32 D_8014EE18[] = { 0x90909000, 0x90909000, 0xFFFFFF00, 0xFFFFFF00, 0x00007800, 0x00000000, 0xFFFFFF00, 0xFFFFFF00,
                     0x00008800, 0x00000000,
                   };

s32 D_8014EE40[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, };

s32 D_8014EE50[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x02000000, };

u16 D_8014EE60 = 300;

// padding?
s16 D_8014EE62 = 0;
s16 D_8014EE64 = 0;
s16 D_8014EE66 = 0;

s32 D_8014EE68[] = { 0xD9FDF9FF, 0x00000000, 0xD9FFFFFF, 0x00200005, 0xD7000002, 0xFFFFFFFF, 0xE2001E01, 0x00000000,
                     0xE3000A11, 0x00082CF0, 0xDF000000, 0x00000000,
                   };

s32 D_8014EE98[] = { 0x00441208, 0x00111208, 0x00000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40,
                     0x01000000, 0x00404B40, 0x00104B40, 0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40,
                     0x00104B40, 0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40, 0x01000000,
                     0x00404B40, 0x00104B40, 0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40,
                     0x01000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40, 0x01000000, 0x00441208,
                     0x00111208, 0x00000000, 0x00441208, 0x00111208, 0x00000000, 0x00404B40, 0x00104B40, 0x01000000,
                     0x00441208, 0x00111208, 0x00000000,
                   };

s32 fold_groupOffsets[] = {
    0x00014358, 0x00018200, 0x0001A858, 0x0001E830, 0x00029458, 0x000314E0, 0x00033498, 0x00038988, 0x00039228,
    0x0005B7A8, 0x0007CF10, 0x00086490, 0x00096258, 0x000A1820, 0x000ACDE8, 0x000BBF68, 0x000C0490, 0x000C49B8,
    0x000C6150, 0x000CA380
};

extern FoldDataCache fold_gfxDataCache[8];

void fold_clear_state_gfx(FoldState*);
void fold_clear_state_data(FoldState*);
void fold_init_state(FoldState*);
void func_8013B0EC(FoldState* state);
void func_8013B1B0(FoldState* state, Matrix4f mtx);
void func_8013BC88(FoldState*);
void func_8013C048(FoldState*);
void fold_load_gfx(FoldState*);
void func_8013C3F0(FoldState*);
void func_8013EE68(FoldState*);
void func_8013F1F8(FoldState*);

void func_8013A370(s16 arg0) {
    D_8014EE60 = arg0;
}

void fold_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156948); i++) {
        D_80156948[i] = _heap_malloc(&gSpriteHeapPtr, D_8014EE60 * sizeof(*(D_80156948[0])));
    }

    D_80156954 = (FoldStateList*)_heap_malloc(&gSpriteHeapPtr, ARRAY_COUNT(*D_80156954) * sizeof((*D_80156954)[0]));

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

    (*D_80156954)[0].flags |= FOLD_STATE_FLAGS_1;

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (((*D_80156954)[i].flags & FOLD_STATE_FLAGS_1) && (*D_80156954)[i].unk_05 != 5) {
            fold_clear_state_gfx(&(*D_80156954)[i]);
        }
    }

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if ((*D_80156954)[i].flags & FOLD_STATE_FLAGS_1 && (*D_80156954)[i].buf != NULL) {
            s32 temp = (*D_80156954)[i].unk_06; // TODO find a better way to match

            if (temp == 11 || (*D_80156954)[i].unk_06 == 12) {
                continue;
            }

            general_heap_free((*D_80156954)[i].buf);
            (*D_80156954)[i].buf = NULL;
            (*D_80156954)[i].bufSize = 0;
        }
    }
}

void fold_add_to_gfx_cache(s32* data, s8 usingContextualHeap) {
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
        if (!((*D_80156954)[i].flags & FOLD_STATE_FLAGS_1)) {
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
        if (!((*D_80156954)[i].flags & FOLD_STATE_FLAGS_1)) {
            if (!cond) {
                ret = i;
                cond = TRUE;
            } else {
                (*D_80156954)[iPrev].unk_10 = i;
            }

            (*D_80156954)[i].arrayIdx = i;
            fold_init_state(&(*D_80156954)[i]);
            count++;
            (*D_80156954)[i].flags |= FOLD_STATE_FLAGS_1;
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
    if (idx < 90) {
        (*D_80156954)[idx].flags = FOLD_STATE_FLAGS_0;
        (*D_80156954)[idx].unk_10 = -1;
    }
}

void func_8013A888(u32 idx) {
    if (idx < 90) {
        s32 temp_s0;

        do {
            temp_s0 = (*D_80156954)[idx].unk_10;
            func_8013A854(idx);
            idx = temp_s0;
        } while (temp_s0 != -1);
    }
}

s16 func_8013A8E0(s32 idx) {
    // TODO find better match
    if ((u32)idx >= 90) {
        return -1;
    }

    if (idx >= 90) {
        return 0xFF;
    } else {
        return (*D_80156954)[idx].unk_10;
    }
}

FoldState* fold_get_state(s32 idx) {
    return &(*D_80156954)[idx];
}

void fold_clear_state_gfx(FoldState* state) {
    if (state->unk_64 != 0) {
        state->unk_64 = 0;
    }
    if (state->unk_68[0] != 0) {
        fold_add_to_gfx_cache(state->unk_68[0], 1);
        state->unk_68[0] = 0;
    }
    if (state->unk_68[1] != 0) {
        fold_add_to_gfx_cache(state->unk_68[1], 1);
        state->unk_68[1] = 0;
    }
    if (state->unk_70[0] != 0) {
        fold_add_to_gfx_cache(state->unk_70[0], 1);
        state->unk_70[0] = 0;
    }
    if (state->unk_70[1] != 0) {
        fold_add_to_gfx_cache(state->unk_70[1], 1);
        state->unk_70[1] = 0;
    }
}

void fold_clear_state_data(FoldState* state) {
    state->unk_64 = 0;
    state->unk_68[0] = 0;
    state->unk_68[1] = 0;
    state->unk_70[0] = 0;
    state->unk_70[1] = 0;
    state->buf = NULL;
    state->bufSize = 0;
}

void fold_init_state(FoldState* state) {
    s32 i;
    s32 j;

    state->unk_10 = -1;
    state->unk_05 = 0;
    state->unk_06 = 0;
    state->flags = FOLD_STATE_FLAGS_0;
    state->meshType = 0;
    state->renderType = 0;
    state->firstVtxIdx = 0;
    state->lastVtxIdx = 0;
    state->unk_0C = 0;
    state->unk_0E = 0;
    state->unk_1C[0][3] = 255;
    state->unk_1C[1][3] = 255;
    state->subdivX = 0;
    state->subdivY = 0;
    state->firstVtxIdx = 0;
    state->lastVtxIdx = 0;

    for (i = 0; i < ARRAY_COUNT(state->unk_1C); i++) {
        for (j = 0; j < ARRAY_COUNT(state->unk_1C[0]); j++) {
            state->unk_1C[i][j] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(state->unk_3C); i++) {
        for (j = 0; j < ARRAY_COUNT(state->unk_3C[0]); j++) {
            state->unk_3C[i][j] = 0;
        }
    }
}

void fold_update(u32 idx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    FoldState* state = &(*D_80156954)[idx];
    s32 oldFlags;
    s32 t1;

    if (!(state->flags & FOLD_STATE_FLAGS_1) || (idx >= 90)) {
        return;
    }

    switch (arg1) {
        case 0:
        case 3:
            oldFlags = state->flags;
            fold_clear_state_gfx(state);
            fold_init_state(state);
            state->flags = oldFlags;
            state->unk_05 = 0;
            state->unk_06 = 0;
            state->meshType = 0;
            state->renderType = 0;
            state->unk_1C[0][0] = -1;
            state->unk_1C[1][0] = -1;
            state->flags &= FOLD_STATE_FLAGS_1;

            if (arg6 != 0) {
                state->flags |= arg6;
            } else {
                state->flags = state->flags; // required to match
            }
            return;
        case 1:
            state->unk_05 = 0;
            state->renderType = 0;
            state->unk_1C[0][0] = -1;
            return;
        case 2:
            state->unk_06 = 0;
            state->meshType = 0;
            state->unk_1C[1][0] = -1;
            return;
        case 17:
            if (state->buf != NULL) {
                heap_free(state->buf);
            }
            state->bufSize = arg2 * 4;
            state->buf = heap_malloc(state->bufSize);
            return;
        case 15:
        case 16:
            if (arg1 == state->unk_06 && arg2 == state->unk_1C[1][0] && arg3 == state->unk_1C[1][1]) {
                return;
            }
            break;
        case 5:
            if (state->unk_05 == arg1 && state->unk_1C[0][0] == arg2 && state->unk_1C[0][1] == arg3 &&
                state->unk_1C[0][2] == arg4)
            {
                return;
            }
            break;
        default:
            if (arg1 != 0xD && state->unk_06 == 0xD) {
                state->meshType = 0;
                state->subdivX = 1;
                state->subdivY = 1;
            }
            break;
    }

    if (arg1 != 5 && state->unk_05 == 5) {
        state->unk_05 = 0;
    }

    if (arg1 == 4 || arg1 == 5) {
        state->unk_05 = arg1;
        state->unk_1C[0][0] = arg2;
        state->unk_1C[0][1] = arg3;
        state->unk_1C[0][2] = arg4;
        state->unk_1C[0][3] = arg5;
    } else if (arg1 >= 6 && arg1 <= 16) {
        state->unk_06 = arg1;
        state->unk_1C[1][0] = arg2;
        state->unk_1C[1][1] = arg3;
        state->unk_1C[1][2] = arg4;
        state->unk_1C[1][3] = arg5;
    }

    state->flags &= FOLD_STATE_FLAGS_1;
    if (arg6 != 0) {
        state->flags |= arg6;
    }
    state->meshType = 0;

    switch (arg1) {
        case 3:
            state->meshType = 0;
            state->renderType = 0;
            break;
        case 4:
            state->subdivX = 4;
            state->subdivY = 4;
            state->meshType = 1;
            func_8013EE48(state);
            break;
        case 5:
            state->meshType = 2;
            state->renderType = 0xB;
            state->unk_3C[0][0] = 0.0f;
            state->unk_3C[0][1] = 0.0f;
            state->flags |= FOLD_STATE_FLAGS_200;
            break;
        case 6:
        case 7:
        case 8:
            if (arg2 >= 0xFF && arg3 >= 0xFF && arg4 >= 0xFF && arg5 >= 0xFF) {
                state->renderType = 0;
            } else if (arg5 >= 0xFF) {
                state->renderType = 1;
            } else if (arg2 >= 0xFF && arg3 >= 0xFF && arg4 >= 0xFF) {
                state->renderType = 2;
            } else {
                state->renderType = 3;
            }
            break;
        case 9:
        case 10:
            if (arg5 == 255.0) {
                state->renderType = 4;
            } else {
                state->renderType = 5;
            }
            break;
        case 11:
            if (arg2 < state->bufSize) {
                t1 = (u32) arg3 >> 0x18; // required to match
                state->buf[arg2 * 4 + 0] = (u32) arg3 >> 0x18;
                state->buf[arg2 * 4 + 1] = (u32) arg3 >> 0x10;
                state->buf[arg2 * 4 + 2] = (u32) arg3 >> 0x08;
                do {
                    state->buf[arg2 * 4 + 3] = arg3;
                } while (0); // required to match

                state->meshType = 0;

                if ((arg3 & 0xFF) == 0xFF) {
                    state->renderType = 6;
                } else {
                    state->renderType = 8;
                }
            }
            break;
        case 12:
            if (arg2 < state->bufSize) {
                t1 = (u32) arg3 >> 0x18; // required to match
                state->buf[arg2 * 4 + 0] = t1;
                state->buf[arg2 * 4 + 1] = (u32) arg3 >> 0x10;
                state->buf[arg2 * 4 + 2] = (u32) arg3 >> 0x08;
                do {
                    state->buf[arg2 * 4 + 3] = arg3;
                } while (0); // required to match

                state->meshType = 0;

                if ((arg3 & 0xFF) == 0xFF) {
                    state->renderType = 9;
                } else {
                    state->renderType = 0xA;
                }
            }
            break;
        case 13:
            state->renderType = 0xC;
            break;
        case 14:
            state->renderType = 0xD;
            break;
        case 15:
        case 16:
            state->meshType = 4;
            if (arg3 >= 0xFF) {
                state->renderType = 0xE;
            } else {
                state->renderType = 0xF;
            }
            state->unk_3C[1][0] = 0.0f;
            state->unk_3C[1][1] = 0.0f;
            break;
    }
}

void fold_set_state_flags(s32 idx, u16 flagBits, s32 mode) {
    if ((*D_80156954)[idx].flags & FOLD_STATE_FLAGS_1) {
        if (mode) {
            (*D_80156954)[idx].flags |= flagBits;
        } else {
            (*D_80156954)[idx].flags &= ~flagBits;
        }
    }
}

s32 fold_appendGfx_component(s32 idx, FoldImageRec* image, u32 flagBits, Matrix4f mtx) {
    FoldState* state = &(*D_80156954)[idx];
    s32 ret = 0;

    if (image->unk_10 == 0) {
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
    fold_currentImage->gfxOtherModeD = image->unk_10;

    if ((u32)idx >= 90) {
        return 0;
    }

    if (idx >= 90 || state == NULL) {
        return 0;
    }

    func_8013B0EC(state);
    func_8013B1B0(state, mtx);

    if (state->flags & FOLD_STATE_FLAGS_1000) {
        state->unk_1C[0][0] = -1;
        state->unk_1C[1][0] = -1;
        state->unk_05 = 0;
        state->meshType = 0;
        state->renderType = 0;
        state->flags &= ~(FOLD_STATE_FLAGS_1000 | FOLD_STATE_FLAGS_800 | FOLD_STATE_FLAGS_100 | FOLD_STATE_FLAGS_80);
        fold_clear_state_gfx(state);
        ret = 1;
    } else if (state->flags & FOLD_STATE_FLAGS_4000) {
        ret = 2;
    } else if (state->flags & FOLD_STATE_FLAGS_20000) {
        state->unk_05 = 0;
        state->unk_06 = 0;
        state->meshType = 0;
        state->renderType = 0;
        state->unk_1C[0][0] = -1;
        state->unk_1C[1][0] = -1;
        state->flags &= FOLD_STATE_FLAGS_1;
        ret = 1;
    }
    return ret;
}

void func_8013B0EC(FoldState* state) {
    switch (state->meshType) {
        case 3:
            if (state->unk_1C[1][2] == 0) {
                state->subdivX = 1;
                state->subdivY = 16;
            } else {
                state->subdivX = 1;
                state->subdivY = 1;
            }
        case 1:
            func_8013C048(state);
            break;
        case 2:
            func_8013C3F0(state);
            break;
        case 0:
        case 4:
            func_8013BC88(state);
            break;
        default:
            return;
    }

    if (state->unk_05 == 4) {
        func_8013EE68(state);
    }

    switch (state->unk_06) {
        case 11:
        case 12:
            func_8013F1F8(state);
            break;
    }
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013B1B0);

void func_8013BC88(FoldState* state) {
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

void func_8013C048(FoldState* state) {
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

// Issues with the loop
#ifdef NON_EQUIVALENT
void fold_load_gfx(FoldState* state) {
    Gfx* temp_s0;
    Gfx* temp_s1_2;
    FoldGfxDescriptor* descriptor;
    s32* temp_s1;
    s32 startAddr = _24B7F0_ROM_START;
    Gwords* gfxPos;
    u32 gfxOp;
    s32 i;

    temp_s1 = fold_groupOffsets[state->unk_1C[0][0]] + startAddr;
    descriptor = &fold_groupDescriptors[(u8) state->arrayIdx];

    if (state->unk_64 != temp_s1) {
        state->unk_64 = temp_s1;

        dma_copy(state->unk_64, (s32)state->unk_64 + 0x10, descriptor);

        if (state->unk_68[0] != NULL) {
            fold_add_to_gfx_cache(state->unk_68[0], 1);
            state->unk_68[0] = NULL;
        }
        if (state->unk_68[1] != NULL) {
            fold_add_to_gfx_cache(state->unk_68[1], 1);
            state->unk_68[1] = NULL;
        }
        if (state->unk_70[0] != NULL) {
            fold_add_to_gfx_cache(state->unk_70[0], 1);
            state->unk_70[0] = NULL;
        }
        if (state->unk_70[1] != NULL) {
            fold_add_to_gfx_cache(state->unk_70[1], 1);
            state->unk_70[1] = NULL;
        }
        state->unk_68[0] = heap_malloc((u16) descriptor->vtxCount * 0x10);
        state->unk_68[1] = heap_malloc((u16) descriptor->vtxCount * 0x10);
        state->unk_70[0] = heap_malloc((u16) descriptor->gfxCount * 8);
        state->unk_70[1] = heap_malloc((u16) descriptor->gfxCount * 8);
        temp_s1_2 = (s32)descriptor->gfx + startAddr;
        temp_s0 = &temp_s1_2[descriptor->gfxCount];
        dma_copy(temp_s1_2, temp_s0, state->unk_70[0]);
        dma_copy(temp_s1_2, temp_s0, state->unk_70[1]);


        gfxPos = &state->unk_70[0]->words;

        for (i = 0; i < 2; i++) {
            gfxOp = state->unk_70[i]->words.w0;
            if (gfxOp >> 0x18 == 1) {
                state->unk_70[i]->words.w1 = (u32)(state->unk_68[i] + ((s32)(state->unk_70[i]->words.w1 - (s32)descriptor->vtx) / 3) * 4);
            }

            if (gfxOp != 0xDF) {
                break;
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "d0a70_len_4fe0", fold_load_gfx);
#endif

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013C3F0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013CFA8);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013DAB4);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013E2F0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013E904);

void func_8013EE48(FoldState* state) {
    state->unk_3C[0][0] = 0.0f;
    state->unk_3C[0][1] = 50.0f;
    state->unk_3C[0][2] = 30.0f;
}

// Float stuff
#ifdef NON_MATCHING
void func_8013EE68(FoldState* state) {
    Vtx* temp_s0;
    Vtx* temp_s0_2;
    Vtx* temp_s0_3;
    f32 temp_f0_7;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_fblah;
    f32 temp_f2;
    s32 temp_s5;
    f32 phi_f8;
    f32 phi_f6;
    f32 phi_f4;
    s32 phi_s3;
    s32 phi_s4;
    s32 i;

    phi_f8 = (f32) gGameStatusPtr->frameCounter / 10.3;
    while (phi_f8 > 360.0) {
        phi_f8 -= 360.0;
    }

    phi_f6 = (f32) (gGameStatusPtr->frameCounter + 40) / 11.2;
    while (phi_f6 > 360.0) {
        phi_f6 -= 360.0;
    }

    phi_f4 = (f32) (gGameStatusPtr->frameCounter + 25) / 10.8;
    while (phi_f4 > 360.0) {
        phi_f4 -= 360.0;
    }

    state->unk_3C[0][0] = phi_f8;
    state->unk_3C[0][1] = phi_f6;
    state->unk_3C[0][2] = phi_f4;

    if (state->unk_3C[0][0] >= 360.0) {
        state->unk_3C[0][0] -= 360.0;
    }

    if (state->unk_3C[0][1] >= 360.0) {
        state->unk_3C[0][1] -= 360.0;
    }

    if (state->unk_3C[0][2] >= 360.0) {
        state->unk_3C[0][2] -= 360.0;
    }

    phi_s4 = 0;
    phi_s3 = 0;
    temp_s5 = (state->lastVtxIdx - state->firstVtxIdx) - state->subdivX;
    for (i = 0; i < temp_s5; i++) {
        temp_f2 = phi_s3;
        temp_f0_7 = phi_s4 * 180;

        temp_fblah = state->unk_3C[0][0] + temp_f2 + temp_f0_7;
        temp_f22 = state->unk_3C[0][1] + temp_f2 + temp_f0_7;
        temp_f24 = state->unk_3C[0][2] + temp_f2 + temp_f0_7;

        temp_s0 = &fold_vtxBuf[state->firstVtxIdx + i];
        temp_f20 = temp_s0->v.ob[0];
        temp_s0->v.ob[0] = (temp_f20 + (sin_rad(temp_fblah) * state->unk_1C[0][0]));
        temp_s0_2 = &fold_vtxBuf[state->firstVtxIdx + i];
        temp_f20_2 = temp_s0_2->v.ob[1];
        temp_s0_2->v.ob[1] = (temp_f20_2 + (sin_rad(temp_f22) * state->unk_1C[0][1]));
        temp_s0_3 = &fold_vtxBuf[state->firstVtxIdx + i];
        temp_f20_3 = temp_s0_3->v.ob[2];
        temp_s0_3->v.ob[2] = (temp_f20_3 + (sin_rad(temp_f24) * state->unk_1C[0][2]));
        phi_s3 += 45;
        if ((i % (s32) (state->subdivX + 1)) == 0) {
            phi_s3 = 0;
            phi_s4 = !phi_s4;
        }
    }
}
#else
INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013EE68);
#endif

void func_8013F1F8(FoldState* state) {
    f32 alpha = (f32)fold_currentImage->gfxOtherModeD / 255.0;
    s32 vtxCount = state->lastVtxIdx - state->firstVtxIdx;
    s32 i;

    for (i = 0; i <= vtxCount; i++) {
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[0] = state->buf[i * 4 + 0];
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[1] = state->buf[i * 4 + 1];
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[2] = state->buf[i * 4 + 2];
        fold_vtxBuf[state->firstVtxIdx + i].v.cn[3] = state->buf[i * 4 + 3] * alpha;
    }
}
