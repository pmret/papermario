#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/SpyGuy.h"

#define NAMESPACE A(spy_guy)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_STONE       = 2,
};

enum N(ActorVars) {
    AVAR_ItemState          = 0,
    AVAL_Item_None          = 0,
    AVAL_Item_Fumble        = 1,
    AVAL_Item_KnockAway     = 2,
    AVAL_Item_Gone          = 3,
    AVAR_Knockoff_ItemIdx   = 1,
    AVAR_Weapon             = 2,
    AVAL_Weapon_Slingshot   = 0,
    AVAL_Weapon_Mallet      = 1,
    AVAR_ShouldSwitchWeapon = 3,
};

enum N(ActorParams) {
    DMG_SHOOT       = 2,
    DMG_MALLET      = 2,
};

s32 N(MalletAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpyGuy_Anim03,
    STATUS_KEY_STONE,     ANIM_SpyGuy_Anim01,
    STATUS_KEY_SLEEP,     ANIM_SpyGuy_Anim0F,
    STATUS_KEY_POISON,    ANIM_SpyGuy_Anim03,
    STATUS_KEY_STOP,      ANIM_SpyGuy_Anim01,
    STATUS_KEY_STATIC,    ANIM_SpyGuy_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_SpyGuy_Anim01,
    STATUS_KEY_DIZZY,     ANIM_SpyGuy_Anim12,
    STATUS_KEY_FEAR,      ANIM_SpyGuy_Anim12,
    STATUS_END,
};

s32 N(SlingshotAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpyGuy_Anim02,
    STATUS_KEY_STONE,     ANIM_SpyGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_SpyGuy_Anim0F,
    STATUS_KEY_POISON,    ANIM_SpyGuy_Anim02,
    STATUS_KEY_STOP,      ANIM_SpyGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_SpyGuy_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_SpyGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_SpyGuy_Anim12,
    STATUS_KEY_FEAR,      ANIM_SpyGuy_Anim12,
    STATUS_END,
};

s32 N(StoneAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpyGuy_Anim10,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,              0,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(MalletAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -13 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_STONE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(StoneAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPY_GUY,
    .level = ACTOR_LEVEL_SPY_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 1,
    .size = { 32, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Mallet)
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, false)
    Call(GetInstigatorValue, ACTOR_SELF, LVar0)
    IfNe(LVar0, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Slingshot)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SlingshotAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
    EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_TrySwitchWeapon) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, LVar0)
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(GetLastDamage, ACTOR_SELF, LVar0)
    IfEq(LVar0, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, false)
        Return
    EndIf
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, false)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Weapon_Slingshot)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
        CaseEq(AVAL_Weapon_Mallet)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
    EndSwitch
    Label(0)
        Call(GetBattleFlags, LVar0)
        IfFlag(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            Wait(1)
            Goto(0)
        EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Weapon_Slingshot)
            Call(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Mallet)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(MalletAnims)))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim17)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim19)
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
        CaseEq(AVAL_Weapon_Mallet)
            Call(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Slingshot)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SlingshotAnims)))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim18)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim1A)
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
    EndSwitch
    Wait(10)
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, false)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0B)
            ExecWait(EVS_Enemy_Hit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, true)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0B)
            ExecWait(EVS_Enemy_Hit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, true)
            ExecWait(N(EVS_TrySwitchWeapon))
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0D)
            SetConst(LVar2, ANIM_SpyGuy_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, true)
            ExecWait(N(EVS_TrySwitchWeapon))
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0D)
            SetConst(LVar2, ANIM_SpyGuy_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0B)
            ExecWait(EVS_Enemy_SpinSmashHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, true)
            ExecWait(N(EVS_TrySwitchWeapon))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0B)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            IfEq(LVar1, AVAL_Weapon_Slingshot)
                SetConst(LVar1, ANIM_SpyGuy_Anim02)
            Else
                SetConst(LVar1, ANIM_SpyGuy_Anim03)
            EndIf
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            IfEq(LVar1, AVAL_Weapon_Slingshot)
                SetConst(LVar1, ANIM_SpyGuy_Anim02)
            Else
                SetConst(LVar1, ANIM_SpyGuy_Anim03)
            EndIf
            ExecWait(EVS_Enemy_NoDamageHit)
            ExecWait(N(EVS_TrySwitchWeapon))
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0B)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            IfEq(LVar1, AVAL_Weapon_Slingshot)
                SetConst(LVar1, ANIM_SpyGuy_Anim02)
            Else
                SetConst(LVar1, ANIM_SpyGuy_Anim03)
            EndIf
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            IfEq(LVar1, AVAL_Weapon_Slingshot)
                SetConst(LVar1, ANIM_SpyGuy_Anim06)
            Else
                SetConst(LVar1, ANIM_SpyGuy_Anim07)
            EndIf
            SetConst(LVar2, ANIM_SpyGuy_Anim11)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            IfEq(LVar1, AVAL_Weapon_Slingshot)
                SetConst(LVar1, ANIM_SpyGuy_Anim06)
            Else
                SetConst(LVar1, ANIM_SpyGuy_Anim07)
            EndIf
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            IfEq(LVar1, AVAL_Weapon_Slingshot)
                SetConst(LVar1, ANIM_SpyGuy_Anim06)
            Else
                SetConst(LVar1, ANIM_SpyGuy_Anim07)
            EndIf
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_Slingshot) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 1)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_DRAW)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim15)
    Wait(12)
    Wait(12)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim16)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Add(LVar1, 10)
    Call(SetPartPos, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_STONE, Float(0.4), Float(0.4), Float(0.4))
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_FIRE)
    Call(SetPartSounds, ACTOR_SELF, PRT_STONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Loop(0)
                    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    Call(GetPartOffset, ACTOR_SELF, PRT_STONE, LVar3, LVar4, LVar5)
                    IfGt(LVar0, LVar3)
                        BreakLoop
                    EndIf
                    Wait(1)
                EndLoop
                IfEq(LVarA, HIT_RESULT_LUCKY)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndIf
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(14.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.002))
            Call(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Wait(15)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(14.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.002))
    Call(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, true)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(GetPartOffset, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2)
            Sub(LVar0, 100)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.7))
            Call(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, 0, LVar2, 30, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(YieldTurn)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

#include "common/ItemEntityJumpToPos.inc.c"

#include "common/GetItemEntityPosition.inc.c"

#include "common/DisableRandomAbility.inc.c"

#include "common/battle/CheckPlayerCanLoseCommand.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_ManageItemMotion) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_ItemState, LVarA)
        Switch(LVarA)
            CaseEq(AVAL_Item_None)
                // do nothing
            CaseEq(AVAL_Item_Fumble)
                Call(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
                Set(LVar2, 0)
                Sub(LVar3, 1)
                Call(N(DisableRandomAbility), LVar4, LVar5)
                Call(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_Knockoff_ItemIdx, LVar0)
                Add(LVar1, 30)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 20, Float(1.0))
                Add(LVar1, 20)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 10, Float(1.0))
                Add(LVar1, 10)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, Float(1.0))
                Call(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAR_ItemState)
            CaseEq(AVAL_Item_KnockAway)
                Call(ShowMessageBox, LVar5, 60)
                Sub(LVar1, 150)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 30, Float(1.0))
                Call(RemoveItemEntity, LVar0)
                Call(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAL_Item_Gone)
                Return
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Attack_Mallet) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar1)
    IfNotFlag(LVar1, STATUS_FLAG_SHRINK)
        Call(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EndIf
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
    Wait(10)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Thread
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MALLET_SWING)
    EndThread
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim0A)
            Wait(6)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim07)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim0A)
    Wait(5)
    Wait(2)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MALLET, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Set(LFlag0, false)
            Call(GetBattleFlags, LVar0)
            IfNotFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Call(N(CheckPlayerCanLoseCommand), LVar0)
                IfNe(LVar0, -1)
                    Set(LFlag0, true)
                EndIf
            EndIf
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfLe(LVar0, 0)
                Wait(20)
                Goto(100)
            EndIf
            Call(GetStatusFlags, ACTOR_SELF, LVar1)
            IfFlag(LVar1, STATUS_FLAG_SHRINK)
                Wait(20)
                Goto(100)
            EndIf
            Call(GetStatusFlags, ACTOR_PLAYER, LVar1)
            IfFlag(LVar1, STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
                Wait(20)
                Goto(100)
            EndIf
            IfEq(LFlag0, true)
                Call(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAL_Item_Fumble)
                Exec(N(EVS_ManageItemMotion))
                Wait(8)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, 70)
                Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(RunToGoal, ACTOR_SELF, 0, false)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
                Label(0)
                    Call(GetActorVar, ACTOR_SELF, AVAR_ItemState, LVar0)
                    IfNe(LVar0, AVAL_Item_None)
                        Wait(1)
                        Goto(0)
                    EndIf
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
                Call(GetActorVar, ACTOR_SELF, AVAR_Knockoff_ItemIdx, LVar0)
                Call(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
                Add(LVar1, 20)
                Sub(LVar3, 2)
                Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
                Call(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                Call(RunToGoal, ACTOR_SELF, 0, false)
                Thread
                    Wait(5)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_COMMAND_LOSS)
                    Call(N(StartRumbleWithParams), 200, 10)
                EndThread
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim09)
                Wait(5)
                Call(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAL_Item_KnockAway)
                Sub(LVar1, 7)
                PlayEffect(EFFECT_FIREWORK, 0, LVar1, LVar2, LVar3, Float(1.0), 0, 0)
                Wait(40)
            Else
                Wait(8)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, 70)
                Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(RunToGoal, ACTOR_SELF, 0, false)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
                Wait(10)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 10)
                PlayEffect(EFFECT_EMOTE, EMOTE_QUESTION, 0, LVar0, LVar1, LVar2, 25, -45, 20, 0, 0)
                Wait(20)
            EndIf
            Label(100)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_SpyGuy_Anim07)
            ExecWait(EVS_Enemy_ReturnHome)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Slingshot)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SlingshotAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Weapon_Slingshot)
            ExecWait(N(EVS_Attack_Slingshot))
        CaseEq(AVAL_Weapon_Mallet)
            ExecWait(N(EVS_Attack_Mallet))
    EndSwitch
    Return
    End
};
