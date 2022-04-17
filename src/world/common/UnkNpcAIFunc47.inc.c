#include "common.h"
#include "npc.h"

// TODO apiStatus?
s32 N(UnkNpcAIFunc47)(Evt* script, f32 arg1, f32 arg2, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];

    if (basic_ai_try_detect_player(territory, enemy, arg1, arg2, 0)) {
        f32 angle;
        f32 t1;

        if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
            angle = 90.0f;
        } else {
            angle = 270.0f;
        }

        t1 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        if (fabsf(get_clamped_angle_diff(angle, t1)) > 75.0) {
            return -1;
        }

        t1 = atan2(0.0f, npc->pos.y, fabsf(npc->pos.x - gPlayerStatusPtr->position.x), gPlayerStatusPtr->position.y);
        if (fabsf(t1 - 90.0) > 70.0) {
            return -1;
        }

        if (gPartnerActionStatus.actingPartner == PARTNER_BOW || gPartnerActionStatus.actingPartner == PARTNER_SUSHIE) {
            return -1;
        }

        if ((get_enemy(enemy->npcID + 1)->varTable[0] == 0)) {
            return 1;
        }
    }

    return -1;
}
