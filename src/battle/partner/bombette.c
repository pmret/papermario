#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBombette.h"
#include "battle/action_cmd/bomb.h"
#include "battle/action_cmd/body_slam.h"

#define NAMESPACE battle_partner_bombette

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);
extern EvtScript N(celebrate);
extern EvtScript N(executeAction);
extern EvtScript N(firstStrikeBodySlam);
extern EvtScript N(firstStrike);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(bodySlam);
extern EvtScript N(bomb);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum {
    LF_MashEnded    = LFlag0,
    LF_MashStarted  = LFlag2,
};

API_CALLABLE(N(PlayExplosionFX)) {
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
        case MOVE_BOMB:
            if (script->varTable[10] > 0) {
                fx_explosion(1, x, y + 20, z);
            } else {
                fx_explosion(0, x, y + 20, z);
            }
            sfx_play_sound(SOUND_CANNON1);
            break;
        case MOVE_POWER_BOMB:
            if (script->varTable[10] > 0) {
                fx_explosion(1, x, y + 20, z);
            } else {
                fx_explosion(0, x, y + 20, z);
            }
            sfx_play_sound(SOUND_CANNON2);
            break;
        case MOVE_MEGA_BOMB:
            if (script->varTable[10] > 0) {
                fx_explosion(2, x, y + 20, z);
            } else {
                fx_explosion(1, x, y + 20, z);
            }
            sfx_play_sound(SOUND_CANNON2);
            break;
        default:
            fx_explosion(0, x, y + 20, z);
            sfx_play_sound(SOUND_CANNON1);
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SlowDown)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorState* partnerActorMovement = &partnerActor->state;

    if (isInitialCall) {
        partnerActor->state.curPos.x = partnerActor->curPos.x;
        partnerActor->state.curPos.y = partnerActor->curPos.y;
        partnerActor->state.curPos.z = partnerActor->curPos.z;
    }

    add_xz_vec3f(&partnerActorMovement->curPos, partnerActor->state.speed, partnerActor->state.angle);

    if (partnerActor->state.speed < 4.0f) {
        play_movement_dust_effects(0, partnerActor->state.curPos.x, partnerActor->state.curPos.y,
                                   partnerActor->state.curPos.z, partnerActor->state.angle);
    } else {
        play_movement_dust_effects(1, partnerActor->state.curPos.x, partnerActor->state.curPos.y,
                                   partnerActor->state.curPos.z, partnerActor->state.angle);
    }

    partnerActorMovement->speed /= 1.5;

    partnerActor->curPos.x = partnerActorMovement->curPos.x;
    partnerActor->curPos.y = partnerActorMovement->curPos.y;
    partnerActor->curPos.z = partnerActorMovement->curPos.z;

    if (partnerActorMovement->speed < 1.0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(GetBombDamage)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 mashResult = evt_get_variable(script, *args++);
    s32 damage = 0;

    switch (partnerActor->actorBlueprint->level) {
        case 0:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 2;
            } else if (mashResult <= 80) {
                damage = 3;
            } else if (mashResult <= 99) {
                damage = 4;
            } else {
                damage = 5;
            }
            break;
        case 1:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 4;
            } else if (mashResult <= 99) {
                damage = 5;
            } else {
                damage = 6;
            }
            break;
        case 2:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 5;
            } else if (mashResult <= 99) {
                damage = 6;
            } else {
                damage = 7;
            }
            break;
    }


    if (!(mashResult < 100)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = damage;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPowerBombDamage)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 mashResult = evt_get_variable(script, *args++);
    s32 damage = 0;

    switch (partnerActor->actorBlueprint->level) {
        case 1:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 4;
            } else if (mashResult <= 99) {
                damage = 5;
            } else {
                damage = 6;
            }
            break;
        case 2:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 5;
            } else if (mashResult <= 99) {
                damage = 6;
            } else {
                damage = 7;
            }
    }


    if (!(mashResult < 100)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = damage;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetMegaBombDamage)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 mashResult = evt_get_variable(script, *args++);
    s32 damage = 0;

    switch (partnerActor->actorBlueprint->level) {
        case 2:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 5;
            } else if (mashResult <= 99) {
                damage = 6;
            } else {
                damage = 7;
            }
            break;
    }


    if (!(mashResult < 100)) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    script->varTable[15] = damage;

    return ApiStatus_DONE2;
}

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBombette_Walk,
    STATUS_KEY_STONE,     ANIM_BattleBombette_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBombette_Sleep,
    STATUS_KEY_POISON,    ANIM_BattleBombette_Still,
    STATUS_KEY_STOP,      ANIM_BattleBombette_Still,
    STATUS_KEY_DAZE,      ANIM_BattleBombette_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleBombette_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 9, 20 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOMBETTE,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_PARTNER, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_PARTNER, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_PARTNER, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_PARTNER, EVT_PTR(N(nextTurn)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(StopSound, SOUND_287)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_SET_CONST(LVar2, ANIM_BattleBombette_Backfire2)
            EVT_EXEC_WAIT(EVS_Partner_Hit)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_SET(LVar2, 15)
            EVT_SET_CONST(LVar3, ANIM_BattleBombette_Injured)
            EVT_EXEC_WAIT(EVS_Partner_BombetteSpikeContact)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleBombette_BurnStill)
            EVT_EXEC_WAIT(EVS_Partner_BurnHit)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVarA, 0)
            EVT_CALL(N(PlayExplosionFX), LVar0, LVar1, LVar2)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(3.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(1.5))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.8))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.3))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.1))
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
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_61)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleBombette_BurnHurt, ANIM_BattleBombette_BurnHurt, ANIM_BattleBombette_BurnHurt)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BurnHurt)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleBombette_BurnStill)
            EVT_EXEC_WAIT(EVS_Partner_BurnHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVarA, 0)
            EVT_CALL(N(PlayExplosionFX), LVar0, LVar1, LVar2)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(3.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(1.5))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.8))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.3))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.1))
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
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_SET(LVar2, 15)
            EVT_SET_CONST(LVar3, ANIM_BattleBombette_Injured)
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
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Fall)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVarA, 0)
            EVT_CALL(N(PlayExplosionFX), LVar0, LVar1, LVar2)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(3.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(1.5))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.8))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.3))
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.1))
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
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Idle)
            EVT_SET_CONST(LVar2, ANIM_BattleBombette_Run)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(EVS_Partner_Recover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBombette_Block)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(firstStrike))
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(executeAction))
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(N(celebrate))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(runAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(runAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(celebrate) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BattleBombette_CelebrateLoop)
    EVT_SET_CONST(LVar2, ANIM_BattleBombette_Celebrate)
    EVT_SET_CONST(LVar3, ANIM_BattleBombette_Idle)
    EVT_EXEC_WAIT(EVS_Partner_Celebrate)
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BODY_SLAM1)
            EVT_EXEC_WAIT(N(bodySlam))
        EVT_CASE_EQ(MOVE_BODY_SLAM2)
            EVT_EXEC_WAIT(N(bodySlam))
        EVT_CASE_EQ(MOVE_BODY_SLAM3)
            EVT_EXEC_WAIT(N(bodySlam))
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_EXEC_WAIT(N(bomb))
        EVT_CASE_EQ(MOVE_POWER_BOMB)
            EVT_EXEC_WAIT(N(bomb))
        EVT_CASE_EQ(MOVE_MEGA_BOMB)
            EVT_EXEC_WAIT(N(bomb))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(firstStrike) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BODY_SLAM1)
            EVT_EXEC_WAIT(N(firstStrikeBodySlam))
        EVT_CASE_EQ(MOVE_BODY_SLAM2)
            EVT_EXEC_WAIT(N(firstStrikeBodySlam))
        EVT_CASE_EQ(MOVE_BODY_SLAM3)
            EVT_EXEC_WAIT(N(firstStrikeBodySlam))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BattleBombette_Run)
    EVT_EXEC_WAIT(EVS_Partner_RunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome2) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 25, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_SUB(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EVT_WAIT(8)
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_SUB(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EVT_WAIT(8)
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(runToTarget) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 35)
    EVT_RETURN
    EVT_END
};

EvtScript N(animBrace) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Brace)
    EVT_LOOP(15)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(animHold) = {
    EVT_LOOP(15)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(bodySlam) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_BODY_SLAM)
    EVT_CALL(action_command_body_slam_init)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_48)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
    EVT_SET(LF_MashStarted, 0)
    EVT_LOOP(60)
        EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_SET(LF_MashStarted, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(MoveBattleCamOver, 65)
    EVT_IF_EQ(LF_MashStarted, 1)
        EVT_CALL(action_command_body_slam_start, 0, 92, 3, 0)
        EVT_SET(LF_MashEnded, 0)
        EVT_EXEC_GET_TID(N(runToTarget), LVarA)
        EVT_LOOP(35)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_SET(LF_MashEnded, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LF_MashEnded, 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LF_MashEnded, 0)
        EVT_EXEC_GET_TID(N(animBrace), LVarA)
        EVT_LOOP(30)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_SET(LF_MashEnded, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LF_MashEnded, 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LF_MashEnded, 0)
            EVT_EXEC_GET_TID(N(animHold), LVarA)
            EVT_LOOP(30)
                EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LF_MashEnded, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LF_MashEnded, 1)
                EVT_KILL_THREAD(LVarA)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LF_MashEnded, 0)
        EVT_EXEC_GET_TID(N(runToTarget), LVarA)
        EVT_LOOP(35)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_IF_EQ(LF_MashStarted, 0)
                    EVT_CALL(action_command_body_slam_start, 0, 92, 3, 0)
                    EVT_SET(LF_MashStarted, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LF_MashStarted, 1)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LF_MashEnded, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LF_MashEnded, 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LF_MashEnded, 0)
        EVT_EXEC_GET_TID(N(animBrace), LVarA)
        EVT_LOOP(30)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_IF_EQ(LF_MashStarted, 0)
                    EVT_CALL(action_command_body_slam_start, 0, 92, 3, 0)
                    EVT_SET(LF_MashStarted, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LF_MashStarted, 1)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LF_MashEnded, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LF_MashEnded, 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LF_MashEnded, 0)
            EVT_EXEC_GET_TID(N(animHold), LVarA)
            EVT_LOOP(30)
                EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_SET(LF_MashEnded, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LF_MashEnded, 1)
                EVT_KILL_THREAD(LVarA)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2020)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BodySlam)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
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
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        EVT_THREAD
            EVT_CALL(N(SlowDown))
        EVT_END_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
        EVT_CALL(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BODY_SLAM1)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
        EVT_CASE_EQ(MOVE_BODY_SLAM2)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 3)
        EVT_CASE_EQ(MOVE_BODY_SLAM3)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 5)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2020)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BodySlam)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 3)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EVT_ELSE
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BodySlam)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP, 0, LVarF, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP, 0, LVarE, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(bomb) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_BOMB)
    EVT_CALL(action_command_bomb_init)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_CALL(GetActorLevel, ACTOR_PARTNER, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EVT_END_SWITCH
        EVT_CASE_EQ(MOVE_POWER_BOMB)
            EVT_CALL(GetActorLevel, ACTOR_PARTNER, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EVT_END_SWITCH
        EVT_CASE_EQ(MOVE_MEGA_BOMB)
            EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_48)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_CALL(InitTargetIterator)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
        EVT_CASE_EQ(MOVE_POWER_BOMB)
            EVT_CALL(InitTargetIterator)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
        EVT_CASE_EQ(MOVE_MEGA_BOMB)
            EVT_CALL(InitTargetIterator)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(MoveBattleCamOver, 60 * DT)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_CALL(action_command_bomb_start, 0, 57 * DT, 3, 0)
        EVT_CASE_EQ(MOVE_POWER_BOMB)
            EVT_CALL(action_command_bomb_start, 0, 73 * DT - 1, 3, 1)
        EVT_CASE_EQ(MOVE_MEGA_BOMB)
            EVT_CALL(action_command_bomb_start, 0, 87 * DT, 3, 2)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_287)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_RunLit)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(MOVE_BOMB)
                EVT_SET(LVar0, 45 * DT)
            EVT_CASE_EQ(MOVE_POWER_BOMB)
                EVT_SET(LVar0, 50 * DT)
            EVT_CASE_EQ(MOVE_MEGA_BOMB)
                EVT_SET(LVar0, 50 * DT)
        EVT_END_SWITCH
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 45 * DT)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_AboutToExplode)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_SET(LVar0, 45 * DT)
        EVT_CASE_EQ(MOVE_POWER_BOMB)
            EVT_SET(LVar0, 50 * DT)
        EVT_CASE_EQ(MOVE_MEGA_BOMB)
            EVT_SET(LVar0, 50 * DT)
    EVT_END_SWITCH
    EVT_WAIT(LVar0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(StopSound, SOUND_287)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_SET(LVar0, 6 * DT + 1)
        EVT_CASE_EQ(MOVE_POWER_BOMB)
            EVT_SET(LVar0, 12 * DT)
        EVT_CASE_EQ(MOVE_MEGA_BOMB)
            EVT_SET(LVar0, 20 * DT)
    EVT_END_SWITCH
    EVT_LOOP(LVar0)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 8)
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_CALL(N(GetBombDamage), LVar0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(N(PlayExplosionFX), LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(MOVE_BOMB)
                EVT_IF_GT(LVarA, 0)
                    EVT_CALL(StartRumble, 4)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.75))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(4.5))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(6.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(2.25))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.45))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.15))
                EVT_ELSE
                    EVT_CALL(StartRumble, 4)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.4))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.4))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.2))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.64))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.24))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.08))
                EVT_END_IF
            EVT_CASE_EQ(MOVE_POWER_BOMB)
                EVT_IF_GT(LVarA, 0)
                    EVT_CALL(StartRumble, 5)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.75))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(4.5))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(6.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(2.25))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.45))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.15))
                EVT_ELSE
                    EVT_CALL(StartRumble, 5)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.4))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(2.4))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.2))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(1.2))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.64))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.24))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.08))
                EVT_END_IF
            EVT_CASE_EQ(MOVE_MEGA_BOMB)
                EVT_IF_GT(LVarA, 0)
                    EVT_CALL(StartRumble, 6)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(6.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(8.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.6))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.2))
                EVT_ELSE
                    EVT_CALL(StartRumble, 6)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(4.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(1.5))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.8))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(0.3))
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.1))
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(MOVE_BOMB)
            EVT_CASE_EQ(MOVE_POWER_BOMB)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
                EVT_WAIT(8)
                EVT_IF_GT(LVarA, 0)
                    EVT_PLAY_EFFECT(EFFECT_RED_IMPACT, 0, LVar0, 0, LVar2, 1, 0, 0)
                EVT_ELSE
                    EVT_PLAY_EFFECT(EFFECT_RED_IMPACT, 1, LVar0, 0, LVar2, 1, 0, 0)
                EVT_END_IF
            EVT_CASE_EQ(MOVE_MEGA_BOMB)
                EVT_SET(LVarA, 0)
                EVT_WAIT(10)
                EVT_CALL(N(PlayExplosionFX), 88, 33, 5)
                EVT_WAIT(10)
                EVT_CALL(N(PlayExplosionFX), 18, 73, 5)
                EVT_WAIT(10)
                EVT_CALL(N(PlayExplosionFX), 120, 19, 5)
                EVT_WAIT(10)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_SET(LF_MashEnded, 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BOMB)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON1)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
            EVT_IF_EQ(LVar0, 6)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActionSuccessCopy, LVar0)
            EVT_CALL(N(GetBombDamage), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_GT(0)
                    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarF, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
                    EVT_SET(LF_MashEnded, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarF, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
            EVT_END_SWITCH
        EVT_CASE_EQ(MOVE_POWER_BOMB)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON1)
            EVT_LABEL(5)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
            EVT_IF_EQ(LVar0, 6)
                EVT_GOTO(6)
            EVT_END_IF
            EVT_CALL(GetActionSuccessCopy, LVar0)
            EVT_CALL(N(GetPowerBombDamage), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_GT(0)
                    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
                    EVT_SET(LF_MashEnded, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
            EVT_END_SWITCH
            EVT_LABEL(6)
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_IF_NE(LVar0, -1)
                EVT_GOTO(5)
            EVT_END_IF
        EVT_CASE_EQ(MOVE_MEGA_BOMB)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON3)
            EVT_LABEL(10)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
            EVT_IF_EQ(LVar0, 6)
                EVT_GOTO(11)
            EVT_END_IF
            EVT_CALL(GetActionSuccessCopy, LVar0)
            EVT_CALL(N(GetMegaBombDamage), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_GT(0)
                    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
                    EVT_SET(LF_MashEnded, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
            EVT_END_SWITCH
            EVT_LABEL(11)
            EVT_WAIT(5)
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_IF_NE(LVar0, -1)
                EVT_GOTO(10)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_GT(LF_MashEnded, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
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
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            EVT_WAIT(50)
            EVT_CALL(PartnerYieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 25)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(firstStrikeBodySlam) = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_287)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_11)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_AboutToExplode)
    EVT_WAIT(5)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_WAIT(10)
    EVT_CALL(StopSound, SOUND_287)
    EVT_LOOP(7)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_SET(LVarA, 0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(N(PlayExplosionFX), LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 8)
    EVT_THREAD
        EVT_CALL(StartRumble, 4)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.75))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(4.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(2.25))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.2))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.45))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.15))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CANNON1)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVarF, 1)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_BODY_SLAM1)
            EVT_SET(LVarF, 5)
        EVT_CASE_EQ(MOVE_BODY_SLAM2)
            EVT_SET(LVarF, 6)
        EVT_CASE_EQ(MOVE_BODY_SLAM3)
            EVT_SET(LVarF, 7)
    EVT_END_SWITCH
    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarF, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
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
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            EVT_WAIT(50)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 25)
            EVT_ADD(LVar1, 200)
            EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
            EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(0.6))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
