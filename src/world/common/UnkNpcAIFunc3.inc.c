#include "common.h"
#include "map.h"

static void UnkNpcAIFunc3(ScriptInstance* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    if ((npc->duration <= 0) || ((--npc->duration << 0x10) <= 0)) {
        if (npc->unk_8C == 0) {
            npc->duration = 0;
            script->functionTemp[0].s = 14;
        }
    }
}
