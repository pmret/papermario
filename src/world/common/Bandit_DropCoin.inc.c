#include "common.h"
#include "map.h"

ApiStatus N(Bandit_DropCoin)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcID;
    Npc* npc;
    s32 itemEntityIndex;
    s32 areaFlag;

    if (isInitialCall) {
        npcID = evt_get_variable(script, *args++);
        itemEntityIndex = evt_get_variable(script, *args++);
        areaFlag = *args++;

        if (npcID == -1) {
            npc = get_npc_unsafe(script->owner2.npcID);
        } else if (npcID >= -270000000) {
            npc = get_npc_unsafe(npcID);
        } else {
            npc = (Npc*)npcID;
        }

        script->functionTemp[0] = (s32)npc;
        script->functionTemp[1] = itemEntityIndex;
        script->functionTemp[2] = areaFlag;
    }

    npc = (Npc*)script->functionTemp[0];
    itemEntityIndex = script->functionTemp[1];
    areaFlag = script->functionTemp[2];

    if (evt_get_variable(script, areaFlag)) {
        set_item_entity_position(itemEntityIndex, npc->pos.x, npc->pos.y + 30.0f, npc->pos.z);
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}
