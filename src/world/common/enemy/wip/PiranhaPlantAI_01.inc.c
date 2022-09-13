#include "common.h"
#include "npc.h"
#include "effects.h"

void N(PiranhaPlantAI_01)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;

    if (basic_ai_check_player_dist(territory, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist, 0)) {
        ai_enemy_play_sound(npc, 802, 0);
        fx_emote(EMOTE_EXCLAMATION, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &temp);
        ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
        npc->currentAnim = enemy->animList[ENEMY_ANIM_MELEE_PRE];
        npc->duration = enemy->varTable[8];
        script->functionTemp[0] = 10;
    }
}
