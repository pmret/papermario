#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/magikoopa.h"
#include "sprite/npc/flying_magikoopa.h"

extern EvtScript N(init);
extern EvtScript N(init_flying);
extern EvtScript N(takeTurn);

extern EvtScript N(flee);

extern s32 N(idleAnimations1)[];
extern s32 N(idleAnimations2)[];
extern s32 N(idleAnimations3)[];

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable_flying)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 50,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

s32 N(statusTable_flying)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 50,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations1),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -5,
        .unk_1D = -12,
    },
};

ActorPartBlueprint N(parts_flying)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations1),
        .defenseTable = N(defenseTable_flying),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -5,
        .unk_1D = -12,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations2),
        .defenseTable = N(defenseTable_flying),
        .eventFlags = ACTOR_EVENT_FLAG_800000,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations3),
        .defenseTable = N(defenseTable_flying),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GRAY_MAGIKOOPA,
    .level = 21,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 40,
    .airLiftChance = 80,
    .spookChance = 70,
    .baseStatusChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 36, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 32 },
};

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA,
    .level = 21,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(parts_flying)),
    .partsData = N(parts_flying),
    .script = &N(init_flying),
    .statusTable = N(statusTable_flying),
    .escapeChance = 40,
    .airLiftChance = 95,
    .spookChance = 75,
    .baseStatusChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusMessageOffset = { 1, 34 },
};

s32 N(idleAnimations1)[] = {
    STATUS_NORMAL, NPC_ANIM_magikoopa_Palette_05_Anim_1,
    STATUS_STONE, NPC_ANIM_magikoopa_Palette_05_Anim_0,
    STATUS_SLEEP, NPC_ANIM_magikoopa_Palette_05_Anim_8,
    STATUS_POISON, NPC_ANIM_magikoopa_Palette_05_Anim_1,
    STATUS_STOP, NPC_ANIM_magikoopa_Palette_05_Anim_0,
    STATUS_STATIC, NPC_ANIM_magikoopa_Palette_05_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_magikoopa_Palette_05_Anim_0,
    STATUS_DIZZY, NPC_ANIM_magikoopa_Palette_05_Anim_7,
    STATUS_FEAR, NPC_ANIM_magikoopa_Palette_05_Anim_7,
    STATUS_END,
};

s32 N(idleAnimations2)[] = {
    STATUS_NORMAL, NPC_ANIM_flying_magikoopa_Palette_05_Anim_1,
    STATUS_STONE, NPC_ANIM_flying_magikoopa_Palette_05_Anim_0,
    STATUS_SLEEP, NPC_ANIM_flying_magikoopa_Palette_05_Anim_8,
    STATUS_POISON, NPC_ANIM_flying_magikoopa_Palette_05_Anim_1,
    STATUS_STOP, NPC_ANIM_flying_magikoopa_Palette_05_Anim_0,
    STATUS_STATIC, NPC_ANIM_flying_magikoopa_Palette_05_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_flying_magikoopa_Palette_05_Anim_0,
    STATUS_DIZZY, NPC_ANIM_flying_magikoopa_Palette_05_Anim_7,
    STATUS_FEAR, NPC_ANIM_flying_magikoopa_Palette_05_Anim_7,
    STATUS_END,
};

s32 N(idleAnimations3)[] = {
    STATUS_NORMAL, NPC_ANIM_flying_magikoopa_Palette_05_Anim_A,
    STATUS_END,
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

#include "common/ShrinkActor.inc.c"
#include "common/GetSelectedMoveID.inc.c"
#include "common/UnkBattleFunc1.inc.c"
#include "common/StartRumbleWithParams.inc.c"
#include "world/common/UnkFunc52.inc.c"

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_5)
            EVT_SET_CONST(LW(2), NPC_ANIM_magikoopa_Palette_05_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_5)
            EVT_SET_CONST(LW(2), NPC_ANIM_magikoopa_Palette_05_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_2)
            EVT_EXEC_WAIT(N(flee))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_2)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 1, 0, 2, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 1, -4, 5, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(canBeKnockedOff) = {
    EVT_CALL(GetBattleFlags, LW(0))
    EVT_IF_NOT_FLAG(LW(0), BS_FLAGS1_80000)
        EVT_IF_FLAG(LW(0), BS_FLAGS1_40 | BS_FLAGS1_200)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_OR_EQ(MOVE_HEADBONK1)
            EVT_CASE_OR_EQ(MOVE_HEADBONK2)
            EVT_CASE_OR_EQ(MOVE_HEADBONK3)
            EVT_CASE_OR_EQ(MOVE_MULTIBONK)
                EVT_CALL(GetBattleFlags, LW(0))
                EVT_IF_FLAG(LW(0), BS_FLAGS1_40 | BS_FLAGS1_200)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(knockOff) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_4)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetLastElement, LW(0))
    EVT_IF_FLAG(LW(0), DAMAGE_TYPE_POW)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_4)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_MULTI_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(2), 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 150, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(3))
    EVT_IF_EQ(LW(3), EVENT_15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_4)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
        EVT_ADD(LW(4), 10)
        EVT_ADD(LW(5), 5)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 10, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_GRAY_MAGIKOOPA)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_ADDR(N(statusTable)))
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 32)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LW(0))
    EVT_MOD(LW(0), 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LW(0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_flying) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(canBeKnockedOff))
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_FALL_TRIGGER)
            EVT_EXEC_WAIT(N(canBeKnockedOff))
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(knockOff))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_15)
            EVT_EXEC_WAIT(N(canBeKnockedOff))
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_5)
            EVT_SET_CONST(LW(2), NPC_ANIM_flying_magikoopa_Palette_05_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(knockOff))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_5)
            EVT_SET_CONST(LW(2), NPC_ANIM_flying_magikoopa_Palette_05_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_1)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_2)
            EVT_EXEC_WAIT(N(flee))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_2)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, -3, 0, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, -15, 0, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_flying_magikoopa_Palette_05_Anim_4)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackMagicBlast) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_SUB(LW(0), 12)
        EVT_ADD(LW(1), 14)
    EVT_ELSE
        EVT_SUB(LW(0), 30)
        EVT_ADD(LW(1), 36)
    EVT_END_IF
    EVT_CALL(PlayEffect, EFFECT_GATHER_MAGIC, 0, LW(0), LW(1), LW(2), EVT_FLOAT(0.5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_2)
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_3)
            EVT_WAIT(5)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(9))
            EVT_IF_FLAG(LW(9), STATUS_FLAG_SHRINK)
                EVT_SUB(LW(0), 8)
                EVT_ADD(LW(1), 8)
            EVT_ELSE
                EVT_SUB(LW(0), 20)
                EVT_ADD(LW(1), 20)
            EVT_END_IF
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
            EVT_SUB(LW(3), 50)
            EVT_SET(LW(4), 0)
            EVT_CALL(N(ShrinkActor), LW(0), LW(1), LW(5), LW(3), LW(4), LW(5), 25)
            EVT_WAIT(50)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(14)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_3)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_SUB(LW(0), 8)
        EVT_ADD(LW(1), 8)
    EVT_ELSE
        EVT_SUB(LW(0), 20)
        EVT_ADD(LW(1), 20)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_SUB(LW(3), 10)
    EVT_CALL(N(ShrinkActor), LW(0), LW(1), LW(5), LW(3), LW(4), LW(5), 20)
    EVT_WAIT(18)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_WAIT(19)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackWandStrike) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2DB)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_2)
        EVT_SET(LW(0), 200)
        EVT_LOOP(20)
            EVT_SUB(LW(0), 10)
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(0), 5)
    EVT_ELSE
        EVT_ADD(LW(0), 25)
    EVT_END_IF
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
    EVT_SET(LW(0), 55)
    EVT_LOOP(20)
        EVT_ADD(LW(0), 10)
        EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_3)
    EVT_WAIT(11)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2DC)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_SET(LW(0), 200)
            EVT_LOOP(20)
                EVT_SUB(LW(0), 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_1)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_SET(LW(0), 55)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT(10)
            EVT_SET(LW(0), 200)
            EVT_LOOP(20)
                EVT_SUB(LW(0), 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_1)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, 10)
            EVT_SET(LW(0), 55)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(flee) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_IF_NE(LW(0), EVENT_SCARE_AWAY)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(GetBattleVar, 2, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_flying) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_flying)))
    EVT_CALL(GetBattleVar, 2, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_SET(ScriptFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(GetIndexFromHome, LW(0), LW(1))
    EVT_CALL(GetBattleVar, 2, LW(2))
    EVT_IF_GT(LW(1), LW(2))
        EVT_CALL(N(UnkFunc52), LW(0), LW(3))
        EVT_IF_EQ(LW(3), 0)
            EVT_CALL(GetStatusFlags, LW(0), LW(4))
            EVT_IF_NOT_FLAG(LW(4), STATUS_FLAG_STATIC | STATUS_FLAG_TRANSPARENT)
                EVT_SET(LW(8), LW(0))
                EVT_CALL(SetBattleVar, 2, LW(1))
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(ScriptFlag(0), 0)
        EVT_SET(ScriptFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, 32770, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_EXEC_WAIT(N(flee))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_EXEC_WAIT(N(attackMagicBlast))
    EVT_ELSE
        EVT_EXEC_WAIT(N(attackWandStrike))
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(100) // make ally invisible
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_2)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
        EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
            EVT_SUB(LW(0), 6)
            EVT_ADD(LW(1), 12)
            EVT_SUB(LW(2), 2)
            EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 6, LW(0), LW(1), LW(2), EVT_FLOAT(0.12), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LW(0), 16)
            EVT_ADD(LW(1), 31)
            EVT_SUB(LW(2), 2)
            EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 6, LW(0), LW(1), LW(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
        EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
            EVT_SUB(LW(0), 12)
            EVT_ADD(LW(1), 14)
            EVT_SUB(LW(2), 2)
            EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 6, LW(0), LW(1), LW(2), EVT_FLOAT(0.12), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_ELSE
            EVT_SUB(LW(0), 30)
            EVT_ADD(LW(1), 36)
            EVT_SUB(LW(2), 2)
            EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 6, LW(0), LW(1), LW(2), EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_magikoopa_Palette_05_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_flying_magikoopa_Palette_05_Anim_1)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LW(8), SOUND_2DB)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(VanishActor, LW(8), 2)
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
