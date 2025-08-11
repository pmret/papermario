#include "flo_12.h"
#include "sprite/player.h"

#include "world/common/npc/Rosie.inc.c"
#include "world/common/npc/Dummy.inc.c"

#include "common/foliage.inc.c"

#include "world/common/complete/GiveReward.inc.c"
#include "world/common/complete/KeyItemChoice.inc.c"

s32 N(KeyList)[] = {
    ITEM_CRYSTAL_BERRY,
    ITEM_NONE
};

EvtScript N(EVS_Scene_SunReturns) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(GetNpcPos, NPC_Rosie, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.5))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Call(SpeakToPlayer, NPC_Rosie, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_00C7)
    Wait(10)
    Call(GotoMap, Ref("flo_03"), flo_03_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_PlayerApproachRosie) = {
    Wait(10)
    Call(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(PlayerMoveTo, -5, 20, 20)
    Call(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
    Call(PlayerFaceNpc, NPC_Rosie, true)
    Return
    End
};

EvtScript N(EVS_PlayerApproachRosieAndItem) = {
    Wait(10)
    Call(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(PlayerMoveTo, -5, 20, 20)
    Call(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
    Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
    Call(PlayerFaceNpc, NPC_Rosie, true)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Rosie) = {
    ExecWait(N(EVS_PushFlowerSong))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_CRYSTAL_BERRY)
            Switch(GF_FLO12_Met_Rosie)
                CaseEq(0)
                    Exec(N(EVS_PlayerApproachRosie))
                    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                    Add(LVar0, 30)
                    Call(SetCamProperties, CAM_DEFAULT, Float(4.0), LVar0, LVar1, LVar2, 325, Float(19.0), Float(-9.5))
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_Talk, ANIM_Rosie_Idle, 5, MSG_CH6_008C)
                    Call(ShowChoice, MSG_Choice_0011)
                    Wait(10)
                    Switch(LVar0)
                        CaseEq(0)
                            Call(ContinueSpeech, NPC_SELF, ANIM_Rosie_Talk, ANIM_Rosie_Idle, 5, MSG_CH6_008D)
                        CaseEq(1)
                            Call(ContinueSpeech, NPC_SELF, ANIM_Rosie_Talk, ANIM_Rosie_Idle, 5, MSG_CH6_008E)
                    EndSwitch
                    Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
                    Call(SetNpcAnimation, NPC_SELF, ANIM_Rosie_TakeOut)
                    Wait(10)
                    Call(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
                    Call(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, 0x00000564)
                    Wait(10)
                    Switch(GF_FLO10_LilyRequestedWaterStone)
                        CaseEq(0)
                            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_008F)
                        CaseEq(1)
                            Call(SetPlayerAnimation, ANIM_MarioW1_CarryRun)
                            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_008F)
                            Call(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
                            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0091)
                            Call(SetPlayerAnimation, ANIM_Mario1_Pray)
                            Wait(40)
                            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0092)
                            Set(GF_FLO12_RosieRequestedSomethingBeautiful, true)
                    EndSwitch
                    Set(GF_FLO12_Met_Rosie, true)
                CaseEq(1)
                    Switch(GF_FLO12_RosieRequestedSomethingBeautiful)
                        CaseEq(0)
                            IfEq(GF_FLO10_LilyRequestedWaterStone, true)
                                Exec(N(EVS_PlayerApproachRosieAndItem))
                                Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_0090)
                                Call(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
                                Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0091)
                                Call(SetPlayerAnimation, ANIM_Mario1_Pray)
                                Wait(40)
                                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                                Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0092)
                                Set(GF_FLO12_RosieRequestedSomethingBeautiful, true)
                            Else
                                Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_0090)
                            EndIf
                        CaseEq(1)
                            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0093)
                    EndSwitch
            EndSwitch
        CaseLt(STORY_CH6_GOT_WATER_STONE)
            Call(FindKeyItem, ITEM_CRYSTAL_BERRY, LVar0)
            IfNe(LVar0, -1)
                Exec(N(EVS_PlayerApproachRosieAndItem))
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, 30)
                Call(SetCamProperties, CAM_DEFAULT, Float(4.0), LVar0, LVar1, LVar2, 325, Float(19.0), Float(-9.5))
            EndIf
            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0094)
            EVT_CHOOSE_KEY_ITEM_FROM(N(KeyList))
            Switch(LVar0)
                CaseLe(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0093)
                CaseDefault
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0095)
                    Call(RemoveItemEntity, LVar7)
                    Call(MakeItemEntity, ITEM_CRYSTAL_BERRY, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
                    EVT_GIVE_KEY_REWARD(ITEM_WATER_STONE)
                    Wait(10)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0096)
                    Set(AF_FLO_GivenCrystalBerry, true)
                    Set(GB_StoryProgress, STORY_CH6_GOT_WATER_STONE)
            EndSwitch
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Switch(AF_FLO_GivenCrystalBerry)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0097)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0096)
            EndSwitch
        CaseLt(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0098)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0099)
    EndSwitch
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    ExecWait(N(EVS_PopMusic))
    Return
    End
};

EvtScript N(EVS_NpcInit_Rosie) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rosie)))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 35)
    Call(SetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
    Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_INVISIBLE, true)
    Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_HAS_SHADOW, true)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_CRYSTAL_BERRY)
            IfEq(GF_FLO12_Met_Rosie, true)
                Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
                Call(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
                Set(LVarA, LVar0)
            EndIf
        CaseLt(STORY_CH6_GOT_WATER_STONE)
            Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
            Call(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
            Set(LVarA, LVar0)
        CaseDefault
            Call(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
            Call(MakeItemEntity, ITEM_CRYSTAL_BERRY, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
            Set(LVarA, LVar0)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Rosie)[] = {
    {
        .id = NPC_Rosie,
        .pos = { -70.0f, 0.0f, 20.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Rosie),
        .settings = &N(NpcSettings_Rosie),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = ROSIE_ANIMS,
        .tattle = MSG_NpcTattle_Rosie,
    },
    {
        .id = NPC_Dummy,
        .pos = { -70.0f, 0.0f, 20.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = ROSIE_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Rosie)),
    {}
};
