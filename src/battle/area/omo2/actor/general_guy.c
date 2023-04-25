#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "animation_script.h"
#include "sprite/npc/GeneralGuy.h"
#include "sprite/npc/GeneralGuyBomb.h"

#define NAMESPACE b_area_omo2_general_guy

extern ActorBlueprint b_area_omo2_1_shy_squad;
extern AnimScript toy_tank_as_close_hatch;
extern AnimScript toy_tank_as_open_hatch;

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(attack_throw_bomb);
extern EvtScript N(attack_lightning_shot);
extern s32 N(IdleAnimations)[];
extern s32 N(IdleAnimations_bomb)[];
extern Formation N(formation_shy_squad);

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnfadeBackgroundToBlack.inc.c"

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
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_20000000,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_20000000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_bomb),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_HIDE_HP_BAR,
    .type = ACTOR_TYPE_GENERAL_GUY,
    .level = 73,
    .maxHP = 10,
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
    .size = { 30, 30 },
    .hpBarOffset = { 20, -3 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_GeneralGuy_Anim02,
    STATUS_STONE, ANIM_GeneralGuy_Anim00,
    STATUS_SLEEP, ANIM_GeneralGuy_Anim00,
    STATUS_POISON, ANIM_GeneralGuy_Anim02,
    STATUS_STOP, ANIM_GeneralGuy_Anim00,
    STATUS_STATIC, ANIM_GeneralGuy_Anim00,
    STATUS_PARALYZE, ANIM_GeneralGuy_Anim00,
    STATUS_PARALYZE, ANIM_GeneralGuy_Anim00,
    STATUS_DIZZY, ANIM_GeneralGuy_Anim00,
    STATUS_DIZZY, ANIM_GeneralGuy_Anim00,
    STATUS_FEAR, ANIM_GeneralGuy_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations_bomb)[] = {
    STATUS_NORMAL, ANIM_GeneralGuyBomb_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations3)[] = {
    STATUS_NORMAL, ANIM_GeneralGuy_Anim0E,
    STATUS_POISON, ANIM_GeneralGuy_Anim0E,
    STATUS_STOP, ANIM_GeneralGuy_Anim00,
    STATUS_STATIC, ANIM_GeneralGuy_Anim00,
    STATUS_PARALYZE, ANIM_GeneralGuy_Anim00,
    STATUS_DIZZY, ANIM_GeneralGuy_Anim00,
    STATUS_FEAR, ANIM_GeneralGuy_Anim00,
    STATUS_END,
};

EvtScript N(nextTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init) = {
    EVT_CALL(SetActorPos, ACTOR_SELF, 200, 0, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 200, 0, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(LoadBattleSection, 41)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_shy_squad)), 1)
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

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_GeneralGuy_Anim08)
            EVT_SET(LVar2, ANIM_GeneralGuy_Anim09)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_GeneralGuy_Anim08)
            EVT_SET(LVar2, ANIM_GeneralGuy_Anim09)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim09)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim0E)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim02)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim0E)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim02)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim02)
            EVT_SET_CONST(LVar2, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_KO)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 60)
                EVT_EXEC_WAIT(N(attack_lightning_shot))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(attack_throw_bomb))
    EVT_RETURN
    EVT_END
};

EvtScript N(attack_throw_bomb) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 30)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206A)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim0B)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_open_hatch))
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GeneralGuy_Anim0B)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 8)
    EVT_ADD(LVar1, 27)
    EVT_SUB(LVar2, 4)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_GeneralGuyBomb_Anim00)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GeneralGuy_Anim0A)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_WAIT(6)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 8)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_GeneralGuyBomb_Anim01)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 2, SOUND_2F9)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 120)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 2, SOUND_2F9)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 65)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 2, SOUND_2F9)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_BOMB_BLAST)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GeneralGuy_Anim02)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
                EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
                EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attack_lightning_shot) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 30)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206A)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim0B)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_open_hatch))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(func_80253734, BTL_DARKNESS_MODE_2)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GeneralGuy_Anim03)
    EVT_WAIT(20)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundToBlack))
    EVT_END_THREAD
    EVT_CALL(GetModelCenter, 39)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, LVar8, SOUND_3D2)
            EVT_CALL(RandInt, 3, LVar0)
            EVT_ADD(LVar0, 3)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 40, 0)
    EVT_WAIT(40)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(GetModelCenter, 39)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_CALL(PlaySound, SOUND_2069)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_WAIT(12)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_IF_NE(LVar0, HIT_RESULT_MISS)
                EVT_CALL(GetModelCenter, 39)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                EVT_CALL(PlaySound, SOUND_2069)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
                EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
                EVT_WAIT(12)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_ELSE
                EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
                EVT_WAIT(20)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(func_80253734, BTL_DARKNESS_MODE_3)
            EVT_END_IF
            EVT_CALL(N(UnfadeBackgroundToBlack))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(GetModelCenter, 39)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_CALL(PlaySound, SOUND_2069)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_WAIT(12)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(GetModelCenter, 39)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_CALL(PlaySound, SOUND_2069)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
            EVT_WAIT(12)
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(func_80253734, BTL_DARKNESS_MODE_3)
            EVT_END_IF
            EVT_CALL(N(UnfadeBackgroundToBlack))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetModelCenter, 39)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(PlaySound, SOUND_2069)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
    EVT_WAIT(12)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GeneralGuy_Anim02)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
                EVT_WAIT(30)
                EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
                EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
                EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    EVT_CALL(GetModelCenter, 39)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(PlaySound, SOUND_2069)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
    EVT_WAIT(12)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(func_80253734, BTL_DARKNESS_MODE_3)
    EVT_END_IF
    EVT_CALL(N(UnfadeBackgroundToBlack))
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(summon_pos) = { 240, 0, 0 };

Formation N(formation_shy_squad) = {
    { .actor = &b_area_omo2_1_shy_squad, .home = { .vec = &N(summon_pos) }, .priority = 100, }
};


