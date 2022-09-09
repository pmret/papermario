#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/monty_mole.h"

#define NAMESPACE b_area_iwa_monty_mole

extern s32 N(idleAnimations_8021A59C)[];
extern s32 N(idleAnimations_8021A5E8)[];
extern EvtScript N(init_8021A7B0);
extern EvtScript N(takeTurn_8021AFAC);
extern EvtScript N(idle_8021A814);
extern EvtScript N(handleEvent_8021A824);

s32 N(defenseTable_8021A450)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021A45C)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 90,
    STATUS_POISON, 80,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 10,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 90,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021A508)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 16 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A59C),
        .defenseTable = N(defenseTable_8021A450),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 249,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 0, -15 },
        .targetOffset = { -2, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A59C),
        .defenseTable = N(defenseTable_8021A450),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 249,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A5E8),
        .defenseTable = N(defenseTable_8021A450),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint N(1) = {
    .flags = 0,
    .type = ACTOR_TYPE_MONTY_MOLE,
    .level = 8,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(partsTable_8021A508)),
    .partsData = N(partsTable_8021A508),
    .script = &N(init_8021A7B0),
    .statusTable = N(statusTable_8021A45C),
    .escapeChance = 80,
    .airLiftChance = 70,
    .spookChance = 50,
    .baseStatusChance = 85,
    .upAndAwayChance = 95,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 34, 18 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8021A59C)[] = {
    STATUS_NORMAL,    NPC_ANIM_monty_mole_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_monty_mole_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_monty_mole_Palette_00_Anim_14,
    STATUS_POISON,    NPC_ANIM_monty_mole_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_monty_mole_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_monty_mole_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_monty_mole_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_monty_mole_Palette_00_Anim_14,
    STATUS_FEAR,      NPC_ANIM_monty_mole_Palette_00_Anim_14,
    STATUS_END,
};

s32 N(idleAnimations_8021A5E8)[] = {
    STATUS_NORMAL,    NPC_ANIM_monty_mole_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(idleAnimations_8021A5F4)[] = {
    STATUS_NORMAL,    NPC_ANIM_monty_mole_Palette_00_Anim_12,
    STATUS_END,
};

s32 N(unk_missing_8021A600)[] = {
    0x00000001, 0x002F0006, 0x00000000,
};

ActorPartBlueprint N(partsTable_8021A60C)[] = {
    {
        .flags = ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A5F4),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

EvtScript N(init_8021A630) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

ActorBlueprint N(2) = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_40000 | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY,
    .type = ACTOR_TYPE_MONTY_HOLE,
    .level = 9,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(partsTable_8021A60C)),
    .partsData = N(partsTable_8021A60C),
    .script = &N(init_8021A630),
    .statusTable = NULL,
    .escapeChance = 80,
    .airLiftChance = 0,
    .spookChance = 80,
    .baseStatusChance = 80,
    .upAndAwayChance = 90,
    .spinSmashReq = 4,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 32, 18 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

Vec3i N(vector3D_8021A6B8) = { 0, 0xFFFFFC18, 0, };

Formation N(specialFormation_8021A6C4) = {
    { .actor = &N(2), .home = { .vec = &N(vector3D_8021A6B8) },},
};

Formation N(specialFormation_8021A6E0) = {
    { .actor = &N(2), .home = { .vec = &N(vector3D_8021A6B8) }, .var0 = 1 },
};

EvtScript N(8021A6FC) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8021A6E0)), 0)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8021A6C4)), 0)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_SUB(LocalVar(3), 1)
    EVT_CALL(SetActorPos, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8021A7B0) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021AFAC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021A814)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021A824)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021A814) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021A824) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_SMASH)
                EVT_CHILD_THREAD
                    EVT_WAIT(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_7)
                EVT_END_CHILD_THREAD
                EVT_SET_CONST(LocalVar(0), 1)
                EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_8)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_SET_CONST(LocalVar(0), 1)
                EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_5)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_A)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_monty_mole_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_A)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_monty_mole_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021A6FC))
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetLastElement, LocalVar(0))
            EVT_IF_FLAG(LocalVar(0), DAMAGE_TYPE_SMASH)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_11)
                EVT_WAIT(80)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_10)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_14)
                EVT_WAIT(20)
            EVT_ELSE
                EVT_SET_CONST(LocalVar(0), 1)
                EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_6)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(8021A6FC))
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_6)
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_7)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_8)
            EVT_WAIT(8)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_6)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_7)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_8)
            EVT_WAIT(15)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_APPLY, 1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021A5F4)))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_monty_mole_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(8021A6FC))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -5, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_19)
            EVT_ELSE
                EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -9, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -23, 0)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_9)
            EVT_END_IF
            EVT_WAIT(1000)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_11)
            EVT_WAIT(40)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_10)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_14)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_EXEC_WAIT(N(8021A6FC))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021AFAC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_monty_mole_Palette_00_Anim_4)
    EVT_WAIT(37)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, SOUND_MOLE_THROW)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, 1, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LocalVar(0))
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 100)
            EVT_SET(LocalVar(1), -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_monty_mole_Palette_00_Anim_F)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LocalVar(0), LocalVar(1), LocalVar(2), 0, 30, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(12.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_monty_mole_Palette_00_Anim_F)
    EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LocalVar(0), LocalVar(1), LocalVar(2), 0, 20, 0)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 55)
            EVT_SET(LocalVar(1), 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LocalVar(0), LocalVar(1), LocalVar(2), 0, 25, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(4.0))
            EVT_SUB(LocalVar(0), 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LocalVar(0), LocalVar(1), LocalVar(2), 0, 21, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
