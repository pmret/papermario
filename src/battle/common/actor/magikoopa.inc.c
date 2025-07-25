#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "effects.h"

#define NAMESPACE A(magikoopa)

extern s32 N(GroundAnims)[];
extern s32 N(FlyingAnims)[];
extern s32 N(BroomAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Flying_Init);
extern EvtScript N(EVS_Flying_HandleEvent);

enum N(ActorPartIDs) {
    PRT_GROUND      = 1,
    PRT_FLYING      = 2,
    PRT_BROOM       = 3,
};

enum N(ActorVars) {
    AVAR_HitTypeFlags           = 0,
    AVAL_HitType_Combo          = 1,
    AVAR_IsClone                = 1,
    AVAR_ShouldKnockDown        = 2,
    AVAR_HealAllCount           = 3,
    AVAR_HealOneCount           = 4,
    AVAR_AttackBoostCount       = 5,
    AVAR_DefenseBoostCount      = 6,
    AVAR_ElectrifyCount         = 7,
    AVAR_TransparifyCount       = 8,
    AVAR_CloneActorID           = 9,
    AVAR_MadeCloneLastTurn      = 10,
    AVAR_LastMove               = 11,
    AVAL_LastMove_None          = -1,
    AVAL_LastMove_HealOne       = 0,
    AVAL_LastMove_HealAll       = 1,
    AVAL_LastMove_MagicBlast    = 2,
    AVAL_LastMove_MakeClone     = 3,
    AVAL_LastMove_BoostAttack   = 4,
    AVAL_LastMove_BoostDefense  = 5,
    AVAL_LastMove_Electrify     = 6,
    AVAL_LastMove_Transparify   = 7,
};

enum N(ActorParams) {
    DMG_MAGIC_BLAST     = 6,
    HEAL_AMT_ONE        = 5,
    HEAL_AMT_ALL        = 3,
    ATTACK_BOOST_AMT    = 1,
    DEFENSE_BOOST_AMT   = 1,
    ELECTRIFY_TURNS     = 3,
    TRANSPARIFY_TURNS   = 2,
    MAX_HEAL_ONE        = 2,
    MAX_HEAL_ALL        = 2,
    MAX_ATTACK_BOOST    = 3,
    MAX_DEFENSE_BOOST   = 3,
    MAX_ELECTRIFY       = 3,
    MAX_TRANSPARIFY     = 3,
    HEAL_THRESHOLD_1    = 25,
    HEAL_THRESHOLD_2    = 20,
    HEAL_THRESHOLD_3    = 15,
    HEAL_CHANCE_1       = 75,
    HEAL_CHANCE_2       = 80,
    HEAL_CHANCE_3       = 100,
    HEAL_ONE_CHANCE     = 500,
    HEAL_ALL_CHANCE     = 500,
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
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
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
    .type = ACTOR_TYPE_MAGIKOOPA,
    .level = ACTOR_LEVEL_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 32 },
};

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_MAGIKOOPA,
    .level = ACTOR_LEVEL_FLYING_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(FlyingParts)),
    .partsData = N(FlyingParts),
    .initScript = &N(EVS_Flying_Init),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 40,
    .airLiftChance = 85,
    .hurricaneChance = 75,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusTextOffset = { 1, 34 },
};

s32 N(GroundAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_Magikoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Magikoopa_Anim08,
    STATUS_KEY_POISON,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_Magikoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Magikoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Magikoopa_Anim07,
    STATUS_KEY_FEAR,      ANIM_Magikoopa_Anim07,
    STATUS_END,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_FlyingMagikoopa_Anim08,
    STATUS_KEY_POISON,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_FlyingMagikoopa_Anim07,
    STATUS_KEY_FEAR,      ANIM_FlyingMagikoopa_Anim07,
    STATUS_END,
};

s32 N(BroomAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Anim0A,
    STATUS_END,
};

#include "common/ShrinkActor.inc.c"
#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_Idle) = {
    Set(LVarF, 0)
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
        Call(ActorExists, LVar0, LVar1)
        IfEq(LVar1, 1)
            Call(N(CosInterpMinMax), LVarF, LVar1, Float(254.0), Float(100.0), 20, 0, 0)
            Add(LVarF, 1)
            Call(GetActorFlags, ACTOR_SELF, LVar2)
            IfFlag(LVar2, ACTOR_FLAG_FLYING)
                Call(SetPartAlpha, ACTOR_SELF, PRT_FLYING, LVar1)
                Call(SetPartAlpha, LVar0, 1, LVar1)
            Else
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar1)
                Call(SetPartAlpha, LVar0, 1, LVar1)
            EndIf
        Else
            Set(LVarF, 0)
            Call(GetActorFlags, ACTOR_SELF, LVar2)
            IfFlag(LVar2, ACTOR_FLAG_FLYING)
                Call(SetPartAlpha, ACTOR_SELF, PRT_FLYING, 255)
            Else
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
            EndIf
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

#include "common/GetSelectedMoveID.inc.c"

EvtScript N(EVS_KnockDownCheck) = {
    Call(GetBattleFlags, LVar0)
    IfNotFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
        IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, true)
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
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, true)
                EndIf
            EndCaseGroup
        EndSwitch
    EndIf
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"
#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_KnockDown) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, LVar0)
    IfEq(LVar0, 1)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
        Goto(0)
    EndIf
    Call(GetLastElement, LVar0)
    IfFlag(LVar0, DAMAGE_TYPE_POW)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
        Goto(0)
    EndIf
    Return
    Label(0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_BROOM, Float(0.4), Float(0.4), Float(0.4))
    EndIf
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 1)
    Call(SetPartPos, ACTOR_SELF, PRT_BROOM, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
    Call(N(StartRumbleWithParams), 150, 10)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.7))
    EndThread
    Call(GetLastEvent, ACTOR_SELF, LVar3)
    IfEq(LVar3, EVENT_15)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Add(LVar4, 10)
        Add(LVar5, 5)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, Float(1.0), 10, 0)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Loop(20)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, true)
        Wait(1)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, false)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, false)
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_MAGIKOOPA)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 32)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, true)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(GetIndexFromPos, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Flee) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(HideHealthBar, ACTOR_SELF)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    IfNe(LVar0, EVENT_SCARE_AWAY)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 15)
        Wait(15)
        Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Wait(10)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(YieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ExecWait(EVS_ForceNextTarget)
    Call(HideHealthBar, ACTOR_SELF)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
    BitwiseAndConst(LVar0, ~AVAL_HitType_Combo)
    Call(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    IfEq(LVar0, 0)
        Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_IsClone, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_HealAllCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_HealOneCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ElectrifyCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TransparifyCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, -1)
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_None)
    Return
    End
};

EvtScript N(EVS_Flying_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Flying_HandleEvent)))
    Call(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    IfEq(LVar0, 0)
        Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_IsClone, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_HealAllCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_HealOneCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ElectrifyCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TransparifyCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, -1)
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_None)
    Return
    End
};

EvtScript N(EVS_RemoveClone) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_IsClone, LVar0)
    IfEq(LVar0, 1)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, 0)
        Return
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(GetLastElement, LVarA)
    IfFlag(LVarA, DAMAGE_TYPE_MULTIPLE_POPUPS)
        Label(0)
        Call(GetBattleFlags, LVarA)
        IfFlag(LVarA, BS_FLAGS1_EXECUTING_MOVE)
            Wait(1)
            Goto(0)
        EndIf
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, -1)
    Call(GetActorFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, ACTOR_FLAG_FLYING)
        Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, false)
    Else
        Call(SetPartEventBits, ACTOR_SELF, PRT_GROUND, ACTOR_EVENT_FLAG_ATTACK_CHARGED, false)
    EndIf
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(RemoveActor, LVar0)
    Thread
        Add(LVar3, 2)
        Loop(2)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
            Wait(2)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            Call(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            BitwiseOrConst(LVar0, AVAL_HitType_Combo)
            Call(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_UP_AND_AWAY)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RemoveClone))
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim05)
            SetConst(LVar2, ANIM_Magikoopa_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_RemoveClone))
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim05)
            SetConst(LVar2, ANIM_Magikoopa_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_RemoveClone))
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim06)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_RemoveClone))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_RemoveClone))
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            IfFlag(LVar0, AVAL_HitType_Combo)
                ExecWait(N(EVS_RemoveClone))
                Return
            EndIf
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNe(LVar0, 0)
                ExecWait(N(EVS_RemoveClone))
            EndIf
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RemoveClone))
            Wait(10)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            ExecWait(N(EVS_RemoveClone))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
            ExecWait(N(EVS_Flee))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim02)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            ExecWait(N(EVS_RemoveClone))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, 0, 2, 0)
                Else
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, -4, 5, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_STAR_BEAM)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RemoveClone))
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Flying_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetPartAlpha, ACTOR_SELF, PRT_FLYING, 255)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            Call(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            BitwiseOrConst(LVar0, AVAL_HitType_Combo)
            Call(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_FALL_TRIGGER)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RemoveClone))
            ExecWait(N(EVS_KnockDown))
        EndCaseGroup
        CaseEq(EVENT_UP_AND_AWAY)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RemoveClone))
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_15)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim05)
            SetConst(LVar2, ANIM_FlyingMagikoopa_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_RemoveClone))
            ExecWait(N(EVS_KnockDown))
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim05)
            SetConst(LVar2, ANIM_FlyingMagikoopa_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_RemoveClone))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim06)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_RemoveClone))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_RemoveClone))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            IfFlag(LVar0, AVAL_HitType_Combo)
                ExecWait(N(EVS_RemoveClone))
                Return
            EndIf
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNe(LVar0, 0)
                ExecWait(N(EVS_RemoveClone))
            EndIf
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RemoveClone))
            Wait(10)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            ExecWait(N(EVS_RemoveClone))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim04)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
            ExecWait(N(EVS_Flee))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim02)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            ExecWait(N(EVS_RemoveClone))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -3, 0, 0)
                Else
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -15, 0, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_STAR_BEAM)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_RemoveClone))
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

// (in) LVarB: actorID to heal
EvtScript N(EVS_Move_HealOne) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_HealOne)
    Call(AddActorVar, ACTOR_SELF, AVAR_HealOneCount, 1)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
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
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 16)
            Add(LVar1, 31)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    EndIf
    Wait(30)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EndIf
    Wait(5)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, LVarB, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, LVarB, SOUND_HEART_BOUNCE)
        Wait(30)
        Call(PlaySoundAtActor, LVarB, SOUND_STAR_BOUNCE_A)
    EndThread
    Thread
        Call(FreezeBattleState, true)
        Call(HealActor, LVarB, HEAL_AMT_ONE, false)
        Call(FreezeBattleState, false)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Move_HealAll) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_HealAll)
    Call(AddActorVar, ACTOR_SELF, AVAR_HealAllCount, 1)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
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
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 16)
            Add(LVar1, 31)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    EndIf
    Wait(30)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EndIf
    Wait(5)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Set(LFlag0, false)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar1)
        IfEq(LVar1, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        IfEq(LFlag0, false)
            Thread
                Wait(5)
                Call(PlaySoundAtActor, LVar0, SOUND_RECOVER_HEART)
                Call(PlaySoundAtActor, LVar0, SOUND_HEART_BOUNCE)
                Wait(30)
                Call(PlaySoundAtActor, LVar0, SOUND_STAR_BOUNCE_A)
            EndThread
            Thread
                Call(FreezeBattleState, true)
                Call(HealActor, LVar0, HEAL_AMT_ALL, true)
                Call(FreezeBattleState, false)
            EndThread
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Call(WaitForBuffDone)
    Wait(1)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_MagicBlast) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_MagicBlast)
    Set(LFlag0, false)
    Set(LFlag1, false)
    Call(GetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, LVar0)
    IfEq(LVar0, 1)
        Set(LFlag0, true)
        Call(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVarA)
    EndIf
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_FLYING)
        Set(LFlag1, true)
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, false)
    IfEq(LFlag0, true)
        Call(UseIdleAnimation, LVarA, false)
    EndIf
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
    IfEq(LFlag1, false)
        IfEq(LFlag0, true)
            Call(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Sub(LVar0, 17)
            Add(LVar1, 33)
            PlayEffect(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, Float(0.5), 30, 0)
        EndIf
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVar3)
        IfFlag(LVar3, STATUS_FLAG_SHRINK)
            Sub(LVar0, 6)
            Add(LVar1, 13)
        Else
            Sub(LVar0, 17)
            Add(LVar1, 33)
        EndIf
        PlayEffect(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, Float(0.5), 30, 0)
    Else
        IfEq(LFlag0, true)
            Call(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Add(LVar1, 36)
            PlayEffect(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, Float(0.5), 30, 0)
        EndIf
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVar3)
        IfFlag(LVar3, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
        EndIf
        PlayEffect(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, Float(0.5), 30, 0)
    EndIf
    Wait(30)
    Call(EnemyTestTarget, ACTOR_SELF, LVar9, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar9)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            IfEq(LFlag0, true)
                Call(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
            EndIf
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            IfEq(LFlag1, false)
                IfEq(LFlag0, true)
                    Call(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
                EndIf
                Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim03)
            Else
                IfEq(LFlag0, true)
                    Call(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
                EndIf
                Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim03)
            EndIf
            Wait(5)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            Sub(LVar4, 50)
            Set(LVar5, 0)
            IfEq(LFlag1, false)
                IfEq(LFlag0, true)
                    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    Sub(LVar0, 20)
                    Add(LVar1, 20)
                    Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EndIf
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfFlag(LVar3, STATUS_FLAG_SHRINK)
                    Sub(LVar0, 8)
                    Add(LVar1, 8)
                Else
                    Sub(LVar0, 20)
                    Add(LVar1, 20)
                EndIf
                Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            Else
                IfEq(LFlag0, true)
                    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    Sub(LVar0, 20)
                    Add(LVar1, 20)
                    Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EndIf
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfFlag(LVar3, STATUS_FLAG_SHRINK)
                    Sub(LVar0, 8)
                    Add(LVar1, 8)
                Else
                    Sub(LVar0, 20)
                    Add(LVar1, 20)
                EndIf
                Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            EndIf
            Wait(50)
            IfEq(LVar9, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(YieldTurn)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            IfEq(LFlag0, true)
                Call(UseIdleAnimation, LVarA, true)
            EndIf
            Return
        EndCaseGroup
    EndSwitch
    IfEq(LFlag0, true)
        Call(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    IfEq(LFlag1, false)
        IfEq(LFlag0, true)
            Call(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
        EndIf
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim03)
    Else
        IfEq(LFlag0, true)
            Call(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
        EndIf
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim03)
    EndIf
    Wait(5)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    IfEq(LFlag1, false)
        IfEq(LFlag0, true)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Add(LVar1, 20)
            Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EndIf
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVar3)
        IfFlag(LVar3, STATUS_FLAG_SHRINK)
            Sub(LVar0, 8)
            Add(LVar1, 8)
        Else
            Sub(LVar0, 20)
            Add(LVar1, 20)
        EndIf
        Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    Else
        IfEq(LFlag0, true)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Add(LVar1, 20)
            Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EndIf
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVar3)
        IfFlag(LVar3, STATUS_FLAG_SHRINK)
            Sub(LVar0, 8)
            Add(LVar1, 8)
        Else
            Sub(LVar0, 20)
            Add(LVar1, 20)
        EndIf
        Call(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    EndIf
    Wait(18)
    IfEq(LFlag0, true)
        Wait(2)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MAGIC_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    Else
        Wait(2)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MAGIC_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    EndIf
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(20)
            Call(YieldTurn)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    IfEq(LFlag0, true)
        Call(UseIdleAnimation, LVarA, true)
    EndIf
    Return
    End
};

EvtScript N(EVS_GetAvailableColumn) = {
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetIndexFromHome, LVar0, LVar1)
        Mod(LVar1, 4)
        Switch(LVar1)
            CaseEq(0)
                Set(LFlagB, true)
            CaseEq(1)
                Set(LFlagC, true)
            CaseEq(2)
                Set(LFlagD, true)
            CaseEq(3)
                Set(LFlagE, true)
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Set(LVar0, -1)
    Call(GetIndexFromHome, ACTOR_SELF, LVar1)
    Mod(LVar1, 4)
    Switch(LVar1)
        CaseEq(0)
            IfEq(LFlagC, false)
                Set(LVar0, 1)
            EndIf
        CaseEq(1)
            IfEq(LFlagB, false)
                Set(LVar0, 0)
            EndIf
            IfEq(LFlagD, false)
                Set(LVar0, 2)
            EndIf
        CaseEq(2)
            IfEq(LFlagC, false)
                Set(LVar0, 1)
            EndIf
            IfEq(LFlagE, false)
                Set(LVar0, 3)
            EndIf
        CaseEq(3)
            IfEq(LFlagD, false)
                Set(LVar0, 2)
            EndIf
    EndSwitch
    IfNe(LVar0, -1)
        Call(GetActorFlags, ACTOR_SELF, LVar1)
        IfFlag(LVar1, ACTOR_FLAG_FLYING)
            Add(LVar0, 4)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Clone_HandleEvent) = {
    Return
    End
};

EvtScript N(EVS_Clone_Init) = {
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Clone_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_IsClone, true)
    Return
    End
};

EvtScript N(EVS_FlyingClone_Init) = {
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Clone_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_IsClone, true)
    Return
    End
};

s32 N(CloneDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingCloneDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(CloneStatusTable)[] = {
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

s32 N(FlyingCloneStatusTable)[] = {
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

ActorPartBlueprint N(CloneParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(CloneDefense),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

ActorPartBlueprint N(FlyingCloneParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingCloneDefense),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint N(clone) = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_MAGICLONE,
    .level = ACTOR_LEVEL_MAGICLONE,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(CloneParts)),
    .partsData = N(CloneParts),
    .initScript = &N(EVS_Clone_Init),
    .statusTable = N(CloneStatusTable),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 32 },
};

ActorBlueprint N(clone_flying) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_FLYING_MAGICLONE,
    .level = ACTOR_LEVEL_FLYING_MAGICLONE,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(FlyingCloneParts)),
    .partsData = N(FlyingCloneParts),
    .initScript = &N(EVS_FlyingClone_Init),
    .statusTable = N(FlyingCloneStatusTable),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusTextOffset = { 1, 34 },
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(CloneFormation) = {
    ACTOR_BY_POS(N(clone), N(SummonPos), 0),
};

Formation N(FlyingCloneFormation) = {
    ACTOR_BY_POS(N(clone_flying), N(SummonPos), 0),
};

EvtScript N(EVS_Move_MakeClone) = {
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, true)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_MakeClone)
    Set(LFlag0, false)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_FLYING)
        Set(LFlag0, true)
    EndIf
    IfEq(LFlag0, false)
        Call(SummonEnemy, Ref(N(CloneFormation)), false)
    Else
        Call(SummonEnemy, Ref(N(FlyingCloneFormation)), false)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
    Set(LVarA, LVar0)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(EnableIdleScript, LVarA, IDLE_SCRIPT_DISABLE)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(UseIdleAnimation, LVarA, false)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 25)
    Wait(25)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST3)
    IfEq(LFlag0, false)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
        Call(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 23)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
        Call(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 23)
    EndIf
    PlayEffect(EFFECT_ENERGY_IN_OUT, 1, LVar0, LVar1, LVar2, Float(1.0), 30, 0)
    Wait(10)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(EnableIdleScript, LVar9, IDLE_SCRIPT_ENABLE)
    Wait(30)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, -3)
    Call(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    Set(LVar9, LVarA)
    Wait(15)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST4)
    Call(PlaySoundAtActor, LVar9, SOUND_SPELL_CAST4)
    Call(SetPartFlagBits, LVar9, 1, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
    Call(RandInt, 1000, LVar0)
    IfLt(LVar0, 500)
        Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
        ExecWait(N(EVS_GetAvailableColumn))
        Call(SetGoalToIndex, ACTOR_SELF, LVar0)
        Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    Else
        Call(SetActorSpeed, LVar9, Float(2.0))
        ExecWait(N(EVS_GetAvailableColumn))
        Call(SetGoalToIndex, LVar9, LVar0)
        Call(FlyToGoal, LVar9, 0, 0, EASING_LINEAR)
    EndIf
    Call(SetPartFlagBits, LVar9, 1, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(SetEnemyHP, LVar9, LVar0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(GetActorPos, LVar9, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVar9, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVar9)
    IfEq(LFlag0, false)
        Call(SetPartEventBits, ACTOR_SELF, PRT_GROUND, ACTOR_EVENT_FLAG_ATTACK_CHARGED, true)
    Else
        Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, true)
    EndIf
    IfEq(LFlag0, false)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
        Call(SetAnimation, LVar9, 1, ANIM_Magikoopa_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
        Call(SetAnimation, LVar9, 1, ANIM_FlyingMagikoopa_Anim01)
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Call(UseIdleAnimation, LVar9, true)
    Return
    End
};

#include "common/battle/CheckMagikoopaCastTarget.inc.c"

EvtScript N(EVS_Move_TryBoostAttack) = {
    Set(LFlag0, false)
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
                    Call(GetActorAttackBoost, LVar0, LVar4)
                    IfLt(LVar4, MAX_ATTACK_BOOST)
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
        IfEq(LFlag0, false)
            Set(LFlag0, true)
            Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            Goto(10)
        EndIf
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    ExecWait(N(EVS_Attack_MagicBlast))
    Return
    // found target
    Label(100)
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_BoostAttack)
    Call(AddActorVar, ACTOR_SELF, AVAR_AttackBoostCount, 1)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
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
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EndIf
    Wait(5)
    Thread
        Wait(10)
        Call(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_POWER_UP)
    EndThread
    Thread
        Call(FreezeBattleState, true)
        Call(BoostAttack, LVar8, ATTACK_BOOST_AMT)
        Call(FreezeBattleState, false)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Move_TryBoostDefense) = {
    Set(LFlag0, false)
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
                    IfLt(LVar4, MAX_DEFENSE_BOOST)
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
        IfEq(LFlag0, false)
            Set(LFlag0, true)
            Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            Goto(10)
        EndIf
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    ExecWait(N(EVS_Attack_MagicBlast))
    Return
    // found target
    Label(100)
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_BoostDefense)
    Call(AddActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, 1)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
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
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EndIf
    Wait(5)
    Thread
        Wait(10)
        Call(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_POWER_UP)
    EndThread
    Thread
        Call(FreezeBattleState, true)
        Call(BoostDefense, LVar8, DEFENSE_BOOST_AMT)
        Call(FreezeBattleState, false)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Move_TryElectrify) = {
    Set(LFlag0, false)
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
                    Call(GetStatusFlags, LVar0, LVar4)
                    IfNotFlag(LVar4, STATUS_FLAG_STATIC | STATUS_FLAG_TRANSPARENT)
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
        IfEq(LFlag0, false)
            Set(LFlag0, true)
            Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            Goto(10)
        EndIf
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    ExecWait(N(EVS_Attack_MagicBlast))
    Return
    // found target
    Label(100)
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_Electrify)
    Call(AddActorVar, ACTOR_SELF, AVAR_ElectrifyCount, 1)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
    EndIf
    Wait(5)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_ELECTRIFY)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 6)
            Add(LVar1, 12)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 16)
            Add(LVar1, 31)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    EndIf
    Wait(30)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EndIf
    Wait(5)
    Thread
        Wait(10)
        Loop(4)
            Call(PlaySoundAtActor, LVar8, SOUND_ELECTRIC_BUZZ)
            Call(RandInt, 3, LVar0)
            Add(LVar0, 3)
            Wait(LVar0)
        EndLoop
    EndThread
    Thread
        Call(FreezeBattleState, true)
        Call(ElectrifyActor, LVar8, ELECTRIFY_TURNS)
        Call(FreezeBattleState, false)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Move_TryTransparent) = {
    Set(LFlag0, false)
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
                    Call(GetStatusFlags, LVar0, LVar4)
                    IfNotFlag(LVar4, STATUS_FLAG_STATIC | STATUS_FLAG_TRANSPARENT)
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
        IfEq(LFlag0, false)
            Set(LFlag0, true)
            Call(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            Goto(10)
        EndIf
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    ExecWait(N(EVS_Attack_MagicBlast))
    Return
    // found target
    Label(100)
    Call(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_Transparify)
    Call(AddActorVar, ACTOR_SELF, AVAR_TransparifyCount, 1)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
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
            PlayEffect(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 16)
            Add(LVar1, 31)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    EndIf
    Wait(30)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EndIf
    Wait(5)
    Thread
        Wait(10)
        Call(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_VANISH)
    EndThread
    Thread
        Call(FreezeBattleState, true)
        Call(VanishActor, LVar8, TRANSPARIFY_TURNS)
        Call(FreezeBattleState, false)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    #define LBL_LOOP_COUNT_INJURED_1    0
    #define LBL_LOOP_COUNT_INJURED_2    1
    #define LBL_LOOP_COUNT_INJURED_3    2
    #define LBL_TRY_HEALING             10
    #define LBL_LOOP_CHOOSE_BEST_HEAL   11
    #define LBL_TRY_MOVES               20
    #define LBL_CHOOSE_MOVE             123
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        ExecWait(N(EVS_Attack_MagicBlast))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, LVar0)
    IfEq(LVar0, 1)
        Goto(LBL_TRY_MOVES)
    EndIf
    // first heal check: count ~75% of actors with less than 25% HP
    Set(LVarA, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(LBL_LOOP_COUNT_INJURED_1)
        Set(LFlag0, false)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar1)
        IfEq(LVar1, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        Call(GetActorHP, LVar0, LVar2)
        Call(GetEnemyMaxHP, LVar0, LVar3)
        MulF(LVar2, Float(100.0))
        DivF(LVar2, LVar3)
        IfEq(LFlag0, false) // collapsed dry bones check
            IfLe(LVar2, HEAL_THRESHOLD_1) // HP% check
                Call(RandInt, 99, LVar4)
                Add(LVar4, 1)
                IfLt(LVar4, HEAL_CHANCE_1) // chance to ignore actor
                    Add(LVarA, 1)
                    Set(LVarB, LVar0)
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(LBL_LOOP_COUNT_INJURED_1)
        EndIf
    IfGt(LVarA, 0)
        Goto(LBL_TRY_HEALING)
    EndIf
    // second heal check: count ~80% of actors with less than 20% HP
    Set(LVarA, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(LBL_LOOP_COUNT_INJURED_2)
        Set(LFlag0, false)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar1)
        IfEq(LVar1, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        Call(GetActorHP, LVar0, LVar2)
        Call(GetEnemyMaxHP, LVar0, LVar3)
        MulF(LVar2, Float(100.0))
        DivF(LVar2, LVar3)
        IfEq(LFlag0, false) // collapsed dry bones check
            IfLe(LVar2, HEAL_THRESHOLD_2) // HP% check
                Call(RandInt, 99, LVar4)
                Add(LVar4, 1)
                IfLt(LVar4, HEAL_CHANCE_2) // chance to ignore actor
                    Add(LVarA, 1)
                    Set(LVarB, LVar0)
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(LBL_LOOP_COUNT_INJURED_2)
        EndIf
    IfGt(LVarA, 0)
        Goto(LBL_TRY_HEALING)
    EndIf
    // third heal check: count ~99% of actors with less than 15% HP
    Set(LVarA, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(LBL_LOOP_COUNT_INJURED_3)
        Set(LFlag0, false)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar1)
        IfEq(LVar1, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        Call(GetActorHP, LVar0, LVar2)
        Call(GetEnemyMaxHP, LVar0, LVar3)
        MulF(LVar2, Float(100.0))
        DivF(LVar2, LVar3)
        IfEq(LFlag0, false) // collapsed dry bones check
            IfLe(LVar2, HEAL_THRESHOLD_3) // HP% check
                Call(RandInt, 99, LVar4)
                Add(LVar4, 1)
                IfLt(LVar4, HEAL_CHANCE_3) // chance to ignore actor
                    Add(LVarA, 1)
                    Set(LVarB, LVar0)
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(LBL_LOOP_COUNT_INJURED_3)
        EndIf
    IfGt(LVarA, 0)
        Goto(LBL_TRY_HEALING)
    EndIf
    Goto(LBL_TRY_MOVES)
    // try healing spells
    Label(LBL_TRY_HEALING)
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    // single healing target available
    IfEq(LVarA, 1)
        Call(GetActorVar, ACTOR_SELF, AVAR_HealOneCount, LVar0)
        IfLt(LVar0, MAX_HEAL_ONE)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, HEAL_ONE_CHANCE)
                ExecWait(N(EVS_Move_HealOne))
                Return
            EndIf
        Else
            Call(GetActorVar, ACTOR_SELF, AVAR_HealAllCount, LVar0)
            IfLt(LVar0, MAX_HEAL_ALL)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, HEAL_ALL_CHANCE)
                    ExecWait(N(EVS_Move_HealAll))
                    Return
                EndIf
            EndIf
        EndIf
    Else
    // multiple injured actors were found
        Call(GetActorVar, ACTOR_SELF, AVAR_HealAllCount, LVar0)
        IfLt(LVar0, MAX_HEAL_ALL)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, HEAL_ALL_CHANCE)
                ExecWait(N(EVS_Move_HealAll))
                Return
            EndIf
        Else
            // choose actor with least HP%
            Call(GetActorVar, ACTOR_SELF, AVAR_HealOneCount, LVar0)
            IfLt(LVar0, MAX_HEAL_ONE)
                SetF(LVar9, Float(100.0))
                Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
                Call(InitTargetIterator)
                Label(LBL_LOOP_CHOOSE_BEST_HEAL)
                    Set(LFlag0, false)
                    Call(GetOwnerTarget, LVar0, LVar1)
                    Call(GetOriginalActorType, LVar0, LVar1)
                    IfEq(LVar1, ACTOR_TYPE_DRY_BONES)
                        Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
                        IfEq(LVar1, 1)
                            Set(LFlag0, true)
                        EndIf
                    EndIf
                    Call(GetActorHP, LVar0, LVar2)
                    Call(GetEnemyMaxHP, LVar0, LVar3)
                    MulF(LVar2, Float(100.0))
                    DivF(LVar2, LVar3)
                    IfEq(LFlag0, false)
                        IfLe(LVar2, LVar9)
                            SetF(LVar9, LVar2)
                            Set(LVarB, LVar0)
                        EndIf
                    EndIf
                    Call(ChooseNextTarget, ITER_NEXT, LVar0)
                    IfNe(LVar0, ITER_NO_MORE)
                        Goto(LBL_LOOP_CHOOSE_BEST_HEAL)
                    EndIf
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, HEAL_ONE_CHANCE)
                    ExecWait(N(EVS_Move_HealOne))
                    Return
                EndIf
            EndIf
        EndIf
    EndIf
    // check various buffs and attacks
    Label(LBL_TRY_MOVES)
    Set(LVarA, 10)
    Set(LVarB, 10)
    Set(LVarC, 10)
    Set(LVarD, 10)
    Set(LVarE, 10)
    Set(LVarF, 10)
    Call(GetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, LVar0)
    IfEq(LVar0, 1)
        Set(LVarA, 100) // only magic blast
        Set(LVarB, 0)
        Set(LVarC, 0)
        Set(LVarD, 0)
        Set(LVarE, 0)
        Set(LVarF, 0)
        Goto(LBL_CHOOSE_MOVE)
    Else
        ExecWait(N(EVS_GetAvailableColumn))
        IfEq(LVar0, -1)
            Set(LVarB, 0)
        EndIf
    EndIf
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNe(LVar0, 0)
        Set(LVarB, 0)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_LastMove, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_LastMove_BoostAttack)
            Call(GetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, LVar1)
            IfLt(LVar1, MAX_ATTACK_BOOST)
                Call(RandInt, 99, LVar0)
                Add(LVar0, 1)
                IfLe(LVar0, 50)
                    Set(LVarA, 0)
                    Set(LVarB, 0)
                    Set(LVarC, 100) // only boost attack
                    Set(LVarD, 0)
                    Set(LVarE, 0)
                    Set(LVarF, 0)
                EndIf
            EndIf
        CaseEq(AVAL_LastMove_BoostDefense)
            Call(GetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, LVar1)
            IfLt(LVar1, MAX_DEFENSE_BOOST)
                Call(RandInt, 99, LVar0)
                Add(LVar0, 1)
                IfLe(LVar0, 50)
                    Set(LVarA, 0)
                    Set(LVarB, 0)
                    Set(LVarC, 0)
                    Set(LVarD, 100) // only boost defense
                    Set(LVarE, 0)
                    Set(LVarF, 0)
                EndIf
            EndIf
    EndSwitch
    // set weights to zero for anything we cant cast anymore
    Call(GetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, LVar0)
    IfGe(LVar0, MAX_ATTACK_BOOST)
        Set(LVarC, 0)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, LVar0)
    IfGe(LVar0, MAX_DEFENSE_BOOST)
        Set(LVarD, 0)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_ElectrifyCount, LVar0)
    IfGe(LVar0, MAX_ELECTRIFY)
        Set(LVarE, 0)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_TransparifyCount, LVar0)
    IfGe(LVar0, MAX_TRANSPARIFY)
        Set(LVarF, 0)
    EndIf
    // make a weighted choice
    Label(LBL_CHOOSE_MOVE)
    Set(LVar9, 0)
    Add(LVar9, LVarA)
    Add(LVar9, LVarB)
    Add(LVar9, LVarC)
    Add(LVar9, LVarD)
    Add(LVar9, LVarE)
    Add(LVar9, LVarF)
    Sub(LVar9, 1)
    Call(RandInt, LVar9, LVar0)
    Add(LVar0, 1)
    IfLe(LVar0, LVarA)
        ExecWait(N(EVS_Attack_MagicBlast))
        Return
    EndIf
    Add(LVarA, LVarB)
    IfLe(LVar0, LVarA)
        ExecWait(N(EVS_Move_MakeClone))
        Return
    EndIf
    Add(LVarA, LVarC)
    IfLe(LVar0, LVarA)
        ExecWait(N(EVS_Move_TryBoostAttack))
        Return
    EndIf
    Add(LVarA, LVarD)
    IfLe(LVar0, LVarA)
        ExecWait(N(EVS_Move_TryBoostDefense))
        Return
    EndIf
    Add(LVarA, LVarE)
    IfLe(LVar0, LVarA)
        ExecWait(N(EVS_Move_TryElectrify))
        Return
    EndIf
    ExecWait(N(EVS_Move_TryTransparent))
    Return
    End
};
