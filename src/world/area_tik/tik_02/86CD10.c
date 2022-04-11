#include "tik_02.h"

#include "world/common/UnkPosFunc2.inc.c"

extern s16 D_80241BAE_86E2EE[0][2]; // length unk

ApiStatus func_80240940_86D080(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 index = evt_get_variable(script, *args++);
    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = D_80241BAE_86E2EE[index][0];
    return ApiStatus_DONE2;
}
