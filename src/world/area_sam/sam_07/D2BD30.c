#include "sam_07.h"

static char* N(exit_str_0) = "sam_04";
static char* N(exit_str_1) = "sam_08";

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240000_D2BD30);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240448_D2C178);

#include "world/common/GetEntityPosition.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_802405B0_D2C2E0);

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240C6C_D2C99C);
/*
ApiStatus N(func_80240C6C_D2C99C)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(UnkNpcAIFunc26)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, npcAISettings, territoryPtr);
        case 1:
            func_800496B8(script, npcAISettings, territoryPtr);
            break;
        case 2:
            base_UnkNpcAIFunc1(script, npcAISettings, territoryPtr);
        case 3:
            func_80049C04(script, npcAISettings, territoryPtr);
            break;
        case 10:
            func_80049E3C(script, npcAISettings, territoryPtr);
        case 11:
            func_80049ECC(script, npcAISettings, territoryPtr);
            break;
        case 12:
            func_80049F7C(script, npcAISettings, territoryPtr);
        case 13:
            func_8004A124(script, npcAISettings, territoryPtr);
            break;
        case 14:
            func_8004A3E8(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(UnkNpcAIFunc6)(script);
        case 31:
            N(UnkNpcAIFunc7)(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->functionTemp[0] != 33) {
                break;
            }
        case 33:
            N(UnkNpcAIFunc5)(script);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240F20_D2CC50);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240F8C_D2CCBC);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241088_D2CDB8);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241AC8_D2D7F8);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241B58_D2D888);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241C58_D2D988);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241CB8_D2D9E8);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241DA4_D2DAD4);
