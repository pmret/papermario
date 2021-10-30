#include "common.h"
#include "npc.h"

ApiStatus N(func_80240814_97BE44)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    npc->unk_AB = npc->collisionHeight;
    npc->pos.y -= (f32) npc->collisionHeight;

    return ApiStatus_DONE2;
}

ApiStatus N(AwaitPlayerNearNpc)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    if (dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z) < 50.0f) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802408B4_97BEE4)(Evt* script, s32 isInitialCall) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    if (isInitialCall) {
        npc->unk_AB = 0;
    }

    if (npc->flags & 0x1000) {
        currentEncounter->encounterList[enemy->encounterIndex]->battle = enemy->varTable[0];
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
