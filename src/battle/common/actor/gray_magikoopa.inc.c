#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/FlyingMagikoopa.h"

#define NAMESPACE A(gray_magikoopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Init_Flying);
extern EvtScript N(EVS_TakeTurn);

extern EvtScript N(EVS_Flee);

extern s32 N(GroundAnims)[];
extern s32 N(FlyingAnims)[];
extern s32 N(BroomAnims)[];

enum N(ActorPartIDs) {
    PRT_GROUND      = 1,
    PRT_FLYING      = 2,
    PRT_BROOM       = 3,
};

enum N(ActorVars) {
    AVAR_ShouldKnockDown    = 0,
};

enum N(ActorParams) {
    DMG_MAGIC_BLAST     = 3,
    DMG_WAND_STRIKE     = 3,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
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
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
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
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(GroundParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

ActorPartBlueprint N(FlyingParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAG_RIDING_BROOMSTICK,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BROOM,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BroomAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GRAY_MAGIKOOPA,
    .level = ACTOR_LEVEL_GRAY_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(GroundParts)),
    .partsData = N(GroundParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 32 },
};

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA,
    .level = ACTOR_LEVEL_FLYING_GRAY_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(FlyingParts)),
    .partsData = N(FlyingParts),
    .initScript = &N(EVS_Init_Flying),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 40,
    .airLiftChance = 95,
    .hurricaneChance = 75,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusTextOffset = { 1, 34 },
};

s32 N(GroundAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Magikoopa_Gray_Anim01,
    STATUS_KEY_STONE,     ANIM_Magikoopa_Gray_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Magikoopa_Gray_Anim08,
    STATUS_KEY_POISON,    ANIM_Magikoopa_Gray_Anim01,
    STATUS_KEY_STOP,      ANIM_Magikoopa_Gray_Anim00,
    STATUS_KEY_STATIC,    ANIM_Magikoopa_Gray_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Magikoopa_Gray_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Magikoopa_Gray_Anim07,
    STATUS_KEY_FEAR,      ANIM_Magikoopa_Gray_Anim07,
    STATUS_END,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Gray_Anim01,
    STATUS_KEY_STONE,     ANIM_FlyingMagikoopa_Gray_Anim00,
    STATUS_KEY_SLEEP,     ANIM_FlyingMagikoopa_Gray_Anim08,
    STATUS_KEY_POISON,    ANIM_FlyingMagikoopa_Gray_Anim01,
    STATUS_KEY_STOP,      ANIM_FlyingMagikoopa_Gray_Anim00,
    STATUS_KEY_STATIC,    ANIM_FlyingMagikoopa_Gray_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_FlyingMagikoopa_Gray_Anim00,
    STATUS_KEY_DIZZY,     ANIM_FlyingMagikoopa_Gray_Anim07,
    STATUS_KEY_FEAR,      ANIM_FlyingMagikoopa_Gray_Anim07,
    STATUS_END,
};

s32 N(BroomAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Gray_Anim0A,
    STATUS_END,
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

#include "common/ShrinkActor.inc.c"
#include "common/GetSelectedMoveID.inc.c"
#include "common/battle/SetAbsoluteStatusOffsets.inc.c"
#include "common/StartRumbleWithParams.inc.c"
#include "common/battle/CheckMagikoopaCastTarget.inc.c"

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Gray_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Gray_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim02)
            EVT_EXEC_WAIT(N(EVS_Flee))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, 0, 2, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, -4, 5, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KnockDownCheck) = {
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(MOVE_HEADBONK1)
            EVT_CASE_OR_EQ(MOVE_HEADBONK2)
            EVT_CASE_OR_EQ(MOVE_HEADBONK3)
            EVT_CASE_OR_EQ(MOVE_MULTIBONK)
                EVT_CALL(GetBattleFlags, LVar0)
                EVT_IF_FLAG(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, TRUE)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KnockDown) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetLastElement, LVar0)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_POW)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_BROOM, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BROOM, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 150, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, EVENT_15)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim04)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_ADD(LVar4, 10)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 10, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim01)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_GRAY_MAGIKOOPA)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 32)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_Flying) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(EVS_KnockDownCheck))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_FALL_TRIGGER)
            EVT_EXEC_WAIT(N(EVS_KnockDownCheck))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_KnockDown))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_15)
            EVT_EXEC_WAIT(N(EVS_KnockDownCheck))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Gray_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_KnockDown))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Gray_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim01)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim01)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim02)
            EVT_EXEC_WAIT(N(EVS_Flee))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -3, 0, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -15, 0, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Gray_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_MagicBlast) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SUB(LVar0, 12)
        EVT_ADD(LVar1, 14)
    EVT_ELSE
        EVT_SUB(LVar0, 30)
        EVT_ADD(LVar1, 36)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim02)
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim03)
            EVT_WAIT(5)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar9)
            EVT_IF_FLAG(LVar9, STATUS_FLAG_SHRINK)
                EVT_SUB(LVar0, 8)
                EVT_ADD(LVar1, 8)
            EVT_ELSE
                EVT_SUB(LVar0, 20)
                EVT_ADD(LVar1, 20)
            EVT_END_IF
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 50)
            EVT_SET(LVar4, 0)
            EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar5, LVar3, LVar4, LVar5, 25)
            EVT_WAIT(50)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(14)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim03)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SUB(LVar0, 8)
        EVT_ADD(LVar1, 8)
    EVT_ELSE
        EVT_SUB(LVar0, 20)
        EVT_ADD(LVar1, 20)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 10)
    EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar5, LVar3, LVar4, LVar5, 20)
    EVT_WAIT(18)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MAGIC_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(19)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_WandStrike) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_VANISH)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim02)
        EVT_SET(LVar0, 200)
        EVT_LOOP(20)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 5)
    EVT_ELSE
        EVT_ADD(LVar0, 25)
    EVT_END_IF
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    EVT_SET(LVar0, 55)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 10)
        EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim03)
    EVT_WAIT(11)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_WAND_STRIKE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_SET(LVar0, 200)
            EVT_LOOP(20)
                EVT_SUB(LVar0, 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim01)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            EVT_SET(LVar0, 55)
            EVT_LOOP(20)
                EVT_ADD(LVar0, 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WAND_STRIKE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(10)
            EVT_SET(LVar0, 200)
            EVT_LOOP(20)
                EVT_SUB(LVar0, 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim01)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
            EVT_SET(LVar0, 55)
            EVT_LOOP(20)
                EVT_ADD(LVar0, 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flee) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, EVENT_SCARE_AWAY)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init_Flying) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent_Flying)))
    EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
        EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
        EVT_CALL(InitTargetIterator)
        EVT_LABEL(0)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(GetIndexFromHome, LVar0, LVar1)
            EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar2)
            EVT_IF_GT(LVar1, LVar2)
                EVT_CALL(N(CheckMagikoopaCastTarget), LVar0, LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_CALL(GetStatusFlags, LVar0, LVar4)
                    EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_STATIC | STATUS_FLAG_TRANSPARENT)
                        EVT_SET(LVar8, LVar0)
                        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar1)
                        EVT_GOTO(100)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_IF_NE(LVar0, ITER_NO_MORE)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_SET(LFlag0, TRUE)
            EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flee))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_EXEC_WAIT(N(EVS_Attack_MagicBlast))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_WandStrike))
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(100) // make ally invisible
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Gray_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Gray_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_VANISH)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(VanishActor, LVar8, 2)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
