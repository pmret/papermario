#include "common.h"
#include "../partners.h"

extern s32 DoorModelsSwingCCW[3];
extern s32 DoorModelsSwingCW[3];

ApiStatus CheckRideScriptForEnterExit(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    script->varTable[10] = 0;
    if (partner_get_ride_script() != NULL) {
        if (gPartnerActionStatus.partnerActionState == ACTION_STATE_IDLE) {
            script->varTable[10] = 0;
        } else {
            script->varTable[10] = 1;
            script->varTablePtr[11] = partner_get_ride_script();
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

    camera->changingMap = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus EnterPlayerPostPipe(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    MapSettings* mapSettings = get_current_map_settings();
    ApiStatus ret = ApiStatus_BLOCK;

    if (isInitialCall) {
        playerStatus->position.x = (*mapSettings->entryList)[gGameStatusPtr->entryID].x;
        playerStatus->position.z = (*mapSettings->entryList)[gGameStatusPtr->entryID].z;
        script->varTable[2] = (*mapSettings->entryList)[gGameStatusPtr->entryID].y;
        playerStatus->position.y = script->varTable[2] - 40;
        playerStatus->flags |= PS_FLAGS_CAMERA_DOESNT_FOLLOW;
    } else {
        do {
            playerStatus->position.y += 1.0f;
            if (!(playerStatus->position.y < script->varTable[2])) {
                playerStatus->position.y = script->varTable[2];
                playerStatus->flags &= ~PS_FLAGS_CAMERA_DOESNT_FOLLOW;
                ret = ApiStatus_DONE2;
            }
        } while (0); // todo required to match
    }
    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
    return ret;
}

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
        script->functionTemp[0] = evt_get_variable(script, *args++);
        move_player(script->functionTemp[0], playerStatus->targetYaw, playerStatus->runSpeed);
    }

    script->functionTemp[0]--;
    return script->functionTemp[0] < 0;
}

ApiStatus GetEntryCoords(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    MapSettings* mapSettings = get_current_map_settings();
    Vec4f* entryList = (Vec4f*)mapSettings->entryList;
    s32 index = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, entryList[index].x);
    evt_set_variable(script, *args++, entryList[index].y);
    evt_set_variable(script, *args++, entryList[index].z);
    evt_set_variable(script, *args++, entryList[index].yaw);

    return ApiStatus_DONE2;
}

ApiStatus SetupSingleDoor(Evt* script, s32 isInitialCall) {
    if (script->varTable[3] >= 0) {
        DoorModelsSwingCCW[0] = script->varTable[2];
        DoorModelsSwingCCW[1] = -1;
        DoorModelsSwingCW[0] = -1;
    } else {
        DoorModelsSwingCW[0] = script->varTable[2];
        DoorModelsSwingCW[1] = -1;
        DoorModelsSwingCCW[0] = -1;
    }

    script->varTablePtr[2] = &DoorModelsSwingCCW;
    script->varTablePtr[3] = &DoorModelsSwingCW;

    return ApiStatus_DONE2;
}

ApiStatus SetupSplitSingleDoor(Evt* script, s32 isInitialCall) {
    if (script->varTable[3] >= 0) {
        DoorModelsSwingCCW[0] = script->varTable[2];
        DoorModelsSwingCCW[1] = script->varTable[4];
        DoorModelsSwingCCW[2] = -1;
        DoorModelsSwingCW[0] = -1;
    } else {
        DoorModelsSwingCW[0] = script->varTable[2];
        DoorModelsSwingCW[1] = script->varTable[4];
        DoorModelsSwingCW[2] = -1;
        DoorModelsSwingCCW[0] = -1;
    }

    script->varTablePtr[2] = &DoorModelsSwingCCW;
    script->varTablePtr[3] = &DoorModelsSwingCW;

    return ApiStatus_DONE2;
}

ApiStatus SetupDoubleDoors(Evt* script, s32 isInitialCall) {
    DoorModelsSwingCCW[0] = script->varTable[2];
    DoorModelsSwingCCW[1] = -1;

    DoorModelsSwingCW[0] = script->varTable[3];
    DoorModelsSwingCW[1] = -1;

    script->varTablePtr[3] = &DoorModelsSwingCW;
    script->varTablePtr[2] = &DoorModelsSwingCCW;

    return ApiStatus_DONE2;
}

ApiStatus SetupSplitDoubleDoors(Evt* script, s32 isInitialCall) {
    DoorModelsSwingCCW[0] = script->varTable[2];
    DoorModelsSwingCCW[1] = script->varTable[4];
    DoorModelsSwingCCW[2] = -1;

    DoorModelsSwingCW[0] = script->varTable[3];
    DoorModelsSwingCW[1] = script->varTable[5];
    DoorModelsSwingCW[2] = -1;

    script->varTablePtr[3] = &DoorModelsSwingCW;
    script->varTablePtr[2] = &DoorModelsSwingCCW;

    return ApiStatus_DONE2;
}
