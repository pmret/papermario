#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Pokey.h"

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
    STATUS_NORMAL,    ANIM_Pokey_Anim04,
    STATUS_STONE,     ANIM_Pokey_Anim00,
    STATUS_SLEEP,     ANIM_Pokey_Anim25,
    STATUS_STOP,      ANIM_Pokey_Anim00,
    STATUS_PARALYZE,  ANIM_Pokey_Anim00,
    STATUS_DIZZY,     ANIM_Pokey_Anim21,
    STATUS_FEAR,      ANIM_Pokey_Anim21,
    STATUS_END,
};

s32 N(idleAnimations_80218474)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim05,
    STATUS_STONE,     ANIM_Pokey_Anim01,
    STATUS_SLEEP,     ANIM_Pokey_Anim26,
    STATUS_STOP,      ANIM_Pokey_Anim01,
    STATUS_PARALYZE,  ANIM_Pokey_Anim01,
    STATUS_DIZZY,     ANIM_Pokey_Anim22,
    STATUS_FEAR,      ANIM_Pokey_Anim22,
    STATUS_END,
};

s32 N(idleAnimations_802184B0)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim06,
    STATUS_STONE,     ANIM_Pokey_Anim02,
    STATUS_SLEEP,     ANIM_Pokey_Anim27,
    STATUS_STOP,      ANIM_Pokey_Anim02,
    STATUS_PARALYZE,  ANIM_Pokey_Anim02,
    STATUS_DIZZY,     ANIM_Pokey_Anim23,
    STATUS_FEAR,      ANIM_Pokey_Anim23,
    STATUS_END,
};

s32 N(idleAnimations_802184EC)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim07,
    STATUS_STONE,     ANIM_Pokey_Anim03,
    STATUS_SLEEP,     ANIM_Pokey_Anim28,
    STATUS_STOP,      ANIM_Pokey_Anim03,
    STATUS_PARALYZE,  ANIM_Pokey_Anim03,
    STATUS_DIZZY,     ANIM_Pokey_Anim24,
    STATUS_FEAR,      ANIM_Pokey_Anim24,
    STATUS_END,
};

s32 N(idleAnimations_80218528)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim16,
    STATUS_END,
};

EvtScript N(init_80218534) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021A018)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_802186B0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_802186C0)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, LVar0)
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
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                    EVT_EXEC_WAIT(DoNormalHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(8021CCAC))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                            EVT_EXEC_WAIT(DoNormalHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_WAIT(10)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(8021CCAC))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                            EVT_EXEC_WAIT(DoNormalHit)
                            EVT_WAIT(10)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar2)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LVarA)
                    EVT_SWITCH(LVarA)
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
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar2)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LVarA)
                    EVT_SWITCH(LVarA)
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
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar1)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(8021BF50))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(8021BF50))
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021CCAC))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021CCAC))
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, -1)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 77)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Anim21)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 59)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Anim22)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 41)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Anim23)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 23)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Anim24)
            EVT_END_SWITCH
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar2)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar6)
            EVT_IF_FLAG(LVar6, STATUS_FLAG_SHRINK)
                EVT_MULF(LVar0, EVT_FLOAT(0.4))
                EVT_MULF(LVar1, EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_ADDF(LVar3, LVar0)
            EVT_ADDF(LVar4, LVar1)
            EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar3, LVar4, LVar5, 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 60, 0, 0)
            EVT_ELSE
                EVT_CALL(AddGoalPos, ACTOR_SELF, 24, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim08)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim04)
        EVT_CASE_EQ(1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
            EVT_ELSE
                EVT_CALL(AddGoalPos, ACTOR_SELF, 16, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim09)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim05)
        EVT_CASE_EQ(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
            EVT_ELSE
                EVT_CALL(AddGoalPos, ACTOR_SELF, 8, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim0A)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim06)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x342)
    EVT_CALL(MakeLerp, 0, -40, 20, 10)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2ED)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -40, 90, 5, 1)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(MakeLerp, 90, 0, 5, 0)
            EVT_LABEL(4)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(4)
            EVT_END_IF
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim08)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim04)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim09)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim05)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim0A)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim06)
            EVT_END_SWITCH
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar1, 2)
        EVT_CASE_EQ(1)
            EVT_SET(LVar1, 2)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 2)
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MakeLerp, 90, 0, 10, 0)
            EVT_LABEL(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(5)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim08)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim04)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim09)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim05)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim0A)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim06)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80219EB4) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ACTOR_TYPE_POKEY)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_CALL(GetActorVar, LVar0, 10, LVar3)
                    EVT_IF_NE(LVar3, 2)
                        EVT_ADD(LVar9, 1)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021A018) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_EQ(LVarA, 3)
        EVT_EXEC_WAIT(N(8021B590))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_GOTO(123)
        EVT_END_IF
        EVT_EXEC_WAIT(N(8021AB44))
        EVT_IF_EQ(LVarE, -1)
            EVT_GOTO(123)
        EVT_END_IF
        EVT_EXEC_WAIT(N(80219EB4))
        EVT_SWITCH(LVar9)
            EVT_CASE_EQ(1)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 400)
                    EVT_EXEC_WAIT(N(8021AE2C))
                    EVT_RETURN
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 200)
                    EVT_EXEC_WAIT(N(8021AE2C))
                    EVT_RETURN
                EVT_END_IF
            EVT_CASE_EQ(3)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 100)
                    EVT_EXEC_WAIT(N(8021AE2C))
                    EVT_RETURN
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(123)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_EXEC_WAIT(N(802193B8))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(SetPartSounds, ACTOR_SELF, 6, 2, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(2.2))
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Anim16)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(0)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 38)
                EVT_ELSE
                    EVT_ADD(LVar1, 15)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 15, 1)
            EVT_CASE_EQ(1)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 20)
                EVT_ELSE
                    EVT_ADD(LVar1, 8)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 15, 1)
            EVT_CASE_EQ(2)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_ADD(LVar1, 3)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 15, 1)
            EVT_CASE_EQ(3)
        EVT_END_SWITCH
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x342)
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_WAIT(12)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2CE)
    EVT_WAIT(3)
    EVT_EXEC_WAIT(N(8021C07C))
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_CHILD_THREAD
                    EVT_WAIT(5)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_CHILD_THREAD
            EVT_END_IF
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 80)
            EVT_SUB(LVar1, 5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(20.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Anim16)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(20.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Anim16)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 1)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 55)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 25, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(4.0))
            EVT_SUB(LVar0, 24)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 21, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(3.0))
            EVT_SUB(LVar0, 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 20, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021AB44) = {
    EVT_SET(LVarE, -1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LocalFlag(1), 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_SET(LocalFlag(3), 0)
    EVT_SET(LocalFlag(4), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar5)
    EVT_CALL(GetIndexFromHome, LVar0, LVar5)
    EVT_MOD(LVar5, 4)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_SET(LocalFlag(1), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LocalFlag(2), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LocalFlag(3), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LocalFlag(4), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LocalFlag(1), 0)
                EVT_SET(LVarE, 0)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LocalFlag(2), 0)
                EVT_SET(LVarE, 1)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LocalFlag(3), 0)
                EVT_SET(LVarE, 2)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim04)
    EVT_CALL(MakeLerp, 0, -20, 20, 10)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x344)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -20, 30, 20, 10)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x345)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, 30, -40, 20, 10)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2EE)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -40, 90, 10, 10)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x346)
    EVT_CALL(StartRumble, 9)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8021AE10)), 0)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SUB(LVar1, 80)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CHILD_THREAD
        EVT_CALL(PlayEffect, EFFECT_SHOCKWAVE, 2, LVar0, 0, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(UseIdleAnimation, LVarB, FALSE)
        EVT_CALL(SetAnimation, LVarB, 1, ANIM_Pokey_Anim0C)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, LVarB, EVT_FLOAT(1.2))
        EVT_CALL(SetGoalPos, LVarB, LVar0, 0, LVar2)
        EVT_CALL(JumpToGoal, LVarB, 20, FALSE, TRUE, FALSE)
        EVT_WAIT(20)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(SetAnimation, LVarB, 1, ANIM_Pokey_Anim04)
        EVT_CALL(SetHomePos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(HPBarToHome, LVarB)
        EVT_CALL(UseIdleAnimation, LVarB, TRUE)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVarB, 10, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVarB, 10, 2)
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(MakeLerp, 90, -30, 7, 4)
    EVT_LABEL(4)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(4)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, -30, 0, 10, 10)
    EVT_LABEL(5)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim04)
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
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim0B)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim07)
    EVT_WAIT(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim0B)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_SET(LVar1, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
            EVT_CHILD_THREAD
                EVT_WAIT(2)
                EVT_SET(LVar0, 0)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 22, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
            EVT_CHILD_THREAD
                EVT_WAIT(2)
                EVT_SET(LVar0, 180)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_IF_EQ(LVar0, 360)
                        EVT_SET(LVar0, 0)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_CHILD_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim0B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim07)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
    EVT_CHILD_THREAD
        EVT_WAIT(2)
        EVT_SET(LVar0, 0)
        EVT_LOOP(5)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim07)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim07)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim0B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim07)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BF50) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SET_CONST(LVar0, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
        EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(8021C860))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(8021C860))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(8021C860))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(8021C07C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211269)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211273)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211277)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211282)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211283)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211290)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211291)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80218474)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 62, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 55, 10, 45)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211270)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211274)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211278)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 3211284)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 3211285)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211292)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211293)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_802184B0)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 44, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 35, 10, 25)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3211271)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3211275)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3211279)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 3211294)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3211295)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_802184EC)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 26, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 15, 10, 5)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C574) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 18)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_WAIT(2)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(3)
    EVT_SUB(LVar3, 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(2)
    EVT_SUB(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 7)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar3, 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C860) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021C07C))
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_EXEC_WAIT(N(8021C574))
    EVT_END_CHILD_THREAD
    EVT_CALL(EnemyCreateTargetList, 98308)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LVar1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_IF_NE(LVar1, LVar0)
        EVT_CALL(ChooseNextTarget, 0, LVar0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LVarF, 1)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_CALL(GetActorFlags, LVar0, LVar1)
    EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetOwnerID, LVar0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(7.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 1)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(DispatchDamageEvent, LVar0, 1, 17)
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
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021C07C))
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Anim20)
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar1)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_EXEC_WAIT(N(8021C574))
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_NE(LVarA, 3)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 30)
        EVT_SET(LVar1, 0)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 10, 18, 0)
        EVT_ADD(LVar0, 20)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 8, 10, 0)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_ELSE
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_DIV(LVar3, 2)
            EVT_ADD(LVar1, LVar3)
            EVT_ADD(LVar2, 5)
            EVT_DIVF(LVar3, EVT_FLOAT(10.0))
            EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_WAIT(10)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D184) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar9)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.05))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SET(LVarD, LVarB)
    EVT_ADD(LVarD, 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarD, LVarC)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FallToGoal, -127, 10)
    EVT_WAIT(20)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT(5)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 96)
            EVT_SET(LVar6, 4)
        EVT_CASE_EQ(1)
            EVT_SET(LVar2, 72)
            EVT_SET(LVar6, 3)
        EVT_CASE_EQ(2)
            EVT_SET(LVar2, 48)
            EVT_SET(LVar6, 2)
        EVT_CASE_DEFAULT
            EVT_SET(LVar2, 24)
            EVT_SET(LVar6, 1)
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
        EVT_LOOP(LVar6)
            EVT_CALL(PlayEffect, EFFECT_SHOCKWAVE, 2, LVarA, 0, LVarC, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar4, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(8)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
