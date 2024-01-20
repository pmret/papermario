#include "hos_06.h"
#include "effects.h"
#include "model.h"
#include "sprite/player.h"

#include "world/common/complete/KeyItemChoice.inc.c"
#include "world/common/complete/GiveReward.inc.c"

u8 N(HintPrices)[] = {
    5, 20, 30
};

// for hints available at any point in the story
// constant is smaller than any valid story progress value
#define STORY_REQ_ANY_TIME -10000

typedef struct BadgeHint {
    /* 0x00 */ s32 hintMsg;
    /* 0x04 */ s32 itemID;
    /* 0x08 */ s32 requiredProgress;
} BadgeHint; // size = 0xC

// badges in Merlow's shop only get hints once all other (currently available) badges are obtained
// constant is larger than any valid story progress value
#define BADGE_REQ_MERLOW_SHOP 10002

BadgeHint N(BadgeHintData)[] = {
    { MSG_MerluvleeHint_JumpCharge,       ITEM_JUMP_CHARGE,   STORY_CH3_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_SuperJumpCharge,  ITEM_S_JUMP_CHG,     STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_ShrinkStomp,      ITEM_SHRINK_STOMP,   STORY_CH1_DEFEATED_JR_TROOPA },
    { MSG_MerluvleeHint_Multibounce,      ITEM_MULTIBOUNCE,    STORY_CH1_DEFEATED_JR_TROOPA },
    { MSG_MerluvleeHint_SleepStomp,       ITEM_SLEEP_STOMP,    STORY_CH2_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_DDownJump,        ITEM_D_DOWN_JUMP,    STORY_CH3_SAW_TUBBA_EAT_BOO },
    { MSG_MerluvleeHint_PowerBounce,      ITEM_POWER_BOUNCE,   STORY_CH1_SPOTTED_BY_KOOPA_BROS },
    { MSG_MerluvleeHint_DizzyStomp,       ITEM_DIZZY_STOMP,    STORY_CH5_ENTERED_MT_LAVA_LAVA },
    { MSG_MerluvleeHint_MegaJump,         ITEM_MEGA_JUMP,      STORY_CH7_MAYOR_MURDER_MYSTERY },
    { MSG_MerluvleeHint_PowerSmash,       ITEM_POWER_SMASH1,   STORY_CH2_GOT_SUPER_HAMMER },
    { MSG_MerluvleeHint_SmashCharge,      ITEM_SMASH_CHARGE,   STORY_CH1_SPOTTED_BY_KOOPA_BROS },
    { MSG_MerluvleeHint_SuperSmashCharge, ITEM_S_SMASH_CHG,    STORY_CH5_RETURNED_TO_TOAD_TOWN },
    { MSG_MerluvleeHint_SpinSmash,        ITEM_SPIN_SMASH,     STORY_CH3_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_HammerThrow,      ITEM_HAMMER_THROW,   STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_QuakeHammer,      ITEM_QUAKE_HAMMER,   STORY_CH2_SPOKE_WITH_PARAKARRY },
    { MSG_MerluvleeHint_PowerQuake,       ITEM_POWER_QUAKE,    STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_MegaQuake,        ITEM_MEGA_QUAKE,     STORY_CH5_RETURNED_TO_TOAD_TOWN },
    { MSG_MerluvleeHint_DDownPound,       ITEM_D_DOWN_POUND,   STORY_CH1_DEFEATED_JR_TROOPA },
    { MSG_MerluvleeHint_MegaSmash,        ITEM_MEGA_SMASH,     STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_DoubleDip,        ITEM_DOUBLE_DIP,     STORY_CH2_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_QuickChange,      ITEM_QUICK_CHANGE,   STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_Refund,           ITEM_REFUND,         STORY_CH1_SPOTTED_BY_KOOPA_BROS },
    { MSG_MerluvleeHint_TripleDip,        ITEM_TRIPLE_DIP,     STORY_CH7_RAISED_FROZEN_STAIRS },
    { MSG_MerluvleeHint_DeepFocus1,       ITEM_DEEP_FOCUS1,    STORY_CH2_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_DeepFocus2,       ITEM_DEEP_FOCUS2,    STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_DeepFocus3,       ITEM_DEEP_FOCUS3,    STORY_CH8_REACHED_BOWSERS_CASTLE },
    { MSG_MerluvleeHint_HPPlus1,          ITEM_HP_PLUS_A,      STORY_CH3_INVITED_TO_BOOS_MANSION },
    { MSG_MerluvleeHint_HPPlus2,          ITEM_HP_PLUS_B,      STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_FPPlus1,          ITEM_FP_PLUS_A,      STORY_CH3_INVITED_TO_BOOS_MANSION },
    { MSG_MerluvleeHint_FPPlus2,          ITEM_FP_PLUS_B,      STORY_CH1_SPOTTED_BY_KOOPA_BROS },
    { MSG_MerluvleeHint_HappyHeart1,      ITEM_HAPPY_HEART_A,  BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_HappyHeart2,      ITEM_HAPPY_HEART_B,  STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_HappyFlower1,     ITEM_HAPPY_FLOWER_A, BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_HappyFlower2,     ITEM_HAPPY_FLOWER_B, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_FlowerSaver1,     ITEM_FLOWER_SAVER_A, BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_FlowerSaver2,     ITEM_FLOWER_SAVER_B, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_DodgeMaster,      ITEM_DODGE_MASTER,   STORY_CH2_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_PdownDup,         ITEM_P_DOWN_D_UP,    STORY_CH7_RAISED_FROZEN_STAIRS },
    { MSG_MerluvleeHint_PupDdown,         ITEM_P_UP_D_DOWN,    STORY_CH7_RAISED_FROZEN_STAIRS },
    { MSG_MerluvleeHint_AllorNothing,     ITEM_ALLOR_NOTHING,  STORY_CH4_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_PowerPlus1,       ITEM_POWER_PLUS_A,   BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_PowerPlus2,       ITEM_POWER_PLUS_B,   STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_HPDrain,          ITEM_HP_DRAIN,       BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_ZapTap,           ITEM_ZAP_TAP,        BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_IcePower,         ITEM_ICE_POWER,      STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_FireShield,       ITEM_FIRE_SHIELD,    STORY_CH5_ENTERED_MT_LAVA_LAVA },
    { MSG_MerluvleeHint_SpikeShield,      ITEM_SPIKE_SHIELD,   STORY_CH2_UNCOVERED_DRY_DRY_RUINS },
    { MSG_MerluvleeHint_CloseCall,        ITEM_CLOSE_CALL,     STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_LastStand,        ITEM_LAST_STAND,     STORY_CH3_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_PowerRush,        ITEM_POWER_RUSH,     STORY_CH2_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_MegaRush,         ITEM_MEGA_RUSH,      STORY_CH3_SAW_TUBBA_EAT_BOO },
    { MSG_MerluvleeHint_FeelingFine,      ITEM_FEELING_FINE,   BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_DamageDodge1,     ITEM_DAMAGE_DODGE_A, STORY_CH5_RETURNED_TO_TOAD_TOWN },
    { MSG_MerluvleeHint_DamageDodge2,     ITEM_DAMAGE_DODGE_B, STORY_CH2_SPOKE_WITH_PARAKARRY },
    { MSG_MerluvleeHint_PrettyLucky,      ITEM_PRETTY_LUCKY,   BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_DefendPlus,       ITEM_DEFEND_PLUS_A,  STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_LuckyDay,         ITEM_LUCKY_DAY,      STORY_CH7_MAYOR_MURDER_MYSTERY },
    { MSG_MerluvleeHint_SlowGo,           ITEM_SLOW_GO,        STORY_CH2_UNCOVERED_DRY_DRY_RUINS },
    { MSG_MerluvleeHint_AttackFXA,        ITEM_ATTACK_FX_A,    BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_PayOff,           ITEM_PAY_OFF,        BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_RunawayPay,       ITEM_RUNAWAY_PAY,    STORY_CH2_PARAKARRY_JOINED_PARTY },
    { MSG_MerluvleeHint_HeartFinder,      ITEM_HEART_FINDER,   BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_FlowerFinder,     ITEM_FLOWER_FINDER,  BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_MoneyMoney,       ITEM_MONEY_MONEY,    BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_SpeedySpin,       ITEM_SPEEDY_SPIN,    STORY_CH1_DEFEATED_JR_TROOPA },
    { MSG_MerluvleeHint_ISpy,             ITEM_I_SPY,          STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_DizzyAttack,      ITEM_DIZZY_ATTACK,   STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_ChillOut,         ITEM_CHILL_OUT,      BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_FirstAttack,      ITEM_FIRST_ATTACK,   STORY_CH1_DEFEATED_JR_TROOPA },
    { MSG_MerluvleeHint_SpinAttack,       ITEM_SPIN_ATTACK,    STORY_CH2_PARAKARRY_JOINED_PARTY },
    { MSG_MerluvleeHint_BumpAttack,       ITEM_BUMP_ATTACK,    STORY_CH5_SUSHIE_JOINED_PARTY },
    { MSG_MerluvleeHint_GroupFocus,       ITEM_GROUP_FOCUS,    STORY_CH3_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_AttackFXD,        ITEM_ATTACK_FX_D,    STORY_CH2_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_AttackFXB,        ITEM_ATTACK_FX_B,    STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_AttackFXE,        ITEM_ATTACK_FX_E,    STORY_CH7_MAYOR_MURDER_MYSTERY },
    { MSG_MerluvleeHint_AttackFXC,        ITEM_ATTACK_FX_C,    STORY_CH2_PARAKARRY_JOINED_PARTY },
    { MSG_MerluvleeHint_Peekaboo,         ITEM_PEEKABOO,       BADGE_REQ_MERLOW_SHOP },
    { MSG_MerluvleeHint_HPPlus3,          ITEM_HP_PLUS_C,      STORY_CH4_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_FPPlus3,          ITEM_FP_PLUS_C,      STORY_CH4_STAR_SPRIT_DEPARTED },
};

typedef struct GameFlagHint {
    /* 0x00 */ s32 hintMsg;
    /* 0x04 */ s32 doneFlag;
    /* 0x08 */ s32 requiredProgress;
} GameFlagHint; // size = 0xC

GameFlagHint N(SuperBlockHintData)[] = {
    { MSG_MerluvleeHint_SuperBlock_01, GF_TIK07_SuperBlock, STORY_CH2_GOT_SUPER_HAMMER },
    { MSG_MerluvleeHint_SuperBlock_02, GF_TIK10_SuperBlock, STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_SuperBlock_03, GF_TIK02_SuperBlock, STORY_CH5_ZIP_LINE_READY },
    { MSG_MerluvleeHint_SuperBlock_04, GF_TIK17_SuperBlock, STORY_CH7_INVITED_TO_STARBORN_VALLEY },
    { MSG_MerluvleeHint_SuperBlock_05, GF_TIK19_SuperBlock, STORY_CH5_SUSHIE_JOINED_PARTY },
    { MSG_MerluvleeHint_SuperBlock_06, GF_IWA10_SuperBlock, STORY_CH2_GOT_SUPER_HAMMER },
    { MSG_MerluvleeHint_SuperBlock_07, GF_SBK56_SuperBlock, STORY_CH1_STAR_SPRIT_DEPARTED },
    { MSG_MerluvleeHint_SuperBlock_08, GF_ISK10_SuperBlock, STORY_CH2_UNCOVERED_DRY_DRY_RUINS },
    { MSG_MerluvleeHint_SuperBlock_09, GF_DGB04_SuperBlock, STORY_UNUSED_FFFFFFE1 },
    { MSG_MerluvleeHint_SuperBlock_10, GF_OMO11_SuperBlock, STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_MerluvleeHint_SuperBlock_11, GF_JAN08_SuperBlock, STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_MerluvleeHint_SuperBlock_12, GF_KZN04_SuperBlock, STORY_CH5_ZIP_LINE_READY },
    { MSG_MerluvleeHint_SuperBlock_13, GF_KZN09_SuperBlock, STORY_CH5_ZIP_LINE_READY },
    { MSG_MerluvleeHint_SuperBlock_14, GF_FLO08_SuperBlock, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_SuperBlock_15, GF_FLO16_SuperBlock, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_MerluvleeHint_SuperBlock_16, GF_SAM08_SuperBlock, STORY_CH7_MAYOR_MURDER_MYSTERY },
};

GameFlagHint N(StarPieceHintData)[] = {
    { MSG_MerluvleeHint_StarPiece_01, GF_KMR05_Item_StarPiece,  STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_StarPiece_02, GF_KMR11_Tree1_StarPiece, STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_StarPiece_03, GF_KMR00_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_04, GF_KMR03_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_05, GF_KMR11_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_06, GF_MAC00_Item_StarPiece,  STORY_CH5_SUSHIE_JOINED_PARTY },
    { MSG_MerluvleeHint_StarPiece_07, GF_MAC00_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_08, GF_MAC02_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_09, GF_MAC03_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_10, GF_MAC05_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_11, GF_MAC01_Tree1_StarPiece, STORY_REQ_ANY_TIME },
    { MSG_MerluvleeHint_StarPiece_12, GF_HOS00_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_13, GF_HOS01_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_14, GF_HOS06_HiddenPanel,     STORY_CH3_GOT_SUPER_BOOTS },
    { MSG_MerluvleeHint_StarPiece_15, GF_HOS01_Item_StarPiece,  STORY_REQ_ANY_TIME },
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

s32 N(PlayerHasBadge)(s32 badgeID) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPlayerData.badges); i++) {
        if (gPlayerData.badges[i] == badgeID) {
            return TRUE;
        }
    }
    return FALSE;
}

API_CALLABLE(N(ResetHintFlags)) {
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(BadgeHintData)); i++) {
        evt_set_variable(NULL, AF_HOS06_BadgeHints + i, FALSE);
    }
    for (i = 0; i < ARRAY_COUNT(N(SuperBlockHintData)); i++) {
        evt_set_variable(NULL, AF_HOS06_SuperBlocksHints + i, FALSE);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetBadgeHint)) {
    s32 storyProgress = evt_get_variable(NULL, GB_StoryProgress);
    BadgeHint* hint;
    u32 count = 0;
    s32 selectedIdx;
    u32 i;

    // check for all badges obtainable outside Merlow's shop
    script->varTable[1] = 0;
    for (i = 0, hint = N(BadgeHintData); i < ARRAY_COUNT(N(BadgeHintData)); i++, hint++) {
        if (storyProgress >= hint->requiredProgress
            && !N(PlayerHasBadge)(hint->itemID)
            && !evt_get_variable(NULL, AF_HOS06_BadgeHints + i))
        {
            count++;
        }
    }

    // select the Nth valid hint at random
    if (count > 0) {
        selectedIdx = rand_int(count - 1);
        hint = N(BadgeHintData);
        count = 0;

        for (i = 0; i < ARRAY_COUNT(N(BadgeHintData)); i++, hint++) {
            if (storyProgress >= hint->requiredProgress
                && !N(PlayerHasBadge)(hint->itemID)
                && !evt_get_variable(NULL, AF_HOS06_BadgeHints + i))
            {
                if (count == selectedIdx) {
                    script->varTable[1] = hint->hintMsg;
                    evt_set_variable(NULL, AF_HOS06_BadgeHints + i, TRUE);
                    break;
                }
                count++;
            }
        }
        return ApiStatus_DONE2;
    }

    // if no obtainable badges are found, check for badges obtained via Merlow's shop
    for (i = 0, hint = N(BadgeHintData); i < ARRAY_COUNT(N(BadgeHintData)); i++, hint++) {
        if (hint->requiredProgress == BADGE_REQ_MERLOW_SHOP
            && !N(PlayerHasBadge)(hint->itemID)
            && !evt_get_variable(NULL, AF_HOS06_BadgeHints + i))
        {
            count++;
        }
    }

    // select the Nth valid hint at random
    if (count > 0) {
        selectedIdx = rand_int(count - 1);
        hint = N(BadgeHintData);
        count = 0;
        i = 0;

        for (; i < ARRAY_COUNT(N(BadgeHintData)); i++, hint++) {
            if (hint->requiredProgress == BADGE_REQ_MERLOW_SHOP
                && !N(PlayerHasBadge)(hint->itemID)
                && !evt_get_variable(NULL, AF_HOS06_BadgeHints + i))
            {
                if (count == selectedIdx) {
                    script->varTable[1] = hint->hintMsg;
                    evt_set_variable(NULL, AF_HOS06_BadgeHints + i, 1);
                    break;
                }
                count++;
            }
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetSuperBlockHint)) {
    s32 storyProgress = evt_get_variable(NULL, GB_StoryProgress);
    GameFlagHint* hint;
    u32 count = 0;
    s32 selectedIdx;
    u32 i;

    script->varTable[1] = 0;

    // count unused super blocks
    hint = N(SuperBlockHintData);
    for (i = 0; i < ARRAY_COUNT(N(SuperBlockHintData)); i++, hint++) {
        if (storyProgress >= hint->requiredProgress
            && !evt_get_variable(NULL, hint->doneFlag)
            && !evt_get_variable(NULL, AF_HOS06_SuperBlocksHints + i))
        {
            count++;
        }
    }

    // select the Nth valid hint at random
    if (count > 0) {
        selectedIdx = rand_int(count - 1);
        hint = N(SuperBlockHintData);
        count = 0;

        for (i = 0; i < ARRAY_COUNT(N(SuperBlockHintData)); i++, hint++) {
            if (storyProgress >= hint->requiredProgress
                && !evt_get_variable(NULL, hint->doneFlag)
                && !evt_get_variable(NULL, AF_HOS06_SuperBlocksHints + i))
            {
                if (count == selectedIdx) {
                    script->varTable[1] = hint->hintMsg;
                    evt_set_variable(NULL, AF_HOS06_SuperBlocksHints + i, TRUE);
                    break;
                }
                count++;
            }
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetStarPieceHint)) {
    s32 storyProgress = evt_get_variable(NULL, GB_StoryProgress);
    GameFlagHint* hint;
    u32 count = 0;
    s32 selectedIdx;
    u32 i;

    script->varTable[1] = 0;

    // count unobtained star pieces
    hint = N(StarPieceHintData);
    for (i = 0; i < ARRAY_COUNT(N(StarPieceHintData)); i++, hint++) {
        if (storyProgress >= hint->requiredProgress
            && !evt_get_variable(NULL, hint->doneFlag)
            && !evt_get_variable(NULL, AF_HOS06_StarPieceHints + i))
        {
            count++;
        }
    }

    // select the Nth valid hint at random
    if (count > 0) {
        selectedIdx = rand_int(count - 1);
        hint = N(StarPieceHintData);
        count = 0;

        for (i = 0; i < ARRAY_COUNT(N(StarPieceHintData)); i++, hint++) {
            if (storyProgress >= hint->requiredProgress
                && !evt_get_variable(NULL, hint->doneFlag)
                && !evt_get_variable(NULL, AF_HOS06_StarPieceHints + i))
            {
                if (count == selectedIdx) {
                    script->varTable[1] = hint->hintMsg;
                    evt_set_variable(NULL, AF_HOS06_StarPieceHints + i, TRUE);
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
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o98)),  CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o76)),  CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o84)),  CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o85)),  CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o89)),  CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o104)), CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o78)),  CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        mdl_set_remap_tint_params(255, 255, 255, 0, 0, 0);
        script->functionTemp[0] = 255;
    }

    script->functionTemp[0] -= 4;
    if (script->functionTemp[0] < 64) {
        script->functionTemp[0] = 64;
    }
    mdl_set_remap_tint_params(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
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
    mdl_set_remap_tint_params(
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
    mdl_set_remap_tint_params(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);

    if (script->functionTemp[0] == 255) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o98)),  CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o76)),  CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o84)),  CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o85)),  CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o89)),  CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o104)), CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o78)),  CUSTOM_GFX_NONE, ENV_TINT_NONE);
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
        guRotateF(sp28, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
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

EvtScript N(EVS_PerformHintRitual) = {
    Call(SetMusicTrack, 0, SONG_MERLEE_SPELL, 2, 8)
    Call(SetNpcAnimation, NPC_Merluvlee, ANIM_Merluvlee_Release)
    Call(GetModelCenter, MODEL_o100)
    Add(LVar1, 20)
    Call(PlaySoundAt, SOUND_LRAW_CRYSTAL_BALL_GLOW, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 1, LVar0, LVar1, LVar2, Float(1.0), -1)
    Set(ArrayVar(1), LVarF)
    Call(EnableModel, MODEL_o185, FALSE)
    Call(EnableModel, MODEL_o186, FALSE)
    Wait(30)
    Thread
        Call(N(func_802418E8_A3ADC8))
    EndThread
    Call(GetModelCenter, MODEL_o100)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Add(LVar1, -20)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPosA, CAM_DEFAULT, Float(-91.5), Float(18.40625))
    Call(GetCamDistance, CAM_DEFAULT, LVar0)
    IfGt(LVar0, 0)
        SetF(LVar0, Float(284.6))
    Else
        SetF(LVar0, Float(-284.6))
    EndIf
    Call(SetCamDistance, CAM_DEFAULT, LVar0)
    Call(GetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    SetF(LVar1, Float(-11.0))
    Call(SetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    PlayEffect(EFFECT_MERLIN_HOUSE_STARS, 0, -298, 21, -330)
    Set(ArrayVar(2), LVarF)
    Call(GetModelCenter, MODEL_o100)
    Add(LVar1, 20)
    PlayEffect(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    Set(ArrayVar(3), LVarF)
    PlayEffect(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    Set(ArrayVar(4), LVarF)
    PlayEffect(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    Set(ArrayVar(5), LVarF)
    Thread
        Call(N(func_80241CCC_A3B1AC))
    EndThread
    Wait(50)
    Call(GetModelCenter, MODEL_o100)
    Add(LVar1, 20)
    Call(PlaySoundAt, SOUND_CRYSTAL_BALL_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 5, LVar0, LVar1, LVar2, Float(0.5), 20)
    Wait(30)
    Call(GetModelCenter, MODEL_o100)
    Add(LVar1, 20)
    Call(PlaySoundAt, SOUND_CRYSTAL_BALL_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 5, LVar0, LVar1, LVar2, Float(0.5), 20)
    Wait(30)
    Thread
        Call(N(func_80241A58_A3AF38))
    EndThread
    Call(GetModelCenter, MODEL_o100)
    Add(LVar1, 20)
    Call(PlaySoundAt, SOUND_CRYSTAL_BALL_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, Float(0.5), 20)
    Wait(70)
    Call(DismissEffect, ArrayVar(2))
    Wait(40)
    Call(PlaySoundAt, SOUND_LRAW_CRYSTAL_BALL_GLOW | SOUND_ID_TRIGGER_CHANGE_SOUND, 0, LVar0, LVar1, LVar2)
    Call(N(func_80241F98_A3B478), ArrayVar(1))
    Wait(15)
    Call(EnableModel, MODEL_o185, TRUE)
    Call(EnableModel, MODEL_o186, TRUE)
    Call(DismissEffect, ArrayVar(1))
    Thread
        Call(N(func_80241B74_A3B054))
    EndThread
    Wait(46)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Call(SetNpcAnimation, NPC_Merluvlee, ANIM_Merluvlee_Idle)
    Call(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    Return
    End
};

EvtScript N(EVS_NpcInit_Merluvlee) = {
    Call(N(ResetHintFlags))
    Return
    End
};

EvtScript N(EVS_KootRequestBall_Merluvlee) = {
    IfEq(GB_KootFavor_Current, KOOT_FAVOR_CH4_1)
        IfEq(GF_HOS06_MerluvleeRequestedCrystalBall, FALSE)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Wait(1)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(20)
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0046)
            Wait(10)
            Call(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0047)
            Set(GF_HOS06_MerluvleeRequestedCrystalBall, TRUE)
        EndIf
    EndIf
    Return
    End
};

s32 N(CrystalBallItems)[] = {
    ITEM_CRYSTAL_BALL,
    -1
};

EvtScript N(EVS_KootCheckBall_Merluvlee) = {
    IfEq(GF_HOS06_MerluvleeRequestedCrystalBall, FALSE)
        Return
    EndIf
    IfEq(GF_HOS06_Gift_MerluvleesAutograph, TRUE)
        Return
    EndIf
    Call(FindKeyItem, ITEM_CRYSTAL_BALL, LVar0)
    IfEq(LVar0, -1)
        Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0048)
    Else
        EVT_CHOOSE_KEY_ITEM_FROM(N(CrystalBallItems))
        IfNe(LVar0, -1)
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0049)
            EVT_GIVE_KEY_REWARD(ITEM_KOOT_MERLUVLEE_AUTOGRAPH)
            Set(GF_HOS06_Gift_MerluvleesAutograph, TRUE)
        Else
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0048)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_AskForHint) = {
    Call(DisablePlayerInput, TRUE)
    Call(func_802CF56C, 1)
    Call(PlayerMoveTo, -49, 0, 6)
    Call(PlayerFaceNpc, NPC_Merluvlee, FALSE)
    IfEq(MV_RitualFXArrayPtr, 0)
        MallocArray(20, MV_RitualFXArrayPtr)
    EndIf
    UseArray(MV_RitualFXArrayPtr)
    IfEq(AF_HOS06_SpokeWithMerluvlee, FALSE)
        Set(AF_HOS06_SpokeWithMerluvlee, TRUE)
        IfEq(GF_HOS06_Met_Merluvlee, FALSE)
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0038)
            Set(GF_HOS06_Met_Merluvlee, TRUE)
        Else
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0039)
        EndIf
    Else
        Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003A)
    EndIf
    Label(10)
    Call(ShowChoice, MSG_Choice_0011)
    IfNe(LVar0, 0)
        Call(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003C)
        Call(func_802CF56C, 0)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(ShowCoinCounter, TRUE)
    Call(ShowChoice, MSG_Choice_0000)
    Call(ShowCoinCounter, FALSE)
    IfEq(LVar0, 4)
        Call(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003C)
        Call(func_802CF56C, 0)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(N(HasEnoughCoinsForHint), LVar0, LVar1)
    IfNe(LVar1, 0)
        Call(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003D)
        Call(func_802CF56C, 0)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(N(DeductHintCoins), LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003E)
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Gather, ANIM_Merluvlee_Gather, 0, MSG_HOS_0041)
            ExecWait(N(EVS_PerformHintRitual))
            Call(N(GetStarPieceHint))
            IfEq(LVar1, 0)
                Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Think, ANIM_Merluvlee_Think, 0, MSG_HOS_0042)
                Call(N(RefundHintCoins), 0)
            Else
                Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, LVar1)
            EndIf
            Goto(99)
        CaseEq(1)
            Call(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_003F)
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Gather, ANIM_Merluvlee_Gather, 0, MSG_HOS_0041)
            ExecWait(N(EVS_PerformHintRitual))
            Call(N(GetBadgeHint))
            IfEq(LVar1, 0)
                Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Think, ANIM_Merluvlee_Think, 0, MSG_HOS_0043)
                Call(N(RefundHintCoins), 1)
            Else
                Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, LVar1)
            EndIf
            Goto(99)
        CaseEq(2)
            Call(ContinueSpeech, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0040)
            Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Gather, ANIM_Merluvlee_Gather, 0, MSG_HOS_0041)
            ExecWait(N(EVS_PerformHintRitual))
            Call(N(GetSuperBlockHint))
            IfEq(LVar1, 0)
                Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Think, ANIM_Merluvlee_Think, 0, MSG_HOS_0044)
                Call(N(RefundHintCoins), 2)
            Else
                Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, LVar1)
            EndIf
            Goto(99)
    EndSwitch
    Label(99)
    Call(func_802CF56C, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Merluvlee) = {
    Call(SpeakToPlayer, NPC_Merluvlee, ANIM_Merluvlee_Talk, ANIM_Merluvlee_Idle, 0, MSG_HOS_0045)
    ExecWait(N(EVS_KootCheckBall_Merluvlee))
    ExecWait(N(EVS_KootRequestBall_Merluvlee))
    Return
    End
};
