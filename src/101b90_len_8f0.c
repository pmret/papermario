#include "common.h"

typedef struct UnkSpr10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0xC];
} UnkSpr10;

extern s32 D_802E0C58;
extern UnkSpr10 D_802E0C70[];

INCLUDE_ASM(s32, "101b90_len_8f0", spr_swizzle_anim_offsets);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_sprite);

INCLUDE_ASM(void, "101b90_len_8f0", spr_init_player_raster_cache, s32 cacheSize, s32 maxRasterSize);

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
