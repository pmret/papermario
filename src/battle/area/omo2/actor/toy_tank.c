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
        .idleAnimations = NULL,
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
        .idleAnimations = NULL,
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
        .idleAnimations = NULL,
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
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_ShouldTetherGeneral, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, AVAL_SquadPhase_Init)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Init)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, AVAL_StackPhase_Init)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, AVAL_UnusedPhase_Init)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_HandlingEvent, FALSE)
    EVT_CALL(SetActorDispOffset, ACTOR_GENERAL, 0, 7, 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, 85, 0, 0)
    EVT_CALL(SetHomePos, ACTOR_SELF, 85, 0, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_2, 85, 30, 0)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_3, 80, 0, 0)
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(toy_tank_model))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_Idle))
    EVT_CALL(EnableModel, MODEL_shy, FALSE)
    EVT_CALL(SetAnimatedModelRootPosition, 0, 200, 0, 0)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_TARGET_NO_JUMP, TRUE)
    EVT_CALL(GetModelCenter, MODEL_kyu3)
    EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), LVar5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, LVar5)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_EXEC(N(EVS_ManageTroopWaves))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(ActorExists, ACTOR_TANK, LVar0)
        EVT_IF_TRUE(LVar0)
            // update position of general guy
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_ShouldTetherGeneral, LVar0)
            EVT_IF_TRUE(LVar0)
                EVT_CALL(GetAnimatedNodePosition, 0, MODEL_shy, LVar0, LVar1, LVar2)
                EVT_CALL(SetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
                EVT_CALL(GetAnimatedNodeRotation, 0, MODEL_shy, LVar0, LVar1, LVar2)
                EVT_CALL(SetActorRotation, ACTOR_GENERAL, LVar0, 0, LVar2)
            EVT_END_IF
            // update position of bulb glow
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, LVar5)
            EVT_IF_NE(LVar5, NULL)
                EVT_CALL(ActorExists, ACTOR_BULB, LVar0)
                EVT_IF_TRUE(LVar0)
                    EVT_CALL(GetAnimatedNodeRotation, 0, MODEL_shy, LVar0, LVar1, LVar3)
                    EVT_CALL(GetModelCenter, MODEL_kyu3)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, LVar6)
                    EVT_IF_FALSE(LVar6)
                        // set x position to 1000 if the bulb is inactive
                        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, LVarA)
                        EVT_IF_TRUE(LVarA)
                            EVT_SET(LVar0, 1000)
                        EVT_END_IF
                    EVT_END_IF
                    EVT_CALL(N(UpdateBulbGlowPos), LVar0, LVar1, LVar2, LVar3, LVar5)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_HandlingEvent, TRUE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
            EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            EVT_WAIT(30)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_WAIT(30)
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_HandlingEvent, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Hit) = {
    EVT_CALL(UseIdleAnimation, ACTOR_GENERAL, FALSE)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 50)
    EVT_EXEC_WAIT(N(EVS_ShakeTank))
    EVT_CALL(GetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
    EVT_CALL(GetDamageSource, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(DMG_SRC_ELECTRO_DASH)
            EVT_IF_NOT_FLAG(LVar0, AVAR_GeneralFlag_ComplainElectric)
                EVT_BITWISE_OR_CONST(LVar0, AVAR_GeneralFlag_ComplainElectric | AVAR_GeneralFlag_ComplainUnfair | AVAR_GeneralFlag_ComplainGeneric)
                EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH4_0072, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
        EVT_CASE_OR_EQ(DMG_SRC_D_DOWN_POUND)
        EVT_CASE_OR_EQ(DMG_SRC_D_DOWN_JUMP)
            EVT_IF_NOT_FLAG(LVar0, AVAR_GeneralFlag_ComplainUnfair)
                EVT_BITWISE_OR_CONST(LVar0, AVAR_GeneralFlag_ComplainUnfair | AVAR_GeneralFlag_ComplainGeneric)
                EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH4_0073, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_IF_NOT_FLAG(LVar0, AVAR_GeneralFlag_ComplainGeneric)
                EVT_BITWISE_OR_CONST(LVar0, AVAR_GeneralFlag_ComplainUnfair | AVAR_GeneralFlag_ComplainGeneric)
                EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamZoom, 260)
                EVT_CALL(SetBattleCamTarget, 85, 80, 0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH4_0074, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05, ANIM_GeneralGuy_Anim05)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 30)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_GENERAL, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShakeTank) = {
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_Shake))
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageTroopWaves) = {
    #define LBL_SQUAD_PHASE 0
    #define LBL_PHASE_STILT 1
    #define LBL_PHASE_STACK 2
    #define LBL_PHASE_BROKEN 3
    #define LBL_PHASE_UNUSED 10
    #define LBL_DONE 99
    // monitor the shy squad phase, waiting for them to be defeated
    EVT_LABEL(LBL_SQUAD_PHASE)
        EVT_CALL(ActorExists, ACTOR_TANK, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_GOTO(LBL_DONE)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, LVar0)
        EVT_IF_EQ(LVar0, AVAL_SquadPhase_Defeated)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, AVAL_SquadPhase_Done)
            EVT_CALL(CancelEnemyTurn, 1)
            EVT_EXEC_WAIT(N(EVS_IncrementWavesDefeated))
            EVT_EXEC_WAIT(N(EVS_BeginWave_StiltGuys))
        EVT_ELSE
            EVT_WAIT(1)
            EVT_GOTO(LBL_SQUAD_PHASE)
    EVT_END_IF
    // monitor the stilt guys phase, waiting for them to be defeated
    EVT_LABEL(LBL_PHASE_STILT)
        EVT_CALL(ActorExists, ACTOR_TANK, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_GOTO(LBL_DONE)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, LVar0)
        EVT_IF_EQ(LVar0, AVAL_StiltPhase_Defeated)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Done)
            EVT_CALL(CancelEnemyTurn, 1)
            EVT_EXEC_WAIT(N(EVS_IncrementWavesDefeated))
            EVT_EXEC_WAIT(N(EVS_BeginWave_ShyStacks))
        EVT_ELSE
            EVT_WAIT(1)
            EVT_GOTO(LBL_PHASE_STILT)
        EVT_END_IF
    // monitor the shy stacks phase, waiting for them to be defeated
    EVT_LABEL(LBL_PHASE_STACK)
        EVT_CALL(ActorExists, ACTOR_TANK, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_GOTO(LBL_DONE)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, LVar0)
        EVT_IF_NE(LVar0, AVAL_StackPhase_Defeated)
            EVT_WAIT(1)
            EVT_GOTO(LBL_PHASE_STACK)
        EVT_END_IF
    // this block was added to short-circuit the following unused phase and go directly to the tank phase
    // everything between this block and LBL_DONE is unreachable
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, AVAL_UnusedPhase_Done)
    EVT_CALL(CancelEnemyTurn, 1)
    EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 8)
    EVT_EXEC_WAIT(N(EVS_BeginWave_Tank))
    EVT_GOTO(LBL_DONE)
    // ----------------------- begin unreachable code ----------------------- 
    // a second stilt phase? but nothing is summoned and AVAR_Tank_StiltPhase == AVAL_StiltPhase_Defeated
    EVT_LABEL(LBL_PHASE_BROKEN)
        EVT_CALL(ActorExists, ACTOR_TANK, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_GOTO(LBL_DONE)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, LVar0)
        EVT_IF_NE(LVar0, AVAL_StiltPhase_Defeated)
            EVT_WAIT(1)
            EVT_GOTO(LBL_PHASE_BROKEN)
        EVT_END_IF
    // if watt is out, re-summon the shy stacks. otherwise, summon the unused shy guy group
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_WATT)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Done)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, AVAL_StackPhase_Init)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_EXEC_WAIT(N(EVS_IncrementWavesDefeated))
        EVT_EXEC_WAIT(N(EVS_BeginWave_ShyStacks))
        EVT_WAIT(1)
        EVT_GOTO(LBL_PHASE_STACK)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_StackPhase, AVAL_StackPhase_Done)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Done)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 7)
        EVT_EXEC_WAIT(N(EVS_BeginWave_ShySquadRedux))
        EVT_WAIT(1)
        EVT_GOTO(LBL_PHASE_UNUSED)
    EVT_END_IF
    // monitor the shy stacks phase, waiting for them to be defeated
    EVT_LABEL(LBL_PHASE_UNUSED)
        EVT_CALL(ActorExists, ACTOR_TANK, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_GOTO(LBL_DONE)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, LVar0)
        EVT_IF_EQ(LVar0, AVAL_UnusedPhase_Defeated)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_UnusedPhase, AVAL_UnusedPhase_Done)
            EVT_CALL(CancelEnemyTurn, 1)
            EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 8)
            EVT_EXEC_WAIT(N(EVS_BeginWave_Tank))
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(LBL_PHASE_UNUSED)
    // ------------------------ end unreachable code ------------------------ 
    EVT_LABEL(LBL_DONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_IncrementWavesDefeated) = {
    EVT_CALL(GetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(6)
            EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, 5)
        EVT_CASE_DEFAULT
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BeginWave_StiltGuys) = {
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(GetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, AVAR_GeneralFlag_SquadFled)
        EVT_CALL(ActorSpeak, MSG_CH4_0069, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim00, ANIM_GeneralGuy_Anim00)
    EVT_ELSE // shy squad has fled
        EVT_CALL(ActorSpeak, MSG_CH4_006A, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_END_IF
    EVT_CALL(LoadBattleSection, BTL_AREA_OMO2_4)
    EVT_CALL(SummonEnemy, EVT_PTR(N(SignalGuyFormation)), TRUE)
    EVT_WAIT(60)
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_MOVE1)
    EVT_WAIT(5)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_MoveForward))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    EVT_WAIT(25)
    EVT_WAIT(2)
    EVT_CALL(SetOwnerTarget, LVar0, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar1, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_SCENE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim10)
    EVT_WAIT(16)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim04)
    EVT_WAIT(16)
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_MOVE2)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_WAIT(20)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_Idle))
    EVT_WAIT(26)
    EVT_EXEC_WAIT(N(EVS_SummonStiltGuys))
    EVT_CALL(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_GENERAL)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BeginWave_ShyStacks) = {
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_GENERAL)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(GetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(ActorSpeak, MSG_CH4_006E, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_ELSE
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_CALL(LoadBattleSection, BTL_AREA_OMO2_3)
    EVT_CALL(SummonEnemy, EVT_PTR(N(LeftShyStackFormation)), TRUE)
    EVT_WAIT(124)
    EVT_CALL(SummonEnemy, EVT_PTR(N(RightShyStackFormation)), TRUE)
    EVT_WAIT(114)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_Idle))
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_StiltPhase, LVar0)
        EVT_IF_NE(LVar0, AVAL_StiltPhase_Next)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 60)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(ActorSpeak, MSG_CH4_006F, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_WAVE_A, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_WAVE_A, 10, FALSE, TRUE, FALSE)
        EVT_CALL(UseIdleAnimation, ACTOR_WAVE_A, FALSE)
        EVT_CALL(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_WAVE_A, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(UseIdleAnimation, ACTOR_WAVE_A, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_WAVE_B, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_WAVE_B, 10, FALSE, TRUE, FALSE)
        EVT_CALL(UseIdleAnimation, ACTOR_WAVE_B, FALSE)
        EVT_CALL(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_WAVE_B, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(UseIdleAnimation, ACTOR_WAVE_B, TRUE)
    EVT_END_THREAD
    EVT_CALL(ActorSpeak, MSG_CH4_0070, ACTOR_WAVE_B, PRT_MAIN, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SummonStiltGuys) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_GENERAL)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetActorVar, ACTOR_GENERAL, AVAR_General_WavesDefeated, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ActorSpeak, MSG_CH4_006B, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_ELSE
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_CALL(LoadBattleSection, BTL_AREA_OMO2_2)
    EVT_CALL(SummonEnemy, EVT_PTR(N(LeftStiltGuyFormation)), TRUE)
    EVT_WAIT(60)
    EVT_CALL(SummonEnemy, EVT_PTR(N(RightStiltGuyFormation)), TRUE)
    EVT_WAIT(60)
    EVT_LABEL(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_SquadPhase, LVar0)
        EVT_IF_NE(LVar0, AVAL_SquadPhase_Next)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 50, 1, 0)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 60)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(ActorSpeak, MSG_CH4_006C, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0C, ANIM_GeneralGuy_Anim02)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_WAVE_A, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_WAVE_A, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_WAVE_A, 10, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_WAVE_B, EVT_FLOAT(1.5))
        EVT_CALL(SetGoalPos, ACTOR_WAVE_B, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_WAVE_B, 10, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(ActorSpeak, MSG_CH4_006D, ACTOR_WAVE_B, PRT_MAIN, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

// actually unused
EvtScript N(EVS_BeginWave_ShySquadRedux) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(SetActorYaw, ACTOR_GENERAL, 180)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetDarknessMode, BTL_DARKNESS_MODE_1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, TRUE)
    EVT_EXEC(N(EVS_ManageDarkness))
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_GENERAL)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(EndActorSpeech, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetActorYaw, ACTOR_GENERAL, 0)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_CALL(LoadBattleSection, BTL_AREA_OMO2_5)
    EVT_CALL(SummonEnemy, EVT_PTR(N(ShySquadReduxFormation)), TRUE)
    EVT_WAIT(155)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(BattleCamTargetActor, ACTOR_GENERAL)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    EVT_CALL(EndActorSpeech, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(BattleCamTargetActor, ACTOR_WAVE_A)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(20)
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(RandInt, 3, LVar1)
        EVT_SWITCH(LVar1)
            EVT_CASE_EQ(0)
                EVT_SET(LVar1, ANIM_TankGuy_Anim08)
            EVT_CASE_EQ(1)
                EVT_SET(LVar1, ANIM_TankGuy_Anim09)
            EVT_CASE_EQ(2)
                EVT_SET(LVar1, ANIM_TankGuy_Anim0A)
            EVT_CASE_DEFAULT
                EVT_SET(LVar1, ANIM_TankGuy_Anim06)
        EVT_END_SWITCH
        EVT_CALL(SetAnimation, ACTOR_WAVE_A, LVar0, LVar1)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim04)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_SET(LVar0, 2)
    EVT_LOOP(15)
        EVT_CALL(SetAnimation, ACTOR_WAVE_A, LVar0, ANIM_TankGuy_Anim01)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BeginWave_Tank) = {
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_GENERAL)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT(60)
    EVT_CALL(ActorSpeak, MSG_CH4_0071, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim00, ANIM_GeneralGuy_Anim00)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    EVT_CALL(EndActorSpeech, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_NO_STATUS_ANIMS, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_BULB, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_TANK, PRT_2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_TANK, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_TANK)
    EVT_CALL(SetActorVar, ACTOR_GENERAL, AVAR_General_DoingTankPhase, TRUE)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, PRT_2, 0, 35)
    EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_TANK, SOUND_TOY_TANK_FALL_APART)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_FallApart))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, LVar0)
    EVT_IF_NE(LVar0, NULL)
        EVT_CALL(RemoveEffect, LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_BulbGlowEffect, NULL)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, FALSE)
    EVT_END_IF
    EVT_WAIT(45)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_GENERAL, FALSE)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    EVT_WAIT(15)
    EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 2, 102, 40, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_ShouldTetherGeneral, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_GENERAL)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(PlaySoundAtActor, ACTOR_TANK, SOUND_TOY_TANK_EXPLODE)
    EVT_CALL(SetActorJumpGravity, ACTOR_GENERAL, EVT_FLOAT(0.6))
    EVT_CALL(SetActorDispOffset, ACTOR_GENERAL, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(SetAnimatedModelRootPosition, 0, 380, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_GENERAL, 50, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_GENERAL, SOUND_ACTOR_COLLAPSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim10)
    EVT_CALL(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 18)
    EVT_CALL(ForceHomePos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_CALL(SetEnemyHP, ACTOR_GENERAL, 1)
    EVT_CALL(SetPartDispOffset, ACTOR_GENERAL, PRT_MAIN, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_GENERAL, 0, 0, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_GENERAL, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_GENERAL, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim07)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 6, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar1, 30)
    EVT_PLAY_EFFECT(EFFECT_STARS_ORBITING, 0, LVar0, LVar1, LVar2, 20, 4, LVarF, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_GENERAL, SOUND_KNOCKOUT_CHIRPING)
    EVT_CALL(DropStarPoints, ACTOR_GENERAL)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(ActorExists, ACTOR_BULB, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(SetActorFlagBits, ACTOR_BULB, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_END_IF
    EVT_CALL(SetActorFlagBits, ACTOR_GENERAL, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageDarkness) = {
    EVT_LABEL(0)
        EVT_CALL(ActorExists, ACTOR_SELF, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetDarknessStatus, LVar0, LVar1)
        EVT_IF_EQ(LVar0, SCREEN_LAYER_BACK)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_ModulateDarkness, LVar0)
        EVT_IF_FALSE(LVar0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, LVar1)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_WATT)
            EVT_EXEC_WAIT(N(EVS_DecreaseDarknessAmt))
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Tank_UsingBulbAttack, LVar0)
            EVT_IF_TRUE(LVar0)
                EVT_EXEC_WAIT(N(EVS_DecreaseDarknessAmt))
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_IncreaseDarknessAmt))
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(SetDarknessParams), LVar1)
        EVT_LABEL(10)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DecreaseDarknessAmt) = {
    EVT_IF_NE(LVar1, 0)
        EVT_SUB(LVar1, 5)
        EVT_IF_LT(LVar1, 0)
            EVT_SET(LVar1, 0)
        EVT_END_IF
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, LVar1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_IncreaseDarknessAmt) = {
    EVT_IF_NE(LVar1, 215)
        EVT_ADD(LVar1, 5)
        EVT_IF_GT(LVar1, 215)
            EVT_SET(LVar1, 215)
        EVT_END_IF
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Tank_DarknessAmt, LVar1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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

