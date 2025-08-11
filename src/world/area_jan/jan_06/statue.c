#include "jan_06.h"
#include "sprite.h"
#include "sprite/player.h"

s32 N(JadeRavenList)[] = {
    ITEM_JADE_RAVEN,
    ITEM_NONE
};

EvtScript N(EVS_MoveStatue) = {
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 25, Float(0.8))
        Call(ShakeCam, CAM_DEFAULT, 0, 25, Float(0.7))
    EndThread
    Call(MakeLerp, 1, 5, 50, EASING_CUBIC_IN)
    Set(LVar2, 1)
    Loop(0)
        Call(UpdateLerp)
        Mul(LVar2, -1)
        Set(LVar3, LVar2)
        Mul(LVar3, LVar0)
        Call(TranslateGroup, MODEL_g11, LVar3, 0, 0)
        Call(RotateGroup, MODEL_g11, 0, 0, 1, 0)
        Call(SetItemPos, MV_JadeRavenItemIdx, LVar3, 15, -400)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 25, Float(0.6))
        Call(ShakeCam, CAM_DEFAULT, 0, 25, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 25, Float(0.4))
    EndThread
    Call(MakeLerp, 5, 0, 75, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Mul(LVar2, -1)
        Set(LVar3, LVar2)
        Mul(LVar3, LVar0)
        Call(TranslateGroup, MODEL_g11, LVar3, 0, 0)
        Call(RotateGroup, MODEL_g11, 0, 0, 1, 0)
        Call(SetItemPos, MV_JadeRavenItemIdx, LVar3, 15, -400)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

API_CALLABLE(N(AdjustEnvSoundPosition)) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_LRAW_MOVE_STATUE, SOUND_SPACE_DEFAULT, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);

    return ApiStatus_DONE2;
}

EvtScript N(PlayMovingStatueSound) = {
    Loop(0)
        Call(GetModelCenter, MODEL_o162)
        Call(N(AdjustEnvSoundPosition), LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_MoveStatue) = {
    Call(PlaySound, SOUND_LOOP_MOVE_LARGE_STATUE)
    ExecWait(N(EVS_MoveStatue))
    Call(GetModelCenter, MODEL_o162)
    Call(PlaySoundAt, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    ExecGetTID(N(PlayMovingStatueSound), LVar9)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 180, Float(0.4))
    EndThread
    Call(MakeLerp, 0, -100, 180, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g11, LVar0, 0, 0)
        Call(RotateGroup, MODEL_g11, 0, 0, 1, 0)
        Call(SetItemPos, MV_JadeRavenItemIdx, LVar0, 15, -400)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(1.0))
    KillThread(LVar9)
    Call(StopSound, SOUND_LOOP_MOVE_STATUE)
    Call(StopSound, SOUND_LOOP_MOVE_LARGE_STATUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o247, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o180, COLLIDER_FLAGS_UPPER_MASK)
    Wait(10)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Return
    End
};

EvtScript N(ItemPrompt_Statue) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(ShowKeyChoicePopup)
    IfLe(LVar0, 0)
        IfEq(LVar0, 0)
            Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_RaphaelStatue, 160, 40)
        EndIf
        Call(CloseChoicePopup)
        Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(RemoveKeyItemAt, LVar1)
    Call(MakeItemEntity, ITEM_JADE_RAVEN, 0, 15, -400, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_JadeRavenItemIdx, LVar0)
    Call(CloseChoicePopup)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Call(SetPlayerAnimation, ANIM_MarioW1_PlaceItem | SPRITE_ID_BACK_FACING)
    Wait(20)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Wait(10)
    ExecWait(N(EVS_Scene_MoveStatue))
    Set(GB_StoryProgress, STORY_CH5_MOVED_RAVEN_STATUE)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_SetupStatue) = {
    IfLt(GB_StoryProgress, STORY_CH5_MOVED_RAVEN_STATUE)
        BindPadlock(Ref(N(ItemPrompt_Statue)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, Ref(N(JadeRavenList)), 0, 1)
    EndIf
    Return
    End
};
