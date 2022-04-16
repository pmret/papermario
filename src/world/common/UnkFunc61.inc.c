#include "common.h"
#include "npc.h"

s32 N(UnkFunc61)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[gCurrentCamID];
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32* temp_v0 = (f32*)evt_get_variable(script, *args++); // TODO figure out what this is
    f32 angle;
    f32 t0;
    f32 t1;
    s32 i;

    if (func_800493EC(enemy, 0, temp_v0[9], temp_v0[10])) {
        if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
            angle = 90.0f;
        } else {
            angle = 270.0f;
        }

        t0 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        t1 = get_clamped_angle_diff(angle, t0);
        if (fabsf(t1) > 75.0 || (2.0 * npc->collisionHeight <= fabsf(npc->pos.y - gPlayerStatusPtr->position.y))) {
           return -1;
        }
        if (gPartnerActionStatus.actionState.b[3] == PARTNER_BOW) {
            return -1;
        }
        if (gPartnerActionStatus.actionState.b[3] == PARTNER_SUSHIE) {
            return -1;
        }

        for (i = 0; i < enemy->varTable[3]; i++) {
            s32 enemy2ID = enemy->npcID + i + 1;
            Enemy* enemy2 = get_enemy(enemy2ID);

            get_npc_unsafe(enemy2ID);

            if (enemy2->varTable[0] == 0) {
                return enemy2ID;
            }
        }
    }
    return -1;
}
