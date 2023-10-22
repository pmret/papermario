#include "../area.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/npc/TubbasHeart.h"
#include "sprite/player.h"

#define NAMESPACE A(tubbas_heart)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Move_Charge);
extern EvtScript N(EVS_Attack_Leap);
extern EvtScript N(EVS_Attack_DarkSwarm);
extern EvtScript N(EVS_FleeFromBattle);
extern EvtScript N(EVS_ReturnHome);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_NextMove           = 0,
    AVAL_NextMove_Charge    = 0,
    AVAL_NextMove_Swarm     = 1,
    AVAL_NextMove_Leap      = 2,
    AVAR_ChargeLevel        = 1,
    AVAR_Flags              = 2,
    AVAL_Flag_TauntBow      = 1,
    AVAL_Flag_HidStatusBar  = 2,
    AVAR_ChargeTaunt        = 3,
    AVAR_ChargedEffectID    = 4,
    AVAR_SwarmCount         = 5,
};

enum N(ActorParams) {
    DMG_LEAP        = 6,
    DMG_SWARM       = 12,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TubbasHeart_Anim01,
    STATUS_KEY_STONE,     ANIM_TubbasHeart_Anim00,
    STATUS_KEY_SLEEP,     ANIM_TubbasHeart_Anim04,
    STATUS_KEY_POISON,    ANIM_TubbasHeart_Anim01,
    STATUS_KEY_STOP,      ANIM_TubbasHeart_Anim00,
    STATUS_KEY_STATIC,    ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_FEAR,      ANIM_TubbasHeart_Anim0A,
    STATUS_END,
};

s32 N(ChargedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TubbasHeart_Anim0B,
    STATUS_KEY_STONE,     ANIM_TubbasHeart_Anim00,
    STATUS_KEY_SLEEP,     ANIM_TubbasHeart_Anim04,
    STATUS_KEY_POISON,    ANIM_TubbasHeart_Anim0B,
    STATUS_KEY_STOP,      ANIM_TubbasHeart_Anim00,
    STATUS_KEY_STATIC,    ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_FEAR,      ANIM_TubbasHeart_Anim0A,
    STATUS_END,
};

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
    STATUS_KEY_SHRINK,             90,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 54, 0 },
        .targetOffset = { 0, -30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUBBA_HEART,
    .level = ACTOR_LEVEL_TUBBA_HEART,
    .maxHP = 50,
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
    .size = { 30, 30 },
    .healthBarOffset = { 5, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Charge)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargeLevel, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SwarmCount, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_TARGET_NO_SMASH, TRUE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(UpdateChargeEffectPos)) {
    Bytecode *args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    f32 scale = evt_get_float_variable(script, *args++);

    effect->data.energyInOut->pos.x = x;
    effect->data.energyInOut->pos.y = y;
    effect->data.energyInOut->pos.z = z;
    effect->data.energyInOut->scale = scale;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(ActorExists, ACTOR_SELF, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar4)
                EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar2, 15)
                    EVT_SETF(LVar4, EVT_FLOAT(1.0))
                EVT_ELSE
                    EVT_ADD(LVar2, 6)
                    EVT_SETF(LVar4, EVT_FLOAT(0.4))
                EVT_END_IF
                EVT_CALL(N(UpdateChargeEffectPos), LVar0, LVar1, LVar2, LVar3, LVar4)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SelectAnimation) = {
    EVT_SET(LVar1, ANIM_TubbasHeart_Anim0E)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_SET(LVar1, ANIM_TubbasHeart_Anim0B)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(EVS_SelectAnimation))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TubbasHeart_Anim10)
            EVT_SET_CONST(LVar2, ANIM_TubbasHeart_Anim11)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(EVS_SelectAnimation))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(EVS_SelectAnimation))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_EXEC_WAIT(N(EVS_SelectAnimation))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET(LVar1, ANIM_TubbasHeart_Anim01)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_SET(LVar1, ANIM_TubbasHeart_Anim0B)
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(EVS_SelectAnimation))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(EVS_SelectAnimation))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TubbasHeart_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 5)
        EVT_EXEC_WAIT(N(EVS_FleeFromBattle))
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FleeFromBattle) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(ActorSpeak, MSG_CH3_00C6, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0D, ANIM_TubbasHeart_Anim0D)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, TRUE)
    EVT_CALL(SetEndBattleFadeOutRate, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 45)
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim01)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_IF_NE(LVar0, HIT_RESULT_MISS)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, AVAL_Flag_TauntBow)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_EQ(LVar0, PARTNER_BOW)
                EVT_CALL(EnableBattleStatusBar, FALSE)
                //@bug -- meant to OR 3 with value of AVAR_Flags, not PARTNER_BOW
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Flag_TauntBow | AVAL_Flag_HidStatusBar)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 40)
                EVT_WAIT(40)
                EVT_CALL(ActorSpeak, MSG_CH3_00C3, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_PARTNER)
                EVT_CALL(MoveBattleCamOver, 25)
                EVT_WAIT(25)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, 1, ANIM_BattleBow_Talk)
                EVT_CALL(ActorSpeak, MSG_CH3_00C4, ACTOR_PARTNER, 1, ANIM_BattleBow_Talk, ANIM_BattleBow_Idle)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, 1, ANIM_BattleBow_Laugh)
                EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, -1, -1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
                EVT_IF_EQ(LVar0, AVAL_NextMove_Charge)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, LVar0)
                    EVT_IF_TRUE(LVar0)
                        EVT_CALL(EnableBattleStatusBar, TRUE)
                    EVT_END_IF
                EVT_ELSE
                    EVT_CALL(EnableBattleStatusBar, TRUE)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_NextMove_Charge)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 40)
                EVT_WAIT(40)
                EVT_CALL(ActorSpeak, MSG_CH3_00C5, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_Move_Charge))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Swarm)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AVAL_Flag_HidStatusBar)
                EVT_CALL(EnableBattleStatusBar, TRUE)
            EVT_END_IF
        EVT_CASE_EQ(AVAL_NextMove_Swarm)
            EVT_EXEC_WAIT(N(EVS_Attack_DarkSwarm))
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SwarmCount, LVar1)
                EVT_ADD(LVar1, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SwarmCount, LVar1)
                EVT_IF_GE(LVar1, 2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Leap)
                EVT_ELSE
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Charge)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(AVAL_NextMove_Leap)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Charge)
            EVT_EXEC_WAIT(N(EVS_Attack_Leap))
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AVAL_Flag_HidStatusBar)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Leap) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 45)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim16)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim01)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_Charge) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 85, 50, 0)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar4)
    EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 15)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_ADD(LVar1, 6)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 1, LVar0, LVar1, LVar2, LVar3, 60, 0)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, LVar3, 60, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_TUBBAS_HEART_CHARGE)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargeLevel, 1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar4)
    EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 15)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_ADD(LVar1, 6)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 3, LVar0, LVar1, LVar2, LVar3, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, LVarF)
    EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ChargedAnims)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_DarkSwarm) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 85, 50, 0)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 16)
    EVT_ELSE
        EVT_ADD(LVar1, 6)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, LVar0)
        EVT_CALL(RemoveEffect, LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_TUBBAS_HEART_SWARM_ATTACK)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 5)
            EVT_PLAY_EFFECT(EFFECT_TUBBA_HEART_ATTACK, FX_HEART_SWARM_MISS, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 200, 0)
            EVT_WAIT(145)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_ELSE
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 5)
    EVT_PLAY_EFFECT(EFFECT_TUBBA_HEART_ATTACK, FX_HEART_SWARM_HIT, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 200, 0)
    EVT_THREAD
        EVT_WAIT(160)
        EVT_CALL(PlaySound, SOUND_TUBBAS_HEART_SWARM_VANISH)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, 35)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT(56)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SQUEEZE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
    EVT_WAIT(37)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SQUEEZE)
    EVT_WAIT(22)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TUBBAS_HEART_SWARM_DISPERSE)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_RETURN
    EVT_END
};
