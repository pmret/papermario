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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChildBits, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, 100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, 100)
    EVT_EXEC_WAIT(N(EVS_UpdateSize))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateSize) = {
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    EVT_MUL(LVar0, 145)
    EVT_MUL(LVar1, 135)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(SetActorSize, ACTOR_HUFF_N_PUFF, LVar1, LVar0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    EVT_MUL(LVar0, -10)
    EVT_MUL(LVar1, 40)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(SetTargetOffset, ACTOR_HUFF_N_PUFF, PRT_MAIN, LVar0, LVar1)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    EVT_MUL(LVar0, -15)
    EVT_MUL(LVar1, -50)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_HUFF_N_PUFF, PRT_MAIN, LVar0, LVar1)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar1)
    EVT_MUL(LVar0, -17)
    EVT_MUL(LVar1, -31)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(N(SetHealthBarPos), LVar0, LVar1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateChargedJitter) = {
    EVT_SET(LFlag0, FALSE)
    EVT_SET(LVarA, 0)
    EVT_SET(LVarB, 0)
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(AVAL_Move_PreCharge_1)
            EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
            EVT_CASE_OR_EQ(AVAL_Move_PreCharge_3)
            EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
                EVT_IF_EQ(LFlag0, FALSE)
                    EVT_CALL(RandInt, 2, LVarA)
                    EVT_CALL(RandInt, 2, LVarB)
                    EVT_SET(LFlag0, TRUE)
                EVT_ELSE
                    EVT_MUL(LVarA, -1)
                    EVT_MUL(LVarB, -1)
                    EVT_SET(LFlag0, FALSE)
                EVT_END_IF
            EVT_END_CASE_GROUP
            EVT_CASE_OR_EQ(AVAL_Move_PreCharge_2)
            EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
                EVT_IF_EQ(LFlag0, FALSE)
                    EVT_CALL(RandInt, 1, LVarA)
                    EVT_SET(LFlag0, TRUE)
                EVT_ELSE
                    EVT_MUL(LVarA, -1)
                    EVT_SET(LFlag0, FALSE)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVarA, LVarB, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_WobbleMode, LVarA)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.97), EVT_FLOAT(1.03), 15, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.03), EVT_FLOAT(0.97), 15, 0, 0)
                EVT_ADD(LVarF, 1)
            EVT_CASE_EQ(1)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.95), EVT_FLOAT(1.05), 15, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.05), EVT_FLOAT(0.95), 15, 0, 0)
                EVT_ADD(LVarF, 3)
            EVT_CASE_EQ(2)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.9), EVT_FLOAT(1.1), 15, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), 15, 0, 0)
                EVT_ADD(LVarF, 5)
        EVT_END_SWITCH
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
        EVT_DIVF(LVar2, EVT_FLOAT(100.0))
        EVT_DIVF(LVar3, EVT_FLOAT(100.0))
        EVT_MULF(LVar1, LVar2)
        EVT_MULF(LVar0, LVar3)
        EVT_CALL(SetActorScale, ACTOR_SELF, LVar1, LVar0, EVT_FLOAT(1.0))
        EVT_IF_GE(LVarF, 30)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(SmallTuffFormation) = {
    ACTOR_BY_POS(A(tuff_puff), N(SummonPos), 0, FALSE),
};

Formation N(LargeTuffFormation) = {
    ACTOR_BY_POS(A(tuff_puff), N(SummonPos), 0, TRUE),
};

EvtScript N(EVS_TrySpawningRuffPuff) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar9)
    EVT_IF_LE(LVar9, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
        EVT_IF_GT(LVar9, 8)
            EVT_SET(LVar9, 8)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_GT(LVar9, 4)
            EVT_SET(LVar9, 4)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar8)
    EVT_MUL(LVar8, 1)
    EVT_SUB(LVar0, LVar8)
    EVT_IF_LT(LVar0, 50)
        EVT_SET(LVar0, 50)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar8)
    EVT_MUL(LVar8, 1)
    EVT_SUB(LVar0, LVar8)
    EVT_IF_LT(LVar0, 50)
        EVT_SET(LVar0, 50)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
    EVT_EXEC_WAIT(N(EVS_UpdateSize))
    EVT_SET(LVarA, 0)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
        EVT_SET(LVar0, LVar9)
        EVT_IF_GT(LVar0, 1)
            EVT_SET(LVarA, LVar0)
            EVT_DIV(LVarA, 2)
            EVT_SET(LVar9, LVar0)
            EVT_MOD(LVar9, 2)
            EVT_ADD(LVar9, LVarA)
        EVT_END_IF
    EVT_END_IF
    EVT_LOOP(LVar9)
        EVT_CALL(N(SetTuffPuffPriority))
        EVT_IF_GT(LVarA, 0)
            EVT_SUB(LVarA, 1)
            EVT_CALL(SummonEnemy, EVT_PTR(N(LargeTuffFormation)), FALSE)
            EVT_CALL(SetActorVar, LVar0, AVAR_TuffPuff_HealValue, 2)
        EVT_ELSE
            EVT_CALL(SummonEnemy, EVT_PTR(N(SmallTuffFormation)), FALSE)
            EVT_CALL(SetActorVar, LVar0, AVAR_TuffPuff_HealValue, 1)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar1)
        EVT_CALL(N(FindPlaceForTuffPuff), LVar1, LVar2)
        EVT_SWITCH(LVar2)

            #define HNP_REGISTER_CHILD(idx) \
                EVT_CASE_EQ(1 << idx) \
                    EVT_BITWISE_OR_CONST(LVar1, 1 << idx) \
                    EVT_SET(LVar2, idx) \
                    EVT_SET(ArrayVar(idx), LVar0)

            // try registering the child with each position, until we find the one on LVar2
            FOR_CHILDREN_ORDERED(HNP_REGISTER_CHILD)

            EVT_CASE_DEFAULT
                EVT_SET(LVar2, -1)
        EVT_END_SWITCH
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar1)
        EVT_CALL(PlaySoundAtActor, LVar0, SOUND_OPEN_SHELL)
        EVT_THREAD
            EVT_SET(LVar3, LVar0)
            EVT_CALL(MakeLerp, 150, 255, 15, EASING_QUADRATIC_IN)
            EVT_LABEL(123)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetPartAlpha, LVar3, 1, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(123)
                EVT_END_IF
            EVT_CALL(SetPartAlpha, LVar3, 1, 255)
        EVT_END_THREAD
        EVT_IF_NE(LVar2, -1)
            EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVar0)
            EVT_CALL(CopyBuffs, ACTOR_SELF, LVar0)
            EVT_CALL(SetActorVar, LVar0, AVAR_TuffPuff_Index, LVar2)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(SetActorPos, LVar0, LVar3, LVar4, LVar5)
            EVT_ADD(LVar3, -5)
            EVT_ADD(LVar4, 0)
            EVT_ADD(LVar5, 0)
            EVT_MUL(LVar2, 36)
            EVT_ADD(LVar2, 0)
            EVT_CALL(N(SetTuffPuffPos), LVar3, LVar4, LVar5, LVar2, EVT_FLOAT(0.0), EVT_FLOAT(50.0))
            EVT_THREAD
                EVT_CALL(SetActorJumpGravity, LVar0, EVT_FLOAT(0.8))
                EVT_CALL(SetGoalPos, LVar0, LVar3, LVar4, LVar5)
                EVT_CALL(JumpToGoal, LVar0, 30, FALSE, FALSE, FALSE)
                EVT_CALL(ForceHomePos, LVar0, LVar3, LVar4, LVar5)
                EVT_CALL(HPBarToHome, LVar0)
            EVT_END_THREAD
        EVT_ELSE
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(SetActorPos, LVar0, LVar3, LVar4, LVar5)
            EVT_CALL(RandInt, 200, LVar6)
            EVT_SUB(LVar6, 100)
            EVT_ADD(LVar3, LVar6)
            EVT_ADD(LVar5, 10)
            EVT_THREAD
                EVT_CALL(SetActorJumpGravity, LVar0, EVT_FLOAT(0.8))
                EVT_CALL(SetGoalPos, LVar0, LVar3, -30, LVar5)
                EVT_CALL(JumpToGoal, LVar0, 40, FALSE, FALSE, FALSE)
                EVT_CALL(RemoveActor, LVar0)
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_Hit) = {
    EVT_EXEC_WAIT(N(EVS_TrySpawningRuffPuff))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim11)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim12)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim13)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim07)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim08)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim09)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, PRT_MAIN)
        EVT_SET(LVar1, LVar2)
        EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, PRT_FACE)
        EVT_SET(LVar1, LVar3)
        EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, PRT_ARMS)
        EVT_SET(LVar1, LVar4)
        EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_Death) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_KILL_CHILD(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT) \
            EVT_CALL(DispatchEvent, ArrayVar(idx), EVENT_DEATH) \
        EVT_END_IF

    // kill any remaining Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_KILL_CHILD)

    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(StopSound, SOUND_CHARGE_LIGHTNING)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim08)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim09)
    EVT_SET(LVar0, PRT_MAIN)
    EVT_SET(LVar1, ANIM_HuffNPuff_Anim07)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_BurnHit) = {
    EVT_EXEC_WAIT(N(EVS_TrySpawningRuffPuff))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim11)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim12)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim13)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim23)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim24)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim25)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, LVar3)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, LVar4)
    EVT_WAIT(20)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim11)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim12)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim13)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim26)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim27)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim28)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, LVar3)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, LVar4)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_BurnDeath) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_KILL_CHILD(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_CALL(DispatchEvent, ArrayVar(idx), EVENT_DEATH) \
        EVT_END_IF

    // kill any remaining Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_KILL_CHILD)

    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(StopSound, SOUND_CHARGE_LIGHTNING)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim27)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim28)
    EVT_SET(LVar0, PRT_MAIN)
    EVT_SET(LVar1, ANIM_HuffNPuff_Anim26)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HuffNPuff_NoDamage) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim11)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim12)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim13)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar2, ANIM_HuffNPuff_Anim01)
            EVT_SET_CONST(LVar3, ANIM_HuffNPuff_Anim02)
            EVT_SET_CONST(LVar4, ANIM_HuffNPuff_Anim03)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, PRT_MAIN)
        EVT_SET(LVar1, LVar2)
        EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, PRT_FACE)
        EVT_SET(LVar1, LVar3)
        EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, PRT_ARMS)
        EVT_SET(LVar1, LVar4)
        EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_IncreaseWobble) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_WobbleMode, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 2)
        EVT_CASE_EQ(2)
            // can't increase any more
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(EVS_IncreaseWobble))
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_Hit))
        EVT_CASE_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(EVS_IncreaseWobble))
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_Hit))
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_DamageCombo)
            EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(EVS_IncreaseWobble))
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_BurnHit))
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_DamageCombo)
            EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(EVS_IncreaseWobble))
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_BurnHit))
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_BurnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_NoDamage))
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_NoDamage))
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_DamageCombo)
            EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(EVS_IncreaseWobble))
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_Hit))
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_EXEC_WAIT(N(EVS_IncreaseWobble))
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_EXEC_WAIT(N(EVS_HuffNPuff_NoDamage))
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_DamageCombo)
            EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Dialogue_PummelPermission) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_SET(LVar0, ArrayVar(idx)) \
            EVT_GOTO(0) \
        EVT_END_IF

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    EVT_GOTO(1)
    // found a Tuff Puff to speak
    EVT_LABEL(0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, LVar0)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(SetAnimation, LVar0, 1, ANIM_TuffPuff_Anim09)
        EVT_CALL(ActorSpeak, MSG_CH6_00CF, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00CF, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_WAIT(20)
    // Huff N Puff replies
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim2D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim2E)
    EVT_CALL(ActorSpeak, MSG_CH6_00D0, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim2C, ANIM_HuffNPuff_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Dialogue_FullPower) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim2D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim2E)
    EVT_CALL(ActorSpeak, MSG_CH6_00D1, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim2C, ANIM_HuffNPuff_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_SET(LVar0, ArrayVar(idx)) \
            EVT_GOTO(0) \
        EVT_END_IF

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    EVT_GOTO(1)
    // found a Tuff Puff to speak
    EVT_LABEL(0)
    EVT_CALL(BattleCamTargetActor, LVar0)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_IF_LT(LVar1, LVar4)
        EVT_SETF(LVar7, EVT_FLOAT(0.0))
        EVT_LOOP(10)
            EVT_ADDF(LVar7, EVT_FLOAT(18.0))
            EVT_CALL(SetActorYaw, LVar0, LVar7)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(SetAnimation, LVar0, 1, ANIM_TuffPuff_Anim09)
        EVT_CALL(ActorSpeak, MSG_CH6_00D2, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00D2, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_IF_LT(LVar1, LVar4)
        EVT_SETF(LVar7, EVT_FLOAT(180.0))
        EVT_LOOP(10)
            EVT_SUBF(LVar7, EVT_FLOAT(18.0))
            EVT_CALL(SetActorYaw, LVar0, LVar7)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    // done speaking
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Dialogue_PraiseHuff) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim18)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim19)
    EVT_CALL(ActorSpeak, MSG_CH6_00D3, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim17, ANIM_HuffNPuff_Anim17)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_SET(LVar0, ArrayVar(idx)) \
            EVT_GOTO(0) \
        EVT_END_IF

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    EVT_GOTO(1)
    // found a Tuff Puff to speak
    EVT_LABEL(0)
    EVT_CALL(BattleCamTargetActor, LVar0)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_IF_LT(LVar1, LVar4)
        EVT_SETF(LVar7, EVT_FLOAT(0.0))
        EVT_LOOP(10)
            EVT_ADDF(LVar7, EVT_FLOAT(18.0))
            EVT_CALL(SetActorYaw, LVar0, LVar7)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(ActorSpeak, MSG_CH6_00D4, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00D4, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_IF_LT(LVar1, LVar4)
        EVT_SETF(LVar7, EVT_FLOAT(180.0))
        EVT_LOOP(10)
            EVT_SUBF(LVar7, EVT_FLOAT(18.0))
            EVT_CALL(SetActorYaw, LVar0, LVar7)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    // done speaking
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Dialogue_Concerned) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim24)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim25)
    EVT_CALL(ActorSpeak, MSG_CH6_00D5, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim23, ANIM_HuffNPuff_Anim23)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GET_SPEAKER(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_SET(LVar0, ArrayVar(idx)) \
            EVT_GOTO(0) \
        EVT_END_IF

    // select the first available Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_GET_SPEAKER)

    EVT_GOTO(1)
    // found a Tuff Puff to speak
    EVT_LABEL(0)
    EVT_CALL(BattleCamTargetActor, LVar0)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(GetActorVar, LVar0, AVAR_TuffPuff_IsLarge, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(ActorSpeak, MSG_CH6_00D6, LVar0, 1, ANIM_TuffPuff_Anim14, ANIM_TuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00D6, LVar0, 1, ANIM_TuffPuff_Anim15, ANIM_TuffPuff_Anim03)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    // Huff N Puff replies
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim24)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim25)
    EVT_CALL(ActorSpeak, MSG_CH6_00D7, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim23, ANIM_HuffNPuff_Anim23)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    // if charged with less than 5 HP, switch upcoming move to a group slam
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_1)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_2)
        EVT_CASE_OR_EQ(AVAL_Move_Charged_3)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_IF_LE(LVar0, 5)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Desperation)
            EVT_END_IF
    EVT_END_SWITCH
    // try dialogue before charging for the first time
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Move_PreCharge_1)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AVAL_Dialogue_FullPower)
                EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Dialogue_FullPower)
                EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_EXEC_WAIT(N(EVS_Dialogue_FullPower))
            EVT_END_IF
    EVT_END_SWITCH
    // try Tuff Puff swarm attack
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, AVAL_Dialogue_Request)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AVAL_Dialogue_Request)
            EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_EXEC_WAIT(N(EVS_Dialogue_PummelPermission))
        EVT_END_IF
        EVT_EXEC_WAIT(N(EVS_Attack_TuffPuffSwarm))
    EVT_END_IF
    EVT_CALL(GetPlayerHP, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    // try dialogue before first group slam
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Move_Desperation)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AVAL_Dialogue_Concerned)
                EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Dialogue_Concerned)
                EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_EXEC_WAIT(N(EVS_Dialogue_Concerned))
            EVT_END_IF
    EVT_END_SWITCH
    // select move according to fixed rotation through states
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Move_Basic_1)
            EVT_EXEC_WAIT(N(EVS_Move_HealOrSlam))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Breath_1)
        EVT_CASE_EQ(AVAL_Move_Breath_1)
            EVT_EXEC_WAIT(N(EVS_Move_HurricaneBreath))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_2)
        EVT_CASE_EQ(AVAL_Move_Basic_2)
            EVT_EXEC_WAIT(N(EVS_Move_HealOrSlam))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_PreCharge_1)
        EVT_CASE_EQ(AVAL_Move_PreCharge_1)
            EVT_EXEC_WAIT(N(EVS_Move_ChargeForGround))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Charged_1)
        EVT_CASE_EQ(AVAL_Move_Charged_1)
            EVT_EXEC_WAIT(N(EVS_Attack_GroundLightning))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_3)
        EVT_CASE_EQ(AVAL_Move_Basic_3)
            EVT_EXEC_WAIT(N(EVS_Move_HealOrSlam))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Breath_2)
        EVT_CASE_EQ(AVAL_Move_Breath_2)
            EVT_EXEC_WAIT(N(EVS_Move_HurricaneBreath))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_PreCharge_2)
        EVT_CASE_EQ(AVAL_Move_PreCharge_2)
            EVT_EXEC_WAIT(N(EVS_Move_ChargeForDirect))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Charged_2)
        EVT_CASE_EQ(AVAL_Move_Charged_2)
            EVT_EXEC_WAIT(N(EVS_Attack_DirectLightning))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_4)
        EVT_CASE_EQ(AVAL_Move_Basic_4)
            EVT_EXEC_WAIT(N(EVS_Move_HealOrSlam))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_PreCharge_3)
        EVT_CASE_EQ(AVAL_Move_PreCharge_3)
            EVT_EXEC_WAIT(N(EVS_Move_ChargeForGround))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Charged_3)
        EVT_CASE_EQ(AVAL_Move_Charged_3)
            EVT_EXEC_WAIT(N(EVS_Attack_GroundLightning))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Basic_1)
        EVT_CASE_EQ(AVAL_Move_Desperation)
            EVT_EXEC_WAIT(N(EVS_Attack_GroupSlam))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AVAR_Flag_LightningHit)
                EVT_IF_NOT_FLAG(LVar0, AVAL_Dialogue_Praise)
                    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, AVAL_Dialogue_Praise)
                    EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                    EVT_EXEC_WAIT(N(EVS_Dialogue_PraiseHuff))
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_BodySlam) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(AddBattleCamZoom, -200)
    EVT_CALL(SetBattleCamOffsetZ, -30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    EVT_SETF(LVar2, EVT_FLOAT(62.5))
    EVT_SETF(LVar3, EVT_FLOAT(47.5))
    EVT_MULF(LVar2, LVar0)
    EVT_MULF(LVar3, LVar1)
    EVT_DIVF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_CALL(AddGoalPos, ACTOR_SELF, LVar2, LVar3, 0)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 20, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LARGE_ACTOR_JUMP)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0B)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0C)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim0D)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar5, LVar6, LVar7)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar5, LVar3, LVar7)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(0.8))
            EVT_END_THREAD
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(AddGoalPos, ACTOR_SELF, -80, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 25, FALSE, FALSE, FALSE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.6))
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(0.4))
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, -30, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.2))
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, -20, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 80, -20, EASING_SIN_OUT)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0C)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim0D)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar3, 5)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, -30, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
    EVT_CALL(SetDamageSource, DMG_SRC_CRUSH)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MUL(LVar0, 100)
    EVT_DIV(LVar0, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_LE(20)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_LE(40)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_LE(60)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_LE(80)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_DEFAULT
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 20, EVT_FLOAT(1.0))
            EVT_END_THREAD
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
                    EVT_THREAD
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                        EVT_ADD(LVar1, 10)
                        EVT_WAIT(55)
                        EVT_PLAY_EFFECT(EFFECT_CLOUD_PUFF, LVar0, LVar1, LVar2, 0, 0)
                    EVT_END_THREAD
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpWithBounce, ACTOR_SELF, 20, EVT_FLOAT(4.0))
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RuffPuff_Inhale) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(SetOwnerID, LVar0) // note: ownership transferred to Tuff Puff actor here
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(GetActorPos, ACTOR_HUFF_N_PUFF, LVar5, LVar6, LVar7)
    EVT_ADD(LVar5, -13)
    EVT_ADD(LVar6, 0)
    EVT_ADD(LVar7, 0)
    EVT_CALL(N(MakeSuctionPath), LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7)
    EVT_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 1)
        EVT_WAIT(10)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TuffPuff_IsLarge, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim12)
        EVT_ELSE
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim13)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(MakeLerp, 255, 0, 10, EASING_LINEAR)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_END_THREAD
    EVT_SWITCH(LVar1)

        #define HNP_LOAD_SUCTION_PATH(idx) \
            EVT_CASE_EQ(idx) \
                EVT_CALL(LoadPath, 40, EVT_PTR(N(SuctionPaths)[idx]), 3, EASING_QUADRATIC_IN)
        
        // select the suction path for this Tuff Puff
        FOR_CHILDREN_ORDERED(HNP_LOAD_SUCTION_PATH)

    EVT_END_SWITCH
    EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVarA)
    EVT_MUL(LVarA, 1)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    EVT_ADD(LVar0, LVarA)
    EVT_IF_GT(LVar0, 100)
        EVT_SET(LVar0, 100)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar0)
    EVT_ADD(LVar0, LVarA)
    EVT_IF_GT(LVar0, 100)
        EVT_SET(LVar0, 100)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_ScaleY, LVar0)
    EVT_EXEC_WAIT(N(EVS_UpdateSize))
    EVT_WAIT(10)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_HealOrSlam) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    // use basic attack if no Tuff Puffs are present
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar9)
    EVT_IF_EQ(LVar9, 0)
        EVT_EXEC_WAIT(N(EVS_Attack_BodySlam))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, 0)

    #define HNP_ADD_HEAL_VALUE(idx) \
        EVT_IF_FLAG(LVar9, 1 << idx) \
            EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_HealValue, LVarB) \
            EVT_ADD(LVarA, LVarB) \
        EVT_END_IF

    // add heal values from Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_ADD_HEAL_VALUE)

    // 50% chance to use basic attack if healing would give 2 or less HP and Huff has healed before
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
    EVT_IF_FLAG(LVar0, AVAL_Flag_HasHealed)
        EVT_IF_LE(LVarA, 2)
            EVT_CALL(RandInt, 100, LVarB)
            EVT_IF_LT(LVarB, 50)
                EVT_EXEC_WAIT(N(EVS_Attack_BodySlam))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_INHALE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -13)
    EVT_ADD(LVar1, 0)
    EVT_ADD(LVar2, 0)
    EVT_CALL(N(HuffPuffBreath), 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(-1.0), EVT_FLOAT(1.2), 0, LVar8)
    EVT_CALL(N(StartRumbleWithParams), 80, 220)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 110, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_SET(LVar1, 0)

    #define HNP_INHALE_CHILD(idx) \
        EVT_IF_FLAG(LVar9, 1 << idx) \
            EVT_SET(LVar0, ArrayVar(idx)) \
            EVT_EXEC_GET_TID(N(EVS_RuffPuff_Inhale), LVar7) \
            EVT_ADD(LVar1, 1) \
            EVT_WAIT(5) \
        EVT_END_IF

    // inhale each Tuff Puff
    FOR_CHILDREN_SCATTERED(HNP_INHALE_CHILD)

    EVT_LABEL(0)
    EVT_IS_THREAD_RUNNING(LVar7, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(RemoveEffect, LVar8)
    EVT_CALL(StopSound, SOUND_HUFF_N_PUFF_INHALE)
    EVT_CALL(StopSound, SOUND_BIG_POWER_UP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim17)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim18)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim19)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, LVar3, 0)
    EVT_ADD(LVar0, 20)
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVarA, 0)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
    EVT_ADD(LVarB, LVarA)
    EVT_CALL(SetEnemyHP, ACTOR_SELF, LVarB)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChildBits, 0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_HasHealed)
    EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_HurricaneBreath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
    EVT_MULF(LVar3, EVT_FLOAT(-13.0))
    EVT_MULF(LVar4, EVT_FLOAT(0.0))
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_DIVF(LVar4, EVT_FLOAT(100.0))
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 1, LVar0, LVar1, LVar2, EVT_FLOAT(190.0), EVT_FLOAT(-1.0), EVT_FLOAT(1.5), 100, 0)
    EVT_CALL(N(StartRumbleWithParams), 80, 150)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 75, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        EVT_SET(LVar3, LVar2)
        EVT_ADD(LVar3, 25)
        EVT_CALL(MakeLerp, LVar2, LVar3, 90, EASING_SIN_OUT)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
        EVT_SET(LVar3, LVar2)
        EVT_ADD(LVar3, 25)
        EVT_CALL(MakeLerp, LVar2, LVar3, 90, EASING_SIN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_INHALE)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, 20)
    EVT_CALL(MoveBattleCamOver, 180)
    EVT_WAIT(90)
    EVT_CALL(StopSound, SOUND_HUFF_N_PUFF_INHALE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1E)
    EVT_WAIT(60)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim21)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim22)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_WIND_LOOP)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
                EVT_SET(LVar3, LVar2)
                EVT_SUB(LVar3, 25)
                EVT_CALL(MakeLerp, LVar2, LVar3, 40, EASING_CUBIC_IN)
                EVT_LABEL(2)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_GOTO(2)
                    EVT_END_IF
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
                EVT_SET(LVar3, LVar2)
                EVT_SUB(LVar3, 25)
                EVT_CALL(MakeLerp, LVar2, LVar3, 40, EASING_CUBIC_IN)
                EVT_LABEL(3)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_GOTO(3)
                    EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
            EVT_MULF(LVar3, EVT_FLOAT(-20.0))
            EVT_MULF(LVar4, EVT_FLOAT(-20.0))
            EVT_DIVF(LVar3, EVT_FLOAT(100.0))
            EVT_DIVF(LVar4, EVT_FLOAT(100.0))
            EVT_ADD(LVar0, LVar3)
            EVT_ADD(LVar1, LVar4)
            EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(190.0), EVT_FLOAT(1.5), EVT_FLOAT(1.0), 40, 0)
            EVT_CALL(N(StartRumbleWithParams), 80, 60)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 30, EVT_FLOAT(0.3))
            EVT_END_THREAD
            EVT_LOOP(10)
                EVT_CALL(RandInt, 150, LVar3)
                EVT_CALL(RandInt, 100, LVar4)
                EVT_ADD(LVar3, 50)
                EVT_SETF(LVar4, EVT_FLOAT(5.0))
                EVT_CALL(RandInt, 4, LVar5)
                EVT_ADDF(LVar4, LVar5)
                EVT_DIVF(LVar4, EVT_FLOAT(10.0))
                EVT_SETF(LVar5, EVT_FLOAT(100.0))
                EVT_CALL(RandInt, 40, LVar6)
                EVT_ADDF(LVar5, LVar6)
                EVT_DIVF(LVar5, EVT_FLOAT(10.0))
                EVT_PLAY_EFFECT(EFFECT_MOVING_CLOUD, 0, 200, LVar3, 5, -200, LVar4, 5, LVar5, LVar4, 0)
                EVT_CALL(RandInt, 5, LVar0)
                EVT_ADD(LVar0, 5)
                EVT_WAIT(LVar0)
            EVT_END_LOOP
            EVT_WAIT(20)
            EVT_CALL(StopSound, SOUND_HEAVY_WIND_LOOP)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 180)
        EVT_CALL(ShowActionHud, TRUE)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
        EVT_CALL(action_command_whirlwind_init, 0)
        EVT_CALL(SetupMashMeter, 5, 20, 40, 60, 80, 100)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        EVT_CALL(action_command_whirlwind_start, 0, 200 * DT, 3)
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 200, EASING_CUBIC_IN)
            EVT_LABEL(4)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(4)
                EVT_END_IF
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 200, EASING_CUBIC_IN)
            EVT_LABEL(5)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(5)
                EVT_END_IF
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
        EVT_MULF(LVar3, EVT_FLOAT(-20.0))
        EVT_MULF(LVar4, EVT_FLOAT(-20.0))
        EVT_DIVF(LVar3, EVT_FLOAT(100.0))
        EVT_DIVF(LVar4, EVT_FLOAT(100.0))
        EVT_ADD(LVar0, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(190.0), EVT_FLOAT(1.5), EVT_FLOAT(1.0), 200, 0)
        EVT_CALL(N(StartRumbleWithParams), 100, 350)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 175, EVT_FLOAT(0.3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(25)
                EVT_CALL(RandInt, 150, LVar3)
                EVT_CALL(RandInt, 100, LVar4)
                EVT_ADD(LVar3, 50)
                EVT_SETF(LVar4, EVT_FLOAT(5.0))
                EVT_CALL(RandInt, 4, LVar5)
                EVT_ADDF(LVar4, LVar5)
                EVT_DIVF(LVar4, EVT_FLOAT(10.0))
                EVT_SETF(LVar5, EVT_FLOAT(100.0))
                EVT_CALL(RandInt, 40, LVar6)
                EVT_ADDF(LVar5, LVar6)
                EVT_DIVF(LVar5, EVT_FLOAT(10.0))
                EVT_PLAY_EFFECT(EFFECT_MOVING_CLOUD, 0, 200, LVar3, 5, -200, LVar4, 5, LVar5, LVar4, 0)
                EVT_CALL(RandInt, 5, LVar0)
                EVT_ADD(LVar0, 5)
                EVT_WAIT(LVar0)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(MakeLerp, 0, 7200, 200, EASING_SIN_OUT)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(GetActionQuality, LVar1)
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
            EVT_LABEL(6)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(6)
                EVT_END_IF
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
            EVT_LABEL(7)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(7)
                EVT_END_IF
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
        EVT_MULF(LVar3, EVT_FLOAT(-20.0))
        EVT_MULF(LVar4, EVT_FLOAT(-20.0))
        EVT_DIVF(LVar3, EVT_FLOAT(100.0))
        EVT_DIVF(LVar4, EVT_FLOAT(100.0))
        EVT_ADD(LVar0, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_PLAY_EFFECT(EFFECT_HUFF_PUFF_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(190.0), EVT_FLOAT(1.5), EVT_FLOAT(1.0), 100, 0)
        EVT_CALL(N(StartRumbleWithParams), 100, 200)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 100, EVT_FLOAT(0.3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(15)
                EVT_CALL(RandInt, 150, LVar3)
                EVT_CALL(RandInt, 100, LVar4)
                EVT_ADD(LVar3, 50)
                EVT_SETF(LVar4, EVT_FLOAT(5.0))
                EVT_CALL(RandInt, 4, LVar5)
                EVT_ADDF(LVar4, LVar5)
                EVT_DIVF(LVar4, EVT_FLOAT(10.0))
                EVT_SETF(LVar5, EVT_FLOAT(100.0))
                EVT_CALL(RandInt, 40, LVar6)
                EVT_ADDF(LVar5, LVar6)
                EVT_DIVF(LVar5, EVT_FLOAT(10.0))
                EVT_PLAY_EFFECT(EFFECT_MOVING_CLOUD, 0, 200, LVar3, 5, -200, LVar4, 5, LVar5, LVar4, 0)
                EVT_CALL(RandInt, 5, LVar0)
                EVT_ADD(LVar0, 5)
                EVT_WAIT(LVar0)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_WAIT(110)
        EVT_SET(LVar1, 0)
    EVT_END_IF
    EVT_CALL(StopSound, SOUND_HEAVY_WIND_LOOP)
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_6, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_5, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_4, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(3)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_3, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(4)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_2, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_DEFAULT
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WIND_1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_ChargeForGround) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_EXEC_GET_TID(N(EVS_UpdateChargedJitter), LVarA)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim11)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim12)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim13)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ChargedBodyAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FACE, EVT_PTR(N(ChargedFaceAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, EVT_PTR(N(ChargedArmAnims)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHARGE_LIGHTNING)
    EVT_CALL(N(StartRumbleWithParams), 70, 120)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 60, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_CALL(N(MakeSnakingStatic), LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_GroundLightning) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(N(StartRumbleWithParams), 70, 100)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 100, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 60, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetBackgroundAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BodyAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FACE, EVT_PTR(N(FaceAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, EVT_PTR(N(ArmAnims)))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0E)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0F)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim10)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, FALSE)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 200, 0, 30, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(StopSound, SOUND_CHARGE_LIGHTNING)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_LIGHTNING_BLAST)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 10)
    EVT_SET(LVar3, LVar0)
    EVT_SUB(LVar3, 30)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, 1, LVar2, EVT_FLOAT(3.0), 30, 0)
    EVT_WAIT(5)
    EVT_CALL(N(StartRumbleWithParams), 256, 30)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(5.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_SETF(LVar6, EVT_FLOAT(0.0))
    EVT_LOOP(10)
        EVT_SET(LVar4, LVar3)
        EVT_SET(LVar5, LVar2)
        EVT_ADDF(LVar6, EVT_FLOAT(36.0))
        EVT_CALL(AddVectorPolar, LVar4, LVar5, EVT_FLOAT(300.0), LVar6)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar3, 1, LVar2, LVar4, 1, LVar5, EVT_FLOAT(4.0), 30, 0)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_GROUND_LIGHTNING, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_GT(LVar0, 0)
                EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AVAR_Flag_LightningHit)
                EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_END_IF
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_ChargeForDirect) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_EXEC_GET_TID(N(EVS_UpdateChargedJitter), LVarA)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim11)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim12)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim13)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ChargedBodyAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FACE, EVT_PTR(N(ChargedFaceAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, EVT_PTR(N(ChargedArmAnims)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHARGE_LIGHTNING)
    EVT_CALL(N(StartRumbleWithParams), 70, 120)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 60, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar3)
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_CALL(N(MakeSnakingStatic), LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_DirectLightning) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(AddBattleCamZoom, -100)
    EVT_CALL(SetBattleCamOffsetZ, 50)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 70, 80)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 40, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(UnkBackgroundFunc3))
        EVT_CALL(MakeLerp, 0, 200, 40, EASING_LINEAR)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(40)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVarA)
            EVT_CALL(N(SetSnakingStaticPos), LVarA, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar1)
    EVT_SETF(LVar2, EVT_FLOAT(72.5))
    EVT_SETF(LVar3, EVT_FLOAT(67.5))
    EVT_MULF(LVar2, LVar0)
    EVT_MULF(LVar3, LVar1)
    EVT_DIVF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar3, 0)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 40, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
    EVT_WAIT(30)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedJitterScriptID, LVarA)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedStaticEffect, LVar0)
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BodyAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FACE, EVT_PTR(N(FaceAnims)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_ARMS, EVT_PTR(N(ArmAnims)))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0E)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim0F)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim10)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, FALSE)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 200, 0, 30, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(StopSound, SOUND_CHARGE_LIGHTNING)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_FIRE_LIGHTNING)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
            EVT_SUB(LVarC, 10)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
            EVT_SUB(LVarD, 100)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVarA, LVarB, LVarC, LVarD, 0, LVarF, EVT_FLOAT(1.5), 20, 0)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 10)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 4)
            EVT_ADD(LVar4, 10)
            EVT_ADD(LVar5, 1)
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar6)
                EVT_SETF(LVar7, EVT_FLOAT(0.725))
                EVT_SETF(LVar8, EVT_FLOAT(0.242))
                EVT_MULF(LVar7, LVar6)
                EVT_MULF(LVar8, LVar6)
                EVT_SUBF(LVar0, LVar7)
                EVT_SETF(LVar9, LVar8)
                EVT_MULF(LVar9, 3)
                EVT_ADDF(LVar9, LVar0)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
                EVT_WAIT(3)
                EVT_SETF(LVar9, LVar8)
                EVT_MULF(LVar9, 1)
                EVT_ADDF(LVar9, LVar0)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
                EVT_WAIT(3)
                EVT_SETF(LVar9, LVar8)
                EVT_MULF(LVar9, 4)
                EVT_ADDF(LVar9, LVar0)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
                EVT_WAIT(3)
                EVT_SETF(LVar9, LVar8)
                EVT_MULF(LVar9, 2)
                EVT_ADDF(LVar9, LVar0)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
                EVT_WAIT(3)
                EVT_SETF(LVar9, LVar8)
                EVT_MULF(LVar9, 5)
                EVT_ADDF(LVar9, LVar0)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
            EVT_END_THREAD
            EVT_WAIT(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 4)
    EVT_ADD(LVar4, 10)
    EVT_ADD(LVar5, 1)
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar6)
        EVT_SETF(LVar7, EVT_FLOAT(0.725))
        EVT_SETF(LVar8, EVT_FLOAT(0.242))
        EVT_MULF(LVar7, LVar6)
        EVT_MULF(LVar8, LVar6)
        EVT_SUBF(LVar0, LVar7)
        EVT_SETF(LVar9, LVar8)
        EVT_MULF(LVar9, 3)
        EVT_ADDF(LVar9, LVar0)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
        EVT_WAIT(3)
        EVT_SETF(LVar9, LVar8)
        EVT_MULF(LVar9, 1)
        EVT_ADDF(LVar9, LVar0)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
        EVT_WAIT(3)
        EVT_SETF(LVar9, LVar8)
        EVT_MULF(LVar9, 4)
        EVT_ADDF(LVar9, LVar0)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
        EVT_WAIT(3)
        EVT_SETF(LVar9, LVar8)
        EVT_MULF(LVar9, 2)
        EVT_ADDF(LVar9, LVar0)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
        EVT_WAIT(3)
        EVT_SETF(LVar9, LVar8)
        EVT_MULF(LVar9, 5)
        EVT_ADDF(LVar9, LVar0)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar9, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.2), 10, 0)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DIRECT_LIGHTNING, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim03)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_GroupSlam) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_REAR_UP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1C)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim1E)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim1F)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_JIGGLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    EVT_SET(LVarF, 0)
    EVT_LOOP(20)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.3), 10, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.7), 10, 0, 0)
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
        EVT_ADD(LVarF, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_JIGGLE)
    EVT_LOOP(20)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
        EVT_ADD(LVarF, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    EVT_SET(LVar9, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_ADD(LVarB, 150)

    #define HNP_GROUP_ASCEND(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_CALL(UseIdleAnimation, ArrayVar(idx), FALSE) \
            EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
            EVT_IF_EQ(LVar1, 0) \
                EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim09) \
            EVT_ELSE \
                EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim0B) \
            EVT_END_IF \
            EVT_THREAD \
                EVT_MOD(LVar9, 2) \
                EVT_IF_EQ(LVar9, 0) \
                    EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                EVT_ELSE \
                    EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                EVT_END_IF \
                EVT_CALL(GetActorPos, ArrayVar(idx), LVarD, LVarE, LVarF) \
                EVT_CALL(SetGoalPos, ArrayVar(idx), LVarA, LVarB, LVarF) \
                EVT_CALL(FlyToGoal, ArrayVar(idx), 20, 10, EASING_QUADRATIC_IN) \
                EVT_SET(LVarD, LVarA) \
                EVT_SET(LVarE, LVarC) \
                EVT_SET(LVarF, idx) \
                EVT_MUL(LVarF, 36) \
                EVT_ADD(LVarF, -90) \
                EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF) \
                EVT_CALL(SetActorPos, ArrayVar(idx), LVarD, LVarB, LVarE) \
            EVT_END_THREAD \
            EVT_ADD(LVar9, 1) \
            EVT_WAIT(8) \
        EVT_END_IF

    // have each Tuff Puff ascend above the battlefield
    FOR_CHILDREN_SCATTERED(HNP_GROUP_ASCEND)

    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 10, EASING_QUADRATIC_IN)
    EVT_WAIT(75)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_GROUP_DROP(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_THREAD \
                EVT_CALL(GetActorPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar4) \
                EVT_IF_EQ(LVar4, 0) \
                    EVT_SET(LVar2, 10) \
                EVT_ELSE \
                    EVT_SET(LVar2, 14) \
                EVT_END_IF \
                EVT_CALL(SetActorSounds, ArrayVar(idx), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE) \
                EVT_CALL(SetGoalPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                EVT_CALL(FlyToGoal, ArrayVar(idx), 20, 0, EASING_CUBIC_IN) \
                EVT_CALL(ResetActorSounds, ArrayVar(idx), ACTOR_SOUND_FLY) \
            EVT_END_THREAD \
        EVT_END_IF

    // have each Tuff Puff drop down from the sky
    FOR_CHILDREN_ORDERED(HNP_GROUP_DROP)

    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_FALLING)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar4)
    EVT_MUL(LVar4, 95)
    EVT_DIV(LVar4, 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar4, LVar3)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_CUBIC_IN)
    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 3, LVar0, 0, LVar2, 0)
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar1, LVar4, LVar3, 60, 8, 0, 30, 0)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar1, LVar4, LVar3, 60, 8, 33, 30, 0)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar1, LVar4, LVar3, 60, 8, 66, 30, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 20, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
        EVT_SET(LVarF, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_WOBBLE)
        EVT_LOOP(20)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
            EVT_MULF(LVar2, LVar0)
            EVT_MULF(LVar3, LVar1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
            EVT_ADD(LVarF, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HUFF_N_PUFF_WOBBLE)
        EVT_LOOP(20)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
            EVT_MULF(LVar2, LVar0)
            EVT_MULF(LVar3, LVar1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
            EVT_ADD(LVarF, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(40)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
            EVT_MUL(LVar3, 95)
            EVT_DIV(LVar3, 200)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_IMPACT_JIGGLE(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_THREAD \
                EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar0) \
                EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar1) \
                EVT_SET(LVarF, 0) \
                EVT_LOOP(20) \
                    EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0) \
                    EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0) \
                    EVT_MULF(LVar2, LVar0) \
                    EVT_MULF(LVar3, LVar1) \
                    EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar2) \
                    EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar3) \
                    EVT_ADD(LVarF, 1) \
                    EVT_WAIT(1) \
                EVT_END_LOOP \
                EVT_LOOP(20) \
                    EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0) \
                    EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0) \
                    EVT_MULF(LVar2, LVar0) \
                    EVT_MULF(LVar3, LVar1) \
                    EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar2) \
                    EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar3) \
                    EVT_ADD(LVarF, 1) \
                    EVT_WAIT(1) \
                EVT_END_LOOP \
                EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleX, LVar0) \
                EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar1) \
            EVT_END_THREAD \
            EVT_THREAD \
                EVT_LOOP(40) \
                    EVT_CALL(GetActorPos, ArrayVar(idx), LVar0, LVar1, LVar2) \
                    EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_ScaleY, LVar3) \
                    EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar4) \
                    EVT_IF_EQ(LVar4, 0) \
                        EVT_MUL(LVar3, 20) \
                    EVT_ELSE \
                        EVT_MUL(LVar3, 28) \
                    EVT_END_IF \
                    EVT_DIV(LVar3, 200) \
                    EVT_CALL(SetActorPos, ArrayVar(idx), LVar0, LVar3, LVar2) \
                    EVT_WAIT(1) \
                EVT_END_LOOP \
            EVT_END_THREAD \
        EVT_END_IF

    // have each Tuff Puff oscillate after slamming into the ground
    FOR_CHILDREN_ORDERED(HNP_IMPACT_JIGGLE)

    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(100)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FACE, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ARMS, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_SET(LVarA, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                EVT_IF_FLAG(LVar0, 1 << idx) \
                    EVT_THREAD \
                        EVT_MOD(LVarA, 2) \
                        EVT_IF_EQ(LVarA, 0) \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        EVT_ELSE \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EVT_END_IF \
                        EVT_CALL(SetGoalToHome, ArrayVar(idx)) \
                        EVT_CALL(FlyToGoal, ArrayVar(idx), 20, -10, EASING_SIN_OUT) \
                    EVT_END_THREAD \
                    EVT_ADD(LVarA, 1) \
                    EVT_WAIT(8) \
                EVT_END_IF

            // have each Tuff Puff return to their home position
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)
            
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 20, -10, EASING_SIN_OUT)
            EVT_WAIT(15)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_SET(LVarA, DMG_GROUP_SLAM_BASE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_ADD_CHILD(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_ADD(LVarA, 1) \
        EVT_END_IF
    
    // add 1 damage for each Tuff Puff
    FOR_CHILDREN_ORDERED(HNP_ADD_CHILD)

    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarA, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(50)
            EVT_SET(LVarA, 0)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 20, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                EVT_IF_FLAG(LVar0, 1 << idx) \
                    EVT_THREAD \
                        EVT_MOD(LVarA, 2) \
                        EVT_IF_EQ(LVarA, 0) \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        EVT_ELSE \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EVT_END_IF \
                        EVT_CALL(SetGoalToHome, ArrayVar(idx)) \
                        EVT_CALL(FlyToGoal, ArrayVar(idx), 20, -10, EASING_SIN_OUT) \
                    EVT_END_THREAD \
                    EVT_ADD(LVarA, 1) \
                    EVT_WAIT(8) \
                EVT_END_IF

            // make each Tuff Puff return home
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)

            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TuffPuff_SqueezePlayer) = {
    EVT_IF_EQ(LVar3, 0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_DIV(LVarB, 2)
    EVT_ADD(LVarB, 1)
    EVT_CALL(SetOwnerID, LVar1) // note: ownership transferred to Tuff Puff actor here
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 1)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TuffPuff_WobbleMode, 2)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(GetDist2D, LVarD, LVar0, LVar2, LVar3, LVar5)
    EVT_CALL(N(Atan2), LVarE, LVar0, LVar2, LVar3, LVar5)
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SQUEEZE)
        EVT_SET(LVarF, 0)
        EVT_SET(LVarC, LVarB)
        EVT_ADD(LVarC, LVarB)
        EVT_SET(LVar9, LVarC)
        EVT_LOOP(LVarC)
            EVT_CALL(N(UpdateLerp), EASING_CUBIC_OUT, EVT_FLOAT(100.0), EVT_FLOAT(40.0), LVarF, LVar9, LVar0)
            EVT_MULF(LVar0, LVarD)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, LVar0, LVarE)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar1, LVar5, LVar3)
            EVT_ADD(LVarF, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AVAR_Flag_WaitForChild)
            EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
        EVT_END_IF
        EVT_SET(LVarF, 0)
        EVT_SET(LVarC, LVarB)
        EVT_LOOP(LVarC)
            EVT_CALL(N(UpdateLerp), EASING_QUARTIC_OUT, EVT_FLOAT(40.0), EVT_FLOAT(100.0), LVarF, LVarB, LVar0)
            EVT_MULF(LVar0, LVarD)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, LVar0, LVarE)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar1, LVar5, LVar3)
            EVT_ADD(LVarF, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_TuffPuffSwarm) = {
    EVT_USE_ARRAY(N(RuffPuffDataBuffer))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)
    
    #define HNP_SWARM_MOVE_UP(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_THREAD \
                EVT_CALL(GetActorPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                EVT_ADD(LVar2, 15) \
                EVT_CALL(SetGoalPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                EVT_CALL(FlyToGoal, ArrayVar(idx), 20, 0, EASING_LINEAR) \
                EVT_WAIT(3) \
            EVT_END_THREAD \
        EVT_END_IF

    // each Tuff Puff moves up slightly
    FOR_CHILDREN_SCATTERED(HNP_SWARM_MOVE_UP)

    EVT_WAIT(20)
    EVT_SET(LVarA, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_ADD_CHILD(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_ADD(LVarA, 1) \
        EVT_END_IF
    
    // count the number of Tuff Puffs to compute radial spacing around the player
    FOR_CHILDREN_ORDERED(HNP_ADD_CHILD)

    // radial increment will be stored in LVarB
    EVT_SETF(LVarB, EVT_FLOAT(360.0))
    EVT_DIVF(LVarB, LVarA)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 35)
        EVT_CALL(MoveBattleCamOver, 60)
    EVT_END_THREAD
    EVT_SET(LVarA, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_SWARM_SURROUND_PLAYER(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_CALL(UseIdleAnimation, ArrayVar(idx), FALSE) \
            EVT_CALL(SetPartAlpha, ArrayVar(idx), 1, 254) \
            EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
            EVT_IF_EQ(LVar1, 0) \
                EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim09) \
            EVT_ELSE \
                EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim0B) \
            EVT_END_IF \
            EVT_THREAD \
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3) \
                EVT_MULF(LVarB, LVarA) \
                EVT_ADDF(LVarB, EVT_FLOAT(100.0)) \
                EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB) \
                EVT_CALL(RandInt, 20, LVar4) \
                EVT_SUB(LVar4, 10) \
                EVT_ADD(LVar4, 19) \
                EVT_ADD(LVar2, LVar4) \
                EVT_MOD(LVarA, 2) \
                EVT_IF_EQ(LVarA, 0) \
                    EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                EVT_ELSE \
                    EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                EVT_END_IF \
                EVT_CALL(SetGoalPos, ArrayVar(idx), LVar1, LVar2, LVar3) \
                EVT_CALL(FlyToGoal, ArrayVar(idx), 30, -10, EASING_SIN_OUT) \
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6) \
                EVT_IF_LT(LVar1, LVar4) \
                    EVT_CALL(SetActorYaw, ArrayVar(idx), 180) \
                EVT_END_IF \
            EVT_END_THREAD \
            EVT_ADD(LVarA, 1) \
            EVT_WAIT(4) \
        EVT_END_IF

    // move each Tuff Puff to a position surrounding the player
    FOR_CHILDREN_SCATTERED(HNP_SWARM_SURROUND_PLAYER)
    
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_SET(LVar9, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)
    
    #define HNP_ADD_CHILD(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_ADD(LVar9, 1) \
        EVT_END_IF
    
    // count the number of Tuff Puffs
    FOR_CHILDREN_ORDERED(HNP_ADD_CHILD)

    EVT_SET(LVarA, 30 * DT)
    EVT_SUB(LVarA, LVar9)
    EVT_SET(LVar3, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

    #define HNP_SQUEEZE_PLAYER(idx) \
        EVT_IF_FLAG(LVar0, 1 << idx) \
            EVT_SET(LVar1, ArrayVar(idx)) \
            EVT_SET(LVar2, LVarA) \
            EVT_EXEC_GET_TID(N(EVS_TuffPuff_SqueezePlayer), ArrayVar(idx + MAX_RUFF_PUFFS)) \
            EVT_ADD(LVar3, 1) \
        EVT_END_IF

    // have each Tuff Puff squeeze the player
    FOR_CHILDREN_ORDERED(HNP_SQUEEZE_PLAYER)

    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_LABEL(0)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AVAR_Flag_WaitForChild)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_WaitForChild)
            EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_SCATTER_PUFF(idx) \
                EVT_IF_FLAG(LVar0, 1 << idx) \
                    EVT_KILL_THREAD(ArrayVar(idx + MAX_RUFF_PUFFS)) \
                    EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    EVT_IF_EQ(LVar1, 0) \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim12) \
                    EVT_ELSE \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim13) \
                    EVT_END_IF \
                    EVT_THREAD \
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2) \
                        EVT_CALL(GetActorPos, ArrayVar(idx), LVar3, LVar4, LVar5) \
                        EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5) \
                        EVT_DIVF(LVar6, EVT_FLOAT(2.0)) \
                        EVT_ADDF(LVar6, EVT_FLOAT(90.0)) \
                        EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6) \
                        EVT_CALL(SetActorJumpGravity, ArrayVar(idx), EVT_FLOAT(1.0)) \
                        EVT_CALL(SetGoalPos, ArrayVar(idx), LVar0, LVar1, LVar2) \
                        EVT_CALL(JumpToGoal, ArrayVar(idx), 20, FALSE, FALSE, FALSE) \
                    EVT_END_THREAD \
                EVT_END_IF

            // throw each Tuff Puff away in a large fan pattern
            FOR_CHILDREN_ORDERED(HNP_SCATTER_PUFF)

            EVT_WAIT(15)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_SET(LVarA, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                EVT_IF_FLAG(LVar0, 1 << idx) \
                    EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    EVT_IF_EQ(LVar1, 0) \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim06) \
                    EVT_ELSE \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim07) \
                    EVT_END_IF \
                    EVT_THREAD \
                        EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_WobbleMode, 0) \
                        EVT_MOD(LVarA, 2) \
                        EVT_IF_EQ(LVarA, 0) \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        EVT_ELSE \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EVT_END_IF \
                        EVT_CALL(SetGoalToHome, ArrayVar(idx)) \
                        EVT_CALL(FlyToGoal, ArrayVar(idx), 30, 10, EASING_SIN_OUT) \
                        EVT_CALL(SetPartAlpha, ArrayVar(idx), 1, 255) \
                        EVT_CALL(SetActorYaw, ArrayVar(idx), 0) \
                        EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                        EVT_IF_EQ(LVar1, 0) \
                            EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim02) \
                        EVT_ELSE \
                            EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim03) \
                        EVT_END_IF \
                    EVT_END_THREAD \
                    EVT_ADD(LVarA, 1) \
                    EVT_WAIT(4) \
                EVT_END_IF

            // have each Tuff Puff fly back to its home position
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)

            EVT_WAIT(50)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar1)
    EVT_IF_FLAG(LVar1, STATUS_FLAG_STONE)
        EVT_WAIT(10)
        EVT_SET(LVar3, 0)
        EVT_LOOP(0)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AVAR_Flag_WaitForChild)
                EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_WaitForChild)
                EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_WAIT(2)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_NICE_HIT)
                EVT_ADD(LVar3, 1)
            EVT_END_IF
            EVT_IF_GT(LVar3, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 180)
        EVT_CALL(ShowActionHud, TRUE)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        EVT_CALL(action_command_stop_leech_init)
        EVT_CALL(SetupMashMeter, 1, 25, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        EVT_CALL(action_command_stop_leech_start, 0, 32767, 3)
        EVT_SET(LVarB, LVarA)
        EVT_DIV(LVarB, 2)
        EVT_WAIT(LVarB)
        EVT_SET(LVarD, 0)
        EVT_LOOP(0)
            EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AVAR_Flag_WaitForChild)
                EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_BITWISE_AND_CONST(LVar0, ~AVAR_Flag_WaitForChild)
                EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_Flags, LVar0)
                EVT_WAIT(2)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_NICE_HIT)
                EVT_ADD(LVarD, 1)
            EVT_END_IF
            EVT_CALL(GetActionSuccessCopy, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_IF_GT(LVarD, 1)
                    EVT_CALL(func_80269470)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(func_80269470)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_IF_GE(LVarD, 20)
                EVT_CALL(func_80269470)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(func_80269470)
    EVT_END_IF
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_SCATTER_PUFF(idx) \
                EVT_IF_FLAG(LVar0, 1 << idx) \
                    EVT_KILL_THREAD(ArrayVar(idx + MAX_RUFF_PUFFS)) \
                    EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    EVT_IF_EQ(LVar1, 0) \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim12) \
                    EVT_ELSE \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim13) \
                    EVT_END_IF \
                    EVT_THREAD \
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2) \
                        EVT_CALL(GetActorPos, ArrayVar(idx), LVar3, LVar4, LVar5) \
                        EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5) \
                        EVT_DIVF(LVar6, EVT_FLOAT(2.0)) \
                        EVT_ADDF(LVar6, EVT_FLOAT(90.0)) \
                        EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6) \
                        EVT_CALL(SetActorJumpGravity, ArrayVar(idx), EVT_FLOAT(1.0)) \
                        EVT_CALL(SetGoalPos, ArrayVar(idx), LVar0, LVar1, LVar2) \
                        EVT_CALL(JumpToGoal, ArrayVar(idx), 20, FALSE, FALSE, FALSE) \
                    EVT_END_THREAD \
                EVT_END_IF

            // throw each Tuff Puff away in a large fan pattern
            FOR_CHILDREN_ORDERED(HNP_SCATTER_PUFF)

            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                EVT_WAIT(1)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
                    EVT_THREAD
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(20)
                            EVT_ADD(LVar0, 54)
                            EVT_MOD(LVar0, 360)
                            EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                    EVT_END_THREAD
                    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_Land)
                    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.5))
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(func_80273444, 20, 0, 1)
                EVT_ELSE
                    EVT_WAIT(20)
                EVT_END_IF
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_ELSE
                EVT_WAIT(20)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_SET(LVarA, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChildBits, LVar0)

            #define HNP_RETURN_HOME(idx) \
                EVT_IF_FLAG(LVar0, 1 << idx) \
                    EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                    EVT_IF_EQ(LVar1, 0) \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim06) \
                    EVT_ELSE \
                        EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim07) \
                    EVT_END_IF \
                    EVT_THREAD \
                        EVT_CALL(SetActorVar, ArrayVar(idx), AVAR_TuffPuff_WobbleMode, 0) \
                        EVT_MOD(LVarA, 2) \
                        EVT_IF_EQ(LVarA, 0) \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_A) \
                        EVT_ELSE \
                            EVT_CALL(PlaySoundAtActor, ArrayVar(idx), SOUND_RUFF_PUFF_FLY_B) \
                        EVT_END_IF \
                        EVT_CALL(SetGoalToHome, ArrayVar(idx)) \
                        EVT_CALL(FlyToGoal, ArrayVar(idx), 30, 10, EASING_SIN_OUT) \
                        EVT_CALL(SetPartAlpha, ArrayVar(idx), 1, 255) \
                        EVT_CALL(SetActorYaw, ArrayVar(idx), 0) \
                        EVT_CALL(GetActorVar, ArrayVar(idx), AVAR_TuffPuff_IsLarge, LVar1) \
                        EVT_IF_EQ(LVar1, 0) \
                            EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim02) \
                        EVT_ELSE \
                            EVT_CALL(SetAnimation, ArrayVar(idx), 1, ANIM_TuffPuff_Anim03) \
                        EVT_END_IF \
                    EVT_END_THREAD \
                    EVT_ADD(LVarA, 1) \
                    EVT_WAIT(4) \
                EVT_END_IF

            // have each Tuff Puff fly back to its home position
            FOR_CHILDREN_SCATTERED(HNP_RETURN_HOME)

            EVT_WAIT(50)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
