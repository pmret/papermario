#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/flying_magikoopa.h"
#include "sprite/npc/magikoopa.h"

#define NAMESPACE b_area_hos_magikoopa

s32 N(defenseTable_8021D480)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable_8021D48C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021D498)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
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

s32 N(statusTable_8021D544)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
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

extern s32 N(idleAnimations_8021D6D0)[];

ActorPartBlueprint N(partsTable_8021D5F0)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D6D0),
        .defenseTable = N(defenseTable_8021D480),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFB,
        .unk_1D = 0xF4,
    },
};

extern s32 N(idleAnimations_8021D71C)[];
extern s32 N(idleAnimations_8021D768)[];

ActorPartBlueprint N(partsTable_8021D614)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D6D0),
        .defenseTable = N(defenseTable_8021D48C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFB,
        .unk_1D = 0xF4,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D71C),
        .defenseTable = N(defenseTable_8021D48C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D768),
        .defenseTable = N(defenseTable_8021D48C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

extern EvtScript N(init_8021E100);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_MAGIKOOPA_BOSS,
    .level = 32,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(partsTable_8021D5F0)),
    .partsData = N(partsTable_8021D5F0),
    .script = &N(init_8021E100),
    .statusTable = N(statusTable_8021D498),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 36, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(init_8021E2C0);

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS,
    .level = 32,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(partsTable_8021D614)),
    .partsData = N(partsTable_8021D614),
    .script = &N(init_8021E2C0),
    .statusTable = N(statusTable_8021D544),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 48, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8021D6D0)[] = {
    STATUS_NORMAL,    NPC_ANIM_magikoopa_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_magikoopa_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_magikoopa_Palette_00_Anim_8,
    STATUS_POISON,    NPC_ANIM_magikoopa_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_magikoopa_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_magikoopa_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_magikoopa_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_magikoopa_Palette_00_Anim_7,
    STATUS_FEAR,      NPC_ANIM_magikoopa_Palette_00_Anim_7,
    STATUS_END,
};

s32 N(idleAnimations_8021D71C)[] = {
    STATUS_NORMAL,    NPC_ANIM_flying_magikoopa_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_flying_magikoopa_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_flying_magikoopa_Palette_00_Anim_8,
    STATUS_POISON,    NPC_ANIM_flying_magikoopa_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_flying_magikoopa_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_flying_magikoopa_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_flying_magikoopa_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_flying_magikoopa_Palette_00_Anim_7,
    STATUS_FEAR,      NPC_ANIM_flying_magikoopa_Palette_00_Anim_7,
    STATUS_END,
};

s32 N(idleAnimations_8021D768)[] = {
    STATUS_NORMAL,    NPC_ANIM_flying_magikoopa_Palette_00_Anim_A,
    STATUS_END,
};

EvtScript N(idle_8021D774) = {
    EVT_RETURN
    EVT_END
};

#include "common/ShrinkActor.inc.c"

#include "common/GetSelectedMoveID.inc.c"

EvtScript N(8021D784) = {
    EVT_CALL(GetBattleFlags, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x80000)
        EVT_IF_FLAG(LocalVar(0), 0x240)
            EVT_CALL(SetActorVar, -127, 2, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LocalVar(0))
        EVT_SWITCH(LocalVar(0))
            EVT_CASE_OR_EQ(131)
            EVT_CASE_OR_EQ(132)
            EVT_CASE_OR_EQ(133)
            EVT_CASE_OR_EQ(136)
                EVT_CALL(GetBattleFlags, LocalVar(0))
                EVT_IF_FLAG(LocalVar(0), 0x240)
                    EVT_CALL(SetActorVar, -127, 2, 1)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

#include "common/StartRumbleWithParams.inc.c"

extern EvtScript N(handleEvent_8021E6D8);

EvtScript N(8021D890) = {
    EVT_CALL(GetActorVar, -127, 2, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_4)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetLastElement, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), 0x400)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_4)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), 0x80000)
        EVT_CALL(SetPartScale, -127, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, -127, 1, 8388608, 1)
    EVT_CALL(SetPartFlagBits, -127, 1, 131073, 0)
    EVT_CALL(SetPartFlagBits, -127, 2, 131073, 1)
    EVT_CALL(SetPartFlagBits, -127, 2, 8388608, 0)
    EVT_CALL(SetPartFlagBits, -127, 3, 1048576, 1)
    EVT_CALL(SetPartFlagBits, -127, 3, 1, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(2), 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x301)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 150, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(3))
    EVT_IF_EQ(LocalVar(3), 15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_4)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(3), LocalVar(4), LocalVar(5))
        EVT_ADD(LocalVar(4), 10)
        EVT_ADD(LocalVar(5), 5)
        EVT_CALL(PlayEffect, 0x27, 0, LocalVar(3), LocalVar(4), LocalVar(5), EVT_FLOAT(1.0), 10, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, -127, 3, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021E6D8)))
    EVT_CALL(SetActorType, -127, 149)
    EVT_CALL(SetStatusTable, -127, EVT_ADDR(N(statusTable_8021D498)))
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 32)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetIndexFromPos, -127, LocalVar(0))
    EVT_MOD(LocalVar(0), 4)
    EVT_CALL(SetGoalToIndex, -127, LocalVar(0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 57)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(EnableActorBlur, -127, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(RemoveActor, -127)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021E0B0) = {
    EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
    EVT_BITWISE_AND_CONST(LocalVar(0), -2) // TODO
    EVT_CALL(SetActorVar, -127, 0, LocalVar(0))
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_80223B24);

EvtScript N(init_8021E100) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021D774)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80223B24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021E6D8)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_8021E0B0)))
    EVT_CALL(GetBattleVar, 2, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 0)
    EVT_CALL(SetActorVar, -127, 4, 0)
    EVT_CALL(SetActorVar, -127, 5, 0)
    EVT_CALL(SetActorVar, -127, 6, 0)
    EVT_CALL(SetActorVar, -127, 7, 0)
    EVT_CALL(SetActorVar, -127, 8, 0)
    EVT_CALL(SetActorVar, -127, 9, -1)
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, -1)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(handleEvent_8021EDF0);

EvtScript N(init_8021E2C0) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021D774)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80223B24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021EDF0)))
    EVT_CALL(GetBattleVar, 2, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 0)
    EVT_CALL(SetActorVar, -127, 4, 0)
    EVT_CALL(SetActorVar, -127, 5, 0)
    EVT_CALL(SetActorVar, -127, 6, 0)
    EVT_CALL(SetActorVar, -127, 7, 0)
    EVT_CALL(SetActorVar, -127, 8, 0)
    EVT_CALL(SetActorVar, -127, 9, -1)
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E46C) = {
    EVT_CALL(GetActorVar, -127, 1, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 9, LocalVar(0))
    EVT_CALL(ActorExists, LocalVar(0), LocalVar(1))
    EVT_IF_EQ(LocalVar(1), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(GetLastElement, LocalVar(10))
    EVT_IF_FLAG(LocalVar(10), 0x20000000)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x100)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 9, LocalVar(0))
    EVT_CALL(SetActorVar, -127, 9, -1)
    EVT_CALL(GetActorFlags, -127, LocalVar(10))
    EVT_IF_FLAG(LocalVar(10), 0x200)
        EVT_CALL(SetPartEventBits, -127, 2, 4194304, 0)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, -127, 1, 4194304, 0)
    EVT_END_IF
    EVT_CALL(GetActorPos, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(RemoveActor, LocalVar(0))
    EVT_THREAD
        EVT_ADD(LocalVar(3), 2)
        EVT_LOOP(2)
            EVT_CALL(PlayEffect, 0x1, LocalVar(1), LocalVar(2), LocalVar(3), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021E6D8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetPartAlpha, -127, 1, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(9)
            EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
            EVT_BITWISE_OR_CONST(LocalVar(0), 0x1)
            EVT_CALL(SetActorVar, -127, 0, LocalVar(0))
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(61)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_5)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_magikoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_5)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_magikoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
            EVT_IF_FLAG(LocalVar(0), 0x1)
                EVT_EXEC_WAIT(N(8021E46C))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_EXEC_WAIT(N(8021E46C))
            EVT_END_IF
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
            EVT_EXEC_WAIT(N(runAway))
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_NOT_FLAG(LocalVar(0), 0x35D000)
                EVT_IF_FLAG(LocalVar(0), 0x80000)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 1, 0, 2, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 1, -4, 5, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(31)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(19)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021EDF0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetPartAlpha, -127, 2, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(9)
            EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
            EVT_BITWISE_OR_CONST(LocalVar(0), 0x1)
            EVT_CALL(SetActorVar, -127, 0, LocalVar(0))
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(12)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_EXEC_WAIT(N(8021D890))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(61)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(15)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_5)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_flying_magikoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_EXEC_WAIT(N(8021D890))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_5)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_flying_magikoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
            EVT_IF_FLAG(LocalVar(0), 0x1)
                EVT_EXEC_WAIT(N(8021E46C))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_NE(LocalVar(0), 0)
                EVT_EXEC_WAIT(N(8021E46C))
            EVT_END_IF
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(56)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(53)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
            EVT_EXEC_WAIT(N(runAway))
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_NOT_FLAG(LocalVar(0), 0x35D000)
                EVT_IF_FLAG(LocalVar(0), 0x80000)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, -3, 0, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, -15, 0, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(31)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(19)
            EVT_SET_CONST(LocalVar(0), 0x00000002)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_flying_magikoopa_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(healOne) = {
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, 0)
    EVT_CALL(AddActorVar, -127, 4, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 6)
            EVT_ADD(LocalVar(1), 12)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 16)
            EVT_ADD(LocalVar(1), 31)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 12)
            EVT_ADD(LocalVar(1), 14)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, LocalVar(11), 0x206D)
        EVT_CALL(PlaySoundAtActor, LocalVar(11), 0x214)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, LocalVar(11), SOUND_25C)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(HealActor, LocalVar(11), 0, 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(healAll) = {
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, 1)
    EVT_CALL(AddActorVar, -127, 3, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 6)
            EVT_ADD(LocalVar(1), 12)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 16)
            EVT_ADD(LocalVar(1), 31)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 12)
            EVT_ADD(LocalVar(1), 14)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 7, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(1))
    EVT_IF_EQ(LocalVar(1), 71)
        EVT_CALL(GetActorVar, LocalVar(0), 8, LocalVar(1))
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, LocalVar(0), 0x206D)
            EVT_CALL(PlaySoundAtActor, LocalVar(0), 0x214)
            EVT_WAIT(30)
            EVT_CALL(PlaySoundAtActor, LocalVar(0), SOUND_25C)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, LocalVar(0), 0, 1)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(WaitForBuffDone)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shapeSpell) = {
    EVT_CALL(SetActorVar, -127, 11, 2)
    EVT_SET(LocalFlag(0), 0)
    EVT_SET(LocalFlag(1), 0)
    EVT_CALL(GetActorVar, -127, 10, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(GetActorVar, -127, 9, LocalVar(10))
    EVT_END_IF
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), 0x200)
        EVT_SET(LocalFlag(1), 1)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(UseIdleAnimation, LocalVar(10), FALSE)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_IF_EQ(LocalFlag(1), 0)
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LocalVar(10), 1, 0x560002)
            EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 17)
            EVT_ADD(LocalVar(1), 33)
            EVT_CALL(PlayEffect, 0x47, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.5), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(3))
        EVT_IF_FLAG(LocalVar(3), 0x80000)
            EVT_SUB(LocalVar(0), 6)
            EVT_ADD(LocalVar(1), 13)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 17)
            EVT_ADD(LocalVar(1), 33)
        EVT_END_IF
        EVT_CALL(PlayEffect, 0x47, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LocalVar(10), 1, 0x570002)
            EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
            EVT_CALL(PlayEffect, 0x47, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.5), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(3))
        EVT_IF_FLAG(LocalVar(3), 0x80000)
            EVT_SUB(LocalVar(0), 12)
            EVT_ADD(LocalVar(1), 14)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
        EVT_END_IF
        EVT_CALL(PlayEffect, 0x47, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(9), 0, 0, 1, 16)
    EVT_SWITCH(LocalVar(9))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(PlaySoundAtActor, LocalVar(10), SOUND_SPELL_CAST2)
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_IF_EQ(LocalFlag(1), 0)
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(SetAnimation, LocalVar(10), 1, 0x560003)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_3)
            EVT_ELSE
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(SetAnimation, LocalVar(10), 1, 0x570003)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_3)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
            EVT_SUB(LocalVar(4), 50)
            EVT_SET(LocalVar(5), 0)
            EVT_IF_EQ(LocalFlag(1), 0)
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_SUB(LocalVar(0), 20)
                    EVT_ADD(LocalVar(1), 20)
                    EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(3))
                EVT_IF_FLAG(LocalVar(3), 0x80000)
                    EVT_SUB(LocalVar(0), 8)
                    EVT_ADD(LocalVar(1), 8)
                EVT_ELSE
                    EVT_SUB(LocalVar(0), 20)
                    EVT_ADD(LocalVar(1), 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 30)
            EVT_ELSE
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_SUB(LocalVar(0), 20)
                    EVT_ADD(LocalVar(1), 20)
                    EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(3))
                EVT_IF_FLAG(LocalVar(3), 0x80000)
                    EVT_SUB(LocalVar(0), 8)
                    EVT_ADD(LocalVar(1), 8)
                EVT_ELSE
                    EVT_SUB(LocalVar(0), 20)
                    EVT_ADD(LocalVar(1), 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 30)
            EVT_END_IF
            EVT_WAIT(50)
            EVT_IF_EQ(LocalVar(9), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, LocalVar(10), TRUE)
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(PlaySoundAtActor, LocalVar(10), SOUND_SPELL_CAST2)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_IF_EQ(LocalFlag(1), 0)
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LocalVar(10), 1, 0x560003)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_3)
    EVT_ELSE
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LocalVar(10), 1, 0x570003)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_3)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
    EVT_IF_EQ(LocalFlag(1), 0)
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 20)
            EVT_ADD(LocalVar(1), 20)
            EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(3))
        EVT_IF_FLAG(LocalVar(3), 0x80000)
            EVT_SUB(LocalVar(0), 8)
            EVT_ADD(LocalVar(1), 8)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 20)
            EVT_ADD(LocalVar(1), 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 20)
    EVT_ELSE
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 20)
            EVT_ADD(LocalVar(1), 20)
            EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(3))
        EVT_IF_FLAG(LocalVar(3), 0x80000)
            EVT_SUB(LocalVar(0), 8)
            EVT_ADD(LocalVar(1), 8)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 20)
            EVT_ADD(LocalVar(1), 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LocalVar(0), LocalVar(1), LocalVar(6), LocalVar(4), LocalVar(5), LocalVar(6), 20)
    EVT_END_IF
    EVT_WAIT(18)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 0, 32)
    EVT_ELSE
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 3, 32)
    EVT_END_IF
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(UseIdleAnimation, LocalVar(10), TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80221144) = {
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetIndexFromHome, LocalVar(0), LocalVar(1))
    EVT_MOD(LocalVar(1), 4)
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_SET(LocalFlag(11), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LocalFlag(12), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LocalFlag(13), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LocalFlag(14), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LocalVar(0), -1)
    EVT_CALL(GetIndexFromHome, -127, LocalVar(1))
    EVT_MOD(LocalVar(1), 4)
    EVT_SWITCH(LocalVar(1))
        EVT_CASE_EQ(0)
            EVT_IF_EQ(LocalFlag(12), 0)
                EVT_SET(LocalVar(0), 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LocalFlag(11), 0)
                EVT_SET(LocalVar(0), 0)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(13), 0)
                EVT_SET(LocalVar(0), 2)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LocalFlag(12), 0)
                EVT_SET(LocalVar(0), 1)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(14), 0)
                EVT_SET(LocalVar(0), 3)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LocalFlag(13), 0)
                EVT_SET(LocalVar(0), 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LocalVar(0), -1)
        EVT_CALL(GetActorFlags, -127, LocalVar(1))
        EVT_IF_FLAG(LocalVar(1), 0x200)
            EVT_ADD(LocalVar(0), 4)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022142C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8022143C) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022142C)))
    EVT_CALL(SetActorVar, -127, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80221478) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022142C)))
    EVT_CALL(SetActorVar, -127, 1, 1)
    EVT_RETURN
    EVT_END
};

s32 N(defenseTable_802214B4)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable_802214C0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_802214CC)[] = {
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

s32 N(statusTable_80221578)[] = {
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

ActorPartBlueprint N(partsTable_80221624)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D6D0),
        .defenseTable = N(defenseTable_802214B4),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFB,
        .unk_1D = 0xF4,
    },
};

ActorPartBlueprint N(partsTable_80221648)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D71C),
        .defenseTable = N(defenseTable_802214C0),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .unk_1D = 248,
    },
};

ActorBlueprint N(clone) = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_MAGICLONE,
    .level = 26,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(partsTable_80221624)),
    .partsData = N(partsTable_80221624),
    .script = &N(init_8022143C),
    .statusTable = N(statusTable_802214CC),
    .escapeChance = 40,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 36, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 32 },
};

ActorBlueprint N(flying_clone) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_FLYING_MAGICLONE,
    .level = 26,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(partsTable_80221648)),
    .partsData = N(partsTable_80221648),
    .script = &N(init_80221478),
    .statusTable = N(statusTable_80221578),
    .escapeChance = 40,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusMessageOffset = { 1, 34 },
};

Vec3i N(vector3D_802216BC) = { 0, 0xFFFFFC18, 0 };

Formation N(specialFormation_802216C8) = {
    { .actor = &N(clone), .home = { .vec = &N(vector3D_802216BC) }},
};

Formation N(specialFormation_802216E4) = {
    { .actor = &N(flying_clone), .home = { .vec = &N(vector3D_802216BC) }},
};

EvtScript N(makeCopy) = {
    EVT_CALL(CountPlayerTargets, -127, 32770, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, -127, 10, 1)
    EVT_CALL(SetActorVar, -127, 11, 3)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), 0x200)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_802216C8)), 0)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_802216E4)), 0)
    EVT_END_IF
    EVT_CALL(SetActorVar, -127, 9, LocalVar(0))
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(EnableIdleScript, LocalVar(10), 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, LocalVar(10), FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST3)
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
        EVT_CALL(SetAnimation, LocalVar(10), 1, 0x560002)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 23)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
        EVT_CALL(SetAnimation, LocalVar(10), 1, 0x570002)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 23)
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x6B, 1, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(EnableIdleScript, LocalVar(9), 1)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(2), -3)
    EVT_CALL(SetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(9), LocalVar(10))
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST4)
    EVT_CALL(PlaySoundAtActor, LocalVar(9), SOUND_SPELL_CAST4)
    EVT_CALL(SetPartFlagBits, LocalVar(9), 1, 8388608, 0)
    EVT_CALL(RandInt, 1000, LocalVar(0))
    EVT_IF_LT(LocalVar(0), 500)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(80221144))
        EVT_CALL(SetGoalToIndex, -127, LocalVar(0))
        EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(SetActorSpeed, LocalVar(9), EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(80221144))
        EVT_CALL(SetGoalToIndex, LocalVar(9), LocalVar(0))
        EVT_CALL(FlyToGoal, LocalVar(9), 0, 0, 0)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, LocalVar(9), 1, 8388608, 1)
    EVT_CALL(GetActorHP, -127, LocalVar(0))
    EVT_CALL(SetEnemyHP, LocalVar(9), LocalVar(0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorPos, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ForceHomePos, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(HPBarToHome, LocalVar(9))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetPartEventBits, -127, 1, 4194304, 1)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, -127, 2, 4194304, 1)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
        EVT_CALL(SetAnimation, LocalVar(9), 1, 0x560001)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
        EVT_CALL(SetAnimation, LocalVar(9), 1, 0x570001)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseIdleAnimation, LocalVar(9), TRUE)
    EVT_RETURN
    EVT_END
};

#include "world/common/UnkFunc52.inc.c"

EvtScript N(boostAttack) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetIndexFromHome, LocalVar(0), LocalVar(1))
    EVT_CALL(GetBattleVar, 2, LocalVar(2))
    EVT_IF_GT(LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkFunc52), LocalVar(0), LocalVar(3))
        EVT_IF_EQ(LocalVar(3), 0)
            EVT_CALL(GetActorAttackBoost, LocalVar(0), LocalVar(4))
            EVT_IF_LT(LocalVar(4), 0)
                EVT_SET(LocalVar(8), LocalVar(0))
                EVT_CALL(SetBattleVar, 2, LocalVar(1))
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, -127, 32770, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, 4)
    EVT_CALL(AddActorVar, -127, 5, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 6)
            EVT_ADD(LocalVar(1), 12)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 16)
            EVT_ADD(LocalVar(1), 31)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 12)
            EVT_ADD(LocalVar(1), 14)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LocalVar(8), 0x2DD)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(BoostAttack, LocalVar(8), 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(boostDefense) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetIndexFromHome, LocalVar(0), LocalVar(1))
    EVT_CALL(GetBattleVar, 2, LocalVar(2))
    EVT_IF_GT(LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkFunc52), LocalVar(0), LocalVar(3))
        EVT_IF_EQ(LocalVar(3), 0)
            EVT_CALL(GetActorDefenseBoost, LocalVar(0), LocalVar(4))
            EVT_IF_LT(LocalVar(4), 0)
                EVT_SET(LocalVar(8), LocalVar(0))
                EVT_CALL(SetBattleVar, 2, LocalVar(1))
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, -127, 32770, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, 5)
    EVT_CALL(AddActorVar, -127, 6, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 6)
            EVT_ADD(LocalVar(1), 12)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 16)
            EVT_ADD(LocalVar(1), 31)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 12)
            EVT_ADD(LocalVar(1), 14)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 5, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LocalVar(8), 0x2DD)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(BoostDefense, LocalVar(8), 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(electrify) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetIndexFromHome, LocalVar(0), LocalVar(1))
    EVT_CALL(GetBattleVar, 2, LocalVar(2))
    EVT_IF_GT(LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkFunc52), LocalVar(0), LocalVar(3))
        EVT_IF_EQ(LocalVar(3), 0)
            EVT_CALL(GetStatusFlags, LocalVar(0), LocalVar(4))
            EVT_IF_NOT_FLAG(LocalVar(4), 0x4002000)
                EVT_SET(LocalVar(8), LocalVar(0))
                EVT_CALL(SetBattleVar, 2, LocalVar(1))
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, -127, 32770, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, 6)
    EVT_CALL(AddActorVar, -127, 7, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2F0)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 6)
            EVT_ADD(LocalVar(1), 12)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x57, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 16)
            EVT_ADD(LocalVar(1), 31)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x57, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 12)
            EVT_ADD(LocalVar(1), 14)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x57, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x57, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, LocalVar(8), 0x3D2)
            EVT_CALL(RandInt, 3, LocalVar(0))
            EVT_ADD(LocalVar(0), 3)
            EVT_WAIT(LocalVar(0))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(ElectrifyActor, LocalVar(8), 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(vanish) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetIndexFromHome, LocalVar(0), LocalVar(1))
    EVT_CALL(GetBattleVar, 2, LocalVar(2))
    EVT_IF_GT(LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkFunc52), LocalVar(0), LocalVar(3))
        EVT_IF_EQ(LocalVar(3), 0)
            EVT_CALL(GetStatusFlags, LocalVar(0), LocalVar(4))
            EVT_IF_NOT_FLAG(LocalVar(4), 0x4002000)
                EVT_SET(LocalVar(8), LocalVar(0))
                EVT_CALL(SetBattleVar, 2, LocalVar(1))
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, -127, 32770, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, -127, 10, 0)
    EVT_CALL(SetActorVar, -127, 11, 7)
    EVT_CALL(AddActorVar, -127, 8, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_2)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 6)
            EVT_ADD(LocalVar(1), 12)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 6, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 16)
            EVT_ADD(LocalVar(1), 31)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 6, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
        EVT_IF_FLAG(LocalVar(10), 0x80000)
            EVT_SUB(LocalVar(0), 12)
            EVT_ADD(LocalVar(1), 14)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 6, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.1201171875), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LocalVar(0), 30)
            EVT_ADD(LocalVar(1), 36)
            EVT_SUB(LocalVar(2), 2)
            EVT_CALL(PlayEffect, 0x33, 6, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, -127, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_00_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_00_Anim_1)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LocalVar(8), 0x2DB)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(VanishActor, LocalVar(8), 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80223B24) = {
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC_WAIT(N(shapeSpell))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 10, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_SET(LocalVar(10), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(1))
    EVT_IF_EQ(LocalVar(1), 71)
        EVT_CALL(GetActorVar, LocalVar(0), 8, LocalVar(1))
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LocalVar(0), LocalVar(2))
    EVT_CALL(GetEnemyMaxHP, LocalVar(0), LocalVar(3))
    EVT_MULF(LocalVar(2), EVT_FLOAT(100.0))
    EVT_DIVF(LocalVar(2), LocalVar(3))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_IF_LE(LocalVar(2), 0)
            EVT_CALL(RandInt, 99, LocalVar(4))
            EVT_ADD(LocalVar(4), 1)
            EVT_IF_LT(LocalVar(4), 0)
                EVT_ADD(LocalVar(10), 1)
                EVT_SET(LocalVar(11), LocalVar(0))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_GT(LocalVar(10), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LocalVar(10), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(1))
    EVT_IF_EQ(LocalVar(1), 71)
        EVT_CALL(GetActorVar, LocalVar(0), 8, LocalVar(1))
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LocalVar(0), LocalVar(2))
    EVT_CALL(GetEnemyMaxHP, LocalVar(0), LocalVar(3))
    EVT_MULF(LocalVar(2), EVT_FLOAT(100.0))
    EVT_DIVF(LocalVar(2), LocalVar(3))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_IF_LE(LocalVar(2), 0)
            EVT_CALL(RandInt, 99, LocalVar(4))
            EVT_ADD(LocalVar(4), 1)
            EVT_IF_LT(LocalVar(4), 0)
                EVT_ADD(LocalVar(10), 1)
                EVT_SET(LocalVar(11), LocalVar(0))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_GT(LocalVar(10), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LocalVar(10), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(1))
    EVT_IF_EQ(LocalVar(1), 71)
        EVT_CALL(GetActorVar, LocalVar(0), 8, LocalVar(1))
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LocalVar(0), LocalVar(2))
    EVT_CALL(GetEnemyMaxHP, LocalVar(0), LocalVar(3))
    EVT_MULF(LocalVar(2), EVT_FLOAT(100.0))
    EVT_DIVF(LocalVar(2), LocalVar(3))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_IF_LE(LocalVar(2), 0)
            EVT_CALL(RandInt, 99, LocalVar(4))
            EVT_ADD(LocalVar(4), 1)
            EVT_IF_LT(LocalVar(4), 0)
                EVT_ADD(LocalVar(10), 1)
                EVT_SET(LocalVar(11), LocalVar(0))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_IF_GT(LocalVar(10), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_GOTO(20)
    EVT_LABEL(10)
    EVT_CALL(CountPlayerTargets, -127, 32770, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LocalVar(10), 1)
        EVT_CALL(GetActorVar, -127, 4, LocalVar(0))
        EVT_IF_LT(LocalVar(0), 0)
            EVT_CALL(RandInt, 1000, LocalVar(0))
            EVT_IF_LT(LocalVar(0), 0)
                EVT_EXEC_WAIT(N(healOne))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, -127, 3, LocalVar(0))
            EVT_IF_LT(LocalVar(0), 0)
                EVT_CALL(RandInt, 1000, LocalVar(0))
                EVT_IF_LT(LocalVar(0), 0)
                    EVT_EXEC_WAIT(N(healAll))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, -127, 3, LocalVar(0))
        EVT_IF_LT(LocalVar(0), 0)
            EVT_CALL(RandInt, 1000, LocalVar(0))
            EVT_IF_LT(LocalVar(0), 0)
                EVT_EXEC_WAIT(N(healAll))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, -127, 4, LocalVar(0))
            EVT_IF_LT(LocalVar(0), 0)
                EVT_SETF(LocalVar(9), EVT_FLOAT(100.0))
                EVT_CALL(EnemyCreateTargetList, 32770)
                EVT_CALL(InitTargetIterator)
                EVT_LABEL(11)
                EVT_SET(LocalFlag(0), 0)
                EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
                EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(1))
                EVT_IF_EQ(LocalVar(1), 71)
                    EVT_CALL(GetActorVar, LocalVar(0), 8, LocalVar(1))
                    EVT_IF_EQ(LocalVar(1), 1)
                        EVT_SET(LocalFlag(0), 1)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(GetActorHP, LocalVar(0), LocalVar(2))
                EVT_CALL(GetEnemyMaxHP, LocalVar(0), LocalVar(3))
                EVT_MULF(LocalVar(2), EVT_FLOAT(100.0))
                EVT_DIVF(LocalVar(2), LocalVar(3))
                EVT_IF_EQ(LocalFlag(0), 0)
                    EVT_IF_LE(LocalVar(2), LocalVar(9))
                        EVT_SETF(LocalVar(9), LocalVar(2))
                        EVT_SET(LocalVar(11), LocalVar(0))
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
                EVT_IF_NE(LocalVar(0), -1)
                    EVT_GOTO(11)
                EVT_END_IF
                EVT_CALL(RandInt, 1000, LocalVar(0))
                EVT_IF_LT(LocalVar(0), 0)
                    EVT_EXEC_WAIT(N(healOne))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(20)
    EVT_SET(LocalVar(10), 100)
    EVT_SET(LocalVar(11), 0)
    EVT_SET(LocalVar(12), 0)
    EVT_SET(LocalVar(13), 0)
    EVT_SET(LocalVar(14), 0)
    EVT_SET(LocalVar(15), 0)
    EVT_CALL(GetActorVar, -127, 10, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_SET(LocalVar(10), 100)
        EVT_SET(LocalVar(11), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_SET(LocalVar(13), 0)
        EVT_SET(LocalVar(14), 0)
        EVT_SET(LocalVar(15), 0)
        EVT_GOTO(123)
    EVT_ELSE
        EVT_EXEC_WAIT(N(80221144))
        EVT_IF_EQ(LocalVar(0), -1)
            EVT_SET(LocalVar(11), 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 0)
        EVT_SET(LocalVar(11), 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 11, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(4)
            EVT_CALL(GetActorVar, -127, 5, LocalVar(1))
            EVT_IF_LT(LocalVar(1), 0)
                EVT_CALL(RandInt, 99, LocalVar(0))
                EVT_ADD(LocalVar(0), 1)
                EVT_IF_LE(LocalVar(0), 0)
                    EVT_SET(LocalVar(10), 0)
                    EVT_SET(LocalVar(11), 0)
                    EVT_SET(LocalVar(12), 100)
                    EVT_SET(LocalVar(13), 0)
                    EVT_SET(LocalVar(14), 0)
                    EVT_SET(LocalVar(15), 0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorVar, -127, 6, LocalVar(1))
            EVT_IF_LT(LocalVar(1), 0)
                EVT_CALL(RandInt, 99, LocalVar(0))
                EVT_ADD(LocalVar(0), 1)
                EVT_IF_LE(LocalVar(0), 0)
                    EVT_SET(LocalVar(10), 0)
                    EVT_SET(LocalVar(11), 0)
                    EVT_SET(LocalVar(12), 0)
                    EVT_SET(LocalVar(13), 100)
                    EVT_SET(LocalVar(14), 0)
                    EVT_SET(LocalVar(15), 0)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, -127, 5, LocalVar(0))
    EVT_IF_GE(LocalVar(0), 0)
        EVT_SET(LocalVar(12), 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 6, LocalVar(0))
    EVT_IF_GE(LocalVar(0), 0)
        EVT_SET(LocalVar(13), 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 7, LocalVar(0))
    EVT_IF_GE(LocalVar(0), 0)
        EVT_SET(LocalVar(14), 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 8, LocalVar(0))
    EVT_IF_GE(LocalVar(0), 0)
        EVT_SET(LocalVar(15), 0)
    EVT_END_IF
    EVT_LABEL(123)
    EVT_SET(LocalVar(9), 0)
    EVT_ADD(LocalVar(9), LocalVar(10))
    EVT_ADD(LocalVar(9), LocalVar(11))
    EVT_ADD(LocalVar(9), LocalVar(12))
    EVT_ADD(LocalVar(9), LocalVar(13))
    EVT_ADD(LocalVar(9), LocalVar(14))
    EVT_ADD(LocalVar(9), LocalVar(15))
    EVT_SUB(LocalVar(9), 1)
    EVT_CALL(RandInt, LocalVar(9), LocalVar(0))
    EVT_ADD(LocalVar(0), 1)
    EVT_IF_LE(LocalVar(0), LocalVar(10))
        EVT_EXEC_WAIT(N(shapeSpell))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LocalVar(10), LocalVar(11))
    EVT_IF_LE(LocalVar(0), LocalVar(10))
        EVT_EXEC_WAIT(N(makeCopy))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LocalVar(10), LocalVar(12))
    EVT_IF_LE(LocalVar(0), LocalVar(10))
        EVT_EXEC_WAIT(N(boostAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LocalVar(10), LocalVar(13))
    EVT_IF_LE(LocalVar(0), LocalVar(10))
        EVT_EXEC_WAIT(N(boostDefense))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LocalVar(10), LocalVar(14))
    EVT_IF_LE(LocalVar(0), LocalVar(10))
        EVT_EXEC_WAIT(N(electrify))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(vanish))
    EVT_RETURN
    EVT_END
};
