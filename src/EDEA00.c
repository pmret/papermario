#include "dead.h"
#include "common.h"

// Copy of flo_13 (CC3850.c)

#define NAMESPACE EDEA00

extern f32 D_802441DC_EE2B9C[];

#include "world/common/UnkFunc41.inc.c"

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "EDEA00", func_80240374_EDED34);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void func_80240E18_EDF7D8(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += D_802441DC_EE2B9C[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "EDEA00", func_802414D0_EDFE90);

s32 func_802416E8_EE00A8(void) {
    s32 i;

    for (i = 50; i < 56; i++) {
        if (get_enemy(i)->varTable[10] == 0) {
            return i;
        }
    }

    return -1;
}

void func_80241730_EE00F0(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 var1 = enemy->varTable[4];
    f32 var2 = enemy->varTable[3];
    f32 var3;

    temp_f22 = var1 / 100.0;
    temp_f24 = var2 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var3 = enemy->varTable[1];
    temp_f20 = var3 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f24 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->unk_14;
            if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) != 0) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
                ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
                npc->moveToPos.y = y + temp_f24;
                script->functionTemp[0] = 12;
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape, enemy->territory->wander.point.x,
                               enemy->territory->wander.point.z, npc->pos.x, npc->pos.z, enemy->territory->wander.wanderSizeX,
                               enemy->territory->wander.wanderSizeZ) != 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->duration > 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (enemy->varTable[0] & 1) {
                x = npc->pos.x;
                y = temp_f22;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
                y += temp_f24;
                w = y - temp_f22;
                if (w > 2.0) {
                    temp_f22 += 2.0;
                } else if (w < -2.0) {
                    temp_f22 -= 2.0;
                } else {
                    temp_f22 = y;
                }
                enemy->varTable[4] = (temp_f22 * 100.0);
            }
            if (npc->duration > 0) {
                return;
            }
        }
        script->functionTemp[0] = 2;
        script->functionTemp[1] = (rand_int(1000) % 3) + 2;
        if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || (script->functionTemp[1] == 0)) {
            script->functionTemp[0] = 0;
        }
    }
}

void func_80241B94_EE0554(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 var1 = enemy->varTable[3];
    f32 var2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = var1 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var2 = enemy->varTable[1];
    temp_f20 = var2 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    npc_raycast_down_sides(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f22 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);
    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) != 0) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        script->functionTemp[0] = 12;
        return;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = (rand_int(1000) % 11) + 5;
            return;
        }
        script->functionTemp[0] = 0;
    }
}

INCLUDE_ASM(s32, "EDEA00", func_80241DE4_EE07A4);

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "EDEA00", func_80242684_EE1044);

INCLUDE_ASM(s32, "EDEA00", func_80242AF0_EE14B0);

#include "world/common/UnkFunc42.inc.c"

ApiStatus func_80243470_EE1E30(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(1);
    s16 param1;
    s16 param2;

    script->functionTemp[1] = evt_get_variable(script, *script->ptrReadPos);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == (script->functionTemp[0] / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
                                         &param1, &param2, 0x200002);

        sfx_play_sound_with_params(0x295, param1, param2,
                                   update_lerp(0, 500.0f, 0.0f, script->functionTemp[0], script->functionTemp[1]));
    }

    script->functionTemp[0]++;
    return (script->functionTemp[1] < script->functionTemp[0]) * ApiStatus_DONE2;
}

ApiStatus func_80243584_EE1F44(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);
    s16 param1;
    s16 param2;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == (script->functionTemp[0] / 5) * 5) {

        sfx_get_spatialized_sound_params(npc->pos.x, npc->pos.y, npc->pos.z,
                                         &param1, &param2, 0x200002);

        sfx_play_sound_with_params(0x295, param1, param2,
                                   update_lerp(0, 500.0f, 0.0f, script->functionTemp[0], 0x50));
    }

    script->functionTemp[0]++;
    return (script->functionTemp[0] > 0x50) * ApiStatus_DONE2;
}
