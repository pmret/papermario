#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Pokey.h"

#define NAMESPACE A(pokey_mummy)

extern s32 N(FourPartAnims)[];
extern s32 N(ThrownPartAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_KnockPartAway);
extern EvtScript N(EVS_Attack_SinglePartLeap);
extern EvtScript N(EVS_Pokey_SpinSmashHit);
extern EvtScript N(EVS_DecrementSize);
extern EvtScript N(EVS_Pokey_Hit);
extern EvtScript N(EVS_Pokey_ScareAway);

// while these parts seem set up to manage Pokeys changing size, its actually all handled via animations
// and the PRT_BODY* are always invisible
enum N(ActorPartIDs) {
    PRT_MAIN        = 1, // top part of a 4-part Pokey
    PRT_BODY3       = 2, // bottom part of a 4-part Pokey
    PRT_BODY2       = 3,
    PRT_BODY1       = 4,
    PRT_SINGLE      = 5, // single-part Pokey
    PRT_PROJECTILE  = 6, // part which is thrown
};

enum N(ActorVars) {
    AVAR_IN_CantSummon      = 1,
    AVAR_PartsThrown        = 0,
    AVAR_Anim_Immune        = 1,
    AVAR_Anim_Run           = 2,
    AVAR_Anim_Hit           = 3,
    AVAR_Anim_Windup        = 4,
    AVAR_Anim_Throw         = 5,
    AVAR_Anim_BurnHurt      = 6,
    AVAR_Anim_BurnStill     = 7,
    AVAR_CantSummon         = 9,
    AVAR_Generation         = 10,

    AVAL_Generation_First   = 0,
    AVAL_Generation_Second  = 1,
    AVAL_Generation_Last    = 2,
};

enum N(ActorParams) {
    DMG_THROW_PART         = 2, // throw a body part at the player
    DMG_LEAP               = 2, // jump onto the player, used when no more parts can be thrown
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
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

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(FourPartAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_BODY3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 72 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BODY2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BODY1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 36 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_SINGLE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_PROJECTILE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(ThrownPartAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_POKEY_MUMMY,
    .level = ACTOR_LEVEL_POKEY_MUMMY,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 90,
    .hurricaneChance = 85,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 24, 80 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusTextOffset = { 10, 65 },
};

s32 N(FourPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle4,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still4,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep4,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still4,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still4,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy4,
    STATUS_KEY_FEAR,      ANIM_Pokey_Mummy_Dizzy4,
    STATUS_END,
};

s32 N(ThreePartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle3,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still3,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep3,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still3,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still3,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy3,
    STATUS_KEY_FEAR,      ANIM_Pokey_Mummy_Dizzy3,
    STATUS_END,
};

s32 N(TwoPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle2,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still2,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep2,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still2,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still2,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy2,
    STATUS_KEY_FEAR,      ANIM_Pokey_Mummy_Dizzy2,
    STATUS_END,
};

s32 N(OnePartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle1,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still1,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep1,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still1,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still1,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy1,
    STATUS_KEY_FEAR,      ANIM_Pokey_Mummy_Dizzy1,
    STATUS_END,
};

s32 N(ThrownPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Projectile,
    STATUS_END,
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Generation, AVAL_Generation_First)
    // copy input var from Formation
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_CantSummon, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CantSummon, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle4)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run4)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt4)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Mummy_Windup3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Mummy_Throw3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt4)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill4)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
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
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_Pokey_Hit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, PRT_MAIN)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                            EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_WAIT(10)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_Pokey_Hit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, PRT_MAIN)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                            EVT_EXEC_WAIT(EVS_Enemy_Hit)
                            EVT_WAIT(10)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_Pokey_Hit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_Pokey_Hit))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(EVS_Pokey_SpinSmashHit))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(EVS_Pokey_SpinSmashHit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Pokey_Hit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Pokey_Hit))
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, -1)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Run, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Immune, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(AfflictActor, ACTOR_PLAYER, STATUS_KEY_POISON, 3)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 77)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Dizzy4)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 59)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Dizzy3)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 41)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Dizzy2)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar0, 0)
                    EVT_SET(LVar1, 23)
                    EVT_SET_CONST(LVar2, ANIM_Pokey_Mummy_Dizzy1)
            EVT_END_SWITCH
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar2)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar6)
            EVT_IF_FLAG(LVar6, STATUS_FLAG_SHRINK)
                EVT_MULF(LVar0, EVT_FLOAT(0.4))
                EVT_MULF(LVar1, EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_ADDF(LVar3, LVar0)
            EVT_ADDF(LVar4, LVar1)
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar3, LVar4, LVar5, 20, 0)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Immune, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(EVS_Pokey_ScareAway))
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    EVT_IF_EQ(LVarA, 3)
        EVT_EXEC_WAIT(N(EVS_Attack_SinglePartLeap))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_PROJECTILE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(2.2))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Mummy_Projectile)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(0)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 38)
                EVT_ELSE
                    EVT_ADD(LVar1, 15)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_CASE_EQ(1)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 20)
                EVT_ELSE
                    EVT_ADD(LVar1, 8)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_CASE_EQ(2)
                EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_ADD(LVar1, 3)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(1.2))
                EVT_END_IF
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_CASE_EQ(3)
        EVT_END_SWITCH
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_SWAY)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Windup, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    EVT_WAIT(12)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Throw, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_THROW)
    EVT_WAIT(3)
    EVT_EXEC_WAIT(N(EVS_DecrementSize))
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_CHILD_THREAD
                    EVT_WAIT(5)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_CHILD_THREAD
            EVT_END_IF
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 80)
            EVT_SUB(LVar1, 5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(20.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.1))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Mummy_Projectile)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Run, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(20.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Mummy_Projectile)
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 40), DMG_THROW_PART, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Run, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 55)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(4.0))
            EVT_SUB(LVar0, 24)
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(3.0))
            EVT_SUB(LVar0, 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, 20, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SinglePartLeap) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_POKEY_STEP, SOUND_POKEY_STEP)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_POKEY_STEP, SOUND_NONE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
    EVT_WAIT(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_SET(LVar1, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
            EVT_CHILD_THREAD
                EVT_WAIT(2)
                EVT_SET(LVar0, 0)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_CHILD_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 22, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
            EVT_CHILD_THREAD
                EVT_WAIT(2)
                EVT_SET(LVar0, 180)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_IF_EQ(LVar0, 360)
                        EVT_SET(LVar0, 0)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_CHILD_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
    EVT_CHILD_THREAD
        EVT_WAIT(2)
        EVT_SET(LVar0, 0)
        EVT_LOOP(5)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
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
            EVT_SUB(LVar0, 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Pokey_SpinSmashHit) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SET_CONST(LVar0, PRT_MAIN)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
        EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_KnockPartAway))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_KnockPartAway))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_KnockPartAway))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DecrementSize) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle3)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run3)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt3)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Mummy_Windup2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Mummy_Throw2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt3)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill3)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ThreePartAnims)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY3, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY3, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, PRT_MAIN, 62, EVT_IGNORE_ARG)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -15, 55, 10, 45)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Mummy_Windup1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Mummy_Throw1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill2)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(TwoPartAnims)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 2)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, PRT_MAIN, 44, EVT_IGNORE_ARG)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -15, 35, 10, 25)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(OnePartAnims)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SINGLE, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SINGLE, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 3)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            EVT_CALL(SetPartSize, ACTOR_SELF, PRT_MAIN, 26, EVT_IGNORE_ARG)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -15, 15, 10, 5)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitReactionBounce) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 18)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_WAIT(2)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(3)
    EVT_SUB(LVar3, 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(2)
    EVT_SUB(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 7)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar3, 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 3)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KnockPartAway) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_DecrementSize))
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_EXEC_WAIT(N(EVS_HitReactionBounce))
    EVT_END_CHILD_THREAD
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_PRIMARY_ONLY | TARGET_FLAG_ALLOW_TARGET_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerID, LVar1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_IF_NE(LVar1, LVar0)
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_LABEL(1)
        EVT_ADD(LVarF, 1)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_EQ(LVar0, ITER_NO_MORE)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_CALL(GetActorFlags, LVar0, LVar1)
        EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetOwnerID, LVar0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.1))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(7.0))
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, TRUE)
        EVT_CHILD_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_END_CHILD_THREAD
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
        EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(6.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, 296, 0, 0, 0, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Pokey_Hit) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_DecrementSize))
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_BurnedProjectile)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_EXEC_WAIT(N(EVS_HitReactionBounce))
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    EVT_IF_NE(LVarA, 3)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, EVT_FLOAT(6.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 30)
        EVT_SET(LVar1, 0)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 10, 18, EASING_LINEAR)
        EVT_ADD(LVar0, 20)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 8, 10, EASING_LINEAR)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_ELSE
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_DIV(LVar3, 2)
            EVT_ADD(LVar1, LVar3)
            EVT_ADD(LVar2, 5)
            EVT_DIVF(LVar3, EVT_FLOAT(10.0))
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_WAIT(10)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Pokey_ScareAway) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar9)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.05))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SET(LVarD, LVarB)
    EVT_ADD(LVarD, 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarD, LVarC)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FallToGoal, ACTOR_SELF, 10)
    EVT_WAIT(20)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_WAIT(5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 200, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(8)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
