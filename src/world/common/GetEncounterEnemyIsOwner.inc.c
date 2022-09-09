#include "common.h"
#include "npc.h"

ApiStatus N(GetEncounterEnemyIsOwner)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;

    evt_set_variable(script, LVar0, gCurrentEncounter.currentEnemy == enemy);
    return ApiStatus_DONE2;
}
