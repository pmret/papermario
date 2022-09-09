#include "common.h"
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

// use this in a script macro calling MakeEntity for this super block
#define EVT_SETUP_SUPER_BLOCK(mapVar,gameFlag) \
    EVT_SET(mapVar, LocalVar(0))\
    EVT_CALL(AssignBlockFlag, gameFlag)\
    EVT_CALL(AssignScript, EVT_PTR(N(SuperBlock_OnHit)))

s32 N(SuperBlock_CantUpgradeMessages)[2] = {
    MESSAGE_ID(0x1D,0xF0), MESSAGE_ID(0x1D,0xF1)
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
    { MESSAGE_ID(0x1D,0xE0), MESSAGE_ID(0x1D,0xE1) },
    { MESSAGE_ID(0x1D,0xE2), MESSAGE_ID(0x1D,0xE3) },
    { MESSAGE_ID(0x1D,0xE4), MESSAGE_ID(0x1D,0xE5) },
    { MESSAGE_ID(0x1D,0xE6), MESSAGE_ID(0x1D,0xE7) },
    { MESSAGE_ID(0x1D,0xE8), MESSAGE_ID(0x1D,0xE9) },
    { MESSAGE_ID(0x1D,0xEA), MESSAGE_ID(0x1D,0xEB) },
    { MESSAGE_ID(0x1D,0xEC), MESSAGE_ID(0x1D,0xED) },
    { MESSAGE_ID(0x1D,0xEE), MESSAGE_ID(0x1D,0xEF) }
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
    EVT_CALL(IsStartingConversation, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(SuperBlock_WaitForPlayerToLand))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ModifyGlobalOverrideFlags, 1, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    EVT_CALL(N(SuperBlock_SetOverride40))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_100, TRUE)
    EVT_CALL(N(SuperBlock_StartGlowEffect), SUPER_BLOCK_MAPVAR, LocalVar(9))
    EVT_CALL(FindKeyItem, ITEM_ULTRA_STONE, LVarC)
    EVT_CALL(N(SuperBlock_CountEligiblePartners))
    EVT_IF_EQ(LocalVar(0), -1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D,0xDC), 160, 40)
        EVT_WAIT(10)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LocalVar(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_Tutorial_SuperBlock, 0)
        EVT_SET(GF_Tutorial_SuperBlock, 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D,0xDA), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D,0xDB), 160, 40)
    EVT_END_IF
    EVT_CALL(N(SuperBlock_ShowSelectPartnerMenu))
    EVT_IF_EQ(LocalVar(0), -1)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LocalVar(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, LocalVar(0))
    EVT_SET(LVarB, LocalVar(1))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), LVarB)
        EVT_CALL(N(SuperBlock_SwitchToPartner), LVarB)
    EVT_ELSE
        EVT_CALL(func_802CF56C, 2)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D,0x0DF), 160, 40)
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E,0x0D))
    EVT_CALL(CloseMessage)
    EVT_IF_NE(LocalVar(0), 0)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LocalVar(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(SuperBlock_ShowUpgradeEffects))
    EVT_CALL(N(SuperBlock_GetPartnerRank), LVarB, LVarD)
    EVT_SET(SUPER_BLOCK_GAMEFLAG, 1)
    EVT_CALL(N(SuperBlock_EndGlowEffect), LocalVar(9))
    EVT_CALL(N(SuperBlock_LoadCurrentPartnerName))
    EVT_IF_EQ(LVarD, 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D,0xDD), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D,0xDE), 160, 40)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    EVT_CALL(N(SuperBlock_ClearOverride40))
    EVT_RETURN
    EVT_END
};
