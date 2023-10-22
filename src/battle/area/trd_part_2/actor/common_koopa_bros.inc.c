#include "../area.h"
#include "boss.h"

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TakeTurn);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

s32 N(DefaultDefense)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(ToppledDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               THIS_SLEEP_CHANCE,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               THIS_DIZZY_CHANCE,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            THIS_PARALYZE_CHANCE,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,               75,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 36 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefaultDefense),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = THIS_ACTOR_TYPE,
    .level = THIS_LEVEL,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 0,
    .size = { 38, 42 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    THIS_ANIM_IDLE,
    STATUS_KEY_STONE,     THIS_ANIM_STILL,
    STATUS_KEY_SLEEP,     THIS_ANIM_SLEEP,
    STATUS_KEY_POISON,    THIS_ANIM_STILL,
    STATUS_KEY_STOP,      THIS_ANIM_STILL,
    STATUS_KEY_STATIC,    THIS_ANIM_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_STILL,
    STATUS_KEY_DIZZY,     THIS_ANIM_DIZZY,
    STATUS_KEY_DIZZY,     THIS_ANIM_DIZZY,
    STATUS_END,
};

s32 N(TowerAnims)[] = {
    STATUS_KEY_NORMAL,    THIS_ANIM_TOWER_IDLE,
    STATUS_KEY_STONE,     THIS_ANIM_TOWER_STILL,
    STATUS_KEY_POISON,    THIS_ANIM_TOWER_STILL,
    STATUS_KEY_STOP,      THIS_ANIM_TOWER_STILL,
    STATUS_KEY_STATIC,    THIS_ANIM_TOWER_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_TOWER_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_TOWER_STILL,
    STATUS_END,
};

s32 N(TippingAnims)[] = {
    STATUS_KEY_NORMAL,    THIS_ANIM_TIPPING_IDLE,
    STATUS_KEY_STONE,     THIS_ANIM_TOWER_STILL,
    STATUS_KEY_POISON,    THIS_ANIM_TOWER_STILL,
    STATUS_KEY_STOP,      THIS_ANIM_TOWER_STILL,
    STATUS_KEY_STATIC,    THIS_ANIM_TOWER_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_TOWER_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_TOWER_STILL,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    THIS_ANIM_TOPPLE_IDLE,
    STATUS_KEY_STONE,     THIS_ANIM_TOPPLE_STILL,
    STATUS_KEY_SLEEP,     THIS_ANIM_TOPPLE_STILL,
    STATUS_KEY_POISON,    THIS_ANIM_TOPPLE_STILL,
    STATUS_KEY_STOP,      THIS_ANIM_TOPPLE_STILL,
    STATUS_KEY_STATIC,    THIS_ANIM_TOPPLE_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_TOPPLE_STILL,
    STATUS_KEY_PARALYZE,  THIS_ANIM_TOPPLE_STILL,
    STATUS_KEY_DIZZY,     THIS_ANIM_TOPPLE_DIZZY,
    STATUS_KEY_DIZZY,     THIS_ANIM_TOPPLE_DIZZY,
    STATUS_END,
};

s32 N(BasicHurtAnims)[] = {
    STATUS_KEY_NORMAL,    THIS_ANIM_HURT_STILL,
    STATUS_END,
};

s32 N(BasicToppledAnims)[] = {
    STATUS_KEY_NORMAL,    THIS_ANIM_TOPPLE_IDLE,
    STATUS_END,
};

#include "common/StartRumbleWithParams.inc.c"

BSS PlayerStatus N(DummyPlayerStatus);

API_CALLABLE(N(SpawnSpinEffect)) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    N(DummyPlayerStatus).pos.x = posX;
    N(DummyPlayerStatus).pos.y = posY - 10.0f;
    N(DummyPlayerStatus).pos.z = posZ;

    fx_effect_46(6, &N(DummyPlayerStatus), 1.0f, duration);
    return ApiStatus_DONE2;
}

Actor* N(GetKoopaBrosWithState)(s32 state) {
    Actor* actor = get_actor(GREEN_ACTOR);
    if (actor != NULL && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    actor = get_actor(YELLOW_ACTOR);
    if (actor != NULL && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    actor = get_actor(BLACK_ACTOR);
    if (actor != NULL && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    actor = get_actor(RED_ACTOR);
    if (actor != NULL && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    return NULL;
}

API_CALLABLE(N(GetTowerFallPosition)) {
    Bytecode* args = script->ptrReadPos;
    Vec3f temp;
    Vec3f fallPositions[4];
    s32 height;
    s32 ownerState;
    Actor* enemy;
    Vec3f* iVec;
    Vec3f* jVec;
    s32 i, j;

    height = get_actor(BOSS_ACTOR)->state.varTable[AVAR_Boss_TowerHeight];
    switch (height) {
        case 2:
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosA));
            fallPositions[0].x = enemy->homePos.x;
            fallPositions[0].y = enemy->homePos.y;
            fallPositions[0].z = enemy->homePos.z;
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosB));
            fallPositions[1].x = enemy->homePos.x;
            fallPositions[1].y = enemy->homePos.y;
            fallPositions[1].z = enemy->homePos.z;
            break;
        case 3:
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosA));
            fallPositions[0].x = enemy->homePos.x;
            fallPositions[0].y = enemy->homePos.y;
            fallPositions[0].z = enemy->homePos.z;
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosC));
            fallPositions[1].x = enemy->homePos.x;
            fallPositions[1].y = enemy->homePos.y;
            fallPositions[1].z = enemy->homePos.z;
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosB));
            fallPositions[2].x = enemy->homePos.x;
            fallPositions[2].y = enemy->homePos.y;
            fallPositions[2].z = enemy->homePos.z;
            break;
        case 4:
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosA));
            fallPositions[0].x = enemy->homePos.x;
            fallPositions[0].y = enemy->homePos.y;
            fallPositions[0].z = enemy->homePos.z;
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosD));
            fallPositions[1].x = enemy->homePos.x;
            fallPositions[1].y = enemy->homePos.y;
            fallPositions[1].z = enemy->homePos.z;
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosC));
            fallPositions[2].x = enemy->homePos.x;
            fallPositions[2].y = enemy->homePos.y;
            fallPositions[2].z = enemy->homePos.z;
            enemy = N(GetKoopaBrosWithState(AVAL_Koopa_State_PosB));
            fallPositions[3].x = enemy->homePos.x;
            fallPositions[3].y = enemy->homePos.y;
            fallPositions[3].z = enemy->homePos.z;
            break;
    }

    for (i = 0; i < height - 1; i++) {
        for (j = i; j < height; j++) {
            iVec = &fallPositions[i];
            jVec = &fallPositions[j];
            if (iVec->x < jVec->x) {
                temp = *iVec;
                *iVec = *jVec;
                *jVec = temp;
            }
        }
    }

    ownerState = get_actor(script->owner1.enemyID)->state.varTable[AVAR_Koopa_State];
    switch (height) {
        case 2:
            switch (ownerState) {
                case AVAL_Koopa_State_PosA:
                    evt_set_variable(script, *args++, fallPositions[0].x);
                    evt_set_variable(script, *args++, fallPositions[0].y);
                    evt_set_variable(script, *args++, fallPositions[0].z);
                    break;
                case AVAL_Koopa_State_PosB:
                    evt_set_variable(script, *args++, fallPositions[1].x);
                    evt_set_variable(script, *args++, fallPositions[1].y);
                    evt_set_variable(script, *args++, fallPositions[1].z);
                    break;
            }
            break;
        case 3:
            switch (ownerState) {
                case AVAL_Koopa_State_PosA:
                    evt_set_variable(script, *args++, fallPositions[0].x);
                    evt_set_variable(script, *args++, fallPositions[0].y);
                    evt_set_variable(script, *args++, fallPositions[0].z);
                    break;
                case AVAL_Koopa_State_PosC:
                    evt_set_variable(script, *args++, fallPositions[1].x);
                    evt_set_variable(script, *args++, fallPositions[1].y);
                    evt_set_variable(script, *args++, fallPositions[1].z);
                    break;
                case AVAL_Koopa_State_PosB:
                    evt_set_variable(script, *args++, fallPositions[2].x);
                    evt_set_variable(script, *args++, fallPositions[2].y);
                    evt_set_variable(script, *args++, fallPositions[2].z);
                    break;
            }
            break;
        case 4:
            switch (ownerState) {
                case AVAL_Koopa_State_PosA:
                    evt_set_variable(script, *args++, fallPositions[0].x);
                    evt_set_variable(script, *args++, fallPositions[0].y);
                    evt_set_variable(script, *args++, fallPositions[0].z);
                    break;
                case AVAL_Koopa_State_PosD:
                    evt_set_variable(script, *args++, fallPositions[1].x);
                    evt_set_variable(script, *args++, fallPositions[1].y);
                    evt_set_variable(script, *args++, fallPositions[1].z);
                    break;
                case AVAL_Koopa_State_PosC:
                    evt_set_variable(script, *args++, fallPositions[2].x);
                    evt_set_variable(script, *args++, fallPositions[2].y);
                    evt_set_variable(script, *args++, fallPositions[2].z);
                    break;
                case AVAL_Koopa_State_PosB:
                    evt_set_variable(script, *args++, fallPositions[3].x);
                    evt_set_variable(script, *args++, fallPositions[3].y);
                    evt_set_variable(script, *args++, fallPositions[3].z);
                    break;
            }
            break;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetLastActorEventType)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    actor->lastEventType = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

// respond to commands issued from BOSS_ACTOR
// (in) LVarA : event
EvtScript N(HandleCommand) = {
    EVT_CALL(SetOwnerID, THIS_ACTOR_ID)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(BOSS_CMD_STABLE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Koopa_State_PosA)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_IDLE)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(TowerAnims)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOWER_IDLE)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_UNSTABLE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_WAIT(5)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(TippingAnims)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TIPPING_IDLE)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, THIS_ANIM_HURT)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                    EVT_IF_NE(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(TippingAnims)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TIPPING_IDLE)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BasicHurtAnims)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT_STILL)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_CALL(N(GetLastActorEventType), EVENT_BURN_HIT)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, THIS_ANIM_BURN)
                    EVT_SET_CONST(LVar2, -1)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                    EVT_IF_NE(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(TippingAnims)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TIPPING_IDLE)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BasicHurtAnims)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT_STILL)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_NO_DAMAGE_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Koopa_State_PosA)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, THIS_ANIM_TOP_ENTER_SHELL)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, THIS_ANIM_ENTER_SHELL)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_EXIT_SHELL)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_WAIT(15)
        EVT_CASE_EQ(BOSS_CMD_TOPPLE_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_SET(LFlag0, FALSE)
                    EVT_IF_EQ(LVar0, AVAL_Koopa_State_PosA)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
                    EVT_CALL(N(GetTowerFallPosition), LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT_STILL)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BasicHurtAnims)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LFlag0, TRUE)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.8))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOPPLE_IDLE)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BasicToppledAnims)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefense)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Toppled)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_TOPPLE_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_SET(LFlag0, FALSE)
                    EVT_IF_EQ(LVar0, AVAL_Koopa_State_PosA)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
                    EVT_CALL(N(GetTowerFallPosition), LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_BURN)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BasicHurtAnims)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LFlag0, TRUE)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.8))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                    EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar1, LVar3)
                    EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                    EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                    EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOPPLE_IDLE)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BasicToppledAnims)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefense)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Toppled)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_TRY_GET_UP)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Koopa_State_Toppled)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, LVar0)
                    EVT_SUB(LVar0, 1)
                    EVT_IF_GT(LVar0, 0)
                        // still has topple turns left, just struggle a bit
                        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, LVar0)
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                        EVT_WAIT(20)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                    EVT_ELSE
                        // topple turns are over, koopa bros can get up
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                        EVT_WAIT(12)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                        EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
                        EVT_THREAD
                            EVT_SET(LVar0, 0)
                            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 18, 0)
                            EVT_LOOP(4)
                                EVT_ADD(LVar0, 22)
                                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                                EVT_WAIT(1)
                            EVT_END_LOOP
                        EVT_END_THREAD
                        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
                        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 36)
                        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_GotUp)
                        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultDefense)))
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_IDLE)
                        EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
                    EVT_END_IF
                EVT_CASE_DEFAULT
                    EVT_WAIT(20)
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_GET_READY)
            // if koopa just got up, change its state to ready
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Koopa_State_GotUp)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Ready)
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_SPIN_ATTACK)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Koopa_State_PosA)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_ENTER_SHELL)
                    EVT_WAIT(10)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_TOWER_SPIN_3)
                        EVT_CASE_EQ(3)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_TOWER_SPIN_2)
                        EVT_CASE_EQ(2)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_TOWER_SPIN_1)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_SHELL_SPIN)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 60)
                    EVT_WAIT(60)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
                        EVT_SWITCH(LVar0)
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVarA)
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        EVT_IF_GT(LVar0, LVar3)
                            EVT_WAIT(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar1)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_LAUNCH_SHELL)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(13.0))
                        EVT_CASE_EQ(3)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                    EVT_END_SWITCH
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                    EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                    EVT_SET(LVar4, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVarB)
                    EVT_SET(LVar0, LVarB)
                    EVT_SUB(LVar0, 1)
                    EVT_MUL(LVar0, 18)
                    EVT_SWITCH(LVarB)
                        EVT_CASE_EQ(4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -10)
                        EVT_CASE_EQ(3)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -7)
                        EVT_CASE_EQ(2)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -4)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 60)
                            EVT_WAIT(60)
                        EVT_CASE_EQ(3)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 50)
                            EVT_WAIT(50)
                        EVT_CASE_EQ(2)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 40)
                            EVT_WAIT(40)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_POINT)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 22)
                    EVT_ADD(LVar1, 19)
                    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_IDLE)
                    EVT_WAIT(20)
                    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_TowerState, 0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_ENTER_SHELL)
                    EVT_WAIT(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_SHELL_SPIN)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 60)
                    EVT_WAIT(60)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(AVAL_Koopa_State_PosD)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(AVAL_Koopa_State_PosC)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                        EVT_CASE_EQ(AVAL_Koopa_State_PosB)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_END_SWITCH
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(AVAL_Koopa_State_PosD)
                            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 36, -7)
                        EVT_CASE_EQ(AVAL_Koopa_State_PosC)
                            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 18, -4)
                        EVT_CASE_EQ(AVAL_Koopa_State_PosB)
                            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(AVAL_Koopa_State_PosD)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 50)
                            EVT_WAIT(50)
                        EVT_CASE_EQ(AVAL_Koopa_State_PosC)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 40)
                            EVT_WAIT(40)
                        EVT_CASE_EQ(AVAL_Koopa_State_PosB)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 30)
                            EVT_WAIT(30)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_EXIT_SHELL)
                    EVT_WAIT(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOWER_IDLE)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(BOSS_CMD_SOLO_ATTACK)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Koopa_State_Ready)
                    EVT_CALL(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SET(LVar2, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_RUN)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_ENTER_SHELL)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_SPINUP)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_SHELL_SPIN)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 30)
                    EVT_WAIT(30)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
                        EVT_SWITCH(LVar0)
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        EVT_IF_GT(LVar0, LVar3)
                            EVT_WAIT(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_LAUNCH_SHELL)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SET(LVar2, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 30)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_POINT)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 22)
                    EVT_ADD(LVar1, 19)
                    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_RUN)
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_DoingSoloAttack)
                    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Ready)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_HURT)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_BURN)
            EVT_SET_CONST(LVar2, THIS_ANIM_BURN_STILL)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_BURN)
            EVT_SET_CONST(LVar2, THIS_ANIM_BURN_STILL)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_BURN_STILL)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_HURT)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_HURT)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_HURT)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Toppled)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 2)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefense)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_Koopa_State_Ready)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_THREAD
                    EVT_WAIT(4)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                    EVT_WAIT(1)
                EVT_END_THREAD
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOPPLE_IDLE)
            EVT_END_IF
            EVT_USE_BUF(EVT_PTR(N(FlipPosOffsets)))
            EVT_LOOP(ARRAY_COUNT(N(FlipPosOffsets)))
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_Koopa_State_Ready)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, THIS_ANIM_TOP_ENTER_SHELL)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                    EVT_WAIT(10)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, THIS_ANIM_TOPPLE_IDLE)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_HURT)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, THIS_ANIM_HURT)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_Koopa_State_Ready)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, THIS_ANIM_IDLE)
                EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_END
};
