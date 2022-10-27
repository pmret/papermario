#include "omo_14.h"

ApiStatus func_80240160_DE5810(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    f32 x = playerStatus->position.x +
        ((playerStatus->colliderDiameter + npc->collisionRadius) * 0.5f * sin_deg((npc->npcID * 360.0f) / 10.0f));
    f32 z = playerStatus->position.z -
        ((playerStatus->colliderDiameter + npc->collisionRadius) * 0.5f * cos_deg((npc->npcID * 360.0f) / 10.0f));
    f32 dist = dist2D(npc->pos.x, npc->pos.z, x, z);

    if (npc->moveSpeed < dist) {
        if (npc->flags & 0x2000) {
            if (npc->yaw < 180.0f) {
                npc->yaw = npc->pos.z > 0.0f ? 45.0f : 135.0f;
            } else {
                npc->yaw = npc->pos.z > 0.0f ? 315.0f : 225.0f;
            }
        } else {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        }
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    } else {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
    }

    if (script->varTableF[11] == playerStatus->position.x && script->varTableF[13] == playerStatus->position.z) {
        if (dist < 20.0f) {
            script->varTable[14]++;
        } else {
            script->varTable[14] = 0;
        }
    }
    script->varTableF[11] = playerStatus->position.x;
    script->varTableF[12] = playerStatus->position.y;
    script->varTableF[13] = playerStatus->position.z;
    return ApiStatus_DONE2;
}

ApiStatus func_802403FC_DE5AAC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    f32 x = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    if (npc->moveSpeed < dist2D(npc->pos.x, npc->pos.z, x, z)) {
        if (npc->flags & NPC_FLAG_NO_PROJECT_SHADOW) {
            if (npc->yaw < 180.0f) {
                npc->yaw = npc->pos.z > 0.0f ? 45.0f : 135.0f;
            } else {
                npc->yaw = npc->pos.z > 0.0f ? 315.0f : 225.0f;
            }
        } else {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        }
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240564_DE5C14(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.partnerActionState != 0) {
        script->varTable[9] = gPartnerActionStatus.actingPartner;
    } else {
        script->varTable[9] = -1;
    }
    return ApiStatus_DONE2;
}

ApiStatus N(IsPartnerWatt)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.actingPartner == PARTNER_WATT) {
        script->varTable[1] = TRUE;
    } else {
        script->varTable[1] = FALSE;
    }
    return ApiStatus_DONE2;
}
