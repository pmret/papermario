#include "common.h"
#include "effects.h"

extern f64 D_8023C060_70BD00;
extern s32 D_8023C070;

#ifdef NON_MATCHING
ApiStatus func_80238000_707CA0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorPart* partsTable;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f6;

    set_goal_pos_to_part(partnerActor + 10, partnerActor->targetActorID, partnerActor->targetPartIndex);
    partsTable = get_actor_part(get_actor(partnerActor->targetActorID), partnerActor->targetPartIndex);
    temp_f2 = partnerActor->walk.goalPos.x + partsTable->unk_75;
    temp_f6 = partnerActor->currentPos.x + 8;
    temp_f4 = partnerActor->currentPos.y + 16;
    partnerActor->walk.goalPos.x = temp_f2;
    partnerActor->walk.currentPos.x = temp_f6;
    partnerActor->walk.currentPos.y = temp_f4;
    partnerActor->walk.goalPos.y = (f32) (partnerActor->walk.goalPos.y + (f32) partsTable->unk_76);
    partnerActor->walk.currentPos.z = (f32) partnerActor->currentPos.z;
    temp_f0 = atan2(temp_f6, temp_f4, temp_f2, partnerActor->walk.goalPos.y);
    temp_f4_2 = (temp_f0 - 90.0f) * 0.25f;
    partnerActor->walk.distance = temp_f0;
    partnerActor->rotation.z = temp_f4_2;

    if (temp_f4_2 < 0) {
        partnerActor->rotation.z = 0;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/partner/sushie", func_80238000_707CA0);
#endif

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238114_707DB4);

ApiStatus func_802381EC_707E8C(ScriptInstance* script, s32 isInitialCall) {
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
        script->functionTemp[1] = (s32) (temp_v0 - 1);

        return ApiStatus_BLOCK;
    }

    partnerActor->scale.x = 1.0f;
    partnerActor->scale.y = 1.0f;
    partnerActor->scale.z = 1.0f;

    return ApiStatus_DONE2;
}

ApiStatus func_802382A4_707F44(ScriptInstance* script, s32 isInitialCall) {
    f32 var1 = script->varTable[0];
    f32 var2 = script->varTable[1];

    add_vec2D_polar(&var1, &var2, 300, atan2(var1, var2, script->varTable[3], script->varTable[4]));

    script->varTable[3] = var1;
    script->varTable[4] = var2;

    return ApiStatus_DONE2;
}

ApiStatus func_80238328_707FC8(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_80238388_708028(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* playerActor = battleStatus->playerActor;

    D_8023C070 = playFX_59(1, partnerActor->currentPos.x - 5.5, partnerActor->currentPos.y + 15.5, partnerActor->currentPos.z + 5, playerActor->currentPos.x, playerActor->currentPos.y, playerActor->currentPos.z, rand_int(10) * D_8023C060_70BD00 + 1, 30);

    return ApiStatus_DONE2;
}

ApiStatus func_80238480_708120(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    f32 var1 = get_float_variable(script, *args++);
    f32 var2 = get_float_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);
    s32 effect = battleStatus->unk_A0;

    if (effect != NULL) {
        remove_effect(effect);
    }

    battleStatus->unk_A0 = playFX_5A(0, var1, var2, var3, 1.5f, 0);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238540_7081E0);

ApiStatus func_80238E30_708AD0(ScriptInstance* script, s32 isInitialCall) {
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
