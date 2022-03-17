#include "common.h"
#include "npc.h"

void N(UnkFunc59)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    f32 temp_f0 = (rand_int(100) % 2) * 180.0f;

    npc->duration = 15;
    npc->moveSpeed = 0.8f;
    npc->yaw = temp_f0 + 90.0f;
    script->functionTemp[0] = 6;
}
