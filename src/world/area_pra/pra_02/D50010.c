#include "pra_02.h"

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_8024114C_D5113C);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 pra_02_D_80243CC0[];

ApiStatus func_802411D8_D511C8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            pra_02_D_80243CC0[i] = ptr[i];
        }
        pra_02_D_80243CC0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            pra_02_D_80243CC0[i] = i + 16;
            pra_02_D_80243CC0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 pra_02_80243E88[];

ApiStatus func_80241274_D51264(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            pra_02_80243E88[i] = ptr[i];
        }
        pra_02_80243E88[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            pra_02_80243E88[i] = i + 128;
            pra_02_80243E88[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

#include "world/common/todo/UnkFunc44.inc.c"

ApiStatus func_802414A8_D51498(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIdx = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    f32 temp = evt_get_float_variable(script, MapVar(0));
    Entity* entity;

    if (entityIdx == -1) {
        return ApiStatus_DONE2;
    }

    entity = get_entity_by_index(entityIdx);
    entity->position.x = x;
    entity->position.y = y + temp;
    entity->position.z = z;
    return ApiStatus_DONE2;
}

#include "world/common/todo/RemovePadlock.inc.c"

#define NAMESPACE dup_pra_02
#include "world/common/todo/GetEntityPosition.inc.c"
#define NAMESPACE pra_02
