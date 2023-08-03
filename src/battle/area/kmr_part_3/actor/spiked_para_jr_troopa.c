#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/SpikedParaJrTroopa.h"

#define NAMESPACE A(spiked_para_jr_troopa)

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
};

s32 N(IdleAnimations_80227F00)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpikedParaJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_SpikedParaJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_SpikedParaJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_80227F44)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_OutOfBreath,
    STATUS_END,
};

s32 N(IdleAnimations_80227F50)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(DefenseTable_80227F5C)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable_80227F68)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           45,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               70,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts_80228014)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 32 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80227F00),
        .defenseTable = N(DefenseTable_80227F5C),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -11 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80227F44),
        .defenseTable = N(DefenseTable_80227F5C),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

extern EvtScript N(init_80228618);

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_JR_TROOPA4,
    .level = 59,
    .maxHP = 40,
    .partCount = ARRAY_COUNT( N(ActorParts_80228014)),
    .partsData = N(ActorParts_80228014),
    .initScript = &N(init_80228618),
    .statusTable = N(StatusTable_80227F68),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 60, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 35 },
    .statusTextOffset = { 10, 25 },
};

EvtScript N(80228084) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_FLAG(LVar2, STATUS_FLAGS_IMMOBILIZED)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar2)
    EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar2, MOVE_SPOOK)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_263)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 30)
            EVT_CALL(ShowEmote, 0x00000000, EMOTE_QUESTION, -45, 30, EMOTER_POS, LVar0, LVar1, LVar2, 5)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802281B4) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B9)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, 0x80000)
        EVT_ADD(LVar1, 16)
    EVT_ELSE
        EVT_ADD(LVar1, 6)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(32)
            EVT_WAIT(1)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(32)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_300)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 40, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 4, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802284DC) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_07)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(80228574) = {
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(802285B4) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_8022936C);
extern EvtScript N(idle_802286C0);
extern EvtScript N(handleEvent_802287D0);
extern EvtScript N(nextTurn_80229B38);

EvtScript N(init_80228618) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022936C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_802286C0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_802287D0)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_80229B38)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(idle_802286C0) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -15, 28)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 4, -6)
        EVT_CALL(N(SetAbsoluteStatusOffsets), -25, 27, -1, 27)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -8, 33)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -6)
        EVT_CALL(N(SetAbsoluteStatusOffsets), -22, 30, 2, 28)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(80228FE8);
extern EvtScript N(8022906C);
extern EvtScript N(8022A018);
extern EvtScript N(8022A39C);
extern EvtScript N(8022A480);

EvtScript N(handleEvent_802287D0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(9)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(10)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8022906C))
            EVT_EXEC_WAIT(N(80228084))
            EVT_EXEC_WAIT(N(8022A480))
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2293770)
            EVT_SET(LVar2, 2293771)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(8022906C))
        EVT_CASE_EQ(36)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2293770)
            EVT_SET(LVar2, 2293771)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_BurnStill)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(8022906C))
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_EXEC_WAIT(N(8022A39C))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Still)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_EXEC_WAIT(N(80228084))
            EVT_EXEC_WAIT(N(8022A480))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(27)
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_SWITCH(LVar3)
                EVT_CASE_FLAG(266240)
                    EVT_ADD(LVar0, -13)
                    EVT_ADD(LVar1, 37)
                EVT_CASE_FLAG(524288)
                    EVT_ADD(LVar0, -1)
                    EVT_ADD(LVar1, 14)
                EVT_CASE_DEFAULT
                    EVT_ADD(LVar0, -4)
                    EVT_ADD(LVar1, 37)
            EVT_END_SWITCH
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(58)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Flail)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Flail)
                EVT_WAIT(20)
                EVT_EXEC_WAIT(N(802284DC))
                EVT_CALL(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, PRT_MAIN, 0x0023000F, 0x0023000F)
                EVT_EXEC_WAIT(N(80228574))
            EVT_END_IF
        EVT_CASE_EQ(42)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(8022A39C))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpikedParaJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80228FE8) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetLastDamage, ACTOR_SELF, LVar1)
        EVT_IF_NE(LVar1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8022906C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, 0x351000)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
            EVT_EXEC_WAIT(N(802284DC))
            EVT_CALL(ActorSpeak, MSG_MAC_Port_00BC, ACTOR_SELF, PRT_MAIN, -1, -1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
            EVT_EXEC_WAIT(N(80228574))
        EVT_ELSE
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80229160) = {
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022936C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 6, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_20E0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(LVar0, 80)
            EVT_SET(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_20E0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_WAIT(10)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(func_802189DC_447E1C) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    s32 icon = hud_element_create(&HES_AnimatedHandPointer);

    hud_element_set_render_pos(icon, posX, posY);
    hud_element_set_scale(icon, 1.5f);
    hud_element_clear_flags(icon, HUD_ELEMENT_FLAG_200000 | HUD_ELEMENT_FLAG_DISABLED);
    evt_set_variable(script, *args++, icon);
    load_tattle_flags(ACTOR_TYPE_JR_TROOPA4);
    return ApiStatus_DONE2;
}

#include "common/FreeIcon.inc.c"

EvtScript N(nextTurn_80229B38) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetBattleCamOffsetZ, 35)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_MAC_Port_00B8, ACTOR_SELF, PRT_2, 0x00210005, 0x00210005)
                EVT_WAIT(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, 0x00001000, TRUE)
                EVT_CALL(func_8026D940, ACTOR_SELF, -20, 40)
                EVT_CALL(ShowHealthBar, ACTOR_SELF)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_SET(LVar0, 115)
                EVT_SET(LVar1, 150)
                EVT_CALL(func_802189DC_447E1C, LVar0, LVar1, LVarA)
                EVT_WAIT(10)
                EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
                EVT_LABEL(0)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
                EVT_IF_GT(LVar0, 20)
                    EVT_GOTO(0)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_JrTroopa_Panic)
                EVT_WAIT(15)
                EVT_LOOP(2)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 0x00001000, FALSE)
                    EVT_WAIT(15)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 0x00001000, TRUE)
                    EVT_WAIT(15)
                EVT_END_LOOP
                EVT_CALL(ActorSpeak, MSG_MAC_Port_00B9, ACTOR_SELF, PRT_2, 0x00210013, 0x00210013)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, 0x00001000, FALSE)
                EVT_CALL(N(FreeIcon), LVarA)
                EVT_CALL(HideHealthBar, ACTOR_SELF)
                EVT_CALL(func_8026D940, ACTOR_SELF, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_JrTroopa_OutOfBreath)
                EVT_WAIT(25)
                EVT_CALL(ActorSpeak, MSG_MAC_Port_00BA, ACTOR_SELF, PRT_2, 0x00210016, 0x00210003)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(802281B4))
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, 1, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, 1, FALSE)
                EVT_WAIT(20)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 80, 0)
                EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_LINEAR)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(HPBarToHome, ACTOR_SELF)
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, MSG_MAC_Port_00BB, ACTOR_SELF, PRT_MAIN, 0x0023000F, 0x00230003)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(80228574))
            EVT_END_IF
        EVT_CASE_EQ(12)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A018) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar1, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(FallToGoal, ACTOR_SELF, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(ShowHealthBar, ACTOR_SELF)
    EVT_LABEL(0)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_ADD(LVar2, 10)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, 1, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, 1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_JrTroopa_DefeatedBegin)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_80227F50)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 0x00400000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A39C) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar4, LVar1)
    EVT_MULF(LVar4, EVT_FLOAT(0.3))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, LVar4, EASING_LINEAR)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A480) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(802284DC))
            EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_MAIN, 0x0023000F, 0x00230003)
            EVT_EXEC_WAIT(N(80228574))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
