#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "message_ids.h"
#include "sprite/npc/general_guy.h"
#include "sprite/npc/tank_guy.h"
#include "mapfs/omo_bt07_shape.h"

#define NAMESPACE b_area_omo2_toy_tank

extern ActorBlueprint b_area_omo2_4_signal_guy;
extern ActorBlueprint b_area_omo2_2_stilt_guy;
extern ActorBlueprint b_area_omo2_3_shy_stack;
extern ActorBlueprint b_area_omo2_5_shy_squad_dup;

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(onHit);
extern EvtScript N(shake_tank);
extern EvtScript N(select_phase);
extern EvtScript N(update_phase);
extern EvtScript N(start_stilt_guys_phase);
extern EvtScript N(start_shy_stack_phase);
extern EvtScript N(summon_stilt_guys);
extern EvtScript N(summon_tank_squad);
extern EvtScript N(start_battle_with_tank);
extern EvtScript N(onDeath);
extern EvtScript N(8022F4D0);
extern EvtScript N(8022F458);
extern EvtScript N(8022F2BC);

extern Formation N(formation_signal_guy);
extern Formation N(formation_stilt_guy_1);
extern Formation N(formation_stilt_guy_2);
extern Formation N(formation_shy_stack_1);
extern Formation N(formation_shy_stack_2);
extern Formation N(formation_shy_squad_dup);

ApiStatus N(UpdateBulbGlow)(Evt* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;

    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 rotation = evt_get_variable(script, *args++);
    BulbGlowFXData* effectData = ((EffectInstance*) evt_get_variable(script, *args++))->data;

    effectData->pos.x = x;
    effectData->pos.y = y;
    effectData->pos.z = z + 2;

    return ApiStatus_DONE2;
}

ApiStatus func_802181F4_52B894(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    get_actor(script->owner1.actorID);
    set_screen_overlay_params_back(13, evt_get_variable(script, *args));
    return ApiStatus_DONE2;
}

#include "animation.inc.c"

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 2,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 30, 0 },
        .targetOffset = { 0, 50 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
        .unk_20 = MSG_actor_general_guy_dup,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { -5, 0, 0 },
        .targetOffset = { -10, 20 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
        .unk_20 = MSG_actor_general_guy_dup,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_40000,
    .type = ACTOR_TYPE_TOY_TANK,
    .level = 0,
    .maxHP = 30,
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
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 48, 78 },
    .hpBarOffset = { 20, -3 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_ENEMY0, 0, 7, 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, 85, 0, 0)
    EVT_CALL(SetHomePos, ACTOR_SELF, 85, 0, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, 85, 30, 0)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, 80, 0, 0)
    EVT_CALL(LoadAnimatedModel, 0, EVT_ADDR(toy_tank_model))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_idle))
    EVT_CALL(EnableModel, 62, 0)
    EVT_CALL(SetAnimatedModelRootPosition, 0, 200, 0, 0)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 3, 1, 1)
    EVT_CALL(GetModelCenter, 39)
    EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 2, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), LW(5), 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, LW(5))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_EXEC(N(select_phase))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LW(0))
    EVT_IF_NE(LW(0), FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_CALL(GetAnimatedNodePosition, 0, 62, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
            EVT_CALL(GetAnimatedNodeRotation, 0, 62, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorRotation, ACTOR_ENEMY0, LW(0), 0, LW(2))
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(5))
        EVT_IF_NE(LW(5), 0)
            EVT_CALL(ActorExists, ACTOR_ENEMY2, LW(0))
            EVT_IF_NE(LW(0), FALSE)
                EVT_CALL(GetAnimatedNodeRotation, 0, 62, LW(0), LW(1), LW(3))
                EVT_CALL(GetModelCenter, 39)
                EVT_CALL(GetActorVar, ACTOR_SELF, 6, LW(6))
                EVT_IF_EQ(LW(6), 0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(10))
                    EVT_IF_NE(LW(10), 0)
                        EVT_SET(LW(0), 1000)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(N(UpdateBulbGlow), LW(0), LW(1), LW(2), LW(3), LW(5))
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(onHit))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_CALL(func_8026E914, LW(0), LW(1))
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_WAIT_FRAMES(30)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_WAIT_FRAMES(30)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_WAIT_FRAMES(30)
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 50)
    EVT_EXEC_WAIT(N(shake_tank))
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LW(0))
    EVT_CALL(func_80269E80, LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(19)
            EVT_IF_NOT_FLAG(LW(0), 0x2)
                EVT_BITWISE_OR_CONST(LW(0), 0xE)
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LW(0))
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0072), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5, NPC_ANIM_general_guy_Palette_00_Anim_5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(4)
            EVT_IF_NOT_FLAG(LW(0), 0x4)
                EVT_BITWISE_OR_CONST(LW(0), 0xC)
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LW(0))
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0073), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5, NPC_ANIM_general_guy_Palette_00_Anim_5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_IF_NOT_FLAG(LW(0), 0x8)
                EVT_BITWISE_OR_CONST(LW(0), 0xC)
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LW(0))
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0074), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5, NPC_ANIM_general_guy_Palette_00_Anim_5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY0, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shake_tank) = {
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_shake))
    EVT_WAIT_FRAMES(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(select_phase) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_EXEC_WAIT(N(update_phase))
        EVT_EXEC_WAIT(N(start_stilt_guys_phase))
    EVT_ELSE
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_IF_EQ(LW(0), 2)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_EXEC_WAIT(N(update_phase))
        EVT_EXEC_WAIT(N(start_shy_stack_phase))
    EVT_ELSE
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(2)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(0))
    EVT_IF_NE(LW(0), 2)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
    EVT_CALL(CancelEnemyTurn, 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 8)
    EVT_EXEC_WAIT(N(start_battle_with_tank))
    EVT_GOTO(99)
    EVT_LABEL(3) // unreachable code
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_IF_NE(LW(0), 2)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_CALL(GetCurrentPartnerID, LW(0))
    EVT_IF_EQ(LW(0), PARTNER_WATT)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_EXEC_WAIT(N(update_phase))
        EVT_EXEC_WAIT(N(start_shy_stack_phase))
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(2)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 7)
        EVT_EXEC_WAIT(N(summon_tank_squad))
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 8)
        EVT_EXEC_WAIT(N(start_battle_with_tank))
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(10)
    EVT_LABEL(99)
    EVT_RETURN
    EVT_END
};

EvtScript N(update_phase) = {
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 2, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(6)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 5)
        EVT_CASE_DEFAULT
            EVT_ADD(LW(0), 1)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, LW(0))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(start_stilt_guys_phase) = {
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x1)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0069), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_0, NPC_ANIM_general_guy_Palette_00_Anim_0)
    EVT_ELSE // shy squad has fleed
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x006A), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_C, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_END_IF
    EVT_CALL(LoadBattleSection, 44)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_signal_guy)), 1)
    EVT_WAIT_FRAMES(60)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_TOY_TANK_MOVE1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_move_forward))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_3)
    EVT_WAIT_FRAMES(25)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetOwnerTarget, LW(0), 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(1), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_10)
    EVT_WAIT_FRAMES(16)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_4)
    EVT_WAIT_FRAMES(16)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_TOY_TANK_MOVE2)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_idle))
    EVT_WAIT_FRAMES(26)
    EVT_EXEC_WAIT(N(summon_stilt_guys))
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_CALL(SetHomePos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_ENEMY0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(start_shy_stack_phase) = {
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 2, LW(0))
    EVT_IF_EQ(LW(0), 2)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x006E), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_C, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_ELSE
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(LoadBattleSection, 43)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_shy_stack_1)), 1)
    EVT_WAIT_FRAMES(124)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_shy_stack_2)), 1)
    EVT_WAIT_FRAMES(114)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_idle))
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_IF_NE(LW(0), 4)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_ENEMY4, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 60)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x006F), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_C, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY3, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY3, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY3, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_ENEMY3, 10, FALSE, TRUE, FALSE)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY3, FALSE)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY3, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY4, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY4, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY4, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_ENEMY4, 10, FALSE, TRUE, FALSE)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY4, FALSE)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY4, TRUE)
    EVT_END_THREAD
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0070), ACTOR_ENEMY4, 1, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(summon_stilt_guys) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(func_8024ECF8, 0, 1, 0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 2, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x006B), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_C, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_ELSE
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(LoadBattleSection, 42)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_stilt_guy_1)), 1)
    EVT_WAIT_FRAMES(60)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_stilt_guy_2)), 1)
    EVT_WAIT_FRAMES(60)
    EVT_LABEL(1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_IF_NE(LW(0), 3)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 50, 1, 0)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 60)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x006C), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_C, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY3, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY3, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY3, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_ENEMY3, 10, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY4, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY4, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY4, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_ENEMY4, 10, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x006D), ACTOR_ENEMY4, 1, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(summon_tank_squad) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetActorYaw, ACTOR_ENEMY0, 180)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_3)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_80253734, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 1)
    EVT_EXEC(N(8022F2BC))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(func_8024ECF8, 0, 1, 0)
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_CALL(SetActorYaw, ACTOR_ENEMY0, 0)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_CALL(LoadBattleSection, 45)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_shy_squad_dup)), 1)
    EVT_WAIT_FRAMES(155)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_3)
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY3)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(20)
    EVT_SET(LW(0), 2)
    EVT_LOOP(15)
        EVT_CALL(RandInt, 3, LW(1))
        EVT_SWITCH(LW(1))
            EVT_CASE_EQ(0)
                EVT_SET(LW(1), NPC_ANIM_tank_guy_Palette_00_Anim_8)
            EVT_CASE_EQ(1)
                EVT_SET(LW(1), NPC_ANIM_tank_guy_Palette_00_Anim_9)
            EVT_CASE_EQ(2)
                EVT_SET(LW(1), NPC_ANIM_tank_guy_Palette_00_Anim_A)
            EVT_CASE_DEFAULT
                EVT_SET(LW(1), NPC_ANIM_tank_guy_Palette_00_Anim_6)
        EVT_END_SWITCH
        EVT_CALL(SetAnimation, ACTOR_ENEMY3, LW(0), LW(1))
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_SET(LW(0), 2)
    EVT_LOOP(15)
        EVT_CALL(SetAnimation, ACTOR_ENEMY3, LW(0), NPC_ANIM_tank_guy_Palette_00_Anim_1)
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(start_battle_with_tank) = {
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT_FRAMES(60)
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0F, 0x0071), ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_0, NPC_ANIM_general_guy_Palette_00_Anim_0)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5)
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_20000000, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY2, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY1, 2, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY1, ACTOR_FLAG_40000, 0)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, 0, 1)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, SOUND_36F)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_fall_apart))
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(RemoveEffect, LW(0))
        EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(45)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlayEffect, EFFECT_EXPLOSION, 2, 102, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, SOUND_34E)
    EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY0, EVT_FLOAT(0.6))
    EVT_CALL(SetActorDispOffset, ACTOR_ENEMY0, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5)
    EVT_THREAD
        EVT_WAIT_FRAMES(25)
        EVT_CALL(SetAnimatedModelRootPosition, 0, 380, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_ENEMY0, 50, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY0, SOUND_20E4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_10)
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 18)
    EVT_CALL(ForceHomePos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_CALL(SetEnemyHP, ACTOR_ENEMY0, 1)
    EVT_CALL(SetPartDispOffset, ACTOR_ENEMY0, 1, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_ENEMY0, 0, 0, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY0, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_ENEMY0, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_7)
    EVT_CALL(ShakeCam, 1, 0, 6, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 10)
    EVT_ADD(LW(1), 30)
    EVT_CALL(PlayEffect, EFFECT_STARS_ORBITING, 0, LW(0), LW(1), LW(2), 20, 4, LW(15), 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY0, SOUND_20E5)
    EVT_CALL(DropStarPoints, 512)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(RemoveEffect, LW(15))
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LW(0))
    EVT_IF_NE(LW(0), FALSE)
        EVT_CALL(SetActorFlagBits, ACTOR_ENEMY2, ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_END_IF
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F2BC) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_SELF, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(func_802537C0, LW(0), LW(1))
    EVT_IF_EQ(LW(0), 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(1))
    EVT_CALL(GetCurrentPartnerID, LW(0))
    EVT_IF_EQ(LW(0), PARTNER_WATT)
        EVT_EXEC_WAIT(N(8022F458))
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 6, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_EXEC_WAIT(N(8022F458))
        EVT_ELSE
            EVT_EXEC_WAIT(N(8022F4D0))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(func_802181F4_52B894, LW(1))
    EVT_LABEL(10)
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F458) = {
    EVT_IF_NE(LW(1), 0)
        EVT_SUB(LW(1), 5)
        EVT_IF_LT(LW(1), 0)
            EVT_SET(LW(1), 0)
        EVT_END_IF
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, LW(1))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F4D0) = {
    EVT_IF_NE(LW(1), 215)
        EVT_ADD(LW(1), 5)
        EVT_IF_GT(LW(1), 215)
            EVT_SET(LW(1), 215)
        EVT_END_IF
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, LW(1))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3i N(summon_pos) = { 240, 0, 0 };

Formation N(formation_signal_guy) = {
    { .actor = &b_area_omo2_4_signal_guy, .home = { .vec = &N(summon_pos) }, .priority = 95, }
};

Formation N(formation_stilt_guy_1) = {
    { .actor = &b_area_omo2_2_stilt_guy, .home = { .vec = &N(summon_pos) }, .priority = 95, }
};

Formation N(formation_stilt_guy_2) = {
    { .actor = &b_area_omo2_2_stilt_guy, .home = { .vec = &N(summon_pos) }, .priority = 90, .var0 = 1, }
};

Formation N(formation_shy_stack_1) = {
    { .actor = &b_area_omo2_3_shy_stack, .home = { .vec = &N(summon_pos) }, .priority = 95, }
};

Formation N(formation_shy_stack_2) = {
    { .actor = &b_area_omo2_3_shy_stack, .home = { .vec = &N(summon_pos) }, .priority = 90, .var0 = 1, }
};

Formation N(formation_shy_squad_dup) = {
    { .actor = &b_area_omo2_5_shy_squad_dup, .home = { .vec = &N(summon_pos) }, .priority = 95, }
};

