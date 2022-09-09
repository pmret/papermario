#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_bombette.h"
#include "battle/action_cmd/bomb.h"
#include "battle/action_cmd/body_slam.h"

extern EvtScript N(init_80238780);
extern EvtScript N(takeTurn_80239AB8);
extern EvtScript N(idle_802387E0);
extern EvtScript N(handleEvent_802387F0);
extern EvtScript N(nextTurn_80239E7C);
extern EvtScript N(80239B64);
extern EvtScript N(80239BC0);
extern EvtScript N(8023C990);
extern EvtScript N(80239D08);
extern EvtScript N(80239D8C);
extern EvtScript N(80239DC8);
extern EvtScript N(8023A5F8);
extern EvtScript N(8023B228);

ApiStatus func_80238000_6FAD10(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s16 selectedMoveID;
    s32 soundID;

    fx_smoke_ring(0, x, y, z);
    selectedMoveID = battleStatus->selectedMoveID;

    switch (selectedMoveID) {
        case 146:
            if (script->varTable[10] > 0) {
                fx_explosion(1, x, y + 20, z);
            } else {
                fx_explosion(0, x, y + 20, z);
            }
            sfx_play_sound(8214);
            break;
        case 147:
            if (script->varTable[10] > 0) {
                fx_explosion(1, x, y + 20, z);
            } else {
                fx_explosion(0, x, y + 20, z);
            }
            sfx_play_sound(8215);
            break;
        case 148:
            if (script->varTable[10] > 0) {
                fx_explosion(2, x, y + 20, z);
            } else {
                fx_explosion(1, x, y + 20, z);
            }
            sfx_play_sound(8215);
            break;
        default:
            fx_explosion(0, x, y + 20, z);
            sfx_play_sound(8214);
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238244_6FAF54(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorState* partnerActorMovement = &partnerActor->state;

    if (isInitialCall) {
        partnerActor->state.currentPos.x = partnerActor->currentPos.x;
        partnerActor->state.currentPos.y = partnerActor->currentPos.y;
        partnerActor->state.currentPos.z = partnerActor->currentPos.z;
    }

    add_xz_vec3f(&partnerActorMovement->currentPos, partnerActor->state.speed, partnerActor->state.angle);

    if (partnerActor->state.speed < 4.0f) {
        play_movement_dust_effects(0, partnerActor->state.currentPos.x, partnerActor->state.currentPos.y,
                                   partnerActor->state.currentPos.z, partnerActor->state.angle);
    } else {
        play_movement_dust_effects(1, partnerActor->state.currentPos.x, partnerActor->state.currentPos.y,
                                   partnerActor->state.currentPos.z, partnerActor->state.angle);
    }

    partnerActorMovement->speed /= 1.5;

    partnerActor->currentPos.x = partnerActorMovement->currentPos.x;
    partnerActor->currentPos.y = partnerActorMovement->currentPos.y;
    partnerActor->currentPos.z = partnerActorMovement->currentPos.z;

    if (partnerActorMovement->speed < 1.0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238358_6FB068(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = 0;

    switch (partnerActor->actorBlueprint->level) {
        case 0:
            if (var0 < 36) {
                var1 = 1;
            } else if (var0 < 61) {
                var1 = 2;
            } else if (var0 < 81) {
                var1 = 3;
            } else if (var0 < 100) {
                var1 = 4;
            } else {
                var1 = 5;
            }
            break;
        case 1:
            if (var0 < 36) {
                var1 = 1;
            } else if (var0 < 61) {
                var1 = 3;
            } else if (var0 < 81) {
                var1 = 4;
            } else if (var0 < 100) {
                var1 = 5;
            } else {
                var1 = 6;
            }
            break;
        case 2:
            if (var0 < 36) {
                var1 = 1;
            } else if (var0 < 61) {
                var1 = 3;
            } else if (var0 < 81) {
                var1 = 5;
            } else if (var0 < 100) {
                var1 = 6;
            } else {
                var1 = 7;
            }
            break;
    }


    if (!(var0 < 100)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = var1;

    return ApiStatus_DONE2;
}

ApiStatus func_8023849C_6FB1AC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = 0;

    switch (partnerActor->actorBlueprint->level) {
        case 1:
            if (var0 < 36) {
                var1 = 1;
            } else if (var0 < 61) {
                var1 = 3;
            } else if (var0 < 81) {
                var1 = 4;
            } else if (var0 < 100) {
                var1 = 5;
            } else {
                var1 = 6;
            }
            break;
        case 2:
            if (var0 < 36) {
                var1 = 1;
            } else if (var0 < 61) {
                var1 = 3;
            } else if (var0 < 81) {
                var1 = 5;
            } else if (var0 < 100) {
                var1 = 6;
            } else {
                var1 = 7;
            }
    }


    if (!(var0 < 100)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = var1;

    return ApiStatus_DONE2;
}

ApiStatus func_80238590_6FB2A0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = 0;

    switch (partnerActor->actorBlueprint->level) {
        case 2:
            if (var0 < 36) {
                var1 = 1;
            } else if (var0 < 61) {
                var1 = 3;
            } else if (var0 < 81) {
                var1 = 5;
            } else if (var0 < 100) {
                var1 = 6;
            } else {
                var1 = 7;
            }
            break;
    }


    if (!(var0 < 100)) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    script->varTable[15] = var1;

    return ApiStatus_DONE2;
}

s32 N(idleAnimations_80238640)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_bombette_Palette_00_Anim_6,
    STATUS_STONE,     NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_bombette_Palette_00_Anim_1D,
    STATUS_POISON,    NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_DAZE,      NPC_ANIM_battle_bombette_Palette_00_Anim_1E,
    STATUS_TURN_DONE, NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(defenseTable_8023867C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80238688)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 100,
    STATUS_POISON, 100,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80238734)[] = {
    {
        .flags = 0,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 9, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80238640),
        .defenseTable = N(defenseTable_8023867C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOMBETTE,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_80238734)),
    .partsData = N(partsTable_80238734),
    .script = &N(init_80238780),
    .statusTable = N(statusTable_80238688),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_80238780) = {
    EVT_CALL(BindTakeTurn, ACTOR_PARTNER, EVT_ADDR(N(takeTurn_80239AB8)))
    EVT_CALL(BindIdle, ACTOR_PARTNER, EVT_ADDR(N(idle_802387E0)))
    EVT_CALL(BindHandleEvent, ACTOR_PARTNER, EVT_ADDR(N(handleEvent_802387F0)))
    EVT_CALL(BindNextTurn, ACTOR_PARTNER, EVT_ADDR(N(nextTurn_80239E7C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802387E0) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802387F0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(StopSound, 647)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_SET_CONST(LVar2, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(D_80296014)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(D_80297814)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_SET(LVar2, 15)
            EVT_SET_CONST(LVar3, NPC_ANIM_battle_bombette_Palette_00_Anim_1E)
            EVT_EXEC_WAIT(D_80295350)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_13)
            EVT_SET_CONST(LVar2, NPC_ANIM_battle_bombette_Palette_00_Anim_14)
            EVT_EXEC_WAIT(D_8029621C)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVarA, 0)
            EVT_CALL(func_80238000_6FAD10, LVar0, LVar1, LVar2)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(3.0))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(1.5))
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.8))
                EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.3))
                EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.1))
            EVT_END_THREAD
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(80)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_ADD(LVar0, 33)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, 0)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, 720915, 720915, 720915)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_13)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_13)
            EVT_SET_CONST(LVar2, NPC_ANIM_battle_bombette_Palette_00_Anim_14)
            EVT_EXEC_WAIT(D_8029621C)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVarA, 0)
            EVT_CALL(func_80238000_6FAD10, LVar0, LVar1, LVar2)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(3.0))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(1.5))
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.8))
                EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.3))
                EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.1))
            EVT_END_THREAD
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(80)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_ADD(LVar0, 33)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, 0)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_SET(LVar2, 15)
            EVT_SET_CONST(LVar3, NPC_ANIM_battle_bombette_Palette_00_Anim_1E)
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
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_B)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVarA, 0)
            EVT_CALL(func_80238000_6FAD10, LVar0, LVar1, LVar2)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(3.0))
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(1.5))
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.8))
                EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.3))
                EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.1))
            EVT_END_THREAD
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(80)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_ADD(LVar0, 33)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, 0)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_RECOVER_PARTNER)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
            EVT_SET_CONST(LVar2, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(D_80295EC4)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_16)
            EVT_EXEC_WAIT(D_80297814)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80239AB8) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(80239D08))
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(80239BC0))
        EVT_CASE_EQ(PHASE_5)
            EVT_EXEC_WAIT(N(80239B64))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(80239D8C))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(80239DC8))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80239B64) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_18)
    EVT_SET_CONST(LVar2, NPC_ANIM_battle_bombette_Palette_00_Anim_19)
    EVT_SET_CONST(LVar3, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(80239BC0) = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(143)
            EVT_EXEC_WAIT(N(8023A5F8))
        EVT_CASE_EQ(144)
            EVT_EXEC_WAIT(N(8023A5F8))
        EVT_CASE_EQ(145)
            EVT_EXEC_WAIT(N(8023A5F8))
        EVT_CASE_EQ(146)
            EVT_EXEC_WAIT(N(8023B228))
        EVT_CASE_EQ(147)
            EVT_EXEC_WAIT(N(8023B228))
        EVT_CASE_EQ(148)
            EVT_EXEC_WAIT(N(8023B228))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80239D08) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(143)
            EVT_EXEC_WAIT(N(8023C990))
        EVT_CASE_EQ(144)
            EVT_EXEC_WAIT(N(8023C990))
        EVT_CASE_EQ(145)
            EVT_EXEC_WAIT(N(8023C990))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80239D8C) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
    EVT_EXEC_WAIT(D_80294AFC)
    EVT_RETURN
    EVT_END
};

EvtScript N(80239DC8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80239E7C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80239E8C) = {
    EVT_CALL(func_80280818)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 25, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_SUB(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_WAIT(8)
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, 0)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A1AC) = {
    EVT_CALL(func_80280818)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_SUB(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_WAIT(8)
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, 0)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A4BC) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 35)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A4F8) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_F)
    EVT_LOOP(15)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A584) = {
    EVT_LOOP(15)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A5F8) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_BODY_SLAM)
    EVT_CALL(action_command_body_slam_CreateHudElements)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_48)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_LOOP(60)
        EVT_CALL(CheckButtonDown, 0x00008000, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_SET(LocalFlag(2), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(MoveBattleCamOver, 65)
    EVT_IF_EQ(LocalFlag(2), 1)
        EVT_CALL(action_command_body_slam_MashActionCommandInit, 0, 92, 3, 0)
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(8023A4BC), LVarA)
        EVT_LOOP(35)
            EVT_CALL(CheckButtonDown, 0x00008000, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_SET(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(8023A4F8), LVarA)
        EVT_LOOP(30)
            EVT_CALL(CheckButtonDown, 0x00008000, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_SET(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LocalFlag(0), 0)
            EVT_EXEC_GET_TID(N(8023A584), LVarA)
            EVT_LOOP(30)
                EVT_CALL(CheckButtonDown, 0x00008000, LVar0)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_KILL_THREAD(LVarA)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(8023A4BC), LVarA)
        EVT_LOOP(35)
            EVT_CALL(CheckButtonDown, 0x00008000, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_IF_EQ(LocalFlag(2), 0)
                    EVT_CALL(action_command_body_slam_MashActionCommandInit, 0, 92, 3, 0)
                    EVT_SET(LocalFlag(2), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(2), 1)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(8023A4F8), LVarA)
        EVT_LOOP(30)
            EVT_CALL(CheckButtonDown, 0x00008000, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_IF_EQ(LocalFlag(2), 0)
                    EVT_CALL(action_command_body_slam_MashActionCommandInit, 0, 92, 3, 0)
                    EVT_SET(LocalFlag(2), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(2), 1)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LocalFlag(0), 0)
            EVT_EXEC_GET_TID(N(8023A584), LVarA)
            EVT_LOOP(30)
                EVT_CALL(CheckButtonDown, 0x00008000, LVar0)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_KILL_THREAD(LVarA)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 149, 0, 1, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x2020)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_10)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_THREAD
            EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 15, 0)
            EVT_SET(LVar0, 0)
            EVT_LOOP(10)
                EVT_ADD(LVar0, -72)
                EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        EVT_END_THREAD
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 60, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 10)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
        EVT_THREAD
            EVT_CALL(func_80238244_6FAF54)
        EVT_END_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
        EVT_CALL(ResetActorSounds, ACTOR_PARTNER, 0)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(143)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
        EVT_CASE_EQ(144)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 3)
        EVT_CASE_EQ(145)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 5)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x2020)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_10)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 3)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_ELSE
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_10)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, 1, 0, LVarF, 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, 1, 0, LVarE, 48)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(N(8023A1AC))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_EXEC_WAIT(N(80239E8C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8023B228) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_BOMB)
    EVT_CALL(func_802A9000_427A70)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(146)
            EVT_CALL(GetActorLevel, 256, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EVT_END_SWITCH
        EVT_CASE_EQ(147)
            EVT_CALL(GetActorLevel, 256, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EVT_END_SWITCH
        EVT_CASE_EQ(148)
            EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_48)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(146)
            EVT_CALL(InitTargetIterator)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
        EVT_CASE_EQ(147)
            EVT_CALL(InitTargetIterator)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
        EVT_CASE_EQ(148)
            EVT_CALL(InitTargetIterator)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(146)
            EVT_CALL(action_command_bomb_MashActionCommandInit, 0, 57, 3, 0)
        EVT_CASE_EQ(147)
            EVT_CALL(action_command_bomb_MashActionCommandInit, 0, 72, 3, 1)
        EVT_CASE_EQ(148)
            EVT_CALL(action_command_bomb_MashActionCommandInit, 0, 87, 3, 2)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x287)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_9)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(146)
                EVT_SET(LVar0, 45)
            EVT_CASE_EQ(147)
                EVT_SET(LVar0, 50)
            EVT_CASE_EQ(148)
                EVT_SET(LVar0, 50)
        EVT_END_SWITCH
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 45)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1A)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(146)
            EVT_SET(LVar0, 45)
        EVT_CASE_EQ(147)
            EVT_SET(LVar0, 50)
        EVT_CASE_EQ(148)
            EVT_SET(LVar0, 50)
    EVT_END_SWITCH
    EVT_WAIT(LVar0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(146)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, 16, 0, 1, 16)
    EVT_END_SWITCH
    EVT_CALL(StopSound, 647)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(146)
            EVT_SET(LVar0, 7)
        EVT_CASE_EQ(147)
            EVT_SET(LVar0, 12)
        EVT_CASE_EQ(148)
            EVT_SET(LVar0, 20)
    EVT_END_SWITCH
    EVT_LOOP(LVar0)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 8)
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_CALL(func_80238358_6FB068, LVar0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80238000_6FAD10, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(146)
                EVT_IF_GT(LVarA, 0)
                    EVT_CALL(StartRumble, 4)
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.75))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(4.5))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(6.0))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(2.25))
                    EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.45))
                    EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.15))
                EVT_ELSE
                    EVT_CALL(StartRumble, 4)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.4))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.4))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.2))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.64))
                    EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.24))
                    EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.08))
                EVT_END_IF
            EVT_CASE_EQ(147)
                EVT_IF_GT(LVarA, 0)
                    EVT_CALL(StartRumble, 5)
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.75))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(4.5))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(6.0))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(2.25))
                    EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.45))
                    EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.15))
                EVT_ELSE
                    EVT_CALL(StartRumble, 5)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.4))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(2.4))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.2))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.64))
                    EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.24))
                    EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.08))
                EVT_END_IF
            EVT_CASE_EQ(148)
                EVT_IF_GT(LVarA, 0)
                    EVT_CALL(StartRumble, 6)
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(6.0))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(8.0))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.6))
                    EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.2))
                EVT_ELSE
                    EVT_CALL(StartRumble, 6)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
                    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(1.5))
                    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.8))
                    EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(0.3))
                    EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.1))
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(146)
            EVT_CASE_EQ(147)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
                EVT_WAIT(8)
                EVT_IF_GT(LVarA, 0)
                    EVT_CALL(PlayEffect, EFFECT_RED_IMPACT, 0, LVar0, 0, LVar2, 1, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_ELSE
                    EVT_CALL(PlayEffect, EFFECT_RED_IMPACT, 1, LVar0, 0, LVar2, 1, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_END_IF
            EVT_CASE_EQ(148)
                EVT_SET(LVarA, 0)
                EVT_WAIT(10)
                EVT_CALL(func_80238000_6FAD10, 88, 33, 5)
                EVT_WAIT(10)
                EVT_CALL(func_80238000_6FAD10, 18, 73, 5)
                EVT_WAIT(10)
                EVT_CALL(func_80238000_6FAD10, 120, 19, 5)
                EVT_WAIT(10)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(146)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON1)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 1, 16)
            EVT_IF_EQ(LVar0, 6)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActionSuccessCopy, LVar0)
            EVT_CALL(func_80238358_6FB068, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_GT(0)
                    EVT_CALL(PartnerDamageEnemy, LVar0, 268435968, 0, 0, LVarF, 112)
                    EVT_SET(LocalFlag(0), 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(PartnerDamageEnemy, LVar0, 268435968, 0, 0, LVarF, 48)
            EVT_END_SWITCH
        EVT_CASE_EQ(147)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON1)
            EVT_LABEL(5)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 1, 16)
            EVT_IF_EQ(LVar0, 6)
                EVT_GOTO(6)
            EVT_END_IF
            EVT_CALL(GetActionSuccessCopy, LVar0)
            EVT_CALL(func_8023849C_6FB1AC, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_GT(0)
                    EVT_CALL(PartnerDamageEnemy, LVar0, 805306880, 0, 0, LVarF, 112)
                    EVT_SET(LocalFlag(0), 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(PartnerDamageEnemy, LVar0, 805306880, 0, 0, LVarF, 48)
            EVT_END_SWITCH
            EVT_LABEL(6)
            EVT_CALL(ChooseNextTarget, 0, LVar0)
            EVT_IF_NE(LVar0, -1)
                EVT_GOTO(5)
            EVT_END_IF
        EVT_CASE_EQ(148)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON3)
            EVT_LABEL(10)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 1, 16)
            EVT_IF_EQ(LVar0, 6)
                EVT_GOTO(11)
            EVT_END_IF
            EVT_CALL(GetActionSuccessCopy, LVar0)
            EVT_CALL(func_80238590_6FB2A0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_GT(0)
                    EVT_CALL(PartnerDamageEnemy, LVar0, 805306880, 0, 0, LVarF, 112)
                    EVT_SET(LocalFlag(0), 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(PartnerDamageEnemy, LVar0, 805306880, 0, 0, LVarF, 48)
            EVT_END_SWITCH
            EVT_LABEL(11)
            EVT_WAIT(5)
            EVT_CALL(ChooseNextTarget, 0, LVar0)
            EVT_IF_NE(LVar0, -1)
                EVT_GOTO(10)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_GT(LocalFlag(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
        EVT_CALL(MoveBattleCamOver, 10)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(80)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_ADD(LVar0, 33)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, 0)
            EVT_WAIT(50)
            EVT_CALL(func_80280818)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 25)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8023C990) = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x287)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_11)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1A)
    EVT_WAIT(5)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 16, 0, 1, 16)
    EVT_WAIT(10)
    EVT_CALL(StopSound, 647)
    EVT_LOOP(7)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_SET(LVarA, 0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80238000_6FAD10, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 8)
    EVT_THREAD
        EVT_CALL(StartRumble, 4)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.75))
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(4.5))
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(2.25))
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.2))
        EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(0.45))
        EVT_CALL(ShakeCam, 1, 0, 8, EVT_FLOAT(0.15))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON1)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 1, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVarF, 1)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(143)
            EVT_SET(LVarF, 5)
        EVT_CASE_EQ(144)
            EVT_SET(LVarF, 6)
        EVT_CASE_EQ(145)
            EVT_SET(LVarF, 7)
    EVT_END_SWITCH
    EVT_CALL(PartnerDamageEnemy, LVar0, 268435968, 0, 0, LVarF, 48)
    EVT_LABEL(10)
    EVT_SET(LVar0, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(80)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_ADD(LVar0, 33)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, 0)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 25)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_1B)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
