#include "../area.h"
#include "sprite/npc/BattleBowser.h"

#define NAMESPACE A(hallway_bowser)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_TakeTurn_Inner);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_AnimateImgFX);
extern EvtScript N(EVS_Attack_FireBreath);
extern EvtScript N(EVS_Attack_ClawSwipe);
extern EvtScript N(EVS_Attack_BodySlam);
extern EvtScript N(EVS_UseAttack);
extern EvtScript N(EVS_UseDrainingShockwave);
extern EvtScript N(EVS_UseAttackOrShockwave);
extern EvtScript N(EVS_StarRodCast);
extern EvtScript N(EVS_Hit);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_NoDamageHit);
extern EvtScript N(EVS_BasicHit);
extern EvtScript N(EVS_BurnHit);
extern EvtScript N(EVS_ShockReaction);
extern EvtScript N(EVS_ReturnHome);
extern EvtScript N(EVS_PlayFootstepSounds);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_TurnCount              = 0,
    AVAR_Flags                  = 1,
    AVAL_Flag_InitialTaunt          = 0x01,
    AVAL_Flag_StarBeamRemark        = 0x02,
    AVAL_Flag_HasBeenDisenchanted   = 0x04,
    AVAL_Flag_CowardTaunt           = 0x08,
    AVAL_Flag_UsedStarRod           = 0x40,
    AVAR_TurnsSinceShockwave    = 2,
    AVAR_TurnsSinceStarBeam     = 3,
    AVAR_TurnsSinceClawSwipe    = 4,
    AVAR_TurnsSinceBodySlam     = 5,
    AVAR_TurnsSinceRecover      = 6,
    AVAR_RecoversLeft           = 7,
    AVAR_CommandLossState       = 9,
    AVAL_LossState_Idle             = 0,
    AVAL_LossState_KnockAway        = 1,
    AVAL_LossState_ShowMessage      = 2,
    AVAL_LossState_Done             = 3,
    AVAR_CommandLossItemIdx     = 10,
    AVAR_Unused                 = 14,
};

enum N(ActorParams) {
    DMG_CLAW_SWIPE              = 6,
    DMG_BOOSTED_CLAW_SWIPE      = 12,
    DMG_BODY_SLAM               = 6,
    DMG_BOOSTED_BODY_SLAM       = 12,
    DMG_FIRE_BREATH             = 8,
    DMG_BOOSTED_FIRE_BREATH     = 16,
    DMG_SHOCKWAVE               = 4,
    DMG_BOOSTED_SHOCKWAVE       = 4,
    DMG_SHOCKWAVE_P             = 3,
    DMG_BOOSTED_SHOCKWAVE_P     = 3,
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

s32 N(NormalDefense)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(BoostedDefense)[] = {
    ELEMENT_NORMAL,   4,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               30,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
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
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
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
        .defenseTable = N(NormalDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HALLWAY_BOWSER,
    .level = ACTOR_LEVEL_HALLWAY_BOWSER,
    .maxHP = 50,
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
    .powerBounceChance = 65,
    .coinReward = 0,
    .size = { 80, 82 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -40, 67 },
    .statusTextOffset = { 10, 60 },
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/UpdateEnchantedBowserColors.inc.c"
#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"
#include "common/RemoveChillOut.inc.c"
#include "common/StarRodAppearEffect.inc.c"
#include "common/StarRodPowerUpEffect.inc.c"
#include "common/GetJumpHammerCharge.inc.c"
#include "common/GetPlayerHpPercent.inc.c"
#include "common/ItemEntityJumpToPos.inc.c"
#include "common/GetItemEntityPosition.inc.c"

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Idle)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_RecoversLeft, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 100, 0, 0, 0)
    EVT_EXEC(N(EVS_AnimateImgFX))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar3)
    EVT_LABEL(0)
        EVT_CALL(ActorExists, ACTOR_SELF, LVarB)
        EVT_IF_EQ(LVarB, 0)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarB)
        EVT_IF_NOT_FLAG(LVarB, STATUS_FLAG_SHRINK)
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 100, 0, 0, 0)
        EVT_ELSE
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 40, 0, 0, 0)
        EVT_END_IF
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
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_InitialTaunt)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_InitialTaunt)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                EVT_CALL(EnableBattleStatusBar, FALSE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
                EVT_CALL(ActorSpeak, MSG_CH8_0073, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(EnableBattleStatusBar, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
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
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_BasicHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_BattleBowser_BurnHurt)
            EVT_SET(LVar2, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(EVS_BurnHit))
            EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
            EVT_IF_NOT_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                EVT_IF_FLAG(LVar0, AVAL_Flag_HasBeenDisenchanted)
                    EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_CowardTaunt)
                        EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_CowardTaunt)
                        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                            EVT_CALL(MoveBattleCamOver, 30)
                            EVT_CALL(ActorSpeak, MSG_CH8_0077, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_AnnoyedTalk, ANIM_BattleBowser_AnnoyedTalk)
                        EVT_END_IF
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_BattleBowser_BurnHurt)
            EVT_SET(LVar2, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(EVS_BurnHit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_BasicHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_ShockReaction))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_ShockReaction))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetDamageSource, LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_OR_EQ(DMG_SRC_SPOOK)
                EVT_CASE_OR_EQ(DMG_SRC_FRIGHT_JAR)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_BattleBowser_Mock)
                    EVT_EXEC_WAIT(N(EVS_NoDamageHit))
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
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
        EVT_CASE_EQ(EVENT_RECEIVE_BUFF)
            EVT_CALL(N(FadeBackgroundLighten))
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(FreezeBattleCam, TRUE)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 1)
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
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 50, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, LVar4)
            EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30, 0)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ENCHANTED, FALSE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, 0)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(NormalDefense)))
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_StarBeamRemark)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_StarBeamRemark)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_HasBeenDisenchanted)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_CALL(ActorSpeak, MSG_CH8_0075, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Hurt, ANIM_BattleBowser_Hurt)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpStill)
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
                EVT_CALL(ActorSpeak, MSG_CH8_0076, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Hurt, ANIM_BattleBowser_Hurt)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_END_IF
            EVT_CALL(FreezeBattleCam, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_WAIT(30)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BasicHit) = {
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
        EVT_IF_FLAG(LVar0, AVAL_Flag_HasBeenDisenchanted)
            EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_CowardTaunt)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_CowardTaunt)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                    EVT_CALL(FreezeBattleCam, TRUE)
                    EVT_EXEC_WAIT(N(EVS_Hit))
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                    EVT_CALL(MoveBattleCamOver, 30)
                    EVT_CALL(ActorSpeak, MSG_CH8_0077, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_AnnoyedTalk, ANIM_BattleBowser_AnnoyedTalk)
                    EVT_CALL(FreezeBattleCam, FALSE)
                EVT_ELSE
                    EVT_EXEC_WAIT(N(EVS_Hit))
                EVT_END_IF
                EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Hit))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hit) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_IF_NE(LVar1, -1)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(GetDamageSource, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar1)
            EVT_SWITCH(LVar1)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOB_OMB)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BULLET_BILL)
                EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BILL)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
            EVT_IF_NE(LVar2, EXEC_DEATH_NO_SPINNING)
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
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NoDamageHit) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_EXEC_WAIT(N(EVS_TakeTurn_Inner))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_UseStarRod) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_UsedStarRod)
        EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_UsedStarRod)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
        EVT_WAIT(5)
        EVT_CALL(ActorSpeak, MSG_CH8_0074, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_BrandishTalk, ANIM_BattleBowser_BrandishIdle)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_BrandishStill)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_EXEC_WAIT(N(EVS_StarRodCast))
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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 39)
    EVT_WAIT(30)
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

EvtScript N(EVS_Recover) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RecoversLeft, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_RecoversLeft, LVar0)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_CAST_RECOVER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 90)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 50, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, 90, LVar2, EVT_FLOAT(0.3), 30, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 6)
        EVT_ADD(LVar1, 36)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.4), 50, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 6)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, 36, LVar2, EVT_FLOAT(0.12), 30, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    EVT_MUL(LVar0, 40)
    EVT_DIV(LVar0, 100)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(HealActor, ACTOR_SELF, LVar0, FALSE)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn_Inner) = {
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnCount, 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
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
        EVT_EXEC_WAIT(N(EVS_Move_UseStarRod))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MUL(LVar0, 100)
    EVT_DIV(LVar0, LVar1)
    EVT_CALL(N(GetPlayerHpPercent), LVar2)
    EVT_SUB(LVar2, LVar0)
    EVT_IF_GT(LVar2, 30)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RecoversLeft, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 80)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, LVar0)
                EVT_IF_GT(LVar0, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 0)
                    EVT_EXEC_WAIT(N(EVS_Recover))
                    EVT_RETURN
                EVT_ELSE
                    EVT_CALL(RandInt, 100, LVar0)
                    EVT_IF_LT(LVar0, 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 0)
                        EVT_EXEC_WAIT(N(EVS_Recover))
                        EVT_RETURN
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    EVT_IF_GT(LVar0, 1)
        EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
        EVT_IF_NOT_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, LVar0)
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
                EVT_EXEC_WAIT(N(EVS_Move_UseStarRod))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    EVT_IF_LT(LVar0, 3)
        EVT_EXEC_WAIT(N(EVS_UseAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_UseAttackOrShockwave))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseAttackOrShockwave) = {
    // only use regular attacks for the first few turns
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    EVT_IF_LE(LVar0, 3)
        EVT_EXEC_WAIT(N(EVS_UseAttack))
        EVT_RETURN
    EVT_END_IF
    // use shockwave if it hasn't been used recently
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    EVT_IF_GE(LVar0, 6)
        EVT_CALL(RandInt, 20, LVar0)
        EVT_IF_LT(LVar0, 20)
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    // if either hammer or jump are boosted, try using shockwave
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 75)
        EVT_CALL(N(GetJumpHammerCharge), LVar0, LVar1)
        EVT_IF_GT(LVar0, 0)
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
            EVT_RETURN
        EVT_END_IF
        EVT_IF_GT(LVar1, 0)
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    // 20% chance to use regardless
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 20)
        EVT_IF_LT(LVar0, 20)
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    // fallback to using a regular attack
    EVT_EXEC_WAIT(N(EVS_UseAttack))
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseAttack) = {
    EVT_CALL(RandInt, 80, LVar0)
    EVT_IF_LT(LVar0, 20)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, LVar0)
        EVT_IF_GE(LVar0, 2)
            EVT_EXEC_WAIT(N(EVS_Attack_BodySlam))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RandInt, 60, LVar0)
    EVT_IF_LT(LVar0, 20)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, LVar0)
        EVT_IF_GE(LVar0, 2)
            EVT_EXEC_WAIT(N(EVS_Attack_ClawSwipe))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Attack_FireBreath))
    EVT_RETURN
    EVT_END
};

#include "common/DisableRandomAbility.inc.c"
#include "common/CanPlayerLoseAction.inc.c"
#include "common/SetBowserFireBreathScales.inc.c"

EvtScript N(EVS_ManageCommandLoss) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVarA)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(AVAL_LossState_Idle)
                // do nothing
            EVT_CASE_EQ(AVAL_LossState_KnockAway)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
                EVT_SET(LVar2, 0)
                EVT_SUB(LVar3, 1)
                EVT_CALL(N(DisableRandomAbility), LVar4, LVar5)
                EVT_CALL(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, LVar0)
                EVT_ADD(LVar1, 7)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 8, EVT_FLOAT(1.0))
                EVT_ADD(LVar1, 12)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 8, EVT_FLOAT(1.0))
                EVT_ADD(LVar1, 7)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, EVT_FLOAT(1.0))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Idle)
            EVT_CASE_EQ(AVAL_LossState_ShowMessage)
                EVT_CALL(ShowMessageBox, LVar5, 60)
                EVT_CALL(RemoveItemEntity, LVar0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Done)
                EVT_RETURN
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_BodySlam) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 36)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(SetBattleCamZoom, 240)
        EVT_CALL(SetBattleCamOffsetZ, 14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 60, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreJump)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Jump)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_SUB(LVar0, 35)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(2.0))
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            EVT_WAIT(3)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(25)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Land)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar1)
    EVT_IF_FLAG(LVar1, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED) /// @bug checks wrong event flag, never uses 12 damage attack
        EVT_SET(LVar0, DMG_BOOSTED_BODY_SLAM)
    EVT_ELSE
        EVT_SET(LVar0, DMG_BODY_SLAM)
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarF)
    EVT_IF_NOT_FLAG(LVarF, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
        EVT_CALL(SetDamageSource, DMG_SRC_CRUSH)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
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
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_KnockAway)
        EVT_EXEC(N(EVS_ManageCommandLoss))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 52)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
        EVT_THREAD
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
        EVT_END_THREAD
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(2.0))
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
        EVT_WAIT(3)
        EVT_LABEL(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVar0)
            EVT_IF_NE(LVar0, AVAL_LossState_Idle)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_WAIT(8)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, LVar0)
        EVT_CALL(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 30)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        EVT_WAIT(8)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, LVar0)
        EVT_CALL(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_ShowMessage)
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.5), 0, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(2.0), 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.5), 0, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(2.0), 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.5), 0, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(2.0), 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock)
        EVT_WAIT(20)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
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
        EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
        EVT_THREAD
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_IF_EQ(LVarF, 10)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_SET(LVar1, ANIM_BattleBowser_Walk)
    EVT_EXEC_WAIT(N(EVS_ReturnHome))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AttackMissed) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Tantrum)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_LOOP(4)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
            EVT_WAIT(4)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(SetBattleCamZoom, 160)
        EVT_CALL(SetBattleCamOffsetZ, 5)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 16, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock)
    EVT_WAIT(25)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Swipe)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_SWIPE)
    EVT_WAIT(3)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(EVS_AttackMissed))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_WAIT(30)
            EVT_ELSE
                EVT_WAIT(30)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_SET(LVar0, DMG_BOOSTED_CLAW_SWIPE)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_ELSE
        EVT_SET(LVar0, DMG_CLAW_SWIPE)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseDrainingShockwave) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_WAIT(10)
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_USE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarF, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarE, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 6)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarF, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, EVT_FLOAT(0.4), LVarE, 0)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_DRAIN_WAVE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 13)
        EVT_SET(LVar1, 55)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_SET(LVar1, 22)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundLighten))
    EVT_END_THREAD
    EVT_WAIT(8)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
                    EVT_WAIT(30)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_WAIT(2)
                    EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                        EVT_EXEC_WAIT(N(EVS_AttackMissed))
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(2)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    /// @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
                    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
                        EVT_SET(LVar1, DMG_BOOSTED_SHOCKWAVE_P)
                    EVT_ELSE
                        EVT_SET(LVar1, DMG_SHOCKWAVE_P)
                    EVT_END_IF
                    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
                    EVT_CALL(RemovePlayerBuffs, PLAYER_BUFF_PARTNER_GLOWING)
                    EVT_IF_NE(LVarA, HIT_RESULT_LUCKY)
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
                    EVT_END_IF
                    EVT_WAIT(30)
                    EVT_RETURN
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(FreezeBattleState, TRUE)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        /// @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
        EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
            EVT_SET(LVar1, DMG_BOOSTED_SHOCKWAVE_P)
        EVT_ELSE
            EVT_SET(LVar1, DMG_SHOCKWAVE_P)
        EVT_END_IF
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    /// @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_SET(LVar1, DMG_BOOSTED_SHOCKWAVE)
    EVT_ELSE
        EVT_SET(LVar1, DMG_SHOCKWAVE)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(RemovePlayerBuffs, PLAYER_BUFF_JUMP_CHARGE | PLAYER_BUFF_HAMMER_CHARGE | PLAYER_BUFF_STONE | PLAYER_BUFF_HUSTLE | PLAYER_BUFF_STATIC | PLAYER_BUFF_TRANSPARENT | PLAYER_BUFF_CLOUD_NINE | PLAYER_BUFF_TURBO_CHARGE | PLAYER_BUFF_WATER_BLOCK | PLAYER_BUFF_PARTNER_GLOWING | 0xFFEFC04)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_FireBreath) = {
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreFireBreath)
    EVT_WAIT(35)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathStill)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 55)
    EVT_WAIT(10)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar3)
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
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar6)
    EVT_IF_FLAG(LVar6, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
    EVT_ELSE
        EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 2, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
        EVT_CALL(N(SetBowserFireBreathScales), LVarF)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(StartRumbleWithParams), 50, 148)
        EVT_CALL(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(30)
            EVT_EXEC_WAIT(N(EVS_AttackMissed))
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
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        EVT_SET(LVar0, DMG_BOOSTED_FIRE_BREATH)
    EVT_ELSE
        EVT_SET(LVar0, DMG_FIRE_BREATH)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BurnHit) = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, 36)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 1)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ENCHANTED, FALSE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetDamageSource, LVar3)
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(DMG_SRC_FIRE_SHELL)
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
            EVT_IF_NOT_FLAG(LVar1, ACTOR_EVENT_FLAG_FIREY | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_MULF(LVar3, EVT_FLOAT(0.4))
                    EVT_MULF(LVar4, EVT_FLOAT(0.4))
                EVT_END_IF
                EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                EVT_CALL(GetActorFlags, ACTOR_SELF, LVar5)
                EVT_IF_FLAG(LVar5, ACTOR_FLAG_UPSIDE_DOWN)
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
                EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            // do nothing
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
