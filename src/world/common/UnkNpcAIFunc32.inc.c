#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc32)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;

    if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
        ai_enemy_play_sound(npc, 802, 0);
        fx_emote(0, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &temp);
        ai_enemy_play_sound(npc, 756, 0x200000);
        npc->currentAnim.w = enemy->animList[8];
        npc->duration = enemy->varTable[8];
        script->functionTemp[0] = 10;
    }
}
