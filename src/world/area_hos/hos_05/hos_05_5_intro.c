#include "hos_05.h"
#include "effects.h"
#include "model.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

typedef struct StoryGraphicData {
    /* 0x00 */ s32 workerID; // entity ID
    /* 0x04 */ IMG_PTR imgFront;
    /* 0x08 */ PAL_PTR palFront;
    /* 0x0C */ IMG_PTR imgBack;
    /* 0x10 */ PAL_PTR palBack;
    /* 0x14 */ char unk_14[0x4];
    /* 0x18 */ IMG_PTR imgTape;
    /* 0x1C */ IMG_PTR imgBowser;
    /* 0x20 */ PAL_PTR palBowser;
    /* 0x24 */ char unk_24[0x18];
    /* 0x3C */ s16 frontImgPosX;
    /* 0x3E */ s16 frontImgPosY;
    /* 0x40 */ s16 backImgPosX;
    /* 0x42 */ s16 backImgPosY;
    /* 0x44 */ u16 silhouettePosX; // x
    /* 0x46 */ u16 silhouettePosY; // y
    /* 0x48 */ s16 tapePosX; // x
    /* 0x4A */ s16 tapePosY; // y
    /* 0x4C */ char unk_4C[0xC];
    /* 0x58 */ s16 flipOrder; // bool
    /* 0x5A */ s16 unk_5A;
    /* 0x5C */ s16 tapeAlpha; // alpha
    /* 0x60 */ char unk_6E[0x2];
} StoryGraphicData; // size = 0x60

s32 N(missing_802494FC_94FC)[] = {
    0x64, 0x63, 0x62, 0x60, 0x5E, 0x5C, 0x59, 0x57,
    0x54, 0x51, 0x4F, 0x4E, 0x4D, 0x4D, 0x4C, 0x4C,
    0x4C, 0x4C, 0x4D, 0x4D, 0x4E, 0x4E, 0x4F, 0x4F,
    0x50, 0x50, 0x51, 0x51, 0x52, 0x52, 0x53, 0x53,
    0x54, 0x54, 0x55, 0x55, 0x56, 0x56, 0x57, 0x57,
    0x58, 0x58, 0x59, 0x59, 0x5A, 0x5B, 0x5C, 0x5D,
    0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 
};

s32 N(D_802495DC_A3381C) = 0;

s32 N(D_802495E0_A33820) = 0;

CameraControlSettings N(IntroCamSettings0) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 130.4,
	.boomPitch = 12.4,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 0.0, -1.0, -500.0 },
	.viewPitch = -16.8,
	.flag = FALSE,
};
	
CameraControlSettings N(IntroCamSettings1) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 130.4,
	.boomPitch = 12.4,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { -433.0127, -1.0, -250.0 },
	.viewPitch = -16.8,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings2) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 400.0,
	.boomPitch = 2.7,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 0.0, -1.0, -500.0 },
	.viewPitch = -7.4,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings3) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 274.4,
	.boomPitch = -9.3,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 114.3, -1.0, 500.0 },
	.viewPitch = 0.7,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings4) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 274.4,
	.boomPitch = -9.3,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 114.3, -1.0, 500.0 },
	.viewPitch = 0.7,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings5) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 243.3,
	.boomPitch = 16.0,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 56.1, -1.0, -1.1 },
	.viewPitch = -3.0,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings6) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 192.5,
	.boomPitch = 12.4,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 0.0, -1.0, 500.0 },
	.viewPitch = -10.7,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings7) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 467.0,
	.boomPitch = 21.0,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 71.3, -1.0, 154.3 },
	.viewPitch = -3.0,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings8) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 121.6,
	.boomPitch = 0.0,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 24.4, -1.0, 154.3 },
	.viewPitch = 0.0,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings9) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 474.7,
	.boomPitch = 0.0,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 24.4, -1.0, 154.3 },
	.viewPitch = 0.0,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings10) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 225.7,
	.boomPitch = 9.7,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 6.9, -1.0, 168.8 },
	.viewPitch = -3.0,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings11) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 130.0,
	.boomPitch = 9.8,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 40.0, -1.0, 168.8 },
	.viewPitch = -9.3,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings12) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 270.0,
	.boomPitch = 9.8,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 40.0, -1.0, 168.8 },
	.viewPitch = -9.3,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings13) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 246.1,
	.boomPitch = -1.3,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 500.0, -1.0, 500.0 },
	.viewPitch = 0.5,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings14) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 180.0,
	.boomPitch = -1.3,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 0.0, -1.0, -500.0 },
	.viewPitch = 0.5,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings15) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 90.0,
	.boomPitch = 5.4,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 0.0, -1.0, 500.0 },
	.viewPitch = -6.9,
	.flag = FALSE,
};

CameraControlSettings N(IntroCamSettings16) = {
	.type = CAMERA_SETTINGS_TYPE_0,
	.boomLength = 445.8,
	.boomPitch = 5.4,
	.posA = { 0.0, -1.0, 0.0 },
	.posB = { 0.0, -1.0, 500.0 },
	.viewPitch = -6.9,
	.flag = FALSE,
};

f32 N(D_802498D0_A33B10) = 240.0;

API_CALLABLE(N(SetWorldFogParams)) {
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

API_CALLABLE(N(SetWorldColorParams)) {
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

void N(adjust_cam_vfov)(s32 camID, f32 fov) {
    Camera* camera = &gCameras[camID];
    camera->vfov = fov * 1.1;
}

API_CALLABLE(N(AdjustCamVfov)) {
    Bytecode* args = script->ptrReadPos;
    s32 camID = evt_get_variable(script, *args++);
    f32 fov = evt_get_float_variable(script, *args++);

    N(adjust_cam_vfov)(camID, fov);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ResumeIntro)) {
    GameStatus* gameStatus = gGameStatusPtr;
    if (gameStatus->creditsViewportMode < 5U) {
        gameStatus->creditsViewportMode++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

API_CALLABLE(N(InitWorldFogMode)) {
    mdl_set_all_fog_mode(FOG_MODE_3);
    return ApiStatus_DONE2;
}

// adjusts properties of EmitterVolume:GoldShimmer2 effect
API_CALLABLE(N(func_80240E50_A2B090)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 subtype = evt_get_variable(script, *args++);
    s32 posX = evt_get_float_variable(script, *args++);
    s32 posY = evt_get_float_variable(script, *args++);
    s32 posZ = evt_get_float_variable(script, *args++);

    effect->data.miscParticles->pos.x = posX;
    effect->data.miscParticles->pos.y = posY;
    effect->data.miscParticles->pos.z = posZ;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240F30_A2B170)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(0));

    effect->data.somethingRotating[N(D_802495DC_A3381C) + 1].state = 1;
    N(D_802495DC_A3381C)++;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240F88_A2B1C8)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(0));

    effect->data.somethingRotating[N(D_802495E0_A33820) + 1].state = 3;
    N(D_802495E0_A33820)++;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240FE0_A2B220)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(16));

    effect->data.lightRays->unk_10 = script->varTable[0];
    effect->data.lightRays->unk_14 = script->varTable[1];
    effect->data.lightRays->unk_18 = script->varTable[2];
    return ApiStatus_DONE2;
}

#include "../common/IntroMathUtil.inc.c"

u16* N(ColorBufPtr) = NULL;

f32 IntroCamStateA_BoomLength = 130.4;
f32 IntroCamStateA_BoomPitch = 12.4;
f32 IntroCamStateA_ViewPitch = -16.8;
f32 IntroCamStateA_Vfov = 62.0;

API_CALLABLE(N(func_80241274_A2B4B4)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == N(ColorBufPtr)) {
        return ApiStatus_BLOCK;
    }
    N(ColorBufPtr) = nuGfxCfb_ptr;
    N(lerp_value_with_max_step)(250.0f, 0.0f, N(D_802498D0_A33B10), 0.5f, &N(D_802498D0_A33B10));
    N(interp_value_with_easing)(INTRO_MATH_EASING_SIN_OUT_DELAYED, 130.4f, N(IntroCamSettings2).boomLength, 0.0f, 470.0f, &IntroCamStateA_BoomLength);
    N(lerp_value_with_max_step)(12.4f, N(IntroCamSettings2).boomPitch, IntroCamStateA_BoomPitch, 0.05f, &IntroCamStateA_BoomPitch);
    N(lerp_value_with_max_step)(-16.8f, N(IntroCamSettings2).viewPitch, IntroCamStateA_ViewPitch, 0.05f, &IntroCamStateA_ViewPitch);
    N(lerp_value_with_max_step)(62.0f, 49.0f, IntroCamStateA_Vfov, 0.1f, &IntroCamStateA_Vfov);
    N(adjust_cam_vfov)(CAM_DEFAULT, IntroCamStateA_Vfov);
    camera->controlSettings.boomLength = IntroCamStateA_BoomLength;
    camera->controlSettings.boomPitch = IntroCamStateA_BoomPitch;
    camera->controlSettings.viewPitch = IntroCamStateA_ViewPitch;
    camera->controlSettings.posB.x = sin_deg(N(D_802498D0_A33B10)) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(N(D_802498D0_A33B10)) * -500.0f;
    camera->panActive = TRUE;
    return ApiStatus_DONE2;
}

f32 IntroCamStateB_BoomLength = 130.4;
f32 IntroCamStateB_BoomPitch = 12.4;
f32 IntroCamStateB_ViewPitch = -16.8;
f32 IntroCamStateB_Vfov = 62.0;

s32 N(D_802498F8_A33B38) = 0;
s32 N(D_802498FC_A33B3C) = 0;

API_CALLABLE(N(func_8024146C_A2B6AC)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == N(ColorBufPtr)) {
        return ApiStatus_BLOCK;
    }
    N(ColorBufPtr) = nuGfxCfb_ptr;
    N(lerp_value_with_max_step)(250.0f, 0.0f, N(D_802498D0_A33B10), 0.5f, &N(D_802498D0_A33B10));
    N(interp_value_with_easing)(INTRO_MATH_EASING_SIN_OUT_DELAYED, 130.4f, N(IntroCamSettings2).boomLength, N(D_802498FC_A33B3C), 470.0f, &IntroCamStateB_BoomLength);
    N(lerp_value_with_max_step)(12.4f, N(IntroCamSettings2).boomPitch, IntroCamStateB_BoomPitch, 0.05f, &IntroCamStateB_BoomPitch);
    N(lerp_value_with_max_step)(-16.8f, N(IntroCamSettings2).viewPitch, IntroCamStateB_ViewPitch, 0.05f, &IntroCamStateB_ViewPitch);
    N(lerp_value_with_max_step)(62.0f, 49.0f, IntroCamStateB_Vfov, 0.1f, &IntroCamStateB_Vfov);
    N(adjust_cam_vfov)(CAM_DEFAULT, IntroCamStateB_Vfov);
    camera->controlSettings.boomLength = IntroCamStateB_BoomLength;
    camera->controlSettings.boomPitch = IntroCamStateB_BoomPitch;
    camera->controlSettings.viewPitch = IntroCamStateB_ViewPitch;
    camera->controlSettings.posB.x = sin_deg(N(D_802498D0_A33B10)) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(N(D_802498D0_A33B10)) * -500.0f;
    camera->panActive = TRUE;
    N(D_802498FC_A33B3C)++;
    if (N(D_802498D0_A33B10) == 0.0f) {
        N(D_802498F8_A33B38)++;
    }

    if (N(D_802498F8_A33B38) <= 30) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(D_80249900_A33B40) = 0;
f32 N(D_80249904_A33B44) = 1.0;

API_CALLABLE(N(func_802416BC_A2B8FC)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAG_SHAKING;
    }
    guTranslateF(camera->viewMtxShaking,
        N(D_80249904_A33B44) * sin_deg(N(D_80249900_A33B40) * 486),
        N(D_80249904_A33B44) * cos_deg(N(D_80249900_A33B40) * 254),
        0.0f
    );
    N(D_80249900_A33B40)++;
    N(D_80249904_A33B44) += (12.0f - N(D_80249904_A33B44)) * 0.2;
    if (N(D_80249900_A33B40) > 20) {
        guTranslateF(camera->viewMtxShaking, 0.0f, 0.0f, 0.0f);
        camera->flags &= ~CAMERA_FLAG_SHAKING;
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

s32 N(D_80249908_A33B48) = 0;
f32 N(D_8024990C_A33B4C) = 12.0;

API_CALLABLE(N(func_80241850_A2BA90)) {
    Camera* camera = &gCameras[gCurrentCameraID];
    Matrix4f sp18;
    f32 x, y;

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAG_SHAKING;
    }
    x = N(D_8024990C_A33B4C) * sin_deg(N(D_80249908_A33B48) * 486);
    y = N(D_8024990C_A33B4C) * cos_deg(N(D_80249908_A33B48) * 254);
    guTranslateF(camera->viewMtxShaking, x, y, 0.0f);
    guTranslateF(camera->viewMtxShaking, x, y, 0.0f);
    guRotateF(sp18, 20.0f, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp18, camera->viewMtxShaking, camera->viewMtxShaking);
    camera->panActive = TRUE;
    if (N(D_80249908_A33B48) >= 10) {
        guRotateF(camera->viewMtxShaking, 20.0f, 0.0f, 0.0f, 1.0f);
        return ApiStatus_DONE1;
    }
    N(D_80249908_A33B48)++;
    return ApiStatus_BLOCK;
}

s32 N(D_80249910_A33B50) = 0;

s16 N(D_80249914_A33B54)[] = {
    -3, -2, -1, 0, 1, 2, 3, 4, 3, 2, 1, 0, -1, -2, -3, -4
};

s16 N(D_80249934_A33B74)[] = {
    360, 345, 330, 315, 300, 285, 270, 255, 
    240, 225, 215, 203, 191, 180, 170, 161, 153, 146, 140, 135
};

BSS f32 N(D_8024F2C8);

API_CALLABLE(N(func_802419F4_A2BC34)) {
    Npc* npc7 = resolve_npc(script, NPC_Bowser_Main);
    Npc* npc8 = resolve_npc(script, NPC_Bowser_Prop);

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
        N(D_8024F2C8) = 400.0f;
    }
    if (N(D_80249910_A33B50) < 20) {
        npc7->pos.y = N(D_80249934_A33B74)[N(D_80249910_A33B50)];
    } else {
        npc7->pos.y += N(D_80249914_A33B54)[((N(D_80249910_A33B50) - 20) & 30) / 2] * 0.1f;
    }
    npc8->pos.y = npc7->pos.y;
    npc7->colliderPos.y = npc7->pos.y;
    npc8->colliderPos.y = npc8->pos.y;

    N(D_80249910_A33B50)++;
    if (N(D_80249910_A33B50) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(D_8024995C_A33B9C) = 0;

s16 N(D_80249960_A33BA0)[] = {
    -3, -2, -1, 0, 1, 2, 3, 4, 3, 2, 1, 0, -1, -2, -3, -4
};

BSS f32 N(D_8024F2CC);

API_CALLABLE(N(func_80241B40_A2BD80)) {
    Npc* npc7 = resolve_npc(script, NPC_Bowser_Main);
    Npc* npc8 = resolve_npc(script, NPC_Bowser_Prop);

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
        N(D_8024F2CC) = 135.0f;
    }
    npc7->pos.y += N(D_80249960_A33BA0)[((u32) (N(D_8024995C_A33B9C) - 20) & 30) / 2] * 0.1f;
    npc8->pos.y = npc7->pos.y;
    npc7->colliderPos.y = npc7->pos.y;
    npc8->colliderPos.y = npc8->pos.y;
    N(D_8024995C_A33B9C)++;
    if (N(D_8024995C_A33B9C) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(D_80249980_A33BC0) = 30.0;

API_CALLABLE(N(func_80241C54_A2BE94)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(lerp_value_with_max_step)(30.0f, 15.0f, N(D_80249980_A33BC0), 1.0f, &N(D_80249980_A33BC0));
    N(adjust_cam_vfov)(CAM_DEFAULT, N(D_80249980_A33BC0));
    camera->panActive = TRUE;
    if (N(D_80249980_A33BC0) == 15.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80241D08_A2BF48)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        camera->flags &= ~CAMERA_FLAG_SHAKING;
    }
    guTranslateF(camera->viewMtxShaking, 0.0f, 0.0f, 0.0f);
    return ApiStatus_DONE2;
}

s32 N(D_80249984_A33BC4) = 0;

s16 N(D_80249988_A33BC8)[] = {
    -3, -2, -1, 0, 1, 2, 3, 4, 3, 2, 1, 0, -1, -2, -3, -4
};

s16 N(D_802499A8_A33BE8)[][2] = {
    { 0x0064, 0x00F0 },
    { 0x0063, 0x00E6 },
    { 0x0062, 0x00DC },
    { 0x0060, 0x00D3 },
    { 0x005C, 0x00CA },
    { 0x0057, 0x00C2 },
    { 0x0052, 0x00BB },
    { 0x004D, 0x00B5 },
    { 0x0048, 0x00B0 },
    { 0x0042, 0x00AB },
    { 0x003C, 0x00A7 },
    { 0x0035, 0x00A3 },
    { 0x002D, 0x00A0 },
    { 0x0026, 0x009D },
    { 0x001F, 0x009B },
    { 0x0019, 0x0099 },
    { 0x0013, 0x0098 },
    { 0x000D, 0x0096 },
    { 0x0007, 0x0095 },
    { 0x0001, 0x0094 },
    { 0xFFFB, 0x0093 },
    { 0xFFF6, 0x0092 },
    { 0xFFF2, 0x0091 },
    { 0xFFEF, 0x008F },
    { 0xFFEE, 0x008E },
    { 0xFFEE, 0x008E },
    { 0xFFEE, 0x008E },
    { 0xFFEE, 0x008E },
    { 0xFFEE, 0x008E },
    { 0xFFEE, 0x008E },
    { 0xFFEE, 0x008D },
    { 0xFFEF, 0x008C },
    { 0xFFF0, 0x008B },
    { 0xFFF2, 0x008A },
    { 0xFFF5, 0x0089 },
    { 0xFFF8, 0x0088 },
    { 0xFFFB, 0x0087 },
    { 0xFFFD, 0x0087 },
    { 0xFFFF, 0x0087 },
    { 0x0000, 0x0087 },
};

API_CALLABLE(N(func_80241D7C_A2BFBC)) {
    Npc* npc = resolve_npc(script, NPC_Kammy);

    if (isInitialCall) {
        npc->pos.x = -145.0f;
        npc->pos.z = 114.0f;
        npc->yaw = 270.0f;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.z = npc->pos.z;
    }
    if (N(D_80249984_A33BC4) == 30) {
        npc->yaw = 90.0f;
    }
    if (N(D_80249984_A33BC4) < 40) {
        npc->pos.x = N(D_802499A8_A33BE8)[N(D_80249984_A33BC4)][0] - 145;
        npc->pos.y = (((N(D_802499A8_A33BE8)[N(D_80249984_A33BC4)][1] - 135) * 200) / 225) + 147;
        if (N(D_80249984_A33BC4) < 20) {
            npc->pos.z = 114.0f - (N(D_80249984_A33BC4) * 30.0f) / 20.0f;
        } else {
            npc->pos.z = 84.0f;
        }
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.z = npc->pos.z;
    } else {
        npc->pos.y += N(D_80249988_A33BC8)[((N(D_80249984_A33BC4) - 40) & 30) / 2] * 0.1f;
    }
    npc->colliderPos.y = npc->pos.y;
    N(D_80249984_A33BC4)++;
    if (N(D_80249984_A33BC4) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(D_80249A48_A33C88) = 0;

s16 N(D_80249A4C_A33C8C)[] = {
    -3, -2, -1, 0, 1, 2, 3, 4, 3, 2, 1, 0, -1, -2, -3, -4 
};

API_CALLABLE(N(func_80241F54_A2C194)) {
    Npc* npc = resolve_npc(script, NPC_Kammy);

    if (isInitialCall) {
        npc->pos.x = -145.0f;
        npc->pos.z = 84.0f;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.z = npc->pos.z;
        npc->yaw = 90.0f;
        npc->pos.y = 147.0f;
    }
    npc->pos.y += N(D_80249A4C_A33C8C)[((N(D_80249A48_A33C88) - 40) & 30) / 2] * 0.1f;
    npc->colliderPos.y = npc->pos.y;

    N(D_80249A48_A33C88)++;
    if (N(D_80249A48_A33C88) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(D_80249A6C_A33CAC) = 121.6;
s32 N(D_80249A70_A33CB0) = 0;

API_CALLABLE(N(func_80242024_A2C264)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_LINEAR, 121.6f, 90.0f, N(D_80249A70_A33CB0), 40.0f, &N(D_80249A6C_A33CAC));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(D_80249A6C_A33CAC);
    if ((N(D_80249A70_A33CB0) == ((N(D_80249A70_A33CB0) / 5) * 5)) && (N(D_80249A6C_A33CAC) != 90.0f)) {
        f32 temp_f4 = resolve_npc(script, NPC_Bowser_Main)->pos.y - 150.0f;

        fx_fire_breath(
            1, script->varTable[0],
            script->varTable[1] + temp_f4,
            script->varTable[2],
            script->varTable[3] - 5,
            script->varTable[4] + temp_f4,
            script->varTable[5] - 30, 0, 5, 20
        );
    }

    N(D_80249A70_A33CB0)++;
    if (N(D_80249A70_A33CB0) <= 40) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(D_80249A74_A33CB4) = 90.0;
s32 N(D_80249A78_A33CB8) = 0;

API_CALLABLE(N(func_802421E0_A2C420)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 90.0f, 474.7f, N(D_80249A78_A33CB8), 20.0f, &N(D_80249A74_A33CB4));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(D_80249A74_A33CB4);
    N(D_80249A78_A33CB8)++;
    if (N(D_80249A78_A33CB8) < 21) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(D_80249A7C_A33CBC) = 0;

BSS f32 N(D_8024F2D0); // unused?
BSS f32 N(D_8024F2D4); // unused?
BSS f32 N(D_8024F2D8);
BSS f32 N(D_8024F2DC);

API_CALLABLE(N(func_802422A0_A2C4E0)) {
    Npc* npc7 = resolve_npc(script, NPC_Bowser_Main);
    Npc* npc8 = resolve_npc(script, NPC_Bowser_Prop);

    if (isInitialCall) {
        N(D_8024F2D8) = npc7->pos.x;
        N(D_8024F2DC) = npc7->pos.z;
    }
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(D_8024F2D8), 0.0f, N(D_80249A7C_A33CBC), 40.0f, &npc7->pos.x);
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(D_8024F2DC), 0.0f, N(D_80249A7C_A33CBC), 40.0f, &npc7->pos.z);
    npc8->pos.x = npc7->pos.x;
    npc8->pos.z = npc7->pos.z;
    npc7->colliderPos.x = npc7->pos.x;
    npc7->colliderPos.z = npc7->pos.z;
    npc8->colliderPos.x = npc8->pos.x;
    npc8->colliderPos.z = npc8->pos.z;

    N(D_80249A7C_A33CBC)++;
    if (N(D_80249A7C_A33CBC) <= 40) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(D_80249A80_A33CC0) = 0;

BSS f32 N(D_8024F2E0);
BSS f32 N(D_8024F2E4);
BSS f32 N(D_8024F2E8);
BSS f32 N(D_8024F2EC);
BSS f32 N(D_8024F2F0);

API_CALLABLE(N(func_802423D4_A2C614)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 35.0f, 35.0f, N(D_80249A80_A33CC0), 80.0f, &N(D_8024F2E0));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 130.0f, 270.0f, N(D_80249A80_A33CC0), 80.0f, &N(D_8024F2E4));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 30.0f, 0.0f, N(D_80249A80_A33CC0), 80.0f, &N(D_8024F2E8));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 232.0f, 177.0f, N(D_80249A80_A33CC0), 80.0f, &N(D_8024F2EC));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 0.0f, 0.0f, N(D_80249A80_A33CC0), 80.0f, &N(D_8024F2F0));
    N(adjust_cam_vfov)(CAM_DEFAULT, N(D_8024F2E0));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(D_8024F2E4);
    camera->movePos.x = N(D_8024F2E8);
    camera->movePos.y = N(D_8024F2EC);
    camera->movePos.z = N(D_8024F2F0);

    N(D_80249A80_A33CC0)++;
    if (N(D_80249A80_A33CC0) <= 90) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(D_80249A84_A33CC4) = 40.0;
f32 N(D_80249A88_A33CC8) = -40.0;
f32 N(D_80249A8C_A33CCC) = 45.0;
s32 N(D_80249A90_A33CD0) = 0;

API_CALLABLE(N(func_802425A0_A2C7E0)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_LINEAR, 40.0f, -130.0f, N(D_80249A90_A33CD0), 170.0f, &N(D_80249A84_A33CC4));
    N(interp_value_with_easing)(INTRO_MATH_EASING_LINEAR, -40.0f, 130.0f, N(D_80249A90_A33CD0), 170.0f, &N(D_80249A88_A33CC8));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 45.0f, 25.0f, N(D_80249A90_A33CD0), 170.0f, &N(D_80249A8C_A33CCC));
    camera->panActive = TRUE;
    camera->movePos.x = N(D_80249A84_A33CC4);
    camera->movePos.z = N(D_80249A88_A33CC8);
    camera->controlSettings.posB.x = sin_deg(N(D_80249A8C_A33CCC)) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(N(D_80249A8C_A33CCC)) * 500.0f;

    N(D_80249A90_A33CD0)++;
    if (N(D_80249A90_A33CD0) == 170) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

f32 N(D_80249A94_A33CD4) = 50.0;
f32 N(D_80249A98_A33CD8) = 246.1;
f32 N(D_80249A9C_A33CDC) = 200.0;
f32 N(D_80249AA0_A33CE0) = 25.0;
s32 N(D_80249AA4_A33CE4) = 0;

API_CALLABLE(N(func_80242704_A2C944)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 25.0f, 200.0f,
        N(D_80249AA4_A33CE4), 120.0f, &N(D_80249AA0_A33CE0));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 50.0f, 35.0f,
        N(D_80249AA4_A33CE4), 30.0f, &N(D_80249A94_A33CD4));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 246.1f, 180.0f,
        N(D_80249AA4_A33CE4), 30.0f, &N(D_80249A98_A33CD8));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 200.0f, 220.0f,
        N(D_80249AA4_A33CE4), 30.0f, &N(D_80249A9C_A33CDC));
    camera->controlSettings.posB.x = sin_deg(N(D_80249AA0_A33CE0)) * 500.0f;
    camera->controlSettings.posB.z = cos_deg(N(D_80249AA0_A33CE0)) * 500.0f;
    N(adjust_cam_vfov)(CAM_DEFAULT, N(D_80249A94_A33CD4));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(D_80249A98_A33CD8);
    camera->movePos.y = N(D_80249A9C_A33CDC);

    N(D_80249AA4_A33CE4)++;
    if (N(D_80249AA4_A33CE4) <= 120) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

// lotta work to do
#ifdef WIP
API_CALLABLE(func_802428C8_A2CB08) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s6 = evt_get_variable(script, *args++);
    f32 sp10 = evt_get_float_variable(script, *args++);
    f32 temp_f28 = evt_get_float_variable(script, *args++);
    EffectInstance* effect = evt_get_variable(script, ArrayVar(0));
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f20_2;
    f32 var_f26;
    f32 var_f2_2;
    f64 var_f20;
    f64 var_f2;
    f64 var_f2_3;
    f64 var_f2_4;
    f64 var_f2_5;
    f64 var_f2_6;
    f64 var_f2_7;
    f64 var_f2_8;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;

    f32* temp_s1_2;
    f32* temp_s2;
    f32* var_s0;
    f32* var_s2;

    switch (temp_s6) {
        case 1:
            var_s0 = N(D_8024F3F8);
            var_s2 = N(D_8024F3F8);
            temp_v0 = effect->data.somethingRotating->unk_14 + 30;
            var_f2 = temp_v0;
            if (temp_v0 < 0) {
                var_f2 += 4294967296.0;
            }
            var_f20 = var_f2 * 4.0f;
            temp_f20 = var_f20 + 51.43;
            temp_f24 = sin_deg(temp_f20);
            var_f26 = effect->data.somethingRotating->unk_04 + (sin_deg(90.0f) * 50.0f * temp_f24);
            var_f20_2 = effect->data.somethingRotating->unk_08 + (cos_deg(temp_f20) * 50.0f);
            var_f0_2 = sin_deg(90.0f) * 50.0f * temp_f24;
            var_f2_2 = effect->data.somethingRotating->unk_0C;
            break;
        case 2:
            var_s0 = N(D_8024F420);
            var_s2 = N(D_8024F420);
            temp_v0_2 = effect->data.somethingRotating->unk_14 + 30;
            var_f2_3 = temp_v0_2;
            if (temp_v0_2 < 0) {
                var_f2_3 += 4294967296.0;
            }
            var_f20 = (var_f2_3 * 4.0f);
            temp_f20 = var_f20 + 360.01;
            temp_f24 = sin_deg(temp_f20);
            var_f26 = effect->data.somethingRotating->unk_04 + (sin_deg(90.0f) * 50.0f * temp_f24);
            var_f20_2 = effect->data.somethingRotating->unk_08 + (cos_deg(temp_f20) * 50.0f);
            var_f0_2 = sin_deg(90.0f) * 50.0f * temp_f24;
            var_f2_2 = effect->data.somethingRotating->unk_0C;
            break;
        case 3:
            var_s0 = N(D_8024F448);
            var_s2 = N(D_8024F448);
            temp_v0_3 = effect->data.somethingRotating->unk_14 + 30;
            var_f2_4 = temp_v0_3;
            if (temp_v0_3 < 0) {
                var_f2_4 += 4294967296.0;
            }
            var_f20 = var_f2_4 * 4.0f;
            temp_f20 = var_f20 + 154.29;
            temp_f24 = sin_deg(temp_f20);
            var_f26 = effect->data.somethingRotating->unk_04 + (sin_deg(90.0f) * 50.0f * temp_f24);
            var_f20_2 = effect->data.somethingRotating->unk_08 + (cos_deg(temp_f20) * 50.0f);
            var_f0_2 = sin_deg(90.0f) * 50.0f * temp_f24;
            var_f2_2 = effect->data.somethingRotating->unk_0C;
            break;
        case 4:
            var_s0 = N(D_8024F470);
            temp_v0_4 = effect->data.somethingRotating->unk_14 + 30;
            var_f2_5 = temp_v0_4;
            var_s2 = N(D_8024F470);
            if (temp_v0_4 < 0) {
                var_f2_5 += 4294967296.0;
            }
            temp_f20_2 = (var_f2_5 * 4.0f) + 205.72;
            temp_f24_2 = sin_deg(temp_f20_2);
            var_f26 = effect->data.somethingRotating->unk_04 + (sin_deg(90.0f) * 50.0f * temp_f24_2);
            var_f20_2 = effect->data.somethingRotating->unk_08 + (cos_deg(temp_f20_2) * 50.0f);
            var_f0_2 = sin_deg(90.0f) * 50.0f * temp_f24_2;
            var_f2_2 = effect->data.somethingRotating->unk_0C;
            break;
        case 5:
            var_s0 = N(D_8024F498);
            var_s2 = N(D_8024F498);
            temp_v0_5 = effect->data.somethingRotating->unk_14 + 30;
            var_f2_6 = temp_v0_5;
            if (temp_v0_5 < 0) {
                var_f2_6 += 4294967296.0;
            }
            var_f20 = var_f2_6 * 4.0f;
            temp_f20 = var_f20 + 308.58;
            temp_f24 = sin_deg(temp_f20);
            var_f26 = effect->data.somethingRotating->unk_04 + (sin_deg(90.0f) * 50.0f * temp_f24);
            var_f20_2 = effect->data.somethingRotating->unk_08 + (cos_deg(temp_f20) * 50.0f);
            var_f0_2 = sin_deg(90.0f) * 50.0f * temp_f24;
            var_f2_2 = effect->data.somethingRotating->unk_0C;
            break;
        case 6:
            var_s0 = N(D_8024F4C0);
            var_s2 = N(D_8024F4C0);
            temp_v0_6 = effect->data.somethingRotating->unk_14 + 30;
            var_f2_7 = temp_v0_6;
            if (temp_v0_6 < 0) {
                var_f2_7 += 4294967296.0;
            }
            var_f20 = var_f2_7 * 4.0f;
            temp_f20 = var_f20 + 102.86;
            temp_f24 = sin_deg(temp_f20);
            var_f26 = effect->data.somethingRotating->unk_04 + (sin_deg(90.0f) * 50.0f * temp_f24);
            var_f20_2 = effect->data.somethingRotating->unk_08 + (cos_deg(temp_f20) * 50.0f);
            var_f0_2 = sin_deg(90.0f) * 50.0f * temp_f24;
            var_f2_2 = effect->data.somethingRotating->unk_0C;
            break;
        default:
            var_s0 = N(D_8024F4E8);
            var_s2 = N(D_8024F4E8);
            temp_v0_7 = effect->data.somethingRotating->unk_14 + 30;
            var_f2_8 = temp_v0_7;
            if (temp_v0_7 < 0) {
                var_f2_8 += 4294967296.0;
            }
            var_f20 = (var_f2_8 * 4.0f);
            temp_f20 = var_f20 + 257.15;
            temp_f24 = sin_deg(temp_f20);
            var_f26 = effect->data.somethingRotating->unk_04 + (sin_deg(90.0f) * 50.0f * temp_f24);
            var_f20_2 = effect->data.somethingRotating->unk_08 + (cos_deg(temp_f20) * 50.0f);
            var_f0_2 = sin_deg(90.0f) * 50.0f * temp_f24;
            var_f2_2 = effect->data.somethingRotating->unk_0C;
            break;
    }
    var_s0[6] = var_f26;
    var_s0[7] = var_f20_2;
    var_s0[8] = var_f2_2 + var_f0_2;
    var_s2[0] = evt_get_float_variable(script, LocalVar(0));
    var_s2[1] = evt_get_float_variable(script, LocalVar(1));
    temp_s1_2 = var_s2 + 0x18;
    var_s2[4] = evt_get_float_variable(script, LocalVar(2));
    temp_s2 = var_s2 + 0xC;
    if (temp_s6 != 2) {
        temp_f20_3 = 1.0f - temp_f28;
        temp_s2[0] =  (evt_get_float_variable(script, LocalVar(0)) * temp_f28) + (temp_s1_2[0] * temp_f20_3);
        temp_s2[1] = (evt_get_float_variable(script, LocalVar(1)) * temp_f28) + (temp_s1_2[1] * temp_f20_3) + sp10;
        var_f0_3 = (evt_get_float_variable(script, LocalVar(2)) * temp_f28) + (temp_s1_2[2] * temp_f20_3);
    } else {
        temp_f20_4 = 1.0f - temp_f28;
        temp_s2[0] = ((evt_get_float_variable(script, LocalVar(0)) * temp_f28) + (temp_s1_2[0] * temp_f20_4)) - 50.0f;
        temp_s2[1] = (evt_get_float_variable(script, LocalVar(1)) * temp_f28) + (temp_s1_2[1] * temp_f20_4) + sp10;
        var_f0_3 = ((evt_get_float_variable(script, LocalVar(2)) * temp_f28) + (temp_s1_2[2] * temp_f20_4)) - 50.0f;
    }
    temp_s2[2] = var_f0_3;
    script->varTable[0] = 30;
    script->varTable[1] = var_s0;
    script->varTable[2] = 3;
    return ApiStatus_DONE2;
}
#else
API_CALLABLE(func_802428C8_A2CB08);
INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802428C8_A2CB08);
#endif

EvtScript N(D_80249AA8_A33CE8) = {
    EVT_SET(LVar0, 120)
    EVT_SET(LVar1, 895)
    EVT_LOOP(10)
        EVT_ADD(LVar0, -12)
        EVT_ADD(LVar1, 10)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80249B48_A33D88) = {
    EVT_CALL(func_802D7B10, ArrayVar(6))
    EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        EVT_SET(ArrayVar(13), LVarF)
        EVT_CALL(func_802428C8_A2CB08, 6, 80, EVT_FLOAT(0.5))
        EVT_CALL(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_LABEL(6)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Klevar, LVar1, LVar2, LVar3)
        EVT_CALL(N(func_80240E50_A2B090), ArrayVar(13), ArrayVar(24), LVar1, LVar2, LVar3)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.03125))
        EVT_CALL(SetNpcScale, NPC_Klevar, LVar4, LVar4, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(6)
        EVT_END_IF
        EVT_CALL(N(func_80240F30_A2B170))
        EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
        EVT_CALL(func_802CFD30, 5, 0, 0, 0, 0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_2, TRUE)
        EVT_CALL(func_802D7B10, ArrayVar(13))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(func_802D7B10, ArrayVar(3))
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        EVT_SET(ArrayVar(10), LVarF)
        EVT_CALL(func_802428C8_A2CB08, 3, 30, EVT_FLOAT(0.5))
        EVT_CALL(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_LABEL(3)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Skolar, LVar1, LVar2, LVar3)
        EVT_CALL(N(func_80240E50_A2B090), ArrayVar(10), ArrayVar(21), LVar1, LVar2, LVar3)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.03125))
        EVT_CALL(SetNpcScale, NPC_Skolar, LVar4, LVar4, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_CALL(N(func_80240F30_A2B170))
        EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
        EVT_CALL(func_802CFD30, 2, 0, 0, 0, 0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_2, TRUE)
        EVT_CALL(func_802D7B10, ArrayVar(10))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(func_802D7B10, ArrayVar(4))
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        EVT_SET(ArrayVar(11), LVarF)
        EVT_CALL(func_802428C8_A2CB08, 4, -80, EVT_FLOAT(0.3))
        EVT_CALL(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_LABEL(4)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Muskular, LVar1, LVar2, LVar3)
        EVT_CALL(N(func_80240E50_A2B090), ArrayVar(11), ArrayVar(22), LVar1, LVar2, LVar3)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.03125))
        EVT_CALL(SetNpcScale, NPC_Muskular, LVar4, LVar4, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(4)
        EVT_END_IF
        EVT_CALL(N(func_80240F30_A2B170))
        EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
        EVT_CALL(func_802CFD30, 3, 0, 0, 0, 0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_2, TRUE)
        EVT_CALL(func_802D7B10, ArrayVar(11))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(func_802D7B10, ArrayVar(7))
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        EVT_SET(ArrayVar(14), LVarF)
        EVT_CALL(func_802428C8_A2CB08, 7, 120, EVT_FLOAT(0.5))
        EVT_CALL(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_LABEL(7)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kalmar, LVar1, LVar2, LVar3)
        EVT_CALL(N(func_80240E50_A2B090), ArrayVar(14), ArrayVar(25), LVar1, LVar2, LVar3)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.03125))
        EVT_CALL(SetNpcScale, NPC_Kalmar, LVar4, LVar4, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(7)
        EVT_END_IF
        EVT_CALL(N(func_80240F30_A2B170))
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Panic)
        EVT_CALL(func_802CFD30, 6, 0, 0, 0, 0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_2, TRUE)
        EVT_CALL(func_802D7B10, ArrayVar(14))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(func_802D7B10, ArrayVar(5))
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        EVT_SET(ArrayVar(12), LVarF)
        EVT_CALL(func_802428C8_A2CB08, 5, 120, EVT_FLOAT(0.5))
        EVT_CALL(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_LABEL(5)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
        EVT_CALL(N(func_80240E50_A2B090), ArrayVar(12), ArrayVar(23), LVar1, LVar2, LVar3)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.03125))
        EVT_CALL(SetNpcScale, NPC_Misstar, LVar4, LVar4, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_CALL(N(func_80240F30_A2B170))
        EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
        EVT_CALL(func_802CFD30, 4, 0, 0, 0, 0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_2, TRUE)
        EVT_CALL(func_802D7B10, ArrayVar(12))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(func_802D7B10, ArrayVar(2))
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        EVT_SET(ArrayVar(9), LVarF)
        EVT_CALL(func_802428C8_A2CB08, 2, -60, EVT_FLOAT(0.5))
        EVT_CALL(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_LABEL(2)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Mamar, LVar1, LVar2, LVar3)
        EVT_CALL(N(func_80240E50_A2B090), ArrayVar(9), ArrayVar(20), LVar1, LVar2, LVar3)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.03125))
        EVT_CALL(SetNpcScale, NPC_Mamar, LVar4, LVar4, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_CALL(N(func_80240F30_A2B170))
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Panic)
        EVT_CALL(func_802CFD30, 1, 0, 0, 0, 0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_2, TRUE)
        EVT_CALL(func_802D7B10, ArrayVar(9))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

f32 N(D_8024A9C8_A34C08) = 130.0;

API_CALLABLE(N(func_80242F74_A2D1B4)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(lerp_value_with_max_step)(N(IntroCamSettings15).boomLength, N(IntroCamSettings16).boomLength,
        N(D_8024A9C8_A34C08), 1.0f, &N(D_8024A9C8_A34C08));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(D_8024A9C8_A34C08);
    if (N(D_8024A9C8_A34C08) == 700.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

s32 N(D_8024A9CC_A34C0C) = 0;

BSS f32 N(D_8024F2F4);
BSS f32 N(D_8024F2F8);

API_CALLABLE(N(func_8024301C_A2D25C)) {
    Npc* npc = resolve_npc(script, NPC_Kammy);

    if (isInitialCall) {
        N(D_8024F2F4) = npc->pos.x;
        N(D_8024F2F8) = npc->pos.z;
    }

    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(D_8024F2F4), -95.0f, N(D_8024A9CC_A34C0C), 40.0f, &npc->pos.x);
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(D_8024F2F8), 20.0f, N(D_8024A9CC_A34C0C), 40.0f, &npc->pos.z);
    npc->colliderPos.x = npc->pos.x;
    npc->colliderPos.z = npc->pos.z;

    N(D_8024A9CC_A34C0C)++;
    if (N(D_8024A9CC_A34C0C) <= 40) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

BSS f32 N(D_8024F2FC);
BSS f32 N(D_8024F300);
BSS f32 N(D_8024F304);
BSS f32 N(D_8024F308);
BSS f32 N(D_8024F30C);
BSS f32 N(D_8024F310);
BSS char N(D_8024F314)[0x4];

BSS f32 N(StarSpiritsPosX)[7];
BSS char N(D_8024F334)[0x4];

BSS f32 N(StarSpiritsPosY)[7];
BSS char N(D_8024F354)[0x4];

BSS f32 N(StarSpiritsPosZ)[7];

BSS f32 N(AnimBowser_FlyOff_InitialY);
BSS f32 N(AnimKammy_FlyOff_InitialY);
BSS char N(D_8024F37C)[0x4];
BSS s32 N(D_8024F380);
BSS char N(D_8024F384)[0x74];
BSS s32 N(D_8024F3F8)[10];
BSS s32 N(D_8024F420)[10];
BSS s32 N(D_8024F448)[10];
BSS s32 N(D_8024F470)[10];
BSS s32 N(D_8024F498)[10];
BSS s32 N(D_8024F4C0)[10];
BSS s32 N(D_8024F4E8)[10];
BSS StoryGraphicData N(StoryGraphics);

void N(appendGfx_image_strips)(
    s32 baseX, s32 baseY,
    IMG_PTR img, PAL_PTR pal,
    s32 alpha, s32 width, s32 height, s32 lineHeight
);

s32 N(D_8024A9D0_A34C10)[] = {
    EVT_FLOAT(0.93),  EVT_FLOAT(0.9),   EVT_FLOAT(0.938), EVT_FLOAT(0.91),
    EVT_FLOAT(0.955), EVT_FLOAT(0.93),  EVT_FLOAT(0.968), EVT_FLOAT(0.95),
    EVT_FLOAT(0.979), EVT_FLOAT(0.97),  EVT_FLOAT(0.985), EVT_FLOAT(0.985), 
    EVT_FLOAT(0.995), EVT_FLOAT(0.995), EVT_FLOAT(0.998), EVT_FLOAT(0.998),
    EVT_FLOAT(0.999), EVT_FLOAT(0.999), EVT_FLOAT(1.0),   EVT_FLOAT(1.0),
};

StoryGraphicData* N(StoryGraphicsPtr) = &N(StoryGraphics);

Gfx N(gfx_setup_story_viewport)[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 29, 28, 291, 190),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_PATTERN),
    gsDPSetRenderMode(CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_PASS, CVG_DST_FULL | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

void N(draw_foreground_bowser_silhouette)(void) {
    s32 x = N(StoryGraphicsPtr)->silhouettePosX << 0x10;
    s32 y = N(StoryGraphicsPtr)->silhouettePosY << 0x10;

    if (N(StoryGraphicsPtr)->workerID != 0) {
        N(appendGfx_image_strips)(
            x >> 0x10, y >> 0x10,
            N(StoryGraphicsPtr)->imgBowser, N(StoryGraphicsPtr)->palBowser,
            255, 128, 128, 16
        );
    }
}

void N(appendGfx_image_strips)(s32 baseX, s32 baseY, IMG_PTR img, PAL_PTR pal, s32 alpha, s32 width, s32 height, s32 lineHeight) {
    u8 overlayType;
    f32 overlayAlphaBack;
    f32 overlayAlphaFront;
    s32 i;

    if (alpha == 0) {
        return;
    }

    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, N(gfx_setup_story_viewport));

    if (pal != NULL) {
        gDPLoadTLUT_pal256(gMasterGfxPos++, pal);
    } else {
        gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    }

    get_screen_overlay_params(1, &overlayType, &overlayAlphaBack);
    get_screen_overlay_params(0, &overlayType, &overlayAlphaFront);
    alpha = alpha * (255.0f - overlayAlphaBack) * (255.0f - overlayAlphaFront) / 255.0f / 255.0f;
    if (alpha != 255) {
        gDPSetCombineLERP(gMasterGfxPos++,
            0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0,
            0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
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

void N(draw_background_tape)(void) {
    N(appendGfx_image_strips)(
        N(StoryGraphicsPtr)->tapePosX, N(StoryGraphicsPtr)->tapePosY,
        N(StoryGraphicsPtr)->imgTape, NULL,
        N(StoryGraphicsPtr)->tapeAlpha, 128, 128, 32
    );
}

void N(appendGfx_image_ci)(s32 baseX, s32 baseY, IMG_PTR img, PAL_PTR pal) {
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

void N(worker_draw_story_graphics)(void) {
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 vpX = camera->viewportStartX;
    s32 vpY = camera->viewportStartY;
    u8 overlayType;
    f32 overlayAlpha;

    N(draw_background_tape)();

    gSPDisplayList(gMasterGfxPos++, N(gfx_setup_story_viewport));
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb_ptr);

    if (N(StoryGraphicsPtr)->unk_5A < 255) {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(StoryGraphicsPtr)->unk_5A);
    }
    get_screen_overlay_params(1, &overlayType, &overlayAlpha);
    if (overlayAlpha != 0.0f) {
        gDPSetCombineLERP(gMasterGfxPos++,
            PRIMITIVE, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, 1,
            PRIMITIVE, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, 1);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 208, 208, 208, (s32) overlayAlpha);
    }

    if (!N(StoryGraphicsPtr)->flipOrder) {
        N(appendGfx_image_ci)(
            vpX + N(StoryGraphicsPtr)->backImgPosX,
            vpY + N(StoryGraphicsPtr)->backImgPosY,
            N(StoryGraphicsPtr)->imgBack,
            N(StoryGraphicsPtr)->palBack
        );
        N(appendGfx_image_ci)(
            vpX + N(StoryGraphicsPtr)->frontImgPosX,
            vpY + N(StoryGraphicsPtr)->frontImgPosY,
            N(StoryGraphicsPtr)->imgFront,
            N(StoryGraphicsPtr)->palFront
        );
    } else {
        N(appendGfx_image_ci)(
            vpX + N(StoryGraphicsPtr)->frontImgPosX,
            vpY + N(StoryGraphicsPtr)->frontImgPosY,
            N(StoryGraphicsPtr)->imgFront,
            N(StoryGraphicsPtr)->palFront
        );
        N(appendGfx_image_ci)(
            vpX + N(StoryGraphicsPtr)->backImgPosX,
            vpY + N(StoryGraphicsPtr)->backImgPosY,
            N(StoryGraphicsPtr)->imgBack,
            N(StoryGraphicsPtr)->palBack
        );
    }
}

void N(load_story_image)(s32 loadBackImage, s32 imageIdx) {
    s32 i;

    imageIdx--;
    if (imageIdx < 0) {
        u16* pal = N(StoryGraphicsPtr)->palFront;

        // overwrite palette to fill entire frame with subtle off-white coloring
        for (i = 0; i < 256; i++) {
            *pal++ = GPACK_RGBA5551(212, 212, 212, 1);
        }
        return;
    }

    if (!loadBackImage) {
        dma_copy(
            title_bg_1_ROM_START + imageIdx * 0xA910,
            title_bg_1_ROM_START + (imageIdx + 1) * 0xA910,
            N(StoryGraphicsPtr)->imgFront
        );
    } else {
        dma_copy(
            title_bg_1_ROM_START + imageIdx * 0xA910,
            title_bg_1_ROM_START + (imageIdx + 1) * 0xA910,
            N(StoryGraphicsPtr)->imgBack
        );
    }
}

#ifdef SHIFT
#define TAPE_OFFSET title_tape_ROM_START - title_bg_1_ROM_START
#else
#define TAPE_OFFSET 0x2A440
#endif

API_CALLABLE(N(func_80243FC4_A2E204)) {
    u8* dmaEnd;
    u8* dmaStart;
    s32 tapeOffset;
    u8* it;

    N(StoryGraphicsPtr)->workerID = create_worker_frontUI(NULL, N(worker_draw_story_graphics));
    N(StoryGraphicsPtr)->imgFront = it = mdl_get_next_texture_address(0x1D420);
    it += 0xA710;
    N(StoryGraphicsPtr)->palFront = (u16*) it;
    it += 0x200;
    N(StoryGraphicsPtr)->imgBack = it;
    it += 0xA710;
    N(StoryGraphicsPtr)->palBack = (u16*) it;
    it += 0x200;
    N(StoryGraphicsPtr)->imgTape = it;
    it += 0x4000;
    N(StoryGraphicsPtr)->imgBowser = it;
    it += 0x4000;
    N(StoryGraphicsPtr)->palBowser = (u16*) it;
    N(StoryGraphicsPtr)->silhouettePosY = 240;
    N(StoryGraphicsPtr)->tapePosX = 111;
    N(StoryGraphicsPtr)->frontImgPosX = 0;
    N(StoryGraphicsPtr)->frontImgPosY = 0;
    N(StoryGraphicsPtr)->backImgPosX = 0;
    N(StoryGraphicsPtr)->backImgPosY = 0;
    N(StoryGraphicsPtr)->silhouettePosX = 0;
    N(StoryGraphicsPtr)->tapePosY = 54;

    N(load_story_image)(FALSE, 0); // force solid white
    N(load_story_image)(TRUE, 1);

    tapeOffset = TAPE_OFFSET;
    dmaStart = title_bg_1_ROM_START + tapeOffset;
    dmaEnd = title_bg_1_ROM_START + tapeOffset + 0x4000;

    // load the tape and bowser silhouette images
    dma_copy(dmaStart, dmaEnd + 0x4200, N(StoryGraphicsPtr)->imgTape);
    N(StoryGraphicsPtr)->flipOrder = 0;
    N(StoryGraphicsPtr)->unk_5A = 255;
    N(StoryGraphicsPtr)->tapeAlpha = 0;
    return ApiStatus_DONE2;
}

enum {
    STORY_PAGE_STATE_BEGIN          = 0,
    STORY_PAGE_STATE_WAIT           = 1,
    STORY_PAGE_STATE_NEXT           = 2,
    STORY_PAGE_STATE_BOWSER_BEGIN   = 3,
    STORY_PAGE_STATE_BOWSER_ANIM    = 4,
    STORY_PAGE_STATE_BOWSER_LEAP    = 5,
    STORY_PAGE_STATE_DONE           = 6,
};

s32 N(StoryPageState) = STORY_PAGE_STATE_BEGIN;
s32 N(CurrentStoryPageIdx) = 0;
s32 N(CurrentStoryPageTime)= 0;
u32 N(D_8024AABC_A34CFC) = 0;

s32 N(StoryPageDuration)[] = {
    222, 338, 338, 338, 622, 
};

s32 N(NextPageAnimOffsetsX)[] = {
    0, 0, 0, -1, -2, -3, -4, -9, -15, -22,
    -30, -39, -49, -60, -72, -85, -99, -114, -130, -147,
    -165, -184, -204, -225, -247, -270,
};

u8 N(D_8024AB3C_A34D7C)[] = {
    240, 240, 240, 240, 210, 197, 185, 174, 
    168, 170, 170, 170, 170, 170, 170, 167, 
    165, 164, 163, 162, 162, 161, 161, 162, 
    162, 163, 164, 165, 167, 170, 173, 175, 
    176, 176, 175, 172, 171, 170, 170, 167, 
    165, 164, 164, 165, 167, 170, 173, 175, 
    176, 176, 175, 173, 170, 167, 165, 164, 
    164, 165, 167, 170, 173, 175, 176, 176, 
    175, 173, 170, 167, 165, 164, 165, 164, 
    165, 164, 165, 164, 165, 164, 165, 164, 
    165, 164, 165, 164, 165, 164, 164, 165, 
    167, 170, 173, 175, 176, 176, 176, 176, 
    176, 176, 174, 170, 167, 165, 164, 164, 
    165, 167, 170, 170, 167, 165, 164, 164, 
    165, 167, 170, 170, 167, 165, 164, 164, 
    165, 167, 170, 170, 167, 165, 164, 164, 
    165, 167, 170, 170, 167, 165, 164, 164, 
    165, 167, 170, 170, 167, 165, 164, 164, 
    165, 167, 170, 170, 167, 165, 164, 165, 
    166, 167, 166, 165, 166, 167, 166, 165, 
    166, 167, 166, 165, 166, 167, 166, 167, 
    168, 169, 170, 170, 170, 170, 170, 170, 
    170, 170, 170, 170, 170, 170, 173, 175, 
    176, 176, 175, 173, 170, 167, 165, 164, 
    164, 165, 167, 170, 173, 175, 176, 176, 
    175, 173, 170, 167, 165, 164, 164, 165, 
    167, 170, 173, 174, 175, 174, 173, 170, 
    167, 165, 164, 164, 165, 167, 170, 173, 
    175, 176, 176, 175, 173, 170, 167, 165, 
    164, 164, 165, 167, 170, 173, 175, 176, 
    176, 175, 173, 170, 167, 165, 164, 164, 
    165, 167, 169, 170, 170, 170, 170, 170, 
    170, 170, 170, 170, 170, 170, 170, 167, 
    165, 164, 164, 165, 167, 170, 170, 167, 
    165, 164, 164, 165, 167, 170, 173, 175, 
    176, 176, 175, 173, 170, 167, 165, 164, 
    164, 165, 167, 170, 173, 175, 176, 176, 
    175, 173, 170, 167, 165, 164, 164, 165, 
    167, 170, 173, 175, 176, 176, 175, 173, 
    170, 167, 165, 164, 164, 165, 167, 170, 
};

u16 N(D_8024AC7C_A34EBC)[] = {
    100, 110, 121, 136, 155, 175, 195, 214, 232, 249, 265, 280, 294, 307,
    319, 0
};

u16 N(D_8024AC9C_A34EDC)[] = {
    3, 2,
    -6, -21, -40, -63, -90, -120, -160, -200,
    -240, -280,
    -320, 0
};

API_CALLABLE(N(func_802440D0_A2E310)) {
    switch (N(StoryPageState)) {
        case STORY_PAGE_STATE_BEGIN:
            N(StoryPageState)++;
            N(CurrentStoryPageTime) = N(StoryPageDuration)[N(CurrentStoryPageIdx)];
            break;
        case STORY_PAGE_STATE_WAIT:
            if (N(CurrentStoryPageTime) != 0) {
                N(CurrentStoryPageTime)--;
            } else {
                N(CurrentStoryPageTime) = ARRAY_COUNT(N(NextPageAnimOffsetsX));
                N(StoryPageState)++;
                sfx_play_sound(SOUND_B0);
            }
            break;
        case STORY_PAGE_STATE_NEXT:
            if (N(CurrentStoryPageTime) != 0) {
                N(CurrentStoryPageTime)--;
                if (!N(StoryGraphicsPtr)->flipOrder) {
                    N(StoryGraphicsPtr)->frontImgPosX = N(NextPageAnimOffsetsX)[25 - N(CurrentStoryPageTime)];
                    N(StoryGraphicsPtr)->frontImgPosY = 0;
                } else {
                    N(StoryGraphicsPtr)->backImgPosX = N(NextPageAnimOffsetsX)[25 - N(CurrentStoryPageTime)];
                    N(StoryGraphicsPtr)->backImgPosY = 0;
                }
            } else {
                N(CurrentStoryPageIdx)++;
                if (N(CurrentStoryPageIdx) + 1 < 5) {
                    N(load_story_image)(N(StoryGraphicsPtr)->flipOrder, N(CurrentStoryPageIdx) + 1);
                    N(StoryPageState) = STORY_PAGE_STATE_BEGIN;
                    N(StoryGraphicsPtr)->frontImgPosX = 0;
                    N(StoryGraphicsPtr)->frontImgPosY = 0;
                    N(StoryGraphicsPtr)->backImgPosX = 0;
                    N(StoryGraphicsPtr)->backImgPosY = 0;
                    N(StoryGraphicsPtr)->flipOrder = N(StoryGraphicsPtr)->flipOrder ^ 1;
                } else {
                    if (!N(StoryGraphicsPtr)->flipOrder) {
                        N(StoryGraphicsPtr)->backImgPosX = 0;
                        N(StoryGraphicsPtr)->backImgPosY = 0;
                    } else {
                        N(StoryGraphicsPtr)->frontImgPosX = 0;
                        N(StoryGraphicsPtr)->frontImgPosY = 0;
                    }
                    gCameras[CAM_DEFAULT].flags &= ~CAMERA_FLAG_ENABLED;
                    N(StoryPageState)++;
                }
            }
            break;
        case STORY_PAGE_STATE_BOWSER_BEGIN:
            N(D_8024AABC_A34CFC) = 0;
            N(StoryPageState)++;
            N(CurrentStoryPageTime) = N(StoryPageDuration)[N(CurrentStoryPageIdx)];
            break;
        case STORY_PAGE_STATE_BOWSER_ANIM:
            if (N(CurrentStoryPageTime) != 0) {
                if (N(CurrentStoryPageTime) < N(StoryPageDuration)[N(CurrentStoryPageIdx)] - 268) {
                    u32 temp_v1 = N(D_8024AABC_A34CFC) - 320;

                    if (N(D_8024AABC_A34CFC) < 320) {
                        N(StoryGraphicsPtr)->silhouettePosX = N(D_8024AC7C_A34EBC)[0];
                        N(StoryGraphicsPtr)->silhouettePosY = N(D_8024AB3C_A34D7C)[N(D_8024AABC_A34CFC)];
                    } else if (temp_v1 < 15) {
                        N(StoryGraphicsPtr)->silhouettePosX = N(D_8024AC7C_A34EBC)[temp_v1];
                        if (temp_v1 < 13) {
                            N(StoryGraphicsPtr)->silhouettePosY = N(D_8024AB3C_A34D7C)[319] + N(D_8024AC9C_A34EDC)[temp_v1];
                        }
                    }
                    N(D_8024AABC_A34CFC)++;
                }
                N(CurrentStoryPageTime)--;
            } else {
                N(CurrentStoryPageTime) = 26;
                N(StoryPageState)++;
                N(StoryGraphicsPtr)->tapeAlpha = 255;
                sfx_play_sound(SOUND_B0);
            }
            break;
        case STORY_PAGE_STATE_BOWSER_LEAP:
            if (N(CurrentStoryPageTime) != 0) {
                N(CurrentStoryPageTime)--;
                if (!N(StoryGraphicsPtr)->flipOrder) {
                    N(StoryGraphicsPtr)->backImgPosX = N(NextPageAnimOffsetsX)[25 - N(CurrentStoryPageTime)];
                    N(StoryGraphicsPtr)->backImgPosY = 0;
                } else {
                    N(StoryGraphicsPtr)->frontImgPosX = N(NextPageAnimOffsetsX)[25 - N(CurrentStoryPageTime)];
                    N(StoryGraphicsPtr)->frontImgPosY = 0;
                }
            } else {
                N(StoryPageState)++;
            }
            break;
        case STORY_PAGE_STATE_DONE:
        default:
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

s32 N(D_8024ACB8_A34EF8) = 30;

s32 N(D_8024ACBC_A34EFC) = 0x00010019;

API_CALLABLE(N(func_80244454_A2E694)) {
    if (N(D_8024ACB8_A34EF8) != 0) {
        N(D_8024ACB8_A34EF8)--;
        N(StoryGraphicsPtr)->tapeAlpha = (N(D_8024ACB8_A34EF8) * 255) / 30;
        return ApiStatus_BLOCK;
    } else {
        N(StoryGraphicsPtr)->tapeAlpha = 0;
        free_worker(N(StoryGraphicsPtr)->workerID);
        N(StoryGraphicsPtr)->workerID = 0;
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(ForceStarRodAlwaysFaceCamera)) {
    Npc* npc = resolve_npc(script, NPC_StarRod);

    npc->yaw = npc->renderYaw = 180.0f - gCameras[gCurrentCameraID].currentYaw;
    return ApiStatus_BLOCK;
}

#ifdef NON_MATCHING
API_CALLABLE(func_80244550_A2E790) {
    Npc* kammy = resolve_npc(script, NPC_Kammy);
    EffectInstance* effect = evt_get_variable(script, ArrayVar(0));
    f32 x, y, z;
    s32 i;

    if (isInitialCall) {
        N(D_8024F2FC) = kammy->pos.x;
        N(D_8024F300) = kammy->pos.y;
        N(D_8024F304) = kammy->pos.z;

        for (i = NPC_Eldstar; i < ARRAY_COUNT(N(StarSpiritsPosX)); i++) {
            Npc* npc2 = resolve_npc(script, i);

            N(StarSpiritsPosX)[i] = npc2->pos.x;
            N(StarSpiritsPosY)[i] = npc2->pos.y;
            N(StarSpiritsPosZ)[i] = npc2->pos.z;
        }
        N(D_8024F308) = effect->data.somethingRotating->unk_04;
        N(D_8024F30C) = effect->data.somethingRotating->unk_08;
        N(D_8024F310) = effect->data.somethingRotating->unk_0C;
    }

    x = kammy->pos.x - N(D_8024F2FC);
    y = kammy->pos.y - N(D_8024F300);
    z = kammy->pos.z - N(D_8024F304);

    for (i = 0; i < ARRAY_COUNT(N(StarSpiritsPosX)); i++) {
        Npc* npc2 = resolve_npc(script, i);

        npc2->pos.x = N(StarSpiritsPosX)[i] + x;
        npc2->pos.y = N(StarSpiritsPosY)[i] + y;
        npc2->pos.z = N(StarSpiritsPosZ)[i] + z;
        npc2->colliderPos.x = npc2->pos.x;
        npc2->colliderPos.y = npc2->pos.y;
        npc2->colliderPos.z = npc2->pos.z;
    }
    effect->data.somethingRotating->unk_04 = N(D_8024F308) + x;
    effect->data.somethingRotating->unk_08 = N(D_8024F30C) + y;
    effect->data.somethingRotating->unk_0C = N(D_8024F310) + z;
    return ApiStatus_BLOCK;
}
#else
API_CALLABLE(func_80244550_A2E790);
INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80244550_A2E790);
#endif

extern EvtScript N(EVS_Scene_IntroStory);

EvtScript N(EVS_Intro_Main) = {
    EVT_USE_ARRAY(EVT_PTR(N(D_8024F380)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
    EVT_CALL(N(InitWorldFogMode))
    EVT_CALL(N(SetWorldColorParams), 255, 255, 255, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(N(AdjustCamVfov), 0, 62)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 157, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings1)))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(N(func_80243FC4_A2E204))
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(SetCamEnabled, CAM_DEFAULT, FALSE)
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_o33, FALSE)
    EVT_CALL(EnableTexPanning, MODEL_o34, FALSE)
    EVT_CALL(EnableGroup, MODEL_g271, FALSE)
    EVT_CALL(EnableGroup, MODEL_g272, FALSE)
    EVT_CALL(EnableGroup, MODEL_g273, FALSE)
    EVT_CALL(N(func_80241274_A2B4B4))
    EVT_CALL(EnableGroup, MODEL_g277, FALSE)
    EVT_CALL(EnableModel, MODEL_o8, FALSE)
    EVT_EXEC(N(EVS_Scene_IntroStory))
    EVT_RETURN
    EVT_END
};

f32 N(AnimBowser_FlyOff_Time) = 0.0;

API_CALLABLE(N(AnimBowser_FlyOff)) {
    Npc* bowserMain = resolve_npc(script, NPC_Bowser_Main);
    Npc* bowserProp = resolve_npc(script, NPC_Bowser_Prop);

    if (isInitialCall) {
        N(AnimBowser_FlyOff_InitialY) = bowserMain->pos.y;
    }
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT,
        N(AnimBowser_FlyOff_InitialY),
        N(AnimBowser_FlyOff_InitialY) + 500.0f,
        N(AnimBowser_FlyOff_Time),
        40.0f, &bowserMain->pos.y);
    bowserProp->pos.y = bowserMain->pos.y;
    bowserMain->colliderPos.y = bowserMain->pos.y;
    bowserProp->colliderPos.y = bowserProp->pos.y;
    N(AnimBowser_FlyOff_Time)++;
    if (N(AnimBowser_FlyOff_Time) > 40.0f) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

f32 N(AnimKammy_FlyOff_Time) = 0.0;

API_CALLABLE(N(AnimKammy_FlyOff)) {
    Npc* kammy = resolve_npc(script, NPC_Kammy);

    if (isInitialCall) {
        N(AnimKammy_FlyOff_InitialY) = kammy->pos.y;
    }
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT,
        N(AnimKammy_FlyOff_InitialY),
        N(AnimKammy_FlyOff_InitialY) + 500.0f,
        N(AnimKammy_FlyOff_Time),
        40.0f, &kammy->pos.y);
    kammy->colliderPos.y = kammy->pos.y;
    N(AnimKammy_FlyOff_Time)++;
    if (N(AnimKammy_FlyOff_Time) > 40.0f) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80244934_A2EB74)) {
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

EvtScript N(EVS_Scene_IntroStory) = {
    EVT_CALL(SetNpcPaletteSwapMode, NPC_StarRod, 2)
    EVT_CALL(SetNpcPaletteSwapLower, NPC_StarRod, 0, 1, 20, 5)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Eldstar, 2)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Mamar, 2)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Skolar, 2)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Muskular, 2)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Misstar, 2)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Klevar, 2)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Kalmar, 2)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Eldstar, 0, 1, 25, 12, 4, 18, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Mamar, 0, 1, 25, 12, 4, 18, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Skolar, 0, 1, 25, 12, 4, 18, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Muskular, 0, 1, 25, 12, 4, 18, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Misstar, 0, 1, 25, 12, 4, 18, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Klevar, 0, 1, 25, 12, 4, 18, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Kalmar, 0, 1, 25, 12, 4, 18, 0, 0)
    EVT_CALL(SetNpcFlagBits, NPC_StarRod, NPC_FLAG_40000, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarStill)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Prop, ANIM_WorldBowser_ClownCarPropeller)
    EVT_CALL(EnableNpcShadow, NPC_Bowser_Main, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Bowser_Prop, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_StarRod, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Eldstar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Mamar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Skolar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Muskular, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Misstar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Klevar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Kalmar, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Kammy, FALSE)
    EVT_THREAD
        EVT_CALL(N(ForceStarRodAlwaysFaceCamera))
    EVT_END_THREAD
    EVT_CALL(InterpNpcYaw, NPC_Bowser_Main, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_Bowser_Prop, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarTalk)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Prop, ANIM_WorldBowser_ClownCarPropeller)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim17)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 45, 0)
    EVT_CALL(SetNpcPos, NPC_Kammy, -145, 147, 84)
    EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Still)
    EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
    EVT_CALL(N(SetWorldColorParams), 130, 130, 130, 0, 0, 0, 15)
    EVT_CALL(N(AdjustCamVfov), 0, 35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -145, 147, 84)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings6)))
    EVT_CALL(N(func_802440D0_A2E310))
    EVT_WAIT(50)
    EVT_CALL(func_802CFD30, NPC_Bowser_Main, FOLD_TYPE_8, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, NPC_Bowser_Prop, FOLD_TYPE_8, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Bowser_Main, -64, 135, 85)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, -64, 135, 85)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(50)
            EVT_ADD(LVar0, 6)
            EVT_IF_GT(LVar0, 255)
                EVT_SET(LVar0, 255)
            EVT_END_IF
            EVT_CALL(func_802CFD30, NPC_Bowser_Main, FOLD_TYPE_8, 0, 0, 0, LVar0)
            EVT_CALL(func_802CFD30, NPC_Bowser_Prop, FOLD_TYPE_8, 0, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Bowser_Prop, 90, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(40)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetNpcRotation, NPC_Bowser_Main, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_Bowser_Main, 0, 0, 0)
        EVT_CALL(InterpNpcYaw, NPC_Bowser_Main, 90, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 0, 0, 0, 15)
    EVT_END_THREAD
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING, 1, 0, 20, 0, 0, 0)
    EVT_SET(ArrayVar(17), LVarF)
    EVT_THREAD
        EVT_CALL(N(func_80244454_A2E694))
    EVT_END_THREAD
    EVT_WAIT(16)
    EVT_THREAD
        EVT_CALL(N(func_80244934_A2EB74))
    EVT_END_THREAD
    EVT_LOOP(2)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 165, 96, 152, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 975, 1000)
        EVT_WAIT(1)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 64, 34, 58, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 995, 1000)
        EVT_WAIT(1)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 0, 0, 0, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(func_802CFD30, NPC_Bowser_Main, FOLD_TYPE_8, 0, 0, 0, 255)
    EVT_CALL(func_802CFD30, NPC_Bowser_Prop, FOLD_TYPE_8, 0, 0, 0, 255)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(4)
            EVT_ADD(LVar0, 70)
            EVT_IF_GT(LVar0, 255)
                EVT_SET(LVar0, 255)
            EVT_END_IF
            EVT_CALL(func_802CFD30, NPC_Bowser_Main, FOLD_TYPE_8, LVar0, LVar0, LVar0, 255)
            EVT_CALL(func_802CFD30, NPC_Bowser_Prop, FOLD_TYPE_8, LVar0, LVar0, LVar0, 255)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(func_802D7B10, ArrayVar(17))
    EVT_THREAD
        EVT_CALL(EnableTexPanning, MODEL_o33, TRUE)
        EVT_CALL(EnableTexPanning, MODEL_o34, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Hurt)
        EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Hurt)
        EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
        EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
        EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
        EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
        EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Panic)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
        EVT_PLAY_EFFECT(EFFECT_ENDING_DECALS, 2, 0, 180, 0, EVT_FLOAT(2.59375), ArrayVar(15))
        EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 1, 0, 200, 0, EVT_FLOAT(1.0), ArrayVar(16))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_80241B40_A2BD80))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(func_80241F54_A2C194))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(N(AdjustCamVfov), 0, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 157, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings7)))
    EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Hurt)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(10)
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(34)
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetNpcRotation, NPC_Misstar, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(16)
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(28)
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 36)
            EVT_CALL(SetNpcRotation, NPC_Kalmar, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING, 2, 0, 0, 0, 0, 0)
    EVT_SET(ArrayVar(17), LVarF)
    EVT_SET(LVar0, 120)
    EVT_SET(LVar1, 895)
    EVT_LOOP(10)
        EVT_ADD(LVar0, -12)
        EVT_ADD(LVar1, 10)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(2)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 165, 96, 152, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 975, 1000)
        EVT_WAIT(1)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 105, 60, 102, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 975, 1000)
        EVT_WAIT(1)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 64, 34, 58, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 995, 1000)
        EVT_WAIT(1)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 34, 14, 28, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 995, 1000)
        EVT_WAIT(1)
        EVT_CALL(N(SetWorldColorParams), 117, 28, 42, 0, 0, 0, 0)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_WAIT(27)
    EVT_CALL(func_802D7B10, ArrayVar(17))
    EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
    EVT_CALL(N(AdjustCamVfov), 0, 25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -38, 210, 85)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings8)))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarCloseMouth)
    EVT_CALL(SetNpcPos, NPC_Bowser_Main, -30, 150, 162)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, -30, 150, 162)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim11)
    EVT_THREAD
        EVT_CALL(N(SetWorldColorParams), 23, 10, 10, 0, 0, 0, 15)
        EVT_WAIT(28)
        EVT_CALL(N(SetWorldColorParams), 102, 45, 0, 114, 0, 0, 3)
        EVT_CALL(N(SetWorldColorParams), 102, 45, 0, 0, 0, 0, 13)
        EVT_CALL(N(SetWorldColorParams), 180, 180, 180, 0, 0, 0, 20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 995)
        EVT_LOOP(30)
            EVT_SUB(LVar0, 10)
            EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, LVar0, 1000)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(10)
        EVT_SET(LVar0, 875)
        EVT_LOOP(60)
            EVT_ADD(LVar0, 2)
            EVT_CALL(N(SetWorldFogParams), 0, 0, 0, 0, 255, 0, 0, LVar0, 1000)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(LVar0, -28)
    EVT_SET(LVar1, 210)
    EVT_SET(LVar2, 155)
    EVT_SET(LVar3, -28)
    EVT_SET(LVar4, 209)
    EVT_SET(LVar5, 153)
    EVT_CALL(N(func_80242024_A2C264))
    EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 0, -30, 210, 142, 0, 180, 0, 5, 2, 30)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarFireBreath)
    EVT_THREAD
        EVT_CALL(N(func_802421E0_A2C420))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 0, 0, 180, 0, EVT_FLOAT(0.703125), 30)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(RemoveEffect, ArrayVar(15))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(N(AdjustCamVfov), 0, 25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -38, 210, 85)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings9)))
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarOpenMouth)
    EVT_THREAD
        EVT_CALL(N(func_802422A0_A2C4E0))
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_CALL(N(AdjustCamVfov), 0, 35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -240, 200, 113)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings10)))
    EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
    EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_USE_BUF(EVT_PTR(N(D_8024A9D0_A34C10)))
        EVT_LOOP(10)
            EVT_FBUF_READ2(LVarA, LVarB)
            EVT_SETF(LVar3, LVar0)
            EVT_SETF(LVar4, LVar1)
            EVT_SETF(LVar5, LVar2)
            EVT_MULF(LVar3, LVarB)
            EVT_MULF(LVar4, LVarA)
            EVT_MULF(LVar5, LVarB)
            EVT_CALL(SetNpcPos, NPC_Skolar, LVar3, LVar4, LVar5)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(9)
        EVT_USE_BUF(EVT_PTR(N(D_8024A9D0_A34C10)))
        EVT_LOOP(10)
            EVT_FBUF_READ2(LVarA, LVarB)
            EVT_SETF(LVar3, LVar0)
            EVT_SETF(LVar4, LVar1)
            EVT_SETF(LVar5, LVar2)
            EVT_MULF(LVar3, LVarB)
            EVT_MULF(LVar4, LVarA)
            EVT_MULF(LVar5, LVarB)
            EVT_CALL(SetNpcPos, NPC_Misstar, LVar3, LVar4, LVar5)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_MULF(LVar0, EVT_FLOAT(0.9))
    EVT_MULF(LVar1, EVT_FLOAT(0.93))
    EVT_MULF(LVar2, EVT_FLOAT(0.9))
    EVT_CALL(SetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_MULF(LVar0, EVT_FLOAT(0.9))
    EVT_MULF(LVar1, EVT_FLOAT(0.93))
    EVT_MULF(LVar2, EVT_FLOAT(0.9))
    EVT_CALL(SetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_WAIT(35)
    EVT_CALL(N(AdjustCamVfov), 0, 35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 30, 232, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings11)))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarBrandish)
    EVT_CALL(SetNpcPos, NPC_Bowser_Main, 0, 170, 0)
    EVT_CALL(SetNpcPos, NPC_Bowser_Prop, 0, 170, 0)
    EVT_CALL(SetNpcPos, NPC_StarRod, NPC_DISPOSE_LOCATION)
    EVT_THREAD
        EVT_CALL(N(SetWorldColorParams), 20, 20, 20, 0, 0, 0, 15)
    EVT_END_THREAD
    EVT_SET(LVar0, 21)
    EVT_SET(LVar1, 260)
    EVT_SET(LVar2, -21)
    EVT_CALL(N(func_80240FE0_A2B220))
    EVT_WAIT(35)
    EVT_THREAD
        EVT_WAIT(70)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 12)
            EVT_CALL(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 0, 0, 995, 1000)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(92)
        EVT_CALL(N(SetWorldColorParams), 106, 94, 110, 216, 195, 131, 8)
        EVT_CALL(N(SetWorldColorParams), 100, 105, 107, 159, 118, 50, 20)
        EVT_CALL(N(SetWorldColorParams), 122, 180, 110, 0, 0, 0, 15)
        EVT_CALL(N(SetWorldColorParams), 128, 128, 128, 255, 255, 200, 60)
    EVT_END_THREAD
    EVT_CALL(N(func_802423D4_A2C614))
    EVT_CALL(N(AdjustCamVfov), 0, 35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 177, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings12)))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarStarRod)
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, 20, 265, -21, EVT_FLOAT(1.0), ArrayVar(18))
    EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, 20, 265, -21, EVT_FLOAT(1.0), ArrayVar(19))
    EVT_SET(LVar0, 120)
    EVT_SET(LVar1, 895)
    EVT_LOOP(20)
        EVT_ADD(LVar0, -6)
        EVT_ADD(LVar1, 5)
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(5)
    EVT_CALL(N(AdjustCamVfov), 0, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 157, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings7)))
    EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
    EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Panic)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(func_802D7B10, ArrayVar(18))
        EVT_CALL(func_802D7B10, ArrayVar(19))
    EVT_END_THREAD
    EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, 18, 256, -21, EVT_FLOAT(0.40625), 60)
    EVT_SET(LVar0, 120)
    EVT_SETF(LVar1, 895)
    EVT_LOOP(40)
        EVT_ADD(LVar0, -3)
        EVT_ADDF(LVar1, EVT_FLOAT(2.5))
        EVT_CALL(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(AdjustCamVfov), 0, 35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 70, 200, -239)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings5)))
    EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Hurt)
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_AURA, 0, LVar0, LVar1, LVar2, 1, ArrayVar(1))
    EVT_CALL(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_AURA, 0, LVar0, LVar1, LVar2, 1, ArrayVar(2))
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_AURA, 0, LVar0, LVar1, LVar2, 1, ArrayVar(3))
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_AURA, 0, LVar0, LVar1, LVar2, 1, ArrayVar(4))
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_AURA, 0, LVar0, LVar1, LVar2, 1, ArrayVar(5))
    EVT_CALL(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_AURA, 0, LVar0, LVar1, LVar2, 1, ArrayVar(6))
    EVT_CALL(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_AURA, 0, LVar0, LVar1, LVar2, 1, ArrayVar(7))
    EVT_CALL(N(SetWorldColorParams), 110, 110, 110, 255, 255, 255, 0)
    EVT_THREAD
        EVT_CALL(N(SetWorldColorParams), 230, 230, 230, 0, 0, 0, 30)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(28)
        EVT_CALL(func_802CFD30, NPC_Eldstar, FOLD_TYPE_5, 8, 1, 1, 0)
    EVT_END_THREAD
    EVT_SET(LVar0, 255)
    EVT_LOOP(20)
        EVT_CALL(func_802CFD30, NPC_Mamar,    FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Skolar,   FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Muskular, FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Misstar,  FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Klevar,   FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_CALL(func_802CFD30, NPC_Kalmar,   FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(15)
    EVT_CALL(func_802CFD30, NPC_Eldstar, FOLD_TYPE_7, 255, 0, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_SOMETHING_ROTATING, 2, -130, 220, 130, 1, 0)
    EVT_SET(ArrayVar(0), LVarF)
    EVT_SET(LVar0, -130)
    EVT_SET(LVar1, 220)
    EVT_SET(LVar2, 130)
    EVT_ADDF(LVar1, EVT_FLOAT(-30.0))
    EVT_CALL(SetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_EXEC(N(D_80249AA8_A33CE8))
    EVT_CALL(func_802D7B10, ArrayVar(1))
    EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        EVT_SET(ArrayVar(8), LVarF)
        EVT_CALL(func_802428C8_A2CB08, 1, 30, EVT_FLOAT(0.5))
        EVT_CALL(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_LABEL(1)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Eldstar, LVar1, LVar2, LVar3)
        EVT_CALL(N(func_80240E50_A2B090), ArrayVar(8), ArrayVar(19), LVar1, LVar2, LVar3)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.03125))
        EVT_CALL(SetNpcScale, NPC_Eldstar, LVar4, LVar4, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(N(func_80240F30_A2B170))
        EVT_CALL(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Panic)
        EVT_CALL(func_802CFD30, 0, 0, 0, 0, 0, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_2, TRUE)
        EVT_CALL(func_802D7B10, ArrayVar(8))
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(N(AdjustCamVfov), 0, 50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 40, 200, -40)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings13)))
    EVT_CALL(RemoveEffect, ArrayVar(16))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarIdle)
    EVT_THREAD
        EVT_WAIT(45)
        EVT_CALL(NpcFaceNpc, NPC_Bowser_Main, NPC_Eldstar, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim12)
    EVT_EXEC(N(D_80249B48_A33D88))
    EVT_CALL(N(func_802425A0_A2C7E0))
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim09)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim12)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0D)
        EVT_WAIT(40)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim09)
    EVT_END_THREAD
    EVT_CALL(N(func_80242704_A2C944))
    EVT_CALL(N(AdjustCamVfov), 0, 50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 200, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(IntroCamSettings15)))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarLaugh)
    EVT_THREAD
        EVT_CALL(N(func_80242F74_A2D1B4))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(func_80244550_A2E790)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0B)
    EVT_CALL(N(func_8024301C_A2D25C))
    EVT_THREAD
        EVT_CALL(N(func_80240F88_A2B1C8))
        EVT_CALL(N(func_80240F88_A2B1C8))
        EVT_CALL(N(func_80240F88_A2B1C8))
        EVT_CALL(N(func_80240F88_A2B1C8))
        EVT_CALL(N(func_80240F88_A2B1C8))
        EVT_CALL(N(func_80240F88_A2B1C8))
        EVT_CALL(N(func_80240F88_A2B1C8))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0D)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim11)
    EVT_WAIT(32)
    EVT_CALL(SetNpcJumpscale, NPC_Eldstar, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_Mamar, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_Skolar, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_Muskular, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_Misstar, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_Klevar, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcJumpscale, NPC_Kalmar, EVT_FLOAT(0.0))
    EVT_CALL(SetNpcAnimation, NPC_Bowser_Main, ANIM_WorldBowser_ClownCarStill)
    EVT_THREAD
        EVT_CALL(N(AnimBowser_FlyOff))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(N(AnimKammy_FlyOff))
    EVT_WAIT(20)
    EVT_CALL(N(ResumeIntro))
    EVT_RETURN
    EVT_END
};
