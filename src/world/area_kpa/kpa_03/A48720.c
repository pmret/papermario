#include "kpa_03.h"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/UnkNpcAIFunc47.inc.c"

#include "world/common/UnkFunc57.inc.c" // spell hitbox

#include "world/common/enemy/MagikoopaAI.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241D20_A4A2E0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241D6C_A4A32C);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

ApiStatus func_80241DFC_A4A3BC(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (enemy->varTable[0] == 2) {
        npc->jumpVelocity = 0.0f;
        npc->moveSpeed = 0.0f;
    }
    return ApiStatus_DONE2;
}
