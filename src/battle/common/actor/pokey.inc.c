#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Pokey.h"

enum N(ActorVars) {
    N(VAR_PARTS_THROWN) = 0,
    N(VAR_ANIM_IMMUNE) = 1,
    N(VAR_ANIM_UNK) = 2,
    N(VAR_ANIM_HIT) = 3,
    N(VAR_ANIM_THROW1) = 4,
    N(VAR_ANIM_THROW2) = 5,
    N(VAR_ANIM_BURN) = 6,
    N(VAR_ANIM_BURN2) = 7,
    N(VAR_CANT_SUMMON) = 9,
    N(VAR_SUMMON_COUNT) = 10,
};

extern s32 N(IdleAnimations)[];
extern s32 N(IdleAnimations_thrownBodyPart)[];
extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(findPlaceForSummon);
extern EvtScript N(unearthFriend);
extern EvtScript N(attackHeadDive);
extern EvtScript N(onSpinSmash);
extern EvtScript N(afterPartThrown);
extern EvtScript N(doSpinSmashHit);
extern EvtScript N(onHit);
extern EvtScript N(flee);

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
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

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
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
        .defenseTable = N(DefenseTable),
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
        .defenseTable = N(DefenseTable),
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
        .defenseTable = N(DefenseTable),
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
        .defenseTable = N(DefenseTable),
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
        .idleAnimations = N(IdleAnimations_thrownBodyPart),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_200000,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_POKEY,
    .level = 9,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 70,
    .airLiftChance = 90,
    .hurricaneChance = 85,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 24, 80 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusMessageOffset = { 10, 65 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim04,
    STATUS_STONE,     ANIM_Pokey_Anim00,
    STATUS_SLEEP,     ANIM_Pokey_Anim25,
    STATUS_STOP,      ANIM_Pokey_Anim00,
    STATUS_PARALYZE,  ANIM_Pokey_Anim00,
    STATUS_DIZZY,     ANIM_Pokey_Anim21,
    STATUS_FEAR,      ANIM_Pokey_Anim21,
    STATUS_END,
};

s32 N(IdleAnimations_3bodyParts)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim05,
    STATUS_STONE,     ANIM_Pokey_Anim01,
    STATUS_SLEEP,     ANIM_Pokey_Anim26,
    STATUS_STOP,      ANIM_Pokey_Anim01,
    STATUS_PARALYZE,  ANIM_Pokey_Anim01,
    STATUS_DIZZY,     ANIM_Pokey_Anim22,
    STATUS_FEAR,      ANIM_Pokey_Anim22,
    STATUS_END,
};

s32 N(IdleAnimations_2bodyParts)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim06,
    STATUS_STONE,     ANIM_Pokey_Anim02,
    STATUS_SLEEP,     ANIM_Pokey_Anim27,
    STATUS_STOP,      ANIM_Pokey_Anim02,
    STATUS_PARALYZE,  ANIM_Pokey_Anim02,
    STATUS_DIZZY,     ANIM_Pokey_Anim23,
    STATUS_FEAR,      ANIM_Pokey_Anim23,
    STATUS_END,
};

s32 N(IdleAnimations_1bodyPart)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim07,
    STATUS_STONE,     ANIM_Pokey_Anim03,
    STATUS_SLEEP,     ANIM_Pokey_Anim28,
    STATUS_STOP,      ANIM_Pokey_Anim03,
    STATUS_PARALYZE,  ANIM_Pokey_Anim03,
    STATUS_DIZZY,     ANIM_Pokey_Anim24,
    STATUS_FEAR,      ANIM_Pokey_Anim24,
    STATUS_END,
};

s32 N(IdleAnimations_thrownBodyPart)[] = {
    STATUS_NORMAL,    ANIM_Pokey_Anim16,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SUMMON_COUNT), 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_IMMUNE), LVar0) // from formation 'var1' setting
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_CANT_SUMMON), LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_IMMUNE), ANIM_Pokey_Anim04)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_UNK), ANIM_Pokey_Anim08)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), ANIM_Pokey_Anim0C)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW1), ANIM_Pokey_Anim10)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW2), ANIM_Pokey_Anim11)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN), ANIM_Pokey_Anim18)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), ANIM_Pokey_Anim19)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(onHit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                            EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_WAIT(10)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(onHit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                            EVT_EXEC_WAIT(EVS_DoNormalHit)
                            EVT_WAIT(10)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN), LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), LVar2)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(onHit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN), LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), LVar2)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(onHit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), LVar1)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onSpinSmash))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(onSpinSmash))
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(onHit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(onHit))
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, -1)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_UNK), LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(D_8029C12C)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_IMMUNE), LVar1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar0)
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
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar3, LVar4, LVar5, 20, 0)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_IMMUNE), LVar1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(flee))
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(timberAttack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar0)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_342)
    EVT_CALL(MakeLerp, 0, -40, 20, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2ED)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -40, 90, 5, EASING_QUADRATIC_IN)
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
            EVT_CALL(MakeLerp, 90, 0, 5, EASING_LINEAR)
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
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar0)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar0)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_CHANCE(STATUS_FLAG_POISON, 3, 0), LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MakeLerp, 90, 0, 10, EASING_LINEAR)
            EVT_LABEL(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(5)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar0)
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

EvtScript N(calcSummonChance) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ACTOR_TYPE_POKEY)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_CALL(GetActorVar, LVar0, N(VAR_SUMMON_COUNT), LVar3)
                    EVT_IF_NE(LVar3, 2)
                        EVT_ADD(LVar9, 1)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
    EVT_IF_EQ(LVarA, 3)
        EVT_EXEC_WAIT(N(attackHeadDive))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CANT_SUMMON), LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SUMMON_COUNT), LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_GOTO(123)
        EVT_END_IF
        EVT_EXEC_WAIT(N(findPlaceForSummon))
        EVT_IF_EQ(LVarE, -1)
            EVT_GOTO(123)
        EVT_END_IF
        EVT_EXEC_WAIT(N(calcSummonChance))
        EVT_SWITCH(LVar9)
            EVT_CASE_EQ(1)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 400)
                    EVT_EXEC_WAIT(N(unearthFriend))
                    EVT_RETURN
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 200)
                    EVT_EXEC_WAIT(N(unearthFriend))
                    EVT_RETURN
                EVT_END_IF
            EVT_CASE_EQ(3)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 100)
                    EVT_EXEC_WAIT(N(unearthFriend))
                    EVT_RETURN
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(123)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_EXEC_WAIT(N(timberAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Anim16)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW1), LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_WAIT(12)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW2), LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2CE)
    EVT_WAIT(3)
    EVT_EXEC_WAIT(N(afterPartThrown))
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
            EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_UNK), LVar1)
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
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_CHANCE(STATUS_FLAG_POISON, 3, 0), 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_UNK), LVar1)
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

EvtScript N(findPlaceForSummon) = {
    EVT_SET(LVarE, -1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LocalFlag(1), 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_SET(LocalFlag(3), 0)
    EVT_SET(LocalFlag(4), 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
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
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
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

Vec3i N(summon_pos) = { 400, -100, 0 };

Formation N(summon_formation) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(summon_pos) }, .priority = 100 },
};

EvtScript N(unearthFriend) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim04)
    EVT_CALL(MakeLerp, 0, -20, 20, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_344)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -20, 30, 20, EASING_COS_IN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_345)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, 30, -40, 20, EASING_COS_IN_OUT)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EE)
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, -40, 90, 10, EASING_COS_IN_OUT)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_346)
    EVT_CALL(StartRumble, 9)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SummonEnemy, EVT_PTR(N(summon_formation)), 0)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SUB(LVar1, 80)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CHILD_THREAD
        EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 2, LVar0, 0, LVar2, 0)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SUMMON_COUNT), LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVarB, N(VAR_SUMMON_COUNT), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVarB, N(VAR_SUMMON_COUNT), 2)
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(MakeLerp, 90, -30, 7, EASING_QUADRATIC_OUT)
    EVT_LABEL(4)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(4)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, -30, 0, 10, EASING_COS_IN_OUT)
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

EvtScript N(attackHeadDive) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_2EC, SOUND_2EC)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_2EC, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
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
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_CHANCE(STATUS_FLAG_POISON, 3, 0), 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Pokey_Anim07)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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

EvtScript N(onSpinSmash) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SET_CONST(LVar0, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
        EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(afterPartThrown) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_IMMUNE), ANIM_Pokey_Anim05)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_UNK), ANIM_Pokey_Anim09)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), ANIM_Pokey_Anim0D)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW1), ANIM_Pokey_Anim12)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW2), ANIM_Pokey_Anim13)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN), ANIM_Pokey_Anim1A)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), ANIM_Pokey_Anim1B)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_3bodyParts)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 62, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 55, 10, 45)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_IMMUNE), ANIM_Pokey_Anim06)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_UNK), ANIM_Pokey_Anim0A)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), ANIM_Pokey_Anim0E)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW1), ANIM_Pokey_Anim14)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_THROW2), ANIM_Pokey_Anim15)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN), ANIM_Pokey_Anim1C)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), ANIM_Pokey_Anim1D)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_2bodyParts)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), 2)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 44, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 35, 10, 25)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_IMMUNE), ANIM_Pokey_Anim07)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_UNK), ANIM_Pokey_Anim0B)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), ANIM_Pokey_Anim0F)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN), ANIM_Pokey_Anim1E)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), ANIM_Pokey_Anim1F)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_1bodyPart)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), 3)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 26, EVT_IGNORE_ARG)
            EVT_CALL(N(UnkBattleFunc1), -15, 15, 10, 5)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(bounceOnHit) = {
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

EvtScript N(doSpinSmashHit) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(afterPartThrown))
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_EXEC_WAIT(N(bounceOnHit))
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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, 296, 0, 0, 0, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(afterPartThrown))
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Pokey_Anim20)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN), LVar1)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_EXEC_WAIT(N(bounceOnHit))
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVarA)
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
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_DIV(LVar3, 2)
            EVT_ADD(LVar1, LVar3)
            EVT_ADD(LVar2, 5)
            EVT_DIVF(LVar3, EVT_FLOAT(10.0))
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_BURN2), LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_WAIT(10)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(flee) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_ANIM_HIT), LVar1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PARTS_THROWN), LVar2)
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
            EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 2, LVarA, 0, LVarC, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar4, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    EVT_WAIT(8)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
