#include "trd_09.h"

static char* N(exit_str_0) = "trd_01";
static char* N(exit_str_1) = "trd_10";
static char* N(exit_str_2) = "trd_09";
static char* N(exit_str_3) = "";

ApiStatus func_80240000_9BD660(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 varIdx = evt_get_variable(script, *args++);
    s32 var3 = *args++;

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);
    if (npc != NULL) {
        evt_set_variable(script, var3, npc->varTable[varIdx]);
    } else {
        evt_set_variable(script, var3, -1);
    }

    return ApiStatus_DONE2;
}
