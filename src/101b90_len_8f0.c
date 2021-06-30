#include "common.h"

INCLUDE_ASM(s32, "101b90_len_8f0", spr_swizzle_anim_offsets);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_sprite);

// spr_init_player_raster_cache
INCLUDE_ASM(void, "101b90_len_8f0", spr_init_player_raster_cache, s32 cacheSize, s32 maxRasterSize);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_get_player_raster);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_update_player_raster_cache);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_npc_extra_anims);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_allocate_components);
