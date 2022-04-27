#include "common.h"
#include "npc.h"

s32 N(LakituAI_GetAvailableSpiny)(void) {
    s32 npcID;

    for (npcID = AI_LAKITU_FIRST_SPINY_ID; npcID <= AI_LAKITU_LAST_SPINY_ID; npcID++) {
        if (get_enemy(npcID)->varTable[10] == 0) {
            return npcID;
        }
    }

    return -1;
}
