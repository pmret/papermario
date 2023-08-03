#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/SpikedParaJrTroopa.h"
#include "sprite/npc/MageJrTroopa.h"

#define NAMESPACE A(final_jr_troopa)

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
    PRT_3               = 3,
};

s32 N(IdleAnimations_8022C370)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_8022C3A4)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpikedParaJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_SpikedParaJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_SpikedParaJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_8022C3D8)[] = {
    STATUS_KEY_NORMAL,    ANIM_MageJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_MageJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_MageJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_MageJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_8022C40C)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(DefenseTable_8022C418)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_END,
};

s32 N(DefenseTable_8022C424)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_END,
};

s32 N(DefenseTable_8022C430)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_END,
};

s32 N(StatusTable_8022C43C)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               60,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -2,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

s32 N(StatusTable_8022C4E8)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

s32 N(StatusTable_8022C594)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -2,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts_8022C640)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 26 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8022C370),
        .defenseTable = N(DefenseTable_8022C418),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -6 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 32 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8022C3A4),
        .defenseTable = N(DefenseTable_8022C424),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -11 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 28 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8022C3D8),
        .defenseTable = N(DefenseTable_8022C430),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -7 },
    },
};

extern EvtScript N(init_8022CF80);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA6,
    .level = 74,
    .maxHP = 60,
    .partCount = ARRAY_COUNT( N(ActorParts_8022C640)),
    .partsData = N(ActorParts_8022C640),
    .initScript = &N(init_8022CF80),
    .statusTable = N(StatusTable_8022C43C),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 35 },
    .statusTextOffset = { 10, 25 },
};

EvtScript N(8022C6D4) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_FLAG(LVar2, STATUS_FLAGS_IMMOBILIZED)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar2)
    EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar2, MOVE_SPOOK)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
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

EvtScript N(8022C804) = {
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

EvtScript N(8022CB2C) = {
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

EvtScript N(8022CBC4) = {
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022CC04) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(IdleAnimations_8022CC68)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

EvtScript N(8022CC74) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVar1)
    EVT_WAIT(10)
    EVT_CALL(GetDamageSource, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar2, 0)
            EVT_LOOP(24)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                EVT_ADD(LVar2, 30)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 10)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Collapse)
    EVT_WAIT(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, LVarA, EVT_PTR(N(IdleAnimations_8022CC68)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_8022D920);
extern EvtScript N(idle_8022D058);
extern EvtScript N(handleEvent_8022D1C4);
extern EvtScript N(nextTurn_8023147C);

EvtScript N(init_8022CF80) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 5)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022D920)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022D058)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022D1C4)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_8023147C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022D058) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
            EVT_IF_FLAG(LVarA, STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_2, -15, 28)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_2, 4, -6)
                EVT_CALL(N(SetAbsoluteStatusOffsets), -25, 27, -1, 27)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_2, -8, 33)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_2, 0, -6)
                EVT_CALL(N(SetAbsoluteStatusOffsets), -22, 30, 2, 28)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(N(SetAbsoluteStatusOffsets), -20, 35, 10, 25)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(802315F0);
extern EvtScript N(802318F8);
extern EvtScript N(80232040);
extern EvtScript N(80232170);

EvtScript N(handleEvent_8022D1C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(9)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(10)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8022C6D4))
            EVT_EXEC_WAIT(N(80232170))
        EVT_CASE_EQ(32)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(36)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_2, 0, 0, 0)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_EXEC_WAIT(N(80232040))
        EVT_CASE_EQ(38)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_2, 0, 0, 0)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET(LVar1, 5)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(25)
            EVT_SET(LVar1, 5)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_EXEC_WAIT(N(8022C6D4))
            EVT_EXEC_WAIT(N(80232170))
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
                EVT_SET(LVar1, 2)
                EVT_EXEC_WAIT(N(802315F0))
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_SET(LVar1, 5)
                EVT_EXEC_WAIT(N(802315F0))
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                EVT_WAIT(20)
                EVT_EXEC_WAIT(N(8022CB2C))
                EVT_SET(LVar1, 3)
                EVT_EXEC_WAIT(N(802315F0))
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                EVT_CALL(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, LVar0, -1, -1)
                EVT_EXEC_WAIT(N(8022CBC4))
            EVT_END_IF
        EVT_CASE_EQ(42)
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(80232040))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8022DD48);
extern EvtScript N(8022DF54);
extern EvtScript N(8022ED10);
extern EvtScript N(8022F468);
extern EvtScript N(80230034);
extern EvtScript N(80230794);
extern EvtScript N(8023106C);
extern EvtScript N(8022E198);

EvtScript N(takeTurn_8022D920) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_IF_NE(LVar0, 3)
        EVT_CALL(GetActorHP, ACTOR_SELF, LVar1)
        EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar2)
        EVT_MUL(LVar1, 100)
        EVT_DIV(LVar1, LVar2)
        EVT_IF_EQ(LVar0, 1)
            EVT_IF_LT(LVar1, 65)
                EVT_EXEC_WAIT(N(8022DD48))
            EVT_END_IF
        EVT_ELSE
            EVT_IF_LT(LVar1, 35)
                EVT_EXEC_WAIT(N(8022DF54))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LT(LVar0, 15)
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_IF_NOT_FLAG(LVar0, 0x2)
            EVT_BITWISE_OR_CONST(LVar0, 0x2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_Talk)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_Talk)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Talk)
            EVT_END_SWITCH
            EVT_CALL(ActorSpeak, MSG_CH8_0060, ACTOR_SELF, PRT_MAIN, -1, -1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 50)
                EVT_EXEC_WAIT(N(8022ED10))
            EVT_ELSE
                EVT_EXEC_WAIT(N(8022F468))
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_LT(60)
                    EVT_EXEC_WAIT(N(80230034))
                EVT_CASE_LT(80)
                    EVT_EXEC_WAIT(N(80230794))
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
                    EVT_IF_NE(LVar0, LVar1)
                        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar2)
                        EVT_IF_GT(LVar2, 0)
                            EVT_SUB(LVar2, 1)
                            EVT_CALL(SetActorVar, ACTOR_SELF, 4, LVar2)
                            EVT_EXEC_WAIT(N(8023106C))
                        EVT_ELSE
                            EVT_EXEC_WAIT(N(80230034))
                        EVT_END_IF
                    EVT_ELSE
                        EVT_EXEC_WAIT(N(80230034))
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(8022E198))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8022DD48) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(ActorSpeak, MSG_CH8_005E, ACTOR_SELF, PRT_MAIN, 0x00210018, 0x00210018)
    EVT_EXEC_WAIT(N(8022C804))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, 0x00020001, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, 0x00800000, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, 0x00020001, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, 0x00800000, TRUE)
    EVT_WAIT(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 60, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 2)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_8022C4E8)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022DF54) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(ActorSpeak, MSG_CH8_005F, ACTOR_SELF, PRT_2, 0x0023000F, 0x0023000F)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 120)
    EVT_EXEC_WAIT(N(8022C804))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, 0x00020001, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, 0x00800000, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, 0x00020001, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, 0x00800000, TRUE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FallToGoal, ACTOR_SELF, 10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 3)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_8022C594)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022E198) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 8, BS_FLAGS1_10)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(5)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Charge)
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_ChargeTripped)
            EVT_END_THREAD
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Trip)
            EVT_THREAD
                EVT_WAIT(3)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Defeated)
            EVT_END_THREAD
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 16, 0, EASING_CUBIC_OUT)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_ChargeArmsUp)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(6)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_20E2, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Jump)
            EVT_WAIT(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Midair)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 0)
            EVT_ADD(LVar2, 3)
            EVT_THREAD
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Fall)
            EVT_END_THREAD
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_PanicFast)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_20E2, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Jump)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Midair)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Fall)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
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
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
    EVT_WAIT(8)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022ED10) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_20E0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_Dive)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_WAIT(10)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(CalculateArcsinDeg));

EvtScript N(8022F468) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CLOSE_SHELL)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_EnterEgg)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_EggIdle)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 6, BS_FLAGS1_10)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_THREAD
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 10)
                EVT_SET(LVar1, 12)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_END_THREAD
            EVT_SET(LVar0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_LOOP(20)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, LVar0)
                EVT_SET(LVar1, LVar4)
                EVT_SET(LVar2, LVar5)
                EVT_SET(LVar3, LVar6)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LVarF, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_SUB(LVar1, 40)
                EVT_SET(LVar2, 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_LOOP(14)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                EVT_SET(LVar7, LVar0)
                EVT_ADD(LVar7, 180)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, LVar7)
                EVT_SET(LVar1, LVar4)
                EVT_SET(LVar2, LVar5)
                EVT_SET(LVar3, LVar6)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_2, 0, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_ExitEgg)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_2, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_2, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_2, 0, 12, 0)
    EVT_THREAD
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_SET(LVar0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_LOOP(20)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, LVar0)
        EVT_SET(LVar1, LVar4)
        EVT_SET(LVar2, LVar5)
        EVT_SET(LVar3, LVar6)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 9, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 40)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_LOOP(14)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
        EVT_SET(LVar7, LVar0)
        EVT_ADD(LVar7, 180)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, LVar7)
        EVT_SET(LVar1, LVar4)
        EVT_SET(LVar2, LVar5)
        EVT_SET(LVar3, LVar6)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_2, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_ExitEgg)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/CalculateArcsinDeg.inc.c"

EvtScript N(80230034) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 36)
        EVT_SETF(LVar5, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 14)
        EVT_SETF(LVar5, MapFlag(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(6)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 120)
            EVT_ADD(LVar4, 20)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x80000)
                EVT_SET(LVar6, -8)
                EVT_SET(LVar7, 20)
                EVT_SETF(LVar8, EVT_FLOAT(1.0))
            EVT_ELSE
                EVT_SET(LVar6, -3)
                EVT_SET(LVar7, 8)
                EVT_SETF(LVar8, MapFlag(-1999590))
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, LVar6)
            EVT_ADD(LVar1, LVar7)
            EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 30, 0)
            EVT_WAIT(35)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(5)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 12)
                EVT_PLAY_EFFECT(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(3.0), 30, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_BurnStaff)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_WAIT(40)
                EVT_SUB(LVar0, 7)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 4)
                EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_Idle)
            EVT_END_THREAD
            EVT_WAIT(20)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_WAIT(40)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 20)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_SET(LVar6, -8)
        EVT_SET(LVar7, 20)
        EVT_SETF(LVar8, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar6, -3)
        EVT_SET(LVar7, 8)
        EVT_SETF(LVar8, MapFlag(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar6)
    EVT_ADD(LVar1, LVar7)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 15, 0)
    EVT_WAIT(15)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/Dist3D.inc.c" // Not used?

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

EvtScript N(80230794) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 36)
        EVT_SETF(LVar5, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 14)
        EVT_SETF(LVar5, MapFlag(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 60, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(SetBackgroundAlpha), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(RandInt, 40, LVar1)
    EVT_ADD(LVar0, LVar1)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 200)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_366)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(6)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_WAIT(20)
            EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
            EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(RandInt, 40, LVar1)
            EVT_SUB(LVar0, LVar1)
            EVT_SET(LVar1, 200)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, 0, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 12)
                EVT_PLAY_EFFECT(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(3.0), 30, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_BurnStaff)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_WAIT(40)
                EVT_SUB(LVar0, 7)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 4)
                EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_Idle)
            EVT_END_THREAD
            EVT_WAIT(20)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
            EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
    EVT_WAIT(14)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT), 0, SUPPRESS_EVENT_FLAG_10000, 9, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(SetBackgroundAlpha), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023106C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 36)
        EVT_SETF(LVar5, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 14)
        EVT_SETF(LVar5, MapFlag(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2F8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_ADD(LVar2, 50)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar1, LVar2, LVar3, 10, 0)
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar1, LVar2, LVar3, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_3, ANIM_MageJrTroopa_Idle)
    EVT_WAIT(10)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    EVT_MUL(LVar0, 17)
    EVT_DIV(LVar0, 100)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(HealActor, ACTOR_SELF, LVar0, FALSE)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8023147C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x1)
                EVT_BITWISE_OR_CONST(LVar0, 0x1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_CALL(ActorSpeak, MSG_CH8_005D, ACTOR_SELF, PRT_MAIN, 0x0021001A, 0x0021001A)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            EVT_END_IF
        EVT_CASE_EQ(12)
        EVT_CASE_EQ(11)
        EVT_CASE_EQ(10)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802315F0) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar1, 2293769)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar1, 2359305)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, 2162705)
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar1, 2293770)
                    EVT_SET(LVar2, 2293771)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar1, 2359306)
                    EVT_SET(LVar2, 2359307)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, 2162728)
                    EVT_SET(LVar2, 2162729)
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar1, 2293776)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar1, 2359311)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, 2162730)
            EVT_END_SWITCH
        EVT_CASE_EQ(3)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar1, 2293775)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar1, 2359310)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, 2162710)
            EVT_END_SWITCH
        EVT_CASE_EQ(4)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar1, 2293767)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar1, 2359301)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, 2162697)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar1, 2293763)
                EVT_CASE_EQ(3)
                    EVT_SET(LVar1, 2359298)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, 2162691)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(802318F8) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_IF_EQ(LVar1, 0)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
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
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, 1, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, 1, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_DefeatedBegin)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Defeated)
            EVT_WAIT(60)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(3)
            EVT_CALL(HideHealthBar, ACTOR_SELF)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(GetDamageSource, LVar5)
            EVT_SWITCH(LVar5)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SET(LVar2, 0)
                    EVT_LOOP(24)
                        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                        EVT_ADD(LVar2, 30)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_SWITCH
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_ADD(LVar2, 10)
                EVT_LOOP(3)
                    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                    EVT_WAIT(3)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, 1, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, 1, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_DefeatedBegin)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Defeated)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_8022C40C)))
            EVT_WAIT(60)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(N(8022CC74))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80232040) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(2)
            EVT_SET(LVar1, 4)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        EVT_CASE_EQ(3)
            EVT_SET(LVar1, 4)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 4)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80232170) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(8022CB2C))
        EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(2)
                EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_2, 0x0023000F, 0x00230003)
            EVT_CASE_EQ(3)
                EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_3, 0x0024000E, 0x00240003)
            EVT_CASE_DEFAULT
                EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_MAIN, 0x00210016, 0x00210003)
        EVT_END_SWITCH
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_NE(LVar0, 1)
            EVT_EXEC_WAIT(N(8022CBC4))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};
