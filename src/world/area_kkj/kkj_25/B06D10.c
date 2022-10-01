#include "kkj_25.h"
#include "effects.h"

#include "world/common/UnkFoldFunc.inc.c"

ApiStatus func_802406EC_B070EC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* unkStruct = heap_malloc(sizeof(*unkStruct));

    unkStruct->spriteIndex = spriteIndex;
    unkStruct->rasterIndex = rasterIndex;
    unkStruct->unk_34 = gPlayerStatus.colliderHeight;
    unkStruct->unk_38 = gPlayerStatus.colliderDiameter;
    unkStruct->pos.x = gPlayerStatus.position.x;
    unkStruct->pos.y = gPlayerStatus.position.y;
    unkStruct->pos.z = gPlayerStatus.position.z;
    unkStruct->rot.x = 0.0f;
    unkStruct->rot.y = 0.0f;
    unkStruct->rot.z = 0.0f;
    unkStruct->scale.x = SPRITE_WORLD_SCALE_F;
    unkStruct->scale.y = SPRITE_WORLD_SCALE_F;
    unkStruct->scale.z = SPRITE_WORLD_SCALE_F;
    unkStruct->foldID = func_8013A704(1);
    unkStruct->entityID = create_generic_entity_world(NULL, kkj_25_UnkFoldFunc);

    evt_set_variable(script, MapVar(10), (s32) unkStruct);
    return ApiStatus_DONE2;
}

ApiStatus func_80240800_B07200(Evt* script, s32 isInitialCall) {
    UnkEntityStruct* unkStruct = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    func_8013A854(unkStruct->foldID);
    free_generic_entity(unkStruct->entityID);
    heap_free(unkStruct);
    evt_set_variable(script, MapVar(10), 0);

    return ApiStatus_DONE2;
}

ApiStatus func_8024086C_B0726C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* unkStruct = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    unkStruct->pos.x = x;
    unkStruct->pos.y = y;
    unkStruct->pos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus func_8024092C_B0732C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* unkStruct = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    unkStruct->rot.x = x;
    unkStruct->rot.y = y;
    unkStruct->rot.z = z;

    return ApiStatus_DONE2;
}

ApiStatus func_802409EC_B073EC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* unkStruct = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    unkStruct->scale.x = x;
    unkStruct->scale.y = y;
    unkStruct->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus func_80240AAC_B074AC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* unkStruct = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    unkStruct->spriteIndex = spriteIndex;
    unkStruct->rasterIndex = rasterIndex;

    return ApiStatus_DONE2;
}

ApiStatus func_80240B18_B07518(Evt* script, s32 isInitialCall) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

ApiStatus func_80240B8C_B0758C(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80240BA0_B075A0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    effect->data.starsOrbiting->pos.x = var1;
    effect->data.starsOrbiting->pos.y = var2;
    effect->data.starsOrbiting->pos.z = var3;

    return ApiStatus_DONE2;
}

ApiStatus func_80240C60_B07660(Evt* script, s32 isInitialCall) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

ApiStatus func_80240CD4_B076D4(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80240CE8_B076E8(Evt* script, s32 isInitialCall) {
    gPlayerData.starBeamLevel = 2;
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    gPlayerData.specialBarsFilled = gPlayerData.maxStarPower * 256;

    sync_status_menu();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kkj/kkj_25/B06D10", func_80240D30_B07730);

ApiStatus func_80240E54_B07854(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80240EB8_B078B8(Evt* script, s32 isInitialCall) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

ApiStatus func_80240F2C_B0792C(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}
