#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/fuzzipede.h"

#define NAMESPACE b_area_kgr_fuzzipede

extern EvtScript N(init_80218B70);
extern EvtScript N(takeTurn_8021C1A4);
extern EvtScript N(idle_80218D58);
extern EvtScript N(handleEvent_802197FC);
extern EvtScript N(handleEvent_80219ED4);
extern EvtScript N(nextTurn_80218C58);
extern EvtScript N(8021A2E8);

s32 N(idleAnimations_802189B0)[] = {
    STATUS_NORMAL,    NPC_ANIM_fuzzipede_Palette_00_Anim_4,
    STATUS_STONE,     NPC_ANIM_fuzzipede_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_fuzzipede_Palette_00_Anim_29,
    STATUS_POISON,    NPC_ANIM_fuzzipede_Palette_00_Anim_4,
    STATUS_STOP,      NPC_ANIM_fuzzipede_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_fuzzipede_Palette_00_Anim_4,
    STATUS_PARALYZE,  NPC_ANIM_fuzzipede_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_fuzzipede_Palette_00_Anim_26,
    STATUS_FEAR,      NPC_ANIM_fuzzipede_Palette_00_Anim_26,
    STATUS_END,
};

s32 N(idleAnimations_802189FC)[] = {
    STATUS_NORMAL,    NPC_ANIM_fuzzipede_Palette_00_Anim_6,
    STATUS_STONE,     NPC_ANIM_fuzzipede_Palette_00_Anim_2,
    STATUS_SLEEP,     NPC_ANIM_fuzzipede_Palette_00_Anim_2A,
    STATUS_POISON,    NPC_ANIM_fuzzipede_Palette_00_Anim_6,
    STATUS_STOP,      NPC_ANIM_fuzzipede_Palette_00_Anim_2,
    STATUS_STATIC,    NPC_ANIM_fuzzipede_Palette_00_Anim_6,
    STATUS_PARALYZE,  NPC_ANIM_fuzzipede_Palette_00_Anim_2,
    STATUS_DIZZY,     NPC_ANIM_fuzzipede_Palette_00_Anim_27,
    STATUS_FEAR,      NPC_ANIM_fuzzipede_Palette_00_Anim_27,
    STATUS_END,
};

s32 N(defenseTable_80218A48)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80218A54)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 50,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 50,
    STATUS_STOP, 75,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80218B00)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802189B0),
        .defenseTable = N(defenseTable_80218A48),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFE,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 40, 0 },
        .targetOffset = { 2, -16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218A48),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFE,
        .unk_1D = 0xF6,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_FUZZIPEDE,
    .level = 43,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_80218B00)),
    .partsData = N(partsTable_80218B00),
    .script = &N(init_80218B70),
    .statusTable = N(statusTable_80218A54),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 26, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(init_80218B70) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021C1A4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80218D58)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802197FC)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_80218C58)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(SetHomePos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(func_80253734, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80218C58) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 10)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(30)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x07, 0x009C), ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_24, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(30)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80218D58) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80218D68) = {
    EVT_CALL(SetHomePos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_A)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 60)
    EVT_SET(LW(1), 0)
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802189B0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802197FC)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 2, 24)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -2, -10)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_MULTI_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(80218FC8) = {
    EVT_CALL(SetHomePos, ACTOR_SELF, 60, 0, 15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_A)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802189B0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802197FC)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 2, 24)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -2, -10)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_MULTI_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(802191AC) = {
    EVT_CALL(SetHomePos, ACTOR_SELF, 30, 115, -28)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_A)
    EVT_SET(LW(0), 65)
    EVT_SET(LW(1), 0)
    EVT_SET(LW(2), -15)
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, 100, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 110, 109, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 90, 117, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 120, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 50, 125, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 30, 130, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_LOOP(10)
            EVT_ADDF(LW(1), EVT_FLOAT(-1.5))
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(LW(0), 0)
    EVT_LOOP(10)
        EVT_ADD(LW(0), 18)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LW(0), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802189FC)))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_6)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80219ED4)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 1)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 2, 24)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 2, 8)
    EVT_CALL(N(UnkBattleFunc1), -10, -25, 10, -30)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_MULTI_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(80219668) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 4)
        EVT_CASE_EQ(4)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(80218D68))
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
            EVT_EXEC_WAIT(N(802191AC))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(3)
            EVT_EXEC_WAIT(N(80218FC8))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802197FC) = {
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1E)
            EVT_SET_CONST(LW(2), NPC_ANIM_fuzzipede_Palette_00_Anim_1F)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1E)
            EVT_SET_CONST(LW(2), NPC_ANIM_fuzzipede_Palette_00_Anim_1F)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1F)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80219668))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SWAP_PARTNER)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_19)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80219D68) = {
    EVT_CALL(GetLastDamage, ACTOR_SELF, LW(0))
    EVT_IF_LE(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_EXEC_WAIT(N(8021A2E8))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802189B0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802197FC)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 2, 24)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -2, -10)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
        EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_ELSE
        EVT_EXEC_WAIT(N(802191AC))
        EVT_WAIT(20)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80219ED4) = {
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1C)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1C)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(80219D68))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_20)
            EVT_SET_CONST(LW(2), NPC_ANIM_fuzzipede_Palette_00_Anim_21)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(80219D68))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_20)
            EVT_SET_CONST(LW(2), NPC_ANIM_fuzzipede_Palette_00_Anim_21)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_21)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80219668))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1C)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzipede_Palette_00_Anim_1C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A2E8) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 60)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(3)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_HP_OFFSET_BELOW, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 180)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.001953125))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
            EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
                EVT_SET(LW(1), 11)
            EVT_ELSE
                EVT_SET(LW(1), 28)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_THREAD
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LW(0), 180)
                EVT_LOOP(8)
                    EVT_SUB(LW(0), 22)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A6D8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_EXEC_WAIT(N(8021A2E8))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_A)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_12)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DA)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_5)
            EVT_THREAD
                EVT_SET(LW(0), 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(20)
                    EVT_ADD(LW(0), 9)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -20, 0, 5)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), -5, LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(15), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
            EVT_END_THREAD
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(80219668))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_5)
    EVT_THREAD
        EVT_SET(LW(0), 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
        EVT_LOOP(20)
            EVT_ADD(LW(0), 9)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
            EVT_THREAD
                EVT_SET(LW(0), 180)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(10)
                    EVT_SUB(LW(0), 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 30)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_EXEC_WAIT(N(80219668))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/ItemEntityJumpToPos.inc.c"

#include "common/DisableRandomAbility.inc.c"

#include "common/StartRumbleWithParams.inc.c"

#include "common/SpyGuyActionFunc.inc.c"

EvtScript N(8021B008) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(1), LW(2), LW(3))
            EVT_SET(LW(2), 0)
            EVT_SUB(LW(3), 1)
            EVT_CALL(N(DisableRandomAbility), LW(4), LW(5))
            EVT_CALL(MakeItemEntity, LW(4), LW(1), LW(2), LW(3), 1, 0)
            EVT_ADD(LW(1), 30)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 20, EVT_FLOAT(1.0))
            EVT_ADD(LW(1), 20)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 10, EVT_FLOAT(1.0))
            EVT_ADD(LW(1), 10)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 5, EVT_FLOAT(1.0))
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(ShowMessageBox, LW(5), 60)
            EVT_SUB(LW(1), 150)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 30, EVT_FLOAT(1.0))
            EVT_CALL(RemoveItemEntity, LW(0))
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B22C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_EXEC_WAIT(N(8021A2E8))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_A)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 80)
    EVT_SET(LW(1), 0)
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_12)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DB)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_11)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.001953125))
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(15), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
            EVT_THREAD
                EVT_SET(LW(0), 90)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(6)
                    EVT_ADD(LW(0), 15)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_SET(LW(0), 180)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(7)
                    EVT_ADD(LW(0), 25)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 7, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(80219668))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_11)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.001953125))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(2), 1)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_THREAD
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_SET(ScriptFlag(0), 0)
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_NOT_FLAG(LW(0), BS_FLAGS1_ATK_BLOCKED)
                EVT_SET(ScriptFlag(0), 1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LW(0))
            EVT_IF_LE(LW(0), 0)
                EVT_SET(ScriptFlag(0), 0)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_SET(ScriptFlag(0), 0)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
                EVT_SET(ScriptFlag(0), 0)
            EVT_END_IF
            EVT_IF_EQ(ScriptFlag(0), 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                EVT_EXEC(N(8021B008))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), 40)
                EVT_SET(LW(1), 0)
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                EVT_ADD(LW(0), 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                EVT_ADD(LW(0), 20)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
                EVT_WAIT(8)
                EVT_LABEL(0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
                EVT_IF_NE(LW(0), 0)
                    EVT_WAIT(1)
                    EVT_GOTO(0)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_LOOP(3)
                    EVT_SUB(LW(0), 10)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_END_LOOP
                EVT_WAIT(10)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
                EVT_CALL(PlayEffect, EFFECT_FIREWORK, 0, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(N(StartRumbleWithParams), 200, 10)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DC)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_13)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), 40)
                EVT_SET(LW(1), 0)
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                EVT_ADD(LW(0), 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                EVT_ADD(LW(0), 20)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
                EVT_WAIT(8)
                EVT_WAIT(10)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(80219668))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C004) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_12)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzipede_Palette_00_Anim_4)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x214)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(HealActor, ACTOR_SELF, 4, 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021C1A4) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(GetActorHP, ACTOR_SELF, LW(0))
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LW(1))
            EVT_MUL(LW(0), 100)
            EVT_DIV(LW(0), LW(1))
            EVT_IF_LE(LW(0), 35)
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 500)
                    EVT_EXEC_WAIT(N(8021C004))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(RandInt, 1000, LW(0))
    EVT_IF_LT(LW(0), 500)
        EVT_EXEC_WAIT(N(8021A6D8))
    EVT_ELSE
        EVT_CALL(N(SpyGuyActionFunc), LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_EXEC_WAIT(N(8021B22C))
        EVT_ELSE
            EVT_EXEC_WAIT(N(8021A6D8))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
