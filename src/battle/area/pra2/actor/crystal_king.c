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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Flags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_HealCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_First)
    Call(SetActorVar, ACTOR_SELF, AVAR_Clone1_ID, -1)
    Call(SetActorVar, ACTOR_SELF, AVAR_Clone2_ID, -1)
    Call(SetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, ACTOR_BIT_1)
    Call(SetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, ACTOR_BIT_2)
    Call(SetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, ACTOR_BIT_3)
    Return
    End
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
    Set(LVarF, 0)
    Label(0)
        Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
        IfFlag(LVar0, AVAR_Flag_HasClones)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
            Call(ActorExists, LVar1, LVar3)
            IfEq(LVar3, TRUE)
                Call(N(CosInterpMinMax), LVarF, LVar4, Float(128.0), Float(254.0), 20, 0, 0)
                Set(LVar4, LVar4)
                Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar4)
                Call(SetPartAlpha, LVar1, PRT_MAIN, LVar4)
                Call(SetPartAlpha, LVar2, PRT_MAIN, LVar4)
                Add(LVarF, 1)
                IfGt(LVarF, 40)
                    Set(LVarF, 0)
                EndIf
            Else
                Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                BitwiseAndConst(LVar0, ~AVAR_Flag_HasClones)
                Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EndIf
        Else
            Set(LVarF, 0)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UpdateHovering) = {
    Set(LVarA, 0)
    Set(LVarB, 0)
    Set(LVarC, 0)
    Set(LVarD, 0)
    Set(LVarE, 0)
    Set(LVarF, 0)
    Label(1)
        Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
        IfNotFlag(LVar0, AVAL_Flag_SuspendHover)
            Set(LVar0, ACTOR_SELF)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
            Call(GetActorPos, LVar0, LVar3, LVar4, LVar5)
            Call(GetActorPos, LVar1, LVar4, LVar5, LVar6)
            IfGt(LVar3, LVar4)
                Set(LVar7, LVar0)
                Set(LVar0, LVar1)
                Set(LVar1, LVar7)
            EndIf
            Call(GetActorPos, LVar0, LVar3, LVar4, LVar5)
            Call(GetActorPos, LVar2, LVar4, LVar5, LVar6)
            IfGt(LVar3, LVar4)
                Set(LVar7, LVar0)
                Set(LVar0, LVar2)
                Set(LVar2, LVar7)
            EndIf
            Call(GetActorPos, LVar1, LVar3, LVar4, LVar5)
            Call(GetActorPos, LVar2, LVar4, LVar5, LVar6)
            IfGt(LVar3, LVar4)
                Set(LVar7, LVar1)
                Set(LVar1, LVar2)
                Set(LVar2, LVar7)
            EndIf
            Call(GetActorPos, LVar0, LVar3, LVar4, LVar5)
            Set(LVar4, 41)
            Add(LVar4, LVarA)
            Call(SetActorPos, LVar0, LVar3, LVar4, LVar5)
            Call(GetActorPos, LVar1, LVar3, LVar4, LVar5)
            Set(LVar4, 41)
            Add(LVar4, LVarC)
            Call(SetActorPos, LVar1, LVar3, LVar4, LVar5)
            Call(GetActorPos, LVar2, LVar3, LVar4, LVar5)
            Set(LVar4, 41)
            Add(LVar4, LVarE)
            Call(SetActorPos, LVar2, LVar3, LVar4, LVar5)
            Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.0), Float(5.0), 30, 0, 0)
            Set(LVarA, LVarB)
            Set(LVarB, LVarC)
            Set(LVarC, LVarD)
            Set(LVarD, LVarE)
            Set(LVarE, LVar0)
            Add(LVarF, 1)
            IfGt(LVarF, 60)
                Set(LVarF, 0)
            EndIf
        EndIf
        Wait(1)
        Goto(1)
    Return
    End
};

EvtScript N(EVS_RemoveClone) = {
    Call(EnableActorBlur, LVar9, ACTOR_BLUR_ENABLE)
    Call(SetActorFlagBits, LVar9, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Thread
        Call(N(GetActorPartOpacity), LVar9, PRT_MAIN, LVar3)
        Call(MakeLerp, LVar3, 0, 20, EASING_QUADRATIC_IN)
        Label(0)
        Call(UpdateLerp)
        Call(SetPartAlpha, LVar9, PRT_MAIN, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    EndThread
    Thread
        Call(MakeLerp, 100, 200, 20, EASING_QUADRATIC_IN)
        Label(1)
            Call(UpdateLerp)
            Call(GetStatusFlags, ACTOR_SELF, LVar8)
            IfFlag(LVar8, STATUS_FLAG_SHRINK)
                MulF(LVar0, Float(0.4))
            EndIf
            DivF(LVar0, Float(100.0))
            Call(SetPartScale, LVar9, PRT_MAIN, LVar0, LVar0, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndThread
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetActorRotationOffset, LVar9, 0, 28, 0)
    Else
        Call(SetActorRotationOffset, LVar9, 0, 10, 0)
    EndIf
    Call(MakeLerp, 3600, 0, 25, EASING_QUADRATIC_IN)
    Label(2)
        Call(UpdateLerp)
        Call(SetActorRotation, LVar9, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Call(RemoveActor, LVar9)
    Return
    End
};

EvtScript N(EVS_OnHit) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_AttackWithClones)
        CaseOrEq(AVAL_Move_AfterClonesAttack)
        EndCaseGroup
        CaseOrEq(AVAL_Move_First)
        CaseOrEq(AVAL_Move_AttackWithBits)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_SHRINK)
                Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
                Call(ActorExists, LVar0, LVar1)
                IfEq(LVar1, TRUE)
                    Call(SetDamageSource, DMG_SRC_DEFAULT)
                    Call(DispatchEvent, LVar0, EVENT_DEATH)
                EndIf
                Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
                Call(ActorExists, LVar0, LVar1)
                IfEq(LVar1, TRUE)
                    Call(SetDamageSource, DMG_SRC_DEFAULT)
                    Call(DispatchEvent, LVar0, EVENT_DEATH)
                EndIf
                Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
                Call(ActorExists, LVar0, LVar1)
                IfEq(LVar1, TRUE)
                    Call(SetDamageSource, DMG_SRC_DEFAULT)
                    Call(DispatchEvent, LVar0, EVENT_DEATH)
                EndIf
            EndIf
            Return
        EndCaseGroup
        CaseDefault
            Return
    EndSwitch
    Call(GetLastElement, LVar0)
    IfFlag(LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS)
        Label(0)
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_EXECUTING_MOVE)
                Wait(1)
                Goto(0)
            EndIf
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
    Call(ActorExists, LVar9, LVarA)
    IfEq(LVarA, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
        Exec(N(EVS_RemoveClone))
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar9)
        ExecGetTID(N(EVS_RemoveClone), LVar0)
        Label(1)
            IsThreadRunning(LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Wait(1)
                Goto(1)
            EndIf
    EndIf
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim19)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    IfNe(LVar1, 0)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(GetActorVar, ACTOR_SELF, AVAR_HoveringScriptID, LVarA)
        KillThread(LVarA)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_WITHER)
        Set(LVar1, 0)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        Call(N(StartRumbleWithParams), 150, 10)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.7))
        EndThread
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        Wait(15)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EndIf
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim0E)
        Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
        Call(SetGoalPos, ACTOR_SELF, 70, 0, 5)
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AVAR_Flag_HitCombo)
    Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    Return
    End
};

EvtScript N(EVS_Death) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_AttackWithClones)
        CaseOrEq(AVAL_Move_AfterClonesAttack)
        EndCaseGroup
        CaseOrEq(AVAL_Move_First)
        CaseOrEq(AVAL_Move_AttackWithBits)
            Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Call(SetDamageSource, DMG_SRC_DEFAULT)
                Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                Call(DispatchEvent, LVar0, EVENT_DEATH)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Call(SetDamageSource, DMG_SRC_DEFAULT)
                Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                Call(DispatchEvent, LVar0, EVENT_DEATH)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Call(SetDamageSource, DMG_SRC_DEFAULT)
                Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
                Call(DispatchEvent, LVar0, EVENT_DEATH)
            EndIf
            Return
        EndCaseGroup
        CaseDefault
            Return
    EndSwitch
    Call(GetLastElement, LVar0)
    IfFlag(LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS)
        Label(0)
        Call(GetBattleFlags, LVar0)
        IfFlag(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            Wait(1)
            Goto(0)
        EndIf
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_HoveringScriptID, LVarA)
    IsThreadRunning(LVarA, LVar0)
    IfEq(LVar0, TRUE)
        KillThread(LVarA)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
    Call(ActorExists, LVar9, LVarA)
    IfEq(LVarA, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar9)
        Exec(N(EVS_RemoveClone))
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar9)
        ExecGetTID(N(EVS_RemoveClone), LVar0)
        Label(1)
            IsThreadRunning(LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Wait(1)
                Goto(1)
            EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    BitwiseOrConst(LVar0, AVAL_Flag_SuspendHover)
    Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            BitwiseOrConst(LVar0, AVAR_Flag_HitCombo)
            Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim19)
                    ExecWait(EVS_Enemy_Hit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EndThread
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim19)
                    ExecWait(EVS_Enemy_Hit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EndThread
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim19)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim19)
                    ExecWait(EVS_Enemy_Hit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EndThread
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim19)
                    ExecWait(EVS_Enemy_Hit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
                EndThread
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim19)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_OnHit))
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim20)
                    SetConst(LVar2, ANIM_CrystalKing_Anim21)
                    ExecWait(EVS_Enemy_BurnHit)
                EndThread
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim20)
                    SetConst(LVar2, ANIM_CrystalKing_Anim21)
                    ExecWait(EVS_Enemy_BurnHit)
                EndThread
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim20)
            SetConst(LVar2, ANIM_CrystalKing_Anim21)
            ExecWait(EVS_Enemy_BurnHit)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim19)
            ExecWait(N(EVS_OnHit))
        CaseEq(EVENT_ZERO_DAMAGE)
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim09)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim09)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            IfFlag(LVar0, AVAR_Flag_HitCombo)
                ExecWait(N(EVS_OnHit))
                Return
            EndIf
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                ExecWait(N(EVS_OnHit))
                Return
            EndIf
        CaseEq(EVENT_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim19)
                    ExecWait(EVS_Enemy_Hit)
                EndThread
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim19)
                    ExecWait(EVS_Enemy_Hit)
                EndThread
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim19)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_Death))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim19)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim20)
                    SetConst(LVar2, ANIM_CrystalKing_Anim21)
                    ExecWait(EVS_Enemy_BurnHit)
                EndThread
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Thread
                    Call(SetOwnerID, LVar0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_CrystalKing_Anim20)
                    SetConst(LVar2, ANIM_CrystalKing_Anim21)
                    ExecWait(EVS_Enemy_BurnHit)
                EndThread
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim20)
            SetConst(LVar2, ANIM_CrystalKing_Anim21)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_Death))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim21)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Thread
                Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
                Switch(LVar0)
                    CaseOrEq(AVAL_Move_AttackWithClones)
                    CaseOrEq(AVAL_Move_AfterClonesAttack)
                        SetF(LVar0, Float(0.4))
                        Loop(30)
                            SetF(LVar1, Float(1.0))
                            SubF(LVar1, LVar0)
                            DivF(LVar1, Float(6.0))
                            AddF(LVar0, LVar1)
                            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
                            Call(ActorExists, LVarA, LVarB)
                            IfEq(LVarB, TRUE)
                                Call(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EndIf
                            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarA)
                            Call(ActorExists, LVarA, LVarB)
                            IfEq(LVarB, TRUE)
                                Call(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EndIf
                            Wait(1)
                        EndLoop
                    EndCaseGroup
                    CaseOrEq(AVAL_Move_First)
                    CaseOrEq(AVAL_Move_AttackWithBits)
                        SetF(LVar0, Float(0.4))
                        Loop(30)
                            SetF(LVar1, Float(1.0))
                            SubF(LVar1, LVar0)
                            DivF(LVar1, Float(6.0))
                            AddF(LVar0, LVar1)
                            Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVarA)
                            Call(ActorExists, LVarA, LVarB)
                            IfEq(LVarB, TRUE)
                                Call(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EndIf
                            Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVarA)
                            Call(ActorExists, LVarA, LVarB)
                            IfEq(LVarB, TRUE)
                                Call(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EndIf
                            Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVarA)
                            Call(ActorExists, LVarA, LVarB)
                            IfEq(LVarB, TRUE)
                                Call(SetPartScale, LVarA, PRT_MAIN, LVar0, LVar0, LVar0)
                            EndIf
                            Wait(1)
                        EndLoop
                    EndCaseGroup
                EndSwitch
            EndThread
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim09)
            ExecWait(EVS_Enemy_Recover)
            Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            IfLe(LVar0, 1)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim0E)
                Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
                Call(SetGoalPos, ACTOR_SELF, 70, 0, 5)
                Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_CrystalKing_Anim19)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_RECEIVE_BUFF)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
        CaseDefault
    EndSwitch
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AVAL_Flag_SuspendHover)
    Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorHP, ACTOR_SELF, LVar0)
    IfLe(LVar0, 20)
        Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
        BitwiseOrConst(LVar0, AVAL_Flag_HadLowHP)
        Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EndIf
    Set(LFlag0, FALSE)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    Mul(LVar0, 100)
    Div(LVar0, LVar1)
    Switch(LVar0)
        CaseLt(25)
            // 100% chance to heal when HP < 25%
            Call(RandInt, 99, LVar0)
            Add(LVar0, 1)
            IfLe(LVar0, 100)
                Call(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
                IfLt(LVar0, 2)
                    Set(LFlag0, TRUE)
                EndIf
            EndIf
        CaseLt(40)
            // 30% chance to heal when HP < 40%
            Call(RandInt, 99, LVar0)
            Add(LVar0, 1)
            IfLe(LVar0, 30)
                Call(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
                IfLt(LVar0, 2)
                    Set(LFlag0, TRUE)
                EndIf
            EndIf
        CaseLt(55)
            // 10% chance to heal when HP < 55%
            Call(RandInt, 99, LVar0)
            Add(LVar0, 1)
            IfLe(LVar0, 10)
                Call(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
                IfLt(LVar0, 2)
                    Set(LFlag0, TRUE)
                EndIf
            EndIf
    EndSwitch
    IfEq(LFlag0, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
        Add(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_HealCount, LVar0)
        ExecWait(N(EVS_Move_Recover))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Move_First)
            Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            IfLe(LVar0, 1)
                ExecWait(N(EVS_Move_SummonBits))
                Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithBits)
            Else
                ExecWait(N(EVS_Attack_SpitBits))
                Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_SummonBits)
            EndIf
        CaseEq(AVAL_Move_SummonBits)
            ExecWait(N(EVS_Move_SummonBits))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithBits)
        CaseEq(AVAL_Move_AttackWithBits)
            Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            IfLe(LVar0, 1)
                Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                IfFlag(LVar0, STATUS_FLAG_FROZEN)
                    ExecWait(N(EVS_Attack_IcyBreath))
                Else
                    ExecWait(N(EVS_Attack_IceBolt))
                EndIf
            Else
                ExecWait(N(EVS_Attack_SpitBits))
            EndIf
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AfterBitsAttack)
        CaseEq(AVAL_Move_AfterBitsAttack)
            Call(GetActorHP, ACTOR_SELF, LVar0)
            IfGt(LVar0, 35)
                Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                IfNotFlag(LVar0, AVAR_Flag_HasSummonedClones)
                    ExecWait(N(EVS_Move_SummonBits))
                    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithBits)
                    Return
                EndIf
            EndIf
            Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            IfNotFlag(LVar0, AVAL_Flag_UsedIceBolt)
                ExecWait(N(EVS_Attack_IceBolt))
                Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                BitwiseOrConst(LVar0, AVAL_Flag_UsedIceBolt)
                Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            Else
                ExecWait(N(EVS_Move_MakeClones))
                Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithClones)
                Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
                BitwiseOrConst(LVar0, AVAR_Flag_HasSummonedClones)
                Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            EndIf
        CaseEq(AVAL_Move_AttackWithClones)
            Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            IfLe(LVar0, 1)
                Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                IfFlag(LVar0, STATUS_FLAG_FROZEN)
                    ExecWait(N(EVS_Attack_IcyBreath))
                Else
                    ExecWait(N(EVS_Attack_IceBolt))
                EndIf
                Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AfterBitsAttack)
            Else
                ExecWait(N(EVS_Attack_CloneBreath))
                Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AfterClonesAttack)
            EndIf
        CaseEq(AVAL_Move_AfterClonesAttack)
            Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
            IfGt(LVar0, 1)
                ExecWait(N(EVS_Attack_CloneBreath))
                Return
            EndIf
            ExecWait(N(EVS_Move_MakeClones))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_AttackWithClones)
            Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            BitwiseOrConst(LVar0, AVAR_Flag_HasSummonedClones)
            Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_IcyBreath) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Add(LVar2, -5)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 8)
        Add(LVar2, -2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
    EndIf
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    Wait(3)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_WIND_LOOP)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, -15)
                Add(LVar1, 20)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, Float(180.0), Float(2.0), Float(0.5), 30, 0)
                Call(N(SetBreathColors), LVarF)
            Else
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, -6)
                Add(LVar1, 8)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, Float(180.0), Float(2.0), Float(0.2), 30, 0)
                Call(N(SetBreathColors), LVarF)
            EndIf
            Call(N(StartRumbleWithParams), 70, 60)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 30, Float(0.3))
            EndThread
            Wait(30)
            Call(StopSound, SOUND_HEAVY_WIND_LOOP)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -15)
        Add(LVar1, 20)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, Float(180.0), Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -6)
        Add(LVar1, 8)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, Float(180.0), Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
    EndIf
    Call(N(StartRumbleWithParams), 70, 100)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 50, Float(0.3))
    EndThread
    Wait(60)
    Call(StopSound, SOUND_HEAVY_WIND_LOOP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_ICE_BREATH, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_IceBolt) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Add(LVar2, -5)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 8)
        Add(LVar2, -2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
    EndIf
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    Wait(3)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CRYSTAL_KING_ICE_BOLT)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                Add(LVar0, -15)
                Add(LVar1, 20)
            Else
                Add(LVar0, -6)
                Add(LVar1, 8)
            EndIf
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -50, 20, 0)
            Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Thread
                Sub(LVar3, LVar0)
                Sub(LVar4, LVar1)
                Sub(LVar5, LVar2)
                Div(LVar3, 10)
                Div(LVar4, 10)
                Div(LVar5, 10)
                Loop(10)
                    Add(LVar0, LVar3)
                    Add(LVar1, LVar4)
                    Add(LVar2, LVar5)
                    PlayEffect(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 20, -20, Float(1.0), 5, 30, 0)
                    Wait(1)
                EndLoop
            EndThread
            Wait(3)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 20, 0)
            Call(N(SetBoltColors), LVarF)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar0, -15)
        Add(LVar1, 20)
    Else
        Add(LVar0, -6)
        Add(LVar1, 8)
    EndIf
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Thread
        Sub(LVar3, LVar0)
        Sub(LVar4, LVar1)
        Sub(LVar5, LVar2)
        Div(LVar3, 10)
        Div(LVar4, 10)
        Div(LVar5, 10)
        Loop(10)
            Add(LVar0, LVar3)
            Add(LVar1, LVar4)
            Add(LVar2, LVar5)
            PlayEffect(EFFECT_MISC_PARTICLES, 1, LVar0, LVar1, LVar2, 20, -20, Float(1.0), 5, 30, 0)
            Wait(1)
        EndLoop
    EndThread
    Wait(3)
    PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 20, 0)
    Call(N(SetBoltColors), LVarF)
    Wait(7)
    Thread
        Wait(3)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
    EndThread
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_IGNORE_RES(STATUS_FLAG_FROZEN, 2), DMG_ICE_BOLT, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_COLD_BREATH, 0, LVar0, LVar1, LVar2, Float(2.0), 30, 0)
            Call(N(SetMistColors), LVarF)
            Wait(30)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
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
    Return
    End
};

EvtScript N(EVS_Init_Clone) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Clone_Dummy)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Clone_Dummy)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Clone_Dummy)))
    Return
    End
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
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorHP, ACTOR_SELF, LVarA)
    Call(SummonEnemy, Ref(N(CloneFormation)), FALSE)
    Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_SHADOW, TRUE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
    Call(SetPartEventBits, LVar0, PRT_MAIN, ACTOR_EVENT_FLAG_ILLUSORY, TRUE)
    Call(SetEnemyHP, LVar0, LVarA)
    Call(CopyStatusEffects, ACTOR_SELF, LVar0)
    Call(CopyBuffs, ACTOR_SELF, LVar0)
    Call(SummonEnemy, Ref(N(CloneFormation)), FALSE)
    Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_SHADOW, TRUE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
    Call(SetPartEventBits, LVar0, PRT_MAIN, ACTOR_EVENT_FLAG_ILLUSORY, TRUE)
    Call(SetEnemyHP, LVar0, LVarA)
    Call(CopyStatusEffects, ACTOR_SELF, LVar0)
    Call(CopyBuffs, ACTOR_SELF, LVar0)
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    IfFlag(LVar0, AVAL_Flag_HadLowHP)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1D)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPOOKY_LEVITATE)
        Call(GetActorPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        Call(MakeLerp, 0, 41, 30, EASING_SIN_OUT)
        Label(10)
        Call(UpdateLerp)
        Add(LVar0, LVar8)
        Call(SetActorPos, ACTOR_SELF, LVar7, LVar0, LVar9)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
        Call(SetActorFlagBits, LVar0, ACTOR_FLAG_FLYING, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
        Call(SetActorFlagBits, LVar0, ACTOR_FLAG_FLYING, TRUE)
        ExecGetTID(N(EVS_UpdateHovering), LVar0)
        Call(SetActorVar, ACTOR_SELF, AVAR_HoveringScriptID, LVar0)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_PRESET_01)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
    Call(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarA)
    Call(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    Wait(1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim09)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
    Call(UseIdleAnimation, LVar0, FALSE)
    Call(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim00)
    Call(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim09)
    Call(UseIdleAnimation, LVar0, TRUE)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
    Call(UseIdleAnimation, LVar0, FALSE)
    Call(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim00)
    Call(SetAnimation, LVar0, PRT_MAIN, ANIM_CrystalKing_Anim09)
    Call(UseIdleAnimation, LVar0, TRUE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUMMON_CRYSTAL_CLONES)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar0)
    Call(EnableActorBlur, LVar0, ACTOR_BLUR_ENABLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar0)
    Call(EnableActorBlur, LVar0, ACTOR_BLUR_ENABLE)
    Thread
        Call(MakeLerp, 0, 6840, 210, EASING_COS_IN_OUT)
        Label(0)
        Call(UpdateLerp)
        Call(SetActorYaw, ACTOR_SELF, LVar0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar2)
        Call(SetActorYaw, LVar2, LVar0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
        Call(SetActorYaw, LVar2, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    EndThread
    Call(MakeLerp, 255, 128, 30, EASING_COS_IN_OUT)
    Label(1)
    Call(UpdateLerp)
    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVar2)
    Call(SetPartAlpha, LVar2, PRT_MAIN, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVar2)
    Call(SetPartAlpha, LVar2, PRT_MAIN, LVar0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    BitwiseOrConst(LVar0, AVAR_Flag_HasClones)
    Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    Wait(60)
    Call(RandInt, 1000, LVar0)
    Mod(LVar0, 3)
    Switch(LVar0)
        CaseEq(0)
            Set(LVarA, ACTOR_SELF)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarB)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarC)
        CaseEq(1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
            Set(LVarB, ACTOR_SELF)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarC)
        CaseEq(2)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarB)
            Set(LVarC, ACTOR_SELF)
    EndSwitch
    Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(SetActorFlagBits, LVarB, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(SetActorFlagBits, LVarC, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 150)
    Thread
        Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        Set(LVar3, 18)
        Set(LVar5, 5)
        Sub(LVar3, LVar0)
        Sub(LVar5, LVar2)
        DivF(LVar3, Float(60.0))
        DivF(LVar5, Float(60.0))
        Loop(60)
            AddF(LVar0, LVar3)
            AddF(LVar2, LVar5)
            Call(SetActorPos, LVarA, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Set(LVar3, 70)
        Set(LVar5, 5)
        Sub(LVar3, LVar0)
        Sub(LVar5, LVar2)
        DivF(LVar3, Float(60.0))
        DivF(LVar5, Float(60.0))
        Loop(60)
            AddF(LVar0, LVar3)
            AddF(LVar2, LVar5)
            Call(SetActorPos, LVarB, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(GetActorPos, LVarC, LVar0, LVar1, LVar2)
        Set(LVar3, 122)
        Set(LVar5, 5)
        Sub(LVar3, LVar0)
        Sub(LVar5, LVar2)
        DivF(LVar3, Float(60.0))
        DivF(LVar5, Float(60.0))
        Loop(60)
            AddF(LVar0, LVar3)
            AddF(LVar2, LVar5)
            Call(SetActorPos, LVarC, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Wait(90)
    Wait(30)
    Wait(30)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
    Call(EnableActorBlur, LVarA, ACTOR_BLUR_DISABLE)
    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVarA)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarA)
    Call(EnableActorBlur, LVarA, ACTOR_BLUR_DISABLE)
    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVarA)
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AVAR_Flag_HitCombo)
    Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    Wait(20)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
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
    UseArray(LVar4)
    Set(ArrayVar(0), LVar0)
    SetF(ArrayVar(1), LVar1)
    SetF(ArrayVar(2), LVar2)
    SetF(ArrayVar(3), LVar3)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    SubF(LVar2, LVarB)
    DivF(LVar2, Float(120.0))
    SetF(ArrayVar(4), LVar2)
    SetF(LVar6, LVarB)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(GetDist2D, LVarD, LVarA, LVarC, LVar1, LVar3)
    DivF(LVarD, Float(120.0))
    SetF(ArrayVar(5), LVarD)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(N(CalculateAngle), ArrayVar(6), LVarA, LVarC, LVar1, LVar3)
    Call(SetPartAlpha, LVar0, PRT_MAIN, 0)
    Thread
        Wait(30)
        Call(EnableActorBlur, LVar0, ACTOR_BLUR_ENABLE)
        Set(LVar9, LVar0)
        Call(MakeLerp, 0, 255, 90, EASING_LINEAR)
        Label(0)
            Call(UpdateLerp)
            Call(SetPartAlpha, LVar9, PRT_MAIN, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
    EndThread
    SetF(LVar5, Float(0.0))
    Call(MakeLerp, 0, 2880, 120, EASING_SIN_OUT)
    Label(1)
        Call(UpdateLerp)
        Call(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
        AddF(LVar5, ArrayVar(5))
        AddF(LVar0, ArrayVar(6))
        Call(AddVectorPolar, LVar2, LVar4, LVar5, LVar0)
        AddF(LVar6, ArrayVar(4))
        Call(SetActorPos, ArrayVar(0), LVar2, LVar6, LVar4)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(EnableActorBlur, ArrayVar(0), IDLE_SCRIPT_DISABLE)
    Return
    End
};

EvtScript N(EVS_Move_SummonBits) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1E)
    Wait(20)
    Call(SummonEnemy, Ref(N(CubeBitFormation)), FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    Call(SummonEnemy, Ref(N(SphereBitFormation)), FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    Call(SummonEnemy, Ref(N(PrismBitFormation)), FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
        Call(SetPartScale, LVar0, PRT_MAIN, Float(0.4), Float(0.4), Float(0.4))
        Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
        Call(SetPartScale, LVar0, PRT_MAIN, Float(0.4), Float(0.4), Float(0.4))
        Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
        Call(SetPartScale, LVar0, PRT_MAIN, Float(0.4), Float(0.4), Float(0.4))
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1F)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUMMON_CRYSTAL_BITS)
    Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    SetF(LVar1, Float(42.0))
    SetF(LVar2, Float(85.0))
    SetF(LVar3, Float(-10.0))
    Set(LVar4, N(PrismBitSummonData))
    Exec(N(EVS_SummonBit))
    Wait(10)
    Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    SetF(LVar1, Float(112.0))
    SetF(LVar2, Float(52.0))
    SetF(LVar3, Float(-5.0))
    Set(LVar4, N(SphereBitSummonData))
    Exec(N(EVS_SummonBit))
    Wait(24)
    Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    SetF(LVar1, Float(10.0))
    SetF(LVar2, Float(35.0))
    SetF(LVar3, Float(-5.0))
    Set(LVar4, N(CubeBitSummonData))
    Exec(N(EVS_SummonBit))
    Wait(130)
    Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    Call(ForceHomePos, LVar0, 10, 35, -5)
    Call(HPBarToHome, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    Call(ForceHomePos, LVar0, 112, 52, -5)
    Call(HPBarToHome, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    Call(ForceHomePos, LVar0, 42, 85, -10)
    Call(HPBarToHome, LVar0)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_CloneBreath) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
    Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarB)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(UseIdleAnimation, LVarA, FALSE)
    Call(UseIdleAnimation, LVarB, FALSE)
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    BitwiseOrConst(LVar0, AVAL_Flag_SuspendHover)
    Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamZoom, 350)
    Call(SetBattleCamOffsetZ, 35)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetBattleCamTarget, 70, 41, 5)
    Else
        Call(SetBattleCamTarget, 70, 0, 5)
    EndIf
    Call(MoveBattleCamOver, 15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    Call(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim13)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim13)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    Call(PlaySoundAtActor, LVarA, SOUND_RECOVER_HEART)
    Call(PlaySoundAtActor, LVarB, SOUND_RECOVER_HEART)
    Call(GetStatusFlags, ACTOR_SELF, LVar9)
    IfNotFlag(LVar9, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Add(LVar2, -5)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
        Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Add(LVar2, -5)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Add(LVar2, -5)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 20, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 8)
        Add(LVar2, -2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
        Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        Add(LVar1, 8)
        Add(LVar2, -2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Add(LVar1, 8)
        Add(LVar2, -2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 8, 0)
    EndIf
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    Call(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    Wait(3)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_WIND_LOOP)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVar5, LVar0)
            Call(GetActorFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, ACTOR_FLAG_FLYING)
                SetF(LVar3, Float(195.0))
            Else
                SetF(LVar3, Float(180.0))
            EndIf
            Call(N(StartRumbleWithParams), 100, 60)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 30, Float(0.3))
            EndThread
            Call(GetStatusFlags, ACTOR_SELF, LVar9)
            IfNotFlag(LVar9, STATUS_FLAG_SHRINK)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, -15)
                Add(LVar1, 20)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 30, 0)
                Call(N(SetBreathColors), LVarF)
                Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                Add(LVar0, -15)
                Add(LVar1, 20)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 30, 0)
                Call(N(SetBreathColors), LVarF)
                Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                Add(LVar0, -15)
                Add(LVar1, 20)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 30, 0)
                Call(N(SetBreathColors), LVarF)
            Else
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, -6)
                Add(LVar1, 8)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(0.4), 30, 0)
                Call(N(SetBreathColors), LVarF)
                Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                Add(LVar0, -6)
                Add(LVar1, 8)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(0.4), 30, 0)
                Call(N(SetBreathColors), LVarF)
                Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
                Add(LVar0, -6)
                Add(LVar1, 8)
                PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(0.4), 30, 0)
                Call(N(SetBreathColors), LVarF)
            EndIf
            Wait(30)
            Call(StopSound, SOUND_HEAVY_WIND_LOOP)
            IfEq(LVar5, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AVAL_Flag_SuspendHover)
            Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Call(UseIdleAnimation, LVarA, TRUE)
            Call(UseIdleAnimation, LVarB, TRUE)
            Return
    EndSwitch
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_FLYING)
        SetF(LVar3, Float(195.0))
    Else
        SetF(LVar3, Float(180.0))
    EndIf
    Call(N(StartRumbleWithParams), 100, 120)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 60, Float(0.3))
    EndThread
    Call(GetStatusFlags, ACTOR_SELF, LVar9)
    IfNotFlag(LVar9, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -15)
        Add(LVar1, 20)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
        Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        Add(LVar0, -15)
        Add(LVar1, 20)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Add(LVar0, -15)
        Add(LVar1, 20)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -6)
        Add(LVar1, 8)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
        Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
        Add(LVar0, -6)
        Add(LVar1, 8)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Add(LVar0, -6)
        Add(LVar1, 8)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, LVar3, Float(2.0), Float(1.0), 60, 0)
        Call(N(SetBreathColors), LVarF)
    EndIf
    Wait(60)
    Call(StopSound, SOUND_HEAVY_WIND_LOOP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
    Call(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim15)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim15)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_CLONE_BREATH, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(GetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AVAL_Flag_SuspendHover)
    Call(SetActorVar, ACTOR_KING, AVAR_Flags, LVar0)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(UseIdleAnimation, LVarA, TRUE)
    Call(UseIdleAnimation, LVarB, TRUE)
    Return
    End
};

// LVar0: (in) bit ActorID
// LVar1: (in) suction path array
EvtScript N(EVS_InhaleBit) = {
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Call(UseIdleAnimation, LVarA, FALSE)
    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(GetStatusFlags, ACTOR_SELF, LVar9)
    IfNotFlag(LVar9, STATUS_FLAG_SHRINK)
        Add(LVar3, -15)
        Add(LVar4, 20)
    Else
        Add(LVar3, -6)
        Add(LVar4, 8)
    EndIf
    Call(N(MakeSuctionPath), LVarB, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5)
    Call(LoadPath, 30, LVarB, 3, EASING_QUADRATIC_IN)
    Label(0)
        Call(GetNextPathPos)
        Call(SetActorPos, LVarA, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, TRUE)
    Return
    End
};

EvtScript N(EVS_RemoveBit) = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LIGHT_THROW)
    Set(LVarA, LVar0)
    Call(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, -150, 0, 0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
    Thread
        Sub(LVar0, LVar3)
        Sub(LVar1, LVar4)
        Sub(LVar2, LVar5)
        Div(LVar0, 10)
        Div(LVar1, 10)
        Div(LVar2, 10)
        Loop(10)
            Add(LVar3, LVar0)
            Add(LVar4, LVar1)
            Add(LVar5, LVar2)
            PlayEffect(EFFECT_MISC_PARTICLES, 1, LVar3, LVar4, LVar5, 20, -20, Float(1.0), 5, 30, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetActorSpeed, LVarA, Float(16.0))
    Call(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
    Call(FlyToGoal, LVarA, 0, 0, EASING_LINEAR)
    Call(GetActorVar, LVarA, AVAR_Bit_ParticlesEffect, LVarF)
    Call(RemoveEffect, LVarF)
    Call(RemoveActor, LVarA)
    Return
    End
};

EvtScript N(EVS_SpitSingleBit) = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LIGHT_THROW)
    Set(LVarA, LVar0)
    Call(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
    Thread
        Sub(LVar0, LVar3)
        Sub(LVar1, LVar4)
        Sub(LVar2, LVar5)
        Div(LVar0, 10)
        Div(LVar1, 10)
        Div(LVar2, 10)
        Loop(10)
            Add(LVar3, LVar0)
            Add(LVar4, LVar1)
            Add(LVar5, LVar2)
            PlayEffect(EFFECT_MISC_PARTICLES, 1, LVar3, LVar4, LVar5, 20, -20, Float(1.0), 5, 30, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetActorSpeed, LVarA, Float(16.0))
    Call(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
    Call(FlyToGoal, LVarA, 0, 0, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SPIT_BIT, 0)
    Call(SetActorJumpGravity, LVarA, Float(1.0))
    Call(GetActorPos, LVarA, LVar1, LVar2, LVar3)
    Sub(LVar1, 100)
    Call(RandInt, 50, LVar4)
    Add(LVar2, LVar4)
    Call(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
    Call(JumpToGoal, LVarA, 20, FALSE, TRUE, FALSE)
    Call(GetActorVar, LVarA, AVAR_Bit_ParticlesEffect, LVarF)
    Call(RemoveEffect, LVarF)
    Call(RemoveActor, LVarA)
    Return
    End
};

EvtScript N(EVS_Attack_SpitBits) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
    Wait(20)
    Call(N(StartRumbleWithParams), 70, 60)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 30, Float(0.2))
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CRYSTAL_KING_INHALE)
    Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, TRUE)
        Set(LVar1, &N(BitSuctionPaths)[0])
        ExecGetTID(N(EVS_InhaleBit), LVarA)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, TRUE)
        Set(LVar1, &N(BitSuctionPaths)[1])
        ExecGetTID(N(EVS_InhaleBit), LVarA)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, TRUE)
        Set(LVar1, &N(BitSuctionPaths)[2])
        ExecGetTID(N(EVS_InhaleBit), LVarA)
    EndIf
    Label(0)
        IsThreadRunning(LVarA, LVar0)
        IfEq(LVar0, 1)
            Wait(1)
            Goto(0)
        EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim13)
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVar9, LVar0)
            Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
                ExecGetTID(N(EVS_RemoveBit), LVarA)
                Wait(4)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
                Wait(6)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
                ExecGetTID(N(EVS_RemoveBit), LVarA)
                Wait(4)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
                Wait(6)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
            Call(ActorExists, LVar0, LVar1)
            IfEq(LVar1, TRUE)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
                ExecGetTID(N(EVS_RemoveBit), LVarA)
                Wait(4)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
                Wait(6)
            EndIf
            Label(1)
                IsThreadRunning(LVarA, LVar0)
                IfEq(LVar0, 1)
                    Wait(1)
                    Goto(1)
                EndIf
            IfEq(LVar9, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, AVAR_King_CubeBitID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, TRUE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
        ExecGetTID(N(EVS_SpitSingleBit), LVarA)
        Wait(4)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
        Wait(6)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_King_SphereBitID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, TRUE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
        ExecGetTID(N(EVS_SpitSingleBit), LVarA)
        Wait(4)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
        Wait(6)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_King_PrismBitID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, TRUE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1C)
        ExecGetTID(N(EVS_SpitSingleBit), LVarA)
        Wait(4)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim15)
        Wait(6)
    EndIf
    Label(4)
        IsThreadRunning(LVarA, LVar0)
        IfEq(LVar0, 1)
            Wait(1)
            Goto(4)
        EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_Recover) = {
    Set(LFlag0, FALSE)
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_AttackWithClones)
        CaseOrEq(AVAL_Move_AfterClonesAttack)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone1_ID, LVarA)
            Call(GetActorVar, ACTOR_SELF, AVAR_Clone2_ID, LVarB)
            Call(ActorExists, LVarA, LVar0)
            IfEq(LVar0, TRUE)
                Set(LFlag0, TRUE)
            EndIf
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    IfEq(LFlag0, TRUE)
        Call(UseIdleAnimation, LVarA, FALSE)
        Call(EnableIdleScript, LVarA, IDLE_SCRIPT_DISABLE)
        Call(UseIdleAnimation, LVarB, FALSE)
        Call(EnableIdleScript, LVarB, IDLE_SCRIPT_DISABLE)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamZoom, 350)
    Call(SetBattleCamOffsetZ, 50)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetBattleCamTarget, 70, 41, 5)
    Else
        Call(SetBattleCamTarget, 70, 0, 5)
    EndIf
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim1D)
    IfEq(LFlag0, TRUE)
        Call(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim1D)
        Call(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim1D)
    EndIf
    Wait(20)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        Wait(30)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EndThread
    IfEq(LFlag0, TRUE)
        Thread
            Wait(5)
            Call(PlaySoundAtActor, LVarA, SOUND_RECOVER_HEART)
            Call(PlaySoundAtActor, LVarA, SOUND_HEART_BOUNCE)
            Wait(30)
            Call(PlaySoundAtActor, LVarA, SOUND_STAR_BOUNCE_A)
        EndThread
        Thread
            Wait(5)
            Call(PlaySoundAtActor, LVarB, SOUND_RECOVER_HEART)
            Call(PlaySoundAtActor, LVarB, SOUND_HEART_BOUNCE)
            Wait(30)
            Call(PlaySoundAtActor, LVarB, SOUND_STAR_BOUNCE_A)
        EndThread
    EndIf
    IfEq(LFlag0, FALSE)
        Thread
            Call(FreezeBattleState, TRUE)
            Call(HealActor, ACTOR_SELF, 20, FALSE)
            Call(FreezeBattleState, FALSE)
        EndThread
    Else
        Thread
            Call(FreezeBattleState, TRUE)
            Call(HealActor, ACTOR_SELF, 20, TRUE)
            Call(FreezeBattleState, FALSE)
        EndThread
        Thread
            Call(FreezeBattleState, TRUE)
            Call(HealActor, LVarA, 20, TRUE)
            Call(FreezeBattleState, FALSE)
        EndThread
        Thread
            Call(FreezeBattleState, TRUE)
            Call(HealActor, LVarB, 20, TRUE)
            Call(FreezeBattleState, FALSE)
        EndThread
        Call(SetAnimation, LVarA, PRT_MAIN, ANIM_CrystalKing_Anim09)
        Call(SetAnimation, LVarB, PRT_MAIN, ANIM_CrystalKing_Anim09)
    EndIf
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    IfEq(LFlag0, TRUE)
        Call(EnableIdleScript, LVarA, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, LVarA, TRUE)
        Call(EnableIdleScript, LVarA, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, LVarA, TRUE)
    EndIf
    Return
    End
};
