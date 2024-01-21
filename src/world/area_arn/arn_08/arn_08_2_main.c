#include "arn_08.h"

EvtScript N(EVS_ExitDoor_arn_07_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(ClearDefeatedEnemies)
    Set(LVar0, arn_08_ENTRY_0)
    Set(LVar1, COLLIDER_tts)
    Set(LVar2, MODEL_doa)
    Set(LVar4, MODEL_o37)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSplitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("arn_07"), arn_07_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoor_arn_07_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(arn_08_ENTRY_0)
            Set(LVar4, MODEL_o37)
            Set(LVar2, MODEL_doa)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSplitSingleDoor)
            Set(AF_ARN_01, FALSE)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(arn_08_ENTRY_1)
            Call(DisablePlayerInput, TRUE)
            Call(DisablePlayerPhysics, TRUE)
            IfEq(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WELL)
                Call(SetPlayerPos, 1000, 1000, 0)
                Call(SetNpcPos, NPC_PARTNER, 1000, 1000, 0)
                Call(RotateModel, MODEL_doa, 80, 0, -1, 0)
                Call(RotateModel, MODEL_o37, 80, 0, -1, 0)
                Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim06)
                Call(SetNpcJumpscale, NPC_TubbasHeart, Float(2.5))
                Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_TubbasHeart, -50, 0, 50, 10 * DT)
                Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim07)
                Wait(1)
                Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim06)
                Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_TubbasHeart, -110, 0, 110, 10 * DT)
                Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim07)
                Wait(1)
                Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim06)
                Call(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
                Call(NpcJump0, NPC_TubbasHeart, -180, 0, 180, 10 * DT)
                Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim07)
                Wait(1)
                Call(MakeLerp, 80, 0, 10, EASING_LINEAR)
                Loop(0)
                    Call(UpdateLerp)
                    Call(RotateModel, MODEL_doa, LVar0, 0, -1, 0)
                    Call(RotateModel, MODEL_o37, LVar0, 0, -1, 0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
                Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
                Wait(20 * DT)
                Call(SetPlayerPos, 0, 0, 0)
                Call(SetNpcPos, NPC_PARTNER, 0, 0, 0)
                Set(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
            EndIf
            Call(DisablePlayerPhysics, FALSE)
            Call(SetPlayerJumpscale, Float(2.0))
            Call(PlayerJump, -10, 0, 75, 18)
            Call(DisablePlayerInput, FALSE)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_WINDY_MILL)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Set(GF_MAP_WindyMill, TRUE)
    IfGe(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        Set(GF_ARN10_Defeated_Goomba, FALSE)
        Set(GF_ARN12_Defeated_Goomba, FALSE)
        Set(GF_ARN13_Defeated_Goomba, FALSE)
    EndIf
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_AnimateGears))
    Call(GetDemoState, LVar0)
    IfNe(LVar0, DEMO_STATE_NONE)
        ExecWait(N(EVS_PlayDemoScene))
        Return
    EndIf
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupHole))
    Exec(N(EVS_SetupMusic))
    Return
    End
};
