#include "jan_06.h"
#include "sprite.h"
#include "sprite/player.h"

s32 N(JadeRavenList)[] = {
    ITEM_JADE_RAVEN,
    ITEM_NONE
};

EvtScript N(EVS_MoveStatue) = {
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 25, EVT_FLOAT(0.8))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 25, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 1, 5, 50, EASING_CUBIC_IN)
    EVT_SET(LVar2, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_MUL(LVar2, -1)
        EVT_SET(LVar3, LVar2)
        EVT_MUL(LVar3, LVar0)
        EVT_CALL(TranslateGroup, MODEL_g11, LVar3, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g11, 0, 0, 1, 0)
        EVT_CALL(SetItemPos, MV_JadeRavenItemIdx, LVar3, 15, -400)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 25, EVT_FLOAT(0.6))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 25, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 25, EVT_FLOAT(0.4))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 5, 0, 75, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_MUL(LVar2, -1)
        EVT_SET(LVar3, LVar2)
        EVT_MUL(LVar3, LVar0)
        EVT_CALL(TranslateGroup, MODEL_g11, LVar3, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g11, 0, 0, 1, 0)
        EVT_CALL(SetItemPos, MV_JadeRavenItemIdx, LVar3, 15, -400)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_LOOP(0)
        EVT_CALL(GetModelCenter, MODEL_o162)
        EVT_CALL(N(AdjustEnvSoundPosition), LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MoveStatue) = {
    EVT_CALL(PlaySound, SOUND_LOOP_MOVE_LARGE_STATUE)
    EVT_EXEC_WAIT(N(EVS_MoveStatue))
    EVT_CALL(GetModelCenter, MODEL_o162)
    EVT_CALL(PlaySoundAt, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_EXEC_GET_TID(N(PlayMovingStatueSound), LVar9)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 180, EVT_FLOAT(0.4))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -100, 180, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g11, LVar0, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g11, 0, 0, 1, 0)
        EVT_CALL(SetItemPos, MV_JadeRavenItemIdx, LVar0, 15, -400)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(1.0))
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(StopSound, SOUND_LOOP_MOVE_STATUE)
    EVT_CALL(StopSound, SOUND_LOOP_MOVE_LARGE_STATUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o247, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o180, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(10)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(ItemPrompt_Statue) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_LE(LVar0, 0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_RaphaelStatue, 160, 40)
        EVT_END_IF
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(MakeItemEntity, ITEM_JADE_RAVEN, 0, 15, -400, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_JadeRavenItemIdx, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_PlaceItem | SPRITE_ID_BACK_FACING)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(EVS_Scene_MoveStatue))
    EVT_SET(GB_StoryProgress, STORY_CH5_MOVED_RAVEN_STATUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStatue) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_MOVED_RAVEN_STATUE)
        EVT_BIND_PADLOCK(EVT_PTR(N(ItemPrompt_Statue)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, EVT_PTR(N(JadeRavenList)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
