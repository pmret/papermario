#include "common.h"
#include "npc.h"

API_CALLABLE(N(func_80240814_97BE44)) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    npc->verticalRenderOffset = npc->collisionHeight;
    npc->pos.y -= (f32) npc->collisionHeight;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(AwaitPlayerNearNpc)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    if (dist2D(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z) < 50.0f) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802408B4_97BEE4)) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    if (isInitialCall) {
        npc->verticalRenderOffset = 0;
    }

    if (npc->flags & NPC_FLAG_GROUNDED) {
        currentEncounter->encounterList[enemy->encounterIndex]->battle = enemy->varTable[0];
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
