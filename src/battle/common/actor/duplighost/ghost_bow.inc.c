#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBow.h"

#define NAMESPACE A(bow_clone)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBow_Idle,
    STATUS_KEY_STONE,     ANIM_BattleBow_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBow_Still,
    STATUS_KEY_POISON,    ANIM_BattleBow_Idle,
    STATUS_KEY_STOP,      ANIM_BattleBow_Still,
    STATUS_KEY_STATIC,    ANIM_BattleBow_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleBow_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleBow_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleBow_Injured,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -26 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_GHOST_BOW,
    .level = ACTOR_LEVEL_GHOST_BOW,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 36, 29 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVar1)
            EVT_IF_FLAG(LVar1, DAMAGE_TYPE_SHOCK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
                EVT_EXEC_WAIT(A(EVS_Duplighost_OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_BurnHurtAlt)
            EVT_SET_CONST(LVar2, ANIM_BattleBow_BurnStillAlt)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_BurnHurtAlt)
            EVT_SET_CONST(LVar2, ANIM_BattleBow_BurnStillAlt)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_BurnStillAlt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnShockHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_SET(LVar2, 14)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnShockDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Run)
            EVT_SET_CONST(LVar2, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Run)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
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
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR_A)
    EVT_THREAD
        EVT_SET(LVar0, 200)
        EVT_LOOP(20)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Run)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 4, -4, 0)
        EVT_ELSE
            EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -10, 0)
        EVT_END_IF
        EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH_A)
    EVT_SET(LVar0, 55)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 10)
        EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_PreSlap)
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_SlapOnce)
            EVT_WAIT(2)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LVar0, 0)
            EVT_LOOP(20)
                EVT_ADD(LVar0, -45)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Injured)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SEEING_STARS)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR_A)
            EVT_THREAD
                EVT_SET(LVar0, 200)
                EVT_LOOP(20)
                    EVT_SUB(LVar0, 10)
                    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH_A)
            EVT_CALL(YieldTurn)
            EVT_SET(LVar0, 55)
            EVT_LOOP(20)
                EVT_ADD(LVar0, 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_SET(LVarA, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar8)
    EVT_SWITCH(LVar8)
        EVT_CASE_EQ(PARTNER_RANK_NORMAL)
            EVT_SET(LVar8, 4)
        EVT_CASE_EQ(PARTNER_RANK_SUPER)
            EVT_SET(LVar8, 5)
        EVT_CASE_EQ(PARTNER_RANK_ULTRA)
            EVT_SET(LVar8, 6)
    EVT_END_SWITCH
    EVT_SET(LVar7, LVar8)
    EVT_LOOP(LVar7)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOW_SMACK)
        EVT_ADD(LVarA, 1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_SlapOnce)
            EVT_SET(LFlag0, TRUE)
            EVT_IF_EQ(LVarA, LVar8)
                EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
            EVT_ELSE
                EVT_CALL(SetDamageSource, DMG_SRC_NEXT_SLAP_LEFT)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_SlapBack)
            EVT_SET(LFlag0, FALSE)
            EVT_IF_EQ(LVarA, LVar8)
                EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_RIGHT)
            EVT_ELSE
                EVT_CALL(SetDamageSource, DMG_SRC_NEXT_SLAP_RIGHT)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(2)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.2))
        EVT_END_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
        EVT_SWITCH(LVar9)
            EVT_CASE_EQ(PARTNER_RANK_NORMAL)
                EVT_WAIT(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            EVT_CASE_EQ(PARTNER_RANK_SUPER)
                EVT_WAIT(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            EVT_CASE_EQ(PARTNER_RANK_ULTRA)
                EVT_WAIT(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
        EVT_END_SWITCH
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
        EVT_CALL(GetActorHP, ACTOR_PLAYER, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR_A)
            EVT_THREAD
                EVT_SET(LVar0, 200)
                EVT_LOOP(20)
                    EVT_SUB(LVar0, 10)
                    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH_A)
            EVT_CALL(YieldTurn)
            EVT_SET(LVar0, 55)
            EVT_LOOP(20)
                EVT_ADD(LVar0, 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Formation A(BowCloneFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(DuplighostSummonPos), 0),
};
