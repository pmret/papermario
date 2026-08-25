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
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_UNUSED,         0,
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
        .idleAnimations = nullptr,
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
    script->varTable[0] = false;
    if (gGameStatusPtr->demoBattleFlags & DEMO_BTL_FLAG_ENABLED) {
        script->varTable[0] = true;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(Add1Coin)) {
    add_coins(1);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    IfEq(LVar0, LANGUAGE_ES)
        Set(LVar0, LANGUAGE_FR)
    EndIf
    Call(SetModelTexVariant, MODEL_o408, LVar0)
#endif
    UseArray(N(SharedSlotMachineData))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Set(BUF_GameState, SLOTS_STATE_INERT)
    Set(BUF_ReelState1, REEL_STATE_INERT)
    Set(BUF_ReelState2, REEL_STATE_INERT)
    Set(BUF_ReelState3, REEL_STATE_INERT)
    Call(RandInt, 8, LVar0)
    Mul(LVar0, 45)
    Set(BUF_ReelAngle1, LVar0)
    Call(RandInt, 8, LVar0)
    Mul(LVar0, 45)
    Set(BUF_ReelAngle2, LVar0)
    Call(RandInt, 8, LVar0)
    Mul(LVar0, 45)
    Set(BUF_ReelAngle3, LVar0)
    Call(N(IsDemoBattle))
    IfEq(LVar0, true)
        Set(BUF_GameState, SLOTS_STATE_ACTIVE)
        Set(BUF_ReelState1, REEL_STATE_SPIN)
        Set(BUF_ReelState2, REEL_STATE_SPIN)
        Set(BUF_ReelState3, REEL_STATE_SPIN)
    EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    UseArray(N(SharedSlotMachineData))
    Call(EnableTexPanning, MODEL_o424, true)
    Set(LVarE, 0)
    Set(LVarF, 0)
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_IN_BlockIdx, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_Block_Start)
                // do nothing
            CaseEq(AVAL_Block_StopReel1)
                Switch(BUF_ReelState1)
                    CaseEq(REEL_STATE_INERT)
                        // no nothing
                    CaseEq(REEL_STATE_SPIN)
                        Add(BUF_ReelAngle1, 5)
                    CaseEq(REEL_STATE_STOPPING)
                        IfGt(BUF_ReelLeft1, 0)
                            Add(BUF_ReelAngle1, 5)
                            Sub(BUF_ReelLeft1, 5)
                            BreakSwitch
                        EndIf
                        Set(LVar0, BUF_ReelAngle1)
                        Mod(LVar0, 45)
                        IfNe(LVar0, 0)
                            Add(BUF_ReelAngle1, 5)
                        Else
                            Set(BUF_ReelState1, REEL_STATE_STOPPED)
                        EndIf
                EndSwitch
                Call(RotateModel, MODEL_o412, BUF_ReelAngle1, 1, 0, 0)
                Call(RotateModel, MODEL_o413, BUF_ReelAngle1, 1, 0, 0)
                Call(RotateModel, MODEL_o414, BUF_ReelAngle1, 1, 0, 0)
            CaseEq(AVAL_Block_StopReel2)
                Switch(BUF_ReelState2)
                    CaseEq(REEL_STATE_INERT)
                        // no nothing
                    CaseEq(REEL_STATE_SPIN)
                        Add(BUF_ReelAngle2, 5)
                    CaseEq(REEL_STATE_STOPPING)
                        IfGt(BUF_ReelLeft2, 0)
                            Add(BUF_ReelAngle2, 5)
                            Sub(BUF_ReelLeft2, 5)
                            BreakSwitch
                        EndIf
                        Set(LVar0, BUF_ReelAngle2)
                        Mod(LVar0, 45)
                        IfNe(LVar0, 0)
                            Add(BUF_ReelAngle2, 5)
                        Else
                            Set(BUF_ReelState2, REEL_STATE_STOPPED)
                        EndIf
                EndSwitch
                Call(RotateModel, MODEL_o417, BUF_ReelAngle2, 1, 0, 0)
                Call(RotateModel, MODEL_o418, BUF_ReelAngle2, 1, 0, 0)
                Call(RotateModel, MODEL_o419, BUF_ReelAngle2, 1, 0, 0)
            CaseEq(AVAL_Block_StopReel3)
                Switch(BUF_ReelState3)
                    CaseEq(REEL_STATE_INERT)
                        // no nothing
                    CaseEq(REEL_STATE_SPIN)
                        Add(BUF_ReelAngle3, 5)
                    CaseEq(REEL_STATE_STOPPING)
                        IfGt(BUF_ReelLeft3, 0)
                            Add(BUF_ReelAngle3, 5)
                            Sub(BUF_ReelLeft3, 5)
                            BreakSwitch
                        EndIf
                        Set(LVar0, BUF_ReelAngle3)
                        Mod(LVar0, 45)
                        IfNe(LVar0, 0)
                            Add(BUF_ReelAngle3, 5)
                        Else
                            Set(BUF_ReelState3, REEL_STATE_STOPPED)
                        EndIf
                EndSwitch
                Call(RotateModel, MODEL_o421, BUF_ReelAngle3, 1, 0, 0)
                Call(RotateModel, MODEL_o422, BUF_ReelAngle3, 1, 0, 0)
                Call(RotateModel, MODEL_o423, BUF_ReelAngle3, 1, 0, 0)
        EndSwitch
        // wrap angles
        IfGe(BUF_ReelAngle1, 360)
            Sub(BUF_ReelAngle1, 360)
        EndIf
        IfGe(BUF_ReelAngle2, 360)
            Sub(BUF_ReelAngle2, 360)
        EndIf
        IfGe(BUF_ReelAngle3, 360)
            Sub(BUF_ReelAngle3, 360)
        EndIf
        IfEq(BUF_GameState, SLOTS_STATE_INERT)
            Add(LVarF, -277)
            Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
        EndIf
        IfEq(BUF_GameState, SLOTS_STATE_ACTIVE)
            Add(LVarF, -1110)
            Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
        EndIf
        IfEq(BUF_GameState, SLOTS_STATE_PAYOUT)
            Add(LVarF, -3330)
            Call(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVarF)
        EndIf
        IfEq(BUF_GameState, SLOTS_STATE_PAYOUT)
            Goto(1)
        EndIf
        IfEq(BUF_GameState, SLOTS_STATE_INERT)
            Goto(1)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_IN_BlockIdx, LVar0)
        IfNe(LVar0, AVAL_Block_Start)
            Goto(1)
        EndIf
        Set(LVar0, BUF_ReelState1)
        Add(LVar0, BUF_ReelState2)
        Add(LVar0, BUF_ReelState3)
        IfEq(LVar0, REEL_STATE_STOPPED * 3)
            Set(LVar0, BUF_ReelAngle1)
            Div(LVar0, 45)
            UseBuf(Ref(N(ReelSymbols1)))
            BufPeek(LVarA, LVar0)
            Set(LVar0, BUF_ReelAngle2)
            Div(LVar0, 45)
            UseBuf(Ref(N(ReelSymbols2)))
            BufPeek(LVarB, LVar0)
            Set(LVar0, BUF_ReelAngle3)
            Div(LVar0, 45)
            UseBuf(Ref(N(ReelSymbols3)))
            BufPeek(LVarC, LVar0)
            Loop(0)
                IfNe(LVarA, LVarB)
                    BreakLoop
                EndIf
                IfNe(LVarA, LVarC)
                    BreakLoop
                EndIf
                IfNe(LVarB, LVarC)
                    BreakLoop
                EndIf
                Thread
    #if !VERSION_PAL
                    Call(FreezeBattleState, true)
    #endif
                    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                    Call(SetBattleCamTarget, 0, 100, 0)
                    Call(SetBattleCamOffsetY, 0)
                    Call(SetBattleCamDist, 340)
                    Call(MoveBattleCamOver, 10)
                    Switch(LVarA)
                        CaseEq(SYM_SHYGUY)
                            Loop(10)
                                Call(MakeItemEntity, ITEM_COIN, -7, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(1)
                                Call(MakeItemEntity, ITEM_COIN, 17, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(1)
                                Call(MakeItemEntity, ITEM_COIN, 42, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(10)
                            EndLoop
                        CaseEq(SYM_STAR)
                            Loop(10)
                                Call(MakeItemEntity, ITEM_COIN, -7, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(1)
                                Call(MakeItemEntity, ITEM_COIN, 17, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(1)
                                Call(MakeItemEntity, ITEM_COIN, 42, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(10)
                            EndLoop
                        CaseEq(SYM_COIN)
                            Loop(10)
                                Call(MakeItemEntity, ITEM_COIN, -7, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(1)
                                Call(MakeItemEntity, ITEM_COIN, 17, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(1)
                                Call(MakeItemEntity, ITEM_COIN, 42, 105, -74, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS_SMALL, 0)
                                Call(N(Add1Coin))
                                Wait(10)
                            EndLoop
                    EndSwitch
                    Set(BUF_GameState, SLOTS_STATE_INERT)
                    Set(BUF_ReelState1, REEL_STATE_INERT)
                    Set(BUF_ReelState2, REEL_STATE_INERT)
                    Set(BUF_ReelState3, REEL_STATE_INERT)
    #if !VERSION_PAL
                    Call(FreezeBattleState, false)
    #endif
                EndThread
    #if VERSION_PAL
                Wait(75)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 25)
                Wait(30)
    #endif
                Set(BUF_GameState, SLOTS_STATE_PAYOUT)
                BreakLoop
            EndLoop
    #if VERSION_PAL
            Call(FreezeBattleState, false)
    #endif
        EndIf
        Label(1)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    UseArray(N(SharedSlotMachineData))
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_SHOCK_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_IN_BlockIdx, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Block_Start)
                    Call(TranslateModel, MODEL_o408, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o408, 0, -6, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o408, 0, -7, 0)
                    Wait(4)
                    Call(TranslateModel, MODEL_o408, 0, -4, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o408, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o408, 0, -1, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o408, 0, 0, 0)
                    Set(BUF_GameState, SLOTS_STATE_ACTIVE)
                    Set(BUF_ReelState1, REEL_STATE_SPIN)
                    Set(BUF_ReelState2, REEL_STATE_SPIN)
                    Set(BUF_ReelState3, REEL_STATE_SPIN)
                CaseEq(AVAL_Block_StopReel1)
                    Call(TranslateModel, MODEL_o409, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -6, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -7, 0)
                    Wait(4)
                    Call(TranslateModel, MODEL_o409, 0, -4, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -1, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, 0, 0)
                    IfEq(BUF_ReelState1, REEL_STATE_SPIN)
#if VERSION_PAL
                        Call(FreezeBattleState, true)
#endif
                        Set(BUF_ReelLeft1, 100)
                        Set(BUF_ReelLeft2, 150)
                        Set(BUF_ReelLeft3, 200)
                        Set(BUF_ReelState1, REEL_STATE_STOPPING)
                        Set(BUF_ReelState2, REEL_STATE_STOPPING)
                        Set(BUF_ReelState3, REEL_STATE_STOPPING)
                    EndIf
                CaseEq(AVAL_Block_StopReel2)
                    Call(TranslateModel, MODEL_o409, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -6, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -7, 0)
                    Wait(4)
                    Call(TranslateModel, MODEL_o409, 0, -4, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -1, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, 0, 0)
                    IfEq(BUF_ReelState2, REEL_STATE_SPIN)
#if VERSION_PAL
                        Call(FreezeBattleState, true)
#endif
                        Set(BUF_ReelLeft1, 150)
                        Set(BUF_ReelLeft2, 100)
                        Set(BUF_ReelLeft3, 200)
                        Set(BUF_ReelState1, REEL_STATE_STOPPING)
                        Set(BUF_ReelState2, REEL_STATE_STOPPING)
                        Set(BUF_ReelState3, REEL_STATE_STOPPING)
                    EndIf
                CaseEq(AVAL_Block_StopReel3)
                    Call(TranslateModel, MODEL_o409, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -6, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -7, 0)
                    Wait(4)
                    Call(TranslateModel, MODEL_o409, 0, -4, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -2, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, -1, 0)
                    Wait(1)
                    Call(TranslateModel, MODEL_o409, 0, 0, 0)
                    IfEq(BUF_ReelState3, REEL_STATE_SPIN)
#if VERSION_PAL
                        Call(FreezeBattleState, true)
#endif
                        Set(BUF_ReelLeft1, 200)
                        Set(BUF_ReelLeft2, 150)
                        Set(BUF_ReelLeft3, 100)
                        Set(BUF_ReelState1, REEL_STATE_STOPPING)
                        Set(BUF_ReelState2, REEL_STATE_STOPPING)
                        Set(BUF_ReelState3, REEL_STATE_STOPPING)
                    EndIf
            EndSwitch
        EndCaseGroup
        CaseOrEq(EVENT_BURN_DEATH)
        CaseOrEq(EVENT_SPIN_SMASH_HIT)
        CaseOrEq(EVENT_SHOCK_DEATH)
        CaseOrEq(EVENT_DEATH)
        CaseOrEq(EVENT_SPIN_SMASH_DEATH)
        CaseOrEq(EVENT_SPIKE_CONTACT)
        CaseOrEq(EVENT_BURN_CONTACT)
            // do nothing
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            // do nothing
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    UseArray(N(SharedSlotMachineData))
    // do nothing
    Return
    End
};
