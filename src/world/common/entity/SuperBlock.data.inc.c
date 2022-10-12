#include "common.h"
#include "message_ids.h"
#include "SuperBlock.inc.h"

// map-specific parameters for this data
// which saved byte to associate this block with
#ifndef SUPER_BLOCK_GAMEFLAG
    #define SUPER_BLOCK_GAMEFLAG GF_Unused_EVT_00
#endif
// which map var to store
#ifndef SUPER_BLOCK_MAPVAR
    #define SUPER_BLOCK_MAPVAR MapVar(0)
#endif

// use this in an EvtScript calling MakeEntity for this super block
// expects SUPER_BLOCK_GAMEFLAG and SUPER_BLOCK_MAPVAR to be valid
#define EVT_MAKE_SUPER_BLOCK(x, y, z, angle) \
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), x, y, z, angle, MAKE_ENTITY_END)\
    EVT_SET(SUPER_BLOCK_MAPVAR, LVar0)\
    EVT_CALL(AssignBlockFlag, SUPER_BLOCK_GAMEFLAG)\
    EVT_CALL(AssignScript, EVT_PTR(N(SuperBlock_OnHit)))

s32 N(SuperBlock_CantUpgradeMessages)[2] = {
    MSG_Menus_00F0, MSG_Menus_00F1
};

s16 N(SuperBlock_PartnerIDs)[8] = {
    PARTNER_GOOMBARIO,
    PARTNER_KOOPER,
    PARTNER_BOMBETTE,
    PARTNER_PARAKARRY,
    PARTNER_BOW,
    PARTNER_WATT,
    PARTNER_SUSHIE,
    PARTNER_LAKILESTER
};

s32 N(SuperBlock_UpgradeDescMessages)[8][2] = {
    { MSG_Menus_00E0, MSG_Menus_00E1 },
    { MSG_Menus_00E2, MSG_Menus_00E3 },
    { MSG_Menus_00E4, MSG_Menus_00E5 },
    { MSG_Menus_00E6, MSG_Menus_00E7 },
    { MSG_Menus_00E8, MSG_Menus_00E9 },
    { MSG_Menus_00EA, MSG_Menus_00EB },
    { MSG_Menus_00EC, MSG_Menus_00ED },
    { MSG_Menus_00EE, MSG_Menus_00EF }
};

f32 N(SuperBlock_UpgradeOrbAngles)[SUPER_BLOCK_NUM_ORBS] = {
    140.0f, 180.0f, 220.0f
};

EvtScript N(SuperBlock_ShowUpgradeEffects) = {
    EVT_WAIT(10)
    EVT_CALL(PlaySound, SOUND_212D)
    EVT_CALL(N(SuperBlock_GatherEnergyFX), SUPER_BLOCK_MAPVAR)
    EVT_WAIT(85)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_212E)
        EVT_CALL(N(SuperBlock_WhiteScreenFlash), 70, 70)
        EVT_WAIT(27)
        EVT_CALL(PlaySound, SOUND_208E)
        EVT_CALL(N(SuperBlock_WhiteScreenFlash), 50, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(N(SuperBlock_HideBlockContent), SUPER_BLOCK_MAPVAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(47)
        EVT_CALL(N(SuperBlock_RadiateFaintEnergyFX))
        EVT_CALL(N(SuperBlock_PartnerSparkles2))
        EVT_WAIT(5)
        EVT_CALL(N(SuperBlock_PartnerSparkles4))
        EVT_WAIT(5)
        EVT_CALL(N(SuperBlock_PartnerSparkles2))
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(N(SuperBlock_AnimateEnergyOrbs), SUPER_BLOCK_MAPVAR)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(SuperBlock_OnHit) = {
    EVT_IF_EQ(SUPER_BLOCK_GAMEFLAG, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(IsStartingConversation, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(SuperBlock_WaitForPlayerToLand))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ModifyGlobalOverrideFlags, 1, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    EVT_CALL(N(SuperBlock_SetOverride40))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_100, TRUE)
    EVT_CALL(N(SuperBlock_StartGlowEffect), SUPER_BLOCK_MAPVAR, LVar9)
    EVT_CALL(FindKeyItem, ITEM_ULTRA_STONE, LVarC)
    EVT_CALL(N(SuperBlock_CountEligiblePartners))
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DC, 160, 40)
        EVT_WAIT(10)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_Tutorial_SuperBlock, 0)
        EVT_SET(GF_Tutorial_SuperBlock, 1)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DA, 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DB, 160, 40)
    EVT_END_IF
    EVT_CALL(N(SuperBlock_ShowSelectPartnerMenu))
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, LVarB)
        EVT_CALL(N(SuperBlock_SwitchToPartner), LVarB)
    EVT_ELSE
        EVT_CALL(func_802CF56C, 2)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DF, 160, 40)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_CALL(CloseMessage)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(SuperBlock_ShowUpgradeEffects))
    EVT_CALL(N(SuperBlock_GetPartnerRank), LVarB, LVarD)
    EVT_SET(SUPER_BLOCK_GAMEFLAG, 1)
    EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
    EVT_CALL(N(SuperBlock_LoadCurrentPartnerName))
    EVT_IF_EQ(LVarD, 1)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DD, 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DE, 160, 40)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    EVT_CALL(N(SuperBlock_ClearOverride40))
    EVT_RETURN
    EVT_END
};
