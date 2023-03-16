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
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
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
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript DoPartnerRunAway = {
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

EvtScript DoPartnerBurnContact = {
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
    EVT_EXEC_WAIT(DoPartnerBurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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

EvtScript DoPartnerSpikeContact = {
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
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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

EvtScript D_80295350 = {
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
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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

EvtScript D_80295744 = {
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
    EVT_CALL(ShowShockEffect, -127)
    EVT_SET(LVar1, LVarA)
    EVT_SET(LVar2, 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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

EvtScript D_80295AC0 = {
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
    EVT_CALL(ShowShockEffect, -127)
    EVT_SET(LVar1, LVarA)
    EVT_SET(LVar2, 0)
    EVT_EXEC_WAIT(D_802977BC)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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

EvtScript DoPartnerRecover = {
    EVT_SET(LVar6, LVar3)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar7, LVar8, LVar9)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
    EVT_IF_EQ(LVar6, 000000)
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

EvtScript DoPartnerHit = {
    EVT_SET(LVarA, LVar1)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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

EvtScript DoPartnerBurn = {
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
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

EvtScript D_80296C8C = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar1)
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LVar0)
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

EvtScript D_802976E8 = {
    EVT_CALL(func_80269E80, LVar0)
    EVT_SWITCH(LVar0)
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
    EVT_IF_NE(LVar2, 000000)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_802977BC = {
    EVT_EXEC_WAIT(D_80296C8C)
    EVT_IF_NE(LVar2, 000000)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript DoPartnerBlock = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar1)
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LVar0)
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

EvtScript D_80298494 = {
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
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
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, -36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
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
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
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
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
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
    EVT_CALL(func_80269E80, LVar0)
    EVT_SWITCH(LVar0)
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
            EVT_SET(LVar1, 327683)
            EVT_SET(LVar2, 65583)
            EVT_EXEC_WAIT(D_80297A38)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar2)
            EVT_WAIT(15)
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(D_80297A38)
    EVT_END_SWITCH
    EVT_IF_NE(LVar2, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_802988F0 = {
    EVT_EXEC_WAIT(D_80297A38)
    EVT_IF_NE(LVar2, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar2)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80298948 = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
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
    EVT_CALL(func_80269E80, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(5)
            EVT_WAIT(15)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript ForceNextTarget = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_IF_NE(LVar0, LVarA)
        EVT_CALL(GetOriginalActorType, LVar0, LVar2)
        EVT_IF_NE(LVar2, ACTOR_TYPE_DRY_BONES)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_IF_NE(LVar0, LVarA)
        EVT_CALL(GetActorVar, LVar0, 8, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80298E20 = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2022)
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
    EVT_CALL(PlayEffect, EFFECT_WHIRLWIND, 0, LVar0, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(func_80269E80, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(15)
            EVT_WAIT(10)
            EVT_CALL(RemoveEffect, LVarF)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(16)
        EVT_CASE_OR_EQ(17)
            EVT_WAIT(40)
            EVT_CALL(func_802D7B10, LVarF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2023)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript DoNormalHit = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(func_80269E80, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(7)
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
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
            EVT_IF_EQ(LVar2, 14)
                EVT_EXEC(D_80298E20)
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
            EVT_EXEC_WAIT(D_80299828)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(12)
        EVT_CASE_OR_EQ(16)
            EVT_IF_EQ(LVar2, 16)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 0, 2160, 60, 10)
                EVT_LABEL(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_WAIT(60)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(15)
            EVT_IF_EQ(LVar2, 15)
                EVT_EXEC(D_80298E20)
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
            EVT_EXEC_WAIT(D_80299828)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(13)
        EVT_CASE_OR_EQ(17)
            EVT_IF_EQ(LVar2, 17)
                EVT_EXEC(D_80298E20)
            EVT_END_IF
            EVT_CHILD_THREAD
                EVT_CALL(MakeLerp, 2160, 0, 60, 10)
                EVT_LABEL(1)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_END_CHILD_THREAD
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_WAIT(60)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(18)
            EVT_SET(LVar0, 3)
            EVT_EXEC_WAIT(D_80299828)
        EVT_CASE_EQ(2)
            EVT_EXEC_GET_TID(D_8029B818, LVarE)
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
            EVT_LABEL(2)
            EVT_CALL(GetActorRotation, -127, LVar0, LVar1, LVar2)
            EVT_MOD(LVar1, 360)
            EVT_IF_NE(LVar1, 0)
                EVT_WAIT(1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_KILL_THREAD(LVarE)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(GetDamageIntensity)
            EVT_EXEC_WAIT(D_80299828)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_80299828 = {
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

EvtScript DoBurnHit = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, EVENT_BURN_DEATH)
        EVT_CALL(EnableActorGlow, -127, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(func_80269E80, LVar3)
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(9)
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
            EVT_CALL(GetPartEventFlags, -127, LVar0, LVar1)
            EVT_IF_NOT_FLAG(LVar1, 0x00000202)
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
                EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
    EVT_SETF(LVar5, LVar3)
    EVT_DIVF(LVar5, EVT_FLOAT(20.0))
    EVT_ADDF(LVar1, LVar5)
    EVT_CALL(PlayEffect, EFFECT_FLASHING_BOX_SHOCKWAVE, 0, LVar0, LVar1, LVar2, LVar4, LVar3, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_SHOCK)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(func_8027D2D8, -127)
    EVT_CALL(AddActorPos, -127, 0, 1, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 3, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 3, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 12, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -8, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -8, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 12, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 12, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -4, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -4, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, 6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, 6, 0)
    EVT_WAIT(1)
    EVT_CALL(AddActorPos, -127, 0, -6, 0)
    EVT_CALL(AddEffectOffset, LVarF, 0, -6, 0)
    EVT_WAIT(1)
    EVT_LOOP(6)
        EVT_CALL(AddActorPos, -127, 0, 2, 0)
        EVT_CALL(AddEffectOffset, LVarF, 0, 2, 0)
        EVT_WAIT(1)
        EVT_CALL(AddActorPos, -127, 0, -2, 0)
        EVT_CALL(AddEffectOffset, LVarF, 0, -2, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(5)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, EVENT_SHOCK_DEATH)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript DoImmune = {
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_NOT_FLAG(LVar2, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
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
    EVT_IF_NE(LVar1, -00001)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(func_80269E80, LVar5)
    EVT_SWITCH(LVar5)
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
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar1)
            EVT_SWITCH(LVar1)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOB_OMB)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BULLET_BILL)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BILL)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_NE(LVar2, STATUS_FLAG_1 | 0x00000002 | 0x00000004 | 0x00000040 | 0x00000080 | 0x00000100 | 0x00000200 | 0x00000400 | 0x00000800 | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_POISON | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP | 0x00400000 | 0x00800000 | STATUS_FLAG_KO | STATUS_FLAG_GLOWING | STATUS_FLAG_TRANSPARENT | STATUS_FLAG_ATTACK_BOOST | STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_CHILL_OUT | STATUS_FLAG_RIGHT_ON | 0x80000000)
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
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
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

EvtScript DoScareAway = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
        EVT_CALL(EnableActorGlow, -127, 0)
        EVT_CALL(FallToGoal, -127, 7)
    EVT_ELSE
        EVT_WAIT(15)
        EVT_CALL(EnableActorGlow, -127, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(17)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT(3)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_ADD(LVarA, 300)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029B494 = {
    EVT_CALL(PlayerCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_10000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LVar1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_IF_NE(LVar1, LVar0)
        EVT_CALL(ChooseNextTarget, 0, LVar0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_EQ(LVar0, -1)
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
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_POKEY_MUMMY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_UNUSED_69)
            EVT_CALL(DispatchDamageEvent, LVar0, 1, 17)
            EVT_GOTO(1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
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

EvtScript D_8029B8A8 = {
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar1)
    EVT_MUL(LVar0, LVar1)
    EVT_SWITCH(LVar0)
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
    EVT_EXEC_GET_TID(D_8029B818, LVarE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetPartEventFlags, -127, LVar0, LVarA)
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
    EVT_CALL(GetActorRotation, -127, LVar0, LVar1, LVar2)
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

EvtScript D_8029BBB4 = {
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

EvtScript DoJumpBack = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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

EvtScript DoReturnHome = {
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

EvtScript DoRecover = {
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

EvtScript D_8029C0A4 = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_RETURN
    EVT_END
};

EvtScript D_8029C12C = {
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

EvtScript DoAirLift = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_NOT_FLAG(LVar2, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LVar0, EVT_FLOAT(2.0))
        EVT_LOOP(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar6, LVar7)
            EVT_ADD(LVar4, LVar6)
            EVT_CALL(PlayEffect, EFFECT_SWEAT, 0, LVar3, LVar4, LVar5, 5, -45, 20, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
        EVT_CALL(SetAnimationRate, ACTOR_SELF, LVar0, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript DoBlowAway = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
    EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_ELSE
        EVT_SET(LocalFlag(0), 0)
        EVT_IF_FLAG(LVar2, STATUS_FLAG_SLEEP)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SLEEP)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_STATIC)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_STATIC)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_FROZEN)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_FROZEN)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_FEAR)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_FEAR)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_PARALYZE)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_PARALYZE)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_POISON)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_POISON)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_DIZZY)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_DIZZY)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_STONE)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_STONE)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVar2, STATUS_FLAG_KO)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_KO)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_WAIT(1000)
    EVT_RETURN
    EVT_END
};
