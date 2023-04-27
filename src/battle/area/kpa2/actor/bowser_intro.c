#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBowser.h"
#include "sprite/npc/ParadePeach.h"
#include "effects.h"
#include "sprite.h"

#define NAMESPACE b_area_kpa2_bowser_intro

enum N(ActorVars) {
    N(VAR_TURN_COUNTER) = 0,
    N(VAR_PEACH_SPOKE) = 1,
};

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);
extern EvtScript N(unkDecorationScript);
extern EvtScript N(makeWalkingSounds);
extern EvtScript N(onHit);
extern EvtScript N(onDeath);
extern EvtScript N(attackClawSwipe);
extern EvtScript N(powerUp);
extern EvtScript N(attackFireBreath);
extern EvtScript N(returnHome);
extern EvtScript N(useStarRod);

s32 N(IdleAnimations)[] = {
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

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(DefenseTable_boosted)[] = {
    ELEMENT_NORMAL, 1,
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

s32 N(StatusTable_boosted)[] = {
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
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -18, 72 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_INTRO_BOWSER,
    .level = 0,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 80, 82 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/UnkFireBreathFXFunc.inc.c"
#include "common/UnkBowserFunc1.inc.c"
#include "common/FadeBackgroundToBlack.inc.c"
#include "common/UnfadeBackgroundToBlack.inc.c"
#include "common/RemoveChillOut.inc.c"
#include "common/StarRodAppearEffect.inc.c"
#include "common/StarRodPowerUpEffect.inc.c"

EvtScript N(init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PEACH_SPOKE), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 14, 0)
    EVT_CALL(SetBattleMenuDisableFlags, BTL_MENU_DISABLED_JUMP)
    EVT_CALL(CreateNpc, 0x00000000, ANIM_ParadePeach_IdleRaisedArms)
    EVT_CALL(SetNpcYaw, 0x00000000, 90)
    EVT_CALL(SetNpcPos, 0x00000000, -130, 0, -12)
    EVT_CALL(EnableNpcShadow, 0x00000000, TRUE)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 1, 100, 0, 0, 0)
    EVT_EXEC(N(unkDecorationScript))
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_DONT_STOP_MUSIC, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
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
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_PEACH_SPOKE), LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_PEACH_SPOKE), 1)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamTarget, -115, 0, 0)
                EVT_CALL(SetBattleCamZoom, 320)
                EVT_CALL(SetBattleCamOffsetZ, 50)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
                EVT_CALL(SpeakToPlayer, ACTOR_PLAYER, ANIM_ParadePeach_Talk, ANIM_ParadePeach_IdleRaisedArms, 5, MSG_Intro_0057)
                EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_Fall)
                EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
                EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.5))
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_JumpForJoy)
                EVT_WAIT(24)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                EVT_WAIT(10)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_WAIT(20)
                EVT_CALL(func_802535B4, 1)
            EVT_END_IF
    EVT_END_SWITCH
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
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET(LVar1, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
            EVT_IF_EQ(LVar0, 3)
                EVT_CALL(ActorSpeak, MSG_Intro_005B, ACTOR_SELF, 1, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Jump)
            EVT_EXEC_WAIT(DoRecover)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostJump)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(EVS_DoNormalHit)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(EVS_DoNormalHit)
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(EVS_DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(3)
            EVT_EXEC_WAIT(N(attackClawSwipe))
        EVT_CASE_EQ(3)
            EVT_EXEC_WAIT(N(powerUp))
            EVT_EXEC_WAIT(N(attackClawSwipe))
        EVT_CASE_EQ(4)
            EVT_EXEC_WAIT(N(attackClawSwipe))
        EVT_CASE_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_WAIT(30)
            EVT_CALL(ActorSpeak, MSG_Intro_005C, ACTOR_SELF, 1, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(N(attackFireBreath))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(attackClawSwipe) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_RearUpMock)
    EVT_WAIT(25)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Swipe)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_35E)
    EVT_WAIT(3)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar1)
    EVT_IF_LT(LVar1, 3)
        EVT_SET(LVar0, 1)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_ELSE
        EVT_SET(LVar0, 3)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
        EVT_IF_GE(LVar0, 3)
            EVT_CALL(SetNpcAnimation, 0x00000000, ANIM_ParadePeach_Weep)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, 0x00000000, ANIM_ParadePeach_HorrorLoop)
        EVT_END_IF
        EVT_WAIT(45)
        EVT_CALL(SetNpcAnimation, 0x00000000, ANIM_ParadePeach_IdleRaisedArms)
    EVT_END_THREAD
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackFireBreath) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_ADD(LVar1, 65)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PreFireBreath)
    EVT_WAIT(35)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_FireBreathStill)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_ADD(LVar1, 33)
    EVT_ADD(LVar2, 10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 20)
    EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 2, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
    EVT_CALL(N(UnkFireBreathFXFunc), LVarF)
    EVT_THREAD
        EVT_CALL(N(StartRumbleWithParams), 50, 148)
        EVT_CALL(PlaySound, SOUND_3BD)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, SOUND_3BD | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, 0x00000000, ANIM_ParadePeach_Weep)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 55)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_FireBreathLoop)
    EVT_WAIT(30)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, 10, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostFireBreath)
                EVT_WAIT(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_END_THREAD
            EVT_WAIT(60)
            EVT_CALL(SetNpcAnimation, 0x00000000, ANIM_ParadePeach_HorrorLoop)
            EVT_LOOP(68)
                EVT_CALL(GetAnimation, ACTOR_PLAYER, 0, LVar0)
                EVT_IF_EQ(LVar0, ANIM_Mario1_FallDown)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, 0x00000000, ANIM_ParadePeach_Bow)
            EVT_WAIT(30)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(powerUp) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(ActorSpeak, MSG_Intro_0058, ACTOR_SELF, 1, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_ADD(LVar1, 65)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_ADD(LVar1, 90)
        EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 30, 30, 7, 30, 0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Brandish)
    EVT_WAIT(30)
    EVT_CALL(ActorSpeak, MSG_Intro_0059, ACTOR_SELF, 1, ANIM_BattleBowser_BrandishTalk, ANIM_BattleBowser_BrandishIdle)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Brandish)
    EVT_EXEC_WAIT(N(useStarRod))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_ADD(LVar1, 65)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(ActorSpeak, MSG_Intro_005A, ACTOR_SELF, 1, ANIM_BattleBowser_RearUpMock, ANIM_BattleBowser_RearUpStill)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_boosted)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_boosted)))
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
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarF, 0)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarE, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarD, 0)
    EVT_ELSE
        EVT_ADD(LVar0, 6)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarF, 0)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarE, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarD, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2121)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarE)
    EVT_CALL(RemoveEffect, LVarD)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ENCHANTED, TRUE)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 1, ACTOR_DECORATION_RADIAL_STAR_EMITTER)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_boosted)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_boosted)))
    EVT_CALL(N(RemoveChillOut))
    EVT_WAIT(3)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 40)
        EVT_ADD(LVar2, 12)
        EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 70, 80, 25, 60, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 16)
        EVT_ADD(LVar2, 12)
        EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 28, 32, 10, 60, 0)
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
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 15, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2124)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_ADD(LVar1, 65)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 32)
    EVT_WAIT(32)
    EVT_RETURN
    EVT_END
};

EvtScript N(jumpHome) = {
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
