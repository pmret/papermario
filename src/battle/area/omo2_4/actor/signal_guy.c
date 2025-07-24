#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/MarshalGuy.h"

#define NAMESPACE b_area_omo2_4_signal_guy

extern s32 N(DefaultAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_NO_STATUS_ANIMS,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_DMG_POPUP,
    .type = ACTOR_TYPE_SIGNAL_GUY,
    .level = ACTOR_LEVEL_SIGNAL_GUY,
    .maxHP = 8,
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
    .size = { 30, 30 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MarshalGuy_Anim01,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorPos, ACTOR_SELF, 180, 0, 0)
    Call(ForceHomePos, ACTOR_SELF, 180, 0, 0)
    Call(HPBarToHome, ACTOR_SELF)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim0F)
        Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
        Call(SetGoalPos, ACTOR_SELF, 0, 0, 0)
        Call(RunToGoal, ACTOR_SELF, 0, false)
        Call(SetActorYaw, ACTOR_SELF, 180)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GENERAL_WHISTLE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim04)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim05)
        Wait(15)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim09)
    EndThread
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_BURN_DEATH)
        CaseOrEq(EVENT_SPIN_SMASH_HIT)
        CaseOrEq(EVENT_SPIN_SMASH_DEATH)
        CaseOrEq(EVENT_SHOCK_HIT)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_SPIKE_TAUNT)
        CaseOrEq(EVENT_DEATH)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim0A)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 35)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim02)
            Wait(24)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim03)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 5)
            Add(LVar1, 10)
            Loop(4)
                PlayEffect(EFFECT_SWEAT, 0, LVar0, LVar1, LVar2, 10, 45, 4, 0)
                Wait(6)
            EndLoop
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MarshalGuy_Anim0C)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_STEAM_EMITTER)
            Call(SetGoalPos, ACTOR_SELF, -200, 0, 20)
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(RemoveActorDecoration, ACTOR_SELF, LVar0, 0)
            Call(RemoveActor, ACTOR_SELF)
            Return
        EndCaseGroup
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MarshalGuy_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MarshalGuy_Anim0A)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MarshalGuy_Anim01)
            SetConst(LVar2, ANIM_MarshalGuy_Anim0A)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
            SetConst(LVar1, ANIM_MarshalGuy_Anim0A)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            Wait(20)
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Return
    End
};
