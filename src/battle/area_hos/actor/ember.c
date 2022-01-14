#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/bubble.h"

#define NAMESPACE b_area_hos_ember

s32 N(defenseTable_8021ACB0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_WATER, -2,
    ELEMENT_ICE, -2,
    ELEMENT_FIRE, 99,
    ELEMENT_END,
};

s32 N(statusTable_8021ACD4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 90,
    STATUS_STOP, 85,
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

extern s32 N(idleAnimations_8021AE5C)[];
extern s32 N(idleAnimations_8021AEA8)[];

ActorPartBlueprint N(partsTable_8021AD80)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 25 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021AE5C),
        .defenseTable = N(defenseTable_8021ACB0),
        .eventFlags = ACTOR_EVENT_FLAG_FIREY,
        .elementImmunityFlags = 0,
        .unk_1C = -522,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021AEA8),
        .defenseTable = N(defenseTable_8021ACB0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021AEA8),
        .defenseTable = N(defenseTable_8021ACB0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021AEA8),
        .defenseTable = N(defenseTable_8021ACB0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021AEA8),
        .defenseTable = N(defenseTable_8021ACB0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
};

extern EvtSource N(init_8021AEB4);

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_EMBER,
    .level = 24,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(partsTable_8021AD80)),
    .partsData = N(partsTable_8021AD80),
    .script = N(init_8021AEB4),
    .statusTable = N(statusTable_8021ACD4),
    .escapeChance = 60,
    .airLiftChance = 80,
    .spookChance = 75,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 33, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8021AE5C)[] = {
    STATUS_NORMAL,    NPC_ANIM_bubble_Palette_01_Anim_1,
    STATUS_STONE,     NPC_ANIM_bubble_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_bubble_Palette_01_Anim_1,
    STATUS_POISON,    NPC_ANIM_bubble_Palette_01_Anim_1,
    STATUS_STOP,      NPC_ANIM_bubble_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_bubble_Palette_01_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_bubble_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_bubble_Palette_01_Anim_A,
    STATUS_FEAR,      NPC_ANIM_bubble_Palette_01_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations_8021AEA8)[] = {
    STATUS_NORMAL,    NPC_ANIM_bubble_Palette_01_Anim_1,
    STATUS_END,
};

extern EvtSource N(takeTurn_8021D284);
extern EvtSource N(idle_8021B07C);
extern EvtSource N(handleEvent_8021B8BC);

EvtSource N(init_8021AEB4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021D284)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021B07C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021B8BC)))
    EVT_CALL(GetActorVar, -127, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, -127, 0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(SetPartScale, -127, 2, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, -127, 3, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, -127, 4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetPartScale, -127, 5, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 5)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8021B07C) = {
    EVT_LABEL(0)
    EVT_CALL(MakeLerp, 0, 10, 25, 10)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(GetHomePos, -127, LW(2), LW(3), LW(4))
    EVT_ADD(LW(0), LW(3))
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(2), LW(0), LW(4))
    EVT_IF_EQ(LW(1), 1)
        EVT_LABEL(11)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_FLAG(LW(0), 0x35D000)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_CALL(GetActorVar, -127, 2, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(MakeLerp, 10, 0, 25, 10)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(GetHomePos, -127, LW(2), LW(3), LW(4))
    EVT_ADD(LW(0), LW(3))
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(2), LW(0), LW(4))
    EVT_IF_EQ(LW(1), 1)
        EVT_LABEL(22)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_FLAG(LW(0), 0x35D000)
            EVT_GOTO(22)
        EVT_END_IF
        EVT_CALL(GetActorVar, -127, 2, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_GOTO(22)
        EVT_END_IF
        EVT_GOTO(2)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "common/UnkSfxFunc.inc.c"

EvtSource N(8021B2FC) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021B398) = {
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(5))
    EVT_CALL(GetIndexFromHome, LW(0), LW(5))
    EVT_MOD(LW(5), 4)
    EVT_SWITCH(LW(5))
        EVT_CASE_EQ(0)
            EVT_SET(LF(1), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LF(2), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LF(3), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LF(4), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LF(1), 0)
        EVT_SET(LW(10), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LF(2), 0)
        EVT_SET(LW(10), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LF(3), 0)
        EVT_SET(LW(10), 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LF(4), 0)
        EVT_SET(LW(10), 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LW(10), -1)
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021B594) = { 0, -1000, 0, };

Formation N(specialFormation_8021B5A0) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(vector3D_8021B594) }},
};

EvtSource N(split) = {
    EVT_CALL(GetLastDamage, -127, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, -127, LW(0))
    EVT_IF_LE(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetLastElement, LW(0))
    EVT_IF_FLAG(LW(0), 0x20000000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 1, LW(0))
    EVT_IF_GE(LW(0), 2)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021B398))
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021B5A0)), 0)
            EVT_CALL(SetActorVar, LW(0), 2, 1)
            EVT_CALL(GetActorHP, -127, LW(11))
            EVT_CALL(SetEnemyHP, LW(0), LW(11))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(11), LW(12), LW(13))
            EVT_CALL(SetActorPos, LW(0), LW(11), LW(12), LW(13))
            EVT_CALL(SetGoalToIndex, LW(0), LW(10))
            EVT_CALL(GetGoalPos, LW(0), LW(11), LW(12), LW(13))
            EVT_CALL(SetHomePos, LW(0), LW(11), LW(12), LW(13))
            EVT_CALL(SetActorJumpGravity, LW(0), EVT_FLOAT(1.2001953125))
            EVT_CALL(JumpToGoal, LW(0), 20, FALSE, TRUE, FALSE)
            EVT_CALL(HPBarToHome, LW(0))
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_SWITCH(LW(1))
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, LW(0), 1, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetActorVar, LW(0), 1, 2)
            EVT_END_SWITCH
            EVT_CALL(SetActorVar, -127, 1, 3)
            EVT_CALL(SetActorVar, LW(0), 2, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_8021B8BC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_EXEC(N(split))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_EXEC(N(split))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_8)
            EVT_SET_CONST(LW(2), NPC_ANIM_bubble_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_8)
            EVT_SET_CONST(LW(2), NPC_ANIM_bubble_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_EXEC(N(split))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_759)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(8021B2FC))
        EVT_CASE_EQ(38)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_759)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
        EVT_CASE_OR_EQ(28)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(56)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(8021B2FC))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_bubble_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_bubble_Palette_01_Anim_3)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(61)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021BE64) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_1)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_4)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_ADD(LW(2), 1)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 3, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(14)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8021B2FC))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_4)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(2), 1)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_FIRE, 0, 0, 4, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_SET(LW(0), 1)
            EVT_SET(LW(1), 4587780)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_WAIT_FRAMES(5)
            EVT_EXEC_WAIT(N(8021B2FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021C454) = {
    EVT_SET(LW(6), 2)
    EVT_LOOP(4)
        EVT_THREAD
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
            EVT_IF_FLAG(LW(10), 0x80000)
                EVT_CALL(SetPartScale, -127, LW(6), EVT_FLOAT(0.2001953125), EVT_FLOAT(0.2001953125), EVT_FLOAT(0.2001953125))
            EVT_ELSE
                EVT_CALL(SetPartScale, -127, LW(6), EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
            EVT_END_IF
            EVT_CALL(SetPartPos, ACTOR_SELF, LW(6), LW(0), LW(1), LW(2))
            EVT_CALL(SetPartFlagBits, -127, LW(6), 1, 0)
            EVT_CALL(SetPartMoveSpeed, -127, LW(6), EVT_FLOAT(8.0))
            EVT_CALL(SetPartJumpGravity, -127, LW(6), EVT_FLOAT(0.0107421875))
            EVT_CALL(SetPartSounds, -127, LW(6), 2, 720, 0)
            EVT_CALL(JumpPartTo, -127, LW(6), LW(3), LW(4), LW(5), 0, 0)
            EVT_CALL(SetPartFlagBits, -127, LW(6), 1, 1)
        EVT_END_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_ADD(LW(6), 1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(8021C5F8) = {
    EVT_EXEC(N(8021C454))
    EVT_CALL(GetDistanceToGoal, -127, LW(0))
    EVT_DIVF(LW(0), EVT_FLOAT(8.0))
    EVT_ADD(LW(0), 1)
    EVT_WAIT_FRAMES(LW(0))
    EVT_RETURN
    EVT_END
};

EvtSource N(8021C654) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorVar, -127, 0, LW(10))
    EVT_IF_EQ(LW(10), 1)
        EVT_ADD(LW(0), 100)
        EVT_SET(LW(1), 5)
    EVT_ELSE
        EVT_ADD(LW(0), 30)
        EVT_SET(LW(1), 50)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_3)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_5)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_6)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 5)
            EVT_ADD(LW(1), 4)
            EVT_ADD(LW(2), 2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
            EVT_SUB(LW(3), 100)
            EVT_ADD(LW(5), 2)
            EVT_EXEC_WAIT(N(8021C5F8))
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8021B2FC))
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_6)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_ADD(LW(1), 4)
    EVT_ADD(LW(2), 2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_SUB(LW(4), 6)
    EVT_ADD(LW(5), 2)
    EVT_EXEC_WAIT(N(8021C5F8))
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), (DAMAGE_TYPE_FIRE | DAMAGE_TYPE_NO_CONTACT), 0, 0, 3, 32)
    EVT_WAIT_FRAMES(20)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_EXEC_WAIT(N(8021B2FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021CBC8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_THREAD
        EVT_CALL(N(UnkSfxFunc))
    EVT_END_THREAD
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 11)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetActorSounds, -127, 2, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2CF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_4)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(ResetActorSounds, -127, 2)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2EF)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_ADD(LW(2), 2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_4)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(30)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8021B2FC))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorSounds, -127, 2, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2CF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bubble_Palette_01_Anim_4)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(ResetActorSounds, -127, 2)
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_SET(LW(12), LW(2))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2EF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(2), 2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_FIRE, 0, 0, 4, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_WAIT_FRAMES(20)
            EVT_EXEC_WAIT(N(8021B2FC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8021D284) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetActorVar, -127, 0, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(1)
                EVT_EXEC_WAIT(N(8021BE64))
            EVT_CASE_EQ(0)
                EVT_EXEC_WAIT(N(8021CBC8))
        EVT_END_SWITCH
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(1)
            EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LW(0))
            EVT_IF_FLAG(LW(0), 0x1000000)
                EVT_EXEC_WAIT(N(8021BE64))
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LE(LW(0), 300)
                    EVT_EXEC_WAIT(N(8021C654))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(8021BE64))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LW(0))
            EVT_IF_FLAG(LW(0), 0x1000000)
                EVT_EXEC_WAIT(N(8021CBC8))
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LE(LW(0), 300)
                    EVT_EXEC_WAIT(N(8021C654))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(8021CBC8))
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
