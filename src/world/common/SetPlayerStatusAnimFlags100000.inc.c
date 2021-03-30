#include "common.h"
#include "map.h"

ApiStatus N(SetPlayerStatusAnimFlags100000)(ScriptInstance* script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    gPlayerStatusPtr->animFlags |= 0x100000;
    return ApiStatus_DONE2;
}
