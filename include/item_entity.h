#ifndef ITEM_ENTITY_H
#define ITEM_ENTITY_H

#include "common.h"

typedef s32 ItemScript[];

enum {
    ITEM_SCRIPT_OP_End,
    ITEM_SCRIPT_OP_SetImage,
    ITEM_SCRIPT_OP_Restart,
    ITEM_SCRIPT_OP_Loop,
    ITEM_SCRIPT_OP_RandomRestart
};

#define is_End ITEM_SCRIPT_OP_End,
#define is_SetIcon(time, icon) ITEM_SCRIPT_OP_SetImage, time, ICON_##icon##_raster, ICON_##icon##_palette, 0, 0,
#define is_Restart ITEM_SCRIPT_OP_Restart,
#define is_Loop ITEM_SCRIPT_OP_Loop,
#define is_RandomRestart(max, cutoff) ITEM_SCRIPT_OP_RandomRestart, max, cutoff,

// item entity script templates used to generate scripts via src/item_entity_scripts.yaml

#define IES_TEMPLATE_STANDARD(icon) \
    { \
        is_SetIcon(60, icon) \
        is_Restart \
        is_End \
    }

#define IES_TEMPLATE_BASIC(icon) \
    { \
        is_SetIcon(255, icon) \
        is_End \
    }

#define IES_TEMPLATE_HEART() \
    { \
        is_SetIcon(10, anim_heart_0) \
        is_SetIcon(6, anim_heart_1) \
        is_Restart \
        is_End \
    }

#define IES_TEMPLATE_COIN() \
    { \
        is_Loop \
            is_SetIcon(3, anim_coin_0) \
            is_SetIcon(3, anim_coin_1) \
            is_SetIcon(3, anim_coin_4) \
            is_SetIcon(3, anim_coin_5) \
            is_SetIcon(3, anim_coin_6) \
            is_SetIcon(3, anim_coin_7) \
            is_SetIcon(3, anim_coin_8) \
            is_SetIcon(3, anim_coin_9) \
        is_RandomRestart(100, 50) \
            is_SetIcon(3, anim_coin_0) \
            is_SetIcon(2, anim_coin_1) \
            is_SetIcon(1, anim_coin_2) \
            is_SetIcon(1, anim_coin_3) \
            is_SetIcon(2, anim_coin_4) \
            is_SetIcon(3, anim_coin_5) \
            is_SetIcon(3, anim_coin_6) \
            is_SetIcon(3, anim_coin_7) \
            is_SetIcon(3, anim_coin_8) \
            is_SetIcon(3, anim_coin_9) \
        is_Restart \
        is_End \
    }

#define IES_TEMPLATE_SP() \
    { \
        is_SetIcon(2, anim_sp_0) \
        is_SetIcon(2, anim_sp_1) \
        is_SetIcon(2, anim_sp_2) \
        is_SetIcon(2, anim_sp_3) \
        is_SetIcon(2, anim_sp_4) \
        is_SetIcon(2, anim_sp_5) \
        is_SetIcon(2, anim_sp_6) \
        is_SetIcon(2, anim_sp_7) \
        is_Restart \
        is_End \
    }

#define IES_TEMPLATE_HP() \
    { \
        is_SetIcon(8, anim_hp_0) \
        is_SetIcon(5, anim_hp_1) \
        is_SetIcon(8, anim_hp_2) \
        is_Restart \
        is_End \
    }

#define IES_TEMPLATE_FP() \
    { \
        is_SetIcon(8, anim_fp_0) \
        is_SetIcon(5, anim_fp_1) \
        is_SetIcon(8, anim_fp_2) \
        is_Restart \
        is_End \
    }

#define IES_TEMPLATE_STAR_PIECE() \
    { \
        is_SetIcon(12, anim_star_piece_0) \
        is_SetIcon(4, anim_star_piece_1) \
        is_SetIcon(12, anim_star_piece_2) \
        is_SetIcon(4, anim_star_piece_1) \
        is_Restart \
        is_End \
    }

#endif
