#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/shy_squad_guy.h"

#define NAMESPACE b_area_omo2_1_shy_squad

enum N(ActorVars) {
    N(ACTOR_VAR_SQUAD_APPEARED) = 0,
    N(ACTOR_VAR_TIMES_ATTACKED) = 1,
    N(ACTOR_VAR_WAS_ATTACKED) = 2,
    N(ACTOR_VARS_GUYS_KILLED) = 3,
    N(ACTOR_VAR_TOTAL_DAMAGE) = 4,
};

ApiStatus N(GetActorPartSize)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actorPart = get_actor_part(get_actor(actorID), partIndex);
    evt_set_variable(script, *args++, actorPart->size.y);
    evt_set_variable(script, *args++, actorPart->size.x);

    return ApiStatus_DONE2;
}

extern s32 N(idleAnimations)[];
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

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
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
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 11,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 12,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 13,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 14,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 15,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 16,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW,
    .type = ACTOR_TYPE_SHY_SQUAD,
    .level = 0,
    .maxHP = 15,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 28, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_squad_guy_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_shy_squad_guy_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_shy_squad_guy_Palette_00_Anim_12,
    STATUS_POISON, NPC_ANIM_shy_squad_guy_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_shy_squad_guy_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_shy_squad_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_shy_squad_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_shy_squad_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_shy_squad_guy_Palette_00_Anim_13,
    STATUS_DIZZY, NPC_ANIM_shy_squad_guy_Palette_00_Anim_13,
    STATUS_FEAR, NPC_ANIM_shy_squad_guy_Palette_00_Anim_0,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn)))
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
    EVT_CALL(RandInt, 100, LW(0))
    EVT_ADD(LW(0), 190)
    EVT_CALL(RandInt, 100, LW(2))
    EVT_ADD(LW(2), -50)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_SET(LW(1), 2)
    EVT_LOOP(15)
        EVT_CALL(RandInt, 100, LW(0))
        EVT_ADD(LW(0), 190)
        EVT_CALL(RandInt, 100, LW(2))
        EVT_ADD(LW(2), -50)
        EVT_CALL(SetPartPos, ACTOR_SELF, LW(1), LW(0), 0, LW(2))
        EVT_ADD(LW(1), 1)
    EVT_END_LOOP
    EVT_SET(LW(0), 2)
    EVT_LOOP(15)
        EVT_CALL(CreatePartShadow, ACTOR_SELF, LW(0))
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(SetActorSize, ACTOR_SELF, EVT_LIMIT, 72)
    EVT_CALL(SetPartSize, ACTOR_SELF, 1, 24, 24)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_SQUAD_APPEARED), LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_SQUAD_APPEARED), 1)
                EVT_SET(LW(0), 2)
                EVT_LOOP(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_3)
                    EVT_ADD(LW(0), 1)
                EVT_END_LOOP
                EVT_CALL(SetHomePos, ACTOR_SELF, 65, 0, -10)
                EVT_CALL(HPBarToHome, ACTOR_SELF)
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
                EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_3)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_GUY_SCREAMS1)
                EVT_EXEC_WAIT(N(move_squad_to_home))
                EVT_WAIT(10)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 360)
                EVT_CALL(SetBattleCamTarget, 72, 45, 0)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(30)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0065), ACTOR_SELF, 9, NPC_ANIM_shy_squad_guy_Palette_00_Anim_11, NPC_ANIM_shy_squad_guy_Palette_00_Anim_11)
                EVT_SET(LW(0), 2)
                EVT_LOOP(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_A)
                    EVT_ADD(LW(0), 1)
                EVT_END_LOOP
                EVT_CALL(EndActorSpeech, ACTOR_SELF, 1, -1, -1)
                EVT_CALL(func_802535B4, 1)
                EVT_SET(LW(0), 2)
                EVT_LOOP(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
                    EVT_ADD(LW(0), 1)
                EVT_END_LOOP
            EVT_END_IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 0)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TIMES_ATTACKED), LW(0))
                EVT_ADD(LW(0), 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TIMES_ATTACKED), LW(0))
                EVT_IF_GE(LW(0), 2)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LW(0))
                    EVT_BITWISE_OR_CONST(LW(0), 0x1) // set 'squadFleed' flag
                    EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LW(0))
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
    EVT_SET(LW(10), 2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(11))
    EVT_ADD(LW(10), LW(11))
    EVT_IF_LT(LW(0), LW(10))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPartOffset, ACTOR_SELF, LW(0), LW(6), 0, LW(7))
    EVT_IF_LT(LW(6), LW(2))
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(0), 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(0), 0)
    EVT_END_IF
    EVT_CALL(GetDist2D, LW(9), LW(6), LW(7), LW(2), LW(3))
    EVT_IF_GE(LW(9), LW(4))
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LW(0), LW(4))
        EVT_CALL(RunPartTo, ACTOR_SELF, LW(0), LW(2), 0, LW(3), LW(5))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(move_squad_to_home) = {
    EVT_SET(LW(0), 2)
    EVT_LOOP(15)
        EVT_THREAD
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(2), LW(4), LW(3))
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LW(0), 0, LW(4))
            EVT_ADD(LW(2), LW(4))
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LW(0), 1, LW(4))
            EVT_ADD(LW(3), LW(4))
            EVT_SET(LW(4), EVT_FLOAT(6.0))
            EVT_SET(LW(5), 0)
            EVT_EXEC_WAIT(N(move_guy_to_pos))
            EVT_SET(LW(10), 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(11))
            EVT_ADD(LW(10), LW(11))
            EVT_IF_GE(LW(0), LW(10))
                EVT_CALL(SetPartYaw, ACTOR_SELF, LW(0), 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
            EVT_END_IF
        EVT_END_THREAD
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(13), LW(14), LW(15))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(13), LW(14), LW(15))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(displace_last_guy) = {
    EVT_SET_CONST(LW(0), 16)
    EVT_EXEC_WAIT(N(displace_guy))
    EVT_RETURN
    EVT_END
};

EvtScript N(displace_guy) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_SET(LW(2), LW(0))
    EVT_CALL(GetDamageIntensity)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 5, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(4)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 1, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 20, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 14, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(2)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 1, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 22, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 25, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 12, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 17, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 10, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 4, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(3)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 8, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 24, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 14, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 19, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 14, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 5, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 2, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
            EVT_WAIT(10)
        EVT_CASE_EQ(4)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 10, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 28, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 16, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 32, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 16, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 21, 0)
            EVT_WAIT(1)
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 16, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(6)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 7, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(2)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 3, 0)
                EVT_WAIT(1)
                EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(2), 0, 0, 0)
            EVT_WAIT(10)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onShock) = {
    EVT_SET_CONST(LW(0), 2)
    EVT_LOOP(15)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(13))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LW(14))
        EVT_ADD(LW(13), 2)
        EVT_ADD(LW(13), LW(14))
        EVT_IF_GE(LW(0), LW(13))
            EVT_THREAD
                EVT_EXEC_WAIT(N(displace_guy_2))
            EVT_END_THREAD
        EVT_END_IF
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_WAIT(33)
    EVT_RETURN
    EVT_END
};

EvtScript N(displace_guy_2) = {
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 0, 0)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 4, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 16, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 8, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 20, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 8, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 12, 0)
    EVT_WAIT(1)
    EVT_LOOP(2)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 6, 0)
        EVT_WAIT(1)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(6)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 2, 0)
        EVT_WAIT(1)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, LW(0), 0, 0, 0)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(15))
    EVT_SWITCH(LW(15))
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(displace_last_guy))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(displace_last_guy))
            EVT_WAIT(10)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET(LW(0), 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_E)
                EVT_ADD(LW(0), 1)
            EVT_END_LOOP
            EVT_WAIT(20)
            EVT_SET(LW(0), 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_F)
                EVT_ADD(LW(0), 1)
            EVT_END_LOOP
            EVT_WAIT(15)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET(LW(0), 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_E)
                EVT_ADD(LW(0), 1)
            EVT_END_LOOP
            EVT_WAIT(20)
            EVT_SET(LW(0), 2)
            EVT_LOOP(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_F)
                EVT_ADD(LW(0), 1)
            EVT_END_LOOP
            EVT_WAIT(15)
            EVT_WAIT(10)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_F)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_WAS_ATTACKED), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(displace_last_guy))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(displace_last_guy))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onShock))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_3)
            EVT_EXEC_WAIT(N(move_squad_to_home))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onShock))
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetBattleFlags, LW(2))
            EVT_IF_FLAG(LW(2), BS_FLAGS1_80000)
                EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
                EVT_IF_EQ(LW(2), MOVE_SPOOK)
                    EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
                    EVT_EXEC_WAIT(N(set_alive_guys_animation))
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(N(displace_last_guy))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(set_alive_guys_animation))
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_3)
            EVT_EXEC_WAIT(N(move_squad_to_home))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
    EVT_EXEC_WAIT(N(set_alive_guys_animation))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_SET(LW(1), LW(1))
    EVT_EXEC_WAIT(N(set_alive_guys_animation))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LW(0))
    EVT_CALL(GetLastDamage, ACTOR_SELF, LW(1))
    EVT_ADD(LW(0), LW(1))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LW(0))
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_EXEC_WAIT(N(updateActorSize))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(1))
    EVT_IF_GE(LW(1), 15)
        EVT_EXEC_WAIT(N(updateActorSize))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LW(0), 2)
    EVT_ADD(LW(0), LW(1))
    EVT_IF_NE(LW(0), 16)
        EVT_THREAD
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(0), ACTOR_PART_FLAG_20000000, 1)
            EVT_CALL(GetPartOffset, ACTOR_SELF, LW(0), LW(1), LW(2), LW(3))
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LW(0), 2, LW(7))
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LW(0), 3, LW(8))
            EVT_ADD(LW(1), LW(7))
            EVT_ADD(LW(3), LW(8))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(0), EVT_FLOAT(0.5))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LW(0), LW(1), 0, LW(3), 15, 1)
            EVT_CALL(func_80269E80, LW(5))
            EVT_SWITCH(LW(5))
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
                    EVT_SET(LW(7), 0)
                    EVT_LOOP(24)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, LW(0), 0, LW(7), 0)
                        EVT_ADD(LW(7), 30)
                        EVT_WAIT(1)
                    EVT_END_LOOP
            EVT_END_SWITCH
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
            EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_SET(LW(8), 0)
            EVT_LOOP(12)
                EVT_CALL(SetPartRotation, ACTOR_SELF, LW(0), LW(8), 0, 0)
                EVT_ADD(LW(8), 8)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(0), ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(RemovePartShadow, ACTOR_SELF, LW(0))
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LW(0))
    EVT_SUB(LW(0), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LW(0))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(0))
    EVT_ADD(LW(0), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(set_alive_guys_animation) = {
    EVT_SET(LW(2), 2)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(0))
    EVT_LOOP(15)
        EVT_IF_EQ(LW(0), 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, LW(2), LW(1))
        EVT_ELSE
            EVT_SUB(LW(0), 1)
        EVT_END_IF
        EVT_ADD(LW(2), 1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(kill_guy) = {
    EVT_IF_NE(LW(1), -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(func_80269E80, LW(5))
    EVT_SWITCH(LW(5))
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
            EVT_SET(LW(2), 0)
            EVT_LOOP(24)
                EVT_CALL(SetPartRotation, ACTOR_SELF, LW(0), 0, LW(2), 0)
                EVT_ADD(LW(2), 30)
                EVT_WAIT(1)
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_SET(LW(3), 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, LW(0), LW(3), 0, 0)
        EVT_ADD(LW(3), 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(0), ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(RemovePartShadow, ACTOR_SELF, LW(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_SET_CONST(LW(0), 2)
    EVT_LOOP(14)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(2))
        EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VAR_TOTAL_DAMAGE), LW(3))
        EVT_ADD(LW(2), 2)
        EVT_ADD(LW(2), LW(3))
        EVT_IF_GE(LW(0), LW(2))
            EVT_THREAD
                EVT_EXEC_WAIT(N(kill_guy))
            EVT_END_THREAD
        EVT_END_IF
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_SET(LW(0), 16)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_SET(LW(2), 0)
    EVT_LOOP(24)
        EVT_CALL(SetPartRotation, ACTOR_SELF, LW(0), 0, LW(2), 0)
        EVT_ADD(LW(2), 30)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetPartOffset, ACTOR_SELF, LW(0), LW(1), LW(2), LW(3))
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_SET(LW(3), 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, LW(0), LW(3), 0, 0)
        EVT_ADD(LW(3), 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(0), ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(RemovePartShadow, ACTOR_SELF, LW(0))
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
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 20)
    EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 34)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_SET(LW(0), 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(1))
    EVT_SUB(LW(0), LW(1))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, SOUND_20BA, SOUND_3B4)
        EVT_CASE_LT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EB)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EC)
    EVT_END_SWITCH
    EVT_SET(LW(0), 2)
    EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_3)
    EVT_LOOP(15)
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(2), LW(5), LW(3))
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LW(0), 4, LW(5))
            EVT_ADD(LW(2), LW(5))
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LW(0), 5, LW(5))
            EVT_ADD(LW(3), LW(5))
            EVT_SETF(LW(4), EVT_FLOAT(6.0))
            EVT_SET(LW(5), 30)
            EVT_EXEC_WAIT(N(move_guy_to_pos))
        EVT_END_THREAD
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, LW(2), LW(5), LW(3))
    EVT_CALL(GetPartMovementVar, ACTOR_SELF, 16, 4, LW(5))
    EVT_ADD(LW(2), LW(5))
    EVT_CALL(GetPartMovementVar, ACTOR_SELF, 16, 5, LW(5))
    EVT_ADD(LW(3), LW(5))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(2), 0, LW(3))
    EVT_CALL(RunToGoal, ACTOR_SELF, 30, TRUE)
    EVT_SET(LW(0), 2)
    EVT_LOOP(15)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(4), LW(5), LW(6))
        EVT_CALL(GetPartOffset, ACTOR_SELF, LW(0), LW(1), LW(2), LW(3))
        EVT_IF_LT(LW(1), LW(4))
            EVT_CALL(SetPartYaw, ACTOR_SELF, LW(0), 180)
        EVT_ELSE
            EVT_CALL(SetPartYaw, ACTOR_SELF, LW(0), 0)
        EVT_END_IF
        EVT_CALL(RandInt, 100, LW(7))
        EVT_IF_LT(LW(7), 50)
            EVT_SET(LW(7), NPC_ANIM_shy_squad_guy_Palette_00_Anim_D)
        EVT_ELSE
            EVT_SET(LW(7), NPC_ANIM_shy_squad_guy_Palette_00_Anim_11)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(7))
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(0))
            EVT_IF_LT(LW(0), 14)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
                EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 3, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_THREAD
                    EVT_LOOP(7)
                        EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 0, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                        EVT_WAIT(2)
                        EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 1, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                        EVT_WAIT(2)
                    EVT_END_LOOP
                EVT_END_THREAD
            EVT_END_IF
            EVT_WAIT(36)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_SET(LW(0), 15)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(1))
            EVT_SUB(LW(0), LW(1))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(1)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, SOUND_20BA, SOUND_3B4)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
                EVT_CASE_LT(5)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EB)
                EVT_CASE_DEFAULT
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EC)
            EVT_END_SWITCH
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(N(move_squad_to_home))
            EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(N(set_alive_guys_animation))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SET(LW(14), 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(0))
    EVT_SUB(LW(14), LW(0))
    EVT_SET(LW(13), LW(14))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3AD)
    EVT_LOOP(LW(13))
        EVT_IF_GT(LW(14), 1)
            EVT_SET(LW(0), BS_FLAGS1_40)
        EVT_ELSE
            EVT_SET(LW(0), BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_END_IF
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 1, LW(0))
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(1), LW(2), LW(3))
            EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 0, LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 1, LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
        EVT_END_THREAD
        EVT_CALL(GetPlayerHP, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_SUB(LW(14), 1)
        EVT_IF_EQ(LW(14), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_3AD)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(20)
    EVT_SET(LW(0), 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(1))
    EVT_SUB(LW(0), LW(1))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
        EVT_CASE_LT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EB)
        EVT_CASE_DEFAULT
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EC)
    EVT_END_SWITCH
    EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_4)
    EVT_EXEC_WAIT(N(move_squad_to_home))
    EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_1)
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
    EVT_SET(LW(0), 2)
    EVT_LOOP(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), NPC_ANIM_shy_squad_guy_Palette_00_Anim_8)
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0066), ACTOR_SELF, 1, -1, -1)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_SET(LW(0), 2)
    EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_8)
    EVT_LOOP(14)
        EVT_THREAD
            EVT_CALL(RandInt, 100, LW(2))
            EVT_ADD(LW(2), 190)
            EVT_CALL(RandInt, 100, LW(3))
            EVT_ADD(LW(3), -50)
            EVT_SETF(LW(4), EVT_FLOAT(6.0))
            EVT_SET(LW(5), 0)
            EVT_EXEC_WAIT(N(move_guy_to_pos))
        EVT_END_THREAD
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_SET(LW(0), 16)
        EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_8)
        EVT_SET(LW(2), 240)
        EVT_SET(LW(3), 0)
        EVT_SETF(LW(4), EVT_FLOAT(6.0))
        EVT_SET(LW(5), 0)
        EVT_EXEC_WAIT(N(move_guy_to_pos))
    EVT_END_THREAD
    EVT_SET(LW(0), 15)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(1))
    EVT_SUB(LW(0), LW(1))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
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
    EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(2.5))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(0))
    EVT_IF_LT(LW(0), 14)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0067), ACTOR_ENEMY0, 1, -1, -1)
    EVT_ELSE
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0068), ACTOR_ENEMY0, 1, -1, -1)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_1E2)
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(2.0))
        EVT_WAIT(12)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_1E2)
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(40)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_173)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_174)
    EVT_END_THREAD
    EVT_SET(LW(0), 2)
    EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_8)
    EVT_LOOP(14)
        EVT_THREAD
            EVT_CALL(RandInt, 100, LW(2))
            EVT_ADD(LW(2), -290)
            EVT_CALL(RandInt, 100, LW(3))
            EVT_ADD(LW(3), -50)
            EVT_SETF(LW(4), EVT_FLOAT(10.0))
            EVT_EXEC_WAIT(N(move_guy_to_pos))
        EVT_END_THREAD
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_IF_GT(LW(0), 30)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1002B)
        EVT_LABEL(1)
        EVT_WAIT(1)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(3), LW(4), LW(5))
        EVT_ADD(LW(3), 10)
        EVT_IF_GT(LW(0), LW(3))
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1002B)
        EVT_SET(LW(7), 0)
        EVT_LOOP(40)
            EVT_ADD(LW(7), 36)
            EVT_IF_GE(LW(7), 360)
                EVT_SUB(LW(7), 360)
            EVT_END_IF
            EVT_CALL(SetActorRotation, ACTOR_PLAYER, 0, LW(7), 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
        EVT_CALL(SetActorRotation, ACTOR_PLAYER, 0, 0, 0)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LW(0), 16)
        EVT_SET(LW(1), NPC_ANIM_shy_squad_guy_Palette_00_Anim_8)
        EVT_SET(LW(2), -240)
        EVT_SET(LW(3), 0)
        EVT_SETF(LW(4), EVT_FLOAT(10.0))
        EVT_SET(LW(5), 0)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(ACTOR_VARS_GUYS_KILLED), LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_LE(1)
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_LIMIT, 72)
        EVT_CASE_LE(2)
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_LIMIT, 48)
        EVT_CASE_LE(8)
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_LIMIT, 24)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorSize, ACTOR_SELF, EVT_LIMIT, EVT_LIMIT)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
