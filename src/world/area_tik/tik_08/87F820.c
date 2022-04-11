#include "tik_08.h"

#include "world/common/GetFloorCollider.inc.c"

extern s16 D_80242C0E_8819FE[0][2];

ApiStatus func_80240A5C_87F84C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 index = evt_get_variable(script, *args++);
    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = D_80242C0E_8819FE[index][0];
    return ApiStatus_DONE2;
}
