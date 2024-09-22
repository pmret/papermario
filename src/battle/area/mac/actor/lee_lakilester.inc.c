#define NAMESPACE A(lakilester_lee)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleLakilester_Idle,
    STATUS_KEY_STONE,     ANIM_BattleLakilester_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleLakilester_Still,
    STATUS_KEY_POISON,    ANIM_BattleLakilester_Idle,
    STATUS_KEY_STOP,      ANIM_BattleLakilester_Still,
    STATUS_KEY_STATIC,    ANIM_BattleLakilester_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleLakilester_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleLakilester_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleLakilester_Idle,
    STATUS_END,
};

s32 N(SpinyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleLakilester_Spiny,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 33 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SPINY,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpinyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_LAKILESTER,
    .level = ACTOR_LEVEL_LEE_LAKILESTER,
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
    .size = { 44, 40 },
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
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_BurnHurt)
            SetConst(LVar2, ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_BurnHurt)
            SetConst(LVar2, ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
        CaseEq(EVENT_SHOCK_DEATH)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            ExecWait(A(EVS_Lee_RemoveParentActor))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Run)
            SetConst(LVar2, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
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
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Run)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, 20, 30, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Idle)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, -1)
        Add(LVar1, 4)
        Add(LVar2, 2)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY, Float(0.4), Float(0.4), Float(0.4))
    Else
        Add(LVar0, -3)
        Add(LVar1, 10)
        Add(LVar2, 5)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY, Float(1.0), Float(1.0), Float(1.0))
    EndIf
    Call(SetPartPos, ACTOR_SELF, PRT_SPINY, LVar0, LVar1, LVar2)
    Wait(1)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY, ANIM_BattleLakilester_Spiny)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_LiftSpiny)
    Loop(4)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            AddF(LVar1, Float(2.4))
        Else
            Add(LVar1, 6)
        EndIf
        Call(SetPartPos, ACTOR_SELF, PRT_SPINY, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, -3)
        Add(LVar1, 16)
        Add(LVar2, 2)
        SetF(LVar3, Float(0.4))
    Else
        Add(LVar0, -8)
        Add(LVar1, 40)
        Add(LVar2, 5)
        SetF(LVar3, Float(1.0))
    EndIf
    PlayEffect(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, LVar3, 30, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPIKE_SUMMON_SPINY)
    Thread
        Loop(15)
            Call(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_SPINY, 1, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_SPINY, -1, 0, 0)
            Wait(1)
        EndLoop
        Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        Call(SetPartDispOffset, ACTOR_SELF, PRT_SPINY, 0, 0, 0)
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_HoldSpiny)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_StrainHoldSpiny)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_ThrowSpiny)
    Wait(3)
    Call(SetPartSounds, ACTOR_SELF, PRT_SPINY, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LAKILESTER_THROW_SPINY_A)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_SPINY, ANIM_BattleLakilester_SpinySpin)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY, Float(1.5))
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(RandInt, 100, LVar3)
            Sub(LVar3, 50)
            Add(LVar0, LVar3)
            Call(JumpPartTo, ACTOR_SELF, PRT_SPINY, LVar0, 0, LVar2, 20, TRUE)
            Thread
                Add(LVar0, -50)
                Call(JumpPartTo, ACTOR_SELF, PRT_SPINY, LVar0, 0, LVar2, 15, TRUE)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(YieldTurn)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 60)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY, ANIM_BattleLakilester_SpinySpin)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY, Float(1.5))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpPartTo, ACTOR_SELF, PRT_SPINY, LVar0, LVar1, LVar2, 20, TRUE)
    Thread
        Add(LVar0, -50)
        Call(JumpPartTo, ACTOR_SELF, PRT_SPINY, LVar0, 0, LVar2, 15, TRUE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndThread
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    Switch(LVar9)
        CaseEq(PARTNER_RANK_NORMAL)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_SUPER)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_ULTRA)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(15)
            Call(YieldTurn)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 8)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
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
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(A(EVS_Lee_LoseDisguise))
            Return
    EndSwitch
    Return
    End
};

Formation A(LeeLakilesterFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(Lee_SummonPos), 0)
};
