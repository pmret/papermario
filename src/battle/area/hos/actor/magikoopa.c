#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "sprite/npc/Magikoopa.h"

#define NAMESPACE b_area_hos_magikoopa

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(DefenseTable_flying)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

s32 N(StatusTable_flying)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

extern s32 N(IdleAnimations)[];

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

extern s32 N(IdleAnimations_flying)[];
extern s32 N(IdleAnimations_broomstick)[];

ActorPartBlueprint N(parts_flying)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable_flying),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_flying),
        .defenseTable = N(DefenseTable_flying),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_broomstick),
        .defenseTable = N(DefenseTable_flying),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

extern EvtScript N(init_8021E100);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_MAGIKOOPA_BOSS,
    .level = 32,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init_8021E100),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 36, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(init_8021E2C0);

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS,
    .level = 32,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts_flying)),
    .partsData = N(parts_flying),
    .initScript = &N(init_8021E2C0),
    .statusTable = N(StatusTable_flying),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 48, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL,    ANIM_Magikoopa_Anim01,
    STATUS_STONE,     ANIM_Magikoopa_Anim00,
    STATUS_SLEEP,     ANIM_Magikoopa_Anim08,
    STATUS_POISON,    ANIM_Magikoopa_Anim01,
    STATUS_STOP,      ANIM_Magikoopa_Anim00,
    STATUS_STATIC,    ANIM_Magikoopa_Anim01,
    STATUS_PARALYZE,  ANIM_Magikoopa_Anim00,
    STATUS_DIZZY,     ANIM_Magikoopa_Anim07,
    STATUS_FEAR,      ANIM_Magikoopa_Anim07,
    STATUS_END,
};

s32 N(IdleAnimations_flying)[] = {
    STATUS_NORMAL,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_STONE,     ANIM_FlyingMagikoopa_Anim00,
    STATUS_SLEEP,     ANIM_FlyingMagikoopa_Anim08,
    STATUS_POISON,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_STOP,      ANIM_FlyingMagikoopa_Anim00,
    STATUS_STATIC,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_PARALYZE,  ANIM_FlyingMagikoopa_Anim00,
    STATUS_DIZZY,     ANIM_FlyingMagikoopa_Anim07,
    STATUS_FEAR,      ANIM_FlyingMagikoopa_Anim07,
    STATUS_END,
};

s32 N(IdleAnimations_broomstick)[] = {
    STATUS_NORMAL,    ANIM_FlyingMagikoopa_Anim0A,
    STATUS_END,
};

EvtScript N(idle_8021D774) = {
    EVT_RETURN
    EVT_END
};

#include "common/ShrinkActor.inc.c"

#include "common/GetSelectedMoveID.inc.c"

EvtScript N(8021D784) = {
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_200 | BS_FLAGS1_40)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(MOVE_HEADBONK1)
            EVT_CASE_OR_EQ(MOVE_HEADBONK2)
            EVT_CASE_OR_EQ(MOVE_HEADBONK3)
            EVT_CASE_OR_EQ(MOVE_MULTIBONK)
                EVT_CALL(GetBattleFlags, LVar0)
                EVT_IF_FLAG(LVar0, BS_FLAGS1_200 | BS_FLAGS1_40)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

#include "common/StartRumbleWithParams.inc.c"

extern EvtScript N(handleEvent_8021E6D8);

EvtScript N(8021D890) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetLastElement, LVar0)
    EVT_IF_FLAG(LVar0, 0x400)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, 0x80000)
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, 0x00800000, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, 0x00020001, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 0x00020001, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 0x00800000, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 0x00100000, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 1, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
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
    EVT_IF_EQ(LVar3, 15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim04)
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
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 1, TRUE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 1, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 1, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021E6D8)))
    EVT_CALL(SetActorType, ACTOR_SELF, 149)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 32)
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

EvtScript N(runAway) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 57)
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
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021E0B0) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, -2) // TODO
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_80223B24);

EvtScript N(init_8021E100) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021D774)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80223B24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021E6D8)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_8021E0B0)))
    EVT_CALL(GetBattleVar, 2, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, -1)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(handleEvent_8021EDF0);

EvtScript N(init_8021E2C0) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021D774)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80223B24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021EDF0)))
    EVT_CALL(GetBattleVar, 2, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E46C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(GetLastElement, LVarA)
    EVT_IF_FLAG(LVarA, 0x20000000)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVarA)
        EVT_IF_FLAG(LVarA, BS_FLAGS1_100)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, -1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, 0x200)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, 0x00400000, FALSE)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, 0x00400000, FALSE)
    EVT_END_IF
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(RemoveActor, LVar0)
    EVT_THREAD
        EVT_ADD(LVar3, 2)
        EVT_LOOP(2)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021E6D8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(9)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, 0x1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(61)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x1)
                EVT_EXEC_WAIT(N(8021E46C))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(8021E46C))
            EVT_END_IF
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
            EVT_EXEC_WAIT(N(runAway))
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim02)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LVar0, 0x80000)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 1, 0, 2, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 1, -4, 5, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(31)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(19)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021EDF0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 2, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(9)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, 0x1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(12)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_EXEC_WAIT(N(8021D890))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(61)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(15)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_EXEC_WAIT(N(8021D890))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x1)
                EVT_EXEC_WAIT(N(8021E46C))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(8021E46C))
            EVT_END_IF
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(56)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(53)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
            EVT_EXEC_WAIT(N(runAway))
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim02)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LVar0, 0x80000)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, -3, 0, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, -15, 0, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(31)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(19)
            EVT_SET_CONST(LVar0, 0x00000002)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(healOne) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 0)
    EVT_CALL(AddActorVar, ACTOR_SELF, 4, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_206D)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_214)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_25C)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(HealActor, LVarB, 0, FALSE)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(healAll) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, 3, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, 8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, LVar0, SOUND_206D)
            EVT_CALL(PlaySoundAtActor, LVar0, SOUND_214)
            EVT_WAIT(30)
            EVT_CALL(PlaySoundAtActor, LVar0, SOUND_25C)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(func_8026BF48, 1)
            EVT_CALL(HealActor, LVar0, 0, TRUE)
            EVT_CALL(func_8026BF48, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(WaitForBuffDone)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shapeSpell) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 2)
    EVT_SET(LocalFlag(0), 0)
    EVT_SET(LocalFlag(1), 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVarA)
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, 0x200)
        EVT_SET(LocalFlag(1), 1)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_IF_EQ(LocalFlag(1), 0)
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 17)
            EVT_ADD(LVar1, 33)
            EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, 0x80000)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 13)
        EVT_ELSE
            EVT_SUB(LVar0, 17)
            EVT_ADD(LVar1, 33)
        EVT_END_IF
        EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
    EVT_ELSE
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, 0x80000)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
        EVT_END_IF
        EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar9, 0, 0, 1, 16)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_IF_EQ(LocalFlag(1), 0)
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim03)
            EVT_ELSE
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim03)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            EVT_SUB(LVar4, 50)
            EVT_SET(LVar5, 0)
            EVT_IF_EQ(LocalFlag(1), 0)
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                    EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_FLAG(LVar3, 0x80000)
                    EVT_SUB(LVar0, 8)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            EVT_ELSE
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                    EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_FLAG(LVar3, 0x80000)
                    EVT_SUB(LVar0, 8)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            EVT_END_IF
            EVT_WAIT(50)
            EVT_IF_EQ(LVar9, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, LVarA, TRUE)
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_IF_EQ(LocalFlag(1), 0)
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim03)
    EVT_ELSE
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim03)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_IF_EQ(LocalFlag(1), 0)
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
            EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, 0x80000)
            EVT_SUB(LVar0, 8)
            EVT_ADD(LVar1, 8)
        EVT_ELSE
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    EVT_ELSE
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
            EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, 0x80000)
            EVT_SUB(LVar0, 8)
            EVT_ADD(LVar1, 8)
        EVT_ELSE
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    EVT_END_IF
    EVT_WAIT(18)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_ELSE
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(UseIdleAnimation, LVarA, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80221144) = {
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_MOD(LVar1, 4)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LocalFlag(11), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LocalFlag(12), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LocalFlag(13), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LocalFlag(14), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LVar0, -1)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar1)
    EVT_MOD(LVar1, 4)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(LocalFlag(12), 0)
                EVT_SET(LVar0, 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LocalFlag(11), 0)
                EVT_SET(LVar0, 0)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(13), 0)
                EVT_SET(LVar0, 2)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LocalFlag(12), 0)
                EVT_SET(LVar0, 1)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(14), 0)
                EVT_SET(LVar0, 3)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LocalFlag(13), 0)
                EVT_SET(LVar0, 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(GetActorFlags, ACTOR_SELF, LVar1)
        EVT_IF_FLAG(LVar1, 0x200)
            EVT_ADD(LVar0, 4)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022142C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8022143C) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022142C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80221478) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022142C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_RETURN
    EVT_END
};

s32 N(DefenseTable_802214B4)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(DefenseTable_802214C0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable_802214CC)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

s32 N(StatusTable_80221578)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable_80221624)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable_802214B4),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

ActorPartBlueprint N(PartsTable_80221648)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_flying),
        .defenseTable = N(DefenseTable_802214C0),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint N(clone) = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_MAGICLONE,
    .level = 26,
    .maxHP = 11,
    .partCount = ARRAY_COUNT( N(PartsTable_80221624)),
    .partsData = N(PartsTable_80221624),
    .initScript = &N(init_8022143C),
    .statusTable = N(StatusTable_802214CC),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 36, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 32 },
};

ActorBlueprint N(flying_clone) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_FLYING_MAGICLONE,
    .level = 26,
    .maxHP = 11,
    .partCount = ARRAY_COUNT( N(PartsTable_80221648)),
    .partsData = N(PartsTable_80221648),
    .initScript = &N(init_80221478),
    .statusTable = N(StatusTable_80221578),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusMessageOffset = { 1, 34 },
};

Vec3i N(vector3D_802216BC) = { 0, 0xFFFFFC18, 0 };

Formation N(specialFormation_802216C8) = {
    { .actor = &N(clone), .home = { .vec = &N(vector3D_802216BC) }},
};

Formation N(specialFormation_802216E4) = {
    { .actor = &N(flying_clone), .home = { .vec = &N(vector3D_802216BC) }},
};

EvtScript N(makeCopy) = {
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 3)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, 0x200)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_802216C8)), 0)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_802216E4)), 0)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(EnableIdleScript, LVarA, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST3)
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 23)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 23)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(EnableIdleScript, LVar9, 1)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, -3)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_SET(LVar9, LVarA)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST4)
    EVT_CALL(PlaySoundAtActor, LVar9, SOUND_SPELL_CAST4)
    EVT_CALL(SetPartFlagBits, LVar9, 1, 0x00800000, FALSE)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(80221144))
        EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    EVT_ELSE
        EVT_CALL(SetActorSpeed, LVar9, EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(80221144))
        EVT_CALL(SetGoalToIndex, LVar9, LVar0)
        EVT_CALL(FlyToGoal, LVar9, 0, 0, EASING_LINEAR)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, LVar9, 1, 0x00800000, TRUE)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, LVar9, LVar0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorPos, LVar9, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVar9, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVar9)
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, 0x00400000, TRUE)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, 0x00400000, TRUE)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
        EVT_CALL(SetAnimation, LVar9, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
        EVT_CALL(SetAnimation, LVar9, 1, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseIdleAnimation, LVar9, TRUE)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc52.inc.c"

EvtScript N(boostAttack) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetActorAttackBoost, LVar0, LVar4)
            EVT_IF_LT(LVar4, 0)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 4)
    EVT_CALL(AddActorVar, ACTOR_SELF, 5, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_2DD)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(BoostAttack, LVar8, 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(boostDefense) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetActorDefenseBoost, LVar0, LVar4)
            EVT_IF_LT(LVar4, 0)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 5)
    EVT_CALL(AddActorVar, ACTOR_SELF, 6, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_2DD)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(BoostDefense, LVar8, 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(electrify) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetStatusFlags, LVar0, LVar4)
            EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_TRANSPARENT | STATUS_FLAG_STATIC)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 6)
    EVT_CALL(AddActorVar, ACTOR_SELF, 7, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2F0)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, LVar8, SOUND_3D2)
            EVT_CALL(RandInt, 3, LVar0)
            EVT_ADD(LVar0, 3)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(ElectrifyActor, LVar8, 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(vanish) = {
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetStatusFlags, LVar0, LVar4)
            EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_TRANSPARENT | STATUS_FLAG_STATIC)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 7)
    EVT_CALL(AddActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, 0x80000)
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
        EVT_IF_FLAG(LVarA, 0x80000)
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
    EVT_IF_NOT_FLAG(LVar0, 0x200)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_2DB)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(VanishActor, LVar8, 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80223B24) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(shapeSpell))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, 8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LVar0, LVar2)
    EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar2, LVar3)
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_IF_LE(LVar2, 0)
            EVT_CALL(RandInt, 99, LVar4)
            EVT_ADD(LVar4, 1)
            EVT_IF_LT(LVar4, 0)
                EVT_ADD(LVarA, 1)
                EVT_SET(LVarB, LVar0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, 8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LVar0, LVar2)
    EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar2, LVar3)
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_IF_LE(LVar2, 0)
            EVT_CALL(RandInt, 99, LVar4)
            EVT_ADD(LVar4, 1)
            EVT_IF_LT(LVar4, 0)
                EVT_ADD(LVarA, 1)
                EVT_SET(LVarB, LVar0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, 8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LocalFlag(0), 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LVar0, LVar2)
    EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar2, LVar3)
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_IF_LE(LVar2, 0)
            EVT_CALL(RandInt, 99, LVar4)
            EVT_ADD(LVar4, 1)
            EVT_IF_LT(LVar4, 0)
                EVT_ADD(LVarA, 1)
                EVT_SET(LVarB, LVar0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_GOTO(20)
    EVT_LABEL(10)
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVarA, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
        EVT_IF_LT(LVar0, 0)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_EXEC_WAIT(N(healOne))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 0)
                    EVT_EXEC_WAIT(N(healAll))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
        EVT_IF_LT(LVar0, 0)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_EXEC_WAIT(N(healAll))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_SETF(LVar9, EVT_FLOAT(100.0))
                EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
                EVT_CALL(InitTargetIterator)
                EVT_LABEL(11)
                EVT_SET(LocalFlag(0), 0)
                EVT_CALL(GetOwnerTarget, LVar0, LVar1)
                EVT_CALL(GetOriginalActorType, LVar0, LVar1)
                EVT_IF_EQ(LVar1, 71)
                    EVT_CALL(GetActorVar, LVar0, 8, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(GetActorHP, LVar0, LVar2)
                EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
                EVT_MULF(LVar2, EVT_FLOAT(100.0))
                EVT_DIVF(LVar2, LVar3)
                EVT_IF_EQ(LocalFlag(0), 0)
                    EVT_IF_LE(LVar2, LVar9)
                        EVT_SETF(LVar9, LVar2)
                        EVT_SET(LVarB, LVar0)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
                EVT_IF_NE(LVar0, -1)
                    EVT_GOTO(11)
                EVT_END_IF
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 0)
                    EVT_EXEC_WAIT(N(healOne))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(20)
    EVT_SET(LVarA, 100)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, 0)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LVarA, 100)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_SET(LVarD, 0)
        EVT_SET(LVarE, 0)
        EVT_SET(LVarF, 0)
        EVT_GOTO(123)
    EVT_ELSE
        EVT_EXEC_WAIT(N(80221144))
        EVT_IF_EQ(LVar0, -1)
            EVT_SET(LVarB, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 11, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(4)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
            EVT_IF_LT(LVar1, 0)
                EVT_CALL(RandInt, 99, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_IF_LE(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 100)
                    EVT_SET(LVarD, 0)
                    EVT_SET(LVarE, 0)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar1)
            EVT_IF_LT(LVar1, 0)
                EVT_CALL(RandInt, 99, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_IF_LE(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 0)
                    EVT_SET(LVarD, 100)
                    EVT_SET(LVarE, 0)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarC, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarD, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarE, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarF, 0)
    EVT_END_IF
    EVT_LABEL(123)
    EVT_SET(LVar9, 0)
    EVT_ADD(LVar9, LVarA)
    EVT_ADD(LVar9, LVarB)
    EVT_ADD(LVar9, LVarC)
    EVT_ADD(LVar9, LVarD)
    EVT_ADD(LVar9, LVarE)
    EVT_ADD(LVar9, LVarF)
    EVT_SUB(LVar9, 1)
    EVT_CALL(RandInt, LVar9, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(shapeSpell))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarB)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(makeCopy))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarC)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(boostAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarD)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(boostDefense))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarE)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(electrify))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(vanish))
    EVT_RETURN
    EVT_END
};
