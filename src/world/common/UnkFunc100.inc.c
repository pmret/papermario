#include "common.h"
 
ApiStatus N(UnkFunc100)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1].s <= 0) {
        script->functionTemp[1].s = aiSettings->unk_14;
        if (func_800490B4(shape, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.s, 0)) {
            npc->currentAnim = enemy->animList[9];
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
            func_800494C0(npc, 0x2F4, 0x200000);
            npc->duration = 12;
            script->functionTemp[0].s = 2;
        }
    }

    script->functionTemp[1].s--;
}
