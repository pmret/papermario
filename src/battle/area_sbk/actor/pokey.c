#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/pokey.h"

#define NAMESPACE b_area_sbk_pokey

extern s32 N(idleAnimations_80218438)[];
extern s32 N(idleAnimations_80218528)[];
extern EvtScript N(init_80218534);
extern EvtScript N(takeTurn_8021A018);
extern EvtScript N(idle_802186B0);
extern EvtScript N(handleEvent_802186C0);
extern EvtScript N(8021AB44);
extern EvtScript N(8021AE2C);
extern EvtScript N(8021B590);
extern EvtScript N(8021BF50);
extern EvtScript N(8021C07C);
extern EvtScript N(8021C860);
extern EvtScript N(8021CCAC);
extern EvtScript N(8021D184);

s32 N(defenseTable_80218280)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021828C)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 90,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 90,
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

ActorPartBlueprint N(partsTable_80218338)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218438),
        .defenseTable = N(defenseTable_80218280),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 72 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218280),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1D = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218280),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1D = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 36 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218280),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1D = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80218280),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1D = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218528),
        .defenseTable = N(defenseTable_80218280),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_POKEY,
    .level = 9,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_80218338)),
    .partsData = N(partsTable_80218338),
    .script = &N(init_80218534),
    .statusTable = N(statusTable_8021828C),
    .escapeChance = 70,
    .airLiftChance = 90,
    .spookChance = 85,
    .baseStatusChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 24, 80 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusMessageOffset = { 10, 65 },
};

s32 N(idleAnimations_80218438)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_00_Anim_4,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_00_Anim_25,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_00_Anim_21,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_00_Anim_21,
    STATUS_END,
};

s32 N(idleAnimations_80218474)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_00_Anim_5,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_00_Anim_1,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_00_Anim_26,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_00_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_00_Anim_22,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_00_Anim_22,
    STATUS_END,
};

s32 N(idleAnimations_802184B0)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_00_Anim_6,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_00_Anim_2,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_00_Anim_27,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_00_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_00_Anim_2,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_00_Anim_23,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_00_Anim_23,
    STATUS_END,
};

s32 N(idleAnimations_802184EC)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_00_Anim_7,
    STATUS_STONE,     NPC_ANIM_pokey_Palette_00_Anim_3,
    STATUS_SLEEP,     NPC_ANIM_pokey_Palette_00_Anim_28,
    STATUS_STOP,      NPC_ANIM_pokey_Palette_00_Anim_3,
    STATUS_PARALYZE,  NPC_ANIM_pokey_Palette_00_Anim_3,
    STATUS_DIZZY,     NPC_ANIM_pokey_Palette_00_Anim_24,
    STATUS_FEAR,      NPC_ANIM_pokey_Palette_00_Anim_24,
    STATUS_END,
};

s32 N(idleAnimations_80218528)[] = {
    STATUS_NORMAL,    NPC_ANIM_pokey_Palette_00_Anim_16,
    STATUS_END,
};

EvtScript N(init_80218534) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021A018)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_802186B0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802186C0)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, LW(0))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211268)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211272)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211276)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211280)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211281)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211288)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211289)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802186B0) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802186C0) = {
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
                            EVT_EXEC_WAIT(N(8021CCAC))
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
                            EVT_EXEC_WAIT(N(8021CCAC))
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
                            EVT_EXEC_WAIT(N(8021CCAC))
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
                            EVT_EXEC_WAIT(N(8021CCAC))
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
            EVT_EXEC_WAIT(N(8021BF50))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(8021BF50))
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
                EVT_EXEC_WAIT(N(8021CCAC))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021CCAC))
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
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 77)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_00_Anim_21)
                EVT_CASE_EQ(1)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 59)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_00_Anim_22)
                EVT_CASE_EQ(2)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 41)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_00_Anim_23)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(0), 0)
                    EVT_SET(LW(1), 23)
                    EVT_SET_CONST(LW(2), NPC_ANIM_pokey_Palette_00_Anim_24)
            EVT_END_SWITCH
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SLEEP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(2))
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(6))
            EVT_IF_FLAG(LW(6), STATUS_FLAG_SHRINK)
                EVT_MULF(LW(0), EVT_FLOAT(0.4))
                EVT_MULF(LW(1), EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_ADDF(LW(3), LW(0))
            EVT_ADDF(LW(4), LW(1))
            EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LW(3), LW(4), LW(5), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(30)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(1))
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(8021D184))
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802193B8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 60, 0, 0)
            EVT_ELSE
                EVT_CALL(AddGoalPos, ACTOR_SELF, 24, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_8)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_4)
        EVT_CASE_EQ(1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
            EVT_ELSE
                EVT_CALL(AddGoalPos, ACTOR_SELF, 16, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_9)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_5)
        EVT_CASE_EQ(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
            EVT_ELSE
                EVT_CALL(AddGoalPos, ACTOR_SELF, 8, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_A)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_6)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x342)
    EVT_CALL(MakeLerp, 0, -40, 20, 10)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2ED)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -40, 90, 5, 1)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(MakeLerp, 90, 0, 5, 0)
            EVT_LABEL(4)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(LW(1), 1)
                EVT_GOTO(4)
            EVT_END_IF
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_8)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_4)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_9)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_5)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_A)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_6)
            EVT_END_SWITCH
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_SET(LW(1), 2)
        EVT_CASE_EQ(1)
            EVT_SET(LW(1), 2)
        EVT_CASE_DEFAULT
            EVT_SET(LW(1), 2)
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, LW(1), BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MakeLerp, 90, 0, 10, 0)
            EVT_LABEL(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(LW(1), 1)
                EVT_GOTO(5)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_8)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_4)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_9)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_5)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_A)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_6)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80219EB4) = {
    EVT_SET(LW(9), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(GetOriginalActorType, LW(0), LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_EQ(ACTOR_TYPE_POKEY)
            EVT_CALL(GetStatusFlags, LW(0), LW(3))
            EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(3))
                EVT_IF_EQ(LW(3), 0)
                    EVT_CALL(GetActorVar, LW(0), 10, LW(3))
                    EVT_IF_NE(LW(3), 2)
                        EVT_ADD(LW(9), 1)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021A018) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_IF_EQ(LW(10), 3)
        EVT_EXEC_WAIT(N(8021B590))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 9, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 10, LW(0))
        EVT_IF_EQ(LW(0), 2)
            EVT_GOTO(123)
        EVT_END_IF
        EVT_EXEC_WAIT(N(8021AB44))
        EVT_IF_EQ(LW(14), -1)
            EVT_GOTO(123)
        EVT_END_IF
        EVT_EXEC_WAIT(N(80219EB4))
        EVT_SWITCH(LW(9))
            EVT_CASE_EQ(1)
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 400)
                    EVT_EXEC_WAIT(N(8021AE2C))
                    EVT_RETURN
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 200)
                    EVT_EXEC_WAIT(N(8021AE2C))
                    EVT_RETURN
                EVT_END_IF
            EVT_CASE_EQ(3)
                EVT_CALL(RandInt, 1000, LW(0))
                EVT_IF_LT(LW(0), 100)
                    EVT_EXEC_WAIT(N(8021AE2C))
                    EVT_RETURN
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(123)
    EVT_CALL(RandInt, 1000, LW(0))
    EVT_IF_LT(LW(0), 500)
        EVT_EXEC_WAIT(N(802193B8))
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
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(2.2))
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_pokey_Palette_00_Anim_16)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
        EVT_SWITCH(LW(10))
            EVT_CASE_EQ(0)
                EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_ADD(LW(1), 38)
                EVT_ELSE
                    EVT_ADD(LW(1), 15)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 15, 1)
            EVT_CASE_EQ(1)
                EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_ADD(LW(1), 20)
                EVT_ELSE
                    EVT_ADD(LW(1), 8)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 15, 1)
            EVT_CASE_EQ(2)
                EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                    EVT_ADD(LW(1), 8)
                EVT_ELSE
                    EVT_ADD(LW(1), 3)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
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
    EVT_EXEC_WAIT(N(8021C07C))
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
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_pokey_Palette_00_Anim_16)
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
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_pokey_Palette_00_Anim_16)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 1)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 55)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
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

EvtScript N(8021AB44) = {
    EVT_SET(LW(14), -1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LF(1), 0)
    EVT_SET(LF(2), 0)
    EVT_SET(LF(3), 0)
    EVT_SET(LF(4), 0)
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
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LF(1), 0)
                EVT_SET(LW(14), 0)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LF(2), 0)
                EVT_SET(LW(14), 1)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LF(3), 0)
                EVT_SET(LW(14), 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021AE04) = { 400, 0xFFFFFF9C, 0 };

Formation N(specialFormation_8021AE10) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(vector3D_8021AE04) }, .priority = 100 },
};

EvtScript N(8021AE2C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_4)
    EVT_CALL(MakeLerp, 0, -20, 20, 10)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x344)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -20, 30, 20, 10)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(6)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x345)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, 30, -40, 20, 10)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2EE)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -40, 90, 10, 10)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x346)
    EVT_CALL(StartRumble, 9)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021AE10)), 0)
    EVT_SET(LW(11), LW(0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 40)
    EVT_SUB(LW(1), 80)
    EVT_CALL(SetActorPos, LW(11), LW(0), LW(1), LW(2))
    EVT_CHILD_THREAD
        EVT_CALL(PlayEffect, EFFECT_SHOCKWAVE, 2, LW(0), 0, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(UseIdleAnimation, LW(11), FALSE)
        EVT_CALL(SetAnimation, LW(11), 1, NPC_ANIM_pokey_Palette_00_Anim_C)
        EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, LW(11), EVT_FLOAT(1.2))
        EVT_CALL(SetGoalPos, LW(11), LW(0), 0, LW(2))
        EVT_CALL(JumpToGoal, LW(11), 20, FALSE, TRUE, FALSE)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
        EVT_CALL(SetAnimation, LW(11), 1, NPC_ANIM_pokey_Palette_00_Anim_4)
        EVT_CALL(SetHomePos, LW(11), LW(0), LW(1), LW(2))
        EVT_CALL(HPBarToHome, LW(11))
        EVT_CALL(UseIdleAnimation, LW(11), TRUE)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 10, LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LW(11), 10, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LW(11), 10, 2)
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SET(LW(10), LW(0))
    EVT_CALL(MakeLerp, 90, -30, 7, 4)
    EVT_LABEL(4)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(4)
    EVT_END_IF
    EVT_WAIT_FRAMES(20)
    EVT_CALL(MakeLerp, -30, 0, 10, 10)
    EVT_LABEL(5)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_4)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B590) = {
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
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_B)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_7)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_B)
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
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_7)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_7)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
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
            EVT_SUB(LW(0), 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_7)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_pokey_Palette_00_Anim_7)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BF50) = {
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
            EVT_EXEC_WAIT(N(8021C860))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(8021C860))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(8021C860))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoSpinSmashHit)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(8021C07C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211269)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211273)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211277)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211282)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211283)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211290)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211291)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218474)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, -250000000)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 62, -250000000)
            EVT_CALL(N(UnkBattleFunc1), -15, 55, 10, 45)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211270)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211274)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211278)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211284)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211285)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211292)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211293)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802184B0)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, -250000000)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 44, -250000000)
            EVT_CALL(N(UnkBattleFunc1), -15, 35, 10, 25)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211271)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211275)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211279)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211294)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211295)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802184EC)))
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

EvtScript N(8021C574) = {
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

EvtScript N(8021C860) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021C07C))
    EVT_SET_CONST(LW(0), 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CHILD_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_EXEC_WAIT(N(8021C574))
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
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
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
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, 296, 0, 0, 0, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021CCAC) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021C07C))
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
        EVT_EXEC_WAIT(N(8021C574))
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
            EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LW(0), LW(1), LW(2), LW(3), 10, 0, 0, 0, 0, 0, 0, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_WAIT_FRAMES(10)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D184) = {
    EVT_SET_CONST(LW(0), 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(9))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.05))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_SET(LW(13), LW(11))
    EVT_ADD(LW(13), 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(13), LW(12))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_CALL(FallToGoal, -127, 10)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_EQ(0)
            EVT_SET(LW(2), 96)
            EVT_SET(LW(6), 4)
        EVT_CASE_EQ(1)
            EVT_SET(LW(2), 72)
            EVT_SET(LW(6), 3)
        EVT_CASE_EQ(2)
            EVT_SET(LW(2), 48)
            EVT_SET(LW(6), 2)
        EVT_CASE_DEFAULT
            EVT_SET(LW(2), 24)
            EVT_SET(LW(6), 1)
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
        EVT_LOOP(LW(6))
            EVT_CALL(PlayEffect, EFFECT_SHOCKWAVE, 2, LW(10), 0, LW(12), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_SUB(LW(4), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
