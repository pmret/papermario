#include "common.h"
#include "npc.h"

s32 N(AttackAheadHitbox_CanSeePlayer)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    f32 angle;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) > enemy2->varTable[2]) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    } else {
        angle = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                     gPlayerStatusPtr->position.z))) > enemy2->varTable[3]) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - gPlayerStatusPtr->position.y)) {
        ret = FALSE;
    }

    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        ret = FALSE;
    }

    if (gPartnerActionStatus.actingPartner == PARTNER_SUSHIE) {
        ret = FALSE;
    }

    return ret;
}
