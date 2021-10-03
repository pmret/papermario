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
extern MessageID bActorTattles[ACTOR_TYPE_COUNT];

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
    MessageID* tattle = &bActorTattles[targetActor->actorType];

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

    effect->data->pos.y = 144.0f;
    effect->flags |= 0x10;

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
        .eventFlags = 0,
        .elementImmunityFlags = 0,
    },
};

EvtSource N(init_802392F0);

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

EvtSource N(init_802392F0) = SCRIPT({
    BindTakeTurn(ACTOR_PARTNER, N(takeTurn_802396D8));
    BindIdle(ACTOR_PARTNER, N(idle_80239350));
    BindHandleEvent(ACTOR_PARTNER, N(handleEvent_80239360));
    BindNextTurn(256, N(nextTurn_80239A3C));
});

EvtSource N(idle_80239350) = SCRIPT({

});

EvtSource N(handleEvent_80239360) = SCRIPT({
    UseIdleAnimation(ACTOR_PARTNER, FALSE);
    CloseActionCommandInfo();
    GetLastEvent(ACTOR_PARTNER, EVT_VAR(0));
    match EVT_VAR(0) {
        EVENT_HIT_COMBO, EVENT_HIT {
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            EVT_VAR(2) = (const) NPC_ANIM_battle_goombario_default_pain;
            await 0x802977BC;
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            await 0x80296014;
        }
        23, EVENT_IMMUNE {
            PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208C);
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            await 0x80297814;
        }
        == EVENT_SPIKE_CONTACT {
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            EVT_VAR(2) = 12;
            await 0x80294FE4;
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            await 0x80296014;
        }
        == EVENT_BURN_CONTACT {
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_burn_pain;
            EVT_VAR(2) = 12;
            EVT_VAR(3) = (const) NPC_ANIM_battle_goombario_default_burn_dead;
            await 0x80294C68;
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            await 0x80296014;
        }
        == EVENT_BURN_HIT {
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_burn_pain;
            EVT_VAR(2) = (const) NPC_ANIM_battle_goombario_default_burn_dead;
            await 0x8029621C;
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            await 0x80296014;
        }
        == EVENT_SHOCK_HIT {
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            EVT_VAR(2) = 12;
            await 0x80295744;
        }
        == 51 {
            N(StopGlowing)();
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_pain;
            await 0x80296014;
        }
        == 52 {
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_idle;
            EVT_VAR(2) = (const) NPC_ANIM_battle_goombario_default_run;
            EVT_VAR(3) = 0;
            await 0x80295EC4;
        }
        24, EVENT_BLOCK {
            PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208C);
            EVT_VAR(0) = (const) 1;
            EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_block;
            await 0x80297814;
            sleep 10;
        }
        else {
        }
    }
    UseIdleAnimation(ACTOR_PARTNER, TRUE);
});

EvtSource N(takeTurn_802396D8) = SCRIPT({
    GetBattlePhase(EVT_VAR(0));
    match EVT_VAR(0) {
        == 1 {
            await N(8023993C);
        }
        == HIT_RESULT_HIT {
            await N(802397E0);
        }
        == HIT_RESULT_LUCKY {
            await N(80239784);
        }
        == 3 {
            await N(8023994C);
        }
        == HIT_RESULT_HIT_STATIC {
            await N(80239988);
        }
    }
});

EvtSource N(80239784) = SCRIPT({
    EVT_VAR(0) = (const) 1;
    EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_celebrate;
    EVT_VAR(2) = (const) NPC_ANIM_battle_goombario_default_celebrate_still;
    EVT_VAR(3) = (const) NPC_ANIM_battle_goombario_default_idle;
    await 0x80294720;
});

EvtSource N(802397E0) = SCRIPT({
    GetMenuSelection(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    func_802694A4(1);
    SetBattleFlagBits(16384, 0);
    match EVT_VAR(0) {
        == 8 {
            LoadStarPowerScript();
            await 0xFE363C80;
            return;
        }
        == 2 {
            LoadItemScript();
            await 0xFE363C80;
            return;
        }
    }
    match EVT_VAR(2) {
        == 131 {
            await N(8023A754);
        }
        == 132 {
            await N(8023ADC4);
        }
        == 133 {
            await N(8023B45C);
        }
        == 134 {
            await N(8023C5B8);
        }
        == 135 {
            await N(8023C90C);
        }
        == 136 {
            await N(8023BB9C);
        }
    }
});

EvtSource N(8023993C) = SCRIPT({

});

EvtSource N(8023994C) = SCRIPT({
    EVT_VAR(0) = (const) 1;
    EVT_VAR(1) = (const) NPC_ANIM_battle_goombario_default_run;
    await 0x80294AFC;
});

EvtSource N(80239988) = SCRIPT({
    UseIdleAnimation(ACTOR_PARTNER, FALSE);
    SetGoalToHome(ACTOR_PARTNER);
    SetActorSpeed(ACTOR_PARTNER, 6.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_run);
    SetActorYaw(ACTOR_PARTNER, 0);
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    UseIdleAnimation(ACTOR_PARTNER, 1);
});

EvtSource N(nextTurn_80239A3C) = SCRIPT({
    GetBattlePhase(EVT_VAR(0));
    match EVT_VAR(0) {
        == 10 {
            if (EVT_SAVE_FLAG(1817) == 0) {
                UseIdleAnimation(ACTOR_PARTNER, 0);
                UseBattleCamPreset(14);
                BattleCamTargetActor(ACTOR_SELF);
                MoveBattleCamOver(20);
                sleep 10;
                SetActorYaw(ACTOR_PLAYER, 30);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 60);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 90);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 120);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 150);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 180);
                sleep 5;
                ActorSpeak(721082, 256, 0, 589839, 589825);
                SetActorYaw(ACTOR_PLAYER, 150);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 120);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 90);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 60);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 30);
                sleep 1;
                SetActorYaw(ACTOR_PLAYER, 0);
                sleep 5;
                EVT_SAVE_FLAG(1817) = 1;
                UseIdleAnimation(ACTOR_PARTNER, 1);
            }
        }
    }
});

EvtSource N(80239CA8) = SCRIPT({
    func_80280818();
    UseBattleCamPreset(51);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    spawn {
        sleep 4;
        SetActorRotationOffset(-127, 0, 12, 0);
        EVT_VAR(0) = 180;
        loop 3 {
            EVT_VAR(0) += 60;
            SetActorRotation(ACTOR_SELF, 0, 0, EVT_VAR(0));
            sleep 1;
        }
        SetActorRotation(ACTOR_SELF, 0, 0, 0);
        SetActorRotationOffset(-127, 0, 0, 0);
    }
    GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) -= 30;
    EVT_VAR(1) = 0;
    SetGoalPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetActorJumpGravity(ACTOR_PARTNER, 1.2);
    N(func_80238000_6F10E0)();
    JumpToGoal(ACTOR_PARTNER, EVT_VAR(0), FALSE, TRUE, FALSE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    SetActorRotation(ACTOR_SELF, 0, 0, 0);
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    AddGoalPos(ACTOR_PARTNER, -10, 0, 0);
    JumpToGoal(ACTOR_PARTNER, 6, FALSE, FALSE, TRUE);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle);
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    sleep 2;
    SetGoalToHome(ACTOR_PARTNER);
    SetActorSpeed(ACTOR_PARTNER, 8.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_run);
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
});

EvtSource N(8023A06C) = SCRIPT({
    func_80280818();
    UseBattleCamPreset(3);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    SetGoalToHome(ACTOR_PARTNER);
    GetGoalPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 60;
    SetGoalPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetActorJumpGravity(ACTOR_PARTNER, 1.4);
    N(func_80238000_6F10E0)();
    spawn {
        sleep 4;
        SetActorRotationOffset(-127, 0, 12, 0);
        EVT_VAR(0) -= 4;
        EVT_VAR(1) = EVT_VAR(0);
        EVT_VAR(1) /= 3;
        if (EVT_VAR(1) < 1) {
            EVT_VAR(1) = 1;
        }
        EVT_VAR(2) = EVT_VAR(1);
        EVT_VAR(2) %= 2;
        if (EVT_VAR(2) == 0) {
            EVT_VAR(1) -= 1;
        }
        EVT_VAR(0) = 180;
        loop EVT_VAR(1) {
            loop 3 {
                EVT_VAR(0) += 60;
                SetActorRotation(ACTOR_SELF, 0, 0, EVT_VAR(0));
                sleep 1;
            }
        }
        SetActorRotation(ACTOR_SELF, 0, 0, 0);
        SetActorRotationOffset(-127, 0, 0, 0);
    }
    JumpToGoal(ACTOR_PARTNER, EVT_VAR(0), FALSE, TRUE, FALSE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorRotation(ACTOR_SELF, 0, 0, 0);
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    AddGoalPos(ACTOR_PARTNER, -20, 0, 0);
    JumpToGoal(ACTOR_PARTNER, 6, FALSE, FALSE, TRUE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    AddGoalPos(ACTOR_PARTNER, -10, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    JumpToGoal(ACTOR_PARTNER, 4, FALSE, FALSE, TRUE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    sleep 2;
    SetGoalToHome(ACTOR_PARTNER);
    SetActorSpeed(ACTOR_PARTNER, 8.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_run);
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
});

EvtSource N(8023A52C) = SCRIPT({
    SetGoalToFirstTarget(-127);
    GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) -= 40;
    InitTargetIterator();
    SetGoalToTarget(ACTOR_PARTNER);
    GetGoalPos(ACTOR_PARTNER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
    EVT_VAR(3) -= (int) 70.0;
    if (EVT_VAR(0) < EVT_VAR(3)) {
        EVT_VAR(3) = EVT_VAR(0);
    }
    SetGoalPos(ACTOR_PARTNER, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
    UseBattleCamPreset(47);
    SetActorSpeed(ACTOR_PARTNER, 5.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_run);
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
});

EvtSource N(8023A66C) = SCRIPT({
    SetGoalToTarget(ACTOR_PARTNER);
    GetGoalPos(ACTOR_PARTNER, EVT_VAR(11), EVT_VAR(7), EVT_VAR(13));
    GetActorPos(ACTOR_PARTNER, EVT_VAR(7), EVT_VAR(13), EVT_VAR(14));
    if (EVT_VAR(11) > EVT_VAR(7)) {
        EVT_VAR(11) -= EVT_VAR(7);
    } else {
        EVT_VAR(7) -= EVT_VAR(11);
        EVT_VAR(11) = EVT_VAR(7);
    }
    EVT_VAR(11) -= 20;
    EVT_VAR(11) /= 10.5888671875;
    EVT_VAR(11) += (float) 15;
    EVT_VAR(10) = EVT_VAR(11);
});

EvtSource N(8023A754) = SCRIPT({
    LoadActionCommand(1);
    func_802A9000_430020();
    await N(8023A52C);
    await N(8023A66C);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 5;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    UseBattleCamPreset(52);
    func_802A9120_421B10(EVT_VAR(10), 3);
    UseBattleCamPreset(52);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk);
    SetActorDispOffset(ACTOR_PARTNER, 0, 9, 0);
    SetGoalToTarget(ACTOR_PARTNER);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_200D);
    func_8023817C_6F125C(EVT_VAR(10), 0);
    PartnerTestEnemy(EVT_VAR(0), 128, 20, 0, 1, 16);
    if (EVT_VAR(0) == 6) {
        SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
        N(func_80238A20_6F1B00)();
        spawn {
            ShakeCam(1, 0, 5, 1.0);
        }
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_162);
        sleep 20;
        await N(80239CA8);
        return;
    }
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    GetActionCommandResult(EVT_VAR(0));
    match EVT_VAR(0) {
        > 0 {
            N(IsGlowing)();
            EVT_VAR(0) += 1;
            PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 80);
        }
        else {
            N(StopGlowingAndGet)();
            EVT_VAR(0) += 1;
            PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 48);
        }
    }
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    match EVT_VAR(0) {
        0, 2 {
            await N(80239CA8);
            return;
        }
        1, 3 {}
    }
    spawn {
        UseBattleCamPreset(50);
        sleep 5;
        SetGoalToTarget(ACTOR_PARTNER);
        UseBattleCamPreset(53);
    }
    func_80269524(EVT_VAR(15));
    CloseActionCommandInfo();
    LoadActionCommand(1);
    func_802A9000_430020();
    func_802694A4(0);
    func_802A9120_421B10(24, 3);
    EVT_VAR(10) = 24;
    spawn {
        sleep 4;
        EVT_VAR(0) = 0;
        loop 6 {
            EVT_VAR(0) += -30;
            SetActorRotation(ACTOR_SELF, 0, 0, EVT_VAR(0));
            sleep 1;
        }
    }
    SetGoalToTarget(ACTOR_PARTNER);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, 0x281);
    func_8023817C_6F125C(EVT_VAR(10), 3);
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    N(StopGlowingAndGet)();
    EVT_VAR(0) += 1;
    PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 32);
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    func_80269550(EVT_VAR(15));
    await N(8023A06C);
});

EvtSource N(8023ADC4) = SCRIPT({
    LoadActionCommand(1);
    func_802A9000_430020();
    await N(8023A52C);
    await N(8023A66C);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 5;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    UseBattleCamPreset(52);
    func_802A9120_421B10(EVT_VAR(10), 3);
    UseBattleCamPreset(52);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk);
    SetActorDispOffset(ACTOR_PARTNER, 0, 9, 0);
    SetGoalToTarget(ACTOR_PARTNER);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_200D);
    func_8023817C_6F125C(EVT_VAR(10), 0);
    PartnerTestEnemy(EVT_VAR(0), 128, 20, 0, 1, 16);
    if (EVT_VAR(0) == 6) {
        SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
        N(func_80238A20_6F1B00)();
        spawn {
            ShakeCam(1, 0, 5, 1.0);
        }
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_162);
        sleep 20;
        await N(80239CA8);
        return;
    }
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    GetActionCommandResult(EVT_VAR(0));
    match EVT_VAR(0) {
        > 0 {
            N(IsGlowing)();
            EVT_VAR(0) += 2;
            PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 80);
        }
        else {
            N(StopGlowingAndGet)();
            EVT_VAR(0) += 2;
            PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 48);
        }
    }
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    match EVT_VAR(0) {
        0, 2 {
            await N(80239CA8);
            return;
        }
        1, 3 {}
    }
    spawn {
        UseBattleCamPreset(50);
        sleep 5;
        SetGoalToTarget(ACTOR_PARTNER);
        UseBattleCamPreset(53);
    }
    func_80269524(EVT_VAR(15));
    CloseActionCommandInfo();
    LoadActionCommand(1);
    func_802A9000_430020();
    func_802694A4(0);
    func_802A9120_421B10(24, 3);
    EVT_VAR(10) = 24;
    spawn {
        sleep 4;
        EVT_VAR(0) = 0;
        loop 6 {
            EVT_VAR(0) += -30;
            SetActorRotation(ACTOR_SELF, 0, 0, EVT_VAR(0));
            sleep 1;
        }
    }
    SetGoalToTarget(ACTOR_PARTNER);
    EnableActorBlur(256, 1);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, 0x281);
    func_8023817C_6F125C(EVT_VAR(10), 3);
    EnableActorBlur(256, -1);
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    N(StopGlowingAndGet)();
    EVT_VAR(0) += 2;
    PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 32);
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    func_80269550(EVT_VAR(15));
    await N(8023A06C);
});

EvtSource N(8023B45C) = SCRIPT({
    LoadActionCommand(1);
    func_802A9000_430020();
    await N(8023A52C);
    await N(8023A66C);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 5;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    UseBattleCamPreset(52);
    func_802A9120_421B10(EVT_VAR(10), 3);
    UseBattleCamPreset(52);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk);
    SetActorDispOffset(ACTOR_PARTNER, 0, 9, 0);
    SetGoalToTarget(ACTOR_PARTNER);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_200D);
    func_8023817C_6F125C(EVT_VAR(10), 0);
    PartnerTestEnemy(EVT_VAR(0), 128, 20, 0, 1, 16);
    if (EVT_VAR(0) == 6) {
        SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
        N(func_80238A20_6F1B00)();
        spawn {
            ShakeCam(1, 0, 5, 1.0);
        }
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_162);
        sleep 20;
        await N(80239CA8);
        return;
    }
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    GetActionCommandResult(EVT_VAR(0));
    match EVT_VAR(0) {
        > 0 {
            N(IsGlowing)();
            EVT_VAR(0) += 3;
            PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 80);
        }
        else {
            N(StopGlowingAndGet)();
            EVT_VAR(0) += 3;
            PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 48);
        }
    }
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    match EVT_VAR(0) {
        0, 2 {
            await N(80239CA8);
            return;
        }
        1, 3 {}
    }
    spawn {
        UseBattleCamPreset(50);
        sleep 5;
        SetGoalToTarget(ACTOR_PARTNER);
        UseBattleCamPreset(53);
    }
    func_80269524(EVT_VAR(15));
    CloseActionCommandInfo();
    LoadActionCommand(1);
    func_802A9000_430020();
    func_802694A4(0);
    func_802A9120_421B10(24, 3);
    EVT_VAR(10) = 24;
    spawn {
        sleep 4;
        EVT_VAR(0) = 0;
        loop 6 {
            EVT_VAR(0) += -30;
            SetActorRotation(ACTOR_SELF, 0, -250000000, EVT_VAR(0));
            sleep 1;
        }
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk);
    }
    spawn {
        EVT_VAR(0) = 0;
        loop EVT_VAR(10) {
            EVT_VAR(0) += 133;
            SetActorRotation(ACTOR_SELF, -250000000, EVT_VAR(0), -250000000);
            sleep 1;
        }
    }
    SetGoalToTarget(ACTOR_PARTNER);
    EnableActorBlur(256, 1);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, 0x281);
    func_8023817C_6F125C(EVT_VAR(10), 3);
    EnableActorBlur(256, -1);
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    N(StopGlowingAndGet)();
    EVT_VAR(0) += 3;
    PartnerDamageEnemy(EVT_VAR(0), 128, 0, 0, EVT_VAR(0), 32);
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    func_80269550(EVT_VAR(15));
    await N(8023A06C);
});

s32 N(D_8023BB78_6ECC58)[] = {
    0x00000007, 0x00000006, 0x00000005, 0x00000004, 0x00000003, 0x00000002, 0x00000001, 0x00000000,
};

s32 D_8023BB98_6ECC78 = 0x000000C8;

EvtSource N(8023BB9C) = SCRIPT({
    LoadActionCommand(1);
    func_802A9000_430020();
    await N(8023A52C);
    await N(8023A66C);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 5;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    UseBattleCamPreset(52);
    func_802A9120_421B10(EVT_VAR(10), 1);
    UseBattleCamPreset(52);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk);
    SetActorDispOffset(ACTOR_PARTNER, 0, 9, 0);
    SetGoalToTarget(ACTOR_PARTNER);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_200D);
    func_8023817C_6F125C(EVT_VAR(10), 0);
    PartnerTestEnemy(EVT_VAR(0), 1048704, 20, 0, 1, 16);
    if (EVT_VAR(0) == 6) {
        SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
        N(func_80238A20_6F1B00)();
        spawn {
            ShakeCam(1, 0, 5, 1.0);
        }
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_162);
        sleep 20;
        await N(80239CA8);
        return;
    }
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    GetActionCommandResult(EVT_VAR(0));
    match EVT_VAR(0) {
        > 0 {
            N(IsGlowing)();
            EVT_VAR(0) += 3;
            PartnerDamageEnemy(EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), 80);
        }
        else {
            N(StopGlowingAndGet)();
            EVT_VAR(0) += 3;
            PartnerDamageEnemy(EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), 48);
        }
    }
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    match EVT_VAR(0) {
        0, 2 {
            await N(80239CA8);
            return;
        }
        1, 3 {}
    }
    spawn {
        UseBattleCamPreset(50);
        sleep 5;
        SetGoalToTarget(ACTOR_PARTNER);
        UseBattleCamPreset(53);
    }
    func_80269524(EVT_VAR(15));
    EVT_VAR(13) = 0;
    EVT_VAR(15) = 0;
    EVT_FLAG(0) = 0;
10:
    spawn {
        UseBattleCamPreset(50);
        sleep 5;
        SetGoalToTarget(ACTOR_PARTNER);
        UseBattleCamPreset(53);
    }
    CloseActionCommandInfo();
    func_8026919C(N(D_8023BB78_6ECC58));
    LoadActionCommand(1);
    func_802A9000_430020();
    EVT_VAR(10) = 24;
    match EVT_VAR(15) {
        == 0 {
            func_802A9120_421B10(EVT_VAR(10), 1);
        }
        == 1 {
            func_802A9120_421B10(EVT_VAR(10), 2);
        }
        == 2 {
            func_802A9120_421B10(EVT_VAR(10), 3);
        }
        == 3 {
            func_802A9120_421B10(EVT_VAR(10), 4);
        }
        else {
            func_802A9120_421B10(EVT_VAR(10), 5);
        }
    }
    spawn {
        sleep 4;
        EVT_VAR(0) = 0;
        loop 6 {
            EVT_VAR(0) += -30;
            SetActorRotation(ACTOR_SELF, 0, -250000000, EVT_VAR(0));
            sleep 1;
        }
        SetAnimation(ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk);
    }
    spawn {
        EVT_VAR(0) = 0;
        loop EVT_VAR(10) {
            EVT_VAR(0) += 133;
            SetActorRotation(ACTOR_SELF, -250000000, EVT_VAR(0), -250000000);
            sleep 1;
        }
    }
    SetGoalToTarget(ACTOR_PARTNER);
    EnableActorBlur(256, 1);
    SetJumpAnimations(ACTOR_PARTNER, 0, ANIM_90006, ANIM_90006, ANIM_90006);
    PlaySoundAtActor(ACTOR_PARTNER, 0x281);
    func_8023817C_6F125C(EVT_VAR(10), 3);
    EnableActorBlur(256, -1);
    EVT_VAR(13) -= 1;
    func_802380E4_6F11C4();
    if (EVT_VAR(15) >= EVT_VAR(0)) {
        EVT_FLAG(0) = 1;
    }
    parallel {
        SetActorScale(ACTOR_PARTNER, 1.1, 0.8, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.3, 0.5, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    sleep 1;
    GetActionCommandResult(EVT_VAR(0));
    match EVT_VAR(0) {
        > 0 {
            if (EVT_FLAG(0) == 0) {
                N(IsGlowing)();
                EVT_VAR(0) += 3;
                PartnerPowerBounceEnemy(EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), EVT_VAR(13), 64);
            } else {
                N(StopGlowingAndGet)();
                EVT_VAR(0) += 3;
                PartnerPowerBounceEnemy(EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), EVT_VAR(13), 32);
            }
        }
        else {
            N(StopGlowingAndGet)();
            EVT_VAR(0) += 3;
            PartnerPowerBounceEnemy(EVT_VAR(0), 1048704, 0, 0, EVT_VAR(0), EVT_VAR(13), 32);
            EVT_FLAG(0) = 0;
        }
    }
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_0);
    func_80269550(EVT_VAR(14));
    match EVT_VAR(0) {
        0, 2 {
            await N(80239CA8);
            return;
        }
        1, 3 {
            if (EVT_FLAG(0) == 1) {
                await N(8023A06C);
                return;
            }
        }
    }
    EVT_VAR(15) += 1;
    goto 10;
});

EvtSource N(8023C5B8) = SCRIPT({
    GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 30;
    SetActorSpeed(ACTOR_PARTNER, 6.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_run);
    SetGoalPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    RunToGoal(ACTOR_PARTNER, 0, FALSE);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    InitTargetIterator();
    SetGoalToTarget(ACTOR_PARTNER);
    SetBattleFlagBits(4, 1);
    func_80238E04_6F1EE4();
    sleep 12;
    SetCamEnabled(2, 1);
    SetCamFlag80(2, 0);
    SetCamPerspective(2, 6, 25, 16, 1024);
    SetCamViewport(2, 137, 95, 138, 99);
    GetOwnerTarget(EVT_VAR(10), EVT_VAR(11));
    GetActorPos(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    SetGoalPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    func_80238BCC_6F1CAC();
    sleep 1;
    func_802CAE50(2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    func_802CABE8(2, 0, EVT_VAR(3), 100, 4);
    sleep 2;
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_282);
    SetCamFlag80(2, 1);
    sleep 10;
    func_80238B60_6F1C40();
    ActorSpeak(EVT_VAR(0), -127, 1, 589839, 589825);
    func_80238E48_6F1F28();
    sleep 12;
    SetCamEnabled(2, 0);
    sleep 32;
    UseBattleCamPreset(2);
    SetBattleFlagBits(4, 0);
    func_80280818();
    SetGoalToHome(ACTOR_PARTNER);
    SetActorSpeed(ACTOR_PARTNER, 4.0);
    SetActorJumpGravity(ACTOR_PARTNER, 1.80078125);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_run);
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
});

EvtSource N(8023C90C) = SCRIPT({
    UseBattleCamPreset(55);
    sleep 10;
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_charge);
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) += 15;
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208F);
    func_802390C8_6F21A8(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1.2);
    sleep 3;
    func_802390C8_6F21A8(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0.8);
    spawn {
        sleep 15;
        GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(1) += 15;
        EVT_VAR(2) += -5;
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_2003);
        PlayEffect(0x52, 9, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 2.0, 20, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep 30;
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
    SetActorDispOffset(ACTOR_PARTNER, 0, 0, 0);
    UseBattleCamPreset(2);
    MoveBattleCamOver(10);
    func_80238E74_6F1F54();
    if (EVT_VAR(0) == 0) {
        GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(0) += 10;
        EVT_VAR(1) += 25;
        EVT_VAR(2) += 5;
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208E);
        func_80238EDC_6F1FBC(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        sleep 4;
        SetActorJumpGravity(ACTOR_PARTNER, 1.4);
        GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        SetJumpAnimations(ACTOR_PARTNER, 589828, ANIM_1, ANIM_90004, ANIM_90004);
        SetGoalPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        JumpToGoal(ACTOR_PARTNER, 20, 1, 1, 0);
        SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM_battle_goombario_default_idle);
        GetMenuSelection(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        match EVT_VAR(2) {
            == 134 {
                ShowMessageBox(36, 60);
            }
            == 135 {
                N(func_80239190_6F2270)();
                ShowMessageBox(EVT_VAR(0), 60);
            }
            == 136 {
                ShowMessageBox(36, 60);
            }
        }
    } else {
        ShowMessageBox(8, 60);
    }
0:
    sleep 1;
    IsMessageBoxDisplayed(EVT_VAR(0));
    if (EVT_VAR(0) == 1) {
        goto 0;
    }
});
