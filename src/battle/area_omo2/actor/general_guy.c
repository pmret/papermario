#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "animation_script.h"
#include "sprite/npc/general_guy.h"
#include "sprite/npc/general_guy_bomb.h"

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
extern s32 N(idleAnimations)[];
extern s32 N(idleAnimations_bomb)[];
extern Formation N(formation_shy_squad);

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnfadeBackgroundToBlack.inc.c"

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
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -1,
        .unk_1D = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_20000000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_bomb),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -1,
        .unk_1D = -10,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_40000,
    .type = ACTOR_TYPE_GENERAL_GUY,
    .level = 73,
    .maxHP = 10,
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
    .size = { 30, 30 },
    .hpBarOffset = { 20, -3 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_general_guy_Palette_00_Anim_2,
    STATUS_STONE, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_POISON, NPC_ANIM_general_guy_Palette_00_Anim_2,
    STATUS_STOP, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_FEAR, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(idleAnimations_bomb)[] = {
    STATUS_NORMAL, NPC_ANIM_general_guy_bomb_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(idleAnimations3)[] = {
    STATUS_NORMAL, NPC_ANIM_general_guy_Palette_00_Anim_E,
    STATUS_POISON, NPC_ANIM_general_guy_Palette_00_Anim_E,
    STATUS_STOP, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_FEAR, NPC_ANIM_general_guy_Palette_00_Anim_0,
    STATUS_END,
};

EvtScript N(nextTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn)))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(LoadBattleSection, 41)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_shy_squad)), 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LW(0), 1)
            EVT_SET(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_8)
            EVT_SET(LW(2), NPC_ANIM_general_guy_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LW(0), 1)
            EVT_SET(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_8)
            EVT_SET(LW(2), NPC_ANIM_general_guy_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_SET_CONST(LW(2), NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LW(0))
    EVT_IF_NE(LW(0), FALSE)
        EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_KO)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LT(LW(0), 60)
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
        EVT_WAIT_FRAMES(35)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 30)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(5)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206A)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_B)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_open_hatch))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_general_guy_Palette_00_Anim_B)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 8)
    EVT_ADD(LW(1), 27)
    EVT_SUB(LW(2), 4)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_general_guy_bomb_Palette_00_Anim_0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_general_guy_Palette_00_Anim_A)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_WAIT_FRAMES(6)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 8)
    EVT_ADD(LW(1), 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_general_guy_bomb_Palette_00_Anim_1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 2, SOUND_2F9)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 120)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 2, SOUND_2F9)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 50)
            EVT_SET(LW(1), -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 30, 0)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 65)
            EVT_SET(LW(1), -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 15, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 2, SOUND_2F9)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 15, 0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_BOMB_BLAST)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_WAIT_FRAMES(30)
            EVT_IF_EQ(LW(15), HIT_RESULT_10)
                EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
                EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
                EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
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
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 30)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206A)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_B)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_open_hatch))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(func_80253734, 2)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_general_guy_Palette_00_Anim_3)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundToBlack))
    EVT_END_THREAD
    EVT_CALL(GetModelCenter, 39)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, LW(8), SOUND_3D2)
            EVT_CALL(RandInt, 3, LW(0))
            EVT_ADD(LW(0), 3)
            EVT_WAIT_FRAMES(LW(0))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlayEffect, EFFECT_SNAKING_STATIC, 0, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 40, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_NO_CONTACT, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(GetModelCenter, 39)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), 0, LW(5))
            EVT_CALL(PlaySound, SOUND_2069)
            EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(12)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_IF_NE(LW(0), HIT_RESULT_MISS)
                EVT_CALL(GetModelCenter, 39)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
                EVT_CALL(PlaySound, SOUND_2069)
                EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
                EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
                EVT_WAIT_FRAMES(12)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_ELSE
                EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
                EVT_WAIT_FRAMES(20)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_CALL(func_80253734, 3)
            EVT_END_IF
            EVT_CALL(N(UnfadeBackgroundToBlack))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(GetModelCenter, 39)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), 0, LW(5))
            EVT_CALL(PlaySound, SOUND_2069)
            EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(12)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(GetModelCenter, 39)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), 0, LW(5))
            EVT_CALL(PlaySound, SOUND_2069)
            EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
            EVT_WAIT_FRAMES(12)
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_CALL(func_80253734, 3)
            EVT_END_IF
            EVT_CALL(N(UnfadeBackgroundToBlack))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetModelCenter, 39)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_CALL(PlaySound, SOUND_2069)
    EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
            EVT_IF_EQ(LW(15), HIT_RESULT_10)
                EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
                EVT_WAIT_FRAMES(30)
                EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
                EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
                EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_206B)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    EVT_CALL(GetModelCenter, 39)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_CALL(PlaySound,SOUND_2069)
    EVT_CALL(PlayEffect, EFFECT_LIGHTNING_BOLT, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 7, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(func_80253734, 3)
    EVT_END_IF
    EVT_CALL(N(UnfadeBackgroundToBlack))
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
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


