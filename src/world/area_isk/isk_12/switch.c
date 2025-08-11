#include "isk_12.h"

// switch for draining the sand into the lower chamber
EvtScript N(EVS_OnTouch_DrainSwitch) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, false)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Label(5)
        Wait(1)
        Call(PartnerCanUseAbility, LVar0)
        IfEq(LVar0, true)
            Goto(5)
        EndIf
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    IfLt(LVar1, -470)
        Thread
            Call(DisablePartnerAI, 0)
            Call(SetNpcJumpscale, NPC_PARTNER, Float(2.5))
            Call(NpcJump0, NPC_PARTNER, 529, -470, 82, 10)
            Wait(10)
            Call(EnablePartnerAI)
        EndThread
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2059, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_g367, 0, LVar0, 0)
    Call(UpdateColliderTransform, COLLIDER_o2056)
    Call(UpdateColliderTransform, COLLIDER_o2059)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2059, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK12_SandSwitchActivated, true)
    Unbind
    Return
    End
};

// switch for creating a staircase of bricks emerging from the wall
EvtScript N(EVS_OnTouch_StaircaseSwitch) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, false)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(PlaySoundAtCollider, COLLIDER_o2090, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_B2, 0, LVar0, 0)
    Call(UpdateColliderTransform, COLLIDER_o2090)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2090, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Call(InterpPlayerYaw, 260, 0)
    Set(AF_ISK12_StairSwitchActivated, true)
    Thread
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 449, -822, 148)
        Call(MakeLerp, -50, 0, 60, EASING_QUADRATIC_IN)
        Label(20)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g378, LVar0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 449, -822, 148)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    EndThread
    Wait(50)
    Thread
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 460, -806, 108)
        Call(MakeLerp, -50, 0, 60, EASING_QUADRATIC_IN)
        Label(22)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g379, LVar0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(22)
        EndIf
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 460, -806, 108)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    EndThread
    Wait(30)
    Thread
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 432, -825, 189)
        Call(MakeLerp, -50, 0, 60, EASING_QUADRATIC_IN)
        Label(24)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g376, LVar0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(24)
        EndIf
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 432, -825, 189)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    EndThread
    Wait(30)
    Thread
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 451, -812, 137)
        Call(MakeLerp, -50, 0, 50, EASING_QUADRATIC_IN)
        Label(26)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g373, LVar0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(26)
        EndIf
        Call(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 451, -812, 137)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.3))
    EndThread
    Wait(50)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2080, COLLIDER_FLAGS_UPPER_MASK)
    Wait(3)
    Call(DisablePlayerInput, false)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupSwitches) = {
    Call(ParentColliderToModel, COLLIDER_o2056, MODEL_g367)
    Call(ParentColliderToModel, COLLIDER_o2059, MODEL_g367)
    Call(ParentColliderToModel, COLLIDER_o2090, MODEL_B2)
    IfEq(AF_ISK12_SandSwitchActivated, false)
        BindTrigger(Ref(N(EVS_OnTouch_DrainSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2059, 1, 0)
    Else
        Call(TranslateModel, MODEL_g367, 0, -14, 0)
        Call(UpdateColliderTransform, COLLIDER_o2056)
        Call(UpdateColliderTransform, COLLIDER_o2059)
    EndIf
    IfEq(AF_ISK12_StairSwitchActivated, true)
        Call(TranslateModel, MODEL_B2, 0, -14, 0)
        Call(UpdateColliderTransform, COLLIDER_o2090)
    Else
        Thread
            Call(TranslateGroup, MODEL_g378, -52, 0, 0)
            Call(TranslateGroup, MODEL_g379, -52, 0, 0)
            Call(TranslateGroup, MODEL_g376, -52, 0, 0)
            Call(TranslateGroup, MODEL_g373, -52, 0, 0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2080, COLLIDER_FLAGS_UPPER_MASK)
            IfEq(GF_ISK12_Hammer2Block, false)
                Call(TranslateModel, MODEL_B2, 0, -14, 0)
                Call(UpdateColliderTransform, COLLIDER_o2090)
                Label(10)
                IfEq(GF_ISK12_Hammer2Block, false)
                    Wait(1)
                    Goto(10)
                EndIf
                Call(DisablePlayerInput, true)
                Call(MakeLerp, -14, 0, 30, EASING_LINEAR)
                Label(20)
                Call(UpdateLerp)
                Call(TranslateModel, MODEL_B2, 0, LVar0, 0)
                Call(UpdateColliderTransform, COLLIDER_o2090)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(20)
                EndIf
                Wait(3)
                Call(DisablePlayerInput, false)
            EndIf
            BindTrigger(Ref(N(EVS_OnTouch_StaircaseSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2090, 1, 0)
        EndThread
    EndIf
    Return
    End
};
