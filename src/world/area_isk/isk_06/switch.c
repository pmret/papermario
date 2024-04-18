#include "isk_06.h"

extern EvtScript N(EVS_OnTouch_DrainSwitch);

EvtScript N(EVS_SetupSwitch) = {
    Call(ParentColliderToModel, COLLIDER_o2090, MODEL_g336)
    Call(ParentColliderToModel, COLLIDER_o2091, MODEL_g336)
    IfEq(AF_ISK06_SandSwitchActivated, FALSE)
        BindTrigger(Ref(N(EVS_OnTouch_DrainSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2091, 1, 0)
    Else
        Call(TranslateModel, MODEL_g336, 0, -14, 0)
        Call(UpdateColliderTransform, COLLIDER_o2090)
        Call(UpdateColliderTransform, COLLIDER_o2091)
    EndIf
    Return
    End
};

EvtScript N(EVS_OnTouch_DrainSwitch) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Label(5)
        Wait(1)
        Call(PartnerCanUseAbility, LVar0)
        IfEq(LVar0, TRUE)
            Goto(5)
        EndIf
    Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    IfLt(LVar1, -80)
        Thread
            Call(DisablePartnerAI, 0)
            Call(SetNpcJumpscale, NPC_PARTNER, Float(2.5))
            Call(NpcJump0, NPC_PARTNER, 343, -80, -421, 10)
            Wait(10)
            Call(EnablePartnerAI)
        EndThread
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2091, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_g336, 0, LVar0, 0)
    Call(UpdateColliderTransform, COLLIDER_o2090)
    Call(UpdateColliderTransform, COLLIDER_o2091)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2091, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK06_SandSwitchActivated, TRUE)
    Unbind
    Return
    End
};
