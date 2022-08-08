#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/crystal_king.h"

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

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_crystal_king_Palette_00_Anim_9,
    STATUS_SLEEP, NPC_ANIM_crystal_king_Palette_00_Anim_1B,
    STATUS_DIZZY, NPC_ANIM_crystal_king_Palette_00_Anim_1A,
    STATUS_PARALYZE, NPC_ANIM_crystal_king_Palette_00_Anim_0,
    STATUS_STOP, NPC_ANIM_crystal_king_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_FIRE, 0,
    ELEMENT_ICE, 99,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
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
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -22,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CRYSTAL_KING,
    .level = 85,
    .maxHP = 70,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
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
#include "common/UnkFloatFunc.inc.c"

ApiStatus GetActorPartOpacity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    evt_set_variable(script, *args++, get_actor_part(get_actor(actorID), partIndex)->opacity);

    return ApiStatus_DONE2;
}

ApiStatus func_80218280_6609D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args);

    effect->data.huffPuffBreath->unk_18 = 0xF8;
    effect->data.huffPuffBreath->unk_1C = 0xF8;
    effect->data.huffPuffBreath->unk_20 = 0xFF;
    effect->data.huffPuffBreath->unk_28 = 0x80;
    effect->data.huffPuffBreath->unk_2C = 0xE0;
    ((HuffPuffBreathFXData*)effect->data.huffPuffBreath)->unk_30 = 0xFF;
    return ApiStatus_DONE2;
}

ApiStatus func_802182E4_660A34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args);

    effect->data.lightningBolt->unk_30 = 0xFF;
    effect->data.lightningBolt->unk_34 = 0xFF;
    effect->data.lightningBolt->unk_38 = 0xFF;
    effect->data.lightningBolt->unk_40 = 0xC8;
    effect->data.lightningBolt->unk_44 = 0xF0;
    effect->data.lightningBolt->unk_48 = 0xFF;
    return ApiStatus_DONE2;
}

ApiStatus func_80218344_660A94(Evt* script, s32 isInitialCall) {
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

ApiStatus func_802183A4_660AF4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;
    f32 startX = evt_get_variable(script, *args++);
    f32 startZ = evt_get_variable(script, *args++);
    f32 endX = evt_get_variable(script, *args++);
    f32 endZ = evt_get_variable(script, *args++);

    evt_set_variable(script, arg0, atan2(startX, startZ, endX, endZ));
    return ApiStatus_DONE2;
}

ApiStatus func_8021848C_660BDC(Evt* script, s32 isInitialCall) {
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
    EVT_SET(LW(15), 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_IF_FLAG(LW(0), N(FLAG_HAS_CLONES))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(1))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(2))
        EVT_CALL(ActorExists, LW(1), LW(3))
        EVT_IF_EQ(LW(3), TRUE)
            EVT_CALL(N(UnkFloatFunc), LW(15), LW(4), EVT_FLOAT(128.0), EVT_FLOAT(254.0), 20, 0, 0)
            EVT_SET(LW(4), LW(4))
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(4))
            EVT_CALL(SetPartAlpha, LW(1), 1, LW(4))
            EVT_CALL(SetPartAlpha, LW(2), 1, LW(4))
            EVT_ADD(LW(15), 1)
            EVT_IF_GT(LW(15), 40)
                EVT_SET(LW(15), 0)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_BITWISE_AND_CONST(LW(0), ~N(FLAG_HAS_CLONES))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LW(15), 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(FlyWithClones) = {
    EVT_SET(LW(10), 0)
    EVT_SET(LW(11), 0)
    EVT_SET(LW(12), 0)
    EVT_SET(LW(13), 0)
    EVT_SET(LW(14), 0)
    EVT_SET(LW(15), 0)
    EVT_LABEL(1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_IF_NOT_FLAG(LW(0), N(FLAG_NOT_IDLE))
        EVT_SET(LW(0), ACTOR_SELF)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(1))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(2))
        EVT_CALL(GetActorPos, LW(0), LW(3), LW(4), LW(5))
        EVT_CALL(GetActorPos, LW(1), LW(4), LW(5), LW(6))
        EVT_IF_GT(LW(3), LW(4))
            EVT_SET(LW(7), LW(0))
            EVT_SET(LW(0), LW(1))
            EVT_SET(LW(1), LW(7))
        EVT_END_IF
        EVT_CALL(GetActorPos, LW(0), LW(3), LW(4), LW(5))
        EVT_CALL(GetActorPos, LW(2), LW(4), LW(5), LW(6))
        EVT_IF_GT(LW(3), LW(4))
            EVT_SET(LW(7), LW(0))
            EVT_SET(LW(0), LW(2))
            EVT_SET(LW(2), LW(7))
        EVT_END_IF
        EVT_CALL(GetActorPos, LW(1), LW(3), LW(4), LW(5))
        EVT_CALL(GetActorPos, LW(2), LW(4), LW(5), LW(6))
        EVT_IF_GT(LW(3), LW(4))
            EVT_SET(LW(7), LW(1))
            EVT_SET(LW(1), LW(2))
            EVT_SET(LW(2), LW(7))
        EVT_END_IF
        EVT_CALL(GetActorPos, LW(0), LW(3), LW(4), LW(5))
        EVT_SET(LW(4), 41)
        EVT_ADD(LW(4), LW(10))
        EVT_CALL(SetActorPos, LW(0), LW(3), LW(4), LW(5))
        EVT_CALL(GetActorPos, LW(1), LW(3), LW(4), LW(5))
        EVT_SET(LW(4), 41)
        EVT_ADD(LW(4), LW(12))
        EVT_CALL(SetActorPos, LW(1), LW(3), LW(4), LW(5))
        EVT_CALL(GetActorPos, LW(2), LW(3), LW(4), LW(5))
        EVT_SET(LW(4), 41)
        EVT_ADD(LW(4), LW(14))
        EVT_CALL(SetActorPos, LW(2), LW(3), LW(4), LW(5))
        EVT_CALL(N(UnkFloatFunc), LW(15), LW(0), EVT_FLOAT(0.0), EVT_FLOAT(5.0), 30, 0, 0)
        EVT_SET(LW(10), LW(11))
        EVT_SET(LW(11), LW(12))
        EVT_SET(LW(12), LW(13))
        EVT_SET(LW(13), LW(14))
        EVT_SET(LW(14), LW(0))
        EVT_ADD(LW(15), 1)
        EVT_IF_GT(LW(15), 60)
            EVT_SET(LW(15), 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(RemoveClone) = {
    EVT_CALL(EnableActorBlur, LW(9), 1)
    EVT_CALL(SetActorFlagBits, LW(9), ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_THREAD
        EVT_CALL(GetActorPartOpacity, LW(9), 1, LW(3))
        EVT_CALL(MakeLerp, LW(3), 0, 20, 1)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartAlpha, LW(9), 1, LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 200, 20, 1)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(8))
        EVT_IF_FLAG(LW(8), STATUS_FLAG_SHRINK)
            EVT_MULF(LW(0), EVT_FLOAT(0.4))
        EVT_END_IF
        EVT_DIVF(LW(0), EVT_FLOAT(100.0))
        EVT_CALL(SetPartScale, LW(9), 1, LW(0), LW(0), LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetActorRotationOffset, LW(9), 0, 28, 0)
    EVT_ELSE
        EVT_CALL(SetActorRotationOffset, LW(9), 0, 10, 0)
    EVT_END_IF
    EVT_CALL(MakeLerp, 3600, 0, 25, 1)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetActorRotation, LW(9), 0, 0, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(RemoveActor, LW(9))
    EVT_RETURN
    EVT_END
};

EvtScript N(OnHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
        EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(N(PHASE_BEGIN))
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_BITS))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
                EVT_CALL(ActorExists, LW(0), LW(1))
                EVT_IF_EQ(LW(1), TRUE)
                    EVT_CALL(func_80269EAC, 0)
                    EVT_CALL(DispatchEvent, LW(0), EVENT_DEATH)
                EVT_END_IF
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
                EVT_CALL(ActorExists, LW(0), LW(1))
                EVT_IF_EQ(LW(1), TRUE)
                    EVT_CALL(func_80269EAC, 0)
                    EVT_CALL(DispatchEvent, LW(0), EVENT_DEATH)
                EVT_END_IF
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
                EVT_CALL(ActorExists, LW(0), LW(1))
                EVT_IF_EQ(LW(1), TRUE)
                    EVT_CALL(func_80269EAC, 0)
                    EVT_CALL(DispatchEvent, LW(0), EVENT_DEATH)
                EVT_END_IF
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetLastElement, LW(0))
    EVT_IF_FLAG(LW(0), DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LW(0))
        EVT_IF_FLAG(LW(0), BS_FLAGS1_100)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(9))
    EVT_CALL(ActorExists, LW(9), LW(10))
    EVT_IF_EQ(LW(10), TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(9))
        EVT_EXEC(N(RemoveClone))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(9))
        EVT_EXEC_GET_TID(N(RemoveClone), LW(0))
        EVT_LABEL(1)
        EVT_IS_THREAD_RUNNING(LW(0), LW(1))
        EVT_IF_EQ(LW(1), TRUE)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_IF_NE(LW(1), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLY_THREAD_ID), LW(10))
        EVT_KILL_THREAD(LW(10))
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E3)
        EVT_SET(LW(1), 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 150, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.7))
        EVT_END_THREAD
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_E)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 0, 5)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_BITWISE_AND_CONST(LW(0), ~N(FLAG_IGNORE_IMMUNE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(OnDeath) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
        EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(N(PHASE_BEGIN))
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_BITS))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_CALL(func_80269EAC, 0)
                EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_NO_DMG_APPLY, 1)
                EVT_CALL(DispatchEvent, LW(0), EVENT_DEATH)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_CALL(func_80269EAC, 0)
                EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_NO_DMG_APPLY, 1)
                EVT_CALL(DispatchEvent, LW(0), EVENT_DEATH)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_CALL(func_80269EAC, 0)
                EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_NO_DMG_APPLY, 1)
                EVT_CALL(DispatchEvent, LW(0), EVENT_DEATH)
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetLastElement, LW(0))
    EVT_IF_FLAG(LW(0), DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LW(0))
        EVT_IF_FLAG(LW(0), BS_FLAGS1_100)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLY_THREAD_ID), LW(10))
    EVT_IS_THREAD_RUNNING(LW(10), LW(0))
    EVT_IF_EQ(LW(0), BS_FLAGS1_1)
        EVT_KILL_THREAD(LW(10))
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(9))
    EVT_CALL(ActorExists, LW(9), LW(10))
    EVT_IF_EQ(LW(10), TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(9))
        EVT_EXEC(N(RemoveClone))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(9))
        EVT_EXEC_GET_TID(N(RemoveClone), LW(0))
        EVT_LABEL(1)
        EVT_IS_THREAD_RUNNING(LW(0), LW(1))
        EVT_IF_EQ(LW(1), TRUE)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_BITWISE_OR_CONST(LW(0), N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_BITWISE_OR_CONST(LW(0), N(FLAG_IGNORE_IMMUNE))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(OnHit))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_20)
                    EVT_SET_CONST(LW(2), NPC_ANIM_crystal_king_Palette_00_Anim_21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_20)
                    EVT_SET_CONST(LW(2), NPC_ANIM_crystal_king_Palette_00_Anim_21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_20)
            EVT_SET_CONST(LW(2), NPC_ANIM_crystal_king_Palette_00_Anim_21)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_19)
            EVT_EXEC_WAIT(N(OnHit))
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_IF_FLAG(LW(0), N(FLAG_IGNORE_IMMUNE))
                EVT_EXEC_WAIT(N(OnHit))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_EXEC_WAIT(N(OnHit))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
                    EVT_EXEC_WAIT(DoNormalHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
                    EVT_EXEC_WAIT(DoNormalHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_20)
                    EVT_SET_CONST(LW(2), NPC_ANIM_crystal_king_Palette_00_Anim_21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LW(0))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_20)
                    EVT_SET_CONST(LW(2), NPC_ANIM_crystal_king_Palette_00_Anim_21)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_20)
            EVT_SET_CONST(LW(2), NPC_ANIM_crystal_king_Palette_00_Anim_21)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_21)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LW(0))
                EVT_SWITCH(LW(0))
                    EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
                    EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
                        EVT_SETF(LW(0), EVT_FLOAT(0.4))
                        EVT_LOOP(30)
                            EVT_SETF(LW(1), EVT_FLOAT(1.0))
                            EVT_SUBF(LW(1), LW(0))
                            EVT_DIVF(LW(1), EVT_FLOAT(6.0))
                            EVT_ADDF(LW(0), LW(1))
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(10))
                            EVT_CALL(ActorExists, LW(10), LW(11))
                            EVT_IF_EQ(LW(11), TRUE)
                                EVT_CALL(SetPartScale, LW(10), 1, LW(0), LW(0), LW(0))
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(10))
                            EVT_CALL(ActorExists, LW(10), LW(11))
                            EVT_IF_EQ(LW(11), TRUE)
                                EVT_CALL(SetPartScale, LW(10), 1, LW(0), LW(0), LW(0))
                            EVT_END_IF
                            EVT_WAIT_FRAMES(1)
                        EVT_END_LOOP
                    EVT_END_CASE_GROUP
                    EVT_CASE_OR_EQ(N(PHASE_BEGIN))
                    EVT_CASE_OR_EQ(N(PHASE_SUMMONED_BITS))
                        EVT_SETF(LW(0), EVT_FLOAT(0.4))
                        EVT_LOOP(30)
                            EVT_SETF(LW(1), EVT_FLOAT(1.0))
                            EVT_SUBF(LW(1), LW(0))
                            EVT_DIVF(LW(1), EVT_FLOAT(6.0))
                            EVT_ADDF(LW(0), LW(1))
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(10))
                            EVT_CALL(ActorExists, LW(10), LW(11))
                            EVT_IF_EQ(LW(11), TRUE)
                                EVT_CALL(SetPartScale, LW(10), 1, LW(0), LW(0), LW(0))
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(10))
                            EVT_CALL(ActorExists, LW(10), LW(11))
                            EVT_IF_EQ(LW(11), TRUE)
                                EVT_CALL(SetPartScale, LW(10), 1, LW(0), LW(0), LW(0))
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(10))
                            EVT_CALL(ActorExists, LW(10), LW(11))
                            EVT_IF_EQ(LW(11), TRUE)
                                EVT_CALL(SetPartScale, LW(10), 1, LW(0), LW(0), LW(0))
                            EVT_END_IF
                            EVT_WAIT_FRAMES(1)
                        EVT_END_LOOP
                    EVT_END_CASE_GROUP
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoRecover)
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, 0x8002, LW(0))
            EVT_IF_LE(LW(0), 1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_E)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 0, 5)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_SWAP_PARTNER)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 20)
            EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_BITWISE_AND_CONST(LW(0), ~N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorHP, ACTOR_SELF, LW(0))
    EVT_IF_LE(LW(0), 20)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
        EVT_BITWISE_OR_CONST(LW(0), N(FLAG_LOW_HP))
        EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_END_IF
    EVT_SET(LF(0), 0)
    EVT_CALL(GetActorHP, ACTOR_SELF, LW(0))
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LW(1))
    EVT_MUL(LW(0), 100)
    EVT_DIV(LW(0), LW(1))
    EVT_SWITCH(LW(0))
        EVT_CASE_LT(25)
            EVT_CALL(RandInt, 99, LW(0))
            EVT_ADD(LW(0), 1)
            EVT_IF_LE(LW(0), 100)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LW(0))
                EVT_IF_LT(LW(0), 2)
                    EVT_SET(LF(0), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(40)
            EVT_CALL(RandInt, 99, LW(0))
            EVT_ADD(LW(0), 1)
            EVT_IF_LE(LW(0), 30)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LW(0))
                EVT_IF_LT(LW(0), 2)
                    EVT_SET(LF(0), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(55)
            EVT_CALL(RandInt, 99, LW(0))
            EVT_ADD(LW(0), 1)
            EVT_IF_LE(LW(0), 10)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LW(0))
                EVT_IF_LT(LW(0), 2)
                    EVT_SET(LF(0), 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_EQ(LF(0), 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LW(0))
        EVT_ADD(LW(0), 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_HEAL_COUNTER), LW(0))
        EVT_EXEC_WAIT(N(Heal))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(N(PHASE_BEGIN))
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, 0x8002, LW(0))
            EVT_IF_LE(LW(0), 1)
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
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, 0x8002, LW(0))
            EVT_IF_LE(LW(0), 1)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
                EVT_IF_FLAG(LW(0), STATUS_FLAG_FROZEN)
                    EVT_EXEC_WAIT(N(AttackIcyBreath))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(AttackIceBolt))
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(NormalAttack))
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_AFTER_ATTACK))
        EVT_CASE_EQ(N(PHASE_AFTER_ATTACK))
            EVT_CALL(GetActorHP, ACTOR_SELF, LW(0))
            EVT_IF_GT(LW(0), 35)
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
                EVT_IF_NOT_FLAG(LW(0), N(FLAG_SUMMONED_CLONES_ONCE))
                    EVT_EXEC_WAIT(N(SummonCrystalBits))
                    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_BITS))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_IF_NOT_FLAG(LW(0), N(FLAG_FORBID_SECOND_ATTACK))
                EVT_EXEC_WAIT(N(AttackIceBolt))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
                EVT_BITWISE_OR_CONST(LW(0), N(FLAG_FORBID_SECOND_ATTACK))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_ELSE
                EVT_EXEC_WAIT(N(MakeIllusions))
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_CLONES))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
                EVT_BITWISE_OR_CONST(LW(0), N(FLAG_SUMMONED_CLONES_ONCE))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_END_IF
        EVT_CASE_EQ(N(PHASE_SUMMONED_CLONES))
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, 0x8002, LW(0))
            EVT_IF_LE(LW(0), 1)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
                EVT_IF_FLAG(LW(0), STATUS_FLAG_FROZEN)
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
            EVT_CALL(CountPlayerTargets, ACTOR_SELF, 0x8002, LW(0))
            EVT_IF_GT(LW(0), 1)
                EVT_EXEC_WAIT(N(AttackIcyBreathWithClones))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(MakeIllusions))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PHASE), N(PHASE_SUMMONED_CLONES))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_BITWISE_OR_CONST(LW(0), N(FLAG_SUMMONED_CLONES_ONCE))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_13)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 20)
        EVT_ADD(LW(2), -5)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 8)
        EVT_ADD(LW(2), -2)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 8, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35D)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -15)
                EVT_ADD(LW(1), 20)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(0.5), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
            EVT_ELSE
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -6)
                EVT_ADD(LW(1), 8)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(0.2), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
            EVT_END_IF
            EVT_CALL(N(StartRumbleWithParams), 70, 60)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 30, EVT_FLOAT(0.3))
            EVT_END_THREAD
            EVT_WAIT_FRAMES(30)
            EVT_CALL(StopSound, SOUND_35D)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -15)
        EVT_ADD(LW(1), 20)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -6)
        EVT_ADD(LW(1), 8)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
    EVT_END_IF
    EVT_CALL(N(StartRumbleWithParams), 70, 100)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 50, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(60)
    EVT_CALL(StopSound, SOUND_35D)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_13)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 20)
        EVT_ADD(LW(2), -5)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 8)
        EVT_ADD(LW(2), -2)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 8, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SHRINK)
                EVT_ADD(LW(0), -15)
                EVT_ADD(LW(1), 20)
            EVT_ELSE
                EVT_ADD(LW(0), -6)
                EVT_ADD(LW(1), 8)
            EVT_END_IF
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 20, 0)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
            EVT_THREAD
                EVT_SUB(LW(3), LW(0))
                EVT_SUB(LW(4), LW(1))
                EVT_SUB(LW(5), LW(2))
                EVT_DIV(LW(3), 10)
                EVT_DIV(LW(4), 10)
                EVT_DIV(LW(5), 10)
                EVT_LOOP(10)
                    EVT_ADD(LW(0), LW(3))
                    EVT_ADD(LW(1), LW(4))
                    EVT_ADD(LW(2), LW(5))
                    EVT_CALL(PlayEffect, EFFECT_MISC_PARTICLES, 1, LW(0), LW(1), LW(2), 20, -20, EVT_FLOAT(1.0), 5, 30, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(3)
            EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 20, 0, 0, 0, 0)
            EVT_CALL(func_802182E4_660A34, LW(15))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
    EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(0), -15)
        EVT_ADD(LW(1), 20)
    EVT_ELSE
        EVT_ADD(LW(0), -6)
        EVT_ADD(LW(1), 8)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_THREAD
        EVT_SUB(LW(3), LW(0))
        EVT_SUB(LW(4), LW(1))
        EVT_SUB(LW(5), LW(2))
        EVT_DIV(LW(3), 10)
        EVT_DIV(LW(4), 10)
        EVT_DIV(LW(5), 10)
        EVT_LOOP(10)
            EVT_ADD(LW(0), LW(3))
            EVT_ADD(LW(1), LW(4))
            EVT_ADD(LW(2), LW(5))
            EVT_CALL(PlayEffect, EFFECT_MISC_PARTICLES, 1, LW(0), LW(1), LW(2), 20, -20, EVT_FLOAT(1.0), 5, 30, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(3)
    EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 20, 0, 0, 0, 0)
    EVT_CALL(func_802182E4_660A34, LW(15))
    EVT_WAIT_FRAMES(7)
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0x00000002 | STATUS_FLAG_4 | STATUS_FLAG_8 | 0x00000010 | STATUS_FLAG_20 | STATUS_FLAG_40 | 0x00000080 | STATUS_FLAG_200 | STATUS_FLAG_FROZEN, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_COLD_BREATH, 0, LW(0), LW(1), LW(2), EVT_FLOAT(2.0), 30, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(func_80218344_660A94, LW(15))
            EVT_WAIT_FRAMES(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(clone_script)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(clone_script)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(clone_script)))
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
    .script = &N(clone_init),
    .statusTable = N(clone_statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 56, 56 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 40 },
    .statusMessageOffset = { 15, 40 },
};

Vec3i N(pos_crystal_clone) = { 0, -1000, 0 };

Formation N(clone_formation) = {
    { .actor = &N(clone), .home = { .vec = &N(pos_crystal_clone) }, .priority = 0 },
};

EvtScript N(MakeIllusions) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(GetActorHP, ACTOR_SELF, LW(10))
    EVT_CALL(SummonEnemy, EVT_ADDR(N(clone_formation)), 0)
    EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_NO_SHADOW, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
    EVT_CALL(SetPartEventBits, LW(0), 1, ACTOR_EVENT_FLAG_ILLUSORY, 1)
    EVT_CALL(SetEnemyHP, LW(0), LW(10))
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LW(0))
    EVT_CALL(CopyBuffs, ACTOR_SELF, LW(0))
    EVT_CALL(SummonEnemy, EVT_ADDR(N(clone_formation)), 0)
    EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_NO_SHADOW, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
    EVT_CALL(SetPartEventBits, LW(0), 1, ACTOR_EVENT_FLAG_ILLUSORY, 1)
    EVT_CALL(SetEnemyHP, LW(0), LW(10))
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LW(0))
    EVT_CALL(CopyBuffs, ACTOR_SELF, LW(0))
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_IF_FLAG(LW(0), N(FLAG_LOW_HP))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1D)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E7)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(7), LW(8), LW(9))
        EVT_CALL(MakeLerp, 0, 41, 30, 11)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LW(0), LW(8))
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(7), LW(0), LW(9))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
        EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_FLYING, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
        EVT_CALL(SetActorFlagBits, LW(0), ACTOR_FLAG_FLYING, 1)
        EVT_EXEC_GET_TID(N(FlyWithClones), LW(0))
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLY_THREAD_ID), LW(0))
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(10))
    EVT_CALL(SetActorPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(10))
    EVT_CALL(SetActorPos, LW(10), LW(0), LW(1), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
    EVT_CALL(UseIdleAnimation, LW(0), FALSE)
    EVT_CALL(SetAnimation, LW(0), 1, NPC_ANIM_crystal_king_Palette_00_Anim_0)
    EVT_CALL(SetAnimation, LW(0), 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
    EVT_CALL(UseIdleAnimation, LW(0), TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
    EVT_CALL(UseIdleAnimation, LW(0), FALSE)
    EVT_CALL(SetAnimation, LW(0), 1, NPC_ANIM_crystal_king_Palette_00_Anim_0)
    EVT_CALL(SetAnimation, LW(0), 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
    EVT_CALL(UseIdleAnimation, LW(0), TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2DF)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(0))
    EVT_CALL(EnableActorBlur, LW(0), 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(0))
    EVT_CALL(EnableActorBlur, LW(0), 1)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 6840, 210, 10)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(2))
        EVT_CALL(SetActorYaw, LW(2), LW(0))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(2))
        EVT_CALL(SetActorYaw, LW(2), LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 255, 128, 30, 10)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(2))
    EVT_CALL(SetPartAlpha, LW(2), 1, LW(0))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(2))
    EVT_CALL(SetPartAlpha, LW(2), 1, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_BITWISE_OR_CONST(LW(0), N(FLAG_HAS_CLONES))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_WAIT_FRAMES(60)
    EVT_CALL(RandInt, 1000, LW(0))
    EVT_MOD(LW(0), 3)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_SET(LW(10), ACTOR_SELF)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(11))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(12))
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(10))
            EVT_SET(LW(11), ACTOR_SELF)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(12))
        EVT_CASE_EQ(2)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(10))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(11))
            EVT_SET(LW(12), ACTOR_SELF)
    EVT_END_SWITCH
    EVT_CALL(SetActorFlagBits, LW(10), ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(SetActorFlagBits, LW(11), ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(SetActorFlagBits, LW(12), ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 150)
    EVT_THREAD
        EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
        EVT_SET(LW(3), 18)
        EVT_SET(LW(5), 5)
        EVT_SUB(LW(3), LW(0))
        EVT_SUB(LW(5), LW(2))
        EVT_DIVF(LW(3), EVT_FLOAT(60.0))
        EVT_DIVF(LW(5), EVT_FLOAT(60.0))
        EVT_LOOP(60)
            EVT_ADDF(LW(0), LW(3))
            EVT_ADDF(LW(2), LW(5))
            EVT_CALL(SetActorPos, LW(10), LW(0), LW(1), LW(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
        EVT_SET(LW(3), 70)
        EVT_SET(LW(5), 5)
        EVT_SUB(LW(3), LW(0))
        EVT_SUB(LW(5), LW(2))
        EVT_DIVF(LW(3), EVT_FLOAT(60.0))
        EVT_DIVF(LW(5), EVT_FLOAT(60.0))
        EVT_LOOP(60)
            EVT_ADDF(LW(0), LW(3))
            EVT_ADDF(LW(2), LW(5))
            EVT_CALL(SetActorPos, LW(11), LW(0), LW(1), LW(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, LW(12), LW(0), LW(1), LW(2))
        EVT_SET(LW(3), 122)
        EVT_SET(LW(5), 5)
        EVT_SUB(LW(3), LW(0))
        EVT_SUB(LW(5), LW(2))
        EVT_DIVF(LW(3), EVT_FLOAT(60.0))
        EVT_DIVF(LW(5), EVT_FLOAT(60.0))
        EVT_LOOP(60)
            EVT_ADDF(LW(0), LW(3))
            EVT_ADDF(LW(2), LW(5))
            EVT_CALL(SetActorPos, LW(12), LW(0), LW(1), LW(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(90)
    EVT_WAIT_FRAMES(30)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(10))
    EVT_CALL(EnableActorBlur, LW(10), 0)
    EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, LW(10))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(10))
    EVT_CALL(EnableActorBlur, LW(10), 0)
    EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, LW(10))
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_BITWISE_AND_CONST(LW(0), ~N(FLAG_IGNORE_IMMUNE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_WAIT_FRAMES(20)
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
    EVT_USE_ARRAY(LW(4))
    EVT_SET(UW(0), LW(0))
    EVT_SETF(UW(1), LW(1))
    EVT_SETF(UW(2), LW(2))
    EVT_SETF(UW(3), LW(3))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_SUBF(LW(2), LW(11))
    EVT_DIVF(LW(2), EVT_FLOAT(120.0))
    EVT_SETF(UW(4), LW(2))
    EVT_SETF(LW(6), LW(11))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_CALL(GetDist2D, LW(13), LW(10), LW(12), LW(1), LW(3))
    EVT_DIVF(LW(13), EVT_FLOAT(120.0))
    EVT_SETF(UW(5), LW(13))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_CALL(func_802183A4_660AF4, UW(6), LW(10), LW(12), LW(1), LW(3))
    EVT_CALL(SetPartAlpha, LW(0), 1, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(30)
        EVT_CALL(EnableActorBlur, LW(0), 1)
        EVT_SET(LW(9), LW(0))
        EVT_CALL(MakeLerp, 0, 255, 90, 0)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartAlpha, LW(9), 1, LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_SETF(LW(5), EVT_FLOAT(0.0))
    EVT_CALL(MakeLerp, 0, 2880, 120, 11)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(2), LW(3), LW(4))
    EVT_ADDF(LW(5), UW(5))
    EVT_ADDF(LW(0), UW(6))
    EVT_CALL(AddVectorPolar, LW(2), LW(4), LW(5), LW(0))
    EVT_ADDF(LW(6), UW(4))
    EVT_CALL(SetActorPos, UW(0), LW(2), LW(6), LW(4))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableActorBlur, UW(0), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(SummonCrystalBits) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1E)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_bit_1)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_bit_2)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_bit_3)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
        EVT_CALL(SetPartScale, LW(0), 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
        EVT_CALL(SetPartScale, LW(0), 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
        EVT_CALL(SetPartScale, LW(0), 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1F)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2DE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
    EVT_SETF(LW(1), EVT_FLOAT(42.0))
    EVT_SETF(LW(2), EVT_FLOAT(85.0))
    EVT_SETF(LW(3), EVT_FLOAT(-10.0))
    EVT_SET(LW(4), N(array_3))
    EVT_EXEC(N(CrystalBitAppear))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
    EVT_SETF(LW(1), EVT_FLOAT(112.0))
    EVT_SETF(LW(2), EVT_FLOAT(52.0))
    EVT_SETF(LW(3), EVT_FLOAT(-5.0))
    EVT_SET(LW(4), N(array_2))
    EVT_EXEC(N(CrystalBitAppear))
    EVT_WAIT_FRAMES(24)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
    EVT_SETF(LW(1), EVT_FLOAT(10.0))
    EVT_SETF(LW(2), EVT_FLOAT(35.0))
    EVT_SETF(LW(3), EVT_FLOAT(-5.0))
    EVT_SET(LW(4), N(array_1))
    EVT_EXEC(N(CrystalBitAppear))
    EVT_WAIT_FRAMES(130)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
    EVT_CALL(ForceHomePos, LW(0), 10, 35, -5)
    EVT_CALL(HPBarToHome, LW(0))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
    EVT_CALL(ForceHomePos, LW(0), 112, 52, -5)
    EVT_CALL(HPBarToHome, LW(0))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
    EVT_CALL(ForceHomePos, LW(0), 42, 85, -10)
    EVT_CALL(HPBarToHome, LW(0))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(AttackIcyBreathWithClones) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(10))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(11))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, LW(10), FALSE)
    EVT_CALL(UseIdleAnimation, LW(11), FALSE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_BITWISE_OR_CONST(LW(0), N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 35)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_CALL(SetBattleCamTarget, 70, 41, 5)
    EVT_ELSE
        EVT_CALL(SetBattleCamTarget, 70, 0, 5)
    EVT_END_IF
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_13)
    EVT_CALL(SetAnimation, LW(10), 1, NPC_ANIM_crystal_king_Palette_00_Anim_13)
    EVT_CALL(SetAnimation, LW(11), 1, NPC_ANIM_crystal_king_Palette_00_Anim_13)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(PlaySoundAtActor, LW(10), SOUND_206D)
    EVT_CALL(PlaySoundAtActor, LW(11), SOUND_206D)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(9))
    EVT_IF_NOT_FLAG(LW(9), STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 20)
        EVT_ADD(LW(2), -5)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 20)
        EVT_ADD(LW(2), -5)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 20)
        EVT_ADD(LW(2), -5)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 8)
        EVT_ADD(LW(2), -2)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 8, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 8)
        EVT_ADD(LW(2), -2)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 8, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 8)
        EVT_ADD(LW(2), -2)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 8, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
    EVT_CALL(SetAnimation, LW(10), 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
    EVT_CALL(SetAnimation, LW(11), 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35D)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(5), LW(0))
            EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), ACTOR_FLAG_FLYING)
                EVT_SETF(LW(3), EVT_FLOAT(195.0))
            EVT_ELSE
                EVT_SETF(LW(3), EVT_FLOAT(180.0))
            EVT_END_IF
            EVT_CALL(N(StartRumbleWithParams), 100, 60)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 30, EVT_FLOAT(0.3))
            EVT_END_THREAD
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(9))
            EVT_IF_NOT_FLAG(LW(9), STATUS_FLAG_SHRINK)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -15)
                EVT_ADD(LW(1), 20)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
                EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -15)
                EVT_ADD(LW(1), 20)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
                EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -15)
                EVT_ADD(LW(1), 20)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
            EVT_ELSE
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -6)
                EVT_ADD(LW(1), 8)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
                EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -6)
                EVT_ADD(LW(1), 8)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
                EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), -6)
                EVT_ADD(LW(1), 8)
                EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0, 0, 0, 0, 0)
                EVT_CALL(func_80218280_6609D0, LW(15))
            EVT_END_IF
            EVT_WAIT_FRAMES(30)
            EVT_CALL(StopSound, SOUND_35D)
            EVT_IF_EQ(LW(5), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_BITWISE_AND_CONST(LW(0), ~N(FLAG_NOT_IDLE))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_CALL(UseIdleAnimation, LW(10), TRUE)
            EVT_CALL(UseIdleAnimation, LW(11), TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_SETF(LW(3), EVT_FLOAT(195.0))
    EVT_ELSE
        EVT_SETF(LW(3), EVT_FLOAT(180.0))
    EVT_END_IF
    EVT_CALL(N(StartRumbleWithParams), 100, 120)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 60, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(9))
    EVT_IF_NOT_FLAG(LW(9), STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -15)
        EVT_ADD(LW(1), 20)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
        EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -15)
        EVT_ADD(LW(1), 20)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
        EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -15)
        EVT_ADD(LW(1), 20)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -6)
        EVT_ADD(LW(1), 8)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
        EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -6)
        EVT_ADD(LW(1), 8)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
        EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), -6)
        EVT_ADD(LW(1), 8)
        EVT_CALL(PlayEffect, EFFECT_HUFF_PUFF_BREATH, 0, LW(0), LW(1), LW(2), LW(3), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0)
        EVT_CALL(func_80218280_6609D0, LW(15))
    EVT_END_IF
    EVT_WAIT_FRAMES(60)
    EVT_CALL(StopSound, SOUND_35D)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
    EVT_CALL(SetAnimation, LW(10), 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
    EVT_CALL(SetAnimation, LW(11), 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_BITWISE_AND_CONST(LW(0), ~N(FLAG_NOT_IDLE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LW(0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseIdleAnimation, LW(10), TRUE)
    EVT_CALL(UseIdleAnimation, LW(11), TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(MoveBitToTarget) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_CALL(UseIdleAnimation, LW(10), FALSE)
    EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(9))
    EVT_IF_NOT_FLAG(LW(9), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(3), -15)
        EVT_ADD(LW(4), 20)
    EVT_ELSE
        EVT_ADD(LW(3), -6)
        EVT_ADD(LW(4), 8)
    EVT_END_IF
    EVT_CALL(func_8021848C_660BDC, LW(11), LW(0), LW(1), LW(2), LW(3), LW(4), LW(5))
    EVT_CALL(LoadPath, 30, LW(11), 3, 1)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetActorPos, LW(10), LW(1), LW(2), LW(3))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, LW(10), 1, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(SetActorFlagBits, LW(10), ACTOR_FLAG_NO_SHADOW, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(RemoveCrystalBit) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D9)
    EVT_SET(LW(10), LW(0))
    EVT_CALL(SetPartFlagBits, LW(10), 1, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetActorFlagBits, LW(10), ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -150, 0, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, LW(10), LW(3), LW(4), LW(5))
    EVT_THREAD
        EVT_SUB(LW(0), LW(3))
        EVT_SUB(LW(1), LW(4))
        EVT_SUB(LW(2), LW(5))
        EVT_DIV(LW(0), 10)
        EVT_DIV(LW(1), 10)
        EVT_DIV(LW(2), 10)
        EVT_LOOP(10)
            EVT_ADD(LW(3), LW(0))
            EVT_ADD(LW(4), LW(1))
            EVT_ADD(LW(5), LW(2))
            EVT_CALL(PlayEffect, EFFECT_MISC_PARTICLES, 1, LW(3), LW(4), LW(5), 20, -20, EVT_FLOAT(1.0), 5, 30, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LW(10), EVT_FLOAT(16.0))
    EVT_CALL(SetGoalPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, LW(10), 0, 0, 0)
    EVT_CALL(GetActorVar, LW(10), 0, LW(15))
    EVT_CALL(RemoveEffect, LW(15))
    EVT_CALL(RemoveActor, LW(10))
    EVT_RETURN
    EVT_END
};

EvtScript N(AttackWithCrystalBit) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D9)
    EVT_SET(LW(10), LW(0))
    EVT_CALL(SetPartFlagBits, LW(10), 1, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetActorFlagBits, LW(10), ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, LW(10), LW(3), LW(4), LW(5))
    EVT_THREAD
        EVT_SUB(LW(0), LW(3))
        EVT_SUB(LW(1), LW(4))
        EVT_SUB(LW(2), LW(5))
        EVT_DIV(LW(0), 10)
        EVT_DIV(LW(1), 10)
        EVT_DIV(LW(2), 10)
        EVT_LOOP(10)
            EVT_ADD(LW(3), LW(0))
            EVT_ADD(LW(4), LW(1))
            EVT_ADD(LW(5), LW(2))
            EVT_CALL(PlayEffect, EFFECT_MISC_PARTICLES, 1, LW(3), LW(4), LW(5), 20, -20, EVT_FLOAT(1.0), 5, 30, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LW(10), EVT_FLOAT(16.0))
    EVT_CALL(SetGoalPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, LW(10), 0, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, 0)
    EVT_CALL(SetActorJumpGravity, LW(10), EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, LW(10), LW(1), LW(2), LW(3))
    EVT_SUB(LW(1), 100)
    EVT_CALL(RandInt, 50, LW(4))
    EVT_ADD(LW(2), LW(4))
    EVT_CALL(SetGoalPos, LW(10), LW(1), LW(2), LW(3))
    EVT_CALL(JumpToGoal, LW(10), 20, FALSE, TRUE, FALSE)
    EVT_CALL(GetActorVar, LW(10), 0, LW(15))
    EVT_CALL(RemoveEffect, LW(15))
    EVT_CALL(RemoveActor, LW(10))
    EVT_RETURN
    EVT_END
};

EvtScript N(NormalAttack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(N(StartRumbleWithParams), 70, 60)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 30, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3AF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
    EVT_CALL(ActorExists, LW(0), LW(1))
    EVT_IF_EQ(LW(1), TRUE)
        EVT_SET(LW(1), &N(paths)[0])
        EVT_EXEC_GET_TID(N(MoveBitToTarget), LW(10))
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
    EVT_CALL(ActorExists, LW(0), LW(1))
    EVT_IF_EQ(LW(1), TRUE)
        EVT_SET(LW(1), &N(paths)[1])
        EVT_EXEC_GET_TID(N(MoveBitToTarget), LW(10))
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
    EVT_CALL(ActorExists, LW(0), LW(1))
    EVT_IF_EQ(LW(1), TRUE)
        EVT_SET(LW(1), &N(paths)[2])
        EVT_EXEC_GET_TID(N(MoveBitToTarget), LW(10))
    EVT_END_IF
    EVT_LABEL(0)
    EVT_IS_THREAD_RUNNING(LW(10), LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_13)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(9), LW(0))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
                EVT_EXEC_GET_TID(N(RemoveCrystalBit), LW(10))
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
                EVT_WAIT_FRAMES(6)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
                EVT_EXEC_GET_TID(N(RemoveCrystalBit), LW(10))
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
                EVT_WAIT_FRAMES(6)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
            EVT_CALL(ActorExists, LW(0), LW(1))
            EVT_IF_EQ(LW(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
                EVT_EXEC_GET_TID(N(RemoveCrystalBit), LW(10))
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
                EVT_WAIT_FRAMES(6)
            EVT_END_IF
            EVT_LABEL(1)
            EVT_IS_THREAD_RUNNING(LW(10), LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_WAIT_FRAMES(1)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_IF_EQ(LW(9), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(30)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT1_ID), LW(0))
    EVT_CALL(ActorExists, LW(0), LW(1))
    EVT_IF_EQ(LW(1), TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
        EVT_EXEC_GET_TID(N(AttackWithCrystalBit), LW(10))
        EVT_WAIT_FRAMES(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
        EVT_WAIT_FRAMES(6)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT2_ID), LW(0))
    EVT_CALL(ActorExists, LW(0), LW(1))
    EVT_IF_EQ(LW(1), TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
        EVT_EXEC_GET_TID(N(AttackWithCrystalBit), LW(10))
        EVT_WAIT_FRAMES(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
        EVT_WAIT_FRAMES(6)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_BIT3_ID), LW(0))
    EVT_CALL(ActorExists, LW(0), LW(1))
    EVT_IF_EQ(LW(1), TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1C)
        EVT_EXEC_GET_TID(N(AttackWithCrystalBit), LW(10))
        EVT_WAIT_FRAMES(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_15)
        EVT_WAIT_FRAMES(6)
    EVT_END_IF
    EVT_LABEL(4)
    EVT_IS_THREAD_RUNNING(LW(10), LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(4)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(Heal) = {
    EVT_SET(LF(0), 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PHASE), LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(N(PHASE_SUMMONED_CLONES))
        EVT_CASE_OR_EQ(N(PHASE_ATTACKED_WITH_CLONES))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE1_ID), LW(10))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_CLONE2_ID), LW(11))
            EVT_CALL(ActorExists, LW(10), LW(0))
            EVT_IF_EQ(LW(0), TRUE)
                EVT_SET(LF(0), 1)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_IF_EQ(LF(0), 1)
        EVT_CALL(UseIdleAnimation, LW(10), FALSE)
        EVT_CALL(EnableIdleScript, LW(10), 0)
        EVT_CALL(UseIdleAnimation, LW(11), FALSE)
        EVT_CALL(EnableIdleScript, LW(11), 0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 50)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), ACTOR_FLAG_FLYING)
        EVT_CALL(SetBattleCamTarget, 70, 41, 5)
    EVT_ELSE
        EVT_CALL(SetBattleCamTarget, 70, 0, 5)
    EVT_END_IF
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_1D)
    EVT_IF_EQ(LF(0), 1)
        EVT_CALL(SetAnimation, LW(10), 1, NPC_ANIM_crystal_king_Palette_00_Anim_1D)
        EVT_CALL(SetAnimation, LW(11), 1, NPC_ANIM_crystal_king_Palette_00_Anim_1D)
    EVT_END_IF
    EVT_WAIT_FRAMES(20)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
    EVT_END_THREAD
    EVT_IF_EQ(LF(0), 1)
        EVT_THREAD
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtActor, LW(10), SOUND_206D)
            EVT_CALL(PlaySoundAtActor, LW(10), SOUND_214)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(PlaySoundAtActor, LW(10), SOUND_25C)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtActor, LW(11), SOUND_206D)
            EVT_CALL(PlaySoundAtActor, LW(11), SOUND_214)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(PlaySoundAtActor, LW(11), SOUND_25C)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, ACTOR_SELF, 20, 0)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, ACTOR_SELF, 20, 1)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, LW(10), 20, 1)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, LW(11), 20, 1)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
        EVT_CALL(SetAnimation, LW(10), 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
        EVT_CALL(SetAnimation, LW(11), 1, NPC_ANIM_crystal_king_Palette_00_Anim_9)
    EVT_END_IF
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_IF_EQ(LF(0), 1)
        EVT_CALL(EnableIdleScript, LW(10), 1)
        EVT_CALL(UseIdleAnimation, LW(10), TRUE)
        EVT_CALL(EnableIdleScript, LW(10), 1)
        EVT_CALL(UseIdleAnimation, LW(10), TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
