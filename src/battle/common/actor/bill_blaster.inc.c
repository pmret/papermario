#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BillBlaster.h"

#define NAMESPACE A(bill_blaster)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Move_FireBullet);
extern EvtScript N(EVS_Move_CheckForBullet);

extern ActorBlueprint A(bullet_bill);
extern Formation N(BulletFormation);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_TARGET          = 2,
};

enum N(ActorVars) {
    AVAR_BulletID       = 0,
    AVAR_HasBullet      = 8,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,             50,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -6, 29 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -9 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 100, 0, 0 },
        .targetOffset = { -106, 29 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -9 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BILL_BLASTER,
    .level = ACTOR_LEVEL_BILL_BLASTER,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 20,
    .hurricaneChance = 15,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 55, 32 },
    .healthBarOffset = { 8, 0 },
    .statusIconOffset = { -24, 20 },
    .statusTextOffset = { 5, 25 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BillBlaster_Idle,
    STATUS_KEY_STONE,     ANIM_BillBlaster_Still,
    STATUS_KEY_STOP,      ANIM_BillBlaster_Still,
    STATUS_KEY_PARALYZE,  ANIM_BillBlaster_Still,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_HasBullet, false)
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
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BillBlaster_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_HasBullet, LVar0)
    Switch(LVar0)
        CaseEq(0)
            ExecWait(N(EVS_Move_FireBullet))
        CaseEq(1)
            ExecWait(N(EVS_Move_CheckForBullet))
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

API_CALLABLE(N(SetBulletInitVars)) {
    N(BulletFormation)[0].var0 = true;
    N(BulletFormation)[0].var1 = script->owner1.actorID;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Move_FireBullet) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BillBlaster_Fire)
    Wait(13)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.0))
    EndThread
    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BULLET_BILL_FIRE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 33)
    Add(LVar1, 19)
    Add(LVar2, 3)
    PlayEffect(EFFECT_00, LVar0, LVar1, LVar2, 2, 5, 0, 2, 0)
    PlayEffect(EFFECT_00, LVar0, LVar1, LVar2, 2, 5, 2, 2, 0)
    Wait(2)
    Call(N(SetBulletInitVars))
    Call(SummonEnemy, Ref(N(BulletFormation)), false)
    Call(SetActorVar, ACTOR_SELF, AVAR_BulletID, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_HasBullet, true)
    Return
    End
};

EvtScript N(EVS_Move_CheckForBullet) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_BulletID, LVar0)
    Call(ActorExists, LVar0, LVar1)
    IfEq(LVar1, false)
        Call(SetActorVar, ACTOR_SELF, AVAR_HasBullet, false)
    EndIf
    Return
    End
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(BulletFormation) = {
    ACTOR_BY_POS(A(bullet_bill), N(SummonPos), 100),
};
