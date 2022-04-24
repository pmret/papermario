#include "common.h"
#include "npc.h"

s32 N(CleftAI_CanSeePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    f32 phi_f20;
    s32 ret = FALSE;

    if (func_800493EC(enemy, 0, aiSettings->alertRadius, aiSettings->unk_10.f)) {
        ret = TRUE;
    }
    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    } else {
        phi_f20 = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(phi_f20,
                                     atan2(npc->pos.x, npc->pos.z,
                                           gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z))) > 75.0) {
        ret = FALSE;
    }
    if (fabsf(npc->pos.y - gPlayerStatusPtr->position.y) >= 40.0f) {
        ret = FALSE;
    }
    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        ret = FALSE;
    }
    return ret;
}
