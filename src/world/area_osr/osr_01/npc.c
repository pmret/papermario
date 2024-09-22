
#include "osr_01.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

EvtScript N(EVS_Scene_Wishing) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 400)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 400)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(3.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30)
    Call(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_HOS_006F)
    Wait(10)
    Call(GotoMap, Ref("mac_04"), mac_04_ENTRY_4)
    Wait(100)
    Return
    End
};

s32 N(LetterList)[] = {
    ITEM_LETTER_CHAIN_MUSS_T,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Toad) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_OSR_0000)
        CaseLt(STORY_CH1_SPOKE_WITH_MERLIN)
            Set(LVar0, MSG_OSR_0001)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_OSR_0002)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_OSR_0003)
            Else
                Set(LVar0, MSG_OSR_0004)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_OSR_0005)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_MailbagStolen, FALSE)
                Set(LVar0, MSG_OSR_0006)
            Else
                IfEq(GF_MAC01_MailbagReturned, FALSE)
                    Set(LVar0, MSG_OSR_0007)
                Else
                    Set(LVar0, MSG_OSR_0008)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_OSR_0009)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_OSR_000A)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_OSR_000B)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_OSR_000C)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_OSR_000D)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_OSR_000E)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_OSR_000F)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    Call(N(LetterDelivery_Init),
        NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle,
        ITEM_LETTER_CHAIN_MUSS_T, ITEM_LETTER_CHAIN_KOOVER_1,
        MSG_OSR_0010, MSG_OSR_0011, MSG_OSR_0012, MSG_OSR_0013,
        Ref(N(LetterList)))
    ExecWait(N(EVS_DoLetterDelivery))
    IfEq(LVarC, 1)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(osr_01_ENTRY_3)
            Call(SetNpcPos, NPC_SELF, 0, 0, 400)
            Call(SetNpcYaw, NPC_SELF, 90)
        CaseDefault
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad)))
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Toad) = {
    .id = NPC_Toad,
    .pos = { 25.0f, 0.0f, 130.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_OSR_LovesToClean,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
