#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/MageJrTroopa.h"

#define NAMESPACE A(mage_jr_troopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TryFearReaction);
extern EvtScript N(EVS_JrTroopa_Death);

enum N(ActorPartIDs) {
    PRT_BASE        = 1,
    PRT_MAGE        = 2,
};

enum N(ActorVars) {
    // 'you wont like this!' brag before attacking
    AVAR_MagicBrag_State        = 0,
    AVAL_MagicBrag_None         = 0,
    AVAL_MagicBrag_Ready        = 1,
    AVAL_MagicBrag_Done         = 2,
    // 'that felt fantastic!' brag after dealing damage
    AVAR_DamageBrag_State       = 1,
    AVAL_DamageBrag_None        = 0,
    AVAL_DamageBrag_Ready       = 1,
    AVAL_DamageBrag_Done        = 2,
    AVAR_Unused                 = 2,
    AVAR_SpookReact             = 3,
    AVAL_SpookReact_None        = 0,
    AVAL_SpookReact_Ready       = 1,
};

enum N(ActorParams) {
    DMG_SPELL       = 8,
};

s32 N(MageAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MageJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_MageJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_MageJrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_MageJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(UnusedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MageJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_STONE,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_MageJrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_MageJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(BaseAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              35,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              45,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           45,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               60,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_BASE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 28 },
        .opacity = 255,
        .idleAnimations = N(MageAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAGE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(BaseAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA_5,
    .level = ACTOR_LEVEL_JR_TROOPA_5,
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
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 35 },
    .statusTextOffset = { 10, 25 },
};

EvtScript N(EVS_SetupFearReaction) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar2)
    IfFlag(LVar2, STATUS_FLAGS_IMMOBILIZED)
        Return
    EndIf
    Call(GetBattleFlags, LVar2)
    IfFlag(LVar2, BS_FLAGS1_PARTNER_ACTING)
        Call(GetMenuSelection, LVar0, LVar1, LVar2)
        IfEq(LVar2, MOVE_SPOOK)
            Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_Ready)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMOTE_QUESTION)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 30)
            Call(ShowEmote, 0, EMOTE_QUESTION, -45, 30, EMOTER_POS, LVar0, LVar1, LVar2, 5)
            Wait(30)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Transform) = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 16)
    Else
        Add(LVar1, 6)
    EndIf
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
    Thread
        Set(LVar0, 0)
        Loop(32)
            Wait(1)
            Add(LVar0, 45)
            Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EndLoop
    EndThread
    Wait(32)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_NEW_POWER)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 40, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 4, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 4, 0)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnJrTroopa) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_GOAL_SIMPLE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamOffsetY, 38)
    Call(SetBattleCamDist, 256)
    Call(MoveBattleCamOver, 15)
    Return
    End
};

EvtScript N(EVS_Cam_ResetFocus) = {
    Call(EnableBattleStatusBar, true)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 12)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnGoompa) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_GOOMPA)
    Call(MoveBattleCamOver, 30)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, AVAL_MagicBrag_None)
    Call(SetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, AVAL_DamageBrag_None)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_SetupFearReaction))
            ExecWait(N(EVS_TryFearReaction))
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Still)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, PRT_BASE)
            Set(LVar1, ANIM_MageJrTroopa_BurnHurt)
            Set(LVar2, ANIM_MageJrTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, PRT_BASE)
            Set(LVar1, ANIM_MageJrTroopa_BurnHurt)
            Set(LVar2, ANIM_MageJrTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_BurnStill)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(ResetAllActorSounds, ACTOR_SELF)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Still)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
            ExecWait(N(EVS_SetupFearReaction))
            ExecWait(N(EVS_TryFearReaction))
        EndCaseGroup
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Flail)
                Wait(1000)
            EndIf
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Flail)
                Wait(20)
                ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                Call(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                ExecWait(N(EVS_Cam_ResetFocus))
            EndIf
        CaseEq(EVENT_SPIKE_CONTACT)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Hurt)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_MageJrTroopa_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_RaiseStaff)
    Wait(8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Set(LVar3, 0)
        Set(LVar4, 36)
        SetF(LVar5, Float(1.0))
    Else
        Set(LVar3, 0)
        Set(LVar4, 14)
        SetF(LVar5, Float(0.4))
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_SwingStaff)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            Sub(LVar3, 120)
            Add(LVar4, 20)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                Set(LVar6, -8)
                Set(LVar7, 20)
                SetF(LVar8, Float(1.0))
            Else
                Set(LVar6, -3)
                Set(LVar7, 8)
                SetF(LVar8, Float(0.4))
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, LVar6)
            Add(LVar1, LVar7)
            PlayEffect(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 30, 0)
            Wait(35)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Add(LVar4, 20)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Set(LVar6, -8)
        Set(LVar7, 20)
        SetF(LVar8, Float(1.0))
    Else
        Set(LVar6, -3)
        Set(LVar7, 8)
        SetF(LVar8, Float(0.4))
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, LVar6)
    Add(LVar1, LVar7)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 15, 0)
    Wait(15)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, DMG_SPELL, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseEq(0)
            Call(GetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, LVar0)
            IfEq(LVar0, AVAL_DamageBrag_None)
                Call(GetLastDamage, ACTOR_PLAYER, LVar1)
                IfNe(LVar1, 0)
                    Call(SetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, AVAL_DamageBrag_Ready)
                EndIf
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_ENEMY_BEGIN)
            // trying showing the scene where Jr Troopa brags about his new skills
            Call(GetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, LVar0)
            IfEq(LVar0, AVAL_MagicBrag_Ready)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfNotFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Call(SetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, AVAL_MagicBrag_Done)
                    Call(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
                    IfEq(LVar0, AVAL_SpookReact_None)
                        ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                        Wait(20)
                    EndIf
                    Call(ActorSpeak, MSG_CH7_00DD, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                    ExecWait(N(EVS_Cam_ResetFocus))
                    Wait(20)
                EndIf
            Else
                Wait(20)
            EndIf
            Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
            Return
        CaseEq(PHASE_ENEMY_END)
            // trying showing the scene where Jr Troopa brgas about dealing damage
            Call(GetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, LVar0)
            IfEq(LVar0, AVAL_DamageBrag_Ready)
                Call(SetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, AVAL_DamageBrag_Done)
                ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                Wait(20)
                Call(ActorSpeak, MSG_CH7_00DE, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                ExecWait(N(EVS_Cam_ResetFocus))
                Wait(10)
            EndIf
            Return
        CaseEq(PHASE_PLAYER_BEGIN)
            // trying showing the scene where Jr Troopa transforms
            Call(GetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, LVar0)
            IfEq(LVar0, AVAL_MagicBrag_None)
                Call(SetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, AVAL_MagicBrag_Ready)
                Wait(15)
                ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                Wait(10)
                Call(ActorSpeak, MSG_CH7_00DB, ACTOR_SELF, PRT_MAGE, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot)
                Wait(8)
                ExecWait(N(EVS_Transform))
                Call(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_INVISIBLE, true)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, false)
                Wait(15)
                Call(ActorSpeak, MSG_CH7_00DC, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                Wait(10)
                ExecWait(N(EVS_Cam_ResetFocus))
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_JrTroopa_Death) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, false)
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
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        Add(LVar2, 10)
        Loop(3)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            Wait(3)
        EndLoop
    EndThread
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_JrTroopa_DefeatedBegin)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 5)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Wait(15)
    Call(PlaySound, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(SetBattleCamDist, 260)
    Call(SetBattleCamOffsetY, 15)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_JrTroopa_Defeated)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAGE, Ref(N(DefeatedAnims)))
    Wait(60)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, true)
    Return
    End
};

EvtScript N(EVS_TryFearReaction) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
    IfEq(LVar0, AVAL_SpookReact_Ready)
        Wait(10)
        ExecWait(N(EVS_Cam_FocusOnJrTroopa))
        Call(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
        Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
        Call(GetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, LVar0)
        IfNe(LVar0, AVAL_MagicBrag_Ready)
            ExecWait(N(EVS_Cam_ResetFocus))
        EndIf
    EndIf
    Return
    End
};
