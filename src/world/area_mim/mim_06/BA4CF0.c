#include "mim_06.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80240778_BA4EF8);
/*
s32 N(func_80240778_BA4EF8)(ScriptInstance *script) {
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

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_8024092C_BA50AC);
/*
ApiStatus N(func_8024092C_BA50AC)(ScriptInstance *script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80240B8C_BA530C);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80240E40_BA55C0);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80240EAC_BA562C);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80240FA8_BA5728);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_802419E8_BA6168);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80241A78_BA61F8);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80241B78_BA62F8);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80241BD8_BA6358);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80241CC4_BA6444);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80241F14_BA6694);

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80242144_BA68C4);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_8024253C_BA6CBC);

#include "world/common/UnkNpcAIFunc15.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_802427C0_BA6F40);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_06/BA4CF0", func_80242B04_BA7284);