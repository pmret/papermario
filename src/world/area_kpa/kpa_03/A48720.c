#include "kpa_03.h"

#include "world/common/atomic/enemy/UnkAI_5.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/UnkNpcAIFunc47.inc.c"

#include "world/common/UnkFunc57.inc.c"

#include "world/common/UnkFunc58.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_8024119C_A4975C);

#include "world/common/UnkFunc59.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241368_A49928);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802413CC_A4998C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_8024150C_A49ACC);

void func_802416B0_A49C70(Evt* script) {
    get_npc_unsafe(script->owner1.enemy->npcID)->duration = 40;
    script->functionTemp[0] = 21;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802416EC_A49CAC);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802418AC_A49E6C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241918_A49ED8);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241A4C_A4A00C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241AB4_A4A074);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241D20_A4A2E0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241D6C_A4A32C);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241DFC_A4A3BC);
