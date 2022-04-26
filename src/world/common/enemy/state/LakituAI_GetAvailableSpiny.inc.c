#include "common.h"
#include "npc.h"

// required include args
#ifndef AI_LAKITU_FIRST_SPINY_ID
#error  AI_LAKITU_FIRST_SPINY_ID must be defined for LakituAI.inc.c
#define AI_LAKITU_FIRST_SPINY_ID 0
#endif
#ifndef AI_SENTINEL_LAST_SPINY_ID
#error  AI_SENTINEL_LAST_SPINY_ID must be defined for LakituAI.inc.c
#define AI_SENTINEL_LAST_SPINY_ID 0
#endif

s32 N(LakituAI_GetAvailableSpiny)(void) {
    s32 npcID;

    for (npcID = AI_LAKITU_FIRST_SPINY_ID; npcID <= AI_SENTINEL_LAST_SPINY_ID; npcID++) {
        if (get_enemy(npcID)->varTable[10] == 0) {
            return npcID;
        }
    }

    return -1;
}
