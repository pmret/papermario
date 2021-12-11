#include "common.h"
#include "script_api/battle.h"

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
extern s16 D_8029F2A0;
extern s8 D_8029F2A2;
extern s8 D_8029F2A3;
extern s8 D_8029F2A4;
extern s8 D_8029F2A5;
extern s8 D_8029F2A6;
extern s8 D_8029F2A7;
extern f32 D_8029F2A8;
extern f32 D_8029F2AC;
extern f32 D_8029F2B0;
extern EvtSource* D_8029F2B4;

s8 D_80280CE0 = 0;
s32 D_80280CE4 = -1;

EvtSource CamPreset_B = {
    EVT_CALL(func_80248DD0)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_F = {
    EVT_CALL(func_80248DE4)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_M = {
    EVT_CALL(func_80249804)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_G = {
    EVT_CALL(func_8024A214)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_I = {
    EVT_CALL(func_8024A990)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_H = {
    EVT_CALL(func_8024AFE4)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_N = {
    EVT_CALL(func_8024B5FC)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_C = {
    EVT_CALL(func_8024B9A0)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_D = {
    EVT_CALL(func_8024BDA4)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_E = {
    EVT_CALL(func_8024C180)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_J = {
    EVT_CALL(func_8024C570)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_K = {
    EVT_CALL(func_8024C944)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_L = {
    EVT_CALL(func_8024CB68)
    EVT_RETURN
    EVT_END
};

EvtSource CamPreset_A = {
    EVT_CALL(func_8024E9B0, 0, 15, 0)
    EVT_CALL(func_8024E748, 2, 550)
    EVT_CALL(func_8024E748, 3, 100)
    EVT_CALL(func_8024E748, 4, 8)
    EVT_RETURN
    EVT_END
};

EvtSource D_80280EB8 = {
    EVT_CALL(SetCamPerspective, 1, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, 1, 12, 20, 296, 200)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 1, 1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(InitVirtualEntityList)
    EVT_CALL(InitAnimatedModels)
    EVT_CALL(func_802CABE8, 1, 0, 240, 100, 8)
    EVT_CALL(func_802CAE50, 1, -75, 35, 0)
    EVT_CALL(BattleCamTargetActor, 0)
    EVT_CALL(func_8024CE9C)
    EVT_RETURN
    EVT_END
};

ApiStatus func_80248DD0(Evt* script, s32 isInitialCall) {
    D_8029F29C = 1;
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "1776B0", func_80248DE4);

INCLUDE_ASM(s32, "1776B0", func_80249804);

INCLUDE_ASM(s32, "1776B0", func_8024A214);

INCLUDE_ASM(s32, "1776B0", func_8024A990);

INCLUDE_ASM(s32, "1776B0", func_8024AFE4);

ApiStatus func_8024B5FC(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    f32 x, y, z;
    f32 invAngle;
    f32 angle;

    x = D_8029F270;
    y = D_8029F274;
    z = D_8029F278;

    if (isInitialCall) {
        D_8029F28C = camera->unk_1E;
        D_8029F294 = camera->unk_22;
        D_8029F290 = camera->unk_24;
        D_8029F298 = camera->unk_26 / 256;
        D_8029F2A8 = camera->unk_54;
        D_8029F2AC = camera->unk_58;
        D_8029F2B0 = camera->unk_5C;
        D_8029F2A0 = D_8029F29E;
    }

    if (D_8029F2A5 == 0) {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
        angle = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - angle) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
    }

    invAngle = 1.0f - angle;
    camera->unk_54 = (D_8029F2A8 * angle) + (x * invAngle);
    camera->unk_58 = (D_8029F2AC * angle) + (y * invAngle);
    camera->unk_5C = (D_8029F2B0 * angle) + (z * invAngle);
    camera->unk_26 = ((D_8029F298 * angle) + (D_8029F286 * invAngle)) * 256.0f;
    camera->unk_1E = (D_8029F28C * angle) + (D_8029F280 * invAngle);
    camera->unk_24 = (D_8029F290 * angle) + (D_8029F282 * invAngle);
    camera->unk_22 = (D_8029F294 * angle) + (D_8029F284 * invAngle);

    if (D_8029F29E == 0) {
        D_8029F29C = 1;
    } else {
        D_8029F29E--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_8024B9A0(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    f32 x, y, z;
    f32 invAngle;
    f32 angle;

    if (isInitialCall) {
        D_8029F270 = 0.0f;
        D_8029F278 = 0.0f;
        D_8029F282 = 0;
        D_8029F284 = 8;
        D_8029F286 = 0;
        D_8029F274 = 60.0f;
        if (D_8029F2A4 != 0) {
            camera->unk_58 = 60.0f;
            camera->unk_26 = 0;
            camera->unk_24 = 0;
            camera->unk_22 = 8;
            camera->unk_54 = D_8029F270;
            camera->unk_5C = D_8029F270;
            camera->unk_1E = D_8029F280;
        }
        D_8029F28C = camera->unk_1E;
        D_8029F294 = camera->unk_22;
        D_8029F290 = camera->unk_24;
        D_8029F298 = camera->unk_26 / 256;
        D_8029F2A8 = camera->unk_54;
        D_8029F2AC = camera->unk_58;
        D_8029F2B0 = camera->unk_5C;
        D_8029F2A0 = D_8029F29E;
    }

    x = D_8029F270;
    y = D_8029F274;
    z = D_8029F278;

    if (D_8029F2A5 == 0) {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
        angle = 1.0f - sin_rad(sin_rad((1.0f - angle) * PI_S / 2) * PI_S / 2);
    } else {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
    }

    invAngle = 1.0f - angle;
    camera->unk_54 = (D_8029F2A8 * angle) + (x * invAngle);
    camera->unk_58 = (D_8029F2AC * angle) + (y * invAngle);
    camera->unk_5C = (D_8029F2B0 * angle) + (z * invAngle);
    camera->unk_26 = ((D_8029F298 * angle) + (D_8029F286 * invAngle)) * 256.0f;
    camera->unk_1E = (D_8029F28C * angle) + (D_8029F280 * invAngle);
    camera->unk_24 = (D_8029F290 * angle) + (D_8029F282 * invAngle);
    camera->unk_22 = (D_8029F294 * angle) + (D_8029F284 * invAngle);

    if (D_8029F29E == 0) {
        D_8029F29C = 1;
    } else {
        D_8029F29E--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_8024BDA4(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    f32 x, y, z;
    f32 invAngle;
    f32 angle;

    if (isInitialCall) {
        D_8029F284 = 8;
        D_8029F270 = 35.0f;
        D_8029F278 = 0.0f;
        D_8029F282 = 0;
        D_8029F274 = 60.0f;
        D_8029F28C = camera->unk_1E;
        D_8029F294 = camera->unk_22;
        D_8029F290 = camera->unk_24;
        D_8029F298 = camera->unk_26 / 256;
        D_8029F2A8 = camera->unk_54;
        D_8029F2AC = camera->unk_58;
        D_8029F2B0 = camera->unk_5C;
        D_8029F2A0 = D_8029F29E;
    }

    x = D_8029F270;
    y = D_8029F274;
    z = D_8029F278;

    if (D_8029F2A5 == 0) {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
        angle = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - angle) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
    }

    invAngle = 1.0f - angle;
    camera->unk_54 = (D_8029F2A8 * angle) + (x * invAngle);
    camera->unk_58 = (D_8029F2AC * angle) + (y * invAngle);
    camera->unk_5C = (D_8029F2B0 * angle) + (z * invAngle);
    camera->unk_26 = ((D_8029F298 * angle) + (D_8029F286 * invAngle)) * 256.0f;
    camera->unk_1E = (D_8029F28C * angle) + (D_8029F280 * invAngle);
    camera->unk_24 = (D_8029F290 * angle) + (D_8029F282 * invAngle);
    camera->unk_22 = (D_8029F294 * angle) + (D_8029F284 * invAngle);

    if (D_8029F29E == 0) {
        D_8029F29C = 1;
    } else {
        D_8029F29E--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_8024C180(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    f32 x, y, z;
    f32 invAngle;
    f32 angle;

    if (isInitialCall) {
        D_8029F270 = 35.0f;
        D_8029F274 = camera->unk_58;
        if (D_8029F274 < 60.0f) {
            D_8029F274 = 60.0f;
        }
        D_8029F284 = 8;
        D_8029F278 = 0.0f;
        D_8029F282 = 0;
        D_8029F28C = camera->unk_1E;
        D_8029F294 = camera->unk_22;
        D_8029F290 = camera->unk_24;
        D_8029F298 = camera->unk_26 / 256;
        D_8029F2A8 = camera->unk_54;
        D_8029F2AC = camera->unk_58;
        D_8029F2B0 = camera->unk_5C;
        D_8029F2A0 = D_8029F29E;
    }

    x = D_8029F270;
    y = D_8029F274;
    z = D_8029F278;

    if (D_8029F2A5 == 0) {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
        angle = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - angle) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
    }

    invAngle = 1.0f - angle;
    camera->unk_54 = (D_8029F2A8 * angle) + (x * invAngle);
    camera->unk_58 = (D_8029F2AC * angle) + (y * invAngle);
    camera->unk_5C = (D_8029F2B0 * angle) + (z * invAngle);
    camera->unk_26 = ((D_8029F298 * angle) + (D_8029F286 * invAngle)) * 256.0f;
    camera->unk_1E = (D_8029F28C * angle) + (D_8029F280 * invAngle);
    camera->unk_24 = (D_8029F290 * angle) + (D_8029F282 * invAngle);
    camera->unk_22 = (D_8029F294 * angle) + (D_8029F284 * invAngle);

    if (D_8029F29E == 0) {
        D_8029F29C = 1;
    } else {
        D_8029F29E--;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_8024C570(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    f32 x, y, z;
    f32 invAngle;
    f32 angle;

    if (isInitialCall) {
        if (D_8029F2A4 != 0) {
            D_8029F270 = camera->unk_54;
            D_8029F274 = camera->unk_58;
            D_8029F278 = camera->unk_5C;
        }
        D_8029F28C = camera->unk_1E;
        D_8029F294 = camera->unk_22;
        D_8029F290 = camera->unk_24;
        D_8029F298 = camera->unk_26 / 256;
        D_8029F2A8 = camera->unk_54;
        D_8029F2AC = camera->unk_58;
        D_8029F2B0 = camera->unk_5C;
        D_8029F2A0 = D_8029F29E;
    }

    x = D_8029F270;
    y = D_8029F274;
    z = D_8029F278;

    if (D_8029F2A5 == 0) {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
        angle = 1.0f - sin_rad(sin_rad(sin_rad((1.0f - angle) * PI_S / 2) * PI_S / 2) * PI_S / 2);
    } else {
        angle = D_8029F29E;
        angle /= D_8029F2A0;
    }

    invAngle = 1.0f - angle;
    camera->unk_54 = (D_8029F2A8 * angle) + (x * invAngle);
    camera->unk_58 = (D_8029F2AC * angle) + (y * invAngle);
    camera->unk_5C = (D_8029F2B0 * angle) + (z * invAngle);
    camera->unk_26 = ((D_8029F298 * angle) + (D_8029F286 * invAngle)) * 256.0f;
    camera->unk_1E = (D_8029F28C * angle) + (D_8029F280 * invAngle);
    camera->unk_24 = (D_8029F290 * angle) + (D_8029F282 * invAngle);
    camera->unk_22 = (D_8029F294 * angle) + (D_8029F284 * invAngle);

    if (D_8029F29E == 0) {
        D_8029F29C = 1;
    } else {
        D_8029F29E--;
    }

    return ApiStatus_BLOCK;
}

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

ApiStatus func_8024CB68(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actorType = D_8029F27C & 0x700;
    s32 actorID = D_8029F27C & 0xFF;
    f32 x, y, z;
    s32 screenX, screenY, screenZ;
    f32 temp;

    switch (actorType) {
        case 0:
            if (battleStatus->playerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->playerActor->currentPos.x;
            y = battleStatus->playerActor->currentPos.y + (playerStatus->colliderHeight / 2);
            z = battleStatus->playerActor->currentPos.z;
            break;
        case 0x100:
            if (battleStatus->partnerActor == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->partnerActor->currentPos.x;
            y = battleStatus->partnerActor->currentPos.y;
            z = battleStatus->partnerActor->currentPos.z;
            break;
        case 0x200:
        default:
            if (battleStatus->enemyActors[actorID] == NULL) {
                return ApiStatus_BLOCK;
            }
            x = battleStatus->enemyActors[actorID]->currentPos.x;
            y = battleStatus->enemyActors[actorID]->currentPos.y;
            z = battleStatus->enemyActors[actorID]->currentPos.z;
            break;
    }

    if (isInitialCall) {
        D_8029F270 = camera->unk_54;
        D_8029F274 = camera->unk_58;
        D_8029F278 = camera->unk_5C;
        D_8029F288 = camera->unk_1E;
        D_8029F290 = camera->unk_24;
        D_8029F294 = camera->unk_22;
    }

    get_screen_coords(1, x, y, z, &screenX, &screenY, &screenZ);

    if (screenY < 100) {
        y += 25.0f;
    }
    if (y < D_8029F274) {
        y = D_8029F274;
    }

    if (screenX < 100) {
        x -= 25.0f;
    }
    if (x < D_8029F270) {
        x = D_8029F270;
    }
    if (screenX > 220) {
        x += 25.0f;
    }

    temp = x - camera->unk_54;
    if (fabsf(temp) < 0.01) {
        if (temp != 0.0f) {
            camera->unk_54 = x;
        }
    } else {
        camera->unk_54 += temp / 5.0f;
    }

    temp = y - camera->unk_58;
    if (fabsf(temp) < 0.01) {
        if (temp != 0.0f) {
            camera->unk_58 = y;
        }
    } else {
        camera->unk_58 += temp / 5.0f;
    }

    temp = z - camera->unk_5C;
    if (fabsf(temp) < 0.01) {
        if (temp != 0.0f) {
            camera->unk_5C = z;
        }
    } else {
        camera->unk_5C += temp / 5.0f;
    }

    return ApiStatus_BLOCK;
}

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

void btl_cam_use_preset(s32 id) {
    BattleStatus* battleStatus = &gBattleStatus;
    EvtSource* preset = NULL;
    Evt* newScript;

    if (D_80280CE0 == 0) {
        D_8029F2A6 = 1;
        D_8029F2A2 = 0;
        D_8029F2A3 = 0;
        D_8029F2A5 = 0;
        D_8029F2A7 = 0;

        switch (id) {
            case 0x0:
                preset = &CamPreset_A;
                break;
            case 0x1:
                preset = &CamPreset_B;
                break;
            case 0x2:
                if (D_80280CE4 != id) {
                    D_8029F280 = 500;
                    D_8029F29E = 30;
                    preset = &CamPreset_C;
                    break;
                }
                return;
            case 0x3:
                if (D_80280CE4 != id) {
                    D_8029F280 = 480;
                    preset = &CamPreset_D;
                    D_8029F29E = 20;
                    D_8029F286 = 0;
                    break;
                }
                return;
            case 0x4:
                if (D_80280CE4 != id) {
                    D_8029F280 = 500;
                    preset = &CamPreset_E;
                    D_8029F29E = 10;
                    D_8029F286 = 0;
                    break;
                }
                return;
            case 0x5:
                D_8029F280 = 300;
                D_8029F29E = 20;
                preset = &CamPreset_F;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0x6:
                D_8029F280 = 300;
                D_8029F29E = 20;
                preset = &CamPreset_G;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0x7:
                D_8029F280 = 300;
                D_8029F29E = 20;
                preset = &CamPreset_H;
                break;
            case 0x8:
                D_8029F280 = 300;
                D_8029F29E = 20;
                preset = &CamPreset_I;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0x9:
                if (D_8029F2B4 != &CamPreset_C) {
                    D_8029F280 = 500;
                    D_8029F29E = 120;
                    preset = &CamPreset_C;
                    break;
                }
                return;
            case 0xA:
                D_8029F280 = 200;
                D_8029F284 = 8;
                D_8029F29E = 20;
                preset = &CamPreset_F;
                D_8029F286 = 15;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0xB:
                D_8029F280 = 300;
                D_8029F284 = 8;
                preset = &CamPreset_F;
                D_8029F29E = 20;
                D_8029F286 = 16;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0xC:
                D_8029F280 = 400;
                D_8029F284 = 8;
                D_8029F29E = 20;
                preset = &CamPreset_F;
                D_8029F286 = 30;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0xD:
                D_8029F280 = 200;
                D_8029F284 = 8;
                D_8029F29E = 20;
                preset = &CamPreset_I;
                D_8029F286 = 15;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0xE:
                D_8029F280 = 300;
                D_8029F284 = 8;
                preset = &CamPreset_I;
                D_8029F29E = 20;
                D_8029F286 = 16;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0xF:
                D_8029F280 = 400;
                D_8029F284 = 8;
                D_8029F29E = 20;
                preset = &CamPreset_I;
                D_8029F286 = 30;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0x10:
                D_8029F280 = 267;
                D_8029F284 = 8;
                D_8029F29E = 20;
                D_8029F282 = 0;
                D_8029F286 = 23;
                preset = &CamPreset_H;
                break;
            case 0x11:
                D_8029F280 = 300;
                D_8029F282 = 0;
                D_8029F284 = 8;
                D_8029F29E = 20;
                D_8029F286 = 8;
                preset = &CamPreset_H;
                break;
            case 0x12:
                D_8029F280 = 400;
                D_8029F284 = 8;
                D_8029F282 = 0;
                preset = &CamPreset_H;
                D_8029F29E = 20;
                D_8029F286 = 0;
                break;
            case 0x13:
                D_8029F29E = 20;
                preset = &CamPreset_J;
                break;
            case 0x14:
                preset = &CamPreset_K;
                D_8029F29E = 20;
                D_8029F286 = 0;
                break;
            case 0x15:
                preset = &CamPreset_L;
                D_8029F29E = 20;
                D_8029F286 = 0;
                break;
            case 0x19:
                D_8029F280 = 266;
                D_8029F284 = 8;
                D_8029F282 = 0;
                D_8029F286 = 40;
                btl_cam_set_target_pos(-80.0f, 0.0f, 0.0f);
                D_8029F29E = 20;
                D_8029F27C = 0;
                preset = &CamPreset_J;
                break;
            case 0x18:
                D_8029F280 = 250;
                D_8029F284 = 8;
                D_8029F29E = 20;
                D_8029F286 = 14;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                D_80280CE0 = 1;
                preset = &CamPreset_I;
                break;
            case 0x17:
                D_8029F280 = 255;
                D_8029F284 = 8;
                D_8029F29E = 20;
                D_8029F282 = 0;
                D_8029F286 = 29;
                D_8029F2A2 = 0;
                D_8029F2A3 = 0;
                btl_cam_set_target_pos(-95.0f, 18.0f, 10.0f);
                D_8029F27C = 0;
                preset = &CamPreset_J;
                break;
            case 0x16:
                D_8029F280 = 230;
                D_8029F284 = 8;
                D_8029F282 = 0;
                D_8029F29E = 20;
                D_8029F286 = 0;
                D_8029F27C = 0;
                preset = &CamPreset_J;
                break;
            case 0x1A:
                D_8029F280 = 310;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = 0x10;
                D_8029F282 = 0;
                D_8029F27C = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F2A6 = 0;
                preset = &CamPreset_M;
                break;
            case 0x1B:
                D_8029F280 = 320;
                D_8029F284 = 8;
                D_8029F29E = 5;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x1C:
                D_8029F280 = 340;
                D_8029F284 = 8;
                D_8029F29E = 5;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                D_8029F27C = 0;
                D_8029F2A6 = 0;
                preset = &CamPreset_M;
                break;
            case 0x1E:
            case 0x1F:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F29E = 0xF;
                D_8029F286 = -32;
                D_8029F2A7 = 20;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F27C = 0;
                preset = &CamPreset_I;
                break;
            case 0x20:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F282 = 0;
                D_8029F29E = 0xA;
                preset = &CamPreset_N;
                D_8029F286 = 0xA;
                D_8029F2A2 = 0;
                D_8029F2A3 = 0;
                D_8029F278 = 0.0f;
                D_8029F270 = -65.0f;
                D_8029F274 = 30.0f;
                break;
            case 0x21:
                D_8029F280 = 220;
                D_8029F284 = 8;
                D_8029F29E = 30;
                preset = &CamPreset_I;
                D_8029F286 = 24;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x22:
                D_8029F280 = 280;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = -4;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                D_8029F27C = 0;
                D_8029F2A6 = 0;
                preset = &CamPreset_M;
                break;
            case 0x23:
                D_8029F280 = 380;
                D_8029F284 = 8;
                D_8029F29E = 60;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                D_8029F2A5 = 1;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x25:
                D_8029F280 = 320;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = -4;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x24:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F29E = 60;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                D_8029F2A5 = 1;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x26:
                D_8029F280 = 320;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = -4;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x27:
                D_8029F280 = 320;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x28:
                D_8029F280 = 360;
                D_8029F284 = 8;
                D_8029F29E = 20;
                preset = &CamPreset_M;
                D_8029F286 = -4;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F2A6 = 0;
                D_8029F27C = 0;
                break;
            case 0x29:
            case 0x2A:
                D_8029F280 = 200;
                D_8029F29E = 7;
                D_8029F2A0 = 7;
                D_8029F29C = 0;
                D_8029F2A6 = 0;
                preset = D_8029F2B4;
                break;
            case 0x2B:
                D_8029F280 = 214;
                D_8029F284 = 8;
                D_8029F29E = 20;
                D_8029F286 = 0x10;
                D_8029F2A2 = -2;
                D_8029F282 = 0;
                D_8029F27C = 0;
                D_8029F2A3 = 1;
                D_8029F2A6 = 0;
                preset = &CamPreset_M;
                break;
            case 0x2C:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F29E = 8;
                D_8029F286 = 0x10;
                D_8029F282 = 0;
                D_8029F27C = 0;
                D_8029F2A2 = 0;
                D_8029F2A3 = 1;
                D_8029F2A6 = 0;
                preset = &CamPreset_M;
                break;
            case 45:
                D_8029F280 = 430;
                D_8029F284 = 8;
                D_8029F29E = 0xA;
                D_8029F282 = 0;
                D_8029F286 = 0x10;
                D_8029F27C = 0;
                preset = &CamPreset_N;
                D_8029F2A2 = 0;
                D_8029F2A3 = 0;
                D_8029F278 = 0.0f;
                D_8029F270 = 60.0f;
                D_8029F274 = 40.0f;
                break;
            case 0x2E:
                D_8029F280 = 460;
                D_8029F284 = 8;
                D_8029F29E = 0xA;
                D_8029F282 = 0;
                D_8029F286 = 27;
                D_8029F27C = 0;
                D_8029F2A2 = 0;
                preset = &CamPreset_N;
                D_8029F278 = 0.0f;
                D_8029F270 = 60.0f;
                D_8029F274 = 40.0f;
                break;
            case 0x46:
                D_8029F280 = 390;
                D_8029F284 = 8;
                D_8029F282 = 0;
                D_8029F286 = 45;
                btl_cam_set_target_pos(-70.0f, 0.0f, 0.0f);
                D_8029F29E = 10;
                D_8029F2A6 = 0;
                preset = &CamPreset_J;
                break;
            case 0x47:
                D_8029F280 = 500;
                D_8029F284 = 8;
                D_8029F282 = 0;
                D_8029F286 = 45;
                btl_cam_set_target_pos(0.0f, 0.0f, 0.0f);
                D_8029F29E = 40;
                D_8029F2A6 = 0;
                preset = &CamPreset_J;
                break;
            case 0x45:
            case 0x48:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F282 = 0;
                D_8029F286 = 45;
                btl_cam_set_target_pos(-50.0f, 0.0f, 0.0f);
                D_8029F29E = 20;
                D_8029F2A6 = 0;
                preset = &CamPreset_J;
                break;
            case 0x49:
                D_8029F280 = 166;
                D_8029F284 = 8;
                D_8029F29E = 1;
                preset = &CamPreset_N;
                D_8029F282 = 0;
                D_8029F286 = 17;
                D_8029F2A2 = 0;
                D_8029F2A3 = 0;
                D_8029F278 = 0.0f;
                D_8029F270 = -75.0f;
                D_8029F274 = 150.0f;
                break;
            case 0x2F:
                D_8029F280 = 310;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = 0x10;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                preset = &CamPreset_M;
                D_8029F282 = 0;
                D_8029F27C = 256;
                D_8029F2A6 = 0;
                break;
            case 0x30:
                D_8029F280 = 250;
                D_8029F284 = 8;
                D_8029F29E = 120;
                D_8029F286 = 0x10;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F2A5 = 1;
                preset = &CamPreset_M;
                D_8029F282 = 0;
                D_8029F2A6 = 0;
                D_8029F27C = 256;
                break;
            case 0x31:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F29E = 120;
                D_8029F286 = 0x10;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F2A5 = 1;
                preset = &CamPreset_I;
                D_8029F282 = 0;
                D_8029F2A6 = 0;
                D_8029F27C = 256;
                break;
            case 0x32:
                D_8029F280 = 320;
                D_8029F284 = 8;
                D_8029F29E = 5;
                D_8029F2A2 = 1;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A3 = 0;
                preset = &CamPreset_M;
                D_8029F27C = 256;
                D_8029F2A6 = 0;
                break;
            case 0x1D:
            case 0x33:
                D_8029F29E = 50;
                D_8029F280 = 500;
                D_8029F286 = 0;
                preset = &CamPreset_D;
                break;
            case 0x34:
                D_8029F280 = 280;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = -4;
                D_8029F2A2 = 1;
                D_8029F282 = 0;
                D_8029F2A3 = 0;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 256;
                break;
            case 0x35:
                D_8029F280 = 380;
                D_8029F284 = 8;
                D_8029F29E = 60;
                D_8029F2A2 = 1;
                D_8029F2A5 = 1;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A3 = 0;
                preset = &CamPreset_M;
                D_8029F2A6 = 0;
                D_8029F27C = 256;
                break;
            case 0x36:
                D_8029F280 = 220;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = 24;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                preset = &CamPreset_I;
                D_8029F282 = 0;
                D_8029F2A6 = 0;
                D_8029F27C = 256;
                break;
            case 0x37:
                D_8029F280 = 210;
                D_8029F284 = 8;
                D_8029F29E = 20;
                preset = &CamPreset_N;
                D_8029F282 = 0;
                D_8029F286 = 0xA;
                D_8029F2A2 = 0;
                D_8029F2A3 = 0;
                D_8029F278 = 0.0f;
                D_8029F270 = -95.0f;
                D_8029F274 = 22.0f;
                break;
            case 0x38:
                D_8029F280 = 320;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F286 = -4;
                D_8029F2A2 = 1;
                D_8029F282 = 0;
                D_8029F2A3 = 0;
                D_8029F27C = 256;
                preset = &CamPreset_M;
                break;
            case 0x39:
                D_8029F280 = 320;
                D_8029F284 = 8;
                D_8029F29E = 30;
                D_8029F2A2 = 1;
                D_8029F282 = 0;
                D_8029F286 = 0;
                D_8029F2A3 = 0;
                D_8029F27C = 256;
                preset = &CamPreset_M;
                break;
            case 0x3A:
                D_8029F280 = 400;
                D_8029F284 = 8;
                D_8029F29E = 30;
                preset = &CamPreset_N;
                D_8029F282 = 0;
                D_8029F286 = 0xA;
                D_8029F2A2 = 0;
                D_8029F2A3 = 0;
                D_8029F278 = 0.0f;
                D_8029F270 = 25.0f;
                D_8029F274 = 60.0f;
                break;
            case 0x3B:
                D_8029F280 = 200;
                D_8029F284 = 8;
                D_8029F29E = 60;
                D_8029F286 = 11;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F2A5 = 1;
                preset = &CamPreset_I;
                D_8029F282 = 0;
                D_8029F27C = 256;
                D_8029F2A6 = 0;
                break;
            case 0x3C:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F29E = 8;
                D_8029F286 = 0x10;
                D_8029F282 = 0;
                D_8029F27C = 256;
                D_8029F2A2 = 0;
                D_8029F2A3 = 0;
                preset = &CamPreset_I;
                break;
            case 0x3D:
            case 0x3E:
                D_8029F280 = 300;
                D_8029F284 = 8;
                D_8029F29E = 15;
                D_8029F286 = -32;
                D_8029F2A7 = 20;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                D_8029F282 = 0;
                D_8029F27C = 256;
                preset = &CamPreset_I;
                break;
            case 0x3F:
                D_8029F280 = 400;
                D_8029F284 = 8;
                D_8029F29E = 20;
                preset = &CamPreset_F;
                D_8029F286 = 27;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0x40:
                D_8029F280 = 358;
                D_8029F284 = 8;
                D_8029F29E = 10;
                D_8029F286 = 0x10;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                preset = &CamPreset_F;
                break;
            case 0x41:
                D_8029F29E = 50;
                D_8029F280 = 500;
                preset = &CamPreset_C;
                break;
            case 0x42:
                D_8029F280 = 267;
                D_8029F284 = 8;
                D_8029F29E = 20;
                D_8029F286 = 0x10;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 0;
                preset = &CamPreset_F;
                break;
            case 0x43:
                D_8029F280 = 214;
                D_8029F284 = 8;
                preset = &CamPreset_F;
                D_8029F29E = 20;
                D_8029F286 = 16;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
            case 0x44:
                D_8029F280 = 300;
                D_8029F284 = 8;
                preset = &CamPreset_F;
                D_8029F29E = 4;
                D_8029F286 = 16;
                D_8029F282 = 0;
                D_8029F2A2 = 1;
                D_8029F2A3 = 1;
                break;
        }

        D_80280CE4 = id;

        if (battleStatus->camMovementScript != NULL) {
            kill_script_by_ID(battleStatus->camMovementScriptID);
        }

        D_8029F2B4 = preset;
        newScript = start_script(preset, 0xA, 0x20);
        D_8029F29C = 0;
        battleStatus->camMovementScript = newScript;
        battleStatus->camMovementScriptID = newScript->id;
    }
}

void func_8024E3D8(s32 arg0) {
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

void btl_cam_target_actor(s32 actorID) {
    if (D_80280CE0 == 0) {
        D_8029F27C = actorID;
    }
}

void func_8024E45C(s32 actorID, s32 arg1) {
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

void btl_cam_unfreeze(void) {
    D_80280CE0 = 0;
}

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
    s32 actorID;

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
    s32 actorID;

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
