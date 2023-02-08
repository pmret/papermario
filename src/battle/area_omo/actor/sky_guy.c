#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/SkyGuy.h"

#define NAMESPACE b_area_omo_sky_guy

extern s32 N(idleAnimations_8022B104)[];
extern EvtScript N(init_8022987C);
extern EvtScript N(takeTurn_8022A9D0);
extern EvtScript N(takeTurn_8022CA9C);
extern EvtScript N(idle_80229A24);
extern EvtScript N(idle_8022B19C);
extern EvtScript N(handleEvent_8022A398);
extern EvtScript N(handleEvent_8022B310);

s32 N(idleAnimations_802294C0)[] = {
    STATUS_NORMAL,    ANIM_SkyGuy_Anim01,
    STATUS_STONE,     ANIM_SkyGuy_Anim00,
    STATUS_SLEEP,     ANIM_SkyGuy_Anim04,
    STATUS_POISON,    ANIM_SkyGuy_Anim01,
    STATUS_STOP,      ANIM_SkyGuy_Anim00,
    STATUS_STATIC,    ANIM_SkyGuy_Anim01,
    STATUS_PARALYZE,  ANIM_SkyGuy_Anim00,
    STATUS_DIZZY,     ANIM_SkyGuy_Anim05,
    STATUS_FEAR,      ANIM_SkyGuy_Anim05,
    STATUS_END,
};

s32 N(idleAnimations_8022950C)[] = {
    STATUS_NORMAL,    ANIM_SkyGuy_Anim10,
    STATUS_STONE,     ANIM_SkyGuy_Anim0D,
    STATUS_SLEEP,     ANIM_SkyGuy_Anim19,
    STATUS_POISON,    ANIM_SkyGuy_Anim10,
    STATUS_STOP,      ANIM_SkyGuy_Anim0D,
    STATUS_STATIC,    ANIM_SkyGuy_Anim10,
    STATUS_PARALYZE,  ANIM_SkyGuy_Anim0D,
    STATUS_DIZZY,     ANIM_SkyGuy_Anim10,
    STATUS_FEAR,      ANIM_SkyGuy_Anim10,
    STATUS_END,
};

s32 N(idleAnimations_80229558)[] = {
    STATUS_NORMAL,    ANIM_SkyGuy_Anim0F,
    STATUS_STONE,     ANIM_SkyGuy_Anim0C,
    STATUS_SLEEP,     ANIM_SkyGuy_Anim18,
    STATUS_POISON,    ANIM_SkyGuy_Anim0F,
    STATUS_STOP,      ANIM_SkyGuy_Anim0C,
    STATUS_STATIC,    ANIM_SkyGuy_Anim0F,
    STATUS_PARALYZE,  ANIM_SkyGuy_Anim0C,
    STATUS_DIZZY,     ANIM_SkyGuy_Anim0F,
    STATUS_FEAR,      ANIM_SkyGuy_Anim0F,
    STATUS_END,
};

s32 N(idleAnimations_802295A4)[] = {
    STATUS_NORMAL,    ANIM_SkyGuy_Anim11,
    STATUS_STONE,     ANIM_SkyGuy_Anim0E,
    STATUS_SLEEP,     ANIM_SkyGuy_Anim1A,
    STATUS_POISON,    ANIM_SkyGuy_Anim11,
    STATUS_STOP,      ANIM_SkyGuy_Anim0E,
    STATUS_STATIC,    ANIM_SkyGuy_Anim11,
    STATUS_PARALYZE,  ANIM_SkyGuy_Anim0E,
    STATUS_DIZZY,     ANIM_SkyGuy_Anim11,
    STATUS_FEAR,      ANIM_SkyGuy_Anim11,
    STATUS_END,
};

s32 N(idleAnimations_802295F0)[] = {
    STATUS_NORMAL,    ANIM_SkyGuy_Anim0B,
    STATUS_END,
};

s32 N(defenseTable_802295FC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(defenseTable_80229610)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(statusTable_80229624)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

s32 N(statusTable_802296D0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8022977C)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022B104),
        .defenseTable = N(defenseTable_80229610),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802294C0),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 50 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022950C),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
        .unk_20 = 0x29007E,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80229558),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802295A4),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802295F0),
        .defenseTable = N(defenseTable_802295FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_SKY_GUY,
    .level = 14,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(partsTable_8022977C)),
    .partsData = N(partsTable_8022977C),
    .takeTurnScript = &N(init_8022987C),
    .statusTable = N(statusTable_80229624),
    .escapeChance = 50,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 28, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_8022987C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022A9D0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80229A24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022A398)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 5)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 3, 4, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80229A24) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80229A34) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar2)
    EVT_IF_NE(LVar2, 0)
        EVT_EXEC_WAIT(DoDeath)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        EVT_ADD(LVar8, 20)
        EVT_CALL(PlayEffect, EFFECT_BALLOON, 2, LVar7, LVar8, LVar9, EVT_FLOAT(1.0), 150, 0, 0, 0, 0, 0, 0, 0)
        EVT_SUB(LVar7, 14)
        EVT_SUB(LVar8, 4)
        EVT_CALL(PlayEffect, EFFECT_BALLOON, 0, LVar7, LVar8, LVar9, EVT_FLOAT(1.0), 150, 0, 0, 0, 0, 0, 0, 0)
        EVT_ADD(LVar7, 28)
        EVT_CALL(PlayEffect, EFFECT_BALLOON, 1, LVar7, LVar8, LVar9, EVT_FLOAT(1.0), 150, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_EXEC_WAIT(DoDeath)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80229C40) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_SkyGuy_Anim13)
    EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_SkyGuy_Anim12)
    EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_SkyGuy_Anim14)
    EVT_RETURN
    EVT_END
};

EvtScript N(80229CB0) = {
    EVT_CALL(MakeLerp, 100, 80, 7, 5)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVar2, EVT_FLOAT(2.0))
    EVT_SUBF(LVar2, LVar0)
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, LVar2, LVar0, EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, LVar2, LVar0, EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, LVar2, LVar0, EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(MakeLerp, 80, 100, 7, 8)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVar2, EVT_FLOAT(2.0))
    EVT_SUBF(LVar2, LVar0)
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, LVar2, LVar0, EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, LVar2, LVar0, EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, LVar2, LVar0, EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(80229F08) = {
    EVT_CALL(GetLastElement, LVar0)
    EVT_SET(LVar0, 65536)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_4000 | DAMAGE_TYPE_SPINY_SURGE)
        EVT_CALL(func_8027D32C, ACTOR_SELF)
        EVT_THREAD
            EVT_WAIT(20)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E1)
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_SkyGuy_Anim2E)
        EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_SkyGuy_Anim2D)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_SkyGuy_Anim2F)
        EVT_WAIT(30)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
        EVT_WAIT(15)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim00)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_263)
        EVT_CALL(PlayEffect, EFFECT_EMOTE, 2, 0, LVar0, LVar1, LVar2, 24, 0, 25, 0, 0, 0, 0, 0)
        EVT_WAIT(25)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim06)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim06)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 769, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 120, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
        EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
        EVT_CALL(SetPartFlags, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
        EVT_CALL(SetPartFlags, ACTOR_SELF, 1, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim12)
        EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(40)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022CA9C)))
        EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022B19C)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022B310)))
        EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
        EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_ELSE
        EVT_EXEC_WAIT(N(80229CB0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022A398) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, 3)
                EVT_EXEC_WAIT(N(80229CB0))
            EVT_ELSE
                EVT_SET_CONST(LVar0, 2)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, 3)
                EVT_EXEC_WAIT(N(80229CB0))
                EVT_EXEC_WAIT(N(80229F08))
            EVT_ELSE
                EVT_SET_CONST(LVar0, 2)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_SkyGuy_Anim0A)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_SkyGuy_Anim0A)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim0A)
            EVT_EXEC_WAIT(N(80229A34))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SCRIPTED_IMMUNE)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, 3)
                EVT_EXEC_WAIT(N(80229CB0))
            EVT_ELSE
                EVT_SET_CONST(LVar0, 2)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim01)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, 3)
                EVT_EXEC_WAIT(N(80229CB0))
            EVT_ELSE
                EVT_SET_CONST(LVar0, 2)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim01)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
            EVT_EXEC_WAIT(N(80229A34))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim03)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim01)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_SkyGuy_Anim1F)
            EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_SkyGuy_Anim1E)
            EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_SkyGuy_Anim20)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim03)
            EVT_SET_CONST(LVar2, ANIM_SkyGuy_Anim06)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim03)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim07)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(80229C40))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022A9D0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E7)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim08)
    EVT_WAIT(12)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_SkyGuy_Anim0B)
    EVT_WAIT(12)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E8)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 6, 2, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 120)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_EXEC_WAIT(N(80229C40))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 30, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_SkyGuy_Anim07)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 65)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 15, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_EXEC_WAIT(N(80229C40))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 15, 0)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 55)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 25, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(4.0))
            EVT_SUB(LVar0, 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 21, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(80229C40))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_8022B104)[] = {
    STATUS_NORMAL,    ANIM_ShyGuy_Red_Anim01,
    STATUS_STONE,     ANIM_ShyGuy_Red_Anim00,
    STATUS_SLEEP,     ANIM_ShyGuy_Red_Anim12,
    STATUS_POISON,    ANIM_ShyGuy_Red_Anim01,
    STATUS_STOP,      ANIM_ShyGuy_Red_Anim00,
    STATUS_STATIC,    ANIM_ShyGuy_Red_Anim01,
    STATUS_PARALYZE,  ANIM_ShyGuy_Red_Anim00,
    STATUS_DIZZY,     ANIM_ShyGuy_Red_Anim13,
    STATUS_FEAR,      ANIM_ShyGuy_Red_Anim13,
    STATUS_END,
};

EvtScript N(8022B150) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022CA9C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022B19C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022B310)))
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_8022B19C) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 14)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
        EVT_CALL(N(UnkBattleFunc1), -10, 13, 10, 13)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 24)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -10)
        EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022B2AC) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022B310) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8022B2AC))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_SCRIPTED_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim14)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022B7EC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 751, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim05)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_EXEC_WAIT(N(8022B2AC))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022BF14) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_234)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim09)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_SUB(LVar0, 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim09)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim0A)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim09)
    EVT_THREAD
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim0A)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LVar3, 0)
                EVT_LOOP(20)
                    EVT_SUB(LVar3, 30)
                    EVT_IF_LT(LVar3, 0)
                        EVT_ADD(LVar3, 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349 | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim09)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim07)
            EVT_WAIT(15)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim10)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C3)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 50)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim11)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim13)
            EVT_END_IF
            EVT_WAIT(25)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_LABEL(2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ShyGuy_Red_Anim01)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022CA9C) = {
    EVT_CALL(RandInt, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(N(8022B7EC))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8022BF14))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
