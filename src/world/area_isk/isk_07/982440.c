#include "isk_07.h"

static char* N(exit_str_0) = "isk_08";
static char* N(exit_str_1) = "isk_04";

#include "world/common/SetNpcB5_3.inc.c"

ApiStatus func_80240014_982454(Evt* script, s32 isInitialCall) {
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    s32 i, j;
    s32 count;

    script->varTable[1] = 0;
    count = 0;
    for (i = 0; i < encounterStatus->numEncounters; i++) {
        Encounter* encounter = encounterStatus->encounterList[i];
        if (encounter != NULL) {
            s32 hasEnemy = FALSE;
            for (j = 0; j < encounter->count; j++) {
                if (encounter->enemy[j] != NULL) {
                    hasEnemy = TRUE;
                }
            }
            if (hasEnemy) {
                count++;
            }
        }
    }
    
    if (count != 1) {
        return ApiStatus_DONE2;
    }
    script->varTable[1] = count;
    return ApiStatus_DONE2;
}
