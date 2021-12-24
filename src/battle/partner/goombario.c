#define NAMESPACE battle_partner_goombario

#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/battle_goombario.h"

extern EffectInstance* D_8023CDA0;
extern s32 D_8023CDA4;
extern s32 D_8023BB98_6ECC78;
extern s32 bActorTattles[ACTOR_TYPE_COUNT];

extern EvtSource N(init);
extern EvtSource N(80239784);
extern EvtSource N(802397E0);
extern EvtSource N(8023993C);
extern EvtSource N(8023994C);
extern EvtSource N(80239988);
extern EvtSource N(8023A754);
extern EvtSource N(8023ADC4);
extern EvtSource N(8023B45C);
extern EvtSource N(8023BB9C);
extern EvtSource N(8023C5B8);
extern EvtSource N(8023C90C);
extern EvtSource N(handleEvent_80239360);
extern EvtSource N(idle_80239350);
extern EvtSource N(nextTurn_80239A3C);
extern EvtSource N(takeTurn_802396D8);

ApiStatus func_802380E4_6F11C4(Evt* script, s32 isInitialCall);
ApiStatus func_8023817C_6F125C(Evt* script, s32 isInitialCall);
ApiStatus func_80238BCC_6F1CAC(Evt* script, s32 isInitialCall);
ApiStatus func_80238EDC_6F1FBC(Evt* script, s32 isInitialCall);

ApiStatus N(func_80238000_6F10E0)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 posX = partnerActor->currentPos.x;
    f32 posY = partnerActor->currentPos.y;
    f32 posZ = partnerActor->currentPos.z;
    f32 goalX = partnerActor->state.goalPos.x;
    f32 goalY = partnerActor->state.goalPos.y;
    f32 goalZ = partnerActor->state.goalPos.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (battleStatus->unk_83 != 0) {
        if (script->varTable[0] < 10) {
            script->varTable[0] = 10;
        }
    } else if (script->varTable[0] < 15) {
        script->varTable[0] = 15;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802380E4_6F11C4(Evt* script, s32 isInitialCall) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);

    script->varTable[0] = 99;
    D_8023BB98_6ECC78 *= targetActor->staticActorData->powerBounceChance;
    D_8023BB98_6ECC78 /= 100;
    if (D_8023BB98_6ECC78 < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/goombario", func_8023817C_6F125C);

ApiStatus N(func_80238A20_6F1B00)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = gBattleStatus.partnerActor;
    Vec3f* pos = &partnerActor->state.currentPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        partnerActor->state.currentPos.x = partnerActor->currentPos.x;
        partnerActor->state.currentPos.y = partnerActor->currentPos.y;
        partnerActor->state.currentPos.z = partnerActor->currentPos.z;
        script->functionTemp[0] = 1;
    }

    if (partnerActor->state.velocity > 0.0f) {
        set_animation(0x100, 0, partnerActor->state.animJumpRise);
    }

    if (partnerActor->state.velocity < 0.0f) {
        set_animation(0x100, 0, partnerActor->state.animJumpFall);
    }

    partnerActor->state.currentPos.y = (partnerActor->state.currentPos.y + partnerActor->state.velocity);
    partnerActor->state.velocity = (partnerActor->state.velocity - partnerActor->state.acceleration);
    add_xz_vec3f(pos, partnerActor->state.speed, partnerActor->state.angle);
    partnerActor->currentPos.x = partnerActor->state.currentPos.x;
    partnerActor->currentPos.y = partnerActor->state.currentPos.y;
    partnerActor->currentPos.z = partnerActor->state.currentPos.z;

    if (partnerActor->currentPos.y < 10.0f) {
        partnerActor->currentPos.y = 10.0f;

        play_movement_dust_effects(2, partnerActor->currentPos.x, partnerActor->currentPos.y, partnerActor->currentPos.z,
                                   partnerActor->yaw);
        sfx_play_sound(SOUND_SOFT_LAND);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238B60_6F1C40(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    s32* tattle = &bActorTattles[targetActor->actorType];

    script->varTable[0] = *tattle;

    if (script->varTable[0] == NULL) {
        script->varTable[0] = bActorTattles[0];
    }

    save_tattle_flags(targetActor->actorType);

    return ApiStatus_DONE2;
}


INCLUDE_ASM(s32, "battle/partner/goombario", func_80238BCC_6F1CAC);

ApiStatus func_80238E04_6F1EE4(Evt* script, s32 isInitialCall) {
    D_8023CDA0 = playFX_6C(0, 206, 144, 0, 1.0f, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80238E48_6F1F28(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = D_8023CDA0;

    ((EffectInstanceData*)effect->data)->pos.y = 144.0f;
    effect->flags |= EFFECT_INSTANCE_FLAGS_10;

    return ApiStatus_DONE2;
}

ApiStatus func_80238E74_6F1F54(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;

    script->varTable[0] = FALSE;

    switch (battleStatus->selectedMoveID) {
        case 134:
            if (partnerActor->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
        case 135:
            if (partnerActor->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
        case 136:
            if (partnerActor->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/goombario", func_80238EDC_6F1FBC);

ApiStatus N(StopGlowing)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->partnerActor->isGlowing = FALSE;
    battleStatus->flags1 &= ~0x40000000;

    return ApiStatus_DONE2;
}

ApiStatus N(StopGlowingAndGet)(Evt* script, s32 isInitialCall) {
    Actor* partnerActor = gBattleStatus.partnerActor;

    if (!(gBattleStatus.flags1 & 0x40000000)) {
        partnerActor->isGlowing = FALSE;
    }

    script->varTable[0] = partnerActor->isGlowing;
    partnerActor->isGlowing = FALSE;
    gBattleStatus.flags1 &= ~0x40000000;

    return ApiStatus_DONE2;
}

ApiStatus N(IsGlowing)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    script->varTable[0] = battleStatus->partnerActor->isGlowing;

    return ApiStatus_DONE2;
}

ApiStatus func_802390C8_6F21A8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    playFX_6B(6, var1, var2, var3, var4, 45);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80239190_6F2270)(Evt* script, s32 isInitialCall) {
    if (D_8023CDA4 == 0) {
        script->varTable[0] = 36;
    } else {
        script->varTable[0] = 37;
    }

    return ApiStatus_DONE2;
}

s32 N(idleAnimations_802391B0)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_goombario_default_walk,
    STATUS_STONE,     NPC_ANIM_battle_goombario_default_still,
    STATUS_SLEEP,     NPC_ANIM_battle_goombario_default_sleep,
    STATUS_POISON,    NPC_ANIM_battle_goombario_default_still,
    STATUS_STOP,      NPC_ANIM_battle_goombario_default_still,
    STATUS_DAZE,      NPC_ANIM_battle_goombario_default_daze,
    STATUS_TURN_DONE, NPC_ANIM_battle_goombario_default_still,
    STATUS_END,
};

s32 N(defenseTable_802391EC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_802391F8)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 100,
    STATUS_POISON, 100,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
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

ActorPartDesc N(partsTable_802392A4)[] = {
    {
        .flags = 0,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 8, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802391B0),
        .defenseTable = N(defenseTable_802391EC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = ELEMENT_IMMUNITY_FLAGS_0,
    },
};

extern EvtSource N(init_802392F0);

ActorDesc N(goombario) = {
    .flags = 0,
    .type = 111,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_802392A4)),
    .partsData = N(partsTable_802392A4),
    .script = N(init_802392F0),
    .statusTable = N(statusTable_802391F8),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 29, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtSource N(init_802392F0) = {
    EVT_CALL(BindTakeTurn, 256, EVT_PTR(battle_partner_goombario_takeTurn_802396D8))
    EVT_CALL(BindIdle, 256, EVT_PTR(battle_partner_goombario_idle_80239350))
    EVT_CALL(BindHandleEvent, 256, EVT_PTR(battle_partner_goombario_handleEvent_80239360))
    EVT_CALL(BindNextTurn, 256, EVT_PTR(battle_partner_goombario_nextTurn_80239A3C))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80239350) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_80239360) = {
    EVT_CALL(UseIdleAnimation, 256, 0)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, 256, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_SET_CONST(EVT_VAR(2), 0x9000A)
            EVT_EXEC_WAIT(0x802977BC)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_EXEC_WAIT(0x80296014)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_CALL(PlaySoundAtActor, 256, 8332)
            EVT_SET_CONST(EVT_VAR(0), 0x1)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_EXEC_WAIT(0x80297814)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(42)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_SET(EVT_VAR(2), 12)
            EVT_EXEC_WAIT(0x80294FE4)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_EXEC_WAIT(0x80296014)
        EVT_CASE_EQ(44)
            EVT_SET_CONST(EVT_VAR(1), 0x9000B)
            EVT_SET(EVT_VAR(2), 12)
            EVT_SET_CONST(EVT_VAR(3), 0x9000C)
            EVT_EXEC_WAIT(0x80294C68)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_EXEC_WAIT(0x80296014)
        EVT_CASE_EQ(14)
            EVT_SET_CONST(EVT_VAR(1), 0x9000B)
            EVT_SET_CONST(EVT_VAR(2), 0x9000C)
            EVT_EXEC_WAIT(0x8029621C)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_EXEC_WAIT(0x80296014)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_SET(EVT_VAR(2), 12)
            EVT_EXEC_WAIT(0x80295744)
        EVT_CASE_EQ(51)
            EVT_CALL(battle_partner_goombario_StopGlowing)
            EVT_SET_CONST(EVT_VAR(1), 0x9000A)
            EVT_EXEC_WAIT(0x80296014)
        EVT_CASE_EQ(52)
            EVT_SET_CONST(EVT_VAR(0), 0x1)
            EVT_SET_CONST(EVT_VAR(1), 0x90001)
            EVT_SET_CONST(EVT_VAR(2), 0x90003)
            EVT_SET(EVT_VAR(3), 0)
            EVT_EXEC_WAIT(0x80295EC4)
        EVT_CASE_OR_EQ(24)
        EVT_CASE_OR_EQ(26)
            EVT_CALL(PlaySoundAtActor, 256, 8332)
            EVT_SET_CONST(EVT_VAR(0), 0x1)
            EVT_SET_CONST(EVT_VAR(1), 0x9000E)
            EVT_EXEC_WAIT(0x80297814)
            EVT_WAIT_FRAMES(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, 256, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_802396D8) = {
    EVT_CALL(GetBattlePhase, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(battle_partner_goombario_8023993C)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(battle_partner_goombario_802397E0)
        EVT_CASE_EQ(5)
            EVT_EXEC_WAIT(battle_partner_goombario_80239784)
        EVT_CASE_EQ(3)
            EVT_EXEC_WAIT(battle_partner_goombario_8023994C)
        EVT_CASE_EQ(7)
            EVT_EXEC_WAIT(battle_partner_goombario_80239988)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80239784) = {
    EVT_SET_CONST(EVT_VAR(0), 0x1)
    EVT_SET_CONST(EVT_VAR(1), 0x90010)
    EVT_SET_CONST(EVT_VAR(2), 0x90011)
    EVT_SET_CONST(EVT_VAR(3), 0x90001)
    EVT_EXEC_WAIT(0x80294720)
    EVT_RETURN
    EVT_END
};

EvtSource N(802397E0) = {
    EVT_CALL(GetMenuSelection, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(SetBattleFlagBits, 16384, 0)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(EVT_VAR(0))
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_CALL(LoadItemScript)
            EVT_EXEC_WAIT(EVT_VAR(0))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SWITCH(EVT_VAR(2))
        EVT_CASE_EQ(131)
            EVT_EXEC_WAIT(battle_partner_goombario_8023A754)
        EVT_CASE_EQ(132)
            EVT_EXEC_WAIT(battle_partner_goombario_8023ADC4)
        EVT_CASE_EQ(133)
            EVT_EXEC_WAIT(battle_partner_goombario_8023B45C)
        EVT_CASE_EQ(134)
            EVT_EXEC_WAIT(battle_partner_goombario_8023C5B8)
        EVT_CASE_EQ(135)
            EVT_EXEC_WAIT(battle_partner_goombario_8023C90C)
        EVT_CASE_EQ(136)
            EVT_EXEC_WAIT(battle_partner_goombario_8023BB9C)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(8023993C) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(8023994C) = {
    EVT_SET_CONST(EVT_VAR(0), 0x1)
    EVT_SET_CONST(EVT_VAR(1), 0x90003)
    EVT_EXEC_WAIT(0x80294AFC)
    EVT_RETURN
    EVT_END
};

EvtSource N(80239988) = {
    EVT_CALL(UseIdleAnimation, 256, 0)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FIXED(6.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(SetActorYaw, 256, 0)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(UseIdleAnimation, 256, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(nextTurn_80239A3C) = {
    EVT_CALL(GetBattlePhase, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(10)
            EVT_IF_EQ(EVT_SAVE_FLAG(1817), 0)
                EVT_CALL(UseIdleAnimation, 256, 0)
                EVT_CALL(UseBattleCamPreset, 14)
                EVT_CALL(BattleCamTargetActor, -127)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetActorYaw, 0, 30)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 60)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 90)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 120)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 150)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 180)
                EVT_WAIT_FRAMES(5)
                EVT_CALL(ActorSpeak, 721082, 256, 0, 589839, 589825)
                EVT_CALL(SetActorYaw, 0, 150)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 120)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 90)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 60)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 30)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorYaw, 0, 0)
                EVT_WAIT_FRAMES(5)
                EVT_SET(EVT_SAVE_FLAG(1817), 1)
                EVT_CALL(UseIdleAnimation, 256, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80239CA8) = {
    EVT_CALL(func_80280818)
    EVT_CALL(UseBattleCamPreset, 51)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
        EVT_SET(EVT_VAR(0), 180)
        EVT_LOOP(3)
            EVT_ADD(EVT_VAR(0), 60)
            EVT_CALL(SetActorRotation, -127, 0, 0, EVT_VAR(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, -127, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 30)
    EVT_SET(EVT_VAR(1), 0)
    EVT_CALL(SetGoalPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetActorJumpGravity, 256, EVT_FIXED(1.2001953125))
    EVT_CALL(battle_partner_goombario_func_80238000_6F10E0)
    EVT_CALL(JumpToGoal, 256, EVT_VAR(0), 0, 1, 0)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorRotation, -127, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(AddGoalPos, 256, -10, 0, 0)
    EVT_CALL(JumpToGoal, 256, 6, 0, 0, 1)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, -127, 1, 589825)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FIXED(8.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtSource N(8023A06C) = {
    EVT_CALL(func_80280818)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(GetGoalPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 60)
    EVT_CALL(SetGoalPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetActorJumpGravity, 256, EVT_FIXED(1.400390625))
    EVT_CALL(battle_partner_goombario_func_80238000_6F10E0)
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
        EVT_SUB(EVT_VAR(0), 4)
        EVT_SET(EVT_VAR(1), EVT_VAR(0))
        EVT_DIV(EVT_VAR(1), 3)
        EVT_IF_LT(EVT_VAR(1), 1)
            EVT_SET(EVT_VAR(1), 1)
        EVT_END_IF
        EVT_SET(EVT_VAR(2), EVT_VAR(1))
        EVT_MOD(EVT_VAR(2), 2)
        EVT_IF_EQ(EVT_VAR(2), 0)
            EVT_SUB(EVT_VAR(1), 1)
        EVT_END_IF
        EVT_SET(EVT_VAR(0), 180)
        EVT_LOOP(EVT_VAR(1))
            EVT_LOOP(3)
                EVT_ADD(EVT_VAR(0), 60)
                EVT_CALL(SetActorRotation, -127, 0, 0, EVT_VAR(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, -127, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, 256, EVT_VAR(0), 0, 1, 0)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorRotation, -127, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(AddGoalPos, 256, -20, 0, 0)
    EVT_CALL(JumpToGoal, 256, 6, 0, 0, 1)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(AddGoalPos, 256, -10, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(JumpToGoal, 256, 4, 0, 0, 1)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FIXED(8.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtSource N(8023A52C) = {
    EVT_CALL(SetGoalToFirstTarget, -127)
    EVT_CALL(GetGoalPos, -127, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 40)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(GetGoalPos, 256, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_SUB(EVT_VAR(3), EVT_FIXED(70.0))
    EVT_IF_LT(EVT_VAR(0), EVT_VAR(3))
        EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_END_IF
    EVT_CALL(SetGoalPos, 256, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(UseBattleCamPreset, 47)
    EVT_CALL(SetActorSpeed, 256, EVT_FIXED(5.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtSource N(8023A66C) = {
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(GetGoalPos, 256, EVT_VAR(11), EVT_VAR(7), EVT_VAR(13))
    EVT_CALL(GetActorPos, 256, EVT_VAR(7), EVT_VAR(13), EVT_VAR(14))
    EVT_IF_GT(EVT_VAR(11), EVT_VAR(7))
        EVT_SUB(EVT_VAR(11), EVT_VAR(7))
    EVT_ELSE
        EVT_SUB(EVT_VAR(7), EVT_VAR(11))
        EVT_SET(EVT_VAR(11), EVT_VAR(7))
    EVT_END_IF
    EVT_SUB(EVT_VAR(11), 20)
    EVT_DIVF(EVT_VAR(11), EVT_FIXED(10.5888671875))
    EVT_ADDF(EVT_VAR(11), 15)
    EVT_SET(EVT_VAR(10), EVT_VAR(11))
    EVT_RETURN
    EVT_END
};

EvtSource N(8023A754) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 3)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 0)
    EVT_CALL(PartnerTestEnemy, EVT_VAR(0), 128, 20, 0, 1, 16)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT_FRAMES(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionCommandResult, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(EVT_VAR(0), 1)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(EVT_VAR(0), 1)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, 50)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, 53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, EVT_VAR(15))
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(EVT_VAR(10), 24)
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(6)
            EVT_ADD(EVT_VAR(0), -30)
            EVT_CALL(SetActorRotation, -127, 0, 0, EVT_VAR(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 3)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
    EVT_ADD(EVT_VAR(0), 1)
    EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 32)
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, EVT_VAR(15))
    EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
    EVT_RETURN
    EVT_END
};

EvtSource N(8023ADC4) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 3)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 0)
    EVT_CALL(PartnerTestEnemy, EVT_VAR(0), 128, 20, 0, 1, 16)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT_FRAMES(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionCommandResult, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(EVT_VAR(0), 2)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(EVT_VAR(0), 2)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, 50)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, 53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, EVT_VAR(15))
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(EVT_VAR(10), 24)
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(6)
            EVT_ADD(EVT_VAR(0), -30)
            EVT_CALL(SetActorRotation, -127, 0, 0, EVT_VAR(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(EnableActorBlur, 256, 1)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 3)
    EVT_CALL(EnableActorBlur, 256, -1)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
    EVT_ADD(EVT_VAR(0), 2)
    EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 32)
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, EVT_VAR(15))
    EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
    EVT_RETURN
    EVT_END
};

EvtSource N(8023B45C) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 3)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 0)
    EVT_CALL(PartnerTestEnemy, EVT_VAR(0), 128, 20, 0, 1, 16)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT_FRAMES(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionCommandResult, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(EVT_VAR(0), 3)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(EVT_VAR(0), 3)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, 50)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, 53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, EVT_VAR(15))
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(EVT_VAR(10), 24)
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(6)
            EVT_ADD(EVT_VAR(0), -30)
            EVT_CALL(SetActorRotation, -127, 0, -250000000, EVT_VAR(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(EVT_VAR(10))
            EVT_ADD(EVT_VAR(0), 133)
            EVT_CALL(SetActorRotation, -127, -250000000, EVT_VAR(0), -250000000)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(EnableActorBlur, 256, 1)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 3)
    EVT_CALL(EnableActorBlur, 256, -1)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
    EVT_ADD(EVT_VAR(0), 3)
    EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 32)
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, EVT_VAR(15))
    EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
    EVT_RETURN
    EVT_END
};

s32 N(D_8023BB78_6ECC58)[] = {
    0x00000007, 0x00000006, 0x00000005, 0x00000004, 0x00000003, 0x00000002, 0x00000001, 0x00000000,
};

s32 D_8023BB98_6ECC78 = 0x000000C8;

EvtSource N(8023BB9C) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 1)
    EVT_CALL(UseBattleCamPreset, 52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 0)
    EVT_CALL(PartnerTestEnemy, EVT_VAR(0), 1048704, 20, 0, 1, 16)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT_FRAMES(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionCommandResult, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(EVT_VAR(0), 3)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(EVT_VAR(0), 3)
            EVT_CALL(PartnerDamageEnemy, EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, 50)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, 53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, EVT_VAR(15))
    EVT_SET(EVT_VAR(13), 0)
    EVT_SET(EVT_VAR(15), 0)
    EVT_SET(EVT_FLAG(0), 0)
    EVT_LABEL(10)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, 50)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, 53)
    EVT_END_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(func_8026919C, EVT_PTR(battle_partner_goombario_D_8023BB78_6ECC58))
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(func_802A9000_430020)
    EVT_SET(EVT_VAR(10), 24)
    EVT_SWITCH(EVT_VAR(15))
        EVT_CASE_EQ(0)
            EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 2)
        EVT_CASE_EQ(2)
            EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 3)
        EVT_CASE_EQ(3)
            EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 4)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A9120_421B10, EVT_VAR(10), 5)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(6)
            EVT_ADD(EVT_VAR(0), -30)
            EVT_CALL(SetActorRotation, -127, 0, -250000000, EVT_VAR(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 0)
        EVT_LOOP(EVT_VAR(10))
            EVT_ADD(EVT_VAR(0), 133)
            EVT_CALL(SetActorRotation, -127, -250000000, EVT_VAR(0), -250000000)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(EnableActorBlur, 256, 1)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, EVT_VAR(10), 3)
    EVT_CALL(EnableActorBlur, 256, -1)
    EVT_SUB(EVT_VAR(13), 1)
    EVT_CALL(func_802380E4_6F11C4)
    EVT_IF_GE(EVT_VAR(15), EVT_VAR(0))
        EVT_SET(EVT_FLAG(0), 1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.1005859375), EVT_FIXED(0.80078125), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.30078125), EVT_FIXED(0.5), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, 256, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionCommandResult, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(EVT_FLAG(0), 0)
                EVT_CALL(battle_partner_goombario_IsGlowing)
                EVT_ADD(EVT_VAR(0), 3)
                EVT_CALL(PartnerPowerBounceEnemy, EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), EVT_VAR(13), 64)
            EVT_ELSE
                EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
                EVT_ADD(EVT_VAR(0), 3)
                EVT_CALL(PartnerPowerBounceEnemy, EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), EVT_VAR(13), 32)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(EVT_VAR(0), 3)
            EVT_CALL(PartnerPowerBounceEnemy, EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), EVT_VAR(13), 32)
            EVT_SET(EVT_FLAG(0), 0)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, EVT_VAR(14))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(EVT_FLAG(0), 1)
                EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(EVT_VAR(15), 1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(8023C5B8) = {
    EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 30)
    EVT_CALL(SetActorSpeed, 256, EVT_FIXED(6.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(SetGoalPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(RunToGoal, 256, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetBattleFlagBits, 4, 1)
    EVT_CALL(func_80238E04_6F1EE4)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetCamEnabled, 2, 1)
    EVT_CALL(SetCamFlag80, 2, 0)
    EVT_CALL(SetCamPerspective, 2, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, 2, 137, 95, 138, 99)
    EVT_CALL(GetOwnerTarget, EVT_VAR(10), EVT_VAR(11))
    EVT_CALL(GetActorPos, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetGoalPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_80238BCC_6F1CAC)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(func_802CAE50, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_802CABE8, 2, 0, EVT_VAR(3), 100, 4)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(PlaySoundAtActor, 256, 642)
    EVT_CALL(SetCamFlag80, 2, 1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_80238B60_6F1C40)
    EVT_CALL(ActorSpeak, EVT_VAR(0), -127, 1, 589839, 589825)
    EVT_CALL(func_80238E48_6F1F28)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetCamEnabled, 2, 0)
    EVT_WAIT_FRAMES(32)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(SetBattleFlagBits, 4, 0)
    EVT_CALL(func_80280818)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FIXED(4.0))
    EVT_CALL(SetActorJumpGravity, 256, EVT_FIXED(1.80078125))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtSource N(8023C90C) = {
    EVT_CALL(UseBattleCamPreset, 55)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, 256, -1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 15)
    EVT_CALL(PlaySoundAtActor, 256, 8335)
    EVT_CALL(func_802390C8_6F21A8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(1.2001953125))
    EVT_WAIT_FRAMES(3)
    EVT_CALL(func_802390C8_6F21A8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(0.80078125))
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 15)
        EVT_ADD(EVT_VAR(2), -5)
        EVT_CALL(PlaySoundAtActor, 256, 8195)
        EVT_CALL(PlayEffect, 82, 9, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(2.0), 20, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetActorDispOffset, 256, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(func_80238E74_6F1F54)
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 10)
        EVT_ADD(EVT_VAR(1), 25)
        EVT_ADD(EVT_VAR(2), 5)
        EVT_CALL(PlaySoundAtActor, 256, 8334)
        EVT_CALL(func_80238EDC_6F1FBC, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_WAIT_FRAMES(4)
        EVT_CALL(SetActorJumpGravity, 256, EVT_FIXED(1.400390625))
        EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(SetJumpAnimations, 256, 589828, 1, 589828, 589828)
        EVT_CALL(SetGoalPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(JumpToGoal, 256, 20, 1, 1, 0)
        EVT_CALL(SetAnimation, 256, -1, 589825)
        EVT_CALL(GetMenuSelection, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_SWITCH(EVT_VAR(2))
            EVT_CASE_EQ(134)
                EVT_CALL(ShowMessageBox, 36, 60)
            EVT_CASE_EQ(135)
                EVT_CALL(battle_partner_goombario_func_80239190_6F2270)
                EVT_CALL(ShowMessageBox, EVT_VAR(0), 60)
            EVT_CASE_EQ(136)
                EVT_CALL(ShowMessageBox, 36, 60)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageBox, 8, 60)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(IsMessageBoxDisplayed, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
