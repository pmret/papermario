#include "nok_14.h"

static char* N(exit_str_0) = "nok_13";
static char* N(exit_str_1) = "nok_15";

// copy of func_80240000_9FA7F0
ApiStatus func_80240000_A02840(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    Bytecode *args = script->ptrReadPos;
    s32 xMin = evt_get_variable(script, *args++);
    s32 xMax = evt_get_variable(script, *args++);
    s32 zMin = evt_get_variable(script, *args++);
    s32 zMax = evt_get_variable(script, *args++);
    s32 var5 = evt_get_variable(script, *args++);
    s32 var6 = evt_get_variable(script, *args++);
    s32 stage = var5;
    s32 i;

    if (xMin <= playerStatus->position.x && playerStatus->position.x <= xMax &&
        zMin <= playerStatus->position.z && playerStatus->position.z <= zMax)
    {
        stage = var6;
    }

    for (i = 0; i < encounterStatus->numEncounters; i++) {
        encounterStatus->encounterList[i]->stage = stage;
    }
    return ApiStatus_DONE2;
}
