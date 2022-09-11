#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_omo_omo_04

extern Formation N(specialFormation_8022DE64);
extern ActorBlueprint N(slot_machine_stop);
extern ActorBlueprint N(slot_machine_start);
extern EvtScript N(init_8022E060);
extern EvtScript N(takeTurn_8022F4A8);
extern EvtScript N(idle_8022E1F8);
extern EvtScript N(handleEvent_8022ED54);

BSS char D_80231110[0x250];
BSS s32 D_80231360[10];

EvtScript N(beforeBattle_8022DD30) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetTexPanner, 29, 10)
    EVT_THREAD
        EVT_SET(LVarE, 0)
        EVT_LOOP(0)
            EVT_ADD(LVarE, 32768)
            EVT_CALL(SetTexPanOffset, 10, 0, LVarE, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022DDEC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022DDFC)[] = {
    0x00000012, 0x00000011, 0x0000000D, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt04_shape",
    .hit = "omo_bt04_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle_8022DD30),
    .postBattle = &N(afterBattle_8022DDEC),
    .foregroundModelList = N(foregroundModelList_8022DDFC),
    .specialFormationSize = 4,
    .specialFormation = &N(specialFormation_8022DE64),
};

Vec3i N(vector3D_8022DE34) = { 0xFFFFFFCF, 56, 0xFFFFFFBC };

Vec3i N(vector3D_8022DE40) = { 0xFFFFFFF3, 56, 0xFFFFFFBC };

Vec3i N(vector3D_8022DE4C) = { 20, 56, 0xFFFFFFBC };

Vec3i N(vector3D_8022DE58) = { 53, 56, 0xFFFFFFBC };

Formation N(specialFormation_8022DE64) = {
    { .actor = &N(slot_machine_start), .home = { .vec = &N(vector3D_8022DE34) }, .var0 = 0 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(vector3D_8022DE40) }, .var0 = 1 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(vector3D_8022DE4C) }, .var0 = 2 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(vector3D_8022DE58) }, .var0 = 3 },
};

s32 N(intTable_8022DED4)[] = {
    0, 1, 0, 2, 0, 2, 0, 2,
};

s32 N(intTable_8022DEF4)[] = {
    0, 1, 0, 2, 1, 2, 0, 2,
};

s32 N(intTable_8022DF14)[] = {
    0, 1, 0, 2, 0, 2, 0, 2,
};

s32 N(defenseTable_8022DF34)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8022DF40)[] = {
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

ActorPartBlueprint N(partsTable_8022DFEC)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8022DF34),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint N(slot_machine_stop) = {
    .flags = ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_40000 | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_SLOT_MACHINE_STOP,
    .level = 99,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_8022DFEC)),
    .partsData = N(partsTable_8022DFEC),
    .script = &N(init_8022E060),
    .statusTable = N(statusTable_8022DF40),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 44, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

ActorBlueprint N(slot_machine_start) = {
    .flags = ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_40000 | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_SLOT_MACHINE_START,
    .level = 99,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_8022DFEC)),
    .partsData = N(partsTable_8022DFEC),
    .script = &N(init_8022E060),
    .statusTable = N(statusTable_8022DF40),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 44, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/IsGameStatusUnkAA_1.inc.c"

EvtScript N(init_8022E060) = {
    EVT_USE_ARRAY(D_80231360)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022F4A8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022E1F8)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022ED54)))
    EVT_SET(ArrayVar(1), 0)
    EVT_SET(ArrayVar(2), 0)
    EVT_SET(ArrayVar(3), 0)
    EVT_SET(ArrayVar(4), 0)
    EVT_CALL(RandInt, 8, LVar0)
    EVT_MUL(LVar0, 45)
    EVT_SET(ArrayVar(5), LVar0)
    EVT_CALL(RandInt, 8, LVar0)
    EVT_MUL(LVar0, 45)
    EVT_SET(ArrayVar(6), LVar0)
    EVT_CALL(RandInt, 8, LVar0)
    EVT_MUL(LVar0, 45)
    EVT_SET(ArrayVar(7), LVar0)
    EVT_CALL(N(IsGameStatusUnkAA_1))
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(ArrayVar(1), 1)
        EVT_SET(ArrayVar(2), 1)
        EVT_SET(ArrayVar(3), 1)
        EVT_SET(ArrayVar(4), 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022E1F8) = {
    EVT_USE_ARRAY(D_80231360)
    EVT_CALL(EnableTexPanning, 45, 1)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_SWITCH(ArrayVar(2))
                EVT_CASE_EQ(0)
                EVT_CASE_EQ(1)
                    EVT_ADD(ArrayVar(5), 5)
                EVT_CASE_EQ(2)
                    EVT_IF_GT(ArrayVar(8), 0)
                        EVT_ADD(ArrayVar(5), 5)
                        EVT_SUB(ArrayVar(8), 5)
                        EVT_BREAK_SWITCH
                    EVT_END_IF
                    EVT_SET(LVar0, ArrayVar(5))
                    EVT_MOD(LVar0, 45)
                    EVT_IF_NE(LVar0, 0)
                        EVT_ADD(ArrayVar(5), 5)
                    EVT_ELSE
                        EVT_SET(ArrayVar(2), 3)
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_CALL(RotateModel, 32, ArrayVar(5), 1, 0, 0)
            EVT_CALL(RotateModel, 33, ArrayVar(5), 1, 0, 0)
            EVT_CALL(RotateModel, 34, ArrayVar(5), 1, 0, 0)
        EVT_CASE_EQ(2)
            EVT_SWITCH(ArrayVar(3))
                EVT_CASE_EQ(0)
                EVT_CASE_EQ(1)
                    EVT_ADD(ArrayVar(6), 5)
                EVT_CASE_EQ(2)
                    EVT_IF_GT(ArrayVar(9), 0)
                        EVT_ADD(ArrayVar(6), 5)
                        EVT_SUB(ArrayVar(9), 5)
                        EVT_BREAK_SWITCH
                    EVT_END_IF
                    EVT_SET(LVar0, ArrayVar(6))
                    EVT_MOD(LVar0, 45)
                    EVT_IF_NE(LVar0, 0)
                        EVT_ADD(ArrayVar(6), 5)
                    EVT_ELSE
                        EVT_SET(ArrayVar(3), 3)
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_CALL(RotateModel, 36, ArrayVar(6), 1, 0, 0)
            EVT_CALL(RotateModel, 37, ArrayVar(6), 1, 0, 0)
            EVT_CALL(RotateModel, 38, ArrayVar(6), 1, 0, 0)
        EVT_CASE_EQ(3)
            EVT_SWITCH(ArrayVar(4))
                EVT_CASE_EQ(0)
                EVT_CASE_EQ(1)
                    EVT_ADD(ArrayVar(7), 5)
                EVT_CASE_EQ(2)
                    EVT_IF_GT(ArrayVar(10), 0)
                        EVT_ADD(ArrayVar(7), 5)
                        EVT_SUB(ArrayVar(10), 5)
                        EVT_BREAK_SWITCH
                    EVT_END_IF
                    EVT_SET(LVar0, ArrayVar(7))
                    EVT_MOD(LVar0, 45)
                    EVT_IF_NE(LVar0, 0)
                        EVT_ADD(ArrayVar(7), 5)
                    EVT_ELSE
                        EVT_SET(ArrayVar(4), 3)
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_CALL(RotateModel, 40, ArrayVar(7), 1, 0, 0)
            EVT_CALL(RotateModel, 41, ArrayVar(7), 1, 0, 0)
            EVT_CALL(RotateModel, 42, ArrayVar(7), 1, 0, 0)
    EVT_END_SWITCH
    EVT_IF_GE(ArrayVar(5), 360)
        EVT_SUB(ArrayVar(5), 360)
    EVT_END_IF
    EVT_IF_GE(ArrayVar(6), 360)
        EVT_SUB(ArrayVar(6), 360)
    EVT_END_IF
    EVT_IF_GE(ArrayVar(7), 360)
        EVT_SUB(ArrayVar(7), 360)
    EVT_END_IF
    EVT_IF_EQ(ArrayVar(1), 0)
        EVT_ADD(LVarF, -277)
        EVT_CALL(SetTexPanOffset, 11, 0, 0, LVarF)
    EVT_END_IF
    EVT_IF_EQ(ArrayVar(1), 1)
        EVT_ADD(LVarF, -1110)
        EVT_CALL(SetTexPanOffset, 11, 0, 0, LVarF)
    EVT_END_IF
    EVT_IF_EQ(ArrayVar(1), 2)
        EVT_ADD(LVarF, -3330)
        EVT_CALL(SetTexPanOffset, 11, 0, 0, LVarF)
    EVT_END_IF
    EVT_IF_EQ(ArrayVar(1), 2)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_EQ(ArrayVar(1), 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SET(LVar0, ArrayVar(2))
    EVT_ADD(LVar0, ArrayVar(3))
    EVT_ADD(LVar0, ArrayVar(4))
    EVT_IF_EQ(LVar0, 9)
        EVT_SET(LVar0, ArrayVar(5))
        EVT_DIV(LVar0, 45)
        EVT_USE_BUF(EVT_PTR(N(intTable_8022DED4)))
        EVT_BUF_PEEK(LVarA, LVar0)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_DIV(LVar0, 45)
        EVT_USE_BUF(EVT_PTR(N(intTable_8022DEF4)))
        EVT_BUF_PEEK(LVarB, LVar0)
        EVT_SET(LVar0, ArrayVar(7))
        EVT_DIV(LVar0, 45)
        EVT_USE_BUF(EVT_PTR(N(intTable_8022DF14)))
        EVT_BUF_PEEK(LVarC, LVar0)
        EVT_LOOP(0)
            EVT_IF_NE(LVarA, LVarB)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_IF_NE(LVarA, LVarC)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_IF_NE(LVarB, LVarC)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_THREAD
                EVT_CALL(func_8026BF48, 1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamTarget, 0, 100, 0)
                EVT_CALL(SetBattleCamOffsetZ, 0)
                EVT_CALL(SetBattleCamZoom, 340)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(0)
                        EVT_LOOP(10)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, -7, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 17, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 42, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(10)
                        EVT_END_LOOP
                    EVT_CASE_EQ(1)
                        EVT_LOOP(10)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, -7, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 17, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 42, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(10)
                        EVT_END_LOOP
                    EVT_CASE_EQ(2)
                        EVT_LOOP(10)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, -7, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 17, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 42, 105, -74, 26, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(10)
                        EVT_END_LOOP
                EVT_END_SWITCH
                EVT_SET(ArrayVar(1), 0)
                EVT_SET(ArrayVar(2), 0)
                EVT_SET(ArrayVar(3), 0)
                EVT_SET(ArrayVar(4), 0)
                EVT_CALL(func_8026BF48, 0)
            EVT_END_THREAD
            EVT_SET(ArrayVar(1), 2)
            EVT_BREAK_LOOP
        EVT_END_LOOP
    EVT_END_IF
    EVT_LABEL(1)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022ED54) = {
    EVT_USE_ARRAY(D_80231360)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(TranslateModel, 28, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 28, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 28, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, 28, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 28, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 28, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 28, 0, 0, 0)
                    EVT_SET(ArrayVar(1), 1)
                    EVT_SET(ArrayVar(2), 1)
                    EVT_SET(ArrayVar(3), 1)
                    EVT_SET(ArrayVar(4), 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(TranslateModel, 29, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, 29, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, 0, 0)
                    EVT_IF_EQ(ArrayVar(2), 1)
                        EVT_SET(ArrayVar(8), 100)
                        EVT_SET(ArrayVar(9), 150)
                        EVT_SET(ArrayVar(10), 200)
                        EVT_SET(ArrayVar(2), 2)
                        EVT_SET(ArrayVar(3), 2)
                        EVT_SET(ArrayVar(4), 2)
                    EVT_END_IF
                EVT_CASE_EQ(2)
                    EVT_CALL(TranslateModel, 29, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, 29, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, 0, 0)
                    EVT_IF_EQ(ArrayVar(3), 1)
                        EVT_SET(ArrayVar(8), 150)
                        EVT_SET(ArrayVar(9), 100)
                        EVT_SET(ArrayVar(10), 200)
                        EVT_SET(ArrayVar(2), 2)
                        EVT_SET(ArrayVar(3), 2)
                        EVT_SET(ArrayVar(4), 2)
                    EVT_END_IF
                EVT_CASE_EQ(3)
                    EVT_CALL(TranslateModel, 29, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, 29, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, 29, 0, 0, 0)
                    EVT_IF_EQ(ArrayVar(4), 1)
                        EVT_SET(ArrayVar(8), 200)
                        EVT_SET(ArrayVar(9), 150)
                        EVT_SET(ArrayVar(10), 100)
                        EVT_SET(ArrayVar(2), 2)
                        EVT_SET(ArrayVar(3), 2)
                        EVT_SET(ArrayVar(4), 2)
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_OR_EQ(EVENT_BURN_CONTACT)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022F4A8) = {
    EVT_USE_ARRAY(D_80231360)
    EVT_RETURN
    EVT_END
};
