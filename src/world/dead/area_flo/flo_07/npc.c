#include "flo_07.h"

#include "world/common/npc/Posie.inc.c"

#include "common/foliage.inc.c"

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_Scene_SunReturns) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(GetNpcPos, NPC_Posie, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(11.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_00C5)
    Wait(10)
    Call(GotoMap, Ref("flo_10"), flo_10_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ShakeGround) = {
    Label(0)
        Call(ShakeCam, CAM_DEFAULT, 0, 1, Float(1.0))
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_MakeCrystalBerry) = {
    IfEq(AF_FLO_MadeCrystalBerry, true)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0068)
    Thread
        Call(SetCamDistance, CAM_DEFAULT, 300)
        Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-7.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Call(PlaySound, SOUND_LOOP_RUMBLE)
    ExecGetTID(N(EVS_ShakeGround), MV_GroundShakingScript)
    Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Strain, ANIM_Posie_Strain, 0, MSG_CH6_0069)
    KillThread(MV_GroundShakingScript)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.0), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(8.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Sub(LVar0, LVar2)
    IfLt(LVar0, -250)
        Call(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 100, -25, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
    Else
        Call(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 100, 54, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
        Set(GF_FLO07_CrystalBerryFellOnLeftSide, true)
    EndIf
    Call(PlaySound, SOUND_LRAW_RUMBLE | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Call(StopTrackingSoundPos, SOUND_LRAW_RUMBLE)
    Set(AF_FLO_MadeCrystalBerry, true)
    Wait(20)
    Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006A)
    Set(GB_StoryProgress, STORY_CH6_GOT_CRYSTAL_BERRY)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Posie) = {
    ExecWait(N(EVS_PushFlowerSong))
    Call(NpcFacePlayer, NPC_SELF, 1)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            IfEq(AF_FLO_PoiseHintDialogue, false)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0070)
                Set(AF_FLO_PoiseHintDialogue, true)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0071)
            EndIf
        CaseLt(STORY_CH6_GOT_FERTILE_SOIL)
            Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, Float(350.0), Float(18.0), Float(-7.5))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0065)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Posie_GiveItem)
            Wait(20)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Posie_Still)
            EVT_GIVE_KEY_REWARD(ITEM_FERTILE_SOIL)
            Set(GB_StoryProgress, STORY_CH6_GOT_FERTILE_SOIL)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0066)
            IfEq(GF_FLO12_RosieRequestedSomethingBeautiful, true)
                ExecWait(N(EVS_MakeCrystalBerry))
            EndIf
            Call(ResetCam, CAM_DEFAULT, Float(4.0))
        CaseLt(STORY_CH6_GOT_CRYSTAL_BERRY)
            IfEq(GF_FLO12_RosieRequestedSomethingBeautiful, true)
                IfEq(AF_FLO_MadeCrystalBerry, false)
                    Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, Float(350.0), Float(18.0), Float(-7.5))
                    ExecWait(N(EVS_MakeCrystalBerry))
                    Call(ResetCam, CAM_DEFAULT, Float(4.0))
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
                EndIf
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
            EndIf
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            IfEq(GF_FLO07_Item_CrystalBerry, false)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
            Else
                IfLt(GB_StoryProgress, STORY_CH6_GOT_WATER_STONE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0073)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0074)
                EndIf
                Call(ContinueSpeech, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0075)
            EndIf
        CaseLt(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0076)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0077)
    EndSwitch
    ExecWait(N(EVS_PopSong))
    Return
    End
};

EvtScript N(EVS_NpcInit_Posie) = {
    IfEq(GB_StoryProgress, STORY_CH6_GOT_CRYSTAL_BERRY)
        IfEq(GF_FLO07_Item_CrystalBerry, false)
            IfEq(GF_FLO07_CrystalBerryFellOnLeftSide, false)
                Call(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 0, -25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
            Else
                Call(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 0, 54, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
            EndIf
        EndIf
    EndIf
    Set(AF_FLO_PoiseHintDialogue, false)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Posie)))
    Return
    End
};

EvtScript N(EVS_TryKickingPlayerOut) = {
    IfNe(AB_FLO_PoiseKickedOutCount, 0)
        Call(DisablePlayerInput, true)
        Wait(10)
        IfLt(AB_FLO_PoiseKickedOutCount, 5)
            Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006E)
            Call(GetPlayerPos, LVar1, LVar2, LVar3)
            Call(PlayerMoveTo, 410, LVar3, 10)
            Add(AB_FLO_PoiseKickedOutCount, 1)
        Else
            Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006F)
            Set(AB_FLO_PoiseKickedOutCount, 0)
        EndIf
        Call(DisablePlayerInput, false)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnHit_CrystalTree) = {
    Call(DisablePlayerInput, true)
    IfLt(GB_StoryProgress, STORY_CH6_GOT_CRYSTAL_BERRY)
        Call(NpcFacePlayer, NPC_Posie, 1)
        Wait(10)
        Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Confused, ANIM_Posie_Idle, 0, MSG_CH6_0067)
        IfEq(GB_StoryProgress, STORY_CH6_GOT_FERTILE_SOIL)
            IfEq(GF_FLO12_RosieRequestedSomethingBeautiful, true)
                Call(UseSettingsFrom, CAM_DEFAULT, -250, 0, 0)
                Call(SetPanTarget, CAM_DEFAULT, -250, 0, 0)
                Call(SetCamDistance, CAM_DEFAULT, 350)
                Call(PanToTarget, CAM_DEFAULT, 0, true)
                ExecWait(N(EVS_MakeCrystalBerry))
                Call(ResetCam, CAM_DEFAULT, Float(4.0))
            EndIf
        EndIf
    Else
        IfEq(GF_FLO07_Item_CrystalBerry, false)
            Call(NpcFacePlayer, NPC_Posie, 1)
            Wait(10)
            Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_Confused, ANIM_Posie_Idle, 0, MSG_CH6_0067)
        Else
            Add(AB_FLO_CrystalTreeHitCount, 1)
            Switch(AB_FLO_CrystalTreeHitCount)
                CaseLt(2)
                    Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006B)
                CaseLt(5)
                    Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006C)
                CaseGe(5)
                    Call(SpeakToPlayer, NPC_Posie, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006D)
                    Set(AB_FLO_PoiseKickedOutCount, 1)
                    Call(GotoMap, Ref("flo_25"), flo_25_ENTRY_1)
                    Wait(100)
            EndSwitch
        EndIf
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Call(DisablePlayerInput, false)
    Return
    End
};

FoliageModelList N(CrystalTree_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o6, MODEL_o7, MODEL_o8);
FoliageModelList N(CrystalTree_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o5);

ShakeTreeConfig N(ShakeTree_CrystalTree) = {
    .leaves = &N(CrystalTree_LeafModels),
    .trunk = &N(CrystalTree_TrunkModels),
    .callback = &N(EVS_OnHit_CrystalTree),
};

BombTrigger N(BombPos_CrystalTree) = {
    .pos = { -309.0f, 0.0f, 31.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    Set(LVar0, Ref(N(ShakeTree_CrystalTree)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o5, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_CrystalTree)), 1, 0)
    Return
    End
};

NpcData N(NpcData_Posie) = {
    .id = NPC_Posie,
    .pos = { -260.0f, 0.0f, 0.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Posie),
    .settings = &N(NpcSettings_Posie),
    .flags = BASE_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = POSIE_ANIMS,
    .tattle = MSG_NpcTattle_Posie,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Posie)),
    {}
};
