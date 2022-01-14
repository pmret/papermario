#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/pokey.h"

#define NAMESPACE b_area_isk_part_1_pokey_mummy

extern s32 N(idleAnimations_80218DC8)[];
extern s32 N(idleAnimations_80218EB8)[];
extern EvtSource N(init_80218EC4);
extern EvtSource N(takeTurn_80219D88);
extern EvtSource N(idle_80219040);
extern EvtSource N(handleEvent_80219050);
extern EvtSource N(8021B998);
extern EvtSource N(8021A6C8);
extern EvtSource N(8021B088);
extern EvtSource N(8021B1B4);
extern EvtSource N(8021BDE4);
extern EvtSource N(8021C2BC);

s32 N(defenseTable_80218C10)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80218C1C)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 90,
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
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80218CC8)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218DC8),
        .defenseTable = N(defenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 72 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1C = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1C = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 36 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1C = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1C = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218EB8),
        .defenseTable = N(defenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_POKEY_MUMMY,
    .level = 10,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_80218CC8)),
    .partsData = N(partsTable_80218CC8),
    .script = N(init_80218EC4),
    .statusTable = N(statusTable_80218C1C),
    .escapeChance = 60,
    .airLiftChance = 90,
    .spookChance = 85,
    .baseStatusChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 24, 80 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusMessageOffset = { 10, 65 },
};

s32 N(idleAnimations_80218DC8)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_01_Anim_4,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_01_Anim_25,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_01_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_01_Anim_21,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_01_Anim_21,
    STATUS_END,
};

s32 N(idleAnimations_80218E04)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_01_Anim_5,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_01_Anim_1,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_01_Anim_26,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_01_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_01_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_01_Anim_22,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_01_Anim_22,
    STATUS_END,
};

s32 N(idleAnimations_80218E40)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_01_Anim_6,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_01_Anim_2,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_01_Anim_27,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_01_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_01_Anim_2,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_01_Anim_23,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_01_Anim_23,
    STATUS_END,
};

s32 N(idleAnimations_80218E7C)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_01_Anim_7,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_01_Anim_3,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_01_Anim_28,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_01_Anim_3,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_01_Anim_3,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_01_Anim_24,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_01_Anim_24,
    STATUS_END,
};

s32 N(idleAnimations_80218EB8)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_01_Anim_16,
    STATUS_END,
};

#include "common/UnkBattleFunc1.inc.c"

EvtSource N(init_80218EC4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80219D88)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80219040)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80219050)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, LW(0))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211524)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211528)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211532)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211536)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211537)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211544)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211545)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80219040) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_80219050) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
                EVT_IF_EQ(LW(10), 3)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                    EVT_EXEC_WAIT(DoNormalHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(8021BDE4))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LW(0), 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                            EVT_EXEC_WAIT(DoNormalHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
                EVT_IF_EQ(LW(10), 3)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_WAIT_FRAMES(10)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(8021BDE4))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LW(0), 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                            EVT_EXEC_WAIT(DoNormalHit)
                            EVT_WAIT_FRAMES(10)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LW(1))
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(2))
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
                EVT_IF_EQ(LW(10), 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(10))
                    EVT_SWITCH(LW(10))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(8021BDE4))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LW(1))
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(2))
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
                EVT_IF_EQ(LW(10), 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(10))
                    EVT_SWITCH(LW(10))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(8021BDE4))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(1))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(8021B088))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(8021B088))
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021BDE4))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021BDE4))
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), -1)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(1))
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_NOT_FLAG(LW(0), BS_FLAGS1_80000)
                EVT_CALL(AfflictActor, 0, 9, 3)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 77)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_01_Anim_21)
                EVT_CASE_EQ(1)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 59)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_01_Anim_22)
                EVT_CASE_EQ(2)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 41)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_01_Anim_23)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 23)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_01_Anim_24)
            EVT_END_SWITCH
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SLEEP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(2))
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(6))
            EVT_IF_FLAG(LW(6), STATUS_FLAG_SHRINK)
                EVT_MULF(LW(0), EVT_FLOAT(0.400390625))
                EVT_MULF(LW(1), EVT_FLOAT(0.400390625))
            EVT_END_IF
            EVT_ADDF(LW(3), LW(0))
            EVT_ADDF(LW(4), LW(1))
            EVT_CALL(PlayEffect, EFFECT_ID_1A, 0, LW(3), LW(4), LW(5), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(30)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(1))
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(8021C2BC))
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_80219D88) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_IF_EQ(LW(10), 3)
        EVT_EXEC_WAIT(N(8021A6C8))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(SetPartSounds, ACTOR_SELF, 6, 2, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.400390625), EVT_FLOAT(0.400390625), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(2.2001953125))
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_pokey_Palette_01_Anim_16)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
        EVT_SWITCH(LW(10))
            EVT_CASE_EQ(0)
                EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_ADD(LW(1), 38)
                EVT_ELSE
                    EVT_ADD(LW(1), 15)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2001953125))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 15, 1)
            EVT_CASE_EQ(1)
                EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_ADD(LW(1), 20)
                EVT_ELSE
                    EVT_ADD(LW(1), 8)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2001953125))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 15, 1)
            EVT_CASE_EQ(2)
                EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_ADD(LW(1), 8)
                EVT_ELSE
                    EVT_ADD(LW(1), 3)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2001953125))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 15, 1)
            EVT_CASE_EQ(3)
        EVT_END_SWITCH
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x342)
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_WAIT_FRAMES(12)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2CE)
    EVT_WAIT_FRAMES(3)
    EVT_EXEC_WAIT(N(8021B1B4))
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LW(0), HIT_RESULT_LUCKY)
                EVT_CHILD_THREAD
                    EVT_WAIT_FRAMES(5)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_CHILD_THREAD
            EVT_END_IF
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 80)
            EVT_SUB(LW(1), 5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(20.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1005859375))
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_pokey_Palette_01_Anim_16)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(20.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1005859375))
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_pokey_Palette_01_Anim_16)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 1)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0x00000008 | 0x00000020 | STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 55)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1005859375))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 25, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(4.0))
            EVT_SUB(LW(0), 24)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 21, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(3.0))
            EVT_SUB(LW(0), 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 20, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021A6C8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 748, 748)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 748, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_B)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_7)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_B)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 5)
            EVT_SET(LW(1), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1005859375))
            EVT_CHILD_THREAD
                EVT_WAIT_FRAMES(2)
                EVT_SET(LW(0), 0)
                EVT_LOOP(5)
                    EVT_ADD(LW(0), 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 22, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
            EVT_CHILD_THREAD
                EVT_WAIT_FRAMES(2)
                EVT_SET(LW(0), 180)
                EVT_LOOP(6)
                    EVT_ADD(LW(0), 30)
                    EVT_IF_EQ(LW(0), 360)
                        EVT_SET(LW(0), 0)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_CHILD_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_7)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1005859375))
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(2)
        EVT_SET(LW(0), 0)
        EVT_LOOP(5)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0x00000004 | 0x00000020 | 0x00000040 | STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_7)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_7)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_01_Anim_7)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021B088) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_SET_CONST(LW(0), 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
        EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(8021B998))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(8021B998))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(8021B998))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoSpinSmashHit)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(8021B1B4) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211525)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211529)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211533)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211538)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211539)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211546)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211547)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218E04)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, -250000000)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 62, -250000000)
            EVT_CALL(N(UnkBattleFunc1), -15, 55, 10, 45)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211526)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211530)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211534)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211540)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211541)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211548)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211549)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218E40)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, -250000000)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 44, -250000000)
            EVT_CALL(N(UnkBattleFunc1), -15, 35, 10, 25)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211527)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211531)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211535)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211550)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211551)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218E7C)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, -250000000)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 26, -250000000)
            EVT_CALL(N(UnkBattleFunc1), -15, 15, 10, 5)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(8021B6AC) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 18)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(3), LW(1))
    EVT_WAIT_FRAMES(2)
    EVT_SUB(LW(3), 1)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(3)
    EVT_SUB(LW(3), 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(2)
    EVT_SUB(LW(3), 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_SUB(LW(3), 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_SUB(LW(3), 7)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_ADD(LW(3), 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_ADD(LW(3), 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_ADD(LW(3), 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_SUB(LW(3), 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_SUB(LW(3), 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_SUB(LW(3), 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
    EVT_RETURN
    EVT_END
};

EvtSource N(8021B998) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.400390625), EVT_FLOAT(0.400390625), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021B1B4))
    EVT_SET_CONST(LW(0), 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_EXEC_WAIT(N(8021B6AC))
    EVT_END_CHILD_THREAD
    EVT_CALL(EnemyCreateTargetList, 98308)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LW(1))
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_IF_NE(LW(1), LW(0))
        EVT_CALL(ChooseNextTarget, 0, LW(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LW(15), 1)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_EQ(LW(0), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_CALL(GetActorFlags, LW(0), LW(1))
    EVT_IF_FLAG(LW(1), ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetOwnerID, LW(0))
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1005859375))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(7.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 1)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(DispatchDamageEvent, LW(0), 1, 17)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1005859375))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, 296, 0, 0, 0, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021BDE4) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.400390625), EVT_FLOAT(0.400390625), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021B1B4))
    EVT_SET_CONST(LW(0), 1)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_pokey_Palette_00_Anim_20)
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LW(1))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_EXEC_WAIT(N(8021B6AC))
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_IF_NE(LW(10), 3)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 30)
        EVT_SET(LW(1), 0)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 10, 18, 0)
        EVT_ADD(LW(0), 20)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 8, 10, 0)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_ELSE
        EVT_WAIT_FRAMES(30)
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetActorSize, ACTOR_SELF, LW(3), LW(4))
            EVT_DIV(LW(3), 2)
            EVT_ADD(LW(1), LW(3))
            EVT_ADD(LW(2), 5)
            EVT_DIVF(LW(3), EVT_FLOAT(10.0))
            EVT_CALL(PlayEffect, EFFECT_ID_27, 0, LW(0), LW(1), LW(2), LW(3), 10, 0, 0, 0, 0, 0, 0, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_WAIT_FRAMES(10)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(8021C2BC) = {
    EVT_SET_CONST(LW(0), 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(9))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.05078125))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_SET(LW(13), LW(11))
    EVT_ADD(LW(13), 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(13), LW(12))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_CALL(FallToGoal, ACTOR_SELF, 10)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 200, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
