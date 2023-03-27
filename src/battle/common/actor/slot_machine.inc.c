#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

BSS s32 N(slot_machine_buffer)[10];

s32 N(intTable1)[] = { 0, 1, 0, 2, 0, 2, 0, 2, };
s32 N(intTable2)[] = { 0, 1, 0, 2, 1, 2, 0, 2, };
s32 N(intTable3)[] = { 0, 1, 0, 2, 0, 2, 0, 2, };

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
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

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint N(slot_machine_stop) = {
    .flags = ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_HIDE_HP_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_SLOT_MACHINE_STOP,
    .level = 99,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
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
    .flags = ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_HIDE_HP_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_SLOT_MACHINE_START,
    .level = 99,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 44, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

API_CALLABLE(N(IsDemoBattle)) {
    script->varTable[0] = 0;
    if (gGameStatusPtr->demoFlags & 1) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(Add1Coin)) {
    add_coins(1);
    return ApiStatus_DONE2;
}

EvtScript N(init) = {
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_IF_EQ(LVar0, LANGUAGE_ES)
        EVT_SET(LVar0, LANGUAGE_FR)
    EVT_END_IF
    EVT_CALL(SetModelTexVariant, 28, LVar0)
#endif
    EVT_USE_ARRAY(N(slot_machine_buffer))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
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
    EVT_CALL(N(IsDemoBattle))
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(ArrayVar(1), 1)
        EVT_SET(ArrayVar(2), 1)
        EVT_SET(ArrayVar(3), 1)
        EVT_SET(ArrayVar(4), 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_USE_ARRAY(N(slot_machine_buffer))
    EVT_CALL(EnableTexPanning, 45, TRUE)
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
        EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
    EVT_END_IF
    EVT_IF_EQ(ArrayVar(1), 1)
        EVT_ADD(LVarF, -1110)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
    EVT_END_IF
    EVT_IF_EQ(ArrayVar(1), 2)
        EVT_ADD(LVarF, -3330)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
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
        EVT_USE_BUF(EVT_PTR(N(intTable1)))
        EVT_BUF_PEEK(LVarA, LVar0)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_DIV(LVar0, 45)
        EVT_USE_BUF(EVT_PTR(N(intTable2)))
        EVT_BUF_PEEK(LVarB, LVar0)
        EVT_SET(LVar0, ArrayVar(7))
        EVT_DIV(LVar0, 45)
        EVT_USE_BUF(EVT_PTR(N(intTable3)))
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
#if !VERSION_PAL
                EVT_CALL(func_8026BF48, 1)
#endif
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamTarget, 0, 100, 0)
                EVT_CALL(SetBattleCamOffsetZ, 0)
                EVT_CALL(SetBattleCamZoom, 340)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(0)
                        EVT_LOOP(10)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, -7, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 17, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 42, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(10)
                        EVT_END_LOOP
                    EVT_CASE_EQ(1)
                        EVT_LOOP(10)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, -7, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 17, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 42, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(10)
                        EVT_END_LOOP
                    EVT_CASE_EQ(2)
                        EVT_LOOP(10)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, -7, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 17, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(1)
                            EVT_CALL(MakeItemEntity, ITEM_COIN, 42, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                            EVT_CALL(N(Add1Coin))
                            EVT_WAIT(10)
                        EVT_END_LOOP
                EVT_END_SWITCH
                EVT_SET(ArrayVar(1), 0)
                EVT_SET(ArrayVar(2), 0)
                EVT_SET(ArrayVar(3), 0)
                EVT_SET(ArrayVar(4), 0)
#if !VERSION_PAL
                EVT_CALL(func_8026BF48, 0)
#endif
            EVT_END_THREAD
#if VERSION_PAL
            EVT_WAIT(75)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 25)
            EVT_WAIT(30)
#endif
            EVT_SET(ArrayVar(1), 2)
            EVT_BREAK_LOOP
        EVT_END_LOOP
#if VERSION_PAL
        EVT_CALL(func_8026BF48, 0)
#endif
    EVT_END_IF
    EVT_LABEL(1)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_USE_ARRAY(N(slot_machine_buffer))
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
#if VERSION_PAL
                        EVT_CALL(func_8026BF48, 1)
#endif
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
#if VERSION_PAL
                        EVT_CALL(func_8026BF48, 1)
#endif
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
#if VERSION_PAL
                        EVT_CALL(func_8026BF48, 1)
#endif
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
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_USE_ARRAY(N(slot_machine_buffer))
    EVT_RETURN
    EVT_END
};
