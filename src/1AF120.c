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

    ((EffectInstanceData*)effect->data)->pos.x += evt_get_variable(script, *args++);
    ((EffectInstanceData*)effect->data)->pos.y += evt_get_variable(script, *args++);
    ((EffectInstanceData*)effect->data)->pos.z += evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

EvtScript D_80294720 = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_LOOP(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_CALL(AddActorPos, -127, 0, 6, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, 4, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, 3, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, 2, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, -2, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, -3, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, -4, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, -6, 0)
        EVT_WAIT_FRAMES(1)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(AddActorPos, -127, 0, 6, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 4, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 3, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 2, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -2, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -3, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_WAIT_FRAMES(1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(3))
    EVT_RETURN
    EVT_END
};

EvtScript D_80294AFC = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, -250, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80294C68 = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_SET(LW(12), LW(3))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 60)
    EVT_ADD(LW(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LW(10), LW(10), LW(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LW(1), LW(10))
    EVT_SET(LW(2), LW(12))
    EVT_EXEC_WAIT(D_8029621C)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LW(11), 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LW(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80294FE4 = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 60)
    EVT_ADD(LW(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LW(10), LW(10), LW(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LW(1), LW(10))
    EVT_SET(LW(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LW(11), 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LW(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295350 = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_SET(LW(12), LW(3))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 60)
    EVT_ADD(LW(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LW(10), LW(10), LW(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_SET(LW(1), LW(10))
    EVT_SET(LW(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LW(11), 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LW(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(12))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(12))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295744 = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 60)
    EVT_ADD(LW(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LW(10), LW(10), LW(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_CALL(ShowShockEffect, -127)
    EVT_SET(LW(1), LW(10))
    EVT_SET(LW(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LW(11), 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LW(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295AC0 = {
    EVT_SET(LW(10), LW(1))
    EVT_SET(LW(11), LW(2))
    EVT_SET(LW(12), LW(3))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_62)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 60)
    EVT_ADD(LW(1), 40)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, LW(10), LW(10), LW(10))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
    EVT_CALL(ShowShockEffect, -127)
    EVT_SET(LW(1), LW(10))
    EVT_SET(LW(2), 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, LW(11), 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LW(0), 48)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(12))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(12))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80295EC4 = {
    EVT_SET(LW(6), LW(3))
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(7), LW(8), LW(9))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(2))
    EVT_IF_EQ(LW(6), 000000)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(7), LW(6), LW(9))
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(7), LW(6), LW(9))
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    EVT_END_IF
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(1))
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_80296014 = {
    EVT_SET(LW(10), LW(1))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_IF_EQ(LW(1), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(func_8026F1A0, 256, 1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(10))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(8)
    EVT_LABEL(10)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(PlayEffect, EFFECT_ID_06, 0, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029621C = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(1))
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(5), LW(6), LW(7))
        EVT_ADD(LW(5), -5)
        EVT_ADD(LW(6), 18)
        EVT_ADD(LW(7), 5)
        EVT_CALL(PlayEffect, EFFECT_ID_24, 0, LW(5), LW(6), LW(7), EVT_FLOAT(1.5), 15, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_ADD(LW(5), 10)
        EVT_ADD(LW(6), -14)
        EVT_CALL(PlayEffect, EFFECT_ID_24, 0, LW(5), LW(6), LW(7), EVT_FLOAT(1.5), 15, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(StartRumble, 3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(1)
            EVT_CALL(StartRumble, 3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(2)
            EVT_CALL(StartRumble, 4)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(3)
            EVT_CALL(StartRumble, 5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(2))
    EVT_WAIT_FRAMES(8)
    EVT_RETURN
    EVT_END
};

EvtScript D_80296C8C = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(1))
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(StartRumble, 3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(1)
            EVT_CALL(StartRumble, 3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(2)
            EVT_CALL(StartRumble, 4)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(3)
            EVT_CALL(StartRumble, 5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_802975C8 = {
    EVT_CALL(StartRumble, 6)
    EVT_SETF(LW(0), EVT_FLOAT(1.0))
    EVT_SETF(LW(1), EVT_FLOAT(1.0))
    EVT_LOOP(10)
        EVT_ADDF(LW(0), EVT_FLOAT(0.1))
        EVT_SUBF(LW(1), EVT_FLOAT(0.08))
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LW(0), LW(1), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(45)
    EVT_LOOP(5)
        EVT_SUBF(LW(0), EVT_FLOAT(0.220703125))
        EVT_ADDF(LW(1), EVT_FLOAT(0.2))
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LW(0), LW(1), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript D_802976E8 = {
    EVT_CALL(func_80269E80, LW(0))
    EVT_SWITCH(LW(0))
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
    EVT_IF_NE(LW(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(2))
        EVT_WAIT_FRAMES(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_802977BC = {
    EVT_EXEC_WAIT(D_80296C8C)
    EVT_IF_NE(LW(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LW(2))
        EVT_WAIT_FRAMES(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80297814 = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(AddActorPos, -127, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, -4, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 4, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, -3, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 3, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, -1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtScript D_80297A38 = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(1))
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(StartRumble, 3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(1)
            EVT_CALL(StartRumble, 3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(2)
            EVT_CALL(StartRumble, 4)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_EQ(3)
            EVT_CALL(StartRumble, 5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_80298374 = {
    EVT_CALL(StartRumble, 6)
    EVT_SETF(LW(0), EVT_FLOAT(1.0))
    EVT_SETF(LW(1), EVT_FLOAT(1.0))
    EVT_LOOP(10)
        EVT_ADDF(LW(0), EVT_FLOAT(0.1))
        EVT_SUBF(LW(1), EVT_FLOAT(0.08))
        EVT_CALL(SetActorScale, ACTOR_PLAYER, LW(0), LW(1), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(45)
    EVT_LOOP(5)
        EVT_SUBF(LW(0), EVT_FLOAT(0.220703125))
        EVT_ADDF(LW(1), EVT_FLOAT(0.2))
        EVT_CALL(SetActorScale, ACTOR_PLAYER, LW(0), LW(1), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript D_80298494 = {
    EVT_CHILD_THREAD
        EVT_SET(LW(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LW(0), 36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(D_80297A38)
    EVT_RETURN
    EVT_END
};

EvtScript D_80298520 = {
    EVT_CHILD_THREAD
        EVT_SET(LW(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LW(0), -36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
            EVT_WAIT_FRAMES(1)
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
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(D_80297A38)
    EVT_WAIT_FRAMES(40)
    EVT_RETURN
    EVT_END
};

EvtScript D_80298668 = {
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 2160, 0, 60, 10)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CALL(GetDamageIntensity)
    EVT_EXEC_WAIT(D_80297A38)
    EVT_WAIT_FRAMES(40)
    EVT_RETURN
    EVT_END
};

EvtScript D_80298724 = {
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(func_80269E80, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(1000)
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
            EVT_SET(LW(1), 327683)
            EVT_SET(LW(2), 65583)
            EVT_EXEC_WAIT(D_80297A38)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(2))
            EVT_WAIT_FRAMES(15)
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(D_80297A38)
    EVT_END_SWITCH
    EVT_IF_NE(LW(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(2))
        EVT_WAIT_FRAMES(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_802988F0 = {
    EVT_EXEC_WAIT(D_80297A38)
    EVT_IF_NE(LW(2), 000000)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(2))
        EVT_WAIT_FRAMES(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80298948 = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LW(1))
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -4, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(func_80269E80, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(5)
            EVT_WAIT_FRAMES(15)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript ForceNextTarget = {
    EVT_CALL(GetOwnerID, LW(10))
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_IF_NE(LW(0), LW(10))
        EVT_CALL(GetOriginalActorType, LW(0), LW(2))
        EVT_IF_NE(LW(2), ACTOR_TYPE_DRY_BONES)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_IF_NE(LW(0), LW(10))
        EVT_CALL(GetActorVar, LW(0), 8, LW(3))
        EVT_IF_NE(LW(3), 1)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80298E20 = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2022)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorSize, ACTOR_SELF, LW(3), LW(4))
    EVT_DIVF(LW(3), EVT_FLOAT(40.0))
    EVT_IF_LT(LW(3), 1)
        EVT_SETF(LW(3), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
    EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
        EVT_MULF(LW(3), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(6))
    EVT_IF_FLAG(LW(6), ACTOR_FLAG_HP_OFFSET_BELOW)
        EVT_CALL(GetActorSize, ACTOR_SELF, LW(7), LW(8))
        EVT_SUB(LW(1), LW(7))
    EVT_END_IF
    EVT_SUB(LW(1), 3)
    EVT_CALL(PlayEffect, EFFECT_ID_67, 0, LW(0), LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(func_80269E80, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(15)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(RemoveEffect, LW(15))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(16)
        EVT_CASE_OR_EQ(17)
            EVT_WAIT_FRAMES(40)
            EVT_CALL(func_802D7B10, LW(15))
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2023)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript DoNormalHit = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(func_80269E80, LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_EQ(7)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LW(5))
            EVT_SWITCH(LW(5))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LW(1), 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LW(5), 0)
            EVT_LOOP(30)
                EVT_ADD(LW(5), 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(5))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LW(7))
            EVT_SWITCH(LW(7))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT_FRAMES(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LW(1), 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LW(1), 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
            EVT_IF_EQ(LW(2), 14)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_SET(LW(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LW(0), 36)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(12)
        EVT_CASE_OR_EQ(16)
            EVT_IF_EQ(LW(2), 16)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 0, 2160, 60, 10)
                EVT_LABEL(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(LW(1), 1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_WAIT_FRAMES(60)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(15)
            EVT_IF_EQ(LW(2), 15)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_SET(LW(0), 360)
                EVT_LOOP(10)
                    EVT_SUB(LW(0), 36)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(13)
        EVT_CASE_OR_EQ(17)
            EVT_IF_EQ(LW(2), 17)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 2160, 0, 60, 10)
                EVT_LABEL(1)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(LW(1), 1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_WAIT_FRAMES(60)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(18)
            EVT_SET(LW(0), 3)
            EVT_EXEC_WAIT(D_80299828)
        EVT_CASE_EQ(2)
            EVT_EXEC_GET_TID(D_8029B818, LW(14))
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_LABEL(2)
            EVT_CALL(GetActorRotation, -127, LW(0), LW(1), LW(2))
            EVT_MOD(LW(1), 360)
            EVT_IF_NE(LW(1), 0)
                EVT_WAIT_FRAMES(1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_KILL_THREAD(LW(14))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_80299828 = {
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 20, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 6, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 22, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 25, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 12, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 17, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 4, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 24, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 28, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 19, 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 14, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 2, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript DoBurnHit = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(3))
    EVT_IF_EQ(LW(3), EVENT_BURN_DEATH)
        EVT_CALL(EnableActorGlow, -127, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(func_80269E80, LW(3))
    EVT_SWITCH(LW(3))
        EVT_CASE_EQ(9)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LW(7))
            EVT_SWITCH(LW(7))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LW(5), 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LW(7), 0)
            EVT_LOOP(30)
                EVT_ADD(LW(7), 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(7))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LW(7))
            EVT_SWITCH(LW(7))
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT_FRAMES(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LW(5), 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LW(5), 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_WAIT_FRAMES(20)
    EVT_END_SWITCH
    EVT_IF_NE(LW(2), -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(2))
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetPartEventFlags, -127, LW(0), LW(1))
            EVT_IF_NOT_FLAG(LW(1), 0x00000202)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(GetActorSize, ACTOR_SELF, LW(3), LW(4))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
                EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_MULF(LW(3), EVT_FLOAT(0.4))
                    EVT_MULF(LW(4), EVT_FLOAT(0.4))
                EVT_END_IF
                EVT_DIVF(LW(3), EVT_FLOAT(2.0))
                EVT_CALL(GetActorFlags, ACTOR_SELF, LW(5))
                EVT_IF_FLAG(LW(5), ACTOR_FLAG_HP_OFFSET_BELOW)
                    EVT_SUBF(LW(1), LW(3))
                EVT_ELSE
                    EVT_ADDF(LW(1), LW(3))
                EVT_END_IF
                EVT_ADDF(LW(2), EVT_FLOAT(5.0))
                EVT_DIVF(LW(3), EVT_FLOAT(10.0))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
                EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_MULF(LW(3), EVT_FLOAT(0.4))
                    EVT_IF_LT(LW(3), 1)
                        EVT_SETF(LW(3), EVT_FLOAT(1.0))
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(PlayEffect, EFFECT_ID_27, 0, LW(0), LW(1), LW(2), LW(3), 10, 0, 0, 0, 0, 0, 0, 0)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorSize, ACTOR_SELF, LW(3), LW(4))
    EVT_SETF(LW(5), LW(3))
    EVT_DIVF(LW(5), EVT_FLOAT(20.0))
    EVT_ADDF(LW(1), LW(5))
    EVT_CALL(PlayEffect, EFFECT_ID_4A, 0, LW(0), LW(1), LW(2), LW(4), LW(3), 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_SHOCK)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(func_8027D2D8, -127)
    EVT_CALL(AddActorPos, -127, 0, 1, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, 1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 3, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, 3, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, 12, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -8, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, -8, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, 12, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, -4, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, -4, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, -6, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, -6, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, 6, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, 6, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LW(15), 0, -6, 0)
    EVT_WAIT_FRAMES(1)
    EVT_LOOP(6)
        EVT_CALL(AddActorPos, -127, 0, 2, 0)
        EVT_CALL(AddEffectOffset, LW(15), 0, 2, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(AddActorPos, -127, 0, -2, 0)
        EVT_CALL(AddEffectOffset, LW(15), 0, -2, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(5)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_IF_NE(LW(0), EVENT_SHOCK_DEATH)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript DoImmune = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(2))
    EVT_IF_NOT_FLAG(LW(2), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -4, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(1)
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
    EVT_IF_NE(LW(1), -00001)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_WAIT_FRAMES(10)
    EVT_END_IF
    EVT_CALL(func_80269E80, LW(5))
    EVT_SWITCH(LW(5))
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
            EVT_SET(LF(0), 0)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LW(1))
            EVT_SWITCH(LW(1))
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOB_OMB)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BULLET_BILL)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BILL)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_NE(LW(2), STATUS_FLAG_1 | 0x00000002 | 0x00000004 | 0x00000040 | 0x00000080 | 0x00000100 | 0x00000200 | 0x00000400 | 0x00000800 | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_POISON | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP | 0x00400000 | 0x00800000 | STATUS_FLAG_KO | STATUS_FLAG_GLOWING | STATUS_FLAG_TRANSPARENT | STATUS_FLAG_ATTACK_BOOST | STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_CHILL_OUT | STATUS_FLAG_RIGHT_ON | 0x80000000)
                EVT_SET(LW(2), 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LW(2))
                    EVT_ADD(LW(2), 30)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 10)
    EVT_ADD(LW(2), 10)
    EVT_CALL(PlayEffect, EFFECT_ID_01, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LW(3), 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LW(3), 0, 0)
        EVT_ADD(LW(3), 8)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript DoScareAway = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(2))
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(9))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.05))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_SET(LW(13), LW(11))
    EVT_ADD(LW(13), 20)
    EVT_IF_NOT_FLAG(LW(9), ACTOR_FLAG_FLYING)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(13), LW(12))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 3, FALSE, FALSE, FALSE)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
        EVT_CALL(EnableActorGlow, -127, 0)
        EVT_CALL(FallToGoal, -127, 7)
    EVT_ELSE
        EVT_WAIT_FRAMES(15)
        EVT_CALL(EnableActorGlow, -127, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_WAIT_FRAMES(17)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_ADD(LW(10), 300)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
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
    EVT_CALL(GetOwnerID, LW(1))
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_IF_NE(LW(1), LW(0))
        EVT_CALL(ChooseNextTarget, 0, LW(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_EQ(LW(0), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_CALL(GetActorFlags, LW(0), LW(1))
    EVT_IF_FLAG(LW(1), ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetStatusFlags, LW(0), LW(9))
    EVT_IF_FLAG(LW(9), STATUS_FLAG_TRANSPARENT)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(GetOriginalActorType, LW(0), LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY_MUMMY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_UNUSED_69)
            EVT_CALL(DispatchDamageEvent, LW(0), 1, 17)
            EVT_GOTO(1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(20)
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
    EVT_SET(LW(0), 0)
    EVT_LABEL(0)
    EVT_SUB(LW(0), 30)
    EVT_IF_LT(LW(0), 0)
        EVT_ADD(LW(0), 360)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029B8A8 = {
    EVT_CALL(GetActorSize, ACTOR_SELF, LW(0), LW(1))
    EVT_MUL(LW(0), LW(1))
    EVT_SWITCH(LW(0))
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
    EVT_EXEC_GET_TID(D_8029B818, LW(14))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(GetPartEventFlags, -127, LW(0), LW(10))
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
    EVT_WAIT_FRAMES(15)
    EVT_LABEL(0)
    EVT_CALL(GetActorRotation, -127, LW(0), LW(1), LW(2))
    EVT_MOD(LW(1), 360)
    EVT_IF_NE(LW(1), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_KILL_THREAD(LW(14))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029BBB4 = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_SET(LW(12), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), LW(11))
    EVT_SET(LW(0), 0)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), 0)
    EVT_LOOP(5)
        EVT_ADD(LW(0), 30)
        EVT_ADD(LW(1), 4)
        EVT_ADD(LW(2), -2)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LW(2), LW(1), 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), LW(12))
    EVT_SET(LW(2), -10)
    EVT_LOOP(5)
        EVT_ADD(LW(2), 2)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LW(2), 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript DoJumpBack = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
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
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(13), LW(14), LW(15))
    EVT_CALL(GetDist2D, LW(9), LW(10), LW(12), LW(13), LW(15))
    EVT_IF_GE(LW(9), EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript DoRecover = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(7), LW(8), LW(9))
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(7), LW(8), LW(9))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(7), LW(8), LW(9))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_8029C0A4 = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029C12C = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_IF_EQ(LW(3), LW(0))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_LT(LW(3), LW(0))
        EVT_SET(LW(4), LW(0))
        EVT_SUB(LW(4), LW(3))
        EVT_IF_LT(LW(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_ELSE
            EVT_SET(LW(4), LW(3))
            EVT_ADD(LW(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(3), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LW(4), LW(3))
        EVT_SUB(LW(4), LW(0))
        EVT_IF_LT(LW(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_ELSE
            EVT_SUB(LW(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(3), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};

EvtScript DoAirLift = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(2))
    EVT_IF_NOT_FLAG(LW(2), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LW(0), EVT_FLOAT(2.0))
        EVT_LOOP(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
            EVT_CALL(GetActorSize, ACTOR_SELF, LW(6), LW(7))
            EVT_ADD(LW(4), LW(6))
            EVT_CALL(PlayEffect, EFFECT_ID_28, 0, LW(3), LW(4), LW(5), 5, -45, 20, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_END_LOOP
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LW(0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript DoBlowAway = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
    EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_ELSE
        EVT_SET(LF(0), 0)
        EVT_IF_FLAG(LW(2), STATUS_FLAG_SLEEP)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SLEEP)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_STATIC)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_STATIC)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_FROZEN)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_FROZEN)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_FEAR)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_FEAR)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_PARALYZE)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_PARALYZE)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_POISON)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_POISON)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_DIZZY)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_DIZZY)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
            EVT_SET(LF(0), 1)
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_STONE)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_STONE)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(2), STATUS_FLAG_KO)
            EVT_IF_FLAG(LW(5), STATUS_FLAG_KO)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LF(0), 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_WAIT_FRAMES(1000)
    EVT_RETURN
    EVT_END
};
