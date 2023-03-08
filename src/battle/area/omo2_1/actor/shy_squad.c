#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/ShySquadGuy.h"

#define NAMESPACE b_area_omo2_1_shy_squad

enum N(ActorVars) {
    N(ACTOR_VAR_SQUAD_APPEARED) = 0,
    N(ACTOR_VAR_TIMES_ATTACKED) = 1,
    N(ACTOR_VAR_WAS_ATTACKED) = 2,
    N(ACTOR_VARS_GUYS_KILLED) = 3,
    N(ACTOR_VAR_TOTAL_DAMAGE) = 4,
};

API_CALLABLE(N(GetActorPartSize)) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actorPart = get_actor_part(get_actor(actorID), partID);
    evt_set_variable(script, *args++, actorPart->size.y);
    evt_set_variable(script, *args++, actorPart->size.x);

    return ApiStatus_DONE2;
}

extern s32 N(IdleAnimations)[];
extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

extern EvtScript N(move_squad_to_home);
extern EvtScript N(displace_guy);
extern EvtScript N(displace_guy_2);
extern EvtScript N(onHit);
extern EvtScript N(set_alive_guys_animation);
extern EvtScript N(onDeath);
extern EvtScript N(flee);
extern EvtScript N(next_phase);
extern EvtScript N(updateActorSize);

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
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
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 11,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 12,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 13,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 14,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 15,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 16,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW,
    .type = ACTOR_TYPE_SHY_SQUAD,
    .level = 0,
    .maxHP = 15,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 28, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_ShySquadGuy_Anim01,
    STATUS_STONE, ANIM_ShySquadGuy_Anim00,
    STATUS_SLEEP, ANIM_ShySquadGuy_Anim12,
    STATUS_POISON, ANIM_ShySquadGuy_Anim01,
    STATUS_STOP, ANIM_ShySquadGuy_Anim00,
    STATUS_STATIC, ANIM_ShySquadGuy_Anim00,
    STATUS_PARALYZE, ANIM_ShySquadGuy_Anim00,
    STATUS_PARALYZE, ANIM_ShySquadGuy_Anim00,
    STATUS_DIZZY, ANIM_ShySquadGuy_Anim13,
    STATUS_DIZZY, ANIM_ShySquadGuy_Anim13,
    STATUS_FEAR, ANIM_ShySquadGuy_Anim00,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_SQUAD_APPEARED), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TIMES_ATTACKED), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 0, 50)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 1, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 0, 50)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 1, -40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 0, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 1, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 0, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 1, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 0, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 1, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 0, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 0, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 1, -40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 0, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 1, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 10, 0, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 10, 1, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 11, 0, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 11, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 12, 0, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 12, 1, -40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 13, 0, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 13, 1, -40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 14, 0, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 14, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 15, 0, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 15, 1, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 16, 0, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 16, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 2, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 3, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 2, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 3, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 2, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 3, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 2, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 3, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 2, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 3, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 2, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 3, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 2, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 3, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 2, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 3, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 10, 2, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 10, 3, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 11, 2, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 11, 3, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 12, 2, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 12, 3, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 13, 2, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 13, 3, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 14, 2, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 14, 3, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 15, 2, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 15, 3, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 16, 2, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 16, 3, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 4, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 5, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 4, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 5, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 4, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 5, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 4, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 5, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 4, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 5, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 4, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 5, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 4, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 5, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 4, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 5, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 10, 4, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 10, 5, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 11, 4, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 11, 5, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 12, 4, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 12, 5, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 13, 4, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 13, 5, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 14, 4, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 14, 5, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 15, 4, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 15, 5, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 16, 4, -20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 16, 5, 20)
    EVT_CALL(RandInt, 100, LVar0)
    EVT_ADD(LVar0, 190)
    EVT_CALL(RandInt, 100, LVar2)
    EVT_ADD(LVar2, -50)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_SET(LVar1, 2)
    EVT_LOOP(15)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_ADD(LVar0, 190)
        EVT_CALL(RandInt, 100, LVar2)
        EVT_ADD(LVar2, -50)
        EVT_CALL(SetPartPos, ACTOR_SELF, LVar1, LVar0, 0, LVar2)
        EVT_ADD(LVar1, 1)
    EVT_END_LOOP
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(CreatePartShadow, ACTOR_SELF, LVar0)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 72)
    EVT_CALL(SetPartSize, ACTOR_SELF, 1, 24, 24)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_SQUAD_APPEARED), LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_SQUAD_APPEARED), 1)
                EVT_SET(LVar0, 2)
                EVT_LOOP(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim03)
                    EVT_ADD(LVar0, 1)
                EVT_END_LOOP
                EVT_CALL(SetHomePos, ACTOR_SELF, 65, 0, -10)
                EVT_CALL(HPBarToHome, ACTOR_SELF)
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
                EVT_SET(LVar1, ANIM_ShySquadGuy_Anim03)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_GUY_SCREAMS1)
                EVT_EXEC_WAIT(N(move_squad_to_home))
                EVT_WAIT(10)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 360)
                EVT_CALL(SetBattleCamTarget, 72, 45, 0)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(30)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(ActorSpeak, MSG_CH4_0065, ACTOR_SELF, 9, ANIM_ShySquadGuy_Anim11, ANIM_ShySquadGuy_Anim11)
                EVT_SET(LVar0, 2)
                EVT_LOOP(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0A)
                    EVT_ADD(LVar0, 1)
                EVT_END_LOOP
                EVT_CALL(EndActorSpeech, ACTOR_SELF, 1, -1, -1)
                EVT_CALL(func_802535B4, 1)
                EVT_SET(LVar0, 2)
                EVT_LOOP(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim01)
                    EVT_ADD(LVar0, 1)
                EVT_END_LOOP
            EVT_END_IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 0)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TIMES_ATTACKED), LVar0)
                EVT_ADD(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TIMES_ATTACKED), LVar0)
                EVT_IF_GE(LVar0, 2)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, 0x1) // set 'squadFleed' flag
                    EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LVar0)
                    EVT_EXEC_WAIT(N(flee))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(move_guy_to_pos) = {
    EVT_SET(LVarA, 2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVarB)
    EVT_ADD(LVarA, LVarB)
    EVT_IF_LT(LVar0, LVarA)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar0, LVar6, 0, LVar7)
    EVT_IF_LT(LVar6, LVar2)
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar0, 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar0, 0)
    EVT_END_IF
    EVT_CALL(GetDist2D, LVar9, LVar6, LVar7, LVar2, LVar3)
    EVT_IF_GE(LVar9, LVar4)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar0, LVar4)
        EVT_CALL(RunPartTo, ACTOR_SELF, LVar0, LVar2, 0, LVar3, LVar5)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(move_squad_to_home) = {
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_THREAD
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar2, LVar4, LVar3)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 0, LVar4)
            EVT_ADD(LVar2, LVar4)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 1, LVar4)
            EVT_ADD(LVar3, LVar4)
            EVT_SET(LVar4, EVT_FLOAT(6.0))
            EVT_SET(LVar5, 0)
            EVT_EXEC_WAIT(N(move_guy_to_pos))
            EVT_SET(LVarA, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVarB)
            EVT_ADD(LVarA, LVarB)
            EVT_IF_GE(LVar0, LVarA)
                EVT_CALL(SetPartYaw, ACTOR_SELF, LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim01)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(displace_last_guy) = {
    EVT_SET_CONST(LVar0, 16)
    EVT_EXEC_WAIT(N(displace_guy))
    EVT_RETURN
    EVT_END
};

EvtScript N(displace_guy) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVar2, LVar0)
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 5, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 20, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(2)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 25, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 17, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(3)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 24, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 19, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 5, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 2, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(4)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 16, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 32, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 16, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 21, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 16, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            EVT_WAIT(10)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onShock) = {
    EVT_SET_CONST(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVarD)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LVarE)
        EVT_ADD(LVarD, 2)
        EVT_ADD(LVarD, LVarE)
        EVT_IF_GE(LVar0, LVarD)
            EVT_THREAD
                EVT_EXEC_WAIT(N(displace_guy_2))
            EVT_END_THREAD
        EVT_END_IF
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_WAIT(33)
    EVT_RETURN
    EVT_END
};

EvtScript N(displace_guy_2) = {
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 4, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 16, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 8, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 20, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 8, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 12, 0)
    EVT_WAIT(1)
    EVT_LOOP(2)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 6, 0)
        EVT_WAIT(1)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(6)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 2, 0)
        EVT_WAIT(1)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVarF)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(displace_last_guy))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(displace_last_guy))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0E)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET(LVar0, 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0E)
                EVT_ADD(LVar0, 1)
            EVT_END_LOOP
            EVT_WAIT(20)
            EVT_SET(LVar0, 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0F)
                EVT_ADD(LVar0, 1)
            EVT_END_LOOP
            EVT_WAIT(15)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0E)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET(LVar0, 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0E)
                EVT_ADD(LVar0, 1)
            EVT_END_LOOP
            EVT_WAIT(20)
            EVT_SET(LVar0, 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0F)
                EVT_ADD(LVar0, 1)
            EVT_END_LOOP
            EVT_WAIT(15)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0F)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(displace_last_guy))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(displace_last_guy))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onShock))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_SET(LVar1, ANIM_ShySquadGuy_Anim03)
            EVT_EXEC_WAIT(N(move_squad_to_home))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onShock))
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetBattleFlags, LVar2)
            EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
                EVT_IF_EQ(LVar2, MOVE_SPOOK)
                    EVT_SET(LVar1, ANIM_ShySquadGuy_Anim01)
                    EVT_EXEC_WAIT(N(set_alive_guys_animation))
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim01)
            EVT_EXEC_WAIT(N(displace_last_guy))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET(LVar1, ANIM_ShySquadGuy_Anim08)
            EVT_EXEC_WAIT(N(set_alive_guys_animation))
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_SET(LVar1, ANIM_ShySquadGuy_Anim03)
            EVT_EXEC_WAIT(N(move_squad_to_home))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShySquadGuy_Anim0D)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_SET(LVar1, ANIM_ShySquadGuy_Anim01)
    EVT_EXEC_WAIT(N(set_alive_guys_animation))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_SET(LVar1, LVar1)
    EVT_EXEC_WAIT(N(set_alive_guys_animation))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LVar0)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar1)
    EVT_ADD(LVar0, LVar1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LVar0)
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(N(updateActorSize))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar1)
    EVT_IF_GE(LVar1, 15)
        EVT_EXEC_WAIT(N(updateActorSize))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, 2)
    EVT_ADD(LVar0, LVar1)
    EVT_IF_NE(LVar0, 16)
        EVT_THREAD
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_20000000, TRUE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 2, LVar7)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 3, LVar8)
            EVT_ADD(LVar1, LVar7)
            EVT_ADD(LVar3, LVar8)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar0, EVT_FLOAT(0.5))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, 0, LVar3, 15, TRUE)
            EVT_CALL(func_80269E80, LVar5)
            EVT_SWITCH(LVar5)
                EVT_CASE_OR_EQ(10)
                EVT_CASE_OR_EQ(14)
                EVT_CASE_OR_EQ(12)
                EVT_CASE_OR_EQ(16)
                EVT_CASE_OR_EQ(11)
                EVT_CASE_OR_EQ(15)
                EVT_CASE_OR_EQ(13)
                EVT_CASE_OR_EQ(17)
                EVT_CASE_OR_EQ(2)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SET(LVar7, 0)
                    EVT_LOOP(24)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, LVar0, 0, LVar7, 0)
                        EVT_ADD(LVar7, 30)
                        EVT_WAIT(1)
                    EVT_END_LOOP
            EVT_END_SWITCH
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
            EVT_SET(LVar8, 0)
            EVT_LOOP(12)
                EVT_CALL(SetPartRotation, ACTOR_SELF, LVar0, LVar8, 0, 0)
                EVT_ADD(LVar8, 8)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(RemovePartShadow, ACTOR_SELF, LVar0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LVar0)
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(set_alive_guys_animation) = {
    EVT_SET(LVar2, 2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar0)
    EVT_LOOP(15)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar2, LVar1)
        EVT_ELSE
            EVT_SUB(LVar0, 1)
        EVT_END_IF
        EVT_ADD(LVar2, 1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(kill_guy) = {
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(func_80269E80, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(12)
        EVT_CASE_OR_EQ(16)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(15)
        EVT_CASE_OR_EQ(13)
        EVT_CASE_OR_EQ(17)
        EVT_CASE_OR_EQ(2)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar2, 0)
            EVT_LOOP(24)
                EVT_CALL(SetPartRotation, ACTOR_SELF, LVar0, 0, LVar2, 0)
                EVT_ADD(LVar2, 30)
                EVT_WAIT(1)
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, LVar0, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(RemovePartShadow, ACTOR_SELF, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_SET_CONST(LVar0, 2)
    EVT_LOOP(14)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LVar3)
        EVT_ADD(LVar2, 2)
        EVT_ADD(LVar2, LVar3)
        EVT_IF_GE(LVar0, LVar2)
            EVT_THREAD
                EVT_EXEC_WAIT(N(kill_guy))
            EVT_END_THREAD
        EVT_END_IF
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_SET(LVar0, 16)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVar2, 0)
    EVT_LOOP(24)
        EVT_CALL(SetPartRotation, ACTOR_SELF, LVar0, 0, LVar2, 0)
        EVT_ADD(LVar2, 30)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, LVar0, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(RemovePartShadow, ACTOR_SELF, LVar0)
    EVT_EXEC_WAIT(N(next_phase))
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(attack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 34)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_SET(LVar0, 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar1)
    EVT_SUB(LVar0, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
        EVT_CASE_LT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EB)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EC)
    EVT_END_SWITCH
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, ANIM_ShySquadGuy_Anim03)
    EVT_LOOP(15)
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar2, LVar5, LVar3)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 4, LVar5)
            EVT_ADD(LVar2, LVar5)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 5, LVar5)
            EVT_ADD(LVar3, LVar5)
            EVT_SETF(LVar4, EVT_FLOAT(6.0))
            EVT_SET(LVar5, 30)
            EVT_EXEC_WAIT(N(move_guy_to_pos))
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar2, LVar5, LVar3)
    EVT_CALL(GetPartMovementVar, ACTOR_SELF, 16, 4, LVar5)
    EVT_ADD(LVar2, LVar5)
    EVT_CALL(GetPartMovementVar, ACTOR_SELF, 16, 5, LVar5)
    EVT_ADD(LVar3, LVar5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, 0, LVar3)
    EVT_CALL(RunToGoal, ACTOR_SELF, 30, TRUE)
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
        EVT_CALL(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
        EVT_IF_LT(LVar1, LVar4)
            EVT_CALL(SetPartYaw, ACTOR_SELF, LVar0, 180)
        EVT_ELSE
            EVT_CALL(SetPartYaw, ACTOR_SELF, LVar0, 0)
        EVT_END_IF
        EVT_CALL(RandInt, 100, LVar7)
        EVT_IF_LT(LVar7, 50)
            EVT_SET(LVar7, ANIM_ShySquadGuy_Anim0D)
        EVT_ELSE
            EVT_SET(LVar7, ANIM_ShySquadGuy_Anim11)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar7)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar0)
            EVT_IF_LT(LVar0, 14)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0, 0)
                EVT_THREAD
                    EVT_LOOP(7)
                        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 0, LVar0, LVar1, LVar2, 0, 0)
                        EVT_WAIT(2)
                        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0, 0)
                        EVT_WAIT(2)
                    EVT_END_LOOP
                EVT_END_THREAD
            EVT_END_IF
            EVT_WAIT(36)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_SET(LVar0, 15)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar1)
            EVT_SUB(LVar0, LVar1)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
                EVT_CASE_LT(5)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EB)
                EVT_CASE_DEFAULT
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EC)
            EVT_END_SWITCH
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_SET(LVar1, ANIM_ShySquadGuy_Anim04)
            EVT_EXEC_WAIT(N(move_squad_to_home))
            EVT_SET(LVar1, ANIM_ShySquadGuy_Anim01)
            EVT_EXEC_WAIT(N(set_alive_guys_animation))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SET(LVarE, 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar0)
    EVT_SUB(LVarE, LVar0)
    EVT_SET(LVarD, LVarE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3AD)
    EVT_LOOP(LVarD)
        EVT_IF_GT(LVarE, 1)
            EVT_SET(LVar0, BS_FLAGS1_40)
        EVT_ELSE
            EVT_SET(LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_END_IF
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 1, LVar0)
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 0, LVar1, LVar2, LVar3, 0, 0)
            EVT_WAIT(2)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, LVar2, LVar3, 0, 0)
            EVT_WAIT(2)
        EVT_END_THREAD
        EVT_CALL(GetPlayerHP, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_SUB(LVarE, 1)
        EVT_IF_EQ(LVarE, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_3AD)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(20)
    EVT_SET(LVar0, 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar1)
    EVT_SUB(LVar0, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
        EVT_CASE_LT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EB)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EC)
    EVT_END_SWITCH
    EVT_SET(LVar1, ANIM_ShySquadGuy_Anim04)
    EVT_EXEC_WAIT(N(move_squad_to_home))
    EVT_SET(LVar1, ANIM_ShySquadGuy_Anim01)
    EVT_EXEC_WAIT(N(set_alive_guys_animation))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_EXEC_WAIT(N(attack))
    EVT_RETURN
    EVT_END
};

EvtScript N(flee) = {
    EVT_CALL(func_802535B4, 0)
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim08)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(ActorSpeak, MSG_CH4_0066, ACTOR_SELF, 1, -1, -1)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, ANIM_ShySquadGuy_Anim08)
    EVT_LOOP(14)
        EVT_THREAD
            EVT_CALL(RandInt, 100, LVar2)
            EVT_ADD(LVar2, 190)
            EVT_CALL(RandInt, 100, LVar3)
            EVT_ADD(LVar3, -50)
            EVT_SETF(LVar4, EVT_FLOAT(6.0))
            EVT_SET(LVar5, 0)
            EVT_EXEC_WAIT(N(move_guy_to_pos))
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_SET(LVar0, 16)
        EVT_SET(LVar1, ANIM_ShySquadGuy_Anim08)
        EVT_SET(LVar2, 240)
        EVT_SET(LVar3, 0)
        EVT_SETF(LVar4, EVT_FLOAT(6.0))
        EVT_SET(LVar5, 0)
        EVT_EXEC_WAIT(N(move_guy_to_pos))
    EVT_END_THREAD
    EVT_SET(LVar0, 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar1)
    EVT_SUB(LVar0, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
        EVT_CASE_LT(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_GUY_SCREAMS3)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_GUY_SCREAMS2)
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 240, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, TRUE)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_1E2)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(2.5))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar0)
    EVT_IF_LT(LVar0, 14)
        EVT_CALL(ActorSpeak, MSG_CH4_0067, ACTOR_ENEMY0, 1, -1, -1)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MSG_CH4_0068, ACTOR_ENEMY0, 1, -1, -1)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_1E2)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(2.0))
        EVT_WAIT(12)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_1E2)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
    EVT_WAIT(40)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_173)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_174)
    EVT_END_THREAD
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, ANIM_ShySquadGuy_Anim08)
    EVT_LOOP(14)
        EVT_THREAD
            EVT_CALL(RandInt, 100, LVar2)
            EVT_ADD(LVar2, -290)
            EVT_CALL(RandInt, 100, LVar3)
            EVT_ADD(LVar3, -50)
            EVT_SETF(LVar4, EVT_FLOAT(10.0))
            EVT_EXEC_WAIT(N(move_guy_to_pos))
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 30)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
        EVT_LABEL(1)
        EVT_WAIT(1)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
        EVT_ADD(LVar3, 10)
        EVT_IF_GT(LVar0, LVar3)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
        EVT_SET(LVar7, 0)
        EVT_LOOP(40)
            EVT_ADD(LVar7, 36)
            EVT_IF_GE(LVar7, 360)
                EVT_SUB(LVar7, 360)
            EVT_END_IF
            EVT_CALL(SetActorRotation, ACTOR_PLAYER, 0, LVar7, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(SetActorRotation, ACTOR_PLAYER, 0, 0, 0)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 16)
        EVT_SET(LVar1, ANIM_ShySquadGuy_Anim08)
        EVT_SET(LVar2, -240)
        EVT_SET(LVar3, 0)
        EVT_SETF(LVar4, EVT_FLOAT(10.0))
        EVT_SET(LVar5, 0)
        EVT_EXEC_WAIT(N(move_guy_to_pos))
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, -240, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, TRUE)
    EVT_EXEC_WAIT(N(next_phase))
    EVT_WAIT(10)
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(next_phase) = {
    EVT_CALL(func_8026BF48, 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(updateActorSize) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LE(1)
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 72)
        EVT_CASE_LE(2)
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 48)
        EVT_CASE_LE(8)
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 24)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, EVT_IGNORE_ARG)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
