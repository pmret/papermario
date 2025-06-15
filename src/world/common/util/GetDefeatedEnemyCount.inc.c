#include "common.h"

API_CALLABLE(N(GetDefeatedEnemyCount)) {
    Bytecode* args = script->ptrReadPos;
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    s32 enemyCount = 0;
    s32 i, j;

    for (i = 0; i < encounterStatus->numEncounters; i++) {
        Encounter* temp = encounterStatus->encounterList[i];
        if (temp == nullptr) {
            continue;
        }
        for (j = 0; j < temp->count; j++) {
            if (temp->enemy[j] != nullptr) {
                enemyCount++;
            }
        }
    }

    evt_set_variable(script, *args++, enemyCount);
    return ApiStatus_DONE2;
}
