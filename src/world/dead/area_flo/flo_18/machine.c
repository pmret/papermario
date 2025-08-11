#include "flo_18.h"
#include "effects.h"

enum {
    DAMAGE_PART_LEFT_SIDE,
    DAMAGE_PART_RIGHT_SIDE,
    DAMAGE_PART_PROTRUSTIONS,
    DAMAGE_PART_LEVER,
    DAMAGE_PART_SMOKE_STACK,
};

API_CALLABLE(N(SetMachineLightningColor)) {
    EffectInstance* effect = (EffectInstance*) script->varTable[15];

    effect->data.lightningBolt->outerColor.r = 69;
    effect->data.lightningBolt->outerColor.g = 255;
    effect->data.lightningBolt->outerColor.b = 217;
    effect->data.lightningBolt->innerColor.r = 176;
    effect->data.lightningBolt->innerColor.g = 254;
    effect->data.lightningBolt->innerColor.b = 124;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateMachineLightning) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    Loop(0)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, Float(-16.0), Float(102.0), Float(-4.1), Float(80.9), Float(102.0), Float(-4.1), Float(0.5), 6)
        Call(N(SetMachineLightningColor))
        Wait(4)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, Float(80.9), Float(102.0), Float(-4.1), Float(-16.0), Float(102.0), Float(-4.1), Float(0.5), 6)
        Call(N(SetMachineLightningColor))
        Wait(4)
        IfGe(GB_FLO18_MachineDamage_Right, 3)
            BreakLoop
        EndIf
    EndLoop
    Set(LVar0, 6)
    Loop(5)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, Float(-16.0), Float(102.0), Float(-4.1), Float(80.9), Float(102.0), Float(-4.1), Float(0.5), 6)
        Call(N(SetMachineLightningColor))
        Wait(LVar0)
        Add(LVar0, 2)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, Float(80.9), Float(102.0), Float(-4.1), Float(-16.0), Float(102.0), Float(-4.1), Float(0.5), 6)
        Call(N(SetMachineLightningColor))
        Wait(LVar0)
        Add(LVar0, 2)
    EndLoop
    Return
    End
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_UpdateSmokeParticle) = {
    Call(EnableModel, LVarF, true)
    Set(LVarE, 159)
    Loop(LVarE)
        AddF(LVar3, 0)
        AddF(LVar4, Float(0.0))
        SetF(LVar5, Float(0.01))
        AddF(LVar0, LVar3)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        MulF(LVar6, Float(1.01))
        AddF(LVar7, Float(0.01))
        SetF(LVar8, LVar6)
        Call(N(CosInterpMinMax), LVarE, LVarA, Float(0.0), Float(0.203), 15, 0, 0)
        AddF(LVar8, LVarA)
        SetF(LVar9, LVar7)
        Call(N(CosInterpMinMax), LVarE, LVarA, Float(0.0), Float(0.203), 20, 0, 90)
        AddF(LVar9, LVarA)
        SetF(LVarA, LVar0)
        MulF(LVarA, Float(10.0))
        Call(TranslateModel, LVarF, LVar0, LVar1, LVar2)
        Call(ScaleModel, LVarF, LVar8, LVar9, 1)
        Call(RotateModel, LVarF, LVarA, 0, 0, 1)
        Wait(1)
    EndLoop
    Call(EnableModel, LVarF, false)
    Return
    End
};

EvtScript N(EVS_ManageSmoke) = {
    Set(LVarE, 0)
    Label(0)
        IfGe(GB_FLO18_MachineDamage_Right, 3)
            Return
        EndIf
        SetF(LVar0, Float(132.0))
        SetF(LVar1, Float(90.0))
        SetF(LVar2, Float(-30.0))
        Call(RandInt, 100, LVar3)
        AddF(LVar3, -50)
        DivF(LVar3, Float(200.0))
        SetF(LVar4, Float(1.0))
        SetF(LVar5, 0)
        SetF(LVar6, Float(0.296))
        SetF(LVar7, Float(0.296))
        Set(LVarF, LVarE)
        Add(LVarF, CLONED_MODEL(0))
        Exec(N(EVS_UpdateSmokeParticle))
        Add(LVarE, 1)
        IfGe(LVarE, 16)
            Set(LVarE, 0)
        EndIf
        Wait(10)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ShakeMachine) = {
    IfEq(MF_MachineShaking, true)
        Return
    EndIf
    Set(MF_MachineShaking, true)
    Set(LVarF, 0)
    Loop(12)
        Call(RandInt, 80, LVar0)
        Sub(LVar0, 40)
        Call(RandInt, 50, LVar1)
        Call(RandInt, 50, LVar2)
        Sub(LVar2, 25)
        PlayEffect(EFFECT_00, LVar0, LVar1, LVar2, 5, 10, 1, 1)
        Add(LVarF, 1)
        Call(N(CosInterpMinMax), LVarF, LVarE, Float(1.0), Float(1.093), 2, 0, 0)
        Call(N(CosInterpMinMax), LVarF, LVarD, Float(1.093), Float(1.0), 2, 0, 0)
        SetF(LVar0, LVarE)
        SetF(LVar1, LVarD)
        SetF(LVar2, LVarE)
        IfEq(GB_FLO18_MachineDamage_Left, 0)
            Call(ScaleModel, MODEL_o115, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o116, LVar0, LVar1, LVar2)
        EndIf
        IfEq(GB_FLO18_MachineDamage_Right, 0)
            Call(ScaleModel, MODEL_o117, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o118, LVar0, LVar1, LVar2)
        EndIf
        IfLe(GB_FLO18_MachineDamage_Left, 1)
            Call(ScaleModel, MODEL_o119, LVar0, LVar1, LVar2)
        EndIf
        IfLe(GB_FLO18_MachineDamage_Left, 2)
            IfLe(GB_FLO18_MachineDamage_Right, 1)
                Call(ScaleModel, MODEL_o120, LVar0, LVar1, LVar2)
                Call(ScaleModel, MODEL_o121, LVar0, LVar1, LVar2)
                Call(ScaleModel, MODEL_o122, LVar0, LVar1, LVar2)
                Call(ScaleModel, MODEL_o123, LVar0, LVar1, LVar2)
                Call(ScaleModel, MODEL_o124, LVar0, LVar1, LVar2)
            EndIf
        EndIf
        Call(ScaleModel, MODEL_o113, LVar0, LVar1, LVar2)
        IfLe(GB_FLO18_MachineDamage_Left, 2)
            IfLe(GB_FLO18_MachineDamage_Right, 2)
                Call(ScaleModel, MODEL_o100, LVar0, LVar1, LVar2)
                Call(ScaleModel, MODEL_o99, LVar0, LVar1, LVar2)
                Call(ScaleModel, MODEL_o125, LVar0, LVar1, LVar2)
            EndIf
        EndIf
        Call(ScaleModel, MODEL_o92, LVar0, LVar1, LVar2)
        Call(ScaleModel, MODEL_o93, LVar0, LVar1, LVar2)
        Call(ScaleModel, MODEL_o94, LVar0, LVar1, LVar2)
        Call(ScaleModel, MODEL_o95, LVar0, LVar1, LVar2)
        Call(ScaleModel, MODEL_o91, LVar0, LVar1, LVar2)
        Call(ScaleModel, MODEL_o114, LVar0, LVar1, LVar2)
        SubF(LVar0, Float(1.046))
        MulF(LVar0, Float(100.0))
        IfEq(GB_FLO18_MachineDamage_Left, 0)
            Call(RotateModel, MODEL_o115, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_o116, LVar0, 0, 0, 1)
        EndIf
        IfEq(GB_FLO18_MachineDamage_Right, 0)
            Call(RotateModel, MODEL_o117, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_o118, LVar0, 0, 0, 1)
        EndIf
        IfLe(GB_FLO18_MachineDamage_Left, 1)
            Call(RotateModel, MODEL_o119, LVar0, 0, 0, 1)
        EndIf
        IfLe(GB_FLO18_MachineDamage_Left, 2)
            IfLe(GB_FLO18_MachineDamage_Right, 1)
                Call(RotateModel, MODEL_o120, LVar0, 0, 0, 1)
                Call(RotateModel, MODEL_o121, LVar0, 0, 0, 1)
                Call(RotateModel, MODEL_o122, LVar0, 0, 0, 1)
                Call(RotateModel, MODEL_o123, LVar0, 0, 0, 1)
                Call(RotateModel, MODEL_o124, LVar0, 0, 0, 1)
            EndIf
        EndIf
        Call(RotateModel, MODEL_o113, LVar0, 0, 0, 1)
        IfLe(GB_FLO18_MachineDamage_Left, 2)
            IfLe(GB_FLO18_MachineDamage_Right, 2)
                Call(RotateModel, MODEL_o100, LVar0, 0, 0, 1)
                Call(RotateModel, MODEL_o99, LVar0, 0, 0, 1)
                Call(RotateModel, MODEL_o125, LVar0, 0, 0, 1)
            EndIf
        EndIf
        Call(RotateModel, MODEL_o92, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_o93, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_o94, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_o95, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_o91, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_o114, LVar0, 0, 0, 1)
        Wait(1)
    EndLoop
    SetF(LVar0, 1)
    SetF(LVar1, 1)
    SetF(LVar2, 1)
    IfEq(GB_FLO18_MachineDamage_Left, 0)
        Call(ScaleModel, MODEL_o115, LVar0, LVar1, LVar2)
        Call(ScaleModel, MODEL_o116, LVar0, LVar1, LVar2)
    EndIf
    IfEq(GB_FLO18_MachineDamage_Right, 0)
        Call(ScaleModel, MODEL_o117, LVar0, LVar1, LVar2)
        Call(ScaleModel, MODEL_o118, LVar0, LVar1, LVar2)
    EndIf
    IfLe(GB_FLO18_MachineDamage_Left, 1)
        Call(ScaleModel, MODEL_o119, LVar0, LVar1, LVar2)
    EndIf
    IfLe(GB_FLO18_MachineDamage_Left, 2)
        IfLe(GB_FLO18_MachineDamage_Right, 1)
            Call(ScaleModel, MODEL_o120, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o121, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o122, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o123, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o124, LVar0, LVar1, LVar2)
        EndIf
    EndIf
    Call(ScaleModel, MODEL_o113, LVar0, LVar1, LVar2)
    IfLe(GB_FLO18_MachineDamage_Left, 2)
        IfLe(GB_FLO18_MachineDamage_Right, 2)
            Call(ScaleModel, MODEL_o100, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o99, LVar0, LVar1, LVar2)
            Call(ScaleModel, MODEL_o125, LVar0, LVar1, LVar2)
        EndIf
    EndIf
    Call(ScaleModel, MODEL_o92, LVar0, LVar1, LVar2)
    Call(ScaleModel, MODEL_o93, LVar0, LVar1, LVar2)
    Call(ScaleModel, MODEL_o94, LVar0, LVar1, LVar2)
    Call(ScaleModel, MODEL_o95, LVar0, LVar1, LVar2)
    Call(ScaleModel, MODEL_o91, LVar0, LVar1, LVar2)
    Call(ScaleModel, MODEL_o114, LVar0, LVar1, LVar2)
    Wait(1)
    Set(MF_MachineShaking, false)
    Return
    End
};

EvtScript N(EVS_DamagedLeftOnce) = {
    SetF(LVar0, 0)
    SetF(LVar1, 0)
    SetF(LVar2, 0)
    SetF(LVar3, Float(-1.0))
    SetF(LVar4, Float(0.0))
    SetF(LVar5, Float(3.0))
    Thread
        Wait(10)
        Call(PlaySoundAtCollider, COLLIDER_o130, SOUND_PUFF_PUFF_PART_BREAKS, SOUND_SPACE_DEFAULT)
    EndThread
    Loop(300)
        AddF(LVar4, Float(-0.5))
        AddF(LVar5, Float(0.093))
        AddF(LVar0, LVar3)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        IfLt(LVar1, -10)
            SetF(LVar1, Float(-10.0))
            SetF(LVar3, Float(0.0))
            SetF(LVar4, Float(0.0))
            IfGe(LVar2, 80)
                Goto(0)
            EndIf
        EndIf
    EndIf
    Call(TranslateModel, MODEL_o115, -78, 19, 2)
    Call(TranslateModel, MODEL_o116, -78, 19, 2)
    Call(TranslateModel, MODEL_o115, LVar0, LVar1, 0)
    Call(TranslateModel, MODEL_o116, LVar0, LVar1, 0)
    Call(RotateModel, MODEL_o115, LVar2, 0, 0, 1)
    Call(RotateModel, MODEL_o116, LVar2, 0, 0, 1)
    Call(TranslateModel, MODEL_o115, 78, -19, -2)
    Call(TranslateModel, MODEL_o116, 78, -19, -2)
    Wait(1)
EndLoop
Label(0)
Wait(30)
Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
Return
End
};

EvtScript N(EVS_DamagedRightOnce) = {
    SetF(LVar0, 0)
    SetF(LVar1, 0)
    SetF(LVar2, 0)
    SetF(LVar3, Float(0.0))
    SetF(LVar4, Float(0.0))
    SetF(LVar5, Float(-5.0))
    Thread
        Wait(12)
        Call(PlaySoundAtCollider, COLLIDER_o175, SOUND_PUFF_PUFF_PANEL_BREAKS, SOUND_SPACE_DEFAULT)
    EndThread
    Loop(300)
        AddF(LVar4, Float(-0.5))
        AddF(LVar0, LVar3)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        IfLt(LVar2, -45)
            Set(LVar5, 5)
        EndIf
        IfGt(LVar2, 0)
            Set(LVar2, 0)
            Set(LVar3, 5)
        EndIf
        IfLt(LVar1, -25)
            Set(LVar4, 0)
            Set(LVar1, -25)
        EndIf
        IfGt(LVar0, 90)
            Goto(0)
        EndIf
        Call(TranslateModel, MODEL_o117, 50, 28, 27)
        Call(TranslateModel, MODEL_o118, 50, 28, 27)
        Call(TranslateModel, MODEL_o117, 0, LVar1, 1)
        Call(TranslateModel, MODEL_o118, 0, LVar1, 1)
        Call(RotateModel, MODEL_o117, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o118, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o117, LVar2, 0, 0, 1)
        Call(RotateModel, MODEL_o118, LVar2, 0, 0, 1)
        Call(TranslateModel, MODEL_o117, -50, -28, -27)
        Call(TranslateModel, MODEL_o118, -50, -28, -27)
        Wait(1)
    EndLoop
    Label(0)
    Wait(30)
    Return
    End
};

EvtScript N(EVS_DamagedLeftTwice) = {
    SetF(LVar2, 0)
    SetF(LVar1, 0)
    SetF(LVar0, 0)
    SetF(LVar5, Float(0.0))
    Thread
        Wait(15)
        Call(PlaySoundAtCollider, COLLIDER_o174, SOUND_PUFF_PUFF_PANEL_BREAKS, SOUND_SPACE_DEFAULT)
    EndThread
    Loop(300)
        AddF(LVar5, Float(0.5))
        AddF(LVar2, LVar5)
        IfGe(LVar2, 80)
            SetF(LVar2, 80)
            MulF(LVar5, Float(-0.5))
            IfEq(LVar5, 0)
                Goto(0)
            EndIf
        EndIf
        Call(TranslateModel, MODEL_o119, -55, 5, 16)
        Call(TranslateModel, MODEL_o119, LVar0, LVar1, 0)
        Call(RotateModel, MODEL_o119, LVar2, 0, 0, 1)
        Call(TranslateModel, MODEL_o119, 55, -5, -16)
        Wait(1)
    EndLoop
    Label(0)
    Wait(30)
    Return
    End
};

EvtScript N(EVS_DamagedRightTwice) = {
    SetF(LVar2, 0)
    SetF(LVar1, 0)
    SetF(LVar0, 0)
    SetF(LVar5, Float(0.0))
    Thread
        Wait(15)
        Call(PlaySoundAtCollider, COLLIDER_o127, SOUND_PUFF_PUFF_PANEL_BREAKS, SOUND_SPACE_DEFAULT)
    EndThread
    Loop(300)
        AddF(LVar5, Float(0.5))
        AddF(LVar2, LVar5)
        IfGe(LVar2, 80)
            SetF(LVar2, 80)
            MulF(LVar5, Float(-0.5))
            IfEq(LVar5, 0)
                Goto(0)
            EndIf
        EndIf
        Call(TranslateModel, MODEL_o122, 60, 0, 16)
        Call(RotateModel, MODEL_o122, LVar2, 0, 0, -1)
        Call(TranslateModel, MODEL_o122, -60, 0, -16)
        Call(TranslateModel, MODEL_o120, 0, 0, 27)
        Call(TranslateModel, MODEL_o121, 0, 0, 27)
        Call(RotateModel, MODEL_o120, LVar2, 1, 0, 0)
        Call(RotateModel, MODEL_o121, LVar2, 1, 0, 0)
        Call(TranslateModel, MODEL_o120, 0, 0, -27)
        Call(TranslateModel, MODEL_o121, 0, 0, -27)
        Call(TranslateModel, MODEL_o123, 0, 0, -41)
        Call(TranslateModel, MODEL_o124, 0, 0, -41)
        Call(RotateModel, MODEL_o123, LVar2, -1, 0, 0)
        Call(RotateModel, MODEL_o124, LVar2, -1, 0, 0)
        Call(TranslateModel, MODEL_o123, 0, 0, 41)
        Call(TranslateModel, MODEL_o124, 0, 0, 41)
        Wait(1)
    EndLoop
    Label(0)
    Wait(30)
    Return
    End
};

EvtScript N(EVS_BreakSmokestack) = {
    SetF(LVar0, 0)
    SetF(LVar1, 0)
    SetF(LVar2, 0)
    SetF(LVar3, Float(-1.0))
    SetF(LVar4, Float(0.0))
    SetF(LVar5, Float(3.0))
    Thread
        Wait(15)
        Call(PlaySoundAtCollider, COLLIDER_o131, SOUND_PUFF_PUFF_PART_BREAKS, SOUND_SPACE_DEFAULT)
    EndThread
    Loop(300)
        AddF(LVar4, Float(-0.5))
        AddF(LVar5, Float(0.093))
        AddF(LVar0, LVar3)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        IfLt(LVar1, -25)
            SetF(LVar1, Float(-25.0))
            SetF(LVar3, Float(0.0))
            SetF(LVar4, Float(0.0))
            IfGe(LVar2, 80)
                Goto(0)
            EndIf
        EndIf
    EndIf
    Call(TranslateModel, MODEL_o100, 124, 17, 3)
    Call(TranslateModel, MODEL_o100, LVar0, LVar1, 0)
    Call(RotateModel, MODEL_o100, LVar2, 0, 0, -1)
    Call(TranslateModel, MODEL_o100, -124, -17, -3)
    Wait(1)
EndLoop
Label(0)
Return
End
};

EvtScript N(EVS_BreakAntenna) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o131, COLLIDER_FLAGS_UPPER_MASK)
    SetF(LVar0, 0)
    SetF(LVar1, 0)
    SetF(LVar2, 0)
    SetF(LVar3, Float(3.0))
    SetF(LVar4, Float(1.0))
    SetF(LVar5, Float(5.0))
    Thread
        Wait(15)
        Call(PlaySoundAtCollider, COLLIDER_o126, SOUND_PUFF_PUFF_PART_BREAKS, SOUND_SPACE_DEFAULT)
    EndThread
    Loop(300)
        AddF(LVar4, Float(-0.5))
        AddF(LVar0, LVar3)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        IfLe(LVar1, -40)
            SetF(LVar1, -40)
            MulF(LVar4, Float(-0.5))
            IfLe(LVar4, 1)
                Goto(1)
            EndIf
        EndIf
        IfGe(LVar2, 60)
            SetF(LVar2, 60)
            SetF(LVar5, 0)
        EndIf
        Call(TranslateModel, MODEL_o99, -34, 50, 10)
        Call(TranslateModel, MODEL_o125, -34, 50, 10)
        Call(TranslateModel, MODEL_o99, 0, LVar1, LVar0)
        Call(RotateModel, MODEL_o99, LVar2, 0, 0, 1)
        Call(TranslateModel, MODEL_o125, 0, LVar1, LVar0)
        Call(RotateModel, MODEL_o125, LVar2, 0, 0, 1)
        Call(TranslateModel, MODEL_o99, 34, -50, -10)
        Call(TranslateModel, MODEL_o125, 34, -50, -10)
        Wait(1)
    EndLoop
    Label(1)
    Wait(30)
    Return
    End
};

Vec3i N(SmokeBurstPositions)[] = {
    {  0,  0, 27 },
    { 80, 35, 27 },
    { 60, 10, 27 },
    { 30,  0, 27 },
    { 80, 35, 27 },
    { 30,  0, 27 },
    { 85,  0, 27 },
    { 80, 35, 27 },
};

EvtScript N(EVS_DamageMachine) = {
    #define LABEL_DONE 0
    DebugPrintVar(LVar0)
    Set(LVarA, LVar0) // in: damage part
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, -210)
        Return
    EndIf
    Call(PlaySound, SOUND_PUFF_PUFF_SMASH)
    ExecWait(N(EVS_ShakeMachine))
    DebugPrintVar(LVarA)
    Set(LVar0, LVarA)
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        Set(MF_HitGuardedMachine, true)
        Return
    EndIf
    DebugPrintVar(MF_MachineBeingDamaged)
    IfEq(MF_MachineBeingDamaged, true)
        Return
    EndIf
    // check damage type
    Set(MF_MachineBeingDamaged, true)
    IfGt(LVar0, DAMAGE_PART_PROTRUSTIONS)
        Goto(LABEL_DONE)
    EndIf
    IfEq(LVar0, DAMAGE_PART_PROTRUSTIONS)
        Goto(11)
    EndIf
    IfEq(LVar0, DAMAGE_PART_LEFT_SIDE)
        Label(11)
        IfEq(GB_FLO18_MachineDamage_Left, 0)
            Set(GB_FLO18_MachineDamage_Left, 1)
            Exec(N(EVS_DamagedLeftOnce))
            Goto(LABEL_DONE)
        EndIf
    EndIf
    IfEq(LVar0, DAMAGE_PART_RIGHT_SIDE)
        IfEq(GB_FLO18_MachineDamage_Right, 0)
            Set(GB_FLO18_MachineDamage_Right, 1)
            Exec(N(EVS_DamagedRightOnce))
            Goto(LABEL_DONE)
        EndIf
    EndIf
    IfEq(LVar0, DAMAGE_PART_LEFT_SIDE)
        IfEq(GB_FLO18_MachineDamage_Left, 1)
            Set(GB_FLO18_MachineDamage_Left, 2)
            Exec(N(EVS_DamagedLeftTwice))
            Goto(LABEL_DONE)
        EndIf
    EndIf
    IfEq(GB_FLO18_MachineDamage_Left, 2)
        IfEq(GB_FLO18_MachineDamage_Right, 1)
            Set(GB_FLO18_MachineDamage_Right, 2)
            Exec(N(EVS_DamagedRightTwice))
            Goto(LABEL_DONE)
        EndIf
    EndIf
    // check if machine is fully broken (2 damage to each side)
    IfEq(GB_FLO18_MachineDamage_Left, 2)
        IfEq(GB_FLO18_MachineDamage_Right, 2)
            Call(DisablePlayerInput, true)
            Call(UseSettingsFrom, CAM_DEFAULT, 40, 0, 0)
            Call(SetPanTarget, CAM_DEFAULT, 40, 0, 0)
            Call(SetCamSpeed, CAM_DEFAULT, Float(1.5))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Set(GB_FLO18_MachineDamage_Right, 3)
            ExecWait(N(EVS_ShakeMachine))
            ExecWait(N(EVS_ShakeMachine))
            ExecWait(N(EVS_ShakeMachine))
            Wait(30)
            Call(GetModelCenter, MODEL_o113)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, 50, LVar2, 100, 20, 0, 30)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, 30, LVar2, 120, 20, 0, 30)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, 10, LVar2, 100, 20, 0, 30)
            Wait(15)
            Thread
                Set(LVar3, 6)
                UseBuf(Ref(N(SmokeBurstPositions)))
                Loop(ARRAY_COUNT(N(SmokeBurstPositions)))
                    BufRead3(LVar0, LVar1, LVar2)
                    Call(PlaySoundAt, SOUND_FLO_PUFF_PUFF_SMOKE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 6)
                    Wait(2)
                    Add(LVar1, 5)
                    Call(PlaySoundAt, SOUND_FLO_PUFF_PUFF_SMOKE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 2, 15)
                    Wait(LVar3)
                    Add(LVar3, 1)
                EndLoop
                SetF(LVar4, Float(2.0))
                Loop(2)
                    UseBuf(Ref(N(SmokeBurstPositions)))
                    Loop(ARRAY_COUNT(N(SmokeBurstPositions)))
                        BufRead3(LVar0, LVar1, LVar2)
                        Call(PlaySoundAt, SOUND_FLO_PUFF_PUFF_SMOKE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 25)
                        Wait(LVar3)
                        Add(LVar3, LVar4)
                        AddF(LVar4, Float(0.5))
                    EndLoop
                EndLoop
            EndThread
            Call(PlaySoundAt, SOUND_FLO_PUFF_PUFF_EXPLODE, SOUND_SPACE_DEFAULT, 70, 40, 10)
            PlayEffect(EFFECT_RING_BLAST, 0, 70, 40, 10, Float(3.0), 30)
            Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
            Call(PlaySoundAt, SOUND_FLO_PUFF_PUFF_EXPLODE, SOUND_SPACE_DEFAULT, 0, 30, 30)
            PlayEffect(EFFECT_RING_BLAST, 0, 0, 30, 30, Float(4.0), 40)
            Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(2.0))
            ExecWait(N(EVS_BreakSmokestack))
            Call(PlaySoundAtCollider, COLLIDER_o126, SOUND_LRAW_PUFF_PUFF_MACHINE | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_DEFAULT)
            Call(FadeOutMusic, 0, 1000)
            Call(DisablePlayerPhysics, true)
            Wait(30)
            ExecWait(N(EVS_BreakAntenna))
            Set(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(GotoMap, Ref("flo_15"), flo_15_ENTRY_1)
            Wait(70)
            Return
        EndIf
    EndIf
    Label(LABEL_DONE)
    Set(MF_MachineBeingDamaged, false)
    Return
    End
};

BombTrigger N(Machine_BombTrigger_01) = {
    .pos = { 5.0f, 0.0f, -10.0f },
    .diameter = 0.0f
};

BombTrigger N(Machine_BombTrigger_02) = {
    .pos = { -5.0f, 0.0f, -20.0f },
    .diameter = 0.0f
};

BombTrigger N(Machine_BombTrigger_03) = {
    .pos = { 50.0f, 0.0f, -10.0f },
    .diameter = 0.0f
};

BombTrigger N(Machine_BombTrigger_04) = {
    .pos = { 105.0f, 0.0f, -10.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_SetupMachine) = {
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(EnableModel, MODEL_o101, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o115, false)
        Call(EnableModel, MODEL_o116, false)
        Call(EnableModel, MODEL_o117, false)
        Call(EnableModel, MODEL_o118, false)
        Call(EnableModel, MODEL_o119, false)
        Call(EnableModel, MODEL_o120, false)
        Call(EnableModel, MODEL_o121, false)
        Call(EnableModel, MODEL_o122, false)
        Call(EnableModel, MODEL_o123, false)
        Call(EnableModel, MODEL_o124, false)
        Call(EnableModel, MODEL_o100, false)
        Call(EnableModel, MODEL_o99, false)
        Call(EnableModel, MODEL_o125, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o131, COLLIDER_FLAGS_UPPER_MASK)
        Return
    EndIf
    Exec(N(EVS_AnimateMachineLightning))
    Call(EnableModel, MODEL_o101, false)
    IfGe(GB_FLO18_MachineDamage_Left, 1)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o115, false)
        Call(EnableModel, MODEL_o116, false)
    EndIf
    IfGe(GB_FLO18_MachineDamage_Right, 1)
        Call(EnableModel, MODEL_o117, false)
        Call(EnableModel, MODEL_o118, false)
    EndIf
    IfGe(GB_FLO18_MachineDamage_Left, 2)
        Call(EnableModel, MODEL_o119, false)
    EndIf
    IfGe(GB_FLO18_MachineDamage_Right, 2)
        Call(EnableModel, MODEL_o120, false)
        Call(EnableModel, MODEL_o121, false)
        Call(EnableModel, MODEL_o122, false)
        Call(EnableModel, MODEL_o123, false)
        Call(EnableModel, MODEL_o124, false)
    EndIf
    IfGe(GB_FLO18_MachineDamage_Right, 3)
        Call(EnableModel, MODEL_o100, false)
        Call(EnableModel, MODEL_o99, false)
        Call(EnableModel, MODEL_o125, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o131, COLLIDER_FLAGS_UPPER_MASK)
        Return
    EndIf
    Set(LVar0, DAMAGE_PART_LEFT_SIDE)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o174, 1, 0)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, Ref(N(Machine_BombTrigger_01)), 1, 0)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, Ref(N(Machine_BombTrigger_02)), 1, 0)
    Set(LVar0, DAMAGE_PART_RIGHT_SIDE)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o127, 1, 0)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, Ref(N(Machine_BombTrigger_03)), 1, 0)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, Ref(N(Machine_BombTrigger_04)), 1, 0)
    Set(LVar0, DAMAGE_PART_LEVER)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o130, 1, 0)
    Set(LVar0, DAMAGE_PART_SMOKE_STACK)
    BindTrigger(Ref(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o131, 1, 0)
    Set(LVar0, 0)
    Loop(16)
        Set(LVar1, LVar0)
        Add(LVar1, CLONED_MODEL(0))
        Add(LVar0, 1)
        Call(CloneModel, MODEL_o101, LVar1)
        Call(EnableModel, LVar1, false)
    EndLoop
    Exec(N(EVS_ManageSmoke))
    Call(EnableTexPanning, MODEL_o92, true)
    Call(EnableTexPanning, MODEL_o93, true)
    Call(EnableTexPanning, MODEL_o94, true)
    Call(EnableTexPanning, MODEL_o95, true)
    Call(EnableTexPanning, MODEL_o91, true)
    Call(EnableTexPanning, MODEL_o99, true)
    Thread
        SetF(LVarE, Float(1.0))
        Label(0)
        IfGe(GB_FLO18_MachineDamage_Right, 3)
            MulF(LVarE, Float(0.953))
        EndIf
        AddF(LVarF, LVarE)
        IfEq(LVarF, 1080)
            SetF(LVarF, 0)
        EndIf
        Set(LVar0, LVarF)
        Div(LVar0, 9)
        Mod(LVar0, 4)
        Mul(LVar0, 0x4000)
        Set(LVar1, LVarF)
        Div(LVar1, 4)
        Mod(LVar1, 2)
        Mul(LVar1, 0x4000)
        Set(LVar2, LVarF)
        Div(LVar2, 5)
        Mod(LVar2, 2)
        Mul(LVar2, 0x4000)
        Set(LVar3, LVarF)
        Div(LVar3, 6)
        Mod(LVar3, 2)
        Mul(LVar3, 0x4000)
        Set(LVar4, LVarF)
        Div(LVar4, 2)
        Mod(LVar4, 2)
        Mul(LVar4, 0x8000)
        Set(LVar5, LVarF)
        Div(LVar5, 8)
        Mod(LVar5, 2)
        Mul(LVar5, 0x4000)
        Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar1, 0)
        Call(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar2, 0)
        Call(SetTexPanOffset, TEX_PANNER_F, TEX_PANNER_MAIN, LVar3, 0)
        Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, LVar4, 0)
        Call(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_MAIN, LVar5, 0)
        Call(SetTexPanOffset, TEX_PANNER_9, TEX_PANNER_MAIN, LVar5, 0)
        Wait(1)
        Goto(0)
    EndThread
    Return
    End
};
