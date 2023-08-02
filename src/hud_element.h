#ifndef HUD_ELEMENT_H
#define HUD_ELEMENT_H

#include "common_structs.h"
#include "icon_offsets.h"

#define HUD_ELEMENT_BATTLE_ID_MASK 0x800

typedef s32 HudScript[];

typedef s32 HudElemID;

enum {
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
};

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
    HUD_ELEMENT_FLAG_INITIALIZED        = 0x00000001,
    HUD_ELEMENT_FLAG_DISABLED           = 0x00000002,
    HUD_ELEMENT_FLAG_ANIMATION_FINISHED = 0x00000004,
    HUD_ELEMENT_FLAG_8                  = 0x00000008,
    HUD_ELEMENT_FLAG_SCALED             = 0x00000010,
    HUD_ELEMENT_FLAG_TRANSPARENT        = 0x00000020,
    HUD_ELEMENT_FLAG_FRONTUI            = 0x00000040,
    HUD_ELEMENT_FLAG_80                 = 0x00000080,
    HUD_ELEMENT_FLAG_FIXEDSCALE         = 0x00000100,
    HUD_ELEMENT_FLAG_200                = 0x00000200,
    HUD_ELEMENT_FLAG_BATTLE             = 0x00000400,
    HUD_ELEMENT_FLAG_REPEATED           = 0x00000800,
    HUD_ELEMENT_FLAG_FLIPX              = 0x00001000,
    HUD_ELEMENT_FLAG_FLIPY              = 0x00002000,
    HUD_ELEMENT_FLAG_FMT_CI4            = 0x00004000,
    HUD_ELEMENT_FLAG_FILTER_TEX         = 0x00008000,
    HUD_ELEMENT_FLAG_TRANSFORM          = 0x00010000,
    HUD_ELEMENT_FLAG_NO_FOLD            = 0x00020000,
    HUD_ELEMENT_FLAG_DELETE             = 0x00040000,
    HUD_ELEMENT_FLAG_FMT_IA8            = 0x00080000,
    HUD_ELEMENT_FLAG_CUSTOM_SIZE        = 0x00100000,
    HUD_ELEMENT_FLAG_200000             = 0x00200000,
    HUD_ELEMENT_FLAG_MEMOFFSET          = 0x00400000,
    HUD_ELEMENT_FLAG_ANTIALIASING       = 0x00800000,
    HUD_ELEMENT_FLAG_1000000            = 0x01000000,
    HUD_ELEMENT_FLAG_2000000            = 0x02000000,
    HUD_ELEMENT_FLAG_4000000            = 0x04000000,
    HUD_ELEMENT_FLAG_8000000            = 0x08000000,
    HUD_ELEMENT_FLAG_10000000           = 0x10000000,
    HUD_ELEMENT_FLAG_DROP_SHADOW        = 0x20000000,
    HUD_ELEMENT_FLAG_40000000           = 0x40000000,
    HUD_ELEMENT_FLAG_80000000           = 0x80000000,
};

enum {
    HUD_ELEMENT_DRAW_FIRST_WITH_CLIPPING    = 0,
    HUD_ELEMENT_DRAW_NEXT                   = 1,
    HUD_ELEMENT_DRAW_FIRST_WITHOUT_CLIPPING = 2,
};

typedef struct HudCacheEntry {
    /* 0x00 */ s32 id;
    /* 0x04 */ u8* data;
} HudCacheEntry; // size = 0x8;

typedef struct PopupMenu {
    /* 0x000 */ HudScript* ptrIcon[32];
    /* 0x080 */ char unk_80[0x4];
    /* 0x084 */ s32 nameMsg[32];
    /* 0x104 */ char unk_104[0x4];
    /* 0x108 */ s32 userIndex[32]; // used to map menu order to a user-ID for each item
    /* 0x188 */ char unk_188[0x4];
    /* 0x18C */ s32 enabled[32];
    /* 0x20C */ char unk_20C[0x4];
    /* 0x210 */ s32 value[32]; // sale price, etc
    /* 0x290 */ char unk_290[0x4];
    /* 0x294 */ s32 descMsg[32];
    /* 0x314 */ char unk_314[0x4];
    /* 0x318 */ s32 popupType;
    /* 0x31C */ s32 dipMode;
    /* 0x320 */ s32 titleNumber; // used to display 2/3 with double/triple dip
    /* 0x324 */ s32 numEntries;
    /* 0x328 */ s32 initialPos;
    /* 0x32C */ s16 result;
    /* 0x32E */ char unk_32E[0x2];
#if VERSION_PAL
    /* 0x330 */ s32 unk_330; // message ID
    /* 0x334 */ s32 unk_334; // x offset
    /* 0x338 */ s32 unk_338;
    /* 0x33C */ s32 unk_33C; // message ID
    /* 0x340 */ s32 unk_340;
#endif
} PopupMenu; // size = 0x330

typedef struct Shop {
    /* 0x000 */ s16 flags;
    /* 0x002 */ s16 numItems;
    /* 0x004 */ s16 numSpecialPrices;
    /* 0x006 */ char unk_06[0x2];
    /* 0x008 */ s32 curItemSlot;
    /* 0x00C */ s32 selectedStoreItemSlot;
    /* 0x010 */ ShopOwner* owner;
    /* 0x014 */ ShopItemLocation* itemDataPositions;
    /* 0x018 */ ShopItemData* staticInventory;
    /* 0x01C */ ShopSellPriceData* staticPriceList;
    /* 0x020 */ s32 costIconID;
    /* 0x024 */ s32 inventoryItemFlags;
    /* 0x028 */ PopupMenu itemSelectMenu;
    /* 0x358 */ s32 unk_358;
} Shop; // size = 0x35C

typedef struct IconHudScriptPair {
    /* 0x00 */ HudScript* enabled;
    /* 0x04 */ HudScript* disabled;
} IconHudScriptPair; // size = 0x08

typedef struct VtxRect {
    Vtx vtx[4];
} VtxRect; // size = 0x40

typedef struct HudTransform {
    /* 0x00 */ s32 imgfxIdx;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Vec2s pivot;
    /* 0x30 */ VtxRect unk_30[3];
} HudTransform; // size = 0xF0

typedef struct HudElement {
    /* 0x00 */ u32 flags;
    /* 0x04 */ HudScript* readPos;
    /* 0x08 */ HudScript* anim;
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

extern HudScript HES_AnimatedHandPointer;
extern HudScript HES_StatusCoin;
extern HudScript HES_Refund;
#if VERSION_PAL
extern HudScript HES_Refund_de;
extern HudScript HES_Refund_fr;
extern HudScript HES_Refund_es;
#endif
extern HudScript HES_MenuTimes;

typedef struct PartnerPopupProperties {
    /* 0x00 */ s32 nameMsg;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 worldDescMsg;
    /* 0x0C */ s32 battleDescMsg;
} PartnerPopupProperties; // size = 0x10

extern PartnerPopupProperties gPartnerPopupProperties[13];
extern HudScript* wDisabledPartnerHudScripts[];
extern HudScript* wPartnerHudScripts[];

#define HS_PTR(sym)         (s32)&sym

#define hs_End HUD_ELEMENT_OP_End,
#define hs_SetRGBA(time, image) HUD_ELEMENT_OP_SetRGBA, time, (s32)image,
#define hs_SetCI(time, name) HUD_ELEMENT_OP_SetCI, time, (s32)name##_png, (s32)name##_pal,
#define hs_SetCI_Explicit(time, raster, palette) HUD_ELEMENT_OP_SetCI, time, (s32)raster##_png, (s32)palette##_pal,
#define hs_Restart HUD_ELEMENT_OP_Restart,
#define hs_Loop HUD_ELEMENT_OP_Loop,
#define hs_SetTileSize(size) HUD_ELEMENT_OP_SetTileSize, size,
#define hs_SetSizesAutoScale(size1, size2) HUD_ELEMENT_OP_SetSizesAutoScale, size1, size2,
#define hs_SetSizesFixedScale(size1, size2) HUD_ELEMENT_OP_SetSizesFixedScale, size1, size2,
#define hs_SetVisible HUD_ELEMENT_OP_SetVisible,
#define hs_SetHidden HUD_ELEMENT_OP_SetHidden,
#define hs_AddTexelOffsetX(x) HUD_ELEMENT_OP_AddTexelOffsetX, x,
#define hs_AddTexelOffsetY(y) HUD_ELEMENT_OP_AddTexelOffsetY, y,
#define hs_SetTexelOffset(x, y) HUD_ELEMENT_OP_SetTexelOffset, x, y,
#define hs_SetIcon(time, icon) HUD_ELEMENT_OP_SetImage, time, ICON_##icon##_raster, ICON_##icon##_palette, 0, 0,
#define hs_SetScale(scale) HUD_ELEMENT_OP_SetScale, (s32)(scale * 65536.0f),
#define hs_SetAlpha(alpha) HUD_ELEMENT_OP_SetAlpha, alpha,
#define hs_RandomDelay(arg0, arg1) HUD_ELEMENT_OP_RandomDelay, arg0, arg1,
#define hs_Delete HUD_ELEMENT_OP_Delete,
#define hs_UseIA8 HUD_ELEMENT_OP_UseIA8,
#define hs_SetCustomSize(arg0, arg1) HUD_ELEMENT_OP_SetCustomSize, arg0, arg1,

/// Restarts the loop if cutoff < rand_int(max)
#define hs_RandomRestart(max, cutoff) HUD_ELEMENT_OP_RandomRestart, max, cutoff,

#define hs_op_15(arg0) HUD_ELEMENT_OP_op_15, arg0,
#define hs_RandomBranch(args...) HUD_ELEMENT_OP_RandomBranch, (sizeof((s32[]){args})/sizeof(s32)), args,
#define hs_SetFlags(arg0) HUD_ELEMENT_OP_SetFlags, arg0,
#define hs_ClearFlags(arg0) HUD_ELEMENT_OP_ClearFlags, arg0,
#define hs_PlaySound(arg0) HUD_ELEMENT_OP_PlaySound, arg0,
#define hs_SetPivot(arg0, arg1) HUD_ELEMENT_OP_SetPivot, arg0, arg1,

/// Basic HudScript used for static CI images, setting size with hs_SetTileSize
#define HES_TEMPLATE_CI_ENUM_SIZE(name, sizeX, sizeY) \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_##sizeX##x##sizeY) \
        hs_Loop \
            hs_SetCI(60, name) \
        hs_Restart \
        hs_End \
    }

/// Basic HudScript used for static CI images, setting size with hs_SetCustomSize
#define HES_TEMPLATE_CI_CUSTOM_SIZE(name, sizeX, sizeY) \
    { \
        hs_SetVisible \
        hs_SetCustomSize(sizeX, sizeY) \
        hs_Loop \
            hs_SetCI(60, name) \
        hs_Restart \
        hs_End \
    }

// hud script templates used to generate scripts via src/item_hud_scripts.yaml

#define HES_TEMPLATE_STANDARD_ITEM(icon) \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_32x32) \
        hs_Loop \
            hs_SetIcon(60, icon) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_HEART_PIECE() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_24x24) \
        hs_Loop \
            hs_SetIcon(60, anim_heart_piece) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_HEART() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_24x24) \
        hs_Loop \
            hs_SetIcon(10, anim_heart_0) \
            hs_SetIcon(6, anim_heart_1) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_STAR_POINT() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_24x24) \
        hs_Loop \
            hs_SetIcon(2, anim_sp_0) \
            hs_SetIcon(2, anim_sp_1) \
            hs_SetIcon(2, anim_sp_2) \
            hs_SetIcon(2, anim_sp_3) \
            hs_SetIcon(2, anim_sp_4) \
            hs_SetIcon(2, anim_sp_5) \
            hs_SetIcon(2, anim_sp_6) \
            hs_SetIcon(2, anim_sp_7) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_SMALL_STAR_POINT() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_8x8) \
        hs_Loop \
            hs_SetIcon(2, anim_sp_small_0) \
            hs_SetIcon(2, anim_sp_small_1) \
            hs_SetIcon(2, anim_sp_small_2) \
            hs_SetIcon(2, anim_sp_small_3) \
            hs_SetIcon(2, anim_sp_small_4) \
            hs_SetIcon(2, anim_sp_small_5) \
            hs_SetIcon(2, anim_sp_small_6) \
            hs_SetIcon(2, anim_sp_small_7) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_HEART_POINT() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_32x32) \
        hs_Loop \
            hs_SetIcon(8, anim_hp_0) \
            hs_SetIcon(5, anim_hp_1) \
            hs_SetIcon(8, anim_hp_2) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_FLOWER_POINT() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_32x32) \
        hs_Loop \
            hs_SetIcon(8, anim_fp_0) \
            hs_SetIcon(5, anim_fp_1) \
            hs_SetIcon(8, anim_fp_2) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_STAR_PIECE() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_32x32) \
        hs_Loop \
            hs_SetIcon(12, anim_star_piece_0) \
            hs_SetIcon(4, anim_star_piece_1) \
            hs_SetIcon(12, anim_star_piece_2) \
            hs_SetIcon(4, anim_star_piece_1) \
        hs_Restart \
        hs_End \
    }

#define HES_TEMPLATE_COIN() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_24x24) \
        hs_Loop \
            hs_op_15(0) \
            hs_SetIcon(3, anim_coin_0) \
            hs_SetIcon(3, anim_coin_1) \
            hs_SetIcon(3, anim_coin_4) \
            hs_SetIcon(3, anim_coin_5) \
            hs_SetIcon(3, anim_coin_6) \
            hs_SetIcon(3, anim_coin_7) \
            hs_SetIcon(3, anim_coin_8) \
            hs_SetIcon(3, anim_coin_9) \
            hs_RandomRestart(100, 70) \
            hs_op_15(1) \
            hs_SetIcon(3, anim_coin_0) \
            hs_SetIcon(2, anim_coin_1) \
            hs_SetIcon(1, anim_coin_2) \
            hs_SetIcon(1, anim_coin_3) \
            hs_SetIcon(2, anim_coin_4) \
            hs_SetIcon(3, anim_coin_5) \
            hs_SetIcon(3, anim_coin_6) \
            hs_SetIcon(3, anim_coin_7) \
            hs_SetIcon(3, anim_coin_8) \
            hs_SetIcon(3, anim_coin_9) \
        hs_Restart \
        hs_End \
    }

#define HES_COIN_SPARKLE(dx, dy) \
    { \
        hs_SetTexelOffset(dx, dy) \
        hs_SetIcon(1, anim_shimmer_0) \
        hs_SetIcon(1, anim_shimmer_1) \
        hs_SetIcon(1, anim_shimmer_2) \
        hs_SetIcon(2, anim_shimmer_6) \
        hs_SetIcon(1, anim_shimmer_2) \
        hs_SetIcon(1, anim_shimmer_3) \
        hs_SetIcon(1, anim_shimmer_6) \
        hs_SetIcon(1, anim_shimmer_4) \
        hs_SetIcon(1, anim_shimmer_6) \
        hs_SetIcon(1, anim_shimmer_5) \
        hs_SetIcon(16, anim_shimmer_6) \
        hs_End \
    }

#define HES_TEMPLATE_COIN_SPARKLE() \
    { \
        hs_SetVisible \
        hs_SetTileSize(HUD_ELEMENT_SIZE_8x8) \
        hs_RandomBranch( \
            HS_PTR(HES_Item_CoinSparkleA), \
            HS_PTR(HES_Item_CoinSparkleB), \
            HS_PTR(HES_Item_CoinSparkleC), \
            HS_PTR(HES_Item_CoinSparkleD), \
            HS_PTR(HES_Item_CoinSparkleE)) \
        hs_End \
    }

void hud_element_load_script(HudElement* hudElement, HudScript* anim);

/// @param clamp        0 = repeat; 1 = clamp
/// @param dropShadow   Whether to render a drop shadow or not
void hud_element_draw_rect(HudElement* hudElement, s16 texSizeX, s16 texSizeY, s16 drawSizeX, s16 drawSizeY, s16 offsetX, s16 offsetY, s32 clamp, s32 dropShadow);

void hud_element_clear_cache(void);

void init_hud_element_list(void);

/// Creates a new HUD element and returns its ID.
s32 hud_element_create(HudScript* anim);

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

void hud_element_set_script(s32 id, HudScript* anim);

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

void create_standard_popup_menu(PopupMenu*);

#endif
