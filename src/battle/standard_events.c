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
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_LOOP(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, 6, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, 4, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, 3, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, 2, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, -3, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, -4, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, -6, 0)
        EVT_WAIT(1)
        EVT_WAIT(1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 3, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 2, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -3, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -6, 0)
    EVT_WAIT(1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar3)
    EVT_RETURN
    EVT_END
};

// Partner actions during 'Run Away'
// (in) LVar0: part idx
// (in) LVar1: run animID
EvtScript EVS_Partner_RunAway = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_WAIT(5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, -250, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

// Partner reaction to touching a fiery enemy
// (in) LVar1: burn loop animID
// (in) LVar2: rotation y-offset
// (in) LVar3: burn still animID
EvtScript EVS_Partner_BurnContact = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LVar1, LVarA)
    EVT_SET(LVar2, LVarC)
    EVT_EXEC_WAIT(EVS_Partner_BurnHit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

// Partner reaction to touching a spiky enemy
// (in) LVar1: hurt still animID
// (in) LVar2: rotation y-offset
EvtScript EVS_Partner_SpikeContact = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LVar1, LVarA)
    EVT_SET(LVar2, 0)
    EVT_EXEC_WAIT(EVS_Partner_Hit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

// Bombette-specific reaction to touching a spiky enemy
// (in) LVar1: hurt loop animID
// (in) LVar2: rotation y-offset
// (in) LVar3: injured animID
EvtScript EVS_Partner_BombetteSpikeContact = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LVar1, LVarA)
    EVT_SET(LVar2, 0)
    EVT_EXEC_WAIT(EVS_Partner_Hit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

// Partner reaction to being hit by a shocking attack
// (in) LVar1: hurt loop animID
// (in) LVar2: rotation y-offset
EvtScript EVS_Partner_ShockHit = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_CALL(ShowShockEffect, ACTOR_SELF)
    EVT_SET(LVar1, LVarA)
    EVT_SET(LVar2, 0)
    EVT_EXEC_WAIT(EVS_Partner_Hit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

// Unused partner reaction to being hit by a shocking attack
// Only difference is a new arg on LVar3 which sets an anim for 1 frame twice at the end
// (in) LVar1: hurt loop animID
// (in) LVar2: rotation y-offset
// (in) LVar3: jolt animID (?)
EvtScript EVS_Partner_UnusedShockHit = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_CALL(ShowShockEffect, ACTOR_SELF)
    EVT_SET(LVar1, LVarA)
    EVT_SET(LVar2, 0)
    EVT_EXEC_WAIT(EVS_Partner_Hit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LVarB, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarC)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

// Partner gets up from being KO
// (in) LVar0: part idx? (unused)
// (in) LVar1: idle animID
// (in) LVar2: run animID
// (in) LVar3: idle y-pos
EvtScript EVS_Partner_Recover = {
    EVT_SET(LVar6, LVar3)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar7, LVar8, LVar9)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
    EVT_IF_EQ(LVar6, 0)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar7, LVar6, LVar9)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar7, LVar6, LVar9)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    EVT_END_IF
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar1)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_RETURN
    EVT_END
};

// Partner falls down if y > 0
// (in) LVar1: hurt animID
EvtScript EVS_Partner_Drop = {
    EVT_SET(LVarA, LVar1)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(func_8026F1A0, ACTOR_PARTNER, 1)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
        EVT_WAIT(8)
    EVT_LABEL(10)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 0, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

// Partner reaction to being hit by a fiery attack
// (in) LVar1: burn hurt loop animID
// (in) LVar2: burn hurt end animID
EvtScript EVS_Partner_BurnHit = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar1)
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar5, LVar6, LVar7)
        EVT_ADD(LVar5, -5)
        EVT_ADD(LVar6, 18)
        EVT_ADD(LVar7, 5)
        EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.5), 15)
        EVT_WAIT(2)
        EVT_ADD(LVar5, 10)
        EVT_ADD(LVar6, -14)
        EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.5), 15)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(DAMAGE_INTENSITY_LIGHT)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_MEDIUM)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_HEAVY)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_HEAVY)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_EXTREME)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_EXTREME)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

// Internal script for animating a partner hit by an attack
// (in) LVar1: hurt loop animID
EvtScript EVS_Partner_Hit_Impl = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar1)
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(DAMAGE_INTENSITY_LIGHT)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_MEDIUM)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_HEAVY)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_HEAVY)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_EXTREME)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_EXTREME)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

// Internal script for animating a partner hit by a crushing attack
EvtScript EVS_Partner_Crushed_Impl = {
    EVT_CALL(StartRumble, BTL_RUMBLE_HIT_MAX)
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_SETF(LVar1, EVT_FLOAT(1.0))
    EVT_LOOP(10)
        EVT_ADDF(LVar0, EVT_FLOAT(0.1))
        EVT_SUBF(LVar1, EVT_FLOAT(0.08))
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar1, EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(45)
    EVT_LOOP(5)
        EVT_SUBF(LVar0, EVT_FLOAT(0.22))
        EVT_ADDF(LVar1, EVT_FLOAT(0.2))
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar1, EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

// Lakilester-specific reaction to being hit by an attack
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Partner_LakilesterHit = {
    EVT_CALL(GetDamageSource, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(DMG_SRC_DEFAULT)
            EVT_EXEC_WAIT(EVS_Partner_Hit_Impl)
        EVT_CASE_OR_EQ(DMG_SRC_CRUSH)
        EVT_CASE_OR_EQ(DMG_SRC_TUBBA_SMASH)
        EVT_CASE_OR_EQ(DMG_SRC_CRUSH_PARTNER)
            EVT_EXEC_WAIT(EVS_Partner_Crushed_Impl)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(EVS_Partner_Hit_Impl)
    EVT_END_SWITCH
    EVT_IF_NE(LVar2, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// Partner reaction to being hit by an attack
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Partner_Hit = {
    EVT_EXEC_WAIT(EVS_Partner_Hit_Impl)
    EVT_IF_NE(LVar2, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// Partner reaction to being hit by an attack dealing no damage
// (in) LVar0: part idx
// (in) LVar1: hurt loop animID
EvtScript EVS_Partner_NoDamageHit = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(AddActorPos, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, -4, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 4, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, -3, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 3, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, -1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 1, 0, 0)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

// Internal script for animating player hit by an attack
// (in) LVar0: damage intensity (unused)
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID (unused)
EvtScript EVS_Player_Hit_Impl = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar1)
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(DAMAGE_INTENSITY_LIGHT)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_MEDIUM)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_LIGHT)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_HEAVY)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_HEAVY)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(DAMAGE_INTENSITY_EXTREME)
            EVT_CALL(StartRumble, BTL_RUMBLE_HIT_EXTREME)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(10)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Player_Crushed_Impl = {
    EVT_CALL(StartRumble, BTL_RUMBLE_HIT_MAX)
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_SETF(LVar1, EVT_FLOAT(1.0))
    EVT_LOOP(10)
        EVT_ADDF(LVar0, EVT_FLOAT(0.1))
        EVT_SUBF(LVar1, EVT_FLOAT(0.08))
        EVT_CALL(SetActorScale, ACTOR_PLAYER, LVar0, LVar1, EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(45)
    EVT_LOOP(5)
        EVT_SUBF(LVar0, EVT_FLOAT(0.22))
        EVT_ADDF(LVar1, EVT_FLOAT(0.2))
        EVT_CALL(SetActorScale, ACTOR_PLAYER, LVar0, LVar1, EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Player_NextSlapRight_Impl = {
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Player_NextSlapLeft_Impl = {
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, -36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Player_LastSlapRight_Impl = {
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 0, 2160, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
    EVT_WAIT(40)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Player_LastSlapLeft_Impl = {
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 2160, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
    EVT_WAIT(40)
    EVT_RETURN
    EVT_END
};

// Player reaction to being hit by an attack, handling different damage sources
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Player_ComplexHit = {
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetDamageSource, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(DMG_SRC_LEECH)
            EVT_WAIT(1000)
            EVT_RETURN
        EVT_CASE_EQ(DMG_SRC_DEFAULT)
            EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
        EVT_CASE_OR_EQ(DMG_SRC_CRUSH)
        EVT_CASE_OR_EQ(DMG_SRC_TUBBA_SMASH)
        EVT_CASE_OR_EQ(DMG_SRC_CRUSH_PARTNER)
            EVT_EXEC_WAIT(EVS_Player_Crushed_Impl)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
            EVT_EXEC_WAIT(EVS_Player_NextSlapRight_Impl)
        EVT_CASE_EQ(DMG_SRC_NEXT_SLAP_LEFT)
            EVT_EXEC_WAIT(EVS_Player_NextSlapLeft_Impl)
        EVT_CASE_EQ(DMG_SRC_LAST_SLAP_RIGHT)
            EVT_EXEC_WAIT(EVS_Player_LastSlapRight_Impl)
        EVT_CASE_EQ(DMG_SRC_LAST_SLAP_LEFT)
            EVT_EXEC_WAIT(EVS_Player_LastSlapLeft_Impl)
        EVT_CASE_EQ(DMG_SRC_INK_BLAST)
            EVT_SET(LVar1, ANIM_MarioB3_BurnHurt)
            EVT_SET(LVar2, ANIM_Mario1_Burnt)
            EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar2)
            EVT_WAIT(15)
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
    EVT_END_SWITCH
    EVT_IF_NE(LVar2, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// Player reaction to being hit which ignores damage source
// (in) LVar1: hurt loop animID
// (in) LVar2: hurt end animID
EvtScript EVS_Player_SimpleHit = {
    EVT_EXEC_WAIT(EVS_Player_Hit_Impl)
    EVT_IF_NE(LVar2, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// Player reaction to being hit by an attack dealing no damage
// (in) LVar0: part idx
// (in) LVar1: hurt loop animID
EvtScript EVS_Player_NoDamageHit = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar1)
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -4, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(GetDamageSource, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(DMG_SRC_TUTORIAL_GOOMBARIO)
            EVT_WAIT(15)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ForceNextTarget = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_IF_NE(LVar0, LVarA)
            EVT_CALL(GetOriginalActorType, LVar0, LVar2)
            EVT_IF_NE(LVar2, ACTOR_TYPE_DRY_BONES)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_IF_NE(LVar0, LVarA)
            EVT_CALL(GetActorVar, LVar0, 8, LVar3)
            EVT_IF_NE(LVar3, 1)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_FanSmack_Impl = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FAN_SMACK_HIT)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
    EVT_DIVF(LVar3, EVT_FLOAT(40.0))
    EVT_IF_LT(LVar3, 1)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
    EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
        EVT_MULF(LVar3, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar6)
    EVT_IF_FLAG(LVar6, ACTOR_FLAG_UPSIDE_DOWN)
        EVT_CALL(GetActorSize, ACTOR_SELF, LVar7, LVar8)
        EVT_SUB(LVar1, LVar7)
    EVT_END_IF
    EVT_SUB(LVar1, 3)
    EVT_PLAY_EFFECT(EFFECT_WHIRLWIND, 0, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(GetDamageSource, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
            EVT_WAIT(10)
            EVT_CALL(RemoveEffect, LVarF)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
            EVT_WAIT(40)
            EVT_CALL(DismissEffect, LVarF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FAN_SMACK_END)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_Hit = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetDamageSource, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(DMG_SRC_POWER_SHELL)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar5)
            EVT_SWITCH(LVar5)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LVar1, 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LVar5, 0)
            EVT_LOOP(30)
                EVT_ADD(LVar5, 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar5)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar7)
            EVT_SWITCH(LVar7)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LVar1, 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
            EVT_IF_EQ(LVar2, DMG_SRC_NEXT_FAN_SMACK_LEFT)
                EVT_EXEC(EVS_Enemy_FanSmack_Impl)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(EVS_Enemy_Hit_Impl)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
            EVT_IF_EQ(LVar2, DMG_SRC_LAST_FAN_SMACK_LEFT)
                EVT_EXEC(EVS_Enemy_FanSmack_Impl)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 0, 0x00000870, 60, EASING_COS_IN_OUT)
                EVT_LABEL(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(EVS_Enemy_Hit_Impl)
            EVT_WAIT(60)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
            EVT_IF_EQ(LVar2, DMG_SRC_NEXT_FAN_SMACK_RIGHT)
                EVT_EXEC(EVS_Enemy_FanSmack_Impl)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_SET(LVar0, 360)
                EVT_LOOP(10)
                    EVT_SUB(LVar0, 36)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(EVS_Enemy_Hit_Impl)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
            EVT_IF_EQ(LVar2, DMG_SRC_LAST_FAN_SMACK_RIGHT)
                EVT_EXEC(EVS_Enemy_FanSmack_Impl)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 0x00000870, 0, 60, EASING_COS_IN_OUT)
                EVT_LABEL(1)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(EVS_Enemy_Hit_Impl)
            EVT_WAIT(60)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(DMG_SRC_SPOOK)
            EVT_SET(LVar0, DAMAGE_INTENSITY_EXTREME)
            EVT_EXEC_WAIT(EVS_Enemy_Hit_Impl)
        EVT_CASE_EQ(DMG_SRC_SPIN_SMASH)
            EVT_EXEC_GET_TID(EVS_Enemy_SpinAround_Impl, LVarE)
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(EVS_Enemy_Hit_Impl)
            EVT_LABEL(2)
                EVT_CALL(GetActorRotation, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_MOD(LVar1, 360)
                EVT_IF_NE(LVar1, 0)
                    EVT_WAIT(1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_KILL_THREAD(LVarE)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(EVS_Enemy_Hit_Impl)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

// Enemy shakes in reaction to being hit
// (in) LVar0: damage intensity
EvtScript EVS_Enemy_Hit_Impl = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_BurnHit = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, EVENT_BURN_DEATH)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetDamageSource, LVar3)
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(DMG_SRC_FIRE_SHELL)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar7)
            EVT_SWITCH(LVar7)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LVar5, 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LVar7, 0)
            EVT_LOOP(30)
                EVT_ADD(LVar7, 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar7)
            EVT_SWITCH(LVar7)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LVar5, 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LVar5, 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_IF_NE(LVar2, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetPartEventFlags, ACTOR_SELF, LVar0, LVar1)
            EVT_IF_NOT_FLAG(LVar1, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION | ACTOR_EVENT_FLAG_FIREY)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_MULF(LVar3, EVT_FLOAT(0.4))
                    EVT_MULF(LVar4, EVT_FLOAT(0.4))
                EVT_END_IF
                EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                EVT_CALL(GetActorFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, ACTOR_FLAG_UPSIDE_DOWN)
                    EVT_SUBF(LVar1, LVar3)
                EVT_ELSE
                    EVT_ADDF(LVar1, LVar3)
                EVT_END_IF
                EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_MULF(LVar3, EVT_FLOAT(0.4))
                    EVT_IF_LT(LVar3, 1)
                        EVT_SETF(LVar3, EVT_FLOAT(1.0))
                    EVT_END_IF
                EVT_END_IF
                EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_ShockHit = {
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_EXEC_WAIT(EVS_Enemy_ShockHit_Impl)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_ShockHit_Impl = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
    EVT_SETF(LVar5, LVar3)
    EVT_DIVF(LVar5, EVT_FLOAT(20.0))
    EVT_ADDF(LVar1, LVar5)
    EVT_PLAY_EFFECT(EFFECT_FLASHING_BOX_SHOCKWAVE, 0, LVar0, LVar1, LVar2, LVar4, LVar3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_SHOCK)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(ShowHealthBar, ACTOR_SELF)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 1, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 3, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 3, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 12, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -8, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -8, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 12, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, 6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, ACTOR_SELF, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -6, 0)
    EVT_WAIT(1)
    EVT_LOOP(6)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, 2, 0)
        EVT_CALL(AddEffectOffset, LVarF, 0, 2, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, ACTOR_SELF, 0, -2, 0)
        EVT_CALL(AddEffectOffset, LVarF, 0, -2, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(5)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, EVENT_SHOCK_DEATH)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// Enemy reaction to being hit by an attack dealing no damage
// (in) LVar0: part idx
// (in) LVar1: hurt loop animID
EvtScript EVS_Enemy_NoDamageHit = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_NOT_FLAG(LVar2, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -4, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_Death = {
    EVT_EXEC_WAIT(EVS_Enemy_DeathWithoutRemove)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

// in LVar2: if set to EXEC_DEATH_NO_SPINNING, the actor will not spin around
EvtScript EVS_Enemy_DeathWithoutRemove = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(GetDamageSource, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar1)
            EVT_SWITCH(LVar1)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOB_OMB)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BULLET_BILL)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BILL)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_NE(LVar2, EXEC_DEATH_NO_SPINNING) // special signal value
                EVT_SET(LVar2, 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                    EVT_ADD(LVar2, 30)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 10)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_ScareAway = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar9)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.05))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SET(LVarD, LVarB)
    EVT_ADD(LVarD, 20)
    EVT_IF_NOT_FLAG(LVar9, ACTOR_FLAG_FLYING)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarD, LVarC)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 3, FALSE, FALSE, FALSE)
        EVT_WAIT(20)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
        EVT_CALL(FallToGoal, ACTOR_SELF, 7)
    EVT_ELSE
        EVT_WAIT(15)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(17)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT(3)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_ADD(LVarA, 300)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_SpinSmash_HitNext = {
    EVT_CALL(CreateCurrentPosTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_ALLOW_TARGET_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerID, LVar1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_IF_NE(LVar1, LVar0)
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_LABEL(1)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_EQ(LVar0, ITER_NO_MORE)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_CALL(GetActorFlags, LVar0, LVar1)
        EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetStatusFlags, LVar0, LVar9)
        EVT_IF_FLAG(LVar9, STATUS_FLAG_TRANSPARENT)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        EVT_CHILD_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_END_CHILD_THREAD
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar1)
        EVT_SWITCH(LVar1)
            EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY)
            EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY_MUMMY)
            EVT_CASE_OR_EQ(ACTOR_TYPE_UNUSED_69)
                EVT_CALL(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
                EVT_GOTO(1)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_GOTO(1)
    // done
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_WAIT(20)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 296, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_SpinAround_Impl = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_SUB(LVar0, 30)
        EVT_IF_LT(LVar0, 0)
            EVT_ADD(LVar0, 360)
        EVT_END_IF
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_SpinSmash_ShakeCam = {
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar1)
    EVT_MUL(LVar0, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(1000)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.3))
            EVT_END_CHILD_THREAD
        EVT_CASE_LT(2000)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.6))
            EVT_END_CHILD_THREAD
        EVT_CASE_DEFAULT
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.9))
            EVT_END_CHILD_THREAD
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_SpinSmashHit = {
    EVT_EXEC_GET_TID(EVS_Enemy_SpinAround_Impl, LVarE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, LVar0, LVarA)
    EVT_EXEC_WAIT(EVS_Enemy_SpinSmash_HitNext)
    EVT_CALL(SetActorPos, ACTOR_SELF, -200, 30, 0)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.4))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(AddGoalPos, ACTOR_SELF, -30, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_EXEC(EVS_Enemy_SpinSmash_ShakeCam)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_EXEC(EVS_Enemy_SpinSmash_ShakeCam)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_EXEC(EVS_Enemy_SpinSmash_ShakeCam)
    EVT_WAIT(15)
    EVT_LABEL(0)
        EVT_CALL(GetActorRotation, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_MOD(LVar1, 360)
        EVT_IF_NE(LVar1, 0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_KILL_THREAD(LVarE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_FlipBackUp = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LOOP(5)
        EVT_ADD(LVar0, 30)
        EVT_ADD(LVar1, 4)
        EVT_ADD(LVar2, -2)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar2, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarC)
    EVT_SET(LVar2, -10)
    EVT_LOOP(5)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar2, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_Knockback = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_ReturnHome = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    EVT_CALL(GetDist2D, LVar9, LVarA, LVarC, LVarD, LVarF)
    EVT_IF_GE(LVar9, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_Recover = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// (in) LVar0: part idx
// (in) LVar1: hopping animID
EvtScript EVS_Enemy_HopHome = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_RETURN
    EVT_END
};

// (in) LVar0: target posX
// (in) LVar1: target posY
// (in) LVar2: target posZ
EvtScript EVS_Enemy_HopToPos = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_LABEL(0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_IF_EQ(LVar3, LVar0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_LT(LVar3, LVar0)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_IF_LT(LVar4, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_ELSE
                EVT_SET(LVar4, LVar3)
                EVT_ADD(LVar3, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVar4, LVar3)
            EVT_SUB(LVar4, LVar0)
            EVT_IF_LT(LVar4, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_ELSE
                EVT_SUB(LVar3, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EVT_END_IF
        EVT_END_IF
        EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_AirLift = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_NOT_FLAG(LVar2, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LVar0, EVT_FLOAT(2.0))
        EVT_LOOP(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar6, LVar7)
            EVT_ADD(LVar4, LVar6)
            EVT_PLAY_EFFECT(EFFECT_SWEAT, 0, LVar3, LVar4, LVar5, 5, -45, 20)
            EVT_WAIT(10)
        EVT_END_LOOP
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LVar0, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Enemy_BlowAway = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
    EVT_IF_NOT_FLAG(LVar5, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_ELSE
        EVT_SET(LFlag0, FALSE)
        EVT_IF_FLAG(LVar2, STATUS_FLAG_SLEEP)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SLEEP)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_STATIC)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_STATIC)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_FROZEN)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_FROZEN)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_FEAR)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_FEAR)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_PARALYZE)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_PARALYZE)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_POISON)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_POISON)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_DIZZY)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_DIZZY)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_STONE)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_STONE)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_KO)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_KO)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_WAIT(1000)
    EVT_RETURN
    EVT_END
};
