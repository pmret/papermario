#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/paragoomba.h"

#define NAMESPACE b_area_kmr_part_1_paragoomba

ApiStatus N(AngleCalculate)(Evt* script, s32 isInitialCall);

s32 N(defenseTable_8021CB00)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable_8021CB0C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021CB18)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 100,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
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

s32 N(statusTable_8021CBC4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 80,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 80,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
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

s32 N(idleAnimations_8021E4EC)[];
s32 N(idleAnimations_8021CD28)[];
s32 N(idleAnimations_8021CDC0)[];
s32 N(idleAnimations_8021CDCC)[];
EvtSource N(init_8021CDD8);

ActorPartDesc N(partsTable_8021CC70)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021E4EC),
        .defenseTable = N(defenseTable_8021CB00),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = ELEMENT_IMMUNITY_FLAGS_0,
        .unk_1C = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021CD28),
        .defenseTable = N(defenseTable_8021CB0C),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = ELEMENT_IMMUNITY_FLAGS_0,
        .unk_1C = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021CDC0),
        .defenseTable = N(defenseTable_8021CB00),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = ELEMENT_IMMUNITY_FLAGS_0,
        .unk_1C = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021CDCC),
        .defenseTable = N(defenseTable_8021CB00),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = ELEMENT_IMMUNITY_FLAGS_0,
        .unk_1C = 246,
    },
};

ActorDesc NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PARAGOOMBA,
    .level = 6,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(partsTable_8021CC70)),
    .partsData = N(partsTable_8021CC70),
    .script = N(init_8021CDD8),
    .statusTable = N(statusTable_8021CBC4),
    .escapeChance = 90,
    .airLiftChance = 100,
    .spookChance = 100,
    .baseStatusChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 36, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8021CD28)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_idle,
    STATUS_STONE,     NPC_ANIM_paragoomba_default_still,
    STATUS_SLEEP,     NPC_ANIM_paragoomba_default_sleep,
    STATUS_POISON,    NPC_ANIM_paragoomba_default_idle,
    STATUS_STOP,      NPC_ANIM_paragoomba_default_still,
    STATUS_STATIC,    NPC_ANIM_paragoomba_default_idle,
    STATUS_PARALYZE,  NPC_ANIM_paragoomba_default_still,
    STATUS_DIZZY,     NPC_ANIM_paragoomba_default_dizzy,
    STATUS_FEAR,      NPC_ANIM_paragoomba_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021CD74)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_run,
    STATUS_STONE,     NPC_ANIM_paragoomba_default_still,
    STATUS_SLEEP,     NPC_ANIM_paragoomba_default_sleep,
    STATUS_POISON,    NPC_ANIM_paragoomba_default_idle,
    STATUS_STOP,      NPC_ANIM_paragoomba_default_still,
    STATUS_STATIC,    NPC_ANIM_paragoomba_default_run,
    STATUS_PARALYZE,  NPC_ANIM_paragoomba_default_still,
    STATUS_DIZZY,     NPC_ANIM_paragoomba_default_dizzy,
    STATUS_FEAR,      NPC_ANIM_paragoomba_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021CDC0)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_left_wing_only,
    STATUS_END,
};

s32 N(idleAnimations_8021CDCC)[] = {
    STATUS_NORMAL,    NPC_ANIM_paragoomba_default_right_wing_only,
    STATUS_END,
};

EvtSource N(takeTurn_8021D74C);
EvtSource N(idle_8021CE24);
EvtSource N(handleEvent_8021D158);

EvtSource N(init_8021CDD8) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021D74C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021CE24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021D158)))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8021CE24) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, EVT_VAR(0))
    EVT_ADD(EVT_VAR(0), 80)
    EVT_LOOP(EVT_VAR(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FIXED(0.6))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(idleAnimations_8021CD74)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FIXED(0.6))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(idleAnimations_8021CD28)))
    EVT_LOOP(40)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021D0E0) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(7.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_idle)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021DF64);

EvtSource N(handleEvent_8021D158) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(GetBattlePhase, EVT_VAR(0))
            EVT_IF_EQ(EVT_VAR(0), 1)
                EVT_CALL(GetEncounterState, EVT_VAR(0))
                EVT_IF_EQ(EVT_VAR(0), 4)
                    EVT_EXEC_WAIT(N(8021DF64))
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_burn_pain)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_paragoomba_default_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_burn_pain)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_paragoomba_default_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_burn_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(12)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021DF64))
        EVT_CASE_EQ(15)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_burn_pain)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_paragoomba_default_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021DF64))
        EVT_CASE_EQ(47)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_pain)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_dizzy)
            EVT_EXEC_WAIT(N(8021D0E0))
        EVT_CASE_EQ(38)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(19)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(56)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(53)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run)
            EVT_EXEC_WAIT(N(8021D0E0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, 512, 0)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_run)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_paragoomba_default_pain)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(EVT_VAR(0), 0x00000002)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_paragoomba_default_pain)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8021D74C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, EVT_VAR(0), ((0)), 0, 1, 16)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(EVT_VAR(10), EVT_VAR(0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 66)
            EVT_CALL(SetBattleCamZoom, 300)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 8416)
            EVT_CALL(SetActorSounds, -127, 2, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack)
            EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(EVT_VAR(0), 80)
            EVT_SET(EVT_VAR(1), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
            EVT_THREAD
                EVT_LOOP(4)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 8415)
                    EVT_WAIT_FRAMES(4)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_aim)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 2, EVT_FIXED(3.0))
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(EVT_VAR(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, EVT_VAR(0), ((0x80000000)), 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 2, EVT_FIXED(1.0))
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8021D0E0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 66)
            EVT_CALL(SetBattleCamZoom, 300)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 8416)
            EVT_CALL(SetActorSounds, -127, 2, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack)
            EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_attack)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, EVT_VAR(0), ((0)), 0, 0, 1, 32)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_paragoomba_default_run)
            EVT_EXEC_WAIT(N(8021D0E0))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021E584);

#include "common/StartRumbleWithParams.inc.c"

EvtSource N(8021DF64) = {
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, 131077)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 3, 1179652)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 4, 1179652)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, 8388612)
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, -9, 7, -2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 4, 11, 7, -2)
    EVT_CALL(GetLastEvent, ACTOR_SELF, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_burn_dead)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pain)
    EVT_END_IF
    EVT_CALL(SetActorSounds, -127, 2, 769, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 100, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(0.3))
    EVT_END_THREAD
    EVT_CALL(ResetActorSounds, -127, 2)
    EVT_CALL(GetLastEvent, ACTOR_SELF, EVT_VAR(3))
    EVT_IF_EQ(EVT_VAR(3), 15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pain)
        EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
        EVT_ADD(EVT_VAR(4), 10)
        EVT_ADD(EVT_VAR(5), 5)
        EVT_CALL(PlayEffect, 0x27, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), EVT_FIXED(1.0), 10, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(10)
        EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
        EVT_CALL(SetPartFlagBits, -127, 4, 1, 1)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartFlagBits, -127, 3, 1, 0)
        EVT_CALL(SetPartFlagBits, -127, 4, 1, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
    EVT_CALL(SetPartFlagBits, -127, 4, 1, 1)
    EVT_CALL(GetIndexFromHome, -127, EVT_VAR(0))
    EVT_MOD(EVT_VAR(0), 4)
    EVT_CALL(SetGoalToIndex, -127, EVT_VAR(0))
    EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetHomePos, -127, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 512, 0)
    EVT_CALL(SetStatusTable, -127, EVT_PTR(N(statusTable_8021CB18)))
    EVT_CALL(SetActorType, -127, 7)
    EVT_EXEC_WAIT(N(8021E584))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4096, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

// Copy of goomba.c follows..................
// TODO: deduplicate

s32 N(idleAnimations_8021E4EC)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_normal_idle,
    STATUS_STONE,     NPC_ANIM_goomba_normal_still,
    STATUS_SLEEP,     NPC_ANIM_goomba_normal_asleep,
    STATUS_POISON,    NPC_ANIM_goomba_normal_idle,
    STATUS_STOP,      NPC_ANIM_goomba_normal_still,
    STATUS_STATIC,    NPC_ANIM_goomba_normal_idle,
    STATUS_PARALYZE,  NPC_ANIM_goomba_normal_still,
    STATUS_DIZZY,     NPC_ANIM_goomba_normal_dizzy,
    STATUS_FEAR,      NPC_ANIM_goomba_normal_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021E538)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_normal_run,
    STATUS_STONE,     NPC_ANIM_goomba_normal_still,
    STATUS_SLEEP,     NPC_ANIM_goomba_normal_asleep,
    STATUS_POISON,    NPC_ANIM_goomba_normal_idle,
    STATUS_STOP,      NPC_ANIM_goomba_normal_still,
    STATUS_STATIC,    NPC_ANIM_goomba_normal_run,
    STATUS_PARALYZE,  NPC_ANIM_goomba_normal_still,
    STATUS_DIZZY,     NPC_ANIM_goomba_normal_dizzy,
    STATUS_FEAR,      NPC_ANIM_goomba_normal_dizzy,
    STATUS_END,
};

EvtSource N(takeTurn_8021F0D8);
EvtSource N(idle_8021E5D0);
EvtSource N(handleEvent_8021E8AC);

EvtSource N(8021E584) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021F0D8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021E5D0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021E8AC)))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8021E5D0) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, EVT_VAR(0))
    EVT_ADD(EVT_VAR(0), 80)
    EVT_LOOP(EVT_VAR(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FIXED(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021E538)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021E4EC)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FIXED(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021E538)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021E4EC)))
    EVT_LOOP(80)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_8021E8AC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_pain)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_burn_pain)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_goomba_normal_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_burn_pain)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_goomba_normal_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_burn_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_pain)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_dizzy)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(19)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_run)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_goomba_normal_pain)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_goomba_normal_pain)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "anglestuff.inc.c"

EvtSource N(takeTurn_8021F0D8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, EVT_VAR(0), ((0)), 0, 1, 16)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(EVT_VAR(10), EVT_VAR(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(0), 10)
            EVT_SET(EVT_VAR(1), 10)
            EVT_ADD(EVT_VAR(2), 3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(1), EVT_VAR(2), EVT_VAR(0))
                EVT_SET(EVT_VAR(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6))
                    EVT_CALL(N(AngleCalculate), EVT_VAR(1), EVT_VAR(2), EVT_VAR(4), EVT_VAR(5), EVT_VAR(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, EVT_VAR(0))
                    EVT_SET(EVT_VAR(1), EVT_VAR(4))
                    EVT_SET(EVT_VAR(2), EVT_VAR(5))
                    EVT_SET(EVT_VAR(3), EVT_VAR(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_asleep)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.3), EVT_FIXED(0.5), EVT_FIXED(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pain)
            EVT_WAIT_FRAMES(5)
            EVT_IF_EQ(EVT_VAR(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, EVT_VAR(0), ((0x80000000)), 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(0), 20)
            EVT_SET(EVT_VAR(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(2.0))
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_SET(EVT_VAR(0), 180)
                EVT_LOOP(4)
                    EVT_SUB(EVT_VAR(0), 45)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, EVT_VAR(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_dizzy)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(1), EVT_VAR(2), EVT_VAR(0))
                EVT_SET(EVT_VAR(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6))
                    EVT_CALL(N(AngleCalculate), EVT_VAR(1), EVT_VAR(2), EVT_VAR(4), EVT_VAR(5), EVT_VAR(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, EVT_VAR(0))
                    EVT_SET(EVT_VAR(1), EVT_VAR(4))
                    EVT_SET(EVT_VAR(2), EVT_VAR(5))
                    EVT_SET(EVT_VAR(3), EVT_VAR(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_pre_headbonk)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.3), EVT_FIXED(0.5), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, EVT_VAR(0), ((0)), 0, 0, 1, 32)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle)
            EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(0), 40)
            EVT_SET(EVT_VAR(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(EVT_VAR(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(EVT_VAR(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_idle)
            EVT_WAIT_FRAMES(3)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_normal_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
