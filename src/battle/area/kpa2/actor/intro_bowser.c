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
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_PeachSpoke, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    Call(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_JUMP)
    Call(CreateNpc, NPC_BTL_COMPANION, ANIM_ParadePeach_IdleRaisedArms)
    Call(SetNpcYaw, NPC_BTL_COMPANION, 90)
    Call(SetNpcPos, NPC_BTL_COMPANION, -130, 0, -12)
    Call(EnableNpcShadow, NPC_BTL_COMPANION, TRUE)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 1, 100, 0, 0, 0)
    Exec(N(EVS_AnimateImgFX))
    Call(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    Call(SetBattleFlagBits2, BS_FLAGS2_DONT_STOP_MUSIC, TRUE)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Label(0)
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
            Call(GetActorVar, ACTOR_SELF, AVAR_PeachSpoke, LVar0)
            IfEq(LVar0, FALSE)
                Call(SetActorVar, ACTOR_SELF, AVAR_PeachSpoke, TRUE)
                Call(EnableBattleStatusBar, FALSE)
                Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                Call(SetBattleCamTarget, -115, 0, 0)
                Call(SetBattleCamDist, 320)
                Call(SetBattleCamOffsetY, 50)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                Call(SetActorYaw, ACTOR_PLAYER, 180)
                Call(SpeakToPlayer, ACTOR_PLAYER, ANIM_ParadePeach_Talk, ANIM_ParadePeach_IdleRaisedArms, 5, MSG_Intro_0057)
                Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_Fall)
                Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
                Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.5))
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_JumpForJoy)
                Wait(24)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                Wait(10)
                Call(SetActorYaw, ACTOR_PLAYER, 0)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Wait(20)
                Call(EnableBattleStatusBar, TRUE)
            EndIf
    EndSwitch
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
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnHit))
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnHit))
        CaseOrEq(EVENT_BURN_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnHit))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_BattleBowser_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
            IfEq(LVar0, 3)
                Call(ActorSpeak, MSG_Intro_005B, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
        CaseEq(EVENT_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
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
        CaseDefault
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            Wait(20)
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_OnHit) = {
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Hit)
    Return
    End
};

EvtScript N(EVS_OnDeath) = {
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Hit)
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    Switch(LVar0)
        CaseLt(3)
            ExecWait(N(EVS_Attack_ClawSwipe))
        CaseEq(3)
            ExecWait(N(EVS_UseStarRod))
            ExecWait(N(EVS_Attack_ClawSwipe))
        CaseEq(4)
            ExecWait(N(EVS_Attack_ClawSwipe))
        CaseEq(5)
            Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(MoveBattleCamOver, 30)
            Wait(30)
            Call(ActorSpeak, MSG_Intro_005C, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
            ExecWait(N(EVS_Attack_FireBreath))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamDist, 200)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock)
    Wait(25)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Swipe)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_SWIPE)
    Wait(3)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar1)
    IfLt(LVar1, 3)
        Set(LVar0, DMG_CLAW_SWIPE)
        Call(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Else
        Set(LVar0, DMG_MEGA_CLAW_SWIPE)
        Call(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
        Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Thread
        Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
        IfGe(LVar0, 3)
            Call(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_Weep)
        Else
            Call(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_HorrorLoop)
        EndIf
        Wait(45)
        Call(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_IdleRaisedArms)
    EndThread
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Wait(30)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_FireBreath) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 30)
    Add(LVar1, 65)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 400)
    Call(SetBattleCamOffsetY, 0)
    Call(MoveBattleCamOver, 40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreFireBreath)
    Wait(35)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathStill)
    Wait(10)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 50)
    Add(LVar1, 33)
    Add(LVar2, 10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar3, 40)
    Set(LVar4, 20)
    PlayEffect(EFFECT_FIRE_BREATH, 2, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24)
    Call(N(SetBowserFireBreathScales), LVarF)
    Thread
        Call(N(StartRumbleWithParams), 50, 148)
        Call(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP)
        Wait(70)
        Call(PlaySound, SOUND_BOWSER_FIRE_BREATH_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EndThread
    Call(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_Weep)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 55)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
    Wait(30)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, DMG_FIRE_BREATH, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Thread
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
                Wait(15)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EndThread
            Wait(60)
            Call(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_HorrorLoop)
            Loop(68)
                Call(GetAnimation, ACTOR_PLAYER, 0, LVar0)
                IfEq(LVar0, ANIM_Mario1_FallDown)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Call(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_ParadePeach_Bow)
            Wait(30)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_UseStarRod) = {
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(ActorSpeak, MSG_Intro_0058, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Talk, ANIM_BattleBowser_Idle)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 15)
    Add(LVar1, 65)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 320)
    Call(SetBattleCamOffsetY, 0)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Thread
        Wait(2)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 20)
        Add(LVar1, 90)
        PlayEffect(EFFECT_STARS_SHIMMER, 3, LVar0, LVar1, LVar2, 30, 30, 7, 30, 0)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    Wait(30)
    Call(ActorSpeak, MSG_Intro_0059, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_BrandishTalk, ANIM_BattleBowser_BrandishIdle)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    ExecWait(N(EVS_StarRodCast))
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 15)
    Add(LVar1, 65)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 320)
    Call(SetBattleCamOffsetY, 0)
    Call(MoveBattleCamOver, 25)
    Call(ActorSpeak, MSG_Intro_005A, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock, ANIM_BattleBowser_RearUpStill)
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(BoostedDefense)))
    Call(SetStatusTable, ACTOR_SELF, Ref(N(BoostedStatusTable)))
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
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 15)
    Add(LVar1, 65)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 400)
    Call(SetBattleCamOffsetY, 0)
    Call(MoveBattleCamOver, 32)
    Wait(32)
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
