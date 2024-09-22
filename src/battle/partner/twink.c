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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(N(IsPeachBattle))
    IfNe(LVar0, TRUE)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_ATTACK, TRUE)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_Twink_PowerLevel, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Twink_DefensePtr, Ref(N(DefenseTable)))
    Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SPARKLES)
    Call(ModifyActorDecoration, ACTOR_SELF, PRT_MAIN, 0, 0, 0, 0, 0)
    Return
    End
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
    Loop(0)
        Call(N(AddFlightBobbing))
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(CloseActionCommandInfo)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Gasp)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Twink_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Walk)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Gasp)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Twink_Angry)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Walk)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(N(EVS_ExecuteAction))
        CaseEq(PHASE_CELEBRATE)
            ExecWait(N(EVS_Celebrate))
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(N(EVS_RunAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(EVS_RunAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Twink_Fly)
    SetConst(LVar2, ANIM_Twink_Fly)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(EVS_RunAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Twink_Angry)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(EVS_RunAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_FLY, SOUND_TWINK_FLY_A, SOUND_TWINK_FLY_B)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MIDAIR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(InitTargetIterator)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
    Call(FlyToGoal, ACTOR_PARTNER, 0, -10, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Idle)
    Wait(3)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MIDAIR)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Cringe)
    Call(AddGoalPos, ACTOR_PARTNER, 0, 10, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    Wait(2)
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_ACTOR_JUMP)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MIDAIR)
    Call(AddGoalPos, ACTOR_PARTNER, -40, 15, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 20, -20, EASING_QUARTIC_OUT)
    Call(GetActorVar, ACTOR_SELF, AVAR_Twink_PowerLevel, LVarF)
    IfGt(LVarF, 1)
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    EndIf
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_TWINK_ATTACK)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    Call(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    Call(GetActorVar, ACTOR_SELF, AVAR_Twink_PowerLevel, LVarF)
    IfGt(LVarF, 0)
        Call(PartnerDamageEnemy, LVar0, 0, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    Else
        Call(PartnerDamageEnemy, LVar0, 0, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 10)
    Call(AddGoalPos, ACTOR_PARTNER, 150, 100, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 15, 20, EASING_LINEAR)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Loop(0)
        Wait(1)
        Call(GetActorVar, ACTOR_ENEMY0, AVAR_Kammy_Speaking, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_FLY, SOUND_TWINK_FLY_A, SOUND_TWINK_FLY_B)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Twink_Angry)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
    Call(FlyToGoal, ACTOR_PARTNER, 0, -20, EASING_COS_IN_OUT)
    Call(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};
