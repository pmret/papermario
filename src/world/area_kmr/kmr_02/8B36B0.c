#include "kmr_02.h"

#include "world/common/todo/CheckPartnerFlags1000.inc.c"

extern s32* D_8025578C_8C57FC[4]; // EnemyTerritoryWander

NOP_FIX // TODO remove when D_8025578C_8C57FC is migrated
ApiStatus func_8024366C_8B36DC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 territoryIndex = evt_get_variable(script, *args++);
    s32* var_s0 = D_8025578C_8C57FC[territoryIndex];
    Enemy* enemy = get_enemy(npcID);
    s32 i;

    for (i = 0; i < (s32) (sizeof(enemy->territory->wander) / sizeof(i)); i++) {
        s32* wander = (s32*) &enemy->territory->wander;

        wander[i] = var_s0[i];
    }
    return ApiStatus_DONE2;
}
NOP_UNFIX // TODO remove when D_8025578C_8C57FC is migrated


#include "world/common/todo/UnkFunc42.inc.c"
