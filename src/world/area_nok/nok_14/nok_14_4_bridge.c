#include "nok_14.h"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

EvtScript N(EVS_Scene_BuildBridge) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(DisableCameraLeadingPlayer))
    EVT_CALL(InterpCamTargetPos, CAM_DEFAULT, TRUE, 3, 0, -60, 20)
    EVT_WAIT(10)
    EVT_SET(GB_StoryProgress, STORY_CH1_MADE_SECOND_BRIDGE)
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_THUD_1, SOUND_SPACE_DEFAULT, 0, 0, -60)
    EVT_CALL(MakeLerp, -200, 0, 15, EASING_COS_IN)
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
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_1, SOUND_SPACE_DEFAULT, -84, 0, -60)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 8, EASING_COS_IN_OUT)
        EVT_LABEL(20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ita11, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(20)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_2, SOUND_SPACE_DEFAULT, -56, 0, -60)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 8, EASING_LINEAR)
        EVT_LABEL(24)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ita22, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(24)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_3, SOUND_SPACE_DEFAULT, -28, 0, -60)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 8, EASING_LINEAR)
        EVT_LABEL(21)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ita33, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(21)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_4, SOUND_SPACE_DEFAULT, 0, 0, -60)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 8, EASING_LINEAR)
        EVT_LABEL(25)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ita44, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(25)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_5, SOUND_SPACE_DEFAULT, 28, 0, -60)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 8, EASING_LINEAR)
        EVT_LABEL(22)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ita55, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(22)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_6, SOUND_SPACE_DEFAULT, 56, 0, -60)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 8, EASING_LINEAR)
        EVT_LABEL(26)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ita66, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(26)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_7, SOUND_SPACE_DEFAULT, 84, 0, -60)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 8, EASING_LINEAR)
        EVT_LABEL(23)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ita77, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_NE(LVar1, 0)
                EVT_GOTO(23)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o255, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(20)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(InterpCamTargetPos, CAM_DEFAULT, TRUE, LVar0, LVar1, LVar2, 10)
    EVT_CALL(N(EnableCameraLeadingPlayer))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBridge) = {
    EVT_SET(LVar0, 1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_MADE_SECOND_BRIDGE)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_BuildBridge)), TRIGGER_AREA_FLAG_SET, AF_NOK14_HitSwitch, 1, 0)
        EVT_CALL(TranslateGroup, MODEL_hashi, 0, -200, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o255, COLLIDER_FLAGS_UPPER_MASK)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RotateModel, MODEL_ita11, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ita33, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ita55, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ita77, 90, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ita22, 90, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ita44, 90, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ita66, 90, 1, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
