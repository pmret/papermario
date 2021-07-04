#include "nok_15.h"

static char* N(exit_str_0) = "nok_14";
static char* N(exit_str_1) = "trd_00";
static char* N(exit_str_2) = "nok_15";
static char* N(exit_str_3) = "";

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_80240674_A07574);

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_80240C64_A07B64);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_80241708_A08608);
/*
void N(func_80241708_A08608)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80243D5C_A0AC5C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_80241DC0_A08CC0);
/*
ApiStatus N(func_80241DC0_A08CC0)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_80241C9C_A08B9C)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
#include "world/common/UnkNpcAIFunc23.inc.c"
        case 1:
            N(func_80240C64_A07B64)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_8024134C_A0824C)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241708_A08608)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_8024190C_A0880C)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_80241FAC_A08EAC);

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_802420D4_A08FD4);

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_80242190_A09090);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_15/A06F00", func_802422EC_A091EC);
