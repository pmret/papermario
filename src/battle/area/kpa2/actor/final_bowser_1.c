#include "../area.h"
#include "sprite/npc/BattleBowser.h"

#define NAMESPACE A(final_bowser_1)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_TakeTurn_Inner);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_AnimateImgFX);
extern EvtScript N(EVS_Attack_LightningBlast);
extern EvtScript N(EVS_Attack_FireBreath);
extern EvtScript N(EVS_Attack_ClawSwipe);
extern EvtScript N(EVS_Attack_BodySlam);
extern EvtScript N(EVS_UseAttack);
extern EvtScript N(EVS_UseDrainingShockwave);
extern EvtScript N(EVS_UseAttackOrShockwave);
extern EvtScript N(EVS_StarRodCast);
extern EvtScript N(EVS_ReturnHome);
extern EvtScript N(EVS_Hit);
extern EvtScript N(EVS_Hit_Inner);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_NoDamageHit);
extern EvtScript N(EVS_BurnHit);
extern EvtScript N(EVS_ShockReaction);
extern EvtScript N(EVS_PlayFootstepSounds);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_TurnCount              = 0,
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
    DMG_CLAW_SWIPE              = 8,
    DMG_BOOSTED_CLAW_SWIPE      = 16,
    DMG_BODY_SLAM               = 8,
    DMG_BOOSTED_BODY_SLAM       = 16,
    DMG_FIRE_BREATH             = 10,
    DMG_BOOSTED_FIRE_BREATH     = 20,
    DMG_SHOCKWAVE               = 6,
    DMG_BOOSTED_SHOCKWAVE       = 6,
    DMG_SHOCKWAVE_P             = 3,
    DMG_BOOSTED_SHOCKWAVE_P     = 3,
    DMG_LIGHTNING_BLAST         = 10,
    DMG_BOOSTED_LIGHTNING_BLAST = 20,
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
    ELEMENT_NORMAL,   2,
    ELEMENT_END,
};

s32 N(BoostedDefense)[] = {
    ELEMENT_NORMAL,  99,
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
        .targetOffset = { -27, 108 },
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
    .type = ACTOR_TYPE_FINAL_BOWSER_1,
    .level = ACTOR_LEVEL_FINAL_BOWSER_1,
    .maxHP = 99,
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
    .powerBounceChance = 50,
    .coinReward = 0,
    .size = { 123, 119 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -53, 103 },
    .statusTextOffset = { 33, 92 },
};

#define BOWSER_LARGE
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
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_RecoversLeft, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Idle)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 150, 0, 0, 0)
    EVT_EXEC(N(EVS_AnimateImgFX))
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 0, 150, 150, 0, 0)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_BOWSER_AURA)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_FINAL_BOWSER_PART_1 | BS_FLAGS2_DONT_STOP_MUSIC, TRUE)
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
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 0, 150, 150, 255, 0)
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 150, 0, 0, 0)
        EVT_ELSE
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 0, 60, 60, 255, 0)
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 60, 0, 0, 0)
        EVT_END_IF
        EVT_EXEC_WAIT(N(EVS_PlayFootstepSounds))
        EVT_WAIT(1)
        EVT_GOTO(0)
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
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_BattleBowser_BurnHurt)
            EVT_SET(LVar2, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(EVS_BurnHit))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_BattleBowser_BurnHurt)
            EVT_SET(LVar2, ANIM_BattleBowser_BurnStill)
            EVT_EXEC_WAIT(N(EVS_BurnHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Hit))
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
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
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
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Jump)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
        EVT_CASE_EQ(EVENT_RECEIVE_BUFF)
            EVT_CALL(N(FadeBackgroundLighten))
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_INVUNERABLE_TAUNT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET(LVar3, 60)
                EVT_SET(LVar4, 97)
            EVT_ELSE
                EVT_SET(LVar3, 24)
                EVT_SET(LVar4, 39)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, LVar3)
            EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 20, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpLaugh)
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 15)
            EVT_ADD(LVar1, LVar4)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(SetBattleCamZoom, 420)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_WAIT(30)
            EVT_CALL(ActorSpeak, MSG_CH8_0085, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock, ANIM_BattleBowser_Mock)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_WAIT(20)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(PARTNER_KOOPER)
                    EVT_CALL(ActorSpeak, MSG_CH8_0087, ACTOR_PARTNER, 0, -1, -1)
                EVT_CASE_EQ(PARTNER_BOMBETTE)
                    EVT_CALL(ActorSpeak, MSG_CH8_0088, ACTOR_PARTNER, 0, -1, -1)
                EVT_CASE_EQ(PARTNER_PARAKARRY)
                    EVT_CALL(ActorSpeak, MSG_CH8_0089, ACTOR_PARTNER, 0, -1, -1)
                EVT_CASE_EQ(PARTNER_BOW)
                    EVT_CALL(ActorSpeak, MSG_CH8_008A, ACTOR_PARTNER, 0, -1, -1)
                EVT_CASE_EQ(PARTNER_WATT)
                    EVT_CALL(ActorSpeak, MSG_CH8_008B, ACTOR_PARTNER, 0, -1, -1)
                EVT_CASE_EQ(PARTNER_SUSHIE)
                    EVT_CALL(ActorSpeak, MSG_CH8_008C, ACTOR_PARTNER, 0, -1, -1)
                EVT_CASE_EQ(PARTNER_LAKILESTER)
                    EVT_CALL(ActorSpeak, MSG_CH8_008D, ACTOR_PARTNER, 0, -1, -1)
                EVT_CASE_DEFAULT
                    EVT_CALL(ActorSpeak, MSG_CH8_0086, ACTOR_PARTNER, 0, -1, -1)
            EVT_END_SWITCH
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(GetActorHP, ACTOR_SELF, GB_FinalBowserHP)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, TRUE)
            EVT_CALL(SetEndBattleFadeOutRate, 20)
            EVT_RETURN
        EVT_CASE_EQ(20)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hit) = {
    EVT_EXEC_WAIT(N(EVS_Hit_Inner))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hit_Inner) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
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
    EVT_EXEC_WAIT(N(EVS_TakeTurn_Inner))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_UseStarRod) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_EXEC_WAIT(N(EVS_StarRodCast))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
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
        EVT_ADD(LVar0, 22)
        EVT_ADD(LVar1, 135)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_GATHER)
            EVT_ADD(LVar2, 10)
            EVT_CALL(N(StarRodAppearEffect), LVar0, LVar1, LVar2, EVT_FLOAT(2.5), EVT_FLOAT(0.075))
        EVT_END_THREAD
    EVT_ELSE
        EVT_ADD(LVar0, 9)
        EVT_ADD(LVar1, 54)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_GATHER)
            EVT_ADD(LVar2, 10)
            EVT_CALL(N(StarRodAppearEffect), LVar0, LVar1, LVar2, EVT_FLOAT(2.5), EVT_FLOAT(0.03))
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(65)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 22)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 135, LVar2, EVT_FLOAT(1.5), LVarF, 0)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 135, LVar2, EVT_FLOAT(1.0), LVarE, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 135, LVar2, EVT_FLOAT(1.5), LVarD, 0)
    EVT_ELSE
        EVT_ADD(LVar0, 9)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 54, LVar2, EVT_FLOAT(0.6), LVarF, 0)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 54, LVar2, EVT_FLOAT(0.4), LVarE, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 54, LVar2, EVT_FLOAT(0.6), LVarD, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_USE)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarE)
    EVT_CALL(RemoveEffect, LVarD)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED, TRUE)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 1, ACTOR_DECORATION_RADIAL_STAR_EMITTER)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BoostedDefense)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(BoostedStatusTable)))
    EVT_CALL(N(RemoveChillOut))
    EVT_WAIT(3)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_ADD(LVar2, 12)
        EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 105, 120, 37, 60, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 24)
        EVT_ADD(LVar2, 12)
        EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 42, 48, 15, 60, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_ENCHANT)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(N(StarRodPowerUpEffect), LVar0, LVar1, LVar2, EVT_FLOAT(1.2))
    EVT_END_THREAD
    EVT_WAIT(75)
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundLighten))
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpLaugh)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 60)
    EVT_ELSE
        EVT_ADD(LVar1, 24)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 15, 0)
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
        EVT_ADD(LVar1, 97)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 420)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 6)
        EVT_ADD(LVar1, 39)
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
        EVT_ADD(LVar0, 22)
        EVT_ADD(LVar1, 135)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 50, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 22)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, 135, LVar2, EVT_FLOAT(0.45), 30, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 9)
        EVT_ADD(LVar1, 54)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.6), 50, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 9)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, 54, LVar2, EVT_FLOAT(0.18), 30, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    EVT_MUL(LVar0, 31)
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
            EVT_ADD(LVar1, 90)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(SetBattleCamZoom, 420)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
        EVT_ELSE
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 36)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(SetBattleCamZoom, 420)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
        EVT_END_IF
        EVT_CALL(ActorSpeak, MSG_CH8_0084, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock, ANIM_BattleBowser_Mock)
        EVT_EXEC_WAIT(N(EVS_Move_UseStarRod))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MUL(LVar0, 100)
    EVT_DIV(LVar0, LVar1)
    EVT_CALL(N(GetPlayerHpPercent), LVar2)
    EVT_SUB(LVar2, LVar0)
    EVT_IF_GT(LVar2, 25)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RecoversLeft, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 75)
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
        EVT_IF_NOT_FLAG(LVar0, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, 0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar0, 0)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar0, 15)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar0, 75)
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
        EVT_CALL(RandInt, 30, LVar0)
        EVT_IF_LT(LVar0, 20)
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_LightningBlast))
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
    // ~27% chance to use regardless
    EVT_CALL(RandInt, 110, LVar0)
    EVT_IF_LT(LVar0, 30)
        EVT_IF_LT(LVar0, 20)
            EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_LightningBlast))
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
#include "common/UnkLightningBoltFxFunc1.inc.c"

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
        EVT_CALL(SetBattleCamOffsetZ, 54)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(SetBattleCamZoom, 240)
        EVT_CALL(SetBattleCamOffsetZ, 21)
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
    EVT_IF_FLAG(LVar1, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
        EVT_SET(LVar0, DMG_BOOSTED_BODY_SLAM)
    EVT_ELSE
        EVT_SET(LVar0, DMG_BODY_SLAM)
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarF)
    EVT_IF_NOT_FLAG(LVarF, STATUS_FLAG_SHRINK)
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
        EVT_ADD(LVar1, 38)
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
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.75), 0, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(3.0), 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.75), 0, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(3.0), 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, EVT_FLOAT(0.75), 0, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, EVT_FLOAT(3.0), 0)
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
        EVT_CALL(AddGoalPos, ACTOR_SELF, 60, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 24, 0, 0)
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
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
        EVT_SET(LVar0, DMG_BOOSTED_CLAW_SWIPE)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_ELSE
        EVT_SET(LVar0, DMG_CLAW_SWIPE)
        EVT_CALL(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_IF
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
        EVT_ADD(LVar1, 97)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 420)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 9)
        EVT_ADD(LVar1, 39)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 375)
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
        EVT_ADD(LVar0, 22)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 135, LVar2, EVT_FLOAT(1.0), LVarF, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 135, LVar2, EVT_FLOAT(1.0), LVarE, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 9)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 54, LVar2, EVT_FLOAT(0.4), LVarF, 0)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 54, LVar2, EVT_FLOAT(0.4), LVarE, 0)
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
        EVT_ADD(LVar0, 19)
        EVT_SET(LVar1, 55)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 7)
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
                    // @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
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
        // @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
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
    // @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
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
        EVT_ADD(LVar1, 81)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 400)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 30)
        EVT_ADD(LVar1, 56)
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
    EVT_IF_FLAG(LVar3, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
        EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 70)
            EVT_ADD(LVar1, 35)
        EVT_ELSE
            EVT_SUB(LVar0, 28)
            EVT_ADD(LVar1, 14)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 75)
            EVT_ADD(LVar1, 49)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 19)
        EVT_END_IF
    EVT_END_IF
    EVT_ADD(LVar2, 10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 20)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar6)
    EVT_IF_FLAG(LVar6, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
        EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
    EVT_ELSE
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar7)
        EVT_IF_NOT_FLAG(LVar7, STATUS_FLAG_SHRINK)
            EVT_ADD(LVar0, 15)
        EVT_ELSE
            EVT_ADD(LVar0, 6)
        EVT_END_IF
        EVT_SUB(LVar3, 10)
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
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
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

EvtScript N(EVS_Attack_LightningBlast) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_CHARGE_LIGHTNING)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 54)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 50, 0)
        EVT_WAIT(50)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 22)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 135, LVar2, EVT_FLOAT(1.5), LVarF, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_USE)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 135, LVar2, EVT_FLOAT(1.5), LVarE, 0)
        EVT_WAIT(30)
        EVT_CALL(RemoveEffect, LVarF)
        EVT_CALL(RemoveEffect, LVarE)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 21)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.6), 50, 0)
        EVT_WAIT(50)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 9)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 54, LVar2, EVT_FLOAT(0.6), LVarF, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_USE)
        EVT_SUB(LVar2, 3)
        EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 54, LVar2, EVT_FLOAT(0.6), LVarE, 0)
        EVT_WAIT(30)
        EVT_CALL(RemoveEffect, LVarF)
        EVT_CALL(RemoveEffect, LVarE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_LIGHTNING)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, 0, LVar1)
        EVT_CALL(N(UnkLightningBoltFxFunc1), LVar0, LVar1)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_WAIT(20)
                EVT_CALL(N(FadeBackgroundLighten))
            EVT_ELSE
                EVT_WAIT(20)
                EVT_CALL(N(FadeBackgroundLighten))
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT(5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
        EVT_SET(LVar0, DMG_BOOSTED_LIGHTNING_BLAST)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_ELSE
        EVT_SET(LVar0, DMG_LIGHTNING_BLAST)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_IF
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(30)
            EVT_CALL(N(FadeBackgroundLighten))
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
