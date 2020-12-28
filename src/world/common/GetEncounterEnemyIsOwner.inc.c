#include "common.h"
#include "map.h"

ApiStatus M(GetEncounterEnemyIsOwner)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;

    set_variable(script, SI_VAR(0), gCurrentEncounter.currentEnemy == enemy);
    return ApiStatus_DONE2;
}
