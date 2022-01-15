#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/bill_blaster.h"

#define AREA b_area_trd_part_1

#define NAMESPACE A(bill_blaster)

s32 N(defenseTable_80219D20)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_80219D2C)[] = {
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

extern s32 N(idleAnimations_80219E48)[];
extern EvtSource N(init_80219E6C);

ActorPartDesc N(partsTable_80219DD8)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -6, 29 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219E48),
        .defenseTable = N(defenseTable_80219D20),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 247,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 100, 0, 0 },
        .targetOffset = { -106, 29 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219E48),
        .defenseTable = N(defenseTable_80219D20),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 247,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BILL_BLASTER,
    .level = 10,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_80219DD8)),
    .partsData = N(partsTable_80219DD8),
    .script = N(init_80219E6C),
    .statusTable = N(statusTable_80219D2C),
    .escapeChance = 0,
    .airLiftChance = 20,
    .spookChance = 15,
    .baseStatusChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 55, 32 },
    .hpBarOffset = { 8, 0 },
    .statusIconOffset = { -24, 20 },
    .statusMessageOffset = { 5, 25 },
};

s32 N(idleAnimations_80219E48)[] = {
    STATUS_NORMAL,    NPC_ANIM_bill_blaster_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_bill_blaster_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_bill_blaster_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_bill_blaster_Palette_00_Anim_0,
    STATUS_END,
};

extern EvtSource N(takeTurn_8021A200);
extern EvtSource N(idle_80219ED0);
extern EvtSource N(handleEvent_80219EE0);

EvtSource N(init_80219E6C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021A200)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80219ED0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80219EE0)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80219ED0) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_80219EE0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bill_blaster_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtSource N(8021A2BC);
extern EvtSource N(8021A470);

EvtSource N(takeTurn_8021A200) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_SWITCH(LW(0))
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

ApiStatus func_80218000_4A10A0(Evt* script, s32 isInitialCall) {
    N(specialFormation_8021A4E8)[0].var0 = 1;
    N(specialFormation_8021A4E8)[0].var1 = script->owner1.actorID;

    return ApiStatus_DONE2;
}


EvtSource N(8021A2BC) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bill_blaster_Palette_00_Anim_2)
    EVT_WAIT_FRAMES(13)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(StartRumble, 9)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2C8)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 33)
    EVT_ADD(LW(1), 19)
    EVT_ADD(LW(2), 3)
    EVT_CALL(PlayEffect, EFFECT_ID_00, LW(0), LW(1), LW(2), 2, 5, 0, 2, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, EFFECT_ID_00, LW(0), LW(1), LW(2), 2, 5, 2, 2, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(func_80218000_4A10A0)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021A4E8)), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021A470) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_CALL(ActorExists, LW(0), LW(1))
    EVT_IF_EQ(LW(1), FALSE)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

extern ActorDesc A(bullet_bill);

Vec3i N(vector3D_8021A4DC) = { 0, -1000, 0, };

Formation N(specialFormation_8021A4E8) = {
    { .actor = &A(bullet_bill), .home = { .vec = &N(vector3D_8021A4DC) }, .priority = 100 },
};
