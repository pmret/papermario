#include "../area.h"
#include "sprite/npc/HuffNPuff.h"
#include "sprite/npc/TuffPuff.h"
#include "sprite/player.h"
#include "battle/action_cmd/whirlwind.h"
#include "battle/action_cmd/stop_leech.h"
#include "huff_n_puff_common.h"

#define NAMESPACE A(huff_n_puff)

#define MAX_RUFF_PUFFS 10

// execute a template for each child in an orderly sequence
#define FOR_CHILDREN_ORDERED(template) \
    template(0) \
    template(1) \
    template(2) \
    template(3) \
    template(4) \
    template(5) \
    template(6) \
    template(7) \
    template(8) \
    template(9)

// execute a template for each child in a disordered sequence
#define FOR_CHILDREN_SCATTERED(template) \
    template(4) \
    template(9) \
    template(3) \
    template(5) \
    template(1) \
    template(0) \
    template(8) \
    template(2) \
    template(7) \
    template(6)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_UpdateSize);
extern EvtScript N(EVS_Move_HealOrSlam);
extern EvtScript N(EVS_Move_HurricaneBreath);
extern EvtScript N(EVS_Move_ChargeForGround);
extern EvtScript N(EVS_Move_ChargeForDirect);
extern EvtScript N(EVS_Attack_GroundLightning);
extern EvtScript N(EVS_Attack_DirectLightning);
extern EvtScript N(EVS_Attack_GroupSlam);
extern EvtScript N(EVS_Attack_TuffPuffSwarm);

extern ActorBlueprint A(tuff_puff);
extern Formation N(SmallTuffFormation);
extern Formation N(LargeTuffFormation);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_FACE        = 2,
    PRT_ARMS        = 3,
    PRT_UNUSED      = 4,
};

enum N(ActorVars) {
    AVAR_Flags                  = 0,
    AVAL_Flag_HasHealed         = 0x01,
    AVAR_Flag_DamageCombo       = 0x02,
    AVAR_Flag_WaitForChild      = 0x04,
    AVAR_Flag_LightningHit      = 0x08,
    AVAL_Dialogue_Request       = 0x10,
    AVAL_Dialogue_FullPower     = 0x20,
    AVAL_Dialogue_Praise        = 0x40,
    AVAL_Dialogue_Concerned     = 0x80,
    AVAR_NextMove               = 1,
    AVAL_Move_Basic_1           = 0,
    AVAL_Move_Breath_1          = 1,
    AVAL_Move_Basic_2           = 2,
    AVAL_Move_PreCharge_1       = 3,
    AVAL_Move_Charged_1         = 4,
    AVAL_Move_Basic_3           = 5,
    AVAL_Move_Breath_2          = 6,
    AVAL_Move_PreCharge_2       = 7,
    AVAL_Move_Charged_2         = 8,
    AVAL_Move_Basic_4           = 9,
    AVAL_Move_PreCharge_3       = 10,
    AVAL_Move_Charged_3         = 11,
    AVAL_Move_Desperation       = 12,
    AVAR_ChildBits              = 2,
    AVAR_WobbleMode             = 3,
    AVAR_ChargedJitterScriptID  = 4,
    AVAR_ChargedStaticEffect    = 5,
    AVAR_ScaleX                 = 6,
    AVAR_ScaleY                 = 7,
};

enum N(ActorParams) {
    DMG_WIND_6              = 7,
    DMG_WIND_5              = 6,
    DMG_WIND_4              = 5,
    DMG_WIND_3              = 4,
    DMG_WIND_2              = 3,
    DMG_WIND_1              = 2,
    DMG_SLAM                = 5,
    DMG_DIRECT_LIGHTNING    = 10,
    DMG_GROUND_LIGHTNING    = 12,
    DMG_GROUP_SLAM_BASE     = 5,
};

typedef struct SuctionPath {
    /* 0x00 */ Vec3f start;
    /* 0x0C */ Vec3f mid;
    /* 0x18 */ Vec3f end;
} SuctionPath; // size = 0x24

BSS SuctionPath N(SuctionPaths)[MAX_RUFF_PUFFS];

#include "common/StartRumbleWithParams.inc.c"

API_CALLABLE(N(SetHealthBarPos)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(ACTOR_HUFF_N_PUFF);

    actor->healthBarPos.x = actor->homePos.x + evt_get_variable(script, *args++);
    actor->healthBarPos.y = actor->homePos.y + evt_get_variable(script, *args++);
    actor->healthBarPos.z = actor->homePos.z;
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

API_CALLABLE(N(SetTuffPuffPos)) {
    Bytecode* args = script->ptrReadPos;

    Bytecode outVarX = *args++;
    f32 x = evt_get_float_variable(script, outVarX);
    Bytecode outVarY = *args++;
    f32 y = evt_get_float_variable(script, outVarY);
    Bytecode outVarZ = *args++;
    f32 z = evt_get_float_variable(script, outVarZ);

    f32 pitch = evt_get_float_variable(script, *args++);
    f32 yaw = evt_get_float_variable(script, *args++);
    f32 length = evt_get_float_variable(script, *args++);

    yaw -= 15.0f;
    x += length * cos_deg(pitch) * cos_deg(yaw);
    y += length * sin_deg(pitch);
    z -= length * cos_deg(pitch) * sin_deg(yaw);

    evt_set_float_variable(script, outVarX, x);
    evt_set_float_variable(script, outVarY, y);
    evt_set_float_variable(script, outVarZ, z);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(FindPlaceForTuffPuff)) {
    Bytecode* args = script->ptrReadPos;
    s32 flags = evt_get_variable(script, *args++);
    s32 validBits[MAX_RUFF_PUFFS];
    s32 count = 0;
    s32 selectedIdx;

    if (!(flags & (1 << 1))) {
        validBits[count++] = (1 << 1);
    }
    if (!(flags & (1 << 3))) {
        validBits[count++] = (1 << 3);
    }
    if (!(flags & (1 << 5))) {
        validBits[count++] = (1 << 5);
    }
    if (!(flags & (1 << 7))) {
        validBits[count++] = (1 << 7);
    }
    if (!(flags & (1 << 9))) {
        validBits[count++] = (1 << 9);
    }
    if (!(flags & (1 << 0))) {
        validBits[count++] = (1 << 0);
    }
    if (!(flags & (1 << 2))) {
        validBits[count++] = (1 << 2);
    }
    if (!(flags & (1 << 4))) {
        validBits[count++] = (1 << 4);
    }

    if (count == 0) {
        if (!(flags & (1 << 8))) {
            validBits[count++] = (1 << 8);
        }
        if (!(flags & (1 << 6))) {
            validBits[count++] = (1 << 6);
        }
    }

    if (count == 0) {
        selectedIdx = -1;
    } else {
        selectedIdx = validBits[rand_int(count - 1)];
    }

    evt_set_variable(script, *args++, selectedIdx);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetTuffPuffPriority)) {
    s32* actorID = &script->owner1.actorID;
    N(SmallTuffFormation)[0].priority = get_actor(*actorID)->turnPriority;
    N(LargeTuffFormation)[0].priority = get_actor(*actorID)->turnPriority;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(MakeSuctionPath)) {
    Bytecode* args = script->ptrReadPos;
    SuctionPath* path = &N(SuctionPaths)[evt_get_variable(script, *args++)];

    path->start.x = evt_get_variable(script, *args++);
    path->start.y = evt_get_variable(script, *args++);
    path->start.z = evt_get_variable(script, *args++);
    path->mid.x = -rand_int(20);
    path->mid.y = rand_int(40) + 60;
    path->mid.z = 0;
    path->end.x = evt_get_variable(script, *args++);
    path->end.y = evt_get_variable(script, *args++);
    path->end.z = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(HuffPuffBreath)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);
    f32 var6 = evt_get_float_variable(script, *args++);
    f32 var7 = evt_get_float_variable(script, *args++);
    s32 var8 = evt_get_variable(script, *args++);
    EffectInstance* effect = fx_huff_puff_breath(var1, var2, var3, var4, var5, var6, var7, var8);

    evt_set_variable(script, *args++, (s32)effect);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

API_CALLABLE(N(MakeSnakingStatic)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    script->varTablePtr[0] = fx_snaking_static(0, var1, var2, var3, var4 * 2.5f, 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetSnakingStaticPos)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);

    effect->data.snakingStatic->pos.x = posX;
    effect->data.snakingStatic->pos.y = posY;
    effect->data.snakingStatic->pos.z = posZ;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Atan2)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    f32 startX = evt_get_float_variable(script, *args++);
    f32 startZ = evt_get_float_variable(script, *args++);
    f32 endX = evt_get_float_variable(script, *args++);
    f32 endZ = evt_get_float_variable(script, *args++);

    evt_set_float_variable(script, outVar, atan2(startX, startZ, endX, endZ));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateLerp)) {
    Bytecode* args = script->ptrReadPos;
    s32 easing = evt_get_variable(script, *args++);
    f32 start = evt_get_float_variable(script, *args++);
    f32 end = evt_get_float_variable(script, *args++);
    s32 elapsed = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    evt_set_float_variable(script, *args++, update_lerp(easing, start, end, elapsed, duration));
    return ApiStatus_DONE2;
}

// first N words are actorIDs, next N are scriptIDs
s32 N(RuffPuffDataBuffer)[32] = {};

s32 N(BodyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim01,
    STATUS_KEY_STONE,     ANIM_HuffNPuff_Anim01,
    STATUS_KEY_SLEEP,     ANIM_HuffNPuff_Anim01,
    STATUS_KEY_POISON,    ANIM_HuffNPuff_Anim01,
    STATUS_KEY_STOP,      ANIM_HuffNPuff_Anim01,
    STATUS_KEY_STATIC,    ANIM_HuffNPuff_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_HuffNPuff_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_HuffNPuff_Anim01,
    STATUS_KEY_DIZZY,     ANIM_HuffNPuff_Anim01,
    STATUS_KEY_DIZZY,     ANIM_HuffNPuff_Anim01,
    STATUS_KEY_FEAR,      ANIM_HuffNPuff_Anim01,
    STATUS_END,
};

s32 N(FaceAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim02,
    STATUS_KEY_STONE,     ANIM_HuffNPuff_Anim02,
    STATUS_KEY_SLEEP,     ANIM_HuffNPuff_Anim02,
    STATUS_KEY_POISON,    ANIM_HuffNPuff_Anim02,
    STATUS_KEY_STOP,      ANIM_HuffNPuff_Anim02,
    STATUS_KEY_STATIC,    ANIM_HuffNPuff_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_HuffNPuff_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_HuffNPuff_Anim02,
    STATUS_KEY_DIZZY,     ANIM_HuffNPuff_Anim02,
    STATUS_KEY_DIZZY,     ANIM_HuffNPuff_Anim02,
    STATUS_KEY_FEAR,      ANIM_HuffNPuff_Anim02,
    STATUS_END,
};

s32 N(ArmAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim03,
    STATUS_KEY_STONE,     ANIM_HuffNPuff_Anim03,
    STATUS_KEY_SLEEP,     ANIM_HuffNPuff_Anim03,
    STATUS_KEY_POISON,    ANIM_HuffNPuff_Anim03,
    STATUS_KEY_STOP,      ANIM_HuffNPuff_Anim03,
    STATUS_KEY_STATIC,    ANIM_HuffNPuff_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_HuffNPuff_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_HuffNPuff_Anim03,
    STATUS_KEY_DIZZY,     ANIM_HuffNPuff_Anim03,
    STATUS_KEY_DIZZY,     ANIM_HuffNPuff_Anim03,
    STATUS_KEY_FEAR,      ANIM_HuffNPuff_Anim03,
    STATUS_END,
};

s32 N(ChargedBodyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim11,
    STATUS_END,
};

s32 N(ChargedFaceAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim12,
    STATUS_END,
};

s32 N(ChargedArmAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim13,
    STATUS_END,
};

s32 N(DummyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TuffPuff_Anim02,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,   99,
    ELEMENT_MYSTERY,  0,
    ELEMENT_JUMP,     0,
    ELEMENT_SMASH,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_DEFAULT_TARGET | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 40 },
        .opacity = 255,
        .idleAnimations = N(BodyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -15, -50 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_FACE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(FaceAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_ARMS,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(ArmAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_UNUSED,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(DummyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_HALF_HEIGHT,
    .type = ACTOR_TYPE_HUFF_N_PUFF,
    .level = ACTOR_LEVEL_HUFF_N_PUFF,
    .maxHP = 60,
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
    .size = { 125, 95 },
    .healthBarOffset = { -17, -31 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_1)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChildBits, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, 100)
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, 100)
    ExecWait(N(EVS_UpdateSize))
    Return
    End
};

EvtScript N(EVS_UpdateSize) = {
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    Mul(LVar0, 145)
    Mul(LVar1, 135)
    Div(LVar0, 100)
    Div(LVar1, 100)
    Call(SetActorSize, ACTOR_HUFF_N_PUFF, LVar1, LVar0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    Mul(LVar0, -10)
    Mul(LVar1, 40)
    Div(LVar0, 100)
    Div(LVar1, 100)
    Call(SetTargetOffset, ACTOR_HUFF_N_PUFF, PRT_MAIN, LVar0, LVar1)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    Mul(LVar0, -15)
    Mul(LVar1, -50)
    Div(LVar0, 100)
    Div(LVar1, 100)
    Call(SetProjectileTargetOffset, ACTOR_HUFF_N_PUFF, PRT_MAIN, LVar0, LVar1)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    Mul(LVar0, -17)
    Mul(LVar1, -31)
    Div(LVar0, 100)
    Div(LVar1, 100)
    Call(N(SetHealthBarPos), LVar0, LVar1)
    Return
    End
};

EvtScript N(EVS_UpdateChargedJitter) = {
    Set(LFlag0, FALSE)
    Set(LVarA, 0)
    Set(LVarB, 0)
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
        Switch(LVar0)
            CaseOrEq(AVAL_Move_PreCharge_1)
            CaseOrEq(AVAL_Move_Charged_1)
            CaseOrEq(AVAL_Move_PreCharge_3)
            CaseOrEq(AVAL_Move_Charged_3)
                IfEq(LFlag0, FALSE)
                    Call(RandInt, 2, LVarA)
                    Call(RandInt, 2, LVarB)
                    Set(LFlag0, TRUE)
                Else
                    Mul(LVarA, -1)
                    Mul(LVarB, -1)
                    Set(LFlag0, FALSE)
                EndIf
            EndCaseGroup
            CaseOrEq(AVAL_Move_PreCharge_2)
            CaseOrEq(AVAL_Move_Charged_2)
                IfEq(LFlag0, FALSE)
                    Call(RandInt, 1, LVarA)
                    Set(LFlag0, TRUE)
                Else
                    Mul(LVarA, -1)
                    Set(LFlag0, FALSE)
                EndIf
            EndCaseGroup
        EndSwitch
        Call(SetActorDispOffset, ACTOR_SELF, LVarA, LVarB, 0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Set(LVarF, 0)
    Loop(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_WobbleMode, LVarA)
        Switch(LVarA)
            CaseEq(0)
                Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.97), Float(1.03), 15, 0, 0)
                Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.03), Float(0.97), 15, 0, 0)
                Add(LVarF, 1)
            CaseEq(1)
                Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.95), Float(1.05), 15, 0, 0)
                Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.05), Float(0.95), 15, 0, 0)
                Add(LVarF, 3)
            CaseEq(2)
                Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.9), Float(1.1), 15, 0, 0)
                Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.1), Float(0.9), 15, 0, 0)
                Add(LVarF, 5)
        EndSwitch
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
        DivF(LVar2, Float(100.0))
        DivF(LVar3, Float(100.0))
        MulF(LVar1, LVar2)
        MulF(LVar0, LVar3)
        Call(SetActorScale, ACTOR_SELF, LVar1, LVar0, Float(1.0))
        IfGe(LVarF, 30)
            Set(LVarF, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(SmallTuffFormation) = {
    ACTOR_BY_POS(A(tuff_puff), N(SummonPos), 0, FALSE),
};

Formation N(LargeTuffFormation) = {
    ACTOR_BY_POS(A(tuff_puff), N(SummonPos), 0, TRUE),
};

EvtScript N(EVS_TrySpawningRuffPuff) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(GetLastDamage, ACTOR_SELF, LVar9)
    IfLe(LVar9, 0)
        Return
    EndIf
    Call(GetBattleFlags, LVar0)
    IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
        IfGt(LVar9, 8)
            Set(LVar9, 8)
        EndIf
    Else
        IfGt(LVar9, 4)
            Set(LVar9, 4)
        EndIf
    EndIf
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_DEATH)
        CaseOrEq(EVENT_BURN_DEATH)
            Return
        EndCaseGroup
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    Call(GetLastDamage, ACTOR_SELF, LVar8)
    Mul(LVar8, 1)
    Sub(LVar0, LVar8)
    IfLt(LVar0, 50)
        Set(LVar0, 50)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
    Call(GetLastDamage, ACTOR_SELF, LVar8)
    Mul(LVar8, 1)
    Sub(LVar0, LVar8)
    IfLt(LVar0, 50)
        Set(LVar0, 50)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
    ExecWait(N(EVS_UpdateSize))
    Set(LVarA, 0)
    Call(GetBattleFlags, LVar0)
    IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
        Set(LVar0, LVar9)
        IfGt(LVar0, 1)
            Set(LVarA, LVar0)
            Div(LVarA, 2)
            Set(LVar9, LVar0)
            Mod(LVar9, 2)
            Add(LVar9, LVarA)
        EndIf
    EndIf
    Loop(LVar9)
        Call(N(SetTuffPuffPriority))
        IfGt(LVarA, 0)
            Sub(LVarA, 1)
            Call(SummonEnemy, Ref(N(LargeTuffFormation)), FALSE)
            Call(SetActorVar, LVar0, AVAR_TuffPuff_HealValue, 2)
        Else
            Call(SummonEnemy, Ref(N(SmallTuffFormation)), FALSE)
            Call(SetActorVar, LVar0, AVAR_TuffPuff_HealValue, 1)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar1)
        Call(N(FindPlaceForTuffPuff), LVar1, LVar2)
        Switch(LVar2)

            #define HNP_REGISTER_CHILD(idx) \
                CaseEq(1 << idx) \
                    BitwiseOrConst(LVar1, 1 << idx) \
                    Set(LVar2, idx) \
                    Set(ArrayVar(idx), LVar0)

            // try registering the child with each position, until we find the one on LVar2
            FOR_CHILDREN_ORDERED(HNP_REGISTER_CHILD)

            CaseDefault
                Set(LVar2, -1)
        EndSwitch
        Call(SetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar1)
        Call(PlaySoundAtActor, LVar0, SOUND_OPEN_SHELL)
        Thread
            Set(LVar3, LVar0)
            Call(MakeLerp, 150, 255, 15, EASING_QUADRATIC_IN)
            Label(123)
                Call(UpdateLerp)
                Call(SetPartAlpha, LVar3, 1, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(123)
                EndIf
            Call(SetPartAlpha, LVar3, 1, 255)
        EndThread
        IfNe(LVar2, -1)
            Call(CopyStatusEffects, ACTOR_SELF, LVar0)
            Call(CopyBuffs, ACTOR_SELF, LVar0)
            Call(SetActorVar, LVar0, AVAR_TuffPuff_Index, LVar2)
            Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Call(SetActorPos, LVar0, LVar3, LVar4, LVar5)
            Add(LVar3, -5)
            Add(LVar4, 0)
            Add(LVar5, 0)
            Mul(LVar2, 36)
            Add(LVar2, 0)
            Call(N(SetTuffPuffPos), LVar3, LVar4, LVar5, LVar2, Float(0.0), Float(50.0))
            Thread
                Call(SetActorJumpGravity, LVar0, Float(0.8))
                Call(SetGoalPos, LVar0, LVar3, LVar4, LVar5)
                Call(JumpToGoal, LVar0, 30, FALSE, FALSE, FALSE)
                Call(ForceHomePos, LVar0, LVar3, LVar4, LVar5)
                Call(HPBarToHome, LVar0)
            EndThread
        Else
            Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Call(SetActorPos, LVar0, LVar3, LVar4, LVar5)
            Call(RandInt, 200, LVar6)
            Sub(LVar6, 100)
            Add(LVar3, LVar6)
            Add(LVar5, 10)
            Thread
                Call(SetActorJumpGravity, LVar0, Float(0.8))
                Call(SetGoalPos, LVar0, LVar3, -30, LVar5)
                Call(JumpToGoal, LVar0, 40, FALSE, FALSE, FALSE)
                Call(RemoveActor, LVar0)
            EndThread
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_HuffNPuff_Hit) = {
    ExecWait(N(EVS_TrySpawningRuffPuff))
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_Charged_1)
        CaseOrEq(AVAL_Move_Charged_2)
        CaseOrEq(AVAL_Move_Charged_3)
            SetConst(LVar2, ANIM_HuffNPuff_Anim11)
            SetConst(LVar3, ANIM_HuffNPuff_Anim12)
            SetConst(LVar4, ANIM_HuffNPuff_Anim13)
        EndCaseGroup
        CaseDefault
            SetConst(LVar2, ANIM_HuffNPuff_Anim07)
            SetConst(LVar3, ANIM_HuffNPuff_Anim08)
            SetConst(LVar4, ANIM_HuffNPuff_Anim09)
    EndSwitch
    Thread
        Set(LVar0, PRT_MAIN)
        Set(LVar1, LVar2)
        ExecWait(EVS_Enemy_Hit)
    EndThread
    Thread
        Set(LVar0, PRT_FACE)
        Set(LVar1, LVar3)
        ExecWait(EVS_Enemy_Hit)
    EndThread
    Thread
        Set(LVar0, PRT_ARMS)
        Set(LVar1, LVar4)
        ExecWait(EVS_Enemy_Hit)
    EndThread
    Wait(30)
    Return
    End
};

EvtScript N(EVS_HuffNPuff_Death) = {
    UseArray(N(RuffPuffDataBuffer))
    Label(0)
        Call(GetBattleFlags, LVar0)
        IfFlag(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            Wait(1)
            Goto(0)
        EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_KILL_CHILD(idx) \
        IfFlag(LVar0, 1 << idx) \
            Call(SetDamageSource, DMG_SRC_DEFAULT) \
            Call(DispatchEvent, ArrayVar(idx), EVENT_DEATH) \
        EndIf

    // kill any remaining Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_KILL_CHILD)

    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_Charged_1)
        CaseOrEq(AVAL_Move_Charged_2)
        CaseOrEq(AVAL_Move_Charged_3)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVar0)
            KillThread(LVar0)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
            Call(RemoveEffect, LVar0)
            Call(StopSound, SOUND_CHARGE_LIGHTNING)
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim08)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim09)
    Set(LVar0, PRT_MAIN)
    Set(LVar1, ANIM_HuffNPuff_Anim07)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

EvtScript N(EVS_HuffNPuff_BurnHit) = {
    ExecWait(N(EVS_TrySpawningRuffPuff))
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_Charged_1)
        CaseOrEq(AVAL_Move_Charged_2)
        CaseOrEq(AVAL_Move_Charged_3)
            SetConst(LVar2, ANIM_HuffNPuff_Anim11)
            SetConst(LVar3, ANIM_HuffNPuff_Anim12)
            SetConst(LVar4, ANIM_HuffNPuff_Anim13)
        EndCaseGroup
        CaseDefault
            SetConst(LVar2, ANIM_HuffNPuff_Anim23)
            SetConst(LVar3, ANIM_HuffNPuff_Anim24)
            SetConst(LVar4, ANIM_HuffNPuff_Anim25)
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, LVar3)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, LVar4)
    Wait(20)
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_Charged_1)
        CaseOrEq(AVAL_Move_Charged_2)
        CaseOrEq(AVAL_Move_Charged_3)
            SetConst(LVar2, ANIM_HuffNPuff_Anim11)
            SetConst(LVar3, ANIM_HuffNPuff_Anim12)
            SetConst(LVar4, ANIM_HuffNPuff_Anim13)
        EndCaseGroup
        CaseDefault
            SetConst(LVar2, ANIM_HuffNPuff_Anim26)
            SetConst(LVar3, ANIM_HuffNPuff_Anim27)
            SetConst(LVar4, ANIM_HuffNPuff_Anim28)
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, LVar3)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, LVar4)
    Wait(10)
    Return
    End
};

EvtScript N(EVS_HuffNPuff_BurnDeath) = {
    UseArray(N(RuffPuffDataBuffer))
    Label(0)
        Call(GetBattleFlags, LVar0)
        IfFlag(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            Wait(1)
            Goto(0)
        EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_KILL_CHILD(idx) \
        IfFlag(LVar0, 1 << idx) \
            Call(DispatchEvent, ArrayVar(idx), EVENT_DEATH) \
        EndIf

    // kill any remaining Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_KILL_CHILD)

    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_Charged_1)
        CaseOrEq(AVAL_Move_Charged_2)
        CaseOrEq(AVAL_Move_Charged_3)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVar0)
            KillThread(LVar0)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
            Call(RemoveEffect, LVar0)
            Call(StopSound, SOUND_CHARGE_LIGHTNING)
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim27)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim28)
    Set(LVar0, PRT_MAIN)
    Set(LVar1, ANIM_HuffNPuff_Anim26)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

EvtScript N(EVS_HuffNPuff_NoDamage) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_Charged_1)
        CaseOrEq(AVAL_Move_Charged_2)
        CaseOrEq(AVAL_Move_Charged_3)
            SetConst(LVar2, ANIM_HuffNPuff_Anim11)
            SetConst(LVar3, ANIM_HuffNPuff_Anim12)
            SetConst(LVar4, ANIM_HuffNPuff_Anim13)
        EndCaseGroup
        CaseDefault
            SetConst(LVar2, ANIM_HuffNPuff_Anim01)
            SetConst(LVar3, ANIM_HuffNPuff_Anim02)
            SetConst(LVar4, ANIM_HuffNPuff_Anim03)
    EndSwitch
    Thread
        Set(LVar0, PRT_MAIN)
        Set(LVar1, LVar2)
        ExecWait(EVS_Enemy_NoDamageHit)
    EndThread
    Thread
        Set(LVar0, PRT_FACE)
        Set(LVar1, LVar3)
        ExecWait(EVS_Enemy_NoDamageHit)
    EndThread
    Thread
        Set(LVar0, PRT_ARMS)
        Set(LVar1, LVar4)
        ExecWait(EVS_Enemy_NoDamageHit)
    EndThread
    Wait(30)
    Return
    End
};

EvtScript N(EVS_IncreaseWobble) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_WobbleMode, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 1)
        CaseEq(1)
            Call(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 2)
        CaseEq(2)
            // can't increase any more
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            ExecWait(N(EVS_IncreaseWobble))
            ExecWait(N(EVS_HuffNPuff_Hit))
        CaseEq(EVENT_HIT)
            ExecWait(N(EVS_IncreaseWobble))
            ExecWait(N(EVS_HuffNPuff_Hit))
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AVAR_Flag_DamageCombo)
            Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            Call(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
        CaseEq(EVENT_BURN_HIT)
            ExecWait(N(EVS_IncreaseWobble))
            ExecWait(N(EVS_HuffNPuff_BurnHit))
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AVAR_Flag_DamageCombo)
            Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            Call(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
        CaseEq(EVENT_BURN_DEATH)
            ExecWait(N(EVS_IncreaseWobble))
            ExecWait(N(EVS_HuffNPuff_BurnHit))
            ExecWait(N(EVS_HuffNPuff_BurnDeath))
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            ExecWait(N(EVS_HuffNPuff_NoDamage))
        CaseEq(EVENT_IMMUNE)
            ExecWait(N(EVS_HuffNPuff_NoDamage))
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AVAR_Flag_DamageCombo)
            Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
        CaseEq(EVENT_DEATH)
            ExecWait(N(EVS_IncreaseWobble))
            ExecWait(N(EVS_HuffNPuff_Hit))
            ExecWait(N(EVS_HuffNPuff_Death))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            ExecWait(N(EVS_IncreaseWobble))
        CaseEq(EVENT_AIR_LIFT_FAILED)
            ExecWait(N(EVS_HuffNPuff_NoDamage))
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AVAR_Flag_DamageCombo)
            Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            Call(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Dialogue_PummelPermission) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        IfFlag(LVar0, 1 << idx) \
            Set(LVar0, ArrayVar(idx)) \
            Goto(0) \
        EndIf

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    Goto(1)
    // found a Tuff Puff to speak
    Label(0)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
    Call(BattleCamTargetActor, LVar0)
    Call(SetBattleCamDist, 300)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, LVar0, FALSE)
    Call(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    IfEq(LVar1, 0)
        Call(SetAnimation, LVar0, 1, ANIM_TuffPuff_Anim09)
        Call(ActorSpeak, MSG_CH6_00CF, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    Else
        Call(ActorSpeak, MSG_CH6_00CF, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EndIf
    Call(UseIdleAnimation, LVar0, TRUE)
    Wait(20)
    // Huff N Puff replies
    Label(1)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamDist, 180)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim2D)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim2E)
    Call(ActorSpeak, MSG_CH6_00D0, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim2C, ANIM_HuffNPuff_Anim01)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Return
    End
};

EvtScript N(EVS_Dialogue_FullPower) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamDist, 180)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim2D)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim2E)
    Call(ActorSpeak, MSG_CH6_00D1, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim2C, ANIM_HuffNPuff_Anim01)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        IfFlag(LVar0, 1 << idx) \
            Set(LVar0, ArrayVar(idx)) \
            Goto(0) \
        EndIf

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    Goto(1)
    // found a Tuff Puff to speak
    Label(0)
    Call(BattleCamTargetActor, LVar0)
    Call(SetBattleCamDist, 300)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    IfLt(LVar1, LVar4)
        SetF(LVar7, Float(0.0))
        Loop(10)
            AddF(LVar7, Float(18.0))
            Call(SetActorYaw, LVar0, LVar7)
            Wait(1)
        EndLoop
    EndIf
    Call(UseIdleAnimation, LVar0, FALSE)
    Call(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    IfEq(LVar1, 0)
        Call(SetAnimation, LVar0, 1, ANIM_TuffPuff_Anim09)
        Call(ActorSpeak, MSG_CH6_00D2, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    Else
        Call(ActorSpeak, MSG_CH6_00D2, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EndIf
    Call(UseIdleAnimation, LVar0, TRUE)
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    IfLt(LVar1, LVar4)
        SetF(LVar7, Float(180.0))
        Loop(10)
            SubF(LVar7, Float(18.0))
            Call(SetActorYaw, LVar0, LVar7)
            Wait(1)
        EndLoop
    EndIf
    // done speaking
    Label(1)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Return
    End
};

EvtScript N(EVS_Dialogue_PraiseHuff) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamDist, 180)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim18)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim19)
    Call(ActorSpeak, MSG_CH6_00D3, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim17, ANIM_HuffNPuff_Anim17)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        IfFlag(LVar0, 1 << idx) \
            Set(LVar0, ArrayVar(idx)) \
            Goto(0) \
        EndIf

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    Goto(1)
    // found a Tuff Puff to speak
    Label(0)
    Call(BattleCamTargetActor, LVar0)
    Call(SetBattleCamDist, 300)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    IfLt(LVar1, LVar4)
        SetF(LVar7, Float(0.0))
        Loop(10)
            AddF(LVar7, Float(18.0))
            Call(SetActorYaw, LVar0, LVar7)
            Wait(1)
        EndLoop
    EndIf
    Call(UseIdleAnimation, LVar0, FALSE)
    Call(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    IfEq(LVar1, 0)
        Call(ActorSpeak, MSG_CH6_00D4, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    Else
        Call(ActorSpeak, MSG_CH6_00D4, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EndIf
    Call(UseIdleAnimation, LVar0, TRUE)
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    IfLt(LVar1, LVar4)
        SetF(LVar7, Float(180.0))
        Loop(10)
            SubF(LVar7, Float(18.0))
            Call(SetActorYaw, LVar0, LVar7)
            Wait(1)
        EndLoop
    EndIf
    // done speaking
    Label(1)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Return
    End
};

EvtScript N(EVS_Dialogue_Concerned) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamDist, 180)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim24)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim25)
    Call(ActorSpeak, MSG_CH6_00D5, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim23, ANIM_HuffNPuff_Anim23)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        IfFlag(LVar0, 1 << idx) \
            Set(LVar0, ArrayVar(idx)) \
            Goto(0) \
        EndIf

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    Goto(1)
    // found a Tuff Puff to speak
    Label(0)
    Call(BattleCamTargetActor, LVar0)
    Call(SetBattleCamDist, 300)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, LVar0, FALSE)
    Call(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    IfEq(LVar1, 0)
        Call(ActorSpeak, MSG_CH6_00D6, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    Else
        Call(ActorSpeak, MSG_CH6_00D6, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EndIf
    Call(UseIdleAnimation, LVar0, TRUE)
    // Huff N Puff replies
    Label(1)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamDist, 180)
    Call(SetBattleCamOffsetY, -10)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim24)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim25)
    Call(ActorSpeak, MSG_CH6_00D7, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim23, ANIM_HuffNPuff_Anim23)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    // if charged with less than 5 HP, switch upcoming move to a group slam
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Move_Charged_1)
        CaseOrEq(AVAL_Move_Charged_2)
        CaseOrEq(AVAL_Move_Charged_3)
        EndCaseGroup
        CaseDefault
            Call(GetActorHP, ACTOR_SELF, LVar0)
            IfLe(LVar0, 5)
                Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Desperation)
            EndIf
    EndSwitch
    // try dialogue before charging for the first time
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Move_PreCharge_1)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            IfNotFlag(LVar0, AVAL_Dialogue_FullPower)
                Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                BitwiseOrConst(LVar0, AVAL_Dialogue_FullPower)
                Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                ExecWait(N(EVS_Dialogue_FullPower))
            EndIf
    EndSwitch
    // try Tuff Puff swarm attack
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)
    IfNe(LVar0, 0)
        Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
        IfNotFlag(LVar0, AVAL_Dialogue_Request)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            BitwiseOrConst(LVar0, AVAL_Dialogue_Request)
            Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            ExecWait(N(EVS_Dialogue_PummelPermission))
        EndIf
        ExecWait(N(EVS_Attack_TuffPuffSwarm))
    EndIf
    Call(GetPlayerHP, LVar0)
    IfEq(LVar0, 0)
        Return
    EndIf
    // try dialogue before first group slam
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Move_Desperation)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            IfNotFlag(LVar0, AVAL_Dialogue_Concerned)
                Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                BitwiseOrConst(LVar0, AVAL_Dialogue_Concerned)
                Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                ExecWait(N(EVS_Dialogue_Concerned))
            EndIf
    EndSwitch
    // select move according to fixed rotation through states
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Move_Basic_1)
            ExecWait(N(EVS_Move_HealOrSlam))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Breath_1)
        CaseEq(AVAL_Move_Breath_1)
            ExecWait(N(EVS_Move_HurricaneBreath))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_2)
        CaseEq(AVAL_Move_Basic_2)
            ExecWait(N(EVS_Move_HealOrSlam))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_PreCharge_1)
        CaseEq(AVAL_Move_PreCharge_1)
            ExecWait(N(EVS_Move_ChargeForGround))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Charged_1)
        CaseEq(AVAL_Move_Charged_1)
            ExecWait(N(EVS_Attack_GroundLightning))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_3)
        CaseEq(AVAL_Move_Basic_3)
            ExecWait(N(EVS_Move_HealOrSlam))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Breath_2)
        CaseEq(AVAL_Move_Breath_2)
            ExecWait(N(EVS_Move_HurricaneBreath))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_PreCharge_2)
        CaseEq(AVAL_Move_PreCharge_2)
            ExecWait(N(EVS_Move_ChargeForDirect))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Charged_2)
        CaseEq(AVAL_Move_Charged_2)
            ExecWait(N(EVS_Attack_DirectLightning))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_4)
        CaseEq(AVAL_Move_Basic_4)
            ExecWait(N(EVS_Move_HealOrSlam))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_PreCharge_3)
        CaseEq(AVAL_Move_PreCharge_3)
            ExecWait(N(EVS_Move_ChargeForGround))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Charged_3)
        CaseEq(AVAL_Move_Charged_3)
            ExecWait(N(EVS_Attack_GroundLightning))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_1)
        CaseEq(AVAL_Move_Desperation)
            ExecWait(N(EVS_Attack_GroupSlam))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
        CaseEq(PHASE_ENEMY_BEGIN)
        CaseEq(PHASE_ENEMY_END)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            IfFlag(LVar0, AVAR_Flag_LightningHit)
                IfNotFlag(LVar0, AVAL_Dialogue_Praise)
                    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                    BitwiseOrConst(LVar0, AVAL_Dialogue_Praise)
                    Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                    ExecWait(N(EVS_Dialogue_PraiseHuff))
                EndIf
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_BodySlam) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(AddBattleCamDist, -200)
    Call(SetBattleCamOffsetY, -30)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    SetF(LVar2, Float(62.5))
    SetF(LVar3, Float(47.5))
    MulF(LVar2, LVar0)
    MulF(LVar3, LVar1)
    DivF(LVar2, Float(100.0))
    DivF(LVar3, Float(100.0))
    Call(AddGoalPos, ACTOR_SELF, LVar2, LVar3, 0)
    Call(AddGoalPos, ACTOR_SELF, 0, 20, 0)
    Call(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LARGE_ACTOR_JUMP)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0B)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0C)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim0D)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar5, LVar6, LVar7)
            Call(SetGoalPos, ACTOR_SELF, LVar5, LVar3, LVar7)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(0.8))
            EndThread
            IfEq(LVar0, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(AddGoalPos, ACTOR_SELF, -80, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 25, FALSE, FALSE, FALSE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.6))
            EndThread
            Call(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.4))
            EndThread
            Call(AddGoalPos, ACTOR_SELF, -30, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.2))
            EndThread
            Call(AddGoalPos, ACTOR_SELF, -20, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 80, -20, EASING_SIN_OUT)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0B)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0C)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim0D)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 0, LVar3, 5)
    Call(AddGoalPos, ACTOR_SELF, 0, -30, 0)
    Call(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
    Call(SetDamageSource, DMG_SRC_CRUSH)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    Mul(LVar0, 100)
    Div(LVar0, LVar1)
    Switch(LVar0)
        CaseLe(20)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        CaseLe(40)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        CaseLe(60)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        CaseLe(80)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        CaseDefault
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 20, Float(1.0))
            EndThread
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetBattleFlags, LVar0)
            IfNotFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_STONE)
                    Thread
                        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                        Add(LVar1, 10)
                        Wait(55)
                        PlayEffect(EFFECT_CLOUD_PUFF, LVar0, LVar1, LVar2, 0, 0)
                    EndThread
                EndIf
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            Call(JumpWithBounce, ACTOR_SELF, 20, Float(4.0))
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_RuffPuff_Inhale) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(SetOwnerID, LVar0) // note: ownership transferred to Tuff Puff actor here
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    Call(GetActorPos, ACTOR_HUFF_N_PUFF, LVar5, LVar6, LVar7)
    Add(LVar5, -13)
    Add(LVar6, 0)
    Add(LVar7, 0)
    Call(N(MakeSuctionPath), LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7)
    Thread
        Call(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 1)
        Wait(10)
        Call(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 2)
        Call(GetActorVar, ACTOR_SELF, AVAR_TuffPuff_IsLarge, LVar0)
        IfEq(LVar0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim12)
        Else
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim13)
        EndIf
    EndThread
    Wait(15)
    Thread
        Wait(35)
        Call(MakeLerp, 255, 0, 10, EASING_LINEAR)
        Label(10)
            Call(UpdateLerp)
            Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EndThread
    Switch(LVar1)

        #define HNP_LOAD_SUCTION_PATH(idx) \
            CaseEq(idx) \
                Call(LoadPath, 40, Ref(N(SuctionPaths)[idx]), 3, EASING_QUADRATIC_IN)

        // select the suction path for this Tuff Puff
        FOR_CHILDREN_ORDERED(HNP_LOAD_SUCTION_PATH)

    EndSwitch
    Label(0)
        Call(GetNextPathPos)
        Call(SetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(GetEnemyMaxHP, ACTOR_SELF, LVarA)
    Mul(LVarA, 1)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    Add(LVar0, LVarA)
    IfGt(LVar0, 100)
        Set(LVar0, 100)
    EndIf
    Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar0)
    Add(LVar0, LVarA)
    IfGt(LVar0, 100)
        Set(LVar0, 100)
    EndIf
    Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar0)
    ExecWait(N(EVS_UpdateSize))
    Wait(10)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Move_HealOrSlam) = {
    UseArray(N(RuffPuffDataBuffer))
    // use basic attack if no Tuff Puffs are present
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar9)
    IfEq(LVar9, 0)
        ExecWait(N(EVS_Attack_BodySlam))
        Return
    EndIf
    Set(LVarA, 0)

    #define HNP_ADD_HEAL_VALUE(idx) \
        IfFlag(LVar9, 1 << idx) \
            Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_HealValue, LVarB) \
            Add(LVarA, LVarB) \
        EndIf

    // add heal values from Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_ADD_HEAL_VALUE)

    // 50% chance to use basic attack if healing would give 2 or less HP and Huff has healed before
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
    IfFlag(LVar0, AVAL_Flag_HasHealed)
        IfLe(LVarA, 2)
            Call(RandInt, 100, LVarB)
            IfLt(LVarB, 50)
                ExecWait(N(EVS_Attack_BodySlam))
                Return
            EndIf
        EndIf
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_INHALE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1B)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1C)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -13)
    Add(LVar1, 0)
    Add(LVar2, 0)
    Call(N(HuffPuffBreath), 0, LVar0, LVar1, LVar2, Float(180.0), Float(-1.0), Float(1.2), 0, LVar8)
    Call(N(StartRumbleWithParams), 80, 220)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 110, Float(0.3))
    EndThread
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    Set(LVar1, 0)

    #define HNP_INHALE_CHILD(idx) \
        IfFlag(LVar9, 1 << idx) \
            Set(LVar0, ArrayVar(idx)) \
            ExecGetTID(N(EVS_RuffPuff_Inhale), LVar7) \
            Add(LVar1, 1) \
            Wait(5) \
        EndIf

    // inhale each Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_INHALE_CHILD)

    Label(0)
    IsThreadRunning(LVar7, LVar0)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(RemoveEffect, LVar8)
    Call(StopSound, SOUND_HUFF_N_PUFF_INHALE)
    Call(StopSound, SOUND_BIG_POWER_UP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim17)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim18)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim19)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, LVar3, 0)
    Add(LVar0, 20)
    PlayEffect(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVarA, 0)
    Call(GetActorHP, ACTOR_SELF, LVarB)
    Add(LVarB, LVarA)
    Call(SetEnemyHP, ACTOR_SELF, LVarB)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChildBits, 0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
    BitwiseOrConst(LVar0, AVAL_Flag_HasHealed)
    Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_HurricaneBreath) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1B)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1C)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
    MulF(LVar3, Float(-13.0))
    MulF(LVar4, Float(0.0))
    DivF(LVar3, Float(100.0))
    DivF(LVar4, Float(100.0))
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    PlayEffect(EFFECT_HUFF_PUFF_BREATH, 1, LVar0, LVar1, LVar2, Float(190.0), Float(-1.0), Float(1.5), 100, 0)
    Call(N(StartRumbleWithParams), 80, 150)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 75, Float(0.3))
    EndThread
    Thread
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        Set(LVar3, LVar2)
        Add(LVar3, 25)
        Call(MakeLerp, LVar2, LVar3, 90, EASING_SIN_OUT)
        Label(0)
            Call(UpdateLerp)
            Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
    EndThread
    Thread
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
        Set(LVar3, LVar2)
        Add(LVar3, 25)
        Call(MakeLerp, LVar2, LVar3, 90, EASING_SIN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_INHALE)
    Thread
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EndThread
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 20)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 300)
    Call(SetBattleCamOffsetY, 20)
    Call(MoveBattleCamOver, 180)
    Wait(90)
    Call(StopSound, SOUND_HUFF_N_PUFF_INHALE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1D)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1D)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1E)
    Wait(60)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim20)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim21)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim22)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_WIND_LOOP)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Set(LVarA, LVar0)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Thread
                Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
                Set(LVar3, LVar2)
                Sub(LVar3, 25)
                Call(MakeLerp, LVar2, LVar3, 40, EASING_CUBIC_IN)
                Label(2)
                    Call(UpdateLerp)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
                    Wait(1)
                    IfEq(LVar1, 1)
                        Goto(2)
                    EndIf
            EndThread
            Thread
                Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
                Set(LVar3, LVar2)
                Sub(LVar3, 25)
                Call(MakeLerp, LVar2, LVar3, 40, EASING_CUBIC_IN)
                Label(3)
                    Call(UpdateLerp)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
                    Wait(1)
                    IfEq(LVar1, 1)
                        Goto(3)
                    EndIf
            EndThread
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
            Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
            MulF(LVar3, Float(-20.0))
            MulF(LVar4, Float(-20.0))
            DivF(LVar3, Float(100.0))
            DivF(LVar4, Float(100.0))
            Add(LVar0, LVar3)
            Add(LVar1, LVar4)
            PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, Float(190.0), Float(1.5), Float(1.0), 40, 0)
            Call(N(StartRumbleWithParams), 80, 60)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 30, Float(0.3))
            EndThread
            Loop(10)
                Call(RandInt, 150, LVar3)
                Call(RandInt, 100, LVar4)
                Add(LVar3, 50)
                SetF(LVar4, Float(5.0))
                Call(RandInt, 4, LVar5)
                AddF(LVar4, LVar5)
                DivF(LVar4, Float(10.0))
                SetF(LVar5, Float(100.0))
                Call(RandInt, 40, LVar6)
                AddF(LVar5, LVar6)
                DivF(LVar5, Float(10.0))
                PlayEffect(EFFECT_MOVING_CLOUD, 0, 200, LVar3, 5, -200, LVar4, 5, LVar5, LVar4, 0)
                Call(RandInt, 5, LVar0)
                Add(LVar0, 5)
                Wait(LVar0)
            EndLoop
            Wait(20)
            Call(StopSound, SOUND_HEAVY_WIND_LOOP)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            Wait(20)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_STONE)
        Call(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 180)
        Call(ShowActionHud, TRUE)
        Call(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
        Call(action_command_whirlwind_init, 0)
        Call(SetupMashMeter, 5, 20, 40, 60, 80, 100)
        Wait(10)
        Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        Call(action_command_whirlwind_start, 0, 200 * DT, 3)
        Thread
            Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            Set(LVar3, LVar2)
            Sub(LVar3, 25)
            Call(MakeLerp, LVar2, LVar3, 200, EASING_CUBIC_IN)
            Label(4)
                Call(UpdateLerp)
                Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(4)
                EndIf
        EndThread
        Thread
            Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
            Set(LVar3, LVar2)
            Sub(LVar3, 25)
            Call(MakeLerp, LVar2, LVar3, 200, EASING_CUBIC_IN)
            Label(5)
                Call(UpdateLerp)
                Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(5)
                EndIf
        EndThread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
        MulF(LVar3, Float(-20.0))
        MulF(LVar4, Float(-20.0))
        DivF(LVar3, Float(100.0))
        DivF(LVar4, Float(100.0))
        Add(LVar0, LVar3)
        Add(LVar1, LVar4)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, Float(190.0), Float(1.5), Float(1.0), 200, 0)
        Call(N(StartRumbleWithParams), 100, 350)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 175, Float(0.3))
        EndThread
        Thread
            Loop(25)
                Call(RandInt, 150, LVar3)
                Call(RandInt, 100, LVar4)
                Add(LVar3, 50)
                SetF(LVar4, Float(5.0))
                Call(RandInt, 4, LVar5)
                AddF(LVar4, LVar5)
                DivF(LVar4, Float(10.0))
                SetF(LVar5, Float(100.0))
                Call(RandInt, 40, LVar6)
                AddF(LVar5, LVar6)
                DivF(LVar5, Float(10.0))
                PlayEffect(EFFECT_MOVING_CLOUD, 0, 200, LVar3, 5, -200, LVar4, 5, LVar5, LVar4, 0)
                Call(RandInt, 5, LVar0)
                Add(LVar0, 5)
                Wait(LVar0)
            EndLoop
        EndThread
        Call(MakeLerp, 0, 7200, 200, EASING_SIN_OUT)
        Label(10)
            Call(UpdateLerp)
            Call(SetActorYaw, ACTOR_PLAYER, LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Call(GetActionQuality, LVar1)
    Else
        Thread
            Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            Set(LVar3, LVar2)
            Sub(LVar3, 25)
            Call(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
            Label(6)
                Call(UpdateLerp)
                Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(6)
                EndIf
        EndThread
        Thread
            Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
            Set(LVar3, LVar2)
            Sub(LVar3, 25)
            Call(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
            Label(7)
                Call(UpdateLerp)
                Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(7)
                EndIf
        EndThread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
        MulF(LVar3, Float(-20.0))
        MulF(LVar4, Float(-20.0))
        DivF(LVar3, Float(100.0))
        DivF(LVar4, Float(100.0))
        Add(LVar0, LVar3)
        Add(LVar1, LVar4)
        PlayEffect(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, Float(190.0), Float(1.5), Float(1.0), 100, 0)
        Call(N(StartRumbleWithParams), 100, 200)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 100, Float(0.3))
        EndThread
        Thread
            Loop(15)
                Call(RandInt, 150, LVar3)
                Call(RandInt, 100, LVar4)
                Add(LVar3, 50)
                SetF(LVar4, Float(5.0))
                Call(RandInt, 4, LVar5)
                AddF(LVar4, LVar5)
                DivF(LVar4, Float(10.0))
                SetF(LVar5, Float(100.0))
                Call(RandInt, 40, LVar6)
                AddF(LVar5, LVar6)
                DivF(LVar5, Float(10.0))
                PlayEffect(EFFECT_MOVING_CLOUD, 0, 200, LVar3, 5, -200, LVar4, 5, LVar5, LVar4, 0)
                Call(RandInt, 5, LVar0)
                Add(LVar0, 5)
                Wait(LVar0)
            EndLoop
        EndThread
        Wait(110)
        Set(LVar1, 0)
    EndIf
    Call(StopSound, SOUND_HEAVY_WIND_LOOP)
    Wait(2)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Switch(LVar1)
        CaseEq(0)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_6, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(1)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_5, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_4, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(3)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_3, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(4)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_2, BS_FLAGS1_TRIGGER_EVENTS)
        CaseDefault
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_1, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_ChargeForGround) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    ExecGetTID(N(EVS_UpdateChargedJitter), LVarA)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 400)
    Call(SetBattleCamOffsetY, 5)
    Call(MoveBattleCamOver, 60)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim11)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim12)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim13)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ChargedBodyAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_FACE, Ref(N(ChargedFaceAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, Ref(N(ChargedArmAnims)))
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, TRUE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHARGE_LIGHTNING)
    Call(N(StartRumbleWithParams), 70, 120)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 60, Float(0.3))
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    DivF(LVar3, Float(100.0))
    Call(N(MakeSnakingStatic), LVar0, LVar1, LVar2, LVar3)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    Wait(60)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_GroundLightning) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 400)
    Call(SetBattleCamOffsetY, 5)
    Call(MoveBattleCamOver, 60)
    Call(N(StartRumbleWithParams), 70, 100)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 100, Float(0.3))
    EndThread
    Call(N(UnkBackgroundFunc3))
    Call(MakeLerp, 0, 200, 60, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(N(SetBackgroundAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    KillThread(LVarA)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    Call(RemoveEffect, LVar0)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BodyAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_FACE, Ref(N(FaceAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, Ref(N(ArmAnims)))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0E)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0F)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim10)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, FALSE)
    Thread
        Wait(20)
        Call(MakeLerp, 200, 0, 30, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(N(SetBackgroundAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndThread
    Call(StopSound, SOUND_CHARGE_LIGHTNING)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_LIGHTNING_BLAST)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 10)
    Set(LVar3, LVar0)
    Sub(LVar3, 30)
    PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, 1, LVar2, Float(3.0), 30, 0)
    Wait(5)
    Call(N(StartRumbleWithParams), 256, 30)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(5.0))
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(4.0))
    EndThread
    SetF(LVar6, Float(0.0))
    Loop(10)
        Set(LVar4, LVar3)
        Set(LVar5, LVar2)
        AddF(LVar6, Float(36.0))
        Call(AddVectorPolar, LVar4, LVar5, Float(300.0), LVar6)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar3, 1, LVar2, LVar4, 1, LVar5, Float(4.0), 30, 0)
    EndLoop
    Wait(10)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            IfEq(LVar0, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            Wait(20)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Wait(2)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_GROUND_LIGHTNING, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfGt(LVar0, 0)
                Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                BitwiseOrConst(LVar0, AVAR_Flag_LightningHit)
                Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EndIf
            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_ChargeForDirect) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    ExecGetTID(N(EVS_UpdateChargedJitter), LVarA)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 400)
    Call(SetBattleCamOffsetY, 5)
    Call(MoveBattleCamOver, 60)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim11)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim12)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim13)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ChargedBodyAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_FACE, Ref(N(ChargedFaceAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, Ref(N(ChargedArmAnims)))
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, TRUE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHARGE_LIGHTNING)
    Call(N(StartRumbleWithParams), 70, 120)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 60, Float(0.3))
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    DivF(LVar3, Float(100.0))
    Call(N(MakeSnakingStatic), LVar0, LVar1, LVar2, LVar3)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    Wait(60)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    Return
    End
};

EvtScript N(EVS_Attack_DirectLightning) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(AddBattleCamDist, -100)
    Call(SetBattleCamOffsetY, 50)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(N(StartRumbleWithParams), 70, 80)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 40, Float(0.3))
    EndThread
    Thread
        Call(N(UnkBackgroundFunc3))
        Call(MakeLerp, 0, 200, 40, EASING_LINEAR)
        Label(0)
            Call(UpdateLerp)
            Call(N(SetBackgroundAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
    EndThread
    Thread
        Loop(40)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVarA)
            Call(N(SetSnakingStaticPos), LVarA, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar1)
    SetF(LVar2, Float(72.5))
    SetF(LVar3, Float(67.5))
    MulF(LVar2, LVar0)
    MulF(LVar3, LVar1)
    DivF(LVar2, Float(100.0))
    DivF(LVar3, Float(100.0))
    Call(AddGoalPos, ACTOR_SELF, 0, LVar3, 0)
    Call(AddGoalPos, ACTOR_SELF, 20, 40, 0)
    Call(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
    Wait(30)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    KillThread(LVarA)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    Call(RemoveEffect, LVar0)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BodyAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_FACE, Ref(N(FaceAnims)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, Ref(N(ArmAnims)))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0E)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0F)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim10)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, FALSE)
    Thread
        Wait(20)
        Call(MakeLerp, 200, 0, 30, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(N(SetBackgroundAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndThread
    Call(StopSound, SOUND_CHARGE_LIGHTNING)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_FIRE_LIGHTNING)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseEq(HIT_RESULT_LUCKY)
            Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
            Sub(LVarC, 10)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
            Sub(LVarD, 100)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVarA, LVarB, LVarC, LVarD, 0, LVarF, Float(1.5), 20, 0)
            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseEq(HIT_RESULT_MISS)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar2, 10)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            Sub(LVar3, 4)
            Add(LVar4, 10)
            Add(LVar5, 1)
            Thread
                Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar6)
                SetF(LVar7, Float(0.725))
                SetF(LVar8, Float(0.242))
                MulF(LVar7, LVar6)
                MulF(LVar8, LVar6)
                SubF(LVar0, LVar7)
                SetF(LVar9, LVar8)
                MulF(LVar9, 3)
                AddF(LVar9, LVar0)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
                Wait(3)
                SetF(LVar9, LVar8)
                MulF(LVar9, 1)
                AddF(LVar9, LVar0)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
                Wait(3)
                SetF(LVar9, LVar8)
                MulF(LVar9, 4)
                AddF(LVar9, LVar0)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
                Wait(3)
                SetF(LVar9, LVar8)
                MulF(LVar9, 2)
                AddF(LVar9, LVar0)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
                Wait(3)
                SetF(LVar9, LVar8)
                MulF(LVar9, 5)
                AddF(LVar9, LVar0)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
            EndThread
            Wait(2)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, 4)
    Add(LVar4, 10)
    Add(LVar5, 1)
    Thread
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar6)
        SetF(LVar7, Float(0.725))
        SetF(LVar8, Float(0.242))
        MulF(LVar7, LVar6)
        MulF(LVar8, LVar6)
        SubF(LVar0, LVar7)
        SetF(LVar9, LVar8)
        MulF(LVar9, 3)
        AddF(LVar9, LVar0)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
        Wait(3)
        SetF(LVar9, LVar8)
        MulF(LVar9, 1)
        AddF(LVar9, LVar0)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
        Wait(3)
        SetF(LVar9, LVar8)
        MulF(LVar9, 4)
        AddF(LVar9, LVar0)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
        Wait(3)
        SetF(LVar9, LVar8)
        MulF(LVar9, 2)
        AddF(LVar9, LVar0)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
        Wait(3)
        SetF(LVar9, LVar8)
        MulF(LVar9, 5)
        AddF(LVar9, LVar0)
        PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.2), 10, 0)
    EndThread
    Wait(2)
    Wait(2)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DIRECT_LIGHTNING, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_GroupSlam) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 400)
    Call(SetBattleCamOffsetY, 5)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_REAR_UP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1B)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1C)
    Wait(8)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1D)
    Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1E)
    Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1F)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_JIGGLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    Set(LVarF, 0)
    Loop(20)
        Call(N(CosInterpMinMax), LVarF, LVar2, Float(1.0), Float(1.3), 10, 0, 0)
        Call(N(CosInterpMinMax), LVarF, LVar3, Float(1.0), Float(0.7), 10, 0, 0)
        MulF(LVar2, LVar0)
        MulF(LVar3, LVar1)
        Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
        Add(LVarF, 1)
        Wait(1)
    EndLoop
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_JIGGLE)
    Loop(20)
        Call(N(CosInterpMinMax), LVarF, LVar2, Float(1.0), Float(1.2), 10, 0, 0)
        Call(N(CosInterpMinMax), LVarF, LVar3, Float(1.0), Float(0.8), 10, 0, 0)
        MulF(LVar2, LVar0)
        MulF(LVar3, LVar1)
        Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
        Add(LVarF, 1)
        Wait(1)
    EndLoop
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    Set(LVar9, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Add(LVarB, 150)

    #define HNP_GROUP_ASCEND(idx) \
        IfFlag(LVar0, 1 << idx) \
            Call(UseIdleAnimation, ArrayVar(idx), FALSE) \
            Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
            IfEq(LVar1, 0) \
                Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim09) \
            Else \
                Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim0B) \
            EndIf \
            Thread \
                Mod(LVar9, 2) \
                IfEq(LVar9, 0) \
                    Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                Else \
                    Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                EndIf \
                Call(GetActorPos, ArrayVar(idx), LVarD, LVarE, LVarF) \
                Call(SetGoalPos, ArrayVar(idx), LVarA, LVarB, LVarF) \
                Call(FlyToGoal, ArrayVar(idx), 20, 10, EASING_QUADRATIC_IN) \
                Set(LVarD, LVarA) \
                Set(LVarE, LVarC) \
                Set(LVarF, idx) \
                Mul(LVarF, 36) \
                Add(LVarF, -90) \
                Call(AddVectorPolar, LVarD, LVarE, Float(60.0), LVarF) \
                Call(SetActorPos, ArrayVar(idx), LVarD, LVarB, LVarE) \
            EndThread \
            Add(LVar9, 1) \
            Wait(8) \
        EndIf

    // have each Tuff Puff ascend above the battlefield
    FOR_CHILDREN_SCATTERED(HNP_GROUP_ASCEND)

    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(FlyToGoal, ACTOR_SELF, 30, 10, EASING_QUADRATIC_IN)
    Wait(75)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GROUP_DROP(idx) \
        IfFlag(LVar0, 1 << idx) \
            Thread \
                Call(GetActorPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar4) \
                IfEq(LVar4, 0) \
                    Set(LVar2, 10) \
                Else \
                    Set(LVar2, 14) \
                EndIf \
                Call(SetActorSounds, ArrayVar(idx), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE) \
                Call(SetGoalPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                Call(FlyToGoal, ArrayVar(idx), 20, 0, EASING_CUBIC_IN) \
                Call(ResetActorSounds, ArrayVar(idx), ACTOR_SOUND_FLY) \
            EndThread \
        EndIf

    // have each Tuff Puff drop down from the sky
    FOR_CHILDREN_ORDERED(HNP_GROUP_DROP)

    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Thread
        Wait(3)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_FALLING)
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
    Mul(LVar4, 95)
    Div(LVar4, 200)
    Call(SetGoalPos, ACTOR_SELF, LVar1, LVar4, LVar3)
    Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_CUBIC_IN)
    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_SHOCKWAVE, 3, LVar0, 0, LVar2, 0)
    Thread
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar1, LVar4, LVar3, 60, 8, 0, 30, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar1, LVar4, LVar3, 60, 8, 33, 30, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar1, LVar4, LVar3, 60, 8, 66, 30, 0)
    EndThread
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 20, Float(1.0))
    EndThread
    Thread
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
        Set(LVarF, 0)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_WOBBLE)
        Loop(20)
            Call(N(CosInterpMinMax), LVarF, LVar2, Float(1.0), Float(1.5), 10, 0, 0)
            Call(N(CosInterpMinMax), LVarF, LVar3, Float(1.0), Float(0.5), 10, 0, 0)
            MulF(LVar2, LVar0)
            MulF(LVar3, LVar1)
            Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
            Add(LVarF, 1)
            Wait(1)
        EndLoop
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_WOBBLE)
        Loop(20)
            Call(N(CosInterpMinMax), LVarF, LVar2, Float(1.0), Float(1.2), 10, 0, 0)
            Call(N(CosInterpMinMax), LVarF, LVar3, Float(1.0), Float(0.8), 10, 0, 0)
            MulF(LVar2, LVar0)
            MulF(LVar3, LVar1)
            Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
            Add(LVarF, 1)
            Wait(1)
        EndLoop
        Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
        Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    EndThread
    Thread
        Loop(40)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
            Mul(LVar3, 95)
            Div(LVar3, 200)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_IMPACT_JIGGLE(idx) \
        IfFlag(LVar0, 1 << idx) \
            Thread \
                Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar0) \
                Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar1) \
                Set(LVarF, 0) \
                Loop(20) \
                    Call(N(CosInterpMinMax), LVarF, LVar2, Float(1.0), Float(1.5), 10, 0, 0) \
                    Call(N(CosInterpMinMax), LVarF, LVar3, Float(1.0), Float(0.5), 10, 0, 0) \
                    MulF(LVar2, LVar0) \
                    MulF(LVar3, LVar1) \
                    Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar2) \
                    Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar3) \
                    Add(LVarF, 1) \
                    Wait(1) \
                EndLoop \
                Loop(20) \
                    Call(N(CosInterpMinMax), LVarF, LVar2, Float(1.0), Float(1.2), 10, 0, 0) \
                    Call(N(CosInterpMinMax), LVarF, LVar3, Float(1.0), Float(0.8), 10, 0, 0) \
                    MulF(LVar2, LVar0) \
                    MulF(LVar3, LVar1) \
                    Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar2) \
                    Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar3) \
                    Add(LVarF, 1) \
                    Wait(1) \
                EndLoop \
                Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar0) \
                Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar1) \
            EndThread \
            Thread \
                Loop(40) \
                    Call(GetActorPos, ArrayVar(idx), LVar0, LVar1, LVar2) \
                    Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar3) \
                    Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar4) \
                    IfEq(LVar4, 0) \
                        Mul(LVar3, 20) \
                    Else \
                        Mul(LVar3, 28) \
                    EndIf \
                    Div(LVar3, 200) \
                    Call(SetActorPos, ArrayVar(idx), LVar0, LVar3, LVar2) \
                    Wait(1) \
                EndLoop \
            EndThread \
        EndIf

    // have each Tuff Puff oscillate after slamming into the ground
    FOR_CHILDREN_ORDERED(HNP_IMPACT_JIGGLE)

    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Set(LVarA, LVar0)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(100)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            Call(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            Call(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            Wait(20)
            Set(LVarA, 0)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                IfFlag(LVar0, 1 << idx) \
                    Thread \
                        Mod(LVarA, 2) \
                        IfEq(LVarA, 0) \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        Else \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EndIf \
                        Call(SetGoalToHome, ArrayVar(idx)) \
                        Call(FlyToGoal, ArrayVar(idx), 20, -10, EASING_SIN_OUT) \
                    EndThread \
                    Add(LVarA, 1) \
                    Wait(8) \
                EndIf

            // have each Tuff Puff return to their home position
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)

            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 20, -10, EASING_SIN_OUT)
            Wait(15)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Set(LVarA, DMG_GROUP_SLAM_BASE)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_ADD_CHILD(idx) \
        IfFlag(LVar0, 1 << idx) \
            Add(LVarA, 1) \
        EndIf

    // add 1 damage for each Tuff Puff
    FOR_CHILDREN_ORDERED(HNP_ADD_CHILD)

    Wait(2)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarA, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(50)
            Set(LVarA, 0)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 20, -10, EASING_SIN_OUT)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                IfFlag(LVar0, 1 << idx) \
                    Thread \
                        Mod(LVarA, 2) \
                        IfEq(LVarA, 0) \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        Else \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EndIf \
                        Call(SetGoalToHome, ArrayVar(idx)) \
                        Call(FlyToGoal, ArrayVar(idx), 20, -10, EASING_SIN_OUT) \
                    EndThread \
                    Add(LVarA, 1) \
                    Wait(8) \
                EndIf

            // make each Tuff Puff return home
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)

            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TuffPuff_SqueezePlayer) = {
    IfEq(LVar3, 0)
        Set(LFlag0, TRUE)
    EndIf
    Set(LVarA, LVar1)
    Set(LVarB, LVar2)
    Div(LVarB, 2)
    Add(LVarB, 1)
    Call(SetOwnerID, LVar1) // note: ownership transferred to Tuff Puff actor here
    Call(RandInt, 1000, LVar0)
    IfLt(LVar0, 500)
        Call(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 1)
    Else
        Call(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 2)
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(GetDist2D, LVarD, LVar0, LVar2, LVar3, LVar5)
    Call(N(Atan2), LVarE, LVar0, LVar2, LVar3, LVar5)
    Set(LVarF, 0)
    Loop(0)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SQUEEZE)
        Set(LVarF, 0)
        Set(LVarC, LVarB)
        Add(LVarC, LVarB)
        Set(LVar9, LVarC)
        Loop(LVarC)
            Call(N(UpdateLerp), EASING_CUBIC_OUT, Float(100.0), Float(40.0), LVarF, LVar9, LVar0)
            MulF(LVar0, LVarD)
            DivF(LVar0, Float(100.0))
            Call(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            Call(AddVectorPolar, LVar1, LVar3, LVar0, LVarE)
            Call(SetActorPos, ACTOR_SELF, LVar1, LVar5, LVar3)
            Add(LVarF, 1)
            Wait(1)
        EndLoop
        Wait(5)
        IfEq(LFlag0, TRUE)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            BitwiseOrConst(LVar0, AVAR_Flag_WaitForChild)
            Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
        EndIf
        Set(LVarF, 0)
        Set(LVarC, LVarB)
        Loop(LVarC)
            Call(N(UpdateLerp), EASING_QUARTIC_OUT, Float(40.0), Float(100.0), LVarF, LVarB, LVar0)
            MulF(LVar0, LVarD)
            DivF(LVar0, Float(100.0))
            Call(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            Call(AddVectorPolar, LVar1, LVar3, LVar0, LVarE)
            Call(SetActorPos, ACTOR_SELF, LVar1, LVar5, LVar3)
            Add(LVarF, 1)
            Wait(1)
        EndLoop
        Wait(10)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Attack_TuffPuffSwarm) = {
    UseArray(N(RuffPuffDataBuffer))
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_SWARM_MOVE_UP(idx) \
        IfFlag(LVar0, 1 << idx) \
            Thread \
                Call(GetActorPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                Add(LVar2, 15) \
                Call(SetGoalPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                Call(FlyToGoal, ArrayVar(idx), 20, 0, EASING_LINEAR) \
                Wait(3) \
            EndThread \
        EndIf

    // each Tuff Puff moves up slightly
    FOR_CHILDREN_SCATTERED(HNP_SWARM_MOVE_UP)

    Wait(20)
    Set(LVarA, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_ADD_CHILD(idx) \
        IfFlag(LVar0, 1 << idx) \
            Add(LVarA, 1) \
        EndIf

    // count the number of Tuff Puffs to compute radial spacing around the player
    FOR_CHILDREN_ORDERED(HNP_ADD_CHILD)

    // radial increment will be stored in LVarB
    SetF(LVarB, Float(360.0))
    DivF(LVarB, LVarA)
    Thread
        Wait(10)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 300)
        Call(SetBattleCamOffsetY, 35)
        Call(MoveBattleCamOver, 60)
    EndThread
    Set(LVarA, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_SWARM_SURROUND_PLAYER(idx) \
        IfFlag(LVar0, 1 << idx) \
            Call(UseIdleAnimation, ArrayVar(idx), FALSE) \
            Call(SetPartAlpha, ArrayVar(idx), 1, 254) \
            Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
            IfEq(LVar1, 0) \
                Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim09) \
            Else \
                Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim0B) \
            EndIf \
            Thread \
                Call(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3) \
                MulF(LVarB, LVarA) \
                AddF(LVarB, Float(100.0)) \
                Call(AddVectorPolar, LVar1, LVar3, Float(20.0), LVarB) \
                Call(RandInt, 20, LVar4) \
                Sub(LVar4, 10) \
                Add(LVar4, 19) \
                Add(LVar2, LVar4) \
                Mod(LVarA, 2) \
                IfEq(LVarA, 0) \
                    Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                Else \
                    Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                EndIf \
                Call(SetGoalPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                Call(FlyToGoal, ArrayVar(idx), 30, -10, EASING_SIN_OUT) \
                Call(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6) \
                IfLt(LVar1, LVar4) \
                    Call(SetActorYaw, ArrayVar(idx), 180) \
                EndIf \
            EndThread \
            Add(LVarA, 1) \
            Wait(4) \
        EndIf

    // move each Tuff Puff to a position surrounding the player
    FOR_CHILDREN_SCATTERED(HNP_SWARM_SURROUND_PLAYER)

    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
    Set(LVar9, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_ADD_CHILD(idx) \
        IfFlag(LVar0, 1 << idx) \
            Add(LVar9, 1) \
        EndIf

    // count the number of Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_ADD_CHILD)

    Set(LVarA, 30 * DT)
    Sub(LVarA, LVar9)
    Set(LVar3, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_SQUEEZE_PLAYER(idx) \
        IfFlag(LVar0, 1 << idx) \
            Set(LVar1, ArrayVar(idx)) \
            Set(LVar2, LVarA) \
            ExecGetTID(N(EVS_TuffPuff_SqueezePlayer), ArrayVar(idx + MAX_RUFF_PUFFS)) \
            Add(LVar3, 1) \
        EndIf

    // have each Tuff Puff squeeze the player
    FOR_CHILDREN_ORDERED(HNP_SQUEEZE_PLAYER)

    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Label(0)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            IfNotFlag(LVar0, AVAR_Flag_WaitForChild)
                Wait(1)
                Goto(0)
            EndIf
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AVAR_Flag_WaitForChild)
            Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_SCATTER_PUFF(idx) \
                IfFlag(LVar0, 1 << idx) \
                    KillThread(ArrayVar(idx + MAX_RUFF_PUFFS)) \
                    Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    IfEq(LVar1, 0) \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim12) \
                    Else \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim13) \
                    EndIf \
                    Thread \
                        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2) \
                        Call(GetActorPos, ArrayVar(idx), LVar3, LVar4, LVar5) \
                        Call(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5) \
                        DivF(LVar6, Float(2.0)) \
                        AddF(LVar6, Float(90.0)) \
                        Call(AddVectorPolar, LVar0, LVar1, Float(70.0), LVar6) \
                        Call(SetActorJumpGravity, ArrayVar(idx), Float(1.0)) \
                        Call(SetGoalPos, ArrayVar(idx), LVar0, LVar1, LVar2) \
                        Call(JumpToGoal, ArrayVar(idx), 20, FALSE, FALSE, FALSE) \
                    EndThread \
                EndIf

            // throw each Tuff Puff away in a large fan pattern
            FOR_CHILDREN_ORDERED(HNP_SCATTER_PUFF)

            Wait(15)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Set(LVarA, 0)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                IfFlag(LVar0, 1 << idx) \
                    Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    IfEq(LVar1, 0) \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim06) \
                    Else \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim07) \
                    EndIf \
                    Thread \
                        Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_WobbleMode, 0) \
                        Mod(LVarA, 2) \
                        IfEq(LVarA, 0) \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        Else \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EndIf \
                        Call(SetGoalToHome, ArrayVar(idx)) \
                        Call(FlyToGoal, ArrayVar(idx), 30, 10, EASING_SIN_OUT) \
                        Call(SetPartAlpha, ArrayVar(idx), 1, 255) \
                        Call(SetActorYaw, ArrayVar(idx), 0) \
                        Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                        IfEq(LVar1, 0) \
                            Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim02) \
                        Else \
                            Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim03) \
                        EndIf \
                    EndThread \
                    Add(LVarA, 1) \
                    Wait(4) \
                EndIf

            // have each Tuff Puff fly back to its home position
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)

            Wait(50)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(GetStatusFlags, ACTOR_PLAYER, LVar1)
    IfFlag(LVar1, STATUS_FLAG_STONE)
        Wait(10)
        Set(LVar3, 0)
        Loop(0)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            IfFlag(LVar0, AVAR_Flag_WaitForChild)
                Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                BitwiseAndConst(LVar0, ~AVAR_Flag_WaitForChild)
                Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                Wait(2)
                Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_NICE_HIT)
                Add(LVar3, 1)
            EndIf
            IfGt(LVar3, 1)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    Else
        Call(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 180)
        Call(ShowActionHud, TRUE)
        Call(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        Call(action_command_stop_leech_init)
        Call(SetupMashMeter, 1, 25, 0, 0, 0, 0)
        Wait(10)
        Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        Call(action_command_stop_leech_start, 0, 32767, 3)
        Set(LVarB, LVarA)
        Div(LVarB, 2)
        Wait(LVarB)
        Set(LVarD, 0)
        Loop(0)
            Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            IfFlag(LVar0, AVAR_Flag_WaitForChild)
                Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                BitwiseAndConst(LVar0, ~AVAR_Flag_WaitForChild)
                Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                Wait(2)
                Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_NICE_HIT)
                Add(LVarD, 1)
            EndIf
            Call(GetActionSuccessCopy, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfEq(LVar0, 0)
                IfGt(LVarD, 1)
                    Call(func_80269470)
                    BreakLoop
                EndIf
            EndIf
            Call(GetPlayerHP, LVar0)
            IfEq(LVar0, 0)
                Call(func_80269470)
                BreakLoop
            EndIf
            IfGe(LVarD, 20)
                Call(func_80269470)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(func_80269470)
    EndIf
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_SCATTER_PUFF(idx) \
                IfFlag(LVar0, 1 << idx) \
                    KillThread(ArrayVar(idx + MAX_RUFF_PUFFS)) \
                    Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    IfEq(LVar1, 0) \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim12) \
                    Else \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim13) \
                    EndIf \
                    Thread \
                        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2) \
                        Call(GetActorPos, ArrayVar(idx), LVar3, LVar4, LVar5) \
                        Call(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5) \
                        DivF(LVar6, Float(2.0)) \
                        AddF(LVar6, Float(90.0)) \
                        Call(AddVectorPolar, LVar0, LVar1, Float(70.0), LVar6) \
                        Call(SetActorJumpGravity, ArrayVar(idx), Float(1.0)) \
                        Call(SetGoalPos, ArrayVar(idx), LVar0, LVar1, LVar2) \
                        Call(JumpToGoal, ArrayVar(idx), 20, FALSE, FALSE, FALSE) \
                    EndThread \
                EndIf

            // throw each Tuff Puff away in a large fan pattern
            FOR_CHILDREN_ORDERED(HNP_SCATTER_PUFF)

            Call(GetPlayerHP, LVar0)
            IfNe(LVar0, 0)
                Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                Wait(1)
                Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_STONE)
                    Thread
                        Set(LVar0, 0)
                        Loop(20)
                            Add(LVar0, 54)
                            Mod(LVar0, 360)
                            Call(SetActorYaw, ACTOR_PLAYER, LVar0)
                            Wait(1)
                        EndLoop
                        Call(SetActorYaw, ACTOR_PLAYER, 0)
                    EndThread
                    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_Land)
                    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.5))
                    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    Call(PlayerHopToGoal, 20, 0, 1)
                Else
                    Wait(20)
                EndIf
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            Else
                Wait(20)
            EndIf
            Wait(15)
            Set(LVarA, 0)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                IfFlag(LVar0, 1 << idx) \
                    Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    IfEq(LVar1, 0) \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim06) \
                    Else \
                        Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim07) \
                    EndIf \
                    Thread \
                        Call(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_WobbleMode, 0) \
                        Mod(LVarA, 2) \
                        IfEq(LVarA, 0) \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        Else \
                            Call(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EndIf \
                        Call(SetGoalToHome, ArrayVar(idx)) \
                        Call(FlyToGoal, ArrayVar(idx), 30, 10, EASING_SIN_OUT) \
                        Call(SetPartAlpha, ArrayVar(idx), 1, 255) \
                        Call(SetActorYaw, ArrayVar(idx), 0) \
                        Call(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                        IfEq(LVar1, 0) \
                            Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim02) \
                        Else \
                            Call(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim03) \
                        EndIf \
                    EndThread \
                    Add(LVarA, 1) \
                    Wait(4) \
                EndIf

            // have each Tuff Puff fly back to its home position
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)

            Wait(50)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
