#include "../area.h"
#include "sprite/npc/Lee.h"
#include "sprite/npc/BattleBombette.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/npc/BattleGoombario.h"
#include "sprite/npc/BattleKooper.h"
#include "sprite/npc/BattleLakilester.h"
#include "sprite/npc/BattleParakarry.h"
#include "sprite/npc/BattleSushie.h"
#include "sprite/npc/BattleWatt.h"

#define NAMESPACE A(lee)

// scripts in lee.c calls two functions defined in lee_watt.c for adjusting the background fade
// this macro is used to highlight those instances
#define WATT(x) A( watt_lee_##x )

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Move_CopyPartner);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
    PRT_SPINY       = 3,
    PRT_ZERO        = 0,
};

enum N(ActorVars) {
    AVAR_HandledEvent           = 0,
    AVAR_Copy_ParentActorID     = 0,
    AVAR_Copy_PartnerLevel      = 1,
    AVAR_FormDuration           = 2,
    AVAR_Kooper_Toppled         = 4,
    AVAR_Kooper_ToppleTurns     = 5,
    AVAR_State                  = 8,
    AVAL_State_ReadyToCopy      = 0, // will copy partner next turn
    AVAL_State_CopiedPartner    = 1, // currently transformed
    AVAL_State_ReadyToTackle    = 2, // will use flying tackle next turn
    AVAL_State_WaitToTackle     = 3, // do nothing this turn and tackle next turn (unused)
};

enum N(ActorParams) {
    DMG_FLYING_LEAP     = 5,
};

BSS s32 PartnerCopyHistory[12];
BSS s32 LastPartnerCopied;

API_CALLABLE(N(InitPartnerCopyHistory)) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
        PartnerCopyHistory[i] = 0;
    }
    LastPartnerCopied = -1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(RegisterPartnerToCopy)) {
    PlayerData* playerData = &gPlayerData;
    s32 currentPartner = script->varTable[5];
    s32 partnerId;
    s32 i;
    s32 randomPartnerMap[ARRAY_COUNT(PartnerCopyHistory)];

    // initial case
    if (LastPartnerCopied < 0) {
        LastPartnerCopied = currentPartner;
        PartnerCopyHistory[currentPartner] = TRUE;
        return ApiStatus_DONE2;
    }

    // current partner has never been copied
    if (LastPartnerCopied != currentPartner && !PartnerCopyHistory[currentPartner]) {
        LastPartnerCopied = currentPartner;
        PartnerCopyHistory[currentPartner] = TRUE;
        return ApiStatus_DONE2;
    }

    // prepare to select a partner at random
    for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
        randomPartnerMap[i] = i;
    }

    // randomly swap 100 times
    for (i = 0; i < 100; i++) {
        s32 index1 = rand_int(ARRAY_COUNT(PartnerCopyHistory) - 1);
        s32 index2 = rand_int(ARRAY_COUNT(PartnerCopyHistory) - 1);
        s32 tempValue = randomPartnerMap[index1];
        randomPartnerMap[index1] = randomPartnerMap[index2];
        randomPartnerMap[index2] = tempValue;
    }

    // search the shuffled list for a valid partner who has not been copied
    for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
        partnerId = randomPartnerMap[i];

        if (playerData->partners[partnerId].enabled
            && partnerId != PARTNER_GOOMPA
            && partnerId != PARTNER_GOOMBARIA
            && partnerId != PARTNER_TWINK
            && partnerId != currentPartner
            && !PartnerCopyHistory[partnerId]
        ) {
            break;
        }
    }

    if (i < ARRAY_COUNT(PartnerCopyHistory)) {
        // if a valid partner was found, return it
        PartnerCopyHistory[partnerId] = TRUE;
        LastPartnerCopied = partnerId;
        script->varTable[5] = partnerId;
        script->varTable[6] = playerData->partners[partnerId].level;
        return ApiStatus_DONE2;
    } else {
        // no valid selections were found, reset the copy history and just use the current partner
        for (i = 0; i < ARRAY_COUNT(PartnerCopyHistory); i++) {
            PartnerCopyHistory[i] = FALSE;
        }
        LastPartnerCopied = currentPartner;
        PartnerCopyHistory[currentPartner] = TRUE;
        return ApiStatus_DONE2;
    }
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lee_Idle,
    STATUS_KEY_STONE,     ANIM_Lee_Still,
    STATUS_KEY_SLEEP,     ANIM_Lee_Sleep,
    STATUS_KEY_POISON,    ANIM_Lee_Idle,
    STATUS_KEY_STOP,      ANIM_Lee_Still,
    STATUS_KEY_STATIC,    ANIM_Lee_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Lee_Still,
    STATUS_KEY_DIZZY,     ANIM_Lee_Dizzy,
    STATUS_KEY_DIZZY,     ANIM_Lee_Dizzy,
    STATUS_END,
};

s32 N(FlailingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lee_Hurt,
    STATUS_END,
};

s32 N(UnusedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lee_Run,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             75,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               75,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,        -1,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 25 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_LEE,
    .level = ACTOR_LEVEL_LEE,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 36, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToCopy)
    Call(SetActorVar, ACTOR_SELF, AVAR_HandledEvent, FALSE)
    Thread
        Call(FreezeBattleState, TRUE)
        ExecWait(N(EVS_Move_CopyPartner))
        Call(FreezeBattleState, FALSE)
    EndThread
    Call(N(InitPartnerCopyHistory))
    Call(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Lee_Run)
    ExecWait(EVS_Enemy_ReturnHome)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_HandledEvent, TRUE)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Burned)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Burned)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Burned)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Run)
            SetConst(LVar2, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lee_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_FlyingTackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToCopy)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Crouch)
    Wait(20)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_DUPLIGHOST_LEAP, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Midair)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
            Call(JumpToGoal, ACTOR_SELF, 17, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Idle)
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            Wait(15)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Midair)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Call(AddGoalPos, ACTOR_SELF, Float(4.0), Float(-6.0), 0)
    Else
        Call(AddGoalPos, ACTOR_SELF, 10, -15, 0)
    EndIf
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_FLYING_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Land)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Wait(10)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript A(EVS_Lee_RemoveParentActor) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_ParentActorID, LVar0)
    Call(RemoveActor, LVar0)
    Return
    End
};

EvtScript A(EVS_Lee_LoseDisguise) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Wait(30)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_ParentActorID, LVarA)
    Call(UseIdleAnimation, LVarA, FALSE)
    Call(HideHealthBar, LVarA)
    Call(CopyStatusEffects, ACTOR_SELF, LVarA)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 3)
        Add(LVar2, 5)
        Loop(3)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            Wait(3)
        EndLoop
    EndThread
    Wait(5)
    Call(GetActorHP, ACTOR_SELF, LVarB)
    Call(SetEnemyHP, LVarA, LVarB)
    Call(CopyBuffs, ACTOR_SELF, LVarA)
    Call(GetActorPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    Call(SetActorPos, LVarA, LVarB, LVarC, LVarD)
    Call(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    Call(SetPartFlagBits, LVarA, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, FALSE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    Call(SetActorVar, LVarA, AVAR_State, AVAL_State_ReadyToTackle)
    Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetIdleAnimations, LVarA, PRT_MAIN, Ref(N(FlailingAnims)))
    Call(SetAnimation, LVarA, PRT_MAIN, ANIM_Lee_Hurt)
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(GetActorPos, LVarA, LVarB, LVarC, LVarD)
    IfGt(LVarC, 0)
        Set(LVarC, 0)
        Call(SetActorJumpGravity, LVarA, Float(0.5))
        Call(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
        Call(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        Call(JumpToGoal, LVarA, 15, FALSE, TRUE, FALSE)
        Call(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
        Call(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        Call(JumpToGoal, LVarA, 10, FALSE, TRUE, FALSE)
        Call(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        Call(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
    EndIf
    Call(ForceHomePos, LVarA, LVarB, LVarC, LVarD)
    Call(HPBarToHome, LVarA)
    Call(SetIdleAnimations, LVarA, PRT_MAIN, Ref(N(DefaultAnims)))
    Call(SetAnimation, LVarA, PRT_MAIN, ANIM_Lee_Idle)
    Call(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    Call(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    Call(HPBarToHome, ACTOR_SELF)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript A(EVS_Lee_ShockKnockback) = {
    Call(HideHealthBar, ACTOR_SELF)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 15)
    Add(LVar1, 10)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
    Set(LVar0, LVarA)
    Set(LVar1, LVarB)
    ExecWait(EVS_Enemy_ShockHit)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Thread
        Call(SetActorRotationOffset, ACTOR_SELF, 0, LVarC, 0)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, -48)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Add(LVar0, 10)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    Return
    End
};

Vec3i A(Lee_SummonPos) = { NPC_DISPOSE_LOCATION };

#include "lee_goombario.inc.c"
#include "lee_kooper.inc.c"
#include "lee_bombette.inc.c"
#include "lee_parakarry.inc.c"
#include "lee_bow.inc.c"
#include "lee_watt.inc.c"
#include "lee_sushie.inc.c"
#include "lee_lakilester.inc.c"
#define NAMESPACE A(lee)

API_CALLABLE(N(GetPartnerAndLevel)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.curPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.curPartner].level);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AdjustFormationPriority)) {
    Bytecode* args = script->ptrReadPos;
    s32 partnerID = evt_get_variable(script, *args++);
    Actor* actor = get_actor(script->owner1.enemyID);
    FormationRow* formation = NULL;

    switch (partnerID) {
        case PARTNER_GOOMBARIO:
            formation = A(LeeGoombarioFormation);
            break;
        case PARTNER_KOOPER:
            formation = A(LeeKooperFormation);
            break;
        case PARTNER_BOMBETTE:
            formation = A(LeeBombetteFormation);
            break;
        case PARTNER_PARAKARRY:
            formation = A(LeeParakarryFormation);
            break;
        case PARTNER_BOW:
            formation = A(LeeBowFormation);
            break;
        case PARTNER_WATT:
            formation = A(LeeWattFormation);
            break;
        case PARTNER_SUSHIE:
            formation = A(LeeSushieFormation);
            break;
        case PARTNER_LAKILESTER:
            formation = A(LeeLakilesterFormation);
            break;
    }
    formation->priority = actor->turnPriority + 10;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Move_CopyPartner) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(ActorSpeak, MSG_MAC_Gate_0027, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GHOST_TRANSFORM)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lee_RaisedArmsTalk)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar1, 8)
        SetF(LVar3, Float(0.4))
    Else
        Add(LVar1, 20)
        SetF(LVar3, Float(1.0))
    EndIf
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, LVar3, 40, 0)
    Call(WATT(UnkBackgroundFunc3))
    Call(MakeLerp, 0, 200, 20, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(WATT(SetBackgroundAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Wait(10)
    Call(N(GetPartnerAndLevel), LVar5, LVar6)
    Call(N(RegisterPartnerToCopy))
    Call(N(AdjustFormationPriority), LVar5)
    Switch(LVar5)
        CaseEq(PARTNER_GOOMBARIO)
            Call(SummonEnemy, Ref(A(LeeGoombarioFormation)), FALSE)
        CaseEq(PARTNER_KOOPER)
            Call(SummonEnemy, Ref(A(LeeKooperFormation)), FALSE)
        CaseEq(PARTNER_BOMBETTE)
            Call(SummonEnemy, Ref(A(LeeBombetteFormation)), FALSE)
        CaseEq(PARTNER_PARAKARRY)
            Call(SummonEnemy, Ref(A(LeeParakarryFormation)), FALSE)
        CaseEq(PARTNER_BOW)
            Call(SummonEnemy, Ref(A(LeeBowFormation)), FALSE)
        CaseEq(PARTNER_WATT)
            Call(SummonEnemy, Ref(A(LeeWattFormation)), FALSE)
        CaseEq(PARTNER_SUSHIE)
            Call(SummonEnemy, Ref(A(LeeSushieFormation)), FALSE)
        CaseEq(PARTNER_LAKILESTER)
            Call(SummonEnemy, Ref(A(LeeLakilesterFormation)), FALSE)
    EndSwitch
    Set(LVarA, LVar0)
    Call(CopyStatusEffects, ACTOR_SELF, LVarA)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 3)
        Add(LVar2, 5)
        Loop(3)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            Wait(3)
        EndLoop
    EndThread
    Wait(5)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    Call(SetActorFlagBits, ACTOR_SELF, (ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY), TRUE)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(SetEnemyHP, LVarA, LVar0)
    Call(CopyBuffs, ACTOR_SELF, LVarA)
    Call(GetOwnerID, LVar0)
    Call(SetActorVar, LVarA, AVAR_Copy_ParentActorID, LVar0)
    Call(SetActorVar, LVarA, AVAR_Copy_PartnerLevel, LVar6)
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Thread
        Call(MakeLerp, 200, 0, 20, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(WATT(SetBackgroundAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndThread
    Call(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Switch(LVar5)
        CaseEq(PARTNER_LAKILESTER)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, LVarA, Float(0.01))
            Call(SetGoalPos, LVarA, LVar0, 10, LVar2)
            Call(JumpToGoal, LVarA, 10, FALSE, FALSE, FALSE)
            Wait(10)
        CaseOrEq(PARTNER_WATT)
        CaseOrEq(PARTNER_BOW)
        CaseOrEq(PARTNER_PARAKARRY)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, LVarA, Float(0.01))
            Call(SetGoalPos, LVarA, LVar0, 30, LVar2)
            Call(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
        EndCaseGroup
    EndSwitch
    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVarA)
    Call(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
    Wait(20)
    Call(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    Call(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_CopiedPartner)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_ReadyToCopy)
            ExecWait(N(EVS_Move_CopyPartner))
        CaseEq(AVAL_State_CopiedPartner)
            // do nothing
        CaseEq(AVAL_State_ReadyToTackle)
            ExecWait(N(EVS_Attack_FlyingTackle))
        CaseEq(AVAL_State_WaitToTackle)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ReadyToTackle)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_ENEMY_BEGIN)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_FLAG_SHRINK)
                BreakSwitch
            EndIf
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            Div(LVar1, 2)
            IfLe(LVar0, LVar1)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                IfEq(LVar0, AVAL_State_CopiedPartner)
                    Call(ActorSpeak, MSG_MAC_Gate_0028, ACTOR_ENEMY1, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
                Else
                    Call(ActorSpeak, MSG_MAC_Gate_0028, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
                EndIf
                BreakSwitch
            EndIf
            Call(GetPlayerHP, LVar0)
            IfLe(LVar0, 5)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0029, ACTOR_SELF, PRT_MAIN, ANIM_Lee_Talk, ANIM_Lee_Walk)
                BreakSwitch
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
