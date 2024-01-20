#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/ParaJrTroopa.h"
#include "sprite/player.h"
#include "sprite/npc/Goompa.h"

#define NAMESPACE A(jr_troopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_TurnCount                  = 0,
    AVAR_Goompa_Introduction_Done   = 1,
    AVAR_HitReact_State             = 2,
    AVAL_HitReact_Init              = 0,
    AVAL_HitReact_Hit               = 1,
    AVAL_HitReact_Done              = 2,
    AVAR_JrTroopa_PoweredUp         = 3,
    AVAR_AttackDamage               = 4,
    AVAR_JustGettingStarted         = 5,
};

enum N(ActorParams) {
    DMG_INITIAL          = 1,
    DMG_FULL_POWER       = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
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
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA_1,
    .level = ACTOR_LEVEL_JR_TROOPA_1,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 30 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Cam_FocusOnJrTroopa) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_07)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamOffsetZ, 38)
    Call(SetBattleCamZoom, 256)
    Call(MoveBattleCamOver, 15)
    Return
    End
};

EvtScript N(EVS_Cam_ResetFocus) = {
    Call(EnableBattleStatusBar, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 12)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnGoompa) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_55)
    Call(MoveBattleCamOver, 30)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Return
    End
};

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

EvtScript N(EVS_JrTroopa_Death) = {
    Set(LVarA, LVar0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, LVarA, LVar1)
    Wait(10)
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
            Set(LVar2, 0)
            Loop(24)
                Call(SetActorYaw, ACTOR_SELF, LVar2)
                Add(LVar2, 30)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_SELF, 0)
    EndSwitch
    Label(0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Add(LVar2, 10)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Call(PlaySound, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(SetBattleCamZoom, 260)
    Call(SetBattleCamOffsetZ, 15)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    Call(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Collapse)
    Wait(12)
    Call(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Defeated)
    Call(SetIdleAnimations, ACTOR_SELF, LVarA, Ref(N(DefeatedAnims)))
    Wait(30)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(15)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 180)
    Wait(5)
    Call(ActorSpeak, MSG_CH0_00B4, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 0)
    Wait(5)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Goompa_Introduction_Done, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Init)
    Call(SetActorVar, ACTOR_SELF, AVAR_JrTroopa_PoweredUp, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_AttackDamage, DMG_INITIAL)
    Call(SetActorVar, ACTOR_SELF, AVAR_JustGettingStarted, FALSE)
    Return
    End
};

// unused
EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
        Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_HitReact_State, LVar0)
    IfEq(LVar0, AVAL_HitReact_Init)
        Call(GetLastDamage, ACTOR_SELF, LVar1)
        IfNe(LVar1, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Hit)
        EndIf
    EndIf
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Panic)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(AddActorVar, ACTOR_SELF, AVAR_TurnCount, 1)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    Sub(LVar1, LVar0)
    IfEq(LVar1, 3)
        Call(GetActorVar, ACTOR_SELF, AVAR_JustGettingStarted, LVar0)
        IfFalse(LVar0)
            Call(SetActorVar, ACTOR_SELF, AVAR_JustGettingStarted, TRUE)
            ExecWait(N(EVS_Cam_FocusOnJrTroopa))
            Call(MoveBattleCamOver, 20)
            Wait(20)
            Call(UseIdleAnimation, ACTOR_SELF, FALSE)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            Call(ActorSpeak, MSG_CH0_00B1, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle)
        EndIf
    EndIf
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Jump)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_JR_TOOPA_JUMP, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_AttackDamage, LVar1)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, LVar1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseEq(6)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 30)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Sub(LVar0, 10)
            Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            Wait(8)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            Return
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
    Thread
        Wait(3)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Midair)
        Wait(5)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Fall)
    EndThread
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Wait(2)
    Call(GetActorVar, ACTOR_SELF, AVAR_AttackDamage, LVar1)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            Wait(10)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            // trying showing the scene where Goompa introduces the player to Jr Troopa
            Call(GetActorVar, ACTOR_SELF, AVAR_Goompa_Introduction_Done, LVar0)
            IfFalse(LVar0)
                Call(SetActorVar, ACTOR_SELF, AVAR_Goompa_Introduction_Done, TRUE)
                Wait(15)
                Call(EnableBattleStatusBar, FALSE)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                Thread
                    Set(LVar1, 0)
                    Wait(8)
                    Loop(5)
                        Wait(1)
                        Sub(LVar1, 36)
                        Call(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EndLoop
                EndThread
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Punch)
                Call(ActorSpeak, MSG_CH0_00AF, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_NodYes)
                Wait(10)
                Thread
                    Set(LVar1, 180)
                    Wait(4)
                    Loop(5)
                        Wait(1)
                        Add(LVar1, 36)
                        Call(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EndLoop
                EndThread
                Wait(10)
                Call(EnableBattleStatusBar, TRUE)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 4)
            EndIf
            EndIf /// @bug END_IF with no IF
        CaseEq(PHASE_ENEMY_BEGIN)
            // trying showing the scene where Goompa congratulates the player for dealing damage to Jr Troopa
            Call(GetActorVar, ACTOR_SELF, AVAR_HitReact_State, LVar0)
            IfEq(LVar0, AVAL_HitReact_Hit)
                Call(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Done)
                ExecWait(N(EVS_Cam_FocusOnGoompa))
                Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                Thread
                    Set(LVar1, 0)
                    Loop(5)
                        Wait(1)
                        Sub(LVar1, 36)
                        Call(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EndLoop
                EndThread
                Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                Call(ActorSpeak, MSG_CH0_00B0, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
                Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
                Wait(20)
                Call(SetActorYaw, ACTOR_PLAYER, 0)
                Wait(4)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EndIf
            // trying showing the scene where Jr Troopa powers up
            Call(GetActorVar, ACTOR_SELF, AVAR_JrTroopa_PoweredUp, LVar0)
            IfFalse(LVar0)
                Call(GetActorHP, ACTOR_SELF, LVar0)
                IfLe(LVar0, 1)
                    Call(SetActorVar, ACTOR_SELF, AVAR_JrTroopa_PoweredUp, TRUE)
                    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                    Call(ActorSpeak, MSG_CH0_00B2, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
                    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                    ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                    Call(ActorSpeak, MSG_CH0_00B3, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_ChargeArmsUp)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Add(LVar1, 16)
                    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
                    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
                    Wait(30)
                    Wait(20)
                    Call(SetActorVar, ACTOR_SELF, AVAR_AttackDamage, DMG_FULL_POWER)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
                    Wait(20)
                EndIf
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
