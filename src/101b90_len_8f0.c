#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"

// TODO generate this somehow, or prevent it from shifting. must be resolved at compile time
#define SPRITE_ROM_START 0x1943000 + 0x10

typedef struct UnkSpr10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 rasterIdx;
    /* 0x08 */ s32 spriteID;
    /* 0x0C */ void* raster;
} UnkSpr10;

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern s32 D_802DFEB0[];
extern s32 D_802DFEB8[];
extern s32 D_802E004C;
extern s32 D_802E0050[];
extern s32 D_802E0090[];
extern s32 D_802E0C10;
extern s32 D_802E0C14[];
extern s32 D_802E0C20[];
extern s32 D_802E0C58;
extern s32 D_802E0C5C;
extern s32 D_802E0C60[];
extern s32 D_802E0C64;
extern s32 D_802E0C68;
extern UnkSpr10 D_802E0C70[18];

INCLUDE_ASM(s32, "101b90_len_8f0", spr_swizzle_anim_offsets);

#ifdef NON_EQUIVALENT
SpriteAnimData* spr_load_sprite(s32 idx, s32 arg1, s32 arg2) {
    SpriteAnimData* animData;
    s32 base;
    s32 i;

    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32* temp_a1_3;
    s32** var_s2;
    u16** var_v1;
    s32* temp_v0;

    if (arg1) {
        base = D_802E0C64;
    } else {
        base = D_802E0C68;
    }
    nuPiReadRom(base + (idx * 4), &D_802DFEB0, 8U);

    temp_s0 = ALIGN8(D_802DFEB0[1] - D_802DFEB0[0]);
    temp_v0 = general_heap_malloc(temp_s0);
    nuPiReadRom(base + D_802DFEB0[0], temp_v0, temp_s0);

    if (arg2) {
        temp_v0++;
        animData = _heap_malloc_tail(&gSpriteHeapPtr, *temp_v0);
    } else {
        temp_v0++;
        animData = _heap_malloc(&gSpriteHeapPtr, *temp_v0);
    }

    decode_yay0(temp_v0, animData);
    general_heap_free(temp_v0);

    temp_v0_2 = ((u32) animData / 4) * 4;
    var_s2 = animData->rastersOffset + temp_v0_2;
    animData->rastersOffset = var_s2;

    while (*var_s2 != (s32* )-1) {
        temp_a1_3 = *var_s2 + temp_v0_2;
        *var_s2 = temp_a1_3;
        var_s2++;
        if (!arg1) {
            *temp_a1_3 += temp_v0_2;
        }
    }

    if (arg1) {
        D_802E0050[idx] = D_802E004C;
        temp_s0_2 = D_802E0C20[idx + 1] - D_802E0C20[idx];
        nuPiReadRom(D_802E0C60[0] + D_802E0C14[0] + D_802E0C20[idx], &D_802DFEB8, 0x194);
        for (i = 0; i < temp_s0_2; i++) {
            D_802E0090[D_802E004C++] = D_802DFEB8[i];
        }
    }

    temp_v0_3 = ((u32) animData / 4) * 4;
    var_v1 = animData->palettesOffset + temp_v0_3;
    animData->palettesOffset = var_v1;

    while (*var_v1 != -1) {
        *var_v1 += temp_v0_3;
        var_v1++;
    }

    spr_swizzle_anim_offsets(0, 0, animData);
    return animData;
}
#else
INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_sprite);
#endif

void spr_init_player_raster_cache(s32 cacheSize, s32 maxRasterSize) {
    void* var_a1;
    s32 i;

    nuPiReadRom(SPRITE_ROM_START, &D_802E0C60, 0xC);
    D_802E0C58 = cacheSize;
    D_802E0C5C = maxRasterSize;
    D_802E0C60[0] += SPRITE_ROM_START;
    D_802E0C60[1] += SPRITE_ROM_START;
    D_802E0C60[2] += SPRITE_ROM_START;
    var_a1 = _heap_malloc(&gSpriteHeapPtr, maxRasterSize * cacheSize);

    for (i = 0; i < ARRAY_COUNT(D_802E0C70); i++) {
        D_802E0C70[i].raster = var_a1;
        var_a1 += D_802E0C5C;
        D_802E0C70[i].unk_00 = 0;
        D_802E0C70[i].rasterIdx = 0;
        D_802E0C70[i].spriteID = 0xFF;
    }

    for (i = 0; i < 13; i++)    {
        D_802E0050[i] = 0;
    }
    D_802E004C = 0;
    nuPiReadRom(D_802E0C60[0], &D_802E0C10, 0xC);
    nuPiReadRom(D_802E0C60[0] + D_802E0C10, D_802E0C20, 0x38);
}

void* spr_get_player_raster(s32 rasterIndex, s32 playerSpriteID) {
    UnkSpr10* temp_s0;
    u32 temp_a2;
    s32 idx = -1;
    s32 i;

    for (i = 0; i < D_802E0C58; i++) {
        if (D_802E0C70[i].unk_00 != 0) {
            if (D_802E0C70[i].rasterIdx == rasterIndex && D_802E0C70[i].spriteID == playerSpriteID) {
                D_802E0C70[i].unk_00 = 2;
                return D_802E0C70[i].raster;
            }
        } else if (idx == -1) {
            idx = i;
        }
    }

    if (idx == -1) {
        return NULL;
    }

    temp_s0 = &D_802E0C70[idx];
    temp_s0->unk_00 = 2;
    temp_s0->rasterIdx = rasterIndex;
    temp_s0->spriteID = playerSpriteID;
    temp_a2 = D_802E0090[D_802E0050[playerSpriteID] + rasterIndex];
    nuPiReadRom(*D_802E0C60 + (temp_a2 & 0xFFFFF), temp_s0->raster, (temp_a2 >> 0x10) & 0xFFF0);
    return temp_s0->raster;
}

void spr_update_player_raster_cache(void) {
    s32 i;

    func_8013A4D0();

    for (i = 0; i < D_802E0C58; i++) {
        if (D_802E0C70[i].unk_00 != 0) {
            D_802E0C70[i].unk_00--;
        }
    }
}

INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_npc_extra_anims);

#ifdef NON_MATCHING
void** spr_allocate_components(s32 arg0) {
    s32 temp_s1;
    void** heap;
    void* var_a0_2;
    void** new_var;
    u32 size;
    s32 i;

    temp_s1 = (arg0 + 1) * 4;
    size = (arg0 * 0x50) + (temp_s1);

    if (spr_allocateBtlComponentsOnWorldHeap) {
        heap = _heap_malloc(&heap_generalHead, size);
    } else {
        heap = _heap_malloc(&gSpriteHeapPtr, size);
    }

    new_var = heap;

    var_a0_2 = heap + (temp_s1 / 4);

    for (i = 0; i < arg0; i++) {
        *new_var = var_a0_2;
        new_var++;
        var_a0_2 += 0x50;
    }
    *new_var = (void* )-1;
    return heap;
}
#else
INCLUDE_ASM(s32, "101b90_len_8f0", spr_allocate_components);
#endif
