
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/FlyingMagikoopa.h"

#define NAMESPACE A(green_magikoopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Init_Flying);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Flee);

extern s32 N(GroundAnims)[];
extern s32 N(FlyingAnims)[];
extern s32 N(BroomAnims)[];

enum N(ActorPartIDs) {
    PRT_GROUND      = 1,
    PRT_FLYING      = 2,
    PRT_BROOM       = 3,
};

enum N(ActorVars) {
    AVAR_ShouldKnockDown    = 0,
};

enum N(ActorParams) {
    DMG_MAGIC_BLAST     = 3,
    DMG_WAND_STRIKE     = 3,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(GroundParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

ActorPartBlueprint N(FlyingParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAG_RIDING_BROOMSTICK,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BROOM,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BroomAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GREEN_MAGIKOOPA,
    .level = ACTOR_LEVEL_GREEN_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(GroundParts)),
    .partsData = N(GroundParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 32 },
};

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA,
    .level = ACTOR_LEVEL_FLYING_GREEN_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(FlyingParts)),
    .partsData = N(FlyingParts),
    .initScript = &N(EVS_Init_Flying),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 40,
    .airLiftChance = 95,
    .hurricaneChance = 75,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusTextOffset = { 1, 34 },
};

s32 N(GroundAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Magikoopa_Green_Anim01,
    STATUS_KEY_STONE,     ANIM_Magikoopa_Green_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Magikoopa_Green_Anim08,
    STATUS_KEY_POISON,    ANIM_Magikoopa_Green_Anim01,
    STATUS_KEY_STOP,      ANIM_Magikoopa_Green_Anim00,
    STATUS_KEY_STATIC,    ANIM_Magikoopa_Green_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Magikoopa_Green_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Magikoopa_Green_Anim07,
    STATUS_KEY_FEAR,      ANIM_Magikoopa_Green_Anim07,
    STATUS_END,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Green_Anim01,
    STATUS_KEY_STONE,     ANIM_FlyingMagikoopa_Green_Anim00,
    STATUS_KEY_SLEEP,     ANIM_FlyingMagikoopa_Green_Anim08,
    STATUS_KEY_POISON,    ANIM_FlyingMagikoopa_Green_Anim01,
    STATUS_KEY_STOP,      ANIM_FlyingMagikoopa_Green_Anim00,
    STATUS_KEY_STATIC,    ANIM_FlyingMagikoopa_Green_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_FlyingMagikoopa_Green_Anim00,
    STATUS_KEY_DIZZY,     ANIM_FlyingMagikoopa_Green_Anim07,
    STATUS_KEY_FEAR,      ANIM_FlyingMagikoopa_Green_Anim07,
    STATUS_END,
};

s32 N(BroomAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Green_Anim0A,
    STATUS_END,
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

#include "common/ShrinkActor.inc.c"
#include "common/GetSelectedMoveID.inc.c"
#include "common/battle/SetAbsoluteStatusOffsets.inc.c"
#include "common/StartRumbleWithParams.inc.c"
#include "common/battle/CheckMagikoopaCastTarget.inc.c"

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim05)
            SetConst(LVar2, ANIM_Magikoopa_Green_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim05)
            SetConst(LVar2, ANIM_Magikoopa_Green_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim06)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim04)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim02)
            ExecWait(N(EVS_Flee))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim02)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, 0, 2, 0)
                Else
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, -4, 5, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_KnockDownCheck) = {
    Call(GetBattleFlags, LVar0)
    IfNotFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
        IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, TRUE)
        EndIf
    Else
        Call(N(GetSelectedMoveID), LVar0)
        Switch(LVar0)
            CaseOrEq(MOVE_HEADBONK1)
            CaseOrEq(MOVE_HEADBONK2)
            CaseOrEq(MOVE_HEADBONK3)
            CaseOrEq(MOVE_MULTIBONK)
                Call(GetBattleFlags, LVar0)
                IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, TRUE)
                EndIf
            EndCaseGroup
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_KnockDown) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, LVar0)
    IfEq(LVar0, TRUE)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim04)
        Goto(0)
    EndIf
    Call(GetLastElement, LVar0)
    IfFlag(LVar0, DAMAGE_TYPE_POW)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim04)
        Goto(0)
    EndIf
    Return
    Label(0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_BROOM, Float(0.4), Float(0.4), Float(0.4))
    EndIf
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 1)
    Call(SetPartPos, ACTOR_SELF, PRT_BROOM, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(N(StartRumbleWithParams), 150, 10)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.7))
    EndThread
    Call(GetLastEvent, ACTOR_SELF, LVar3)
    IfEq(LVar3, EVENT_15)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim04)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Add(LVar4, 10)
        Add(LVar5, 5)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, Float(1.0), 10, 0)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Loop(20)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Wait(1)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim01)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_GREEN_MAGIKOOPA)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 32)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(GetIndexFromPos, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HandleEvent_Flying) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Hit)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_FALL_TRIGGER)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_KnockDown))
        EndCaseGroup
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_15)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim05)
            SetConst(LVar2, ANIM_FlyingMagikoopa_Green_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_KnockDown))
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim05)
            SetConst(LVar2, ANIM_FlyingMagikoopa_Green_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim06)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim01)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim01)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim04)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim02)
            ExecWait(N(EVS_Flee))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim02)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -3, 0, 0)
                Else
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -15, 0, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Green_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_MagicBlast) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 1)
    Else
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 10)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Sub(LVar0, 12)
        Add(LVar1, 14)
    Else
        Sub(LVar0, 30)
        Add(LVar1, 36)
    EndIf
    PlayEffect(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, Float(0.5), 30, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim02)
    Wait(30)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim03)
            Wait(5)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar9)
            IfFlag(LVar9, STATUS_FLAG_SHRINK)
                Sub(LVar0, 8)
                Add(LVar1, 8)
            Else
                Sub(LVar0, 20)
                Add(LVar1, 20)
            EndIf
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Sub(LVar3, 50)
            Set(LVar4, 0)
            Call(N(ShrinkActor), LVar0, LVar1, LVar5, LVar3, LVar4, LVar5, 25)
            Wait(50)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(14)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            Wait(30)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim03)
    Wait(5)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Sub(LVar0, 8)
        Add(LVar1, 8)
    Else
        Sub(LVar0, 20)
        Add(LVar1, 20)
    EndIf
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar3, 10)
    Call(N(ShrinkActor), LVar0, LVar1, LVar5, LVar3, LVar4, LVar5, 20)
    Wait(18)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MAGIC_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(19)
            Call(YieldTurn)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_WandStrike) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_VANISH)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim02)
        Set(LVar0, 200)
        Loop(20)
            Sub(LVar0, 10)
            Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, 5)
    Else
        Add(LVar0, 25)
    EndIf
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    Set(LVar0, 55)
    Loop(20)
        Add(LVar0, 10)
        Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim03)
    Wait(11)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_WAND_STRIKE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Set(LVar0, 200)
            Loop(20)
                Sub(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim01)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Set(LVar0, 55)
            Loop(20)
                Add(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WAND_STRIKE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(10)
            Set(LVar0, 200)
            Loop(20)
                Sub(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim01)
            Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
            Set(LVar0, 55)
            Loop(20)
                Add(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Flee) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(HideHealthBar, ACTOR_SELF)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    IfNe(LVar0, EVENT_SCARE_AWAY)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 15)
        Wait(15)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Wait(10)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(YieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ExecWait(EVS_ForceNextTarget)
    Call(HideHealthBar, ACTOR_SELF)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    IfEq(LVar0, 0)
        Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, FALSE)
    Return
    End
};

EvtScript N(EVS_Init_Flying) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Flying)))
    Call(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    IfEq(LVar0, 0)
        Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, FALSE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Set(LFlag0, FALSE)
    Label(10)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetIndexFromHome, LVar0, LVar1)
        Call(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar2)
        IfGt(LVar1, LVar2)
            Call(N(CheckMagikoopaCastTarget), LVar0, LVar3)
            IfEq(LVar3, 0)
                Call(GetActorDefenseBoost, LVar0, LVar4)
                IfLt(LVar4, 3)
                    Set(LVar8, LVar0)
                    Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar1)
                    Goto(100)
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    IfEq(LFlag0, FALSE)
        Set(LFlag0, TRUE)
        Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
        Goto(10)
    EndIf
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_FLYING)
        ExecWait(N(EVS_Attack_MagicBlast))
    Else
        ExecWait(N(EVS_Attack_WandStrike))
    EndIf
    Return
    Label(100)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim02)
    EndIf
    Wait(5)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 6)
            Add(LVar1, 12)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 16)
            Add(LVar1, 31)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    EndIf
    Wait(30)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Green_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Green_Anim01)
    EndIf
    Wait(5)
    Thread
        Wait(10)
        Call(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_POWER_UP)
    EndThread
    Thread
        Call(FreezeBattleState, TRUE)
        Call(BoostDefense, LVar8, 1)
        Call(FreezeBattleState, FALSE)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
