#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/player.h"

extern EvtScript EVS_Enemy_Hit_Impl;
extern EvtScript EVS_Enemy_SpinAround_Impl;

API_CALLABLE(GetDamageIntensity) {
    if (gBattleStatus.lastAttackDamage < 4) {
        script->varTable[0] = DAMAGE_INTENSITY_LIGHT;
    } else if (gBattleStatus.lastAttackDamage < 7) {
        script->varTable[0] = DAMAGE_INTENSITY_MEDIUM;
    } else if (gBattleStatus.lastAttackDamage < 10) {
        script->varTable[0] = DAMAGE_INTENSITY_HEAVY;
    } else {
        script->varTable[0] = DAMAGE_INTENSITY_EXTREME;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(AddEffectOffset) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.flashingBoxShockwave->pos.x += evt_get_variable(script, *args++);
    effect->data.flashingBoxShockwave->pos.y += evt_get_variable(script, *args++);
    effect->data.flashingBoxShockwave->pos.z += evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

// Partner actions during end-of-battle celebration
// (in) LVar0: partIdx
// (in) LVar1: celebration loop animID
// (in) LVar2: celebration end animID
// (in) LVar3: idle animID
EvtScript EVS_Partner_Celebrate = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Loop(2)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Call(AddActorPos, ACTOR_SELF, 0, 6, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, 4, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, 3, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, 2, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, 1, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, -1, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, -2, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, -3, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, -4, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, -6, 0)
        Wait(1)
        Wait(1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar2)
        Wait(1)
    EndLoop
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(AddActorPos, ACTOR_SELF, 0, 6, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 4, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 3, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 2, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 1, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -2, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -3, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -4, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -6, 0)
    Wait(1)
    Wait(1)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar3)
    Return
    End
};

// Partner actions during 'Run Away'
// (in) LVar0: part idx
// (in) LVar1: run animID
EvtScript EVS_Partner_RunAway = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Wait(10)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Wait(5)
    Call(SetActorSpeed, ACTOR_SELF, Float(12.0))
    Call(SetGoalPos, ACTOR_PARTNER, -250, 0, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

// Partner reaction to touching a fiery enemy
// (in) LVar1: burn loop animID
// (in) LVar2: rotation y-offset
// (in) LVar3: burn still animID
EvtScript EVS_Partner_BurnContact = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Set(LVarC, LVar3)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_HIT_HAZARD)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Add(LVar1, 40)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.1))
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    Set(LVar1, LVarA)
    Set(LVar2, LVarC)
    ExecWait(EVS_Partner_BurnHit)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ChildThread
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 48)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EndChildThread
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Sub(LVar0, 10)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Return
    End
};

// Partner reaction to touching a spiky enemy
// (in) LVar1: hurt still animID
// (in) LVar2: rotation y-offset
EvtScript EVS_Partner_SpikeContact = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_HIT_SPIKE)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Add(LVar1, 40)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.1))
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    Set(LVar1, LVarA)
    Set(LVar2, 0)
    ExecWait(EVS_Partner_Hit)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ChildThread
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 48)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EndChildThread
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Sub(LVar0, 10)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Return
    End
};

// Bombette-specific reaction to touching a spiky enemy
// (in) LVar1: hurt loop animID
// (in) LVar2: rotation y-offset
// (in) LVar3: injured animID
EvtScript EVS_Partner_BombetteSpikeContact = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Set(LVarC, LVar3)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_HIT_SPIKE)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Add(LVar1, 40)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.1))
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    Set(LVar1, LVarA)
    Set(LVar2, 0)
    ExecWait(EVS_Partner_Hit)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ChildThread
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 48)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EndChildThread
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Sub(LVar0, 10)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Return
    End
};

// Partner reaction to being hit by a shocking attack
// (in) LVar1: hurt loop animID
// (in) LVar2: rotation y-offset
EvtScript EVS_Partner_ShockHit = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_HIT_HAZARD)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Add(LVar1, 40)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.1))
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    Call(ShowShockEffect, ACTOR_SELF)
    Set(LVar1, LVarA)
    Set(LVar2, 0)
    ExecWait(EVS_Partner_Hit)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ChildThread
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 48)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EndChildThread
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Sub(LVar0, 10)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Return
    End
};

// Unused partner reaction to being hit by a shocking attack
// Only difference is a new arg on LVar3 which sets an anim for 1 frame twice at the end
// (in) LVar1: hurt loop animID
// (in) LVar2: rotation y-offset
// (in) LVar3: jolt animID (?)
EvtScript EVS_Partner_UnusedShockHit = {
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Set(LVarC, LVar3)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_HIT_HAZARD)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Add(LVar1, 40)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.1))
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    Call(ShowShockEffect, ACTOR_SELF)
    Set(LVar1, LVarA)
    Set(LVar2, 0)
    ExecWait(EVS_Partner_Hit)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ChildThread
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 48)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EndChildThread
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Sub(LVar0, 10)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Return
    End
};

// Partner gets up from being KO
// (in) LVar0: part idx? (unused)
// (in) LVar1: idle animID
// (in) LVar2: run animID
// (in) LVar3: idle y-pos
EvtScript EVS_Partner_Recover = {
    Set(LVar6, LVar3)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.8))
    Call(GetActorPos, ACTOR_PARTNER, LVar7, LVar8, LVar9)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVar2)
    IfEq(LVar6, 0)
        Call(SetGoalPos, ACTOR_PARTNER, LVar7, LVar6, LVar9)
        Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Else
        Call(SetGoalPos, ACTOR_PARTNER, LVar7, LVar6, LVar9)
        Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    EndIf
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, LVar1)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Return
    End
};

// Partner falls down if y > 0
// (in) LVar1: hurt animID
EvtScript EVS_Partner_Drop = {
    Set(LVarA, LVar1)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    IfEq(LVar1, 0)
        Goto(10)
    EndIf
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(func_8026F1A0, ACTOR_PARTNER, 1)
        Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
        Wait(8)
    Label(10)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_LANDING_DUST, 0, LVar0, LVar1, LVar2)
    Return
    End
};

// Partner reaction to being hit by a fiery attack
// (in) LVar1: burn hurt loop animID
// (in) LVar2: burn hurt end animID
EvtScript EVS_Partner_BurnHit = {
    Call(SetAnimation, ACTOR_PARTNER, -1, LVar1)
    ChildThread
        Call(GetActorPos, ACTOR_PARTNER, LVar5, LVar6, LVar7)
        Add(LVar5, -5)
        Add(LVar6, 18)
        Add(LVar7, 5)
        PlayEffect(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, Float(1.5), 15)
        Wait(2)
        Add(LVar5, 10)
        Add(LVar6, -14)
        PlayEffect(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, Float(1.5), 15)
    EndChildThread
    Call(GetDamageIntensity)
    Switch(LVar0)
        CaseEq(DAMAGE_INTENSITY_LIGHT)
            Call(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(4)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_MEDIUM)
            Call(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_HEAVY)
            Call(StartRumble, BTL_RUMBLE_HIT_HEAVY)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_EXTREME)
            Call(StartRumble, BTL_RUMBLE_HIT_EXTREME)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
    EndSwitch
    Call(SetAnimation, ACTOR_PARTNER, -1, LVar2)
    Wait(8)
    Return
    End
};

// Internal script for animating a partner hit by an attack
// (in) LVar1: hurt loop animID
EvtScript EVS_Partner_Hit_Impl = {
    Call(SetAnimation, ACTOR_PARTNER, -1, LVar1)
    Call(GetDamageIntensity)
    Switch(LVar0)
        CaseEq(DAMAGE_INTENSITY_LIGHT)
            Call(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(4)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_MEDIUM)
            Call(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_HEAVY)
            Call(StartRumble, BTL_RUMBLE_HIT_HEAVY)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_EXTREME)
            Call(StartRumble, BTL_RUMBLE_HIT_EXTREME)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
    EndSwitch
    Return
    End
};

// Internal script for animating a partner hit by a crushing attack
EvtScript EVS_Partner_Crushed_Impl = {
    Call(StartRumble, BTL_RUMBLE_HIT_MAX)
    SetF(LVar0, Float(1.0))
    SetF(LVar1, Float(1.0))
    Loop(10)
        AddF(LVar0, Float(0.1))
        SubF(LVar1, Float(0.08))
        Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar1, Float(1.0))
        Wait(1)
    EndLoop
    Wait(45)
    Loop(5)
        SubF(LVar0, Float(0.22))
        AddF(LVar1, Float(0.2))
        Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar1, Float(1.0))
        Wait(1)
    EndLoop
    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    Return
    End
};

// Lakilester-specific reaction to being hit by an attack
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Partner_LakilesterHit = {
    Call(GetDamageSource, LVar0)
    Switch(LVar0)
        CaseEq(DMG_SRC_DEFAULT)
            ExecWait(EVS_Partner_Hit_Impl)
        CaseOrEq(DMG_SRC_CRUSH)
        CaseOrEq(DMG_SRC_TUBBA_SMASH)
        CaseOrEq(DMG_SRC_CRUSH_PARTNER)
            ExecWait(EVS_Partner_Crushed_Impl)
        EndCaseGroup
        CaseDefault
            ExecWait(EVS_Partner_Hit_Impl)
    EndSwitch
    IfNe(LVar2, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, LVar2)
        Wait(8)
    EndIf
    Return
    End
};

// Partner reaction to being hit by an attack
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Partner_Hit = {
    ExecWait(EVS_Partner_Hit_Impl)
    IfNe(LVar2, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, LVar2)
        Wait(8)
    EndIf
    Return
    End
};

// Partner reaction to being hit by an attack dealing no damage
// (in) LVar0: part idx
// (in) LVar1: hurt loop animID
EvtScript EVS_Partner_NoDamageHit = {
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(AddActorPos, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 2, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, -4, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 4, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 2, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, -3, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 3, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 2, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, -1, 0, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 1, 0, 0)
    Wait(1)
    Return
    End
};

// Internal script for animating player hit by an attack
// (in) LVar0: damage intensity (unused)
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID (unused)
EvtScript EVS_Player_Hit_Impl = {
    Call(SetAnimation, ACTOR_PLAYER, 0, LVar1)
    Call(GetDamageIntensity)
    Switch(LVar0)
        CaseEq(DAMAGE_INTENSITY_LIGHT)
            Call(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(4)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_MEDIUM)
            Call(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_HEAVY)
            Call(StartRumble, BTL_RUMBLE_HIT_HEAVY)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_EXTREME)
            Call(StartRumble, BTL_RUMBLE_HIT_EXTREME)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Wait(10)
    EndSwitch
    Return
    End
};

EvtScript EVS_Player_Crushed_Impl = {
    Call(StartRumble, BTL_RUMBLE_HIT_MAX)
    SetF(LVar0, Float(1.0))
    SetF(LVar1, Float(1.0))
    Loop(10)
        AddF(LVar0, Float(0.1))
        SubF(LVar1, Float(0.08))
        Call(SetActorScale, ACTOR_PLAYER, LVar0, LVar1, Float(1.0))
        Wait(1)
    EndLoop
    Wait(45)
    Loop(5)
        SubF(LVar0, Float(0.22))
        AddF(LVar1, Float(0.2))
        Call(SetActorScale, ACTOR_PLAYER, LVar0, LVar1, Float(1.0))
        Wait(1)
    EndLoop
    Call(SetActorScale, ACTOR_PLAYER, Float(1.0), Float(1.0), Float(1.0))
    Return
    End
};

EvtScript EVS_Player_NextSlapRight_Impl = {
    ChildThread
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 36)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
        EndLoop
    EndChildThread
    Call(GetDamageIntensity)
    ExecWait(EVS_Player_Hit_Impl)
    Return
    End
};

EvtScript EVS_Player_NextSlapLeft_Impl = {
    ChildThread
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, -36)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
        EndLoop
    EndChildThread
    Call(GetDamageIntensity)
    ExecWait(EVS_Player_Hit_Impl)
    Return
    End
};

EvtScript EVS_Player_LastSlapRight_Impl = {
    ChildThread
        Call(MakeLerp, 0, 2160, 60, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndChildThread
    Call(GetDamageIntensity)
    ExecWait(EVS_Player_Hit_Impl)
    Wait(40)
    Return
    End
};

EvtScript EVS_Player_LastSlapLeft_Impl = {
    ChildThread
        Call(MakeLerp, 2160, 0, 60, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndChildThread
    Call(GetDamageIntensity)
    ExecWait(EVS_Player_Hit_Impl)
    Wait(40)
    Return
    End
};

// Player reaction to being hit by an attack, handling different damage sources
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Player_ComplexHit = {
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(GetDamageSource, LVar0)
    Switch(LVar0)
        CaseEq(DMG_SRC_LEECH)
            Wait(1000)
            Return
        CaseEq(DMG_SRC_DEFAULT)
            ExecWait(EVS_Player_Hit_Impl)
        CaseOrEq(DMG_SRC_CRUSH)
        CaseOrEq(DMG_SRC_TUBBA_SMASH)
        CaseOrEq(DMG_SRC_CRUSH_PARTNER)
            ExecWait(EVS_Player_Crushed_Impl)
        EndCaseGroup
        CaseEq(DMG_SRC_NEXT_SLAP_RIGHT)
            ExecWait(EVS_Player_NextSlapRight_Impl)
        CaseEq(DMG_SRC_NEXT_SLAP_LEFT)
            ExecWait(EVS_Player_NextSlapLeft_Impl)
        CaseEq(DMG_SRC_LAST_SLAP_RIGHT)
            ExecWait(EVS_Player_LastSlapRight_Impl)
        CaseEq(DMG_SRC_LAST_SLAP_LEFT)
            ExecWait(EVS_Player_LastSlapLeft_Impl)
        CaseEq(DMG_SRC_INK_BLAST)
            Set(LVar1, ANIM_MarioB3_BurnHurt)
            Set(LVar2, ANIM_Mario1_Burnt)
            ExecWait(EVS_Player_Hit_Impl)
            Call(SetAnimation, ACTOR_PLAYER, 0, LVar2)
            Wait(15)
        CaseDefault
            ExecWait(EVS_Player_Hit_Impl)
    EndSwitch
    IfNe(LVar2, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, LVar2)
        Wait(8)
    EndIf
    Return
    End
};

// Player reaction to being hit which ignores damage source
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Player_SimpleHit = {
    ExecWait(EVS_Player_Hit_Impl)
    IfNe(LVar2, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, LVar2)
        Wait(8)
    EndIf
    Return
    End
};

// Player reaction to being hit by an attack dealing no damage
// (in) LVar0: part idx
// (in) LVar1: hurt loop animID
EvtScript EVS_Player_NoDamageHit = {
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Call(SetAnimation, ACTOR_PLAYER, 0, LVar1)
    EndIf
    Call(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -4, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -3, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(GetDamageSource, LVar0)
    Switch(LVar0)
        CaseEq(DMG_SRC_TUTORIAL_GOOMBARIO)
            Wait(15)
    EndSwitch
    Return
    End
};

EvtScript EVS_ForceNextTarget = {
    Call(GetOwnerID, LVarA)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        IfNe(LVar0, LVarA)
            Call(GetOriginalActorType, LVar0, LVar2)
            IfNe(LVar2, ACTOR_TYPE_DRY_BONES)
                Return
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        IfNe(LVar0, LVarA)
            Call(GetActorVar, LVar0, 8, LVar3)
            IfNe(LVar3, 1)
                Return
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(2)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(2)
        EndIf
    Return
    End
};

EvtScript EVS_Enemy_FanSmack_Impl = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FAN_SMACK_HIT)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
    DivF(LVar3, Float(40.0))
    IfLt(LVar3, 1)
        SetF(LVar3, Float(1.0))
    EndIf
    Call(GetStatusFlags, ACTOR_SELF, LVar5)
    IfFlag(LVar5, STATUS_FLAG_SHRINK)
        MulF(LVar3, Float(0.4))
    EndIf
    Call(GetActorFlags, ACTOR_SELF, LVar6)
    IfFlag(LVar6, ACTOR_FLAG_UPSIDE_DOWN)
        Call(GetActorSize, ACTOR_SELF, LVar7, LVar8)
        Sub(LVar1, LVar7)
    EndIf
    Sub(LVar1, 3)
    PlayEffect(EFFECT_WHIRLWIND, 0, LVar0, LVar1, LVar2, LVar3)
    Call(GetDamageSource, LVar0)
    Switch(LVar0)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
            Wait(10)
            Call(RemoveEffect, LVarF)
        EndCaseGroup
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
            Wait(40)
            Call(DismissEffect, LVarF)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FAN_SMACK_END)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript EVS_Enemy_Hit = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetDamageSource, LVar2)
    Switch(LVar2)
        CaseEq(DMG_SRC_POWER_SHELL)
            Call(GetOriginalActorType, ACTOR_SELF, LVar5)
            Switch(LVar5)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EndCaseGroup
                CaseDefault
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
                    Add(LVar1, 55)
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EndSwitch
            Set(LVar5, 0)
            Loop(30)
                Add(LVar5, 48)
                Call(SetActorYaw, ACTOR_SELF, LVar5)
                Wait(1)
            EndLoop
            Call(GetOriginalActorType, ACTOR_SELF, LVar7)
            Switch(LVar7)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    Wait(30)
                EndCaseGroup
                CaseDefault
                    Sub(LVar1, 55)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
                    IfEq(LVar1, 0)
                        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    Else
                        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EndIf
            EndSwitch
        CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
            IfEq(LVar2, DMG_SRC_NEXT_FAN_SMACK_LEFT)
                Exec(EVS_Enemy_FanSmack_Impl)
            EndIf
            ChildThread
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 36)
                    Call(SetActorYaw, ACTOR_SELF, LVar0)
                    Wait(1)
                EndLoop
            EndChildThread
            Call(GetDamageIntensity)
            ExecWait(EVS_Enemy_Hit_Impl)
        EndCaseGroup
        CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
            IfEq(LVar2, DMG_SRC_LAST_FAN_SMACK_LEFT)
                Exec(EVS_Enemy_FanSmack_Impl)
            EndIf
            ChildThread
                Call(MakeLerp, 0, 0x00000870, 60, EASING_COS_IN_OUT)
                Label(0)
                Call(UpdateLerp)
                Call(SetActorYaw, ACTOR_SELF, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(0)
                EndIf
            EndChildThread
            Call(GetDamageIntensity)
            ExecWait(EVS_Enemy_Hit_Impl)
            Wait(60)
        EndCaseGroup
        CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
            IfEq(LVar2, DMG_SRC_NEXT_FAN_SMACK_RIGHT)
                Exec(EVS_Enemy_FanSmack_Impl)
            EndIf
            ChildThread
                Set(LVar0, 360)
                Loop(10)
                    Sub(LVar0, 36)
                    Call(SetActorYaw, ACTOR_SELF, LVar0)
                    Wait(1)
                EndLoop
            EndChildThread
            Call(GetDamageIntensity)
            ExecWait(EVS_Enemy_Hit_Impl)
        EndCaseGroup
        CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
            IfEq(LVar2, DMG_SRC_LAST_FAN_SMACK_RIGHT)
                Exec(EVS_Enemy_FanSmack_Impl)
            EndIf
            ChildThread
                Call(MakeLerp, 0x00000870, 0, 60, EASING_COS_IN_OUT)
                Label(1)
                Call(UpdateLerp)
                Call(SetActorYaw, ACTOR_SELF, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(1)
                EndIf
            EndChildThread
            Call(GetDamageIntensity)
            ExecWait(EVS_Enemy_Hit_Impl)
            Wait(60)
        EndCaseGroup
        CaseEq(DMG_SRC_SPOOK)
            Set(LVar0, DAMAGE_INTENSITY_EXTREME)
            ExecWait(EVS_Enemy_Hit_Impl)
        CaseEq(DMG_SRC_SPIN_SMASH)
            ExecGetTID(EVS_Enemy_SpinAround_Impl, LVarE)
            Call(GetDamageIntensity)
            ExecWait(EVS_Enemy_Hit_Impl)
            Label(2)
                Call(GetActorRotation, ACTOR_SELF, LVar0, LVar1, LVar2)
                Mod(LVar1, 360)
                IfNe(LVar1, 0)
                    Wait(1)
                    Goto(2)
                EndIf
            KillThread(LVarE)
            Call(SetActorYaw, ACTOR_SELF, 0)
        CaseDefault
            Call(GetDamageIntensity)
            ExecWait(EVS_Enemy_Hit_Impl)
    EndSwitch
    Return
    End
};

// Enemy shakes in reaction to being hit
// (in) LVar0: damage intensity
EvtScript EVS_Enemy_Hit_Impl = {
    Switch(LVar0)
        CaseEq(0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(4)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        CaseEq(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        CaseEq(2)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        CaseEq(3)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            Wait(1)
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(2)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                Wait(1)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EndSwitch
    Return
    End
};

EvtScript EVS_Enemy_BurnHit = {
    Call(GetLastEvent, ACTOR_SELF, LVar3)
    IfEq(LVar3, EVENT_BURN_DEATH)
        Call(EnableActorGlow, ACTOR_SELF, FALSE)
    EndIf
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetDamageSource, LVar3)
    Switch(LVar3)
        CaseEq(DMG_SRC_FIRE_SHELL)
            Call(GetOriginalActorType, ACTOR_SELF, LVar7)
            Switch(LVar7)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EndCaseGroup
                CaseDefault
                    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
                    Add(LVar5, 55)
                    Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EndSwitch
            Set(LVar7, 0)
            Loop(30)
                Add(LVar7, 48)
                Call(SetActorYaw, ACTOR_SELF, LVar7)
                Wait(1)
            EndLoop
            Call(GetOriginalActorType, ACTOR_SELF, LVar7)
            Switch(LVar7)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    Wait(30)
                EndCaseGroup
                CaseDefault
                    Sub(LVar5, 55)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
                    IfEq(LVar5, 0)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    Else
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EndIf
            EndSwitch
        CaseDefault
            Wait(20)
    EndSwitch
    IfNe(LVar2, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    EndIf
    Wait(10)
    Call(GetLastEvent, ACTOR_SELF, LVar1)
    Switch(LVar1)
        CaseEq(EVENT_BURN_HIT)
            Call(GetPartEventFlags, ACTOR_SELF, LVar0, LVar1)
            IfNotFlag(LVar1, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION | ACTOR_EVENT_FLAG_FIREY)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                Call(GetStatusFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, STATUS_FLAG_SHRINK)
                    MulF(LVar3, Float(0.4))
                    MulF(LVar4, Float(0.4))
                EndIf
                DivF(LVar3, Float(2.0))
                Call(GetActorFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, ACTOR_FLAG_UPSIDE_DOWN)
                    SubF(LVar1, LVar3)
                Else
                    AddF(LVar1, LVar3)
                EndIf
                AddF(LVar2, Float(5.0))
                DivF(LVar3, Float(10.0))
                Call(GetStatusFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, STATUS_FLAG_SHRINK)
                    MulF(LVar3, Float(0.4))
                    IfLt(LVar3, 1)
                        SetF(LVar3, Float(1.0))
                    EndIf
                EndIf
                PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10)
            EndIf
        CaseEq(EVENT_BURN_DEATH)
    EndSwitch
    Return
    End
};

EvtScript EVS_Enemy_ShockHit = {
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    ExecWait(EVS_Enemy_ShockHit_Impl)
    Return
    End
};

EvtScript EVS_Enemy_ShockHit_Impl = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
    SetF(LVar5, LVar3)
    DivF(LVar5, Float(20.0))
    AddF(LVar1, LVar5)
    PlayEffect(EFFECT_FLASHING_BOX_SHOCKWAVE, FX_SHOCK_OVERLAY_SHOCK_HIT, LVar0, LVar1, LVar2, LVar4, LVar3)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_SHOCK)
    Call(HideHealthBar, ACTOR_SELF)
    Call(HPBarToCurrent, ACTOR_SELF)
    Call(ShowHealthBar, ACTOR_SELF)
    Call(AddActorPos, ACTOR_SELF, 0, 1, 0)
    Call(AddEffectOffset, LVarF, 0, 1, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 3, 0)
    Call(AddEffectOffset, LVarF, 0, 3, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 12, 0)
    Call(AddEffectOffset, LVarF, 0, 12, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -8, 0)
    Call(AddEffectOffset, LVarF, 0, -8, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 12, 0)
    Call(AddEffectOffset, LVarF, 0, 12, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -4, 0)
    Call(AddEffectOffset, LVarF, 0, -4, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -4, 0)
    Call(AddEffectOffset, LVarF, 0, -4, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -6, 0)
    Call(AddEffectOffset, LVarF, 0, -6, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -6, 0)
    Call(AddEffectOffset, LVarF, 0, -6, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, 6, 0)
    Call(AddEffectOffset, LVarF, 0, 6, 0)
    Wait(1)
    Call(AddActorPos, ACTOR_SELF, 0, -6, 0)
    Call(AddEffectOffset, LVarF, 0, -6, 0)
    Wait(1)
    Loop(6)
        Call(AddActorPos, ACTOR_SELF, 0, 2, 0)
        Call(AddEffectOffset, LVarF, 0, 2, 0)
        Wait(1)
        Call(AddActorPos, ACTOR_SELF, 0, -2, 0)
        Call(AddEffectOffset, LVarF, 0, -2, 0)
        Wait(1)
    EndLoop
    Wait(5)
    Call(HideHealthBar, ACTOR_SELF)
    Call(HPBarToHome, ACTOR_SELF)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    IfNe(LVar0, EVENT_SHOCK_DEATH)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EndIf
    Return
    End
};

// Enemy reaction to being hit by an attack dealing no damage
// (in) LVar0: part idx
// (in) LVar1: hurt loop animID
EvtScript EVS_Enemy_NoDamageHit = {
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(GetStatusFlags, ACTOR_SELF, LVar2)
    IfNotFlag(LVar2, STATUS_FLAGS_IMMOBILIZED)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EndIf
    Call(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -4, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -3, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(1)
    Return
    End
};

EvtScript EVS_Enemy_Death = {
    ExecWait(EVS_Enemy_DeathWithoutRemove)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ExecWait(EVS_ForceNextTarget)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

// in LVar2: if set to EXEC_DEATH_NO_SPINNING, the actor will not spin around
EvtScript EVS_Enemy_DeathWithoutRemove = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableActorGlow, ACTOR_SELF, FALSE)
    IfNe(LVar1, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Wait(10)
    EndIf
    Call(GetDamageSource, LVar5)
    Switch(LVar5)
        CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_SPIN_SMASH)
        EndCaseGroup
        CaseDefault
            Set(LFlag0, FALSE)
            Call(GetOriginalActorType, ACTOR_SELF, LVar1)
            Switch(LVar1)
                CaseOrEq(ACTOR_TYPE_BOB_OMB)
                CaseOrEq(ACTOR_TYPE_BULLET_BILL)
                CaseOrEq(ACTOR_TYPE_BOMBSHELL_BILL)
                EndCaseGroup
                CaseDefault
            EndSwitch
            IfNe(LVar2, EXEC_DEATH_NO_SPINNING) // special signal value
                Set(LVar2, 0)
                Loop(24)
                    Call(SetActorYaw, ACTOR_SELF, LVar2)
                    Add(LVar2, 30)
                    Wait(1)
                EndLoop
                Call(SetActorYaw, ACTOR_SELF, 0)
            EndIf
    EndSwitch
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Add(LVar2, 10)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Set(LVar3, 0)
    Loop(12)
        Call(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript EVS_Enemy_ScareAway = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    Call(GetActorFlags, ACTOR_SELF, LVar9)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.05))
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Set(LVarD, LVarB)
    Add(LVarD, 20)
    IfNotFlag(LVar9, ACTOR_FLAG_FLYING)
        Call(SetGoalPos, ACTOR_SELF, LVarA, LVarD, LVarC)
        Call(JumpToGoal, ACTOR_SELF, 3, FALSE, FALSE, FALSE)
        Wait(20)
        Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
        Call(EnableActorGlow, ACTOR_SELF, FALSE)
        Call(FallToGoal, ACTOR_SELF, 7)
    Else
        Wait(15)
        Call(EnableActorGlow, ACTOR_SELF, FALSE)
    EndIf
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Wait(17)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Wait(3)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
    Add(LVarA, 300)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    ExecWait(EVS_ForceNextTarget)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript EVS_Enemy_SpinSmash_HitNext = {
    Call(CreateCurrentPosTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_ALLOW_TARGET_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerID, LVar1)
        Call(GetOwnerTarget, LVar0, LVar9)
        IfNe(LVar1, LVar0)
            Call(ChooseNextTarget, ITER_NEXT, LVar0)
            Goto(0)
        EndIf
    Label(1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfEq(LVar0, ITER_NO_MORE)
            Goto(10)
        EndIf
        Call(GetOwnerTarget, LVar0, LVar9)
        Call(GetActorFlags, LVar0, LVar1)
        IfFlag(LVar1, ACTOR_FLAG_TARGET_ONLY)
            Goto(1)
        EndIf
        Call(GetStatusFlags, LVar0, LVar9)
        IfFlag(LVar9, STATUS_FLAG_TRANSPARENT)
            Goto(1)
        EndIf
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
        Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
        Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        ChildThread
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        EndChildThread
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar1)
        Switch(LVar1)
            CaseOrEq(ACTOR_TYPE_POKEY)
            CaseOrEq(ACTOR_TYPE_POKEY_MUMMY)
            CaseOrEq(ACTOR_TYPE_UNUSED_69)
                Call(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
                Goto(1)
            EndCaseGroup
        EndSwitch
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
        Goto(1)
    // done
    Label(10)
    ChildThread
        Wait(20)
        Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
    EndChildThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalPos, ACTOR_SELF, 296, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    Return
    End
};

EvtScript EVS_Enemy_SpinAround_Impl = {
    Set(LVar0, 0)
    Label(0)
        Sub(LVar0, 30)
        IfLt(LVar0, 0)
            Add(LVar0, 360)
        EndIf
        Call(SetActorYaw, ACTOR_SELF, LVar0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript EVS_Enemy_SpinSmash_ShakeCam = {
    Call(GetActorSize, ACTOR_SELF, LVar0, LVar1)
    Mul(LVar0, LVar1)
    Switch(LVar0)
        CaseLt(1000)
            ChildThread
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.3))
            EndChildThread
        CaseLt(2000)
            ChildThread
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.6))
            EndChildThread
        CaseDefault
            ChildThread
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.9))
            EndChildThread
    EndSwitch
    Return
    End
};

EvtScript EVS_Enemy_SpinSmashHit = {
    ExecGetTID(EVS_Enemy_SpinAround_Impl, LVarE)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetPartEventFlags, ACTOR_SELF, LVar0, LVarA)
    ExecWait(EVS_Enemy_SpinSmash_HitNext)
    Call(SetActorPos, ACTOR_SELF, -200, 30, 0)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.4))
    Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
    Call(AddGoalPos, ACTOR_SELF, -30, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    Exec(EVS_Enemy_SpinSmash_ShakeCam)
    Call(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Exec(EVS_Enemy_SpinSmash_ShakeCam)
    Call(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    Exec(EVS_Enemy_SpinSmash_ShakeCam)
    Wait(15)
    Label(0)
        Call(GetActorRotation, ACTOR_SELF, LVar0, LVar1, LVar2)
        Mod(LVar1, 360)
        IfNe(LVar1, 0)
            Wait(1)
            Goto(0)
        EndIf
    KillThread(LVarE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

EvtScript EVS_Enemy_FlipBackUp = {
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Call(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Loop(5)
        Add(LVar0, 30)
        Add(LVar1, 4)
        Add(LVar2, -2)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Call(SetActorDispOffset, ACTOR_SELF, LVar2, LVar1, 0)
        Wait(1)
    EndLoop
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, LVarA, LVarC)
    Set(LVar2, -10)
    Loop(5)
        Add(LVar2, 2)
        Call(SetActorDispOffset, ACTOR_SELF, LVar2, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript EVS_Enemy_Knockback = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
    Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(AddGoalPos, ACTOR_SELF, 15, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Call(AddGoalPos, ACTOR_SELF, 5, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Return
    End
};

EvtScript EVS_Enemy_ReturnHome = {
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    Call(GetDist2D, LVar9, LVarA, LVarC, LVarD, LVarF)
    IfGe(LVar9, Float(8.0))
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    EndIf
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

EvtScript EVS_Enemy_Recover = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(GetActorPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
    Else
        Call(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EndIf
    Return
    End
};

// (in) LVar0: part idx
// (in) LVar1: hopping animID
EvtScript EVS_Enemy_HopHome = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
    ExecWait(EVS_Enemy_HopToPos)
    Return
    End
};

// (in) LVar0: target posX
// (in) LVar1: target posY
// (in) LVar2: target posZ
EvtScript EVS_Enemy_HopToPos = {
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Label(0)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        IfEq(LVar3, LVar0)
            Goto(10)
        EndIf
        IfLt(LVar3, LVar0)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            IfLt(LVar4, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Else
                Set(LVar4, LVar3)
                Add(LVar3, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EndIf
        Else
            Set(LVar4, LVar3)
            Sub(LVar4, LVar0)
            IfLt(LVar4, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Else
                Sub(LVar3, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EndIf
        EndIf
        Goto(0)
    Label(10)
    Return
    End
};

EvtScript EVS_Enemy_AirLift = {
    Call(GetStatusFlags, ACTOR_SELF, LVar2)
    IfNotFlag(LVar2, STATUS_FLAGS_IMMOBILIZED)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Call(SetAnimationRate, ACTOR_SELF, LVar0, Float(2.0))
        Loop(10)
            Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Call(GetActorSize, ACTOR_SELF, LVar6, LVar7)
            Add(LVar4, LVar6)
            PlayEffect(EFFECT_SWEAT, 0, LVar3, LVar4, LVar5, 5, -45, 20)
            Wait(10)
        EndLoop
        Call(SetAnimationRate, ACTOR_SELF, LVar0, Float(1.0))
    EndIf
    Return
    End
};

EvtScript EVS_Enemy_BlowAway = {
    Call(GetStatusFlags, ACTOR_SELF, LVar5)
    IfNotFlag(LVar5, STATUS_FLAGS_IMMOBILIZED)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Else
        Set(LFlag0, FALSE)
        IfFlag(LVar2, STATUS_FLAG_SLEEP)
            IfFlag(LVar5, STATUS_FLAG_SLEEP)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar2, STATUS_FLAG_STATIC)
            IfFlag(LVar5, STATUS_FLAG_STATIC)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar2, STATUS_FLAG_FROZEN)
            IfFlag(LVar5, STATUS_FLAG_FROZEN)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar2, STATUS_FLAG_FEAR)
            IfFlag(LVar5, STATUS_FLAG_FEAR)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar2, STATUS_FLAG_PARALYZE)
            IfFlag(LVar5, STATUS_FLAG_PARALYZE)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar2, STATUS_FLAG_POISON)
            IfFlag(LVar5, STATUS_FLAG_POISON)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar2, STATUS_FLAG_DIZZY)
            IfFlag(LVar5, STATUS_FLAG_DIZZY)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar5, STATUS_FLAG_SHRINK)
            Set(LFlag0, TRUE)
        EndIf
        IfFlag(LVar2, STATUS_FLAG_STONE)
            IfFlag(LVar5, STATUS_FLAG_STONE)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfFlag(LVar2, STATUS_FLAG_KO)
            IfFlag(LVar5, STATUS_FLAG_KO)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        IfEq(LFlag0, TRUE)
            Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EndIf
    EndIf
    ExecWait(EVS_ForceNextTarget)
    Wait(1000)
    Return
    End
};
