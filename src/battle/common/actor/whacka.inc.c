#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Whacka.h"

#define NAMESPACE A(whacka)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_MakeWhackaBump);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_SpawnedBump    = 0,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Whacka_Idle,
    STATUS_KEY_STONE,     ANIM_Whacka_Still,
    STATUS_KEY_SLEEP,     ANIM_Whacka_Idle,
    STATUS_KEY_POISON,    ANIM_Whacka_Idle,
    STATUS_KEY_STOP,      ANIM_Whacka_Still,
    STATUS_KEY_STATIC,    ANIM_Whacka_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Whacka_Still,
    STATUS_KEY_DIZZY,     ANIM_Whacka_Idle,
    STATUS_KEY_FEAR,      ANIM_Whacka_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -5 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_WHACKA,
    .level = ACTOR_LEVEL_WHACKA,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 50,
    .coinReward = 0,
    .size = { 47, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 40 },
    .statusTextOffset = { 10, 30 },
};

API_CALLABLE(N(IsHitEightTimes)) {
    script->varTable[0] = 0;
    if (evt_get_variable(NULL, GB_IWA00_Whacka_HitCount) >= 8) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpawnedBump, FALSE)
    EVT_CALL(N(IsHitEightTimes))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_INVISIBLE | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_WHACKA)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Hurt)
            EVT_EXEC_WAIT(N(EVS_MakeWhackaBump))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_SET_CONST(LVar2, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(N(EVS_MakeWhackaBump))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_SET_CONST(LVar2, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(N(EVS_MakeWhackaBump))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Hurt)
            EVT_EXEC_WAIT(N(EVS_MakeWhackaBump))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(EVS_Death))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_SET_CONST(LVar2, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LE(LVar0, 100)
        EVT_EXEC_WAIT(N(EVS_Death))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeWhackaBump) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpawnedBump, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_WHACKA)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Whacka_Idle)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, 10)
        EVT_CALL(MakeItemEntity, ITEM_WHACKAS_BUMP, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Whacka_Burrow)
    EVT_WAIT(40)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SpawnedBump, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_DROP_WHACKA_BUMP, TRUE)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_INVISIBLE | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
