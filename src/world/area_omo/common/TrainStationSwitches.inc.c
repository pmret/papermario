#include "common.h"

// controls the large arrow hovering in front of the train station
EvtScript N(EVS_UpdateDirectionArrow) = {
    Call(SetTexPanner, MODEL_y_a, TEX_PANNER_2)
    Call(EnableTexPanning, MODEL_y_a, true)
    // adjust color with a UV offset into a color palette texture
    Set(MV_ArrowTexUOffset, 0x4000 * 2)
    Thread
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, MV_ArrowTexUOffset, 0)
            Wait(1)
        EndLoop
    EndThread
    Set(LVar5, 0)
    // slowly rotate the arrow
    Label(0)
        Add(LVar5, 2)
        IfGt(LVar5, 360)
            Sub(LVar5, 360)
        EndIf
        Call(RotateModel, MODEL_y_a, LVar5, 0, 0, -1)
        Wait(1)
        IfEq(MF_EitherSwitchPressed, true)
            Goto(10)
        EndIf
        Goto(0)
    Label(10)
        IfEq(AF_OMO_UsingRightSwitch, false)
            Set(LVar2, 270)
            Call(EnableTexPanning, MODEL_y_c2, false)
            Call(EnableTexPanning, MODEL_y_b2, true)
        Else
            Set(LVar2, 90)
            Call(EnableTexPanning, MODEL_y_b2, false)
            Call(EnableTexPanning, MODEL_y_c2, true)
        EndIf
        IfLt(LVar2, LVar5)
            Add(LVar2, 360)
        EndIf
        Set(LVar6, AF_OMO_UsingRightSwitch)
        Call(MakeLerp, LVar5, LVar2, 60, EASING_COS_FAST_OVERSHOOT)
        Call(UpdateLerp)
        Set(LVar4, -1)
        Label(11)
        Call(UpdateLerp)
        IfLt(LVar2, LVar0)
            Set(LVar3, 0)
        Else
            Set(LVar3, 1)
        EndIf
        IfNe(LVar4, -1)
            IfNe(LVar3, LVar4)
                Call(PlaySound, SOUND_OMO_TRAIN_SWITCH_RATTLE)
            EndIf
        EndIf
        Set(LVar4, LVar3)
        Call(RotateModel, MODEL_y_a, LVar0, 0, 0, -1)
        Wait(1)
        IfNe(AF_OMO_UsingRightSwitch, LVar6)
            Goto(21)
        EndIf
        IfEq(LVar1, 1)
            Goto(11)
        EndIf
        Call(PlaySound, SOUND_OMO_TRAIN_SWITCH_SELECT)
        IfEq(AF_OMO_UsingRightSwitch, false)
            Set(MV_ArrowTexUOffset, 0x4000)
        Else
            Set(MV_ArrowTexUOffset, 0x4000 * 3)
        EndIf
        Label(20)
            Wait(1)
            IfEq(AF_OMO_UsingRightSwitch, LVar6)
                Goto(20)
            EndIf
        Label(21)
        Set(LVar5, LVar0)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_PressSwitch_Left) = {
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_PARAKARRY)
            Return
        EndIf
    EndIf
    IfEq(MF_EitherSwitchPressed, true)
        IfEq(AF_OMO_UsingRightSwitch, false)
            Return
        EndIf
    EndIf
    Set(MF_EitherSwitchPressed, true)
    Set(AF_OMO_UsingRightSwitch, false)
    Call(MakeLerp, 0, -18, 15, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_y_b1, 0, LVar0, 0)
        Call(TranslateModel, MODEL_y_b2, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o920)
        Call(UpdateColliderTransform, COLLIDER_o921)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(MakeLerp, -18, 0, 15, EASING_LINEAR)
    Label(1)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_y_b1, 0, LVar0, 0)
        Call(TranslateModel, MODEL_y_b2, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o920)
        Call(UpdateColliderTransform, COLLIDER_o921)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_PressSwitch_Right) = {
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_PARAKARRY)
            Return
        EndIf
    EndIf
    IfEq(MF_EitherSwitchPressed, true)
        IfEq(AF_OMO_UsingRightSwitch, true)
            Return
        EndIf
    EndIf
    Set(MF_EitherSwitchPressed, true)
    Set(AF_OMO_UsingRightSwitch, true)
    Call(MakeLerp, 0, -18, 15, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_y_c1, 0, LVar0, 0)
        Call(TranslateModel, MODEL_y_c2, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o923)
        Call(UpdateColliderTransform, COLLIDER_o924)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(MakeLerp, -18, 0, 15, EASING_LINEAR)
    Label(1)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_y_c1, 0, LVar0, 0)
        Call(TranslateModel, MODEL_y_c2, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o923)
        Call(UpdateColliderTransform, COLLIDER_o924)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Return
    End
};

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_SetupSwitches) = {
    Set(MF_EitherSwitchPressed, false)
    Set(AF_JAN01_TreeDrop_StarPiece, false)
    Exec(N(EVS_UpdateDirectionArrow))
    Call(ParentColliderToModel, COLLIDER_o920, MODEL_y_b1)
    Call(ParentColliderToModel, COLLIDER_o921, MODEL_y_b2)
    Call(ParentColliderToModel, COLLIDER_o923, MODEL_y_c1)
    Call(ParentColliderToModel, COLLIDER_o924, MODEL_y_c2)
    BindTrigger(Ref(N(EVS_PressSwitch_Left)), TRIGGER_FLOOR_TOUCH, COLLIDER_o920, 1, 0)
    BindTrigger(Ref(N(EVS_PressSwitch_Left)), TRIGGER_WALL_HAMMER, COLLIDER_o921, 1, 0)
    BindTrigger(Ref(N(EVS_PressSwitch_Right)), TRIGGER_FLOOR_TOUCH, COLLIDER_o923, 1, 0)
    BindTrigger(Ref(N(EVS_PressSwitch_Right)), TRIGGER_WALL_HAMMER, COLLIDER_o924, 1, 0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(-1100,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
