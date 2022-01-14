#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/koopa_bros.h"

#define NAMESPACE b_area_trd_part_2_blue_ninja_koopa

extern s32 N(idleAnimations_8022B5B0)[];
extern EvtSource N(init_8022DC2C);
extern EvtSource N(idle_8022DD20);
extern EvtSource N(handleEvent_8022DD88);
extern EvtSource N(nextTurn_8022E424);
extern EvtSource N(takeTurn_8022E414);

s32 N(defenseTable_8022B4A0)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(defenseTable_8022B4AC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8022B4B8)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 40,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 60,
    STATUS_SHRINK, 100,
    STATUS_STOP, 75,
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

ActorPartBlueprint N(partsTable_8022B564)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 36 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022B5B0),
        .defenseTable = N(defenseTable_8022B4A0),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_40000 | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_BLUE_NINJAKOOPA,
    .level = 17,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(partsTable_8022B564)),
    .partsData = N(partsTable_8022B564),
    .script = N(init_8022DC2C),
    .statusTable = N(statusTable_8022B4B8),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 0,
    .size = { 38, 42 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8022B5B0)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_00_Anim_4,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_koopa_bros_Palette_00_Anim_15,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_00_Anim_18,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_00_Anim_18,
    STATUS_END,
};

s32 N(idleAnimations_8022B604)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_00_Anim_5,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(idleAnimations_8022B640)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_00_Anim_D,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(idleAnimations_8022B67C)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_00_Anim_C,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_00_Anim_17,
    STATUS_SLEEP,     NPC_ANIM_koopa_bros_Palette_00_Anim_17,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_00_Anim_17,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_00_Anim_17,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_00_Anim_17,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_17,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_00_Anim_17,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_00_Anim_22,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_00_Anim_22,
    STATUS_END,
};

s32 N(idleAnimations_8022B6D0)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations_8022B6DC)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_00_Anim_C,
    STATUS_END,
};

#include "common/StartRumbleWithParams.inc.c"

// TODO: This pad is here due to rodata having subalign 4, while bss is 0x10 aligned as normal.
BSS static char pad;
#include "common/UnkWhirlwindEffectFunc.inc.c"

#include "common/UnkEnemyFunc.inc.c"

ApiStatus func_80219530_4B2720(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_trd_part_2/4B2550", func_80219530_4B2720);

#include "common/GetLastActorEventType.inc.c"

EvtSource N(8022B6E8) = {
    EVT_CALL(SetOwnerID, ACTOR_ENEMY2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(3)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B5B0)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B604)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_WAIT_FRAMES(5)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B640)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_D)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_B)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LW(0))
                    EVT_BITWISE_AND_CONST(LW(0), 192)
                    EVT_IF_NE(LW(0), 192)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B640)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_D)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B6D0)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_A)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(3)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(N(GetLastActorEventType), 14)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_E)
                    EVT_SET_CONST(LW(2), -1)
                    EVT_EXEC_WAIT(DoBurnHit)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LW(0))
                    EVT_BITWISE_AND_CONST(LW(0), 192)
                    EVT_IF_NE(LW(0), 192)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B640)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_D)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B6D0)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_A)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(4)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(3)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_8)
                    EVT_EXEC_WAIT(DoImmune)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_9)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_1F)
                    EVT_EXEC_WAIT(DoImmune)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_20)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_WAIT_FRAMES(15)
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET(LF(0), 0)
                    EVT_IF_EQ(LW(0), 3)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
                    EVT_CALL(func_80219530_4B2720, LW(0), LW(1), LW(2))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_A)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B6D0)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LF(0), 1)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.80078125))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_C)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B6DC)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_40000, 0)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B67C)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_8022B4AC)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(6)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET(LF(0), 0)
                    EVT_IF_EQ(LW(0), 3)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
                    EVT_CALL(func_80219530_4B2720, LW(0), LW(1), LW(2))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_E)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B6D0)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LF(0), 1)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.80078125))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(GetActorSize, ACTOR_SELF, LW(3), LW(4))
                    EVT_DIVF(LW(3), EVT_FLOAT(2.0))
                    EVT_ADDF(LW(1), LW(3))
                    EVT_ADDF(LW(2), EVT_FLOAT(5.0))
                    EVT_DIVF(LW(3), EVT_FLOAT(10.0))
                    EVT_CALL(PlayEffect, EFFECT_ID_27, 0, LW(0), LW(1), LW(2), LW(3), 10, 0, 0, 0, 0, 0, 0, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_C)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B6DC)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_40000, 0)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B67C)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_8022B4AC)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(9)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
                    EVT_SUB(LW(0), 1)
                    EVT_IF_GT(LW(0), 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 2, LW(0))
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
                        EVT_WAIT_FRAMES(20)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                    EVT_ELSE
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
                        EVT_WAIT_FRAMES(12)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                        EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
                        EVT_THREAD
                            EVT_SET(LW(0), 0)
                            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 18, 0)
                            EVT_LOOP(4)
                                EVT_ADD(LW(0), 22)
                                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                                EVT_WAIT_FRAMES(1)
                            EVT_END_LOOP
                        EVT_END_THREAD
                        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
                        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 36)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
                        EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_8022B4A0)))
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B5B0)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                        EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
                    EVT_END_IF
                EVT_CASE_DEFAULT
                    EVT_WAIT_FRAMES(20)
            EVT_END_SWITCH
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(7)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(3)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_8)
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_EQ(4)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x356)
                        EVT_CASE_EQ(3)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x355)
                        EVT_CASE_EQ(2)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x354)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_7)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 60)
                    EVT_WAIT_FRAMES(60)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_10)
                        EVT_SWITCH(LW(0))
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT_FRAMES(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LW(10))
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(3), LW(4), LW(5))
                        EVT_IF_GT(LW(0), LW(3))
                            EVT_WAIT_FRAMES(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LW(1))
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, LW(1), BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x37C)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_EQ(4)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(13.0))
                        EVT_CASE_EQ(3)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                    EVT_END_SWITCH
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LW(1), LW(2))
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 1, 0, 15, 0)
                        EVT_SET(LW(0), 0)
                        EVT_LOOP(40)
                            EVT_SUB(LW(0), 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, LW(0))
                            EVT_WAIT_FRAMES(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 1, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LW(1))
                    EVT_CALL(GetHomePos, LW(1), LW(2), LW(3), LW(4))
                    EVT_SET(LW(4), 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(2), LW(3), LW(4))
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LW(11))
                    EVT_SET(LW(0), LW(11))
                    EVT_SUB(LW(0), 1)
                    EVT_MUL(LW(0), 18)
                    EVT_SWITCH(LW(11))
                        EVT_CASE_EQ(4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LW(0), -10)
                        EVT_CASE_EQ(3)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LW(0), -7)
                        EVT_CASE_EQ(2)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LW(0), -4)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 60)
                            EVT_WAIT_FRAMES(60)
                        EVT_CASE_EQ(3)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 50)
                            EVT_WAIT_FRAMES(50)
                        EVT_CASE_EQ(2)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 40)
                            EVT_WAIT_FRAMES(40)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_9)
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F3)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1B)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_SUB(LW(0), 22)
                    EVT_ADD(LW(1), 19)
                    EVT_CALL(PlayEffect, EFFECT_ID_1A, 0, LW(0), LW(1), LW(2), 30, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                    EVT_WAIT_FRAMES(20)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 1, 0)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1F)
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_7)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 60)
                    EVT_WAIT_FRAMES(60)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_EQ(4)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(5)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                        EVT_CASE_EQ(6)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_END_SWITCH
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LW(1), LW(2))
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 1, 0, 15, 0)
                        EVT_SET(LW(0), 0)
                        EVT_LOOP(40)
                            EVT_SUB(LW(0), 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, LW(0))
                            EVT_WAIT_FRAMES(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 1, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LW(1))
                            EVT_CALL(GetHomePos, LW(1), LW(2), LW(3), LW(4))
                            EVT_SET(LW(4), 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(2), LW(3), LW(4))
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 36, -7)
                        EVT_CASE_EQ(5)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LW(1))
                            EVT_CALL(GetHomePos, LW(1), LW(2), LW(3), LW(4))
                            EVT_SET(LW(4), 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(2), LW(3), LW(4))
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 18, -4)
                        EVT_CASE_EQ(6)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LW(1))
                            EVT_CALL(GetHomePos, LW(1), LW(2), LW(3), LW(4))
                            EVT_SET(LW(4), 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(2), LW(3), LW(4))
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 50)
                            EVT_WAIT_FRAMES(50)
                        EVT_CASE_EQ(5)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 40)
                            EVT_WAIT_FRAMES(40)
                        EVT_CASE_EQ(6)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 30)
                            EVT_WAIT_FRAMES(30)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_20)
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                    EVT_WAIT_FRAMES(30)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(8)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(GetHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_SET(LW(2), 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_3)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1F)
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x353)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_7)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 30)
                    EVT_WAIT_FRAMES(30)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_10)
                        EVT_SWITCH(LW(0))
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT_FRAMES(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(3), LW(4), LW(5))
                        EVT_IF_GT(LW(0), LW(3))
                            EVT_WAIT_FRAMES(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x37C)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LW(1), LW(2))
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 1, 0, 15, 0)
                        EVT_SET(LW(0), 0)
                        EVT_LOOP(40)
                            EVT_SUB(LW(0), 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, LW(0))
                            EVT_WAIT_FRAMES(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 1, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_SET(LW(2), 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LW(0), LW(1), LW(2), 30)
                    EVT_WAIT_FRAMES(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_9)
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F3)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1B)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_SUB(LW(0), 22)
                    EVT_ADD(LW(1), 19)
                    EVT_CALL(PlayEffect, EFFECT_ID_1A, 0, LW(0), LW(1), LW(2), 30, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_3)
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LW(0))
                    EVT_BITWISE_AND_CONST(LW(0), -513)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LW(0))
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8022DC2C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022E414)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8022DD20)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022DD88)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_8022E424)))
    EVT_CALL(SetActorPos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8022DD20) = {
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8022DD30)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

EvtSource N(handleEvent_8022DD88) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_koopa_bros_Palette_00_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_koopa_bros_Palette_00_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_F)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B67C)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_8022B4AC)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 18)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_B)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_THREAD
                    EVT_WAIT_FRAMES(4)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                    EVT_WAIT_FRAMES(1)
                EVT_END_THREAD
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_C)
            EVT_END_IF
            EVT_USE_BUF(EVT_ADDR(N(intTable_8022DD30)))
            EVT_LOOP(22)
                EVT_BUF_READ1(LW(0))
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(0), 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_8)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_9)
                    EVT_WAIT_FRAMES(10)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8022E414) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(nextTurn_8022E424) = {
    EVT_RETURN
    EVT_END
};
