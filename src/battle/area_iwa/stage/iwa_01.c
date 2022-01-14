#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/whacka.h"

#define NAMESPACE b_area_iwa_iwa_01

extern ActorBlueprint N(whacka);
extern Formation N(specialFormation_802208E4);
extern EvtScript N(init_80220A50);
extern EvtScript N(takeTurn_802212E4);
extern EvtScript N(idle_80220B0C);
extern EvtScript N(handleEvent_80220B40);
extern EvtScript N(80221414);
extern EvtScript N(80221334);

EvtScript N(beforeBattle_80220860) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetGroupEnabled, 21, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80220894) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802208A4)[] = {
    0x00000017, 0x00000018, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "iwa_tex",
    .shape = "iwa_bt01_shape",
    .hit = "iwa_bt01_hit",
    .bg = "iwa_bg\0",
    .preBattle = N(beforeBattle_80220860),
    .postBattle = N(afterBattle_80220894),
    .foregroundModelList = N(foregroundModelList_802208A4),
    .unk_1C = 1,
    .unk_20 = N(specialFormation_802208E4),
    .unk_24 = 0x200,
};

Vec3i N(vector3D_802208D8) = { 116, 0, -30 };

Formation N(specialFormation_802208E4) = {
    { .actor = &N(whacka), .home = { .vec = &N(vector3D_802208D8) }},
};

s32 N(idleAnimations_80220900)[] = {
    STATUS_NORMAL,    NPC_ANIM_whacka_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_whacka_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_whacka_Palette_00_Anim_1,
    STATUS_POISON,    NPC_ANIM_whacka_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_whacka_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_whacka_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_whacka_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_whacka_Palette_00_Anim_1,
    STATUS_FEAR,      NPC_ANIM_whacka_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(defenseTable_8022094C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80220958)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
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

ActorPartBlueprint N(partsTable_80220A04)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80220900),
        .defenseTable = N(defenseTable_8022094C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 251,
    },
};

ActorBlueprint N(whacka) = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_40000,
    .type = ACTOR_TYPE_WHACKA,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_80220A04)),
    .partsData = N(partsTable_80220A04),
    .script = N(init_80220A50),
    .statusTable = N(statusTable_80220958),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 50,
    .coinReward = 0,
    .size = { 47, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 40 },
    .statusMessageOffset = { 10, 30 },
};

#include "common/IsSaveVar123.inc.c"

EvtScript N(init_80220A50) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802212E4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80220B0C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80220B40)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(N(IsSaveVar123))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80220B0C) = {
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80220B40) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2073)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_4)
            EVT_EXEC_WAIT(N(80221334))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LE(LW(0), 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_SET_CONST(LW(2), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(N(80221334))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LE(LW(0), 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_SET_CONST(LW(2), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(N(80221334))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoDeath)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LE(LW(0), 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoDeath)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LE(LW(0), 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LE(LW(0), 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_4)
            EVT_EXEC_WAIT(N(80221334))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(80221414))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoDeath)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_SET_CONST(LW(2), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_whacka_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802212E4) = {
    EVT_CALL(RandInt, 100, LW(0))
    EVT_IF_LE(LW(0), 100)
        EVT_EXEC_WAIT(N(80221414))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80221334) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2073)
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_whacka_Palette_00_Anim_1)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 5)
        EVT_ADD(LW(1), 20)
        EVT_ADD(LW(2), 10)
        EVT_CALL(MakeItemEntity, ITEM_WHACKAS_BUMP, LW(0), LW(1), LW(2), 12, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(80221414) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_whacka_Palette_00_Anim_3)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(SetBattleFlagBits2, 0x10000000, 1)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
