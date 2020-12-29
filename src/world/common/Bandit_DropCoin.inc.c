#include "common.h"
#include "map.h"

ApiStatus M(Bandit_DropCoin)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcId npcID;
    Npc* npc;
    s32 itemEntityIndex;
    s32 areaFlag;

    if (isInitialCall) {
        npcID = get_variable(script, *args++);
        itemEntityIndex = get_variable(script, *args++);
        areaFlag = *args++;

        if (npcID == -1) {
            npc = get_npc_unsafe(script->owner2.npcID);
        } else if (npcID >= -270000000) {
            npc = get_npc_unsafe(npcID);
        } else {
            npc = npcID;
        }

        script->functionTemp[0].s = npc;
        script->functionTemp[1].s = itemEntityIndex;
        script->functionTemp[2].s = areaFlag;
    }

    npc = script->functionTemp[0].s;
    itemEntityIndex = script->functionTemp[1].s;
    areaFlag = script->functionTemp[2].s;

    if (get_variable(script, areaFlag)) {
        set_item_entity_position(itemEntityIndex, npc->pos.x, npc->pos.y + 30.0f, npc->pos.z);
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}
