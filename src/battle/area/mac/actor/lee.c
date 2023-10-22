#include "../area.h"
#include "sprite/npc/Lee.h"
#include "sprite/npc/BattleBombette.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/npc/BattleGoombario.h"
#include "sprite/npc/BattleKooper.h"
#include "sprite/npc/BattleLakilester.h"
#include "sprite/npc/BattleParakarry.h"
#include "sprite/npc/BattleSushie.h"
#include "sprite/npc/BattleWatt.h"

#define NAMESPACE A(lee)

// scripts in lee.c calls two functions defined in lee_watt.c for adjusting the background fade
// this macro is used to highlight those instances
#define WATT(x) A( watt_lee_##x )

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Move_CopyPartner);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
    PRT_SPINY       = 3,
    PRT_ZERO        = 0,
};

enum N(ActorVars) {
    AVAR_HandledEvent           = 0,
    AVAR_Copy_ParentActorID     = 0,
    AVAR_Copy_PartnerLevel      = 1,
    AVAR_FormDuration           = 2,
    AVAR_Kooper_Toppled         = 4,
    AVAR_Kooper_ToppleTurns     = 5,
    AVAR_State                  = 8,
    AVAL_State_ReadyToCopy      = 0, // will copy partner next turn
    AVAL_State_CopiedPartner    = 1, // currently transformed
    AVAL_State_ReadyToTackle    = 2, // will use flying tackle next turn
    AVAL_State_WaitToTackle     = 3, // do nothing this turn and tackle next turn (unused)
};

enum N(ActorParams) {
    DMG_FLYING_LEAP     = 5,
};

BSS s32 PartnerCopyHistory[12];
BSS s32 LastPartnerCopied;

API_CALLABLE(N(InitPartnerCopyHistory)) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
        PartnerCopyHistory[i] = 0;
    }
    LastPartnerCopied = -1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(RegisterPartnerToCopy)) {
    PlayerData* playerData = &gPlayerData;
    s32 currentPartner = script->varTable[5];
    s32 partnerId;
    s32 i;
    s32 randomPartnerMap[ARRAY_COUNT(PartnerCopyHistory)];

    // initial case
    if (LastPartnerCopied < 0) {
        LastPartnerCopied = currentPartner;
        PartnerCopyHistory[currentPartner] = TRUE;
        return ApiStatus_DONE2;
    }

    // current partner has never been copied
    if (LastPartnerCopied != currentPartner && !PartnerCopyHistory[currentPartner]) {
        LastPartnerCopied = currentPartner;
        PartnerCopyHistory[currentPartner] = TRUE;
        return ApiStatus_DONE2;
    }

    // prepare to select a partner at random
    for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
        randomPartnerMap[i] = i;
    }

    // randomly swap 100 times
    for (i = 0; i < 100; i++) {
        s32 index1 = rand_int(ARRAY_COUNT(PartnerCopyHistory) - 1);
        s32 index2 = rand_int(ARRAY_COUNT(PartnerCopyHistory) - 1);
        s32 tempValue = randomPartnerMap[index1];
        randomPartnerMap[index1] = randomPartnerMap[index2];
        randomPartnerMap[index2] = tempValue;
    }

    // search the shuffled list for a valid partner who has not been copied
    for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
        partnerId = randomPartnerMap[i];

        if (playerData->partners[partnerId].enabled
            && partnerId != PARTNER_GOOMPA
            && partnerId != PARTNER_GOOMBARIA
            && partnerId != PARTNER_TWINK
            && partnerId != currentPartner
            && !PartnerCopyHistory[partnerId]
        ) {
            break;
        }
    }

    if (i < ARRAY_COUNT(PartnerCopyHistory)) {
        // if a valid partner was found, return it
        PartnerCopyHistory[partnerId] = TRUE;
        LastPartnerCopied = partnerId;
        script->varTable[5] = partnerId;
        script->varTable[6] = playerData->partners[partnerId].level;
        return ApiStatus_DONE2;
    } else {
        // no valid selections were found, reset the copy history and just use the current partner
        for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
            PartnerCopyHistory[i] = FALSE;
        }
        LastPartnerCopied = currentPartner;
        PartnerCopyHistory[currentPartner] = TRUE;
        return ApiStatus_DONE2;
    }
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lee_Idle,
    STATUS_KEY_STONE,     ANIM_Lee_Still,
    STATUS_KEY_SLEEP,     ANIM_Lee_Sleep,
    STATUS_KEY_POISON,    ANIM_Lee_Idle,
    STATUS_KEY_STOP,      ANIM_Lee_Still,
    STATUS_KEY_STATIC,    ANIM_Lee_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Lee_Still,
    STATUS_KEY_DIZZY,     ANIM_Lee_Dizzy,
    STATUS_KEY_DIZZY,     ANIM_Lee_Dizzy,
    STATUS_END,
};

s32 N(FlailingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lee_Hurt,
    STATUS_END,
};

s32 N(UnusedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lee_Run,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             75,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               75,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,        -1,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 25 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_LEE,
    .level = ACTOR_LEVEL_LEE,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 36, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToCopy)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HandledEvent, FALSE)
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_EXEC_WAIT(N(EVS_Move_CopyPartner))
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(N(InitPartnerCopyHistory))
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_Lee_Run)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HandledEvent, TRUE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Burned)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Burned)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Burned)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Run)
            EVT_SET_CONST(LVar2, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Run)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lee_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_FlyingTackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToCopy)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Crouch)
    EVT_WAIT(20)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_DUPLIGHOST_LEAP, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Midair)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 17, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Idle)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Midair)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, EVT_FLOAT(4.0), EVT_FLOAT(-6.0), 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -15, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_FLYING_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Land)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Lee_RemoveParentActor) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_ParentActorID, LVar0)
    EVT_CALL(RemoveActor, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Lee_LoseDisguise) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(30)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_ParentActorID, LVarA)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(HideHealthBar, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
    EVT_CALL(SetEnemyHP, LVarA, LVarB)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(SetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, LVarA, AVAR_State, AVAL_State_ReadyToTackle)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetIdleAnimations, LVarA, PRT_MAIN, EVT_PTR(N(FlailingAnims)))
    EVT_CALL(SetAnimation, LVarA, PRT_MAIN, ANIM_Lee_Hurt)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_IF_GT(LVarC, 0)
        EVT_SET(LVarC, 0)
        EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.5))
        EVT_CALL(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 15, FALSE, TRUE, FALSE)
        EVT_CALL(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_CALL(ForceHomePos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(SetIdleAnimations, LVarA, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_CALL(SetAnimation, LVarA, PRT_MAIN, ANIM_Lee_Idle)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Lee_ShockKnockback) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
    EVT_SET(LVar0, LVarA)
    EVT_SET(LVar1, LVarB)
    EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, LVarC, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, -48)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3i A(Lee_SummonPos) = { NPC_DISPOSE_LOCATION };

#include "lee_goombario.inc.c"
#include "lee_kooper.inc.c"
#include "lee_bombette.inc.c"
#include "lee_parakarry.inc.c"
#include "lee_bow.inc.c"
#include "lee_watt.inc.c"
#include "lee_sushie.inc.c"
#include "lee_lakilester.inc.c"
#define NAMESPACE A(lee)

API_CALLABLE(N(GetPartnerAndLevel)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.curPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.curPartner].level);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AdjustFormationPriority)) {
    Bytecode* args = script->ptrReadPos;
    s32 partnerID = evt_get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.enemyID);
    FormationRow* formation = NULL;

    switch (partnerID) {
        case PARTNER_GOOMBARIO:
            formation = A(LeeGoombarioFormation);
            break;
        case PARTNER_KOOPER:
            formation = A(LeeKooperFormation);
            break;
        case PARTNER_BOMBETTE:
            formation = A(LeeBombetteFormation);
            break;
        case PARTNER_PARAKARRY:
            formation = A(LeeParakarryFormation);
            break;
        case PARTNER_BOW:
            formation = A(LeeBowFormation);
            break;
        case PARTNER_WATT:
            formation = A(LeeWattFormation);
            break;
        case PARTNER_SUSHIE:
            formation = A(LeeSushieFormation);
            break;
        case PARTNER_LAKILESTER:
            formation = A(LeeLakilesterFormation);
            break;
    }
    formation->priority = actor->turnPriority + 10;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Move_CopyPartner) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(ActorSpeak, MSG_MAC_Gate_0027, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GHOST_TRANSFORM)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_RaisedArmsTalk)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 8)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LVar1, 20)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, LVar3, 40, 0)
    EVT_CALL(WATT(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 20, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(WATT(SetBackgroundAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(N(GetPartnerAndLevel), LVar5, LVar6)
    EVT_CALL(N(RegisterPartnerToCopy))
    EVT_CALL(N(AdjustFormationPriority), LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeGoombarioFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeKooperFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeBombetteFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeParakarryFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_BOW)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeBowFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_WATT)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeWattFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_SUSHIE)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeSushieFormation)), FALSE)
        EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CALL(SummonEnemy, EVT_PTR(A(LeeLakilesterFormation)), FALSE)
    EVT_END_SWITCH
    EVT_SET(LVarA, LVar0)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, (ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY), TRUE)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, LVarA, LVar0)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetOwnerID, LVar0)
    EVT_CALL(SetActorVar, LVarA, AVAR_Copy_ParentActorID, LVar0)
    EVT_CALL(SetActorVar, LVarA, AVAR_Copy_PartnerLevel, LVar6)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(MakeLerp, 200, 0, 20, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(WATT(SetBackgroundAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LVarA, LVar0, 10, LVar2)
            EVT_CALL(JumpToGoal, LVarA, 10, FALSE, FALSE, FALSE)
            EVT_WAIT(10)
        EVT_CASE_OR_EQ(PARTNER_WATT)
        EVT_CASE_OR_EQ(PARTNER_BOW)
        EVT_CASE_OR_EQ(PARTNER_PARAKARRY)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LVarA, LVar0, 30, LVar2)
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
    EVT_WAIT(20)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_CopiedPartner)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_ReadyToCopy)
            EVT_EXEC_WAIT(N(EVS_Move_CopyPartner))
        EVT_CASE_EQ(AVAL_State_CopiedPartner)
            // do nothing
        EVT_CASE_EQ(AVAL_State_ReadyToTackle)
            EVT_EXEC_WAIT(N(EVS_Attack_FlyingTackle))
        EVT_CASE_EQ(AVAL_State_WaitToTackle)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToTackle)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_FLAG_SHRINK)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            EVT_DIV(LVar1, 2)
            EVT_IF_LE(LVar0, LVar1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                EVT_IF_EQ(LVar0, AVAL_State_CopiedPartner)
                    EVT_CALL(ActorSpeak, MSG_MAC_Gate_0028, ACTOR_ENEMY1, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
                EVT_ELSE
                    EVT_CALL(ActorSpeak, MSG_MAC_Gate_0028, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
                EVT_END_IF
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_LE(LVar0, 5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0029, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
