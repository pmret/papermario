#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/LavaBubble.h"

#define NAMESPACE A(ember)

extern s32 N(DefaultAnims)[];
extern s32 N(ProjectileAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_FIRE_1      = 2,
    PRT_FIRE_2      = 3,
    PRT_FIRE_3      = 4,
    PRT_FIRE_4      = 5,
};

enum N(ActorVars) {
    AVAR_IN_Flying      = 0,
    AVAR_StayNearGound  = 0,
    AVAR_Generation     = 1,
    AVAR_PauseIdle      = 2,
};

enum N(ActorParams) {
    DMG_TACKLE      = 4,
    DMG_AIR_SWEEP   = 4,
    DMG_SHOOT       = 3,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,   -2,
    ELEMENT_ICE,     -2,
    ELEMENT_FIRE,    99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 25 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FIREY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -3, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_EMBER,
    .level = ACTOR_LEVEL_EMBER,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 80,
    .hurricaneChance = 75,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 33, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaBubble_Blue_Anim01,
    STATUS_KEY_STONE,     ANIM_LavaBubble_Blue_Anim00,
    STATUS_KEY_SLEEP,     ANIM_LavaBubble_Blue_Anim01,
    STATUS_KEY_POISON,    ANIM_LavaBubble_Blue_Anim01,
    STATUS_KEY_STOP,      ANIM_LavaBubble_Blue_Anim00,
    STATUS_KEY_STATIC,    ANIM_LavaBubble_Blue_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_LavaBubble_Blue_Anim00,
    STATUS_KEY_DIZZY,     ANIM_LavaBubble_Blue_Anim0A,
    STATUS_KEY_FEAR,      ANIM_LavaBubble_Blue_Anim0A,
    STATUS_END,
};

s32 N(ProjectileAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaBubble_Blue_Anim01,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_Flying, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_StayNearGound, TRUE)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_StayNearGound, FALSE)
    EVT_END_SWITCH
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_FIRE_1, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_FIRE_2, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_FIRE_3, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_FIRE_4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_PauseIdle, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 5)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, 10, 25, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(GetHomePos, ACTOR_SELF, LVar2, LVar3, LVar4)
            EVT_ADD(LVar0, LVar3)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            EVT_IF_EQ(LVar1, 1)
                EVT_LABEL(11)
                    EVT_WAIT(1)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        EVT_GOTO(11)
                    EVT_END_IF
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PauseIdle, LVar0)
                    EVT_IF_EQ(LVar0, TRUE)
                        EVT_GOTO(11)
                    EVT_END_IF
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 10, 0, 25, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(GetHomePos, ACTOR_SELF, LVar2, LVar3, LVar4)
            EVT_ADD(LVar0, LVar3)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            EVT_IF_EQ(LVar1, 1)
                EVT_LABEL(22)
                    EVT_WAIT(1)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        EVT_GOTO(22)
                    EVT_END_IF
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PauseIdle, LVar0)
                    EVT_IF_EQ(LVar0, TRUE)
                        EVT_GOTO(22)
                    EVT_END_IF
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "common/PlayLavaBubbleFlightSound.inc.c"

EvtScript N(EVS_FlyHome) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim03)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_THREAD
        EVT_CALL(N(PlayLavaBubbleFlightSound))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetAvailableColumn) = {
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar5)
        EVT_CALL(GetIndexFromHome, LVar0, LVar5)
        EVT_MOD(LVar5, 4)
        EVT_SWITCH(LVar5)
            EVT_CASE_EQ(0)
                EVT_SET(LFlag1, TRUE)
            EVT_CASE_EQ(1)
                EVT_SET(LFlag2, TRUE)
            EVT_CASE_EQ(2)
                EVT_SET(LFlag3, TRUE)
            EVT_CASE_EQ(3)
                EVT_SET(LFlag4, TRUE)
        EVT_END_SWITCH
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, -1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_SET(LVarA, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag2, FALSE)
        EVT_SET(LVarA, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag3, FALSE)
        EVT_SET(LVarA, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag4, FALSE)
        EVT_SET(LVarA, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, -1)
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(SummonFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 0),
};

EvtScript N(EVS_TrySplit) = {
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetLastElement, LVar0)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS) // interesting use-case
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    EVT_IF_GE(LVar0, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(SummonEnemy, EVT_PTR(N(SummonFormation)), FALSE)
            EVT_CALL(SetActorVar, LVar0, AVAR_PauseIdle, TRUE)
            EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
            EVT_CALL(SetEnemyHP, LVar0, LVarB)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVarB, LVarC, LVarD)
            EVT_CALL(SetActorPos, LVar0, LVarB, LVarC, LVarD)
            EVT_CALL(SetGoalToIndex, LVar0, LVarA)
            EVT_CALL(GetGoalPos, LVar0, LVarB, LVarC, LVarD)
            EVT_CALL(SetHomePos, LVar0, LVarB, LVarC, LVarD)
            EVT_CALL(SetActorJumpGravity, LVar0, EVT_FLOAT(1.2))
            EVT_CALL(JumpToGoal, LVar0, 20, FALSE, TRUE, FALSE)
            EVT_CALL(HPBarToHome, LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar1)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, LVar0, AVAR_Generation, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetActorVar, LVar0, AVAR_Generation, 2)
            EVT_END_SWITCH
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Generation, 3)
            EVT_CALL(SetActorVar, LVar0, AVAR_PauseIdle, FALSE)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
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
            EVT_EXEC(N(EVS_TrySplit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC(N(EVS_TrySplit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim08)
            EVT_SET_CONST(LVar2, ANIM_LavaBubble_Blue_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim08)
            EVT_SET_CONST(LVar2, ANIM_LavaBubble_Blue_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC(N(EVS_TrySplit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_FLY | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_FLY | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
        EVT_CASE_OR_EQ(EVENT_BURN_TAUNT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim03)
            EVT_SET_CONST(LVar2, ANIM_LavaBubble_Blue_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Blue_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            // nothing
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Tackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_THREAD
        EVT_CALL(N(PlayLavaBubbleFlightSound))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim01)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim04)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_ADD(LVar2, 1)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 3, FALSE, TRUE, FALSE)
            EVT_WAIT(14)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, 0, 0, DMG_TACKLE, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_SET(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_LavaBubble_Blue_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_WAIT(5)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// (in) LVar3 posX
// (in) LVar4 posY
// (in) LVar5 posZ
EvtScript N(EVS_ShootFire_Impl) = {
    EVT_SET(LVar6, PRT_FIRE_1)
    EVT_LOOP(4)
        EVT_THREAD
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
            EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
                EVT_CALL(SetPartScale, ACTOR_SELF, LVar6, EVT_FLOAT(0.2), EVT_FLOAT(0.2), EVT_FLOAT(0.2))
            EVT_ELSE
                EVT_CALL(SetPartScale, ACTOR_SELF, LVar6, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
            EVT_END_IF
            EVT_CALL(SetPartPos, ACTOR_SELF, LVar6, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar6, EVT_FLOAT(8.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar6, EVT_FLOAT(0.01))
            EVT_CALL(SetPartSounds, ACTOR_SELF, LVar6, ACTOR_SOUND_JUMP, SOUND_EMBER_SPIT, SOUND_NONE)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar6, LVar3, LVar4, LVar5, 0, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_END_THREAD
        EVT_WAIT(3)
        EVT_ADD(LVar6, 1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

// Shoot fireballs at a target and wait before yielding.
// (in) LVar3 posX
// (in) LVar4 posY
// (in) LVar5 posZ
EvtScript N(EVS_ShootFire) = {
    EVT_EXEC(N(EVS_ShootFire_Impl))
    EVT_CALL(GetDistanceToGoal, ACTOR_SELF, LVar0)
    EVT_DIVF(LVar0, EVT_FLOAT(8.0))
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ShootPartner) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_StayNearGound, LVarA)
    EVT_IF_EQ(LVarA, TRUE)
        EVT_ADD(LVar0, 100)
        EVT_SET(LVar1, 5)
    EVT_ELSE
        EVT_ADD(LVar0, 30)
        EVT_SET(LVar1, 50)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_THREAD
        EVT_CALL(N(PlayLavaBubbleFlightSound))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_SIN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim01)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim05)
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim06)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_ADD(LVar1, 4)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 100)
            EVT_ADD(LVar5, 2)
            EVT_EXEC_WAIT(N(EVS_ShootFire))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
            EVT_WAIT(20)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim06)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_ADD(LVar1, 4)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar4, 6)
    EVT_ADD(LVar5, 2)
    EVT_EXEC_WAIT(N(EVS_ShootFire))
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_FIRE | DAMAGE_TYPE_NO_CONTACT), 0, 0, DMG_SHOOT, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(20)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_AirSweep) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_THREAD
        EVT_CALL(N(PlayLavaBubbleFlightSound))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_SIN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_JUMP)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim04)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim04)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(5)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_JUMP)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Blue_Anim04)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, 0, 0, DMG_AIR_SWEEP, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(EVS_FlyHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_StayNearGound, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(1)
                EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
            EVT_CASE_EQ(0)
                EVT_EXEC_WAIT(N(EVS_Attack_AirSweep))
        EVT_END_SWITCH
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_StayNearGound, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_KO)
                EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LE(LVar0, 300)
                    EVT_EXEC_WAIT(N(EVS_Attack_ShootPartner))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_KO)
                EVT_EXEC_WAIT(N(EVS_Attack_AirSweep))
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LE(LVar0, 300)
                    EVT_EXEC_WAIT(N(EVS_Attack_ShootPartner))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(EVS_Attack_AirSweep))
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
