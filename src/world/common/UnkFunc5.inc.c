#include "common.h"
#include "map.h"

void N(UnkFunc5)(Npc *npc, Enemy *enemy, ScriptInstance *script, NpcAISettings *aiSettings) {
    f32 posX, posY, posZ, posW;
    s32 temp_a1;
    s32 temp_v1;
    s32 phi_v0;

    script->functionTemp[0].s = 0;
    npc->duration = 0;
    temp_v1 = npc->flags & ~0x200;
    npc->flags = (npc->flags & ~0x200) | 0x800;
    if (enemy->territory->wander.isFlying) {
        npc->flags = temp_v1 | 0x808;
    } else {
        npc->flags = npc->flags & ~8;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
    enemy->varTable[2] = 0;
    enemy->varTable[9] = 0;
    enemy->varTable[3] = ((posW * 100.0) + 0.5);
    enemy->varTable[7] = ((posY * 100.0) + 0.5);
    script->functionTemp[1].s = aiSettings->unk_14;
    enemy->unk_B0 |= 0x10;
}
