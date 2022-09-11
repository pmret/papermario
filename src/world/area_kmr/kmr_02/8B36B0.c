#include "kmr_02.h"

#include "world/common/CheckPartnerFlags1000.inc.c"

#ifdef NON_MATCHING
ApiStatus func_8024366C_8B36DC(Evt* script, s32 isInitialCall) {
    static s32* D_8025578C_8C57FC[4]; // EnemyTerritoryWander
    
    Bytecode* args = script->ptrReadPos;
    s32 enemyIndex = evt_get_variable(script, *args++);
    s32 territoryIndex = evt_get_variable(script, *args++);
    s32* src = D_8025578C_8C57FC[territoryIndex];
    Enemy* enemy = get_enemy(enemyIndex);   
    s32 i;
    
    for (i = 0; i < 0xE; i++) {
        enemy->territory.raw[i] = src[i];
    }
    
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B36B0", func_8024366C_8B36DC);
#endif

#include "world/common/UnkFunc42.inc.c"
