#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "common.h"

#define SPR_PLAYER_COLOR_VARIATIONS 6
#define SPR_PEACH_BTL_PAL_STRIDE 4

enum SpriteIDFields {
    SPRITE_ID_ANIM_MASK         = 0x000000FF,
    SPRITE_ID_PAL_MASK          = 0x0000FF00,
    SPRITE_ID_SPR_MASK          = 0x00FF0000,
    SPRITE_ID_BACK_FACING       = 0x01000000,
    SPRITE_ID_TAIL_ALLOCATE     = 0x80000000,
};

enum DrawSpriteOptions {
    DRAW_SPRITE_USE_PLAYER_RASTERS  = 0x08000000,
    DRAW_SPRITE_UPSIDE_DOWN         = 0x10000000,
    DRAW_SPRITE_OVERRIDE_PALETTES   = 0x20000000,
    DRAW_SPRITE_OVERRIDE_YAW        = 0x40000000,
    DRAW_SPRITE_OVERRIDE_ALPHA      = 0x80000000,
};

enum {
    PLAYER_SPRITE_MAIN      = 0,
    PLAYER_SPRITE_AUX1      = 1,
    PLAYER_SPRITE_AUX2      = 2,
};

//TODO this is just a boolean isNpcSprite, using a temp enum for documenting
enum {
    SPRITE_MODE_PLAYER  = 0,
    SPRITE_MODE_NPC     = 1,
};

typedef struct SpriteComponent {
    /* 0x00 */ s32 initialized;
    /* 0x04 */ s32 properties; ///< AABBCCCC : AA = unused?, BB = parent, CCCC = notify value
    /* 0x08 */ s16* readPos;
    /* 0x0C */ f32 waitTime;
    /* 0x10 */ s32 loopCounter;
    /* 0x14 */ s32 curRaster;
    /* 0x18 */ s32 curPalette;
    /* 0x1C */ Vec3f posOffset;
    /* 0x28 */ Vec3f compPos;
    /* 0x34 */ Vec3i rot;
    /* 0x40 */ Vec3f scale;
    /* 0x4C */ s32 imgfxIdx;
} SpriteComponent; // size = 0x50

typedef struct PlayerCurrentAnimInfo {
    /* 0x00 */ SpriteComponent** componentList;
    /* 0x04 */ s32 animID;
    /* 0x08 */ s32 notifyValue;
} PlayerCurrentAnimInfo; // size = 0xC

typedef struct SpriteAnimComponent {
    /* 0x00 */ u16* cmdList;
    /* 0x04 */ s16 cmdListSize;
    /* 0x06 */ Vec3s compOffset;
} SpriteAnimComponent; // size = 0xC

// TODO: consider moving to 101b90_len_8f0 (sprite_cache)
typedef struct SpriteRasterCacheEntry {
    /* 0x00 */ IMG_PTR image;
    /* 0x04 */ u8 width;
    /* 0x05 */ u8 height;
    /* 0x06 */ s8 palette;
    /* 0x07 */ s8 quadCacheIndex;
} SpriteRasterCacheEntry; // size = 0x8

/// Sprite data header.
typedef struct SpriteAnimData {
    /* 0x00 */ SpriteRasterCacheEntry** rastersOffset;
    /* 0x04 */ PAL_PTR* palettesOffset;
    /* 0x08 */ s32 maxComponents;
    /* 0x0C */ s32 colorVariations;
    /* 0x10 */ SpriteAnimComponent** animListStart[VLA];
} SpriteAnimData; // size = 0x14

typedef struct SpriteInstance {
    /* 0x00 */ s32 spriteIndex;
    /* 0x04 */ SpriteComponent** componentList;
    /* 0x08 */ SpriteAnimData* spriteData;
    /* 0x0C */ s32 curAnimID;
    /* 0x10 */ s32 notifyValue;
} SpriteInstance; // size = 0x14

typedef struct PlayerRastersHeader {
    /* 0x00 */ s32 indexRanges;
    /* 0x04 */ s32 loadDescriptors;
    /* 0x08 */ s32 imageData;
} PlayerRastersHeader; // size = 0xC

typedef struct PlayerSpriteSet {
    /// Number of cache entries.
    /* 0x00 */ s32 cacheSize;

    /// Maximum raster size.
    /* 0x04 */ s32 rasterSize;

    /// Flags saying which rasters to load into the cache in spr_init_sprites(), with each bit corresponding to the Nth
    /// raster (with LSB = raster 0).
    /* 0x08 */ s32 initiallyLoaded;
} PlayerSpriteSet; // size = 0xC

typedef struct PlayerSpriteCacheEntry {
    /* 0x00 */ s32 lazyDeleteTime;
    /* 0x04 */ s32 rasterIndex;
    /* 0x08 */ s32 spriteIndex;
    /* 0x0C */ IMG_PTR raster;
} PlayerSpriteCacheEntry; // size = 0x10

typedef struct Quad {
    Vtx v[4];
} Quad; // size = 0x40

extern Quad spr_defaultQuad;
extern Vp SprPauseVp;
extern Vp SprPauseVpAlt;
extern Gfx D_802DF3F0[];
extern Gfx D_802DF428[];
extern Gfx D_802DF460[];
extern Gfx D_802DF490[];
extern f32 spr_animUpdateTimeScale;
extern PlayerSpriteSet spr_playerSpriteSets[7];

void imgfx_init(void);

void spr_init_sprites(s32 playerSpriteSet);

void spr_render_init(void);

void spr_update_player_raster_cache(void);

s32 spr_update_player_sprite(s32 arg0, s32 arg1, f32 timescale);

s32 spr_draw_player_sprite(s32 spriteInstanceID, s32 yaw, s32 arg2, PAL_PTR* paletteList, Matrix4f mtx);

s32 func_802DDEC4(s32 arg0);

void set_player_imgfx_comp(s32, s32, ImgFXType, s32, s32, s32, s32, s32);

void set_player_imgfx_all(s32, ImgFXType, s32, s32, s32, s32, s32);

IMG_PTR spr_get_player_raster(s32 rasterIndex, s32 playerSpriteID);

void spr_get_player_raster_info(SpriteRasterInfo* out, s32 playerSpriteID, s32 rasterIndex);

PAL_PTR* spr_get_player_palettes(s32 spriteIndex);

/// @param animID - Set MSB for tail allocation (i.e. `0x80XXYYZZ`)
s32 spr_load_npc_sprite(s32 animID, u32* extraAnimList);

s32 spr_update_sprite(s32 spriteInstanceID, s32 animID, f32 timeScale);

s32 spr_draw_npc_sprite(s32 spriteInstanceID, s32 yaw, s32 arg2, PAL_PTR* paletteList, Matrix4f mtx);

s32 spr_get_notify_value(s32 arg0);

s32 spr_free_sprite(s32 spriteInstanceID);

s32 get_npc_comp_imgfx_idx(s32, s32);

void set_npc_imgfx_comp(s32, s32, ImgFXType, s32, s32, s32, s32, s32);

void set_npc_imgfx_all(s32 arg0, ImgFXType arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

s32 spr_get_comp_position(s32 spriteIdx, s32 compListIdx, s32* outX, s32* outY, s32* outZ);

s32 spr_get_npc_raster_info(SpriteRasterInfo* out, s32 npcSpriteID, s32 rasterIndex);

PAL_PTR* spr_get_npc_palettes(s32 npcSpriteID);

s32 spr_get_npc_color_variations(s32 npcSpriteID);

void create_shading_palette(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha, s32);

SpriteAnimData* spr_load_sprite(s32 idx, s32 arg1, s32 arg2);

#endif
