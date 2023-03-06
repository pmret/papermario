#include "common.h"
#include "hud_element.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/MageJrTroopa.h"

#define NAMESPACE b_area_kmr_part_3_mage_jr_troopa

s32 N(IdleAnimations_8022A550)[] = {
    STATUS_NORMAL,    ANIM_MageJrTroopa_Idle,
    STATUS_SLEEP,     ANIM_MageJrTroopa_Sleep,
    STATUS_STONE,     ANIM_MageJrTroopa_Still,
    STATUS_POISON,    ANIM_MageJrTroopa_Still,
    STATUS_STOP,      ANIM_MageJrTroopa_Still,
    STATUS_STATIC,    ANIM_MageJrTroopa_Still,
    STATUS_PARALYZE,  ANIM_MageJrTroopa_Still,
    STATUS_DIZZY,     ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_8022A594)[] = {
    STATUS_NORMAL,   ANIM_MageJrTroopa_Idle,
    STATUS_SLEEP,    ANIM_MageJrTroopa_Still,
    STATUS_STONE,    ANIM_MageJrTroopa_Still,
    STATUS_POISON,   ANIM_MageJrTroopa_Still,
    STATUS_STOP,     ANIM_MageJrTroopa_Still,
    STATUS_STATIC,   ANIM_MageJrTroopa_Still,
    STATUS_PARALYZE, ANIM_MageJrTroopa_Still,
    STATUS_DIZZY,    ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_8022A5D8)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_STONE,     ANIM_JrTroopa_Still,
    STATUS_POISON,    ANIM_JrTroopa_Still,
    STATUS_STOP,      ANIM_JrTroopa_Still,
    STATUS_STATIC,    ANIM_JrTroopa_Still,
    STATUS_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_8022A61C)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(DefenseTable_8022A628)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(StatusTable_8022A634)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 35,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 45,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 45,
    STATUS_SHRINK, 60,
    STATUS_STOP, 60,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -2,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable_8022A6E0)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 28 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8022A550),
        .defenseTable = N(DefenseTable_8022A628),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8022A5D8),
        .defenseTable = N(DefenseTable_8022A628),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

extern EvtScript N(init_8022ACE4);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA5,
    .level = 65,
    .maxHP = 50,
    .partCount = ARRAY_COUNT( N(PartsTable_8022A6E0)),
    .partsData = N(PartsTable_8022A6E0),
    .initScript = &N(init_8022ACE4),
    .statusTable = N(StatusTable_8022A634),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 24, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 35 },
    .statusMessageOffset = { 10, 25 },
};

EvtScript N(8022A750) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_FLAG(LVar2, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar2)
    EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar2, MOVE_SPOOK)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_263)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 30)
            EVT_CALL(ShowEmote, 0x00000000, EMOTE_QUESTION, -45, 30, EMOTER_POS, LVar0, LVar1, LVar2, 5)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A880) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B9)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, 0x80000)
        EVT_ADD(LVar1, 16)
    EVT_ELSE
        EVT_ADD(LVar1, 6)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(32)
            EVT_WAIT(1)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(32)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_300)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 40, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 4, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022ABA8) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022AC40) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022AC80) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_8022B4F0);
extern EvtScript N(idle_8022ADA4);
extern EvtScript N(handleEvent_8022ADD8);
extern EvtScript N(nextTurn_8022BB44);

EvtScript N(init_8022ACE4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022B4F0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022ADA4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022ADD8)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_8022BB44)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022ADA4) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8022C2A4);
extern EvtScript N(8022BF1C);

EvtScript N(handleEvent_8022ADD8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8022A750))
            EVT_EXEC_WAIT(N(8022C2A4))
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Still)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2359306)
            EVT_SET(LVar2, 2359307)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2359306)
            EVT_SET(LVar2, 2359307)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_BurnStill)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Still)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Idle)
            EVT_EXEC_WAIT(DoImmune)
            EVT_EXEC_WAIT(N(8022A750))
            EVT_EXEC_WAIT(N(8022C2A4))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(58)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Flail)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Flail)
                EVT_WAIT(20)
                EVT_EXEC_WAIT(N(8022ABA8))
                EVT_CALL(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, 1, 0x0024000E, 0x00240003)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Idle)
                EVT_EXEC_WAIT(N(8022AC40))
            EVT_END_IF
        EVT_CASE_EQ(42)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Idle)
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Idle)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022B4F0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 36)
        EVT_SETF(LVar5, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 14)
        EVT_SETF(LVar5, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 120)
            EVT_ADD(LVar4, 20)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x80000)
                EVT_SET(LVar6, -8)
                EVT_SET(LVar7, 20)
                EVT_SETF(LVar8, EVT_FLOAT(1.0))
            EVT_ELSE
                EVT_SET(LVar6, -3)
                EVT_SET(LVar7, 8)
                EVT_SETF(LVar8, EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, LVar6)
            EVT_ADD(LVar1, LVar7)
            EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 30, 0)
            EVT_WAIT(35)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 20)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_SET(LVar6, -8)
        EVT_SET(LVar7, 20)
        EVT_SETF(LVar8, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar6, -3)
        EVT_SET(LVar7, 8)
        EVT_SETF(LVar8, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar6)
    EVT_ADD(LVar1, LVar7)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 15, 0)
    EVT_WAIT(15)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar1)
                EVT_IF_NE(LVar1, 0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8022BB44) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
                    EVT_IF_EQ(LVar0, 0)
                        EVT_EXEC_WAIT(N(8022ABA8))
                        EVT_WAIT(20)
                    EVT_END_IF
                    EVT_CALL(ActorSpeak, MSG_CH7_00DD, ACTOR_SELF, 1, 0x0024000E, 0x00240003)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Idle)
                    EVT_EXEC_WAIT(N(8022AC40))
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_ELSE
                EVT_WAIT(20)
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
                EVT_EXEC_WAIT(N(8022ABA8))
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH7_00DE, ACTOR_SELF, 1, 0x0024000E, 0x00240003)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Idle)
                EVT_EXEC_WAIT(N(8022AC40))
                EVT_WAIT(10)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_WAIT(15)
                EVT_EXEC_WAIT(N(8022ABA8))
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, MSG_CH7_00DB, ACTOR_SELF, 2, 0x0021001A, 0x0021001B)
                EVT_WAIT(8)
                EVT_EXEC_WAIT(N(8022A880))
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, 1, FALSE)
                EVT_WAIT(15)
                EVT_CALL(ActorSpeak, MSG_CH7_00DC, ACTOR_SELF, 1, 0x0024000E, 0x00240003)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Idle)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(8022AC40))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022BF1C) = {
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_80269E80, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(12)
        EVT_CASE_OR_EQ(16)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(15)
        EVT_CASE_OR_EQ(13)
        EVT_CASE_OR_EQ(17)
        EVT_CASE_OR_EQ(2)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar2, 0)
            EVT_LOOP(24)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                EVT_ADD(LVar2, 30)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_ADD(LVar2, 10)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, 1, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_JrTroopa_DefeatedBegin)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(IdleAnimations_8022A61C)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022C2A4) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(8022ABA8))
        EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, 1, 0x0024000E, 0x00240003)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MageJrTroopa_Idle)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_NE(LVar0, 1)
            EVT_EXEC_WAIT(N(8022AC40))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
