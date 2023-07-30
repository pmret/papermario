#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetEncounterEnemyIsOwner)) {
    Enemy* enemy = script->owner1.enemy;

    evt_set_variable(script, LVar0, gCurrentEncounter.curEnemy == enemy);
    return ApiStatus_DONE2;
}
