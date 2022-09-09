#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"

extern EvtScript D_80299828;
extern EvtScript D_8029B818;

ApiStatus GetDamageIntensity(Evt* script, s32 isInitialCall) {
    if (gBattleStatus.lastAttackDamage < 4) {
        script->varTable[0] = 0;
    } else if (gBattleStatus.lastAttackDamage < 7) {
        script->varTable[0] = 1;
    } else if (gBattleStatus.lastAttackDamage < 10) {
        script->varTable[0] = 2;
    } else {
        script->varTable[0] = 3;
    }
    return ApiStatus_DONE2;
}

ApiStatus AddEffectOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.flashingBoxShockwave->pos.x += evt_get_variable(script, *args++);
    effect->data.flashingBoxShockwave->pos.y += evt_get_variable(script, *args++);
    effect->data.flashingBoxShockwave->pos.z += evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

EvtScript D_80294720 = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_LOOP(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
        EVT_CALL(AddActorPos, -127, 0, 6, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, 4, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, 3, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, 2, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, 1, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, -1, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, -2, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, -3, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, -4, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, -6, 0)
        EVT_WAIT(1)
        EVT_WAIT(1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(2))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(AddActorPos, -127, 0, 6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 3, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 2, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -2, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -3, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_WAIT(1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(3))
    EVT_RETURN
    EVT_END
};

EvtScript D_80294AFC = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_WAIT(5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, -250, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80294C68 = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_SET(LocalVar(12), LocalVar(3))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 60)
    EVT_ADD(LocalVar(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LocalVar(10), LocalVar(10), LocalVar(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LocalVar(1), LocalVar(10))
    EVT_SET(LocalVar(2), LocalVar(12))
    EVT_EXEC_WAIT(D_8029621C)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LocalVar(11), 0)
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LocalVar(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 30)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LocalVar(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80294FE4 = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 60)
    EVT_ADD(LocalVar(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LocalVar(10), LocalVar(10), LocalVar(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LocalVar(1), LocalVar(10))
    EVT_SET(LocalVar(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LocalVar(11), 0)
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LocalVar(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 30)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LocalVar(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295350 = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_SET(LocalVar(12), LocalVar(3))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 60)
    EVT_ADD(LocalVar(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LocalVar(10), LocalVar(10), LocalVar(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LocalVar(1), LocalVar(10))
    EVT_SET(LocalVar(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LocalVar(11), 0)
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LocalVar(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 30)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(12))
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_SUB(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(12))
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_SUB(LocalVar(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295744 = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 60)
    EVT_ADD(LocalVar(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LocalVar(10), LocalVar(10), LocalVar(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_CALL(ShowShockEffect, -127)
    EVT_SET(LocalVar(1), LocalVar(10))
    EVT_SET(LocalVar(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LocalVar(11), 0)
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LocalVar(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 30)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LocalVar(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295AC0 = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_SET(LocalVar(11), LocalVar(2))
    EVT_SET(LocalVar(12), LocalVar(3))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 60)
    EVT_ADD(LocalVar(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LocalVar(10), LocalVar(10), LocalVar(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_CALL(ShowShockEffect, -127)
    EVT_SET(LocalVar(1), LocalVar(10))
    EVT_SET(LocalVar(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LocalVar(11), 0)
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LocalVar(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 30)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(12))
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_SUB(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(12))
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_SUB(LocalVar(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295EC4 = {
    EVT_SET(LocalVar(6), LocalVar(3))
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(7), LocalVar(8), LocalVar(9))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(2))
    EVT_IF_EQ(LocalVar(6), 000000)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(7), LocalVar(6), LocalVar(9))
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(7), LocalVar(6), LocalVar(9))
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    EVT_END_IF
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(1))
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_80296014 = {
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_IF_EQ(LocalVar(1), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(func_8026F1A0, 256, 1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(10))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
    EVT_WAIT(8)
    EVT_LABEL(10)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 0, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029621C = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(1))
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(5), LocalVar(6), LocalVar(7))
        EVT_ADD(LocalVar(5), -5)
        EVT_ADD(LocalVar(6), 18)
        EVT_ADD(LocalVar(7), 5)
        EVT_CALL(PlayEffect, EFFECT_RING_BLAST, 0, LocalVar(5), LocalVar(6), LocalVar(7), EVT_FLOAT(1.5), 15, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(2)
        EVT_ADD(LocalVar(5), 10)
        EVT_ADD(LocalVar(6), -14)
        EVT_CALL(PlayEffect, EFFECT_RING_BLAST, 0, LocalVar(5), LocalVar(6), LocalVar(7), EVT_FLOAT(1.5), 15, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(StartRumble, 3)
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
        EVT_CASE_EQ(1)
            EVT_CALL(StartRumble, 3)
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
        EVT_CASE_EQ(2)
            EVT_CALL(StartRumble, 4)
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
        EVT_CASE_EQ(3)
            EVT_CALL(StartRumble, 5)
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
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(2))
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

EvtScript D_80296C8C = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(1))
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(StartRumble, 3)
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
        EVT_CASE_EQ(1)
            EVT_CALL(StartRumble, 3)
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
        EVT_CASE_EQ(2)
            EVT_CALL(StartRumble, 4)
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
        EVT_CASE_EQ(3)
            EVT_CALL(StartRumble, 5)
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

EvtScript D_802975C8 = {
    EVT_CALL(StartRumble, 6)
    EVT_SETF(LocalVar(0), EVT_FLOAT(1.0))
    EVT_SETF(LocalVar(1), EVT_FLOAT(1.0))
    EVT_LOOP(10)
        EVT_ADDF(LocalVar(0), EVT_FLOAT(0.1))
        EVT_SUBF(LocalVar(1), EVT_FLOAT(0.08))
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LocalVar(0), LocalVar(1), EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(45)
    EVT_LOOP(5)
        EVT_SUBF(LocalVar(0), EVT_FLOAT(0.220703125))
        EVT_ADDF(LocalVar(1), EVT_FLOAT(0.2))
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LocalVar(0), LocalVar(1), EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript D_802976E8 = {
    EVT_CALL(func_80269E80, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(D_80296C8C)
        EVT_CASE_OR_EQ(24)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_EXEC_WAIT(D_802975C8)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(D_80296C8C)
    EVT_END_SWITCH
    EVT_IF_NE(LocalVar(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(2))
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_802977BC = {
    EVT_EXEC_WAIT(D_80296C8C)
    EVT_IF_NE(LocalVar(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LocalVar(2))
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80297814 = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(AddActorPos, -127, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, -4, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 4, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, -3, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 3, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, -1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 1, 0, 0)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript D_80297A38 = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LocalVar(1))
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(StartRumble, 3)
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
        EVT_CASE_EQ(1)
            EVT_CALL(StartRumble, 3)
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
        EVT_CASE_EQ(2)
            EVT_CALL(StartRumble, 4)
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
        EVT_CASE_EQ(3)
            EVT_CALL(StartRumble, 5)
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

EvtScript D_80298374 = {
    EVT_CALL(StartRumble, 6)
    EVT_SETF(LocalVar(0), EVT_FLOAT(1.0))
    EVT_SETF(LocalVar(1), EVT_FLOAT(1.0))
    EVT_LOOP(10)
        EVT_ADDF(LocalVar(0), EVT_FLOAT(0.1))
        EVT_SUBF(LocalVar(1), EVT_FLOAT(0.08))
        EVT_CALL(SetActorScale, ACTOR_PLAYER, LocalVar(0), LocalVar(1), EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(45)
    EVT_LOOP(5)
        EVT_SUBF(LocalVar(0), EVT_FLOAT(0.220703125))
        EVT_ADDF(LocalVar(1), EVT_FLOAT(0.2))
        EVT_CALL(SetActorScale, ACTOR_PLAYER, LocalVar(0), LocalVar(1), EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript D_80298494 = {
    EVT_CHILD_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LocalVar(0), 36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(D_80297A38)
    EVT_RETURN
    EVT_END
};

EvtScript D_80298520 = {
    EVT_CHILD_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LocalVar(0), -36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(D_80297A38)
    EVT_RETURN
    EVT_END
};

EvtScript D_802985AC = {
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 0, 2160, 60, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(D_80297A38)
    EVT_WAIT(40)
    EVT_RETURN
    EVT_END
};

EvtScript D_80298668 = {
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 2160, 0, 60, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(D_80297A38)
    EVT_WAIT(40)
    EVT_RETURN
    EVT_END
};

EvtScript D_80298724 = {
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(func_80269E80, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(1)
            EVT_WAIT(1000)
            EVT_RETURN
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(D_80297A38)
        EVT_CASE_OR_EQ(24)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_EXEC_WAIT(D_80298374)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(11)
            EVT_EXEC_WAIT(D_80298494)
        EVT_CASE_EQ(10)
            EVT_EXEC_WAIT(D_80298520)
        EVT_CASE_EQ(13)
            EVT_EXEC_WAIT(D_802985AC)
        EVT_CASE_EQ(12)
            EVT_EXEC_WAIT(D_80298668)
        EVT_CASE_EQ(26)
            EVT_SET(LocalVar(1), 327683)
            EVT_SET(LocalVar(2), 65583)
            EVT_EXEC_WAIT(D_80297A38)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LocalVar(2))
            EVT_WAIT(15)
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(D_80297A38)
    EVT_END_SWITCH
    EVT_IF_NE(LocalVar(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LocalVar(2))
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_802988F0 = {
    EVT_EXEC_WAIT(D_80297A38)
    EVT_IF_NE(LocalVar(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LocalVar(2))
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80298948 = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LocalVar(1))
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
    EVT_CALL(func_80269E80, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(5)
            EVT_WAIT(15)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript ForceNextTarget = {
    EVT_CALL(GetOwnerID, LocalVar(10))
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_IF_NE(LocalVar(0), LocalVar(10))
        EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(2))
        EVT_IF_NE(LocalVar(2), ACTOR_TYPE_DRY_BONES)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_IF_NE(LocalVar(0), LocalVar(10))
        EVT_CALL(GetActorVar, LocalVar(0), 8, LocalVar(3))
        EVT_IF_NE(LocalVar(3), 1)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(SetActorFlagBits, LocalVar(0), ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80298E20 = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2022)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetActorSize, ACTOR_SELF, LocalVar(3), LocalVar(4))
    EVT_DIVF(LocalVar(3), EVT_FLOAT(40.0))
    EVT_IF_LT(LocalVar(3), 1)
        EVT_SETF(LocalVar(3), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(5))
    EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_SHRINK)
        EVT_MULF(LocalVar(3), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LocalVar(6))
    EVT_IF_FLAG(LocalVar(6), ACTOR_FLAG_HP_OFFSET_BELOW)
        EVT_CALL(GetActorSize, ACTOR_SELF, LocalVar(7), LocalVar(8))
        EVT_SUB(LocalVar(1), LocalVar(7))
    EVT_END_IF
    EVT_SUB(LocalVar(1), 3)
    EVT_CALL(PlayEffect, EFFECT_WHIRLWIND, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3), 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(func_80269E80, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(15)
            EVT_WAIT(10)
            EVT_CALL(RemoveEffect, LocalVar(15))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(16)
        EVT_CASE_OR_EQ(17)
            EVT_WAIT(40)
            EVT_CALL(func_802D7B10, LocalVar(15))
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2023)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript DoNormalHit = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(func_80269E80, LocalVar(2))
    EVT_SWITCH(LocalVar(2))
        EVT_CASE_EQ(7)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LocalVar(5))
            EVT_SWITCH(LocalVar(5))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LocalVar(1), 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LocalVar(5), 0)
            EVT_LOOP(30)
                EVT_ADD(LocalVar(5), 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(5))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LocalVar(7))
            EVT_SWITCH(LocalVar(7))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LocalVar(1), 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LocalVar(1), 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
            EVT_IF_EQ(LocalVar(2), 14)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_SET(LocalVar(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LocalVar(0), 36)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(12)
        EVT_CASE_OR_EQ(16)
            EVT_IF_EQ(LocalVar(2), 16)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 0, 2160, 60, 10)
                EVT_LABEL(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
                EVT_WAIT(1)
                EVT_IF_EQ(LocalVar(1), 1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_WAIT(60)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(15)
            EVT_IF_EQ(LocalVar(2), 15)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_SET(LocalVar(0), 360)
                EVT_LOOP(10)
                    EVT_SUB(LocalVar(0), 36)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(13)
        EVT_CASE_OR_EQ(17)
            EVT_IF_EQ(LocalVar(2), 17)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 2160, 0, 60, 10)
                EVT_LABEL(1)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
                EVT_WAIT(1)
                EVT_IF_EQ(LocalVar(1), 1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_WAIT(60)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(18)
            EVT_SET(LocalVar(0), 3)
            EVT_EXEC_WAIT(D_80299828)
        EVT_CASE_EQ(2)
            EVT_EXEC_GET_TID(D_8029B818, LocalVar(14))
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_LABEL(2)
            EVT_CALL(GetActorRotation, -127, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_MOD(LocalVar(1), 360)
            EVT_IF_NE(LocalVar(1), 0)
                EVT_WAIT(1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_KILL_THREAD(LocalVar(14))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_80299828 = {
    EVT_SWITCH(LocalVar(0))
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

EvtScript DoBurnHit = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(3))
    EVT_IF_EQ(LocalVar(3), EVENT_BURN_DEATH)
        EVT_CALL(EnableActorGlow, -127, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(func_80269E80, LocalVar(3))
    EVT_SWITCH(LocalVar(3))
        EVT_CASE_EQ(9)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LocalVar(7))
            EVT_SWITCH(LocalVar(7))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LocalVar(5), 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LocalVar(7), 0)
            EVT_LOOP(30)
                EVT_ADD(LocalVar(7), 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(7))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LocalVar(7))
            EVT_SWITCH(LocalVar(7))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LocalVar(5), 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LocalVar(5), 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_IF_NE(LocalVar(2), -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(2))
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(1))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetPartEventFlags, -127, LocalVar(0), LocalVar(1))
            EVT_IF_NOT_FLAG(LocalVar(1), 0x00000202)
                EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(GetActorSize, ACTOR_SELF, LocalVar(3), LocalVar(4))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(5))
                EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_SHRINK)
                    EVT_MULF(LocalVar(3), EVT_FLOAT(0.4))
                    EVT_MULF(LocalVar(4), EVT_FLOAT(0.4))
                EVT_END_IF
                EVT_DIVF(LocalVar(3), EVT_FLOAT(2.0))
                EVT_CALL(GetActorFlags, ACTOR_SELF, LocalVar(5))
                EVT_IF_FLAG(LocalVar(5), ACTOR_FLAG_HP_OFFSET_BELOW)
                    EVT_SUBF(LocalVar(1), LocalVar(3))
                EVT_ELSE
                    EVT_ADDF(LocalVar(1), LocalVar(3))
                EVT_END_IF
                EVT_ADDF(LocalVar(2), EVT_FLOAT(5.0))
                EVT_DIVF(LocalVar(3), EVT_FLOAT(10.0))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(5))
                EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_SHRINK)
                    EVT_MULF(LocalVar(3), EVT_FLOAT(0.4))
                    EVT_IF_LT(LocalVar(3), 1)
                        EVT_SETF(LocalVar(3), EVT_FLOAT(1.0))
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3), 10, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript DoShockHit = {
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_EXEC_WAIT(D_8029A76C)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029A76C = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetActorSize, ACTOR_SELF, LocalVar(3), LocalVar(4))
    EVT_SETF(LocalVar(5), LocalVar(3))
    EVT_DIVF(LocalVar(5), EVT_FLOAT(20.0))
    EVT_ADDF(LocalVar(1), LocalVar(5))
    EVT_CALL(PlayEffect, EFFECT_FLASHING_BOX_SHOCKWAVE, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(4), LocalVar(3), 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_SHOCK)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(func_8027D2D8, -127)
    EVT_CALL(AddActorPos, -127, 0, 1, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 3, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, 3, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, 12, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -8, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, -8, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, 12, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, -6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, -6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 6, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, 6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LocalVar(15), 0, -6, 0)
    EVT_WAIT(1)
    EVT_LOOP(6)
        EVT_CALL(AddActorPos, -127, 0, 2, 0)
        EVT_CALL(AddEffectOffset, LocalVar(15), 0, 2, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, -2, 0)
        EVT_CALL(AddEffectOffset, LocalVar(15), 0, -2, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(5)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_IF_NE(LocalVar(0), EVENT_SHOCK_DEATH)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript DoImmune = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(2))
    EVT_IF_NOT_FLAG(LocalVar(2), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
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

EvtScript DoDeath = {
    EVT_EXEC_WAIT(D_8029AF08)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029AF08 = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableActorGlow, -127, 0)
    EVT_IF_NE(LocalVar(1), -00001)
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(func_80269E80, LocalVar(5))
    EVT_SWITCH(LocalVar(5))
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(12)
        EVT_CASE_OR_EQ(16)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(15)
        EVT_CASE_OR_EQ(13)
        EVT_CASE_OR_EQ(17)
        EVT_CASE_OR_EQ(2)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LocalFlag(0), 0)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LocalVar(1))
            EVT_SWITCH(LocalVar(1))
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOB_OMB)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BULLET_BILL)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BILL)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_NE(LocalVar(2), STATUS_FLAG_1 | 0x00000002 | 0x00000004 | 0x00000040 | 0x00000080 | 0x00000100 | 0x00000200 | 0x00000400 | 0x00000800 | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_POISON | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP | 0x00400000 | 0x00800000 | STATUS_FLAG_KO | STATUS_FLAG_GLOWING | STATUS_FLAG_TRANSPARENT | STATUS_FLAG_ATTACK_BOOST | STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_CHILL_OUT | STATUS_FLAG_RIGHT_ON | 0x80000000)
                EVT_SET(LocalVar(2), 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(2))
                    EVT_ADD(LocalVar(2), 30)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 10)
    EVT_ADD(LocalVar(2), 10)
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LocalVar(3), 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LocalVar(3), 0, 0)
        EVT_ADD(LocalVar(3), 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript DoScareAway = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(2))
    EVT_CALL(GetActorFlags, ACTOR_SELF, LocalVar(9))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.05))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(10), LocalVar(11), LocalVar(12))
    EVT_SET(LocalVar(13), LocalVar(11))
    EVT_ADD(LocalVar(13), 20)
    EVT_IF_NOT_FLAG(LocalVar(9), ACTOR_FLAG_FLYING)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(10), LocalVar(13), LocalVar(12))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 3, FALSE, FALSE, FALSE)
        EVT_WAIT(20)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(10), LocalVar(11), LocalVar(12))
        EVT_CALL(EnableActorGlow, -127, 0)
        EVT_CALL(FallToGoal, -127, 7)
    EVT_ELSE
        EVT_WAIT(15)
        EVT_CALL(EnableActorGlow, -127, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_WAIT(17)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT(3)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_ADD(LocalVar(10), 300)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(10), LocalVar(11), LocalVar(12))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029B494 = {
    EVT_CALL(PlayerCreateTargetList, 65540)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LocalVar(1))
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(9))
    EVT_IF_NE(LocalVar(1), LocalVar(0))
        EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(9))
    EVT_CALL(GetActorFlags, LocalVar(0), LocalVar(1))
    EVT_IF_FLAG(LocalVar(1), ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetStatusFlags, LocalVar(0), LocalVar(9))
    EVT_IF_FLAG(LocalVar(9), STATUS_FLAG_TRANSPARENT)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), 0, LocalVar(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(1))
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY_MUMMY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_UNUSED_69)
            EVT_CALL(DispatchDamageEvent, LocalVar(0), 1, 17)
            EVT_GOTO(1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_WAIT(20)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 296, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029B818 = {
    EVT_SET(LocalVar(0), 0)
    EVT_LABEL(0)
    EVT_SUB(LocalVar(0), 30)
    EVT_IF_LT(LocalVar(0), 0)
        EVT_ADD(LocalVar(0), 360)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(0))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029B8A8 = {
    EVT_CALL(GetActorSize, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_MUL(LocalVar(0), LocalVar(1))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_LT(1000)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.3))
            EVT_END_CHILD_THREAD
        EVT_CASE_LT(2000)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.6))
            EVT_END_CHILD_THREAD
        EVT_CASE_DEFAULT
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.9))
            EVT_END_CHILD_THREAD
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript DoSpinSmashHit = {
    EVT_EXEC_GET_TID(D_8029B818, LocalVar(14))
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(GetPartEventFlags, -127, LocalVar(0), LocalVar(10))
    EVT_EXEC_WAIT(D_8029B494)
    EVT_CALL(SetActorPos, ACTOR_SELF, -200, 30, 0)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.4))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(AddGoalPos, ACTOR_SELF, -30, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_EXEC(D_8029B8A8)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_EXEC(D_8029B8A8)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_EXEC(D_8029B8A8)
    EVT_WAIT(15)
    EVT_LABEL(0)
    EVT_CALL(GetActorRotation, -127, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_MOD(LocalVar(1), 360)
    EVT_IF_NE(LocalVar(1), 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(LocalVar(14))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029BBB4 = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(11), LocalVar(1))
    EVT_SET(LocalVar(12), LocalVar(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(10), LocalVar(11))
    EVT_SET(LocalVar(0), 0)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), 0)
    EVT_LOOP(5)
        EVT_ADD(LocalVar(0), 30)
        EVT_ADD(LocalVar(1), 4)
        EVT_ADD(LocalVar(2), -2)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LocalVar(0))
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LocalVar(2), LocalVar(1), 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(10), LocalVar(12))
    EVT_SET(LocalVar(2), -10)
    EVT_LOOP(5)
        EVT_ADD(LocalVar(2), 2)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LocalVar(2), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript DoJumpBack = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
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

EvtScript DoReturnHome = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(10), LocalVar(11), LocalVar(12))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(13), LocalVar(14), LocalVar(15))
    EVT_CALL(GetDist2D, LocalVar(9), LocalVar(10), LocalVar(12), LocalVar(13), LocalVar(15))
    EVT_IF_GE(LocalVar(9), EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript DoRecover = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(7), LocalVar(8), LocalVar(9))
    EVT_CALL(GetActorFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), ACTOR_FLAG_FLYING)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(7), LocalVar(8), LocalVar(9))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(7), LocalVar(8), LocalVar(9))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_8029C0A4 = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029C12C = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_IF_EQ(LocalVar(3), LocalVar(0))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_LT(LocalVar(3), LocalVar(0))
        EVT_SET(LocalVar(4), LocalVar(0))
        EVT_SUB(LocalVar(4), LocalVar(3))
        EVT_IF_LT(LocalVar(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_ELSE
            EVT_SET(LocalVar(4), LocalVar(3))
            EVT_ADD(LocalVar(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(3), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LocalVar(4), LocalVar(3))
        EVT_SUB(LocalVar(4), LocalVar(0))
        EVT_IF_LT(LocalVar(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_ELSE
            EVT_SUB(LocalVar(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(3), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};

EvtScript DoAirLift = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(2))
    EVT_IF_NOT_FLAG(LocalVar(2), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LocalVar(0), EVT_FLOAT(2.0))
        EVT_LOOP(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(3), LocalVar(4), LocalVar(5))
            EVT_CALL(GetActorSize, ACTOR_SELF, LocalVar(6), LocalVar(7))
            EVT_ADD(LocalVar(4), LocalVar(6))
            EVT_CALL(PlayEffect, EFFECT_SWEAT, 0, LocalVar(3), LocalVar(4), LocalVar(5), 5, -45, 20, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LocalVar(0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript DoBlowAway = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(5))
    EVT_IF_NOT_FLAG(LocalVar(5), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_ELSE
        EVT_SET(LocalFlag(0), 0)
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_SLEEP)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_SLEEP)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_STATIC)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_STATIC)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_FROZEN)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_FROZEN)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_FEAR)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_FEAR)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_PARALYZE)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_PARALYZE)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_POISON)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_POISON)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_DIZZY)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_DIZZY)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_SHRINK)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_STONE)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_STONE)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LocalVar(2), STATUS_FLAG_KO)
            EVT_IF_FLAG(LocalVar(5), STATUS_FLAG_KO)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_WAIT(1000)
    EVT_RETURN
    EVT_END
};
