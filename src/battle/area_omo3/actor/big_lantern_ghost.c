#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BigLanternGhost.h"
#include "effects.h"
#include "sprite.h"

#define NAMESPACE b_area_omo3_big_lantern_ghost

extern s32 N(idleAnimations)[];

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);
extern EvtScript N(updateEffectThread);
extern EvtScript N(setGhostNoTarget);
extern EvtScript N(onHit);
extern EvtScript N(checkExtinguish);
extern EvtScript N(onDeath);
extern EvtScript N(returnHome);

enum N(ActorVars) {
    N(VAR_LANTERN_BRIGHTNESS)            = 0,
    N(VAR_DARKENING)            = 1,
    N(VAR_LANTERN_X)        = 2,
    N(VAR_LANTERN_Y)        = 3,
    N(VAR_LANTERN_Z)          = 4,
    N(VAR_EXTINGUISHED_ONCE)          = 5,
    N(VAR_6)          = 6,
    N(VAR_SPEAK_FLAGS)     = 7,
    N(VAR_EFFECT)    = 10,
    N(VAR_MOVE_ID)    = 11,
    N(VAR_LIGHT_BEAM_COUNTER)    = 12,
    N(VAR_HIT_SOUND_COUNTER)    = 13,
};

enum N(MoveIds) {
    N(MOVE_HEAVY_JUMP) = 0,
    N(MOVE_EXTINGUISH) = 1,
    N(MOVE_LIGHT_BEAM) = 2,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable2)[] = {
    ELEMENT_NORMAL, 99,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 40,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 60,
    STATUS_SHRINK, 0,
    STATUS_STOP, 60,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -5,
        .unk_1D = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000,
        .index = 2,
        .posOffset = { -40, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -9,
        .unk_20 = 2687103,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BIG_LANTERN_GHOST,
    .level = 42,
    .maxHP = 40,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 86, 60 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -30, 55 },
    .statusMessageOffset = { 20, 45 },
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, ANIM_BigLanternGhost_Anim01,
    STATUS_STONE, ANIM_BigLanternGhost_Anim00,
    STATUS_SLEEP, ANIM_BigLanternGhost_Anim0C,
    STATUS_POISON, ANIM_BigLanternGhost_Anim01,
    STATUS_STOP, ANIM_BigLanternGhost_Anim00,
    STATUS_STATIC, ANIM_BigLanternGhost_Anim00,
    STATUS_PARALYZE, ANIM_BigLanternGhost_Anim00,
    STATUS_PARALYZE, ANIM_BigLanternGhost_Anim00,
    STATUS_DIZZY, ANIM_BigLanternGhost_Anim0D,
    STATUS_FEAR, ANIM_BigLanternGhost_Anim0D,
    STATUS_END,
};

ApiStatus N(init_overlay)(Evt* script, s32 isInitialCall) {
    get_actor(script->owner1.actorID);

    set_screen_overlay_params_back(13, 220.0f);
    set_screen_overlay_alpha(1, 200.0f);
    return ApiStatus_DONE2;
}

s32 N(get_darkening)(ActorState* actorState, s32 targetDarkening) {
    s32 delta = targetDarkening - actorState->varTable[N(VAR_DARKENING)];

    if (delta >= 4) {
        actorState->varTable[N(VAR_DARKENING)] += 4;
    } else if (delta >= -4) {
        actorState->varTable[N(VAR_DARKENING)] = targetDarkening;
    } else {
        actorState->varTable[N(VAR_DARKENING)] -= 4;
    }

    return actorState->varTable[N(VAR_DARKENING)];
}

ApiStatus N(update_effect)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.actorID);
    ActorState* actorState;
    ActorPart* actorPart;
    BulbGlowFXData* effectData;
    s32 partX, partY, partZ;
    f32 posX, posY, posZ;
    f32 rotX, rotY, rotZ;
    f32 yaw;
    f32 f24, f22;
    s32 opacity;
    s32 compListIdx;

    if (actor == NULL) {
        set_screen_overlay_alpha(1, 0.0f);
        return ApiStatus_BLOCK;
    }

    actorState = &actor->state;
    if (effect != NULL) {
        effectData = effect->data.bulbGlow;
    }

    posX = actor->currentPos.x;
    posY = actor->currentPos.y;
    posZ = actor->currentPos.z;

    rotX = actor->rotation.x;
    rotY = actor->rotation.y + actor->yaw;
    rotZ = actor->rotation.z;

    actorPart = get_actor_part(actor, 1);
    if (actorPart->currentAnimation == ANIM_BigLanternGhost_Anim0C) {
        func_802DE8DC(actor->partsTable->unk_84, 0, &partX, &partY, &partZ);
    } else {
        func_802DE8DC(actor->partsTable->unk_84, 1, &partX, &partY, &partZ);
    }


    partY += 20;

    f24 = (f32)partX * SPRITE_WORLD_SCALE_D;
    f22 = (f32)partY * SPRITE_WORLD_SCALE_D;

    f24 *= cos_deg(rotY);
    f22 *= sin_deg(rotX + 90.0);

    partX = f24 * cos_deg(rotZ) + f22 * sin_deg(rotZ);
    partY = f24 * -sin_deg(rotZ) + f22 * cos_deg(rotZ);

    switch (actorState->varTable[N(VAR_LANTERN_BRIGHTNESS)]) {
        case 0:
            opacity = N(get_darkening)(actorState, 290);
            break;
        case 1:
            opacity = N(get_darkening)(actorState, 250) + (rand_int(0x4000) % 5);
            break;
        case 2:
            opacity = N(get_darkening)(actorState, 240) + (rand_int(0x4000) % 5);
            break;
        case 3:
            opacity = N(get_darkening)(actorState, 230) + (rand_int(0x4000) % 5);
            break;
        case 4:
            opacity = N(get_darkening)(actorState, 220) + (rand_int(0x4000) % 5);
            break;
        case 5:
            opacity = N(get_darkening)(actorState, 210) + (rand_int(0x4000) % 5);
            break;
        case 6:
            opacity = N(get_darkening)(actorState, 180) + (rand_int(0x4000) % 5);
            break;
        case 7:
            opacity = N(get_darkening)(actorState, 140) + (rand_int(0x4000) % 5);
            break;
        case 8:
            opacity = N(get_darkening)(actorState, 100) + (rand_int(0x4000) % 5);
            break;
        case 9:
            opacity = N(get_darkening)(actorState, 70) + (rand_int(0x4000) % 5);
            break;
        case 10:
            opacity = N(get_darkening)(actorState, 40) + (rand_int(0x4000) % 5);
            break;
        case 11:
            opacity = N(get_darkening)(actorState, 20);
            opacity = N(get_darkening)(actorState, 20);
            opacity = N(get_darkening)(actorState, 20);
            break;
        default:
            opacity = 0;
            break;
    }

    set_screen_overlay_alpha(1, opacity);
    set_screen_overlay_center_worldpos(1, 0, posX + partX, posY + partY, posZ + partZ);

    actorState->varTable[N(VAR_LANTERN_X)] = posX + partX;
    actorState->varTable[N(VAR_LANTERN_Y)] = posY + partY;
    actorState->varTable[N(VAR_LANTERN_Z)] = posZ + partZ;

    actorPart = get_actor_part(actor, 2);
    actorPart->partOffset.x = partX - 5;
    actorPart->partOffset.y = partY + 5;

    if (effect != NULL) {
        effectData->pos.x = actorState->varTable[N(VAR_LANTERN_X)];
        effectData->pos.y = actorState->varTable[N(VAR_LANTERN_Y)];
        effectData->pos.z = actorState->varTable[N(VAR_LANTERN_Z)] + 25;
    }

    return ApiStatus_DONE2;
}

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EXTINGUISHED_ONCE), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_6), 10)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 2)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_DARKENING), 240)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), 0)
    EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), LVar0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    EVT_CALL(N(init_overlay))
    EVT_EXEC(N(updateEffectThread))
    EVT_EXEC_WAIT(N(setGhostNoTarget))
    EVT_WAIT(2)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
            EVT_IF_NOT_FLAG(LVar0, 1)
                EVT_BITWISE_OR_CONST(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetBattleCamOffsetZ, 40)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(30)
                EVT_CALL(ActorSpeak, MSG_CH4_0051, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(updateEffectThread) = {
    EVT_SET_PRIORITY(99)
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    EVT_ELSE
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_CALL(N(update_effect), LVar0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(checkExtinguish))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(checkExtinguish))
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 7143434)
            EVT_SET(LVar2, 7143435)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 7143434)
            EVT_SET(LVar2, 7143435)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim0B)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(checkExtinguish))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_EQ(LVar1, 2)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar2)
                EVT_IF_LT(LVar2, 10)
                    EVT_ADD(LVar2, 2)
                    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(0)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A3)
                            EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        EVT_CASE_EQ(1)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A4)
                            EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        EVT_CASE_EQ(2)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A5)
                            EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        EVT_CASE_EQ(3)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A6)
                            EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        EVT_CASE_DEFAULT
                    EVT_END_SWITCH
                    EVT_IF_GT(LVar2, 10)
                        EVT_SET(LVar2, 10)
                    EVT_END_IF
                    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar2)
                    EVT_EXEC_WAIT(N(setGhostNoTarget))
                    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
                    EVT_IF_GE(LVar0, 6)
                        EVT_EXEC_WAIT(N(checkExtinguish))
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_SET_CONST(LVar2, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_CALL(func_8026E914, LVar0, LVar1)
    EVT_IF_NE(LVar1, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar1)
    EVT_MUL(LVar1, 10)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_6), LVar0)
    EVT_ADD(LVar0, LVar1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_6), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(checkExtinguish) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), LVar0)
    EVT_IF_NE(LVar0, N(MOVE_LIGHT_BEAM))
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_EXTINGUISH))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(attackHeavyJump) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
    EVT_IF_GE(LVar0, 6)
        EVT_EXEC_WAIT(N(checkExtinguish))
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim06)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 999, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim10)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim11)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37D)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim01)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37D)
            EVT_WAIT(8)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim10)
    EVT_THREAD
        EVT_WAIT(7)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim11)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37D)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
            EVT_CALL(SetBattleCamZoom, 320)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim10)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37D)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim01)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37D)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackLightBeam) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), 3)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim06)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim01)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 35)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EB)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim0F)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar5)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 11)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_Y), LVar1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_Z), LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 2)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlayEffect, EFFECT_LIGHT_RAYS, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), LVarB, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(30)
        EVT_CALL(RemoveEffect, LVarB)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlayEffect, EFFECT_RADIATING_ENERGY_ORB, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                EVT_CASE_DEFAULT
                    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarD, 0, 65535, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT(2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarE, DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_WAIT(2)
            EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarD, DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(40)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar5)
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
        EVT_WAIT(10)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3AA)
            EVT_CASE_EQ(1)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A9)
            EVT_CASE_EQ(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A8)
            EVT_CASE_EQ(3)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A7)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim14)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_EXEC_WAIT(N(returnHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(extinguish) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EXTINGUISHED_ONCE), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_6), 1000)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_LIGHT_BEAM))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
    EVT_IF_NOT_FLAG(LVar0, 2)
        EVT_BITWISE_OR_CONST(LVar0, 2)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), LVar0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(SetBattleCamOffsetZ, 40)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(30)
        EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
        EVT_CALL(GetActorHP, ACTOR_SELF, LVar1)
        EVT_IF_EQ(LVar0, LVar1)
            EVT_CALL(ActorSpeak, MSG_CH4_0053, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
        EVT_ELSE
            EVT_CALL(ActorSpeak, MSG_CH4_0052, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(SetBattleCamZoom, 230)
    EVT_CALL(SetBattleCamOffsetZ, 25)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3CF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim0F)
    EVT_WAIT(8)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3D0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim0E)
    EVT_WAIT(5)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 2)
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 0)
        EVT_WAIT(10)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(4)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3AA)
            EVT_CASE_EQ(3)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A9)
            EVT_CASE_EQ(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A8)
            EVT_CASE_EQ(1)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3A7)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_WAIT(14)
    EVT_WAIT(1)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim01)
    EVT_EXEC_WAIT(N(setGhostNoTarget))
    EVT_WAIT(30)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), LVar0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(N(MOVE_LIGHT_BEAM))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), LVar0)
            EVT_IF_GT(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
            EVT_END_IF
        EVT_CASE_EQ(N(MOVE_EXTINGUISH))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
            EVT_IF_LT(LVar0, 6)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(N(MOVE_LIGHT_BEAM))
            EVT_EXEC_WAIT(N(attackLightBeam))
        EVT_CASE_EQ(N(MOVE_EXTINGUISH))
            EVT_EXEC_WAIT(N(extinguish))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(attackHeavyJump))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim07)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BigLanternGhost_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(setGhostNoTarget) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(5)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CASE_LT(8)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_EXEC_WAIT(D_8029AF08)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
