#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Pokey.h"

#define NAMESPACE b_area_isk_part_1_pokey_mummy

extern s32 N(IdleAnimations_80218DC8)[];
extern s32 N(IdleAnimations_80218EB8)[];
extern EvtScript N(init_80218EC4);
extern EvtScript N(takeTurn_80219D88);
extern EvtScript N(idle_80219040);
extern EvtScript N(handleEvent_80219050);
extern EvtScript N(8021B998);
extern EvtScript N(8021A6C8);
extern EvtScript N(8021B088);
extern EvtScript N(8021B1B4);
extern EvtScript N(8021BDE4);
extern EvtScript N(8021C2BC);

s32 N(DefenseTable_80218C10)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable_80218C1C)[] = {
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

ActorPartBlueprint N(PartsTable_80218CC8)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218DC8),
        .defenseTable = N(DefenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 72 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 36 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218EB8),
        .defenseTable = N(DefenseTable_80218C10),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_POKEY_MUMMY,
    .level = 10,
    .maxHP = 4,
    .partCount = ARRAY_COUNT( N(PartsTable_80218CC8)),
    .partsData = N(PartsTable_80218CC8),
    .initScript = &N(init_80218EC4),
    .statusTable = N(StatusTable_80218C1C),
    .escapeChance = 60,
    .airLiftChance = 90,
    .hurricaneChance = 85,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 24, 80 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusMessageOffset = { 10, 65 },
};

s32 N(IdleAnimations_80218DC8)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Mummy_Anim04,
    STATUS_STONE,     ANIM_Pokey_Mummy_Anim00,
    STATUS_SLEEP,     ANIM_Pokey_Mummy_Anim25,
    STATUS_STOP,      ANIM_Pokey_Mummy_Anim00,
    STATUS_PARALYZE,  ANIM_Pokey_Mummy_Anim00,
    STATUS_DIZZY,     ANIM_Pokey_Mummy_Anim21,
    STATUS_FEAR,      ANIM_Pokey_Mummy_Anim21,
    STATUS_END,
};

s32 N(IdleAnimations_80218E04)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Mummy_Anim05,
    STATUS_STONE,     ANIM_Pokey_Mummy_Anim01,
    STATUS_SLEEP,     ANIM_Pokey_Mummy_Anim26,
    STATUS_STOP,      ANIM_Pokey_Mummy_Anim01,
    STATUS_PARALYZE,  ANIM_Pokey_Mummy_Anim01,
    STATUS_DIZZY,     ANIM_Pokey_Mummy_Anim22,
    STATUS_FEAR,      ANIM_Pokey_Mummy_Anim22,
    STATUS_END,
};

s32 N(IdleAnimations_80218E40)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Mummy_Anim06,
    STATUS_STONE,     ANIM_Pokey_Mummy_Anim02,
    STATUS_SLEEP,     ANIM_Pokey_Mummy_Anim27,
    STATUS_STOP,      ANIM_Pokey_Mummy_Anim02,
    STATUS_PARALYZE,  ANIM_Pokey_Mummy_Anim02,
    STATUS_DIZZY,     ANIM_Pokey_Mummy_Anim23,
    STATUS_FEAR,      ANIM_Pokey_Mummy_Anim23,
    STATUS_END,
};

s32 N(IdleAnimations_80218E7C)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Mummy_Anim07,
    STATUS_STONE,     ANIM_Pokey_Mummy_Anim03,
    STATUS_SLEEP,     ANIM_Pokey_Mummy_Anim28,
    STATUS_STOP,      ANIM_Pokey_Mummy_Anim03,
    STATUS_PARALYZE,  ANIM_Pokey_Mummy_Anim03,
    STATUS_DIZZY,     ANIM_Pokey_Mummy_Anim24,
    STATUS_FEAR,      ANIM_Pokey_Mummy_Anim24,
    STATUS_END,
};

s32 N(IdleAnimations_80218EB8)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Mummy_Anim16,
    STATUS_END,
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(init_80218EC4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80219D88)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80219040)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80219050)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0x00310104)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0x00310108)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0x0031010C)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0x00310110)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0x00310111)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0x00310118)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0x00310119)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80219040) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80219050) = {
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
                            EVT_EXEC_WAIT(N(8021BDE4))
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
                            EVT_EXEC_WAIT(N(8021BDE4))
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
                            EVT_EXEC_WAIT(N(8021BDE4))
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
                            EVT_EXEC_WAIT(N(8021BDE4))
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
            EVT_EXEC_WAIT(N(8021B088))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(8021B088))
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
                EVT_EXEC_WAIT(N(8021BDE4))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021BDE4))
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
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(AfflictActor, ACTOR_PLAYER, STATUS_POISON, 3)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 77)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Anim21)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 59)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Anim22)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 41)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Anim23)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 23)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Anim24)
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
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar3, LVar4, LVar5, 20, 0)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
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

EvtScript N(takeTurn_80219D88) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_EQ(LVarA, 3)
        EVT_EXEC_WAIT(N(8021A6C8))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(SetPartSounds, ACTOR_SELF, 6, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(2.2))
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Mummy_Anim16)
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
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_CASE_EQ(1)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 20)
                EVT_ELSE
                    EVT_ADD(LVar1, 8)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_CASE_EQ(2)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_ADD(LVar1, 3)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_CASE_EQ(3)
        EVT_END_SWITCH
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_342)
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_WAIT(12)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2CE)
    EVT_WAIT(3)
    EVT_EXEC_WAIT(N(8021B1B4))
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Mummy_Anim16)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Mummy_Anim16)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_CHANCE(STATUS_FLAG_POISON, 3, 40), 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 55)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(4.0))
            EVT_SUB(LVar0, 24)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(3.0))
            EVT_SUB(LVar0, 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 20, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A6C8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_2EC, SOUND_2EC)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_2EC, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim0B)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim07)
    EVT_WAIT(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim0B)
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
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim0B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim07)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_CHANCE(STATUS_FLAG_POISON, 3, 100), 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim07)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim07)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim0B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Mummy_Anim07)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B088) = {
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
            EVT_EXEC_WAIT(N(8021B998))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(8021B998))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(8021B998))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B1B4) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0x00310105)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0x00310109)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0x0031010D)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0x00310112)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0x00310113)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0x0031011A)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0x0031011B)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80218E04)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 62, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 55, 10, 45)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0x00310106)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0x0031010A)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0x0031010E)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0x00310114)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0x00310115)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0x0031011C)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0x0031011D)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80218E40)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 44, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 35, 10, 25)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0x00310107)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0x0031010B)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0x0031010F)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0x0031011E)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0x0031011F)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80218E7C)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 26, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 15, 10, 5)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B6AC) = {
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

EvtScript N(8021B998) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021B1B4))
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_EXEC_WAIT(N(8021B6AC))
    EVT_END_CHILD_THREAD
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_8000 | TARGET_FLAG_10000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LVar1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_IF_NE(LVar1, LVar0)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LVarF, 1)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
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
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_CHILD_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, 296, 0, 0, 0, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BDE4) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021B1B4))
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
        EVT_EXEC_WAIT(N(8021B6AC))
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_NE(LVarA, 3)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 30)
        EVT_SET(LVar1, 0)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 10, 18, EASING_LINEAR)
        EVT_ADD(LVar0, 20)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 8, 10, EASING_LINEAR)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_WAIT(10)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C2BC) = {
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
    EVT_CALL(FallToGoal, ACTOR_SELF, 10)
    EVT_WAIT(20)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT(5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 200, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(8)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
