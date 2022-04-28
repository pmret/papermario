#include "world/common/enemy/state/Unk4AI_00.inc.c"

#include "world/common/enemy/state/Unk4AI_01.inc.c"

#include "world/common/enemy/state/Unk4AI_10.inc.c"

void N(Unk4AI_11)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->pos.y += npc->jumpVelocity;
    npc->jumpVelocity -= npc->jumpScale;

    if (!(npc->pos.y > npc->moveToPos.y)) {
        npc->pos.y = npc->moveToPos.y;
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~NPC_FLAG_JUMPING;
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

#include "world/common/enemy/state/Unk4AI_12.inc.c"

#include "world/common/enemy/state/Unk4AI_13.inc.c"

#include "world/common/enemy/state/Unk4AI_14.inc.c"

#include "world/common/enemy/state/Unk4AI_15.inc.c"

#include "world/common/enemy/state/Unk4AI_16.inc.c"

#include "world/common/enemy/state/Unk4AI_Main.inc.c"
