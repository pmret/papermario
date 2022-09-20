#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/npc/BattleGoombario.h"

#define NAMESPACE battle_partner_goombario

extern EffectInstance* D_8023CDA0;
extern s32 D_8023CDA4;
extern s32 D_8023BB98_6ECC78;
extern s32 bActorTattles[ACTOR_TYPE_COUNT];

extern EvtScript N(init);
extern EvtScript N(80239784);
extern EvtScript N(802397E0);
extern EvtScript N(8023993C);
extern EvtScript N(8023994C);
extern EvtScript N(80239988);
extern EvtScript N(8023A754);
extern EvtScript N(8023ADC4);
extern EvtScript N(8023B45C);
extern EvtScript N(8023BB9C);
extern EvtScript N(8023C5B8);
extern EvtScript N(8023C90C);
extern EvtScript N(handleEvent_80239360);
extern EvtScript N(idle_80239350);
extern EvtScript N(nextTurn_80239A3C);
extern EvtScript N(takeTurn_802396D8);

ApiStatus func_802380E4_6F11C4(Evt* script, s32 isInitialCall);
ApiStatus func_8023817C_6F125C(Evt* script, s32 isInitialCall);
ApiStatus func_80238BCC_6F1CAC(Evt* script, s32 isInitialCall);
ApiStatus func_80238EDC_6F1FBC(Evt* script, s32 isInitialCall);

ApiStatus N(func_80238000_6F10E0)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    f32 posX = partner->currentPos.x;
    f32 posY = partner->currentPos.y;
    f32 posZ = partner->currentPos.z;
    f32 goalX = partner->state.goalPos.x;
    f32 goalY = partner->state.goalPos.y;
    f32 goalZ = partner->state.goalPos.z;

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
    D_8023BB98_6ECC78 *= targetActor->actorBlueprint->powerBounceChance;
    D_8023BB98_6ECC78 /= 100;
    if (D_8023BB98_6ECC78 < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/goombario", func_8023817C_6F125C);

ApiStatus N(func_80238A20_6F1B00)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = gBattleStatus.partnerActor;
    Vec3f* pos = &partner->state.currentPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        partner->state.currentPos.x = partner->currentPos.x;
        partner->state.currentPos.y = partner->currentPos.y;
        partner->state.currentPos.z = partner->currentPos.z;
        script->functionTemp[0] = 1;
    }

    if (partner->state.velocity > 0.0f) {
        set_animation(0x100, 0, partner->state.animJumpRise);
    }

    if (partner->state.velocity < 0.0f) {
        set_animation(0x100, 0, partner->state.animJumpFall);
    }

    partner->state.currentPos.y = (partner->state.currentPos.y + partner->state.velocity);
    partner->state.velocity = (partner->state.velocity - partner->state.acceleration);
    add_xz_vec3f(pos, partner->state.speed, partner->state.angle);
    partner->currentPos.x = partner->state.currentPos.x;
    partner->currentPos.y = partner->state.currentPos.y;
    partner->currentPos.z = partner->state.currentPos.z;

    if (partner->currentPos.y < 10.0f) {
        partner->currentPos.y = 10.0f;

        play_movement_dust_effects(2, partner->currentPos.x, partner->currentPos.y, partner->currentPos.z,
                                   partner->yaw);
        sfx_play_sound(SOUND_SOFT_LAND);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238B60_6F1C40(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    Actor* target = get_actor(partner->targetActorID);
    s32* tattle = &bActorTattles[target->actorType];

    script->varTable[0] = *tattle;

    if (script->varTable[0] == NULL) {
        script->varTable[0] = bActorTattles[0];
    }

    save_tattle_flags(target->actorType);

    return ApiStatus_DONE2;
}


ApiStatus func_80238BCC_6F1CAC(Evt* script, s32 isInitalCall) {
    Actor* target = get_actor(gBattleStatus.partnerActor->targetActorID);
    s32 xSize;

    if (!(target->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
        script->varTable[1] = script->varTable[1] + (((target->size.y / 3) & 0xFF) * target->scalingFactor);
        script->varTable[1] += ((target->size.y / 4) * target->scalingFactor);
    } else {
        script->varTable[1] = script->varTable[1] - (((target->size.y / 3) & 0xFF) * target->scalingFactor);
        script->varTable[1] -= ((target->size.y / 4) * target->scalingFactor);
    }

    if (target->flags & ACTOR_FLAG_8000) {
        script->varTable[1] -= (target->size.y / 2) * target->scalingFactor;
    }

    xSize = target->size.y * target->scalingFactor;
    if (xSize < target->size.x) {
        xSize = target->size.x;
    }

    script->varTable[3] = xSize + 76;
    script->varTable[0] += bActorOffsets[target->actorType].tattleCam.x;
    script->varTable[1] += bActorOffsets[target->actorType].tattleCam.y;
    script->varTable[3] += bActorOffsets[target->actorType].tattleCam.z;

    return ApiStatus_DONE2;
}


ApiStatus func_80238E04_6F1EE4(Evt* script, s32 isInitialCall) {
    D_8023CDA0 = fx_tattle_window(0, 206, 144, 0, 1.0f, 0);

    return ApiStatus_DONE2;
}

ApiStatus func_80238E48_6F1F28(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = D_8023CDA0;

    effect->data.tattleWindow->pos.y = 144.0f;
    effect->flags |= EFFECT_INSTANCE_FLAGS_10;

    return ApiStatus_DONE2;
}

ApiStatus func_80238E74_6F1F54(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;

    script->varTable[0] = FALSE;

    switch (battleStatus->selectedMoveID) {
        case 134:
            if (partner->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
        case 135:
            if (partner->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
        case 136:
            if (partner->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238EDC_6F1FBC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 boostAmount;
    s32 x, y, z;

    D_8023CDA4 = 0;
    if (partner->isGlowing > 0) {
        D_8023CDA4 = 1;
    }

    boostAmount = 0;
    switch (battleStatus->selectedMoveID) {
        case MOVE_TATTLE:
            partner->isGlowing += 2;
            boostAmount = 1;
            if (partner->isGlowing >= 99) {
                partner->isGlowing = 99;
            }
            break;
        case MOVE_CHARGE:
            partner->isGlowing += 2;
            boostAmount = 1;
            if (partner->isGlowing >= 99) {
                partner->isGlowing = 99;
            }
            break;
        case MOVE_MULTIBONK:
            partner->isGlowing += 2;
            boostAmount = 1;
            if (partner->isGlowing >= 99) {
                partner->isGlowing = 99;
            }
            break;
    }

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    fx_stat_change(boostAmount, x, y, z, 1.0f, 60);

    gBattleStatus.flags1 |= BS_FLAGS1_40000000;
    return ApiStatus_DONE2;
}

ApiStatus N(StopGlowing)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->partnerActor->isGlowing = FALSE;
    battleStatus->flags1 &= ~0x40000000;

    return ApiStatus_DONE2;
}

ApiStatus N(StopGlowingAndGet)(Evt* script, s32 isInitialCall) {
    Actor* partner = gBattleStatus.partnerActor;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_40000000)) {
        partner->isGlowing = FALSE;
    }

    script->varTable[0] = partner->isGlowing;
    partner->isGlowing = FALSE;
    gBattleStatus.flags1 &= ~BS_FLAGS1_40000000;

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

    fx_energy_in_out(6, var1, var2, var3, var4, 45);

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
    STATUS_NORMAL,    ANIM_BattleGoombario_Walk,
    STATUS_STONE,     ANIM_BattleGoombario_Still,
    STATUS_SLEEP,     ANIM_BattleGoombario_Sleep,
    STATUS_POISON,    ANIM_BattleGoombario_Still,
    STATUS_STOP,      ANIM_BattleGoombario_Still,
    STATUS_DAZE,      ANIM_BattleGoombario_Injured,
    STATUS_TURN_DONE, ANIM_BattleGoombario_Still,
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

ActorPartBlueprint N(partsTable_802392A4)[] = {
    {
        .flags = 0,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 8, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802391B0),
        .defenseTable = N(defenseTable_802391EC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
    },
};

extern EvtScript N(init_802392F0);

ActorBlueprint N(goombario) = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBARIO,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_802392A4)),
    .partsData = N(partsTable_802392A4),
    .script = &N(init_802392F0),
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

EvtScript N(init_802392F0) = {
    EVT_CALL(BindTakeTurn, 256, EVT_PTR(battle_partner_goombario_takeTurn_802396D8))
    EVT_CALL(BindIdle, 256, EVT_PTR(battle_partner_goombario_idle_80239350))
    EVT_CALL(BindHandleEvent, 256, EVT_PTR(battle_partner_goombario_handleEvent_80239360))
    EVT_CALL(BindNextTurn, 256, EVT_PTR(battle_partner_goombario_nextTurn_80239A3C))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80239350) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80239360) = {
    EVT_CALL(UseIdleAnimation, 256, 0)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, 256, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_SET_CONST(LVar2, 0x9000A)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_EXEC_WAIT(D_80296014)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_CALL(PlaySoundAtActor, 256, 8332)
            EVT_SET_CONST(LVar0, 0x1)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_EXEC_WAIT(D_80297814)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(42)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(D_80294FE4)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(44)
            EVT_SET_CONST(LVar1, 0x9000B)
            EVT_SET(LVar2, 12)
            EVT_SET_CONST(LVar3, 0x9000C)
            EVT_EXEC_WAIT(D_80294C68)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LVar1, 0x9000B)
            EVT_SET_CONST(LVar2, 0x9000C)
            EVT_EXEC_WAIT(D_8029621C)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(51)
            EVT_CALL(battle_partner_goombario_StopGlowing)
            EVT_SET_CONST(LVar1, 0x9000A)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(52)
            EVT_SET_CONST(LVar0, 0x1)
            EVT_SET_CONST(LVar1, 0x90001)
            EVT_SET_CONST(LVar2, 0x90003)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(D_80295EC4)
        EVT_CASE_OR_EQ(24)
        EVT_CASE_OR_EQ(26)
            EVT_CALL(PlaySoundAtActor, 256, 8332)
            EVT_SET_CONST(LVar0, 0x1)
            EVT_SET_CONST(LVar1, 0x9000E)
            EVT_EXEC_WAIT(D_80297814)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, 256, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802396D8) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
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

EvtScript N(80239784) = {
    EVT_SET_CONST(LVar0, 0x1)
    EVT_SET_CONST(LVar1, 0x90010)
    EVT_SET_CONST(LVar2, 0x90011)
    EVT_SET_CONST(LVar3, 0x90001)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(802397E0) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(SetBattleFlagBits, 16384, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_CALL(LoadItemScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SWITCH(LVar2)
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

EvtScript N(8023993C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8023994C) = {
    EVT_SET_CONST(LVar0, 0x1)
    EVT_SET_CONST(LVar1, 0x90003)
    EVT_EXEC_WAIT(D_80294AFC)
    EVT_RETURN
    EVT_END
};

EvtScript N(80239988) = {
    EVT_CALL(UseIdleAnimation, 256, 0)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(SetActorYaw, 256, 0)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(UseIdleAnimation, 256, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80239A3C) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_IF_EQ(GF_Tutorial_SwapTurnOrder, 0)
                EVT_CALL(UseIdleAnimation, 256, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, -127)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(10)
                EVT_CALL(SetActorYaw, 0, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 60)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 90)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 120)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 150)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 180)
                EVT_WAIT(5)
                EVT_CALL(ActorSpeak, 721082, 256, 0, 589839, 589825)
                EVT_CALL(SetActorYaw, 0, 150)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 120)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 90)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 60)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 0)
                EVT_WAIT(5)
                EVT_SET(GF_Tutorial_SwapTurnOrder, 1)
                EVT_CALL(UseIdleAnimation, 256, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80239CA8) = {
    EVT_CALL(func_80280818)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
        EVT_SET(LVar0, 180)
        EVT_LOOP(3)
            EVT_ADD(LVar0, 60)
            EVT_CALL(SetActorRotation, -127, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, -127, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, 256, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, 256, EVT_FLOAT(1.2))
    EVT_CALL(battle_partner_goombario_func_80238000_6F10E0)
    EVT_CALL(JumpToGoal, 256, LVar0, 0, 1, 0)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, -127, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(AddGoalPos, 256, -10, 0, 0)
    EVT_CALL(JumpToGoal, 256, 6, 0, 0, 1)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, -127, 1, 589825)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A06C) = {
    EVT_CALL(func_80280818)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(GetGoalPos, 256, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(SetGoalPos, 256, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, 256, EVT_FLOAT(1.4))
    EVT_CALL(battle_partner_goombario_func_80238000_6F10E0)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
        EVT_SUB(LVar0, 4)
        EVT_SET(LVar1, LVar0)
        EVT_DIV(LVar1, 3)
        EVT_IF_LT(LVar1, 1)
            EVT_SET(LVar1, 1)
        EVT_END_IF
        EVT_SET(LVar2, LVar1)
        EVT_MOD(LVar2, 2)
        EVT_IF_EQ(LVar2, 0)
            EVT_SUB(LVar1, 1)
        EVT_END_IF
        EVT_SET(LVar0, 180)
        EVT_LOOP(LVar1)
            EVT_LOOP(3)
                EVT_ADD(LVar0, 60)
                EVT_CALL(SetActorRotation, -127, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, -127, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, 256, LVar0, 0, 1, 0)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, -127, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(AddGoalPos, 256, -20, 0, 0)
    EVT_CALL(JumpToGoal, 256, 6, 0, 0, 1)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, 256, -10, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(JumpToGoal, 256, 4, 0, 0, 1)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, -127, 0, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A52C) = {
    EVT_CALL(SetGoalToFirstTarget, -127)
    EVT_CALL(GetGoalPos, -127, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(GetGoalPos, 256, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, EVT_FLOAT(70.0))
    EVT_IF_LT(LVar0, LVar3)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, 256, LVar3, LVar4, LVar5)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_47)
    EVT_CALL(SetActorSpeed, 256, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A66C) = {
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(GetGoalPos, 256, LVarB, LVar7, LVarD)
    EVT_CALL(GetActorPos, 256, LVar7, LVarD, LVarE)
    EVT_IF_GT(LVarB, LVar7)
        EVT_SUB(LVarB, LVar7)
    EVT_ELSE
        EVT_SUB(LVar7, LVarB)
        EVT_SET(LVarB, LVar7)
    EVT_END_IF
    EVT_SUB(LVarB, 20)
    EVT_DIVF(LVarB, EVT_FLOAT(10.5888671875))
    EVT_ADDF(LVarB, 15)
    EVT_SET(LVarA, LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023A754) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 128, 20, 0, 1, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(LVar0, 1)
            EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(LVar0, 1)
            EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(LVar0)
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
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(LVarA, 24)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, -127, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, LVarA, 3)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
    EVT_ADD(LVar0, 1)
    EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 32)
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023ADC4) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 128, 20, 0, 1, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(LVar0, 2)
            EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(LVar0, 2)
            EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(LVar0)
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
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(LVarA, 24)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, -127, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(EnableActorBlur, 256, 1)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, LVarA, 3)
    EVT_CALL(EnableActorBlur, 256, -1)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
    EVT_ADD(LVar0, 2)
    EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 32)
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023B45C) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 128, 20, 0, 1, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(LVar0)
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
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(LVarA, 24)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, -127, 0, EVT_IGNORE_ARG, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(LVarA)
            EVT_ADD(LVar0, 133)
            EVT_CALL(SetActorRotation, -127, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(EnableActorBlur, 256, 1)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, LVarA, 3)
    EVT_CALL(EnableActorBlur, 256, -1)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
    EVT_ADD(LVar0, 3)
    EVT_CALL(PartnerDamageEnemy, LVar0, 128, 0, 0, LVar0, 32)
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
    EVT_RETURN
    EVT_END
};

s32 N(D_8023BB78_6ECC58)[] = {
    0x00000007, 0x00000006, 0x00000005, 0x00000004, 0x00000003, 0x00000002, 0x00000001, 0x00000000,
};

s32 D_8023BB98_6ECC78 = 0x000000C8;

EvtScript N(8023BB9C) = {
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A52C)
    EVT_EXEC_WAIT(battle_partner_goombario_8023A66C)
    EVT_CALL(SetAnimation, -127, 1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_CALL(SetActorDispOffset, 256, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 8205)
    EVT_CALL(func_8023817C_6F125C, LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 1048704, 20, 0, 1, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
        EVT_CALL(battle_partner_goombario_func_80238A20_6F1B00)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, 256, 354)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(battle_partner_goombario_IsGlowing)
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, 1048704, 0, 0, LVar0, 80)
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, 1048704, 0, 0, LVar0, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_SWITCH(LVar0)
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
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_SET(LVarD, 0)
    EVT_SET(LVarF, 0)
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, 256)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(func_8026919C, EVT_PTR(battle_partner_goombario_D_8023BB78_6ECC58))
    EVT_CALL(LoadActionCommand, 1)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_SET(LVarA, 24)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(func_802A9120_421B10, LVarA, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(func_802A9120_421B10, LVarA, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(func_802A9120_421B10, LVarA, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(func_802A9120_421B10, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A9120_421B10, LVarA, 5)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, -127, 0, EVT_IGNORE_ARG, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, -127, 1, 589830)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(LVarA)
            EVT_ADD(LVar0, 133)
            EVT_CALL(SetActorRotation, -127, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(EnableActorBlur, 256, 1)
    EVT_CALL(SetJumpAnimations, 256, 0, 589830, 589830, 589830)
    EVT_CALL(PlaySoundAtActor, 256, 641)
    EVT_CALL(func_8023817C_6F125C, LVarA, 3)
    EVT_CALL(EnableActorBlur, 256, -1)
    EVT_SUB(LVarD, 1)
    EVT_CALL(func_802380E4_6F11C4)
    EVT_IF_GE(LVarF, LVar0)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, 256, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(battle_partner_goombario_IsGlowing)
                EVT_ADD(LVar0, 3)
                EVT_CALL(PartnerPowerBounceEnemy, LVar0, 1048704, 0, 0, LVar0, LVarD, 64)
            EVT_ELSE
                EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
                EVT_ADD(LVar0, 3)
                EVT_CALL(PartnerPowerBounceEnemy, LVar0, 1048704, 0, 0, LVar0, LVarD, 32)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(battle_partner_goombario_StopGlowingAndGet)
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerPowerBounceEnemy, LVar0, 1048704, 0, 0, LVar0, LVarD, 32)
            EVT_SET(LocalFlag(0), 0)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, 256, 0)
    EVT_CALL(func_80269550, LVarE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(battle_partner_goombario_80239CA8)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(battle_partner_goombario_8023A06C)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023C5B8) = {
    EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, 256, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(SetGoalPos, 256, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, 256, 0, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, 256)
    EVT_CALL(SetBattleFlagBits, 4, 1)
    EVT_CALL(func_80238E04_6F1EE4)
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, 2, 1)
    EVT_CALL(SetCamFlag80, 2, 0)
    EVT_CALL(SetCamPerspective, 2, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, 2, 137, 95, 138, 99)
    EVT_CALL(GetOwnerTarget, LVarA, LVarB)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, 256, LVar0, LVar1, LVar2)
    EVT_CALL(func_80238BCC_6F1CAC)
    EVT_WAIT(1)
    EVT_CALL(func_802CAE50, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_802CABE8, 2, 0, LVar3, 100, 4)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, 256, 642)
    EVT_CALL(SetCamFlag80, 2, 1)
    EVT_WAIT(10)
    EVT_CALL(func_80238B60_6F1C40)
    EVT_CALL(ActorSpeak, LVar0, -127, 1, 589839, 589825)
    EVT_CALL(func_80238E48_6F1F28)
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, 2, 0)
    EVT_WAIT(32)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetBattleFlagBits, 4, 0)
    EVT_CALL(func_80280818)
    EVT_CALL(SetGoalToHome, 256)
    EVT_CALL(SetActorSpeed, 256, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, 256, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, 256, -1, 589827)
    EVT_CALL(RunToGoal, 256, 0)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023C90C) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, 256, -1, 589831)
    EVT_CALL(SetActorDispOffset, 256, 0, 19, 0)
    EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(PlaySoundAtActor, 256, 8335)
    EVT_CALL(func_802390C8_6F21A8, LVar0, LVar1, LVar2, EVT_FLOAT(1.2))
    EVT_WAIT(3)
    EVT_CALL(func_802390C8_6F21A8, LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_ADD(LVar2, -5)
        EVT_CALL(PlaySoundAtActor, 256, 8195)
        EVT_CALL(PlayEffect, 82, 9, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 20, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, 256, -1, 589825)
    EVT_CALL(SetActorDispOffset, 256, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(func_80238E74_6F1F54)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 10)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 5)
        EVT_CALL(PlaySoundAtActor, 256, 8334)
        EVT_CALL(func_80238EDC_6F1FBC, LVar0, LVar1, LVar2)
        EVT_WAIT(4)
        EVT_CALL(SetActorJumpGravity, 256, EVT_FLOAT(1.4))
        EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, 256, 589828, 1, 589828, 589828)
        EVT_CALL(SetGoalPos, 256, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, 256, 20, 1, 1, 0)
        EVT_CALL(SetAnimation, 256, -1, 589825)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(134)
                EVT_CALL(ShowMessageBox, 36, 60)
            EVT_CASE_EQ(135)
                EVT_CALL(battle_partner_goombario_func_80239190_6F2270)
                EVT_CALL(ShowMessageBox, LVar0, 60)
            EVT_CASE_EQ(136)
                EVT_CALL(ShowMessageBox, 36, 60)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageBox, 8, 60)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(IsMessageBoxDisplayed, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
