#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/koopa_bros.h"

#define NAMESPACE b_area_trd_part_2_fake_bowser

extern EvtScript b_area_trd_part_2_green_ninja_koopa_802257A8;
extern EvtScript b_area_trd_part_2_red_ninja_koopa_80228748;
extern EvtScript b_area_trd_part_2_blue_ninja_koopa_8022B6E8;
extern EvtScript b_area_trd_part_2_yellow_ninja_koopa_8022E688;

extern EvtScript N(init_8021A968);
extern EvtScript N(handleEvent_8021E6F0);
extern EvtScript N(handleEvent_802242FC);
extern EvtScript N(idle_8021D508);
extern EvtScript N(idle_802239BC);
extern EvtScript N(nextTurn_8021F410);
extern EvtScript N(nextTurn_80225438);
extern EvtScript N(takeTurn_8021EC98);
extern EvtScript N(takeTurn_80224D84);
extern EvtScript N(8021E3A0);
extern EvtScript N(8021F630);
extern EvtScript N(80222C44);
extern EvtScript N(80223870);

BSS s32 D_80235FC0[31];

#include "common/StartRumbleWithParams.inc.c"

#include "world/common/atomic/UnkFunc27.inc.c"

s32 N(defenseTable_8021A670)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_BLAST, 1,
    ELEMENT_END,
};

s32 N(defenseTable_8021A684)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_8021A690)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, -1,
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

s32 N(idleAnimations_8021A73C)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_bros_Palette_00_Anim_4,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021A748)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 15 },
        .targetOffset = { -46, 110 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A73C),
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A684),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 11,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8021A670),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW,
    .type = ACTOR_TYPE_FAKE_BOWSER,
    .level = 0,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(partsTable_8021A748)),
    .partsData = N(partsTable_8021A748),
    .script = &N(init_8021A968),
    .statusTable = N(statusTable_8021A690),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { -71, 125 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(D_8021A8FC_48BAEC)[] = {
    0x00000009, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000F, 0x00000010, 0x00000011, 0x00000012,
    0x00000013, 0x00000014, 0x00000019, 0x0000001A, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001F,
    0x00000020, 0x00000021, 0x00000023, 0x00000024, 0x00000025, 0x00000027, 0x00000028, 0x00000029,
    0x0000002B, 0x0000002D, 0x0000FFFF,
};

EvtScript N(init_8021A968) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021EC98)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021D508)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021E6F0)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_8021F410)))
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_SET(ArrayVar(0), 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, 96, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartTargetFlagBits, -127, 2, 4, 1)
    EVT_RETURN
    EVT_END
};

s32 N(D_8021AAC4_48BCB4)[] = {
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -229998976,
    -230000000, -230000000, -229997952,
    -230000000, -230000000, -229997440,
    -230000000, -230000000, -229996928,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229996416,
    -230000000, -230000000, -229996928,
    -230000000, -230000000, -229997440,
    -230000000, -230000000, -229996928,
    -230000000, -230000000, -229997952,
    -230000000, -230000000, -229998976,
    -230000000, -230000000, -229999488,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    255,        255,        255
};


EvtScript N(8021ABE4) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_FBUF(EVT_PTR(N(D_8021AAC4_48BCB4)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_FBUF(EVT_PTR(N(D_8021AAC4_48BCB4)))
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetPartRotation, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(D_8021ACCC_48BEBC)[] = {
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -229997952,
    -230000000, -230000000, -229994880,
    -230000000, -230000000, -229991808,
    -230000000, -230000000, -229991808,
    -230000000, -230000000, -229991808,
    -230000000, -230000000, -229991808,
    -230000000, -230000000, -229992832,
    -230000000, -230000000, -229994880,
    -230000000, -230000000, -229995904,
    -230000000, -230000000, -229998976,
    -230000000, -230000000, -230000000,
    255,        255,        255
};

EvtScript N(8021AD68) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_FBUF(EVT_PTR(N(D_8021ACCC_48BEBC)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 5)
        EVT_RETURN
    EVT_END_IF
    EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_FBUF(EVT_PTR(N(D_8021ACCC_48BEBC)))
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetPartRotation, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(D_8021AE50_48C040)[] = {
    -230000000, -229989760, -230000000,
    -229979520, -230000000, -229994880,
    -230000000, -230000000, -230000000,
    -229994880, -229979520, -230000000,
    -229989760, -230000000, -230000000,
    -230000000, -229969280, -230000000,
    -230000000, -229994880, -229997952,
    -229969280, -230000000, -229989760,
    -229969280, -229989760, -230000000,
    -230000000, -229959040, -229997952,
    -230000000, -230000000, -229994880,
    -229994880, -230000000, -229991808,
    -229989760, -230000000, -230000000,
    -230000000, -229969280, -230000000,
    -229979520, -230000000, -229994880,
    -230000000, -230000000, -230000000,
    -230000000, -229994880, -230000000,
    -229989760, -230000000, -229991808,
    -230000000, -229979520, -230000000,
    -229994880, -230000000, -230000000,
    -230000000, -229994880, -229994880,
    -229969280, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    255,        255,        255
};

EvtScript N(8021AF70) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_FBUF(EVT_PTR(N(D_8021AE50_48C040)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_FBUF(EVT_PTR(N(D_8021AE50_48C040)))
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(RandInt, 100, LVarA)
    EVT_IF_LT(LVarA, 50)
        EVT_SETF(LVarA, EVT_FLOAT(0.0))
        EVT_SUBF(LVarA, LVar0)
        EVT_SETF(LVar0, LVarA)
        EVT_SETF(LVarA, EVT_FLOAT(0.0))
        EVT_SUBF(LVarA, LVar1)
        EVT_SETF(LVar1, LVarA)
    EVT_END_IF
    EVT_CALL(SetPartRotation, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B0E4) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(N(StartRumbleWithParams), 256, 30)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 20, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 5, 0, -60, 0)
    EVT_SET(LVar1, 60)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(60)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 5, EVT_FLOAT(0.5))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 5, LVar0, LVar1, LVar2, 60, 1)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtModel, 15, 482, 0)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtModel, 11, 482, 0)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 150, 20)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtModel, 9, 482, 0)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtModel, 31, 482, 0)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 70, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtModel, 25, 482, 0)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtModel, 43, 482, 0)
    EVT_CALL(N(StartRumbleWithParams), 60, 20)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 30, 20)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021B5D0)[] = {
    0,   0,   0,
    0,   1,   0,
    0,   2,   0,
    0,   3,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   3,   0,
    0,   3,   0,
    0,   2,   0,
    0,   1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(8021B6F0) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021B5D0)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021B5D0)))
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021B7D4)[] = {
    0,   2,   0,
    0,   7,   0,
    0,   9,   0,
    0,   9,   0,
    0,   7,   0,
    0,   5,   0,
    0,   1,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(8021B864) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021B7D4)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 5)
        EVT_RETURN
    EVT_END_IF
    EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021B7D4)))
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021B948)[] = {
    0,   0,   0,
    0,   1,   0,
    0,   2,   0,
    0,   3,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   3,   0,
    0,   3,   0,
    0,   2,   0,
    0,   1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(8021BA68) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021B948)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(7)
        EVT_CASE_EQ(11)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021B948)))
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021BB68)[] = {
    0,   1,   0,
    0,   4,   0,
    0,   16,  0,
    0,   8,   0,
    0,   20,  0,
    0,   8,   0,
    0,   12,  0,
    0,   6,   0,
    0,   0,   0,
    0,   6,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(8021BC88) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021BB68)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021BB68)))
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BD6C) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, 0, -30, 0)
    EVT_SET(LVar1, 30)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, -20)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 150)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 80, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BF14) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 4, 0, -24, 0)
    EVT_SET(LVar1, 24)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(60)
            EVT_ADD(LVar0, 4)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 150)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 4, EVT_FLOAT(0.5))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 4, LVar0, LVar1, LVar2, 60, 1)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021C0CC)[] = {
    0,   0,   0,
    0,   0,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(8021C1EC) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021C0CC)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021C0CC)))
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021C2D4)[] = {
    0,   0,   0,
    0,   0,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(8021C3F4) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021C2D4)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(7)
        EVT_CASE_EQ(11)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021C2D4)))
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021C4F8)[] = {
    0,   0, 0,
    0,  -2, 0,
    0,  -4, 0,
    0,  -4, 0,
    0,  -4, 0,
    0,  -3, 0,
    0,  -1, 0,
    0,   0, 0,
    0,   0, 0,
    0,   0, 0,
    0,   0, 0,
    0,   0, 0,
    255, 255, 255,
};

EvtScript N(8021C594) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021C4F8)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 5)
        EVT_RETURN
    EVT_END_IF
    EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021C4F8)))
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C67C) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, -10)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 50)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LVar0, LVar1, LVar2, 80, 1)
    EVT_RETURN
    EVT_END
};

s32 N(D_8021C7F4_48D9E4)[] = {
    -230000000, -230000000, -229994880,
    -230000000, -230000000, -229989760,
    -230000000, -230000000, -229984640,
    -230000000, -230000000, -229979520,
    -230000000, -230000000, -229974400,
    -230000000, -230000000, -229969280,
    -230000000, -230000000, -229964160,
    -230000000, -230000000, -229959040,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229950848,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229950848,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229950848,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229950848,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229950848,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229950848,
    -230000000, -230000000, -229953920,
    -230000000, -230000000, -229964160,
    -230000000, -230000000, -229974400,
    -230000000, -230000000, -229984640,
    -230000000, -230000000, -229994880,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    -230000000, -230000000, -230000000,
    255,        255,        255,
};

EvtScript N(8021C9A4) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_FBUF(EVT_PTR(N(D_8021C7F4_48D9E4)))
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 7)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVarF, 0)
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_SET(LVarF, 1)
            EVT_SET(LVar0, EVT_FLOAT(0.0))
            EVT_SET(LVar1, EVT_FLOAT(0.0))
            EVT_SET(LVar2, EVT_FLOAT(0.0))
        EVT_END_IF
    EVT_END_IF
    EVT_MULF(LVar2, EVT_FLOAT(-2.0))
    EVT_CALL(SetPartRotation, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021CAE4) = {
    EVT_CALL(GetPartRotation, ACTOR_SELF, 6, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, LVar4, 0, 20, 0)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 6, EVT_FLOAT(0.0), EVT_FLOAT(0.0), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8021CB98) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 6, 0, -60, 0)
    EVT_SET(LVar1, 60)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 8)
            EVT_ADD(LVar1, 10)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 0)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.6))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 80, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021CD50) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 11, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -60, 0)
    EVT_SET(LVar1, 60)
    EVT_CALL(SetPartPos, ACTOR_SELF, 11, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 0)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 11, EVT_FLOAT(0.4))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 11, LVar0, LVar1, LVar2, 80, 1)
    EVT_RETURN
    EVT_END
};

s32 N(D_8021CE68_48E058)[] = {
    -230000000, -230000000, -229979520,
    -230000000, -230000000, -229959040,
    -230000000, -230000000, -229938560,
    -230000000, -230000000, -229918080,
    -230000000, -230000000, -229897600,
    -230000000, -230000000, -229877120,
    -230000000, -230000000, -229856640,
    -230000000, -230000000, -229836160,
    -230000000, -230000000, -229815680,
    -230000000, -230000000, -229795200,
    -230000000, -230000000, -229774720,
    -230000000, -230000000, -229754240,
    -230000000, -230000000, -229733760,
    -230000000, -230000000, -229713280,
    -230000000, -230000000, -229692800,
    -230000000, -230000000, -229672320,
    -230000000, -230000000, -229651840,
    -230000000, -230000000, -230000000,
    255,        255,        255
};

EvtScript N(8021CF4C) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_USE_FBUF(EVT_PTR(N(D_8021CE68_48E058)))
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_NE(LVar0, 5)
        EVT_RETURN
    EVT_END_IF
    EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, 255)
        EVT_USE_FBUF(EVT_PTR(N(D_8021CE68_48E058)))
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetPartRotation, ACTOR_SELF, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 9, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D054) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 8, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 8)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 8, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 150)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 8, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 8, LVar0, LVar1, LVar2, 80, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D1CC) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 9, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 9, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 9, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 8)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 9, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 50)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 9, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 9, LVar0, LVar1, LVar2, 80, 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D350) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 7, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 7, 0, -30, 0)
    EVT_SET(LVar1, 30)
    EVT_CALL(SetPartPos, ACTOR_SELF, 7, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 25)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 7, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 0)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 7, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 7, LVar0, LVar1, LVar2, 80, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021D508) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_SET(LVarA, 0)
    EVT_LABEL(0)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(ArrayVar(0), 1)
            EVT_EXEC(N(8021B6F0))
            EVT_EXEC(N(8021C1EC))
            EVT_EXEC(N(8021ABE4))
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
            EVT_SET(ArrayVar(0), 3)
            EVT_EXEC(N(8021BC88))
            EVT_EXEC(N(8021AF70))
        EVT_CASE_EQ(3)
        EVT_CASE_EQ(4)
            EVT_SET(ArrayVar(0), 5)
            EVT_EXEC(N(8021B864))
            EVT_EXEC(N(8021C594))
            EVT_EXEC(N(8021AD68))
            EVT_EXEC(N(8021CF4C))
        EVT_CASE_EQ(5)
        EVT_CASE_EQ(6)
            EVT_SET(ArrayVar(0), 7)
            EVT_EXEC(N(8021BA68))
            EVT_EXEC(N(8021C3F4))
            EVT_EXEC(N(8021C9A4))
        EVT_CASE_EQ(7)
        EVT_CASE_EQ(8)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B5)
            EVT_SET(ArrayVar(0), 9)
            EVT_EXEC(N(8021B0E4))
            EVT_EXEC(N(8021BD6C))
            EVT_EXEC(N(8021BF14))
            EVT_EXEC(N(8021CB98))
            EVT_EXEC(N(8021CD50))
            EVT_EXEC(N(8021D350))
            EVT_EXEC(N(8021D054))
            EVT_EXEC(N(8021D1CC))
            EVT_EXEC(N(8021C67C))
            EVT_EXEC(N(8021F630))
        EVT_CASE_EQ(9)
        EVT_CASE_EQ(10)
            EVT_SET(ArrayVar(0), 11)
            EVT_EXEC(N(8021BA68))
            EVT_EXEC(N(8021C3F4))
            EVT_EXEC(N(8021CAE4))
        EVT_CASE_EQ(11)
    EVT_END_SWITCH
    EVT_CALL(GetPartPos, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 24, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 24, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 24, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 24, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 15, 64, 1)
    EVT_CALL(SetModelFlags, 16, 64, 1)
    EVT_CALL(SetModelFlags, 17, 64, 1)
    EVT_CALL(SetModelFlags, 18, 64, 1)
    EVT_CALL(SetModelFlags, 19, 64, 1)
    EVT_CALL(SetModelFlags, 20, 64, 1)
    EVT_CALL(SetModelFlags, 21, 64, 1)
    EVT_CALL(SetModelFlags, 22, 64, 1)
    EVT_CALL(SetModelFlags, 23, 64, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 34, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 34, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 34, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 34, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 31, 64, 1)
    EVT_CALL(SetModelFlags, 32, 64, 1)
    EVT_CALL(SetModelFlags, 33, 64, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 30, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 30, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 30, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 30, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 25, 64, 1)
    EVT_CALL(SetModelFlags, 26, 64, 1)
    EVT_CALL(SetModelFlags, 27, 64, 1)
    EVT_CALL(SetModelFlags, 28, 64, 1)
    EVT_CALL(SetModelFlags, 29, 64, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 14, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 14, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 14, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 14, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 11, 64, 1)
    EVT_CALL(SetModelFlags, 12, 64, 1)
    EVT_CALL(SetModelFlags, 13, 64, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 7, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 10, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 7, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 10, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 10, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 10, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 9, 64, 1)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_EQ(LVar0, 9)
        EVT_CALL(GetPartPos, ACTOR_SELF, 8, LVar0, LVar1, LVar2)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
    EVT_END_IF
    EVT_CALL(SetPartPos, ACTOR_SELF, 8, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 44, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 8, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 44, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 44, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 44, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 43, 64, 1)
    EVT_SET(LVar0, ArrayVar(0))
    EVT_IF_EQ(LVar0, 9)
        EVT_CALL(GetPartPos, ACTOR_SELF, 9, LVar0, LVar1, LVar2)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
    EVT_END_IF
    EVT_CALL(SetPartPos, ACTOR_SELF, 9, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 46, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 9, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 46, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 46, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 46, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 45, 64, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 11, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 38, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 11, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 38, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 38, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 38, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 35, 64, 1)
    EVT_CALL(SetModelFlags, 36, 64, 1)
    EVT_CALL(SetModelFlags, 37, 64, 1)
    EVT_CALL(GetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_CALL(TranslateGroup, 42, LVar0, LVar1, LVar2)
    EVT_CALL(GetPartRotation, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_CALL(RotateGroup, 42, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, 42, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, 42, LVar2, 0, 0, 1)
    EVT_CALL(SetModelFlags, 39, 64, 1)
    EVT_CALL(SetModelFlags, 40, 64, 1)
    EVT_CALL(SetModelFlags, 41, 64, 1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 2)
        EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
        EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
        EVT_MUL(LVar0, 100)
        EVT_DIV(LVar0, LVar1)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
            EVT_CASE_LT(20)
                EVT_IF_GT(LVarA, 20)
                    EVT_EXEC(N(8021E3A0))
                    EVT_SET(LVarA, 0)
                EVT_END_IF
            EVT_CASE_LT(40)
                EVT_IF_GT(LVarA, 40)
                    EVT_EXEC(N(8021E3A0))
                    EVT_SET(LVarA, 0)
                EVT_END_IF
            EVT_CASE_LT(60)
                EVT_IF_GT(LVarA, 60)
                    EVT_EXEC(N(8021E3A0))
                    EVT_SET(LVarA, 0)
                EVT_END_IF
            EVT_CASE_LT(80)
                EVT_IF_GT(LVarA, 80)
                    EVT_EXEC(N(8021E3A0))
                    EVT_SET(LVarA, 0)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_ADD(LVarA, 1)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E3A0) = {
    EVT_DIV(LVarA, 4)
    EVT_ADD(LVarA, 1)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -8)
    EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 2, LVar0, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -12)
    EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 2, LVar0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -47)
    EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 2, LVar0, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 2, LVar0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -19)
    EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 2, LVar0, 59, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021E6F0) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET(ArrayVar(0), 2)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), 0)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET(ArrayVar(0), 2)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), 0)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET(ArrayVar(0), 2)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), 0)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_IF_EQ(LVar0, EVENT_BURN_DEATH)
                EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(D_8021A8FC_48BAEC)), 3)
                EVT_CALL(N(UnkFunc26), 3, 35, 35, 35, 0, 0, 0, 0, 0, 0)
            EVT_END_IF
            EVT_SET(ArrayVar(0), 2)
            EVT_WAIT(20)
            EVT_IF_EQ(LVar0, EVENT_BURN_DEATH)
                EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(D_8021A8FC_48BAEC)), 0)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                EVT_ADDF(LVar1, LVar3)
                EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ActorSpeak, MSG_CH1_0106, ACTOR_SELF, 1, -00001, -00001)
            EVT_WAIT(30)
            EVT_SET(ArrayVar(0), 8)
            EVT_LABEL(20)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_NOT_FLAG(LVar0, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(80222C44))
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
            EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
            EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(D_8021A8FC_48BAEC)), 3)
            EVT_CALL(N(UnkFunc26), 3, 35, 35, 35, 0, 0, 0, 0, 0, 0)
            EVT_SET(ArrayVar(0), 2)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), 0)
            EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(D_8021A8FC_48BAEC)), 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_DIVF(LVar3, EVT_FLOAT(2.0))
            EVT_ADDF(LVar1, LVar3)
            EVT_ADDF(LVar2, EVT_FLOAT(5.0))
            EVT_DIVF(LVar3, EVT_FLOAT(10.0))
            EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(5)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021EC98) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(N(StartRumbleWithParams), 256, 3)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(ArrayVar(0), 4)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_SET(ArrayVar(0), 0)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20FD)
        EVT_WAIT(22)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20FE)
    EVT_END_THREAD
    EVT_SET(ArrayVar(0), 6)
    EVT_WAIT(24)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_THREAD
            EVT_END_IF
            EVT_WAIT(8)
            EVT_THREAD
                EVT_LOOP(4)
                    EVT_CALL(N(StartRumbleWithParams), 256, 5)
                    EVT_WAIT(8)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SET(ArrayVar(0), 4)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_SET(ArrayVar(0), 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 65535, 0, 1, BS_FLAGS1_40)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
        EVT_CALL(GetPlayerHP, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_SET(ArrayVar(0), 10)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(18)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(N(StartRumbleWithParams), 256, 5)
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(ArrayVar(0), 4)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_SET(ArrayVar(0), 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetPlayerHP, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 28, 75, -101)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 500)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(15)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(ActorSpeak, MSG_CH1_00FE, ACTOR_SELF, 1, -00001, -00001)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(ActorSpeak, MSG_CH1_00FF, ACTOR_SELF, 1, -00001, -00001)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(ActorSpeak, MSG_CH1_0100, ACTOR_SELF, 1, -00001, -00001)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 85, 81, 0)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(SetBattleCamZoom, 249)
            EVT_CALL(MoveBattleCamOver, 10)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0101, ACTOR_SELF, 1, -00001, -00001)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0102, ACTOR_SELF, 1, -00001, -00001)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(ActorSpeak, MSG_CH1_0103, ACTOR_SELF, 1, -00001, -00001)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 85, 81, 0)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(SetBattleCamZoom, 249)
            EVT_CALL(MoveBattleCamOver, 10)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0104, ACTOR_SELF, 1, -00001, -00001)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0105, ACTOR_SELF, 1, -00001, -00001)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
    EVT_END_SWITCH
    EVT_CALL(func_802535B4, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021F410) = {
    EVT_USE_ARRAY(D_80235FC0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x00000008)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamTarget, -4, 46, -2)
                EVT_CALL(SetBattleCamYaw, 24)
                EVT_CALL(SetBattleCamOffsetZ, 30)
                EVT_CALL(SetBattleCamZoom, 461)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(30)
                EVT_CALL(ActorSpeak, MSG_CH1_00FD, ACTOR_SELF, 1, -00001, -00001)
                EVT_THREAD
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20FD)
                    EVT_WAIT(22)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20FE)
                EVT_END_THREAD
                EVT_SET(ArrayVar(0), 6)
                EVT_WAIT(30)
                EVT_SET(ArrayVar(0), 0)
                EVT_CALL(EndActorSpeech, ACTOR_SELF, 1, -00001, -00001)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x8)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_WAIT(20)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

ApiStatus func_80218350_4B1540(Evt* script, s32 isInitialCall) {
    bgm_set_battle_song(8, 0);
    bgm_push_battle_song();
    return ApiStatus_DONE2;
}

EvtScript N(8021F630) = {
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY0, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_ENEMY0, 0)
    EVT_CALL(SetActorPos, ACTOR_ENEMY0, 100, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1C)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY0, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY0, 2, 0, 0)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY0, -300, 250, 0)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY0, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
    EVT_CALL(SetActorPos, ACTOR_ENEMY1, 100, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_1C)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY1, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY1, 2, 0, 0)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY1, -200, 250, 0)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY1, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 0)
    EVT_CALL(SetActorPos, ACTOR_ENEMY2, 100, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_ENEMY2, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1C)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY2, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY2, 2, 0, 0)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY2, 0, 250, 0)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY2, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_ENEMY3, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_ENEMY3, 0)
    EVT_CALL(SetActorPos, ACTOR_ENEMY3, 100, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_ENEMY3, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_1C)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY3, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY3, 2, 0, 0)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY3, 150, 250, 0)
        EVT_CALL(JumpToGoal, ACTOR_ENEMY3, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_WAIT(100)
    EVT_WAIT(100)
    EVT_CALL(EnableGroup, 24, 0)
    EVT_CALL(EnableGroup, 14, 0)
    EVT_CALL(EnableGroup, 10, 0)
    EVT_CALL(EnableGroup, 34, 0)
    EVT_CALL(EnableGroup, 30, 0)
    EVT_CALL(EnableGroup, 44, 0)
    EVT_CALL(EnableGroup, 46, 0)
    EVT_CALL(EnableGroup, 38, 0)
    EVT_CALL(EnableGroup, 42, 0)
    EVT_THREAD
        EVT_WAIT(23)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY0, 0x301)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, 0x301)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY2, 0x301)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY3, 0x301)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_12)
        EVT_CALL(SetActorPos, ACTOR_ENEMY0, 20, 250, 0)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY0, 20, 0, 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY0, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY0, 2, 0, 0)
        EVT_CALL(FallToGoal, 512, 30)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY0, 0x3E9)
        EVT_CALL(ResetActorSounds, ACTOR_ENEMY0, 2)
        EVT_CALL(ForceHomePos, ACTOR_ENEMY0, 20, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_12)
        EVT_CALL(SetActorPos, ACTOR_ENEMY1, 60, 250, -5)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY1, 60, 0, -5)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY1, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY1, 2, 0, 0)
        EVT_CALL(FallToGoal, 513, 30)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, 0x3E9)
        EVT_CALL(ResetActorSounds, ACTOR_ENEMY1, 2)
        EVT_CALL(ForceHomePos, ACTOR_ENEMY1, 60, 0, -5)
        EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_ENEMY2, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_12)
        EVT_CALL(SetActorPos, ACTOR_ENEMY2, 100, 250, -10)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY2, 100, 0, -10)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY2, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY2, 2, 0, 0)
        EVT_CALL(FallToGoal, 514, 30)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY2, 0x3E9)
        EVT_CALL(ResetActorSounds, ACTOR_ENEMY2, 2)
        EVT_CALL(ForceHomePos, ACTOR_ENEMY2, 100, 0, -10)
        EVT_CALL(SetAnimation, ACTOR_ENEMY2, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetAnimation, ACTOR_ENEMY3, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_12)
        EVT_CALL(SetActorPos, ACTOR_ENEMY3, 140, 250, -15)
        EVT_CALL(SetGoalPos, ACTOR_ENEMY3, 140, 0, -15)
        EVT_CALL(SetActorJumpGravity, ACTOR_ENEMY3, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, ACTOR_ENEMY3, 2, 0, 0)
        EVT_CALL(FallToGoal, 515, 30)
        EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY3, 0x3E9)
        EVT_CALL(ResetActorSounds, ACTOR_ENEMY3, 2)
        EVT_CALL(ForceHomePos, ACTOR_ENEMY3, 140, 0, -15)
        EVT_CALL(SetAnimation, ACTOR_ENEMY3, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_5)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 70, 46, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 292)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(28)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1A)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY0, 0x20F3)
    EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_1A)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_ENEMY1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, 0x20F3)
    EVT_CALL(SetAnimation, ACTOR_ENEMY2, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1A)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_ENEMY2, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY2, 0x20F3)
    EVT_CALL(SetAnimation, ACTOR_ENEMY3, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_1A)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_ENEMY3, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY3, 0x20F3)
    EVT_WAIT(30)
    EVT_CALL(func_80218350_4B1540)
    EVT_CALL(ActorSpeak, MSG_CH1_0107, ACTOR_ENEMY1, 1, -00001, -00001)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_40000 | ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_MULTI_TARGET, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 1)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80224D84)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_802239BC)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_802242FC)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_80225438)))
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_40000, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY0)
    EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY1, ACTOR_FLAG_40000, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY1, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY1)
    EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_4)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY2, ACTOR_FLAG_40000, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY2, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY2)
    EVT_CALL(SetAnimation, ACTOR_ENEMY2, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY3, ACTOR_FLAG_40000, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 1, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY3)
    EVT_CALL(SetAnimation, ACTOR_ENEMY3, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_4)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3)
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, 0x1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_RETURN
    EVT_END
};

ApiStatus func_8021837C_4B156C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(evt_get_variable(script, *args++));

    play_movement_dust_effects(2, actor->state.goalPos.x - 15.0f, actor->state.goalPos.y, actor->state.goalPos.z, actor->state.angle);
    return ApiStatus_DONE2;
}

EvtScript N(80220588) = {
    EVT_IF_EQ(LVar2, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_END_IF
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(0)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_1B)
            EVT_END_SWITCH
            EVT_CALL(SetActorYaw, LVarA, 0)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 22)
            EVT_ADD(LVar1, 19)
            EVT_WAIT(10)
            EVT_WAIT(30)
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, 1)
            EVT_MUL(LVar0, 16)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_CALL(SetBattleCamTarget, LVar2, LVar3, LVar4)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamOffsetZ, 50)
            EVT_CALL(SetBattleCamZoom, 400)
            EVT_CALL(MoveBattleCamOver, LVar0)
            EVT_WAIT(LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_SET(LVar4, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
            EVT_CALL(AddGoalPos, LVarA, 0, 0, 0)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_3)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_3)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_3)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_3)
            EVT_END_SWITCH
            EVT_CALL(GetGoalPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_IF_LT(LVar0, LVar3)
                EVT_CALL(SetActorYaw, LVarA, 0)
            EVT_ELSE
                EVT_CALL(SetActorYaw, LVarA, 180)
            EVT_END_IF
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_10)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_SET(LVar4, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, 1)
            EVT_MUL(LVar0, 18)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(4)
                    EVT_CALL(AddGoalPos, LVarA, 0, LVar0, -10)
                EVT_CASE_EQ(3)
                    EVT_CALL(AddGoalPos, LVarA, 0, LVar0, -7)
                EVT_CASE_EQ(2)
                    EVT_CALL(AddGoalPos, LVarA, 0, LVar0, -4)
            EVT_END_SWITCH
            EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_12)
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_11)
            EVT_END_SWITCH
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            EVT_CALL(func_8021837C_4B156C, LVarA)
            EVT_CALL(PlaySoundAtActor, LVarA, 0x3E9)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 15)
            EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_4)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(SetActorYaw, LVarA, 0)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_1B)
            EVT_END_SWITCH
            EVT_CALL(PlaySoundAtActor, LVarA, 0x20F3)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 22)
            EVT_ADD(LVar1, 19)
            EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(20)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 2)
                EVT_CALL(ActorSpeak, MSG_CH1_010A, LVarA, 1, -00001, -00001)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x2)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_4)
            EVT_END_SWITCH
            EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_40000, 1)
            EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(HPBarToHome, LVarA)
            EVT_CALL(SetActorVar, LVarA, 1, 3)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_5)
            EVT_END_SWITCH
            EVT_WAIT(50)
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, 1)
            EVT_IF_EQ(LVarC, LVar0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
                EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                EVT_SET(LVar4, 15)
                EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                EVT_CALL(AddGoalPos, LVarA, 0, 0, 0)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_3)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_3)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_3)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_3)
                EVT_END_SWITCH
                EVT_CALL(RunToGoal, LVarA, 10, FALSE)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_5)
                EVT_END_SWITCH
                EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_40000, 1)
                EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
                EVT_CALL(HPBarToHome, LVarA)
                EVT_CALL(SetActorVar, LVarA, 1, 6)
            EVT_END_IF
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, 2)
            EVT_IF_EQ(LVarC, LVar0)
                EVT_WAIT(10)
                EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
                EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                EVT_SET(LVar4, 15)
                EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                EVT_CALL(AddGoalPos, LVarA, 0, 18, -4)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_10)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_10)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_10)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_10)
                EVT_END_SWITCH
                EVT_WAIT(5)
                EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
                EVT_THREAD
                    EVT_WAIT(10)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_EQ(ACTOR_ENEMY0)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_12)
                        EVT_CASE_EQ(ACTOR_ENEMY1)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_12)
                        EVT_CASE_EQ(ACTOR_ENEMY2)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_12)
                        EVT_CASE_EQ(ACTOR_ENEMY3)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_12)
                    EVT_END_SWITCH
                EVT_END_THREAD
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_11)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_11)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_11)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_11)
                EVT_END_SWITCH
                EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
                EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
                EVT_CALL(func_8021837C_4B156C, LVarA)
                EVT_CALL(PlaySoundAtActor, LVarA, 0x3E9)
                EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SUB(LVar3, 15)
                EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_5)
                EVT_END_SWITCH
                EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_40000, 1)
                EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
                EVT_CALL(HPBarToHome, LVarA)
                EVT_CALL(SetActorVar, LVarA, 1, 5)
            EVT_END_IF
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, 3)
            EVT_IF_EQ(LVarC, LVar0)
                EVT_WAIT(30)
                EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
                EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                EVT_SET(LVar4, 15)
                EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                EVT_CALL(AddGoalPos, LVarA, 0, 36, -7)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_10)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_10)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_10)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_10)
                EVT_END_SWITCH
                EVT_WAIT(5)
                EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
                EVT_THREAD
                    EVT_WAIT(10)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_EQ(ACTOR_ENEMY0)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_12)
                        EVT_CASE_EQ(ACTOR_ENEMY1)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_12)
                        EVT_CASE_EQ(ACTOR_ENEMY2)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_12)
                        EVT_CASE_EQ(ACTOR_ENEMY3)
                            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_12)
                    EVT_END_SWITCH
                EVT_END_THREAD
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_11)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_11)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_11)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_11)
                EVT_END_SWITCH
                EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
                EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
                EVT_CALL(func_8021837C_4B156C, LVarA)
                EVT_CALL(PlaySoundAtActor, LVarA, 0x3E9)
                EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SUB(LVar3, 15)
                EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_5)
                EVT_END_SWITCH
                EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_40000, 1)
                EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
                EVT_CALL(HPBarToHome, LVarA)
                EVT_CALL(SetActorVar, LVarA, 1, 4)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80221DB4) = {
    EVT_IF_EQ(LVar2, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_END_IF
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(ACTOR_ENEMY0)
            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1B)
        EVT_CASE_EQ(ACTOR_ENEMY1)
            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_1B)
        EVT_CASE_EQ(ACTOR_ENEMY2)
            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1B)
        EVT_CASE_EQ(ACTOR_ENEMY3)
            EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_1B)
    EVT_END_SWITCH
    EVT_WAIT(15)
    EVT_SWITCH(LVarC)
        EVT_CASE_EQ(-1)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_5)
            EVT_END_SWITCH
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(4)
                    EVT_SWITCH(LVarD)
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetActorVar, LVarA, 1, 5)
                        EVT_CASE_EQ(1)
                            EVT_CALL(SetActorVar, LVarA, 1, 4)
                    EVT_END_SWITCH
                EVT_CASE_EQ(3)
                    EVT_CALL(SetActorVar, LVarA, 1, 5)
            EVT_END_SWITCH
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_CALL(SetBattleCamTarget, LVar2, LVar3, LVar4)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamOffsetZ, 50)
            EVT_CALL(SetBattleCamZoom, 400)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_IF_EQ(LVarD, 2)
                EVT_WAIT(25)
            EVT_END_IF
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_10)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_CALL(GetHomePos, LVar0, LVar1, LVar2, LVar3)
            EVT_SET(LVar3, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(4)
                    EVT_CALL(AddGoalPos, LVarA, 0, 54, -10)
                EVT_CASE_EQ(3)
                    EVT_CALL(AddGoalPos, LVarA, 0, 36, -7)
            EVT_END_SWITCH
            EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_12)
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_11)
            EVT_END_SWITCH
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            EVT_CALL(func_8021837C_4B156C, LVarA)
            EVT_CALL(PlaySoundAtActor, LVarA, 0x3E9)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 15)
            EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_4)
            EVT_END_SWITCH
            EVT_WAIT(10)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_1B)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_1B)
            EVT_END_SWITCH
            EVT_CALL(PlaySoundAtActor, LVarA, 0x20F3)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 22)
            EVT_ADD(LVar1, 19)
            EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(30)
            EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_40000, 1)
            EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(HPBarToHome, LVarA)
            EVT_CALL(SetActorVar, LVarA, 1, 3)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, 0x100)
            EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
        EVT_CASE_EQ(1)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_10)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_10)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_CALL(GetHomePos, LVar0, LVar1, LVar2, LVar3)
            EVT_SET(LVar3, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
            EVT_CALL(AddGoalPos, LVarA, 0, 36, -7)
            EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(ACTOR_ENEMY0)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY1)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY2)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_12)
                    EVT_CASE_EQ(ACTOR_ENEMY3)
                        EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_12)
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_11)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_11)
            EVT_END_SWITCH
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            EVT_CALL(func_8021837C_4B156C, LVarA)
            EVT_CALL(PlaySoundAtActor, LVarA, 0x3E9)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 15)
            EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_4)
            EVT_END_SWITCH
            EVT_WAIT(10)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(ACTOR_ENEMY0)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY1)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY2)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_5)
                EVT_CASE_EQ(ACTOR_ENEMY3)
                    EVT_CALL(SetAnimation, LVarA, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_5)
            EVT_END_SWITCH
            EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_40000, 1)
            EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(HPBarToHome, LVarA)
            EVT_CALL(SetActorVar, LVarA, 1, 4)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80222C44) = {
    EVT_SET(LVarA, 0)
    EVT_CALL(PlayerCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetActorVar, LVar0, 1, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(GetStatusFlags, LVar0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_IF_EQ(LVarA, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_END_IF
            EVT_ADD(LVarA, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, 0x200)
            EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, LVarA)
    EVT_SET(LocalFlag(0), 0)
    EVT_SET(LVarB, LVarA)
    EVT_SUB(LVarB, 1)
    EVT_CALL(PlayerCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetActorVar, LVar0, 1, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(GetStatusFlags, LVar0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_SET(LVar1, LVarA)
            EVT_SET(LVar2, LVarB)
            EVT_EXEC(N(80220588))
            EVT_SUB(LVarB, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(func_802535B4, 0)
    EVT_LABEL(2)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 3)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_POPUP, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_SET(LVar0, LVarA)
    EVT_MUL(LVar0, 18)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -4, LVar0)
    EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_BROS)
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
    EVT_CALL(GetActorPos, LVar1, LVar2, LVar3, LVar4)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_SET(LVarA, 0)
    EVT_EXEC_WAIT(N(80223870))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802230E8) = {
    EVT_SET(LVarA, 0)
    EVT_CALL(PlayerCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetActorVar, LVar0, 1, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(GetStatusFlags, LVar0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_ADD(LVarA, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LVarA, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar3, LVarA)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_ADD(LVarA, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, LVarA)
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, -257)
    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_SET(LVar0, 512)
    EVT_LOOP(4)
        EVT_CALL(ActorExists, LVar0, LVar1)
        EVT_IF_EQ(LVar1, TRUE)
            EVT_CALL(GetActorVar, LVar0, 1, LVar2)
            EVT_IF_EQ(LVar2, 3)
                EVT_SET(LVar1, LVarA)
                EVT_SET(LVar2, -1)
                EVT_EXEC(N(80221DB4))
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_SET(LVar2, 0)
    EVT_CALL(PlayerCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetActorVar, LVar0, 1, LVar8)
    EVT_IF_EQ(LVar8, 0)
        EVT_SET(LVar1, LVarA)
        EVT_EXEC(N(80221DB4))
        EVT_ADD(LVar2, 1)
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(func_802535B4, 0)
    EVT_LABEL(2)
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x00000100)
        EVT_WAIT(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_POPUP, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_SET(LVar0, LVarA)
    EVT_MUL(LVar0, 18)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -4, LVar0)
    EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_BROS)
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
    EVT_CALL(GetActorPos, LVar1, LVar2, LVar3, LVar4)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_SET(LVarA, 0)
    EVT_EXEC_WAIT(N(80223870))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802235E0) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, 0x10)
    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
    EVT_SET(LVarA, 1)
    EVT_EXEC_WAIT(N(80223870))
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVarA)
    EVT_SET(LVar0, LVarA)
    EVT_MUL(LVar0, 18)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -4, LVar0)
    EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
    EVT_RETURN
    EVT_END
};

EvtScript N(80223718) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, EVENT_BURN_HIT)
        EVT_SET(LVarA, 5)
    EVT_ELSE
        EVT_SET(LVarA, 6)
    EVT_END_IF
    EVT_EXEC_WAIT(N(80223870))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, -17)
    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, -33)
    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80223870) = {
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(b_area_trd_part_2_green_ninja_koopa_802257A8, LVar1)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(b_area_trd_part_2_yellow_ninja_koopa_8022E688, LVar1)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(b_area_trd_part_2_blue_ninja_koopa_8022B6E8, LVar1)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY3, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(b_area_trd_part_2_red_ninja_koopa_80228748, LVar1)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_IS_THREAD_RUNNING(LVar1, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802239BC) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVarA, LVarE, LVarF)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorPos, ACTOR_ENEMY1, LVarC, LVarE, LVarF)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorPos, ACTOR_ENEMY2, LVarD, LVarE, LVarF)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY3, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorPos, ACTOR_ENEMY3, LVarB, LVarE, LVarF)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(RandInt, 2, LVar0)
                EVT_SET(LVar1, 1)
                EVT_SUB(LVar0, LVar1)
                EVT_ADD(LVar0, LVarA)
                EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY0, LVar0, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY1, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(RandInt, 2, LVar0)
                EVT_SET(LVar1, 1)
                EVT_SUB(LVar0, LVar1)
                EVT_ADD(LVar0, LVarC)
                EVT_CALL(GetActorPos, ACTOR_ENEMY1, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY1, LVar0, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY2, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(RandInt, 2, LVar0)
                EVT_SET(LVar1, 1)
                EVT_SUB(LVar0, LVar1)
                EVT_ADD(LVar0, LVarD)
                EVT_CALL(GetActorPos, ACTOR_ENEMY2, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY2, LVar0, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY3, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY3, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(RandInt, 2, LVar0)
                EVT_SET(LVar1, 1)
                EVT_SUB(LVar0, LVar1)
                EVT_ADD(LVar0, LVarB)
                EVT_CALL(GetActorPos, ACTOR_ENEMY3, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY3, LVar0, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_WAIT(2)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY0, LVarA, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY1, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(GetActorPos, ACTOR_ENEMY1, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY1, LVarC, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY2, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(GetActorPos, ACTOR_ENEMY2, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY2, LVarD, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY3, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_ENEMY3, 1, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(3)
            EVT_CASE_OR_EQ(4)
            EVT_CASE_OR_EQ(5)
            EVT_CASE_OR_EQ(6)
                EVT_CALL(GetActorPos, ACTOR_ENEMY3, LVar1, LVar2, LVar3)
                EVT_CALL(SetActorPos, ACTOR_ENEMY3, LVarB, LVar2, LVar3)
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802242FC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_80000)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x80)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x40)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_SET(LVarA, 2)
            EVT_EXEC_WAIT(N(80223870))
            EVT_WAIT(30)
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_BLAST)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x40)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x80)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(802235E0))
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_80000)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x80)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x40)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_BLAST)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x40)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x80)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_IF_FLAG(LVar0, 0x00000080)
                    EVT_EXEC_WAIT(N(80223718))
                    EVT_WAIT(20)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET(LVarA, 2)
            EVT_EXEC_WAIT(N(80223870))
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_EXEC_WAIT(N(802235E0))
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_IF_NOT_FLAG(LVar0, 0x00000020)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
                    EVT_CALL(ActorSpeak, MSG_CH1_0109, LVar0, 1, -00001, -00001)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, 0x20)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_80000)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x80)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x40)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_BLAST)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x40)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x80)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_IF_FLAG(LVar0, 0x00000080)
                    EVT_EXEC_WAIT(N(80223718))
                    EVT_WAIT(20)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET(LVarA, 3)
            EVT_EXEC_WAIT(N(80223870))
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_EXEC_WAIT(N(802235E0))
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_IF_NOT_FLAG(LVar0, 0x00000020)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
                    EVT_CALL(ActorSpeak, MSG_CH1_0109, LVar0, 1, -00001, -00001)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, 0x20)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_SET(LVarA, 4)
            EVT_EXEC_WAIT(N(80223870))
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x40)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, 0x80)
                EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x00000040)
                EVT_IF_FLAG(LVar0, 0x00000080)
                    EVT_EXEC_WAIT(N(80223718))
                    EVT_WAIT(20)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET(LVarA, 4)
            EVT_EXEC_WAIT(N(80223870))
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_IF_FLAG(LVar0, 0x00000010)
                EVT_IF_NOT_FLAG(LVar0, 0x00000020)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
                    EVT_CALL(ActorSpeak, MSG_CH1_0109, LVar0, 1, -00001, -00001)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, 0x20)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80224D84) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
            EVT_WAIT(30)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
            EVT_SET(LVarA, 0)
            EVT_EXEC_WAIT(N(80223870))
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, -17)
            EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, -33)
            EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVarA)
            EVT_SET(LVar0, LVarA)
            EVT_MUL(LVar0, 18)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -4, LVar0)
            EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
        EVT_CASE_EQ(3)
    EVT_END_SWITCH
    EVT_SET(LVar0, 512)
    EVT_LOOP(4)
        EVT_CALL(ActorExists, LVar0, LVar1)
        EVT_IF_EQ(LVar1, TRUE)
            EVT_CALL(GetStatusFlags, LVar0, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(GetActorVar, LVar0, 1, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 90, 0, 0)
        EVT_CALL(SetBattleCamZoom, 350)
        EVT_CALL(SetBattleCamOffsetZ, 40)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
    EVT_END_IF
    EVT_SET(LVarA, 9)
    EVT_EXEC_WAIT(N(80223870))
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(802230E8))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(80222C44))
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_IF_FLAG(LVar0, 0x00000200)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_SET(LVarA, 8)
        EVT_EXEC_WAIT(N(80223870))
        EVT_LABEL(123)
        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
        EVT_IF_FLAG(LVar0, 0x00000200)
            EVT_WAIT(1)
            EVT_GOTO(123)
        EVT_END_IF
        EVT_SET(LVarA, 10)
        EVT_EXEC_WAIT(N(80223870))
        EVT_WAIT(5)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, 10)
    EVT_EXEC_WAIT(N(80223870))
    EVT_WAIT(5)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 4)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(512)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, NPC_ANIM_koopa_bros_Palette_03_Anim_14, NPC_ANIM_koopa_bros_Palette_03_Anim_4)
            EVT_CASE_EQ(513)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, NPC_ANIM_koopa_bros_Palette_02_Anim_14, NPC_ANIM_koopa_bros_Palette_02_Anim_4)
            EVT_CASE_EQ(514)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, NPC_ANIM_koopa_bros_Palette_00_Anim_14, NPC_ANIM_koopa_bros_Palette_00_Anim_4)
            EVT_CASE_EQ(515)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, NPC_ANIM_koopa_bros_Palette_01_Anim_14, NPC_ANIM_koopa_bros_Palette_01_Anim_4)
        EVT_END_SWITCH
        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
        EVT_BITWISE_OR_CONST(LVar0, 0x4)
        EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
    EVT_END_IF
    EVT_SET(LVarA, 7)
    EVT_EXEC_WAIT(N(80223870))
    EVT_LABEL(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80225438) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, -65)
            EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, -129)
            EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
