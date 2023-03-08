#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BillBlaster.h"

#define AREA b_area_trd_part_1

#define NAMESPACE A(bill_blaster)

s32 N(DefenseTable_80219D20)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(StatusTable_80219D2C)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 50,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

extern s32 N(IdleAnimations_80219E48)[];
extern EvtScript N(init_80219E6C);

ActorPartBlueprint N(PartsTable_80219DD8)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -6, 29 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80219E48),
        .defenseTable = N(DefenseTable_80219D20),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -9 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 100, 0, 0 },
        .targetOffset = { -106, 29 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80219E48),
        .defenseTable = N(DefenseTable_80219D20),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -9 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BILL_BLASTER,
    .level = 10,
    .maxHP = 4,
    .partCount = ARRAY_COUNT( N(PartsTable_80219DD8)),
    .partsData = N(PartsTable_80219DD8),
    .initScript = &N(init_80219E6C),
    .statusTable = N(StatusTable_80219D2C),
    .escapeChance = 0,
    .airLiftChance = 20,
    .hurricaneChance = 15,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 55, 32 },
    .hpBarOffset = { 8, 0 },
    .statusIconOffset = { -24, 20 },
    .statusMessageOffset = { 5, 25 },
};

s32 N(IdleAnimations_80219E48)[] = {
    STATUS_NORMAL,    ANIM_BillBlaster_Anim01,
    STATUS_STONE,     ANIM_BillBlaster_Anim00,
    STATUS_STOP,      ANIM_BillBlaster_Anim00,
    STATUS_PARALYZE,  ANIM_BillBlaster_Anim00,
    STATUS_END,
};

extern EvtScript N(takeTurn_8021A200);
extern EvtScript N(idle_80219ED0);
extern EvtScript N(handleEvent_80219EE0);

EvtScript N(init_80219E6C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021A200)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80219ED0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80219EE0)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80219ED0) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80219EE0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BillBlaster_Anim03)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8021A2BC);
extern EvtScript N(8021A470);

EvtScript N(takeTurn_8021A200) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(8021A2BC))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(8021A470))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern Formation N(specialFormation_8021A4E8);

API_CALLABLE(func_80218000_4A10A0) {
    N(specialFormation_8021A4E8)[0].var0 = 1;
    N(specialFormation_8021A4E8)[0].var1 = script->owner1.actorID;

    return ApiStatus_DONE2;
}


EvtScript N(8021A2BC) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BillBlaster_Anim02)
    EVT_WAIT(13)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(StartRumble, 9)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2C8)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 33)
    EVT_ADD(LVar1, 19)
    EVT_ADD(LVar2, 3)
    EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar1, LVar2, 2, 5, 0, 2, 0)
    EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar1, LVar2, 2, 5, 2, 2, 0)
    EVT_WAIT(2)
    EVT_CALL(func_80218000_4A10A0)
    EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8021A4E8)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A470) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, FALSE)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

extern ActorBlueprint A(bullet_bill);

Vec3i N(vector3D_8021A4DC) = { NPC_DISPOSE_LOCATION, };

Formation N(specialFormation_8021A4E8) = {
    { .actor = &A(bullet_bill), .home = { .vec = &N(vector3D_8021A4DC) }, .priority = 100 },
};
