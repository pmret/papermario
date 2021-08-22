#include "common.h"
#include "../partners.h"

ApiStatus CheckRideScriptForEnterExit(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    script->varTable[10] = 0;
    if (partner_get_ride_script() != NULL) {
        if (gPartnerActionStatus.actionState.b[0] == ACTION_STATE_IDLE) {
            script->varTable[10] = 0;
        } else {
            script->varTable[10] = 1;
            script->varTable[11] = partner_get_ride_script();
            script->varTable[13] = playerStatus->targetYaw;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus TeleportPartnerToPlayer(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* partner;

    if (gPlayerData.currentPartner == PARTNER_NONE) {
        return ApiStatus_DONE2;
    }

    partner = get_npc_unsafe(NPC_PARTNER);
    partner->pos.x = playerStatus->position.x;
    partner->pos.z = playerStatus->position.z;

    if (partner_is_flying()) {
        partner->pos.y = playerStatus->position.y;
    }

    set_npc_yaw(partner, playerStatus->targetYaw);
    partner_clear_player_tracking(partner);
    return ApiStatus_DONE2;
}

ApiStatus SetPlayerPositionFromSaveData(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 currentPartner = gPlayerData.currentPartner;

    playerStatus->position.x = gGameStatusPtr->savedPos.x;
    playerStatus->position.y = gGameStatusPtr->savedPos.y;
    playerStatus->position.z = gGameStatusPtr->savedPos.z;

    if (currentPartner != PARTNER_NONE) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);
        f32 angle = clamp_angle((playerStatus->spriteFacingAngle < 180.0f) ? (90.0f) : (-90.0f));

        partner->pos.x = playerStatus->position.x;
        partner->pos.y = playerStatus->position.y;
        partner->pos.z = playerStatus->position.z;
        add_vec2D_polar(&partner->pos.x, &partner->pos.z, playerStatus->colliderDiameter + 5, angle);
        enable_partner_ai();
    }

    camera->unk_08 = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/script_api/7E4690", EnterPlayerPostPipe);

ApiStatus ShortenPartnerTetherDistance(Evt* script, s32 isInitialCall) {
    partner_set_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

ApiStatus ResetPartnerTetherDistance(Evt* script, s32 isInitialCall) {
    repartner_set_tether_distance();
    return ApiStatus_DONE2;
}

ApiStatus PlayerMoveToDoor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = get_variable(script, *args++);
        move_player(script->functionTemp[0], playerStatus->targetYaw, playerStatus->runSpeed);
    }

    script->functionTemp[0]--;
    return script->functionTemp[0] < 0;
}

INCLUDE_ASM(s32, "world/script_api/7E4690", GetEntryCoords);

INCLUDE_ASM(s32, "world/script_api/7E4690", SetupSingleDoor);

INCLUDE_ASM(s32, "world/script_api/7E4690", SetupSplitSingleDoor);

INCLUDE_ASM(s32, "world/script_api/7E4690", SetupDoubleDoors);

INCLUDE_ASM(s32, "world/script_api/7E4690", SetupSplitDoubleDoors);
