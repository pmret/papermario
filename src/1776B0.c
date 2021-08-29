#include "common.h"

extern s8 D_80280CE0;
extern s32 D_80280CE4;

// battle cam
extern f32 D_8029F270; // pos x
extern f32 D_8029F274; // pos y
extern f32 D_8029F278; // pos z
extern s16 D_8029F27C; // actor ID
extern s16 D_8029F27E;
extern s16 D_8029F280; // radial distance from target
extern s16 D_8029F282; // yaw
extern s16 D_8029F284; // pitch
extern s16 D_8029F286;
extern f32 D_8029F288;
extern f32 D_8029F28C;
extern f32 D_8029F290;
extern f32 D_8029F294;
extern f32 D_8029F298;
extern s8 D_8029F29C;
extern s16 D_8029F29E;
extern s8 D_8029F2A2;
extern s8 D_8029F2A3;
extern s8 D_8029F2A4;
extern s8 D_8029F2A5;
extern s8 D_8029F2A6;

ApiStatus func_80248DD0(Evt* script, s32 isInitialCall) {
    D_8029F29C = 1;
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "1776B0", func_80248DE4);

INCLUDE_ASM(s32, "1776B0", func_80249804);

INCLUDE_ASM(s32, "1776B0", func_8024A214);

INCLUDE_ASM(s32, "1776B0", func_8024A990);

INCLUDE_ASM(s32, "1776B0", func_8024AFE4);

INCLUDE_ASM(s32, "1776B0", func_8024B5FC);

INCLUDE_ASM(s32, "1776B0", func_8024B9A0);

INCLUDE_ASM(s32, "1776B0", func_8024BDA4);

INCLUDE_ASM(s32, "1776B0", func_8024C180);

INCLUDE_ASM(s32, "1776B0", func_8024C570);

ApiStatus func_8024C944(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 screenX, screenY, screenZ;
    f32 deltaY;
    f32 y;
    s32 actorID;
    s32 actorType;

    if (isInitialCall) {
        D_8029F270 = camera->unk_54;
        D_8029F274 = camera->unk_58;
        D_8029F278 = camera->unk_5C;
        D_8029F288 = camera->unk_1E;
        D_8029F290 = camera->unk_24;
        D_8029F294 = camera->unk_22;
    }

    y = 0.0f;
    actorType = D_8029F27C & 0x700;
    actorID = D_8029F27C & 0xFF;

    switch (actorType) {
        case 0:
            if (battleStatus->playerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->playerActor->currentPos.y + (playerStatus->colliderHeight / 2);
            break;
        case 0x100:
            if (battleStatus->partnerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->partnerActor->currentPos.y;
            break;
        case 0x200:
            if (battleStatus->enemyActors[actorID] == NULL) {
                return ApiStatus_BLOCK;
            }
            y = battleStatus->enemyActors[actorID]->currentPos.y;
            break;
    }

    get_screen_coords(1, D_8029F270, y, D_8029F278, &screenX, &screenY, &screenZ);

    if (screenY < 100) {
        y += 25.0f;
    }

    if (y < D_8029F274) {
        y = D_8029F274;
    }

    deltaY = y - camera->unk_58;
    if (fabsf(deltaY) < 0.01) {
        if (deltaY != 0.0f) {
            camera->unk_58 = y;
        }
    } else {
        camera->unk_58 += deltaY / 5.0f;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "1776B0", func_8024CB68);

ApiStatus func_8024CE9C(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];

    D_8029F284 = 8;
    camera->unk_24 = 0;
    camera->unk_26 = 0;
    D_8029F282 = D_8029F286 = 0;
    D_80280CE0 = 0;
    D_8029F288 = camera->unk_1C;
    D_8029F28C = camera->unk_1E;
    D_8029F294 = camera->unk_22;
    D_8029F298 = D_8029F290 = 0.0f;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "1776B0", btl_cam_use_preset);

void func_8024E3D8(arg0) {
    if (D_80280CE0 == 0) {
        D_8029F2A4 = 1;
        btl_cam_use_preset(arg0);
    }
}

void func_8024E40C(s32 arg0) {
    if (D_80280CE0 == 0) {
        D_8029F2A4 = 0;
        btl_cam_use_preset(arg0);
    }
}

void btl_cam_target_actor(ActorID actorID) {
    if (D_80280CE0 == 0) {
        D_8029F27C = actorID;
    }
}

void func_8024E45C(ActorID actorID, s32 arg1) {
    if (D_80280CE0 == 0) {
        D_8029F27C = actorID;
        D_8029F27E = arg1;
    }
}

void func_8024E484(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 zoomPercent) {
    Camera* camera = &gCameras[1];

    if (D_80280CE0 == 0) {
        camera->unk_1C = arg0;
        camera->unk_1E = arg1;
        camera->unk_20 = arg2;
        camera->unk_22 = arg3;
        camera->unk_24 = arg4;
        camera->unk_26 = arg5 * 256;
        camera->unk_28 = arg6;
        camera->zoomPercent = zoomPercent;
    }
}

void btl_cam_move(s16 arg0) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (D_80280CE0 == 0) {
        D_8029F29E = arg0;
        if (battleStatus->camMovementScript != NULL) {
            restart_script(battleStatus->camMovementScript);
        }
    }
}

void btl_cam_set_target_pos(f32 x, f32 y, f32 z) {
    if (D_80280CE0 == 0) {
        D_8029F270 = x;
        D_8029F274 = y;
        D_8029F278 = z;
    }
}

void func_8024E554(f32 arg0, f32 arg1, f32 arg2) {
    Camera* camera = &gCameras[1];

    if (D_80280CE0 == 0) {
        camera->unk_54 = arg0;
        camera->unk_58 = arg1;
        camera->unk_5C = arg2;
    }
}

s32 func_8024E584(void) {
    return D_8029F29C;
}

void btl_cam_set_zoom(s16 zoom) {
    if (D_80280CE0 == 0) {
        D_8029F280 = zoom;
    }
}

void btl_cam_add_zoom(s32 zoom) {
    if (D_80280CE0 == 0) {
        D_8029F280 += zoom;
    }
}

void btl_cam_set_zoffset(s16 zOffset) {
    if (D_80280CE0 == 0) {
        D_8029F286 = zOffset;
    }
}

#ifdef NON_MATCHING
void btl_cam_unfreeze(void) {
    D_80280CE0 = 0;
}
#else
INCLUDE_ASM(s32, "1776B0", btl_cam_unfreeze);
#endif

void func_8024E60C(void) {
    D_8029F2A6 = 0;
}

ApiStatus UseBattleCamPreset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 preset;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    preset = evt_get_variable(script, *args++);
    D_8029F2A4 = 0;
    btl_cam_use_preset(preset);

    return ApiStatus_DONE2;
}

ApiStatus func_8024E664(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 preset;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    preset = evt_get_variable(script, *args++);
    D_8029F2A4 = 1;
    btl_cam_use_preset(preset);

    return ApiStatus_DONE2;
}

ApiStatus func_8024E6B4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_8024E40C(evt_get_variable(script, *args++));
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (func_8024E584() != 0) {
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8024E748(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    Bytecode* args = script->ptrReadPos;
    s32 mode;
    s32 val;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    mode = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    switch (mode) {
        case 1:
            camera->unk_1C = val;
            break;
        case 2:
            camera->unk_1E = val;
            break;
        case 3:
            camera->unk_20 = val;
            break;
        case 4:
            camera->unk_22 = val;
            break;
        case 5:
            camera->unk_24 = val;
            break;
        case 6:
            camera->unk_26 = val * 256;
            break;
        case 7:
            camera->unk_28 = val;
            break;
        case 8:
            camera->zoomPercent = val;
            break;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8024E820(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[1];

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    camera->unk_1C = evt_get_variable(script, *args++);
    camera->unk_1E = evt_get_variable(script, *args++);
    camera->unk_20 = evt_get_variable(script, *args++);
    camera->unk_22 = evt_get_variable(script, *args++);
    camera->unk_24 = evt_get_variable(script, *args++);
    camera->unk_26 = evt_get_variable(script, *args++) * 256;
    camera->unk_28 = evt_get_variable(script, *args++);
    camera->zoomPercent = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F270 = evt_get_variable(script, *args++);
    D_8029F274 = evt_get_variable(script, *args++);
    D_8029F278 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_8024E9B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[1];

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    camera->unk_54 = evt_get_variable(script, *args++);
    camera->unk_58 = evt_get_variable(script, *args++);
    camera->unk_5C = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamOffsetZ(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F286 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus AddBattleCamOffsetZ(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F286 += evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamYaw(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F282 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus BattleCamTargetActor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    btl_cam_target_actor(actorID);

    return ApiStatus_DONE2;
}

ApiStatus func_8024EB84(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_8024E45C(actorID, evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}

ApiStatus MoveBattleCamOver(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F29E = evt_get_variable(script, *args++);
    D_80280CE4 = 0;

    if (battleStatus->camMovementScript != NULL) {
        restart_script(battleStatus->camMovementScript);
    }

    return ApiStatus_DONE2;
}

ApiStatus SetBattleCamZoom(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F280 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus AddBattleCamZoom(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F280 += evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_8024ECF8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (D_80280CE0 != 0) {
        return ApiStatus_DONE2;
    }

    D_8029F2A2 = evt_get_variable(script, *args++);
    D_8029F2A3 = evt_get_variable(script, *args++);
    D_8029F2A5 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus FreezeBattleCam(Evt* script, s32 isInitialCall) {
    D_80280CE0 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_8024EDA4(Evt* script, s32 isInitialCall) {
    D_8029F2A6 = 0;
    return ApiStatus_DONE2;
}
