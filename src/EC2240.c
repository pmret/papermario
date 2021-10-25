#include "dead.h"
#include "common.h"

// Copy of flo_03 (CA72E0)

#define NAMESPACE EC2240

const char* ascii_EC7170 = "flo_09";
const char* ascii_EC7178 = "flo_22";
const char* ascii_EC7180 = "flo_18\0";

INCLUDE_ASM(s32, "EC2240", func_80240040_EC2240);

#include "world/common/DeadGetItemName.inc.c"

//const char* D_80244F98_EC7198 = "touch_choro\n";

#ifdef DATA_ISSUE
ApiStatus func_80240158_EC2358(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    f32 clamp = clamp_angle(atan2(-210.0f, -183.0f, gPlayerStatus.position.x, gPlayerStatus.position.z) + 180.0f);
    f32 sp10 = -210.0f;
    f32 sp14 = -183.0f;

    f32 temp_f20;
    f32 temp_f4_2;
    f64 temp_f4;
    f32 phi_f2;

    add_vec2D_polar(&sp10, &sp14, 46.0f, clamp);
    temp_f4 = dist2D(npc->pos.x, npc->pos.z, sp10, sp14);
    if (temp_f4 > 2.0) {
        temp_f20 = clamp_angle(atan2(-210.0f, -183.0f, npc->pos.x, npc->pos.z));
        temp_f4_2 = temp_f20 - clamp_angle(atan2(-210.0f, -183.0f, sp10, sp14));
        if (abs(temp_f4_2) >= 0x15) {
            phi_f2 = temp_f4_2;
            if (temp_f4_2 >= 180.0f) {
                phi_f2 = temp_f4_2 - 360.0f;
            }
            if (phi_f2 <= -180.0f) {
                phi_f2 += 360.0f;
            }
            if (temp_f4_2 == phi_f2) {
                sp10 = -210.0f;
                sp14 = -183.0f;
                if (temp_f4_2 >= 0.0f) {
                    clamp = clamp_angle(temp_f20 - 20.0f);
                } else {
                    clamp = clamp_angle(temp_f20 + 20.0f);
                }
                add_vec2D_polar(&sp10, &sp14, 46.0f, clamp);
            } else {
                osSyncPrintf("cccc\n");
            }
        }
        npc->currentAnim.w = enemy->animList[2];
        npc->yaw = atan2(npc->pos.x, npc->pos.z, sp10, sp14);
        npc_move_heading(npc, 2.0f, npc->yaw);
    } else if (temp_f4 > 0.2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, sp10, sp14);
        npc->pos.x = sp10;
        npc->pos.z = sp14;
        npc->currentAnim.w = enemy->animList[1];
    } else {
        npc->pos.x = sp10;
        npc->pos.z = sp14;
        npc->currentAnim.w = enemy->animList[0];
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EC2240", func_80240158_EC2358);
#endif
