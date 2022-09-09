#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/tutankoopa.h"
#include "sprite/npc/chain_chomp.h"
#include "sprite/npc/buzzy_beetle.h"

#define NAMESPACE b_area_isk_part_2_tutankoopa

extern ActorBlueprint b_area_isk_part_2_chain_chomp;
extern EvtScript N(init_8021BC1C);
extern EvtScript N(takeTurn_8021CCD4);
extern EvtScript N(idle_8021BE28);
extern EvtScript N(handleEvent_8021BFD0);
extern EvtScript N(nextTurn_8021F9C4);
extern EvtScript N(8021C748);
extern EvtScript N(8021C974);
extern EvtScript N(8021D04C);
extern EvtScript N(8021D81C);
extern EvtScript N(8021DDE8);
extern EvtScript N(8021E008);
extern EvtScript N(8021E9C8);
extern EvtScript N(8021F42C);
extern EvtScript N(8021F5E8);
extern EvtScript N(8021F80C);
extern EvtScript N(8021FA54);

s32 N(idleAnimations_8021B960)[] = {
    STATUS_NORMAL,    NPC_ANIM_tutankoopa_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_tutankoopa_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_tutankoopa_Palette_00_Anim_C,
    STATUS_POISON,    NPC_ANIM_tutankoopa_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_tutankoopa_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_tutankoopa_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_tutankoopa_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_tutankoopa_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_tutankoopa_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations_8021B9AC)[] = {
    STATUS_NORMAL,    NPC_ANIM_tutankoopa_Palette_00_Anim_A,
    STATUS_STONE,     NPC_ANIM_tutankoopa_Palette_00_Anim_7,
    STATUS_SLEEP,     NPC_ANIM_tutankoopa_Palette_00_Anim_D,
    STATUS_POISON,    NPC_ANIM_tutankoopa_Palette_00_Anim_A,
    STATUS_STOP,      NPC_ANIM_tutankoopa_Palette_00_Anim_7,
    STATUS_STATIC,    NPC_ANIM_tutankoopa_Palette_00_Anim_A,
    STATUS_PARALYZE,  NPC_ANIM_tutankoopa_Palette_00_Anim_A,
    STATUS_PARALYZE,  NPC_ANIM_tutankoopa_Palette_00_Anim_A,
    STATUS_DIZZY,     NPC_ANIM_tutankoopa_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations_8021B9F8)[] = {
    STATUS_NORMAL,    NPC_ANIM_buzzy_beetle_Palette_00_Anim_6,
    STATUS_END,
};

s32 N(idleAnimations_8021BA04)[] = {
    STATUS_NORMAL,    NPC_ANIM_tutankoopa_Palette_00_Anim_16,
    STATUS_END,
};

s32 N(idleAnimations_8021BA10)[] = {
    STATUS_NORMAL,    NPC_ANIM_tutankoopa_Palette_00_Anim_16,
    STATUS_END,
};

s32 N(defenseTable_8021BA1C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021BA28)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 20,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 30,
    STATUS_SHRINK, 60,
    STATUS_STOP, 40,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
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

ActorPartBlueprint N(partsTable_8021BAD4)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B960),
        .defenseTable = N(defenseTable_8021BA1C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 39 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B960),
        .defenseTable = N(defenseTable_8021BA1C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFB,
        .unk_1D = 0xF1,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_40000000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B9F8),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_40000000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B9F8),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_40000000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B9F8),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021BA04),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021BA04),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021BA10),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUTANKOOPA,
    .level = 55,
    .maxHP = 30,
    .partCount = ARRAY_COUNT(N(partsTable_8021BAD4)),
    .partsData = N(partsTable_8021BAD4),
    .script = &N(init_8021BC1C),
    .statusTable = N(statusTable_8021BA28),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 56, 45 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 35 },
    .statusMessageOffset = { 10, 35 },
};

#include "common/UnkBattleFunc1.inc.c"

ApiStatus func_8021875C_4EFBFC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    EffectInstance* effect = fx_floating_rock(2, var1, 150.0f, var3, var2, -0.5f, -0.9f, 0.5f, 60);

    effect->data.floatingRock->unk_30.x = 0;
    effect->data.floatingRock->unk_30.z = 0;
    effect->data.floatingRock->unk_30.y = 0;
    return ApiStatus_DONE2;
}

EvtScript N(init_8021BC1C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021CCD4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021BE28)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021BFD0)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_8021F9C4)))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 97, 70, 15)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, 70, 70, 3)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, 80, 70, -7)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, 60, 70, -7)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 12, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021BE28) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_DIZZY)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -10, 22)
                EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 2, -8)
                EVT_CALL(N(UnkBattleFunc1), -25, 15, 0, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 0, 39)
                EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, -5, -15)
                EVT_CALL(N(UnkBattleFunc1), -17, 23, 11, 32)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -10, 22)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 2, -8)
            EVT_CALL(N(UnkBattleFunc1), -25, 15, 0, 20)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021BFD0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastElement, LocalVar(14))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, 13, LocalVar(2))
            EVT_IF_NE(LocalVar(2), 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 13, 0)
                EVT_EXEC_WAIT(N(8021C974))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LocalVar(0), 1)
            EVT_SET(LocalVar(1), 6815762)
            EVT_SET(LocalVar(2), 6815763)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LocalVar(0), 1)
            EVT_SET(LocalVar(1), 6815762)
            EVT_SET(LocalVar(2), 6815763)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_13)
            EVT_EXEC_WAIT(N(8021FA54))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(8021C748))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LocalVar(1))
            EVT_IF_EQ(LocalVar(1), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LocalVar(1))
                EVT_IF_NE(LocalVar(1), 0)
                    EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_A)
                EVT_ELSE
                    EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_1)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_1)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LocalVar(1))
            EVT_IF_EQ(LocalVar(1), 0)
                EVT_IF_FLAG(LocalVar(14), DAMAGE_TYPE_JUMP)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 11, LocalVar(0))
                    EVT_IF_EQ(LocalVar(0), 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 11, 1)
                        EVT_WAIT(60)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(8021FA54))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(8021C748))
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(8021FA54))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_6)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_tutankoopa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C748) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_6)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 150, LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_SUB(LocalVar(1), 20)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_7)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_8)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C974) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E3)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_6)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.9))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 10)
    EVT_SET(LocalVar(1), 0)
    EVT_ADD(LocalVar(2), 24)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(0.7), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(StartRumble, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_7)
    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 40)
    EVT_CALL(PlayEffect, EFFECT_STARS_ORBITING, 0, LocalVar(0), LocalVar(1), LocalVar(2), 20, 4, LocalVar(15), 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_A)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LocalVar(15))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021B9AC)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021CCD4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(ActorExists, ACTOR_ENEMY1, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), FALSE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 12, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_EXEC_WAIT(N(8021E9C8))
                EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                EVT_RETURN
            EVT_ELSE
                EVT_SUB(LocalVar(0), 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 12, LocalVar(0))
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
        EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_SHRINK)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LocalVar(0))
        EVT_SWITCH(LocalVar(0))
            EVT_CASE_EQ(0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 2, LocalVar(0))
                EVT_IF_EQ(LocalVar(0), 0)
                    EVT_EXEC_WAIT(N(8021D81C))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_ELSE
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
                    EVT_IF_NOT_FLAG(LocalVar(0), STATUS_FLAG_SHRINK)
                        EVT_EXEC_WAIT(N(8021D04C))
                        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                    EVT_ELSE
                        EVT_EXEC_WAIT(N(8021D81C))
                        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                    EVT_END_IF
                EVT_END_IF
            EVT_CASE_DEFAULT
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                EVT_EXEC_WAIT(N(8021D81C))
        EVT_END_SWITCH
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_EXEC_WAIT(N(8021F80C))
        EVT_EXEC_WAIT(N(8021F5E8))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D04C) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(1)
            EVT_SET(LocalVar(9), 5)
        EVT_CASE_EQ(2)
            EVT_SET(LocalVar(9), 4)
        EVT_CASE_EQ(3)
            EVT_SET(LocalVar(9), 3)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SUB(LocalVar(0), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, LocalVar(0))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActorPart, ACTOR_SELF, LocalVar(9))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_2)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 20)
    EVT_SUB(LocalVar(2), 3)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_4)
    EVT_WAIT(7)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 20)
    EVT_ADD(LocalVar(1), 40)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(9), EVT_FLOAT(0.8))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2), 5, 1)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(9), 0x330005)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2F9)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(10), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LocalVar(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LocalVar(9), EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(9), EVT_FLOAT(0.2))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 50)
            EVT_SET(LocalVar(1), -5)
            EVT_CALL(FlyPartTo, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2), 0, 30, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(0), 65)
            EVT_SET(LocalVar(1), -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LocalVar(9), EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(9), EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2), 0, 15, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(9), ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_IF_EQ(LocalVar(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_5)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LocalVar(9), EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(9), EVT_FLOAT(0.2))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(9), EVT_FLOAT(0.2))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2), 0, 30, 0)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(8), DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 55)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LocalVar(9), EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(9), EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2), 0, 25, 0)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LocalVar(9), EVT_FLOAT(4.0))
    EVT_SUB(LocalVar(0), 20)
    EVT_CALL(FlyPartTo, ACTOR_SELF, LocalVar(9), LocalVar(0), LocalVar(1), LocalVar(2), 0, 21, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(9), ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_WAIT(19)
    EVT_IF_EQ(LocalVar(8), HIT_RESULT_10)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D81C) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0D, 0x00E5), ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_3, NPC_ANIM_tutankoopa_Palette_00_Anim_3)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_CALL(PlayEffect, EFFECT_HIEROGLYPHS, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(1.0), 45, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 70)
    EVT_CALL(PlaySound, 0x20E7)
    EVT_CALL(PlayEffect, EFFECT_CHOMP_DROP, 0, 0, 60, 0, EVT_FLOAT(0.2), 0, EVT_FLOAT(1.4), 255, EVT_FLOAT(0.1), 150, 0, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP | STATUS_FLAG_TRANSPARENT)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1002B)
        EVT_WAIT(49)
        EVT_CALL(PlaySound, 0x20E9)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_5)
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_CROUCH)
        EVT_WAIT(5)
        EVT_CALL(StartRumble, 10)
        EVT_CALL(PlaySound, 0x20EA)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(4.0))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_QUESTION)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 20)
        EVT_CALL(PlayEffect, EFFECT_EMOTE, 2, 0, LocalVar(0), LocalVar(1), LocalVar(2), 20, 315, 30, 0, 0, 0, 0, 0)
        EVT_CALL(PlaySound, 0x20E8)
    EVT_ELSE
        EVT_WAIT(50)
        EVT_CALL(PlaySound, 0x20E9)
        EVT_WAIT(18)
        EVT_CALL(StartRumble, 10)
        EVT_CALL(PlaySound, 0x20EA)
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x20E8)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 1)
            EVT_EXEC_WAIT(N(8021E008))
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorHP, ACTOR_SELF, LocalVar(0))
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 2)
            EVT_IF_GT(LocalVar(0), 2)
                EVT_EXEC_WAIT(N(8021DDE8))
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021E008))
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(RandInt, 2, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_CALL(GetActorHP, ACTOR_SELF, LocalVar(0))
                EVT_IF_GT(LocalVar(0), 2)
                    EVT_EXEC_WAIT(N(8021DDE8))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(8021E008))
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021E008))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021DDE8) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_ENEMY0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(3), 170)
    EVT_CALL(SetPartPos, ACTOR_SELF, 8, LocalVar(0), LocalVar(3), LocalVar(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 8, NPC_ANIM_tutankoopa_Palette_00_Anim_16)
    EVT_CALL(PlaySound, 0x20EB)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 8, EVT_FLOAT(8.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 8, EVT_FLOAT(0.3))
    EVT_CALL(FallPartTo, ACTOR_SELF, 8, LocalVar(0), LocalVar(1), LocalVar(2), 20)
    EVT_THREAD
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THUMBS_UP)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E008) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(10), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LocalVar(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_LOOP(6)
                    EVT_CALL(RandInt, 120, LocalVar(0))
                    EVT_SUB(LocalVar(0), 150)
                    EVT_CALL(RandInt, 90, LocalVar(1))
                    EVT_SUB(LocalVar(0), 40)
                    EVT_CALL(PlaySound, 0x20EB)
                    EVT_CALL(func_8021875C_4EFBFC, LocalVar(0), 0, LocalVar(1))
                    EVT_CALL(RandInt, 5, LocalVar(0))
                    EVT_ADD(LocalVar(0), 5)
                    EVT_WAIT(LocalVar(0))
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(11), 0, 0, 1, BS_FLAGS1_10)
            EVT_SWITCH(LocalVar(11))
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(func_8026BF48, 1)
                    EVT_THREAD
                        EVT_CALL(PlaySound, 0x20EB)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                        EVT_SUB(LocalVar(0), 5)
                        EVT_SET(LocalVar(1), 0)
                        EVT_SET(LocalVar(3), 170)
                        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LocalVar(0), LocalVar(3), LocalVar(2))
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
                        EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_tutankoopa_Palette_00_Anim_16)
                        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(8.0))
                        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.3))
                        EVT_CALL(FallPartTo, ACTOR_SELF, 6, LocalVar(0), LocalVar(1), LocalVar(2), 20)
                        EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_tutankoopa_Palette_00_Anim_17)
                        EVT_IF_EQ(LocalVar(10), HIT_RESULT_LUCKY)
                            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                        EVT_END_IF
                    EVT_END_THREAD
                    EVT_WAIT(25)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
                    EVT_SUB(LocalVar(4), 5)
                    EVT_ADD(LocalVar(5), 5)
                    EVT_SET(LocalVar(7), 170)
                    EVT_CALL(SetPartPos, ACTOR_SELF, 7, LocalVar(4), LocalVar(7), LocalVar(6))
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 7, NPC_ANIM_tutankoopa_Palette_00_Anim_16)
                    EVT_CALL(PlaySound, 0x20EB)
                    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 7, EVT_FLOAT(8.0))
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 7, EVT_FLOAT(0.3))
                    EVT_CALL(FallPartTo, ACTOR_SELF, 7, LocalVar(4), LocalVar(5), LocalVar(6), 20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_tutankoopa_Palette_00_Anim_17)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_WAIT(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, 1)
                    EVT_CALL(func_8026BF48, 0)
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(RandInt, 120, LocalVar(0))
            EVT_SUB(LocalVar(0), 150)
            EVT_CALL(RandInt, 90, LocalVar(1))
            EVT_SUB(LocalVar(0), 40)
            EVT_CALL(PlaySound, 0x20EB)
            EVT_CALL(func_8021875C_4EFBFC, LocalVar(0), 0, LocalVar(1))
            EVT_CALL(RandInt, 5, LocalVar(0))
            EVT_ADD(LocalVar(0), 5)
            EVT_WAIT(LocalVar(0))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_8026BF48, 1)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(4), LocalVar(5), LocalVar(6))
        EVT_SUB(LocalVar(4), 5)
        EVT_ADD(LocalVar(5), 5)
        EVT_SET(LocalVar(7), 170)
        EVT_CALL(SetPartPos, ACTOR_SELF, 7, LocalVar(4), LocalVar(7), LocalVar(6))
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 7, NPC_ANIM_tutankoopa_Palette_00_Anim_16)
        EVT_CALL(PlaySound, 0x20EB)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 7, EVT_FLOAT(8.0))
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 7, EVT_FLOAT(0.3))
        EVT_CALL(FallPartTo, ACTOR_SELF, 7, LocalVar(4), LocalVar(5), LocalVar(6), 20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_tutankoopa_Palette_00_Anim_17)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_WAIT(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySound, 0x20EB)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 5)
    EVT_ADD(LocalVar(1), 5)
    EVT_SET(LocalVar(3), 170)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LocalVar(0), LocalVar(3), LocalVar(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_tutankoopa_Palette_00_Anim_16)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(8.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.3))
    EVT_CALL(FallPartTo, ACTOR_SELF, 6, LocalVar(0), LocalVar(1), LocalVar(2), 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_tutankoopa_Palette_00_Anim_17)
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(19)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_IF_EQ(LocalVar(0), HIT_RESULT_10)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021E9A0) = { 190, 0, 0 };

Formation N(specialFormation_8021E9AC) = {
    { .actor = &b_area_isk_part_2_chain_chomp, .home = { .vec = &N(vector3D_8021E9A0) }, .priority = 100 },
};

EvtScript N(8021E9C8) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_3)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0D, 0x00E6), ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_3, NPC_ANIM_tutankoopa_Palette_00_Anim_3)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_3)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0D, 0x00E7), ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_3, NPC_ANIM_tutankoopa_Palette_00_Anim_3)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(SetBattleCamZoom, 225)
        EVT_CALL(SetBattleCamOffsetZ, -30)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 35)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_THREAD
        EVT_LABEL(0)
        EVT_CALL(StartRumble, 1)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LocalVar(0))
        EVT_IF_LT(LocalVar(0), 60)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySound, 0x26B)
    EVT_LABEL(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LocalVar(13))
    EVT_CALL(TranslateModel, 31, 0, LocalVar(13), 0)
    EVT_ADD(LocalVar(13), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, LocalVar(13))
    EVT_WAIT(1)
    EVT_IF_LT(LocalVar(13), 60)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(StopSound, 619)
    EVT_WAIT(10)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021E9AC)), 0)
    EVT_SET(LocalVar(11), LocalVar(0))
    EVT_SET(LocalVar(0), 165)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), -30)
    EVT_CALL(SetActorPos, LocalVar(11), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetActorDispOffset, LocalVar(11), 0, 0, 0)
    EVT_CALL(UseIdleAnimation, LocalVar(11), FALSE)
    EVT_CALL(EnableIdleScript, LocalVar(11), 0)
    EVT_CALL(SetAnimation, LocalVar(11), 1, NPC_ANIM_chain_chomp_Palette_00_Anim_5)
    EVT_CALL(SetActorSpeed, LocalVar(11), EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LocalVar(11), EVT_FLOAT(0.8))
    EVT_SET(LocalVar(0), 90)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), -30)
    EVT_SET(LocalVar(3), 8)
    EVT_SET(LocalVar(4), 30)
    EVT_EXEC_WAIT(N(8021F42C))
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LocalVar(5))
    EVT_IF_EQ(LocalVar(5), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamZoom, 160)
        EVT_CALL(GetActorPos, LocalVar(11), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_SET(LocalVar(1), 60)
        EVT_CALL(SetBattleCamTarget, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(MoveBattleCamOver, 8)
        EVT_LOOP(3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamZoom, 150)
            EVT_CALL(SetBattleCamTarget, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_WAIT(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2061)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamZoom, 200)
            EVT_CALL(SetBattleCamTarget, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_ELSE
        EVT_WAIT(8)
        EVT_CALL(SetGoalPos, LocalVar(11), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(JumpToGoal, LocalVar(11), 8, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(SetGoalPos, LocalVar(11), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(JumpToGoal, LocalVar(11), 8, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_WAIT(8)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetActorSpeed, LocalVar(11), EVT_FLOAT(3.0))
    EVT_CALL(SetActorJumpGravity, LocalVar(11), EVT_FLOAT(0.8))
    EVT_SET(LocalVar(0), 20)
    EVT_SET(LocalVar(1), 0)
    EVT_SET(LocalVar(2), 20)
    EVT_SET(LocalVar(3), 8)
    EVT_SET(LocalVar(4), 20)
    EVT_EXEC_WAIT(N(8021F42C))
    EVT_CALL(GetActorPos, LocalVar(11), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ForceHomePos, LocalVar(11), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPartPos, LocalVar(11), 2, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(HPBarToHome, LocalVar(11))
    EVT_CALL(SetActorSpeed, LocalVar(11), EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LocalVar(11), EVT_FLOAT(0.8))
    EVT_CALL(EnableIdleScript, LocalVar(11), 1)
    EVT_CALL(UseIdleAnimation, LocalVar(11), TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 60)
    EVT_THREAD
        EVT_LABEL(40)
        EVT_CALL(StartRumble, 1)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 0)
            EVT_GOTO(40)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySound, 0x26B)
    EVT_LABEL(50)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LocalVar(13))
    EVT_CALL(TranslateModel, 31, 0, LocalVar(13), 0)
    EVT_SUB(LocalVar(13), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, LocalVar(13))
    EVT_WAIT(1)
    EVT_IF_GT(LocalVar(13), 0)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_CALL(StopSound, 619)
    EVT_CALL(PlaySound, 0x26C)
    EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(0.5))
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F42C) = {
    EVT_LABEL(20)
    EVT_CALL(GetActorPos, LocalVar(11), LocalVar(5), LocalVar(6), LocalVar(7))
    EVT_IF_EQ(LocalVar(5), LocalVar(0))
        EVT_GOTO(30)
    EVT_END_IF
    EVT_SET(LocalVar(6), LocalVar(5))
    EVT_SUB(LocalVar(6), LocalVar(0))
    EVT_IF_LT(LocalVar(6), LocalVar(4))
        EVT_CALL(SetGoalPos, LocalVar(11), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(JumpToGoal, LocalVar(11), LocalVar(3), FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
    EVT_ELSE
        EVT_SUB(LocalVar(5), LocalVar(4))
        EVT_CALL(SetGoalPos, LocalVar(11), LocalVar(5), LocalVar(1), LocalVar(2))
        EVT_CALL(JumpToGoal, LocalVar(11), LocalVar(3), FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
    EVT_END_IF
    EVT_GOTO(20)
    EVT_LABEL(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F5E8) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_8)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_CALL(PlayEffect, EFFECT_HIEROGLYPHS, 0, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(1.0), 45, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(45)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E6)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 97, 70, 15)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 45, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F80C) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_8)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021B960)))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0D, 0x00E4), ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_B, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 4, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021F9C4) = {
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, 10, LocalVar(0))
            EVT_SWITCH(LocalVar(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 1)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021FA54) = {
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LocalVar(2))
    EVT_IF_NE(LocalVar(2), FALSE)
        EVT_CALL(GetActorHP, ACTOR_ENEMY1, LocalVar(2))
        EVT_IF_NE(LocalVar(2), 0)
            EVT_THREAD
                EVT_CALL(func_8027D32C, ACTOR_ENEMY1)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
                EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_6)
                EVT_WAIT(10)
                EVT_SET(LocalVar(2), 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_ENEMY1, LocalVar(2))
                    EVT_ADD(LocalVar(2), 30)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_ENEMY1, 0)
                EVT_CALL(GetActorPos, ACTOR_ENEMY1, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_ADD(LocalVar(1), 10)
                EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, SOUND_DEATH)
                EVT_SET(LocalVar(3), 0)
                EVT_LOOP(12)
                    EVT_CALL(SetActorRotation, ACTOR_ENEMY1, LocalVar(3), 0, 0)
                    EVT_ADD(LocalVar(3), 8)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(RemoveActor, ACTOR_ENEMY1)
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(D_8029AF08)
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LocalVar(0))
    EVT_IF_NE(LocalVar(0), FALSE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
