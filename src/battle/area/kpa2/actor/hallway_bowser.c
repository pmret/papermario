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
#if VERSION_JP
    ELEMENT_NORMAL,   5,
#else
    ELEMENT_NORMAL,   4,
#endif
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
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, 3)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, 3)
    Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Idle)
    Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_RecoversLeft, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 100, 0, 0, 0)
    Exec(N(EVS_AnimateImgFX))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar3)
    Label(0)
        Call(ActorExists, ACTOR_SELF, LVarB)
        IfEq(LVarB, 0)
            Return
        EndIf
        Call(GetStatusFlags, ACTOR_SELF, LVarB)
        IfNotFlag(LVarB, STATUS_FLAG_SHRINK)
            Call(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 100, 0, 0, 0)
        Else
            Call(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 40, 0, 0, 0)
        EndIf
        ExecWait(N(EVS_PlayFootstepSounds))
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
            IfNotFlag(LVar0, AVAL_Flag_InitialTaunt)
                BitwiseOrConst(LVar0, AVAL_Flag_InitialTaunt)
                Call(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                Call(EnableBattleStatusBar, FALSE)
                Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(UseIdleAnimation, ACTOR_SELF, FALSE)
                Call(ActorSpeak, MSG_CH8_0073, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(EnableBattleStatusBar, TRUE)
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastElement, LVarE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseEq(EVENT_HIT_COMBO)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_Hit))
            Return
        CaseEq(EVENT_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_BasicHit))
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_Hit))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_BattleBowser_BurnHurt)
            Set(LVar2, ANIM_BattleBowser_BurnStill)
            ExecWait(N(EVS_BurnHit))
            Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
            IfNotFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
                Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                IfFlag(LVar0, AVAL_Flag_HasBeenDisenchanted)
                    IfNotFlag(LVar0, AVAL_Flag_CowardTaunt)
                        BitwiseOrConst(LVar0, AVAL_Flag_CowardTaunt)
                        Call(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                        Call(GetStatusFlags, ACTOR_SELF, LVar0)
                        IfNotFlag(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                            Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
                            Call(BattleCamTargetActor, ACTOR_SELF)
                            Call(MoveBattleCamOver, 30)
                            Call(ActorSpeak, MSG_CH8_0077, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_AnnoyedTalk, ANIM_BattleBowser_AnnoyedTalk)
                        EndIf
                    EndIf
                EndIf
            EndIf
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_BattleBowser_BurnHurt)
            Set(LVar2, ANIM_BattleBowser_BurnStill)
            ExecWait(N(EVS_BurnHit))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_BurnStill)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_BasicHit))
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_Hit))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_ShockReaction))
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_ShockReaction))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(GetDamageSource, LVar2)
            Switch(LVar2)
                CaseOrEq(DMG_SRC_SPOOK)
                CaseOrEq(DMG_SRC_FRIGHT_JAR)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock)
                    Wait(30)
                EndCaseGroup
                CaseDefault
                    Set(LVar1, ANIM_BattleBowser_Mock)
                    ExecWait(N(EVS_NoDamageHit))
            EndSwitch
        EndCaseGroup
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_BattleBowser_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_SPIKE_TAUNT)
        CaseEq(EVENT_END_FIRST_STRIKE)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Jump)
            ExecWait(EVS_Enemy_Recover)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_RECEIVE_BUFF)
            Call(N(FadeBackgroundLighten))
        CaseEq(EVENT_STAR_BEAM)
            Call(FreezeBattleCam, TRUE)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 1)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                Set(LVar3, 50)
                Set(LVar4, 40)
            Else
                Set(LVar3, 20)
                Set(LVar4, 16)
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, LVar3)
            PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 50, 0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, LVar4)
            PlayEffect(EFFECT_SHIMMER_BURST, 1, LVar0, LVar1, LVar2, Float(0.7), 30, 0)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ENCHANTED, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, 0)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(NormalDefense)))
            Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_Hit))
            Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
            IfNotFlag(LVar0, AVAL_Flag_StarBeamRemark)
                BitwiseOrConst(LVar0, AVAL_Flag_StarBeamRemark)
                BitwiseOrConst(LVar0, AVAL_Flag_HasBeenDisenchanted)
                Call(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(MoveBattleCamOver, 30)
                Call(ActorSpeak, MSG_CH8_0075, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Hurt, ANIM_BattleBowser_Hurt)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpStill)
                Loop(2)
                    Set(LVar0, 0)
                    Loop(10)
                        Add(LVar0, 18)
                        Call(SetActorYaw, ACTOR_SELF, LVar0)
                        Wait(1)
                    EndLoop
                    Wait(5)
                    Set(LVar0, 180)
                    Loop(10)
                        Sub(LVar0, 18)
                        Call(SetActorYaw, ACTOR_SELF, LVar0)
                        Wait(1)
                    EndLoop
                    Call(SetActorYaw, ACTOR_SELF, 0)
                    Wait(5)
                EndLoop
                Wait(20)
                Call(ActorSpeak, MSG_CH8_0076, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Hurt, ANIM_BattleBowser_Hurt)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EndIf
            Call(FreezeBattleCam, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 30)
            Wait(30)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_BasicHit) = {
    Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
    IfNotFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
        IfFlag(LVar0, AVAL_Flag_HasBeenDisenchanted)
            IfNotFlag(LVar0, AVAL_Flag_CowardTaunt)
                BitwiseOrConst(LVar0, AVAL_Flag_CowardTaunt)
                Call(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                    Call(FreezeBattleCam, TRUE)
                    ExecWait(N(EVS_Hit))
                    Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
                    Call(BattleCamTargetActor, ACTOR_SELF)
                    Call(MoveBattleCamOver, 30)
                    Call(ActorSpeak, MSG_CH8_0077, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_AnnoyedTalk, ANIM_BattleBowser_AnnoyedTalk)
                    Call(FreezeBattleCam, FALSE)
                Else
                    ExecWait(N(EVS_Hit))
                EndIf
                Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                Return
            EndIf
        EndIf
    EndIf
    ExecWait(N(EVS_Hit))
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Hit) = {
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Hit)
    Return
    End
};

EvtScript N(EVS_Death) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    IfNe(LVar1, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Wait(10)
    EndIf
    Call(GetDamageSource, LVar5)
    Switch(LVar5)
        CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_SPIN_SMASH)
        EndCaseGroup
        CaseDefault
            Set(LFlag0, FALSE)
            Call(GetOriginalActorType, ACTOR_SELF, LVar1)
            Switch(LVar1)
                CaseOrEq(ACTOR_TYPE_BOB_OMB)
                CaseOrEq(ACTOR_TYPE_BULLET_BILL)
                CaseOrEq(ACTOR_TYPE_BOMBSHELL_BILL)
                EndCaseGroup
                CaseDefault
            EndSwitch
            IfNe(LVar2, EXEC_DEATH_NO_SPINNING)
                Set(LVar2, 0)
                Loop(24)
                    Call(SetActorYaw, ACTOR_SELF, LVar2)
                    Add(LVar2, 30)
                    Wait(1)
                EndLoop
                Call(SetActorYaw, ACTOR_SELF, 0)
            EndIf
    EndSwitch
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Add(LVar2, 10)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Set(LVar3, 0)
    Loop(12)
        Call(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ExecWait(EVS_ForceNextTarget)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_NoDamageHit) = {
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_NoDamageHit)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    ExecWait(N(EVS_TakeTurn_Inner))
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_UseStarRod) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
    IfNotFlag(LVar0, AVAL_Flag_UsedStarRod)
        BitwiseOrConst(LVar0, AVAL_Flag_UsedStarRod)
        Call(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
        Wait(5)
        Call(ActorSpeak, MSG_CH8_0074, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_BrandishTalk, ANIM_BattleBowser_BrandishIdle)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_BrandishStill)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EndIf
    Wait(2)
    ExecWait(N(EVS_StarRodCast))
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Set(LVar0, PRT_MAIN)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetDist2D, LVar9, LVarA, LVarC, LVarD, LVarF)
    IfGe(LVar9, Float(5.0))
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    EndIf
    IfEq(LVarB, 180)
        Loop(15)
            Sub(LVarB, 12)
            Call(SetActorYaw, ACTOR_SELF, LVarB)
            Wait(1)
        EndLoop
    EndIf
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

EvtScript N(EVS_AnimateImgFX) = {
    Call(N(UpdateEnchantedBowserColors))
    Return
    End
};

EvtScript N(EVS_StarRodCast) = {
    Call(N(FadeBackgroundDarken))
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar0, 15)
        Add(LVar1, 90)
        Thread
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_GATHER)
            Add(LVar2, 10)
            Call(N(StarRodAppearEffect), LVar0, LVar1, LVar2, Float(2.5), Float(0.05))
        EndThread
    Else
        Add(LVar0, 6)
        Add(LVar1, 36)
        Thread
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_GATHER)
            Add(LVar2, 10)
            Call(N(StarRodAppearEffect), LVar0, LVar1, LVar2, Float(2.5), Float(0.02))
        EndThread
    EndIf
    Wait(65)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar0, 15)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, Float(1.0), LVarF, 0)
        PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, Float(1.0), LVarE, 0)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, Float(1.0), LVarD, 0)
    Else
        Add(LVar0, 6)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_LIGHT_RAYS, 2, LVar0, 36, LVar2, Float(0.4), LVarF, 0)
        PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, Float(0.4), LVarE, 0)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, Float(0.4), LVarD, 0)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_USE)
    Wait(30)
    Call(RemoveEffect, LVarF)
    Call(RemoveEffect, LVarE)
    Call(RemoveEffect, LVarD)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ENCHANTED, TRUE)
    Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 1, ACTOR_DECORATION_RADIAL_STAR_EMITTER)
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(BoostedDefense)))
    Call(SetStatusTable, ACTOR_SELF, Ref(N(BoostedStatusTable)))
    Call(N(RemoveChillOut))
    Wait(3)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 40)
        Add(LVar2, 12)
        PlayEffect(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 70, 80, 25, 60, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 16)
        Add(LVar2, 12)
        PlayEffect(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 28, 32, 10, 60, 0)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_ENCHANT)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(N(StarRodPowerUpEffect), LVar0, LVar1, LVar2, Float(0.8))
    EndThread
    Wait(75)
    Thread
        Call(N(FadeBackgroundLighten))
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpLaugh)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 40)
    Else
        Add(LVar1, 16)
    EndIf
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, Float(1.0), 15, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_SHOCKWAVE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 39)
    Wait(30)
    Return
    End
};

EvtScript N(EVS_ShockReaction) = {
    IfNe(LVar1, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    Call(GetActorPos, ACTOR_SELF, LVar5, LVar6, LVar7)
    Set(LVar8, LVar2)
    Add(LVar8, LVar5)
    Div(LVar8, 2)
    Set(LVar9, LVar4)
    Add(LVar9, LVar7)
    Div(LVar9, 2)
    Call(SetGoalPos, ACTOR_SELF, LVar8, 0, LVar9)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Add(LVar8, LVar2)
    Div(LVar8, 2)
    Add(LVar9, LVar4)
    Div(LVar9, 2)
    Call(SetGoalPos, ACTOR_SELF, LVar8, 0, LVar9)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Return
    End
};

EvtScript N(EVS_PlayFootstepSounds) = {
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar7)
    IfNe(LVar7, ANIM_BattleBowser_Walk)
        IfEq(LVar3, ANIM_BattleBowser_Walk)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        EndIf
        Set(LVar3, LVar7)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Return
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar5, LVar6, LVar7)
    Sub(LVar5, LVar0)
    IfGt(LVar5, -30)
        IfLt(LVar5, 30)
            Set(LVar3, LVar7)
            Return
        EndIf
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
    Set(LVar3, LVar7)
    Return
    End
};

EvtScript N(EVS_Recover) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_RecoversLeft, LVar0)
    Sub(LVar0, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_RecoversLeft, LVar0)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 15)
        Add(LVar1, 65)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 420)
        Call(SetBattleCamOffsetY, 0)
        Call(MoveBattleCamOver, 40)
    Else
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 6)
        Add(LVar1, 26)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 294)
        Call(SetBattleCamOffsetY, 0)
        Call(MoveBattleCamOver, 40)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    Call(N(FadeBackgroundDarken))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_CAST_RECOVER)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 90)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, Float(1.0), 50, 0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 5, LVar0, 90, LVar2, Float(0.3), 30, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 6)
        Add(LVar1, 36)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 2, LVar0, LVar1, LVar2, Float(0.4), 50, 0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 6)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 5, LVar0, 36, LVar2, Float(0.12), 30, 0)
    EndIf
    Wait(30)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    Mul(LVar0, 40)
    Div(LVar0, 100)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        Wait(30)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EndThread
    Thread
        Call(FreezeBattleState, TRUE)
        Call(HealActor, ACTOR_SELF, LVar0, FALSE)
        Call(FreezeBattleState, FALSE)
    EndThread
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn_Inner) = {
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnCount, 1)
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, 1)
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, 1)
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 1)
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, 1)
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 1)
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    IfEq(LVar0, 2)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 15)
            Add(LVar1, 60)
            Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
            Call(SetBattleCamDist, 420)
            Call(SetBattleCamOffsetY, 0)
            Call(MoveBattleCamOver, 30)
        Else
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 6)
            Add(LVar1, 24)
            Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
            Call(SetBattleCamDist, 420)
            Call(SetBattleCamOffsetY, 0)
            Call(MoveBattleCamOver, 30)
        EndIf
        ExecWait(N(EVS_Move_UseStarRod))
        Return
    EndIf
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    Mul(LVar0, 100)
    Div(LVar0, LVar1)
    Call(N(GetPlayerHpPercent), LVar2)
    Sub(LVar2, LVar0)
    IfGt(LVar2, 30)
        Call(GetActorVar, ACTOR_SELF, AVAR_RecoversLeft, LVar0)
        IfNe(LVar0, 0)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 80)
                Call(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, LVar0)
                IfGt(LVar0, 1)
                    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 0)
                    ExecWait(N(EVS_Recover))
                    Return
                Else
                    Call(RandInt, 100, LVar0)
                    IfLt(LVar0, 0)
                        Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceRecover, 0)
                        ExecWait(N(EVS_Recover))
                        Return
                    EndIf
                EndIf
            EndIf
        EndIf
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    IfGt(LVar0, 1)
        Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
        IfNotFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
            Call(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceStarBeam, LVar0)
            Switch(LVar0)
                CaseEq(1)
                    Set(LVar0, 0)
                CaseEq(2)
                    Set(LVar0, 20)
                CaseEq(3)
                    Set(LVar0, 30)
                CaseDefault
                    Set(LVar0, 100)
            EndSwitch
            Call(RandInt, 100, LVar1)
            IfLt(LVar1, LVar0)
                ExecWait(N(EVS_Move_UseStarRod))
                Return
            EndIf
        EndIf
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    IfLt(LVar0, 3)
        ExecWait(N(EVS_UseAttack))
        Return
    EndIf
    ExecWait(N(EVS_UseAttackOrShockwave))
    Return
    End
};

EvtScript N(EVS_UseAttackOrShockwave) = {
    // only use regular attacks for the first few turns
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    IfLe(LVar0, 3)
        ExecWait(N(EVS_UseAttack))
        Return
    EndIf
    // use shockwave if it hasn't been used recently
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    IfGe(LVar0, 6)
        Call(RandInt, 20, LVar0)
        IfLt(LVar0, 20)
            ExecWait(N(EVS_UseDrainingShockwave))
        Else
            ExecWait(N(EVS_UseDrainingShockwave))
        EndIf
        Return
    EndIf
    // if either hammer or jump are boosted, try using shockwave
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 75)
        Call(N(GetJumpHammerCharge), LVar0, LVar1)
        IfGt(LVar0, 0)
            ExecWait(N(EVS_UseDrainingShockwave))
            Return
        EndIf
        IfGt(LVar1, 0)
            ExecWait(N(EVS_UseDrainingShockwave))
            Return
        EndIf
    EndIf
    // 20% chance to use regardless
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 20)
        IfLt(LVar0, 20)
            ExecWait(N(EVS_UseDrainingShockwave))
        Else
            ExecWait(N(EVS_UseDrainingShockwave))
        EndIf
        Return
    EndIf
    // fallback to using a regular attack
    ExecWait(N(EVS_UseAttack))
    Return
    Return
    End
};

EvtScript N(EVS_UseAttack) = {
    Call(RandInt, 80, LVar0)
    IfLt(LVar0, 20)
        Call(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, LVar0)
        IfGe(LVar0, 2)
            ExecWait(N(EVS_Attack_BodySlam))
            Return
        EndIf
    EndIf
    Call(RandInt, 60, LVar0)
    IfLt(LVar0, 20)
        Call(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, LVar0)
        IfGe(LVar0, 2)
            ExecWait(N(EVS_Attack_ClawSwipe))
            Return
        EndIf
    EndIf
    ExecWait(N(EVS_Attack_FireBreath))
    Return
    End
};

#include "common/DisableRandomAbility.inc.c"
#include "common/CanPlayerLoseAction.inc.c"
#include "common/SetBowserFireBreathScales.inc.c"

EvtScript N(EVS_ManageCommandLoss) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVarA)
        Switch(LVarA)
            CaseEq(AVAL_LossState_Idle)
                // do nothing
            CaseEq(AVAL_LossState_KnockAway)
                Call(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
                Set(LVar2, 0)
                Sub(LVar3, 1)
                Call(N(DisableRandomAbility), LVar4, LVar5)
                Call(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, LVar0)
                Add(LVar1, 7)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 8, Float(1.0))
                Add(LVar1, 12)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 8, Float(1.0))
                Add(LVar1, 7)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, Float(1.0))
                Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Idle)
            CaseEq(AVAL_LossState_ShowMessage)
                Call(ShowMessageBox, LVar5, 60)
                Call(RemoveItemEntity, LVar0)
                Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Done)
                Return
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Attack_BodySlam) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceBodySlam, 0)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(SetBattleCamDist, 300)
        Call(SetBattleCamOffsetY, 36)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 40)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(SetBattleCamDist, 240)
        Call(SetBattleCamOffsetY, 14)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 40)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 60, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreJump)
    Wait(3)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Jump)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            Thread
                Call(N(StartRumbleWithParams), 80, 14)
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
            EndThread
            Sub(LVar0, 35)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            Thread
                Call(N(StartRumbleWithParams), 80, 14)
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(2.0))
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            Wait(3)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(25)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
    EndThread
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Land)
    Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar1)
    IfFlag(LVar1, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED) /// @bug checks wrong event flag, never uses 12 damage attack
        Set(LVar0, DMG_BOOSTED_BODY_SLAM)
    Else
        Set(LVar0, DMG_BODY_SLAM)
    EndIf
    Call(GetStatusFlags, ACTOR_SELF, LVarF)
    IfNotFlag(LVarF, ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)
        Call(SetDamageSource, DMG_SRC_CRUSH)
    EndIf
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVar0, -1)
    Call(GetBattleFlags, LVar1)
    IfNotFlag(LVar1, BS_FLAGS1_ATK_BLOCKED)
        Call(GetStatusFlags, ACTOR_PLAYER, LVar1)
        IfNotFlag(LVar1, STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
            Call(GetStatusFlags, ACTOR_SELF, LVar1)
            IfNotFlag(LVar1, STATUS_FLAG_SHRINK)
                Call(N(CanPlayerLoseAction), LVar0)
            EndIf
        EndIf
    EndIf
    IfNe(LVar0, -1)
        Call(LandJump, ACTOR_SELF)
        Call(N(StartRumbleWithParams), 80, 14)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
        Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_KnockAway)
        Exec(N(EVS_ManageCommandLoss))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 52)
        Set(LVar1, 0)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
        Thread
            Call(N(StartRumbleWithParams), 80, 14)
            Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
        EndThread
        Add(LVar0, 30)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        Thread
            Call(N(StartRumbleWithParams), 80, 14)
            Call(ShakeCam, CAM_BATTLE, 0, 3, Float(2.0))
        EndThread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
        Wait(3)
        Label(0)
            Call(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVar0)
            IfNe(LVar0, AVAL_LossState_Idle)
                Wait(1)
                Goto(0)
            EndIf
        Wait(8)
        Call(SetActorYaw, ACTOR_SELF, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
        Call(GetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, LVar0)
        Call(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
        Add(LVar1, 30)
        Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
        Call(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        Wait(8)
        Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        Wait(2)
        Call(GetActorVar, ACTOR_SELF, AVAR_CommandLossItemIdx, LVar0)
        Call(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
        Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_ShowMessage)
        PlayEffect(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, Float(0.5), 0, 0)
        PlayEffect(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, Float(2.0), 0)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        Wait(4)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        Wait(2)
        PlayEffect(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, Float(0.5), 0, 0)
        PlayEffect(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, Float(2.0), 0)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        Wait(4)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_StompOnce)
        Wait(2)
        PlayEffect(EFFECT_FIREWORK, 0, LVar1, 0, LVar3, Float(0.5), 0, 0)
        PlayEffect(EFFECT_LANDING_DUST, 1, LVar1, 0, LVar3, Float(2.0), 0)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_C)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock)
        Wait(20)
        Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
    Else
        Call(GetBattleFlags, LVar1)
        IfNotFlag(LVar1, BS_FLAGS1_ATK_BLOCKED)
            Call(GetStatusFlags, ACTOR_PLAYER, LVar1)
            IfNotFlag(LVar1, STATUS_FLAG_STONE)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfNotFlag(LVar1, STATUS_FLAG_SHRINK)
                    Call(LandJump, ACTOR_SELF)
                EndIf
            EndIf
        EndIf
        Call(N(StartRumbleWithParams), 80, 14)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 40)
        Set(LVar1, 0)
        Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
        Thread
            Call(N(StartRumbleWithParams), 80, 14)
            Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
        EndThread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
        Wait(3)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
        Wait(20)
    EndIf
    IfEq(LVarF, 10)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Set(LVar1, ANIM_BattleBowser_Walk)
    ExecWait(N(EVS_ReturnHome))
    Return
    End
};

EvtScript N(EVS_AttackMissed) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Tantrum)
    Thread
        Wait(5)
        Loop(4)
            Call(N(StartRumbleWithParams), 80, 14)
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
            Wait(4)
        EndLoop
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
    EndThread
    Return
    End
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceClawSwipe, 0)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(SetBattleCamDist, 200)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 40)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(SetBattleCamDist, 160)
        Call(SetBattleCamOffsetY, 5)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 40)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    Else
        Call(AddGoalPos, ACTOR_SELF, 16, 0, 0)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock)
    Wait(25)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Swipe)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_SWIPE)
    Wait(3)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            ExecWait(N(EVS_AttackMissed))
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                Wait(30)
            Else
                Wait(30)
            EndIf
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
    IfFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        Set(LVar0, DMG_BOOSTED_CLAW_SWIPE)
        Call(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Else
        Set(LVar0, DMG_CLAW_SWIPE)
        Call(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Wait(30)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UseDrainingShockwave) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 24)
        Add(LVar1, 65)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 420)
        Call(SetBattleCamOffsetY, 0)
        Call(MoveBattleCamOver, 40)
    Else
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 9)
        Add(LVar1, 26)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 250)
        Call(SetBattleCamOffsetY, 0)
        Call(MoveBattleCamOver, 40)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    Wait(10)
    Call(N(FadeBackgroundDarken))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_USE)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, Float(1.0), LVarF, 0)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, Float(1.0), LVarE, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 6)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_LIGHT_RAYS, 2, LVar0, 36, LVar2, Float(0.4), LVarF, 0)
        Sub(LVar2, 3)
        PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, 36, LVar2, Float(0.4), LVarE, 0)
    EndIf
    Wait(25)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, -45, 60, 0)
    Call(SetBattleCamDist, 530)
    Call(SetBattleCamOffsetY, 0)
    Call(MoveBattleCamOver, 80)
    Wait(10)
    Call(RemoveEffect, LVarF)
    Call(RemoveEffect, LVarE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOWSER_STAR_ROD_DRAIN_WAVE)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 13)
        Set(LVar1, 55)
        PlayEffect(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, Float(1.0), 60, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Set(LVar1, 22)
        PlayEffect(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, Float(1.0), 60, 0)
    EndIf
    Thread
        Call(N(FadeBackgroundLighten))
    EndThread
    Wait(8)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            Call(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            Switch(LVarB)
                CaseEq(HIT_RESULT_MISS)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
                    Wait(30)
                    Return
                CaseDefault
                    Wait(2)
                    IfEq(LVarA, HIT_RESULT_LUCKY)
                        ExecWait(N(EVS_AttackMissed))
                        Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EndIf
                    Wait(2)
                    Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    Call(SetGoalToTarget, ACTOR_SELF)
                    /// @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
                    IfFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
                        Set(LVar1, DMG_BOOSTED_SHOCKWAVE_P)
                    Else
                        Set(LVar1, DMG_SHOCKWAVE_P)
                    EndIf
                    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
                    Call(RemovePlayerBuffs, PLAYER_BUFF_PARTNER_GLOWING)
                    IfNe(LVarA, HIT_RESULT_LUCKY)
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
                    EndIf
                    Wait(30)
                    Return
            EndSwitch
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(FreezeBattleState, TRUE)
    Thread
        Wait(4)
        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        Call(SetGoalToTarget, ACTOR_SELF)
        /// @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
        IfFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
            Set(LVar1, DMG_BOOSTED_SHOCKWAVE_P)
        Else
            Set(LVar1, DMG_SHOCKWAVE_P)
        EndIf
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
        Call(FreezeBattleState, FALSE)
    EndThread
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    /// @bug missing a call to GetPartEventFlags, LVar0 is invalid in next block
    IfFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        Set(LVar1, DMG_BOOSTED_SHOCKWAVE)
    Else
        Set(LVar1, DMG_SHOCKWAVE)
    EndIf
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    Call(RemovePlayerBuffs, PLAYER_BUFF_JUMP_CHARGE | PLAYER_BUFF_HAMMER_CHARGE | PLAYER_BUFF_STONE | PLAYER_BUFF_HUSTLE | PLAYER_BUFF_STATIC | PLAYER_BUFF_TRANSPARENT | PLAYER_BUFF_CLOUD_NINE | PLAYER_BUFF_TURBO_CHARGE | PLAYER_BUFF_WATER_BLOCK | PLAYER_BUFF_PARTNER_GLOWING | 0xFFEFC04)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(15)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_FireBreath) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 30)
        Add(LVar1, 65)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 400)
        Call(MoveBattleCamOver, 40)
    Else
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 30)
        Add(LVar1, 45)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 350)
        Call(MoveBattleCamOver, 40)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreFireBreath)
    Wait(35)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathStill)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 55)
    Wait(10)
    Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar3)
    Call(GetStatusFlags, ACTOR_SELF, LVar4)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    IfFlag(LVar3, ACTOR_EVENT_FLAG_ENCHANTED)
        IfNotFlag(LVar4, STATUS_FLAG_SHRINK)
            Sub(LVar0, 70)
            Add(LVar1, 35)
        Else
            Sub(LVar0, 28)
            Add(LVar1, 14)
        EndIf
    Else
        IfNotFlag(LVar4, STATUS_FLAG_SHRINK)
            Sub(LVar0, 50)
            Add(LVar1, 33)
        Else
            Sub(LVar0, 20)
            Add(LVar1, 13)
        EndIf
    EndIf
    Add(LVar2, 10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar3, 40)
    Set(LVar4, 20)
    Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar6)
    IfFlag(LVar6, ACTOR_EVENT_FLAG_ENCHANTED)
        PlayEffect(EFFECT_FIRE_BREATH, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
    Else
        PlayEffect(EFFECT_FIRE_BREATH, 2, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
        Call(N(SetBowserFireBreathScales), LVarF)
    EndIf
    Thread
        Call(N(StartRumbleWithParams), 50, 148)
        Call(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP)
        Wait(70)
        Call(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EndThread
    Wait(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(30)
            ExecWait(N(EVS_AttackMissed))
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetPartEventFlags, ACTOR_SELF, PRT_MAIN, LVar0)
    IfFlag(LVar0, ACTOR_EVENT_FLAG_ENCHANTED)
        Set(LVar0, DMG_BOOSTED_FIRE_BREATH)
    Else
        Set(LVar0, DMG_FIRE_BREATH)
    EndIf
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(30)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_BurnHit) = {
    Call(GetLastEvent, ACTOR_SELF, LVar3)
    IfEq(LVar3, 36)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 1)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ENCHANTED, FALSE)
    EndIf
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetDamageSource, LVar3)
    Switch(LVar3)
        CaseEq(DMG_SRC_FIRE_SHELL)
            Call(GetOriginalActorType, ACTOR_SELF, LVar7)
            Switch(LVar7)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                EndCaseGroup
                CaseDefault
                    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
                    Add(LVar5, 55)
                    Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, FALSE, FALSE)
            EndSwitch
            Set(LVar7, 0)
            Loop(30)
                Add(LVar7, 48)
                Call(SetActorYaw, ACTOR_SELF, LVar7)
                Wait(1)
            EndLoop
            Call(GetOriginalActorType, ACTOR_SELF, LVar7)
            Switch(LVar7)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE)
                CaseOrEq(ACTOR_TYPE_MONTY_MOLE_BOSS)
                    Wait(30)
                EndCaseGroup
                CaseDefault
                    Sub(LVar5, 55)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
                    IfEq(LVar5, 0)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    Else
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
                        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
                    EndIf
            EndSwitch
        CaseDefault
            Wait(20)
    EndSwitch
    IfNe(LVar2, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar2)
    EndIf
    Wait(10)
    Call(GetLastEvent, ACTOR_SELF, LVar1)
    Switch(LVar1)
        CaseEq(EVENT_BURN_HIT)
            Call(GetPartEventFlags, ACTOR_SELF, LVar0, LVar1)
            IfNotFlag(LVar1, ACTOR_EVENT_FLAG_FIREY | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                Call(GetStatusFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, STATUS_FLAG_SHRINK)
                    MulF(LVar3, Float(0.4))
                    MulF(LVar4, Float(0.4))
                EndIf
                DivF(LVar3, Float(2.0))
                Call(GetActorFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, ACTOR_FLAG_UPSIDE_DOWN)
                    SubF(LVar1, LVar3)
                Else
                    AddF(LVar1, LVar3)
                EndIf
                AddF(LVar2, Float(5.0))
                DivF(LVar3, Float(10.0))
                Call(GetStatusFlags, ACTOR_SELF, LVar5)
                IfFlag(LVar5, STATUS_FLAG_SHRINK)
                    MulF(LVar3, Float(0.4))
                    IfLt(LVar3, 1)
                        SetF(LVar3, Float(1.0))
                    EndIf
                EndIf
                PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            // do nothing
    EndSwitch
    Return
    End
};
