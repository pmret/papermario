#include "tik_01.h"

extern s16 D_80242B7E_86C02E[0][2];

ApiStatus func_80240A30_869EE0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 index = evt_get_variable(script, *args++);

    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = D_80242B7E_86C02E[index][0];
    return ApiStatus_DONE2;
}
