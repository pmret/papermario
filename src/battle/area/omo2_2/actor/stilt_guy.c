#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/StiltGuy.h"
#include "sprite/npc/StiltGuyUnfold.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/GeneralGuy.h"

#include "battle/area/omo2/actor/boss_common.h"

#define NAMESPACE b_area_omo2_2_stilt_guy

extern s32 N(ShyGuyAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_RegisterComboHit);
extern EvtScript N(EVS_RegisterHit);
extern EvtScript N(EVS_FallDown);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_ShyGuy_Idle);
extern EvtScript N(EVS_ShyGuy_TakeTurn);
extern EvtScript N(EVS_ShyGuy_HandleEvent);
extern EvtScript N(EVS_Attack_Leap);
extern EvtScript N(EVS_ShyGuy_ReturnHome);

enum N(ActorPartIDs) {
    PRT_GUY         = 1,
    PRT_STILTS      = 2,
    PRT_TARGET      = 3,
    PRT_4           = 4,
    PRT_UNFOLD_1    = 5,
    PRT_UNFOLD_2    = 6,
    PRT_UNFOLD_3    = 7,
    PRT_UNFOLD_4    = 8,
};

enum N(ActorVars) {
    AVAR_IN_Order       = 0, // 0 = left, 1 = right
    AVAR_KnockDownHit   = 1,
    AVAR_HasFallen      = 8,
};

enum N(ActorParams) {
    DMG_LEAP        = 4,
    DMG_TACKLE      = 2,
    DMG_VAULT       = 3,
};

#include "common/GetSelectedMoveID.inc.c"

API_CALLABLE(N(SetActorLevelToZero)) {
    get_actor(script->owner1.actorID)->actorBlueprint->level = 0;
    return ApiStatus_DONE2;
}

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

s32 N(StiltAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_StiltGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_StiltGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_StiltGuy_Anim04,
    STATUS_KEY_POISON,    ANIM_StiltGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_StiltGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_StiltGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_StiltGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_StiltGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_StiltGuy_Anim00,
    STATUS_KEY_FEAR,      ANIM_StiltGuy_Anim00,
    STATUS_END,
};

s32 N(UnfoldAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_StiltGuyUnfold_Anim00,
    STATUS_END,
};

s32 N(StiltGuyDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(ShyGuyDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              60,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               60,
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

s32 N(UnusedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_GUY,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ShyGuyAnims),
        .defenseTable = N(ShyGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_STILTS,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(StiltAnims),
        .defenseTable = N(StiltGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 74, 0 },
        .targetOffset = { 0, -8 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(StiltGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -3 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_4,
        .posOffset = { -2, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(StiltGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, 5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_NO_STATUS_ANIMS,
        .index = PRT_UNFOLD_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(UnfoldAnims),
        .defenseTable = N(StiltGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_NO_STATUS_ANIMS,
        .index = PRT_UNFOLD_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(UnfoldAnims),
        .defenseTable = N(StiltGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_NO_STATUS_ANIMS,
        .index = PRT_UNFOLD_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(UnfoldAnims),
        .defenseTable = N(StiltGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_NO_STATUS_ANIMS,
        .index = PRT_UNFOLD_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(UnfoldAnims),
        .defenseTable = N(StiltGuyDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_STILT_GUY,
    .level = ACTOR_LEVEL_STILT_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 75 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 70 },
    .statusTextOffset = { 10, 65 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_HasFallen, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, FALSE)
    Call(SetPartTargetFlagBits, ACTOR_SELF, PRT_4, ACTOR_PART_TARGET_NO_JUMP, TRUE)
    Call(SetPartSize, ACTOR_SELF, PRT_GUY, 24, 30)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_4, 0, 13, 0)
    Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_3, 0, 13, 0)
    Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_2, 0, 13, 0)
    Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_1, 0, 13, 0)
    Thread
        Set(LVar0, 90)
        Set(LVar1, 270)
        Loop(5)
            Loop(2)
                Label(0)
                Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_4, LVar1, 0, 0)
                Wait(1)
                Sub(LVar1, LVar0)
                IfGe(LVar1, -90)
                    Goto(0)
                EndIf
                Add(LVar1, 360)
            EndLoop
            Sub(LVar0, 15)
        EndLoop
        Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_4, -90, 0, 0)
    EndThread
    Thread
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_UNFOLD_4, Float(0.6))
        Call(SetAnimation, ACTOR_SELF, PRT_UNFOLD_4, ANIM_StiltGuyUnfold_Anim03)
        Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_IN_Order, LVar1)
        IfEq(LVar1, 0)
            Set(LVar0, 10)
            Call(PlaySound, SOUND_LONG_FLUTTER_FALL_A)
        Else
            Set(LVar0, 50)
            Call(PlaySound, SOUND_LONG_FLUTTER_FALL_B)
        EndIf
        Sub(LVar2, 13)
        Call(SetPartPos, ACTOR_SELF, PRT_UNFOLD_4, LVar0, 200, LVar2)
        Call(SetActorPos, ACTOR_SELF, LVar0, 200, LVar2)
        Call(SetAnimation, ACTOR_GENERAL, PRT_GUY, ANIM_GeneralGuy_Anim02)
        Call(SetAnimation, ACTOR_GENERAL, PRT_GUY, ANIM_GeneralGuy_Anim0A)
        Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_GUY, SOUND_GENERAL_WHISTLE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(FallPartTo, ACTOR_SELF, PRT_UNFOLD_4, LVar0, -9, LVar2, 80)
    EndThread
    Thread
        Wait(15)
        Set(LVar0, 90)
        Set(LVar1, 450)
        Loop(5)
            Loop(2)
                Label(1)
                Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_3, LVar1, 0, 0)
                Wait(1)
                Sub(LVar1, LVar0)
                IfGe(LVar1, 90)
                    Goto(1)
                EndIf
                Add(LVar1, 360)
            EndLoop
            Sub(LVar0, 15)
        EndLoop
        Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_3, 90, 0, 0)
    EndThread
    Thread
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_UNFOLD_3, Float(0.6))
        Call(SetAnimation, ACTOR_SELF, PRT_UNFOLD_3, ANIM_StiltGuyUnfold_Anim02)
        Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_IN_Order, LVar0)
        IfEq(LVar0, 0)
            Set(LVar0, 10)
        Else
            Set(LVar0, 50)
        EndIf
        Sub(LVar2, 13)
        Call(SetPartPos, ACTOR_SELF, PRT_UNFOLD_3, LVar0, 200, LVar2)
        Wait(15)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(FallPartTo, ACTOR_SELF, PRT_UNFOLD_3, LVar0, -9, LVar2, 80)
    EndThread
    Thread
        Wait(30)
        Set(LVar0, 90)
        Set(LVar1, 270)
        Loop(5)
            Loop(2)
                Label(2)
                Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_2, LVar1, 0, 0)
                Wait(1)
                Sub(LVar1, LVar0)
                IfGe(LVar1, -90)
                    Goto(2)
                EndIf
                Add(LVar1, 360)
            EndLoop
            Sub(LVar0, 15)
        EndLoop
        Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_2, -90, 0, 0)
    EndThread
    Thread
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_UNFOLD_2, Float(0.6))
        Call(SetAnimation, ACTOR_SELF, PRT_UNFOLD_2, ANIM_StiltGuyUnfold_Anim01)
        Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_IN_Order, LVar0)
        IfEq(LVar0, 0)
            Set(LVar0, 10)
        Else
            Set(LVar0, 50)
        EndIf
        Sub(LVar2, 13)
        Call(SetPartPos, ACTOR_SELF, PRT_UNFOLD_2, LVar0, 200, LVar2)
        Wait(30)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(FallPartTo, ACTOR_SELF, PRT_UNFOLD_2, LVar0, -9, LVar2, 80)
    EndThread
    Thread
        Wait(45)
        Set(LVar0, 90)
        Set(LVar1, 450)
        Loop(5)
            Loop(2)
                Label(3)
                Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_1, LVar1, 0, 0)
                Wait(1)
                Sub(LVar1, LVar0)
                IfGe(LVar1, 90)
                    Goto(3)
                EndIf
                Add(LVar1, 360)
            EndLoop
            Sub(LVar0, 15)
        EndLoop
        Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_1, 90, 0, 0)
    EndThread
    Thread
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_UNFOLD_1, Float(0.6))
        Call(SetAnimation, ACTOR_SELF, PRT_UNFOLD_1, ANIM_StiltGuyUnfold_Anim00)
        Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_IN_Order, LVar0)
        IfEq(LVar0, 0)
            Set(LVar0, 10)
        Else
            Set(LVar0, 50)
        EndIf
        Sub(LVar2, 13)
        Call(SetPartPos, ACTOR_SELF, PRT_UNFOLD_1, LVar0, 200, LVar2)
        Wait(45)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(FallPartTo, ACTOR_SELF, PRT_UNFOLD_1, LVar0, -9, LVar2, 80)
        Wait(15)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_STILTS, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Call(GetPartOffset, ACTOR_SELF, PRT_UNFOLD_4, LVar0, LVar1, LVar2)
        Add(LVar2, 13)
        Call(ForceHomePos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(SetPartPos, ACTOR_SELF, PRT_UNFOLD_1, LVar0, 0, LVar2)
        Call(GetPartOffset, ACTOR_SELF, PRT_UNFOLD_1, LVar0, LVar1, LVar2)
        Call(SetPartPos, ACTOR_SELF, PRT_UNFOLD_1, LVar0, 0, LVar2)
        Call(SetPartRotation, ACTOR_SELF, PRT_UNFOLD_1, 0, 0, 0)
        Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_4, 0, 0, 0)
        Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_3, 0, 0, 0)
        Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_2, 0, 0, 0)
        Call(SetPartRotationOffset, ACTOR_SELF, PRT_UNFOLD_1, 0, 0, 0)
        Call(PlaySoundAtPart, ACTOR_SELF, PRT_UNFOLD_1, SOUND_STILT_GUY_UNFOLD)
        Call(SetAnimation, ACTOR_SELF, PRT_UNFOLD_1, ANIM_StiltGuyUnfold_Anim05)
        Call(EnableActorPaletteEffects, ACTOR_SELF, PRT_UNFOLD_1, TRUE)
        Call(SetActorPaletteSwapParams, ACTOR_SELF, PRT_UNFOLD_1, SPR_PAL_StiltGuyUnfold_Alt, SPR_PAL_StiltGuyUnfold, 0, 36, 0, 255, 0, 0)
        Call(SetActorPaletteEffect, ACTOR_SELF, PRT_UNFOLD_1, ACTOR_PAL_ADJUST_BLEND_PALSETS)
        Wait(18)
        Call(EnableActorPaletteEffects, ACTOR_SELF, PRT_UNFOLD_1, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_UNFOLD_1, ANIM_StiltGuyUnfold_Anim04)
        Wait(5)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STILTS, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_UNFOLD_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STILTS, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Wait(1)
        EndLoop
        Call(HPBarToHome, ACTOR_SELF)
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_IN_Order, LVar0)
        IfEq(LVar0, 1)
            Call(SetActorVar, ACTOR_TANK, AVAR_Tank_SquadPhase, AVAL_SquadPhase_Next)
        Else
        EndIf
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

EvtScript N(EVS_ReturnHome) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_HasFallen, LVar0)
    IfEq(LVar0, TRUE)
        ExecWait(N(EVS_ShyGuy_ReturnHome))
        Return
    EndIf
    SetConst(LVar0, PRT_STILTS)
    SetConst(LVar1, ANIM_StiltGuy_Anim03)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim01)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastElement, LVarF)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseEq(EVENT_HIT_COMBO)
            ExecWait(N(EVS_RegisterComboHit))
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_SPIN_SMASH_HIT)
        CaseOrEq(EVENT_SPIN_SMASH_LAUNCH_HIT)
            Call(GetBattleFlags, LVar2)
            IfFlag(LVar2, BS_FLAGS1_PARTNER_ACTING)
                Call(GetMenuSelection, LVar0, LVar1, LVar2)
                IfEq(LVar2, MOVE_SPOOK)
                    Set(LVar0, PRT_STILTS)
                    Set(LVar1, ANIM_StiltGuy_Anim01)
                    ExecWait(EVS_Enemy_NoDamageHit)
                    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                    Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, FALSE)
                    Return
                EndIf
            EndIf
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RegisterHit))
            Call(GetActorVar, ACTOR_SELF, AVAR_KnockDownHit, LVar0)
            IfTrue(LVar0)
                ExecWait(N(EVS_FallDown))
            EndIf
            Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, FALSE)
        EndCaseGroup
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim06)
            Wait(1000)
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Set(LVar0, 2)
            Set(LVar1, ANIM_StiltGuy_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_BURN_HIT)
            Call(GetDamageSource, LVar0)
            IfNe(LVar0, DMG_SRC_FIRE_SHELL)
                Set(LVar0, 2)
                Set(LVar1, ANIM_StiltGuy_Anim09)
                Set(LVar2, ANIM_StiltGuy_Anim0A)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                Set(LVar0, 2)
                Set(LVar1, ANIM_StiltGuy_Anim09)
                Set(LVar2, ANIM_StiltGuy_Anim0A)
                ExecWait(EVS_Enemy_BurnHit)
                ExecWait(N(EVS_FallDown))
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, 2)
            Set(LVar1, ANIM_StiltGuy_Anim09)
            Set(LVar2, ANIM_StiltGuy_Anim0A)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim0A)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim07)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_ShockHit)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim07)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim07)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_STILTS)
            SetConst(LVar1, ANIM_StiltGuy_Anim03)
            SetConst(LVar2, ANIM_StiltGuy_Anim03)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_RegisterComboHit) = {
    Call(GetBattleFlags, LVar0)
    IfNotFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
        IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, TRUE)
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
                    Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, TRUE)
                EndIf
            EndCaseGroup
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_RegisterHit) = {
    Call(GetBattleFlags, LVar0)
    IfNotFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
        // jump attacks knock down stilts
        IfFlag(LVarF, DAMAGE_TYPE_JUMP)
            IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
                Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, TRUE)
            EndIf
        EndIf
        // quake attacks knock down stilts
        IfFlag(LVarF, DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE)
            Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, TRUE)
        EndIf
    EndIf
    // status effects knock down stilts
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STOP)
        Call(SetActorVar, ACTOR_SELF, AVAR_KnockDownHit, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    ExecWait(N(EVS_Attack_Leap))
    Return
    End
};

EvtScript N(EVS_Attack_Leap) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamOffsetZ, 40)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim04)
    Wait(8)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Wait(9)
                Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim04)
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim05)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 15)
            Set(LVar1, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STILT_GUY_STEP)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 25)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STILT_GUY_STEP)
            Wait(15)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_STILTS, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_STILTS, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Wait(8)
        Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim04)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim05)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STILT_GUY_STEP)
            Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim01)
            Wait(8)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_FallDown) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_HasFallen, TRUE)
    Call(SetPartFlags, ACTOR_SELF, PRT_GUY, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim0C)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 50)
    Else
        Add(LVar1, 20)
    EndIf
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Thread
        Wait(6)
        Call(PlaySoundAtPart, ACTOR_SELF, PRT_STILTS, SOUND_STILTS_FALL)
    EndThread
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_STILTS, ANIM_StiltGuy_Anim08)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 6)
            Call(SetPartRotation, ACTOR_SELF, PRT_STILTS, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetPartFlags, ACTOR_SELF, PRT_STILTS, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
    EndThread
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_STILTS, SOUND_FALL_QUICK)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Call(RandInt, 100, LVar1)
    IfLt(LVar1, 50)
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim10)
        Wait(10)
    EndIf
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_ShyGuy_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_ShyGuy_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_ShyGuy_HandleEvent)))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    Call(HPBarToHome, ACTOR_SELF)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(GetActorSize, ACTOR_SELF, LVar0, LVar1)
    Call(SetActorSize, ACTOR_SELF, 24, LVar1)
    Call(N(SetActorLevelToZero))
    Return
    End
};

EvtScript N(EVS_Death) = {
    ExecWait(EVS_Enemy_DeathWithoutRemove)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_STILTS, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(GetActorVar, ACTOR_TANK, AVAR_Tank_StiltPhase, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_TANK, AVAR_Tank_StiltPhase, LVar0)
    IfGe(LVar0, AVAL_StiltPhase_Defeated)
        Call(FreezeBattleState, TRUE)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 100)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_ShyGuy_SpinAround) = {
    Set(LVar0, 0)
    Label(0)
        Sub(LVar0, 30)
        IfLt(LVar0, 0)
            Add(LVar0, 360)
        EndIf
        Call(SetActorYaw, ACTOR_SELF, LVar0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ShyGuy_SpinSmash) = {
    ExecGetTID(N(EVS_ShyGuy_SpinAround), LVarE)
    Call(GetPartEventFlags, ACTOR_SELF, LVar0, LVarA)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(CreateCurrentPosTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_ALLOW_TARGET_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerID, LVar1)
        Call(GetOwnerTarget, LVar0, LVar9)
        IfNe(LVar1, LVar0)
            Call(ChooseNextTarget, ITER_NEXT, LVar0)
            Goto(0)
        EndIf
    Label(1)
        Add(LVarF, 1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfEq(LVar0, ITER_NO_MORE)
            Goto(10)
        EndIf
        Call(GetOwnerTarget, LVar0, LVar9)
        Call(GetActorFlags, LVar0, LVar1)
        IfFlag(LVar1, ACTOR_FLAG_TARGET_ONLY)
            Goto(1)
        EndIf
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
        Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
        Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        EndThread
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
        Goto(1)
    Label(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    Div(LVar3, 2)
    Set(LVar4, 70)
    Sub(LVar4, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar5, LVar4)
    Sub(LVar5, LVar0)
    IfLt(LVar5, 6)
        Set(LVar5, 1)
    Else
        Set(LVar5, 0)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, LVar5, FALSE, TRUE, FALSE)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    Sub(LVar4, 18)
    IfLe(LVar4, LVar6)
        Set(LVar4, LVar6)
        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    Else
        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
        Call(SetGoalToHome, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar4, LVar7, LVar8)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EndIf
    KillThread(LVarE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Wait(10)
    Return
    End
};

s32 N(ShyGuyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STONE,     ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShyGuy_Red_Anim12,
    STATUS_KEY_POISON,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STOP,      ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShyGuy_Red_Anim13,
    STATUS_KEY_FEAR,      ANIM_ShyGuy_Red_Anim13,
    STATUS_END,
};

EvtScript N(EVS_ShyGuy_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_ShyGuy_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_ShyGuy_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_ShyGuy_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_ShyGuy_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfFlag(LVar0, STATUS_FLAG_SLEEP)
            Call(SetTargetOffset, ACTOR_SELF, PRT_GUY, -4, 14)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_GUY, 0, 0)
            Call(N(SetAbsoluteStatusOffsets), -10, 13, 10, 13)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_GUY, 0, 24)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_GUY, -1, -10)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EndIf
        Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_ShyGuy_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    SetConst(LVar0, PRT_GUY)
    SetConst(LVar1, ANIM_ShyGuy_Red_Anim03)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim01)
    Return
    End
};

EvtScript N(EVS_ShyGuy_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(N(EVS_ShyGuy_SpinSmash))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(N(EVS_ShyGuy_SpinSmash))
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ShyGuy_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim03)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim14)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ShyGuy_Attack_Tackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HOP, 0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim04)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_GUY, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_GUY, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Wait(3)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    EndThread
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim04)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim05)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim01)
    Wait(8)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    ExecWait(N(EVS_ShyGuy_ReturnHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ShyGuy_Attack_Vault) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TIMING_BAR_GO)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim09)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 80)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim04)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Sub(LVar0, 40)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim09)
            Thread
                Wait(12)
                Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim0A)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_GUY, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_GUY, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim09)
    Thread
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim0A)
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_VAULT, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Set(LVar3, 0)
                Loop(20)
                    Sub(LVar3, 30)
                    IfLt(LVar3, 0)
                        Add(LVar3, 360)
                    EndIf
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    Wait(1)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Goto(1)
            EndIf
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfEq(LVar0, 0)
                Goto(1)
            EndIf
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING | SOUND_ID_TRIGGER_CHANGE_SOUND)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim09)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim07)
            Wait(15)
            Goto(2)
            Label(1)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim10)
            Wait(10)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISAPPOINTED)
            Call(AddActorDecoration, ACTOR_SELF, PRT_GUY, 0, ACTOR_DECORATION_SWEAT)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 50)
                Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim11)
            Else
                Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim13)
            EndIf
            Wait(25)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_GUY, 0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Label(2)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY, ANIM_ShyGuy_Red_Anim01)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ShyGuy_TakeTurn) = {
    Call(RandInt, 1, LVar0)
    IfEq(LVar0, 0)
        ExecWait(N(EVS_ShyGuy_Attack_Tackle))
    Else
        ExecWait(N(EVS_ShyGuy_Attack_Vault))
    EndIf
    Return
    End
};
