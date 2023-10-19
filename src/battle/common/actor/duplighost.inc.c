#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Duplighost.h"

#define NAMESPACE A(duplighost)

// scripts in duplighost.c calls two functions defined in ghost_watt.c for adjusting the background fade
// this macro is used to highlight those instances
#define WATT(x) A(  watt_clone_##x )

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
    PRT_SPINY       = 3,
    PRT_ZERO        = 0,
};

enum N(ActorVars) {
    AVAR_Copy_ParentActorID     = 0,
    AVAR_Copy_PartnerLevel      = 1,
    AVAR_Kooper_Toppled         = 3,
    AVAR_Kooper_ToppleTurns     = 4,
    AVAR_State                  = 8,
    AVAL_State_ReadyToCopy      = 0, // will copy partner next turn
    AVAL_State_CopiedPartner    = 1, // currently transformed
    AVAL_State_ReadyToTackle    = 2, // will use flying tackle next turn
    AVAL_State_WaitToTackle     = 3, // do nothing this turn and tackle next turn (unused)
};

enum N(ActorParams) {
    DMG_FLYING_LEAP     = 4,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Duplighost_Anim02,
    STATUS_KEY_STONE,     ANIM_Duplighost_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Duplighost_Anim0D,
    STATUS_KEY_POISON,    ANIM_Duplighost_Anim02,
    STATUS_KEY_STOP,      ANIM_Duplighost_Anim00,
    STATUS_KEY_STATIC,    ANIM_Duplighost_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_Duplighost_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Duplighost_Anim0E,
    STATUS_KEY_FEAR,      ANIM_Duplighost_Anim0E,
    STATUS_END,
};

s32 N(FlailingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Duplighost_Anim0A,
    STATUS_END,
};

s32 N(RunAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Duplighost_Anim04,
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
    STATUS_KEY_STATIC,             75,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 25 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_DUPLIGHOST,
    .level = ACTOR_LEVEL_DUPLIGHOST,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 36, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToCopy)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_WaitToTackle)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToTackle)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim04)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
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
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0C)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0C)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim04)
            EVT_SET_CONST(LVar2, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_FlyingTackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Duplighost_Anim07)
    EVT_WAIT(20)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_DUPLIGHOST_LEAP, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Duplighost_Anim08)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 17, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Duplighost_Anim02)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Duplighost_Anim08)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, EVT_FLOAT(4.0), EVT_FLOAT(-6.0), 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -15, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_FLYING_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Duplighost_Anim09)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Duplighost_OnDeath) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_ParentActorID, LVar0)
    EVT_CALL(RemoveActor, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Duplighost_OnHitElectric) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(30)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_ParentActorID, LVarA)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(HideHealthBar, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
    EVT_CALL(SetEnemyHP, LVarA, LVarB)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(SetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, LVarA, AVAR_State, AVAL_State_ReadyToTackle)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetIdleAnimations, LVarA, PRT_MAIN, EVT_PTR(N(FlailingAnims)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim0A)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_IF_GT(LVarC, 0)
        EVT_SET(LVarC, 0)
        EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.5))
        EVT_CALL(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 15, FALSE, TRUE, FALSE)
        EVT_CALL(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_CALL(ForceHomePos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(SetIdleAnimations, LVarA, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim02)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Duplighost_OnShockHit) = {
    EVT_SET(LVar9, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_ParentActorID, LVarA)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(HideHealthBar, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
    EVT_CALL(SetEnemyHP, LVarA, LVarB)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(SetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, LVarA, AVAR_State, AVAL_State_WaitToTackle)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetIdleAnimations, LVarA, PRT_MAIN, EVT_PTR(N(FlailingAnims)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim0A)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_ADD(LVarB, 30)
    EVT_SET(LVarC, 0)
    EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(JumpToGoal, LVarA, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LVarB, 20)
    EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(JumpToGoal, LVarA, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LVarB, 10)
    EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
    EVT_WAIT(20)
    EVT_CALL(AddActorDecoration, LVarA, 1, 0, ACTOR_DECORATION_SWEAT)
    EVT_CALL(SetActorYaw, LVarA, 180)
    EVT_CALL(SetIdleAnimations, LVarA, PRT_MAIN, EVT_PTR(N(RunAnims)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim04)
    EVT_CALL(SetActorSpeed, LVarA, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(SetGoalPos, LVarA, LVarB, 0, LVarD)
    EVT_CALL(RunToGoal, LVarA, 0, FALSE)
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim02)
    EVT_CALL(SetActorYaw, LVarA, 0)
    EVT_CALL(RemoveActorDecoration, LVarA, 1, 0)
    EVT_CALL(SetIdleAnimations, LVarA, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_CALL(ForceHomePos, LVarA, LVarB, 0, LVarD)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Duplighost_OnShockDeath) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
    EVT_SET(LVar0, LVarA)
    EVT_SET(LVar1, LVarB)
    EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, LVarC, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, -48)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3i A(DuplighostSummonPos) = { NPC_DISPOSE_LOCATION };

#include "duplighost/ghost_goombario.inc.c"
#include "duplighost/ghost_kooper.inc.c"
#include "duplighost/ghost_bombette.inc.c"
#include "duplighost/ghost_parakarry.inc.c"
#include "duplighost/ghost_bow.inc.c"
#include "duplighost/ghost_watt.inc.c"
#include "duplighost/ghost_sushie.inc.c"
#include "duplighost/ghost_lakilester.inc.c"
#define NAMESPACE A(duplighost)

API_CALLABLE(N(GetPartnerAndLevel)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.curPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.curPartner].level);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AdjustFormationPriority)) {
    s32 partnerID = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(script->owner1.actorID);
    FormationRow* formation = NULL;

    switch (partnerID) {
        case PARTNER_GOOMBARIO:
            formation = A(GoombarioCloneFormation);
            break;
        case PARTNER_KOOPER:
            formation = A(KooperCloneFormation);
            break;
        case PARTNER_BOMBETTE:
            formation = A(BombetteCloneFormation);
            break;
        case PARTNER_PARAKARRY:
            formation = A(ParakarryCloneFormation);
            break;
        case PARTNER_BOW:
            formation = A(BowCloneFormation);
            break;
        case PARTNER_WATT:
            formation = A(WattCloneFormation);
            break;
        case PARTNER_SUSHIE:
            formation = A(SushieCloneFormation);
            break;
        case PARTNER_LAKILESTER:
            formation = A(LakilesterCloneFormation);
            break;
    }

    formation->priority = actor->turnPriority;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_CopyPartner) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GHOST_TRANSFORM)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Duplighost_Anim06)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 8)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LVar1, 20)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, LVar3, 40, 0)
    EVT_CALL(WATT(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 20, EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(WATT(SetBackgroundAlpha), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(N(GetPartnerAndLevel), LVar5, LVar6)
    EVT_CALL(N(AdjustFormationPriority), LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SummonEnemy, EVT_PTR(A(GoombarioCloneFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SummonEnemy, EVT_PTR(A(KooperCloneFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SummonEnemy, EVT_PTR(A(BombetteCloneFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SummonEnemy, EVT_PTR(A(ParakarryCloneFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SummonEnemy, EVT_PTR(A(BowCloneFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_WATT)
            EVT_CALL(SummonEnemy, EVT_PTR(A(WattCloneFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_SUSHIE)
            EVT_CALL(SummonEnemy, EVT_PTR(A(SushieCloneFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LakilesterCloneFormation)), FALSE)
    EVT_END_SWITCH
    EVT_SET(LVarA, LVar0)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(SetBattleVar, BTL_VAR_LastCopiedPartner, LVar5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, LVarA, LVar0)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetOwnerID, LVar0)
    EVT_CALL(SetActorVar, LVarA, AVAR_Copy_ParentActorID, LVar0)
    EVT_CALL(SetActorVar, LVarA, AVAR_Copy_PartnerLevel, LVar6)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(MakeLerp, 200, 0, 20, EASING_LINEAR)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(WATT(SetBackgroundAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(8)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LVarA, LVar0, 10, LVar2)
            EVT_CALL(JumpToGoal, LVarA, 10, FALSE, FALSE, FALSE)
            EVT_WAIT(10)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LVarA, LVar0, 30, LVar2)
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
    EVT_WAIT(20)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_CopiedPartner)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_ReadyToCopy)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 600)
                EVT_CALL(GetBattleVar, BTL_VAR_DuplighostCopyFlags, LVar0)
                EVT_IF_NOT_FLAG(LVar0, BTL_VAL_Duplighost_HasCopied)
                    // first time partner is copied, set battle flag and proceed
                    EVT_CALL(GetBattleVar, BTL_VAR_DuplighostCopyFlags, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, BTL_VAL_Duplighost_HasCopied)
                    EVT_CALL(SetBattleVar, BTL_VAR_DuplighostCopyFlags, LVar0)
                    EVT_EXEC_WAIT(N(EVS_CopyPartner))
                EVT_ELSE
                    // partner has been copied before, try to avoid copying the same one
                    EVT_CALL(GetBattleVar, BTL_VAR_LastCopiedPartner, LVar0)
                    EVT_CALL(N(GetPartnerAndLevel), LVar1, LVar2)
                    EVT_IF_EQ(LVar0, LVar1)
                        EVT_EXEC_WAIT(N(EVS_CopyPartner))
                    EVT_ELSE
                        EVT_EXEC_WAIT(N(EVS_Attack_FlyingTackle))
                    EVT_END_IF
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Attack_FlyingTackle))
            EVT_END_IF
        EVT_CASE_EQ(AVAL_State_CopiedPartner)
            // do nothing, currently in disguise
        EVT_CASE_EQ(AVAL_State_ReadyToTackle)
            EVT_EXEC_WAIT(N(EVS_Attack_FlyingTackle))
        EVT_CASE_EQ(AVAL_State_WaitToTackle)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};



