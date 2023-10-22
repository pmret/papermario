#include "../area.h"
#include "sprite.h"
#include "sprite/npc/BattleBowser.h"
#include "sprite/npc/ParadePeach.h"
#include "sprite/player.h"

#define NAMESPACE A(intro_bowser)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_AnimateImgFX);
extern EvtScript N(EVS_PlayFootstepSounds);
extern EvtScript N(EVS_OnHit);
extern EvtScript N(EVS_OnDeath);
extern EvtScript N(EVS_ReturnHome);
extern EvtScript N(EVS_Attack_ClawSwipe);
extern EvtScript N(EVS_Attack_FireBreath);
extern EvtScript N(EVS_UseStarRod);
extern EvtScript N(EVS_StarRodCast);


enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_TurnCount      = 0,
    AVAR_PeachSpoke     = 1,
    AVAR_Unused         = 14,
};

enum N(ActorParams) {
    DMG_CLAW_SWIPE          = 1,
    DMG_MEGA_CLAW_SWIPE     = 3,
    DMG_FIRE_BREATH         = 10,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBowser_Idle,
    STATUS_KEY_STONE,     ANIM_BattleBowser_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBowser_Idle,
    STATUS_KEY_POISON,    ANIM_BattleBowser_Idle,
    STATUS_KEY_STOP,      ANIM_BattleBowser_Still,
    STATUS_KEY_STATIC,    ANIM_BattleBowser_Still,
    STATUS_KEY_PARALYZE,  ANIM_BattleBowser_Still,
    STATUS_KEY_PARALYZE,  ANIM_BattleBowser_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleBowser_Idle,
    STATUS_KEY_DIZZY,     ANIM_BattleBowser_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(BoostedDefense)[] = {
    ELEMENT_NORMAL,   1,
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

s32 N(BoostedStatusTable)[] = {
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -18, 72 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_INTRO_BOWSER,
    .level = ACTOR_LEVEL_INTRO_BOWSER,
    .maxHP = 10,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 80, 82 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/SetBowserFireBreathScales.inc.c"
#include "common/UpdateEnchantedBowserColors.inc.c"
#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"
#include "common/RemoveChillOut.inc.c"
#include "common/StarRodAppearEffect.inc.c"
#include "common/StarRodPowerUpEffect.inc.c"

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_PeachSpoke, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    EVT_CALL(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_JUMP)
    EVT_CALL(CreateNpc, NPC_BTL_COMPANION, ANIM_ParadePeach_IdleRaisedArms)
    EVT_CALL(SetNpcYaw, NPC_BTL_COMPANION, 90)
    EVT_CALL(SetNpcPos, NPC_BTL_COMPANION, -130, 0, -12)
    EVT_CALL(EnableNpcShadow, NPC_BTL_COMPANION, TRUE)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 100, 0, 0, 0)
    EVT_EXEC(N(EVS_AnimateImgFX))
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_DONT_STOP_MUSIC, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
        EVT_EXEC_WAIT(N(EVS_PlayFootstepSounds))
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PeachSpoke, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_PeachSpoke, TRUE)
                EVT_CALL(EnableBattleStatusBar, FALSE)
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
                EVT_CALL(EnableBattleStatusBar, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
            EVT_IF_EQ(LVar0, 3)
                EVT_CALL(ActorSpeak, MSG_Intro_005B, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Jump)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnHit) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnDeath) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(3)
            EVT_EXEC_WAIT(N(EVS_Attack_ClawSwipe))
        EVT_CASE_EQ(3)
            EVT_EXEC_WAIT(N(EVS_UseStarRod))
            EVT_EXEC_WAIT(N(EVS_Attack_ClawSwipe))
        EVT_CASE_EQ(4)
            EVT_EXEC_WAIT(N(EVS_Attack_ClawSwipe))
        EVT_CASE_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_WAIT(30)
            EVT_CALL(ActorSpeak, MSG_Intro_005C, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(N(EVS_Attack_FireBreath))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock)
    EVT_WAIT(25)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Swipe)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_SWIPE)
    EVT_WAIT(3)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar1)
    EVT_IF_LT(LVar1, 3)
        EVT_SET(LVar0, DMG_CLAW_SWIPE)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_ELSE
        EVT_SET(LVar0, DMG_MEGA_CLAW_SWIPE)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
        EVT_IF_GE(LVar0, 3)
            EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_Weep)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_HorrorLoop)
        EVT_END_IF
        EVT_WAIT(45)
        EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_IdleRaisedArms)
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
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_FireBreath) = {
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreFireBreath)
    EVT_WAIT(35)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathStill)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_ADD(LVar1, 33)
    EVT_ADD(LVar2, 10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 20)
    EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 2, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24)
    EVT_CALL(N(SetBowserFireBreathScales), LVarF)
    EVT_THREAD
        EVT_CALL(N(StartRumbleWithParams), 50, 148)
        EVT_CALL(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_Weep)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 55)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
    EVT_WAIT(30)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, DMG_FIRE_BREATH, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
                EVT_WAIT(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_END_THREAD
            EVT_WAIT(60)
            EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_HorrorLoop)
            EVT_LOOP(68)
                EVT_CALL(GetAnimation, ACTOR_PLAYER, 0, LVar0)
                EVT_IF_EQ(LVar0, ANIM_Mario1_FallDown)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_Bow)
            EVT_WAIT(30)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseStarRod) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(ActorSpeak, MSG_Intro_0058, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_WAIT(30)
    EVT_CALL(ActorSpeak, MSG_Intro_0059, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_BrandishTalk, ANIM_BattleBowser_BrandishIdle)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_EXEC_WAIT(N(EVS_StarRodCast))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_ADD(LVar1, 65)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(ActorSpeak, MSG_Intro_005A, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock, ANIM_BattleBowser_RearUpStill)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BoostedDefense)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(BoostedStatusTable)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_SET(LVar0, PRT_MAIN)
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

EvtScript N(EVS_AnimateImgFX) = {
    EVT_CALL(N(UpdateEnchantedBowserColors))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StarRodCast) = {
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 90)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_GATHER)
            EVT_ADD(LVar2, 10)
            EVT_CALL(N(StarRodAppearEffect), LVar0, LVar1, LVar2, EVT_FLOAT(2.5), EVT_FLOAT(0.05))
        EVT_END_THREAD
    EVT_ELSE
        EVT_ADD(LVar0, 6)
        EVT_ADD(LVar1, 36)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_GATHER)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_USE)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarE)
    EVT_CALL(RemoveEffect, LVarD)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ENCHANTED, TRUE)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 1, ACTOR_DECORATION_RADIAL_STAR_EMITTER)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BoostedDefense)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(BoostedStatusTable)))
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_ENCHANT)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(N(StarRodPowerUpEffect), LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_END_THREAD
    EVT_WAIT(75)
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundLighten))
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpLaugh)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 40)
    EVT_ELSE
        EVT_ADD(LVar1, 16)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 15, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_SHOCKWAVE)
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

EvtScript N(EVS_ShockReaction) = {
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

EvtScript N(EVS_PlayFootstepSounds) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar7)
    EVT_IF_NE(LVar7, ANIM_BattleBowser_Walk)
        EVT_IF_EQ(LVar3, ANIM_BattleBowser_Walk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
    EVT_SET(LVar3, LVar7)
    EVT_RETURN
    EVT_END
};
