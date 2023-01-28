#include "hos_06.h"
#include "effects.h"
#include "model.h"

#define NAME_SUFFIX _Merluvlee

#include "world/common/complete/KeyItemChoice.inc.c"
#include "world/common/complete/GiveReward.inc.c"

u8 N(HintPrices)[] = {
    5, 20, 30
};

typedef struct ItemHint {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} ItemHint; // size = 0xC

ItemHint N(BadgeHintData)[] = {
    { 0x00220001, 266, -13 },
    { 0x00220002, 268, 43 },
    { 0x00220004, 303, -74 },
    { 0x00220003, 225, -74 },
    { 0x00220005, 235, -53 },
    { 0x00220007, 302, -33 },
    { 0x00220008, 228, -89 },
    { 0x00220006, 239, 25 },
    { 0x00220000, 291, 63 },
    { 0x00220009, 292, -59 },
    { 0x0022000B, 265, -89 },
    { 0x0022000C, 267, 41 },
    { 0x0022000D, 224, -13 },
    { 0x00220011, 263, 0xFFFFD8F0 },
    { 0x0022000E, 232, -71 },
    { 0x0022000F, 279, 11 },
    { 0x00220010, 264, 41 },
    { 0x00220012, 238, -74 },
    { 0x0022000A, 294, 43 },
    { 0x00220013, 233, -53 },
    { 0x00220016, 237, -40 },
    { 0x00220041, 260, -89 },
    { 0x00220014, 262, 77 },
    { 0x00220017, 297, -53 },
    { 0x00220018, 306, -10 },
    { 0x00220019, 307, 94 },
    { 0x0022001A, 231, -50 },
    { 0x0022001B, 308, 0xFFFFD8F0 },
    { 0x0022001D, 248, -50 },
    { 0x0022001E, 309, -89 },
    { 0x00220020, 255, 0x00002712 },
    { 0x00220021, 310, 11 },
    { 0x00220022, 320, 0x00002712 },
    { 0x00220023, 321, 43 },
    { 0x00220024, 261, 0x00002712 },
    { 0x00220025, 312, 43 },
    { 0x00220026, 227, -53 },
    { 0x00220027, 278, 77 },
    { 0x00220028, 275, 77 },
    { 0x00220029, 244, 7 },
    { 0x0022002A, 226, 0x00002712 },
    { 0x0022002B, 316, -10 },
    { 0x0022002C, 245, 0x00002712 },
    { 0x00220038, 256, 0x00002712 },
    { 0x00220034, 250, -10 },
    { 0x00220035, 236, 25 },
    { 0x00220036, 229, -62 },
    { 0x0022002F, 274, 0xFFFFD8F0 },
    { 0x0022002D, 273, -13 },
    { 0x0022002E, 269, -53 },
    { 0x00220030, 249, -33 },
    { 0x00220037, 242, 0x00002712 },
    { 0x00220031, 304, 41 },
    { 0x00220032, 314, -71 },
    { 0x00220039, 241, 0x00002712 },
    { 0x00220033, 251, -10 },
    { 0x0022003A, 276, 63 },
    { 0x0022003B, 247, -62 },
    { 0x0022003C, 243, 0x00002712 },
    { 0x00220042, 252, 0x00002712 },
    { 0x00220043, 259, -70 },
    { 0x00220044, 282, 0x00002712 },
    { 0x00220045, 283, 0x00002712 },
    { 0x00220046, 253, 0x00002712 },
    { 0x0022004A, 287, -74 },
    { 0x00220048, 286, -10 },
    { 0x0022004B, 285, 0xFFFFD8F0 },
    { 0x00220049, 254, 0x00002712 },
    { 0x0022004E, 230, -74 },
    { 0x0022004C, 284, -70 },
    { 0x0022004D, 288, 15 },
    { 0x00220015, 323, -13 },
    { 0x0022003D, 325, -53 },
    { 0x0022003E, 326, 0xFFFFD8F0 },
    { 0x0022003F, 327, 63 },
    { 0x00220040, 328, -70 },
    { 0x00220047, 324, 0x00002712 },
    { 0x0022001C, 330, 7 },
    { 0x0022001F, 333, 7 },
};

ItemHint N(SuperBlockHintData)[] = {
    { 0x0022004F, GF_TIK07_SuperBlock, -59 },
    { 0x00220050, GF_TIK10_SuperBlock, -40 },
    { 0x00220051, GF_TIK02_SuperBlock, 24 },
    { 0x00220052, GF_TIK17_SuperBlock, 61 },
    { 0x00220053, GF_TIK19_SuperBlock, 15 },
    { 0x00220054, GF_IWA10_SuperBlock, -59 },
    { 0x00220055, GF_SBK56_SuperBlock, -75 },
    { 0x00220056, GF_ISK10_SuperBlock, -62 },
    { 0x00220057, GF_DGB04_SuperBlock, -31 },
    { 0x00220058, GF_OMO11_SuperBlock, -10 },
    { 0x00220059, GF_JAN08_SuperBlock, 11 },
    { 0x0022005A, GF_KZN04_SuperBlock, 24 },
    { 0x0022005B, GF_KZN09_SuperBlock, 24 },
    { 0x0022005C, GF_FLO08_SuperBlock, 43 },
    { 0x0022005D, GF_FLO16_SuperBlock, 43 },
    { 0x0022005E, GF_SAM08_SuperBlock, 63 },
};

ItemHint N(StarPieceHintData)[] = {
    { MSG_MerluvleeHint_StarPiece_01, GF_KMR05_Item_StarPiece,  -10000 },
    { MSG_MerluvleeHint_StarPiece_02, GF_KMR11_Tree1_StarPiece, -10000 },
    { MSG_MerluvleeHint_StarPiece_03, GF_KMR00_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_04, GF_KMR03_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_05, GF_KMR11_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_06, GF_MAC00_Item_StarPiece,  STORY_CH5_SUSHIE_JOINED_PARTY },
    { MSG_MerluvleeHint_StarPiece_07, GF_MAC00_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_08, GF_MAC02_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_09, GF_MAC03_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_10, GF_MAC05_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_11, GF_MAC01_Tree1_StarPiece, -10000 },
    { MSG_MerluvleeHint_StarPiece_12, GF_HOS00_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_13, GF_HOS01_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_14, GF_HOS06_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_15, GF_HOS01_Item_StarPiece,  -10000 },
    { MSG_MerluvleeHint_StarPiece_16, GF_TIK07_Item_StarPiece,  STORY_CH2_GOT_SUPER_HAMMER },

    { MSG_MerluvleeHint_StarPiece_17, GF_NOK12_Item_StarPiece,  STORY_CH1_KNOCKED_SWITCH_FROM_TREE },
    { MSG_MerluvleeHint_StarPiece_18, GF_NOK01_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_19, GF_NOK13_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_20, GF_NOK14_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_21, GF_NOK02_Item_StarPiece,  STORY_CH1_KOOPER_JOINED_PARTY },
    { MSG_MerluvleeHint_StarPiece_22, GF_NOK15_Tree1_StarPiece, STORY_CH1_KOOPER_JOINED_PARTY },

    { MSG_MerluvleeHint_StarPiece_23, GF_IWA02_Item_StarPiece,  STORY_CH2_SPOKE_WITH_PARAKARRY },
    { MSG_MerluvleeHint_StarPiece_24, GF_IWA01_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_25, GF_IWA03_Item_StarPiece,  STORY_CH2_SPOKE_WITH_PARAKARRY },
    { MSG_MerluvleeHint_StarPiece_26, GF_SBK33_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_27, GF_DRO02_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_28, GF_ISK06_Item_StarPiece,  STORY_CH2_UNCOVERED_DRY_DRY_RUINS },

    { MSG_MerluvleeHint_StarPiece_29, GF_OBK01_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_30, GF_OBK02_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_31, GF_OBK04_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_32, GF_OBK08_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_33, GF_OBK06_Crate_StarPiece, STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_34, GF_MIM12_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_35, GF_ARN04_Item_StarPiece,  STORY_CH3_SAW_TUBBA_EAT_BOO },
    { MSG_MerluvleeHint_StarPiece_36, GF_DGB03_Item_StarPiece,  STORY_CH3_SAW_TUBBA_EAT_BOO },
    { MSG_MerluvleeHint_StarPiece_37, GF_DGB07_Item_StarPiece,  STORY_CH3_SAW_TUBBA_EAT_BOO },

    { MSG_MerluvleeHint_StarPiece_38, GF_OMO04_Item_StarPieceA, STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_StarPiece_39, GF_OMO03_HiddenPanel,     STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_StarPiece_40, GF_OMO06_HiddenPanel,     STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_StarPiece_41, GF_OMO08_HiddenPanel,     STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_StarPiece_42, GF_OMO10_HiddenPanel,     STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_StarPiece_43, GF_OMO04_Item_StarPieceB, STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_StarPiece_44, GF_OMO09_Item_StarPiece,  STORY_CH4_FOUND_HIDDEN_DOOR },

    { MSG_MerluvleeHint_StarPiece_45, GF_JAN02_HiddenPanel,     STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_StarPiece_46, GF_JAN15_HiddenPanel,     STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_StarPiece_47, GF_JAN04_Item_StarPiece,  STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_StarPiece_48, GF_JAN01_Tree7_StarPiece, STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_StarPiece_49, GF_JAN10_Item_StarPiece,  STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_StarPiece_50, GF_KZN09_HiddenPanel,     STORY_CH5_ENTERED_MT_LAVA_LAVA },
    { MSG_MerluvleeHint_StarPiece_51, GF_KZN18_HiddenPanel,     STORY_CH5_ENTERED_MT_LAVA_LAVA },

    { MSG_MerluvleeHint_StarPiece_52, GF_FLO16_Item_StarPiece,  STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_StarPiece_53, GF_FLO03_HiddenPanel,     STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_StarPiece_54, GF_FLO24_HiddenPanel,     STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_StarPiece_55, GF_FLO14_Item_StarPiece,  STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_StarPiece_56, GF_FLO25_HiddenPanel,     STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_StarPiece_57, GF_FLO08_Item_StarPiece,  STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },

    { MSG_MerluvleeHint_StarPiece_58, GF_SAM10_Item_StarPiece,  STORY_CH7_MAYOR_MURDER_MYSTERY },
    { MSG_MerluvleeHint_StarPiece_59, GF_SAM01_HiddenPanel,     STORY_CH7_MAYOR_MURDER_MYSTERY },
    { MSG_MerluvleeHint_StarPiece_60, GF_SAM04_HiddenPanel,     STORY_CH7_MAYOR_MURDER_MYSTERY },
    { MSG_MerluvleeHint_StarPiece_61, GF_PRA15_Item_StarPiece,  STORY_CH7_RAISED_FROZEN_STAIRS },
    { MSG_MerluvleeHint_StarPiece_62, GF_PRA21_HiddenPanel,     STORY_CH7_RAISED_FROZEN_STAIRS },
    { MSG_MerluvleeHint_StarPiece_63, GF_PRA22_HiddenPanel,     STORY_CH7_RAISED_FROZEN_STAIRS },
};

s32 func_802411BC_A3A69C(s32 badgeID) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPlayerData.badges); i++) {
        if (gPlayerData.badges[i] == badgeID) {
            return TRUE;
        }
    }
    return FALSE;
}

API_CALLABLE(N(func_802411F0_A3A6D0)) {
    u32 i;

    for (i = 0; i < 79; i++) {
        evt_set_variable(NULL, AreaFlag(3) + i, 0);
    }
    for (i = 0; i < 16; i++) {
        evt_set_variable(NULL, AreaFlag(100) + i, 0);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetBadgeHint)) {
    s32 temp_s6 = evt_get_variable(NULL, GameByte(0));
    u32 count = 0;
    ItemHint* it;
    s32 temp_s5;
    u32 i;

    script->varTable[1] = 0;
    for (i = 0, it = N(BadgeHintData); i < ARRAY_COUNT(N(BadgeHintData)); i++, it++) {
        if (temp_s6 >= it->unk_08 &&
            func_802411BC_A3A69C(it->unk_04) == 0 &&
            evt_get_variable(NULL, AreaFlag(3 + i)) == 0) {
            count++;
        }
    }

    if (count > 0) {
        temp_s5 = rand_int(count - 1);
        it = N(BadgeHintData);
        count = 0;
        i = 0;

        for (; i < ARRAY_COUNT(N(BadgeHintData)); i++, it++) {
            if (temp_s6 >= it->unk_08 &&
                func_802411BC_A3A69C(it->unk_04) == 0 &&
                evt_get_variable(NULL, AreaFlag(3 + i)) == 0)
            {
                if (count == temp_s5) {
                    script->varTable[1] = it->unk_00;
                    evt_set_variable(NULL, AreaFlag(3 + i), 1);
                    break;
                }
                count++;
            }
        }
        return ApiStatus_DONE2;
    }

    for (i = 0, it = N(BadgeHintData); i < ARRAY_COUNT(N(BadgeHintData)); i++, it++) {
        if (it->unk_08 == 0x2712 &&
            func_802411BC_A3A69C(it->unk_04) == 0 &&
            evt_get_variable(NULL, AreaFlag(3 + i)) == 0)
        {
            count++;
        }
    }

    if (count > 0) {
        temp_s5 = rand_int(count - 1);
        it = N(BadgeHintData);
        count = 0;
        i = 0;

        for (; i < ARRAY_COUNT(N(BadgeHintData)); i++, it++) {
            if (it->unk_08 == 0x2712 &&
                func_802411BC_A3A69C(it->unk_04) == 0 &&
                evt_get_variable(NULL, AreaFlag(3 + i)) == 0)
            {
                if (count == temp_s5) {
                    script->varTable[1] = it->unk_00;
                    evt_set_variable(NULL, AreaFlag(3 + i), 1);
                    break;
                }
                count++;
            }
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetSuperBlockHint)) {
    s32 temp_s5 = evt_get_variable(NULL, GameByte(0));
    u32 count = 0;
    s32 temp_s7;
    ItemHint* it;
    u32 i;

    script->varTable[1] = 0;

    it = N(SuperBlockHintData);
    for (i = 0; i < ARRAY_COUNT(N(SuperBlockHintData)); i++, it++) {
        if (temp_s5 >= it->unk_08 &&
            evt_get_variable(NULL, it->unk_04) == 0 &&
            evt_get_variable(NULL, AreaFlag(100 + i)) == 0)
        {
            count++;
        }
    }

    if (count > 0) {
        temp_s7 = rand_int(count - 1);
        it = N(SuperBlockHintData);
        count = 0;

        for (i = 0; i < ARRAY_COUNT(N(SuperBlockHintData)); i++, it++) {
            if (temp_s5 >= it->unk_08 &&
                evt_get_variable(NULL, it->unk_04) == 0 &&
                evt_get_variable(NULL, AreaFlag(100 + i)) == 0)
            {
                if (count == temp_s7) {
                    script->varTable[1] = it->unk_00;
                    evt_set_variable(NULL, AreaFlag(100 + i), 1);
                    break;
                }
                count++;
            }
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetStarPieceHint)) {
    s32 temp_s5 = evt_get_variable(NULL, GameByte(0));
    u32 count = 0;
    s32 temp_s7;
    ItemHint* it;
    u32 i;

    script->varTable[1] = 0;

    it = N(StarPieceHintData);
    for (i = 0; i < ARRAY_COUNT(N(StarPieceHintData)); i++, it++) {
        if (temp_s5 >= it->unk_08 &&
            evt_get_variable(NULL, it->unk_04) == 0 &&
            evt_get_variable(NULL, AreaFlag(116 + i)) == 0)
        {
            count++;
        }
    }

    if (count > 0) {
        temp_s7 = rand_int(count - 1);
        it = N(StarPieceHintData);
        count = 0;

        for (i = 0; i < ARRAY_COUNT(N(StarPieceHintData)); i++, it++) {
            if (temp_s5 >= it->unk_08 &&
                evt_get_variable(NULL, it->unk_04) == 0 &&
                evt_get_variable(NULL, AreaFlag(116 + i)) == 0)
            {
                if (count == temp_s7) {
                    script->varTable[1] = it->unk_00;
                    evt_set_variable(NULL, AreaFlag(116 + i), 1);
                    break;
                }
                count++;
            }
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(HasEnoughCoinsForHint)) {
    Bytecode* args = script->ptrReadPos;
    s32 hintType = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    if (gPlayerData.coins < N(HintPrices)[hintType]) {
        evt_set_variable(script, outVar, TRUE);
    } else {
        evt_set_variable(script, outVar, FALSE);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeductHintCoins)) {
    Bytecode* args = script->ptrReadPos;
    s32 hintType = evt_get_variable(script, *args++);

    gPlayerData.coins -= N(HintPrices)[hintType];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(RefundHintCoins)) {
    Bytecode* args = script->ptrReadPos;
    s32 hintType = evt_get_variable(script, *args++);

    gPlayerData.coins += N(HintPrices)[hintType];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802418E8_A3ADC8)) {
    if (isInitialCall) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x79)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7A)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7B)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7C)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7D)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7F)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0xD0)), -1, FOG_MODE_3);
        set_model_env_color_parameters(255, 255, 255, 0, 0, 0);
        script->functionTemp[0] = 255;
    }

    script->functionTemp[0] -= 4;
    if (script->functionTemp[0] < 64) {
        script->functionTemp[0] = 64;
    }
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
    if (script->functionTemp[0] == 64) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80241A58_A3AF38)) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
        script->functionTemp[2] = 64;
        script->functionTemp[1] = 0;
    }
    if (script->functionTemp[1] == 0) {
        script->functionTemp[0] += 4;
        script->functionTemp[2] += 4;
        if (script->functionTemp[0] > 127) {
            script->functionTemp[0] = 127;
        }
        if (script->functionTemp[2] > 127) {
            script->functionTemp[2] = 127;
        }
        if (script->functionTemp[0] == 127 && (script->functionTemp[2] == script->functionTemp[0])) {
            script->functionTemp[1] = 1;
        }
    } else {
        script->functionTemp[0] -= 4;
        script->functionTemp[2] -= 4;
        if (script->functionTemp[0] < 64) {
            script->functionTemp[0] = 64;
        }
        if (script->functionTemp[2] < 0) {
            script->functionTemp[2] = 0;
        }
    }
    set_model_env_color_parameters(
        script->functionTemp[0], script->functionTemp[0], script->functionTemp[0],
        script->functionTemp[2], script->functionTemp[2], script->functionTemp[2]
    );
    if (script->functionTemp[0] == 64 && script->functionTemp[2] == 0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80241B74_A3B054)) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
    }

    script->functionTemp[0] += 4;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);

    if (script->functionTemp[0] == 255) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x79)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7A)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7B)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7C)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7D)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7F)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0xD0)), -1, FOG_MODE_0);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

// TODO may not be motionBlurFlame
API_CALLABLE(N(func_80241CCC_A3B1AC)) {
    EffectInstance* effects[3];
    Matrix4f sp28, sp68;
    f32 tx;
    f32 ty;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f30;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 180;
        script->functionTempPtr[1] = (EffectInstance*) evt_get_variable(script, ArrayVar(3));
        script->functionTempPtr[2] = (EffectInstance*) evt_get_variable(script, ArrayVar(4));
        script->functionTempPtr[3] = (EffectInstance*) evt_get_variable(script, ArrayVar(5));
    }

    effects[0] = script->functionTempPtr[1];
    effects[1] = script->functionTempPtr[2];
    effects[2] = script->functionTempPtr[3];
    temp_f30 = (sin_deg(script->functionTemp[0]) * 10.0f) + 10.0f;
    temp_f28 = (sin_deg(script->functionTemp[0]) * 25.0f) + 10.0f;
    temp_f24 = script->functionTemp[0] * 10;

    for (i = 0; i < ARRAY_COUNT(effects); i++) {
        guRotateF(sp28, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guRotateF(sp68, i * 120, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp68, sp28, sp28);
        tx = temp_f30 * sin_deg(temp_f24);
        ty = temp_f28 * cos_deg(temp_f24);
        guTranslateF(sp68, tx, ty, 0.0f);
        guMtxCatF(sp68, sp28, sp28);
        effects[i]->data.motionBlurFlame->pos.x = sp28[3][0];
        effects[i]->data.motionBlurFlame->pos.y = sp28[3][1];
        effects[i]->data.motionBlurFlame->pos.z = sp28[3][2];
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 16) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            effects[i]->data.motionBlurFlame->unk_4C = script->functionTemp[0];
        }
    }

    if (script->functionTemp[0] < 0) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            remove_effect(effects[i]);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80241F98_A3B478)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    // TODO effect may be wrong
    effect->data.energyOrbWave->unk_1C++;
    return ApiStatus_DONE2;
}

EvtScript N(D_80244F3C_A3E41C) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MERLEE_SPELL, 2, 8)
    EVT_CALL(SetNpcAnimation, NPC_Merluvlee, ANIM_Merluvlee_Release)
    EVT_CALL(GetModelCenter, MODEL_o100)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlaySoundAt, SOUND_207, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), -1)
    EVT_SET(ArrayVar(1), LVarF)
    EVT_CALL(EnableModel, MODEL_o185, FALSE)
    EVT_CALL(EnableModel, MODEL_o186, FALSE)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(N(func_802418E8_A3ADC8))
    EVT_END_THREAD
    EVT_CALL(GetModelCenter, MODEL_o100)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-91.5), EVT_FLOAT(18.40625))
    EVT_CALL(GetCamDistance, CAM_DEFAULT, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SETF(LVar0, EVT_FLOAT(284.6))
    EVT_ELSE
        EVT_SETF(LVar0, EVT_FLOAT(-284.6))
    EVT_END_IF
    EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar0)
    EVT_CALL(GetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    EVT_SETF(LVar1, EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_PLAY_EFFECT(EFFECT_MERLIN_HOUSE_STARS, 0, -298, 21, -330)
    EVT_SET(ArrayVar(2), LVarF)
    EVT_CALL(GetModelCenter, MODEL_o100)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(3), LVarF)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(4), LVarF)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(5), LVarF)
    EVT_THREAD
        EVT_CALL(N(func_80241CCC_A3B1AC))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(GetModelCenter, MODEL_o100)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlaySoundAt, SOUND_208, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(30)
    EVT_CALL(GetModelCenter, MODEL_o100)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlaySoundAt, SOUND_208, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(N(func_80241A58_A3AF38))
    EVT_END_THREAD
    EVT_CALL(GetModelCenter, MODEL_o100)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlaySoundAt, SOUND_208, 0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(70)
    EVT_CALL(func_802D7B10, ArrayVar(2))
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_607, 0, LVar0, LVar1, LVar2)
    EVT_CALL(N(func_80241F98_A3B478), ArrayVar(1))
    EVT_WAIT(15)
    EVT_CALL(EnableModel, MODEL_o185, TRUE)
    EVT_CALL(EnableModel, MODEL_o186, TRUE)
    EVT_CALL(func_802D7B10, ArrayVar(1))
    EVT_THREAD
        EVT_CALL(N(func_80241B74_A3B054))
    EVT_END_THREAD
    EVT_WAIT(46)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(SetNpcAnimation, NPC_Merluvlee, ANIM_Merluvlee_Idle)
    EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit) = {
    EVT_CALL(N(func_802411F0_A3A6D0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KootRequestBall) = {
    EVT_IF_EQ(GB_KootFavor_Current, 8)
        EVT_IF_EQ(GF_HOS06_MerluvleeRequestedCrystalBall, FALSE)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_WAIT(1)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
            EVT_WAIT(20)
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0046)
            EVT_WAIT(10)
            EVT_CALL(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0047)
            EVT_SET(GF_HOS06_MerluvleeRequestedCrystalBall, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(CrystalBallItems)[] = {
    ITEM_CRYSTAL_BALL,
    -1
};

EvtScript N(EVS_KootCheckBall) = {
    EVT_IF_EQ(GF_HOS06_MerluvleeRequestedCrystalBall, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_HOS06_Gift_MerluvleesAutograph, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_CRYSTAL_BALL, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0048)
    EVT_ELSE
        EVT_CHOOSE_KEY_ITEM_FROM(N(CrystalBallItems))
        EVT_IF_NE(LVar0, -1)
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0049)
            EVT_GIVE_KEY_REWARD(ITEM_KOOT_LUIGI_AUTOGRAPH)
            EVT_SET(GF_HOS06_Gift_MerluvleesAutograph, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0048)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80245878) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 1)
    EVT_CALL(PlayerMoveTo, -49, 0, 6)
    EVT_CALL(PlayerFaceNpc, NPC_Merluvlee, FALSE)
    EVT_IF_EQ(MV_Unk_0A, 0)
        EVT_MALLOC_ARRAY(20, MV_Unk_0A)
    EVT_END_IF
    EVT_USE_ARRAY(MV_Unk_0A)
    EVT_IF_EQ(AF_HOS_B6, FALSE)
        EVT_SET(AF_HOS_B6, TRUE)
        EVT_IF_EQ(GF_HOS06_Met_Merluvlee, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0038)
            EVT_SET(GF_HOS06_Met_Merluvlee, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0039)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003A)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(ShowChoice, MSG_Choice_0011)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003C)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_0000)
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_IF_EQ(LVar0, 4)
        EVT_CALL(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003C)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(HasEnoughCoinsForHint), LVar0, LVar1)
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003D)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(DeductHintCoins), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003E)
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Gather, ANIM_Merluvlee_Gather, 0, MSG_HOS_0041)
            EVT_EXEC_WAIT(N(D_80244F3C_A3E41C))
            EVT_CALL(N(GetStarPieceHint))
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Think, ANIM_Merluvlee_Think, 0, MSG_HOS_0042)
                EVT_CALL(N(RefundHintCoins), 0)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, LVar1)
            EVT_END_IF
            EVT_GOTO(99)
        EVT_CASE_EQ(1)
            EVT_CALL(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003F)
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Gather, ANIM_Merluvlee_Gather, 0, MSG_HOS_0041)
            EVT_EXEC_WAIT(N(D_80244F3C_A3E41C))
            EVT_CALL(N(GetBadgeHint))
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Think, ANIM_Merluvlee_Think, 0, MSG_HOS_0043)
                EVT_CALL(N(RefundHintCoins), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, LVar1)
            EVT_END_IF
            EVT_GOTO(99)
        EVT_CASE_EQ(2)
            EVT_CALL(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0040)
            EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Gather, ANIM_Merluvlee_Gather, 0, MSG_HOS_0041)
            EVT_EXEC_WAIT(N(D_80244F3C_A3E41C))
            EVT_CALL(N(GetSuperBlockHint))
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Think, ANIM_Merluvlee_Think, 0, MSG_HOS_0044)
                EVT_CALL(N(RefundHintCoins), 2)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, LVar1)
            EVT_END_IF
            EVT_GOTO(99)
    EVT_END_SWITCH
    EVT_LABEL(99)
    EVT_CALL(func_802CF56C, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#define NAME_SUFFIX

EvtScript N(EVS_NpcInteract_Merluvlee) = {
    EVT_CALL(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0045)
    EVT_EXEC_WAIT(N(EVS_KootCheckBall_Merluvlee))
    EVT_EXEC_WAIT(N(EVS_KootRequestBall_Merluvlee))
    EVT_RETURN
    EVT_END
};
