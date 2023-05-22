#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Dayzee.h"
#include "effects.h"

#define NAMESPACE b_area_flo_amazy_dayzee

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern s32 N(IdleAnimations)[];

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              10,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              10,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           10,
    STATUS_KEY_SHRINK,             10,
    STATUS_KEY_STOP,               10,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_AMAZY_DAYZEE,
    .level = 100,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 90,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 5,
    .size = { 32, 34 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -14, 17 },
    .statusTextOffset = { 9, 25 },
};

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_Dayzee_Amazy_Anim01,
    STATUS_KEY_STONE,     ANIM_Dayzee_Amazy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Dayzee_Amazy_Anim0C,
    STATUS_KEY_POISON,    ANIM_Dayzee_Amazy_Anim01,
    STATUS_KEY_STOP,      ANIM_Dayzee_Amazy_Anim00,
    STATUS_KEY_STATIC,    ANIM_Dayzee_Amazy_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Dayzee_Amazy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Dayzee_Amazy_Anim0B,
    STATUS_KEY_FEAR,      ANIM_Dayzee_Amazy_Anim0B,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_SUB(LVar2, 2)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 2, LVar0, LVar1, LVar2, 30, 0)
    EVT_WAIT(15)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim03)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Dayzee_Amazy_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Dayzee_Amazy_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim04)
            EVT_SET_CONST(LVar2, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Dayzee_Amazy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackPainfulSong) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorPos, ACTOR_SELF, -20, LVar1, LVar2)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(MoveBattleCamOver, 70)
        EVT_SET(LFlag0, FALSE)
        EVT_LABEL(0)
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim0E)
            EVT_SET(LFlag0, TRUE)
        EVT_ELSE
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim0F)
            EVT_SET(LFlag0, FALSE)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 20)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_IF_GT(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim0E)
            EVT_SET(LFlag0, TRUE)
        EVT_ELSE
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim0F)
            EVT_SET(LFlag0, FALSE)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
        EVT_CALL(SetGoalPos, ACTOR_SELF, -35, 0, 10)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim01)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim06)
        EVT_WAIT(40)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim07)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DAYZEE_SONG)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_ADD(LVar2, 2)
    EVT_LOOP(13)
        EVT_CALL(RandInt, 30, LVar3)
        EVT_SUB(LVar3, 15)
        EVT_ADD(LVar3, LVar0)
        EVT_PLAY_EFFECT(EFFECT_MUSIC_NOTE, 1, LVar3, LVar1, LVar2, 0)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim01)
    EVT_WAIT(10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_KEY(STATUS_FLAG_SLEEP, 3, 15), 20, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 10)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(flee) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, 30)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim03)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Amazy_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
    EVT_ADD(LVar0, 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_BATTLE_FLED, TRUE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(attackPainfulSong))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(850)
            EVT_EXEC_WAIT(N(flee))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(attackPainfulSong))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
