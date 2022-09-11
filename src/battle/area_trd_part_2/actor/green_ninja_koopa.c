#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/koopa_bros.h"

#define NAMESPACE b_area_trd_part_2_green_ninja_koopa

extern s32 N(idleAnimations_80225670)[];
extern EvtScript N(init_80227CEC);
extern EvtScript N(idle_80227DE0);
extern EvtScript N(handleEvent_80227E48);
extern EvtScript N(nextTurn_802284E4);
extern EvtScript N(takeTurn_802284D4);

s32 N(defenseTable_80225560)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(defenseTable_8022556C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80225578)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 45,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
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

ActorPartBlueprint N(partsTable_80225624)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 36 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80225670),
        .defenseTable = N(defenseTable_80225560),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_40000 | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_GREEN_NINJAKOOPA,
    .level = 16,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(partsTable_80225624)),
    .partsData = N(partsTable_80225624),
    .script = &N(init_80227CEC),
    .statusTable = N(statusTable_80225578),
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

s32 N(idleAnimations_80225670)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_03_Anim_4,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_03_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_koopa_bros_Palette_03_Anim_15,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_03_Anim_0,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_03_Anim_0,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_03_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_03_Anim_18,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_03_Anim_18,
    STATUS_END,
};

s32 N(idleAnimations_802256C4)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_03_Anim_5,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_END,
};

s32 N(idleAnimations_80225700)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_03_Anim_D,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_1,
    STATUS_END,
};

s32 N(idleAnimations_8022573C)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_03_Anim_C,
    STATUS_STONE,     NPC_ANIM_koopa_bros_Palette_03_Anim_17,
    STATUS_SLEEP,     NPC_ANIM_koopa_bros_Palette_03_Anim_17,
    STATUS_POISON,    NPC_ANIM_koopa_bros_Palette_03_Anim_17,
    STATUS_STOP,      NPC_ANIM_koopa_bros_Palette_03_Anim_17,
    STATUS_STATIC,    NPC_ANIM_koopa_bros_Palette_03_Anim_17,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_17,
    STATUS_PARALYZE,  NPC_ANIM_koopa_bros_Palette_03_Anim_17,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_03_Anim_22,
    STATUS_DIZZY,     NPC_ANIM_koopa_bros_Palette_03_Anim_22,
    STATUS_END,
};

s32 N(idleAnimations_80225790)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_03_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations_8022579C)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_03_Anim_C,
    STATUS_END,
};

#include "common/StartRumbleWithParams.inc.c"

#include "common/UnkWhirlwindEffectFunc.inc.c"

#include "common/UnkEnemyFunc.inc.c"

#include "common/UnkEnemyPosFunc.inc.c"

#include "common/GetLastActorEventType.inc.c"

EvtScript N(802257A8) = {
    EVT_CALL(SetOwnerID, ACTOR_ENEMY0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225670)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_802256C4)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_WAIT(5)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225700)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_D)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, 192)
                    EVT_IF_NE(LVar0, 192)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225700)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_D)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225790)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_A)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(3)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(N(GetLastActorEventType), 14)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_E)
                    EVT_SET_CONST(LVar2, -1)
                    EVT_EXEC_WAIT(DoBurnHit)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, 192)
                    EVT_IF_NE(LVar0, 192)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225700)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_D)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225790)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_A)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(4)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_8)
                    EVT_EXEC_WAIT(DoImmune)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_9)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_1F)
                    EVT_EXEC_WAIT(DoImmune)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_20)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_WAIT(15)
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET(LocalFlag(0), 0)
                    EVT_IF_EQ(LVar0, 3)
                        EVT_SET(LocalFlag(0), 1)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
                    EVT_CALL(N(UnkEnemyPosFunc), LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_A)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225790)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LocalFlag(0), 1)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.8))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_C)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8022579C)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_40000, 0)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8022573C)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_8022556C)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(6)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET(LocalFlag(0), 0)
                    EVT_IF_EQ(LVar0, 3)
                        EVT_SET(LocalFlag(0), 1)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
                    EVT_CALL(N(UnkEnemyPosFunc), LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_E)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225790)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LocalFlag(0), 1)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.8))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                    EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar1, LVar3)
                    EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                    EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                    EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_C)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8022579C)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_40000, 0)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8022573C)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_8022556C)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(9)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
                    EVT_SUB(LVar0, 1)
                    EVT_IF_GT(LVar0, 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
                        EVT_WAIT(20)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                    EVT_ELSE
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
                        EVT_WAIT(12)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                        EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
                        EVT_THREAD
                            EVT_SET(LVar0, 0)
                            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 18, 0)
                            EVT_LOOP(4)
                                EVT_ADD(LVar0, 22)
                                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                                EVT_WAIT(1)
                            EVT_END_LOOP
                        EVT_END_THREAD
                        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
                        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 36)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
                        EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_80225560)))
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80225670)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                        EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
                    EVT_END_IF
                EVT_CASE_DEFAULT
                    EVT_WAIT(20)
            EVT_END_SWITCH
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(7)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_8)
                    EVT_WAIT(10)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x356)
                        EVT_CASE_EQ(3)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x355)
                        EVT_CASE_EQ(2)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x354)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_7)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 60)
                    EVT_WAIT(60)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_10)
                        EVT_SWITCH(LVar0)
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVarA)
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        EVT_IF_GT(LVar0, LVar3)
                            EVT_WAIT(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar1)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x37C)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(13.0))
                        EVT_CASE_EQ(3)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                    EVT_END_SWITCH
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, -127, 1, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, -127, 1, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                    EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                    EVT_SET(LVar4, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVarB)
                    EVT_SET(LVar0, LVarB)
                    EVT_SUB(LVar0, 1)
                    EVT_MUL(LVar0, 18)
                    EVT_SWITCH(LVarB)
                        EVT_CASE_EQ(4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -10)
                        EVT_CASE_EQ(3)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -7)
                        EVT_CASE_EQ(2)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -4)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 60)
                            EVT_WAIT(60)
                        EVT_CASE_EQ(3)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 50)
                            EVT_WAIT(50)
                        EVT_CASE_EQ(2)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 40)
                            EVT_WAIT(40)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_9)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F3)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1B)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 22)
                    EVT_ADD(LVar1, 19)
                    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                    EVT_WAIT(20)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 1, 0)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1F)
                    EVT_WAIT(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_7)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 60)
                    EVT_WAIT(60)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(5)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                        EVT_CASE_EQ(6)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_END_SWITCH
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, -127, 1, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, -127, 1, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 36, -7)
                        EVT_CASE_EQ(5)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 18, -4)
                        EVT_CASE_EQ(6)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 50)
                            EVT_WAIT(50)
                        EVT_CASE_EQ(5)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 40)
                            EVT_WAIT(40)
                        EVT_CASE_EQ(6)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 30)
                            EVT_WAIT(30)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_20)
                    EVT_WAIT(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(8)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SET(LVar2, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_3)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1F)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x353)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_7)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 30)
                    EVT_WAIT(30)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_10)
                        EVT_SWITCH(LVar0)
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        EVT_IF_GT(LVar0, LVar3)
                            EVT_WAIT(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x37C)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, 0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, -127, 1, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, -127, 1, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SET(LVar2, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 30)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_9)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F3)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1B)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 22)
                    EVT_ADD(LVar1, 19)
                    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_3)
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, -513)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80227CEC) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_802284D4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80227DE0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80227E48)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_802284E4)))
    EVT_CALL(SetActorPos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80227DE0) = {
    EVT_RETURN
    EVT_END
};

s32 N(intTable_80227DF0)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

EvtScript N(handleEvent_80227E48) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_E)
            EVT_SET_CONST(LVar2, NPC_ANIM_koopa_bros_Palette_03_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_E)
            EVT_SET_CONST(LVar2, NPC_ANIM_koopa_bros_Palette_03_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_F)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8022573C)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_8022556C)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 18)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_THREAD
                    EVT_WAIT(4)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                    EVT_WAIT(1)
                EVT_END_THREAD
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_C)
            EVT_END_IF
            EVT_USE_BUF(EVT_PTR(N(intTable_80227DF0)))
            EVT_LOOP(22)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_8)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_9)
                    EVT_WAIT(10)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802284D4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_802284E4) = {
    EVT_RETURN
    EVT_END
};
