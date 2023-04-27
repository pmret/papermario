#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/CrystalKing.h"

#define NAMESPACE b_area_pra2_crystal_king

enum N(StatusFlags) {
    N(FLAG_IGNORE_IMMUNE)           = 0x01,
    N(FLAG_LOW_HP)                  = 0x02,
    N(FLAG_SUMMONED_CLONES_ONCE)    = 0x04,
    N(FLAG_FORBID_SECOND_ATTACK)    = 0x10,
    N(FLAG_HAS_CLONES)              = 0x20,
    N(FLAG_NOT_IDLE)                = 0x40,
};

enum N(Phase) {
    N(PHASE_BEGIN)                  = 0,
    N(PHASE_NEED_BITS)              = 1,
    N(PHASE_SUMMONED_BITS)          = 2,
    N(PHASE_AFTER_ATTACK)           = 3,
    N(PHASE_SUMMONED_CLONES)        = 4,
    N(PHASE_ATTACKED_WITH_CLONES)   = 5,
};

enum N(ActorVars) {
    N(VAR_FLAGS)            = 0,
    N(VAR_PHASE)            = 1,
    N(VAR_CLONE1_ID)        = 2,
    N(VAR_CLONE2_ID)        = 3,
    N(VAR_BIT1_ID)          = 4,
    N(VAR_BIT2_ID)          = 5,
    N(VAR_BIT3_ID)          = 6,
    N(VAR_HEAL_COUNTER)     = 7,
    N(VAR_FLY_THREAD_ID)    = 8,
};

static Vec3f N(paths)[3][3];

extern ActorBlueprint b_area_pra2_crystal_bit_1;
extern ActorBlueprint b_area_pra2_crystal_bit_2;
extern ActorBlueprint b_area_pra2_crystal_bit_3;

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

extern EvtScript N(AttackIcyBreath);
extern EvtScript N(AttackIceBolt);
extern EvtScript N(MakeIllusions);
extern EvtScript N(SummonCrystalBits);
extern EvtScript N(AttackIcyBreathWithClones);
extern EvtScript N(NormalAttack);
extern EvtScript N(Heal);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_CrystalKing_Anim09,
    STATUS_SLEEP, ANIM_CrystalKing_Anim1B,
    STATUS_DIZZY, ANIM_CrystalKing_Anim1A,
    STATUS_PARALYZE, ANIM_CrystalKing_Anim00,
    STATUS_STOP, ANIM_CrystalKing_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_FIRE, 0,
    ELEMENT_ICE, 99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 40,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 40,
    STATUS_SHRINK, 0,
    STATUS_STOP, 50,
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

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_8 | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -22 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CRYSTAL_KING,
    .level = 85,
    .maxHP = 70,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 56, 56 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 40 },
    .statusMessageOffset = { 15, 40 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLAGS), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_BEGIN))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), ACTOR_ENEMY1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), ACTOR_ENEMY2)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), ACTOR_ENEMY3)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/CosInterpMinMax.inc.c"

API_CALLABLE(GetActorPartOpacity) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    evt_set_variable(script, *args++, get_actor_part(get_actor(actorID), partID)->opacity);

    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218280_6609D0) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args);

    effect->data.huffPuffBreath->primR = 0xF8;
    effect->data.huffPuffBreath->primG = 0xF8;
    effect->data.huffPuffBreath->primB = 0xFF;
    effect->data.huffPuffBreath->envR = 0x80;
    effect->data.huffPuffBreath->envG = 0xE0;
    ((HuffPuffBreathFXData*)effect->data.huffPuffBreath)->envB = 0xFF;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802182E4_660A34) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args);

    effect->data.lightningBolt->outerColor.r = 255;
    effect->data.lightningBolt->outerColor.g = 255;
    effect->data.lightningBolt->outerColor.b = 255;
    effect->data.lightningBolt->innerColor.r = 200;
    effect->data.lightningBolt->innerColor.g = 240;
    effect->data.lightningBolt->innerColor.b = 255;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218344_660A94) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.coldBreath->unk_18 = 0xFF;
    effect->data.coldBreath->unk_1C = 0xFF;
    effect->data.coldBreath->unk_20 = 0xFF;
    effect->data.coldBreath->unk_28 = 0xC8;
    effect->data.coldBreath->unk_2C = 0xF0;
    effect->data.coldBreath->unk_30 = 0xFF;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802183A4_660AF4) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;
    f32 startX = evt_get_variable(script, *args++);
    f32 startZ = evt_get_variable(script, *args++);
    f32 endX = evt_get_variable(script, *args++);
    f32 endZ = evt_get_variable(script, *args++);

    evt_set_variable(script, arg0, atan2(startX, startZ, endX, endZ));
    return ApiStatus_DONE2;
}

API_CALLABLE(func_8021848C_660BDC) {
    Bytecode* args = script->ptrReadPos;
    Vec3f* path = (Vec3f*)evt_get_variable(script, *args++);

    path[0].x = evt_get_variable(script, *args++);
    path[0].y = evt_get_variable(script, *args++);
    path[0].z = evt_get_variable(script, *args++);
    path[1].x = -rand_int(20);
    path[1].y = rand_int(40) + 40;
    path[1].z = 0;
    path[2].x = evt_get_variable(script, *args++);
    path[2].y = evt_get_variable(script, *args++);
    path[2].z = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(idle) = {
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_IF_FLAG(LVar0, N(FLAG_HAS_CLONES))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar2)
        EVT_CALL(ActorExists, LVar1, LVar3)
        EVT_IF_EQ(LVar3, TRUE)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar4, EVT_FLOAT(128.0), EVT_FLOAT(254.0), 20, 0, 0)
            EVT_SET(LVar4, LVar4)
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar4)
            EVT_CALL(SetPartAlpha, LVar1, 1, LVar4)
            EVT_CALL(SetPartAlpha, LVar2, 1, LVar4)
            EVT_ADD(LVarF, 1)
            EVT_IF_GT(LVarF, 40)
                EVT_SET(LVarF, 0)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_HAS_CLONES))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVarF, 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(FlyWithClones) = {
    EVT_SET(LVarA, 0)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, 0)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarF, 0)
    EVT_LABEL(1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_IF_NOT_FLAG(LVar0, N(FLAG_NOT_IDLE))
        EVT_SET(LVar0, ACTOR_SELF)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar2)
        EVT_CALL(GetActorPos, LVar0, LVar3, LVar4, LVar5)
        EVT_CALL(GetActorPos, LVar1, LVar4, LVar5, LVar6)
        EVT_IF_GT(LVar3, LVar4)
            EVT_SET(LVar7, LVar0)
            EVT_SET(LVar0, LVar1)
            EVT_SET(LVar1, LVar7)
        EVT_END_IF
        EVT_CALL(GetActorPos, LVar0, LVar3, LVar4, LVar5)
        EVT_CALL(GetActorPos, LVar2, LVar4, LVar5, LVar6)
        EVT_IF_GT(LVar3, LVar4)
            EVT_SET(LVar7, LVar0)
            EVT_SET(LVar0, LVar2)
            EVT_SET(LVar2, LVar7)
        EVT_END_IF
        EVT_CALL(GetActorPos, LVar1, LVar3, LVar4, LVar5)
        EVT_CALL(GetActorPos, LVar2, LVar4, LVar5, LVar6)
        EVT_IF_GT(LVar3, LVar4)
            EVT_SET(LVar7, LVar1)
            EVT_SET(LVar1, LVar2)
            EVT_SET(LVar2, LVar7)
        EVT_END_IF
        EVT_CALL(GetActorPos, LVar0, LVar3, LVar4, LVar5)
        EVT_SET(LVar4, 41)
        EVT_ADD(LVar4, LVarA)
        EVT_CALL(SetActorPos, LVar0, LVar3, LVar4, LVar5)
        EVT_CALL(GetActorPos, LVar1, LVar3, LVar4, LVar5)
        EVT_SET(LVar4, 41)
        EVT_ADD(LVar4, LVarC)
        EVT_CALL(SetActorPos, LVar1, LVar3, LVar4, LVar5)
        EVT_CALL(GetActorPos, LVar2, LVar3, LVar4, LVar5)
        EVT_SET(LVar4, 41)
        EVT_ADD(LVar4, LVarE)
        EVT_CALL(SetActorPos, LVar2, LVar3, LVar4, LVar5)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.0), EVT_FLOAT(5.0), 30, 0, 0)
        EVT_SET(LVarA, LVarB)
        EVT_SET(LVarB, LVarC)
        EVT_SET(LVarC, LVarD)
        EVT_SET(LVarD, LVarE)
        EVT_SET(LVarE, LVar0)
        EVT_ADD(LVarF, 1)
        EVT_IF_GT(LVarF, 60)
            EVT_SET(LVarF, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(RemoveClone) = {
    EVT_CALL(EnableActorBlur, LVar9, 1)
    EVT_CALL(SetActorFlagBits, LVar9, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_THREAD
        EVT_CALL(GetActorPartOpacity, LVar9, 1, LVar3)
        EVT_CALL(MakeLerp, LVar3, 0, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartAlpha, LVar9, 1, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 200, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar8)
        EVT_IF_FLAG(LVar8, STATUS_FLAG_SHRINK)
            EVT_MULF(LVar0, EVT_FLOAT(0.4))
        EVT_END_IF
        EVT_DIVF(LVar0, EVT_FLOAT(100.0))
        EVT_CALL(SetPartScale, LVar9, 1, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetActorRotationOffset, LVar9, 0, 28, 0)
    EVT_ELSE
        EVT_CALL(SetActorRotationOffset, LVar9, 0, 10, 0)
    EVT_END_IF
    EVT_CALL(MakeLerp, 0x00000E10, 0, 25, EASING_QUADRATIC_IN)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, LVar9, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(RemoveActor, LVar9)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
        EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(N(PHASE_BEGIN))
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_BITS))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
                EVT_CALL(ActorExists, LVar0, LVar1)
                EVT_IF_EQ(LVar1, TRUE)
                    EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                    EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
                EVT_END_IF
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
                EVT_CALL(ActorExists, LVar0, LVar1)
                EVT_IF_EQ(LVar1, TRUE)
                    EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                    EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
                EVT_END_IF
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
                EVT_CALL(ActorExists, LVar0, LVar1)
                EVT_IF_EQ(LVar1, TRUE)
                    EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                    EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
                EVT_END_IF
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetLastElement, LVar0)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_100)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar9)
    EVT_CALL(ActorExists, LVar9, LVarA)
    EVT_IF_EQ(LVarA, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar9)
        EVT_EXEC(N(RemoveClone))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar9)
        EVT_EXEC_GET_TID(N(RemoveClone), LVar0)
        EVT_LABEL(1)
        EVT_IS_THREAD_RUNNING(LVar0, LVar1)
        EVT_IF_EQ(LVar1, TRUE)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLY_THREAD_ID), LVarA)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E3)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 150, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.7))
        EVT_END_THREAD
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_WAIT(15)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim0E)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 0, 5)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_IGNORE_IMMUNE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnDeath) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
        EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(N(PHASE_BEGIN))
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_BITS))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetLastElement, LVar0)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_100)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLY_THREAD_ID), LVarA)
    EVT_IS_THREAD_RUNNING(LVarA, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_KILL_THREAD(LVarA)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar9)
    EVT_CALL(ActorExists, LVar9, LVarA)
    EVT_IF_EQ(LVarA, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar9)
        EVT_EXEC(N(RemoveClone))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar9)
        EVT_EXEC_GET_TID(N(RemoveClone), LVar0)
        EVT_LABEL(1)
        EVT_IS_THREAD_RUNNING(LVar0, LVar1)
        EVT_IF_EQ(LVar1, TRUE)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_OR_CONST(LVar0, N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_OR_CONST(LVar0, N(FLAG_IGNORE_IMMUNE))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(OnHit))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
            EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(N(OnHit))
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim09)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim09)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_FLAG(LVar0, N(FLAG_IGNORE_IMMUNE))
                EVT_EXEC_WAIT(N(OnHit))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_EXEC_WAIT(N(OnHit))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
            EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim21)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
                    EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
                        EVT_SETF(LVar0, EVT_FLOAT(0.4))
                        EVT_LOOP(30)
                            EVT_SETF(LVar1, EVT_FLOAT(1.0))
                            EVT_SUBF(LVar1, LVar0)
                            EVT_DIVF(LVar1, EVT_FLOAT(6.0))
                            EVT_ADDF(LVar0, LVar1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, 1, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, 1, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_WAIT(1)
                        EVT_END_LOOP
                    EVT_END_CASE_GROUP
                    EVT_CASE_OR_EQ(N(PHASE_BEGIN))
                    EVT_CASE_OR_EQ(N(PHASE_SUMMONED_BITS))
                        EVT_SETF(LVar0, EVT_FLOAT(0.4))
                        EVT_LOOP(30)
                            EVT_SETF(LVar1, EVT_FLOAT(1.0))
                            EVT_SUBF(LVar1, LVar0)
                            EVT_DIVF(LVar1, EVT_FLOAT(6.0))
                            EVT_ADDF(LVar0, LVar1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, 1, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, 1, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, 1, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_WAIT(1)
                        EVT_END_LOOP
                    EVT_END_CASE_GROUP
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim09)
            EVT_EXEC_WAIT(DoRecover)
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim0E)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 0, 5)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_SWAP_PARTNER)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 20)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
        EVT_BITWISE_OR_CONST(LVar0, N(FLAG_LOW_HP))
        EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_END_IF
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MUL(LVar0, 100)
    EVT_DIV(LVar0, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(25)
            EVT_CALL(RandInt, 99, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_IF_LE(LVar0, 100)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LVar0)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LocalFlag(0), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(40)
            EVT_CALL(RandInt, 99, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_IF_LE(LVar0, 30)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LVar0)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LocalFlag(0), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(55)
            EVT_CALL(RandInt, 99, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_IF_LE(LVar0, 10)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LVar0)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LocalFlag(0), 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LVar0)
        EVT_EXEC_WAIT(N(Heal))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(N(PHASE_BEGIN))
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_EXEC_WAIT(N(SummonCrystalBits))
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_BITS))
            EVT_ELSE
                EVT_EXEC_WAIT(N(NormalAttack))
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_NEED_BITS))
            EVT_END_IF
        EVT_CASE_EQ(N(PHASE_NEED_BITS))
            EVT_EXEC_WAIT(N(SummonCrystalBits))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_BITS))
        EVT_CASE_EQ(N(PHASE_SUMMONED_BITS))
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_FROZEN)
                    EVT_EXEC_WAIT(N(AttackIcyBreath))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(AttackIceBolt))
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(NormalAttack))
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_AFTER_ATTACK))
        EVT_CASE_EQ(N(PHASE_AFTER_ATTACK))
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_IF_GT(LVar0, 35)
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_IF_NOT_FLAG(LVar0, N(FLAG_SUMMONED_CLONES_ONCE))
                    EVT_EXEC_WAIT(N(SummonCrystalBits))
                    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_BITS))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_NOT_FLAG(LVar0, N(FLAG_FORBID_SECOND_ATTACK))
                EVT_EXEC_WAIT(N(AttackIceBolt))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_BITWISE_OR_CONST(LVar0, N(FLAG_FORBID_SECOND_ATTACK))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_ELSE
                EVT_EXEC_WAIT(N(MakeIllusions))
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_CLONES))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_BITWISE_OR_CONST(LVar0, N(FLAG_SUMMONED_CLONES_ONCE))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_END_IF
        EVT_CASE_EQ(N(PHASE_SUMMONED_CLONES))
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_FROZEN)
                    EVT_EXEC_WAIT(N(AttackIcyBreath))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(AttackIceBolt))
                EVT_END_IF
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_AFTER_ATTACK))
            EVT_ELSE
                EVT_EXEC_WAIT(N(AttackIcyBreathWithClones))
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_ATTACKED_WITH_CLONES))
            EVT_END_IF
        EVT_CASE_EQ(N(PHASE_ATTACKED_WITH_CLONES))
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
            EVT_IF_GT(LVar0, 1)
                EVT_EXEC_WAIT(N(AttackIcyBreathWithClones))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(MakeIllusions))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_CLONES))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_OR_CONST(LVar0, N(FLAG_SUMMONED_CLONES_ONCE))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(AttackIcyBreath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim13)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 8)
        EVT_ADD(LVar2, -2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35D)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -15)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(0.5), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
            EVT_ELSE
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(0.2), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
            EVT_END_IF
            EVT_CALL(N(StartRumbleWithParams), 70, 60)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 30, EVT_FLOAT(0.3))
            EVT_END_THREAD
            EVT_WAIT(30)
            EVT_CALL(StopSound, SOUND_35D)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
    EVT_END_IF
    EVT_CALL(N(StartRumbleWithParams), 70, 100)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 50, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(StopSound, SOUND_35D)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(AttackIceBolt) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim13)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 8)
        EVT_ADD(LVar2, -2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar0, -15)
                EVT_ADD(LVar1, 20)
            EVT_ELSE
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
            EVT_END_IF
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 20, 0)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_THREAD
                EVT_SUB(LVar3, LVar0)
                EVT_SUB(LVar4, LVar1)
                EVT_SUB(LVar5, LVar2)
                EVT_DIV(LVar3, 10)
                EVT_DIV(LVar4, 10)
                EVT_DIV(LVar5, 10)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, LVar3)
                    EVT_ADD(LVar1, LVar4)
                    EVT_ADD(LVar2, LVar5)
                    EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 20, -20, EVT_FLOAT(1.0), 5, 30, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT(3)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 20, 0)
            EVT_CALL(func_802182E4_660A34, LVarF)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
    EVT_ELSE
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_SUB(LVar3, LVar0)
        EVT_SUB(LVar4, LVar1)
        EVT_SUB(LVar5, LVar2)
        EVT_DIV(LVar3, 10)
        EVT_DIV(LVar4, 10)
        EVT_DIV(LVar5, 10)
        EVT_LOOP(10)
            EVT_ADD(LVar0, LVar3)
            EVT_ADD(LVar1, LVar4)
            EVT_ADD(LVar2, LVar5)
            EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 20, -20, EVT_FLOAT(1.0), 5, 30, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 20, 0)
    EVT_CALL(func_802182E4_660A34, LVarF)
    EVT_WAIT(7)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0x00000002 | STATUS_FLAG_4 | STATUS_FLAG_8 | 0x00000010 | STATUS_FLAG_20 | STATUS_FLAG_40 | 0x00000080 | STATUS_FLAG_200 | STATUS_FLAG_FROZEN, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_COLD_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 30, 0)
            EVT_CALL(func_80218344_660A94, LVarF)
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(clone_statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 40,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 40,
    STATUS_SHRINK, 0,
    STATUS_STOP, 50,
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

EvtScript N(clone_script) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(clone_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(clone_script)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(clone_script)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(clone_script)))
    EVT_RETURN
    EVT_END
};

ActorBlueprint N(clone) = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_CLONE,
    .level = 0,
    .maxHP = 70,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(clone_init),
    .statusTable = N(clone_statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 56, 56 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 40 },
    .statusMessageOffset = { 15, 40 },
};

Vec3i N(pos_crystal_clone) = { NPC_DISPOSE_LOCATION };

Formation N(clone_formation) = {
    { .actor = &N(clone), .home = { .vec = &N(pos_crystal_clone) }, .priority = 0 },
};

EvtScript N(MakeIllusions) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarA)
    EVT_CALL(SummonEnemy, EVT_PTR(N(clone_formation)), 0)
    EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
    EVT_CALL(SetPartEventBits, LVar0, 1, ACTOR_EVENT_FLAG_ILLUSORY, TRUE)
    EVT_CALL(SetEnemyHP, LVar0, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVar0)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVar0)
    EVT_CALL(SummonEnemy, EVT_PTR(N(clone_formation)), 0)
    EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
    EVT_CALL(SetPartEventBits, LVar0, 1, ACTOR_EVENT_FLAG_ILLUSORY, TRUE)
    EVT_CALL(SetEnemyHP, LVar0, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVar0)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_IF_FLAG(LVar0, N(FLAG_LOW_HP))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1D)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E7)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        EVT_CALL(MakeLerp, 0, 41, 30, EASING_SIN_OUT)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LVar0, LVar8)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar7, LVar0, LVar9)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
        EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_FLYING, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
        EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_FLYING, TRUE)
        EVT_EXEC_GET_TID(N(FlyWithClones), LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLY_THREAD_ID), LVar0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarA)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarA)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim09)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_CrystalKing_Anim00)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_CrystalKing_Anim09)
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_CrystalKing_Anim00)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_CrystalKing_Anim09)
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2DF)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar0)
    EVT_CALL(EnableActorBlur, LVar0, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar0)
    EVT_CALL(EnableActorBlur, LVar0, 1)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 0x00001AB8, 210, EASING_COS_IN_OUT)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar2)
        EVT_CALL(SetActorYaw, LVar2, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar2)
        EVT_CALL(SetActorYaw, LVar2, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 255, 128, 30, EASING_COS_IN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVar2)
    EVT_CALL(SetPartAlpha, LVar2, 1, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVar2)
    EVT_CALL(SetPartAlpha, LVar2, 1, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_OR_CONST(LVar0, N(FLAG_HAS_CLONES))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_WAIT(60)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_MOD(LVar0, 3)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVarA, ACTOR_SELF)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarB)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarC)
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarA)
            EVT_SET(LVarB, ACTOR_SELF)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarC)
        EVT_CASE_EQ(2)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarA)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarB)
            EVT_SET(LVarC, ACTOR_SELF)
    EVT_END_SWITCH
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, FALSE)
    EVT_CALL(SetActorFlagBits, LVarB, ACTOR_FLAG_NO_SHADOW, FALSE)
    EVT_CALL(SetActorFlagBits, LVarC, ACTOR_FLAG_NO_SHADOW, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 150)
    EVT_THREAD
        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        EVT_SET(LVar3, 18)
        EVT_SET(LVar5, 5)
        EVT_SUB(LVar3, LVar0)
        EVT_SUB(LVar5, LVar2)
        EVT_DIVF(LVar3, EVT_FLOAT(60.0))
        EVT_DIVF(LVar5, EVT_FLOAT(60.0))
        EVT_LOOP(60)
            EVT_ADDF(LVar0, LVar3)
            EVT_ADDF(LVar2, LVar5)
            EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_SET(LVar3, 70)
        EVT_SET(LVar5, 5)
        EVT_SUB(LVar3, LVar0)
        EVT_SUB(LVar5, LVar2)
        EVT_DIVF(LVar3, EVT_FLOAT(60.0))
        EVT_DIVF(LVar5, EVT_FLOAT(60.0))
        EVT_LOOP(60)
            EVT_ADDF(LVar0, LVar3)
            EVT_ADDF(LVar2, LVar5)
            EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, LVarC, LVar0, LVar1, LVar2)
        EVT_SET(LVar3, 122)
        EVT_SET(LVar5, 5)
        EVT_SUB(LVar3, LVar0)
        EVT_SUB(LVar5, LVar2)
        EVT_DIVF(LVar3, EVT_FLOAT(60.0))
        EVT_DIVF(LVar5, EVT_FLOAT(60.0))
        EVT_LOOP(60)
            EVT_ADDF(LVar0, LVar3)
            EVT_ADDF(LVar2, LVar5)
            EVT_CALL(SetActorPos, LVarC, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(90)
    EVT_WAIT(30)
    EVT_WAIT(30)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarA)
    EVT_CALL(EnableActorBlur, LVarA, 0)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarA)
    EVT_CALL(EnableActorBlur, LVarA, 0)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_IGNORE_IMMUNE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_WAIT(20)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Formation N(formation_bit_1) = {
    { .actor = &b_area_pra2_crystal_bit_1, .home = { .vec = &N(pos_crystal_clone) }, .priority = 0 },
};

Formation N(formation_bit_2) = {
    { .actor = &b_area_pra2_crystal_bit_2, .home = { .vec = &N(pos_crystal_clone) }, .priority = 0 },
};

Formation N(formation_bit_3) = {
    { .actor = &b_area_pra2_crystal_bit_3, .home = { .vec = &N(pos_crystal_clone) }, .priority = 0 },
};

s32 N(array_1)[16] = { };

s32 N(array_2)[16] = { };

s32 N(array_3)[16] = { };

EvtScript N(CrystalBitAppear) = {
    EVT_USE_ARRAY(LVar4)
    EVT_SET(ArrayVar(0), LVar0)
    EVT_SETF(ArrayVar(1), LVar1)
    EVT_SETF(ArrayVar(2), LVar2)
    EVT_SETF(ArrayVar(3), LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUBF(LVar2, LVarB)
    EVT_DIVF(LVar2, EVT_FLOAT(120.0))
    EVT_SETF(ArrayVar(4), LVar2)
    EVT_SETF(LVar6, LVarB)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(GetDist2D, LVarD, LVarA, LVarC, LVar1, LVar3)
    EVT_DIVF(LVarD, EVT_FLOAT(120.0))
    EVT_SETF(ArrayVar(5), LVarD)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(func_802183A4_660AF4, ArrayVar(6), LVarA, LVarC, LVar1, LVar3)
    EVT_CALL(SetPartAlpha, LVar0, 1, 0)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(EnableActorBlur, LVar0, 1)
        EVT_SET(LVar9, LVar0)
        EVT_CALL(MakeLerp, 0, 255, 90, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartAlpha, LVar9, 1, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_CALL(MakeLerp, 0, 0x00000B40, 120, EASING_SIN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_ADDF(LVar5, ArrayVar(5))
    EVT_ADDF(LVar0, ArrayVar(6))
    EVT_CALL(AddVectorPolar, LVar2, LVar4, LVar5, LVar0)
    EVT_ADDF(LVar6, ArrayVar(4))
    EVT_CALL(SetActorPos, ArrayVar(0), LVar2, LVar6, LVar4)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableActorBlur, ArrayVar(0), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(SummonCrystalBits) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1E)
    EVT_WAIT(20)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_bit_1)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_bit_2)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_bit_3)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
        EVT_CALL(SetPartScale, LVar0, 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
        EVT_CALL(SetPartScale, LVar0, 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
        EVT_CALL(SetPartScale, LVar0, 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1F)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2DE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
    EVT_SETF(LVar1, EVT_FLOAT(42.0))
    EVT_SETF(LVar2, EVT_FLOAT(85.0))
    EVT_SETF(LVar3, EVT_FLOAT(-10.0))
    EVT_SET(LVar4, N(array_3))
    EVT_EXEC(N(CrystalBitAppear))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
    EVT_SETF(LVar1, EVT_FLOAT(112.0))
    EVT_SETF(LVar2, EVT_FLOAT(52.0))
    EVT_SETF(LVar3, EVT_FLOAT(-5.0))
    EVT_SET(LVar4, N(array_2))
    EVT_EXEC(N(CrystalBitAppear))
    EVT_WAIT(24)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
    EVT_SETF(LVar1, EVT_FLOAT(10.0))
    EVT_SETF(LVar2, EVT_FLOAT(35.0))
    EVT_SETF(LVar3, EVT_FLOAT(-5.0))
    EVT_SET(LVar4, N(array_1))
    EVT_EXEC(N(CrystalBitAppear))
    EVT_WAIT(130)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
    EVT_CALL(ForceHomePos, LVar0, 10, 35, -5)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
    EVT_CALL(ForceHomePos, LVar0, 112, 52, -5)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
    EVT_CALL(ForceHomePos, LVar0, 42, 85, -10)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(AttackIcyBreathWithClones) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarA)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarB)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(UseIdleAnimation, LVarB, FALSE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_OR_CONST(LVar0, N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 35)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetBattleCamTarget, 70, 41, 5)
    EVT_ELSE
        EVT_CALL(SetBattleCamTarget, 70, 0, 5)
    EVT_END_IF
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim13)
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_CrystalKing_Anim13)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_CrystalKing_Anim13)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(PlaySoundAtActor, LVarA, SOUND_206D)
    EVT_CALL(PlaySoundAtActor, LVarB, SOUND_206D)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar9)
    EVT_IF_NOT_FLAG(LVar9, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 8)
        EVT_ADD(LVar2, -2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 8)
        EVT_ADD(LVar2, -2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 8)
        EVT_ADD(LVar2, -2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_CrystalKing_Anim1C)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35D)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVar5, LVar0)
            EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
                EVT_SETF(LVar3, EVT_FLOAT(195.0))
            EVT_ELSE
                EVT_SETF(LVar3, EVT_FLOAT(180.0))
            EVT_END_IF
            EVT_CALL(N(StartRumbleWithParams), 100, 60)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 30, EVT_FLOAT(0.3))
            EVT_END_THREAD
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar9)
            EVT_IF_NOT_FLAG(LVar9, STATUS_FLAG_SHRINK)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -15)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
                EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -15)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
                EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -15)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
            EVT_ELSE
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
                EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
                EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0)
                EVT_CALL(func_80218280_6609D0, LVarF)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(StopSound, SOUND_35D)
            EVT_IF_EQ(LVar5, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_NOT_IDLE))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_CALL(UseIdleAnimation, LVarA, TRUE)
            EVT_CALL(UseIdleAnimation, LVarB, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_SETF(LVar3, EVT_FLOAT(195.0))
    EVT_ELSE
        EVT_SETF(LVar3, EVT_FLOAT(180.0))
    EVT_END_IF
    EVT_CALL(N(StartRumbleWithParams), 100, 120)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 60, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar9)
    EVT_IF_NOT_FLAG(LVar9, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(func_80218280_6609D0, LVarF)
    EVT_END_IF
    EVT_WAIT(60)
    EVT_CALL(StopSound, SOUND_35D)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_CrystalKing_Anim15)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_CrystalKing_Anim15)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseIdleAnimation, LVarA, TRUE)
    EVT_CALL(UseIdleAnimation, LVarB, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(MoveBitToTarget) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar9)
    EVT_IF_NOT_FLAG(LVar9, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar3, -15)
        EVT_ADD(LVar4, 20)
    EVT_ELSE
        EVT_ADD(LVar3, -6)
        EVT_ADD(LVar4, 8)
    EVT_END_IF
    EVT_CALL(func_8021848C_660BDC, LVarB, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(LoadPath, 30, LVarB, 3, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetActorPos, LVarA, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(RemoveCrystalBit) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D9)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -150, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_SUB(LVar0, LVar3)
        EVT_SUB(LVar1, LVar4)
        EVT_SUB(LVar2, LVar5)
        EVT_DIV(LVar0, 10)
        EVT_DIV(LVar1, 10)
        EVT_DIV(LVar2, 10)
        EVT_LOOP(10)
            EVT_ADD(LVar3, LVar0)
            EVT_ADD(LVar4, LVar1)
            EVT_ADD(LVar5, LVar2)
            EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, LVar3, LVar4, LVar5, 20, -20, EVT_FLOAT(1.0), 5, 30, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LVarA, EVT_FLOAT(16.0))
    EVT_CALL(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, LVarA, 0, 0, EASING_LINEAR)
    EVT_CALL(GetActorVar, LVarA, 0, LVarF)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveActor, LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(AttackWithCrystalBit) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D9)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_SUB(LVar0, LVar3)
        EVT_SUB(LVar1, LVar4)
        EVT_SUB(LVar2, LVar5)
        EVT_DIV(LVar0, 10)
        EVT_DIV(LVar1, 10)
        EVT_DIV(LVar2, 10)
        EVT_LOOP(10)
            EVT_ADD(LVar3, LVar0)
            EVT_ADD(LVar4, LVar1)
            EVT_ADD(LVar5, LVar2)
            EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, LVar3, LVar4, LVar5, 20, -20, EVT_FLOAT(1.0), 5, 30, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LVarA, EVT_FLOAT(16.0))
    EVT_CALL(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, LVarA, 0, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, 0)
    EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, LVarA, LVar1, LVar2, LVar3)
    EVT_SUB(LVar1, 100)
    EVT_CALL(RandInt, 50, LVar4)
    EVT_ADD(LVar2, LVar4)
    EVT_CALL(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
    EVT_CALL(JumpToGoal, LVarA, 20, FALSE, TRUE, FALSE)
    EVT_CALL(GetActorVar, LVarA, 0, LVarF)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveActor, LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(NormalAttack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(20)
    EVT_CALL(N(StartRumbleWithParams), 70, 60)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 30, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3AF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_SET(LVar1, &N(paths)[0])
        EVT_EXEC_GET_TID(N(MoveBitToTarget), LVarA)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_SET(LVar1, &N(paths)[1])
        EVT_EXEC_GET_TID(N(MoveBitToTarget), LVarA)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_SET(LVar1, &N(paths)[2])
        EVT_EXEC_GET_TID(N(MoveBitToTarget), LVarA)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_IS_THREAD_RUNNING(LVarA, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim13)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVar9, LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
                EVT_EXEC_GET_TID(N(RemoveCrystalBit), LVarA)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
                EVT_WAIT(6)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
                EVT_EXEC_GET_TID(N(RemoveCrystalBit), LVarA)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
                EVT_WAIT(6)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
                EVT_EXEC_GET_TID(N(RemoveCrystalBit), LVarA)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
                EVT_WAIT(6)
            EVT_END_IF
            EVT_LABEL(1)
            EVT_IS_THREAD_RUNNING(LVarA, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_WAIT(1)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_IF_EQ(LVar9, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
        EVT_EXEC_GET_TID(N(AttackWithCrystalBit), LVarA)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
        EVT_WAIT(6)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
        EVT_EXEC_GET_TID(N(AttackWithCrystalBit), LVarA)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
        EVT_WAIT(6)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1C)
        EVT_EXEC_GET_TID(N(AttackWithCrystalBit), LVarA)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim15)
        EVT_WAIT(6)
    EVT_END_IF
    EVT_LABEL(4)
    EVT_IS_THREAD_RUNNING(LVarA, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_WAIT(1)
        EVT_GOTO(4)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(Heal) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
        EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LVarA)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LVarB)
            EVT_CALL(ActorExists, LVarA, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(UseIdleAnimation, LVarA, FALSE)
        EVT_CALL(EnableIdleScript, LVarA, 0)
        EVT_CALL(UseIdleAnimation, LVarB, FALSE)
        EVT_CALL(EnableIdleScript, LVarB, 0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 50)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetBattleCamTarget, 70, 41, 5)
    EVT_ELSE
        EVT_CALL(SetBattleCamTarget, 70, 0, 5)
    EVT_END_IF
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim1D)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_CrystalKing_Anim1D)
        EVT_CALL(SetAnimation, LVarB, 1, ANIM_CrystalKing_Anim1D)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
    EVT_END_THREAD
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_206D)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_214)
            EVT_WAIT(30)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_25C)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, LVarB, SOUND_206D)
            EVT_CALL(PlaySoundAtActor, LVarB, SOUND_214)
            EVT_WAIT(30)
            EVT_CALL(PlaySoundAtActor, LVarB, SOUND_25C)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, ACTOR_SELF, 20, FALSE)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, ACTOR_SELF, 20, TRUE)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, LVarA, 20, TRUE)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, LVarB, 20, TRUE)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_CrystalKing_Anim09)
        EVT_CALL(SetAnimation, LVarB, 1, ANIM_CrystalKing_Anim09)
    EVT_END_IF
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(EnableIdleScript, LVarA, 1)
        EVT_CALL(UseIdleAnimation, LVarA, TRUE)
        EVT_CALL(EnableIdleScript, LVarA, 1)
        EVT_CALL(UseIdleAnimation, LVarA, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
