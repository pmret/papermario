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
    if (actor != nullptr && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    actor = get_actor(YELLOW_ACTOR);
    if (actor != nullptr && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    actor = get_actor(BLACK_ACTOR);
    if (actor != nullptr && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    actor = get_actor(RED_ACTOR);
    if (actor != nullptr && actor->state.varTable[AVAR_Koopa_State] == state) {
        return actor;
    }

    return nullptr;
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
    Call(SetOwnerID, THIS_ACTOR_ID)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNe(LVar0, 0)
        Return
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Switch(LVarA)
        CaseEq(BOSS_CMD_STABLE)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Koopa_State_PosA)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_IDLE)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(TowerAnims)))
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOWER_IDLE)
                EndCaseGroup
            EndSwitch
        CaseEq(BOSS_CMD_UNSTABLE)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Wait(5)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(TippingAnims)))
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TIPPING_IDLE)
                EndCaseGroup
            EndSwitch
        CaseEq(BOSS_CMD_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, THIS_ANIM_HURT)
                    ExecWait(EVS_Enemy_Hit)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    BitwiseAndConst(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                    IfNe(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(TippingAnims)))
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TIPPING_IDLE)
                    Else
                        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BasicHurtAnims)))
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT_STILL)
                    EndIf
                EndCaseGroup
            EndSwitch
        CaseEq(BOSS_CMD_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Call(N(GetLastActorEventType), EVENT_BURN_HIT)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, THIS_ANIM_BURN)
                    SetConst(LVar2, -1)
                    ExecWait(EVS_Enemy_BurnHit)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    BitwiseAndConst(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                    IfNe(LVar0, AFLAG_Boss_PlayerHitTower | AFLAG_Boss_PartnerHitTower)
                        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(TippingAnims)))
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TIPPING_IDLE)
                    Else
                        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BasicHurtAnims)))
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT_STILL)
                    EndIf
                EndCaseGroup
            EndSwitch
        CaseEq(BOSS_CMD_NO_DAMAGE_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Koopa_State_PosA)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, THIS_ANIM_TOP_ENTER_SHELL)
                    ExecWait(EVS_Enemy_NoDamageHit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, THIS_ANIM_ENTER_SHELL)
                    ExecWait(EVS_Enemy_NoDamageHit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_EXIT_SHELL)
                EndCaseGroup
            EndSwitch
            Wait(15)
        CaseEq(BOSS_CMD_TOPPLE_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Set(LFlag0, false)
                    IfEq(LVar0, AVAL_Koopa_State_PosA)
                        Set(LFlag0, true)
                    EndIf
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
                    Call(N(GetTowerFallPosition), LVar0, LVar1, LVar2)
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT_STILL)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BasicHurtAnims)))
                    Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
                    IfEq(LFlag0, true)
                        Call(N(StartRumbleWithParams), 256, 5)
                        Thread
                            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.8))
                        EndThread
                    EndIf
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOPPLE_IDLE)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BasicToppledAnims)))
                    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
                    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
                    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, false)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, false)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(HPBarToHome, ACTOR_SELF)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
                    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefense)))
                    Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Toppled)
                    Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 2)
                    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
                EndCaseGroup
            EndSwitch
        CaseEq(BOSS_CMD_TOPPLE_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Set(LFlag0, false)
                    IfEq(LVar0, AVAL_Koopa_State_PosA)
                        Set(LFlag0, true)
                    EndIf
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
                    Call(N(GetTowerFallPosition), LVar0, LVar1, LVar2)
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_BURN)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BasicHurtAnims)))
                    Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
                    IfEq(LFlag0, true)
                        Call(N(StartRumbleWithParams), 256, 5)
                        Thread
                            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.8))
                        EndThread
                    EndIf
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                    DivF(LVar3, Float(2.0))
                    AddF(LVar1, LVar3)
                    AddF(LVar2, Float(5.0))
                    DivF(LVar3, Float(10.0))
                    PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOPPLE_IDLE)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BasicToppledAnims)))
                    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
                    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
                    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, false)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, false)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(HPBarToHome, ACTOR_SELF)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
                    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefense)))
                    Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Toppled)
                    Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 2)
                    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
                EndCaseGroup
            EndSwitch
        CaseEq(BOSS_CMD_TRY_GET_UP)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Koopa_State_Toppled)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, LVar0)
                    Sub(LVar0, 1)
                    IfGt(LVar0, 0)
                        // still has topple turns left, just struggle a bit
                        Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, LVar0)
                        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                        Wait(20)
                        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                    Else
                        // topple turns are over, koopa bros can get up
                        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                        Wait(12)
                        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                        Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
                        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
                        Thread
                            Set(LVar0, 0)
                            Call(SetActorRotationOffset, ACTOR_SELF, 0, 18, 0)
                            Loop(4)
                                Add(LVar0, 22)
                                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                                Wait(1)
                            EndLoop
                        EndThread
                        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
                        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
                        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
                        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 36)
                        Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_GotUp)
                        Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultDefense)))
                        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_IDLE)
                        Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
                    EndIf
                CaseDefault
                    Wait(20)
            EndSwitch
        CaseEq(BOSS_CMD_GET_READY)
            // if koopa just got up, change its state to ready
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Koopa_State_GotUp)
                    Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Ready)
            EndSwitch
        CaseEq(BOSS_CMD_SPIN_ATTACK)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Koopa_State_PosA)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_ENTER_SHELL)
                    Wait(10)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar0)
                    Switch(LVar0)
                        CaseEq(4)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_TOWER_SPIN_3)
                        CaseEq(3)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_TOWER_SPIN_2)
                        CaseEq(2)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_TOWER_SPIN_1)
                    EndSwitch
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_SHELL_SPIN)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 60)
                    Wait(60)
                    Thread
                        Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
                        Switch(LVar0)
                            CaseEq(HIT_RESULT_LUCKY)
                                Wait(20)
                                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                Return
                            CaseEq(HIT_RESULT_MISS)
                                Return
                        EndSwitch
                        Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVarA)
                        Label(0)
                        Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                        Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        IfGt(LVar0, LVar3)
                            Wait(1)
                            Goto(0)
                        EndIf
                        Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        Call(SetGoalToTarget, ACTOR_SELF)
                        Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar1)
                        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
                    EndThread
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_LAUNCH_SHELL)
                    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
                    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar0)
                    Switch(LVar0)
                        CaseEq(4)
                            Call(SetActorSpeed, ACTOR_SELF, Float(13.0))
                        CaseEq(3)
                            Call(SetActorSpeed, ACTOR_SELF, Float(14.0))
                        CaseEq(2)
                            Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
                    EndSwitch
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    Call(RunToGoal, ACTOR_SELF, 0, false)
                    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
                    Thread
                        Call(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        Set(LVar0, 0)
                        Loop(40)
                            Sub(LVar0, 45)
                            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            Wait(1)
                        EndLoop
                        Call(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EndThread
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                    Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                    Set(LVar4, 15)
                    Call(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVarB)
                    Set(LVar0, LVarB)
                    Sub(LVar0, 1)
                    Mul(LVar0, 18)
                    Switch(LVarB)
                        CaseEq(4)
                            Call(AddGoalPos, ACTOR_SELF, 0, LVar0, -10)
                        CaseEq(3)
                            Call(AddGoalPos, ACTOR_SELF, 0, LVar0, -7)
                        CaseEq(2)
                            Call(AddGoalPos, ACTOR_SELF, 0, LVar0, -4)
                    EndSwitch
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
                    Call(JumpToGoal, ACTOR_SELF, 40, false, true, false)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TowerHeight, LVar0)
                    Switch(LVar0)
                        CaseEq(4)
                            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 60)
                            Wait(60)
                        CaseEq(3)
                            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 50)
                            Wait(50)
                        CaseEq(2)
                            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 40)
                            Wait(40)
                    EndSwitch
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                    Wait(10)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
                    Call(SetActorYaw, ACTOR_SELF, 0)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_POINT)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Sub(LVar0, 22)
                    Add(LVar1, 19)
                    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
                    Wait(30)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_IDLE)
                    Wait(20)
                    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_TowerState, 0)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_ENTER_SHELL)
                    Wait(10)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_SHELL_SPIN)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 60)
                    Wait(60)
                    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
                    Switch(LVar0)
                        CaseEq(AVAL_Koopa_State_PosD)
                            Call(SetActorSpeed, ACTOR_SELF, Float(14.0))
                        CaseEq(AVAL_Koopa_State_PosC)
                            Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
                        CaseEq(AVAL_Koopa_State_PosB)
                            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
                    EndSwitch
                    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    Call(RunToGoal, ACTOR_SELF, 0, false)
                    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
                    Thread
                        Call(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        Set(LVar0, 0)
                        Loop(40)
                            Sub(LVar0, 45)
                            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            Wait(1)
                        EndLoop
                        Call(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EndThread
                    Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
                    Switch(LVar0)
                        CaseEq(AVAL_Koopa_State_PosD)
                            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                            Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            Set(LVar4, 15)
                            Call(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            Call(AddGoalPos, ACTOR_SELF, 0, 36, -7)
                        CaseEq(AVAL_Koopa_State_PosC)
                            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                            Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            Set(LVar4, 15)
                            Call(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            Call(AddGoalPos, ACTOR_SELF, 0, 18, -4)
                        CaseEq(AVAL_Koopa_State_PosB)
                            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_TopKoopaID, LVar1)
                            Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            Set(LVar4, 15)
                            Call(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            Call(AddGoalPos, ACTOR_SELF, 0, 0, 0)
                    EndSwitch
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
                    Call(JumpToGoal, ACTOR_SELF, 40, false, true, false)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
                    Switch(LVar0)
                        CaseEq(AVAL_Koopa_State_PosD)
                            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 50)
                            Wait(50)
                        CaseEq(AVAL_Koopa_State_PosC)
                            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 40)
                            Wait(40)
                        CaseEq(AVAL_Koopa_State_PosB)
                            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 30)
                            Wait(30)
                    EndSwitch
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_EXIT_SHELL)
                    Wait(10)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOWER_IDLE)
                    Wait(30)
                EndCaseGroup
            EndSwitch
        CaseEq(BOSS_CMD_SOLO_ATTACK)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Koopa_State_Ready)
                    Call(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Set(LVar2, 15)
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_RUN)
                    Call(RunToGoal, ACTOR_SELF, 10, false)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_ENTER_SHELL)
                    Wait(10)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_BROS_SPINUP)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_SHELL_SPIN)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 30)
                    Wait(30)
                    Thread
                        Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
                        Switch(LVar0)
                            CaseEq(HIT_RESULT_LUCKY)
                                Wait(20)
                                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                Return
                            CaseEq(HIT_RESULT_MISS)
                                Return
                        EndSwitch
                        Label(0)
                        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        IfGt(LVar0, LVar3)
                            Wait(1)
                            Goto(0)
                        EndIf
                        Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        Call(SetGoalToTarget, ACTOR_SELF)
                        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
                    EndThread
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_LAUNCH_SHELL)
                    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
                    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
                    Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    Call(RunToGoal, ACTOR_SELF, 0, false)
                    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
                    Thread
                        Call(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        Set(LVar0, 0)
                        Loop(40)
                            Sub(LVar0, 45)
                            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            Wait(1)
                        EndLoop
                        Call(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EndThread
                    Call(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Set(LVar2, 15)
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
                    Call(JumpToGoal, ACTOR_SELF, 40, false, true, false)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(N(SpawnSpinEffect), LVar0, LVar1, LVar2, 30)
                    Wait(30)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                    Wait(10)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
                    Call(SetActorYaw, ACTOR_SELF, 0)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_POINT)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Sub(LVar0, 22)
                    Add(LVar1, 19)
                    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
                    Wait(30)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_RUN)
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 10, false)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    BitwiseAndConst(LVar0, ~AFLAG_Boss_DoingSoloAttack)
                    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndSwitch
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    Call(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, true)
    Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Ready)
    Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_HURT)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_BURN)
            SetConst(LVar2, THIS_ANIM_BURN_STILL)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_BURN)
            SetConst(LVar2, THIS_ANIM_BURN_STILL)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_BURN_STILL)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_HURT)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_HURT)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_HURT)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_State, AVAL_Koopa_State_Toppled)
            Call(SetActorVar, ACTOR_SELF, AVAR_Koopa_ToppleTurns, 2)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefense)))
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            IfEq(LVar0, AVAL_Koopa_State_Ready)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_HURT)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                Thread
                    Wait(4)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                    Wait(1)
                EndThread
            Else
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOPPLE_IDLE)
            EndIf
            UseBuf(Ref(N(FlipPosOffsets)))
            Loop(ARRAY_COUNT(N(FlipPosOffsets)))
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            IfEq(LVar0, AVAL_Koopa_State_Ready)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, THIS_ANIM_TOP_ENTER_SHELL)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfEq(LVar0, 0)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, THIS_ANIM_TOP_EXIT_SHELL)
                    Wait(10)
                EndIf
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, THIS_ANIM_TOPPLE_IDLE)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_HURT)
            ExecWait(EVS_Enemy_Hit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, THIS_ANIM_HURT)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_Koopa_State, LVar0)
            IfEq(LVar0, AVAL_Koopa_State_Ready)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, THIS_ANIM_IDLE)
                ExecWait(EVS_Enemy_Recover)
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};
