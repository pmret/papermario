#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/LavaBubble.h"

#define NAMESPACE A(lava_bubble)

extern s32 N(DefaultAnims)[];
extern s32 N(ProjectileAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_FIRE_1      = 2,
    PRT_FIRE_2      = 3,
    PRT_FIRE_3      = 4,
    PRT_FIRE_4      = 5,
};

enum N(ActorVars) {
    AVAR_IN_NoTackle    = 0,
    AVAR_CanTackle      = 0,
    AVAR_Generation     = 1,
    AVAR_PauseIdle      = 2,
};

enum N(ActorParams) {
    DMG_TACKLE          = 4,
    DMG_SHOOT_PLAYER    = 4,
    DMG_SHOOT_PARTNER   = 2,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,   -2,
    ELEMENT_ICE,     -2,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,   -1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 25 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FIREY,
        .elementImmunityFlags = ELEMENT_FIRE,
        .projectileTargetOffset = { -3, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FIRE_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ProjectileAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LAVA_BUBBLE,
    .level = ACTOR_LEVEL_LAVA_BUBBLE,
    .maxHP = 9,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 90,
    .hurricaneChance = 85,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 33, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaBubble_Anim01,
    STATUS_KEY_STONE,     ANIM_LavaBubble_Anim00,
    STATUS_KEY_SLEEP,     ANIM_LavaBubble_Anim01,
    STATUS_KEY_POISON,    ANIM_LavaBubble_Anim01,
    STATUS_KEY_STOP,      ANIM_LavaBubble_Anim00,
    STATUS_KEY_STATIC,    ANIM_LavaBubble_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_LavaBubble_Anim00,
    STATUS_KEY_DIZZY,     ANIM_LavaBubble_Anim0A,
    STATUS_KEY_FEAR,      ANIM_LavaBubble_Anim0A,
    STATUS_END,
};

s32 N(ProjectileAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaBubble_Anim01,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(GetActorVar, ACTOR_SELF, AVAR_IN_NoTackle, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetActorVar, ACTOR_SELF, AVAR_CanTackle, true)
        CaseEq(1)
            Call(SetActorVar, ACTOR_SELF, AVAR_CanTackle, false)
    EndSwitch
    Call(SetPartScale, ACTOR_SELF, PRT_FIRE_1, Float(0.5), Float(0.5), Float(0.5))
    Call(SetPartScale, ACTOR_SELF, PRT_FIRE_2, Float(0.5), Float(0.5), Float(0.5))
    Call(SetPartScale, ACTOR_SELF, PRT_FIRE_3, Float(0.5), Float(0.5), Float(0.5))
    Call(SetPartScale, ACTOR_SELF, PRT_FIRE_4, Float(0.5), Float(0.5), Float(0.5))
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_PauseIdle, false)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 5)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(MakeLerp, 0, 10, 25, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(GetHomePos, ACTOR_SELF, LVar2, LVar3, LVar4)
            Add(LVar0, LVar3)
            Call(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            IfEq(LVar1, 1)
                Label(11)
                    Wait(1)
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        Goto(11)
                    EndIf
                    Call(GetActorVar, ACTOR_SELF, AVAR_PauseIdle, LVar0)
                    IfEq(LVar0, 1)
                        Goto(11)
                    EndIf
                Goto(1)
            EndIf
        Call(MakeLerp, 10, 0, 25, EASING_COS_IN_OUT)
        Label(2)
            Call(UpdateLerp)
            Call(GetHomePos, ACTOR_SELF, LVar2, LVar3, LVar4)
            Add(LVar0, LVar3)
            Call(SetActorPos, ACTOR_SELF, LVar2, LVar0, LVar4)
            IfEq(LVar1, 1)
                Label(22)
                    Wait(1)
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        Goto(22)
                    EndIf
                    Call(GetActorVar, ACTOR_SELF, AVAR_PauseIdle, LVar0)
                    IfEq(LVar0, 1)
                        Goto(22)
                    EndIf
                Goto(2)
            EndIf
        Goto(0)
    Return
    End
};

#include "common/PlayLavaBubbleFlightSound.inc.c"

EvtScript N(EVS_Ember_FlyHome) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim03)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Thread
        Call(N(PlayLavaBubbleFlightSound))
    EndThread
    Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim01)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim08)
            SetConst(LVar2, ANIM_LavaBubble_Anim09)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim08)
            SetConst(LVar2, ANIM_LavaBubble_Anim09)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim09)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_FLY | SOUND_ID_TRIGGER_CHANGE_SOUND)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_Ember_FlyHome))
        CaseEq(EVENT_SHOCK_DEATH)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_FLY | SOUND_ID_TRIGGER_CHANGE_SOUND)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
        CaseOrEq(EVENT_BURN_TAUNT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_Hit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_Ember_FlyHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim03)
            SetConst(LVar2, ANIM_LavaBubble_Anim07)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim03)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LavaBubble_Anim03)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_UP_AND_AWAY)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_Tackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim03)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 5)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Thread
        Call(N(PlayLavaBubbleFlightSound))
    EndThread
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim01)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim04)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Add(LVar2, 1)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 3, false, true, false)
            Wait(14)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_Ember_FlyHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim04)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, 1)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_LavaBubble_Anim04)
            ExecWait(EVS_Enemy_Knockback)
            Wait(5)
            ExecWait(N(EVS_Ember_FlyHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

// (in) LVar3 posX
// (in) LVar4 posY
// (in) LVar5 posZ
EvtScript N(EVS_ShootFire_Impl) = {
    Set(LVar6, 2)
    Loop(4)
        Thread
            Call(GetStatusFlags, ACTOR_SELF, LVarA)
            IfFlag(LVarA, STATUS_FLAG_SHRINK)
                Call(SetPartScale, ACTOR_SELF, LVar6, Float(0.2), Float(0.2), Float(0.2))
            Else
                Call(SetPartScale, ACTOR_SELF, LVar6, Float(0.5), Float(0.5), Float(0.5))
            EndIf
            Call(SetPartPos, ACTOR_SELF, LVar6, LVar0, LVar1, LVar2)
            Call(SetPartFlagBits, ACTOR_SELF, LVar6, ACTOR_PART_FLAG_INVISIBLE, false)
            Call(SetPartMoveSpeed, ACTOR_SELF, LVar6, Float(8.0))
            Call(SetPartJumpGravity, ACTOR_SELF, LVar6, Float(0.01))
            Call(SetPartSounds, ACTOR_SELF, LVar6, ACTOR_SOUND_JUMP, SOUND_EMBER_SPIT, SOUND_NONE)
            Call(JumpPartTo, ACTOR_SELF, LVar6, LVar3, LVar4, LVar5, 0, false)
            Call(SetPartFlagBits, ACTOR_SELF, LVar6, ACTOR_PART_FLAG_INVISIBLE, true)
        EndThread
        Wait(3)
        Add(LVar6, 1)
    EndLoop
    Return
    End
};

// Shoot fireballs at a target and wait before yielding.
// (in) LVar3 posX
// (in) LVar4 posY
// (in) LVar5 posZ
EvtScript N(EVS_ShootFire) = {
    Exec(N(EVS_ShootFire_Impl))
    Call(GetDistanceToGoal, ACTOR_SELF, LVar0)
    DivF(LVar0, Float(8.0))
    Add(LVar0, 1)
    Wait(LVar0)
    Return
    End
};

EvtScript N(EVS_Attack_ShootPartner) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(GetActorVar, ACTOR_SELF, AVAR_CanTackle, LVarA)
    IfEq(LVarA, true)
        Add(LVar0, 100)
        Set(LVar1, 5)
    Else
        Add(LVar0, 30)
        Set(LVar1, 50)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Thread
        Call(N(PlayLavaBubbleFlightSound))
    EndThread
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim01)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim05)
    Wait(30)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim06)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 5)
            Add(LVar1, 4)
            Add(LVar2, 2)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Sub(LVar3, 100)
            Add(LVar5, 2)
            ExecWait(N(EVS_ShootFire))
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_Ember_FlyHome))
            Wait(20)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim06)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 5)
    Add(LVar1, 4)
    Add(LVar2, 2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar4, 6)
    Add(LVar5, 2)
    ExecWait(N(EVS_ShootFire))
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
    Wait(20)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            ExecWait(N(EVS_Ember_FlyHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_ShootPlayer) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim03)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Thread
        Call(N(PlayLavaBubbleFlightSound))
    EndThread
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_SIN_OUT)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Wait(10)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_JUMP)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim04)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, false, false)
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Add(LVar2, 2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim04)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_Ember_FlyHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Wait(5)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMBER_JUMP)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBubble_Anim04)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, false, false)
    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, 2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, 0, 0, DMG_SHOOT_PLAYER, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            Wait(20)
            ExecWait(N(EVS_Ember_FlyHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(GetActorVar, ACTOR_SELF, AVAR_CanTackle, LVar0)
        Switch(LVar0)
            CaseEq(1)
                ExecWait(N(EVS_Attack_Tackle))
            CaseEq(0)
                ExecWait(N(EVS_Attack_ShootPlayer))
        EndSwitch
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_CanTackle, LVar0)
    Switch(LVar0)
        CaseEq(1)
            Call(GetStatusFlags, ACTOR_PARTNER, LVar0)
            IfFlag(LVar0, STATUS_FLAG_KO)
                ExecWait(N(EVS_Attack_Tackle))
            Else
                Call(RandInt, 1000, LVar0)
                IfLe(LVar0, 300)
                    ExecWait(N(EVS_Attack_ShootPartner))
                Else
                    ExecWait(N(EVS_Attack_Tackle))
                EndIf
            EndIf
        CaseEq(0)
            Call(GetStatusFlags, ACTOR_PARTNER, LVar0)
            IfFlag(LVar0, STATUS_FLAG_KO)
                ExecWait(N(EVS_Attack_ShootPlayer))
            Else
                Call(RandInt, 1000, LVar0)
                IfLe(LVar0, 300)
                    ExecWait(N(EVS_Attack_ShootPartner))
                Else
                    ExecWait(N(EVS_Attack_ShootPlayer))
                EndIf
            EndIf
    EndSwitch
    Return
    End
};
