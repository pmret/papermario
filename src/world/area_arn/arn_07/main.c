#include "arn_07.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

s32 N(KeyList)[] = {
    ITEM_MYSTICAL_KEY,
    ITEM_NONE
};

EvtScript N(EVS_SpawnStarCard) = {
    Call(FadeOutMusic, 0, 1000)
    Set(LVar0, 0)
    IfEq(LVar0, 0)
        Call(DisablePlayerInput, TRUE)
        Call(UseSettingsFrom, CAM_DEFAULT, 145, 65, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
        Call(SetPanTarget, CAM_DEFAULT, 145, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(N(StarSpiritEffectFunc2), 2, 50, 100, 31, -6, 145, 65, 0, 30, 0)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EndThread
        Thread
            Wait(12)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(50)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, 145, 0, 0)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
    Else
        Call(N(StarSpiritEffectFunc5), 2, 145, 30, 0, 0)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, TRUE)
    Set(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_2, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_RespawnStarCard) = {
    Set(LVar0, 1)
    IfEq(LVar0, 0)
        Call(DisablePlayerInput, TRUE)
        Call(UseSettingsFrom, CAM_DEFAULT, 145, 65, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
        Call(SetPanTarget, CAM_DEFAULT, 145, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(N(StarSpiritEffectFunc2), 2, 50, 100, 31, -6, 145, 65, 0, 30, 0)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EndThread
        Thread
            Wait(12)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(50)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, 145, 0, 0)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
    Else
        Call(N(StarSpiritEffectFunc5), 2, 145, 30, 0, 0)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, TRUE)
    Set(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_2, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_arn_08_0) = EVT_EXIT_SINGLE_DOOR(arn_07_ENTRY_0, "arn_08", arn_08_ENTRY_0,
    COLLIDER_tt3, MODEL_o39, DOOR_SWING_OUT);
EvtScript N(EVS_ExitWalk_arn_03_0) = EVT_EXIT_WALK(60, arn_07_ENTRY_1, "arn_03", arn_03_ENTRY_0);
EvtScript N(EVS_ExitWalk_mim_12_1) = EVT_EXIT_WALK(60, arn_07_ENTRY_2, "mim_12", mim_12_ENTRY_1);

EvtScript N(EVS_Scene_TubbaReunion) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerPos, -28, 0, -333)
    Call(SetNpcPos, NPC_PARTNER, -28, 0, -333)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamType, CAM_DEFAULT, 0, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, Float(25.0), Float(-4.0))
    Call(SetCamDistance, CAM_DEFAULT, 1100)
    Call(SetCamPosA, CAM_DEFAULT, 500, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, -500)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 5, 0, -147)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(RotateModel, MODEL_o39, 80, 0, -1, 0)
    Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_TubbasHeart, Float(2.5))
    Call(NpcJump0, NPC_TubbasHeart, 0, 20, -120, 8 * DT)
    Wait(1)
    Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_TubbasHeart, 0, 10, -60, 12 * DT)
    Wait(1)
    Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_TubbasHeart, 0, 0, 0, 12 * DT)
    Wait(1)
    Call(SetNpcVar, NPC_TubbasHeart, 0, 0)
    Thread
        Loop(0)
            Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_TubbasHeart, 0, 0, 0, 10 * DT)
            Wait(1)
            Call(GetNpcVar, NPC_TubbasHeart, 0, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcVar, NPC_TubbasHeart, 0, 2)
    EndThread
    Thread
        Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o39, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_tt3, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Call(NpcFaceNpc, NPC_TubbasHeart, NPC_Tubba, 0)
    Call(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0A, ANIM_TubbasHeart_Anim01, 5, MSG_CH3_00C7)
    Call(SetNpcVar, NPC_TubbasHeart, 0, 1)
    Loop(0)
        Call(GetNpcVar, NPC_TubbasHeart, 0, LVar0)
        IfEq(LVar0, 2)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_TubbasHeart, 75, 0, 10, 12)
    Wait(1)
    Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_TubbasHeart, 150, 0, 20, 12)
    Wait(1)
    Thread
        Wait(4 * DT)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(2.0), Float(-9.0))
        Call(SetCamDistance, CAM_DEFAULT, 700)
        Call(SetCamPosA, CAM_DEFAULT, 500, 0)
        Call(SetCamPosB, CAM_DEFAULT, 0, -500)
        Call(SetCamPosC, CAM_DEFAULT, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, 65, 0, -137)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim22)
    EndThread
    Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_TubbasHeart, 298, 56, 31, 18)
    Call(SetNpcPos, NPC_TubbasHeart, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_TubbasHeart, FALSE)
    Thread
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim23)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    EndThread
    Wait(20 * DT)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_tt3, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o39, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(30 * DT)
        Call(UseSettingsFrom, CAM_DEFAULT, 236, 0, -46)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(8.0), Float(-9.0))
        Call(SetCamDistance, CAM_DEFAULT, 450)
        Call(SetPanTarget, CAM_DEFAULT, 250, 0, -46)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetPlayerPos, 0, 20, -195)
    Call(SetNpcPos, NPC_PARTNER, 0, 20, -195)
    Call(EnablePartnerAI)
    Call(PlayerMoveTo, 0, 0, 45 * DT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o39, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_tt3, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Call(PlayerMoveTo, 200, 0, 35 * DT)
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 0, MSG_CH3_00C8)
    Call(SetNpcVar, NPC_Tubba, 0, 1)
    Wait(30 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_arn_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mim_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    IfLt(GB_StoryProgress, STORY_CH3_UNLOCKED_WINDY_MILL)
        BindPadlock(Ref(N(EVS_UnlockDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoor_arn_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(arn_07_ENTRY_0)
            IfEq(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
                ExecWait(N(EVS_Scene_TubbaReunion))
                Exec(N(EVS_BindExitTriggers))
            Else
                Set(LVar2, MODEL_o39)
                Set(LVar3, DOOR_SWING_OUT)
                ExecWait(EnterSingleDoor)
                Exec(N(EVS_BindExitTriggers))
            EndIf
        CaseEq(arn_07_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(arn_07_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(arn_07_ENTRY_3)
            Exec(N(EVS_BindExitTriggers))
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GUSTY_GULCH)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Set(GF_MAP_GustyGulch, TRUE)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, FALSE, Ref(N(BossNPCs)))
        CaseEq(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, FALSE, Ref(N(SpiritNPCs)))
        CaseDefault
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    IfEq(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        Exec(N(EVS_RespawnStarCard))
    EndIf
    Exec(N(EVS_EnterMap))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, arn_07_ENTRY_3)
        Wait(65)
    EndIf
    Exec(N(EVS_SetupWindmill))
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.3))
    Return
    End
};
