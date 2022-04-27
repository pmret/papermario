#include "kpa_102.h"

#include "world/common/enemy/ProjectileAI.inc.c"

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

#include "world/common/enemy/LungeAI.inc.c"

#include "world/common/UnkNpcAIFunc47.inc.c"

#include "world/common/UnkFunc57.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_80242410_A95B50);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_8024244C_A95B8C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_802425D8_A95D18);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_802429C8_A96108);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_80242ABC_A961FC);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_80242D00_A96440);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_80242D3C_A9647C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_80242F08_A96648);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_80242F74_A966B4);

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_802430A8_A967E8);

void func_80243198_A968D8(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;
    
    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);
    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 10;
    }
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_80243270_A969B0);

#define NAMESPACE dup_kpa_102
#include "world/common/GetEncounterEnemyIsOwner.inc.c"
#define NAMESPACE kpa_102

INCLUDE_ASM(s32, "world/area_kpa/kpa_102/A93A50", func_8024353C_A96C7C);
