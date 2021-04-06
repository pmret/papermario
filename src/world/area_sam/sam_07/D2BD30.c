#include "sam_07.h"

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240000_D2BD30);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240448_D2C178);

#include "world/common/GetEntityPosition.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_802405B0_D2C2E0);

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240858_D2C588);
/*
s32 N(func_80240858_D2C588)(ScriptInstance *script) {
    PlayerStatus** playerStatus = &gPlayerStatusPtr;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM2(D_8009A634);
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

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240A0C_D2C73C);
/*
ApiStatus N(func_80240A0C_D2C73C)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Enemy* enemy2;
    Npc* npc2;
    f32 posX, posZ;
    s32 func;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->flags |= 0x102;
        enemy->flags |= 0x1F300000;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
        if (enemy->unk_B0 & 4) {
            enemy->unk_B0 &= ~4;
        }
    }

    func = script->functionTemp[0].s;
    switch (func) {
        case 0:
            enemy2 = get_enemy(enemy->npcID - 1);
            npc2 = get_npc_unsafe(enemy2->npcID);
            enemy->unk_07 = 1;
            if (enemy2->varTable[0] == 3) {
                if (enemy->varTable[15] != 0) {
                    func_800494C0(npc2, enemy->varTable[15], 0);
                }
                posX = npc2->pos.x;
                posZ = npc2->pos.z;
                add_vec2D_polar(&posX, &posZ, enemy->varTable[1], 270.0f - npc2->unk_34);
                
                npc->pos.x = posX;
                enemy->unk_10.x = npc->pos.x;

                npc->pos.y = npc2->pos.y + enemy->varTable[0];
                enemy->unk_10.y = npc->pos.y;
                
                npc->pos.z = posZ;
                enemy->unk_10.z = npc->pos.z;
                
                npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                enemy->flags &= 0xE0EFFFFF;
                npc->duration = 0;
                script->functionTemp[0].s = 1;
            }
            break;

        case 1:
            enemy2 = get_enemy(enemy->npcID - 1);
            get_npc_unsafe(enemy2->npcID);
            npc->duration++;
            if (npc->duration >= enemy->varTable[4]) {
                enemy->unk_07 = 0;
            }
            if (enemy2->varTable[0] == 4) {
                enemy->flags |= 0x1F100000;
                npc->pos.x = 0.0f;
                npc->pos.y = -1000.0f;
                npc->pos.z = 0.0f;
                enemy->unk_07 = func;
                script->functionTemp[0].s = 0;
            }
            break; 
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240C6C_D2C99C);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240F20_D2CC50);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80240F8C_D2CCBC);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241088_D2CDB8);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241AC8_D2D7F8);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241B58_D2D888);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241C58_D2D988);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241CB8_D2D9E8);

INCLUDE_ASM(s32, "world/area_sam/sam_07/D2BD30", func_80241DA4_D2DAD4);
