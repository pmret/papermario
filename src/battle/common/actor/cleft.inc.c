#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Cleft.h"

#define NAMESPACE A(cleft)

extern s32 N(UprightAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Toppled        = 0,
    AVAR_ToppleTurns    = 1,
};

enum N(ActorParams) {
    DMG_TACKLE      = 2,
};

s32 N(UprightDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_FIRE,    99,
    ELEMENT_MAGIC,    0,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,    99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             75,
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
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(UprightAnims),
        .defenseTable = N(UprightDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CLEFT,
    .level = ACTOR_LEVEL_CLEFT,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 80,
    .airLiftChance = 40,
    .hurricaneChance = 40,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 2,
    .size = { 44, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(UprightAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Cleft_Anim02,
    STATUS_KEY_STONE,     ANIM_Cleft_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Cleft_Anim0C,
    STATUS_KEY_POISON,    ANIM_Cleft_Anim02,
    STATUS_KEY_STOP,      ANIM_Cleft_Anim00,
    STATUS_KEY_STATIC,    ANIM_Cleft_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_Cleft_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Cleft_Anim0E,
    STATUS_KEY_FEAR,      ANIM_Cleft_Anim0E,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Cleft_Anim05,
    STATUS_KEY_STONE,     ANIM_Cleft_Anim01,
    STATUS_KEY_SLEEP,     ANIM_Cleft_Anim0D,
    STATUS_KEY_POISON,    ANIM_Cleft_Anim05,
    STATUS_KEY_STOP,      ANIM_Cleft_Anim01,
    STATUS_KEY_STATIC,    ANIM_Cleft_Anim05,
    STATUS_KEY_PARALYZE,  ANIM_Cleft_Anim01,
    STATUS_KEY_DIZZY,     ANIM_Cleft_Anim0F,
    STATUS_KEY_FEAR,      ANIM_Cleft_Anim0F,
    STATUS_END,
};

#include "common/SetSpinSmashable.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipOver) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Toppled, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim07)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(5)
            EVT_ADD(LVar0, -36)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
    EVT_SUB(LVar1, 6)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 200, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 40, 8, EVT_FLOAT(0.0), 20, 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim03)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 15)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -7)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
    EVT_CALL(N(SetSpinSmashable), FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
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
            EVT_CALL(GetLastElement, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_FLAG(DAMAGE_TYPE_BLAST)
                    EVT_EXEC_WAIT(N(EVS_FlipOver))
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                    EVT_ELSE
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                    EVT_END_IF
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetLastElement, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_FLAG(DAMAGE_TYPE_BLAST)
                    EVT_EXEC_WAIT(N(EVS_FlipOver))
                EVT_CASE_DEFAULT
                    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, TRUE)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_SET_CONST(LVar0, PRT_MAIN)
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                        EVT_SET_CONST(LVar2, -1)
                        EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_ELSE
                        EVT_SET_CONST(LVar0, PRT_MAIN)
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                        EVT_SET_CONST(LVar2, -1)
                        EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_END_IF
                    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, FALSE)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                EVT_SET_CONST(LVar2, -1)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                EVT_SET_CONST(LVar2, -1)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim18)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar0, -3)
                EVT_ADD(LVar1, 10)
            EVT_ELSE
                EVT_ADD(LVar0, -8)
                EVT_ADD(LVar1, 27)
            EVT_END_IF
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim03)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim02)
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim02)
                EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim03)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim07)
                EVT_SET_CONST(LVar2, ANIM_Cleft_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim0F)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Anim08)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryGettingUp) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim03)
    EVT_WAIT(20)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim05)
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    EVT_ELSE
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim03)
        EVT_THREAD
            EVT_WAIT(3)
            EVT_LOOP(5)
                EVT_ADD(LVar0, 36)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 6)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 200, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightAnims)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightDefenseTable)))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 22)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -10)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
        EVT_WAIT(1)
        EVT_CALL(N(SetSpinSmashable), TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Tackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim10)
    EVT_WAIT(10)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim11)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, -5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim00)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CLEFT_TACKLE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_TACKLE, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_THREAD
                    EVT_WAIT(10)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim11)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 45)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim08)
            EVT_WAIT(15)
            EVT_WAIT(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim07)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim11)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 15)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
            EVT_WAIT(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim07)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_WAIT(N(EVS_TryGettingUp))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
