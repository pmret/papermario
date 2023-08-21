#include "obk_08.h"
#include "entity.h"

API_CALLABLE(N(ShutterCrashRumble)) {
    Bytecode* args = script->ptrReadPos;

    start_rumble(100, evt_get_variable(script, *args++) & 0xFFFF);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(EnableItemTransparency)) {
    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAG_TRANSPARENT);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateShutterLeft) = {
    EVT_CALL(PlaySoundWithVolume, SOUND_SEQ_WINDOW_OPEN, 0)
    EVT_CALL(PlaySoundAtModel, LVar2, SOUND_SEQ_WINDOW_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(ShutterCrashRumble), 5)
    EVT_SET(LVar3, 90)
    EVT_CALL(MakeLerp, 0, LVar3, 15, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(N(ShutterCrashRumble), 5)
    EVT_SET(LVar4, 0)
    EVT_LABEL(15)
        EVT_CALL(MakeLerp, LVar3, 20, 20, EASING_COS_FAST_OVERSHOOT)
        EVT_LABEL(20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, LVar2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(20)
            EVT_END_IF
        EVT_CALL(N(ShutterCrashRumble), 5)
        EVT_CALL(MakeLerp, 20, LVar3, 5, EASING_COS_FAST_OVERSHOOT)
        EVT_LABEL(30)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, LVar2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(30)
            EVT_END_IF
        EVT_CALL(N(ShutterCrashRumble), 5)
        EVT_IF_NE(MV_WindowsIdle, 0)
            EVT_GOTO(35)
        EVT_END_IF
        EVT_ADD(LVar4, 1)
        EVT_IF_NE(LVar4, 2)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_LABEL(35)
    EVT_CALL(MakeLerp, LVar3, 0, 15, EASING_QUADRATIC_IN)
    EVT_LABEL(40)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(40)
        EVT_END_IF
    EVT_CALL(PlaySoundWithVolume, SOUND_SEQ_WINDOW_CLOSE, 0)
    EVT_CALL(PlaySoundAtModel, LVar2, SOUND_SEQ_WINDOW_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimateShutterRight) = {
    EVT_CALL(N(ShutterCrashRumble), 5)
    EVT_SET(LVar3, 90)
    EVT_CALL(MakeLerp, 0, LVar3, 15, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar2, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(N(ShutterCrashRumble), 5)
    EVT_SET(LVar4, 0)
    EVT_LABEL(15)
        EVT_CALL(MakeLerp, LVar3, 20, 17, EASING_COS_FAST_OVERSHOOT)
        EVT_LABEL(20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, LVar2, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(20)
            EVT_END_IF
        EVT_CALL(N(ShutterCrashRumble), 5)
        EVT_CALL(MakeLerp, 20, LVar3, 8, EASING_COS_FAST_OVERSHOOT)
        EVT_LABEL(30)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, LVar2, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(30)
            EVT_END_IF
        EVT_CALL(N(ShutterCrashRumble), 5)
        EVT_IF_NE(MV_WindowsIdle, 0)
            EVT_GOTO(35)
        EVT_END_IF
        EVT_ADD(LVar4, 1)
        EVT_IF_NE(LVar4, 2)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_LABEL(35)
    EVT_CALL(MakeLerp, LVar3, 0, 15, EASING_QUADRATIC_IN)
    EVT_LABEL(40)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, LVar2, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(40)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageWindows) = {
    EVT_LABEL(10)
        EVT_CALL(AwaitPlayerApproach, 0, -390, 150)
        EVT_SET(MV_WindowsIdle, FALSE)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar2, MODEL_m21)
        EVT_EXEC(N(EVS_AnimateShutterLeft))
        EVT_WAIT(3)
        EVT_SET(LVar2, MODEL_m22)
        EVT_EXEC(N(EVS_AnimateShutterRight))
        EVT_WAIT(2)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar2, MODEL_m41)
        EVT_EXEC(N(EVS_AnimateShutterLeft))
        EVT_WAIT(3)
        EVT_SET(LVar2, MODEL_m42)
        EVT_EXEC(N(EVS_AnimateShutterRight))
        EVT_WAIT(2)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar2, MODEL_m31)
        EVT_EXEC(N(EVS_AnimateShutterLeft))
        EVT_WAIT(2)
        EVT_SET(LVar2, MODEL_m32)
        EVT_EXEC(N(EVS_AnimateShutterRight))
        EVT_WAIT(2)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar2, MODEL_m11)
        EVT_EXEC(N(EVS_AnimateShutterLeft))
        EVT_WAIT(3)
        EVT_SET(LVar2, MODEL_m12)
        EVT_EXEC(N(EVS_AnimateShutterRight))
        EVT_WAIT(2)
        EVT_CALL(AwaitPlayerLeave, 0, -390, 170)
        EVT_SET(MV_WindowsIdle, TRUE)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        EVT_CALL(MakeItemEntity, ITEM_BOO_RECORD, 0, 0, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OBK08_Item_Record)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_BOO_RECORD, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_CALL(N(EnableItemTransparency))
        EVT_SET(MV_KeepAwayItem, LVar0)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 0, 0, 0, 0, MODEL_yuka_jyu, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OBK08_HiddenPanel)
    EVT_RETURN
    EVT_END
};
