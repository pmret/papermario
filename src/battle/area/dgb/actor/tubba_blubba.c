#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleTubba.h"

#define NAMESPACE b_area_dgb_tubba_blubba

extern EvtScript N(EVS_Init);
extern EvtScript N(takeTurn_80219750);
extern EvtScript N(idle_80219204);
extern EvtScript N(handleEvent_80219338);
extern EvtScript N(nextTurn_80218FB0);
extern EvtScript N(80218E60);
extern EvtScript N(80219D88);
extern EvtScript N(8021A36C);

s32 N(IdleAnims)[] = {
    STATUS_NORMAL,    ANIM_BattleTubba_Anim02,
    STATUS_STONE,     ANIM_BattleTubba_Anim00,
    STATUS_SLEEP,     ANIM_BattleTubba_Anim00,
    STATUS_POISON,    ANIM_BattleTubba_Anim02,
    STATUS_STOP,      ANIM_BattleTubba_Anim00,
    STATUS_STATIC,    ANIM_BattleTubba_Anim00,
    STATUS_PARALYZE,  ANIM_BattleTubba_Anim00,
    STATUS_PARALYZE,  ANIM_BattleTubba_Anim00,
    STATUS_DIZZY,     ANIM_BattleTubba_Anim00,
    STATUS_DIZZY,     ANIM_BattleTubba_Anim00,
    STATUS_FEAR,      ANIM_BattleTubba_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
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

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -15, 75 },
        .opacity = 255,
        .idleAnimations = N(IdleAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUBBA_BLUBBA,
    .level = 0,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 15,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 100, 100 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -33, 78 },
    .statusMessageOffset = { 10, 75 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80219750)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80219204)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80219338)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_80218FB0)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_IF_GE(GB_StoryProgress, -30)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(80218E60), LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80218E60) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(ActorExists, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, ANIM_BattleTubba_Anim06)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ANIM_BattleTubba_Anim07)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(1)
    EVT_CALL(StartRumble, 1)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80218FB0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 75)
                EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
                EVT_CALL(SetBattleCamZoom, 380)
                EVT_CALL(SetBattleCamOffsetZ, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_CALL(ActorSpeak, MSG_CH3_0102, ACTOR_SELF, 1, ANIM_BattleTubba_Anim09, ANIM_BattleTubba_Anim02)
                EVT_THREAD
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim15)
                    EVT_WAIT(4)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim16)
                    EVT_WAIT(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim02)
                EVT_END_THREAD
                EVT_CALL(EndActorSpeech, ACTOR_SELF, 1, -1, -1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(func_802535B4, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80219204) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80219238) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim02)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim07)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim02)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802192E0) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80219338) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(802192E0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim02)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(802192E0))
            EVT_WAIT(20)
            EVT_WAIT(15)
            EVT_IF_EQ(LVar0, EVENT_BURN_DEATH)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
                EVT_EXEC_WAIT(DoDeath)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(802192E0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80219238))
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_EXEC_WAIT(N(802192E0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim02)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim14)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(80219238))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleTubba_Anim02)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80219750) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim07)
        EVT_CALL(SetGoalPos, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim01)
        EVT_WAIT(30)
        EVT_SET(LVar0, 0)
        EVT_LOOP(12)
            EVT_ADD(LVar0, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(10)
        EVT_SET(LVar0, 180)
        EVT_LOOP(12)
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 80)
        EVT_PLAY_EFFECT(EFFECT_EMOTE, 2, 0, LVar0, LVar1, LVar2, 30, 315, 30, 0, 0)
        EVT_WAIT(40)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim01)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 12)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim06)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar0, 220)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_KILL_THREAD(LVar0)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, TRUE)
        EVT_CALL(func_8026F60C, 10)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(func_802535B4, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 75)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 380)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(ActorSpeak, MSG_CH3_0103, ACTOR_SELF, 1, ANIM_BattleTubba_Anim09, ANIM_BattleTubba_Anim02)
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim15)
            EVT_WAIT(4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim16)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim02)
        EVT_END_THREAD
        EVT_CALL(EndActorSpeech, ACTOR_SELF, 1, -1, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim01)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
        EVT_CALL(func_802535B4, 1)
    EVT_END_IF
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 60)
        EVT_EXEC_WAIT(N(80219D88))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8021A36C))
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80219D88) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim07)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_IF_NOT_FLAG(LVar5, 0x00080000)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim15)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35E)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim16)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim17)
    EVT_WAIT(3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 1, LVar0, LVar1, LVar2, 0)
        EVT_THREAD
            EVT_CALL(StartRumble, 1)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(15.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim02)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(80219238))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
    EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 1, LVar0, 0, LVar2, 0)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
        EVT_CALL(func_80269EAC, 23)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim02)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(80219238))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A36C) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim07)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim0F)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim10)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_3E7, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim11)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 15)
            EVT_SET(LVar1, 0)
            EVT_ADD(LVar2, 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 23, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim12)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_ADD(LVar2, 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(StartRumble, 1)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim13)
            EVT_WAIT(4)
            EVT_EXEC_WAIT(N(80219238))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim11)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
    EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
        EVT_CALL(func_80269EAC, 24)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
                    EVT_CALL(LandJump, ACTOR_SELF)
                EVT_ELSE
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_ELSE
                EVT_GOTO(1)
            EVT_END_IF
            EVT_LABEL(0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 0, LVar0, 0, LVar2, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim0D)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_ADD(LVar2, 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(StartRumble, 1)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_WAIT(3)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 1, LVar0, 0, LVar2, 0)
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_THREAD
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleTubba_Anim0E)
            EVT_END_THREAD
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_LABEL(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(80219238))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
