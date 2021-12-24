#ifndef HUD_ELEMENT_H
#define HUD_ELEMENT_H

#include "common.h"

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
    HUD_ELEMENT_OP_AddTexelOffset,
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
    HUD_ELEMENT_OP_op_1B,
} HudElementAnim[0];

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


typedef union {
    struct {
        u32 f0: 4;
        u32 f4: 4;
    } as_bitfields;
    u32 as_word;
} HudFlags;

typedef struct HudTransform {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f position;
    /* 0x10 */ Vec3f rotation;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Vec2s pivot;
    /* 0x30 */ char unk_30[0xC4];
} HudTransform; // size = 0xF0

typedef struct HudElement {
    /* 0x00 */ HudFlags flags;
    /* 0x04 */ const HudElementAnim* readPos;
    /* 0x08 */ const HudElementAnim* anim;
    /* 0x0C */ s32* ptrPropertyList;
    /* 0x10 */ s32* imageAddr;
    /* 0x14 */ s32* paletteAddr;
    /* 0x18 */ s32 memOffset;
    /* 0x1C */ HudTransform* hudTransform;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
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
    /* 0x47 */ u8 updateTimer;
    /* 0x48 */ u8 sizeX; /* screen size? */
    /* 0x49 */ u8 sizeY; /* screen size? */
    /* 0x4A */ u8 opacity;
    /* 0x4B */ struct { s8 r; s8 g; s8 b; } tint;
    /* 0x4E */ Vec2b customImageSize;
    /* 0x40 */ Vec2b customDrawSize;
} HudElement; // size = 0x54

extern HudElementAnim D_80104A28[];
extern HudElementAnim D_80108558[];
extern HudElementAnim D_80108A64[];
extern HudElementAnim D_80109270[];
extern HudElementAnim* D_8024FA30[1];
extern HudElementAnim *gBadgeMenuElements[22];
extern HudElement* gItemIcons[20];

#define he_End HUD_ELEMENT_OP_End
#define he_SetRGBA(arg0, image) HUD_ELEMENT_OP_SetRGBA, arg0, (s32)image
#define he_SetCI(arg0, raster, palette) HUD_ELEMENT_OP_SetCI, arg0, (s32) raster, (s32)palette
#define he_Restart HUD_ELEMENT_OP_Restart
#define he_Loop HUD_ELEMENT_OP_Loop
#define he_SetTileSize(size) HUD_ELEMENT_OP_SetTileSize, size
#define he_SetSizesAutoScale(size1, size2) HUD_ELEMENT_OP_SetSizesAutoScale, size1, size1
#define he_SetSizesFixedScale(size1, size2) HUD_ELEMENT_OP_SetSizesFixedScale, size2, size2
#define he_SetVisible HUD_ELEMENT_OP_SetVisible
#define he_SetHidden HUD_ELEMENT_OP_SetHidden
#define he_AddTexelOffsetX(x) HUD_ELEMENT_OP_AddTexelOffsetX, x
#define he_AddTexelOffsetY(y) HUD_ELEMENT_OP_AddTexelOffsetY, y
#define he_AddTexelOffset(x, y) HUD_ELEMENT_OP_AddTexelOffset, x, y
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
#define he_op_1B(arg0, arg1) HUD_ELEMENT_OP_op_1B, arg0, arg1

void load_hud_element(HudElement* hudElement, const HudElementAnim* anim);

/// @param clamp        0 = repeat; 1 = clamp
/// @param dropShadow   Whether to render a drop shadow or not
void draw_rect_hud_element(
    HudElement* hudElement,
    s32 texSizeX,
    s32 texSizeY,
    s32 drawSizeX,
    s32 drawSizeY,
    s32 offsetX,
    s32 offsetY,
    s32 clamp,
    s32 dropShadow
);

void clear_hud_element_cache(void);

void init_hud_element_list(void);

/// Creates a new HUD element and returns its ID.
s32 create_hud_element(const HudElementAnim* anim);

void update_hud_elements(void);

/// @returns 0 if frame is completed
s32 hud_element_update(HudElement* hudElement);

void render_hud_elements_backUI(void);

void render_hud_elements_frontUI(void);

void render_hud_element(HudElement* hudElement);

void render_hud_elements_world(void);

void func_80143C48(s32 arg0, s32 arg1, s32 arg2);
void func_80144218(s32 arg0);
void func_80144258(s32 arg0);
void func_80144278(s32 arg0);

void draw_hud_element(s32 id, s32 clipMode);
void draw_hud_element_clipped(s32 id);
void draw_hud_element_2(s32 id);
void draw_hud_element_3(s32 id);

void set_hud_element_anim(s32 id, const HudElementAnim* anim);

HudElementAnim* get_hud_element_anim(s32 id);

HudElement* get_hud_element(s32 id);

void free_hud_element(s32 id);

void set_hud_element_render_pos(s32 id, s32 x, s32 y);

void get_hud_element_render_pos(s32 id, s32* x, s32* y);

void set_hud_element_render_depth(s32 id, s32 z);

/// Turns on the given flags.
void set_hud_element_flags(s32 id, s32 flags);

/// Turns off the given flags.
void clear_hud_element_flags(s32 id, s32 flags);

/// @see clear_hud_element_cache
void ALT_clear_hud_element_cache(void);

void set_hud_element_scale(s32 index, f32 scale);

void set_hud_element_size(s32 id, s8 size);

s32 func_80144E4C(s32 id);

void func_80144E74(s32 id, s32 arg1);

/// @param opacity 0 = invisible; 255 = opaque
void set_hud_element_alpha(s32 id, s32 opacity);

void set_hud_element_tint(s32 id, s32 r, s32 g, s32 b);

void create_hud_element_transform_A(s32 id);

void create_hud_element_transform_B(s32 id);

void create_hud_element_transform_C(s32 id);

void free_hud_element_transform(s32 id);

void set_hud_element_transform_pos(s32 id, f32 x, f32 y, f32 z);

void set_hud_element_transform_scale(s32 id, f32 x, f32 y, f32 z);

void set_hud_element_transform_rotation(s32 id, f32 x, f32 y, f32 z);

void set_hud_element_transform_rotation_pivot(s32 id, s32 dx, s32 dy);

void copy_world_hud_element_ref_to_battle(s32 worldID, s32 battleID);

void set_hud_element_nonworld_cache(void* base, s32 size);

#endif
