#include "common.h"

INCLUDE_ASM(s32, "code_197F40", count_targets);

INCLUDE_ASM(s32, "code_197F40", get_nearest_home_index);

INCLUDE_ASM(s32, "code_197F40", set_goal_pos_to_part);

INCLUDE_ASM(s32, "code_197F40", set_part_goal_to_actor_part);

INCLUDE_ASM(s32, "code_197F40", set_actor_current_position);

INCLUDE_ASM(s32, "code_197F40", set_part_absolute_position);

INCLUDE_ASM(s32, "code_197F40", set_actor_home_position);

INCLUDE_ASM(Actor*, "code_197F40", get_actor, s32 actorID);

INCLUDE_ASM(s32, "code_197F40", LoadBattleSection);

INCLUDE_ASM(s32, "code_197F40", GetBattlePhase);

INCLUDE_ASM(s32, "code_197F40", GetLastElement);

INCLUDE_ASM(s32, "code_197F40", func_80269E80);

INCLUDE_ASM(s32, "code_197F40", func_80269EAC);

INCLUDE_ASM(s32, "code_197F40", SetGoalToHome);

INCLUDE_ASM(s32, "code_197F40", SetIdleGoalToHome);

INCLUDE_ASM(s32, "code_197F40", SetGoalToIndex);

INCLUDE_ASM(s32, "code_197F40", GetIndexFromPos);

INCLUDE_ASM(s32, "code_197F40", GetIndexFromHome);

INCLUDE_ASM(s32, "code_197F40", CountPlayerTargets);

INCLUDE_ASM(s32, "code_197F40", ForceHomePos);

INCLUDE_ASM(s32, "code_197F40", SetHomePos);

INCLUDE_ASM(s32, "code_197F40", SetGoalToTarget);

INCLUDE_ASM(s32, "code_197F40", SetPartGoalToTarget);

INCLUDE_ASM(s32, "code_197F40", SetGoalToFirstTarget);

INCLUDE_ASM(s32, "code_197F40", SetGoalPos);

INCLUDE_ASM(s32, "code_197F40", SetIdleGoal);

INCLUDE_ASM(s32, "code_197F40", AddGoalPos);

INCLUDE_ASM(s32, "code_197F40", GetGoalPos);

INCLUDE_ASM(s32, "code_197F40", GetIdleGoal);

INCLUDE_ASM(s32, "code_197F40", GetPartTarget);

INCLUDE_ASM(s32, "code_197F40", GetActorPos);

INCLUDE_ASM(s32, "code_197F40", GetPartOffset);

INCLUDE_ASM(s32, "code_197F40", GetPartPos);

INCLUDE_ASM(s32, "code_197F40", GetHomePos);

INCLUDE_ASM(s32, "code_197F40", SetActorPos);

INCLUDE_ASM(s32, "code_197F40", SetPartPos);

INCLUDE_ASM(s32, "code_197F40", SetEnemyTargetOffset);

INCLUDE_ASM(s32, "code_197F40", SetAnimation);

INCLUDE_ASM(s32, "code_197F40", GetAnimation);

INCLUDE_ASM(s32, "code_197F40", SetAnimationRate);

INCLUDE_ASM(s32, "code_197F40", SetActorYaw);

INCLUDE_ASM(s32, "code_197F40", GetActorYaw);

INCLUDE_ASM(s32, "code_197F40", SetPartYaw);

INCLUDE_ASM(s32, "code_197F40", GetPartYaw);

INCLUDE_ASM(s32, "code_197F40", SetActorJumpGravity);

INCLUDE_ASM(s32, "code_197F40", SetActorIdleJumpGravity);

INCLUDE_ASM(s32, "code_197F40", SetActorSpeed);

INCLUDE_ASM(s32, "code_197F40", SetActorIdleSpeed);

INCLUDE_ASM(s32, "code_197F40", SetPartJumpGravity);

INCLUDE_ASM(s32, "code_197F40", SetPartMoveSpeed);

INCLUDE_ASM(s32, "code_197F40", SetJumpAnimations);

INCLUDE_ASM(s32, "code_197F40", AddActorPos);

INCLUDE_ASM(s32, "code_197F40", SetActorDispOffset);

INCLUDE_ASM(s32, "code_197F40", GetPartDispOffset);

INCLUDE_ASM(s32, "code_197F40", SetPartDispOffset);

INCLUDE_ASM(s32, "code_197F40", AddPartDispOffset);

INCLUDE_ASM(s32, "code_197F40", func_8026BF48);

INCLUDE_ASM(s32, "code_197F40", GetActorVar);

INCLUDE_ASM(s32, "code_197F40", SetActorVar);

INCLUDE_ASM(s32, "code_197F40", AddActorVar);

INCLUDE_ASM(s32, "code_197F40", GetPartMovementVar);

INCLUDE_ASM(s32, "code_197F40", SetPartMovementVar);

INCLUDE_ASM(s32, "code_197F40", AddPartMovementVar);

INCLUDE_ASM(s32, "code_197F40", SetActorRotation);

INCLUDE_ASM(s32, "code_197F40", SetActorRotationOffset);

INCLUDE_ASM(s32, "code_197F40", GetActorRotation);

INCLUDE_ASM(s32, "code_197F40", SetPartRotation);

INCLUDE_ASM(s32, "code_197F40", SetPartRotationOffset);

INCLUDE_ASM(s32, "code_197F40", GetPartRotation);

INCLUDE_ASM(s32, "code_197F40", SetActorScale);

INCLUDE_ASM(s32, "code_197F40", SetActorScaleModifier);

INCLUDE_ASM(s32, "code_197F40", GetActorScale);

INCLUDE_ASM(s32, "code_197F40", SetPartScale);

INCLUDE_ASM(s32, "code_197F40", GetPartScale);

INCLUDE_ASM(s32, "code_197F40", GetBattleFlags);

INCLUDE_ASM(s32, "code_197F40", SetBattleFlagBits);

INCLUDE_ASM(s32, "code_197F40", GetBattleFlags2);

INCLUDE_ASM(s32, "code_197F40", SetBattleFlagBits2);

INCLUDE_ASM(s32, "code_197F40", SetActorFlags);

INCLUDE_ASM(s32, "code_197F40", SetActorFlagBits);

INCLUDE_ASM(s32, "code_197F40", GetActorFlags);

INCLUDE_ASM(s32, "code_197F40", SetPartFlags);

INCLUDE_ASM(s32, "code_197F40", SetPartFlagBits);

INCLUDE_ASM(s32, "code_197F40", SetPartTargetFlags);

INCLUDE_ASM(s32, "code_197F40", SetPartTargetFlagBits);

INCLUDE_ASM(s32, "code_197F40", GetPartFlags);

INCLUDE_ASM(s32, "code_197F40", GetPartTargetFlags);

INCLUDE_ASM(s32, "code_197F40", SetPartEventFlags);

INCLUDE_ASM(s32, "code_197F40", SetPartEventBits);

INCLUDE_ASM(s32, "code_197F40", GetPartEventFlags);

INCLUDE_ASM(s32, "code_197F40", func_8026D51C);

INCLUDE_ASM(s32, "code_197F40", func_8026D5A4);

INCLUDE_ASM(s32, "code_197F40", HPBarToHome);

INCLUDE_ASM(s32, "code_197F40", HPBarToCurrent);

INCLUDE_ASM(s32, "code_197F40", func_8026D8EC);

INCLUDE_ASM(s32, "code_197F40", func_8026D940);

INCLUDE_ASM(s32, "code_197F40", func_8026DA94);

INCLUDE_ASM(s32, "code_197F40", SummonEnemy);

INCLUDE_ASM(s32, "code_197F40", GetOwnerID);

INCLUDE_ASM(s32, "code_197F40", SetOwnerID);

ApiStatus ActorExists(ScriptInstance* script, s32 isInitialCall) {
    Bytecode isExist;
    Actor* partner = gBattleStatus.partnerActor;
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);

    if (actorID == ActorId_SELF) {
        actorID = script->ownerActorID;
    }

    isExist = get_actor(actorID) != NULL;
    if ((actorID == ActorId_PARTNER) && (partner == NULL)) {
        isExist = FALSE;
    }

    set_variable(script, *args++, isExist);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", func_8026DEF0);

INCLUDE_ASM(s32, "code_197F40", func_8026DF88);

INCLUDE_ASM(s32, "code_197F40", func_8026E020);

INCLUDE_ASM(s32, "code_197F40", func_8026E038);

INCLUDE_ASM(s32, "code_197F40", SetBattleInputMask);

INCLUDE_ASM(s32, "code_197F40", SetBattleInputButtons);

INCLUDE_ASM(s32, "code_197F40", CheckButtonPress);

INCLUDE_ASM(s32, "code_197F40", CheckButtonHeld);

INCLUDE_ASM(s32, "code_197F40", CheckButtonDown);

INCLUDE_ASM(s32, "code_197F40", GetBattleState);

INCLUDE_ASM(s32, "code_197F40", func_8026E16C);

INCLUDE_ASM(s32, "code_197F40", func_8026E198);

INCLUDE_ASM(s32, "code_197F40", func_8026E208);

INCLUDE_ASM(s32, "code_197F40", func_8026E260);

INCLUDE_ASM(s32, "code_197F40", PlayerCreateTargetList);

INCLUDE_ASM(s32, "code_197F40", EnemyCreateTargetList);

INCLUDE_ASM(s32, "code_197F40", InitTargetIterator);

INCLUDE_ASM(s32, "code_197F40", SetOwnerTarget);

INCLUDE_ASM(s32, "code_197F40", ChooseNextTarget);

INCLUDE_ASM(s32, "code_197F40", func_8026E558);

INCLUDE_ASM(s32, "code_197F40", GetTargetListLength);

INCLUDE_ASM(s32, "code_197F40", GetOwnerTarget);

INCLUDE_ASM(s32, "code_197F40", func_8026E914);

INCLUDE_ASM(s32, "code_197F40", GetPlayerActorID);

INCLUDE_ASM(s32, "code_197F40", func_8026E9A0);

INCLUDE_ASM(s32, "code_197F40", GetDistanceToGoal);

INCLUDE_ASM(s32, "code_197F40", func_8026EA7C);

INCLUDE_ASM(s32, "code_197F40", func_8026EB20);

INCLUDE_ASM(s32, "code_197F40", func_8026EBF8);

INCLUDE_ASM(s32, "code_197F40", func_8026ED20);

INCLUDE_ASM(s32, "code_197F40", func_8026EDE4);

INCLUDE_ASM(s32, "code_197F40", AddActorDecoration);

INCLUDE_ASM(s32, "code_197F40", RemoveActorDecoration);

INCLUDE_ASM(s32, "code_197F40", ModifyActorDecoration);

INCLUDE_ASM(s32, "code_197F40", UseIdleAnimation);

INCLUDE_ASM(s32, "code_197F40", func_8026F1A0);

INCLUDE_ASM(s32, "code_197F40", GetStatusFlags);

INCLUDE_ASM(s32, "code_197F40", RemovePlayerBuffs);

INCLUDE_ASM(s32, "code_197F40", SetPartAlpha);

INCLUDE_ASM(s32, "code_197F40", CreatePartShadow);

INCLUDE_ASM(s32, "code_197F40", RemovePartShadow);

INCLUDE_ASM(s32, "code_197F40", func_8026F60C);

INCLUDE_ASM(s32, "code_197F40", SetBattleVar);

INCLUDE_ASM(s32, "code_197F40", GetBattleVar);

INCLUDE_ASM(s32, "code_197F40", ResetAllActorSounds);

INCLUDE_ASM(s32, "code_197F40", SetActorSounds);

INCLUDE_ASM(s32, "code_197F40", ResetActorSounds);

INCLUDE_ASM(s32, "code_197F40", SetPartSounds);

INCLUDE_ASM(s32, "code_197F40", SetActorType);

INCLUDE_ASM(s32, "code_197F40", ShowShockEffect);

INCLUDE_ASM(s32, "code_197F40", GetActorAttackBoost);

INCLUDE_ASM(s32, "code_197F40", GetActorDefenseBoost);

INCLUDE_ASM(s32, "code_197F40", BoostAttack);

INCLUDE_ASM(s32, "code_197F40", BoostDefense);

INCLUDE_ASM(s32, "code_197F40", VanishActor);

INCLUDE_ASM(s32, "code_197F40", ElectrifyActor);

INCLUDE_ASM(s32, "code_197F40", HealActor);

INCLUDE_ASM(s32, "code_197F40", WaitForBuffDone);

INCLUDE_ASM(s32, "code_197F40", CopyBuffs);

INCLUDE_ASM(s32, "code_197F40", func_80271210);

INCLUDE_ASM(s32, "code_197F40", func_80271258);

INCLUDE_ASM(s32, "code_197F40", func_802712A0);

INCLUDE_ASM(s32, "code_197F40", func_80271328);

INCLUDE_ASM(s32, "code_197F40", func_802713B0);

INCLUDE_ASM(s32, "code_197F40", func_8027143C);

INCLUDE_ASM(s32, "code_197F40", func_80271484);

INCLUDE_ASM(s32, "code_197F40", func_80271588);

INCLUDE_ASM(s32, "code_197F40", dispatch_event_player);

INCLUDE_ASM(s32, "code_197F40", dispatch_event_player_continue_turn);

INCLUDE_ASM(s32, "code_197F40", calc_player_test_enemy);

INCLUDE_ASM(s32, "code_197F40", calc_player_damage_enemy);

INCLUDE_ASM(s32, "code_197F40", dispatch_damage_event_player);

INCLUDE_ASM(s32, "code_197F40", dispatch_damage_event_player_0);

INCLUDE_ASM(s32, "code_197F40", dispatch_damage_event_player_1);

INCLUDE_ASM(s32, "code_197F40", GetMenuSelection);

INCLUDE_ASM(s32, "code_197F40", func_80273444);

INCLUDE_ASM(s32, "code_197F40", PlayerFallToGoal);

INCLUDE_ASM(s32, "code_197F40", PlayerLandJump);

INCLUDE_ASM(s32, "code_197F40", PlayerRunToGoal);

INCLUDE_ASM(s32, "code_197F40", CancelablePlayerRunToGoal);

INCLUDE_ASM(s32, "code_197F40", GetPlayerHP);

INCLUDE_ASM(s32, "code_197F40", PlayerDamageEnemy);

INCLUDE_ASM(s32, "code_197F40", PlayerPowerBounceEnemy);

INCLUDE_ASM(s32, "code_197F40", PlayerTestEnemy);

INCLUDE_ASM(s32, "code_197F40", DispatchDamagePlayerEvent);

INCLUDE_ASM(s32, "code_197F40", EnablePlayerBlur);

INCLUDE_ASM(s32, "code_197F40", func_802749D8);

INCLUDE_ASM(s32, "code_197F40", func_802749F8);

INCLUDE_ASM(s32, "code_197F40", func_80274A18);

INCLUDE_ASM(s32, "code_197F40", func_802752AC);

INCLUDE_ASM(s32, "code_197F40", func_80275F00);

INCLUDE_ASM(s32, "code_197F40", DidActionSucceed);

INCLUDE_ASM(s32, "code_197F40", func_80276EFC);

INCLUDE_ASM(s32, "code_197F40", func_80276F1C);
