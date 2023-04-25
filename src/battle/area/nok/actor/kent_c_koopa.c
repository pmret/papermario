#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Coin.h"
#include "sprite/npc/KentCKoopa.h"

#define NAMESPACE b_area_nok_kent_c_koopa

s32 N(intTable_80227910)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

s32 N(IdleAnimations_80227968)[] = {
    STATUS_NORMAL,    ANIM_KentCKoopa_Anim01,
    STATUS_STONE,     ANIM_KentCKoopa_Anim00,
    STATUS_SLEEP,     ANIM_KentCKoopa_Anim13,
    STATUS_POISON,    ANIM_KentCKoopa_Anim01,
    STATUS_STOP,      ANIM_KentCKoopa_Anim00,
    STATUS_STATIC,    ANIM_KentCKoopa_Anim00,
    STATUS_PARALYZE,  ANIM_KentCKoopa_Anim00,
    STATUS_DIZZY,     ANIM_KentCKoopa_Anim14,
    STATUS_FEAR,      ANIM_KentCKoopa_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations_802279B4)[] = {
    STATUS_NORMAL,    ANIM_KentCKoopa_Anim1A,
    STATUS_STOP,      ANIM_KentCKoopa_Anim19,
    STATUS_PARALYZE,  ANIM_KentCKoopa_Anim19,
    STATUS_END,
};

s32 N(IdleAnimations_802279D0)[] = {
    STATUS_NORMAL,    ANIM_Coin_Rotate,
    STATUS_END,
};

s32 N(DefenseTable_802279DC)[] = {
    ELEMENT_NORMAL, 6,
    ELEMENT_BLAST, 6,
    ELEMENT_END,
};

s32 N(DefenseTable_802279F0)[] = {
    ELEMENT_NORMAL, 3,
    ELEMENT_END,
};

s32 N(DefenseTable_802279FC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable_80227A08)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 30,
    STATUS_SHRINK, 40,
    STATUS_STOP, 50,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable_80227AB4)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80227968),
        .defenseTable = N(DefenseTable_802279DC),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 12, 61, 0 },
        .targetOffset = { 0, -20 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_802279F0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 45, 0, 0 },
        .targetOffset = { -70, 26 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802279D0),
        .defenseTable = N(DefenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802279D0),
        .defenseTable = N(DefenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802279D0),
        .defenseTable = N(DefenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802279D0),
        .defenseTable = N(DefenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802279D0),
        .defenseTable = N(DefenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802279D0),
        .defenseTable = N(DefenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

extern EvtScript N(init_80227C20);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KENT_C_KOOPA,
    .level = 55,
    .maxHP = 70,
    .partCount = ARRAY_COUNT( N(PartsTable_80227AB4)),
    .partsData = N(PartsTable_80227AB4),
    .initScript = &N(init_80227C20),
    .statusTable = N(StatusTable_80227A08),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 90, 70 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -26, 38 },
    .statusMessageOffset = { 2, 63 },
};

extern EvtScript N(takeTurn_80228A7C);
extern EvtScript N(idle_80227DD4);
extern EvtScript N(handleEvent_80227E08);
extern EvtScript N(nextTurn_80227D2C);

EvtScript N(init_80227C20) = {
    EVT_CALL(func_8027D434, ACTOR_SELF, 3, 70)
    EVT_CALL(SetPartSize, ACTOR_SELF, 3, 30, 30)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80228A7C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80227DD4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80227E08)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_80227D2C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0x0047001C)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 20)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80227D2C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80227DD4) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8022AD84);
extern EvtScript N(8022B158);
extern EvtScript N(8022B204);
extern EvtScript N(flipOver_KentC);
extern EvtScript N(shellToss_KentC);
extern EvtScript N(tackle_KentC);

EvtScript N(handleEvent_80227E08) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVarD)
    EVT_SWITCH(LVarD)
        EVT_CASE_EQ(56)
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim15)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim16)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim17)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim18)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_END_IF
        EVT_CASE_EQ(36)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim15)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim16)
            EVT_ELSE
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim17)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim18)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, LVar2)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
                EVT_EXEC_WAIT(N(8022B158))
            EVT_END_IF
        EVT_CASE_EQ(33)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
                EVT_EXEC_WAIT(EVS_DoDeath)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
                EVT_EXEC_WAIT(N(8022B204))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim09)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1A)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(25)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim09)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
                EVT_IF_EQ(LVar2, 0)
                    EVT_WAIT(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0C)
                    EVT_WAIT(8)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1A)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim01)
            EVT_ELSE
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim1A)
            EVT_END_IF
            EVT_SET(LVar0, 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(8022AD84))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim01)
                EVT_SET_CONST(LVar0, 1)
                EVT_EXEC_WAIT(DoRecover)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1A)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(13)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim12)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_IF_GT(LVar0, 0)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_END_IF
            EVT_CALL(GetDamageSource, LVar0)
            EVT_IF_EQ(LVar0, DMG_SRC_POW_BLOCK)
                EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetBattleFlags, LVarD)
                EVT_IF_FLAG(LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
                EVT_END_IF
                EVT_EXEC_WAIT(N(flipOver_KentC))
            EVT_ELSE
                EVT_CALL(GetBattleFlags, LVarD)
                EVT_IF_FLAG(LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
                    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
                    EVT_IF_GT(LVar0, 0)
                        EVT_SET_CONST(LVar0, 1)
                        EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1C)
                        EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_ELSE
                        EVT_SET_CONST(LVar0, 1)
                        EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim09)
                        EVT_EXEC_WAIT(DoImmune)
                        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
                        EVT_IF_EQ(LVar2, 0)
                            EVT_WAIT(20)
                            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0C)
                            EVT_WAIT(8)
                        EVT_END_IF
                    EVT_END_IF
                EVT_ELSE
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1C)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(takeTurn_80228A7C) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 2)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 25)
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 36)
            EVT_ADD(LVar1, 18)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_LOOP(5)
                EVT_PLAY_EFFECT(EFFECT_SWEAT, 1, LVar0, LVar1, LVar2, 1, 225, 10, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
            EVT_WAIT(30)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 36)
            EVT_ADD(LVar1, 18)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_LOOP(5)
                EVT_PLAY_EFFECT(EFFECT_SWEAT, 1, LVar0, LVar1, LVar2, 1, 225, 10, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim19)
            EVT_THREAD
                EVT_WAIT(3)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, 0x80000)
                    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 27, 0)
                EVT_ELSE
                    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EVT_END_IF
                EVT_SET(LVar0, 0)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, 0x80000)
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
            EVT_END_IF
            EVT_WAIT(3)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0C)
            EVT_WAIT(10)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_802279DC)))
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 1, 0, 60)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 0x00020000, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 0x00800000, FALSE)
            EVT_CALL(SetPartFlags, ACTOR_SELF, 2, 0x00020004)
            EVT_CALL(SetPartFlags, ACTOR_SELF, 1, 0x00800004)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80227968)))
            EVT_CALL(N(UnkBattleFunc1), -26, 38, 2, 63)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0x0047001C)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 50)
        EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
        EVT_IF_NOT_FLAG(LVar0, 0x1000000)
            EVT_EXEC_WAIT(N(shellToss_KentC))
        EVT_ELSE
            EVT_EXEC_WAIT(N(tackle_KentC))
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(N(tackle_KentC))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(shellToss_KentC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 20)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0B)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 4)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(3)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_370)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0A)
    EVT_WAIT(10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 3, BS_FLAGS1_10)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(6)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(MoveBattleCamOver, 30)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 40)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -240, 0, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetActorPos, ACTOR_SELF, 240, 0, LVar2)
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
                    EVT_CALL(StopSound, SOUND_370)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0C)
                    EVT_WAIT(8)
                    EVT_CALL(YieldTurn)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim01)
                    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_TRANSPARENT | STATUS_FLAGS_IMMOBILIZED)
                        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
                    EVT_END_IF
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, -25, 60, 0)
                    EVT_CALL(SetBattleCamZoom, 460)
                    EVT_CALL(SetBattleCamOffsetZ, 0)
                    EVT_CALL(MoveBattleCamOver, 50)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                        EVT_ADD(LVar0, 32)
                    EVT_ELSE
                        EVT_ADD(LVar0, 12)
                    EVT_END_IF
                    EVT_SET(LVar1, 0)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_IF_EQ(LVarA, 5)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_SET(LVarA, 1)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, -25, 60, 0)
            EVT_CALL(SetBattleCamZoom, 460)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 50)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_TRANSPARENT | STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
            EVT_END_IF
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar0, 32)
            EVT_ELSE
                EVT_ADD(LVar0, 12)
            EVT_END_IF
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarE)
            EVT_IF_NOT_FLAG(LVarE, STATUS_FLAG_SHRINK)
                EVT_CALL(SetDamageSource, DMG_SRC_CRUSH)
            EVT_END_IF
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_SET(LVarA, 0)
            EVT_IF_NOT_FLAG(LVarE, STATUS_FLAG_SHRINK)
                EVT_CALL(GetBattleFlags, LVar0)
                EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
                        EVT_SET(LVarA, 1)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LVarA, 0)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 32)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(SetDamageSource, DMG_SRC_CRUSH_PARTNER)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, -240, 0, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorPos, ACTOR_SELF, 240, 0, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(StopSound, SOUND_370)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0C)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, -45, 60, 0)
            EVT_CALL(SetBattleCamZoom, 460)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_NOT_FLAG(LVar3, 0x80000)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_ADD(LVar0, 16)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_NOT_FLAG(LVar3, 0x80000)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_NOT_FLAG(LVar3, 0x80000)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(StopSound, SOUND_370)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim0C)
    EVT_WAIT(8)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SET_CONST(LVar0, 0x00000001)
    EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim04)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim01)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(tackle_KentC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim03)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim01)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E7)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim06)
            EVT_THREAD
                EVT_WAIT(7)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim07)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim08)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim01)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(8)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_SET(LVar3, 0)
            EVT_LOOP(12)
                EVT_ADD(LVar3, 15)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar3)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim04)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 1, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim01)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET(LVar3, 180)
            EVT_LOOP(15)
                EVT_SUB(LVar3, 12)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar3)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim06)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim07)
        EVT_WAIT(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim08)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarF)
    EVT_IF_NOT_FLAG(LVarF, 0x80000)
        EVT_CALL(SetDamageSource, DMG_SRC_CRUSH)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, SUPPRESS_EVENT_ALL, 0, 10, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_NOT_FLAG(LVar0, 0x100000)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarE)
                    EVT_IF_NOT_FLAG(LVarE, 0x80000)
                        EVT_CALL(LandJump, ACTOR_SELF)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_THREAD
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim06)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim01)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(8)
            EVT_IF_EQ(LVarF, 10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(8022AD84))
        EVT_CASE_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022AD84) = {
    EVT_SET_CONST(LVar0, 0x00000001)
    EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim04)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_RETURN
    EVT_END
};

EvtScript N(flipOver_KentC) = {
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, 1, 0, 40)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_802279F0)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_802279B4)))
    EVT_CALL(N(UnkBattleFunc1), -24, 47, 23, 37)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim1C)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0x00470012)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, 0x80000)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 35, 0)
        EVT_ELSE
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
        EVT_END_IF
        EVT_SET(LVar0, 0)
        EVT_LOOP(5)
            EVT_SUB(LVar0, 18)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_USE_BUF(EVT_PTR(N(intTable_80227910)))
    EVT_LOOP(22)
        EVT_BUF_READ1(LVar0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
        EVT_IF_EQ(LVar0, 0)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim1D)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KentCKoopa_Anim1E)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 0x00020000, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, 0x00800000, TRUE)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, 4)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, 0x00020004)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8022B2E8);

EvtScript N(8022B158) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVarA, 5)
    EVT_EXEC_WAIT(N(8022B2E8))
    EVT_SET(LVar2, 0)
    EVT_LOOP(36)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022B204) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVarA, 0)
    EVT_EXEC_WAIT(N(8022B2E8))
    EVT_SET(LVar2, 0)
    EVT_LOOP(48)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT(10)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, -1)
    EVT_EXEC_WAIT(EVS_DoDeath)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8022B444);

EvtScript N(8022B2E8) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_FLAG(LVar3, 0x80000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar3)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar4)
    EVT_IF_GT(LVar4, LVar3)
        EVT_SET(LVar4, LVar3)
    EVT_END_IF
    EVT_IF_GT(LVar4, 6)
        EVT_SET(LVar4, 6)
    EVT_END_IF
    EVT_IF_GT(LVar4, 0)
        EVT_THREAD
            EVT_SUB(LVar3, LVar4)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, LVar3)
            EVT_SET(LVar5, 4)
            EVT_LOOP(LVar4)
                EVT_EXEC(N(8022B444))
                EVT_ADD(LVar5, 1)
                EVT_WAIT(LVarA)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(func_80218C74_48DE14) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    f32 rand = rand_int(0x168);

    f32 fx = x;
    f32 fz = z;

    s32 outX1 = fx + cos_deg(rand) * 46.0f;
    s32 outZ1 = fz + sin_deg(rand) * 46.0f;
    s32 outX2 = fx + cos_deg(rand) * 62.0f;
    s32 outZ2 = fz + sin_deg(rand) * 62.0f;

    evt_set_variable(script, *args++, outX1);
    evt_set_variable(script, *args++, outZ1);
    evt_set_variable(script, *args++, outX2);
    evt_set_variable(script, *args++, outZ2);

    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218DF8_48DF98) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var1 = *args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}


EvtScript N(8022B444) = {
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar5, SOUND_212)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVar5, LVar6, 35, LVar8)
    EVT_CALL(func_80218C74_48DE14, LVar6, LVar8, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar5, 1, FALSE)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar5, EVT_FLOAT(1.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar5, LVar0, 0, LVar1, 18, TRUE)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar5, LVar2, 0, LVar3, 9, TRUE)
    EVT_WAIT(10)
    EVT_LOOP(10)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar5, 1, FALSE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar5, 1, TRUE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar5, SOUND_211)
    EVT_CALL(AddCoin, 1)
    EVT_RETURN
    EVT_END
};
