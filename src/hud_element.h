#ifndef HUD_ELEMENT_H
#define HUD_ELEMENT_H

#include "common.h"

#define HUD_ELEMENT_BATTLE_ID_MASK 0x800

typedef enum {
    HUD_ELEMENT_OP_End,
    HUD_ELEMENT_OP_SetRGBA,
    HUD_ELEMENT_OP_SetCI,
    HUD_ELEMENT_OP_Restart,
    HUD_ELEMENT_OP_Loop,
    HUD_ELEMENT_OP_SetTileSize,
    HUD_ELEMENT_OP_SetSizesAutoScale,
    HUD_ELEMENT_OP_SetSizesFixedScale,
    HUD_ELEMENT_OP_SetVisible,
    HUD_ELEMENT_OP_SetHidden,
    HUD_ELEMENT_OP_AddTexelOffsetX,
    HUD_ELEMENT_OP_AddTexelOffsetY,
    HUD_ELEMENT_OP_SetTexelOffset,
    HUD_ELEMENT_OP_SetImage,
    HUD_ELEMENT_OP_SetScale,
    HUD_ELEMENT_OP_SetAlpha,
    HUD_ELEMENT_OP_RandomDelay,
    HUD_ELEMENT_OP_Delete,
    HUD_ELEMENT_OP_UseIA8,
    HUD_ELEMENT_OP_SetCustomSize,
    HUD_ELEMENT_OP_RandomRestart,
    HUD_ELEMENT_OP_op_15,
    HUD_ELEMENT_OP_op_16,
    HUD_ELEMENT_OP_RandomBranch,
    HUD_ELEMENT_OP_SetFlags,
    HUD_ELEMENT_OP_ClearFlags,
    HUD_ELEMENT_OP_PlaySound,
    HUD_ELEMENT_OP_SetPivot,
} HudScript[0];

enum {
    HUD_ELEMENT_SIZE_8x8,
    HUD_ELEMENT_SIZE_16x16,
    HUD_ELEMENT_SIZE_24x24,
    HUD_ELEMENT_SIZE_32x32,
    HUD_ELEMENT_SIZE_48x48,
    HUD_ELEMENT_SIZE_64x64,
    HUD_ELEMENT_SIZE_8x16,
    HUD_ELEMENT_SIZE_16x8,
    HUD_ELEMENT_SIZE_16x24,
    HUD_ELEMENT_SIZE_16x32,
    HUD_ELEMENT_SIZE_64x32,
    HUD_ELEMENT_SIZE_32x16,
    HUD_ELEMENT_SIZE_12x12,
    HUD_ELEMENT_SIZE_48x24,
    HUD_ELEMENT_SIZE_32x8,
    HUD_ELEMENT_SIZE_24x8,
    HUD_ELEMENT_SIZE_64x16,
    HUD_ELEMENT_SIZE_16x64,
    HUD_ELEMENT_SIZE_192x32,
    HUD_ELEMENT_SIZE_40x40,
    HUD_ELEMENT_SIZE_24x16,
    HUD_ELEMENT_SIZE_32x40,
    HUD_ELEMENT_SIZE_40x16,
    HUD_ELEMENT_SIZE_40x24,
    HUD_ELEMENT_SIZE_32x24,
};

enum HudElementFlags {
    HUD_ELEMENT_FLAGS_INITIALIZED        = 0x00000001,
    HUD_ELEMENT_FLAGS_DISABLED           = 0x00000002,
    HUD_ELEMENT_FLAGS_ANIMATION_FINISHED = 0x00000004,
    HUD_ELEMENT_FLAGS_8                  = 0x00000008,
    HUD_ELEMENT_FLAGS_SCALED             = 0x00000010,
    HUD_ELEMENT_FLAGS_TRANSPARENT        = 0x00000020,
    HUD_ELEMENT_FLAGS_FRONTUI            = 0x00000040,
    HUD_ELEMENT_FLAGS_80                 = 0x00000080,
    HUD_ELEMENT_FLAGS_FIXEDSCALE         = 0x00000100,
    HUD_ELEMENT_FLAGS_200                = 0x00000200,
    HUD_ELEMENT_FLAGS_BATTLE             = 0x00000400,
    HUD_ELEMENT_FLAGS_REPEATED           = 0x00000800,
    HUD_ELEMENT_FLAGS_FLIPX              = 0x00001000,
    HUD_ELEMENT_FLAGS_FLIPY              = 0x00002000,
    HUD_ELEMENT_FLAGS_FMT_CI4            = 0x00004000,
    HUD_ELEMENT_FLAGS_FILTER_TEX         = 0x00008000,
    HUD_ELEMENT_FLAGS_TRANSFORM          = 0x00010000,
    HUD_ELEMENT_FLAGS_NO_FOLD            = 0x00020000,
    HUD_ELEMENT_FLAGS_DELETE             = 0x00040000,
    HUD_ELEMENT_FLAGS_FMT_IA8            = 0x00080000,
    HUD_ELEMENT_FLAGS_CUSTOM_SIZE        = 0x00100000,
    HUD_ELEMENT_FLAGS_200000             = 0x00200000,
    HUD_ELEMENT_FLAGS_MEMOFFSET          = 0x00400000,
    HUD_ELEMENT_FLAGS_ANTIALIASING       = 0x00800000,
    HUD_ELEMENT_FLAGS_1000000            = 0x01000000,
    HUD_ELEMENT_FLAGS_2000000            = 0x02000000,
    HUD_ELEMENT_FLAGS_4000000            = 0x04000000,
    HUD_ELEMENT_FLAGS_8000000            = 0x08000000,
    HUD_ELEMENT_FLAGS_10000000           = 0x10000000,
    HUD_ELEMENT_FLAGS_DROP_SHADOW        = 0x20000000,
    HUD_ELEMENT_FLAGS_40000000           = 0x40000000,
    HUD_ELEMENT_FLAGS_80000000           = 0x80000000,
};

enum {
    HUD_ELEMENT_DRAW_FIRST_WITH_CLIPPING    = 0,
    HUD_ELEMENT_DRAW_NEXT                   = 1,
    HUD_ELEMENT_DRAW_FIRST_WITHOUT_CLIPPING = 2,
};

typedef struct HudScriptPair {
    /* 0x00 */ HudScript* enabled;
    /* 0x04 */ HudScript* disabled;
} HudScriptPair; // size = 0x08

typedef struct VtxRect {
    Vtx vtx[4];
} VtxRect; // size = 0x40

typedef struct HudTransform {
    /* 0x00 */ s32 foldIdx;
    /* 0x04 */ Vec3f position;
    /* 0x10 */ Vec3f rotation;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Vec2s pivot;
    /* 0x30 */ VtxRect unk_30[3];
} HudTransform; // size = 0xF0

typedef struct HudElement {
    /* 0x00 */ u32 flags;
    /* 0x04 */ const HudScript* readPos;
    /* 0x08 */ const HudScript* anim;
    /* 0x0C */ HudScript* loopStartPos;
    /* 0x10 */ u8* imageAddr;
    /* 0x14 */ u8* paletteAddr;
    /* 0x18 */ s32 memOffset;
    /* 0x1C */ HudTransform* hudTransform;
    /* 0x20 */ f32 deltaSizeX;
    /* 0x24 */ f32 deltaSizeY;
    /* 0x28 */ f32 unkImgScale[2];
    /* 0x30 */ f32 uniformScale;
    /* 0x34 */ s32 widthScale; ///< X10
    /* 0x38 */ s32 heightScale; ///< X10
    /* 0x3C */ s16 renderPosX;
    /* 0x3E */ s16 renderPosY;
    /* 0x40 */ Vec2b screenPosOffset;
    /* 0x42 */ Vec3b worldPosOffset;
    /* 0x45 */ s8 drawSizePreset;
    /* 0x46 */ s8 tileSizePreset;
    /* 0x47 */ s8 updateTimer;
    /* 0x48 */ u8 sizeX; /* screen size? */
    /* 0x49 */ u8 sizeY; /* screen size? */
    /* 0x4A */ u8 opacity;
    /* 0x4B */ Color_RGB8 tint;
    /* 0x4E */ Vec2bu customImageSize;
    /* 0x50 */ Vec2bu customDrawSize;
} HudElement; // size = 0x54

typedef HudElement* HudElementList[320];

extern HudScript HudScript_AnimatedHandPointer[];
extern HudScript HudScript_StatusCoin[];
extern HudScript HudScript_Refund[];
extern HudScript HudScript_MenuTimes[];

#define he_End HUD_ELEMENT_OP_End
#define he_SetRGBA(arg0, image) HUD_ELEMENT_OP_SetRGBA, arg0, (s32)image
#define he_SetCI(arg0, raster, palette) HUD_ELEMENT_OP_SetCI, arg0, (s32) raster, (s32)palette
#define he_Restart HUD_ELEMENT_OP_Restart
#define he_Loop HUD_ELEMENT_OP_Loop
#define he_SetTileSize(size) HUD_ELEMENT_OP_SetTileSize, size
#define he_SetSizesAutoScale(size1, size2) HUD_ELEMENT_OP_SetSizesAutoScale, size1, size2
#define he_SetSizesFixedScale(size1, size2) HUD_ELEMENT_OP_SetSizesFixedScale, size1, size2
#define he_SetVisible HUD_ELEMENT_OP_SetVisible
#define he_SetHidden HUD_ELEMENT_OP_SetHidden
#define he_AddTexelOffsetX(x) HUD_ELEMENT_OP_AddTexelOffsetX, x
#define he_AddTexelOffsetY(y) HUD_ELEMENT_OP_AddTexelOffsetY, y
#define he_SetTexelOffset(x, y) HUD_ELEMENT_OP_SetTexelOffset, x, y
#define he_SetImage(arg0, raster, palette, arg2, arg3) HUD_ELEMENT_OP_SetImage, arg0, raster, palette, arg2, arg3
#define he_SetScale(scale) HUD_ELEMENT_OP_SetScale, (s32)(scale * 65536.0f)
#define he_SetAlpha(alpha) HUD_ELEMENT_OP_SetAlpha, alpha
#define he_RandomDelay(arg0, arg1) HUD_ELEMENT_OP_RandomDelay, arg0, arg1
#define he_Delete HUD_ELEMENT_OP_Delete
#define he_UseIA8 HUD_ELEMENT_OP_UseIA8
#define he_SetCustomSize(arg0, arg1) HUD_ELEMENT_OP_SetCustomSize, arg0, arg1

/// Restarts the loop if cutoff < rand_int(max)
#define he_RandomRestart(max, cutoff) HUD_ELEMENT_OP_RandomRestart, max, cutoff

#define he_op_15(arg0) HUD_ELEMENT_OP_op_15, arg0
#define he_RandomBranch(...) HUD_ELEMENT_OP_RandomBranch, ARRAY_COUNT({__VA_ARGS__}), __VA_ARGS__
#define he_SetFlags(arg0) HUD_ELEMENT_OP_SetFlags, arg0
#define he_ClearFlags(arg0) HUD_ELEMENT_OP_ClearFlags, arg0
#define he_PlaySound(arg0) HUD_ELEMENT_OP_PlaySound, arg0
#define he_SetPivot(arg0, arg1) HUD_ELEMENT_OP_SetPivot, arg0, arg1

void hud_element_load_script(HudElement* hudElement, const HudScript* anim);

/// @param clamp        0 = repeat; 1 = clamp
/// @param dropShadow   Whether to render a drop shadow or not
void hud_element_draw_rect(HudElement* hudElement, s16 texSizeX, s16 texSizeY, s16 drawSizeX, s16 drawSizeY, s16 offsetX, s16 offsetY, s32 clamp, s32 dropShadow);

void hud_element_clear_cache(void);

void init_hud_element_list(void);

/// Creates a new HUD element and returns its ID.
s32 hud_element_create(const HudScript* anim);

void update_hud_elements(void);

/// @returns 0 if frame is completed
s32 hud_element_update(HudElement* hudElement);

void render_hud_elements_backUI(void);

void render_hud_elements_frontUI(void);

void render_hud_element(HudElement* hudElement);

void render_hud_elements_world(void);

void func_80143C48(s32 arg0, s32 arg1, s32 camID);
void func_80144218(s32 arg0);
void func_80144238(s32 arg0);
void func_80144258(s32 arg0);
void func_80144278(s32 arg0);

void draw_hud_element_internal(s32 id, s32 clipMode);
void hud_element_draw_clipped(s32 id);
void hud_element_draw_next(s32 id);
void hud_element_draw_without_clipping(s32 id);

void hud_element_set_script(s32 id, const HudScript* anim);

HudScript* hud_element_get_script(s32 id);

HudElement* get_hud_element(s32 id);

void hud_element_free(s32 id);

void hud_element_set_render_pos(s32 id, s32 x, s32 y);

void hud_element_get_render_pos(s32 id, s32* x, s32* y);

void hud_element_set_render_depth(s32 id, s32 z);

/// Turns on the given flags.
void hud_element_set_flags(s32 id, s32 flags);

/// Turns off the given flags.
void hud_element_clear_flags(s32 id, s32 flags);

/// @see hud_element_clear_cache
void ALT_clear_hud_element_cache(void);

void hud_element_set_scale(s32 index, f32 scale);

void hud_element_use_preset_size(s32 id, s8 size);

s32 func_80144E4C(s32 id);

void func_80144E74(s32 id, s32 arg1);

/// @param opacity 0 = invisible; 255 = opaque
void hud_element_set_alpha(s32 id, s32 opacity);

void hud_element_set_tint(s32 id, s32 r, s32 g, s32 b);

void hud_element_create_transform_A(s32 id);

void hud_element_create_transform_B(s32 id);

void hud_element_create_transform_C(s32 id);

void hud_element_free_transform(s32 id);

void hud_element_set_transform_pos(s32 id, f32 x, f32 y, f32 z);

void hud_element_set_transform_scale(s32 id, f32 x, f32 y, f32 z);

void hud_element_set_transform_rotation(s32 id, f32 x, f32 y, f32 z);

void hud_element_set_transform_rotation_pivot(s32 id, s32 dx, s32 dy);

void copy_world_hud_element_ref_to_battle(s32 worldID, s32 battleID);

void hud_element_set_aux_cache(void* base, s32 size);

#endif
