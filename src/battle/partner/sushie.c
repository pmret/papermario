#include "common.h"
#include "effects.h"

extern f64 D_8023C060_70BD00;
extern s32 D_8023C070;

ApiStatus func_80238000_707CA0(Evt* script, s32 isInitialCall) {
    ActorPart* targetPart;

    Actor* partner = gBattleStatus.partnerActor;
    set_goal_pos_to_part(&partner->state, partner->targetActorID, partner->targetPartIndex);
    targetPart = get_actor_part(get_actor(partner->targetActorID), partner->targetPartIndex);

    partner->state.goalPos.x += targetPart->unk_75;
    partner->state.goalPos.y += targetPart->unk_76;
    partner->state.goalPos.z = partner->state.goalPos.z; // required to match

    partner->state.currentPos.x = partner->currentPos.x + 8.0f;
    partner->state.currentPos.y = partner->currentPos.y + 16.0f;
    partner->state.currentPos.z = partner->currentPos.z;

    partner->state.angle = atan2(
        partner->state.currentPos.x, partner->state.currentPos.y,
        partner->state.goalPos.x, partner->state.goalPos.y
    );

    partner->rotation.z = (partner->state.angle - 90.0f) * 0.25f;

    if (partner->rotation.z < 0.0f) {
        partner->rotation.z = 0.0f;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238114_707DB4);

ApiStatus func_802381EC_707E8C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 xScale;
    f32 yScale;
    f32 zScale;
    s32 temp_v0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 6;
    }

    xScale = partnerActor->scale.x;
    yScale = partnerActor->scale.y;
    zScale = partnerActor->scale.z;
    partnerActor->scale.x = xScale + ((1.0 - xScale) / 3.0);
    partnerActor->scale.y = yScale + ((1.0 - yScale) / 3.0);
    partnerActor->scale.z = zScale + ((1.0 - zScale) / 3.0);

    temp_v0 = script->functionTemp[1];
    if (temp_v0) {
        script->functionTemp[1] = temp_v0 - 1;

        return ApiStatus_BLOCK;
    }

    partnerActor->scale.x = 1.0f;
    partnerActor->scale.y = 1.0f;
    partnerActor->scale.z = 1.0f;

    return ApiStatus_DONE2;
}

ApiStatus func_802382A4_707F44(Evt* script, s32 isInitialCall) {
    f32 posX = script->varTable[0];
    f32 posY = script->varTable[1];

    add_vec2D_polar(&posX, &posY, 300, atan2(posX, posY, script->varTable[3], script->varTable[4]));

    script->varTable[3] = posX;
    script->varTable[4] = posY;

    return ApiStatus_DONE2;
}

ApiStatus func_80238328_707FC8(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var = script->varTable[0];

    if (var > 0) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = 0;
    script->varTable[10] = var;
    if (battleStatus->waterBlockTurnsLeft < var) {
        battleStatus->waterBlockTurnsLeft = var;
        battleStatus->waterBlockAmount = 1;
        battleStatus->unk_43C->unk_0C->unk_10 = battleStatus->waterBlockTurnsLeft;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238388_708028(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* playerActor = battleStatus->playerActor;

    D_8023C070 = fx_squirt(1, partnerActor->currentPos.x - 5.5, partnerActor->currentPos.y + 15.5, partnerActor->currentPos.z + 5, playerActor->currentPos.x, playerActor->currentPos.y, playerActor->currentPos.z, rand_int(10) * D_8023C060_70BD00 + 1, 30);

    return ApiStatus_DONE2;
}

ApiStatus func_80238480_708120(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    s32 effect = battleStatus->waterBlockEffect;

    if (effect != NULL) {
        remove_effect(effect);
    }

    battleStatus->waterBlockEffect = fx_water_block(0, posX, posY, posZ, 1.5f, 0);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238540_7081E0);

ApiStatus func_80238E30_708AD0(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 var = (((f64) script->varTable[0] * 3) / 100) + 1;
    f32 xScale = partnerActor->scale.x;
    f32 yScale = partnerActor->scale.y;
    f32 zScale = partnerActor->scale.z;

    partnerActor->scale.x = xScale + ((var - xScale) / 3);
    partnerActor->scale.y = yScale + ((var - yScale) / 3);
    partnerActor->scale.z = zScale + ((var - zScale) / 3);

    return ApiStatus_DONE2;
}
