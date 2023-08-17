#include "Blooper.h"

NpcSettings N(NpcSettings_Blooper) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

s32 N(BlooperBattles)[] = {
    BTL_TIK2_FORMATION_00,
    BTL_TIK2_FORMATION_01,
    BTL_TIK2_FORMATION_02,
};

API_CALLABLE(N(GetBlooperBattleID)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 index = evt_get_variable(script, *args++);

    gCurrentEncounter.encounterList[enemy->encounterIndex]->battle = N(BlooperBattles)[index];
    return ApiStatus_DONE2;
}
