#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/LavaBubble.h"

#define NAMESPACE b_area_kzn_lava_bubble

extern s32 N(idleAnimations_80218FC4)[];
extern s32 N(idleAnimations_80219010)[];
extern EvtScript N(init_8021901C);
extern EvtScript N(takeTurn_8021AEA4);
extern EvtScript N(idle_802191E4);
extern EvtScript N(handleEvent_80219500);

s32 N(defenseTable_80218E10)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_WATER, -2,
    ELEMENT_ICE, -2,
    ELEMENT_FIRE, 99,
    ELEMENT_BLAST, -1,
    ELEMENT_END,
};

s32 N(statusTable_80218E3C)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 50,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 75,
    STATUS_STOP, 85,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80218EE8)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 25 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218FC4),
        .defenseTable = N(defenseTable_80218E10),
        .eventFlags = ACTOR_EVENT_FLAG_FIREY,
        .elementImmunityFlags = ELEMENT_IMMUNITY_FLAG_2,
        .unk_1C = 0xFD,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219010),
        .defenseTable = N(defenseTable_80218E10),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219010),
        .defenseTable = N(defenseTable_80218E10),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219010),
        .defenseTable = N(defenseTable_80218E10),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219010),
        .defenseTable = N(defenseTable_80218E10),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LAVA_BUBBLE,
    .level = 17,
    .maxHP = 9,
    .partCount = ARRAY_COUNT(N(partsTable_80218EE8)),
    .partsData = N(partsTable_80218EE8),
    .takeTurnScript = &N(init_8021901C),
    .statusTable = N(statusTable_80218E3C),
    .escapeChance = 50,
    .airLiftChance = 90,
    .hurricaneChance = 85,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 33, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_80218FC4)[] = {
    STATUS_NORMAL,    ANIM_LavaBubble_Anim01,
    STATUS_STONE,     ANIM_LavaBubble_Anim00,
    STATUS_SLEEP,     ANIM_LavaBubble_Anim01,
    STATUS_POISON,    ANIM_LavaBubble_Anim01,
    STATUS_STOP,      ANIM_LavaBubble_Anim00,
    STATUS_STATIC,    ANIM_LavaBubble_Anim01,
    STATUS_PARALYZE,  ANIM_LavaBubble_Anim00,
    STATUS_DIZZY,     ANIM_LavaBubble_Anim0A,
    STATUS_FEAR,      ANIM_LavaBubble_Anim0A,
    STATUS_END,
};

s32 N(idleAnimations_80219010)[] = {
    STATUS_NORMAL,    ANIM_LavaBubble_Anim01,
    STATUS_END,
};

EvtScript N(init_8021901C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021AEA4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_802191E4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80219500)))
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 5)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802191E4) = {
    EVT_LABEL(0)
    EVT_CALL(MakeLerp, 0, 10, 25, 10)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(GetHomePos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_ADD(LVar0, LVar3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
    EVT_IF_EQ(LVar1, 1)
        EVT_LABEL(11)
        EVT_WAIT(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(MakeLerp, 10, 0, 25, 10)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(GetHomePos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_ADD(LVar0, LVar3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
    EVT_IF_EQ(LVar1, 1)
        EVT_LABEL(22)
        EVT_WAIT(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_GOTO(22)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(22)
        EVT_END_IF
        EVT_GOTO(2)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "common/UnkSfxFunc.inc.c"

EvtScript N(80219464) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim03)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80219500) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim08)
            EVT_SET_CONST(LVar2, ANIM_LavaBubble_Anim09)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim08)
            EVT_SET_CONST(LVar2, ANIM_LavaBubble_Anim09)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim09)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_359 | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80219464))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_359 | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_SCRIPTED_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
        EVT_CASE_OR_EQ(EVENT_BURN_TAUNT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(80219464))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim03)
            EVT_SET_CONST(LVar2, ANIM_LavaBubble_Anim07)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim03)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LavaBubble_Anim03)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(fireTackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim01)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim04)
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
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(80219464))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 4587524)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_WAIT(5)
            EVT_EXEC_WAIT(N(80219464))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A074) = {
    EVT_SET(LVar6, 2)
    EVT_LOOP(4)
        EVT_THREAD
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
            EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
                EVT_CALL(SetPartScale, ACTOR_SELF, LVar6, EVT_FLOAT(0.2), EVT_FLOAT(0.2), EVT_FLOAT(0.2))
            EVT_ELSE
                EVT_CALL(SetPartScale, ACTOR_SELF, LVar6, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
            EVT_END_IF
            EVT_CALL(SetPartPos, ACTOR_SELF, LVar6, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar6, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar6, EVT_FLOAT(8.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar6, EVT_FLOAT(0.01))
            EVT_CALL(SetPartSounds, ACTOR_SELF, LVar6, 2, 720, 0)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar6, LVar3, LVar4, LVar5, 0, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar6, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_END_THREAD
        EVT_WAIT(3)
        EVT_ADD(LVar6, 1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A218) = {
    EVT_EXEC(N(8021A074))
    EVT_CALL(GetDistanceToGoal, ACTOR_SELF, LVar0)
    EVT_DIVF(LVar0, EVT_FLOAT(8.0))
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(fireballs_Partner) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_EQ(LVarA, 1)
        EVT_ADD(LVar0, 100)
        EVT_SET(LVar1, 5)
    EVT_ELSE
        EVT_ADD(LVar0, 30)
        EVT_SET(LVar1, 50)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim01)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim05)
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim06)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_ADD(LVar1, 4)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 100)
            EVT_ADD(LVar5, 2)
            EVT_EXEC_WAIT(N(8021A218))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(80219464))
            EVT_WAIT(20)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim06)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_ADD(LVar1, 4)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar4, 6)
    EVT_ADD(LVar5, 2)
    EVT_EXEC_WAIT(N(8021A218))
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(20)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(80219464))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(fireballs_Player) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 11)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2CF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim04)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim04)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(80219464))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(5)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2CF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBubble_Anim04)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(80219464))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021AEA4) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(1)
                EVT_EXEC_WAIT(N(fireTackle))
            EVT_CASE_EQ(0)
                EVT_EXEC_WAIT(N(fireballs_Player))
        EVT_END_SWITCH
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_KO)
                EVT_EXEC_WAIT(N(fireTackle))
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LE(LVar0, 300)
                    EVT_EXEC_WAIT(N(fireballs_Partner))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(fireTackle))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_KO)
                EVT_EXEC_WAIT(N(fireballs_Player))
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LE(LVar0, 300)
                    EVT_EXEC_WAIT(N(fireballs_Partner))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(fireballs_Player))
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
