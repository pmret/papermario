#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Blooper.h"

#define NAMESPACE b_area_tik2_super_blooper

extern ActorBlueprint b_area_tik2_blooper_baby;

EvtScript N(FloatToPos) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_IF_GT(LVarB, 20)
        EVT_SUB(LVarB, 20)
    EVT_ELSE
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DC)
    EVT_SET(LVar7, LVar4)
    EVT_ADD(LVar7, LVar4)
    EVT_ADD(LVar7, LVar0)
    EVT_MULF(LVar7, EVT_FLOAT(0.33))
    EVT_SET(LVar8, LVar5)
    EVT_ADD(LVar8, LVar5)
    EVT_ADD(LVar8, LVar1)
    EVT_MULF(LVar8, EVT_FLOAT(0.33))
    EVT_SET(LVar9, LVar6)
    EVT_ADD(LVar9, LVar6)
    EVT_ADD(LVar9, LVar2)
    EVT_MULF(LVar9, EVT_FLOAT(0.33))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    EVT_CALL(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DC)
    EVT_SET(LVar7, LVar0)
    EVT_ADD(LVar7, LVar0)
    EVT_ADD(LVar7, LVar4)
    EVT_MULF(LVar7, EVT_FLOAT(0.33))
    EVT_SET(LVar8, LVar1)
    EVT_ADD(LVar8, LVar1)
    EVT_ADD(LVar8, LVar5)
    EVT_MULF(LVar8, EVT_FLOAT(0.33))
    EVT_SET(LVar9, LVar2)
    EVT_ADD(LVar9, LVar2)
    EVT_ADD(LVar9, LVar6)
    EVT_MULF(LVar9, EVT_FLOAT(0.33))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    EVT_CALL(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DC)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    EVT_RETURN
    EVT_END
};

EvtScript N(FloatToHome) = {
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, 12)
    EVT_EXEC_WAIT(N(FloatToPos))
    EVT_RETURN
    EVT_END
};

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(onDeath);
extern EvtScript N(makeBabies);
extern EvtScript N(getEnraged);
extern EvtScript N(attackEnragedDrops);
extern EvtScript N(attackSpinDrop);
extern EvtScript N(attackInkBlast);
extern EvtScript N(enrage);
extern EvtScript N(unEnrage);

extern Formation N(formation_baby_1);
extern Formation N(formation_baby_2);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_Blooper_Anim00,
    STATUS_STOP, ANIM_Blooper_Anim00,
    STATUS_SLEEP, ANIM_Blooper_Anim07,
    STATUS_PARALYZE, ANIM_Blooper_Anim08,
    STATUS_PARALYZE, ANIM_Blooper_Anim00,
    STATUS_DIZZY, ANIM_Blooper_Anim08,
    STATUS_SHRINK, ANIM_Blooper_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations2)[] = {
    STATUS_NORMAL, ANIM_Blooper_Anim0C,
    STATUS_STOP, ANIM_Blooper_Anim00,
    STATUS_SLEEP, ANIM_Blooper_Anim07,
    STATUS_PARALYZE, ANIM_Blooper_Anim08,
    STATUS_PARALYZE, ANIM_Blooper_Anim00,
    STATUS_DIZZY, ANIM_Blooper_Anim08,
    STATUS_SHRINK, ANIM_Blooper_Anim0C,
    STATUS_END,
};

s32 N(IdleAnimations3)[] = {
    STATUS_NORMAL, ANIM_Blooper_Anim00,
    STATUS_STOP, ANIM_Blooper_Anim00,
    STATUS_SLEEP, ANIM_Blooper_Anim07,
    STATUS_PARALYZE, ANIM_Blooper_Anim08,
    STATUS_PARALYZE, ANIM_Blooper_Anim00,
    STATUS_DIZZY, ANIM_Blooper_Anim08,
    STATUS_SHRINK, ANIM_Blooper_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 40,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 60,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 70,
    STATUS_STOP, 60,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

s32 N(StatusTable_enraged)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 80 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 20, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -30 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_SUPER_BLOOPER1,
    .level = 65,
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
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { -111, -88 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { 0, 60 },
    .statusMessageOffset = { 40, 80 },
};

#include "common/StartRumbleWithParams.inc.c"

API_CALLABLE(N(unused_func)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;
    f32 var0, var1;

    var1 = evt_get_float_variable(script, *args++);
    do {} while (0);
    var0 = evt_get_float_variable(script, arg0);

    evt_set_float_variable(script, arg0, var1 * sin_rad(DEG_TO_RAD(var0)));

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"
#include "common/UnfadeBackgroundToBlack.inc.c"
#include "common/SpitInk.inc.c"

EvtScript N(init) = {
    EVT_CALL(ForceHomePos, ACTOR_SELF, 90, 45, -10)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(2.0), EVT_FLOAT(2.0), EVT_FLOAT(2.0))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GE(LVar4, LVar1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations2)))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_WAIT(9)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
    EVT_LABEL(11)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GE(LVar4, LVar1)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations2)))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_WAIT(9)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
    EVT_WAIT(3)
    EVT_LABEL(12)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations3)))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, -10)
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_Blooper_Anim05)
            EVT_SET(LVar2, ANIM_Blooper_Anim06)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_Blooper_Anim05)
            EVT_SET(LVar2, ANIM_Blooper_Anim06)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim06)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
        EVT_CASE_OR_EQ(EVENT_INVUNERABLE_TAUNT)
        EVT_CASE_OR_EQ(EVENT_1E)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim00)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_STAR_BEAM)
        EVT_CASE_OR_EQ(EVENT_PEACH_BEAM)
            EVT_EXEC_WAIT(N(unEnrage))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_EXEC_WAIT(N(unEnrage))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(FloatToHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(unEnrage))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(FloatToHome))
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim00)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(3)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
            EVT_ELSE
                EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
                EVT_IF_NE(LVar0, 0)
                    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
                    EVT_IF_NE(LVar0, 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
            EVT_EXEC_WAIT(N(makeBabies))
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3)
            EVT_EXEC_WAIT(N(getEnraged))
            EVT_RETURN
        EVT_CASE_EQ(3)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
            EVT_EXEC_WAIT(N(attackEnragedDrops))
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                EVT_CALL(RandInt, 100, LVar0)
                EVT_IF_LT(LVar0, 50)
                    EVT_EXEC_WAIT(N(attackSpinDrop))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(attackInkBlast))
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(attackSpinDrop))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(attackSpinDrop) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 100)
    EVT_SET(LVar3, 15)
    EVT_EXEC_WAIT(N(FloatToPos))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DD)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(36)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0D)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_EXEC_WAIT(N(FloatToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(16)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0D)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim04)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(N(FloatToHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackInkBlast) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 85)
    EVT_ADD(LVar1, 45)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_IF_GT(LVarB, 30)
        EVT_SUB(LVarB, 30)
    EVT_ELSE
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DC)
    EVT_SET(LVar7, LVar4)
    EVT_ADD(LVar7, LVar0)
    EVT_MULF(LVar7, EVT_FLOAT(0.5))
    EVT_SET(LVar8, LVar5)
    EVT_ADD(LVar8, LVar1)
    EVT_MULF(LVar8, EVT_FLOAT(0.5))
    EVT_SET(LVar9, LVar6)
    EVT_ADD(LVar9, LVar2)
    EVT_MULF(LVar9, EVT_FLOAT(0.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DC)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim03)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 30)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 16, 0, EASING_LINEAR)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 40, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -40)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, 1)
    EVT_SUB(LVar4, 30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(N(SpitInk), LVar0, LVar1, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_EXEC_WAIT(N(FloatToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(func_80269EAC, 26)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_EXEC_WAIT(N(FloatToHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeBabies) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 50)
    EVT_CALL(SetBattleCamZoom, 330)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(N(StartRumbleWithParams), 50, 20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 65)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim09)
    EVT_WAIT(15)
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(0.4))
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 80)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0A)
    EVT_WAIT(15)
    EVT_CALL(N(StartRumbleWithParams), 150, 20)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 95)
    EVT_CALL(SetBattleCamZoom, 60)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0B)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim03)
    EVT_WAIT(10)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D9)
        EVT_CALL(SummonEnemy, EVT_PTR(N(formation_baby_1)), 0)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D9)
        EVT_CALL(SummonEnemy, EVT_PTR(N(formation_baby_2)), 0)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0C)
    EVT_CALL(N(UnfadeBackgroundToBlack))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(getEnraged) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 28)
    EVT_CALL(SetBattleCamZoom, 297)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(N(StartRumbleWithParams), 70, 80)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 40, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim09)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0A)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0B)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(enrage))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(N(UnfadeBackgroundToBlack))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(attackEnragedDrops) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 100)
    EVT_SET(LVar3, 15)
    EVT_EXEC_WAIT(N(FloatToPos))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3DD)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(36)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0D)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_EXEC_WAIT(N(unEnrage))
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_EXEC_WAIT(N(FloatToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(16)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim0D)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVarE)
    EVT_IF_FLAG(LVarE, STATUS_FLAG_STONE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 10, BS_FLAGS1_40)
    EVT_CALL(GetPlayerHP, LVarE)
    EVT_IF_EQ(LVarE, 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.4))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_LABEL(0)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 10, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_LABEL(1)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim04)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Blooper_Anim00)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(N(unEnrage))
    EVT_EXEC_WAIT(N(FloatToHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(enrage) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_CALL(func_8026ED20, ACTOR_SELF, 1, 1)
    EVT_CALL(func_8026EBF8, ACTOR_SELF, 1, 0, 2, 0, 6, 12, 6, 0, 0)
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 15)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_enraged)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(unEnrage) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(func_8026ED20, ACTOR_SELF, 1, 0)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3i N(baby_pos) = { 400, 0, 0 };

Formation N(formation_baby_1) = {
    { .actor = &b_area_tik2_blooper_baby, .home = { .vec = &N(baby_pos) }, .priority = 95, .var0 = 30, .var1 = 68, },
};

Formation N(formation_baby_2) = {
    { .actor = &b_area_tik2_blooper_baby, .home = { .vec = &N(baby_pos) }, .priority = 94, .var0 = 134, .var1 = 45, },
};
