#include "nok_14.h"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

EvtScript N(EVS_Scene_BuildBridge) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(DisablePlayerInput, TRUE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Call(N(DisableCameraLeadingPlayer))
    Call(InterpCamTargetPos, CAM_DEFAULT, TRUE, 3, 0, -60, 20)
    Wait(10)
    Set(GB_StoryProgress, STORY_CH1_MADE_SECOND_BRIDGE)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_THUD_1, SOUND_SPACE_DEFAULT, 0, 0, -60)
    Call(MakeLerp, -200, 0, 15, EASING_COS_IN)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_hashi, 0, LVar0, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(10)
        EndIf
    Loop(6)
        Call(TranslateGroup, MODEL_hashi, 0, 3, 0)
        Wait(1)
        Call(TranslateGroup, MODEL_hashi, 0, 0, 0)
        Wait(1)
    EndLoop
    Wait(15)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_1, SOUND_SPACE_DEFAULT, -84, 0, -60)
    Thread
        Call(MakeLerp, 0, 90, 8, EASING_COS_IN_OUT)
        Label(20)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ita11, LVar0, -1, 0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(20)
            EndIf
    EndThread
    Wait(3)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_2, SOUND_SPACE_DEFAULT, -56, 0, -60)
    Thread
        Call(MakeLerp, 0, 90, 8, EASING_LINEAR)
        Label(24)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ita22, LVar0, 1, 0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(24)
            EndIf
    EndThread
    Wait(3)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_3, SOUND_SPACE_DEFAULT, -28, 0, -60)
    Thread
        Call(MakeLerp, 0, 90, 8, EASING_LINEAR)
        Label(21)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ita33, LVar0, -1, 0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(21)
            EndIf
    EndThread
    Wait(3)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_4, SOUND_SPACE_DEFAULT, 0, 0, -60)
    Thread
        Call(MakeLerp, 0, 90, 8, EASING_LINEAR)
        Label(25)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ita44, LVar0, 1, 0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(25)
            EndIf
    EndThread
    Wait(3)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_5, SOUND_SPACE_DEFAULT, 28, 0, -60)
    Thread
        Call(MakeLerp, 0, 90, 8, EASING_LINEAR)
        Label(22)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ita55, LVar0, -1, 0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(22)
            EndIf
    EndThread
    Wait(3)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_6, SOUND_SPACE_DEFAULT, 56, 0, -60)
    Thread
        Call(MakeLerp, 0, 90, 8, EASING_LINEAR)
        Label(26)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ita66, LVar0, 1, 0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(26)
            EndIf
    EndThread
    Wait(3)
    Call(PlaySoundAt, SOUND_NOK_BRIDGE_XYLOPHONE_7, SOUND_SPACE_DEFAULT, 84, 0, -60)
    Thread
        Call(MakeLerp, 0, 90, 8, EASING_LINEAR)
        Label(23)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ita77, LVar0, -1, 0, 0)
            Wait(1)
            IfNe(LVar1, 0)
                Goto(23)
            EndIf
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o255, COLLIDER_FLAGS_UPPER_MASK)
    Wait(20)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(InterpCamTargetPos, CAM_DEFAULT, TRUE, LVar0, LVar1, LVar2, 10)
    Call(N(EnableCameraLeadingPlayer))
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupBridge) = {
    Set(LVar0, 1)
    IfLt(GB_StoryProgress, STORY_CH1_MADE_SECOND_BRIDGE)
        Set(LVar0, 0)
    EndIf
    IfEq(LVar0, 0)
        BindTrigger(Ref(N(EVS_Scene_BuildBridge)), TRIGGER_AREA_FLAG_SET, AF_NOK14_HitSwitch, 1, 0)
        Call(TranslateGroup, MODEL_hashi, 0, -200, 0)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o255, COLLIDER_FLAGS_UPPER_MASK)
        Return
    EndIf
    Call(RotateModel, MODEL_ita11, 90, -1, 0, 0)
    Call(RotateModel, MODEL_ita33, 90, -1, 0, 0)
    Call(RotateModel, MODEL_ita55, 90, -1, 0, 0)
    Call(RotateModel, MODEL_ita77, 90, -1, 0, 0)
    Call(RotateModel, MODEL_ita22, 90, 1, 0, 0)
    Call(RotateModel, MODEL_ita44, 90, 1, 0, 0)
    Call(RotateModel, MODEL_ita66, 90, 1, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};
