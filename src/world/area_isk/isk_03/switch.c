#include "isk_03.h"

extern EvtScript N(EVS_OnTouch_DrainSwitch);

EvtScript N(EVS_SetupSwitch) = {
    Call(ParentColliderToModel, COLLIDER_o1989, MODEL_o1992)
    Call(ParentColliderToModel, COLLIDER_o1990, MODEL_o1992)
    IfEq(AF_ISK03_SandSwitchActivated, false)
        BindTrigger(Ref(N(EVS_OnTouch_DrainSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o1990, 1, 0)
    Else
        Call(TranslateGroup, MODEL_g319, 0, -14, 0)
        Call(UpdateColliderTransform, COLLIDER_o1989)
        Call(UpdateColliderTransform, COLLIDER_o1990)
    EndIf
    Return
    End
};

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
    IfLt(LVar1, 50)
        Thread
            Call(DisablePartnerAI, 0)
            Call(SetNpcJumpscale, NPC_PARTNER, Float(2.5))
            Call(NpcJump0, NPC_PARTNER, 470, 50, 268, 10)
            Wait(10)
            Call(EnablePartnerAI)
        EndThread
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o1990, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g319, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o1989)
        Call(UpdateColliderTransform, COLLIDER_o1990)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_o1990, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK03_SandSwitchActivated, true)
    Unbind
    Return
    End
};
