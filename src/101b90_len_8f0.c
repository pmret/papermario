#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"

// TODO generate this somehow, or prevent it from shifting. must be resolved at compile time
#define SPRITE_ROM_START 0x1943000 + 0x10

typedef struct UnkSpr10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void* unk_0C;
} UnkSpr10;

extern s32 D_802E004C;
extern s32 D_802E0050[];
extern s32 D_802E0C10;
extern s32 D_802E0C20[];
extern s32 D_802E0C58;
extern s32 D_802E0C5C;
extern s32 D_802E0C60[];
extern UnkSpr10 D_802E0C70[];

INCLUDE_ASM(s32, "101b90_len_8f0", spr_swizzle_anim_offsets);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_sprite);

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

    for (i = 0; i < 0x12; i++) {
        D_802E0C70[i].unk_0C = var_a1;
        var_a1 += D_802E0C5C;
        D_802E0C70[i].unk_00 = 0;
        D_802E0C70[i].unk_04 = 0;
        D_802E0C70[i].unk_08 = 0xFF;
    }

    for (i = 0; i < 13; i++)    {
        D_802E0050[i] = 0;
    }
    D_802E004C = 0;
    nuPiReadRom(D_802E0C60[0], &D_802E0C10, 0xC);
    nuPiReadRom(D_802E0C60[0] + D_802E0C10, D_802E0C20, 0x38);
}

INCLUDE_ASM(s32, "101b90_len_8f0", spr_get_player_raster);

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

INCLUDE_ASM(s32, "101b90_len_8f0", spr_allocate_components);
