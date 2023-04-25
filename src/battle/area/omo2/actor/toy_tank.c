#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "message_ids.h"
#include "sprite/npc/GeneralGuy.h"
#include "sprite/npc/TankGuy.h"
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

API_CALLABLE(N(UpdateBulbGlow)) {
    Bytecode *args = script->ptrReadPos;

    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 rotation = evt_get_variable(script, *args++);
    BulbGlowFXData* effectData = ((EffectInstance*) evt_get_variable(script, *args++))->data.bulbGlow;

    effectData->pos.x = x;
    effectData->pos.y = y;
    effectData->pos.z = z + 2;

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802181F4_52B894) {
    Bytecode* args = script->ptrReadPos;
    get_actor(script->owner1.actorID);
    set_screen_overlay_params_back(OVERLAY_BATTLE_DARKNESS, evt_get_variable(script, *args));
    return ApiStatus_DONE2;
}

#include "animation.inc.c"

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 2,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 30, 0 },
        .targetOffset = { 0, 50 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
        .overrideNameMsg = MSG_EnemyName_GeneralGuyDup,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { -5, 0, 0 },
        .targetOffset = { -10, 20 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
        .overrideNameMsg = MSG_EnemyName_GeneralGuyDup,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_HIDE_HP_BAR,
    .type = ACTOR_TYPE_TOY_TANK,
    .level = 0,
    .maxHP = 30,
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
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(toy_tank_model))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_idle))
    EVT_CALL(EnableModel, 62, FALSE)
    EVT_CALL(SetAnimatedModelRootPosition, 0, 200, 0, 0)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 3, ACTOR_PART_TARGET_FLAG_1, TRUE)
    EVT_CALL(GetModelCenter, 39)
    EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), LVar5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, LVar5)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_EXEC(N(select_phase))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(GetAnimatedNodePosition, 0, 62, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
            EVT_CALL(GetAnimatedNodeRotation, 0, 62, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorRotation, ACTOR_ENEMY0, LVar0, 0, LVar2)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar5)
        EVT_IF_NE(LVar5, 0)
            EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_CALL(GetAnimatedNodeRotation, 0, 62, LVar0, LVar1, LVar3)
                EVT_CALL(GetModelCenter, 39)
                EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar6)
                EVT_IF_EQ(LVar6, 0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVarA)
                    EVT_IF_NE(LVarA, 0)
                        EVT_SET(LVar0, 1000)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(N(UpdateBulbGlow), LVar0, LVar1, LVar2, LVar3, LVar5)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(onHit))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_WAIT(30)
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
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 50)
    EVT_EXEC_WAIT(N(shake_tank))
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LVar0)
    EVT_CALL(GetDamageSource, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(DMG_SRC_ELECTRO_DASH)
            EVT_IF_NOT_FLAG(LVar0, 0x2)
                EVT_BITWISE_OR_CONST(LVar0, 0xE)
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH4_0072, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
        EVT_CASE_OR_EQ(DMG_SRC_D_DOWN_POUND)
        EVT_CASE_OR_EQ(DMG_SRC_D_DOWN_JUMP)
            EVT_IF_NOT_FLAG(LVar0, 0x4)
                EVT_BITWISE_OR_CONST(LVar0, 0xC)
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH4_0073, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_IF_NOT_FLAG(LVar0, 0x8)
                EVT_BITWISE_OR_CONST(LVar0, 0xC)
                EVT_CALL(SetActorVar, ACTOR_ENEMY0, 1, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH4_0074, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY0, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shake_tank) = {
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_shake))
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(select_phase) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_EXEC_WAIT(N(update_phase))
        EVT_EXEC_WAIT(N(start_stilt_guys_phase))
    EVT_ELSE
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_EXEC_WAIT(N(update_phase))
        EVT_EXEC_WAIT(N(start_shy_stack_phase))
    EVT_ELSE
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(2)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_WAIT(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
    EVT_CALL(CancelEnemyTurn, 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 8)
    EVT_EXEC_WAIT(N(start_battle_with_tank))
    EVT_GOTO(99)
    EVT_LABEL(3) // unreachable code
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_WAIT(1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_WATT)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_EXEC_WAIT(N(update_phase))
        EVT_EXEC_WAIT(N(start_shy_stack_phase))
        EVT_WAIT(1)
        EVT_GOTO(2)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 7)
        EVT_EXEC_WAIT(N(summon_tank_squad))
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 8)
        EVT_EXEC_WAIT(N(start_battle_with_tank))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(10)
    EVT_LABEL(99)
    EVT_RETURN
    EVT_END
};

EvtScript N(update_phase) = {
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(6)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, 5)
        EVT_CASE_DEFAULT
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, LVar0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(start_stilt_guys_phase) = {
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x1)
        EVT_CALL(ActorSpeak, MSG_CH4_0069, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim00, ANIM_GeneralGuy_Anim00)
    EVT_ELSE // shy squad has fleed
        EVT_CALL(ActorSpeak, MSG_CH4_006A, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_END_IF
    EVT_CALL(LoadBattleSection, 44)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_signal_guy)), 1)
    EVT_WAIT(60)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_TOY_TANK_MOVE1)
    EVT_WAIT(5)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_move_forward))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim03)
    EVT_WAIT(25)
    EVT_WAIT(2)
    EVT_CALL(SetOwnerTarget, LVar0, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar1, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim10)
    EVT_WAIT(16)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim04)
    EVT_WAIT(16)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_TOY_TANK_MOVE2)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
    EVT_WAIT(20)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_idle))
    EVT_WAIT(26)
    EVT_EXEC_WAIT(N(summon_stilt_guys))
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
    EVT_WAIT(40)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 2, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(ActorSpeak, MSG_CH4_006E, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_ELSE
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_CALL(LoadBattleSection, 43)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_shy_stack_1)), 1)
    EVT_WAIT(124)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_shy_stack_2)), 1)
    EVT_WAIT(114)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_idle))
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_IF_NE(LVar0, 4)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_ENEMY4, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 60)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(ActorSpeak, MSG_CH4_006F, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY3, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY3, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY3, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY3, 10, FALSE, TRUE, FALSE)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY3, FALSE)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY3, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY3, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY4, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY4, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY4, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY4, 10, FALSE, TRUE, FALSE)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY4, FALSE)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_ENEMY4, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY4, TRUE)
    EVT_END_THREAD
    EVT_CALL(ActorSpeak, MSG_CH4_0070, ACTOR_ENEMY4, 1, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(summon_stilt_guys) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 2, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ActorSpeak, MSG_CH4_006B, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_ELSE
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_CALL(LoadBattleSection, 42)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_stilt_guy_1)), 1)
    EVT_WAIT(60)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_stilt_guy_2)), 1)
    EVT_WAIT(60)
    EVT_LABEL(1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_NE(LVar0, 3)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 50, 1, 0)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 60)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(ActorSpeak, MSG_CH4_006C, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY3, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY3, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY3, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY3, 10, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_ENEMY4, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY4, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_ENEMY4, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY4, 10, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(ActorSpeak, MSG_CH4_006D, ACTOR_ENEMY4, 1, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(summon_tank_squad) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(SetActorYaw, ACTOR_ENEMY0, 180)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim03)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_WAIT(10)
    EVT_CALL(func_80253734, BTL_DARKNESS_MODE_1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 1)
    EVT_EXEC(N(8022F2BC))
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetActorYaw, ACTOR_ENEMY0, 0)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
    EVT_CALL(LoadBattleSection, 45)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_shy_squad_dup)), 1)
    EVT_WAIT(155)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim03)
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY3)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(20)
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(RandInt, 3, LVar1)
        EVT_SWITCH(LVar1)
            EVT_CASE_EQ(0)
                EVT_SET(LVar1, ANIM_TankGuy_Anim08)
            EVT_CASE_EQ(1)
                EVT_SET(LVar1, ANIM_TankGuy_Anim09)
            EVT_CASE_EQ(2)
                EVT_SET(LVar1, ANIM_TankGuy_Anim0A)
            EVT_CASE_DEFAULT
                EVT_SET(LVar1, ANIM_TankGuy_Anim06)
        EVT_END_SWITCH
        EVT_CALL(SetAnimation, ACTOR_ENEMY3, LVar0, LVar1)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim04)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(SetAnimation, ACTOR_ENEMY3, LVar0, ANIM_TankGuy_Anim01)
        EVT_ADD(LVar0, 1)
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
    EVT_WAIT(60)
    EVT_CALL(ActorSpeak, MSG_CH4_0071, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim00, ANIM_GeneralGuy_Anim00)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05)
    EVT_CALL(EndActorSpeech, ACTOR_ENEMY0, 1, -1, -1)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_20000000, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY2, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY1, 2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY1, ACTOR_FLAG_HIDE_HP_BAR, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, 0, 1)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 2, 0, 35)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, SOUND_36F)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_fall_apart))
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(RemoveEffect, LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_END_IF
    EVT_WAIT(45)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05)
    EVT_WAIT(15)
    EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 2, 102, 40, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, SOUND_34E)
    EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY0, EVT_FLOAT(0.6))
    EVT_CALL(SetActorDispOffset, ACTOR_ENEMY0, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(SetAnimatedModelRootPosition, 0, 380, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_ENEMY0, 50, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY0, SOUND_20E4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim10)
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 18)
    EVT_CALL(ForceHomePos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_CALL(SetEnemyHP, ACTOR_ENEMY0, 1)
    EVT_CALL(SetPartDispOffset, ACTOR_ENEMY0, 1, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_ENEMY0, 0, 0, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY0, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_ENEMY0, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim07)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar1, 30)
    EVT_PLAY_EFFECT(EFFECT_STARS_ORBITING, 0, LVar0, LVar1, LVar2, 20, 4, LVarF, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY0, SOUND_20E5)
    EVT_CALL(DropStarPoints, ACTOR_ENEMY0)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(SetActorFlagBits, ACTOR_ENEMY2, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_END_IF
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F2BC) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(func_802537C0, LVar0, LVar1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar1)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_WATT)
        EVT_EXEC_WAIT(N(8022F458))
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_EXEC_WAIT(N(8022F458))
        EVT_ELSE
            EVT_EXEC_WAIT(N(8022F4D0))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(func_802181F4_52B894, LVar1)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F458) = {
    EVT_IF_NE(LVar1, 0)
        EVT_SUB(LVar1, 5)
        EVT_IF_LT(LVar1, 0)
            EVT_SET(LVar1, 0)
        EVT_END_IF
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, LVar1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8022F4D0) = {
    EVT_IF_NE(LVar1, 215)
        EVT_ADD(LVar1, 5)
        EVT_IF_GT(LVar1, 215)
            EVT_SET(LVar1, 215)
        EVT_END_IF
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, LVar1)
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

