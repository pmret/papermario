#include "../area.h"
#include "sprite.h"
#include "sprite/npc/BigLanternGhost.h"

#define NAMESPACE A(big_lantern_ghost)

extern s32 N(DefaultAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(updateEffectThread);
extern EvtScript N(setGhostNoTarget);
extern EvtScript N(onHit);
extern EvtScript N(checkExtinguish);
extern EvtScript N(onDeath);
extern EvtScript N(EVS_ReturnHome);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
};

enum N(ActorVars) {
    N(VAR_LANTERN_BRIGHTNESS)   = 0,
    N(VAR_DARKENING)            = 1,
    N(VAR_LANTERN_X)            = 2,
    N(VAR_LANTERN_Y)            = 3,
    N(VAR_LANTERN_Z)            = 4,
    N(VAR_EXTINGUISHED_ONCE)    = 5,
    N(VAR_6)                    = 6,
    N(VAR_SPEAK_FLAGS)          = 7,
    N(VAR_EFFECT)               = 10,
    N(VAR_MOVE_ID)              = 11,
    N(VAR_LIGHT_BEAM_COUNTER)   = 12,
    N(VAR_HIT_SOUND_COUNTER)    = 13,
};

enum N(MoveIds) {
    N(MOVE_HEAVY_JUMP) = 0,
    N(MOVE_EXTINGUISH) = 1,
    N(MOVE_LIGHT_BEAM) = 2,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(defenseTable2)[] = {
    ELEMENT_NORMAL,  99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           60,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,               60,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_DAMAGE_IMMUNE,
        .index = PRT_2,
        .posOffset = { -40, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -9 },
        .overrideNameMsg = MSG_EnemyName_Lantern,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BIG_LANTERN_GHOST,
    .level = ACTOR_LEVEL_BIG_LANTERN_GHOST,
    .maxHP = 40,
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
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 86, 60 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -30, 55 },
    .statusTextOffset = { 20, 45 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BigLanternGhost_Anim01,
    STATUS_KEY_STONE,     ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BigLanternGhost_Anim0C,
    STATUS_KEY_POISON,    ANIM_BigLanternGhost_Anim01,
    STATUS_KEY_STOP,      ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_STATIC,    ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_BigLanternGhost_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BigLanternGhost_Anim0D,
    STATUS_KEY_FEAR,      ANIM_BigLanternGhost_Anim0D,
    STATUS_END,
};

API_CALLABLE(N(init_overlay)) {
    get_actor(script->owner1.actorID);

    set_screen_overlay_params_back(OVERLAY_BATTLE_DARKNESS, 220.0f);
    set_screen_overlay_alpha(SCREEN_LAYER_BACK, 200.0f);
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

API_CALLABLE(N(update_effect)) {
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
        set_screen_overlay_alpha(SCREEN_LAYER_BACK, 0.0f);
        return ApiStatus_BLOCK;
    }

    actorState = &actor->state;
    if (effect != NULL) {
        effectData = effect->data.bulbGlow;
    }

    posX = actor->curPos.x;
    posY = actor->curPos.y;
    posZ = actor->curPos.z;

    rotX = actor->rot.x;
    rotY = actor->rot.y + actor->yaw;
    rotZ = actor->rot.z;

    actorPart = get_actor_part(actor, 1);
    if (actorPart->curAnimation == ANIM_BigLanternGhost_Anim0C) {
        spr_get_comp_position(actor->partsTable->spriteInstanceID, 0, &partX, &partY, &partZ);
    } else {
        spr_get_comp_position(actor->partsTable->spriteInstanceID, 1, &partX, &partY, &partZ);
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

    set_screen_overlay_alpha(SCREEN_LAYER_BACK, opacity);
    set_screen_overlay_center_worldpos(SCREEN_LAYER_BACK, 0, posX + partX, posY + partY, posZ + partZ);

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

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EXTINGUISHED_ONCE), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_6), 10)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 2)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_DARKENING), 240)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SPEAK_FLAGS), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), 0)
    EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), LVar0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    EVT_CALL(N(init_overlay))
    EVT_EXEC(N(updateEffectThread))
    EVT_EXEC_WAIT(N(setGhostNoTarget))
    EVT_WAIT(2)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
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
                EVT_CALL(ActorSpeak, MSG_CH4_0051, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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

EvtScript N(EVS_Idle) = {
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

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(checkExtinguish))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(checkExtinguish))
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 7143434)
            EVT_SET(LVar2, 7143435)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 7143434)
            EVT_SET(LVar2, 7143435)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim0B)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(checkExtinguish))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_EQ(LVar1, 2)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar2)
                EVT_IF_LT(LVar2, 10)
                    EVT_ADD(LVar2, 2)
                    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(0)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_1)
                            EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        EVT_CASE_EQ(1)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_2)
                            EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        EVT_CASE_EQ(2)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_3)
                            EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 1)
                        EVT_CASE_EQ(3)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_REVEAL_MORE_4)
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
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim01)
            EVT_SET_CONST(LVar2, ANIM_BigLanternGhost_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
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
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim06)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_LARGE_ACTOR_JUMP, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim10)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim11)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            EVT_WAIT(8)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim10)
    EVT_THREAD
        EVT_WAIT(7)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim11)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
            EVT_CALL(SetBattleCamZoom, 320)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim10)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_STEP)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackLightBeam) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_HEAVY_JUMP))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LIGHT_BEAM_COUNTER), 3)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim06)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_05)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 35)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_LIGHT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim0F)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar5)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 11)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_X), LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_Y), LVar1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_Z), LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 2)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), LVarB, 0)
        EVT_WAIT(30)
        EVT_CALL(RemoveEffect, LVarB)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(1)
        EVT_PLAY_EFFECT(EFFECT_RADIATING_ENERGY_ORB, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 30, 0)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                EVT_CASE_DEFAULT
                    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarD, 0, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT(2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarE, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
            EVT_WAIT(2)
            EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarD, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(40)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar5)
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
        EVT_WAIT(10)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_4)
            EVT_CASE_EQ(1)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_3)
            EVT_CASE_EQ(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_2)
            EVT_CASE_EQ(3)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_1)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim14)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(N(EVS_ReturnHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(extinguish) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_EXTINGUISHED_ONCE), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_6), 1000)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_MOVE_ID), N(MOVE_LIGHT_BEAM))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
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
            EVT_CALL(ActorSpeak, MSG_CH4_0053, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
        EVT_ELSE
            EVT_CALL(ActorSpeak, MSG_CH4_0052, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim05, ANIM_BigLanternGhost_Anim01)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(SetBattleCamZoom, 230)
    EVT_CALL(SetBattleCamOffsetZ, 25)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_INHALE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim0F)
    EVT_WAIT(8)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_BLOW)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim0E)
    EVT_WAIT(5)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), 2)
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_HIT_SOUND_COUNTER), 0)
        EVT_WAIT(10)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(4)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_4)
            EVT_CASE_EQ(3)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_3)
            EVT_CASE_EQ(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_2)
            EVT_CASE_EQ(1)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LANTERN_GHOST_DARKEN_1)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_WAIT(14)
    EVT_WAIT(1)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    EVT_EXEC_WAIT(N(setGhostNoTarget))
    EVT_WAIT(30)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
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

EvtScript N(EVS_ReturnHome) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BigLanternGhost_Anim07)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BigLanternGhost_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(setGhostNoTarget) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LANTERN_BRIGHTNESS), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(5)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CASE_LT(8)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
        EVT_CASE_DEFAULT
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_EXEC_WAIT(EVS_Enemy_DeathWithoutRemove)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_EFFECT), LVar0)
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
