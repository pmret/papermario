#include "common.h"

typedef struct {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s8 unk_02;
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
    /* 0x60 */ s16 bufSize;
    /* 0x62 */ char unk_62[0x2];
    /* 0x64 */ s32* unk_64;
    /* 0x68 */ s32* unk_68;
    /* 0x6C */ s32* unk_6C;
    /* 0x70 */ s32* unk_70;
    /* 0x74 */ s32* unk_74;
    /* 0x78 */ char unk_78[0x4];
} SpriteEffect; // size = 0x7C

typedef struct Unk8Struct {
    /* 0x00 */ s32* unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x2];
} Unk8Struct; // size = 0x8

typedef struct Unk10Struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
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
} Unk10Struct; // size = 0x25

typedef struct SprFXGfxDescriptor {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} SprFXGfxDescriptor; // size = 0x10

typedef SpriteEffect SpriteEffectList[90];

// BSS
extern Unk10Struct D_80156920; // todo not sure on the type
extern Vtx* D_80156948[2];
extern Vtx* sprfx_vtxBuf;
extern SpriteEffectList* D_80156954;
extern s8 D_80156958[2];
extern s32 D_80156960[2];
extern s32 D_80156968[2];
extern s8 D_80156970;

// Data
Unk10Struct* sprfx_currentImage = &D_80156920;

u16 sprfx_vtxCount = 0;

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

s32 D_8014EF64[] = { 0x00014358, 0x00018200, 0x0001A858, 0x0001E830, 0x00029458, 0x000314E0, 0x00033498, 0x00038988,
                     0x00039228, 0x0005B7A8, 0x0007CF10, 0x00086490, 0x00096258, 0x000A1820, 0x000ACDE8, 0x000BBF68,
                     0x000C0490, 0x000C49B8, 0x000C6150, 0x000CA380, 0x00000000, 0x00000000, 0x00000000,
                   };

extern Unk8Struct D_80156F20[8];

void sprfx_clear_effect_gfx(SpriteEffect*);
void sprfx_clear_effect_data(SpriteEffect*);
void sprfx_init_effect(SpriteEffect*);
void func_8013BC88(SpriteEffect*);
void func_8013C048(SpriteEffect*);
void sprfx_load_gfx(SpriteEffect*);
void func_8013C3F0(SpriteEffect*);
void func_8013EE68(SpriteEffect*);
void func_8013F1F8(SpriteEffect*);

void func_8013A370(s16 arg0) {
    D_8014EE60 = arg0;
}

void sprfx_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156948); i++) {
        D_80156948[i] = _heap_malloc(&gSpriteHeapPtr, D_8014EE60 * sizeof(*(D_80156948[0])));
    }

    D_80156954 = (SpriteEffectList*)_heap_malloc(&gSpriteHeapPtr, ARRAY_COUNT(*D_80156954) * sizeof((*D_80156954)[0]));

    for (i = 0; i < ARRAY_COUNT(*D_80156954); i++) {
        sprfx_init_effect(&(*D_80156954)[i]);
        sprfx_clear_effect_data(&(*D_80156954)[i]);
    }

    for (i = 0; i < ARRAY_COUNT(D_80156958); i++) {
        D_80156958[i] = -1;
        D_80156960[i] = 0;
        D_80156968[i] = 0;
        D_80156970 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(D_80156F20); i++) {
        D_80156F20[i].unk_00 = 0;
        D_80156F20[i].unk_04 = 0;
        D_80156F20[i].unk_05 = 0;
    }

    sprfx_vtxCount = 0;
    sprfx_vtxBuf = D_80156948[gCurrentDisplayContextIndex];
}

void func_8013A4D0(void) {
    s32 i;

    sprfx_vtxBuf = D_80156948[gCurrentDisplayContextIndex];
    sprfx_vtxCount = 0;
    sprfx_init_effect(&(*D_80156954)[0]);

    (*D_80156954)[0].flags |= 1;

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (((*D_80156954)[i].flags & 1) && (*D_80156954)[i].unk_05 != 5) {
            sprfx_clear_effect_gfx(&(*D_80156954)[i]);
        }
    }

    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if ((*D_80156954)[i].flags & 1 && (*D_80156954)[i].buf != NULL) {
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

void sprfx_add_to_gfx_cache(s32* data, s8 usingContextualHeap) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156F20); i++) {
        if (D_80156F20[i].unk_00 == NULL) {
            D_80156F20[i].unk_00 = data;
            D_80156F20[i].unk_04 = 4;
            D_80156F20[i].unk_05 = usingContextualHeap;
            return;
        }
    }
}

void sprfx_update_gfx_cache(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80156F20); i++) {
        if (D_80156F20[i].unk_00 != 0) {
            D_80156F20[i].unk_04--;

            if (D_80156F20[i].unk_04 == 0) {
                if (D_80156F20[i].unk_05 != 0) {
                    heap_free(D_80156F20[i].unk_00);
                    D_80156F20[i].unk_00 = NULL;
                } else {
                    general_heap_free(D_80156F20[i].unk_00);
                    D_80156F20[i].unk_00 = NULL;
                }

                D_80156F20[i].unk_04 = 0;
                D_80156F20[i].unk_05 = 0;
            }
        }
    }
}

void func_8013A6E8(void) {
    sprfx_update_gfx_cache();
}

s32 func_8013A704(s32 arg0) {
    s32 count;
    s32 cond;
    s32 iPrev;
    s32 ret;
    s32 i;

    count = 0;
    for (i = 1; i < ARRAY_COUNT(*D_80156954); i++) {
        if (!((*D_80156954)[i].flags & 1)) {
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
        if (!((*D_80156954)[i].flags & 1)) {
            if (!cond) {
                ret = i;
                cond = TRUE;
            } else {
                (*D_80156954)[iPrev].unk_10 = i;
            }

            (*D_80156954)[i].unk_00 = i;
            sprfx_init_effect(&(*D_80156954)[i]);
            count++;
            (*D_80156954)[i].flags |= 1;
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
        (*D_80156954)[idx].flags = 0;
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

SpriteEffect* sprfx_get_sprite_effect(s32 idx) {
    return &(*D_80156954)[idx];
}

void sprfx_clear_effect_gfx(SpriteEffect* effect) {
    if (effect->unk_64 != 0) {
        effect->unk_64 = 0;
    }
    if (effect->unk_68 != 0) {
        sprfx_add_to_gfx_cache(effect->unk_68, 1);
        effect->unk_68 = 0;
    }
    if (effect->unk_6C != 0) {
        sprfx_add_to_gfx_cache(effect->unk_6C, 1);
        effect->unk_6C = 0;
    }
    if (effect->unk_70 != 0) {
        sprfx_add_to_gfx_cache(effect->unk_70, 1);
        effect->unk_70 = 0;
    }
    if (effect->unk_74 != 0) {
        sprfx_add_to_gfx_cache(effect->unk_74, 1);
        effect->unk_74 = 0;
    }
}

void sprfx_clear_effect_data(SpriteEffect* effect) {
    effect->unk_64 = 0;
    effect->unk_68 = 0;
    effect->unk_6C = 0;
    effect->unk_70 = 0;
    effect->unk_74 = 0;
    effect->buf = NULL;
    effect->bufSize = 0;
}

void sprfx_init_effect(SpriteEffect* effect) {
    s32 i;
    s32 j;

    effect->unk_10 = -1;
    effect->unk_05 = 0;
    effect->unk_06 = 0;
    effect->flags = 0;
    effect->unk_01 = 0;
    effect->unk_02 = 0;
    effect->firstVtxIdx = 0;
    effect->lastVtxIdx = 0;
    effect->unk_0C = 0;
    effect->unk_0E = 0;
    effect->unk_1C[0][3] = 255;
    effect->unk_1C[1][3] = 255;
    effect->subdivX = 0;
    effect->subdivY = 0;
    effect->firstVtxIdx = 0;
    effect->lastVtxIdx = 0;

    for (i = 0; i < ARRAY_COUNT(effect->unk_1C); i++) {
        for (j = 0; j < ARRAY_COUNT(effect->unk_1C[0]); j++) {
            effect->unk_1C[i][j] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(effect->unk_3C); i++) {
        for (j = 0; j < ARRAY_COUNT(effect->unk_3C[0]); j++) {
            effect->unk_3C[i][j] = 0;
        }
    }
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", sprfx_update);

void sprfx_set_effect_flags(s32 idx, u16 flagBits, s32 mode) {
    if ((*D_80156954)[idx].flags & 1) {
        if (mode) {
            (*D_80156954)[idx].flags |= flagBits;
        } else {
            (*D_80156954)[idx].flags &= ~flagBits;
        }
    }
}

s32 sprfx_appendGfx_component(s32 idx, Unk10Struct* image, u32 flagBits, Matrix4f mtx) {
    SpriteEffect* effect = &(*D_80156954)[idx];
    s32 ret = 0;

    if (image->unk_10 == 0) {
        return 0;
    }

    effect->unk_00 = idx;
    effect->flags |= flagBits;
    sprfx_currentImage->unk_00 = image->unk_00;
    sprfx_currentImage->unk_04 = image->unk_04;
    sprfx_currentImage->width = image->width;
    sprfx_currentImage->height = image->height;
    sprfx_currentImage->xOffset = image->xOffset;
    sprfx_currentImage->yOffset =  image->yOffset;
    sprfx_currentImage->unk_18 = 0;
    sprfx_currentImage->unk_1E = 0;
    sprfx_currentImage->gfxOtherModeD = image->unk_10;

    if ((u32)idx >= 90) {
        return 0;
    }

    if (idx >= 90 || effect == NULL) {
        return 0;
    }

    func_8013B0EC(effect);
    func_8013B1B0(effect, mtx);

    if (effect->flags & 0x1000) {
        effect->unk_1C[0][0] = -1;
        effect->unk_1C[1][0] = -1;
        effect->unk_05 = 0;
        effect->unk_01 = 0;
        effect->unk_02 = 0;
        effect->flags &= ~0x1980;
        sprfx_clear_effect_gfx(effect);
        ret = 1;
    } else if (effect->flags & 0x4000) {
        ret = 2;
    } else if (effect->flags & 0x20000) {
        effect->unk_05 = 0;
        effect->unk_06 = 0;
        effect->unk_01 = 0;
        effect->unk_02 = 0;
        effect->unk_1C[0][0] = -1;
        effect->unk_1C[1][0] = -1;
        effect->flags &= 1;
        ret = 1;
    }
    return ret;
}

void func_8013B0EC(SpriteEffect* effect) {
    switch (effect->unk_01) {
        case 3:
            if (effect->unk_1C[1][2] == 0) {
                effect->subdivX = 1;
                effect->subdivY = 16;
            } else {
                effect->subdivX = 1;
                effect->subdivY = 1;
            }
        case 1:
            func_8013C048(effect);
            break;
        case 2:
            func_8013C3F0(effect);
            break;
        case 0:
        case 4:
            func_8013BC88(effect);
            break;
        default:
            return;
    }

    if (effect->unk_05 == 4) {
        func_8013EE68(effect);
    }

    switch (effect->unk_06) {
        case 11:
        case 12:
            func_8013F1F8(effect);
            break;
    }
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013B1B0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013BC88);

void func_8013C048(SpriteEffect* effect) {
    f32 divSizeX;
    f32 divSizeY;
    f32 posX;
    f32 posY;
    f32 texU;
    f32 texV;
    Vtx* vtx;
    s32 i;

    effect->firstVtxIdx = sprfx_vtxCount;
    divSizeX = sprfx_currentImage->width / (f32) effect->subdivX;
    divSizeY = sprfx_currentImage->height / (f32) effect->subdivY;
    posY = sprfx_currentImage->yOffset;
    texV = 0.0f;
    vtx = &sprfx_vtxBuf[sprfx_vtxCount];

    for (i = 0; i <= effect->subdivY; i++) {
        s32 j;

        if (i == effect->subdivY) {
            texV = sprfx_currentImage->height;
            posY = sprfx_currentImage->yOffset - sprfx_currentImage->height;
        }

        posX = sprfx_currentImage->xOffset;
        texU = 0.0f;
        for (j = 0; j <= effect->subdivX; vtx++, j++) {
            if (j == effect->subdivX) {
                texU = sprfx_currentImage->width;
                posX = sprfx_currentImage->xOffset + sprfx_currentImage->width;
            }
            vtx->n.ob[0] = posX;
            vtx->n.ob[1] = posY;
            vtx->n.ob[2] = 0;
            vtx->n.tc[0] = ((s32) texU + 256) * 32;
            vtx->n.tc[1] = ((s32) texV + 256) * 32;
            sprfx_vtxCount++;
            posX += divSizeX;
            texU += divSizeX;
        }
        posY -= divSizeY;
        texV += divSizeY;
    }
    effect->lastVtxIdx = sprfx_vtxCount - 1;
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", sprfx_load_gfx);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013C3F0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013CFA8);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013DAB4);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013E2F0);

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013E904);

void func_8013EE48(SpriteEffect* effect) {
    effect->unk_3C[0][0] = 0.0f;
    effect->unk_3C[0][1] = 50.0f;
    effect->unk_3C[0][2] = 30.0f;
}

INCLUDE_ASM(s32, "d0a70_len_4fe0", func_8013EE68);

void func_8013F1F8(SpriteEffect* effect) {
    f32 alpha = (f32)sprfx_currentImage->gfxOtherModeD / 255.0;
    s32 vtxCount = effect->lastVtxIdx - effect->firstVtxIdx;
    s32 i;

    for (i = 0; i <= vtxCount; i++) {
        sprfx_vtxBuf[effect->firstVtxIdx + i].v.cn[0] = effect->buf[i * 4 + 0];
        sprfx_vtxBuf[effect->firstVtxIdx + i].v.cn[1] = effect->buf[i * 4 + 1];
        sprfx_vtxBuf[effect->firstVtxIdx + i].v.cn[2] = effect->buf[i * 4 + 2];
        sprfx_vtxBuf[effect->firstVtxIdx + i].v.cn[3] = effect->buf[i * 4 + 3] * alpha;
    }
}
