#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "message_ids.h"
#include "sprite/npc/GeneralGuy.h"
#include "sprite/npc/TankGuy.h"
#include "mapfs/omo_bt07_shape.h"

#include "battle/area/omo2/actor/boss_common.h"

#define NAMESPACE b_area_omo2_toy_tank

extern ActorBlueprint b_area_omo2_4_signal_guy;
extern ActorBlueprint b_area_omo2_2_stilt_guy;
extern ActorBlueprint b_area_omo2_3_shy_stack;
extern ActorBlueprint b_area_omo2_5_shy_squad_redux;

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Hit);
extern EvtScript N(EVS_ShakeTank);
extern EvtScript N(EVS_ManageTroopWaves);
extern EvtScript N(EVS_IncrementWavesDefeated);
extern EvtScript N(EVS_BeginWave_StiltGuys);
extern EvtScript N(EVS_BeginWave_ShyStacks);
extern EvtScript N(EVS_BeginWave_ShySquadRedux);
extern EvtScript N(EVS_BeginWave_Tank);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_SummonStiltGuys);
extern EvtScript N(EVS_IncreaseDarknessAmt);
extern EvtScript N(EVS_DecreaseDarknessAmt);
extern EvtScript N(EVS_ManageDarkness);

extern Formation N(SignalGuyFormation);
extern Formation N(LeftStiltGuyFormation);
extern Formation N(RightStiltGuyFormation);
extern Formation N(LeftShyStackFormation);
extern Formation N(RightShyStackFormation);
extern Formation N(ShySquadReduxFormation);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_2           = 2,
    PRT_3           = 3,
};

enum N(ActorParams) {
    DMG_SCENE       = 4,
};

API_CALLABLE(N(UpdateBulbGlowPos)) {
    Bytecode *args = script->ptrReadPos;

    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 rotation = evt_get_variable(script, *args++);
    BulbGlowFXData* effectData = ((EffectInstance*) evt_get_variable(script, *args++))->data.bulbGlow;

    effectData->pos.x = x;
    effectData->pos.y = y;
    effectData->pos.z = z + 2;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetDarknessParams)) {
    Bytecode* args = script->ptrReadPos;
    get_actor(script->owner1.actorID);
    set_screen_overlay_params_back(OVERLAY_BATTLE_DARKNESS, evt_get_variable(script, *args));
    return ApiStatus_DONE2;
}

#include "animation.inc.c"

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   2,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 30, 0 },
        .targetOffset = { 0, 50 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
        .overrideNameMsg = MSG_EnemyName_GeneralGuyDup,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_3,
        .posOffset = { -5, 0, 0 },
        .targetOffset = { -10, 20 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
        .overrideNameMsg = MSG_EnemyName_GeneralGuyDup,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_TOY_TANK,
    .level = ACTOR_LEVEL_TOY_TANK,
    .maxHP = 30,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 48, 78 },
    .healthBarOffset = { 20, -3 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_ShouldTetherGeneral, true)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, AVAL_SquadPhase_Init)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Init)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, AVAL_StackPhase_Init)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, AVAL_UnusedPhase_Init)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, true)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_HandlingEvent, false)
    Call(SetActorDispOffset, ACTOR_GENERAL, 0, 7, 0)
    Call(SetActorPos, ACTOR_SELF, 85, 0, 0)
    Call(SetHomePos, ACTOR_SELF, 85, 0, 0)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetPartPos, ACTOR_SELF, PRT_2, 85, 30, 0)
    Call(SetPartPos, ACTOR_SELF, PRT_3, 80, 0, 0)
    Call(LoadAnimatedModel, 0, Ref(toy_tank_model))
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_Idle))
    Call(EnableModel, MODEL_shy, false)
    Call(SetAnimatedModelRootPosition, 0, 200, 0, 0)
    Call(SetPartTargetFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_TARGET_NO_JUMP, true)
    Call(GetModelCenter, MODEL_kyu3)
    PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, LVar1, LVar2, Float(1.0), LVar5, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, LVar5)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Exec(N(EVS_ManageTroopWaves))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(ActorExists, ACTOR_TANK, LVar0)
        IfTrue(LVar0)
            // update position of general guy
            Call(GetActorVar, ACTOR_SELF, AVAR_Tank_ShouldTetherGeneral, LVar0)
            IfTrue(LVar0)
                Call(GetAnimatedNodePosition, 0, MODEL_shy, LVar0, LVar1, LVar2)
                Call(SetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
                Call(GetAnimatedNodeRotation, 0, MODEL_shy, LVar0, LVar1, LVar2)
                Call(SetActorRotation, ACTOR_GENERAL, LVar0, 0, LVar2)
            EndIf
            // update position of bulb glow
            Call(GetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, LVar5)
            IfNe(LVar5, nullptr)
                Call(ActorExists, ACTOR_BULB, LVar0)
                IfTrue(LVar0)
                    Call(GetAnimatedNodeRotation, 0, MODEL_shy, LVar0, LVar1, LVar3)
                    Call(GetModelCenter, MODEL_kyu3)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, LVar6)
                    IfFalse(LVar6)
                        // set x position to 1000 if the bulb is inactive
                        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, LVarA)
                        IfTrue(LVarA)
                            Set(LVar0, 1000)
                        EndIf
                    EndIf
                    Call(N(UpdateBulbGlowPos), LVar0, LVar1, LVar2, LVar3, LVar5)
                EndIf
            EndIf
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_HandlingEvent, true)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            ExecWait(N(EVS_Hit))
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Call(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
            Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_BURN_HIT)
            ExecWait(N(EVS_Hit))
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Call(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
            Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_Hit))
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Call(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
            Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(func_8026E914, LVar0, LVar1)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            Wait(30)
        CaseEq(EVENT_IMMUNE)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            Wait(30)
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Wait(30)
        CaseOrEq(EVENT_DEATH)
        CaseOrEq(EVENT_BURN_DEATH)
            ExecWait(N(EVS_Hit))
            ExecWait(N(EVS_Death))
            Return
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(N(EVS_Hit))
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIKE_CONTACT)
        CaseEq(EVENT_BURN_CONTACT)
        CaseEq(EVENT_SHOCK_HIT)
        CaseEq(EVENT_END_FIRST_STRIKE)
        CaseDefault
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_HandlingEvent, false)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Return
    End
};

EvtScript N(EVS_Hit) = {
    Call(UseIdleAnimation, ACTOR_GENERAL, false)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 50)
    ExecWait(N(EVS_ShakeTank))
    Call(GetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
    Call(GetDamageSource, LVar1)
    Switch(LVar1)
        CaseEq(DMG_SRC_ELECTRO_DASH)
            IfNotFlag(LVar0, AVAR_GeneralFlag_ComplainElectric)
                BitwiseOrConst(LVar0, AVAR_GeneralFlag_ComplainElectric | AVAR_GeneralFlag_ComplainUnfair | AVAR_GeneralFlag_ComplainGeneric)
                Call(SetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                Call(SetBattleCamDist, 260)
                Call(SetBattleCamTarget, 85, 80, 0)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(ActorSpeak, MSG_CH4_0072, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 30)
            EndIf
        CaseOrEq(DMG_SRC_D_DOWN_POUND)
        CaseOrEq(DMG_SRC_D_DOWN_JUMP)
            IfNotFlag(LVar0, AVAR_GeneralFlag_ComplainUnfair)
                BitwiseOrConst(LVar0, AVAR_GeneralFlag_ComplainUnfair | AVAR_GeneralFlag_ComplainGeneric)
                Call(SetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                Call(SetBattleCamDist, 260)
                Call(SetBattleCamTarget, 85, 80, 0)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(ActorSpeak, MSG_CH4_0073, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 30)
            EndIf
        EndCaseGroup
        CaseDefault
            IfNotFlag(LVar0, AVAR_GeneralFlag_ComplainGeneric)
                BitwiseOrConst(LVar0, AVAR_GeneralFlag_ComplainUnfair | AVAR_GeneralFlag_ComplainGeneric)
                Call(SetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                Call(SetBattleCamDist, 260)
                Call(SetBattleCamTarget, 85, 80, 0)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(ActorSpeak, MSG_CH4_0074, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 30)
            EndIf
    EndSwitch
    Call(UseIdleAnimation, ACTOR_GENERAL, true)
    Return
    End
};

EvtScript N(EVS_ShakeTank) = {
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_Shake))
    Wait(30)
    Return
    End
};

EvtScript N(EVS_ManageTroopWaves) = {
    #define LBL_SQUAD_PHASE 0
    #define LBL_PHASE_STILT 1
    #define LBL_PHASE_STACK 2
    #define LBL_PHASE_BROKEN 3
    #define LBL_PHASE_UNUSED 10
    #define LBL_DONE 99
    // monitor the shy squad phase, waiting for them to be defeated
    Label(LBL_SQUAD_PHASE)
        Call(ActorExists, ACTOR_TANK, LVar0)
        IfEq(LVar0, false)
            Goto(LBL_DONE)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, LVar0)
        IfEq(LVar0, AVAL_SquadPhase_Defeated)
            Call(SetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, AVAL_SquadPhase_Done)
            Call(CancelEnemyTurn, 1)
            ExecWait(N(EVS_IncrementWavesDefeated))
            ExecWait(N(EVS_BeginWave_StiltGuys))
        Else
            Wait(1)
            Goto(LBL_SQUAD_PHASE)
    EndIf
    // monitor the stilt guys phase, waiting for them to be defeated
    Label(LBL_PHASE_STILT)
        Call(ActorExists, ACTOR_TANK, LVar0)
        IfEq(LVar0, false)
            Goto(LBL_DONE)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, LVar0)
        IfEq(LVar0, AVAL_StiltPhase_Defeated)
            Call(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Done)
            Call(CancelEnemyTurn, 1)
            ExecWait(N(EVS_IncrementWavesDefeated))
            ExecWait(N(EVS_BeginWave_ShyStacks))
        Else
            Wait(1)
            Goto(LBL_PHASE_STILT)
        EndIf
    // monitor the shy stacks phase, waiting for them to be defeated
    Label(LBL_PHASE_STACK)
        Call(ActorExists, ACTOR_TANK, LVar0)
        IfEq(LVar0, false)
            Goto(LBL_DONE)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, LVar0)
        IfNe(LVar0, AVAL_StackPhase_Defeated)
            Wait(1)
            Goto(LBL_PHASE_STACK)
        EndIf
    // this block was added to short-circuit the following unused phase and go directly to the tank phase
    // everything between this block and LBL_DONE is unreachable
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, AVAL_UnusedPhase_Done)
    Call(CancelEnemyTurn, 1)
    Call(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 8)
    ExecWait(N(EVS_BeginWave_Tank))
    Goto(LBL_DONE)
    // ----------------------- begin unreachable code -----------------------
    // a second stilt phase? but nothing is summoned and AVAR_Tank_StiltPhase == AVAL_StiltPhase_Defeated
    Label(LBL_PHASE_BROKEN)
        Call(ActorExists, ACTOR_TANK, LVar0)
        IfEq(LVar0, false)
            Goto(LBL_DONE)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, LVar0)
        IfNe(LVar0, AVAL_StiltPhase_Defeated)
            Wait(1)
            Goto(LBL_PHASE_BROKEN)
        EndIf
    // if watt is out, re-summon the shy stacks. otherwise, summon the unused shy guy group
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_WATT)
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Done)
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, AVAL_StackPhase_Init)
        Call(CancelEnemyTurn, 1)
        ExecWait(N(EVS_IncrementWavesDefeated))
        ExecWait(N(EVS_BeginWave_ShyStacks))
        Wait(1)
        Goto(LBL_PHASE_STACK)
    Else
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, AVAL_StackPhase_Done)
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Done)
        Call(CancelEnemyTurn, 1)
        Call(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 7)
        ExecWait(N(EVS_BeginWave_ShySquadRedux))
        Wait(1)
        Goto(LBL_PHASE_UNUSED)
    EndIf
    // monitor the shy stacks phase, waiting for them to be defeated
    Label(LBL_PHASE_UNUSED)
        Call(ActorExists, ACTOR_TANK, LVar0)
        IfEq(LVar0, false)
            Goto(LBL_DONE)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, LVar0)
        IfEq(LVar0, AVAL_UnusedPhase_Defeated)
            Call(SetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, AVAL_UnusedPhase_Done)
            Call(CancelEnemyTurn, 1)
            Call(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 8)
            ExecWait(N(EVS_BeginWave_Tank))
        EndIf
        Wait(1)
        Goto(LBL_PHASE_UNUSED)
    // ------------------------ end unreachable code ------------------------
    Label(LBL_DONE)
    Return
    End
};

EvtScript N(EVS_IncrementWavesDefeated) = {
    Call(GetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    Switch(LVar0)
        CaseEq(6)
            Call(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 5)
        CaseDefault
            Add(LVar0, 1)
            Call(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_BeginWave_StiltGuys) = {
    Call(EnableBattleStatusBar, false)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(GetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
    IfNotFlag(LVar0, AVAR_GeneralFlag_SquadFled)
        Call(ActorSpeak, MSG_CH4_0069, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim00, ANIM_GeneralGuy_Anim00)
    Else // shy squad has fled
        Call(ActorSpeak, MSG_CH4_006A, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EndIf
    Call(LoadBattleSection, BTL_AREA_OMO2_4)
    Call(SummonEnemy, Ref(N(SignalGuyFormation)), true)
    Wait(60)
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_MOVE1)
    Wait(5)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_MoveForward))
    Call(SetAnimatedModelRootPosition, 0, 20, 0, 0)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    Wait(25)
    Wait(2)
    Call(SetOwnerTarget, LVar0, 1)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar1, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_SCENE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim10)
    Wait(16)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim04)
    Wait(16)
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_MOVE2)
    Wait(4)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Wait(20)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_Idle))
    Wait(26)
    ExecWait(N(EVS_SummonStiltGuys))
    Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Call(SetHomePos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_GENERAL)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(EnableBattleStatusBar, true)
    Call(FreezeBattleState, false)
    Return
    End
};

EvtScript N(EVS_BeginWave_ShyStacks) = {
    Call(EnableBattleStatusBar, false)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_GENERAL)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(GetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    IfEq(LVar0, 2)
        Call(ActorSpeak, MSG_CH4_006E, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    Else
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(10)
    Call(LoadBattleSection, BTL_AREA_OMO2_3)
    Call(SummonEnemy, Ref(N(LeftShyStackFormation)), true)
    Wait(124)
    Call(SummonEnemy, Ref(N(RightShyStackFormation)), true)
    Wait(114)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_Idle))
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, LVar0)
        IfNe(LVar0, AVAL_StiltPhase_Next)
            Wait(1)
            Goto(0)
        EndIf
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 320)
    Call(SetBattleCamOffsetY, 60)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(ActorSpeak, MSG_CH4_006F, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    Thread
        Call(GetActorPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_WAVE_A, Float(1.5))
        Call(SetGoalPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_WAVE_A, 10, false, true, false)
        Call(UseIdleAnimation, ACTOR_WAVE_A, false)
        Call(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, Float(1.1), Float(0.9), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, Float(1.2), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, Float(1.1), Float(0.9), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
        Call(UseIdleAnimation, ACTOR_WAVE_A, true)
    EndThread
    Thread
        Call(GetActorPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_WAVE_B, Float(1.5))
        Call(SetGoalPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_WAVE_B, 10, false, true, false)
        Call(UseIdleAnimation, ACTOR_WAVE_B, false)
        Call(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, Float(1.1), Float(0.9), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, Float(1.2), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, Float(1.1), Float(0.9), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
        Call(UseIdleAnimation, ACTOR_WAVE_B, true)
    EndThread
    Call(ActorSpeak, MSG_CH4_0070, ACTOR_WAVE_B, PRT_MAIN, -1, -1)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(EnableBattleStatusBar, true)
    Call(FreezeBattleState, false)
    Return
    End
};

EvtScript N(EVS_SummonStiltGuys) = {
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_GENERAL)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_NONE, BTL_CAM_XADJ_AVG, false)
    Call(GetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    IfEq(LVar0, 1)
        Call(ActorSpeak, MSG_CH4_006B, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    Else
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(10)
    Call(LoadBattleSection, BTL_AREA_OMO2_2)
    Call(SummonEnemy, Ref(N(LeftStiltGuyFormation)), true)
    Wait(60)
    Call(SummonEnemy, Ref(N(RightStiltGuyFormation)), true)
    Wait(60)
    Label(1)
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, LVar0)
        IfNe(LVar0, AVAL_SquadPhase_Next)
            Wait(1)
            Goto(1)
        EndIf
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, 50, 1, 0)
    Call(SetBattleCamDist, 320)
    Call(SetBattleCamOffsetY, 60)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(ActorSpeak, MSG_CH4_006C, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    Thread
        Call(GetActorPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_WAVE_A, Float(1.5))
        Call(SetGoalPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_WAVE_A, 10, false, true, false)
    EndThread
    Thread
        Call(GetActorPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_WAVE_B, Float(1.5))
        Call(SetGoalPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_WAVE_B, 10, false, true, false)
    EndThread
    Call(ActorSpeak, MSG_CH4_006D, ACTOR_WAVE_B, PRT_MAIN, -1, -1)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(FreezeBattleState, false)
    Return
    End
};

// actually unused
EvtScript N(EVS_BeginWave_ShySquadRedux) = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(SetActorYaw, ACTOR_GENERAL, 180)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, false)
    Wait(10)
    Call(SetDarknessMode, BTL_DARKNESS_MODE_1)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, true)
    Exec(N(EVS_ManageDarkness))
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_GENERAL)
    Call(MoveBattleCamOver, 40)
    Wait(20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_NONE, BTL_CAM_XADJ_AVG, false)
    Call(EndActorSpeech, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Call(SetActorYaw, ACTOR_GENERAL, 0)
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Wait(30)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Call(LoadBattleSection, BTL_AREA_OMO2_5)
    Call(SummonEnemy, Ref(N(ShySquadReduxFormation)), true)
    Wait(155)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(SetBattleCamDist, 350)
    Call(BattleCamTargetActor, ACTOR_GENERAL)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    Call(EndActorSpeech, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(SetBattleCamDist, 300)
    Call(BattleCamTargetActor, ACTOR_WAVE_A)
    Call(MoveBattleCamOver, 30)
    Wait(20)
    Set(LVar0, 2)
    Loop(15)
        Call(RandInt, 3, LVar1)
        Switch(LVar1)
            CaseEq(0)
                Set(LVar1, ANIM_TankGuy_Anim08)
            CaseEq(1)
                Set(LVar1, ANIM_TankGuy_Anim09)
            CaseEq(2)
                Set(LVar1, ANIM_TankGuy_Anim0A)
            CaseDefault
                Set(LVar1, ANIM_TankGuy_Anim06)
        EndSwitch
        Call(SetAnimation, ACTOR_WAVE_A, LVar0, LVar1)
        Add(LVar0, 1)
    EndLoop
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim04)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Set(LVar0, 2)
    Loop(15)
        Call(SetAnimation, ACTOR_WAVE_A, LVar0, ANIM_TankGuy_Anim01)
        Add(LVar0, 1)
    EndLoop
    Call(FreezeBattleState, false)
    Return
    End
};

EvtScript N(EVS_BeginWave_Tank) = {
    Call(EnableBattleStatusBar, false)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_GENERAL)
    Call(MoveBattleCamOver, 60)
    Wait(60)
    Call(ActorSpeak, MSG_CH4_0071, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim00, ANIM_GeneralGuy_Anim00)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    Call(EndActorSpeech, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_NO_STATUS_ANIMS, false)
    Call(SetPartFlagBits, ACTOR_BULB, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, false)
    Call(SetPartFlagBits, ACTOR_TANK, PRT_2, ACTOR_PART_FLAG_NO_TARGET, false)
    Call(SetActorFlagBits, ACTOR_TANK, ACTOR_FLAG_NO_HEALTH_BAR, false)
    Call(HPBarToHome, ACTOR_TANK)
    Call(SetActorVar, ACTOR_GENERAL, AVAR_General_DoingTankPhase, true)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Call(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
    Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(EnableBattleStatusBar, true)
    Call(FreezeBattleState, false)
    Return
    End
};

EvtScript N(EVS_Death) = {
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_TANK, SOUND_TOY_TANK_FALL_APART)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_FallApart))
    Call(GetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, LVar0)
    IfNe(LVar0, nullptr)
        Call(RemoveEffect, LVar0)
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, nullptr)
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, false)
    EndIf
    Wait(45)
    Wait(10)
    Call(UseIdleAnimation, ACTOR_GENERAL, false)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    Wait(15)
    PlayEffect(EFFECT_EXPLOSION, 2, 102, 40, 0, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Tank_ShouldTetherGeneral, false)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_GENERAL)
    Call(MoveBattleCamOver, 60)
    Call(PlaySoundAtActor, ACTOR_TANK, SOUND_TOY_TANK_EXPLODE)
    Call(SetActorJumpGravity, ACTOR_GENERAL, Float(0.6))
    Call(SetActorDispOffset, ACTOR_GENERAL, 0, 0, 0)
    Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    Thread
        Wait(25)
        Call(SetAnimatedModelRootPosition, 0, 380, 0, 0)
    EndThread
    Call(SetGoalPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_GENERAL, 50, false, true, false)
    Call(PlaySoundAtActor, ACTOR_GENERAL, SOUND_ACTOR_COLLAPSE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim10)
    Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Add(LVar0, 18)
    Call(ForceHomePos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Call(SetEnemyHP, ACTOR_GENERAL, 1)
    Call(SetPartDispOffset, ACTOR_GENERAL, PRT_MAIN, 0, 0, 0)
    Call(SetActorRotation, ACTOR_GENERAL, 0, 0, 0)
    Call(SetActorJumpGravity, ACTOR_GENERAL, Float(1.0))
    Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_GENERAL, 12, false, true, false)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim07)
    Call(ShakeCam, CAM_BATTLE, 0, 6, Float(1.0))
    Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Add(LVar1, 30)
    PlayEffect(EFFECT_STARS_ORBITING, 0, LVar0, LVar1, LVar2, 20, 4, LVarF, 0)
    Call(PlaySoundAtActor, ACTOR_GENERAL, SOUND_KNOCKOUT_CHIRPING)
    Call(DropStarPoints, ACTOR_GENERAL)
    Wait(30)
    Call(RemoveEffect, LVarF)
    Call(ActorExists, ACTOR_BULB, LVar0)
    IfNe(LVar0, false)
        Call(SetActorFlagBits, ACTOR_BULB, ACTOR_FLAG_NO_DMG_APPLY, true)
    EndIf
    Call(SetActorFlagBits, ACTOR_GENERAL, ACTOR_FLAG_NO_DMG_APPLY, true)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_ManageDarkness) = {
    Label(0)
        Call(ActorExists, ACTOR_SELF, LVar0)
        IfEq(LVar0, false)
            Return
        EndIf
        Call(GetDarknessStatus, LVar0, LVar1)
        IfEq(LVar0, SCREEN_LAYER_BACK)
            Goto(10)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, LVar0)
        IfFalse(LVar0)
            Goto(10)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, LVar1)
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_WATT)
            ExecWait(N(EVS_DecreaseDarknessAmt))
        Else
            Call(GetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, LVar0)
            IfTrue(LVar0)
                ExecWait(N(EVS_DecreaseDarknessAmt))
            Else
                ExecWait(N(EVS_IncreaseDarknessAmt))
            EndIf
        EndIf
        Call(N(SetDarknessParams), LVar1)
        Label(10)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_DecreaseDarknessAmt) = {
    IfNe(LVar1, 0)
        Sub(LVar1, 5)
        IfLt(LVar1, 0)
            Set(LVar1, 0)
        EndIf
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, LVar1)
    EndIf
    Return
    End
};

EvtScript N(EVS_IncreaseDarknessAmt) = {
    IfNe(LVar1, 215)
        Add(LVar1, 5)
        IfGt(LVar1, 215)
            Set(LVar1, 215)
        EndIf
        Call(SetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, LVar1)
    EndIf
    Return
    End
};

Vec3i N(SummonPos) = { 240, 0, 0 };

Formation N(SignalGuyFormation) = {
    ACTOR_BY_POS(b_area_omo2_4_signal_guy, N(SummonPos), 95)
};

Formation N(LeftStiltGuyFormation) = {
    ACTOR_BY_POS(b_area_omo2_2_stilt_guy, N(SummonPos), 95, 0)
};

Formation N(RightStiltGuyFormation) = {
    ACTOR_BY_POS(b_area_omo2_2_stilt_guy, N(SummonPos), 90, 1)
};

Formation N(LeftShyStackFormation) = {
    ACTOR_BY_POS(b_area_omo2_3_shy_stack, N(SummonPos), 95, 0)
};

Formation N(RightShyStackFormation) = {
    ACTOR_BY_POS(b_area_omo2_3_shy_stack, N(SummonPos), 90, 1)
};

Formation N(ShySquadReduxFormation) = {
    ACTOR_BY_POS(b_area_omo2_5_shy_squad_redux, N(SummonPos), 95)
};
