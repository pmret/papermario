#include "../area.h"
#include "sprite/npc/PetitPiranha.h"
#include "effects.h"
#include "boss_common.h"

#define NAMESPACE A(petit_piranha)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_IMPACT      = 6,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_PetitPiranha_Anim01,
    STATUS_KEY_STONE,     ANIM_PetitPiranha_Anim01,
    STATUS_KEY_SLEEP,     ANIM_PetitPiranha_Anim01,
    STATUS_KEY_POISON,    ANIM_PetitPiranha_Anim01,
    STATUS_KEY_STOP,      ANIM_PetitPiranha_Anim00,
    STATUS_KEY_STATIC,    ANIM_PetitPiranha_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_PetitPiranha_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_PetitPiranha_Anim01,
    STATUS_KEY_DIZZY,     ANIM_PetitPiranha_Anim01,
    STATUS_KEY_DIZZY,     ANIM_PetitPiranha_Anim01,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,   -2,
    ELEMENT_ICE,     -2,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FIREY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -22 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PETIT_PIRANHA,
    .level = ACTOR_LEVEL_PETIT_PIRANHA,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetEnemyHP, ACTOR_SELF, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_OR_EQ(EVENT_BURN_TAUNT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim03)
            EVT_WAIT(60)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_PetitPiranha_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// unused
EvtScript N(EVS_AbsorbDamage) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 0)
    EVT_ADD(LVar0, 20)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar3)
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_ADD(LVar0, LVar3)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_IF_GT(LVar0, LVar1)
        EVT_SET(LVar0, LVar1)
    EVT_END_IF
    EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SetFlameScaleH)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->scaleH = evt_get_float_variable(script, *args++);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetFlamePosX)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->pos.x = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_GE(LVar1, 41)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim04)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(SetBattleCamZoom, 380)
        EVT_CALL(SetBattleCamOffsetZ, -20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim06)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 15)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 20, -12, EASING_LINEAR)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(SetBattleCamZoom, 380)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim03)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PETIT_PIRANHA_ASCEND)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_LINEAR)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PETIT_PIRANHA_DIVE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 5, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim05)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -16, EASING_QUARTIC_IN)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_ADD(LVar2, 2)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), LVarA, 0)
    EVT_THREAD
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(MakeLerp, 0, 30, 21, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(LVar4, LVar3)
            EVT_SUB(LVar4, LVar0)
            EVT_CALL(N(SetFlamePosX), LVarA, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 140, 160, 2, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_MULF(LVar0, EVT_FLOAT(0.01))
        EVT_CALL(N(SetFlameScaleH), LVarA, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar9, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(MakeLerp, 160, 10, 20, EASING_QUADRATIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_MULF(LVar0, EVT_FLOAT(0.01))
                EVT_CALL(N(SetFlameScaleH), LVarA, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(1)
            EVT_CALL(RemoveEffect, LVarA)
            EVT_IF_EQ(LVar9, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_SET(LVar8, DMG_IMPACT)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar9, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, LVar8, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(MakeLerp, 160, 10, 20, EASING_QUADRATIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_MULF(LVar0, EVT_FLOAT(0.01))
                EVT_CALL(N(SetFlameScaleH), LVarA, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(1)
            EVT_CALL(RemoveEffect, LVarA)
            EVT_WAIT(15)
            EVT_IF_EQ(LVar9, 10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_Death))
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_CALL(ActorExists, ACTOR_BOSS, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_BOSS, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Petit_Parent, LVar0)
    EVT_CALL(GetActorVar, LVar0, AVAR_Bud_PetitCount, LVar1)
    EVT_SUB(LVar1, 1)
    EVT_CALL(SetActorVar, LVar0, AVAR_Bud_PetitCount, LVar1)
    EVT_RETURN
    EVT_END
};
