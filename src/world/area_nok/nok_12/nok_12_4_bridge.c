#include "nok_12.h"

#include "world/common/todo/SetCamera0Flag1000.inc.c"
#include "world/common/todo/UnsetCamera0Flag1000.inc.c"

EvtScript N(EVS_Scene_BuildBridge) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(20)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(N(SetCamera0Flag1000))
    EVT_CALL(InterpCamTargetPos, CAM_DEFAULT, 1, -272, 0, -56, 20)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAt, SOUND_71, 0, -275, 0, -39)
    EVT_CALL(MakeLerp, -320, 0, 15, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, MODEL_hashi, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LOOP(6)
        EVT_CALL(TranslateGroup, MODEL_hashi, 0, 3, 0)
        EVT_WAIT(1)
        EVT_CALL(TranslateGroup, MODEL_hashi, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAt, SOUND_72, 0, -275, 0, -39)
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(20)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o97, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o95, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o94, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o96, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o93, LVar0, -1, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o91, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o101, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o92, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o99, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o100, 0, -80, 0)
    EVT_CALL(RotateModel, MODEL_o91, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o101, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o92, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o99, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o100, LVar0, -1, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o91, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o101, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o92, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o99, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o100, 0, 80, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAt, SOUND_73, 0, -275, 0, -39)
    EVT_CALL(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    EVT_LABEL(30)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_o91, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o101, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o92, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o99, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o100, 0, -80, 0)
    EVT_CALL(RotateModel, MODEL_o91, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o101, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o92, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o99, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o100, 90, -1, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o91, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o101, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o92, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o99, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o100, 0, 80, 0)
    EVT_CALL(RotateModel, MODEL_o91, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o101, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o92, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o99, LVar0, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o100, LVar0, -1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o204, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(InterpCamTargetPos, CAM_DEFAULT, 1, LVar0, LVar1, LVar2, 10)
    EVT_CALL(N(UnsetCamera0Flag1000))
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH1_MADE_FIRST_BRIDGE)
    EVT_CALL(SetGroupEnabled, MODEL_off, 0)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBridge) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_MADE_FIRST_BRIDGE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_BuildBridge)), TRIGGER_AREA_FLAG_SET, AF_NOK_01, 1, 0)
        EVT_CALL(TranslateGroup, MODEL_hashi, 0, -320, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o204, COLLIDER_FLAGS_UPPER_MASK)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetGroupEnabled, MODEL_off, 0)
    EVT_CALL(RotateModel, MODEL_o97, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o95, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o94, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o96, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o93, 90, -1, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o91, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o101, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o92, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o99, 0, -80, 0)
    EVT_CALL(TranslateModel, MODEL_o100, 0, -80, 0)
    EVT_CALL(RotateModel, MODEL_o91, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o101, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o92, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o99, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o100, 90, -1, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o91, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o101, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o92, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o99, 0, 80, 0)
    EVT_CALL(TranslateModel, MODEL_o100, 0, 80, 0)
    EVT_CALL(RotateModel, MODEL_o91, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o101, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o92, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o99, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o100, 90, -1, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
