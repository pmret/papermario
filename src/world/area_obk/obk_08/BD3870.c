#include "obk_08.h"

#include "world/common/todo/UnkFoldFunc.inc.c"

ApiStatus func_802403DC_BD3C4C(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = heap_malloc(sizeof(*temp_v0));

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    temp_v0->unk_34 = gPlayerStatus.colliderHeight;
    temp_v0->unk_38 = gPlayerStatus.colliderDiameter;
    temp_v0->pos.x = gPlayerStatus.position.x;
    temp_v0->pos.y = gPlayerStatus.position.y;
    temp_v0->pos.z = gPlayerStatus.position.z;
    temp_v0->rot.x = 0.0f;
    temp_v0->rot.y = 0.0f;
    temp_v0->rot.z = 0.0f;
    temp_v0->scale.x = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.y = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.z = SPRITE_WORLD_SCALE_F;
    temp_v0->foldID = func_8013A704(1);
    temp_v0->entityID = create_worker_world(0, obk_08_UnkFoldFunc);
    evt_set_variable(script, MapVar(10), temp_v0);
    return ApiStatus_DONE2;
}

ApiStatus func_802404F0_BD3D60(Evt* script, s32 isInitialCall) {
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    func_8013A854(temp_v0->foldID);
    free_worker(temp_v0->entityID);
    heap_free(temp_v0);
    evt_set_variable(script, MapVar(10), NULL);
    return ApiStatus_DONE2;
}

ApiStatus func_8024055C_BD3DCC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->pos.x = x;
    temp_v0->pos.y = y;
    temp_v0->pos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_8024061C_BD3E8C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->rot.x = x;
    temp_v0->rot.y = y;
    temp_v0->rot.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_802406DC_BD3F4C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->scale.x = x;
    temp_v0->scale.y = y;
    temp_v0->scale.z = z;
    return ApiStatus_DONE2;
}

ApiStatus func_8024079C_BD400C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    return ApiStatus_DONE2;
}

ApiStatus func_80240808_BD4078(Evt* script, s32 isInitialCall) {
    if (gPlayerData.curHP < 2) {
        return ApiStatus_DONE2;
    }
    gPlayerData.curHP--;
    return ApiStatus_DONE2;
}
