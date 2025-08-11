#define NAMESPACE A(bow_lee)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBow_Idle,
    STATUS_KEY_STONE,     ANIM_BattleBow_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBow_Still,
    STATUS_KEY_POISON,    ANIM_BattleBow_Idle,
    STATUS_KEY_STOP,      ANIM_BattleBow_Still,
    STATUS_KEY_STATIC,    ANIM_BattleBow_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleBow_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleBow_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleBow_Injured,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -26 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_BOW,
    .level = ACTOR_LEVEL_LEE_BOW,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 36, 29 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_FormDuration, 1)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_BurnHurtAlt)
            SetConst(LVar2, ANIM_BattleBow_BurnStillAlt)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_BurnHurtAlt)
            SetConst(LVar2, ANIM_BattleBow_BurnStillAlt)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_BurnStillAlt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            Set(LVar2, 14)
            ExecWait(A(EVS_Lee_ShockKnockback))
            Thread
                Set(LVar0, 200)
                Loop(20)
                    Sub(LVar0, 10)
                    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 60)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Run)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
            Set(LVar0, 55)
            Loop(20)
                Add(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
        CaseEq(EVENT_SHOCK_DEATH)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            Set(LVar2, 14)
            ExecWait(A(EVS_Lee_ShockKnockback))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Run)
            SetConst(LVar2, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
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
    Wait(10)
    Thread
        Set(LVar0, 200)
        Loop(20)
            Sub(LVar0, 10)
            Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Run)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Call(AddGoalPos, ACTOR_SELF, 4, -4, 0)
        Else
            Call(AddGoalPos, ACTOR_SELF, 10, -10, 0)
        EndIf
        Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
    EndThread
    Wait(15)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_FAR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Set(LVar0, 55)
    Loop(20)
        Add(LVar0, 10)
        Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_PreSlap)
    Wait(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(15)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.4), Float(1.4), Float(1.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_SlapOnce)
            Wait(2)
            Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
            Set(LVar0, 0)
            Loop(20)
                Add(LVar0, -45)
                Call(SetActorYaw, ACTOR_SELF, LVar0)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_SELF, 0)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Injured)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SEEING_STARS)
            Wait(30)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
            Wait(10)
            Call(YieldTurn)
            Thread
                Set(LVar0, 200)
                Loop(20)
                    Sub(LVar0, 10)
                    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 60)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Run)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
            Set(LVar0, 55)
            Loop(20)
                Add(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Set(LVarA, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar8)
    Switch(LVar8)
        CaseEq(PARTNER_RANK_NORMAL)
            Set(LVar8, 4)
        CaseEq(PARTNER_RANK_SUPER)
            Set(LVar8, 5)
        CaseEq(PARTNER_RANK_ULTRA)
            Set(LVar8, 6)
    EndSwitch
    Set(LVar7, LVar8)
    Loop(LVar7)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOW_SMACK)
        Add(LVarA, 1)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.4), Float(1.4), Float(1.0))
        IfEq(LFlag0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_SlapOnce)
            Set(LFlag0, true)
            IfEq(LVarA, LVar8)
                Call(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
            Else
                Call(SetDamageSource, DMG_SRC_NEXT_SLAP_LEFT)
            EndIf
        Else
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_SlapBack)
            Set(LFlag0, false)
            IfEq(LVarA, LVar8)
                Call(SetDamageSource, DMG_SRC_LAST_SLAP_RIGHT)
            Else
                Call(SetDamageSource, DMG_SRC_NEXT_SLAP_RIGHT)
            EndIf
        EndIf
        Wait(2)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.2))
        EndThread
        Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
        Switch(LVar9)
            CaseEq(PARTNER_RANK_NORMAL)
                Wait(2)
                Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            CaseEq(PARTNER_RANK_SUPER)
                Wait(2)
                Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            CaseEq(PARTNER_RANK_ULTRA)
                Wait(2)
                Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
        EndSwitch
        Wait(8)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
        Call(GetActorHP, ACTOR_PLAYER, LVar1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(10)
            Call(YieldTurn)
            Thread
                Set(LVar0, 200)
                Loop(20)
                    Sub(LVar0, 10)
                    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 30)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Run)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBow_Idle)
            Set(LVar0, 55)
            Loop(20)
                Add(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_ENEMY_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_FormDuration, LVar0)
            IfGt(LVar0, 0)
                Sub(LVar0, 1)
                Call(SetActorVar, ACTOR_SELF, AVAR_FormDuration, LVar0)
                BreakSwitch
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(A(EVS_Lee_LoseDisguise))
            Return
    EndSwitch
    Return
    End
};

Formation A(LeeBowFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(Lee_SummonPos), 0)
};
