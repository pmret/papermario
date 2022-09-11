#include "iwa_00.h"
#include "effects.h"

static char* N(exit_str_0) = "iwa_10";
static char* N(exit_str_1) = "iwa_01";

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

// slightly modified version of OnDefeatEnemy which uses a spatialized death sound
ApiStatus func_80240118_90CD58(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 20;
    }
    if (script->functionTemp[1] & 1) {
        npc->flags &= ~NPC_FLAG_2;
    } else {
        npc->flags |= NPC_FLAG_2;
    }
    if (script->functionTemp[1] == 15) {
        sfx_play_sound_at_position(SOUND_DEATH, 0, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z);
        fx_damage_stars(1, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z, 0.0f, -1.0f, 0.0f, 0xA);
    }
    
    temp = script->functionTemp[1];
    if (script->functionTemp[1] == 10) {
        fx_big_smoke_puff(npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 10.0f);
        // odd logic needed to match
        if (script->functionTemp[1] == temp) {
            spawn_drops(enemy);
        }
    }
    
    script->functionTemp[1]--;
    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}
