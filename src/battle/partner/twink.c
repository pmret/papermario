#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Twink.h"
#include "sprite/player.h"

#define NAMESPACE battle_partner_twink

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(EVS_RunAway);
extern EvtScript N(EVS_RunAwayFail);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Twink_PowerLevel   = 0,
    AVAR_Twink_DefensePtr   = 1,
    AVAR_Kammy_Speaking     = 1,
};

API_CALLABLE(N(IsPeachBattle)) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (battleStatus->flags2 & BS_FLAGS2_PEACH_BATTLE) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    return ApiStatus_DONE2;
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Twink_Angry,
    STATUS_KEY_INACTIVE,  ANIM_Twink_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
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
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_DMG_APPLY,
    .type = ACTOR_TYPE_TWINK,
    .level = ACTOR_LEVEL_TWINK,
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
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 20, 20 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 13, 31 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(N(IsPeachBattle))
    EVT_IF_NE(LVar0, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_ATTACK, TRUE)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Twink_PowerLevel, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Twink_DefensePtr, EVT_PTR(N(DefenseTable)))
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SPARKLES)
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

s32 N(BobPhase) = 0;

API_CALLABLE(N(AddFlightBobbing)) {
    Actor* actor = get_actor(script->owner1.actorID);

    N(BobPhase) += 18;
    N(BobPhase) = clamp_angle(N(BobPhase));
    actor->verticalRenderOffset = 2.0f * sin_rad(DEG_TO_RAD(N(BobPhase)));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    EVT_LOOP(0)
        EVT_CALL(N(AddFlightBobbing))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Gasp)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Twink_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Walk)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Gasp)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Twink_Angry)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Walk)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(EVS_ExecuteAction))
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(N(EVS_Celebrate))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(EVS_RunAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(EVS_RunAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Celebrate) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_Twink_Fly)
    EVT_SET_CONST(LVar2, ANIM_Twink_Fly)
    EVT_EXEC_WAIT(EVS_Partner_Celebrate)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RunAway) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_Twink_Angry)
    EVT_EXEC_WAIT(EVS_Partner_RunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RunAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExecuteAction) = {
    EVT_CALL(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_FLY, SOUND_TWINK_FLY_A, SOUND_TWINK_FLY_B)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, -10, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Idle)
    EVT_WAIT(3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Cringe)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, 0, 10, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_ACTOR_JUMP)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -40, 15, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, -20, EASING_QUARTIC_OUT)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Twink_PowerLevel, LVarF)
    EVT_IF_GT(LVarF, 1)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_TWINK_ATTACK)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Twink_PowerLevel, LVarF)
    EVT_IF_GT(LVarF, 0)
        EVT_CALL(PartnerDamageEnemy, LVar0, 0, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_ELSE
        EVT_CALL(PartnerDamageEnemy, LVar0, 0, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, 150, 100, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, 20, EASING_LINEAR)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, AVAR_Kammy_Speaking, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_FLY, SOUND_TWINK_FLY_A, SOUND_TWINK_FLY_B)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, -20, EASING_COS_IN_OUT)
    EVT_CALL(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};
