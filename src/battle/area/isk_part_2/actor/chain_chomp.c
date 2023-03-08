#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/Tutankoopa.h"

#define NAMESPACE b_area_isk_part_2_chain_chomp

extern EvtScript N(init_80218EC4);
extern EvtScript N(takeTurn_8021A7C4);
extern EvtScript N(idle_80219108);
extern EvtScript N(handleEvent_802197C4);
extern EvtScript N(8021972C);
extern EvtScript N(8021A200);
extern EvtScript N(8021B41C);
extern EvtScript N(8021B50C);

s32 N(IdleAnimations_80218B40)[] = {
    STATUS_NORMAL,    ANIM_ChainChomp_Anim01,
    STATUS_STONE,     ANIM_ChainChomp_Anim00,
    STATUS_SLEEP,     ANIM_ChainChomp_Anim07,
    STATUS_POISON,    ANIM_ChainChomp_Anim01,
    STATUS_STOP,      ANIM_ChainChomp_Anim00,
    STATUS_STATIC,    ANIM_ChainChomp_Anim00,
    STATUS_PARALYZE,  ANIM_ChainChomp_Anim00,
    STATUS_DIZZY,     ANIM_ChainChomp_Anim08,
    STATUS_END,
};

s32 N(IdleAnimations_80218B84)[] = {
    STATUS_NORMAL,    ANIM_ChainChomp_Anim03,
    STATUS_POISON,    ANIM_ChainChomp_Anim03,
    STATUS_STOP,      ANIM_ChainChomp_Anim00,
    STATUS_STONE,     ANIM_ChainChomp_Anim00,
    STATUS_SLEEP,     ANIM_ChainChomp_Anim07,
    STATUS_STATIC,    ANIM_ChainChomp_Anim00,
    STATUS_PARALYZE,  ANIM_ChainChomp_Anim00,
    STATUS_DIZZY,     ANIM_ChainChomp_Anim08,
    STATUS_END,
};

s32 N(IdleAnimations_80218BC8)[] = {
    STATUS_NORMAL,    ANIM_ChainChomp_Anim04,
    STATUS_POISON,    ANIM_ChainChomp_Anim04,
    STATUS_STOP,      ANIM_ChainChomp_Anim00,
    STATUS_STONE,     ANIM_ChainChomp_Anim00,
    STATUS_SLEEP,     ANIM_ChainChomp_Anim07,
    STATUS_STATIC,    ANIM_ChainChomp_Anim00,
    STATUS_PARALYZE,  ANIM_ChainChomp_Anim00,
    STATUS_DIZZY,     ANIM_ChainChomp_Anim08,
    STATUS_END,
};

s32 N(IdleAnimations_80218C0C)[] = {
    STATUS_NORMAL,    ANIM_ChainChomp_Anim05,
    STATUS_POISON,    ANIM_ChainChomp_Anim05,
    STATUS_STOP,      ANIM_ChainChomp_Anim00,
    STATUS_STONE,     ANIM_ChainChomp_Anim00,
    STATUS_SLEEP,     ANIM_ChainChomp_Anim07,
    STATUS_STATIC,    ANIM_ChainChomp_Anim00,
    STATUS_PARALYZE,  ANIM_ChainChomp_Anim00,
    STATUS_DIZZY,     ANIM_ChainChomp_Anim08,
    STATUS_END,
};

s32 N(IdleAnimations_80218C50)[] = {
    STATUS_NORMAL,    ANIM_ChainChomp_Anim02,
    STATUS_END,
};

s32 N(DefenseTable_80218C5C)[] = {
    ELEMENT_NORMAL, 3,
    ELEMENT_SHOCK, 3,
    ELEMENT_FIRE, 99,
    ELEMENT_ICE, 99,
    ELEMENT_MAGIC, 99,
    ELEMENT_END,
};

s32 N(StatusTable_80218C88)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 75,
    STATUS_STOP, 75,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable_80218D34)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218B40),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -13, 40 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218B40),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -16 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218C50),
        .defenseTable = N(DefenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CHOMP,
    .level = 14,
    .maxHP = 4,
    .partCount = ARRAY_COUNT( N(PartsTable_80218D34)),
    .partsData = N(PartsTable_80218D34),
    .initScript = &N(init_80218EC4),
    .statusTable = N(StatusTable_80218C88),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 0,
    .size = { 56, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/ChompChainInit.inc.c"

#include "common/ChompChainUpdateHelperFunc.inc.c"

#include "common/ChompChainUpdateHelperFunc2.inc.c"

API_CALLABLE(b_area_isk_part_2_chain_chomp_ChompChainUpdate) {
    Bytecode* args = script->ptrReadPos;
    f32 sp18;
    Actor* actor;
    ActorPart* part;
    ChompChainAnimationState* animState;
    f32 dist;
    f32 angle;
    f32 ax, ay;
    s32 three;
    s32 something;
    s32 i;

    actor = get_actor(script->owner1.actorID);
    if (actor == NULL) {
        return ApiStatus_BLOCK;
    }

    something = evt_get_variable(script, *args++);

    three = 3;

    animState = actor->state.functionTempPtr[0];
    if (actor->debuff == STATUS_SHRINK) {
        ax = actor->currentPos.x + 6.0;
        ay = actor->currentPos.y + 2.5;
    } else {
        ax = actor->currentPos.x + 12.0;
        ay = actor->currentPos.y + 5.0;
    }

    for (i = 0; i < 8; i++, animState++) {
        if (actor->debuff == STATUS_SHRINK) {
            animState->scale.x = 3.5f;
            animState->scale.z = 3.5f;
            animState->scale.y = 3.5f;
        } else {
            animState->scale.x = 7.0f;
            animState->scale.z = 7.0f;
            animState->scale.y = 7.0f;
        }

        animState->unk_18 -= animState->unk_14;
        if (animState->unk_18 < 2.0f * -animState->unk_14) {
            animState->unk_18 = 2.0f * -animState->unk_14;
            if (actor->state.varTable[8] != 0 && i == 0) {
                sfx_play_sound_at_position(SOUND_2063, SOUND_SPACE_MODE_0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);
            }
        }
        animState->currentPos.y += animState->unk_18;
        if (actor->debuff == STATUS_SHRINK) {
            if (animState->currentPos.y < 2.5) {
                animState->currentPos.y = 2.5f;
                animState->unk_18 = 0.0f;
            }
        } else {
            if (animState->currentPos.y < 5.0) {
                animState->currentPos.y = 5.0f;
                animState->unk_18 = 0.0f;
            }
        }

        dist = dist2D(ax, ay, animState->currentPos.x, animState->currentPos.y);
        angle = atan2(ax, ay, animState->currentPos.x, animState->currentPos.y);

        if (animState->scale.z <= dist) {
            b_area_isk_part_2_chain_chomp_ChompChainUpdateHelperFunc2(&sp18, dist - animState->scale.z, angle);
            animState->unk_18 += sp18 * 0.5;
        }

        if (animState->scale.y <= dist) {
            f32 t;

            if (animState->scale.x <= dist) {
                t = dist;
                t = t - animState->scale.x;
            } else {
                animState->unk_1C += animState->unk_20;
                t = animState->unk_1C;
            }
            b_area_isk_part_2_chain_chomp_ChompChainUpdateHelperFunc(animState, t, angle);
        } else {
            animState->unk_1C -= animState->unk_20 * 0.2;
            if (animState->unk_1C < 0.0) {
                animState->unk_1C = 0.0f;
            }
            b_area_isk_part_2_chain_chomp_ChompChainUpdateHelperFunc(animState, animState->unk_1C, angle);
        }

        if (animState->unk_1C > 4.0) {
            animState->unk_1C = 4.0f;
        }
        animState->currentPos.z = something;
        part = get_actor_part(actor, three + i);
        part->absolutePosition.x = animState->currentPos.x;
        part->absolutePosition.y = animState->currentPos.y;
        part->absolutePosition.z = animState->currentPos.z;

        if (actor->debuff == STATUS_SHRINK) {
            part->scale.x = 0.5f;
            part->scale.y = 0.5f;
            part->scale.z = 1.0f;
        } else {
            part->scale.x = 1.0f;
            part->scale.y = 1.0f;
            part->scale.z = 1.0f;
        }
        ay = animState->currentPos.y;
        ax = animState->currentPos.x;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_8021866C_4EFB0C) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(init_80218EC4) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021A7C4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80219108)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_802197C4)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, 3)
    EVT_LOOP(8)
        EVT_CALL(SetPartSize, ACTOR_SELF, LVar0, 16, 16)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(N(ChompChainInit))
    EVT_EXEC(N(8021972C))
    EVT_RETURN
    EVT_END
};

EvtScript N(80218FCC) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 0, 24)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, 0, 0)
    EVT_ELSE
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -13, 40)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, 0, -14)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80219108) = {
    EVT_LABEL(0)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80218C0C)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 11, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
    EVT_CALL(RandInt, 10, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80218BC8)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 15, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80218C0C)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 12, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 9, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80218B84)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
    EVT_CALL(RandInt, 10, LVar0)
    EVT_ADD(LVar0, 10)
    EVT_WAIT(LVar0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021972C) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(N(ChompChainUpdate), LVar2)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802197C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(N(8021A200))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim05)
            EVT_EXEC_WAIT(N(8021B41C))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
            EVT_END_THREAD
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_SUB(LVar1, 10)
                    EVT_ADD(LVar2, 4)
                EVT_ELSE
                    EVT_SUB(LVar1, 5)
                    EVT_ADD(LVar2, 11)
                EVT_END_IF
                EVT_CALL(SetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoAirLift)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim01)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(N(8021A200))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim06)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_IF_NE(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(FallToGoal, ACTOR_SELF, 11)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A200) = {
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 8, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim06)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_ENEMY0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 20, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 150, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(15)
    EVT_GOTO(10)
    EVT_LABEL(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim06)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 135, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 105, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(15)
    EVT_LABEL(10)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim01)
    EVT_EXEC_WAIT(N(8021B41C))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021A7C4) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_ADD(LVar0, 45)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim05)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_10F)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(PlaySound, SOUND_10F)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim01)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 25)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim04)
            EVT_WAIT(20)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim01)
            EVT_EXEC_WAIT(N(8021B41C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim01)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim01)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 4)
    EVT_ELSE
        EVT_ADD(LVar0, 10)
    EVT_END_IF
    EVT_SET(LVar1, 27)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim04)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LVar0, 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim01)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Anim01)
            EVT_EXEC_WAIT(N(8021B41C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim01)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B41C) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ChainChomp_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_EXEC_WAIT(N(8021B50C))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B50C) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_IF_LT(LVar3, LVar0)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_ELSE
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_IF_EQ(LVar3, LVar0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_LT(LVar3, LVar0)
        EVT_SET(LVar4, LVar0)
        EVT_SUB(LVar4, LVar3)
        EVT_IF_LT(LVar4, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_ELSE
            EVT_SET(LVar4, LVar3)
            EVT_ADD(LVar3, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar4, LVar3)
        EVT_SUB(LVar4, LVar0)
        EVT_IF_LT(LVar4, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_ELSE
            EVT_SUB(LVar3, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};
