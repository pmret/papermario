#include "mim_05.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_80240278_BA09A8);
/*
s32 N(func_80240278_BA09A8)(ScriptInstance *script) {
    PlayerStatus** playerStatus = &gPlayerStatusPtr;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM(gCurrentCamID);
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    f32 phi_f20;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z) > enemy2->varTable[2]) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    } else {
        phi_f20 = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(phi_f20, atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z))) > enemy2->varTable[3]) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - (*playerStatus)->position.y)) {
        ret = FALSE;
    }

    if (D_8010EBB0.unk_03 == 9) {
        ret = FALSE;
    }

    if (D_8010EBB0.unk_03 == 7) {
        ret = FALSE;
    }

    return ret;
}
*/

#include "world/common/UnkFunc7.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_8024068C_BA0DBC);
/*
ApiStatus N(func_8024068C_BA0DBC)(ScriptInstance *script, s32 isInitialCall) {
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

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(func_80240278_BA09A8)(script)) {
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

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_80240940_BA1070);

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_802409AC_BA10DC);

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_80240AA8_BA11D8);

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_802414E8_BA1C18);

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_80241578_BA1CA8);

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_80241678_BA1DA8);

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_802416D8_BA1E08);

INCLUDE_ASM(s32, "world/area_mim/mim_05/BA07A0", func_802417C4_BA1EF4);
