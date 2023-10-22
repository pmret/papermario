#include "../area.h"
#include "sprite/npc/CrystalKing.h"
#include "crystal_king_common.h"

#define NAMESPACE A(crystal_king)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Move_MakeClones);
extern EvtScript N(EVS_Move_SummonBits);
extern EvtScript N(EVS_Attack_IceBolt);
extern EvtScript N(EVS_Attack_IcyBreath);
extern EvtScript N(EVS_Attack_CloneBreath);
extern EvtScript N(EVS_Attack_SpitBits);
extern EvtScript N(EVS_Move_Recover);

extern ActorBlueprint A(crystal_bit_cube);
extern ActorBlueprint A(crystal_bit_sphere);
extern ActorBlueprint A(crystal_bit_prism);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Flags                  = 0,
    AVAR_Flag_HitCombo          = 0x01,
    AVAL_Flag_HadLowHP          = 0x02,
    AVAR_Flag_HasSummonedClones = 0x04,
    AVAL_Flag_UsedIceBolt       = 0x10,
    AVAR_Flag_HasClones         = 0x20,
    AVAL_Flag_SuspendHover      = 0x40,
    AVAR_NextMove               = 1,
    AVAL_Move_First             = 0,
    AVAL_Move_SummonBits        = 1,
    AVAL_Move_AttackWithBits    = 2,
    AVAL_Move_AfterBitsAttack   = 3,
    AVAL_Move_AttackWithClones  = 4,
    AVAL_Move_AfterClonesAttack = 5,
    AVAR_Clone1_ID              = 2,
    AVAR_Clone2_ID              = 3,
    AVAR_HealCount              = 7,
    AVAR_HoveringScriptID       = 8,

};

enum N(ActorParams) {
    DMG_SPIT_BIT        = 4,
    DMG_ICE_BOLT        = 6,
    DMG_ICE_BREATH      = 8,
    DMG_CLONE_BREATH    = 8,
};

static Vec3f N(BitSuctionPaths)[3][3];

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_CrystalKing_Anim09,
    STATUS_KEY_SLEEP,     ANIM_CrystalKing_Anim1B,
    STATUS_KEY_DIZZY,     ANIM_CrystalKing_Anim1A,
    STATUS_KEY_PARALYZE,  ANIM_CrystalKing_Anim00,
    STATUS_KEY_STOP,      ANIM_CrystalKing_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_FIRE,     0,
    ELEMENT_ICE,     99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_DEFAULT_TARGET | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -22 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CRYSTAL_KING,
    .level = ACTOR_LEVEL_CRYSTAL_KING,
    .maxHP = 70,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 40 },
    .statusTextOffset = { 15, 40 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_First)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Clone1_ID, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Clone2_ID, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, ACTOR_BIT_1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, ACTOR_BIT_2)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, ACTOR_BIT_3)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/CosInterpMinMax.inc.c"

API_CALLABLE(N(GetActorPartOpacity)) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    evt_set_variable(script, *args++, get_actor_part(get_actor(actorID), partID)->opacity);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetBreathColors)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.huffPuffBreath->primCol.r = 248;
    effect->data.huffPuffBreath->primCol.g = 248;
    effect->data.huffPuffBreath->primCol.b = 255;
    effect->data.huffPuffBreath->envCol.r = 128;
    effect->data.huffPuffBreath->envCol.g = 224;
    effect->data.huffPuffBreath->envCol.b = 255;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetBoltColors)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.lightningBolt->outerColor.r = 255;
    effect->data.lightningBolt->outerColor.g = 255;
    effect->data.lightningBolt->outerColor.b = 255;
    effect->data.lightningBolt->innerColor.r = 200;
    effect->data.lightningBolt->innerColor.g = 240;
    effect->data.lightningBolt->innerColor.b = 255;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetMistColors)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.coldBreath->primCol.r = 255;
    effect->data.coldBreath->primCol.g = 255;
    effect->data.coldBreath->primCol.b = 255;
    effect->data.coldBreath->envCol.r = 200;
    effect->data.coldBreath->envCol.g = 240;
    effect->data.coldBreath->envCol.b = 255;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CalculateAngle)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    f32 startX = evt_get_variable(script, *args++);
    f32 startZ = evt_get_variable(script, *args++);
    f32 endX = evt_get_variable(script, *args++);
    f32 endZ = evt_get_variable(script, *args++);
    f32 angle = atan2(startX, startZ, endX, endZ);

    evt_set_variable(script, outVar, angle);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(MakeSuctionPath)) {
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

EvtScript N(EVS_Idle) = {
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
        EVT_IF_FLAG(LVar0, AVAR_Flag_HasClones)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
            EVT_CALL(ActorExists, LVar1, LVar3)
            EVT_IF_EQ(LVar3, TRUE)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar4, EVT_FLOAT(128.0), EVT_FLOAT(254.0), 20, 0, 0)
                EVT_SET(LVar4, LVar4)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar4)
                EVT_CALL(SetPartAlpha, LVar1, PRT_MAIN, LVar4)
                EVT_CALL(SetPartAlpha, LVar2, PRT_MAIN, LVar4)
                EVT_ADD(LVarF, 1)
                EVT_IF_GT(LVarF, 40)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_HasClones)
                EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateHovering) = {
    EVT_SET(LVarA, 0)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, 0)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarF, 0)
    EVT_LABEL(1)
        EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_SuspendHover)
            EVT_SET(LVar0, ACTOR_SELF)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
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

EvtScript N(EVS_RemoveClone) = {
    EVT_CALL(EnableActorBlur, LVar9, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetActorFlagBits, LVar9, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_THREAD
        EVT_CALL(N(GetActorPartOpacity), LVar9, PRT_MAIN, LVar3)
        EVT_CALL(MakeLerp, LVar3, 0, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartAlpha, LVar9, PRT_MAIN, LVar0)
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
            EVT_CALL(SetPartScale, LVar9, PRT_MAIN, LVar0, LVar0, LVar0)
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
    EVT_CALL(MakeLerp, 3600, 0, 25, EASING_QUADRATIC_IN)
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

EvtScript N(EVS_OnHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_AttackWithClones)
        EVT_CASE_OR_EQ(AVAL_Move_AfterClonesAttack)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(AVAL_Move_First)
        EVT_CASE_OR_EQ(AVAL_Move_AttackWithBits)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_SHRINK)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
                EVT_CALL(ActorExists, LVar0, LVar1)
                EVT_IF_EQ(LVar1, TRUE)
                    EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                    EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
                EVT_END_IF
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
                EVT_CALL(ActorExists, LVar0, LVar1)
                EVT_IF_EQ(LVar1, TRUE)
                    EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                    EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
                EVT_END_IF
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
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
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS)
        EVT_LABEL(0)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_EXECUTING_MOVE)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
    EVT_CALL(ActorExists, LVar9, LVarA)
    EVT_IF_EQ(LVarA, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
        EVT_EXEC(N(EVS_RemoveClone))
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar9)
        EVT_EXEC_GET_TID(N(EVS_RemoveClone), LVar0)
        EVT_LABEL(1)
            EVT_IS_THREAD_RUNNING(LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_WAIT(1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_IF
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HoveringScriptID, LVarA)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_WITHER)
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
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim0E)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 0, 5)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_HitCombo)
    EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_AttackWithClones)
        EVT_CASE_OR_EQ(AVAL_Move_AfterClonesAttack)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(AVAL_Move_First)
        EVT_CASE_OR_EQ(AVAL_Move_AttackWithBits)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
                EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                EVT_CALL(DispatchEvent, LVar0, EVENT_DEATH)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
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
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HoveringScriptID, LVarA)
    EVT_IS_THREAD_RUNNING(LVarA, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_KILL_THREAD(LVarA)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
    EVT_CALL(ActorExists, LVar9, LVarA)
    EVT_IF_EQ(LVarA, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
        EVT_EXEC(N(EVS_RemoveClone))
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar9)
        EVT_EXEC_GET_TID(N(EVS_RemoveClone), LVar0)
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

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_SuspendHover)
    EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AVAR_Flag_HitCombo)
            EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
            EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AVAR_Flag_HitCombo)
                EVT_EXEC_WAIT(N(EVS_OnHit))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_EXEC_WAIT(N(EVS_OnHit))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_THREAD
                    EVT_CALL(SetOwnerID, LVar0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
                    EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_END_THREAD
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim20)
            EVT_SET_CONST(LVar2, ANIM_CrystalKing_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_OR_EQ(AVAL_Move_AttackWithClones)
                    EVT_CASE_OR_EQ(AVAL_Move_AfterClonesAttack)
                        EVT_SETF(LVar0, EVT_FLOAT(0.4))
                        EVT_LOOP(30)
                            EVT_SETF(LVar1, EVT_FLOAT(1.0))
                            EVT_SUBF(LVar1, LVar0)
                            EVT_DIVF(LVar1, EVT_FLOAT(6.0))
                            EVT_ADDF(LVar0, LVar1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_WAIT(1)
                        EVT_END_LOOP
                    EVT_END_CASE_GROUP
                    EVT_CASE_OR_EQ(AVAL_Move_First)
                    EVT_CASE_OR_EQ(AVAL_Move_AttackWithBits)
                        EVT_SETF(LVar0, EVT_FLOAT(0.4))
                        EVT_LOOP(30)
                            EVT_SETF(LVar1, EVT_FLOAT(1.0))
                            EVT_SUBF(LVar1, LVar0)
                            EVT_DIVF(LVar1, EVT_FLOAT(6.0))
                            EVT_ADDF(LVar0, LVar1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVarA)
                            EVT_CALL(ActorExists, LVarA, LVarB)
                            EVT_IF_EQ(LVarB, TRUE)
                                EVT_CALL(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EVT_END_IF
                            EVT_WAIT(1)
                        EVT_END_LOOP
                    EVT_END_CASE_GROUP
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim0E)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 0, 5)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_RECEIVE_BUFF)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AVAL_Flag_SuspendHover)
    EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 20)
        EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
        EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_HadLowHP)
        EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_END_IF
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MUL(LVar0, 100)
    EVT_DIV(LVar0, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(25)
            // 100% chance to heal when HP < 25%
            EVT_CALL(RandInt, 99, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_IF_LE(LVar0, 100)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(40)
            // 30% chance to heal when HP < 40%
            EVT_CALL(RandInt, 99, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_IF_LE(LVar0, 30)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(55)
            // 10% chance to heal when HP < 55%
            EVT_CALL(RandInt, 99, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_IF_LE(LVar0, 10)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
                EVT_IF_LT(LVar0, 2)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
        EVT_EXEC_WAIT(N(EVS_Move_Recover))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Move_First)
            EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_EXEC_WAIT(N(EVS_Move_SummonBits))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithBits)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Attack_SpitBits))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_SummonBits)
            EVT_END_IF
        EVT_CASE_EQ(AVAL_Move_SummonBits)
            EVT_EXEC_WAIT(N(EVS_Move_SummonBits))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithBits)
        EVT_CASE_EQ(AVAL_Move_AttackWithBits)
            EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_FROZEN)
                    EVT_EXEC_WAIT(N(EVS_Attack_IcyBreath))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(EVS_Attack_IceBolt))
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Attack_SpitBits))
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AfterBitsAttack)
        EVT_CASE_EQ(AVAL_Move_AfterBitsAttack)
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_IF_GT(LVar0, 35)
                EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                EVT_IF_NOT_FLAG(LVar0, AVAR_Flag_HasSummonedClones)
                    EVT_EXEC_WAIT(N(EVS_Move_SummonBits))
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithBits)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_UsedIceBolt)
                EVT_EXEC_WAIT(N(EVS_Attack_IceBolt))
                EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_UsedIceBolt)
                EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Move_MakeClones))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithClones)
                EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AVAR_Flag_HasSummonedClones)
                EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_END_IF
        EVT_CASE_EQ(AVAL_Move_AttackWithClones)
            EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_FROZEN)
                    EVT_EXEC_WAIT(N(EVS_Attack_IcyBreath))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(EVS_Attack_IceBolt))
                EVT_END_IF
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AfterBitsAttack)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Attack_CloneBreath))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AfterClonesAttack)
            EVT_END_IF
        EVT_CASE_EQ(AVAL_Move_AfterClonesAttack)
            EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            EVT_IF_GT(LVar0, 1)
                EVT_EXEC_WAIT(N(EVS_Attack_CloneBreath))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_Move_MakeClones))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithClones)
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AVAR_Flag_HasSummonedClones)
            EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_IcyBreath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_WIND_LOOP)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
                EVT_CALL(N(SetBreathColors), LVarF)
            EVT_ELSE
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(0.2), 30, 0)
                EVT_CALL(N(SetBreathColors), LVarF)
            EVT_END_IF
            EVT_CALL(N(StartRumbleWithParams), 70, 60)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 30, EVT_FLOAT(0.3))
            EVT_END_THREAD
            EVT_WAIT(30)
            EVT_CALL(StopSound, SOUND_HEAVY_WIND_LOOP)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(N(SetBreathColors), LVarF)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(N(SetBreathColors), LVarF)
    EVT_END_IF
    EVT_CALL(N(StartRumbleWithParams), 70, 100)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 50, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(StopSound, SOUND_HEAVY_WIND_LOOP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_ICE_BREATH, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_IceBolt) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CRYSTAL_KING_ICE_BOLT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            EVT_CALL(N(SetBoltColors), LVarF)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
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
    EVT_CALL(N(SetBoltColors), LVarF)
    EVT_WAIT(7)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_IGNORE_RES(STATUS_FLAG_FROZEN, 2), DMG_ICE_BOLT, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_COLD_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 30, 0)
            EVT_CALL(N(SetMistColors), LVarF)
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(CloneStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

EvtScript N(EVS_Clone_Dummy) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init_Clone) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Clone_Dummy)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Clone_Dummy)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Clone_Dummy)))
    EVT_RETURN
    EVT_END
};

ActorBlueprint N(clone) = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_CLONE,
    .level = ACTOR_LEVEL_CRYSTAL_CLONE,
    .maxHP = 70,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init_Clone),
    .statusTable = N(CloneStatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 56, 56 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 40 },
    .statusTextOffset = { 15, 40 },
};

Vec3i N(CloneSummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(CloneFormation) = {
    ACTOR_BY_POS(N(clone), N(CloneSummonPos), 0),
};

EvtScript N(EVS_Move_MakeClones) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarA)
    EVT_CALL(SummonEnemy, EVT_PTR(N(CloneFormation)), FALSE)
    EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
    EVT_CALL(SetPartEventBits, LVar0, PRT_MAIN, ACTOR_EVENT_FLAG_ILLUSORY, TRUE)
    EVT_CALL(SetEnemyHP, LVar0, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVar0)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVar0)
    EVT_CALL(SummonEnemy, EVT_PTR(N(CloneFormation)), FALSE)
    EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
    EVT_CALL(SetPartEventBits, LVar0, PRT_MAIN, ACTOR_EVENT_FLAG_ILLUSORY, TRUE)
    EVT_CALL(SetEnemyHP, LVar0, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVar0)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVar0)
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_IF_FLAG(LVar0, AVAL_Flag_HadLowHP)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1D)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPOOKY_LEVITATE)
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
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
        EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_FLYING, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
        EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_FLYING, TRUE)
        EVT_EXEC_GET_TID(N(EVS_UpdateHovering), LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HoveringScriptID, LVar0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarA)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim00)
    EVT_CALL(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim09)
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim00)
    EVT_CALL(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim09)
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SUMMON_CRYSTAL_CLONES)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
    EVT_CALL(EnableActorBlur, LVar0, ACTOR_BLUR_ENABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
    EVT_CALL(EnableActorBlur, LVar0, ACTOR_BLUR_ENABLE)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 6840, 210, EASING_COS_IN_OUT)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar2)
        EVT_CALL(SetActorYaw, LVar2, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
        EVT_CALL(SetActorYaw, LVar2, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 255, 128, 30, EASING_COS_IN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar2)
    EVT_CALL(SetPartAlpha, LVar2, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
    EVT_CALL(SetPartAlpha, LVar2, PRT_MAIN, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, AVAR_Flag_HasClones)
    EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_WAIT(60)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_MOD(LVar0, 3)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVarA, ACTOR_SELF)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarB)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarC)
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
            EVT_SET(LVarB, ACTOR_SELF)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarC)
        EVT_CASE_EQ(2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarB)
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
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
    EVT_CALL(EnableActorBlur, LVarA, ACTOR_BLUR_DISABLE)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarA)
    EVT_CALL(EnableActorBlur, LVarA, ACTOR_BLUR_DISABLE)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_HitCombo)
    EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_WAIT(20)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Formation N(CubeBitFormation) = {
    ACTOR_BY_POS(A(crystal_bit_cube), N(CloneSummonPos), 0),
};

Formation N(SphereBitFormation) = {
    ACTOR_BY_POS(A(crystal_bit_sphere), N(CloneSummonPos), 0),
};

Formation N(PrismBitFormation) = {
    ACTOR_BY_POS(A(crystal_bit_prism), N(CloneSummonPos), 0),
};

s32 N(CubeBitSummonData)[16] = {};

s32 N(SphereBitSummonData)[16] = {};

s32 N(PrismBitSummonData)[16] = {};

EvtScript N(EVS_SummonBit) = {
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
    EVT_CALL(N(CalculateAngle), ArrayVar(6), LVarA, LVarC, LVar1, LVar3)
    EVT_CALL(SetPartAlpha, LVar0, PRT_MAIN, 0)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(EnableActorBlur, LVar0, ACTOR_BLUR_ENABLE)
        EVT_SET(LVar9, LVar0)
        EVT_CALL(MakeLerp, 0, 255, 90, EASING_LINEAR)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetPartAlpha, LVar9, PRT_MAIN, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_THREAD
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_CALL(MakeLerp, 0, 2880, 120, EASING_SIN_OUT)
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
    EVT_CALL(EnableActorBlur, ArrayVar(0), IDLE_SCRIPT_DISABLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_SummonBits) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1E)
    EVT_WAIT(20)
    EVT_CALL(SummonEnemy, EVT_PTR(N(CubeBitFormation)), FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    EVT_CALL(SummonEnemy, EVT_PTR(N(SphereBitFormation)), FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    EVT_CALL(SummonEnemy, EVT_PTR(N(PrismBitFormation)), FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
        EVT_CALL(SetPartScale, LVar0, PRT_MAIN, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
        EVT_CALL(SetPartScale, LVar0, PRT_MAIN, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
        EVT_CALL(SetPartScale, LVar0, PRT_MAIN, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1F)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SUMMON_CRYSTAL_BITS)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    EVT_SETF(LVar1, EVT_FLOAT(42.0))
    EVT_SETF(LVar2, EVT_FLOAT(85.0))
    EVT_SETF(LVar3, EVT_FLOAT(-10.0))
    EVT_SET(LVar4, N(PrismBitSummonData))
    EVT_EXEC(N(EVS_SummonBit))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    EVT_SETF(LVar1, EVT_FLOAT(112.0))
    EVT_SETF(LVar2, EVT_FLOAT(52.0))
    EVT_SETF(LVar3, EVT_FLOAT(-5.0))
    EVT_SET(LVar4, N(SphereBitSummonData))
    EVT_EXEC(N(EVS_SummonBit))
    EVT_WAIT(24)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    EVT_SETF(LVar1, EVT_FLOAT(10.0))
    EVT_SETF(LVar2, EVT_FLOAT(35.0))
    EVT_SETF(LVar3, EVT_FLOAT(-5.0))
    EVT_SET(LVar4, N(CubeBitSummonData))
    EVT_EXEC(N(EVS_SummonBit))
    EVT_WAIT(130)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    EVT_CALL(ForceHomePos, LVar0, 10, 35, -5)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    EVT_CALL(ForceHomePos, LVar0, 112, 52, -5)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    EVT_CALL(ForceHomePos, LVar0, 42, 85, -10)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_CloneBreath) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarB)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(UseIdleAnimation, LVarB, FALSE)
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_SuspendHover)
    EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    EVT_CALL(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim13)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim13)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    EVT_CALL(PlaySoundAtActor, LVarA, SOUND_RECOVER_HEART)
    EVT_CALL(PlaySoundAtActor, LVarB, SOUND_RECOVER_HEART)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    EVT_CALL(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(3)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_WIND_LOOP)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
                EVT_CALL(N(SetBreathColors), LVarF)
                EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -15)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0)
                EVT_CALL(N(SetBreathColors), LVarF)
                EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -15)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 30, 0)
                EVT_CALL(N(SetBreathColors), LVarF)
            EVT_ELSE
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0)
                EVT_CALL(N(SetBreathColors), LVarF)
                EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0)
                EVT_CALL(N(SetBreathColors), LVarF)
                EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, -6)
                EVT_ADD(LVar1, 8)
                EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(0.4), 30, 0)
                EVT_CALL(N(SetBreathColors), LVarF)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(StopSound, SOUND_HEAVY_WIND_LOOP)
            EVT_IF_EQ(LVar5, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AVAL_Flag_SuspendHover)
            EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
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
        EVT_CALL(N(SetBreathColors), LVarF)
        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(N(SetBreathColors), LVarF)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(N(SetBreathColors), LVarF)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(N(SetBreathColors), LVarF)
        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(N(SetBreathColors), LVarF)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, EVT_FLOAT(2.0), EVT_FLOAT(1.0), 60, 0)
        EVT_CALL(N(SetBreathColors), LVarF)
    EVT_END_IF
    EVT_WAIT(60)
    EVT_CALL(StopSound, SOUND_HEAVY_WIND_LOOP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
    EVT_CALL(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim15)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim15)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_CLONE_BREATH, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AVAL_Flag_SuspendHover)
    EVT_CALL(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseIdleAnimation, LVarA, TRUE)
    EVT_CALL(UseIdleAnimation, LVarB, TRUE)
    EVT_RETURN
    EVT_END
};

// LVar0: (in) bit ActorID
// LVar1: (in) suction path array
EvtScript N(EVS_InhaleBit) = {
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
    EVT_CALL(N(MakeSuctionPath), LVarB, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(LoadPath, 30, LVarB, 3, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetActorPos, LVarA, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RemoveBit) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LIGHT_THROW)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
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
    EVT_CALL(GetActorVar, LVarA, AVAR_Bit_ParticlesEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveActor, LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpitSingleBit) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LIGHT_THROW)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SPIT_BIT, 0)
    EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, LVarA, LVar1, LVar2, LVar3)
    EVT_SUB(LVar1, 100)
    EVT_CALL(RandInt, 50, LVar4)
    EVT_ADD(LVar2, LVar4)
    EVT_CALL(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
    EVT_CALL(JumpToGoal, LVarA, 20, FALSE, TRUE, FALSE)
    EVT_CALL(GetActorVar, LVarA, AVAR_Bit_ParticlesEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveActor, LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SpitBits) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(20)
    EVT_CALL(N(StartRumbleWithParams), 70, 60)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 30, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CRYSTAL_KING_INHALE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_SET(LVar1, &N(BitSuctionPaths)[0])
        EVT_EXEC_GET_TID(N(EVS_InhaleBit), LVarA)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_SET(LVar1, &N(BitSuctionPaths)[1])
        EVT_EXEC_GET_TID(N(EVS_InhaleBit), LVarA)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_SET(LVar1, &N(BitSuctionPaths)[2])
        EVT_EXEC_GET_TID(N(EVS_InhaleBit), LVarA)
    EVT_END_IF
    EVT_LABEL(0)
        EVT_IS_THREAD_RUNNING(LVarA, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVar9, LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
                EVT_EXEC_GET_TID(N(EVS_RemoveBit), LVarA)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
                EVT_WAIT(6)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
                EVT_EXEC_GET_TID(N(EVS_RemoveBit), LVarA)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
                EVT_WAIT(6)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
            EVT_CALL(ActorExists, LVar0, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
                EVT_EXEC_GET_TID(N(EVS_RemoveBit), LVarA)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
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
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
        EVT_EXEC_GET_TID(N(EVS_SpitSingleBit), LVarA)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
        EVT_WAIT(6)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
        EVT_EXEC_GET_TID(N(EVS_SpitSingleBit), LVarA)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
        EVT_WAIT(6)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, TRUE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
        EVT_EXEC_GET_TID(N(EVS_SpitSingleBit), LVarA)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
        EVT_WAIT(6)
    EVT_END_IF
    EVT_LABEL(4)
        EVT_IS_THREAD_RUNNING(LVarA, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(4)
        EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_Recover) = {
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_AttackWithClones)
        EVT_CASE_OR_EQ(AVAL_Move_AfterClonesAttack)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarB)
            EVT_CALL(ActorExists, LVarA, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(UseIdleAnimation, LVarA, FALSE)
        EVT_CALL(EnableIdleScript, LVarA, IDLE_SCRIPT_DISABLE)
        EVT_CALL(UseIdleAnimation, LVarB, FALSE)
        EVT_CALL(EnableIdleScript, LVarB, IDLE_SCRIPT_DISABLE)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1D)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim1D)
        EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim1D)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EVT_END_THREAD
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_RECOVER_HEART)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_HEART_BOUNCE)
            EVT_WAIT(30)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_STAR_BOUNCE_A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, LVarB, SOUND_RECOVER_HEART)
            EVT_CALL(PlaySoundAtActor, LVarB, SOUND_HEART_BOUNCE)
            EVT_WAIT(30)
            EVT_CALL(PlaySoundAtActor, LVarB, SOUND_STAR_BOUNCE_A)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_THREAD
            EVT_CALL(FreezeBattleState, TRUE)
            EVT_CALL(HealActor, ACTOR_SELF, 20, FALSE)
            EVT_CALL(FreezeBattleState, FALSE)
        EVT_END_THREAD
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(FreezeBattleState, TRUE)
            EVT_CALL(HealActor, ACTOR_SELF, 20, TRUE)
            EVT_CALL(FreezeBattleState, FALSE)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(FreezeBattleState, TRUE)
            EVT_CALL(HealActor, LVarA, 20, TRUE)
            EVT_CALL(FreezeBattleState, FALSE)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(FreezeBattleState, TRUE)
            EVT_CALL(HealActor, LVarB, 20, TRUE)
            EVT_CALL(FreezeBattleState, FALSE)
        EVT_END_THREAD
        EVT_CALL(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim09)
        EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim09)
    EVT_END_IF
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(EnableIdleScript, LVarA, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, LVarA, TRUE)
        EVT_CALL(EnableIdleScript, LVarA, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, LVarA, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
