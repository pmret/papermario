#include "../area.h"
#include "sprite/npc/Paragoomba.h"
#include "sprite/npc/Goomba.h"
#include "sprite/npc/Goompa.h"

#define NAMESPACE A(tutorial_paragoomba)

extern s32 N(DefaultAnims)[];
extern s32 N(LeftWingAnims)[];
extern s32 N(RightWingAnims)[];
extern EvtScript N(EVS_Init_Tutorial);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_KnockDown);

extern s32 A(downed_goomba_tutorial_DefaultAnims)[];
extern EvtScript A(downed_goomba_tutorial_EVS_Init);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1, // body after being downed (must use same name as Goomba part #1)
    PRT_FLYING          = 2, // body while flying
    PRT_DUMMY_WING_L    = 3, // temporary wing while being downed
    PRT_DUMMY_WING_R    = 4, // temporary wing while being downed
};

enum N(ActorParams) {
    DMG_AIR_KICK        = 1,
};

s32 N(DownedDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DownedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
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

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,             80,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,               80,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
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
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = A(downed_goomba_tutorial_DefaultAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DUMMY_WING_L,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(LeftWingAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DUMMY_WING_R,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(RightWingAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PARAGOOMBA,
    .level = ACTOR_LEVEL_PARAGOOMBA,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init_Tutorial),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 90,
    .airLiftChance = 100,
    .hurricaneChance = 100,
    .spookChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 36, 26 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Idle,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Idle,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Dizzy,
    STATUS_END,
};

s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Run,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Idle,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Run,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Dizzy,
    STATUS_END,
};

s32 N(LeftWingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_LWingStill,
    STATUS_END,
};

s32 N(RightWingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_RWingStill,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(10)
        Call(RandInt, 80, LVar0)
        Add(LVar0, 80)
        Loop(LVar0)
            Label(0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(0)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(0.6))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(ShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        Loop(20)
            Label(1)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(1)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(0.6))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(DefaultAnims)))
        Loop(40)
            Label(2)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(2)
                EndIf
            Wait(1)
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Paragoomba_GoHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Idle)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(GetEncounterTrigger, LVar0)
                IfEq(LVar0, ENCOUNTER_TRIGGER_HAMMER)
                    ExecWait(N(EVS_KnockDown))
                EndIf
            EndIf
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_BurnHurt)
            SetConst(LVar2, ANIM_Paragoomba_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_BurnHurt)
            SetConst(LVar2, ANIM_Paragoomba_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FALL_TRIGGER)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_KnockDown))
        CaseEq(EVENT_15)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_BurnHurt)
            SetConst(LVar2, ANIM_Paragoomba_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_KnockDown))
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Dizzy)
            ExecWait(N(EVS_Paragoomba_GoHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_STAR_BEAM)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Run)
            ExecWait(N(EVS_Paragoomba_GoHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Run)
            SetConst(LVar2, ANIM_Paragoomba_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(SetBattleCamZoom, 300)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Dive)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Sub(LVar0, 80)
            Set(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Dive)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            Thread
                Loop(4)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_FLY)
                    Wait(4)
                EndLoop
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Miss)
            Call(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimationRate, ACTOR_SELF, PRT_FLYING, Float(3.0))
            Wait(10)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(SetAnimationRate, ACTOR_SELF, PRT_FLYING, Float(1.0))
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Run)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_Paragoomba_GoHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseDefault
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(SetBattleCamZoom, 300)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Dive)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Dive)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EndSwitch
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_AIR_KICK, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Run)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Wait(5)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Run)
            ExecWait(N(EVS_Paragoomba_GoHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_KnockDown) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetPartFlags, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    Call(SetPartFlags, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    Call(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_DUMMY_WING_L, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_DUMMY_WING_L, -9, 7, -2)
    Call(SetPartPos, ACTOR_SELF, PRT_DUMMY_WING_R, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_DUMMY_WING_R, 11, 7, -2)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    IfEq(LVar0, EVENT_15)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_BurnStill)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hurt)
    EndIf
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(N(StartRumbleWithParams), 100, 10)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.3))
    EndThread
    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
    Call(GetLastEvent, ACTOR_SELF, LVar3)
    IfEq(LVar3, EVENT_15)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hurt)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Add(LVar4, 10)
        Add(LVar5, 5)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, Float(1.0), 10, 0)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Loop(10)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Wait(1)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(GetIndexFromHome, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Idle)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(DownedStatusTable)))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_GOOMBA)
    ExecWait(A(downed_goomba_tutorial_EVS_Init))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    Call(HPBarToHome, ACTOR_SELF)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Return
    End
};

// downed paragoombas are handled via a special nested goomba import
#define NESTED_GOOMBA_INCLUDE
#define NAMESPACE A(downed_goomba_tutorial)
#include "battle/common/actor/goomba.inc.c"

// everything above this point is identical to paragoomba

#define NAMESPACE A(tutorial_paragoomba)
extern EvtScript N(EVS_HandlePhase);

EvtScript N(EVS_Init_Tutorial) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_TutorialScene) = {
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 180)
    Wait(5)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(ActorSpeak, MSG_CH0_00B8, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
    Set(GF_Tutorial_FlyingEnemy, TRUE)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 0)
    Wait(5)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            IfEq(GF_Tutorial_FlyingEnemy, FALSE)
                ExecWait(N(EVS_TutorialScene))
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};
