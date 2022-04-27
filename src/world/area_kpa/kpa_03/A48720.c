#include "kpa_03.h"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/UnkNpcAIFunc47.inc.c"

#include "world/common/UnkFunc57.inc.c"

#include "world/common/UnkFunc58.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_8024119C_A4975C);

#include "world/common/UnkFunc59.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241368_A49928);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802413CC_A4998C);

void func_8024150C_A49ACC(Evt* arg0, NpcAISettings* arg1, EnemyTerritoryThing* arg2) {
    Enemy* enemy = arg0->owner1.enemy;
    Npc* npc = get_npc_unsafe((s32) enemy->npcID);
    f32 scale;
    s16 alpha;
    
    if (enemy->varTable[0] == 0) {
        alpha = (npc->duration * 15) + 130;
    } else {
        alpha = (npc->duration * 15) + 30;
    }
    if (alpha >= 0x100) {
        alpha = 0xFF;
    }
    npc->alpha = alpha;
    
    npc->scale.x = ((f32)npc->duration * 0.1) + 0.4;
    if (npc->scale.x > 1.0) {
       npc->scale.x = 1.0f;
    }
    npc->scale.y = npc->scale.x;
    npc->scale.z = npc->scale.x;
    
    npc->duration++;
    if (npc->duration == 5) {
        enable_npc_shadow(npc);
        enemy->flags &= 0xE0EFFFFF;
    }
    if (enemy->varTable[0] == 0) {
        if (npc->duration >= 20) {
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
            npc->alpha = 0xFF;
            npc->scale.x = 1.0f;
            npc->scale.y = 1.0f;
            npc->scale.z = 1.0f;
            arg0->functionTemp[0] = 20;
        }
    } else if (npc->duration >= 10) {
        npc->alpha = 0xFF;
        npc->scale.x = 1.0f;
        npc->scale.y = 1.0f;
        npc->scale.z = 1.0f;
        arg0->functionTemp[0] = 20;
    }
}

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
