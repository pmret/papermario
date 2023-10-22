#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Bobomb.h"

#define NAMESPACE A(bob_omb)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandleEvent_Ignited);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_HitDuringCombo = 0,
    AVAR_Ignited        = 8,
};

enum N(ActorParams) {
    DMG_TACKLE          = 1,
    DMG_EXPLOSION       = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bobomb_Idle,
    STATUS_KEY_STONE,     ANIM_Bobomb_Still,
    STATUS_KEY_SLEEP,     ANIM_Bobomb_Sleep,
    STATUS_KEY_POISON,    ANIM_Bobomb_Walk,
    STATUS_KEY_STOP,      ANIM_Bobomb_Still,
    STATUS_KEY_STATIC,    ANIM_Bobomb_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Bobomb_Still,
    STATUS_KEY_DIZZY,     ANIM_Bobomb_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Bobomb_Dizzy,
    STATUS_END,
};

s32 N(IgnitedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bobomb_WalkLit,
    STATUS_KEY_STONE,     ANIM_Bobomb_StillLit,
    STATUS_KEY_SLEEP,     ANIM_Bobomb_Sleep,
    STATUS_KEY_POISON,    ANIM_Bobomb_WalkLit,
    STATUS_KEY_STOP,      ANIM_Bobomb_StillLit,
    STATUS_KEY_STATIC,    ANIM_Bobomb_IdleLit,
    STATUS_KEY_PARALYZE,  ANIM_Bobomb_StillLit,
    STATUS_KEY_DIZZY,     ANIM_Bobomb_DizzyLit,
    STATUS_KEY_FEAR,      ANIM_Bobomb_DizzyLit,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              75,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           80,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,               90,
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

s32 N(IgnitedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
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
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -9 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOB_OMB,
    .level = ACTOR_LEVEL_BOB_OMB,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 70,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 34, 35 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Ignited, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitDuringCombo, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Ignite) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_RETURN
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Ignited, TRUE)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IgnitedAnims)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent_Ignited)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_CONTACT, TRUE)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(IgnitedStatusTable)))
    EVT_CALL(PlayLoopingSoundAtActor, ACTOR_SELF, 0, SOUND_LOOP_BOBOMB_FUSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_WalkLit)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(EnableActorPaletteEffects, ACTOR_SELF, PRT_MAIN, TRUE)
    EVT_CALL(SetActorPaletteSwapParams, ACTOR_SELF, PRT_MAIN, SPR_PAL_Bobomb, SPR_PAL_Bobomb_Burst, 0, 10, 0, 10, 0, 0)
    EVT_CALL(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_WAIT(3)
    EVT_CALL(StopLoopingSoundAtActor, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Defuse) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Ignited, FALSE)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_CONTACT, FALSE)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 2)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0, 0)
    EVT_CALL(StopLoopingSoundAtActor, ACTOR_SELF, 0)
    EVT_CALL(EnableActorPaletteEffects, ACTOR_SELF, PRT_MAIN, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cleanup) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Ignited, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(StopLoopingSoundAtActor, ACTOR_SELF, 0)
        EVT_CALL(EnableActorPaletteEffects, ACTOR_SELF, PRT_MAIN, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Explode) = {
    EVT_EXEC_WAIT(N(EVS_Cleanup))
    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MAX)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.75))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(4.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 2)
    EVT_PLAY_EFFECT(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2, 0)
    EVT_ADD(LVar1, 20)
    EVT_ADD(LVar2, 2)
    EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar0, LVar1, LVar2, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOMB_BLAST)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitDuringCombo, TRUE)
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVarE)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_SHOCK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnHurt)
                EVT_SET_CONST(LVar2, ANIM_Bobomb_BurnStill)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_EXEC_WAIT(N(EVS_Explode))
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
                EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
                EVT_IF_NE(LVar0, 0)
                    EVT_EXEC_WAIT(N(EVS_Ignite))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Bobomb_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_Explode))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
            EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(EVS_Ignite))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_Cleanup))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnHurt)
            EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitDuringCombo, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_EXEC_WAIT(N(EVS_Ignite))
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetLastElement, LVarE)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_SHOCK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnHurt)
                EVT_SET_CONST(LVar2, ANIM_Bobomb_BurnStill)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_EXEC_WAIT(N(EVS_Explode))
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
                EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(EVS_Cleanup))
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_EXPLODE_TRIGGER)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Bobomb_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_Explode))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
            EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Run)
            EVT_SET_CONST(LVar2, ANIM_Bobomb_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Dizzy)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Dizzy)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_Ignited) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetLastElement, LVarE)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_WATER)
                EVT_EXEC_WAIT(N(EVS_Defuse))
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_HurtLit)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVarE)
            EVT_SWITCH(LVarE)
                EVT_CASE_FLAG(DAMAGE_TYPE_WATER)
                    EVT_EXEC_WAIT(N(EVS_Defuse))
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_CASE_FLAG(DAMAGE_TYPE_SHOCK)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnHurt)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_EXEC_WAIT(N(EVS_Explode))
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
                    EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
                    EVT_EXEC_WAIT(EVS_Enemy_Death)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Bobomb_HurtLit)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
                    EVT_IF_GT(LVar0, 0)
                        EVT_EXEC_WAIT(N(EVS_Explode))
                        EVT_SET_CONST(LVar0, PRT_MAIN)
                        EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
                        EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
                        EVT_EXEC_WAIT(EVS_Enemy_Death)
                        EVT_RETURN
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_DEATH)
        EVT_CASE_OR_EQ(EVENT_EXPLODE_TRIGGER)
            EVT_EXEC_WAIT(N(EVS_Explode))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
            EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_IdleLit)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetLastElement, LVarE)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_WATER)
                EVT_EXEC_WAIT(N(EVS_Defuse))
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_Hurt)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Explode))
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
                EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(EVS_Explode))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
            EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_IdleLit)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(EVS_Cleanup))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_Run)
            EVT_SET_CONST(LVar2, ANIM_Bobomb_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bobomb_DizzyLit)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetDamageSource, LVar0)
            EVT_IF_EQ(LVar0, DMG_SRC_HURRICANE)
                EVT_EXEC_WAIT(N(EVS_Defuse))
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_Dizzy)
            EVT_ELSE
                EVT_CHILD_THREAD
                    EVT_WAIT(100)
                    EVT_EXEC_WAIT(N(EVS_Explode))
                EVT_END_CHILD_THREAD
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Bobomb_DizzyLit)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_EXEC_WAIT(N(EVS_Defuse))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Tackle) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Run)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Dizzy)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(8)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Buildup)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_PLAY_EFFECT(EFFECT_FLASHING_BOX_SHOCKWAVE, 0, LVar0, LVar1, LVar2, LVar4, LVar3, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_SHOCK)
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(EVS_Explode))
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_BLAST, 0, 0, DMG_EXPLOSION, BS_FLAGS1_TRIGGER_EVENTS)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Idle)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_WAIT(4)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Blast) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(PlayLoopingSoundAtActor, ACTOR_SELF, 0, SOUND_LOOP_BOBOMB_FUSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_RunLit)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 80, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, -1, 14, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 90)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_RunLit)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_Explode))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_BurnStill)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, -1)
            EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_RunLit)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_Buildup)
    EVT_WAIT(15)
    EVT_SET(LVarA, 1)
    EVT_EXEC_WAIT(N(EVS_Explode))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bobomb_BurnStill)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_EXPLOSION, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(15)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_Bobomb_BurnStill)
    EVT_SET(LVar2, EXEC_DEATH_NO_SPINNING)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Ignited, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_Blast))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
