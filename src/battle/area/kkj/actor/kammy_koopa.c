#include "../area.h"
#include "entity.h"
#include "sprite/npc/BattleKammy.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/BattleParakarry.h"

#define NAMESPACE A(kammy_koopa)

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(nextTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(speakOnHit);
extern EvtScript N(onDeath);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
};

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleKammy_Anim05,
    STATUS_END,
};

s32 N(IdleAnimations_broomstick)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleKammy_Anim0C,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
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
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_broomstick),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_KAMMY_KOOPA,
    .level = 99,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
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
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_DONT_STOP_MUSIC, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(unknownCounter) = 0;

API_CALLABLE(N(unknownFunction)) {
    Actor* actor = get_actor(script->owner1.actorID);

    N(unknownCounter) += 9;
    N(unknownCounter) = clamp_angle(N(unknownCounter));
    actor->verticalRenderOffset = sin_rad(DEG_TO_RAD(N(unknownCounter))) * 3.0f;

    return ApiStatus_DONE2;
}

EvtScript N(idle) = {
    EVT_LOOP(0)
        EVT_CALL(N(unknownFunction))
        EVT_WAIT(1)
    EVT_END_LOOP
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
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleKammy_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(speakOnHit))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleKammy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_EXEC_WAIT(N(speakOnHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleKammy_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

API_CALLABLE(N(BlockAppear)) {
    Entity* entity = get_entity_by_index(script->varTable[9]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rot.y = (1.0f - cos_rad(entity->scale.y * PI)) * 1080.0f * 0.5f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(func_8021833C_6DC0DC) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
        set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
        set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
        set_screen_overlay_params_back(OVERLAY_BLUR, 150);
    }
    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
    set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
    set_screen_overlay_params_back(OVERLAY_NONE, -1);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802183EC_6DC18C) {
    if (isInitialCall) {
        script->functionTemp[0] = 30;
        set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
        set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
        set_screen_overlay_params_back(OVERLAY_BLUR, 150);
    }
    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
    set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
    set_screen_overlay_params_back(OVERLAY_NONE, -1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DropBlock)) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 entityIndex = script->varTable[9];
    Entity* entity = get_entity_by_index(entityIndex);

    entity->collisionTimer = 0;
    collisionStatus->lastWallHammered = entityIndex | COLLISION_WITH_ENTITY_BIT;
    playerStatus->flags |= PS_FLAG_HAMMER_CHECK;
    entity->collisionFlags = ENTITY_COLLISION_PLAYER_HAMMER;
    playerStatus->actionState = ACTION_STATE_HAMMER;
    entity->blueprint->fpHandleCollision(entity);
    entity->collisionTimer = 10;
    entity->flags |= ENTITY_FLAG_DETECTED_COLLISION;
    collisionStatus->lastWallHammered = -1;

    return ApiStatus_DONE2;
}

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim07)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_207A)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 25)
    EVT_ADD(LVar1, 40)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 100, 0)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 80, 95, 15)
    EVT_CALL(SetBattleCamZoom, 340)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_207B)
    EVT_SUB(LVar0, 15)
    EVT_ADD(LVar1, 30)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar3, 20)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_WAIT(20)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_WAIT(10)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_WAIT(5)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_WAIT(3)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block), LVar0, LVar1, LVar2, 0, MAKE_ENTITY_END)
    EVT_SET(LVar9, LVar0)
    EVT_CALL(N(BlockAppear))
    EVT_THREAD
        EVT_CALL(func_8021833C_6DC0DC)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_207C)
    EVT_CALL(N(GetEntityPosition), LVar9, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, LVar3, 300, 20, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPositionF), LVar9, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim08)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -80, 37, 5)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CHILD_THREAD
        EVT_WAIT(10)
        EVT_CALL(AddBattleCamZoom, 100)
        EVT_CALL(MoveBattleCamOver, 10)
        EVT_WAIT(5)
        EVT_CALL(func_802183EC_6DC18C)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_207D)
    EVT_SET(LVar5, LVar1)
    EVT_ADD(LVar5, 200)
    EVT_CALL(N(SetEntityPositionF), LVar9, LVar0, LVar5, LVar2)
    EVT_CALL(N(GetEntityPosition), LVar9, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, LVar5, LVar1, 20, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPositionF), LVar9, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(N(DropBlock))
    EVT_CHILD_THREAD
        EVT_CALL(StartRumble, 5)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(5.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_CHILD_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim05)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(19)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetLastDamage, ACTOR_PARTNER, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 69, 14, -18)
        EVT_CALL(SetBattleCamZoom, 340)
        EVT_CALL(SetBattleCamOffsetZ, 62)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(FreezeBattleCam, TRUE)
        EVT_WAIT(20)
        EVT_THREAD
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 5, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 6, 0, EASING_LINEAR)
        EVT_END_THREAD
        EVT_CALL(ActorSpeak, MSG_CH8_009A, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim05)
        EVT_WAIT(10)
        EVT_CALL(FreezeBattleCam, FALSE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, 69, 14, -18)
                    EVT_CALL(SetBattleCamZoom, 340)
                    EVT_CALL(SetBattleCamOffsetZ, 62)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_WAIT(20)
                    EVT_CALL(ActorSpeak, MSG_CH8_0093, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim05)
                    EVT_WAIT(10)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, -56, -9, -18)
                    EVT_CALL(SetBattleCamZoom, 340)
                    EVT_CALL(SetBattleCamOffsetZ, 62)
                    EVT_CALL(MoveBattleCamOver, 1)
                    EVT_WAIT(10)
                    EVT_CALL(ActorSpeak, MSG_CH8_0094, ACTOR_PARTNER, 1, ANIM_Twink_ShoutAngry, ANIM_Twink_Angry)
                    EVT_WAIT(10)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, -66, -9, -18)
                    EVT_CALL(SetBattleCamZoom, 340)
                    EVT_CALL(SetBattleCamOffsetZ, 62)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_WAIT(10)
                    EVT_CALL(ActorSpeak, MSG_CH8_0095, ACTOR_PLAYER, 1, ANIM_BattleParakarry_EnterShell, ANIM_BattleParakarry_ShellFly)
                    EVT_WAIT(10)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(AddActorVar, ACTOR_SELF, 0, 1)
            EVT_END_SWITCH
        EVT_CASE_EQ(12)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(speakOnHit) = {
    EVT_CALL(FreezeBattleState, TRUE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 69, 14, -18)
            EVT_CALL(SetBattleCamZoom, 340)
            EVT_CALL(SetBattleCamOffsetZ, 62)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(FreezeBattleCam, TRUE)
            EVT_WAIT(20)
            EVT_CALL(ActorSpeak, MSG_CH8_0097, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim09, ANIM_BattleKammy_Anim05)
            EVT_WAIT(10)
            EVT_CALL(FreezeBattleCam, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 69, 14, -18)
            EVT_CALL(SetBattleCamZoom, 340)
            EVT_CALL(SetBattleCamOffsetZ, 62)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(FreezeBattleCam, TRUE)
            EVT_WAIT(20)
            EVT_CALL(ActorSpeak, MSG_CH8_0098, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim0A, ANIM_BattleKammy_Anim05)
            EVT_WAIT(10)
            EVT_CALL(FreezeBattleCam, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(7)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 69, 14, -18)
            EVT_CALL(SetBattleCamZoom, 340)
            EVT_CALL(SetBattleCamOffsetZ, 62)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(FreezeBattleCam, TRUE)
            EVT_WAIT(20)
            EVT_CALL(ActorSpeak, MSG_CH8_0099, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim05)
            EVT_WAIT(10)
            EVT_CALL(FreezeBattleCam, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorVar, ACTOR_SELF, 0, 1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim02)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_2, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SEEING_STARS)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim03)
    EVT_WAIT(50)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(ActorSpeak, MSG_CH8_009B, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim03, ANIM_BattleKammy_Anim03)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT(40)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_PLAYER_IN_BACK, FALSE)
    EVT_RETURN
    EVT_END
};
