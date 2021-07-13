#define NAMESPACE battle_partner_goombario

#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/battle_goombario.h"

extern Actor D_8023CDA0;
extern s32 D_8023CDA4;
extern MessageID bActorTattles[ACTOR_TYPE_COUNT];

extern Script N(init);
extern Script N(80239784);
extern Script N(802397E0);
extern Script N(8023993C);
extern Script N(8023994C);
extern Script N(80239988);
extern Script N(8023A754);
extern Script N(8023ADC4);
extern Script N(8023B45C);
extern Script N(8023BB9C);
extern Script N(8023C5B8);
extern Script N(8023C90C);
extern Script N(handleEvent_80239360);
extern Script N(idle_80239350);
extern Script N(nextTurn_80239A3C);
extern Script N(takeTurn_802396D8);

ApiStatus N(func_80238000_6F10E0)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 posX = partnerActor->currentPos.x;
    f32 posY = partnerActor->currentPos.y;
    f32 posZ = partnerActor->currentPos.z;
    f32 goalX = partnerActor->walk.goalPos.x;
    f32 goalY = partnerActor->walk.goalPos.y;
    f32 goalZ = partnerActor->walk.goalPos.z;

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

INCLUDE_ASM(s32, "battle/partner/goombario", func_802380E4_6F11C4);

INCLUDE_ASM(s32, "battle/partner/goombario", func_8023817C_6F125C);

ApiStatus N(func_80238A20_6F1B00)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = gBattleStatus.partnerActor;
    Vec3f* pos = &partnerActor->walk.currentPos;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        partnerActor->walk.currentPos.x = partnerActor->currentPos.x;
        partnerActor->walk.currentPos.y = partnerActor->currentPos.y;
        partnerActor->walk.currentPos.z = partnerActor->currentPos.z;
        script->functionTemp[0].s = 1;
    }

    if (partnerActor->walk.velocity > 0.0f) {
        set_animation(0x100, 0, partnerActor->walk.animJumpRise);
    }

    if (partnerActor->walk.velocity < 0.0f) {
        set_animation(0x100, 0, partnerActor->walk.animJumpFall);
    }

    partnerActor->walk.currentPos.y = (partnerActor->walk.currentPos.y + partnerActor->walk.velocity);
    partnerActor->walk.velocity = (partnerActor->walk.velocity - partnerActor->walk.acceleration);
    add_xz_vec3f(pos, partnerActor->walk.speed, partnerActor->walk.angle);
    partnerActor->currentPos.x = partnerActor->walk.currentPos.x;
    partnerActor->currentPos.y = partnerActor->walk.currentPos.y;
    partnerActor->currentPos.z = partnerActor->walk.currentPos.z;

    if (partnerActor->currentPos.y < 10.0f) {
        partnerActor->currentPos.y = 10.0f;

        play_movement_dust_effects(2, partnerActor->currentPos.x, partnerActor->currentPos.y, partnerActor->currentPos.z,
                                   partnerActor->yaw);
        sfx_play_sound(SOUND_SOFT_LAND);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238B60_6F1C40(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "battle/partner/goombario", func_80238E04_6F1EE4);

INCLUDE_ASM(s32, "battle/partner/goombario", func_80238E48_6F1F28);

INCLUDE_ASM(s32, "battle/partner/goombario", func_80238E74_6F1F54);

INCLUDE_ASM(s32, "battle/partner/goombario", func_80238EDC_6F1FBC);

ApiStatus N(StopGlowing)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->partnerActor->isGlowing = FALSE;
    battleStatus->flags1 &= ~0x40000000;

    return ApiStatus_DONE2;
}

ApiStatus N(StopGlowingAndGet)(ScriptInstance* script, s32 isInitialCall) {
    Actor* partnerActor = gBattleStatus.partnerActor;

    if (!(gBattleStatus.flags1 & 0x40000000)) {
        partnerActor->isGlowing = FALSE;
    }

    script->varTable[0] = partnerActor->isGlowing;
    partnerActor->isGlowing = FALSE;
    gBattleStatus.flags1 &= ~0x40000000;

    return ApiStatus_DONE2;
}

ApiStatus N(IsGlowing)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    script->varTable[0] = battleStatus->partnerActor->isGlowing;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/goombario", func_802390C8_6F21A8);

ApiStatus N(func_80239190_6F2270)(ScriptInstance* script, s32 isInitialCall) {
    if (D_8023CDA4 == 0) {
        script->varTable[0] = 36;
    } else {
        script->varTable[0] = 37;
    }

    return ApiStatus_DONE2;
}

s32 N(idleAnimations_802391B0)[] = {
    STATUS_NORMAL,    NPC_ANIM(battle_goombario, default, walk),
    STATUS_STONE,     NPC_ANIM(battle_goombario, default, still),
    STATUS_SLEEP,     NPC_ANIM(battle_goombario, default, sleep),
    STATUS_POISON,    NPC_ANIM(battle_goombario, default, still),
    STATUS_STOP,      NPC_ANIM(battle_goombario, default, still),
    STATUS_DAZE,      NPC_ANIM(battle_goombario, default, daze),
    STATUS_TURN_DONE, NPC_ANIM(battle_goombario, default, still),
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

Script N(init_802392F0);

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

Script N(init_802392F0) = SCRIPT({
    BindTakeTurn(ACTOR_PARTNER, N(takeTurn_802396D8));
    BindIdle(ACTOR_PARTNER, N(idle_80239350));
    BindHandleEvent(ACTOR_PARTNER, N(handleEvent_80239360));
    BindNextTurn(256, N(nextTurn_80239A3C));
});

Script N(idle_80239350) = SCRIPT({

});

Script N(handleEvent_80239360) = SCRIPT({
    UseIdleAnimation(ACTOR_PARTNER, FALSE);
    CloseActionCommandInfo();
    GetLastEvent(ACTOR_PARTNER, SI_VAR(0));
    match SI_VAR(0) {
        EVENT_HIT_COMBO, EVENT_HIT {
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            SI_VAR(2) = (const) NPC_ANIM(battle_goombario, default, pain);
            await 0x802977BC;
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            await 0x80296014;
        }
        23, EVENT_IMMUNE {
            PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208C);
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            await 0x80297814;
        }
        == EVENT_SPIKE_CONTACT {
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            SI_VAR(2) = 12;
            await 0x80294FE4;
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            await 0x80296014;
        }
        == EVENT_BURN_CONTACT {
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, burn_pain);
            SI_VAR(2) = 12;
            SI_VAR(3) = (const) NPC_ANIM(battle_goombario, default, burn_dead);
            await 0x80294C68;
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            await 0x80296014;
        }
        == EVENT_BURN_HIT {
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, burn_pain);
            SI_VAR(2) = (const) NPC_ANIM(battle_goombario, default, burn_dead);
            await 0x8029621C;
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            await 0x80296014;
        }
        == EVENT_SHOCK_HIT {
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            SI_VAR(2) = 12;
            await 0x80295744;
        }
        == 51 {
            N(StopGlowing)();
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, pain);
            await 0x80296014;
        }
        == 52 {
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, idle);
            SI_VAR(2) = (const) NPC_ANIM(battle_goombario, default, run);
            SI_VAR(3) = 0;
            await 0x80295EC4;
        }
        24, EVENT_BLOCK {
            PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208C);
            SI_VAR(0) = (const) 1;
            SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, block);
            await 0x80297814;
            sleep 10;
        }
        else {
        }
    }
    UseIdleAnimation(ACTOR_PARTNER, TRUE);
});

Script N(takeTurn_802396D8) = SCRIPT({
    GetBattlePhase(SI_VAR(0));
    match SI_VAR(0) {
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

Script N(80239784) = SCRIPT({
    SI_VAR(0) = (const) 1;
    SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, celebrate);
    SI_VAR(2) = (const) NPC_ANIM(battle_goombario, default, celebrate_still);
    SI_VAR(3) = (const) NPC_ANIM(battle_goombario, default, idle);
    await 0x80294720;
});

Script N(802397E0) = SCRIPT({
    GetMenuSelection(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802694A4(1);
    SetBattleFlagBits(16384, 0);
    match SI_VAR(0) {
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
    match SI_VAR(2) {
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

Script N(8023993C) = SCRIPT({

});

Script N(8023994C) = SCRIPT({
    SI_VAR(0) = (const) 1;
    SI_VAR(1) = (const) NPC_ANIM(battle_goombario, default, run);
    await 0x80294AFC;
});

Script N(80239988) = SCRIPT({
    UseIdleAnimation(ACTOR_PARTNER, FALSE);
    SetGoalToHome(ACTOR_PARTNER);
    SetActorSpeed(ACTOR_PARTNER, 6.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, run));
    SetActorYaw(ACTOR_PARTNER, 0);
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    UseIdleAnimation(ACTOR_PARTNER, 1);
});

Script N(nextTurn_80239A3C) = SCRIPT({
    GetBattlePhase(SI_VAR(0));
    match SI_VAR(0) {
        == 10 {
            if (SI_SAVE_FLAG(1817) == 0) {
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
                SI_SAVE_FLAG(1817) = 1;
                UseIdleAnimation(ACTOR_PARTNER, 1);
            }
        }
    }
});

Script N(80239CA8) = SCRIPT({
    func_80280818();
    UseBattleCamPreset(51);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    spawn {
        sleep 4;
        SetActorRotationOffset(-127, 0, 12, 0);
        SI_VAR(0) = 180;
        loop 3 {
            SI_VAR(0) += 60;
            SetActorRotation(ACTOR_SELF, 0, 0, SI_VAR(0));
            sleep 1;
        }
        SetActorRotation(ACTOR_SELF, 0, 0, 0);
        SetActorRotationOffset(-127, 0, 0, 0);
    }
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 30;
    SI_VAR(1) = 0;
    SetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetActorJumpGravity(ACTOR_PARTNER, 1.2);
    N(func_80238000_6F10E0)();
    JumpToGoal(ACTOR_PARTNER, SI_VAR(0), FALSE, TRUE, FALSE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(battle_goombario, default, charge));
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    SetActorRotation(ACTOR_SELF, 0, 0, 0);
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    AddGoalPos(ACTOR_PARTNER, -10, 0, 0);
    JumpToGoal(ACTOR_PARTNER, 6, FALSE, FALSE, TRUE);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(battle_goombario, default, charge));
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    sleep 1;
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(battle_goombario, default, idle));
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    sleep 2;
    SetGoalToHome(ACTOR_PARTNER);
    SetActorSpeed(ACTOR_PARTNER, 8.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, run));
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
});

Script N(8023A06C) = SCRIPT({
    func_80280818();
    UseBattleCamPreset(3);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    SetGoalToHome(ACTOR_PARTNER);
    GetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 60;
    SetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetActorJumpGravity(ACTOR_PARTNER, 1.4);
    N(func_80238000_6F10E0)();
    spawn {
        sleep 4;
        SetActorRotationOffset(-127, 0, 12, 0);
        SI_VAR(0) -= 4;
        SI_VAR(1) = SI_VAR(0);
        SI_VAR(1) /= 3;
        if (SI_VAR(1) < 1) {
            SI_VAR(1) = 1;
        }
        SI_VAR(2) = SI_VAR(1);
        SI_VAR(2) %= 2;
        if (SI_VAR(2) == 0) {
            SI_VAR(1) -= 1;
        }
        SI_VAR(0) = 180;
        loop SI_VAR(1) {
            loop 3 {
                SI_VAR(0) += 60;
                SetActorRotation(ACTOR_SELF, 0, 0, SI_VAR(0));
                sleep 1;
            }
        }
        SetActorRotation(ACTOR_SELF, 0, 0, 0);
        SetActorRotationOffset(-127, 0, 0, 0);
    }
    JumpToGoal(ACTOR_PARTNER, SI_VAR(0), FALSE, TRUE, FALSE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(battle_goombario, default, charge));
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorRotation(ACTOR_SELF, 0, 0, 0);
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    AddGoalPos(ACTOR_PARTNER, -20, 0, 0);
    JumpToGoal(ACTOR_PARTNER, 6, FALSE, FALSE, TRUE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(battle_goombario, default, charge));
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    AddGoalPos(ACTOR_PARTNER, -10, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    JumpToGoal(ACTOR_PARTNER, 4, FALSE, FALSE, TRUE);
    SetAnimation(ACTOR_SELF, 1, NPC_ANIM(battle_goombario, default, charge));
    SetActorDispOffset(ACTOR_PARTNER, 0, 18, 0);
    sleep 1;
    SetActorDispOffset(ACTOR_SELF, 0, 0, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    sleep 2;
    SetGoalToHome(ACTOR_PARTNER);
    SetActorSpeed(ACTOR_PARTNER, 8.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, run));
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
});

Script N(8023A52C) = SCRIPT({
    SetGoalToFirstTarget(-127);
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 40;
    InitTargetIterator();
    SetGoalToTarget(ACTOR_PARTNER);
    GetGoalPos(ACTOR_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(3) -= (int) 70.0;
    if (SI_VAR(0) < SI_VAR(3)) {
        SI_VAR(3) = SI_VAR(0);
    }
    SetGoalPos(ACTOR_PARTNER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    UseBattleCamPreset(47);
    SetActorSpeed(ACTOR_PARTNER, 5.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, run));
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
});

Script N(8023A66C) = SCRIPT({
    SetGoalToTarget(ACTOR_PARTNER);
    GetGoalPos(ACTOR_PARTNER, SI_VAR(11), SI_VAR(7), SI_VAR(13));
    GetActorPos(ACTOR_PARTNER, SI_VAR(7), SI_VAR(13), SI_VAR(14));
    if (SI_VAR(11) > SI_VAR(7)) {
        SI_VAR(11) -= SI_VAR(7);
    } else {
        SI_VAR(7) -= SI_VAR(11);
        SI_VAR(11) = SI_VAR(7);
    }
    SI_VAR(11) -= 20;
    SI_VAR(11) /= 10.5888671875;
    SI_VAR(11) += (float) 15;
    SI_VAR(10) = SI_VAR(11);
});

// *INDENT-OFF*
Script N(8023A754) = {
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A52C)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A66C)),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589831),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 18, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 19, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 3),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589830),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 9, 0),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 8205),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 0),
    SI_CMD(ScriptOpcode_CALL, PartnerTestEnemy, SI_VAR(0), 128, 20, 0, 1, 16),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 6),
        SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
        SI_CMD(ScriptOpcode_CALL, N(func_80238A20_6F1B00)),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, ShakeCam, 1, 0, 5, SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 354),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, GetActionCommandResult, SI_VAR(0)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_GT, 0),
            SI_CMD(ScriptOpcode_CALL, N(IsGlowing)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 80),
        SI_CMD(ScriptOpcode_CASE_ELSE),
            SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 48),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 0),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 2),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
            SI_CMD(ScriptOpcode_RETURN),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 1),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 3),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 50),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
        SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 53),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, func_80269524, SI_VAR(15)),
    SI_CMD(ScriptOpcode_CALL, CloseActionCommandInfo),
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_CALL, func_802694A4, 0),
    SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, 24, 3),
    SI_CMD(ScriptOpcode_SET, SI_VAR(10), 24),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 4),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_LOOP, 6),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), -30),
            SI_CMD(ScriptOpcode_CALL, SetActorRotation, -127, 0, 0, SI_VAR(0)),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 641),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 3),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 1),
    SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 32),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_CALL, func_80269550, SI_VAR(15)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A06C)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

// *INDENT-OFF*
Script N(8023ADC4) = {
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A52C)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A66C)),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589831),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 18, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 19, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 3),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589830),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 9, 0),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 8205),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 0),
    SI_CMD(ScriptOpcode_CALL, PartnerTestEnemy, SI_VAR(0), 128, 20, 0, 1, 16),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 6),
        SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
        SI_CMD(ScriptOpcode_CALL, N(func_80238A20_6F1B00)),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, ShakeCam, 1, 0, 5, SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 354),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, GetActionCommandResult, SI_VAR(0)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_GT, 0),
            SI_CMD(ScriptOpcode_CALL, N(IsGlowing)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 2),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 80),
        SI_CMD(ScriptOpcode_CASE_ELSE),
            SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 2),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 48),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 0),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 2),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
            SI_CMD(ScriptOpcode_RETURN),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 1),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 3),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 50),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
        SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 53),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, func_80269524, SI_VAR(15)),
    SI_CMD(ScriptOpcode_CALL, CloseActionCommandInfo),
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_CALL, func_802694A4, 0),
    SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, 24, 3),
    SI_CMD(ScriptOpcode_SET, SI_VAR(10), 24),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 4),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_LOOP, 6),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), -30),
            SI_CMD(ScriptOpcode_CALL, SetActorRotation, -127, 0, 0, SI_VAR(0)),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, EnableActorBlur, 256, 1),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 641),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 3),
    SI_CMD(ScriptOpcode_CALL, EnableActorBlur, 256, -1),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 2),
    SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 32),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_CALL, func_80269550, SI_VAR(15)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A06C)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

// *INDENT-OFF*
Script N(8023B45C) = {
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A52C)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A66C)),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589831),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 18, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 19, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 3),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589830),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 9, 0),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 8205),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 0),
    SI_CMD(ScriptOpcode_CALL, PartnerTestEnemy, SI_VAR(0), 128, 20, 0, 1, 16),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 6),
        SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
        SI_CMD(ScriptOpcode_CALL, N(func_80238A20_6F1B00)),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, ShakeCam, 1, 0, 5, SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 354),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, GetActionCommandResult, SI_VAR(0)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_GT, 0),
            SI_CMD(ScriptOpcode_CALL, N(IsGlowing)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 80),
        SI_CMD(ScriptOpcode_CASE_ELSE),
            SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 48),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 0),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 2),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
            SI_CMD(ScriptOpcode_RETURN),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 1),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 3),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 50),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
        SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 53),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, func_80269524, SI_VAR(15)),
    SI_CMD(ScriptOpcode_CALL, CloseActionCommandInfo),
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_CALL, func_802694A4, 0),
    SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, 24, 3),
    SI_CMD(ScriptOpcode_SET, SI_VAR(10), 24),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 4),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_LOOP, 6),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), -30),
            SI_CMD(ScriptOpcode_CALL, SetActorRotation, -127, 0, -250000000, SI_VAR(0)),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589830),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_LOOP, SI_VAR(10)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 133),
            SI_CMD(ScriptOpcode_CALL, SetActorRotation, -127, -250000000, SI_VAR(0), -250000000),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, EnableActorBlur, 256, 1),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 641),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 3),
    SI_CMD(ScriptOpcode_CALL, EnableActorBlur, 256, -1),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
    SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
    SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 128, 0, 0, SI_VAR(0), 32),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_CALL, func_80269550, SI_VAR(15)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A06C)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

s32 N(D_8023BB78_6ECC58)[] = {
    0x00000007, 0x00000006, 0x00000005, 0x00000004, 0x00000003, 0x00000002, 0x00000001, 0x00000000,
};

s32 D_8023BB98_6ECC78 = 0x000000C8;

// *INDENT-OFF*
Script N(8023BB9C) = {
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A52C)),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A66C)),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589831),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 18, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 19, 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 1),
    SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 52),
    SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589830),
    SI_CMD(ScriptOpcode_CALL, SetActorDispOffset, 256, 0, 9, 0),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 8205),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 0),
    SI_CMD(ScriptOpcode_CALL, PartnerTestEnemy, SI_VAR(0), 1048704, 20, 0, 1, 16),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(0), 6),
        SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
        SI_CMD(ScriptOpcode_CALL, N(func_80238A20_6F1B00)),
        SI_CMD(ScriptOpcode_SPAWN_THREAD),
            SI_CMD(ScriptOpcode_CALL, ShakeCam, 1, 0, 5, SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 354),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 20),
        SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
        SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, GetActionCommandResult, SI_VAR(0)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_GT, 0),
            SI_CMD(ScriptOpcode_CALL, N(IsGlowing)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 1048704, 0, 0, SI_VAR(0), 80),
        SI_CMD(ScriptOpcode_CASE_ELSE),
            SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
            SI_CMD(ScriptOpcode_CALL, PartnerDamageEnemy, SI_VAR(0), 1048704, 0, 0, SI_VAR(0), 48),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 0),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 2),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
            SI_CMD(ScriptOpcode_RETURN),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 1),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 3),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 50),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
        SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 53),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, func_80269524, SI_VAR(15)),
    SI_CMD(ScriptOpcode_SET, SI_VAR(13), 0),
    SI_CMD(ScriptOpcode_SET, SI_VAR(15), 0),
    SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_LABEL, 10),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 50),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 5),
        SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
        SI_CMD(ScriptOpcode_CALL, UseBattleCamPreset, 53),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, CloseActionCommandInfo),
    SI_CMD(ScriptOpcode_CALL, func_8026919C, N(D_8023BB78_6ECC58)),
    SI_CMD(ScriptOpcode_CALL, LoadActionCommand, 1),
    SI_CMD(ScriptOpcode_CALL, func_802A9000_430020),
    SI_CMD(ScriptOpcode_SET, SI_VAR(10), 24),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(15)),
        SI_CMD(ScriptOpcode_CASE_EQ, 0),
            SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 1),
        SI_CMD(ScriptOpcode_CASE_EQ, 1),
            SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 2),
        SI_CMD(ScriptOpcode_CASE_EQ, 2),
            SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 3),
        SI_CMD(ScriptOpcode_CASE_EQ, 3),
            SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 4),
        SI_CMD(ScriptOpcode_CASE_ELSE),
            SI_CMD(ScriptOpcode_CALL, func_802A9120_421B10, SI_VAR(10), 5),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 4),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_LOOP, 6),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), -30),
            SI_CMD(ScriptOpcode_CALL, SetActorRotation, -127, 0, -250000000, SI_VAR(0)),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
        SI_CMD(ScriptOpcode_CALL, SetAnimation, -127, 1, 589830),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
        SI_CMD(ScriptOpcode_SET, SI_VAR(0), 0),
        SI_CMD(ScriptOpcode_LOOP, SI_VAR(10)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 133),
            SI_CMD(ScriptOpcode_CALL, SetActorRotation, -127, -250000000, SI_VAR(0), -250000000),
            SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_CALL, SetGoalToTarget, 256),
    SI_CMD(ScriptOpcode_CALL, EnableActorBlur, 256, 1),
    SI_CMD(ScriptOpcode_CALL, SetJumpAnimations, 256, 0, 589830, 589830, 589830),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 641),
    SI_CMD(ScriptOpcode_CALL, func_8023817C_6F125C, SI_VAR(10), 3),
    SI_CMD(ScriptOpcode_CALL, EnableActorBlur, 256, -1),
    SI_CMD(ScriptOpcode_SUB, SI_VAR(13), 1),
    SI_CMD(ScriptOpcode_CALL, func_802380E4_6F11C4),
    SI_CMD(ScriptOpcode_IF_GE, SI_VAR(15), SI_VAR(0)),
        SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_PARALLEL_THREAD),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.1005859375), SI_FIXED(0.80078125), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.30078125), SI_FIXED(0.5), SI_FIXED(1.0)),
        SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
        SI_CMD(ScriptOpcode_CALL, SetActorScale, 256, SI_FIXED(1.0), SI_FIXED(1.0), SI_FIXED(1.0)),
    SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_CALL, GetActionCommandResult, SI_VAR(0)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_GT, 0),
            SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 0),
                SI_CMD(ScriptOpcode_CALL, N(IsGlowing)),
                SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
                SI_CMD(ScriptOpcode_CALL, PartnerPowerBounceEnemy, SI_VAR(0), 1048704, 0, 0, SI_VAR(0), SI_VAR(13), 64),
            SI_CMD(ScriptOpcode_ELSE),
                SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
                SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
                SI_CMD(ScriptOpcode_CALL, PartnerPowerBounceEnemy, SI_VAR(0), 1048704, 0, 0, SI_VAR(0), SI_VAR(13), 32),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_CASE_ELSE),
            SI_CMD(ScriptOpcode_CALL, N(StopGlowingAndGet)),
            SI_CMD(ScriptOpcode_ADD, SI_VAR(0), 3),
            SI_CMD(ScriptOpcode_CALL, PartnerPowerBounceEnemy, SI_VAR(0), 1048704, 0, 0, SI_VAR(0), SI_VAR(13), 32),
            SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_CALL, PlaySoundAtActor, 256, 0),
    SI_CMD(ScriptOpcode_CALL, func_80269550, SI_VAR(14)),
    SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 0),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 2),
            SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(80239CA8)),
            SI_CMD(ScriptOpcode_RETURN),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 1),
        SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, 3),
            SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 1),
                SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(8023A06C)),
                SI_CMD(ScriptOpcode_RETURN),
            SI_CMD(ScriptOpcode_END_IF),
        SI_CMD(ScriptOpcode_END_CASE_MULTI),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_ADD, SI_VAR(15), 1),
    SI_CMD(ScriptOpcode_GOTO, 10),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(8023C5B8) = SCRIPT({
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SetActorSpeed(ACTOR_PARTNER, 6.0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, run));
    SetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    RunToGoal(ACTOR_PARTNER, 0, FALSE);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    InitTargetIterator();
    SetGoalToTarget(ACTOR_PARTNER);
    SetBattleFlagBits(4, 1);
    func_80238E04_6F1EE4();
    sleep 12;
    SetCamEnabled(2, 1);
    SetCamFlag80(2, 0);
    SetCamPerspective(2, 6, 25, 16, 1024);
    SetCamViewport(2, 137, 95, 138, 99);
    GetOwnerTarget(SI_VAR(10), SI_VAR(11));
    GetActorPos(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_80238BCC_6F1CAC();
    sleep 1;
    func_802CAE50(2, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802CABE8(2, 0, SI_VAR(3), 100, 4);
    sleep 2;
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_282);
    SetCamFlag80(2, 1);
    sleep 10;
    func_80238B60_6F1C40();
    ActorSpeak(SI_VAR(0), -127, 1, 589839, 589825);
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
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, run));
    RunToGoal(ACTOR_PARTNER, 0);
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
});

Script N(8023C90C) = SCRIPT({
    UseBattleCamPreset(55);
    sleep 10;
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, charge));
    SetActorDispOffset(ACTOR_PARTNER, 0, 19, 0);
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 15;
    PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208F);
    func_802390C8_6F21A8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.2);
    sleep 3;
    func_802390C8_6F21A8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 0.8);
    spawn {
        sleep 15;
        GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 15;
        SI_VAR(2) += -5;
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_2003);
        PlayEffect(0x52, 9, SI_VAR(0), SI_VAR(1), SI_VAR(2), 2.0, 20, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep 30;
    SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
    SetActorDispOffset(ACTOR_PARTNER, 0, 0, 0);
    UseBattleCamPreset(2);
    MoveBattleCamOver(10);
    func_80238E74_6F1F54();
    if (SI_VAR(0) == 0) {
        GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 10;
        SI_VAR(1) += 25;
        SI_VAR(2) += 5;
        PlaySoundAtActor(ACTOR_PARTNER, SOUND_UNKNOWN_208E);
        func_80238EDC_6F1FBC(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 4;
        SetActorJumpGravity(ACTOR_PARTNER, 1.4);
        GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetJumpAnimations(ACTOR_PARTNER, 589828, ANIM_1, ANIM_90004, ANIM_90004);
        SetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        JumpToGoal(ACTOR_PARTNER, 20, 1, 1, 0);
        SetAnimation(ACTOR_PARTNER, -1, NPC_ANIM(battle_goombario, default, idle));
        GetMenuSelection(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        match SI_VAR(2) {
            == 134 {
                ShowMessageBox(36, 60);
            }
            == 135 {
                N(func_80239190_6F2270)();
                ShowMessageBox(SI_VAR(0), 60);
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
    IsMessageBoxDisplayed(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        goto 0;
    }
});
