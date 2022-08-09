#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"

// TODO generate this somehow, or prevent it from shifting. must be resolved at compile time
#define SPRITE_ROM_START 0x1943000 + 0x10

extern s32 PlayerRasterSetsLoaded;
extern s32 PlayerRasterBufferSetOffsets[13];
extern s32 PlayerRasterHeader;
extern s32 D_802E0C20[];
extern s32 PlayerRasterCacheSize;
extern s32 PlayerRasterMaxSize;
extern s32 SpriteDataHeader[];
extern PlayerSpriteCacheEntry PlayerRasterCache[18];

INCLUDE_ASM(s32, "101b90_len_8f0", spr_swizzle_anim_offsets);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_sprite);

void spr_init_player_raster_cache(s32 cacheSize, s32 maxRasterSize) {
    void* raster;
    s32 i;

    nuPiReadRom(SPRITE_ROM_START, &SpriteDataHeader, 0xC);
    PlayerRasterCacheSize = cacheSize;
    PlayerRasterMaxSize = maxRasterSize;
    SpriteDataHeader[0] += SPRITE_ROM_START;
    SpriteDataHeader[1] += SPRITE_ROM_START;
    SpriteDataHeader[2] += SPRITE_ROM_START;
    raster = _heap_malloc(&gSpriteHeapPtr, maxRasterSize * cacheSize);

    for (i = 0; i < ARRAY_COUNT(PlayerRasterCache); i++) {
        PlayerRasterCache[i].raster = raster;
        raster += PlayerRasterMaxSize;
        PlayerRasterCache[i].lazyDeleteTime = 0;
        PlayerRasterCache[i].rasterIndex = 0;
        PlayerRasterCache[i].spriteIndex = 0xFF;
    }

    for (i = 0; i < ARRAY_COUNT(PlayerRasterBufferSetOffsets); i++)    {
        PlayerRasterBufferSetOffsets[i] = 0;
    }
    PlayerRasterSetsLoaded = 0;
    nuPiReadRom(SpriteDataHeader[0], &PlayerRasterHeader, 0xC);
    nuPiReadRom(SpriteDataHeader[0] + PlayerRasterHeader, D_802E0C20, 0x38);
}

INCLUDE_ASM(s32, "101b90_len_8f0", spr_get_player_raster);

void spr_update_player_raster_cache(void) {
    s32 i;

    func_8013A4D0();

    for (i = 0; i < PlayerRasterCacheSize; i++) {
        if (PlayerRasterCache[i].lazyDeleteTime != 0) {
            PlayerRasterCache[i].lazyDeleteTime--;
        }
    }
}

INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_npc_extra_anims);

INCLUDE_ASM(s32, "101b90_len_8f0", spr_allocate_components);
