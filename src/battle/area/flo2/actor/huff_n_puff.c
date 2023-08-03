#include "../area.h"
#include "sprite/npc/HuffNPuff.h"
#include "sprite/npc/RuffPuff.h"
#include "sprite/player.h"
#include "battle/action_cmd/whirlwind.h"
#include "battle/action_cmd/stop_leech.h"

#define NAMESPACE A(huff_n_puff)

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
    PRT_3               = 3,
    PRT_4               = 4,
};

enum N(ActorVars) {
    N(VAR_FLAGS) = 0,
    N(VAR_TURN_NUMBER) = 1,
    N(VAR_TUFF_PUFF_BIT_ARRAY) = 2,
    N(VAR_COMBO_COUNTER) = 3,
    N(VAR_THREAD_ID) = 4,
    N(VAR_EFFECT_SNAKING_STATIC) = 5,
    N(VAR_SCALE_X) = 6,
    N(VAR_SCALE_Y) = 7,
};

enum N(Flags) {
    N(FLAG_HEALED_ONCE) = 0x01,
    N(FLAG_COMBO) = 0x02,
    N(FLAG_4) = 0x04,
    N(FLAG_HIT_GROUND_LIGHTNING) = 0x08,
    N(FLAG_SPEAK_1) = 0x10,
    N(FLAG_SPEAK_2) = 0x20,
    N(FLAG_SPEAK_3) = 0x40,
    N(FLAG_SPEAK_4) = 0x80,
};

extern ActorBlueprint A(tuff_puff);

extern EvtScript N(EVS_Init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);
extern EvtScript N(attackDirectLightning);
extern EvtScript N(normalAction);
extern EvtScript N(electricCharge);
extern EvtScript N(attackGroundLightning);
extern EvtScript N(attackGroundSlam);
extern EvtScript N(UpdateSize);
extern EvtScript N(attackTuffPuffs);
extern EvtScript N(attackWindBreath);
extern EvtScript N(electicCharge_copy);

extern Formation N(formation_tuff_puff_small);
extern Formation N(formation_tuff_puff_large);

typedef struct SuctionPath {
    /* 0x00 */ Vec3f start;
    /* 0x0C */ Vec3f mid;
    /* 0x18 */ Vec3f end;
} SuctionPath; // size = 0x24

static SuctionPath N(suctionPaths)[10];

#include "common/StartRumbleWithParams.inc.c"

API_CALLABLE(SetHealthBarPos) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(ACTOR_ENEMY0);

    actor->healthBarPos.x = actor->homePos.x + evt_get_variable(script, *args++);
    actor->healthBarPos.y = actor->homePos.y + evt_get_variable(script, *args++);
    actor->healthBarPos.z = actor->homePos.z;
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

API_CALLABLE(SetTuffPuffPos) {
    Bytecode* args = script->ptrReadPos;

    Bytecode outVar1 = *args++;
    f32 x = evt_get_float_variable(script, outVar1);
    Bytecode outVar2 = *args++;
    f32 y = evt_get_float_variable(script, outVar2);
    Bytecode outVar3 = *args++;
    f32 z = evt_get_float_variable(script, outVar3);

    f32 pitch = evt_get_float_variable(script, *args++);
    f32 yaw = evt_get_float_variable(script, *args++);
    f32 length = evt_get_float_variable(script, *args++);

    yaw -= 15.0f;
    x += length * cos_deg(pitch) * cos_deg(yaw);
    y += length * sin_deg(pitch);
    z -= length * cos_deg(pitch) * sin_deg(yaw);

    evt_set_float_variable(script, outVar1, x);
    evt_set_float_variable(script, outVar2, y);
    evt_set_float_variable(script, outVar3, z);
    return ApiStatus_DONE2;
}

API_CALLABLE(FindPlaceForTuffPuff) {
    Bytecode* args = script->ptrReadPos;
    s32 arr[10];
    s32 flags = evt_get_variable(script, *args++);
    s32 count = 0;
    s32 var_a2;

    if (!(flags & 2)) {
        arr[count++] = 2;
    }
    if (!(flags & 8)) {
        arr[count++] = 8;
    }
    if (!(flags & 0x20)) {
        arr[count++] = 0x20;
    }
    if (!(flags & 0x80)) {
        arr[count++] = 0x80;
    }
    if (!(flags & 0x200)) {
        arr[count++] = 0x200;
    }
    if (!(flags & 1)) {
        arr[count++] = 1;
    }
    if (!(flags & 4)) {
        arr[count++] = 4;
    }
    if (!(flags & 0x10)) {
        arr[count++] = 0x10;
    }

    if (count == 0) {
        if (!(flags & 0x100)) {
            arr[count++] = 0x100;
        }
        if (!(flags & 0x40)) {
            arr[count++] = 0x40;
        }
    }

    if (count == 0) {
        var_a2 = -1;
    } else {
        var_a2 = arr[rand_int(count - 1)];
    }

    evt_set_variable(script, *args++, var_a2);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetTuffPuffPriority) {
    s32* actorID = &script->owner1.actorID;
    N(formation_tuff_puff_small)[0].priority = get_actor(*actorID)->turnPriority;
    N(formation_tuff_puff_large)[0].priority = get_actor(*actorID)->turnPriority;
    return ApiStatus_DONE2;
}

API_CALLABLE(MakeSuctionPath) {
    Bytecode* args = script->ptrReadPos;
    SuctionPath* path = &N(suctionPaths)[evt_get_variable(script, *args++)];

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

API_CALLABLE(HuffPuffBreath) {
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

API_CALLABLE(SnakingStatic) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    script->varTablePtr[0] = fx_snaking_static(0, var1, var2, var3, var4 * 2.5f, 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetSnakingStaticPos) {
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

s32 N(TuffPuffActorIds)[32] = { };

s32 N(IdleAnimations)[] = {
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

s32 N(IdleAnimations2)[] = {
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

s32 N(IdleAnimations3)[] = {
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

s32 N(IdleAnimations_charged1)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim11,
    STATUS_END,
};

s32 N(IdleAnimations_charged2)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim12,
    STATUS_END,
};

s32 N(IdleAnimations_charged3)[] = {
    STATUS_KEY_NORMAL,    ANIM_HuffNPuff_Anim13,
    STATUS_END,
};

s32 N(IdleAnimations4)[] = {
    STATUS_KEY_NORMAL,    ANIM_RuffPuff_Anim02,
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
        .flags = ACTOR_PART_FLAG_8 | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 40 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -15, -50 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations2),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations3),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations4),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_8000,
    .type = ACTOR_TYPE_HUFF_N_PUFF,
    .level = 80,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), 100)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), 100)
    EVT_EXEC_WAIT(N(UpdateSize))
    EVT_RETURN
    EVT_END
};

EvtScript N(UpdateSize) = {
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_Y), LVar1)
    EVT_MUL(LVar0, 145)
    EVT_MUL(LVar1, 135)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(SetActorSize, ACTOR_ENEMY0, LVar1, LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_Y), LVar1)
    EVT_MUL(LVar0, -10)
    EVT_MUL(LVar1, 40)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(SetTargetOffset, ACTOR_ENEMY0, PRT_MAIN, LVar0, LVar1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_Y), LVar1)
    EVT_MUL(LVar0, -15)
    EVT_MUL(LVar1, -50)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_ENEMY0, PRT_MAIN, LVar0, LVar1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_Y), LVar1)
    EVT_MUL(LVar0, -17)
    EVT_MUL(LVar1, -31)
    EVT_DIV(LVar0, 100)
    EVT_DIV(LVar1, 100)
    EVT_CALL(SetHealthBarPos, LVar0, LVar1)
    EVT_RETURN
    EVT_END
};

EvtScript N(updateCharged) = {
    EVT_SET(LFlag0, FALSE)
    EVT_SET(LVarA, 0)
    EVT_SET(LVarB, 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(11)
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
        EVT_CASE_OR_EQ(7)
        EVT_CASE_OR_EQ(8)
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

EvtScript N(idle) = {
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), LVarA)
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
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar3)
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

Vec3i N(tuff_puff_pos) = { NPC_DISPOSE_LOCATION };

Formation N(formation_tuff_puff_small) = {
    ACTOR_BY_POS(A(tuff_puff), N(tuff_puff_pos), 0),
};

Formation N(formation_tuff_puff_large) = {
    ACTOR_BY_POS(A(tuff_puff), N(tuff_puff_pos), 0, 1),
};

EvtScript N(spawnTuffPuff) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar9)
    EVT_IF_LE(LVar9, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_40 | BS_FLAGS1_200)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar8)
    EVT_MUL(LVar8, 1)
    EVT_SUB(LVar0, LVar8)
    EVT_IF_LT(LVar0, 50)
        EVT_SET(LVar0, 50)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar0)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar8)
    EVT_MUL(LVar8, 1)
    EVT_SUB(LVar0, LVar8)
    EVT_IF_LT(LVar0, 50)
        EVT_SET(LVar0, 50)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar0)
    EVT_EXEC_WAIT(N(UpdateSize))
    EVT_SET(LVarA, 0)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_40 | BS_FLAGS1_200)
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
        EVT_CALL(SetTuffPuffPriority)
        EVT_IF_GT(LVarA, 0)
            EVT_SUB(LVarA, 1)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_tuff_puff_large)), FALSE)
            EVT_CALL(SetActorVar, LVar0, 5, 2)
        EVT_ELSE
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_tuff_puff_small)), FALSE)
            EVT_CALL(SetActorVar, LVar0, 5, 1)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar1)
        EVT_CALL(FindPlaceForTuffPuff, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(0x1)
                EVT_BITWISE_OR_CONST(LVar1, 0x1)
                EVT_SET(LVar2, 0)
                EVT_SET(ArrayVar(0), LVar0)
            EVT_CASE_EQ(0x2)
                EVT_BITWISE_OR_CONST(LVar1, 0x2)
                EVT_SET(LVar2, 1)
                EVT_SET(ArrayVar(1), LVar0)
            EVT_CASE_EQ(0x4)
                EVT_BITWISE_OR_CONST(LVar1, 0x4)
                EVT_SET(LVar2, 2)
                EVT_SET(ArrayVar(2), LVar0)
            EVT_CASE_EQ(0x8)
                EVT_BITWISE_OR_CONST(LVar1, 0x8)
                EVT_SET(LVar2, 3)
                EVT_SET(ArrayVar(3), LVar0)
            EVT_CASE_EQ(0x10)
                EVT_BITWISE_OR_CONST(LVar1, 0x10)
                EVT_SET(LVar2, 4)
                EVT_SET(ArrayVar(4), LVar0)
            EVT_CASE_EQ(0x20)
                EVT_BITWISE_OR_CONST(LVar1, 0x20)
                EVT_SET(LVar2, 5)
                EVT_SET(ArrayVar(5), LVar0)
            EVT_CASE_EQ(0x40)
                EVT_BITWISE_OR_CONST(LVar1, 0x40)
                EVT_SET(LVar2, 6)
                EVT_SET(ArrayVar(6), LVar0)
            EVT_CASE_EQ(0x80)
                EVT_BITWISE_OR_CONST(LVar1, 0x80)
                EVT_SET(LVar2, 7)
                EVT_SET(ArrayVar(7), LVar0)
            EVT_CASE_EQ(0x100)
                EVT_BITWISE_OR_CONST(LVar1, 0x100)
                EVT_SET(LVar2, 8)
                EVT_SET(ArrayVar(8), LVar0)
            EVT_CASE_EQ(0x200)
                EVT_BITWISE_OR_CONST(LVar1, 0x200)
                EVT_SET(LVar2, 9)
                EVT_SET(ArrayVar(9), LVar0)
            EVT_CASE_DEFAULT
                EVT_SET(LVar2, -1)
        EVT_END_SWITCH
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar1)
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
            EVT_CALL(SetActorVar, LVar0, 1, LVar2)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(SetActorPos, LVar0, LVar3, LVar4, LVar5)
            EVT_ADD(LVar3, -5)
            EVT_ADD(LVar4, 0)
            EVT_ADD(LVar5, 0)
            EVT_MUL(LVar2, 36)
            EVT_ADD(LVar2, 0)
            EVT_CALL(SetTuffPuffPos, LVar3, LVar4, LVar5, LVar2, EVT_FLOAT(0.0), EVT_FLOAT(50.0))
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

EvtScript N(OnHit) = {
    EVT_EXEC_WAIT(N(spawnTuffPuff))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(8)
        EVT_CASE_OR_EQ(11)
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
        EVT_SET(LVar0, 1)
        EVT_SET(LVar1, LVar2)
        EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_SET(LVar1, LVar3)
        EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 3)
        EVT_SET(LVar1, LVar4)
        EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnDeath) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_LABEL(0)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_100)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x1)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(0), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x2)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(1), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x4)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(2), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x8)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(3), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x10)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(4), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x20)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(5), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x40)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(6), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x80)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(7), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x100)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(8), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x200)
        EVT_CALL(SetDamageSource, DMG_SRC_DEFAULT)
        EVT_CALL(DispatchEvent, ArrayVar(9), EVENT_DEATH)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(8)
        EVT_CASE_OR_EQ(11)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_THREAD_ID), LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT_SNAKING_STATIC), LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(StopSound, SOUND_35C)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim08)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim09)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, ANIM_HuffNPuff_Anim07)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnBurn) = {
    EVT_EXEC_WAIT(N(spawnTuffPuff))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(8)
        EVT_CASE_OR_EQ(11)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, LVar3)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, LVar4)
    EVT_WAIT(20)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(8)
        EVT_CASE_OR_EQ(11)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, LVar3)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, LVar4)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnBurnDeath) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_LABEL(0)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_100)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x1)
        EVT_CALL(DispatchEvent, ArrayVar(0), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x2)
        EVT_CALL(DispatchEvent, ArrayVar(1), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x4)
        EVT_CALL(DispatchEvent, ArrayVar(2), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x8)
        EVT_CALL(DispatchEvent, ArrayVar(3), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x10)
        EVT_CALL(DispatchEvent, ArrayVar(4), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x20)
        EVT_CALL(DispatchEvent, ArrayVar(5), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x40)
        EVT_CALL(DispatchEvent, ArrayVar(6), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x80)
        EVT_CALL(DispatchEvent, ArrayVar(7), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x100)
        EVT_CALL(DispatchEvent, ArrayVar(8), EVENT_DEATH)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x200)
        EVT_CALL(DispatchEvent, ArrayVar(9), EVENT_DEATH)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(8)
        EVT_CASE_OR_EQ(11)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_THREAD_ID), LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT_SNAKING_STATIC), LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(StopSound, SOUND_35C)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim27)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim28)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, ANIM_HuffNPuff_Anim26)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnImmune) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(8)
        EVT_CASE_OR_EQ(11)
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
        EVT_SET(LVar0, 1)
        EVT_SET(LVar1, LVar2)
        EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_SET(LVar1, LVar3)
        EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 3)
        EVT_SET(LVar1, LVar4)
        EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnDamaged) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), 2)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(OnDamaged))
            EVT_EXEC_WAIT(N(OnHit))
        EVT_CASE_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(OnDamaged))
            EVT_EXEC_WAIT(N(OnHit))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_COMBO))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), 0)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(OnDamaged))
            EVT_EXEC_WAIT(N(OnBurn))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_COMBO))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(OnDamaged))
            EVT_EXEC_WAIT(N(OnBurn))
            EVT_EXEC_WAIT(N(OnBurnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_EXEC_WAIT(N(OnImmune))
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_EXEC_WAIT(N(OnImmune))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_COMBO))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(OnDamaged))
            EVT_EXEC_WAIT(N(OnHit))
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_EXEC_WAIT(N(OnDamaged))
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_EXEC_WAIT(N(OnImmune))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_COMBO))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMBO_COUNTER), 0)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(Speak1) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_SET(LVar0, ArrayVar(4))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_SET(LVar0, ArrayVar(9))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_SET(LVar0, ArrayVar(3))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_SET(LVar0, ArrayVar(5))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_SET(LVar0, ArrayVar(1))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_SET(LVar0, ArrayVar(8))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_SET(LVar0, ArrayVar(2))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_SET(LVar0, ArrayVar(7))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_GOTO(1)
    EVT_LABEL(0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, LVar0)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(GetActorVar, LVar0, 0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(SetAnimation, LVar0, 1, ANIM_RuffPuff_Anim09)
        EVT_CALL(ActorSpeak, MSG_CH6_00CF, LVar0, 1, ANIM_RuffPuff_Anim14, ANIM_RuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00CF, LVar0, 1, ANIM_RuffPuff_Anim15, ANIM_RuffPuff_Anim03)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_WAIT(20)
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim2D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim2E)
    EVT_CALL(ActorSpeak, MSG_CH6_00D0, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim2C, ANIM_HuffNPuff_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(Speak2) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim2D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim2E)
    EVT_CALL(ActorSpeak, MSG_CH6_00D1, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim2C, ANIM_HuffNPuff_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_SET(LVar0, ArrayVar(4))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_SET(LVar0, ArrayVar(9))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_SET(LVar0, ArrayVar(3))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_SET(LVar0, ArrayVar(5))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_SET(LVar0, ArrayVar(1))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_SET(LVar0, ArrayVar(8))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_SET(LVar0, ArrayVar(2))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_SET(LVar0, ArrayVar(7))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_GOTO(1)
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
    EVT_CALL(GetActorVar, LVar0, 0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(SetAnimation, LVar0, 1, ANIM_RuffPuff_Anim09)
        EVT_CALL(ActorSpeak, MSG_CH6_00D2, LVar0, 1, ANIM_RuffPuff_Anim14, ANIM_RuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00D2, LVar0, 1, ANIM_RuffPuff_Anim15, ANIM_RuffPuff_Anim03)
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
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(Speak3) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim18)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim19)
    EVT_CALL(ActorSpeak, MSG_CH6_00D3, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim17, ANIM_HuffNPuff_Anim17)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_SET(LVar0, ArrayVar(4))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_SET(LVar0, ArrayVar(9))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_SET(LVar0, ArrayVar(3))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_SET(LVar0, ArrayVar(5))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_SET(LVar0, ArrayVar(1))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_SET(LVar0, ArrayVar(8))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_SET(LVar0, ArrayVar(2))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_SET(LVar0, ArrayVar(7))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_GOTO(1)
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
    EVT_CALL(GetActorVar, LVar0, 0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(ActorSpeak, MSG_CH6_00D4, LVar0, 1, ANIM_RuffPuff_Anim14, ANIM_RuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00D4, LVar0, 1, ANIM_RuffPuff_Anim15, ANIM_RuffPuff_Anim03)
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
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(Speak4) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim24)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim25)
    EVT_CALL(ActorSpeak, MSG_CH6_00D5, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim23, ANIM_HuffNPuff_Anim23)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_SET(LVar0, ArrayVar(4))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_SET(LVar0, ArrayVar(9))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_SET(LVar0, ArrayVar(3))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_SET(LVar0, ArrayVar(5))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_SET(LVar0, ArrayVar(1))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_SET(LVar0, ArrayVar(8))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_SET(LVar0, ArrayVar(2))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_SET(LVar0, ArrayVar(7))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_GOTO(1)
    EVT_LABEL(0)
    EVT_CALL(BattleCamTargetActor, LVar0)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, LVar0, FALSE)
    EVT_CALL(GetActorVar, LVar0, 0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(ActorSpeak, MSG_CH6_00D6, LVar0, 1, ANIM_RuffPuff_Anim14, ANIM_RuffPuff_Anim02)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH6_00D6, LVar0, 1, ANIM_RuffPuff_Anim15, ANIM_RuffPuff_Anim03)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, LVar0, TRUE)
    EVT_LABEL(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim24)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim25)
    EVT_CALL(ActorSpeak, MSG_CH6_00D7, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim23, ANIM_HuffNPuff_Anim23)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(8)
        EVT_CASE_OR_EQ(11)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_IF_LE(LVar0, 5)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 12)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_NOT_FLAG(LVar0, N(FLAG_SPEAK_2))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_BITWISE_OR_CONST(LVar0, N(FLAG_SPEAK_2))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_EXEC_WAIT(N(Speak2))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
        EVT_IF_NOT_FLAG(LVar0, N(FLAG_SPEAK_1))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_OR_CONST(LVar0, N(FLAG_SPEAK_1))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_EXEC_WAIT(N(Speak1))
        EVT_END_IF
        EVT_EXEC_WAIT(N(attackTuffPuffs))
    EVT_END_IF
    EVT_CALL(GetPlayerHP, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_NOT_FLAG(LVar0, N(FLAG_SPEAK_4))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_BITWISE_OR_CONST(LVar0, N(FLAG_SPEAK_4))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_EXEC_WAIT(N(Speak4))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(normalAction))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 1)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(attackWindBreath))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 2)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(normalAction))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 3)
        EVT_CASE_EQ(3)
            EVT_EXEC_WAIT(N(electricCharge))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 4)
        EVT_CASE_EQ(4)
            EVT_EXEC_WAIT(N(attackGroundLightning))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 5)
        EVT_CASE_EQ(5)
            EVT_EXEC_WAIT(N(normalAction))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 6)
        EVT_CASE_EQ(6)
            EVT_EXEC_WAIT(N(attackWindBreath))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 7)
        EVT_CASE_EQ(7)
            EVT_EXEC_WAIT(N(electicCharge_copy))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 8)
        EVT_CASE_EQ(8)
            EVT_EXEC_WAIT(N(attackDirectLightning))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 9)
        EVT_CASE_EQ(9)
            EVT_EXEC_WAIT(N(normalAction))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 10)
        EVT_CASE_EQ(10)
            EVT_EXEC_WAIT(N(electricCharge))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 11)
        EVT_CASE_EQ(11)
            EVT_EXEC_WAIT(N(attackGroundLightning))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_NUMBER), 0)
        EVT_CASE_EQ(12)
            EVT_EXEC_WAIT(N(attackGroundSlam))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_FLAG(LVar0, N(FLAG_HIT_GROUND_LIGHTNING))
                EVT_IF_NOT_FLAG(LVar0, N(FLAG_SPEAK_3))
                    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, N(FLAG_SPEAK_3))
                    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                    EVT_EXEC_WAIT(N(Speak3))
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(attackBodySlam) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(AddBattleCamZoom, -200)
    EVT_CALL(SetBattleCamOffsetZ, -30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar1)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E7)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0B)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim0C)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim0D)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim06)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 80, -20, EASING_SIN_OUT)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim0C)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim0D)
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
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 8, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_LE(40)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 8, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_LE(60)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 8, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_LE(80)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 8, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_DEFAULT
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 8, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(inhaleOne) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(SetOwnerID, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar5, LVar6, LVar7)
    EVT_ADD(LVar5, -13)
    EVT_ADD(LVar6, 0)
    EVT_ADD(LVar7, 0)
    EVT_CALL(MakeSuctionPath, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7)
    EVT_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
        EVT_WAIT(10)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RuffPuff_Anim12)
        EVT_ELSE
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_RuffPuff_Anim13)
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
        EVT_CASE_EQ(0)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[0]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(1)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[1]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(2)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[2]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(3)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[3]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(4)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[4]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(5)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[5]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(6)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[6]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(7)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[7]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[8]), 3, EASING_QUADRATIC_IN)
        EVT_CASE_EQ(9)
            EVT_CALL(LoadPath, 40, EVT_PTR(N(suctionPaths)[9]), 3, EASING_QUADRATIC_IN)
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
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_X), LVar0)
    EVT_ADD(LVar0, LVarA)
    EVT_IF_GT(LVar0, 100)
        EVT_SET(LVar0, 100)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_Y), LVar0)
    EVT_ADD(LVar0, LVarA)
    EVT_IF_GT(LVar0, 100)
        EVT_SET(LVar0, 100)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_SCALE_Y), LVar0)
    EVT_EXEC_WAIT(N(UpdateSize))
    EVT_WAIT(10)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(normalAction) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar9)
    EVT_IF_EQ(LVar9, 0)
        EVT_EXEC_WAIT(N(attackBodySlam))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_IF_FLAG(LVar9, 0x00000001)
        EVT_CALL(GetActorVar, ArrayVar(0), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000002)
        EVT_CALL(GetActorVar, ArrayVar(1), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000004)
        EVT_CALL(GetActorVar, ArrayVar(2), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000008)
        EVT_CALL(GetActorVar, ArrayVar(3), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000010)
        EVT_CALL(GetActorVar, ArrayVar(4), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000020)
        EVT_CALL(GetActorVar, ArrayVar(5), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000040)
        EVT_CALL(GetActorVar, ArrayVar(6), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000080)
        EVT_CALL(GetActorVar, ArrayVar(7), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000100)
        EVT_CALL(GetActorVar, ArrayVar(8), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000200)
        EVT_CALL(GetActorVar, ArrayVar(9), 5, LVarB)
        EVT_ADD(LVarA, LVarB)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_IF_FLAG(LVar0, N(FLAG_HEALED_ONCE))
        EVT_IF_LE(LVarA, 2)
            EVT_CALL(RandInt, 100, LVarB)
            EVT_IF_LT(LVarB, 50)
                EVT_EXEC_WAIT(N(attackBodySlam))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim1B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim1C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -13)
    EVT_ADD(LVar1, 0)
    EVT_ADD(LVar2, 0)
    EVT_CALL(HuffPuffBreath, 0, LVar0, LVar1, LVar2, EVT_FLOAT(180.0), EVT_FLOAT(-1.0), EVT_FLOAT(1.2), 0, LVar8)
    EVT_CALL(N(StartRumbleWithParams), 80, 220)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 110, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_SET(LVar1, 0)
    EVT_IF_FLAG(LVar9, 0x00000010)
        EVT_SET(LVar0, ArrayVar(4))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000200)
        EVT_SET(LVar0, ArrayVar(9))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000008)
        EVT_SET(LVar0, ArrayVar(3))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000020)
        EVT_SET(LVar0, ArrayVar(5))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000002)
        EVT_SET(LVar0, ArrayVar(1))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000001)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000100)
        EVT_SET(LVar0, ArrayVar(8))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000004)
        EVT_SET(LVar0, ArrayVar(2))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000080)
        EVT_SET(LVar0, ArrayVar(7))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_IF_FLAG(LVar9, 0x00000040)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_EXEC_GET_TID(N(inhaleOne), LVar7)
        EVT_ADD(LVar1, 1)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_IS_THREAD_RUNNING(LVar7, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(RemoveEffect, LVar8)
    EVT_CALL(StopSound, SOUND_3B0)
    EVT_CALL(StopSound, SOUND_BIG_POWER_UP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim17)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim18)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim19)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar3)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, LVar3, 0)
    EVT_ADD(LVar0, 20)
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVarA, 0)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
    EVT_ADD(LVarB, LVarA)
    EVT_CALL(SetEnemyHP, ACTOR_SELF, LVarB)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), 0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_BITWISE_OR_CONST(LVar0, N(FLAG_HEALED_ONCE))
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackWindBreath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim1B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim1C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar3)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar4)
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
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
        EVT_SET(LVar3, LVar2)
        EVT_ADD(LVar3, 25)
        EVT_CALL(MakeLerp, LVar2, LVar3, 90, EASING_SIN_OUT)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar2)
        EVT_SET(LVar3, LVar2)
        EVT_ADD(LVar3, 25)
        EVT_CALL(MakeLerp, LVar2, LVar3, 90, EASING_SIN_OUT)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B0)
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
    EVT_CALL(StopSound, SOUND_3B0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim1D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim1E)
    EVT_WAIT(60)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim21)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim22)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35D)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
                EVT_SET(LVar3, LVar2)
                EVT_SUB(LVar3, 25)
                EVT_CALL(MakeLerp, LVar2, LVar3, 40, EASING_CUBIC_IN)
                EVT_LABEL(2)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar2)
                EVT_SET(LVar3, LVar2)
                EVT_SUB(LVar3, 25)
                EVT_CALL(MakeLerp, LVar2, LVar3, 40, EASING_CUBIC_IN)
                EVT_LABEL(3)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(3)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar3)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar4)
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
            EVT_CALL(StopSound, SOUND_35D)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_03, 180)
        EVT_CALL(ShowActionHud, TRUE)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
        EVT_CALL(action_command_whirlwind_init, 0)
        EVT_CALL(SetupMashMeter, 5, 20, 40, 60, 80, 100)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        EVT_CALL(action_command_whirlwind_start, 0, 200 * DT, 3)
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 200, EASING_CUBIC_IN)
            EVT_LABEL(4)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(4)
            EVT_END_IF
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 200, EASING_CUBIC_IN)
            EVT_LABEL(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(5)
            EVT_END_IF
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar3)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar4)
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
        EVT_CALL(MakeLerp, 0, 0x00001C20, 200, EASING_SIN_OUT)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActionResult, LVar1)
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
            EVT_LABEL(6)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(6)
            EVT_END_IF
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar2)
            EVT_SET(LVar3, LVar2)
            EVT_SUB(LVar3, 25)
            EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
            EVT_LABEL(7)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(7)
            EVT_END_IF
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar3)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar4)
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
    EVT_CALL(StopSound, SOUND_35D)
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 7, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 6, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(3)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(4)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_DEFAULT
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(electricCharge) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_EXEC_GET_TID(N(updateCharged), LVarA)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_THREAD_ID), LVarA)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim11)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim12)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim13)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_charged1)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_charged2)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_3, EVT_PTR(N(IdleAnimations_charged3)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35C)
    EVT_CALL(N(StartRumbleWithParams), 70, 120)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 60, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar3)
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_CALL(SnakingStatic, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EFFECT_SNAKING_STATIC), LVar0)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackGroundLightning) = {
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_THREAD_ID), LVarA)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT_SNAKING_STATIC), LVar0)
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations2)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_3, EVT_PTR(N(IdleAnimations3)))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0E)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim0F)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim10)
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
    EVT_CALL(StopSound, SOUND_35C)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D3)
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
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 12, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_GT(LVar0, 0)
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_BITWISE_OR_CONST(LVar0, N(FLAG_HIT_GROUND_LIGHTNING))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_END_IF
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(electicCharge_copy) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_EXEC_GET_TID(N(updateCharged), LVarA)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_THREAD_ID), LVarA)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim11)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim12)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim13)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_charged1)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_charged2)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_3, EVT_PTR(N(IdleAnimations_charged3)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ELECTRIFIED, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35C)
    EVT_CALL(N(StartRumbleWithParams), 70, 120)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 60, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar3)
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_CALL(SnakingStatic, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EFFECT_SNAKING_STATIC), LVar0)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(attackDirectLightning) = {
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
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT_SNAKING_STATIC), LVarA)
            EVT_CALL(SetSnakingStaticPos, LVarA, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar1)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_THREAD_ID), LVarA)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT_SNAKING_STATIC), LVar0)
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations2)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_3, EVT_PTR(N(IdleAnimations3)))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim0E)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim0F)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim10)
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
    EVT_CALL(StopSound, SOUND_35C)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35B)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim06)
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
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar6)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim06)
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
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar6)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 10, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim01)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim02)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim03)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 40, -20, EASING_SIN_OUT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackGroundSlam) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 5)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B3)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1A)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim1B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim1C)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim1D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim1E)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim1F)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B6)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar1)
    EVT_SET(LVarF, 0)
    EVT_LOOP(20)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.3), 10, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.7), 10, 0, 0)
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar1)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar3)
        EVT_ADD(LVarF, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B6)
    EVT_LOOP(20)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
        EVT_MULF(LVar2, LVar0)
        EVT_MULF(LVar3, LVar1)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar3)
        EVT_ADD(LVarF, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar1)
    EVT_SET(LVar9, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_ADD(LVarB, 150)
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_CALL(UseIdleAnimation, ArrayVar(4), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(4), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(4), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(4), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 4)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(4), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_CALL(UseIdleAnimation, ArrayVar(9), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(9), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(9), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(9), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 9)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(9), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_CALL(UseIdleAnimation, ArrayVar(3), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(3), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(3), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(3), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 3)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(3), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_CALL(UseIdleAnimation, ArrayVar(5), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(5), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(5), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(5), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 5)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(5), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_CALL(UseIdleAnimation, ArrayVar(1), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(1), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(1), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(1), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 1)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(1), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_CALL(UseIdleAnimation, ArrayVar(0), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(0), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(0), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(0), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 0)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(0), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_CALL(UseIdleAnimation, ArrayVar(8), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(8), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(8), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(8), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 8)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(8), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_CALL(UseIdleAnimation, ArrayVar(2), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(2), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(2), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(2), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 2)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(2), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_CALL(UseIdleAnimation, ArrayVar(7), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(7), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(7), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(7), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 7)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(7), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_CALL(UseIdleAnimation, ArrayVar(6), FALSE)
        EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_MOD(LVar9, 2)
            EVT_IF_EQ(LVar9, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(GetActorPos, ArrayVar(6), LVarD, LVarE, LVarF)
            EVT_CALL(SetGoalPos, ArrayVar(6), LVarA, LVarB, LVarF)
            EVT_CALL(FlyToGoal, ArrayVar(6), 20, 10, EASING_QUADRATIC_IN)
            EVT_SET(LVarD, LVarA)
            EVT_SET(LVarE, LVarC)
            EVT_SET(LVarF, 6)
            EVT_MUL(LVarF, 36)
            EVT_ADD(LVarF, -90)
            EVT_CALL(AddVectorPolar, LVarD, LVarE, EVT_FLOAT(60.0), LVarF)
            EVT_CALL(SetActorPos, ArrayVar(6), LVarD, LVarB, LVarE)
        EVT_END_THREAD
        EVT_ADD(LVar9, 1)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 10, EASING_QUADRATIC_IN)
    EVT_WAIT(75)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(0), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(0), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(0), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(0), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(0), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(1), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(1), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(1), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(1), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(1), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(2), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(2), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(2), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(2), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(2), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(3), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(3), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(3), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(3), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(3), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(4), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(4), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(4), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(4), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(4), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(5), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(5), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(5), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(5), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(5), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(6), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(6), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(6), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(6), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(6), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(7), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(7), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(7), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(7), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(7), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(8), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(8), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(8), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(8), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(8), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(9), LVar1, LVar2, LVar3)
            EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar2, 10)
            EVT_ELSE
                EVT_SET(LVar2, 14)
            EVT_END_IF
            EVT_CALL(SetActorSounds, ArrayVar(9), ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalPos, ArrayVar(9), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(9), 20, 0, EASING_CUBIC_IN)
            EVT_CALL(ResetActorSounds, ArrayVar(9), ACTOR_SOUND_FLY)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E9)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar4)
    EVT_MUL(LVar4, 95)
    EVT_DIV(LVar4, 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar4, LVar3)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_CUBIC_IN)
    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
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
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar1)
        EVT_SET(LVarF, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B7)
        EVT_LOOP(20)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
            EVT_MULF(LVar2, LVar0)
            EVT_MULF(LVar3, LVar1)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar3)
            EVT_ADD(LVarF, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B7)
        EVT_LOOP(20)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
            EVT_MULF(LVar2, LVar0)
            EVT_MULF(LVar3, LVar1)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar3)
            EVT_ADD(LVarF, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(40)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar3)
            EVT_MUL(LVar3, 95)
            EVT_DIV(LVar3, 200)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(0), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(0), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(0), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(0), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(0), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(0), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(0), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(0), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(0), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(0), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(0), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(1), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(1), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(1), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(1), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(1), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(1), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(1), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(1), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(1), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(1), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(1), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(2), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(2), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(2), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(2), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(2), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(2), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(2), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(2), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(2), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(2), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(2), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(3), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(3), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(3), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(3), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(3), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(3), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(3), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(3), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(3), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(3), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(3), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(4), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(4), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(4), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(4), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(4), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(4), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(4), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(4), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(4), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(4), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(4), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(5), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(5), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(5), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(5), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(5), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(5), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(5), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(5), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(5), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(5), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(5), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(6), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(6), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(6), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(6), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(6), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(6), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(6), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(6), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(6), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(6), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(6), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(7), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(7), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(7), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(7), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(7), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(7), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(7), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(7), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(7), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(7), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(7), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(8), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(8), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(8), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(8), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(8), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(8), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(8), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(8), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(8), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(8), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(8), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_THREAD
            EVT_CALL(GetActorVar, ArrayVar(9), 3, LVar0)
            EVT_CALL(GetActorVar, ArrayVar(9), 4, LVar1)
            EVT_SET(LVarF, 0)
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.5), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.5), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(9), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(9), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.2), 10, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar3, EVT_FLOAT(1.0), EVT_FLOAT(0.8), 10, 0, 0)
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar1)
                EVT_CALL(SetActorVar, ArrayVar(9), 3, LVar2)
                EVT_CALL(SetActorVar, ArrayVar(9), 4, LVar3)
                EVT_ADD(LVarF, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorVar, ArrayVar(9), 3, LVar0)
            EVT_CALL(SetActorVar, ArrayVar(9), 4, LVar1)
        EVT_END_THREAD
        EVT_THREAD
            EVT_LOOP(40)
                EVT_CALL(GetActorPos, ArrayVar(9), LVar0, LVar1, LVar2)
                EVT_CALL(GetActorVar, ArrayVar(9), 4, LVar3)
                EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar4)
                EVT_IF_EQ(LVar4, 0)
                    EVT_MUL(LVar3, 20)
                EVT_ELSE
                    EVT_MUL(LVar3, 28)
                EVT_END_IF
                EVT_DIV(LVar3, 200)
                EVT_CALL(SetActorPos, ArrayVar(9), LVar0, LVar3, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(100)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HuffNPuff_Anim04)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_HuffNPuff_Anim05)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_HuffNPuff_Anim06)
            EVT_WAIT(20)
            EVT_SET(LVarA, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(4))
                    EVT_CALL(FlyToGoal, ArrayVar(4), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000200)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(9))
                    EVT_CALL(FlyToGoal, ArrayVar(9), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000008)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(3))
                    EVT_CALL(FlyToGoal, ArrayVar(3), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000020)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(5))
                    EVT_CALL(FlyToGoal, ArrayVar(5), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000002)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(1))
                    EVT_CALL(FlyToGoal, ArrayVar(1), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000001)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(0))
                    EVT_CALL(FlyToGoal, ArrayVar(0), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000100)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(8))
                    EVT_CALL(FlyToGoal, ArrayVar(8), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000004)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(2))
                    EVT_CALL(FlyToGoal, ArrayVar(2), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000080)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(7))
                    EVT_CALL(FlyToGoal, ArrayVar(7), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(6))
                    EVT_CALL(FlyToGoal, ArrayVar(6), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 20, -10, EASING_SIN_OUT)
            EVT_WAIT(15)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_SET(LVarA, 5)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarA, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(50)
            EVT_SET(LVarA, 0)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 20, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(4))
                    EVT_CALL(FlyToGoal, ArrayVar(4), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000200)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(9))
                    EVT_CALL(FlyToGoal, ArrayVar(9), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000008)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(3))
                    EVT_CALL(FlyToGoal, ArrayVar(3), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000020)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(5))
                    EVT_CALL(FlyToGoal, ArrayVar(5), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000002)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(1))
                    EVT_CALL(FlyToGoal, ArrayVar(1), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000001)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(0))
                    EVT_CALL(FlyToGoal, ArrayVar(0), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000100)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(8))
                    EVT_CALL(FlyToGoal, ArrayVar(8), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000004)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(2))
                    EVT_CALL(FlyToGoal, ArrayVar(2), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000080)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(7))
                    EVT_CALL(FlyToGoal, ArrayVar(7), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_THREAD
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(6))
                    EVT_CALL(FlyToGoal, ArrayVar(6), 20, -10, EASING_SIN_OUT)
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(8)
            EVT_END_IF
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(tuffPuffMoveToPlayer) = {
    EVT_IF_EQ(LVar3, 0)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_DIV(LVarB, 2)
    EVT_ADD(LVarB, 1)
    EVT_CALL(SetOwnerID, LVar1)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(GetDist2D, LVarD, LVar0, LVar2, LVar3, LVar5)
    EVT_CALL(N(Atan2), LVarE, LVar0, LVar2, LVar3, LVar5)
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DB)
        EVT_SET(LVarF, 0)
        EVT_SET(LVarC, LVarB)
        EVT_ADD(LVarC, LVarB)
        EVT_SET(LVar9, LVarC)
        EVT_LOOP(LVarC)
            EVT_CALL(N(UpdateLerp), 5, EVT_FLOAT(100.0), EVT_FLOAT(40.0), LVarF, LVar9, LVar0)
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
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_OR_CONST(LVar0, N(FLAG_4))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
        EVT_END_IF
        EVT_SET(LVarF, 0)
        EVT_SET(LVarC, LVarB)
        EVT_LOOP(LVarC)
            EVT_CALL(N(UpdateLerp), 6, EVT_FLOAT(40.0), EVT_FLOAT(100.0), LVarF, LVarB, LVar0)
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

EvtScript N(attackTuffPuffs) = {
    EVT_USE_ARRAY(N(TuffPuffActorIds))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(4), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(4), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(4), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(9), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(9), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(9), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(3), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(3), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(3), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(5), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(5), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(5), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(1), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(1), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(1), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(0), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(0), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(0), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(8), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(8), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(8), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(2), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(2), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(2), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(7), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(7), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(7), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_THREAD
            EVT_CALL(GetActorPos, ArrayVar(6), LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetGoalPos, ArrayVar(6), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(6), 20, 0, EASING_LINEAR)
            EVT_WAIT(3)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(20)
    EVT_SET(LVarA, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_ADD(LVarA, 1)
    EVT_END_IF
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_CALL(UseIdleAnimation, ArrayVar(4), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(4), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(4), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(4), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(4), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_CALL(UseIdleAnimation, ArrayVar(9), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(9), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(9), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(9), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(9), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_CALL(UseIdleAnimation, ArrayVar(3), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(3), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(3), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(3), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(3), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_CALL(UseIdleAnimation, ArrayVar(5), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(5), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(5), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(5), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(5), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_CALL(UseIdleAnimation, ArrayVar(1), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(1), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(1), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(1), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(1), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_CALL(UseIdleAnimation, ArrayVar(0), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(0), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(0), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(0), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(0), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_CALL(UseIdleAnimation, ArrayVar(8), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(8), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(8), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(8), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(8), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_CALL(UseIdleAnimation, ArrayVar(2), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(2), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(2), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(2), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(2), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_CALL(UseIdleAnimation, ArrayVar(7), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(7), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(7), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(7), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(7), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_CALL(UseIdleAnimation, ArrayVar(6), FALSE)
        EVT_CALL(SetPartAlpha, ArrayVar(6), 1, 254)
        EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim09)
        EVT_ELSE
            EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim0B)
        EVT_END_IF
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_MULF(LVarB, LVarA)
            EVT_ADDF(LVarB, EVT_FLOAT(100.0))
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVarB)
            EVT_CALL(RandInt, 20, LVar4)
            EVT_SUB(LVar4, 10)
            EVT_ADD(LVar4, 19)
            EVT_ADD(LVar2, LVar4)
            EVT_MOD(LVarA, 2)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D5)
            EVT_ELSE
                EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D6)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ArrayVar(6), LVar1, LVar2, LVar3)
            EVT_CALL(FlyToGoal, ArrayVar(6), 30, -10, EASING_SIN_OUT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_CALL(SetActorYaw, ArrayVar(6), 180)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVarA, 1)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_SET(LVar9, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_ADD(LVar9, 1)
    EVT_END_IF
    EVT_SET(LVarA, 30 * DT)
    EVT_SUB(LVarA, LVar9)
    EVT_SET(LVar3, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
    EVT_IF_FLAG(LVar0, 0x00000001)
        EVT_SET(LVar1, ArrayVar(0))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(10))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000002)
        EVT_SET(LVar1, ArrayVar(1))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(11))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000004)
        EVT_SET(LVar1, ArrayVar(2))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(12))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000008)
        EVT_SET(LVar1, ArrayVar(3))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(13))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000010)
        EVT_SET(LVar1, ArrayVar(4))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(14))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000020)
        EVT_SET(LVar1, ArrayVar(5))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(15))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000040)
        EVT_SET(LVar1, ArrayVar(6))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(16))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000080)
        EVT_SET(LVar1, ArrayVar(7))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(17))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000100)
        EVT_SET(LVar1, ArrayVar(8))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(18))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_SET(LVar1, ArrayVar(9))
        EVT_SET(LVar2, LVarA)
        EVT_EXEC_GET_TID(N(tuffPuffMoveToPlayer), ArrayVar(19))
        EVT_ADD(LVar3, 1)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_LABEL(0)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_NOT_FLAG(LVar0, N(FLAG_4))
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_4))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
            EVT_IF_FLAG(LVar0, 0x00000001)
                EVT_KILL_THREAD(ArrayVar(10))
                EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(0), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(0), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(0), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(0), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000002)
                EVT_KILL_THREAD(ArrayVar(11))
                EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(1), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(1), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(1), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(1), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000004)
                EVT_KILL_THREAD(ArrayVar(12))
                EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(2), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(2), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(2), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(2), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000008)
                EVT_KILL_THREAD(ArrayVar(13))
                EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(3), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(3), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(3), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(3), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_KILL_THREAD(ArrayVar(14))
                EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(4), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(4), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(4), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(4), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000020)
                EVT_KILL_THREAD(ArrayVar(15))
                EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(5), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(5), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(5), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(5), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_KILL_THREAD(ArrayVar(16))
                EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(6), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(6), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(6), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(6), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000080)
                EVT_KILL_THREAD(ArrayVar(17))
                EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(7), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(7), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(7), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(7), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000100)
                EVT_KILL_THREAD(ArrayVar(18))
                EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(8), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(8), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(8), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(8), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000200)
                EVT_KILL_THREAD(ArrayVar(19))
                EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(9), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(9), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(9), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(9), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_WAIT(15)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_SET(LVarA, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(4), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(4))
                    EVT_CALL(FlyToGoal, ArrayVar(4), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(4), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(4), 0)
                    EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000200)
                EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(9), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(9))
                    EVT_CALL(FlyToGoal, ArrayVar(9), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(9), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(9), 0)
                    EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000008)
                EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(3), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(3))
                    EVT_CALL(FlyToGoal, ArrayVar(3), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(3), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(3), 0)
                    EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000020)
                EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(5), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(5))
                    EVT_CALL(FlyToGoal, ArrayVar(5), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(5), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(5), 0)
                    EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000002)
                EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(1), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(1))
                    EVT_CALL(FlyToGoal, ArrayVar(1), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(1), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(1), 0)
                    EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000001)
                EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(0), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(0))
                    EVT_CALL(FlyToGoal, ArrayVar(0), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(0), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(0), 0)
                    EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000100)
                EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(8), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(8))
                    EVT_CALL(FlyToGoal, ArrayVar(8), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(8), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(8), 0)
                    EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000004)
                EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(2), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(2))
                    EVT_CALL(FlyToGoal, ArrayVar(2), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(2), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(2), 0)
                    EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000080)
                EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(7), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(7))
                    EVT_CALL(FlyToGoal, ArrayVar(7), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(7), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(7), 0)
                    EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(6), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(6))
                    EVT_CALL(FlyToGoal, ArrayVar(6), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(6), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(6), 0)
                    EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
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
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_FLAG(LVar0, N(FLAG_4))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_4))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_WAIT(2)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_40)
                EVT_ADD(LVar3, 1)
            EVT_END_IF
            EVT_IF_GT(LVar3, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_03, 180)
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
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
            EVT_IF_FLAG(LVar0, N(FLAG_4))
                EVT_CALL(GetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_BITWISE_AND_CONST(LVar0, ~N(FLAG_4))
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, N(VAR_FLAGS), LVar0)
                EVT_WAIT(2)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_40)
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
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
            EVT_IF_FLAG(LVar0, 0x00000001)
                EVT_KILL_THREAD(ArrayVar(10))
                EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(0), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(0), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(0), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(0), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000002)
                EVT_KILL_THREAD(ArrayVar(11))
                EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(1), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(1), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(1), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(1), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000004)
                EVT_KILL_THREAD(ArrayVar(12))
                EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(2), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(2), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(2), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(2), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000008)
                EVT_KILL_THREAD(ArrayVar(13))
                EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(3), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(3), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(3), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(3), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_KILL_THREAD(ArrayVar(14))
                EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(4), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(4), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(4), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(4), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000020)
                EVT_KILL_THREAD(ArrayVar(15))
                EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(5), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(5), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(5), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(5), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_KILL_THREAD(ArrayVar(16))
                EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(6), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(6), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(6), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(6), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000080)
                EVT_KILL_THREAD(ArrayVar(17))
                EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(7), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(7), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(7), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(7), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000100)
                EVT_KILL_THREAD(ArrayVar(18))
                EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(8), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(8), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(8), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(8), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000200)
                EVT_KILL_THREAD(ArrayVar(19))
                EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim12)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim13)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorPos, ArrayVar(9), LVar3, LVar4, LVar5)
                    EVT_CALL(N(Atan2), LVar6, LVar0, LVar2, LVar3, LVar5)
                    EVT_DIVF(LVar6, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar6, EVT_FLOAT(90.0))
                    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(70.0), LVar6)
                    EVT_CALL(SetActorJumpGravity, ArrayVar(9), EVT_FLOAT(1.0))
                    EVT_CALL(SetGoalPos, ArrayVar(9), LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ArrayVar(9), 20, FALSE, FALSE, FALSE)
                EVT_END_THREAD
            EVT_END_IF
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
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TUFF_PUFF_BIT_ARRAY), LVar0)
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(4), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(4), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(4))
                    EVT_CALL(FlyToGoal, ArrayVar(4), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(4), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(4), 0)
                    EVT_CALL(GetActorVar, ArrayVar(4), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(4), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000200)
                EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(9), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(9), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(9))
                    EVT_CALL(FlyToGoal, ArrayVar(9), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(9), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(9), 0)
                    EVT_CALL(GetActorVar, ArrayVar(9), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(9), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000008)
                EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(3), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(3), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(3))
                    EVT_CALL(FlyToGoal, ArrayVar(3), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(3), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(3), 0)
                    EVT_CALL(GetActorVar, ArrayVar(3), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(3), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000020)
                EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(5), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(5), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(5))
                    EVT_CALL(FlyToGoal, ArrayVar(5), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(5), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(5), 0)
                    EVT_CALL(GetActorVar, ArrayVar(5), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(5), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000002)
                EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(1), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(1), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(1))
                    EVT_CALL(FlyToGoal, ArrayVar(1), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(1), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(1), 0)
                    EVT_CALL(GetActorVar, ArrayVar(1), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(1), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000001)
                EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(0), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(0), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(0))
                    EVT_CALL(FlyToGoal, ArrayVar(0), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(0), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(0), 0)
                    EVT_CALL(GetActorVar, ArrayVar(0), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(0), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000100)
                EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(8), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(8), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(8))
                    EVT_CALL(FlyToGoal, ArrayVar(8), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(8), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(8), 0)
                    EVT_CALL(GetActorVar, ArrayVar(8), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(8), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000004)
                EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(2), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(2), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(2))
                    EVT_CALL(FlyToGoal, ArrayVar(2), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(2), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(2), 0)
                    EVT_CALL(GetActorVar, ArrayVar(2), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(2), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000080)
                EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(7), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(7), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(7))
                    EVT_CALL(FlyToGoal, ArrayVar(7), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(7), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(7), 0)
                    EVT_CALL(GetActorVar, ArrayVar(7), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(7), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim06)
                EVT_ELSE
                    EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim07)
                EVT_END_IF
                EVT_THREAD
                    EVT_CALL(SetActorVar, ArrayVar(6), 2, 0)
                    EVT_MOD(LVarA, 2)
                    EVT_IF_EQ(LVarA, 0)
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D5)
                    EVT_ELSE
                        EVT_CALL(PlaySoundAtActor, ArrayVar(6), SOUND_3D6)
                    EVT_END_IF
                    EVT_CALL(SetGoalToHome, ArrayVar(6))
                    EVT_CALL(FlyToGoal, ArrayVar(6), 30, 10, EASING_SIN_OUT)
                    EVT_CALL(SetPartAlpha, ArrayVar(6), 1, 255)
                    EVT_CALL(SetActorYaw, ArrayVar(6), 0)
                    EVT_CALL(GetActorVar, ArrayVar(6), 0, LVar1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim02)
                    EVT_ELSE
                        EVT_CALL(SetAnimation, ArrayVar(6), 1, ANIM_RuffPuff_Anim03)
                    EVT_END_IF
                EVT_END_THREAD
                EVT_ADD(LVarA, 1)
                EVT_WAIT(4)
            EVT_END_IF
            EVT_WAIT(50)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

