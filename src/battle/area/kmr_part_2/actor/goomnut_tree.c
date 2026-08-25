#include "../area.h"
#include "sprite/npc/SpikyGoomnut.h"
#include "mapfs/kmr_bt06_shape.h"
#include "goomba_king_common.h"

#define NAMESPACE A(goomnut_tree)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_TriggerTreeShake);
extern EvtScript N(EVS_DropNutOnGoombas);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BIG_NUT     = 2,
    // more parts listed in goomba_king_common.h
};

enum N(ActorVars) {
    AVAR_Unused_0       = 0,
    AVAR_Unused_1       = 1,
    AVAR_Unused_2       = 2,
    AVAR_Unused_3       = 3,
    AVAR_Unused_4       = 4,
    AVAR_BigNutDropped  = 5,
    // another var listed in goomba_king_common.h
};

enum N(ActorParams) {
    DMG_TO_KING         = 3,
    DMG_TO_RED_GOOMBA   = 3,
    DMG_TO_BLUE_GOOMBA  = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpikyGoomnut_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SMASH,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_UNUSED,         0,
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
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_BIG_NUT,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_TREE_NUT_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_TREE_NUT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_TREE_NUT_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_POPUP,
    .type = ACTOR_TYPE_GOOMNUT_TREE,
    .level = ACTOR_LEVEL_GOOMNUT_TREE,
    .maxHP = 255,
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
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 0, 0 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { 0, 0 },
    .statusTextOffset = { 0, 0 },
};

EvtScript N(EVS_UnusedStub) = {
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_0, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_1, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_2, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_3, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_4, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_BigNutDropped, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_TREE_DELAY, 1)
    Call(SetPartPos, ACTOR_SELF, PRT_BIG_NUT, 10, 140, 10)
    Call(SetPartPos, ACTOR_SELF, PRT_TREE_NUT_1, -95, 140, 10)
    Call(SetPartPos, ACTOR_SELF, PRT_TREE_NUT_2, -115, 130, 0)
    Call(SetPartPos, ACTOR_SELF, PRT_TREE_NUT_3, -65, 118, 5)
    Call(SetPartScale, ACTOR_SELF, PRT_TREE_NUT_1, Float(0.5), Float(0.5), Float(1.0))
    Call(SetPartScale, ACTOR_SELF, PRT_TREE_NUT_2, Float(0.5), Float(0.5), Float(1.0))
    Call(SetPartScale, ACTOR_SELF, PRT_TREE_NUT_3, Float(0.5), Float(0.5), Float(1.0))
    Call(SetPartTargetFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_TARGET_NO_DAMAGE, true)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastElement, LVarE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_ZERO_DAMAGE)
            ExecWait(N(EVS_TriggerTreeShake))
        EndCaseGroup
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_IMMUNE)
            ExecWait(N(EVS_TriggerTreeShake))
            ExecWait(N(EVS_DropNutOnGoombas))
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_TriggerTreeShake))
            ExecWait(N(EVS_DropNutOnGoombas))
        CaseEq(EVENT_DEATH)
            ExecWait(N(EVS_TriggerTreeShake))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(N(EVS_TriggerTreeShake))
        CaseEq(EVENT_SPIKE_CONTACT)
        CaseEq(EVENT_SHOCK_HIT)
        CaseEq(EVENT_END_FIRST_STRIKE)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

// unclear what values LVar0 could have here
EvtScript N(EVS_TakeTurn) = {
    Switch(LVar0)
        CaseEq(6)
            Return
    EndSwitch
    Switch(LVar0)
        CaseEq(0)
        CaseEq(10)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

#include "common/FoliageTransform.inc.c"

EvtScript N(EVS_ShakeTree) = {
    SetTimescale(Float(2.0))
    UseBuf(LVar0)
    BufRead4(LVar1, LVar2, LVar3, LVar4)
    BufRead1(LVar5)
    Call(GetActorPos, ACTOR_PLAYER, LVar6, LVarF, LVar8)
    Call(PlaySound, SOUND_SMACK_TREE)
    Call(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    Thread
        Set(LFlag0, false)
        IfNe(LVar1, 0)
            Wait(1)
            Loop(5)
                UseBuf(LVar1)
                BufRead1(LVar2)
                Loop(LVar2)
                    BufRead1(LVar3)
                    Call(N(TransformFoliage), LVar3, Float(0.1), Float(0.2), LVarF, 0)
                    IfEq(LFlag0, false)
                        Set(LFlag0, true)
                        Call(PlaySoundAtModel, LVar3, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
                    EndIf
                EndLoop
                Wait(1)
                UseBuf(LVar1)
                BufRead1(LVar2)
                Loop(LVar2)
                    BufRead1(LVar3)
                    Call(N(TransformFoliage), LVar3, Float(0.1), Float(-0.2), LVarF, 0)
                EndLoop
                Wait(1)
            EndLoop
            UseBuf(LVar1)
            BufRead1(LVar2)
            Loop(LVar2)
                BufRead1(LVar3)
                Call(TranslateModel, LVar3, 0, 0, 0)
            EndLoop
            Wait(1)
        EndIf
    EndThread
    Thread
        Set(LFlag0, false)
        IfNe(LVar2, 0)
            Loop(5)
                UseBuf(LVar2)
                BufRead1(LVar3)
                Loop(LVar3)
                    BufRead1(LVar4)
                    Call(N(TransformFoliage), LVar4, Float(0.1), Float(0.2), LVarF, 0)
                    IfEq(LFlag0, false)
                        Set(LFlag0, true)
                        Call(PlaySoundAtModel, LVar4, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
                    EndIf
                EndLoop
                Wait(1)
                UseBuf(LVar2)
                BufRead1(LVar3)
                Loop(LVar3)
                    BufRead1(LVar4)
                    Call(N(TransformFoliage), LVar4, Float(0.1), Float(-0.2), LVarF, 0)
                EndLoop
                Wait(1)
            EndLoop
            UseBuf(LVar2)
            BufRead1(LVar3)
            Loop(LVar3)
                BufRead1(LVar4)
                Call(TranslateModel, LVar4, 0, 0, 0)
            EndLoop
            Wait(1)
        EndIf
    EndThread
    Thread
        IfNe(LVar4, 0)
            UseBuf(LVar4)
            BufRead1(LVar5)
            Loop(LVar5)
                BufRead3(LVar6, LVar7, LVar8)
                PlayEffect(EFFECT_DROP_LEAVES, 0, LVar6, LVar7, LVar8, 100, 0)
            EndLoop
        EndIf
    EndThread
    Wait(15)
    Return
    End
};

FoliageModelList N(TreeLeaves) = FOLIAGE_MODEL_LIST(MODEL_ha3, MODEL_o306);
FoliageModelList N(TreeTrunk) = FOLIAGE_MODEL_LIST(MODEL_o307, MODEL_o308, MODEL_o309);

FoliageVectorList N(EffectPositions) = {
    .count = 2,
    .vectors = {
        { -10, 140, 0 },
        { 100, 140, 0 },
    },
};

ShakeTreeConfig N(Tree) = {
    .leaves = &N(TreeLeaves),
    .trunk = &N(TreeTrunk),
    .vectors = &N(EffectPositions),
};

EvtScript N(EVS_TriggerTreeShake) = {
    Set(LVar0, Ref(N(Tree)))
    ExecWait(N(EVS_ShakeTree))
    Return
    End
};

EvtScript N(EVS_DropNutOnGoombas) = {
    PlayEffect(EFFECT_DROP_LEAVES, 0, -25, 120, 0, 90, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_BigNutDropped, LVar0)
    IfNe(LVar0, false)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_FAR)
    Call(BattleCamTargetActor, ACTOR_KING)
    Wait(20)
    Call(SetActorVar, ACTOR_SELF, AVAR_BigNutDropped, true)
    Call(ActorExists, ACTOR_KING, LVar0)
    IfEq(LVar0, 0)
        Call(SetGoalPos, ACTOR_SELF, 10, 0, 10)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, false)
        Call(PlaySoundAtPart, ACTOR_SELF, PRT_BIG_NUT, SOUND_FALL_QUICK)
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, Float(0.8))
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BIG_NUT, Float(4.0))
        Call(FallPartTo, ACTOR_SELF, PRT_BIG_NUT, 10, 20, 10, 20)
        Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, 30, 20, 10, 10, true)
        Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, 40, 20, 10, 5, true)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, false)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, true)
            Wait(1)
        EndLoop
        Return
    EndIf
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_BIG_NUT, SOUND_FALL_QUICK)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, Float(0.8))
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BIG_NUT, Float(4.0))
    Call(GetStatusFlags, ACTOR_KING, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(FallPartTo, ACTOR_SELF, PRT_BIG_NUT, 10, 80, 10, 10)
    Else
        Call(FallPartTo, ACTOR_SELF, PRT_BIG_NUT, 10, 32, 10, 10)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(SetOwnerTarget, ACTOR_KING, PRT_BIG_NUT)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, DMG_TO_KING, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ActorExists, ACTOR_RED_GOOMBA, LVar0)
    IfEq(LVar0, 0)
        Call(GetPartOffset, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2)
        Add(LVar0, 65)
        Set(LVar1, 20)
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, Float(0.7))
        Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, true)
        Add(LVar0, 12)
        Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 8, true)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, false)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, true)
            Wait(1)
        EndLoop
        Return
    EndIf
    Call(GetActorPos, ACTOR_RED_GOOMBA, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_RED_GOOMBA, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 50)
    Else
        Add(LVar1, 20)
    EndIf
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, Float(0.7))
    Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, true)
    Call(SetOwnerTarget, ACTOR_RED_GOOMBA, PRT_MAIN)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, DMG_TO_RED_GOOMBA, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ActorExists, ACTOR_BLUE_GOOMBA, LVar0)
    IfEq(LVar0, 0)
        Call(GetPartOffset, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2)
        Add(LVar0, 35)
        Set(LVar1, 20)
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, Float(0.7))
        Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, true)
        Add(LVar0, 12)
        Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 8, true)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, false)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, true)
            Wait(1)
        EndLoop
        Return
    EndIf
    Call(GetActorPos, ACTOR_BLUE_GOOMBA, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_BLUE_GOOMBA, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 50)
    Else
        Add(LVar1, 20)
    EndIf
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, Float(0.7))
    Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, true)
    Call(SetOwnerTarget, ACTOR_BLUE_GOOMBA, PRT_MAIN)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, DMG_TO_BLUE_GOOMBA, BS_FLAGS1_TRIGGER_EVENTS)
    Call(GetPartOffset, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Set(LVar1, 20)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, Float(0.7))
    Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, true)
    Add(LVar0, 12)
    Call(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 8, true)
    Loop(20)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, false)
        Wait(1)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, true)
        Wait(1)
    EndLoop
    Return
    End
};
