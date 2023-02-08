#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBowser.h"
#include "effects.h"

#define NAMESPACE b_area_kpa2_bowser_phase_1

enum N(ActorVars) {
    N(VAR_TURN_COUNTER) = 0,
    N(VAR_FLAGS) = 1,
    N(VAR_TURNS_SINCE_LAST_SHOCKWAVE_DRAIN) = 2,
    N(VAR_TURNS_SINCE_LAST_STAR_BEAM) = 3,
    N(VAR_TURNS_SINCE_LAST_CLAW_SWIPE) = 4,
    N(VAR_TURNS_SINCE_LAST_HEAVY_JUMP) = 5,
    N(VAR_TURNS_SINCE_LAST_RECOVER) = 6,
    N(VAR_RECOVERS_LEFT) = 7,
    N(VAR_COMMAND_LOSS_STATE) = 9,
    N(VAR_LOST_ABILITY_ITEM) = 10,
};

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);
extern EvtScript N(unkDecorationScript);
extern EvtScript N(attackFlameBreath);
extern EvtScript N(attackClawSwipe);
extern EvtScript N(attackHeavyJump);
extern EvtScript N(normalAttack);
extern EvtScript N(attackShockwaveDrain);
extern EvtScript N(attack);
extern EvtScript N(useStarRod);
extern EvtScript N(doTakeTurn);
extern EvtScript N(onHit);
extern EvtScript N(onImmune);
extern EvtScript N(onDeath);
extern EvtScript N(jumpHome);
extern EvtScript N(returnHome);
extern EvtScript N(onSpinSmashOrNormalHit);
extern EvtScript N(onBurnHit);
extern EvtScript N(makeWalkingSounds);

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, ANIM_BattleBowser_Idle,
    STATUS_STONE, ANIM_BattleBowser_Still,
    STATUS_SLEEP, ANIM_BattleBowser_Idle,
    STATUS_POISON, ANIM_BattleBowser_Idle,
    STATUS_STOP, ANIM_BattleBowser_Still,
    STATUS_STATIC, ANIM_BattleBowser_Still,
    STATUS_PARALYZE, ANIM_BattleBowser_Still,
    STATUS_PARALYZE, ANIM_BattleBowser_Still,
    STATUS_DIZZY, ANIM_BattleBowser_Idle,
    STATUS_DIZZY, ANIM_BattleBowser_Idle,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(defenseTable_boosted)[] = {
    ELEMENT_NORMAL, 4,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 30,
    STATUS_SHRINK, 50,
    STATUS_STOP, 30,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

s32 N(statusTable_boosted)[] = {
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
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -18, 72 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOWSER_PHASE_1,
    .level = 100,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .takeTurnScript = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 65,
    .coinReward = 0,
    .size = { 80, 82 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -40, 67 },
    .statusMessageOffset = { 10, 60 },
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/UnkBowserFunc1.inc.c"
#include "common/FadeBackgroundToBlack.inc.c"
#include "common/UnfadeBackgroundToBlack.inc.c"
#include "common/RemoveChillOut.inc.c"
#include "common/StarRodAppearEffect.inc.c"
#include "common/StarRodPowerUpEffect.inc.c"
#include "common/GetJumpHammerCharge.inc.c"
#include "common/GetPlayerHpPercent.inc.c"
#include "common/ItemEntityJumpToPos.inc.c"
#include "common/GetItemEntityPosition.inc.c"

EvtScript N(init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_SHOCKWAVE_DRAIN), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_CLAW_SWIPE), 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_HEAVY_JUMP), 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMMAND_LOSS_STATE), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LOST_ABILITY_ITEM), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_STAR_BEAM), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_RECOVER), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_RECOVERS_LEFT), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 14, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 1, 100, 0, 0, 0)
    EVT_EXEC(N(unkDecorationScript))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar3)
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_SELF, LVarB)
    EVT_IF_EQ(LVarB, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarB)
    EVT_IF_NOT_FLAG(LVarB, STATUS_FLAG_SHRINK)
        EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 1, 100, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 1, 40, 0, 0, 0)
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeWalkingSounds))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
            EVT_IF_NOT_FLAG(LVar0, 1)
                EVT_BITWISE_OR_CONST(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
                EVT_CALL(ActorSpeak, MSG_CH8_0073, ACTOR_SELF, 1, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(func_802535B4, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onSpinSmashOrNormalHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_BattleBowser_BurnHurt)
            EVT_SET(LVar2, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(onBurnHit))
            EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar0)
            EVT_IF_NOT_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
                EVT_IF_FLAG(LVar0, 4)
                    EVT_IF_NOT_FLAG(LVar0, 8)
                        EVT_BITWISE_OR_CONST(LVar0, 8)
                        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
                        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                            EVT_CALL(MoveBattleCamOver, 30)
                            EVT_CALL(ActorSpeak, MSG_CH8_0077, ACTOR_SELF, 1, ANIM_BattleBowser_AnnoyedTalk, ANIM_BattleBowser_AnnoyedTalk)
                        EVT_END_IF
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_BattleBowser_BurnHurt)
            EVT_SET(LVar2, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(onBurnHit))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onSpinSmashOrNormalHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(jumpHome))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(jumpHome))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_SCRIPTED_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(func_80269E80, LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_OR_EQ(18)
                EVT_CASE_OR_EQ(21)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Mock)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_BattleBowser_Mock)
                    EVT_EXEC_WAIT(N(onImmune))
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET(LVar1, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Jump)
            EVT_EXEC_WAIT(DoRecover)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostJump)
            EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(3.0))
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SWAP_PARTNER)
            EVT_CALL(N(UnfadeBackgroundToBlack))
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(FreezeBattleCam, 1)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET(LVar3, 50)
                EVT_SET(LVar4, 40)
            EVT_ELSE
                EVT_SET(LVar3, 20)
                EVT_SET(LVar4, 16)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, LVar3)
            EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 50, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, LVar4)
            EVT_CALL(PlayEffect, EFFECT_SHIMMER_BURST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ENCHANTED, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_STAR_BEAM), 0)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable)))
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(statusTable)))
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
            EVT_IF_NOT_FLAG(LVar0, 2)
                EVT_BITWISE_OR_CONST(LVar0, 2)
                EVT_BITWISE_OR_CONST(LVar0, 4)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_CALL(ActorSpeak, MSG_CH8_0075, ACTOR_SELF, 1, ANIM_BattleBowser_Hurt, ANIM_BattleBowser_Hurt)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_RearUpStill)
                EVT_LOOP(2)
                    EVT_SET(LVar0, 0)
                    EVT_LOOP(10)
                        EVT_ADD(LVar0, 18)
                        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_WAIT(5)
                    EVT_SET(LVar0, 180)
                    EVT_LOOP(10)
                        EVT_SUB(LVar0, 18)
                        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_WAIT(5)
                EVT_END_LOOP
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH8_0076, ACTOR_SELF, 1, ANIM_BattleBowser_Hurt, ANIM_BattleBowser_Hurt)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_END_IF
            EVT_CALL(FreezeBattleCam, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_WAIT(30)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onSpinSmashOrNormalHit) = {
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
        EVT_IF_FLAG(LVar0, 4)
            EVT_IF_NOT_FLAG(LVar0, 8)
                EVT_BITWISE_OR_CONST(LVar0, 8)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                    EVT_CALL(FreezeBattleCam, 1)
                    EVT_EXEC_WAIT(N(onHit))
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                    EVT_CALL(MoveBattleCamOver, 30)
                    EVT_CALL(ActorSpeak, MSG_CH8_0077, ACTOR_SELF, 1, ANIM_BattleBowser_AnnoyedTalk, ANIM_BattleBowser_AnnoyedTalk)
                    EVT_CALL(FreezeBattleCam, 0)
                EVT_ELSE
                    EVT_EXEC_WAIT(N(onHit))
                EVT_END_IF
                EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(onHit))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(DoNormalHit)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
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
            EVT_SET(LocalFlag(0), 0)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar1)
            EVT_SWITCH(LVar1)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOB_OMB)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BULLET_BILL)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BILL)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_NE(LVar2, -12345)
                EVT_SET(LVar2, 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                    EVT_ADD(LVar2, 30)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 10)
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_EXEC_WAIT(ForceNextTarget)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(onImmune) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(DoImmune)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_EXEC_WAIT(N(doTakeTurn))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(powerUp) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x40)
        EVT_BITWISE_OR_CONST(LVar0, 0x40)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLAGS), LVar0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Brandish)
        EVT_WAIT(5)
        EVT_CALL(ActorSpeak, MSG_CH8_0074, ACTOR_SELF, 1, ANIM_BattleBowser_BrandishTalk, ANIM_BattleBowser_BrandishIdle)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_BrandishStill)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Brandish)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_EXEC_WAIT(N(useStarRod))
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_SET(LVar0, 1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetDist2D, LVar9, LVarA, LVarC, LVarD, LVarF)
    EVT_IF_GE(LVar9, EVT_FLOAT(5.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_END_IF
    EVT_IF_EQ(LVarB, 180)
        EVT_LOOP(15)
            EVT_SUB(LVarB, 12)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVarB)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(unkDecorationScript) = {
    EVT_CALL(N(UnkBowserFunc1))
    EVT_RETURN
    EVT_END
};

EvtScript N(useStarRod) = {
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 90)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2123)
            EVT_ADD(LVar2, 10)
            EVT_CALL(N(StarRodAppearEffect), LVar0, LVar1, LVar2, EVT_FLOAT(2.5), EVT_FLOAT(0.05))
        EVT_END_THREAD
    EVT_ELSE
        EVT_ADD(LVar0, 6)
        EVT_ADD(LVar1, 36)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2123)
            EVT_ADD(LVar2, 10)
            EVT_CALL(N(StarRodAppearEffect), LVar0, LVar1, LVar2, EVT_FLOAT(2.5), EVT_FLOAT(0.02))
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(65)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 15)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarF, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarE, 0, 0, 0, 0, 0, 0, 0)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarD, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_ADD(LVar0, 6)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_LIGHT_RAYS, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarF, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarE, 0, 0, 0, 0, 0, 0, 0)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarD, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2121)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarE)
    EVT_CALL(RemoveEffect, LVarD)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ENCHANTED, 1)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 1, 11)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_boosted)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(statusTable_boosted)))
    EVT_CALL(N(RemoveChillOut))
    EVT_WAIT(3)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 40)
        EVT_ADD(LVar2, 12)
        EVT_CALL(PlayEffect, EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 70, 80, 25, 60, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 16)
        EVT_ADD(LVar2, 12)
        EVT_CALL(PlayEffect, EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 28, 32, 10, 60, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2125)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(N(StarRodPowerUpEffect), LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_END_THREAD
    EVT_WAIT(75)
    EVT_THREAD
        EVT_CALL(N(UnfadeBackgroundToBlack))
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_RearUpLaugh)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 40)
    EVT_ELSE
        EVT_ADD(LVar1, 16)
    EVT_END_IF
    EVT_CALL(PlayEffect, EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 15, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2124)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 39)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(jumpHome) = {
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar5, LVar6, LVar7)
    EVT_SET(LVar8, LVar2)
    EVT_ADD(LVar8, LVar5)
    EVT_DIV(LVar8, 2)
    EVT_SET(LVar9, LVar4)
    EVT_ADD(LVar9, LVar7)
    EVT_DIV(LVar9, 2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar8, 0, LVar9)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LVar8, LVar2)
    EVT_DIV(LVar8, 2)
    EVT_ADD(LVar9, LVar4)
    EVT_DIV(LVar9, 2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar8, 0, LVar9)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeWalkingSounds) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar7)
    EVT_IF_NE(LVar7, ANIM_BattleBowser_Walk)
        EVT_IF_EQ(LVar3, ANIM_BattleBowser_Walk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F6)
        EVT_END_IF
        EVT_SET(LVar3, LVar7)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar5, LVar6, LVar7)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_GT(LVar5, -30)
        EVT_IF_LT(LVar5, 30)
            EVT_SET(LVar3, LVar7)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B4)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F6)
    EVT_SET(LVar3, LVar7)
    EVT_RETURN
    EVT_END
};

EvtScript N(recover) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_RECOVERS_LEFT), LVar0)
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_RECOVERS_LEFT), LVar0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 15)
        EVT_ADD(LVar1, 65)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 420)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 6)
        EVT_ADD(LVar1, 26)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 294)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Brandish)
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2126)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 90)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 50, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 5, LVar0, 90, LVar2, EVT_FLOAT(0.3), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 6)
        EVT_ADD(LVar1, 36)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.4), 50, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 6)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 5, LVar0, 36, LVar2, EVT_FLOAT(0.12), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    EVT_MUL(LVar0, 40)
    EVT_DIV(LVar0, 100)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(HealActor, ACTOR_SELF, LVar0, 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(doTakeTurn) = {
    EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_CLAW_SWIPE), 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_HEAVY_JUMP), 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_SHOCKWAVE_DRAIN), 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_STAR_BEAM), 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_RECOVER), 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 15)
            EVT_ADD(LVar1, 60)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(SetBattleCamZoom, 420)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
        EVT_ELSE
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 24)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(SetBattleCamZoom, 420)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
        EVT_END_IF
        EVT_EXEC_WAIT(N(powerUp))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MUL(LVar0, 100)
    EVT_DIV(LVar0, LVar1)
    EVT_CALL(N(GetPlayerHpPercent), LVar2)
    EVT_SUB(LVar2, LVar0)
    EVT_IF_GT(LVar2, 30)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_RECOVERS_LEFT), LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 80)
                EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_RECOVER), LVar0)
                EVT_IF_GT(LVar0, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_RECOVER), 0)
                    EVT_EXEC_WAIT(N(recover))
                    EVT_RETURN
                EVT_ELSE
                    EVT_CALL(RandInt, 100, LVar0)
                    EVT_IF_LT(LVar0, 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_RECOVER), 0)
                        EVT_EXEC_WAIT(N(recover))
                        EVT_RETURN
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
    EVT_IF_GT(LVar0, 1)
        EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar0)
        EVT_IF_NOT_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_STAR_BEAM), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, 0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar0, 20)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar0, 30)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar0, 100)
            EVT_END_SWITCH
            EVT_CALL(RandInt, 100, LVar1)
            EVT_IF_LT(LVar1, LVar0)
                EVT_EXEC_WAIT(N(powerUp))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_SHOCKWAVE_DRAIN), LVar0)
    EVT_IF_LT(LVar0, 3)
        EVT_EXEC_WAIT(N(normalAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(attack))
    EVT_RETURN
    EVT_END
};

EvtScript N(attack) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
    EVT_IF_LE(LVar0, 3)
        EVT_EXEC_WAIT(N(normalAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_SHOCKWAVE_DRAIN), LVar0)
    EVT_IF_GE(LVar0, 6)
        EVT_CALL(RandInt, 20, LVar0)
        EVT_IF_LT(LVar0, 20)
            EVT_EXEC_WAIT(N(attackShockwaveDrain))
        EVT_ELSE
            EVT_EXEC_WAIT(N(attackShockwaveDrain))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 75)
        EVT_CALL(N(GetJumpHammerCharge), LVar0, LVar1)
        EVT_IF_GT(LVar0, 0)
            EVT_EXEC_WAIT(N(attackShockwaveDrain))
            EVT_RETURN
        EVT_END_IF
        EVT_IF_GT(LVar1, 0)
            EVT_EXEC_WAIT(N(attackShockwaveDrain))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 20)
        EVT_IF_LT(LVar0, 20)
            EVT_EXEC_WAIT(N(attackShockwaveDrain))
        EVT_ELSE
            EVT_EXEC_WAIT(N(attackShockwaveDrain))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(normalAttack))
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(normalAttack) = {
    EVT_CALL(RandInt, 80, LVar0)
    EVT_IF_LT(LVar0, 20)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_HEAVY_JUMP), LVar0)
        EVT_IF_GE(LVar0, 2)
            EVT_EXEC_WAIT(N(attackHeavyJump))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RandInt, 60, LVar0)
    EVT_IF_LT(LVar0, 20)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_CLAW_SWIPE), LVar0)
        EVT_IF_GE(LVar0, 2)
            EVT_EXEC_WAIT(N(attackClawSwipe))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(attackFlameBreath))
    EVT_RETURN
    EVT_END
};

#include "common/DisableRandomAbility.inc.c"
#include "common/CanPlayerLoseAction.inc.c"
#include "common/UnkFireBreathFXFunc.inc.c"

EvtScript N(inflictCommandLoss) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_COMMAND_LOSS_STATE), LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_SET(LVar2, 0)
            EVT_SUB(LVar3, 1)
            EVT_CALL(N(DisableRandomAbility), LVar4, LVar5)
            EVT_CALL(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_LOST_ABILITY_ITEM), LVar0)
            EVT_ADD(LVar1, 7)
            EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 8, EVT_FLOAT(1.0))
            EVT_ADD(LVar1, 12)
            EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 8, EVT_FLOAT(1.0))
            EVT_ADD(LVar1, 7)
            EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, EVT_FLOAT(1.0))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMMAND_LOSS_STATE), 0)
        EVT_CASE_EQ(2)
            EVT_CALL(ShowMessageBox, LVar5, 60)
            EVT_CALL(RemoveItemEntity, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMMAND_LOSS_STATE), 3)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackHeavyJump) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_HEAVY_JUMP), 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 36)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(SetBattleCamZoom, 240)
        EVT_CALL(SetBattleCamOffsetZ, 14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 60, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PreJump)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Jump)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_SUB(LVar0, 35)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(2.0))
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostJump)
            EVT_WAIT(3)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(25)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Land)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar1)
    EVT_IF_FLAG(LVar1, ACTOR_EVENT_FLAG_80000)
        EVT_SET(LVar0, 12)
    EVT_ELSE
        EVT_SET(LVar0, 6)
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarF)
    EVT_IF_NOT_FLAG(LVarF, ACTOR_EVENT_FLAG_80000)
        EVT_CALL(func_80269EAC, 24)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVar0, -1)
    EVT_CALL(GetBattleFlags, LVar1)
    EVT_IF_NOT_FLAG(LVar1, BS_FLAGS1_ATK_BLOCKED)
        EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar1)
        EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
            EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_SHRINK)
                EVT_CALL(N(CanPlayerLoseAction), LVar0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(LandJump, ACTOR_SELF)
        EVT_CALL(N(StartRumbleWithParams), 80, 14)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMMAND_LOSS_STATE), 1)
        EVT_EXEC(N(inflictCommandLoss))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 52)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
        EVT_THREAD
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(3.0))
        EVT_END_THREAD
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(2.0))
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostJump)
        EVT_WAIT(3)
        EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_COMMAND_LOSS_STATE), LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT(8)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Walk)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LOST_ABILITY_ITEM), LVar0)
        EVT_CALL(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 30)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
        EVT_WAIT(8)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_LOST_ABILITY_ITEM), LVar0)
        EVT_CALL(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_COMMAND_LOSS_STATE), 2)
        EVT_CALL(PlayEffect, EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.5), 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(2.0), 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F6)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_CALL(PlayEffect, EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.5), 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(2.0), 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F6)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_CALL(PlayEffect, EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.5), 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(2.0), 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F6)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Mock)
        EVT_WAIT(20)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(GetBattleFlags, LVar1)
        EVT_IF_NOT_FLAG(LVar1, BS_FLAGS1_ATK_BLOCKED)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar1)
            EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_STONE)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_SHRINK)
                    EVT_CALL(LandJump, ACTOR_SELF)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(StartRumbleWithParams), 80, 14)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 40)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
        EVT_THREAD
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(3.0))
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostJump)
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_IF_EQ(LVarF, 10)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_SET(LVar1, ANIM_BattleBowser_Walk)
    EVT_EXEC_WAIT(N(returnHome))
    EVT_RETURN
    EVT_END
};

EvtScript N(onAttackMissed) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Tantrum)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_LOOP(4)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
            EVT_WAIT(4)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(attackClawSwipe) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_CLAW_SWIPE), 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(SetBattleCamZoom, 160)
        EVT_CALL(SetBattleCamOffsetZ, 5)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 16, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_RearUpMock)
    EVT_WAIT(25)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Swipe)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35E)
    EVT_WAIT(3)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(onAttackMissed))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_WAIT(30)
            EVT_ELSE
                EVT_WAIT(30)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_SET(LVar0, 12)
        EVT_CALL(func_80269EAC, 12)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, STATUS_FLAG_4 | STATUS_FLAG_20 | STATUS_FLAG_40 | STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_ELSE
        EVT_SET(LVar0, 6)
        EVT_CALL(func_80269EAC, 12)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, STATUS_FLAG_4 | STATUS_FLAG_20 | STATUS_FLAG_40 | STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(attackShockwaveDrain) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_SINCE_LAST_SHOCKWAVE_DRAIN), 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 24)
        EVT_ADD(LVar1, 65)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 420)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 9)
        EVT_ADD(LVar1, 26)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 250)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Brandish)
    EVT_WAIT(10)
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2121)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarF, 0, 0, 0, 0, 0, 0, 0)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarE, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 6)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_LIGHT_RAYS, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarF, 0, 0, 0, 0, 0, 0, 0)
        EVT_SUB(LVar2, 3)
        EVT_CALL(PlayEffect, EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarE, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_WAIT(25)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -45, 60, 0)
    EVT_CALL(SetBattleCamZoom, 530)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 80)
    EVT_WAIT(10)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2122)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 13)
        EVT_SET(LVar1, 55)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_SET(LVar1, 22)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 60, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(UnfadeBackgroundToBlack))
    EVT_END_THREAD
    EVT_WAIT(8)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 1, BS_FLAGS1_10)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
                    EVT_WAIT(30)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_WAIT(2)
                    EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                        EVT_EXEC_WAIT(N(onAttackMissed))
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(2)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_IF_FLAG(LVar0, 0x00040000) // ???
                        EVT_SET(LVar1, 3)
                    EVT_ELSE
                        EVT_SET(LVar1, 3)
                    EVT_END_IF
                    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_CALL(RemovePlayerBuffs, 65536)
                    EVT_IF_NE(LVarA, HIT_RESULT_LUCKY)
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
                    EVT_END_IF
                    EVT_WAIT(30)
                    EVT_RETURN
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(func_8026BF48, 1)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_IF_FLAG(LVar0, 0x00040000) // ???
            EVT_SET(LVar1, 3)
        EVT_ELSE
            EVT_SET(LVar1, 3)
        EVT_END_IF
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_IF_FLAG(LVar0, 0x00040000) // ???
        EVT_SET(LVar1, 4)
    EVT_ELSE
        EVT_SET(LVar1, 4)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(RemovePlayerBuffs, 268435455)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(attackFlameBreath) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 30)
        EVT_ADD(LVar1, 65)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 400)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 30)
        EVT_ADD(LVar1, 45)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 350)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PreFireBreath)
    EVT_WAIT(35)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_FireBreathStill)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 55)
    EVT_WAIT(10)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar3)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar4)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_FLAG(LVar3, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 70)
            EVT_ADD(LVar1, 35)
        EVT_ELSE
            EVT_SUB(LVar0, 28)
            EVT_ADD(LVar1, 14)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 50)
            EVT_ADD(LVar1, 33)
        EVT_ELSE
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 13)
        EVT_END_IF
    EVT_END_IF
    EVT_ADD(LVar2, 10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 20)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar6)
    EVT_IF_FLAG(LVar6, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_CALL(PlayEffect, EFFECT_FIRE_BREATH, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(PlayEffect, EFFECT_FIRE_BREATH, 2, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0, 0, 0)
        EVT_CALL(N(UnkFireBreathFXFunc), LVarF)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(StartRumbleWithParams), 50, 148)
        EVT_CALL(PlaySound, SOUND_3BD)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, SOUND_3BD | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_FireBreathLoop)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(30)
            EVT_EXEC_WAIT(N(onAttackMissed))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, 1, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_SET(LVar0, 16)
    EVT_ELSE
        EVT_SET(LVar0, 8)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, 65535, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_FireBreathLoop)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onBurnHit) = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, 36)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 1)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ENCHANTED, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(func_80269E80, LVar3)
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(9)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar7)
            EVT_SWITCH(LVar7)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
                    EVT_ADD(LVar5, 55)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EVT_END_SWITCH
            EVT_SET(LVar7, 0)
            EVT_LOOP(30)
                EVT_ADD(LVar7, 48)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar7)
            EVT_SWITCH(LVar7)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE)
                EVT_CASE_OR_EQ(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SUB(LVar5, 55)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
                    EVT_IF_EQ(LVar5, 0)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_ELSE
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_IF_NE(LVar2, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetPartEventFlags, ACTOR_SELF, LVar0, LVar1)
            EVT_IF_NOT_FLAG(LVar1, ACTOR_EVENT_FLAG_FIREY | ACTOR_EVENT_FLAG_EXPLOSIVE)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_MULF(LVar3, EVT_FLOAT(0.4))
                    EVT_MULF(LVar4, EVT_FLOAT(0.4))
                EVT_END_IF
                EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                EVT_CALL(GetActorFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, ACTOR_FLAG_HP_OFFSET_BELOW)
                    EVT_SUBF(LVar1, LVar3)
                EVT_ELSE
                    EVT_ADDF(LVar1, LVar3)
                EVT_END_IF
                EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_MULF(LVar3, EVT_FLOAT(0.4))
                    EVT_IF_LT(LVar3, 1)
                        EVT_SETF(LVar3, EVT_FLOAT(1.0))
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
