#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/omo_bt04_shape.h"

// namespace not defined here; actor is associated with stages

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

// data pertaining to the slot machine itself is stored here, where all the interactable block actors can access it
BSS s32 N(SharedSlotMachineData)[10];

#define BUF_GameState   ArrayVar(1)
// current state for each reel
#define BUF_ReelState1   ArrayVar(2)
#define BUF_ReelState2   ArrayVar(3)
#define BUF_ReelState3   ArrayVar(4)
// current angle for each reel
#define BUF_ReelAngle1   ArrayVar(5)
#define BUF_ReelAngle2   ArrayVar(6)
#define BUF_ReelAngle3   ArrayVar(7)
// how much further to rotate each reel before stopping
#define BUF_ReelLeft1    ArrayVar(8)
#define BUF_ReelLeft2    ArrayVar(9)
#define BUF_ReelLeft3    ArrayVar(10)

enum N(GameStates) {
    SLOTS_STATE_INERT       = 0, // waiting for START block to be hit
    SLOTS_STATE_ACTIVE      = 1, // the reels are spinning; hit one of blocks to stop them
    SLOTS_STATE_PAYOUT      = 2, // one round is complete, coins may be dropping
};

enum N(ReelStates) {
    REEL_STATE_INERT        = 0,
    REEL_STATE_SPIN         = 1,
    REEL_STATE_STOPPING     = 2,
    REEL_STATE_STOPPED      = 3,
};

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_IN_BlockIdx        = 0,
    AVAL_Block_Start        = 0,
    AVAL_Block_StopReel1    = 1,
    AVAL_Block_StopReel2    = 2,
    AVAL_Block_StopReel3    = 3,
};

#define SYM_SHYGUY 0
#define SYM_STAR   1
#define SYM_COIN   2

s32 N(ReelSymbols1)[] = { SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN };
s32 N(ReelSymbols2)[] = { SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_STAR,   SYM_COIN, SYM_SHYGUY, SYM_COIN };
s32 N(ReelSymbols3)[] = { SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN };

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
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
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint N(slot_machine_stop) = {
    .flags = ACTOR_FLAG_INVISIBLE | ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_SLOT_MACHINE_STOP,
    .level = ACTOR_LEVEL_SLOT_MACHINE_STOP,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

ActorBlueprint N(slot_machine_start) = {
    .flags = ACTOR_FLAG_INVISIBLE | ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_SLOT_MACHINE_START,
    .level = ACTOR_LEVEL_SLOT_MACHINE_START,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

API_CALLABLE(N(IsDemoBattle)) {
    script->varTable[0] = FALSE;
    if (gGameStatusPtr->demoBattleFlags & DEMO_BTL_FLAG_ENABLED) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(Add1Coin)) {
    add_coins(1);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_IF_EQ(LVar0, LANGUAGE_ES)
        EVT_SET(LVar0, LANGUAGE_FR)
    EVT_END_IF
    EVT_CALL(SetModelTexVariant, MODEL_o408, LVar0)
#endif
    EVT_USE_ARRAY(N(SharedSlotMachineData))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_SET(BUF_GameState, SLOTS_STATE_INERT)
    EVT_SET(BUF_ReelState1, REEL_STATE_INERT)
    EVT_SET(BUF_ReelState2, REEL_STATE_INERT)
    EVT_SET(BUF_ReelState3, REEL_STATE_INERT)
    EVT_CALL(RandInt, 8, LVar0)
    EVT_MUL(LVar0, 45)
    EVT_SET(BUF_ReelAngle1, LVar0)
    EVT_CALL(RandInt, 8, LVar0)
    EVT_MUL(LVar0, 45)
    EVT_SET(BUF_ReelAngle2, LVar0)
    EVT_CALL(RandInt, 8, LVar0)
    EVT_MUL(LVar0, 45)
    EVT_SET(BUF_ReelAngle3, LVar0)
    EVT_CALL(N(IsDemoBattle))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_SET(BUF_GameState, SLOTS_STATE_ACTIVE)
        EVT_SET(BUF_ReelState1, REEL_STATE_SPIN)
        EVT_SET(BUF_ReelState2, REEL_STATE_SPIN)
        EVT_SET(BUF_ReelState3, REEL_STATE_SPIN)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_USE_ARRAY(N(SharedSlotMachineData))
    EVT_CALL(EnableTexPanning, MODEL_o424, TRUE)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_BlockIdx, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_Block_Start)
                // do nothing
            EVT_CASE_EQ(AVAL_Block_StopReel1)
                EVT_SWITCH(BUF_ReelState1)
                    EVT_CASE_EQ(REEL_STATE_INERT)
                        // no nothing
                    EVT_CASE_EQ(REEL_STATE_SPIN)
                        EVT_ADD(BUF_ReelAngle1, 5)
                    EVT_CASE_EQ(REEL_STATE_STOPPING)
                        EVT_IF_GT(BUF_ReelLeft1, 0)
                            EVT_ADD(BUF_ReelAngle1, 5)
                            EVT_SUB(BUF_ReelLeft1, 5)
                            EVT_BREAK_SWITCH
                        EVT_END_IF
                        EVT_SET(LVar0, BUF_ReelAngle1)
                        EVT_MOD(LVar0, 45)
                        EVT_IF_NE(LVar0, 0)
                            EVT_ADD(BUF_ReelAngle1, 5)
                        EVT_ELSE
                            EVT_SET(BUF_ReelState1, REEL_STATE_STOPPED)
                        EVT_END_IF
                EVT_END_SWITCH
                EVT_CALL(RotateModel, MODEL_o412, BUF_ReelAngle1, 1, 0, 0)
                EVT_CALL(RotateModel, MODEL_o413, BUF_ReelAngle1, 1, 0, 0)
                EVT_CALL(RotateModel, MODEL_o414, BUF_ReelAngle1, 1, 0, 0)
            EVT_CASE_EQ(AVAL_Block_StopReel2)
                EVT_SWITCH(BUF_ReelState2)
                    EVT_CASE_EQ(REEL_STATE_INERT)
                        // no nothing
                    EVT_CASE_EQ(REEL_STATE_SPIN)
                        EVT_ADD(BUF_ReelAngle2, 5)
                    EVT_CASE_EQ(REEL_STATE_STOPPING)
                        EVT_IF_GT(BUF_ReelLeft2, 0)
                            EVT_ADD(BUF_ReelAngle2, 5)
                            EVT_SUB(BUF_ReelLeft2, 5)
                            EVT_BREAK_SWITCH
                        EVT_END_IF
                        EVT_SET(LVar0, BUF_ReelAngle2)
                        EVT_MOD(LVar0, 45)
                        EVT_IF_NE(LVar0, 0)
                            EVT_ADD(BUF_ReelAngle2, 5)
                        EVT_ELSE
                            EVT_SET(BUF_ReelState2, REEL_STATE_STOPPED)
                        EVT_END_IF
                EVT_END_SWITCH
                EVT_CALL(RotateModel, MODEL_o417, BUF_ReelAngle2, 1, 0, 0)
                EVT_CALL(RotateModel, MODEL_o418, BUF_ReelAngle2, 1, 0, 0)
                EVT_CALL(RotateModel, MODEL_o419, BUF_ReelAngle2, 1, 0, 0)
            EVT_CASE_EQ(AVAL_Block_StopReel3)
                EVT_SWITCH(BUF_ReelState3)
                    EVT_CASE_EQ(REEL_STATE_INERT)
                        // no nothing
                    EVT_CASE_EQ(REEL_STATE_SPIN)
                        EVT_ADD(BUF_ReelAngle3, 5)
                    EVT_CASE_EQ(REEL_STATE_STOPPING)
                        EVT_IF_GT(BUF_ReelLeft3, 0)
                            EVT_ADD(BUF_ReelAngle3, 5)
                            EVT_SUB(BUF_ReelLeft3, 5)
                            EVT_BREAK_SWITCH
                        EVT_END_IF
                        EVT_SET(LVar0, BUF_ReelAngle3)
                        EVT_MOD(LVar0, 45)
                        EVT_IF_NE(LVar0, 0)
                            EVT_ADD(BUF_ReelAngle3, 5)
                        EVT_ELSE
                            EVT_SET(BUF_ReelState3, REEL_STATE_STOPPED)
                        EVT_END_IF
                EVT_END_SWITCH
                EVT_CALL(RotateModel, MODEL_o421, BUF_ReelAngle3, 1, 0, 0)
                EVT_CALL(RotateModel, MODEL_o422, BUF_ReelAngle3, 1, 0, 0)
                EVT_CALL(RotateModel, MODEL_o423, BUF_ReelAngle3, 1, 0, 0)
        EVT_END_SWITCH
        // wrap angles
        EVT_IF_GE(BUF_ReelAngle1, 360)
            EVT_SUB(BUF_ReelAngle1, 360)
        EVT_END_IF
        EVT_IF_GE(BUF_ReelAngle2, 360)
            EVT_SUB(BUF_ReelAngle2, 360)
        EVT_END_IF
        EVT_IF_GE(BUF_ReelAngle3, 360)
            EVT_SUB(BUF_ReelAngle3, 360)
        EVT_END_IF
        EVT_IF_EQ(BUF_GameState, SLOTS_STATE_INERT)
            EVT_ADD(LVarF, -277)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
        EVT_END_IF
        EVT_IF_EQ(BUF_GameState, SLOTS_STATE_ACTIVE)
            EVT_ADD(LVarF, -1110)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
        EVT_END_IF
        EVT_IF_EQ(BUF_GameState, SLOTS_STATE_PAYOUT)
            EVT_ADD(LVarF, -3330)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
        EVT_END_IF
        EVT_IF_EQ(BUF_GameState, SLOTS_STATE_PAYOUT)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_EQ(BUF_GameState, SLOTS_STATE_INERT)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_BlockIdx, LVar0)
        EVT_IF_NE(LVar0, AVAL_Block_Start)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_SET(LVar0, BUF_ReelState1)
        EVT_ADD(LVar0, BUF_ReelState2)
        EVT_ADD(LVar0, BUF_ReelState3)
        EVT_IF_EQ(LVar0, REEL_STATE_STOPPED * 3)
            EVT_SET(LVar0, BUF_ReelAngle1)
            EVT_DIV(LVar0, 45)
            EVT_USE_BUF(EVT_PTR(N(ReelSymbols1)))
            EVT_BUF_PEEK(LVarA, LVar0)
            EVT_SET(LVar0, BUF_ReelAngle2)
            EVT_DIV(LVar0, 45)
            EVT_USE_BUF(EVT_PTR(N(ReelSymbols2)))
            EVT_BUF_PEEK(LVarB, LVar0)
            EVT_SET(LVar0, BUF_ReelAngle3)
            EVT_DIV(LVar0, 45)
            EVT_USE_BUF(EVT_PTR(N(ReelSymbols3)))
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
                    EVT_CALL(FreezeBattleState, TRUE)
    #endif
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, 0, 100, 0)
                    EVT_CALL(SetBattleCamOffsetZ, 0)
                    EVT_CALL(SetBattleCamZoom, 340)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_EQ(SYM_SHYGUY)
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
                        EVT_CASE_EQ(SYM_STAR)
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
                        EVT_CASE_EQ(SYM_COIN)
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
                    EVT_SET(BUF_GameState, SLOTS_STATE_INERT)
                    EVT_SET(BUF_ReelState1, REEL_STATE_INERT)
                    EVT_SET(BUF_ReelState2, REEL_STATE_INERT)
                    EVT_SET(BUF_ReelState3, REEL_STATE_INERT)
    #if !VERSION_PAL
                    EVT_CALL(FreezeBattleState, FALSE)
    #endif
                EVT_END_THREAD
    #if VERSION_PAL
                EVT_WAIT(75)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 25)
                EVT_WAIT(30)
    #endif
                EVT_SET(BUF_GameState, SLOTS_STATE_PAYOUT)
                EVT_BREAK_LOOP
            EVT_END_LOOP
    #if VERSION_PAL
            EVT_CALL(FreezeBattleState, FALSE)
    #endif
        EVT_END_IF
        EVT_LABEL(1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_USE_ARRAY(N(SharedSlotMachineData))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_BlockIdx, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Block_Start)
                    EVT_CALL(TranslateModel, MODEL_o408, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o408, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o408, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, MODEL_o408, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o408, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o408, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o408, 0, 0, 0)
                    EVT_SET(BUF_GameState, SLOTS_STATE_ACTIVE)
                    EVT_SET(BUF_ReelState1, REEL_STATE_SPIN)
                    EVT_SET(BUF_ReelState2, REEL_STATE_SPIN)
                    EVT_SET(BUF_ReelState3, REEL_STATE_SPIN)
                EVT_CASE_EQ(AVAL_Block_StopReel1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, 0, 0)
                    EVT_IF_EQ(BUF_ReelState1, REEL_STATE_SPIN)
#if VERSION_PAL
                        EVT_CALL(FreezeBattleState, TRUE)
#endif
                        EVT_SET(BUF_ReelLeft1, 100)
                        EVT_SET(BUF_ReelLeft2, 150)
                        EVT_SET(BUF_ReelLeft3, 200)
                        EVT_SET(BUF_ReelState1, REEL_STATE_STOPPING)
                        EVT_SET(BUF_ReelState2, REEL_STATE_STOPPING)
                        EVT_SET(BUF_ReelState3, REEL_STATE_STOPPING)
                    EVT_END_IF
                EVT_CASE_EQ(AVAL_Block_StopReel2)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, 0, 0)
                    EVT_IF_EQ(BUF_ReelState2, REEL_STATE_SPIN)
#if VERSION_PAL
                        EVT_CALL(FreezeBattleState, TRUE)
#endif
                        EVT_SET(BUF_ReelLeft1, 150)
                        EVT_SET(BUF_ReelLeft2, 100)
                        EVT_SET(BUF_ReelLeft3, 200)
                        EVT_SET(BUF_ReelState1, REEL_STATE_STOPPING)
                        EVT_SET(BUF_ReelState2, REEL_STATE_STOPPING)
                        EVT_SET(BUF_ReelState3, REEL_STATE_STOPPING)
                    EVT_END_IF
                EVT_CASE_EQ(AVAL_Block_StopReel3)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -6, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -7, 0)
                    EVT_WAIT(4)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -4, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -2, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_CALL(TranslateModel, MODEL_o409, 0, 0, 0)
                    EVT_IF_EQ(BUF_ReelState3, REEL_STATE_SPIN)
#if VERSION_PAL
                        EVT_CALL(FreezeBattleState, TRUE)
#endif
                        EVT_SET(BUF_ReelLeft1, 200)
                        EVT_SET(BUF_ReelLeft2, 150)
                        EVT_SET(BUF_ReelLeft3, 100)
                        EVT_SET(BUF_ReelState1, REEL_STATE_STOPPING)
                        EVT_SET(BUF_ReelState2, REEL_STATE_STOPPING)
                        EVT_SET(BUF_ReelState3, REEL_STATE_STOPPING)
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
            // do nothing
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            // do nothing
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_USE_ARRAY(N(SharedSlotMachineData))
    // do nothing
    EVT_RETURN
    EVT_END
};
