#define NAMESPACE A(parakarry_lee)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleParakarry_Idle,
    STATUS_KEY_STONE,     ANIM_BattleParakarry_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleParakarry_Still,
    STATUS_KEY_POISON,    ANIM_BattleParakarry_Idle,
    STATUS_KEY_STOP,      ANIM_BattleParakarry_Still,
    STATUS_KEY_STATIC,    ANIM_BattleParakarry_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleParakarry_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleParakarry_Idle,
    STATUS_KEY_FEAR,      ANIM_BattleParakarry_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
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
        .targetOffset = { -3, 32 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -16 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -3, -18 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -16 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_PARAKARRY,
    .level = ACTOR_LEVEL_LEE_PARAKARRY,
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
    .size = { 38, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FormDuration, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleParakarry_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleParakarry_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(A(EVS_Lee_RemoveParentActor))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(A(EVS_Lee_RemoveParentActor))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_SET(LVar2, 22)
            EVT_EXEC_WAIT(A(EVS_Lee_ShockKnockback))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(A(EVS_Lee_RemoveParentActor))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_SET(LVar2, 22)
            EVT_EXEC_WAIT(A(EVS_Lee_ShockKnockback))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(A(EVS_Lee_RemoveParentActor))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Run)
            EVT_SET_CONST(LVar2, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Run)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SkyDive) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Still)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_01)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_PREDIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_FlyFast)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 10, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_PreDive)
    EVT_END_THREAD
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 15, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, -20, EASING_QUARTIC_OUT)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_DIVE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Dive)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, EASING_LINEAR)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Idle)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 10, -20, EASING_QUADRATIC_OUT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_PostDive)
    EVT_WAIT(1)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(PARTNER_RANK_NORMAL)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(PARTNER_RANK_SUPER)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(PARTNER_RANK_ULTRA)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_CALL(PlaySound, SOUND_NONE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Dive)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Still)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Run)
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpWithBounce, ACTOR_SELF, 10, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Idle)
            EVT_WAIT(6)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleParakarry_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_EXEC_WAIT(N(EVS_Attack_SkyDive))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FormDuration, LVar0)
            EVT_IF_GT(LVar0, 0)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FormDuration, LVar0)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(A(EVS_Lee_LoseDisguise))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation A(LeeParakarryFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(Lee_SummonPos), 0)
};
