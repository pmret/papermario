#include "hos_05.h"
#include "model.h"
#include "effects.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

typedef struct UnkHosStruct {
    /* 0x00 */ s32 unk_00; // entity ID
    /* 0x04 */ IMG_PTR unk_04;
    /* 0x08 */ PAL_PTR unk_08;
    /* 0x0C */ IMG_PTR unk_0C;
    /* 0x10 */ PAL_PTR unk_10;
    /* 0x14 */ char unk_14[0x4];
    /* 0x18 */ IMG_PTR unk_18;
    /* 0x1C */ IMG_PTR unk_1C;
    /* 0x20 */ PAL_PTR unk_20;
    /* 0x24 */ char unk_24[0x18];
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ u16 unk_44; // x
    /* 0x46 */ u16 unk_46; // y
    /* 0x48 */ s16 unk_48; // x
    /* 0x4A */ s16 unk_4A; // y
    /* 0x4C */ char unk_4C[0xC];
    /* 0x58 */ s16 unk_58; // bool
    /* 0x5A */ s16 unk_5A;
    /* 0x5C */ s16 unk_5C; // alpha
    /* 0x60 */ char unk_6E[0x2];
} UnkHosStruct; // size = 0x60

extern s32 D_802495DC_A3381C;
extern s32 D_802495E0_A33820;
extern f32 D_8024963C_A3387C[];
extern f32 D_8024987C_A33ABC;
extern f32 D_802498A8_A33AE8;
extern f32 D_802498D0_A33B10;
extern u16* D_802498D4_A33B14;
extern f32 D_802498D8_A33B18;
extern f32 D_802498DC_A33B1C;
extern f32 D_802498E0_A33B20;
extern f32 D_802498E4_A33B24;
extern f32 D_802498E8_A33B28;
extern f32 D_802498EC_A33B2C;
extern f32 D_802498F0_A33B30;
extern f32 D_802498F4_A33B34;
extern s32 D_802498F8_A33B38;
extern s32 D_802498FC_A33B3C;
extern s32 D_80249900_A33B40;
extern f32 D_80249904_A33B44;
extern s32 D_80249908_A33B48;
extern f32 D_8024990C_A33B4C;
extern s32 D_80249910_A33B50;
extern s16 D_80249914_A33B54[];
extern s16 D_80249934_A33B74[];
extern s32 D_8024995C_A33B9C;
extern s16 D_80249960_A33BA0[];
extern f32 D_80249980_A33BC0;
extern s32 D_80249984_A33BC4;
extern s16 D_80249988_A33BC8[];
extern s16 D_802499A8_A33BE8[][2];
extern s32 D_80249A48_A33C88;
extern s16 D_80249A4C_A33C8C[];
extern f32 D_80249A6C_A33CAC;
extern s32 D_80249A70_A33CB0;
extern f32 D_80249A74_A33CB4;
extern s32 D_80249A78_A33CB8;
extern s32 D_80249A7C_A33CBC;
extern s32 D_80249A80_A33CC0;
extern f32 D_80249A84_A33CC4;
extern f32 D_80249A88_A33CC8;
extern f32 D_80249A8C_A33CCC;
extern s32 D_80249A90_A33CD0;
extern f32 D_80249A94_A33CD4;
extern f32 D_80249A98_A33CD8;
extern f32 D_80249A9C_A33CDC;
extern f32 D_80249AA0_A33CE0;
extern s32 D_80249AA4_A33CE4;
extern f32 D_8024A9C8_A34C08;
extern s32 D_8024A9CC_A34C0C;
extern UnkHosStruct* D_8024AA20_A34C60;
extern Gfx D_8024AA28_A34C68[];
extern u32 D_8024AAB0_A34CF0;
extern s32 D_8024AAB4_A34CF4; // func_802440D0_A2E310 can be matched once this is migrated
extern s32 D_8024AAB8_A34CF8;
extern u32 D_8024AABC_A34CFC;
extern s32 D_8024AAC0_A34D00[];
extern s32 D_8024AAD6_A34D14[];
extern u8 D_8024AB3C_A34D7C[];
extern u8 D_8024AC7B_A34EBB;
extern u16 D_8024AC7C_A34EBC[];
extern u16 D_8024AC9C_A34EDC[];
extern s32 D_8024ACB8_A34EF8;
extern f32 D_8024AEC4_A35104;
extern f32 D_8024AEC8_A35108;

// BSS?
extern f32 D_8024F2C8;
extern f32 D_8024F2CC;
extern f32 D_8024F2D8;
extern f32 D_8024F2DC;
extern f32 D_8024F2E0;
extern f32 D_8024F2E4;
extern f32 D_8024F2E8;
extern f32 D_8024F2EC;
extern f32 D_8024F2F0_C0CB70;
extern f32 D_8024F2F4;
extern f32 D_8024F2F8;
extern f32 D_8024F374;
extern f32 D_8024F378;

ApiStatus func_80240880_A2AAC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 primR = evt_get_variable(script, *args++);
    s32 primG = evt_get_variable(script, *args++);
    s32 primB = evt_get_variable(script, *args++);
    s32 primA = evt_get_variable(script, *args++);
    s32 fogR = evt_get_variable(script, *args++);
    s32 fogG = evt_get_variable(script, *args++);
    s32 fogB = evt_get_variable(script, *args++);
    s32 fogStart = evt_get_variable(script, *args++);
    s32 fogEnd = evt_get_variable(script, *args++);

    set_model_fog_color_parameters(primR, primG, primB, primA, fogR, fogG, fogB, fogStart, fogEnd);
    return ApiStatus_DONE2;
}

ApiStatus func_802409C4_A2AC04(Evt* script, s32 isInitialCall) {
    Bytecode* args;
    static u8 oldPrimR, oldPrimG, oldPrimB;
    static u8 oldEnvR, oldEnvG, oldEnvB;
    static s32 newPrimR, newPrimG, newPrimB;
    static s32 newEnvR, newEnvG, newEnvB;
    static s32 duration, time;

    args = script->ptrReadPos;
    if (isInitialCall) {
        get_model_env_color_parameters(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
        newPrimR = evt_get_variable(script, *args++);
        newPrimG = evt_get_variable(script, *args++);
        newPrimB = evt_get_variable(script, *args++);
        newEnvR = evt_get_variable(script, *args++);
        newEnvG = evt_get_variable(script, *args++);
        newEnvB = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);
        time = 0;
    }

    if (duration > 0) {
        if(time >= duration) {
            return ApiStatus_DONE2;
        }
        time++;
        set_model_env_color_parameters(
            (oldPrimR + ((newPrimR - oldPrimR) * time) / duration),
            (oldPrimG + ((newPrimG - oldPrimG) * time) / duration),
            (oldPrimB + ((newPrimB - oldPrimB) * time) / duration),
            (oldEnvR  + ( (newEnvR - oldEnvR)  * time) / duration),
            (oldEnvG  + ( (newEnvG - oldEnvG)  * time) / duration),
            (oldEnvB  + ( (newEnvB - oldEnvB)  * time) / duration));
        if (time >= duration) {
            return ApiStatus_DONE2;
        }
    } else {
        set_model_env_color_parameters(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

void func_80240D54_A2AF94(s32 camID, f32 fov) {
    Camera* camera = &gCameras[camID];
    camera->vfov = fov * 1.1;
}

ApiStatus func_80240DA0_A2AFE0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 camID = evt_get_variable(script, *args++);
    f32 fov = evt_get_float_variable(script, *args++);

    func_80240D54_A2AF94(camID, fov);
    return ApiStatus_DONE2;
}

ApiStatus func_80240DF8_A2B038(Evt* script, s32 isInitialCall) {
    GameStatus* gameStatus = gGameStatusPtr;
    if (gameStatus->creditsViewportMode < 5U) {
        gameStatus->creditsViewportMode++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

ApiStatus func_80240E30_A2B070(Evt* script, s32 isInitialCall) {
    mdl_set_all_fog_mode(3);
    return ApiStatus_DONE2;
}

// adjusts properties of EmitterVolume:GoldShimmer2 effect
ApiStatus func_80240E50_A2B090(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 posX;
    s32 posY;
    f32 posZ;
    EffectInstance* effect;

    effect = (EffectInstance*) evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);
    posX = evt_get_float_variable(script, *args++);
    posY = evt_get_float_variable(script, *args++);
    posZ = evt_get_float_variable(script, *args++);
    effect->data.miscParticles->pos.x = (f32) posX;
    effect->data.miscParticles->pos.y = (f32) posY;
    effect->data.miscParticles->pos.z = (f32) (s32) posZ;
    return ApiStatus_DONE2;
}


ApiStatus func_80240F30_A2B170(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(0));
    effect->data.somethingRotating[D_802495DC_A3381C + 1].unk_29 = 1;
    D_802495DC_A3381C += 1;
    return ApiStatus_DONE2;
}


ApiStatus func_80240F88_A2B1C8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(0));
    effect->data.somethingRotating[D_802495E0_A33820 + 1].unk_29 = 3;
    D_802495E0_A33820 += 1;
    return ApiStatus_DONE2;
}

ApiStatus func_80240FE0_A2B220(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect;
    effect = (EffectInstance*) evt_get_variable(script, ArrayVar(16));
    effect->data.lightRays->unk_10 = script->varTable[0];
    effect->data.lightRays->unk_14 = script->varTable[1];
    effect->data.lightRays->unk_18 = script->varTable[2];
    return ApiStatus_DONE2;
}


void func_80241044_A2B284(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4) {
    f32 temp_f2 = arg1 - arg2;

    if (arg1 - arg0 > 0.0f) {
        if (temp_f2 < 0.0f) {
            *arg4 = arg1;
        } else if (arg3 < temp_f2) {
            *arg4 += arg3;
        } else {
            *arg4 += temp_f2;
        }
    } else if (temp_f2 > 0.0f) {
        *arg4 = arg1;
    } else if (temp_f2 < -arg3) {
        *arg4 -= arg3;
    } else {
        *arg4 += temp_f2;
    }
}

void func_802410E4_A2B324(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32* arg5) {
    f32 var_f12_2;

    if (arg3 > arg4) {
        arg3 = arg4;
    }

    switch (arg0) {
        case 1:
            var_f12_2 = sin_deg((arg3 / arg4) * 90.0f);
            break;
        case 2:
            if (arg3 < 30.0f) {
                var_f12_2 = 0.0f;
            } else {
                var_f12_2 = sin_deg((((arg3 - 30.0f) / (arg4 - 30.0f)) * 90.0f) + -90.0f) + 1.0f;
            }
            break;
        case 3:
            var_f12_2 = (sin_deg(((arg3 / arg4) * 180.0f) - 90.0f) + 1.0f) * 0.5;
            break;
        case 4:
            var_f12_2 = sin_deg(((arg3 / arg4) * 90.0f) - 90.0f) + 1.0f;
            break;
        default:
            var_f12_2 = arg3 / arg4;
            break;
    }
    *arg5 = arg1 + ((arg2 - arg1) * var_f12_2);
}

ApiStatus func_80241274_A2B4B4(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == D_802498D4_A33B14) {
        return ApiStatus_BLOCK;
    }
    D_802498D4_A33B14 = nuGfxCfb_ptr;
    func_80241044_A2B284(250.0f, 0.0f, D_802498D0_A33B10, 0.5f, &D_802498D0_A33B10);
    func_802410E4_A2B324(2, 130.4f, D_8024963C_A3387C[1], 0.0f, 470.0f, &D_802498D8_A33B18);
    func_80241044_A2B284(12.4f, D_8024963C_A3387C[2], D_802498DC_A33B1C, 0.05f, &D_802498DC_A33B1C);
    func_80241044_A2B284(-16.8f, D_8024963C_A3387C[9], D_802498E0_A33B20, 0.05f, &D_802498E0_A33B20);
    func_80241044_A2B284(62.0f, 49.0f, D_802498E4_A33B24, 0.1f, &D_802498E4_A33B24);
    func_80240D54_A2AF94(0, D_802498E4_A33B24);
    camera->controlSettings.boomLength = D_802498D8_A33B18;
    camera->controlSettings.boomPitch = D_802498DC_A33B1C;
    camera->controlSettings.viewPitch = D_802498E0_A33B20;
    camera->controlSettings.posB.x = sin_deg(D_802498D0_A33B10) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(D_802498D0_A33B10) * -500.0f;
    camera->panActive = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus func_8024146C_A2B6AC(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == D_802498D4_A33B14) {
        return ApiStatus_BLOCK;
    }
    D_802498D4_A33B14 = nuGfxCfb_ptr;
    func_80241044_A2B284(250.0f, 0.0f, D_802498D0_A33B10, 0.5f, &D_802498D0_A33B10);
    func_802410E4_A2B324(2, 130.4f, D_8024963C_A3387C[1], (f32) D_802498FC_A33B3C, 470.0f, &D_802498E8_A33B28);
    func_80241044_A2B284(12.4f, D_8024963C_A3387C[2], D_802498EC_A33B2C, 0.05f, &D_802498EC_A33B2C);
    func_80241044_A2B284(-16.8f, D_8024963C_A3387C[9], D_802498F0_A33B30, 0.05f, &D_802498F0_A33B30);
    func_80241044_A2B284(62.0f, 49.0f, D_802498F4_A33B34, 0.1f, &D_802498F4_A33B34);
    func_80240D54_A2AF94(0, D_802498F4_A33B34);
    camera->controlSettings.boomLength = D_802498E8_A33B28;
    camera->controlSettings.boomPitch = D_802498EC_A33B2C;
    camera->controlSettings.viewPitch = D_802498F0_A33B30;
    camera->controlSettings.posB.x = sin_deg(D_802498D0_A33B10) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(D_802498D0_A33B10) * -500.0f;
    camera->panActive = TRUE;
    D_802498FC_A33B3C++;
    if (D_802498D0_A33B10 == 0.0f) {
        D_802498F8_A33B38++;
    }

    if (D_802498F8_A33B38 <= 30) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_802416BC_A2B8FC(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAGS_SHAKING;
    }
    guTranslateF(camera->viewMtxShaking,
        D_80249904_A33B44 * sin_deg(D_80249900_A33B40 * 486),
        D_80249904_A33B44 * cos_deg(D_80249900_A33B40 * 254),
        0.0f
    );
    D_80249900_A33B40++;
    D_80249904_A33B44 += (12.0f - D_80249904_A33B44) * 0.2;
    if (D_80249900_A33B40 > 20) {
        guTranslateF(camera->viewMtxShaking, 0.0f, 0.0f, 0.0f);
        camera->flags &= ~CAMERA_FLAGS_SHAKING;
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80241850_A2BA90(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];
    Matrix4f sp18;
    f32 x, y;

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAGS_SHAKING;
    }
    x = D_8024990C_A33B4C * sin_deg(D_80249908_A33B48 * 486);
    y = D_8024990C_A33B4C * cos_deg(D_80249908_A33B48 * 254);
    guTranslateF(camera->viewMtxShaking, x, y, 0.0f);
    guTranslateF(camera->viewMtxShaking, x, y, 0.0f);
    guRotateF(sp18, 20.0f, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp18, camera->viewMtxShaking, camera->viewMtxShaking);
    camera->panActive = TRUE;
    if (D_80249908_A33B48 >= 10) {
        guRotateF(camera->viewMtxShaking, 20.0f, 0.0f, 0.0f, 1.0f);
        return ApiStatus_DONE1;
    }
    D_80249908_A33B48++;
    return ApiStatus_BLOCK;
}

ApiStatus func_802419F4_A2BC34(Evt* script, s32 isInitialCall) {
    Npc* npc7 = resolve_npc(script, 7);
    Npc* npc8 = resolve_npc(script, 8);

    if (isInitialCall) {
        npc7->pos.x = -64.0f;
        npc7->pos.y = 400.0f;
        npc7->pos.z = 85.0f;
        npc8->pos.x = -64.0f;
        npc8->pos.y = 400.0f;
        npc8->pos.z = 85.0f;
        npc7->colliderPos.x = npc7->pos.x;
        npc8->colliderPos.x = npc8->pos.x;
        npc7->colliderPos.z = npc7->pos.z;
        npc8->colliderPos.z = npc8->pos.z;
        D_8024F2C8 = 400.0f;
    }
    if (D_80249910_A33B50 < 20) {
        npc7->pos.y = D_80249934_A33B74[D_80249910_A33B50];
    } else {
        npc7->pos.y += D_80249914_A33B54[((D_80249910_A33B50 - 20) & 30) / 2] * 0.1f;
    }
    npc8->pos.y = npc7->pos.y;
    npc7->colliderPos.y = npc7->pos.y;
    npc8->colliderPos.y = npc8->pos.y;

    D_80249910_A33B50++;
    if (D_80249910_A33B50 < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_80241B40_A2BD80(Evt* script, s32 isInitialCall) {
    Npc* npc7 = resolve_npc(script, 7);
    Npc* npc8 = resolve_npc(script, 8);

    if (isInitialCall) {
        npc7->pos.x = -64.0f;
        npc7->pos.y = 135.0f;
        npc7->pos.z = 85.0f;
        npc8->pos.x = -64.0f;
        npc8->pos.y = 135.0f;
        npc8->pos.z = 85.0f;
        npc7->colliderPos.x = npc7->pos.x;
        npc8->colliderPos.x = npc8->pos.x;
        npc7->colliderPos.z = npc7->pos.z;
        npc8->colliderPos.z = npc8->pos.z;
        D_8024F2CC = 135.0f;
    }
    npc7->pos.y += D_80249960_A33BA0[((u32) (D_8024995C_A33B9C - 20) & 30) / 2] * 0.1f;
    npc8->pos.y = npc7->pos.y;
    npc7->colliderPos.y = npc7->pos.y;
    npc8->colliderPos.y = npc8->pos.y;
    D_8024995C_A33B9C++;
    if (D_8024995C_A33B9C < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_80241C54_A2BE94(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    func_80241044_A2B284(30.0f, 15.0f, D_80249980_A33BC0, 1.0f, &D_80249980_A33BC0);
    func_80240D54_A2AF94(0, D_80249980_A33BC0);
    camera->panActive = TRUE;
    if (D_80249980_A33BC0 == 15.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80241D08_A2BF48(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        camera->flags &= ~CAMERA_FLAGS_SHAKING;
    }
    guTranslateF(camera->viewMtxShaking, 0.0f, 0.0f, 0.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80241D7C_A2BFBC(Evt* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, 9);

    if (isInitialCall) {
        npc->pos.x = -145.0f;
        npc->pos.z = 114.0f;
        npc->yaw = 270.0f;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.z = npc->pos.z;
    }
    if (D_80249984_A33BC4 == 30) {
        npc->yaw = 90.0f;
    }
    if (D_80249984_A33BC4 < 40) {
        npc->pos.x = D_802499A8_A33BE8[D_80249984_A33BC4][0] - 145;
        npc->pos.y = (((D_802499A8_A33BE8[D_80249984_A33BC4][1] - 135) * 200) / 225) + 147;
        if (D_80249984_A33BC4 < 20) {
            npc->pos.z = 114.0f - (D_80249984_A33BC4 * 30.0f) / 20.0f;
        } else {
            npc->pos.z = 84.0f;
        }
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.z = npc->pos.z;
    } else {
        npc->pos.y += D_80249988_A33BC8[((D_80249984_A33BC4 - 40) & 30) / 2] * 0.1f;
    }
    npc->colliderPos.y = npc->pos.y;
    D_80249984_A33BC4++;
    if (D_80249984_A33BC4 < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_80241F54_A2C194(Evt* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, 9);

    if (isInitialCall) {
        npc->pos.x = -145.0f;
        npc->pos.z = 84.0f;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.z = npc->pos.z;
        npc->yaw = 90.0f;
        npc->pos.y = 147.0f;
    }
    npc->pos.y += D_80249A4C_A33C8C[((D_80249A48_A33C88 - 40) & 30) / 2] * 0.1f;
    npc->colliderPos.y = npc->pos.y;

    D_80249A48_A33C88++;
    if (D_80249A48_A33C88 < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_80242024_A2C264(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    func_802410E4_A2B324(0, 121.6f, 90.0f, D_80249A70_A33CB0, 40.0f, &D_80249A6C_A33CAC);
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = D_80249A6C_A33CAC;
    if ((D_80249A70_A33CB0 == ((D_80249A70_A33CB0 / 5) * 5)) && (D_80249A6C_A33CAC != 90.0f)) {
        f32 temp_f4 = resolve_npc(script, 7)->pos.y - 150.0f;

        fx_fire_breath(
            1, script->varTable[0],
            script->varTable[1] + temp_f4,
            script->varTable[2],
            script->varTable[3] - 5,
            script->varTable[4] + temp_f4,
            script->varTable[5] - 30, 0, 5, 20
        );
    }

    D_80249A70_A33CB0++;
    if (D_80249A70_A33CB0 <= 40) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_802421E0_A2C420(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    func_802410E4_A2B324(4, 90.0f, 474.7f, D_80249A78_A33CB8, 20.0f, &D_80249A74_A33CB4);
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = D_80249A74_A33CB4;
    D_80249A78_A33CB8++;
    if (D_80249A78_A33CB8 < 21) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_802422A0_A2C4E0(Evt* script, s32 isInitialCall) {
    Npc* npc7 = resolve_npc(script, 7);
    Npc* npc8 = resolve_npc(script, 8);

    if (isInitialCall) {
        D_8024F2D8 = npc7->pos.x;
        D_8024F2DC = npc7->pos.z;
    }
    func_802410E4_A2B324(3, D_8024F2D8, 0.0f, D_80249A7C_A33CBC, 40.0f, &npc7->pos.x);
    func_802410E4_A2B324(3, D_8024F2DC, 0.0f, D_80249A7C_A33CBC, 40.0f, &npc7->pos.z);
    npc8->pos.x = npc7->pos.x;
    npc8->pos.z = npc7->pos.z;
    npc7->colliderPos.x = npc7->pos.x;
    npc7->colliderPos.z = npc7->pos.z;
    npc8->colliderPos.x = npc8->pos.x;
    npc8->colliderPos.z = npc8->pos.z;

    D_80249A7C_A33CBC++;
    if (D_80249A7C_A33CBC <= 40) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_802423D4_A2C614(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    func_802410E4_A2B324(4, 35.0f, 35.0f, D_80249A80_A33CC0, 80.0f, &D_8024F2E0);
    func_802410E4_A2B324(4, 130.0f, 270.0f, D_80249A80_A33CC0, 80.0f, &D_8024F2E4);
    func_802410E4_A2B324(4, 30.0f, 0.0f, D_80249A80_A33CC0, 80.0f, &D_8024F2E8);
    func_802410E4_A2B324(4, 232.0f, 177.0f, D_80249A80_A33CC0, 80.0f, &D_8024F2EC);
    func_802410E4_A2B324(4, 0.0f, 0.0f, D_80249A80_A33CC0, 80.0f, &D_8024F2F0_C0CB70);
    func_80240D54_A2AF94(0, D_8024F2E0);
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = D_8024F2E4;
    camera->movePos.x = D_8024F2E8;
    camera->movePos.y = D_8024F2EC;
    camera->movePos.z = D_8024F2F0_C0CB70;

    D_80249A80_A33CC0++;
    if (D_80249A80_A33CC0 <= 90) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

ApiStatus func_802425A0_A2C7E0(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    func_802410E4_A2B324(0, 40.0f, -130.0f, D_80249A90_A33CD0, 170.0f, &D_80249A84_A33CC4);
    func_802410E4_A2B324(0, -40.0f, 130.0f, D_80249A90_A33CD0, 170.0f, &D_80249A88_A33CC8);
    func_802410E4_A2B324(3, 45.0f, 25.0f, D_80249A90_A33CD0, 170.0f, &D_80249A8C_A33CCC);
    camera->panActive = TRUE;
    camera->movePos.x = D_80249A84_A33CC4;
    camera->movePos.z = D_80249A88_A33CC8;
    camera->controlSettings.posB.x = sin_deg(D_80249A8C_A33CCC) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(D_80249A8C_A33CCC) * 500.0f;

    D_80249A90_A33CD0++;
    if (D_80249A90_A33CD0 == 170) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80242704_A2C944(void) {
    Camera* camera = &gCameras[gCurrentCameraID];

    func_802410E4_A2B324(3, 25.0f, 200.0f, D_80249AA4_A33CE4, 120.0f, &D_80249AA0_A33CE0);
    func_802410E4_A2B324(3, 50.0f, 35.0f, D_80249AA4_A33CE4, 30.0f, &D_80249A94_A33CD4);
    func_802410E4_A2B324(3, 246.1f, 180.0f, D_80249AA4_A33CE4, 30.0f, &D_80249A98_A33CD8);
    func_802410E4_A2B324(3, 200.0f, 220.0f, D_80249AA4_A33CE4, 30.0f, &D_80249A9C_A33CDC);
    camera->controlSettings.posB.x = sin_deg(D_80249AA0_A33CE0) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(D_80249AA0_A33CE0) * 500.0f;
    func_80240D54_A2AF94(0, D_80249A94_A33CD4);
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = D_80249A98_A33CD8;
    camera->movePos.y = D_80249A9C_A33CDC;
    D_80249AA4_A33CE4++;
    if (D_80249AA4_A33CE4 <= 120) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802428C8_A2CB08);

ApiStatus func_80242F74_A2D1B4(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    func_80241044_A2B284(D_8024987C_A33ABC, D_802498A8_A33AE8, D_8024A9C8_A34C08, 1.0f, &D_8024A9C8_A34C08);
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = D_8024A9C8_A34C08;
    if (D_8024A9C8_A34C08 == 700.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8024301C_A2D25C(Evt* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, 9);

    if (isInitialCall) {
        D_8024F2F4 = npc->pos.x;
        D_8024F2F8 = npc->pos.z;
    }

    func_802410E4_A2B324(3, D_8024F2F4, -95.0f, D_8024A9CC_A34C0C, 40.0f, &npc->pos.x);
    func_802410E4_A2B324(3, D_8024F2F8, 20.0f, D_8024A9CC_A34C0C, 40.0f, &npc->pos.z);
    npc->colliderPos.x = npc->pos.x;
    npc->colliderPos.z = npc->pos.z;

    D_8024A9CC_A34C0C++;
    if (D_8024A9CC_A34C0C <= 40) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

void func_80243164_A2D3A4(
    s32 baseX, s32 baseY,
    IMG_PTR img, PAL_PTR pal,
    s32 alpha, s32 width, s32 height, s32 lineHeight
);

void func_80243100_A2D340(void) {
    s32 x = D_8024AA20_A34C60->unk_44 << 0x10;
    s32 y = D_8024AA20_A34C60->unk_46 << 0x10;

    if (D_8024AA20_A34C60->unk_00 != 0) {
        func_80243164_A2D3A4(
            x >> 0x10, y >> 0x10,
            D_8024AA20_A34C60->unk_1C, D_8024AA20_A34C60->unk_20,
            255, 128, 128, 16
        );
    }
}

void func_80243164_A2D3A4(s32 baseX, s32 baseY, IMG_PTR img, PAL_PTR pal, s32 alpha, s32 width, s32 height, s32 lineHeight) {
    u8 overlayType;
    f32 overlayZoomBack;
    f32 overlayZoomFront;
    s32 i;

    if (alpha == 0) {
        return;
    }

    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_8024AA28_A34C68);

    if (pal != NULL) {
        gDPLoadTLUT_pal256(gMasterGfxPos++, pal);
    } else {
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    }

    get_screen_overlay_params(1, &overlayType, &overlayZoomBack);
    get_screen_overlay_params(0, &overlayType, &overlayZoomFront);
    alpha = alpha * (255.0f - overlayZoomBack) * (255.0f - overlayZoomFront) / 255.0f / 255.0f;
    if (alpha != 255) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);
    } else {
        gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);


    for (i = 0; i < height / lineHeight; i++) {
        gDPLoadTextureTile(gMasterGfxPos++, img, pal != NULL ? G_IM_FMT_CI : G_IM_FMT_IA, G_IM_SIZ_8b, width, height,
                           0, i * lineHeight, width - 1, i * lineHeight + lineHeight - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gMasterGfxPos++, baseX * 4, (baseY + i * lineHeight) * 4, (baseX + width) * 4, (baseY + i * lineHeight + lineHeight) * 4,
                                G_TX_RENDERTILE, 0, (i * lineHeight) * 32, 1024, 1024);
    }

    gDPPipeSync(gMasterGfxPos++);
}

void func_8024370C_A2D94C(void) {
    func_80243164_A2D3A4(
        D_8024AA20_A34C60->unk_48, D_8024AA20_A34C60->unk_4A,
        D_8024AA20_A34C60->unk_18, NULL,
        D_8024AA20_A34C60->unk_5C, 128, 128, 32
    );
}

void func_80243758_A2D998(s32 baseX, s32 baseY, IMG_PTR img, PAL_PTR pal) {
    s32 i;
    s32 m = 1;

    gDPPipeSync(gMasterGfxPos++);
    gDPLoadTLUT_pal256(gMasterGfxPos++, pal);
    for (i = 0; i < 23; i++) {
        gDPLoadTextureTile(gMasterGfxPos++, img, G_IM_FMT_CI, G_IM_SIZ_8b, 264, 162,
                           0, i * 7, 263, i * 7 + 7 - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gMasterGfxPos++, baseX * 4, (baseY + i * 7) * 4, (baseX + 264) * 4, (baseY + i * 7 + 7) * 4,
                                G_TX_RENDERTILE, 0, (i * 7) << 5, 1024, 1024);
    }
    if (m != 0) {
        gDPLoadTextureTile(gMasterGfxPos++, img, G_IM_FMT_CI, G_IM_SIZ_8b, 264, 0,
                           0, i * 7, 263, i * 7 + m - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gMasterGfxPos++, baseX * 4, (baseY + i * 7) * 4, (baseX + 264) * 4, (baseY + i * 7 + m) * 4,
                                G_TX_RENDERTILE, 0, (i * 7) << 5, 1024, 1024);
    }
    gDPPipeSync(gMasterGfxPos++);
}

void func_80243CC0_A2DF00(void) {
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 vpX = camera->viewportStartX;
    s32 vpY = camera->viewportStartY;
    u8 sp10;
    f32 sp14;

    func_8024370C_A2D94C();

    gSPDisplayList(gMasterGfxPos++, D_8024AA28_A34C68);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb_ptr);

    if (D_8024AA20_A34C60->unk_5A < 255) {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_8024AA20_A34C60->unk_5A);
    }
    get_screen_overlay_params(1, &sp10, &sp14);
    if (sp14 != 0.0f) {
        gDPSetCombineLERP(gMasterGfxPos++, PRIMITIVE, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, 1, PRIMITIVE, TEXEL0,
                          PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, 1);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 208, 208, 208, (s32) sp14);
    }

    if (!D_8024AA20_A34C60->unk_58) {
        func_80243758_A2D998(
            vpX + D_8024AA20_A34C60->unk_40,
            vpY + D_8024AA20_A34C60->unk_42,
            D_8024AA20_A34C60->unk_0C,
            D_8024AA20_A34C60->unk_10
        );
        func_80243758_A2D998(
            vpX + D_8024AA20_A34C60->unk_3C,
            vpY + D_8024AA20_A34C60->unk_3E,
            D_8024AA20_A34C60->unk_04,
            D_8024AA20_A34C60->unk_08
        );
    } else {
        func_80243758_A2D998(
            vpX + D_8024AA20_A34C60->unk_3C,
            vpY + D_8024AA20_A34C60->unk_3E,
            D_8024AA20_A34C60->unk_04,
            D_8024AA20_A34C60->unk_08
        );
        func_80243758_A2D998(
            vpX + D_8024AA20_A34C60->unk_40,
            vpY + D_8024AA20_A34C60->unk_42,
            D_8024AA20_A34C60->unk_0C,
            D_8024AA20_A34C60->unk_10
        );
    }
}

void func_80243ED0_A2E110(s32 arg0, s32 idx) {
    s32 i;

    idx--;
    if (idx < 0) {
        u16* pal = D_8024AA20_A34C60->unk_08;

        for (i = 0; i < 256; i++) {
            *pal++ = 0xD6B5;
        }
        return;
    }

    if (!arg0) {
        dma_copy(
            title_bg_1_ROM_START + idx * 0xA910,
            title_bg_1_ROM_START + (idx + 1) * 0xA910 ,
            D_8024AA20_A34C60->unk_04
        );
    } else {
        dma_copy(
            title_bg_1_ROM_START + idx * 0xA910,
            title_bg_1_ROM_START + (idx + 1) * 0xA910 ,
            D_8024AA20_A34C60->unk_0C
        );
    }
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80243FC4_A2E204);

// needs D_8024AAB4_A34CF4 to be migrated
#ifdef NON_MATCHING
ApiStatus func_802440D0_A2E310(Evt* script, s32 isInitialCall) {
    switch (D_8024AAB0_A34CF0) {
        case 0:
            D_8024AAB0_A34CF0++;
            D_8024AAB8_A34CF8 = D_8024AAC0_A34D00[D_8024AAB4_A34CF4];
            break;
        case 1:
            if (D_8024AAB8_A34CF8 != 0) {
                D_8024AAB8_A34CF8--;
            } else {
                D_8024AAB8_A34CF8 = 26;
                D_8024AAB0_A34CF0++;
                sfx_play_sound(SOUND_B0);
            }
            break;
        case 2:
            if (D_8024AAB8_A34CF8 != 0) {
                D_8024AAB8_A34CF8--;
                if (!D_8024AA20_A34C60->unk_58) {
                    D_8024AA20_A34C60->unk_3C = D_8024AAD6_A34D14[25 - D_8024AAB8_A34CF8];
                    D_8024AA20_A34C60->unk_3E = 0;
                } else {
                    D_8024AA20_A34C60->unk_40 = D_8024AAD6_A34D14[25 - D_8024AAB8_A34CF8];
                    D_8024AA20_A34C60->unk_42 = 0;
                }
            } else {
                D_8024AAB4_A34CF4++;
                if (D_8024AAB4_A34CF4 + 1 < 5) {
                    func_80243ED0_A2E110(D_8024AA20_A34C60->unk_58, D_8024AAB4_A34CF4 + 1);
                    D_8024AAB0_A34CF0 = 0;
                    D_8024AA20_A34C60->unk_3C = 0;
                    D_8024AA20_A34C60->unk_3E = 0;
                    D_8024AA20_A34C60->unk_40 = 0;
                    D_8024AA20_A34C60->unk_42 = 0;
                    D_8024AA20_A34C60->unk_58 = D_8024AA20_A34C60->unk_58 ^ 1;
                } else {
                    if (!D_8024AA20_A34C60->unk_58) {
                        D_8024AA20_A34C60->unk_40 = 0;
                        D_8024AA20_A34C60->unk_42 = 0;
                    } else {
                        D_8024AA20_A34C60->unk_3C = 0;
                        D_8024AA20_A34C60->unk_3E = 0;
                    }
                    gCameras[CAM_DEFAULT].flags &= ~CAMERA_FLAGS_ENABLED;
                    D_8024AAB0_A34CF0++;
                }
            }
            break;
        case 3:
            D_8024AABC_A34CFC = 0;
            D_8024AAB0_A34CF0++;
            D_8024AAB8_A34CF8 = D_8024AAC0_A34D00[D_8024AAB4_A34CF4];
            break;
        case 4:
            if (D_8024AAB8_A34CF8 != 0) {
                if (D_8024AAB8_A34CF8 < D_8024AAC0_A34D00[D_8024AAB4_A34CF4] - 268) {
                    u32 temp_v1 = D_8024AABC_A34CFC - 320;

                    if (D_8024AABC_A34CFC < 320) {
                        D_8024AA20_A34C60->unk_44 = D_8024AC7C_A34EBC[0];
                        D_8024AA20_A34C60->unk_46 = D_8024AB3C_A34D7C[D_8024AABC_A34CFC];
                    } else if (temp_v1 < 15) {
                        D_8024AA20_A34C60->unk_44 = D_8024AC7C_A34EBC[temp_v1];
                        if (temp_v1 < 13) {
                            D_8024AA20_A34C60->unk_46 = D_8024AC7B_A34EBB + D_8024AC9C_A34EDC[temp_v1];
                        }
                    }
                    D_8024AABC_A34CFC++;
                }
                D_8024AAB8_A34CF8--;
            } else {
                D_8024AAB8_A34CF8 = 26;
                D_8024AAB0_A34CF0++;
                D_8024AA20_A34C60->unk_5C = 255;
                sfx_play_sound(SOUND_B0);
            }
            break;
        case 5:
            if (D_8024AAB8_A34CF8 != 0) {
                D_8024AAB8_A34CF8--;
                if (!D_8024AA20_A34C60->unk_58) {
                    D_8024AA20_A34C60->unk_40 = D_8024AAD6_A34D14[25 - D_8024AAB8_A34CF8];
                    D_8024AA20_A34C60->unk_42 = 0;
                } else {
                    D_8024AA20_A34C60->unk_3C = D_8024AAD6_A34D14[25 - D_8024AAB8_A34CF8];
                    D_8024AA20_A34C60->unk_3E = 0;
                }
            } else {
                D_8024AAB0_A34CF0++;
            }
            break;
        case 6:
        default:
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802440D0_A2E310);
#endif

ApiStatus func_80244454_A2E694(Evt* script, s32 isInitialCall) {
    if (D_8024ACB8_A34EF8 != 0) {
        D_8024ACB8_A34EF8--;
        D_8024AA20_A34C60->unk_5C = (D_8024ACB8_A34EF8 * 255) / 30;
        return ApiStatus_BLOCK;
    } else {
        D_8024AA20_A34C60->unk_5C = 0;
        free_worker(D_8024AA20_A34C60->unk_00);
        D_8024AA20_A34C60->unk_00 = 0;
        return ApiStatus_DONE1;
    }
}

ApiStatus func_802444E8_A2E728(Evt* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, 10);

    npc->yaw = npc->renderYaw = 180.0f - gCameras[gCurrentCameraID].currentYaw;
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80244550_A2E790);

ApiStatus func_80244774_A2E9B4(Evt* script, s32 isInitialCall) {
    Npc* npc7 = resolve_npc(script, 7);
    Npc* npc8 = resolve_npc(script, 8);

    if (isInitialCall) {
        D_8024F374 = npc7->pos.y;
    }
    func_802410E4_A2B324(3, D_8024F374, D_8024F374 + 500.0f, D_8024AEC4_A35104, 40.0f, &npc7->pos.y);
    npc8->pos.y = npc7->pos.y;
    npc7->colliderPos.y = npc7->pos.y;
    npc8->colliderPos.y = npc8->pos.y;
    D_8024AEC4_A35104++;
    if (D_8024AEC4_A35104 > 40.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8024486C_A2EAAC(Evt* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, 9);

    if (isInitialCall) {
        D_8024F378 = npc->pos.y;
    }
    func_802410E4_A2B324(3, D_8024F378, D_8024F378 + 500.0f, D_8024AEC8_A35108, 40.0f, &npc->pos.y);
    npc->colliderPos.y = npc->pos.y;
    D_8024AEC8_A35108++;
    if (D_8024AEC8_A35108 > 40.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80244934_A2EB74(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        set_screen_overlay_params_back(1, 255.0f);
        set_screen_overlay_color(1, 250, 250, 250);
        return ApiStatus_BLOCK;
    }
    script->functionTemp[0]++;
    if (script->functionTemp[0] == 10) {
        set_screen_overlay_params_back(0, 0.0f);
        set_screen_overlay_color(1, 250, 250, 250);
        return ApiStatus_DONE2;
    }
    set_screen_overlay_params_back(1, (10 - script->functionTemp[0]) * 25);
    set_screen_overlay_color(1, 250, 250, 250);
    return ApiStatus_BLOCK;
}
