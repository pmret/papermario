#include "hos_05.h"
#include "effects.h"
#include "model.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

enum {
    STORY_PAGE_BLANK        = 0,
    STORY_PAGE_STARRY_SKY   = 1,
    STORY_PAGE_SHRINE_EXT   = 2,
    STORY_PAGE_STAR_ROD     = 3,
    STORY_PAGE_SHRINE_INT   = 4,
};

typedef struct StoryGraphicData {
    /* 0x00 */ s32 workerID;
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
    /* 0x44 */ u16 silhouettePosX;
    /* 0x46 */ u16 silhouettePosY;
    /* 0x48 */ s16 tapePosX;
    /* 0x4A */ s16 tapePosY;
    /* 0x4C */ char unk_4C[0xC];
    /* 0x58 */ s16 flipOrder;
    /* 0x5A */ s16 storyPageAlpha;
    /* 0x5C */ s16 tapeAlpha;
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
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 130.4,
    .boomPitch = 12.4,
    .points = { .two = {  0.0, -1.0, 0.0, 0.0, -1.0, -500.0 }},
    .viewPitch = -16.8,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings1) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 130.4,
    .boomPitch = 12.4,
    .points = { .two = {  0.0, -1.0, 0.0, -433.0127, -1.0, -250.0 }},
    .viewPitch = -16.8,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings2) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 400.0,
    .boomPitch = 2.7,
    .points = { .two = {  0.0, -1.0, 0.0, 0.0, -1.0, -500.0 }},
    .viewPitch = -7.4,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings3) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 274.4,
    .boomPitch = -9.3,
    .points = { .two = {  0.0, -1.0, 0.0, 114.3, -1.0, 500.0 }},
    .viewPitch = 0.7,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings4) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 274.4,
    .boomPitch = -9.3,
    .points = { .two = {  0.0, -1.0, 0.0, 114.3, -1.0, 500.0 }},
    .viewPitch = 0.7,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings5) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 243.3,
    .boomPitch = 16.0,
    .points = { .two = {  0.0, -1.0, 0.0, 56.1, -1.0, -1.1 }},
    .viewPitch = -3.0,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings6) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 192.5,
    .boomPitch = 12.4,
    .points = { .two = {  0.0, -1.0, 0.0, 0.0, -1.0, 500.0 }},
    .viewPitch = -10.7,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings7) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 467.0,
    .boomPitch = 21.0,
    .points = { .two = {  0.0, -1.0, 0.0, 71.3, -1.0, 154.3 }},
    .viewPitch = -3.0,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings8) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 121.6,
    .boomPitch = 0.0,
    .points = { .two = {  0.0, -1.0, 0.0, 24.4, -1.0, 154.3 }},
    .viewPitch = 0.0,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings9) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 474.7,
    .boomPitch = 0.0,
    .points = { .two = {  0.0, -1.0, 0.0, 24.4, -1.0, 154.3 }},
    .viewPitch = 0.0,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings10) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 225.7,
    .boomPitch = 9.7,
    .points = { .two = {  0.0, -1.0, 0.0, 6.9, -1.0, 168.8 }},
    .viewPitch = -3.0,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings11) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 130.0,
    .boomPitch = 9.8,
    .points = { .two = {  0.0, -1.0, 0.0, 40.0, -1.0, 168.8 }},
    .viewPitch = -9.3,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings12) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 270.0,
    .boomPitch = 9.8,
    .points = { .two = {  0.0, -1.0, 0.0, 40.0, -1.0, 168.8 }},
    .viewPitch = -9.3,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings13) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 246.1,
    .boomPitch = -1.3,
    .points = { .two = {  0.0, -1.0, 0.0, 500.0, -1.0, 500.0 }},
    .viewPitch = 0.5,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings14) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 180.0,
    .boomPitch = -1.3,
    .points = { .two = {  0.0, -1.0, 0.0, 0.0, -1.0, -500.0 }},
    .viewPitch = 0.5,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings15) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 90.0,
    .boomPitch = 5.4,
    .points = { .two = {  0.0, -1.0, 0.0, 0.0, -1.0, 500.0 }},
    .viewPitch = -6.9,
    .flag = FALSE,
};

CameraControlSettings N(IntroCamSettings16) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 445.8,
    .boomPitch = 5.4,
    .points = { .two = {  0.0, -1.0, 0.0, 0.0, -1.0, 500.0 }},
    .viewPitch = -6.9,
    .flag = FALSE,
};

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

    mdl_set_depth_tint_params(primR, primG, primB, primA, fogR, fogG, fogB, fogStart, fogEnd);
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
        mdl_get_remap_tint_params(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
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
        mdl_set_remap_tint_params(
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
        mdl_set_remap_tint_params(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
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
    if (gameStatus->introPart > INTRO_PART_NONE && gameStatus->introPart < INTRO_PART_5) {
        gameStatus->introPart++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

API_CALLABLE(N(InitWorldTintMode)) {
    mdl_set_all_tint_type(ENV_TINT_REMAP);
    return ApiStatus_DONE2;
}

// adjusts properties of EmitterVolume:GoldShimmer2 effect
API_CALLABLE(N(SetStarSpiritSparkleTrailPos)) {
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

API_CALLABLE(N(SetCardCaptureState1)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(0));

    effect->data.somethingRotating[N(D_802495DC_A3381C) + 1].state = 1;
    N(D_802495DC_A3381C)++;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetCardCaptureState3)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(0));

    effect->data.somethingRotating[N(D_802495E0_A33820) + 1].state = 3;
    N(D_802495E0_A33820)++;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetLightRayPos)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(16));

    effect->data.lightRays->pos.x = script->varTable[0];
    effect->data.lightRays->pos.y = script->varTable[1];
    effect->data.lightRays->pos.z = script->varTable[2];
    return ApiStatus_DONE2;
}

#include "../common/IntroMathUtil.inc.c"

f32 N(StoryCameraAngle) = 240.0;

u16* N(ColorBufPtr) = NULL;

f32 IntroCamStateA_BoomLength = 130.4;
f32 IntroCamStateA_BoomPitch = 12.4;
f32 IntroCamStateA_ViewPitch = -16.8;
f32 IntroCamStateA_Vfov = 62.0;

API_CALLABLE(N(InitializeStoryCamera)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == N(ColorBufPtr)) {
        return ApiStatus_BLOCK;
    }
    N(ColorBufPtr) = nuGfxCfb_ptr;
    N(lerp_value_with_max_step)(250.0f, 0.0f, N(StoryCameraAngle), 0.5f, &N(StoryCameraAngle));
    N(interp_value_with_easing)(INTRO_MATH_EASING_SIN_OUT_DELAYED,
        130.4f, N(IntroCamSettings2).boomLength, 0.0f,
        470.0f, &IntroCamStateA_BoomLength);
    N(lerp_value_with_max_step)(12.4f, N(IntroCamSettings2).boomPitch, IntroCamStateA_BoomPitch, 0.05f, &IntroCamStateA_BoomPitch);
    N(lerp_value_with_max_step)(-16.8f, N(IntroCamSettings2).viewPitch, IntroCamStateA_ViewPitch, 0.05f, &IntroCamStateA_ViewPitch);
    N(lerp_value_with_max_step)(62.0f, 49.0f, IntroCamStateA_Vfov, 0.1f, &IntroCamStateA_Vfov);
    N(adjust_cam_vfov)(CAM_DEFAULT, IntroCamStateA_Vfov);
    camera->controlSettings.boomLength = IntroCamStateA_BoomLength;
    camera->controlSettings.boomPitch = IntroCamStateA_BoomPitch;
    camera->controlSettings.viewPitch = IntroCamStateA_ViewPitch;
    camera->controlSettings.points.two.Bx = sin_deg(N(StoryCameraAngle)) * 500.0f;
    camera->controlSettings.points.two.Bz = cos_deg(N(StoryCameraAngle)) * -500.0f;
    camera->panActive = TRUE;
    return ApiStatus_DONE2;
}

f32 IntroCamStateB_BoomLength = 130.4;
f32 IntroCamStateB_BoomPitch = 12.4;
f32 IntroCamStateB_ViewPitch = -16.8;
f32 IntroCamStateB_Vfov = 62.0;

s32 N(D_802498F8_A33B38) = 0;
s32 N(D_802498FC_A33B3C) = 0;

// probably for unused 'breaking ceiling' part of the scene
API_CALLABLE(N(UnusedInitializeStoryCamera)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == N(ColorBufPtr)) {
        return ApiStatus_BLOCK;
    }
    N(ColorBufPtr) = nuGfxCfb_ptr;
    N(lerp_value_with_max_step)(250.0f, 0.0f, N(StoryCameraAngle), 0.5f, &N(StoryCameraAngle));
    N(interp_value_with_easing)(INTRO_MATH_EASING_SIN_OUT_DELAYED, 130.4f, N(IntroCamSettings2).boomLength, N(D_802498FC_A33B3C), 470.0f, &IntroCamStateB_BoomLength);
    N(lerp_value_with_max_step)(12.4f, N(IntroCamSettings2).boomPitch, IntroCamStateB_BoomPitch, 0.05f, &IntroCamStateB_BoomPitch);
    N(lerp_value_with_max_step)(-16.8f, N(IntroCamSettings2).viewPitch, IntroCamStateB_ViewPitch, 0.05f, &IntroCamStateB_ViewPitch);
    N(lerp_value_with_max_step)(62.0f, 49.0f, IntroCamStateB_Vfov, 0.1f, &IntroCamStateB_Vfov);
    N(adjust_cam_vfov)(CAM_DEFAULT, IntroCamStateB_Vfov);
    camera->controlSettings.boomLength = IntroCamStateB_BoomLength;
    camera->controlSettings.boomPitch = IntroCamStateB_BoomPitch;
    camera->controlSettings.viewPitch = IntroCamStateB_ViewPitch;
    camera->controlSettings.points.two.Bx = sin_deg(N(StoryCameraAngle)) * 500.0f;
    camera->controlSettings.points.two.Bz = cos_deg(N(StoryCameraAngle)) * -500.0f;
    camera->panActive = TRUE;
    N(D_802498FC_A33B3C)++;
    if (N(StoryCameraAngle) == 0.0f) {
        N(D_802498F8_A33B38)++;
    }

    if (N(D_802498F8_A33B38) <= 30) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(StoryCameraShake1Angle) = 0;
f32 N(StoryCameraShake1Scale) = 1.0;

// probably for unused 'breaking ceiling' part of the scene
API_CALLABLE(N(StoryCameraShake1)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAG_SHAKING;
    }
    guTranslateF(camera->viewMtxShaking,
        N(StoryCameraShake1Scale) * sin_deg(N(StoryCameraShake1Angle) * 486),
        N(StoryCameraShake1Scale) * cos_deg(N(StoryCameraShake1Angle) * 254),
        0.0f
    );
    N(StoryCameraShake1Angle)++;
    N(StoryCameraShake1Scale) += (12.0f - N(StoryCameraShake1Scale)) * 0.2;
    if (N(StoryCameraShake1Angle) > 20) {
        guTranslateF(camera->viewMtxShaking, 0.0f, 0.0f, 0.0f);
        camera->flags &= ~CAMERA_FLAG_SHAKING;
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

s32 N(StoryCameraShake2Angle) = 0;
f32 N(StoryCameraShake2Scale) = 12.0;

// probably for unused 'breaking ceiling' part of the scene
API_CALLABLE(N(StoryCameraShake2)) {
    Camera* camera = &gCameras[gCurrentCameraID];
    Matrix4f sp18;
    f32 x, y;

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAG_SHAKING;
    }
    x = N(StoryCameraShake2Scale) * sin_deg(N(StoryCameraShake2Angle) * 486);
    y = N(StoryCameraShake2Scale) * cos_deg(N(StoryCameraShake2Angle) * 254);
    guTranslateF(camera->viewMtxShaking, x, y, 0.0f);
    guTranslateF(camera->viewMtxShaking, x, y, 0.0f);
    guRotateF(sp18, 20.0f, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp18, camera->viewMtxShaking, camera->viewMtxShaking);
    camera->panActive = TRUE;
    if (N(StoryCameraShake2Angle) >= 10) {
        guRotateF(camera->viewMtxShaking, 20.0f, 0.0f, 0.0f, 1.0f);
        return ApiStatus_DONE1;
    }
    N(StoryCameraShake2Angle)++;
    return ApiStatus_BLOCK;
}

s32 N(UnusedBowserLeapTime) = 0;

s16 N(UnusedBowserHoverOffsets)[] = {
    -3, -2, -1,  0,  1,  2,  3,  4,
     3,  2,  1,  0, -1, -2, -3, -4,
};

s16 N(UnusedBowserLeapPath)[] = {
    360, 345, 330, 315, 300, 285, 270, 255,
    240, 225, 215, 203, 191, 180, 170, 161, 153, 146, 140, 135
};

BSS f32 N(UnusedBowserLeapBaseY);

// probably for unused 'breaking ceiling' part of the scene
API_CALLABLE(N(UnusedBowserLeapDown)) {
    Npc* bowserMain = resolve_npc(script, NPC_Bowser_Body);
    Npc* bowserProp = resolve_npc(script, NPC_Bowser_Prop);

    if (isInitialCall) {
        bowserMain->pos.x = -64.0f;
        bowserMain->pos.y = 400.0f;
        bowserMain->pos.z = 85.0f;
        bowserProp->pos.x = -64.0f;
        bowserProp->pos.y = 400.0f;
        bowserProp->pos.z = 85.0f;
        bowserMain->colliderPos.x = bowserMain->pos.x;
        bowserProp->colliderPos.x = bowserProp->pos.x;
        bowserMain->colliderPos.z = bowserMain->pos.z;
        bowserProp->colliderPos.z = bowserProp->pos.z;
        N(UnusedBowserLeapBaseY) = 400.0f;
    }
    if (N(UnusedBowserLeapTime) < 20) {
        bowserMain->pos.y = N(UnusedBowserLeapPath)[N(UnusedBowserLeapTime)];
    } else {
        bowserMain->pos.y += N(UnusedBowserHoverOffsets)[((N(UnusedBowserLeapTime) - 20) & 30) / 2] * 0.1f;
    }
    bowserProp->pos.y = bowserMain->pos.y;
    bowserMain->colliderPos.y = bowserMain->pos.y;
    bowserProp->colliderPos.y = bowserProp->pos.y;

    N(UnusedBowserLeapTime)++;
    if (N(UnusedBowserLeapTime) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(BowserHoverTime) = 0;

s16 N(BowserHoverOffsets)[] = {
    -3, -2, -1,  0,  1,  2,  3,  4,
     3,  2,  1,  0, -1, -2, -3, -4,
};

BSS f32 N(BowserHoverBaseY);

API_CALLABLE(N(AddBowserHoverOffset)) {
    Npc* bowserMain = resolve_npc(script, NPC_Bowser_Body);
    Npc* bowserProp = resolve_npc(script, NPC_Bowser_Prop);

    if (isInitialCall) {
        bowserMain->pos.x = -64.0f;
        bowserMain->pos.y = 135.0f;
        bowserMain->pos.z = 85.0f;
        bowserProp->pos.x = -64.0f;
        bowserProp->pos.y = 135.0f;
        bowserProp->pos.z = 85.0f;
        bowserMain->colliderPos.x = bowserMain->pos.x;
        bowserProp->colliderPos.x = bowserProp->pos.x;
        bowserMain->colliderPos.z = bowserMain->pos.z;
        bowserProp->colliderPos.z = bowserProp->pos.z;
        N(BowserHoverBaseY) = 135.0f;
    }
    bowserMain->pos.y += N(BowserHoverOffsets)[((u32) (N(BowserHoverTime) - 20) & 30) / 2] * 0.1f;
    bowserProp->pos.y = bowserMain->pos.y;
    bowserMain->colliderPos.y = bowserMain->pos.y;
    bowserProp->colliderPos.y = bowserProp->pos.y;
    N(BowserHoverTime)++;
    if (N(BowserHoverTime) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(UnusedStoryCameraZoomAmt) = 30.0;

// probably for unused 'breaking ceiling' part of the scene
API_CALLABLE(N(UnusedStoryCameraZoom)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(lerp_value_with_max_step)(30.0f, 15.0f, N(UnusedStoryCameraZoomAmt), 1.0f, &N(UnusedStoryCameraZoomAmt));
    N(adjust_cam_vfov)(CAM_DEFAULT, N(UnusedStoryCameraZoomAmt));
    camera->panActive = TRUE;
    if (N(UnusedStoryCameraZoomAmt) == 15.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

// probably for unused 'breaking ceiling' part of the scene
API_CALLABLE(N(StoryCameraShakeEnd)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        camera->flags &= ~CAMERA_FLAG_SHAKING;
    }
    guTranslateF(camera->viewMtxShaking, 0.0f, 0.0f, 0.0f);
    return ApiStatus_DONE2;
}

s32 N(UnusedKammyMoveTime) = 0;

s16 N(UnusedKammyHoverOffset)[] = {
    -3, -2, -1,  0,  1,  2,  3,  4,
     3,  2,  1,  0, -1, -2, -3, -4,
};

Vec2s N(UnusedKammyMovePath)[] = {
    { 100, 240 },
    {  99, 230 },
    {  98, 220 },
    {  96, 211 },
    {  92, 202 },
    {  87, 194 },
    {  82, 187 },
    {  77, 181 },
    {  72, 176 },
    {  66, 171 },
    {  60, 167 },
    {  53, 163 },
    {  45, 160 },
    {  38, 157 },
    {  31, 155 },
    {  25, 153 },
    {  19, 152 },
    {  13, 150 },
    {   7, 149 },
    {   1, 148 },
    {  -5, 147 },
    { -10, 146 },
    { -14, 145 },
    { -17, 143 },
    { -18, 142 },
    { -18, 142 },
    { -18, 142 },
    { -18, 142 },
    { -18, 142 },
    { -18, 142 },
    { -18, 141 },
    { -17, 140 },
    { -16, 139 },
    { -14, 138 },
    { -11, 137 },
    {  -8, 136 },
    {  -5, 135 },
    {  -3, 135 },
    {  -1, 135 },
    {   0, 135 },
};

BSS f32 N(UnusedKammyMoveBaseY); // unused

// probably for unused 'breaking ceiling' part of the scene
API_CALLABLE(N(UnusedKammyMoveFunc)) {
    Npc* kammy = resolve_npc(script, NPC_Kammy);

    if (isInitialCall) {
        kammy->pos.x = -145.0f;
        kammy->pos.z = 114.0f;
        kammy->yaw = 270.0f;
        kammy->colliderPos.x = kammy->pos.x;
        kammy->colliderPos.z = kammy->pos.z;
    }
    if (N(UnusedKammyMoveTime) == 30) {
        kammy->yaw = 90.0f;
    }
    if (N(UnusedKammyMoveTime) < 40) {
        kammy->pos.x = N(UnusedKammyMovePath)[N(UnusedKammyMoveTime)].x - 145;
        kammy->pos.y = (((N(UnusedKammyMovePath)[N(UnusedKammyMoveTime)].y - 135) * 200) / 225) + 147;
        if (N(UnusedKammyMoveTime) < 20) {
            kammy->pos.z = 114.0f - (N(UnusedKammyMoveTime) * 30.0f) / 20.0f;
        } else {
            kammy->pos.z = 84.0f;
        }
        kammy->colliderPos.x = kammy->pos.x;
        kammy->colliderPos.z = kammy->pos.z;
    } else {
        kammy->pos.y += N(UnusedKammyHoverOffset)[((N(UnusedKammyMoveTime) - 40) & 30) / 2] * 0.1f;
    }
    kammy->colliderPos.y = kammy->pos.y;
    N(UnusedKammyMoveTime)++;
    if (N(UnusedKammyMoveTime) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(KammyHoverTime) = 0;

s16 N(KammyHoverOffsets)[] = {
    -3, -2, -1,  0,  1,  2,  3,  4,
     3,  2,  1,  0, -1, -2, -3, -4,
};

BSS f32 N(KammyHoverBaseY); // unused

API_CALLABLE(N(AddKammyHoverOffset)) {
    Npc* kammy = resolve_npc(script, NPC_Kammy);

    if (isInitialCall) {
        kammy->pos.x = -145.0f;
        kammy->pos.z = 84.0f;
        kammy->colliderPos.x = kammy->pos.x;
        kammy->colliderPos.z = kammy->pos.z;
        kammy->yaw = 90.0f;
        kammy->pos.y = 147.0f;
    }
    kammy->pos.y += N(KammyHoverOffsets)[((N(KammyHoverTime) - 40) & 30) / 2] * 0.1f;
    kammy->colliderPos.y = kammy->pos.y;

    N(KammyHoverTime)++;
    if (N(KammyHoverTime) < 2000) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(BoomLengthInhale) = 121.6;
s32 N(CamMoveInhaleTime) = 0;

API_CALLABLE(N(CamPushIn_BowserInhale)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_LINEAR, 121.6f, 90.0f, N(CamMoveInhaleTime), 40.0f, &N(BoomLengthInhale));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(BoomLengthInhale);
    if (N(CamMoveInhaleTime) % 5 == 0 && N(BoomLengthInhale) != 90.0f) {
        f32 temp_f4 = resolve_npc(script, NPC_Bowser_Body)->pos.y - 150.0f;

        fx_fire_breath(
            1, script->varTable[0],
            script->varTable[1] + temp_f4,
            script->varTable[2],
            script->varTable[3] - 5,
            script->varTable[4] + temp_f4,
            script->varTable[5] - 30, 0, 5, 20
        );
    }

    N(CamMoveInhaleTime)++;
    if (N(CamMoveInhaleTime) <= (s32)(40 * DT)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(BoomLengthExhale) = 90.0;
s32 N(CamMoveExhaleTime) = 0;

API_CALLABLE(N(CamPullBack_BowserExhale)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 90.0f, 474.7f, N(CamMoveExhaleTime), 20.0f, &N(BoomLengthExhale));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(BoomLengthExhale);
    N(CamMoveExhaleTime)++;
    if (N(CamMoveExhaleTime) < (s32)(21 * DT)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(FlyToStarRodTime) = 0;

BSS f32 N(FlyToStarRodStartX);
BSS f32 N(FlyToStarRodStartZ);

API_CALLABLE(N(BowserFlyToStarRod)) {
    Npc* bowserMain = resolve_npc(script, NPC_Bowser_Body);
    Npc* bowserProp = resolve_npc(script, NPC_Bowser_Prop);

    if (isInitialCall) {
        N(FlyToStarRodStartX) = bowserMain->pos.x;
        N(FlyToStarRodStartZ) = bowserMain->pos.z;
    }
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(FlyToStarRodStartX), 0.0f, N(FlyToStarRodTime), 40.0f, &bowserMain->pos.x);
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(FlyToStarRodStartZ), 0.0f, N(FlyToStarRodTime), 40.0f, &bowserMain->pos.z);
    bowserProp->pos.x = bowserMain->pos.x;
    bowserProp->pos.z = bowserMain->pos.z;
    bowserMain->colliderPos.x = bowserMain->pos.x;
    bowserMain->colliderPos.z = bowserMain->pos.z;
    bowserProp->colliderPos.x = bowserProp->pos.x;
    bowserProp->colliderPos.z = bowserProp->pos.z;

    N(FlyToStarRodTime)++;
    if (N(FlyToStarRodTime) <= (s32)(40 * DT)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(HoldStarRodTime) = 0;

BSS f32 N(HoldStarRodFov);
BSS f32 N(HoldStarRodBoomLength);
BSS f32 N(HoldStarRodCamX);
BSS f32 N(HoldStarRodCamY);
BSS f32 N(HoldStarRodCamZ);

BSS f32 N(FlyToBowserStartX);
BSS f32 N(FlyToBowserStartZ);

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

typedef struct UnkHos05Path {
    /* 0x00 */ Vec3f startPoint;
    /* 0x0C */ Vec3f midPoint;
    /* 0x18 */ Vec3f endPoint;
    /* 0x24 */ char unk_24[4];
} UnkHos05Path; // size = 0x28

BSS UnkHos05Path N(D_8024F3F8)[7];

BSS StoryGraphicData N(StoryGraphics);

API_CALLABLE(N(CamPullBack_BowserHoldingStarRod)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_4,  35.0f,  35.0f, N(HoldStarRodTime), 80.0f, &N(HoldStarRodFov));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 130.0f, 270.0f, N(HoldStarRodTime), 80.0f, &N(HoldStarRodBoomLength));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4,  30.0f,   0.0f, N(HoldStarRodTime), 80.0f, &N(HoldStarRodCamX));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4, 232.0f, 177.0f, N(HoldStarRodTime), 80.0f, &N(HoldStarRodCamY));
    N(interp_value_with_easing)(INTRO_MATH_EASING_4,   0.0f,   0.0f, N(HoldStarRodTime), 80.0f, &N(HoldStarRodCamZ));
    N(adjust_cam_vfov)(CAM_DEFAULT, N(HoldStarRodFov));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(HoldStarRodBoomLength);
    camera->movePos.x = N(HoldStarRodCamX);
    camera->movePos.y = N(HoldStarRodCamY);
    camera->movePos.z = N(HoldStarRodCamZ);

    N(HoldStarRodTime)++;
    if (N(HoldStarRodTime) <= (s32)(90 * DT)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

f32 N(PanAcrossRoomCamX) = 40.0;
f32 N(PanAcrossRoomCamZ) = -40.0;
f32 N(PanAcrossRoomAngle) = 45.0;
s32 N(PanAcrossRoomTime) = 0;

// pan across the room
API_CALLABLE(N(CamPanAcrossRoom)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_LINEAR, 40.0f, -130.0f, N(PanAcrossRoomTime), 170.0f, &N(PanAcrossRoomCamX));
    N(interp_value_with_easing)(INTRO_MATH_EASING_LINEAR, -40.0f, 130.0f, N(PanAcrossRoomTime), 170.0f, &N(PanAcrossRoomCamZ));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 45.0f, 25.0f, N(PanAcrossRoomTime), 170.0f, &N(PanAcrossRoomAngle));
    camera->panActive = TRUE;
    camera->movePos.x = N(PanAcrossRoomCamX);
    camera->movePos.z = N(PanAcrossRoomCamZ);
    camera->controlSettings.points.two.Bx = sin_deg(N(PanAcrossRoomAngle)) * 500.0f;
    camera->controlSettings.points.two.Bz = cos_deg(N(PanAcrossRoomAngle)) * 500.0f;

    N(PanAcrossRoomTime)++;
    if (N(PanAcrossRoomTime) == (s32)(170 * DT)) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

f32 N(OrbitKammyFov) = 50.0;
f32 N(OrbitKammyBoomLength) = 246.1;
f32 N(OrbitKammyCamY) = 200.0;
f32 N(OrbitKammyAngle) = 25.0;
s32 N(OrbitKammyTime) = 0;

API_CALLABLE(N(CamMove_OrbitKammy)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT,  25.0f, 200.0f, N(OrbitKammyTime), 120.0f, &N(OrbitKammyAngle));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT,  50.0f,  35.0f, N(OrbitKammyTime), 30.0f, &N(OrbitKammyFov));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 246.1f, 180.0f, N(OrbitKammyTime), 30.0f, &N(OrbitKammyBoomLength));
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, 200.0f, 220.0f, N(OrbitKammyTime), 30.0f, &N(OrbitKammyCamY));
    camera->controlSettings.points.two.Bx = sin_deg(N(OrbitKammyAngle)) * 500.0f;
    camera->controlSettings.points.two.Bz = cos_deg(N(OrbitKammyAngle)) * 500.0f;
    N(adjust_cam_vfov)(CAM_DEFAULT, N(OrbitKammyFov));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(OrbitKammyBoomLength);
    camera->movePos.y = N(OrbitKammyCamY);

    N(OrbitKammyTime)++;
    if (N(OrbitKammyTime) <= (s32)(120 * DT)) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

// TODO document this function
API_CALLABLE(func_802428C8_A2CB08) {
    Bytecode* args = script->ptrReadPos;
    s32 arg0 = evt_get_variable(script, *args++);
    f32 arg1 = evt_get_float_variable(script, *args++);
    f32 arg2 = evt_get_float_variable(script, *args++);
    EffectInstance* arrayVar0;
    f32 xPos, yPos, zPos;
    EffectInstance* effect;
    UnkHos05Path* path;
    Vec3f* point;
    Vec3f* endPoint;
    s32 numPoints;
    s32 pathTime;
    s32 i;

    arrayVar0 = (EffectInstance*) evt_get_variable(script, ArrayVar(0));
    effect = arrayVar0;

    // set endPoint
    switch (arg0) {
        case 1:
            path = &N(D_8024F3F8)[0];
            i = 1;
            point = &path->startPoint;
            pathTime = 30;
            numPoints = 3;
            {
                f32 angle = 90.0f;
                u32 unk_14 = effect->data.somethingRotating->unk_14 + 30;
                f32 angle3 = unk_14 * 4.0f + (f32) i * 51.43;
                f32 radius = 50.0f;
                f32 temp_f24 = sin_deg(angle3);
                xPos = effect->data.somethingRotating->pos.x + sin_deg(angle) * radius * temp_f24 ;
                yPos = effect->data.somethingRotating->pos.y + cos_deg(angle3) * radius;
                /// @bug should be `zPos = effect->data.somethingRotating->pos.z + cos_deg(angle) * radius * temp_f24;`
                zPos = effect->data.somethingRotating->pos.z + sin_deg(angle) * radius * temp_f24;
                path->endPoint.x = xPos;
                path->endPoint.y = yPos;
                path->endPoint.z = zPos;
            }
            break;
        case 2:
            path = &N(D_8024F3F8)[1];
            i = 7;
            point = &path->startPoint;
            pathTime = 30;
            numPoints = 3;
            {
                f32 angle = 90.0f;
                u32 unk_14 = effect->data.somethingRotating->unk_14 + 30;
                f32 angle3 = unk_14 * 4.0f + (f32) i * 51.43;
                f32 radius = 50.0f;
                f32 temp_f24 = sin_deg(angle3);
                xPos = effect->data.somethingRotating->pos.x + sin_deg(angle) * radius * temp_f24 ;
                yPos = effect->data.somethingRotating->pos.y + cos_deg(angle3) * radius;
                zPos = effect->data.somethingRotating->pos.z + sin_deg(angle) * radius * temp_f24;
                path->endPoint.x = xPos;
                path->endPoint.y = yPos;
                path->endPoint.z = zPos;
            }
            break;
        case 3:
            path = &N(D_8024F3F8)[2];
            i = 3;
            point = &path->startPoint;
            pathTime = 30;
            numPoints = 3;
            {
                f32 angle = 90.0f;
                u32 unk_14 = effect->data.somethingRotating->unk_14 + 30;
                f32 angle3 = unk_14 * 4.0f + (f32) i * 51.43;
                f32 radius = 50.0f;
                f32 temp_f24 = sin_deg(angle3);
                xPos = effect->data.somethingRotating->pos.x + sin_deg(angle) * radius * temp_f24 ;
                yPos = effect->data.somethingRotating->pos.y + cos_deg(angle3) * radius;
                zPos = effect->data.somethingRotating->pos.z + sin_deg(angle) * radius * temp_f24;
                path->endPoint.x = xPos;
                path->endPoint.y = yPos;
                path->endPoint.z = zPos;
            }
            break;
        case 4:
            path = &N(D_8024F3F8)[3];
            i = 4;
            point = &path->startPoint;
            pathTime = 30;
            {
                f32 angle = 90.0f;
                u32 unk_14 = effect->data.somethingRotating->unk_14 + 30;
                f32 angle3 = unk_14 * 4.0f + (f32) i * 51.43;
                f32 radius = 50.0f;
                f32 temp_f24 = sin_deg(angle3);
                numPoints = 3;
                xPos = effect->data.somethingRotating->pos.x + sin_deg(angle) * radius * temp_f24 ;
                yPos = effect->data.somethingRotating->pos.y + cos_deg(angle3) * radius;
                zPos = effect->data.somethingRotating->pos.z + sin_deg(angle) * radius * temp_f24;
                path->endPoint.x = xPos;
                path->endPoint.y = yPos;
                path->endPoint.z = zPos;
            }
            break;
        case 5:
            path = &N(D_8024F3F8)[4];
            i = 6;
            point = &path->startPoint;
            pathTime = 30;
            numPoints = 3;
            {
                f32 angle = 90.0f;
                u32 unk_14 = effect->data.somethingRotating->unk_14 + 30;
                f32 angle3 = unk_14 * 4.0f + (f32) i * 51.43;
                f32 radius = 50.0f;
                f32 temp_f24 = sin_deg(angle3);
                xPos = effect->data.somethingRotating->pos.x + sin_deg(angle) * radius * temp_f24 ;
                yPos = effect->data.somethingRotating->pos.y + cos_deg(angle3) * radius;
                zPos = effect->data.somethingRotating->pos.z + sin_deg(angle) * radius * temp_f24;
                path->endPoint.x = xPos;
                path->endPoint.y = yPos;
                path->endPoint.z = zPos;
            }
            break;
        case 6:
            path = &N(D_8024F3F8)[5];
            i = 2;
            point = &path->startPoint;
            pathTime = 30;
            numPoints = 3;
            {
                f32 angle = 90.0f;
                u32 unk_14 = effect->data.somethingRotating->unk_14 + 30;
                f32 angle3 = unk_14 * 4.0f + (f32) i * 51.43;
                f32 radius = 50.0f;
                f32 temp_f24 = sin_deg(angle3);
                xPos = effect->data.somethingRotating->pos.x + sin_deg(angle) * radius * temp_f24 ;
                yPos = effect->data.somethingRotating->pos.y + cos_deg(angle3) * radius;
                zPos = effect->data.somethingRotating->pos.z + sin_deg(angle) * radius * temp_f24;
                path->endPoint.x = xPos;
                path->endPoint.y = yPos;
                path->endPoint.z = zPos;
            }
            break;
        default:
            path = &N(D_8024F3F8)[6];
            i = 5;
            point = &path->startPoint;
            pathTime = 30;
            numPoints = 3;
            {
                f32 angle = 90.0f;
                u32 unk_14 = effect->data.somethingRotating->unk_14 + 30;
                f32 angle3 = unk_14 * 4.0f + (f32) i * 51.43;
                f32 radius = 50.0f;
                f32 temp_f24 = sin_deg(angle3);
                xPos = effect->data.somethingRotating->pos.x + sin_deg(angle) * radius * temp_f24 ;
                yPos = effect->data.somethingRotating->pos.y + cos_deg(angle3) * radius;
                zPos = effect->data.somethingRotating->pos.z + sin_deg(angle) * radius * temp_f24;
                path->endPoint.x = xPos;
                path->endPoint.y = yPos;
                path->endPoint.z = zPos;
            }
            break;
    }

    // set startPoint
    point->x = evt_get_float_variable(script, LVar0);
    point->y = evt_get_float_variable(script, LVar1);
    point->z = evt_get_float_variable(script, LVar2);

    endPoint = &point[2];
    point++;

    // set midPoint
    if (arg0 != 2) {
        point->x = (evt_get_float_variable(script, LVar0) * arg2) + (endPoint->x * (1.0f - arg2));
        point->y = (evt_get_float_variable(script, LVar1) * arg2) + (endPoint->y * (1.0f - arg2)) + arg1;
        point->z = (evt_get_float_variable(script, LVar2) * arg2) + (endPoint->z * (1.0f - arg2));
    } else {
        point->x = ((evt_get_float_variable(script, LVar0) * arg2) + (endPoint->x * (1.0f - arg2))) - 50.0f;
        point->y = (evt_get_float_variable(script, LVar1) * arg2) + (endPoint->y * (1.0f - arg2)) + arg1;
        point->z = ((evt_get_float_variable(script, LVar2) * arg2) + (endPoint->z * (1.0f - arg2))) - 50.0f;
    }

    script->varTable[0] = pathTime;
    script->varTablePtr[1] = path;
    script->varTable[2] = numPoints;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateWorldFogParams) = {
    Set(LVar0, 120)
    Set(LVar1, 895)
    Loop(10)
        Add(LVar0, -12)
        Add(LVar1, 10)
        Call(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CaptureSpirits) = {
    Call(DismissEffect, ArrayVar(6))
    Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    Thread
        Wait(3)
        Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        Set(ArrayVar(13), LVarF)
        Call(func_802428C8_A2CB08, 6, 80, Float(0.5))
        Call(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        SetF(LVar4, Float(1.0))
        Label(6)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Klevar, LVar1, LVar2, LVar3)
        Call(N(SetStarSpiritSparkleTrailPos), ArrayVar(13), ArrayVar(24), LVar1, LVar2, LVar3)
        AddF(LVar4, Float(-0.03125))
        Call(SetNpcScale, NPC_Klevar, LVar4, LVar4, LVar4)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(6)
        EndIf
        Call(N(SetCardCaptureState1))
        Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
        Call(SetNpcImgFXParams, NPC_Klevar, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetNpcFlagBits, NPC_Klevar, NPC_FLAG_INVISIBLE, TRUE)
        Call(DismissEffect, ArrayVar(13))
    EndThread
    Wait(20 * DT)
    Call(DismissEffect, ArrayVar(3))
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    Thread
        Wait(3)
        Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        Set(ArrayVar(10), LVarF)
        Call(func_802428C8_A2CB08, 3, 30, Float(0.5))
        Call(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        SetF(LVar4, Float(1.0))
        Label(3)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Skolar, LVar1, LVar2, LVar3)
        Call(N(SetStarSpiritSparkleTrailPos), ArrayVar(10), ArrayVar(21), LVar1, LVar2, LVar3)
        AddF(LVar4, Float(-0.03125))
        Call(SetNpcScale, NPC_Skolar, LVar4, LVar4, LVar4)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(3)
        EndIf
        Call(N(SetCardCaptureState1))
        Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
        Call(SetNpcImgFXParams, NPC_Skolar, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_INVISIBLE, TRUE)
        Call(DismissEffect, ArrayVar(10))
    EndThread
    Wait(20 * DT)
    Call(DismissEffect, ArrayVar(4))
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    Thread
        Wait(3)
        Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        Set(ArrayVar(11), LVarF)
        Call(func_802428C8_A2CB08, 4, -80, Float(0.3))
        Call(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        SetF(LVar4, Float(1.0))
        Label(4)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Muskular, LVar1, LVar2, LVar3)
        Call(N(SetStarSpiritSparkleTrailPos), ArrayVar(11), ArrayVar(22), LVar1, LVar2, LVar3)
        AddF(LVar4, Float(-0.03125))
        Call(SetNpcScale, NPC_Muskular, LVar4, LVar4, LVar4)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(4)
        EndIf
        Call(N(SetCardCaptureState1))
        Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
        Call(SetNpcImgFXParams, NPC_Muskular, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_INVISIBLE, TRUE)
        Call(DismissEffect, ArrayVar(11))
    EndThread
    Wait(20 * DT)
    Call(DismissEffect, ArrayVar(7))
    Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    Thread
        Wait(3)
        Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        Set(ArrayVar(14), LVarF)
        Call(func_802428C8_A2CB08, 7, 120, Float(0.5))
        Call(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        SetF(LVar4, Float(1.0))
        Label(7)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kalmar, LVar1, LVar2, LVar3)
        Call(N(SetStarSpiritSparkleTrailPos), ArrayVar(14), ArrayVar(25), LVar1, LVar2, LVar3)
        AddF(LVar4, Float(-0.03125))
        Call(SetNpcScale, NPC_Kalmar, LVar4, LVar4, LVar4)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(7)
        EndIf
        Call(N(SetCardCaptureState1))
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Panic)
        Call(SetNpcImgFXParams, NPC_Kalmar, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetNpcFlagBits, NPC_Kalmar, NPC_FLAG_INVISIBLE, TRUE)
        Call(DismissEffect, ArrayVar(14))
    EndThread
    Wait(20 * DT)
    Call(DismissEffect, ArrayVar(5))
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    Thread
        Wait(3)
        Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        Set(ArrayVar(12), LVarF)
        Call(func_802428C8_A2CB08, 5, 120, Float(0.5))
        Call(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        SetF(LVar4, Float(1.0))
        Label(5)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
        Call(N(SetStarSpiritSparkleTrailPos), ArrayVar(12), ArrayVar(23), LVar1, LVar2, LVar3)
        AddF(LVar4, Float(-0.03125))
        Call(SetNpcScale, NPC_Misstar, LVar4, LVar4, LVar4)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(5)
        EndIf
        Call(N(SetCardCaptureState1))
        Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
        Call(SetNpcImgFXParams, NPC_Misstar, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetNpcFlagBits, NPC_Misstar, NPC_FLAG_INVISIBLE, TRUE)
        Call(DismissEffect, ArrayVar(12))
    EndThread
    Wait(20 * DT)
    Call(DismissEffect, ArrayVar(2))
    Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    Thread
        Wait(3)
        Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        Set(ArrayVar(9), LVarF)
        Call(func_802428C8_A2CB08, 2, -60, Float(0.5))
        Call(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        SetF(LVar4, Float(1.0))
        Label(2)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Mamar, LVar1, LVar2, LVar3)
        Call(N(SetStarSpiritSparkleTrailPos), ArrayVar(9), ArrayVar(20), LVar1, LVar2, LVar3)
        AddF(LVar4, Float(-0.03125))
        Call(SetNpcScale, NPC_Mamar, LVar4, LVar4, LVar4)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(2)
        EndIf
        Call(N(SetCardCaptureState1))
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Panic)
        Call(SetNpcImgFXParams, NPC_Mamar, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetNpcFlagBits, NPC_Mamar, NPC_FLAG_INVISIBLE, TRUE)
        Call(DismissEffect, ArrayVar(9))
    EndThread
    Wait(20 * DT)
    Return
    End
};

f32 N(FinalCamMoveBoomLength) = 130.0;

API_CALLABLE(N(CamPullBack_Final)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    N(lerp_value_with_max_step)(N(IntroCamSettings15).boomLength, N(IntroCamSettings16).boomLength,
        N(FinalCamMoveBoomLength), 1.0f, &N(FinalCamMoveBoomLength));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(FinalCamMoveBoomLength);
    if (N(FinalCamMoveBoomLength) == 700.0f) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

s32 N(FlyToBowserTime) = 0;

API_CALLABLE(N(KammyFlyToBowser)) {
    Npc* kammy = resolve_npc(script, NPC_Kammy);

    if (isInitialCall) {
        N(FlyToBowserStartX) = kammy->pos.x;
        N(FlyToBowserStartZ) = kammy->pos.z;
    }

    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(FlyToBowserStartX), -95.0f, N(FlyToBowserTime), 40.0f, &kammy->pos.x);
    N(interp_value_with_easing)(INTRO_MATH_EASING_COS_IN_OUT, N(FlyToBowserStartZ), 20.0f, N(FlyToBowserTime), 40.0f, &kammy->pos.z);
    kammy->colliderPos.x = kammy->pos.x;
    kammy->colliderPos.z = kammy->pos.z;

    N(FlyToBowserTime)++;
    if (N(FlyToBowserTime) <= (s32)(40 * DT)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

void N(appendGfx_image_strips)(
    s32 baseX, s32 baseY,
    IMG_PTR img, PAL_PTR pal,
    s32 alpha, s32 width, s32 height, s32 lineHeight
);

// when the spirits leap back in shock, their radial position is multuplied by these; xz by the first, y by the second
s32 N(StarSpiritLeapBackScalars)[] = {
    Float(0.93),  Float(0.9),
    Float(0.938), Float(0.91),
    Float(0.955), Float(0.93),
    Float(0.968), Float(0.95),
    Float(0.979), Float(0.97),
    Float(0.985), Float(0.985),
    Float(0.995), Float(0.995),
    Float(0.998), Float(0.998),
    Float(0.999), Float(0.999),
    Float(1.0),   Float(1.0),
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
    gsDPSetCombineMode(PM_CC_10, PM_CC_10),
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

    gDPPipeSync(gMainGfxPos++);
    gSPDisplayList(gMainGfxPos++, N(gfx_setup_story_viewport));

    if (pal != NULL) {
        gDPLoadTLUT_pal256(gMainGfxPos++, pal);
    } else {
        gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    }

    get_screen_overlay_params(SCREEN_LAYER_BACK, &overlayType, &overlayAlphaBack);
    get_screen_overlay_params(SCREEN_LAYER_FRONT, &overlayType, &overlayAlphaFront);
    alpha = alpha * (255.0f - overlayAlphaBack) * (255.0f - overlayAlphaFront) / 255.0f / 255.0f;
    if (alpha != 255) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_01, PM_CC_01);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);
    } else {
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);


    for (i = 0; i < height / lineHeight; i++) {
        gDPLoadTextureTile(gMainGfxPos++, img, pal != NULL ? G_IM_FMT_CI : G_IM_FMT_IA, G_IM_SIZ_8b, width, height,
                        0, i * lineHeight, width - 1, i * lineHeight + lineHeight - 1, 0,
                        G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gMainGfxPos++, baseX * 4, (baseY + i * lineHeight) * 4, (baseX + width) * 4,
                        (baseY + i * lineHeight + lineHeight) * 4, G_TX_RENDERTILE, 0, (i * lineHeight) * 32, 1024, 1024);
    }

    gDPPipeSync(gMainGfxPos++);
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

    gDPPipeSync(gMainGfxPos++);
    gDPLoadTLUT_pal256(gMainGfxPos++, pal);
    for (i = 0; i < 23; i++) {
        gDPLoadTextureTile(gMainGfxPos++, img, G_IM_FMT_CI, G_IM_SIZ_8b, 264, 162,
                           0, i * 7, 263, i * 7 + 7 - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gMainGfxPos++, baseX * 4, (baseY + i * 7) * 4, (baseX + 264) * 4, (baseY + i * 7 + 7) * 4,
                                G_TX_RENDERTILE, 0, (i * 7) << 5, 1024, 1024);
    }
    if (m != 0) {
        gDPLoadTextureTile(gMainGfxPos++, img, G_IM_FMT_CI, G_IM_SIZ_8b, 264, 0,
                           0, i * 7, 263, i * 7 + m - 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gMainGfxPos++, baseX * 4, (baseY + i * 7) * 4, (baseX + 264) * 4, (baseY + i * 7 + m) * 4,
                                G_TX_RENDERTILE, 0, (i * 7) << 5, 1024, 1024);
    }
    gDPPipeSync(gMainGfxPos++);
}

void N(worker_draw_story_graphics)(void) {
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 vpX = camera->viewportStartX;
    s32 vpY = camera->viewportStartY;
    u8 overlayType;
    f32 overlayAlpha;

    N(draw_background_tape)();

    gSPDisplayList(gMainGfxPos++, N(gfx_setup_story_viewport));
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb_ptr);

    if (N(StoryGraphicsPtr)->storyPageAlpha < 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(StoryGraphicsPtr)->storyPageAlpha);
    }
    get_screen_overlay_params(SCREEN_LAYER_BACK, &overlayType, &overlayAlpha);
    if (overlayAlpha != 0.0f) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_43, PM_CC_43);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 208, 208, 208, (s32) overlayAlpha);
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

#ifdef SHIFT
// TODO this breaks stuff to enable it for the shift build
// #define TAPE_OFFSET title_tape_ROM_START - title_bg_1_ROM_START
#define TAPE_OFFSET 0x2A440
#else
#define TAPE_OFFSET 0x2A440
#endif

#define STORY_IMG_SIZE (264 * 162 * G_IM_SIZ_8b_BYTES)
#define TAPE_IMG_SIZE (128 * 128 * G_IM_SIZ_8b_BYTES)
#define BOWSER_IMG_SIZE (128 * 128 * G_IM_SIZ_8b_BYTES)
#define PAL_256_SIZE (256 * 2)

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
            title_bg_1_ROM_START + imageIdx * (STORY_IMG_SIZE + PAL_256_SIZE),
            title_bg_1_ROM_START + (imageIdx + 1) * (STORY_IMG_SIZE + PAL_256_SIZE),
            N(StoryGraphicsPtr)->imgFront
        );
    } else {
        dma_copy(
            title_bg_1_ROM_START + imageIdx * (STORY_IMG_SIZE + PAL_256_SIZE),
            title_bg_1_ROM_START + (imageIdx + 1) * (STORY_IMG_SIZE + PAL_256_SIZE),
            N(StoryGraphicsPtr)->imgBack
        );
    }
}

API_CALLABLE(N(InitializeStoryGraphicsData)) {
    u8* dmaEnd;
    u8* dmaStart;
    s32 tapeOffset;
    u8* it;

    N(StoryGraphicsPtr)->workerID = create_worker_frontUI(NULL, N(worker_draw_story_graphics));
    N(StoryGraphicsPtr)->imgFront = it = mdl_get_next_texture_address(
        (STORY_IMG_SIZE + PAL_256_SIZE) +
        (STORY_IMG_SIZE + PAL_256_SIZE) +
        TAPE_IMG_SIZE +
        (BOWSER_IMG_SIZE + PAL_256_SIZE));
    it += STORY_IMG_SIZE;
    N(StoryGraphicsPtr)->palFront = (u16*) it;
    it += PAL_256_SIZE;
    N(StoryGraphicsPtr)->imgBack = it;
    it += STORY_IMG_SIZE;
    N(StoryGraphicsPtr)->palBack = (u16*) it;
    it += PAL_256_SIZE;
    N(StoryGraphicsPtr)->imgTape = it;
    it += TAPE_IMG_SIZE;
    N(StoryGraphicsPtr)->imgBowser = it;
    it += BOWSER_IMG_SIZE;
    N(StoryGraphicsPtr)->palBowser = (u16*) it;
    N(StoryGraphicsPtr)->frontImgPosX = 0;
    N(StoryGraphicsPtr)->frontImgPosY = 0;
    N(StoryGraphicsPtr)->backImgPosX = 0;
    N(StoryGraphicsPtr)->backImgPosY = 0;
    N(StoryGraphicsPtr)->silhouettePosX = 0;
    N(StoryGraphicsPtr)->silhouettePosY = 240;
    N(StoryGraphicsPtr)->tapePosX = 111;
    N(StoryGraphicsPtr)->tapePosY = 54;

    N(load_story_image)(FALSE, STORY_PAGE_BLANK);
    N(load_story_image)(TRUE, STORY_PAGE_STARRY_SKY);

    // load the tape and bowser silhouette images
    tapeOffset = TAPE_OFFSET;
    dmaStart = title_bg_1_ROM_START + tapeOffset;
    dmaEnd = title_bg_1_ROM_START + tapeOffset + TAPE_IMG_SIZE;

    dma_copy(dmaStart, dmaEnd + (BOWSER_IMG_SIZE + PAL_256_SIZE), N(StoryGraphicsPtr)->imgTape);
    N(StoryGraphicsPtr)->flipOrder = 0;
    N(StoryGraphicsPtr)->storyPageAlpha = 255;
    N(StoryGraphicsPtr)->tapeAlpha = 0;
    return ApiStatus_DONE2;
}

enum {
    STORY_PAGE_STATE_BEGIN          = 0,
    STORY_PAGE_STATE_WAIT           = 1,
    STORY_PAGE_STATE_NEXT           = 2,
    STORY_PAGE_STATE_BOWSER_BEGIN   = 3,
    STORY_PAGE_STATE_BOWSER_ANIM    = 4,
    STORY_PAGE_STATE_BOWSER_NEXT    = 5,
    STORY_PAGE_STATE_DONE           = 6,
};

s32 N(StoryPageState) = STORY_PAGE_STATE_BEGIN;
s32 N(CurrentStoryPageIdx) = 0;
s32 N(CurrentStoryPageTime)= 0;
u32 N(BowserSilhouetteTime) = 0;

s32 N(StoryPageDuration)[] = {
    [STORY_PAGE_BLANK]          222 * DT,
    [STORY_PAGE_STARRY_SKY]     338 * DT,
    [STORY_PAGE_SHRINE_EXT]     338 * DT,
    [STORY_PAGE_STAR_ROD]       338 * DT,
    [STORY_PAGE_SHRINE_INT]     622 * DT,
};

s32 N(NextPageAnimOffsetsX)[] = {
#if VERSION_PAL
    0, 0, 0, -1, -3, -7, -12, -18, -28, -43, -60, -80, -100, -120, -140, -160, -180, -200, -220, -515, -270,
#else
    0, 0, 0, -1, -2, -3, -4, -9, -15, -22,
    -30, -39, -49, -60, -72, -85, -99, -114, -130, -147,
    -165, -184, -204, -225, -247, -270,
#endif
};

#if VERSION_PAL
static u32 padding = 0;
#endif

u8 N(BowserSilhouetteShakeY)[] = {
#if VERSION_PAL
    240, 240, 240, 240, 210, 185, 174, 168,
    170, 170, 170, 170, 170, 167, 165, 163,
    162, 162, 161, 161, 162, 163, 164, 165,
    167, 173, 175, 176, 176, 175, 171, 170,
    170, 167, 165, 164, 165, 167, 170, 173,
    176, 176, 175, 173, 170, 165, 164, 164,
    165, 167, 173, 175, 176, 176, 175, 170,
    167, 165, 164, 165, 165, 164, 165, 164,
    165, 165, 164, 165, 164, 165, 165, 164,
    164, 165, 167, 173, 175, 176, 176, 176,
    176, 176, 174, 170, 167, 164, 164, 165,
    167, 170, 167, 165, 164, 164, 165, 170,
    170, 167, 165, 164, 165, 167, 170, 170,
    167, 164, 164, 165, 167, 170, 167, 165,
    164, 164, 165, 170, 170, 167, 165, 164,
    165, 167, 170, 170, 167, 164, 165, 166,
    167, 166, 166, 167, 166, 165, 166, 166,
    165, 166, 167, 166, 168, 169, 170, 170,
    170, 170, 170, 170, 170, 170, 170, 170,
    173, 175, 176, 175, 173, 170, 167, 165,
    164, 165, 167, 170, 173, 176, 176, 175,
    173, 170, 165, 164, 164, 165, 167, 173,
    174, 175, 174, 173, 167, 165, 164, 164,
    165, 170, 173, 175, 176, 176, 173, 170,
    167, 165, 164, 165, 167, 170, 173, 175,
    176, 175, 173, 170, 167, 164, 164, 165,
    167, 169, 170, 170, 170, 170, 170, 170,
    170, 170, 170, 170, 165, 164, 164, 165,
    167, 170, 167, 165, 164, 164, 167, 170,
    173, 175, 176, 175, 173, 170, 167, 165,
    164, 165, 167, 170, 173, 176, 176, 175,
    173, 170, 165, 164, 164, 165, 167, 173,
    175, 176, 176, 175, 170, 167, 165, 164,
    164, 167, 170,
#else
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
#endif
};

u16 N(BowserSilhouetteLeapX)[] = {
    100, 110, 121, 136, 155, 175, 195, 214, 232, 249, 265, 280, 294, 307, 319
};

u16 N(BowserSilhouetteLeapY)[] = {
    3, 2, -6, -21, -40, -63, -90, -120, -160, -200, -240, -280, -320
};

#if VERSION_PAL
#define BOWSER_APPEARS_TIME (233)
#else
#define BOWSER_APPEARS_TIME (268)
#endif

API_CALLABLE(N(AnimateStorybookPages)) {
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
                sfx_play_sound(SOUND_INTRO_NEXT_PAGE);
            }
            break;
        case STORY_PAGE_STATE_NEXT:
            if (N(CurrentStoryPageTime) != 0) {
                N(CurrentStoryPageTime)--;
                if (!N(StoryGraphicsPtr)->flipOrder) {
                    N(StoryGraphicsPtr)->frontImgPosX = N(NextPageAnimOffsetsX)[ARRAY_COUNT(N(NextPageAnimOffsetsX)) - 1 - N(CurrentStoryPageTime)];
                    N(StoryGraphicsPtr)->frontImgPosY = 0;
                } else {
                    N(StoryGraphicsPtr)->backImgPosX = N(NextPageAnimOffsetsX)[ARRAY_COUNT(N(NextPageAnimOffsetsX)) - 1 - N(CurrentStoryPageTime)];
                    N(StoryGraphicsPtr)->backImgPosY = 0;
                }
            } else {
                N(CurrentStoryPageIdx)++;
                if (N(CurrentStoryPageIdx) + 1 < STORY_PAGE_SHRINE_INT + 1) {
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
                    gCameras[CAM_DEFAULT].flags &= ~CAMERA_FLAG_DISABLED;
                    N(StoryPageState)++;
                }
            }
            break;
        case STORY_PAGE_STATE_BOWSER_BEGIN:
            N(BowserSilhouetteTime) = 0;
            N(StoryPageState)++;
            N(CurrentStoryPageTime) = N(StoryPageDuration)[N(CurrentStoryPageIdx)];
            break;
        case STORY_PAGE_STATE_BOWSER_ANIM:
            if (N(CurrentStoryPageTime) != 0) {
                if (N(CurrentStoryPageTime) < N(StoryPageDuration)[N(CurrentStoryPageIdx)] - BOWSER_APPEARS_TIME) {
                    u32 timeLeft = N(BowserSilhouetteTime) - ARRAY_COUNT(N(BowserSilhouetteShakeY));

                    if (N(BowserSilhouetteTime) < ARRAY_COUNT(N(BowserSilhouetteShakeY))) {
                        N(StoryGraphicsPtr)->silhouettePosX = N(BowserSilhouetteLeapX)[0];
                        N(StoryGraphicsPtr)->silhouettePosY = N(BowserSilhouetteShakeY)[N(BowserSilhouetteTime)];
                    } else {
                        if (timeLeft < ARRAY_COUNT(N(BowserSilhouetteLeapX))) {
                            N(StoryGraphicsPtr)->silhouettePosX = N(BowserSilhouetteLeapX)[timeLeft];
                            if (timeLeft < ARRAY_COUNT(N(BowserSilhouetteLeapY))) {
                                N(StoryGraphicsPtr)->silhouettePosY =
                                    N(BowserSilhouetteShakeY)[ARRAY_COUNT(N(BowserSilhouetteShakeY)) - 1]
                                    + N(BowserSilhouetteLeapY)[timeLeft];
                            }
                        }
                    }
                    N(BowserSilhouetteTime)++;
                }
                N(CurrentStoryPageTime)--;
            } else {
                N(CurrentStoryPageTime) = ARRAY_COUNT(N(NextPageAnimOffsetsX));
                N(StoryPageState)++;
                N(StoryGraphicsPtr)->tapeAlpha = 255;
                sfx_play_sound(SOUND_INTRO_NEXT_PAGE);
            }
            break;
        case STORY_PAGE_STATE_BOWSER_NEXT:
            if (N(CurrentStoryPageTime) != 0) {
                N(CurrentStoryPageTime)--;
                if (!N(StoryGraphicsPtr)->flipOrder) {
                    N(StoryGraphicsPtr)->backImgPosX = N(NextPageAnimOffsetsX)[ARRAY_COUNT(N(NextPageAnimOffsetsX)) - 1 - N(CurrentStoryPageTime)];
                    N(StoryGraphicsPtr)->backImgPosY = 0;
                } else {
                    N(StoryGraphicsPtr)->frontImgPosX = N(NextPageAnimOffsetsX)[ARRAY_COUNT(N(NextPageAnimOffsetsX)) - 1 - N(CurrentStoryPageTime)];
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

s32 N(FadeAwayTapeTime) = 30;

API_CALLABLE(N(FadeAwayTapeGraphic)) {
    if (N(FadeAwayTapeTime) != 0) {
        N(FadeAwayTapeTime)--;
        N(StoryGraphicsPtr)->tapeAlpha = (N(FadeAwayTapeTime) * 255) / 30;
        return ApiStatus_BLOCK;
    } else {
        N(StoryGraphicsPtr)->tapeAlpha = 0;
        free_worker(N(StoryGraphicsPtr)->workerID);
        N(StoryGraphicsPtr)->workerID = 0;
        return ApiStatus_DONE1;
    }
}

s32 N(D_8024ACBC_A34EFC) = 0x00010019;

API_CALLABLE(N(ForceStarRodAlwaysFaceCamera)) {
    Npc* npc = resolve_npc(script, NPC_StarRod);

    npc->yaw = npc->renderYaw = 180.0f - gCameras[gCurrentCameraID].curYaw;
    return ApiStatus_BLOCK;
}

API_CALLABLE(func_80244550_A2E790) {
    Npc* kammy = resolve_npc(script, NPC_Kammy);
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, ArrayVar(0));
    Npc* npc2;
    f32 x, y, z;
    f32* x2;
    f32* y2;
    f32* z2;
    s32 i;

    if (isInitialCall) {
        N(D_8024F2FC) = kammy->pos.x;
        N(D_8024F300) = kammy->pos.y;
        N(D_8024F304) = kammy->pos.z;

        for (i = NPC_Eldstar; i < ARRAY_COUNT(N(StarSpiritsPosX)); i++) {
            npc2 = resolve_npc(script, i);

            N(StarSpiritsPosX)[i] = npc2->pos.x;
            N(StarSpiritsPosY)[i] = npc2->pos.y;
            N(StarSpiritsPosZ)[i] = npc2->pos.z;
        }
        N(D_8024F308) = effect->data.somethingRotating->pos.x;
        N(D_8024F30C) = effect->data.somethingRotating->pos.y;
        N(D_8024F310) = effect->data.somethingRotating->pos.z;
    }

    x = kammy->pos.x - N(D_8024F2FC);
    y = kammy->pos.y - N(D_8024F300);
    z = kammy->pos.z - N(D_8024F304);

    i = 0;
    z2 = N(StarSpiritsPosZ);
    y2 = N(StarSpiritsPosY);
    x2 = N(StarSpiritsPosX);
    for (; i < ARRAY_COUNT(N(StarSpiritsPosX)); ) {
        npc2 = resolve_npc(script, i);
        i++;
        npc2->pos.x = *x2++ + x;
        npc2->pos.y = *y2++ + y;
        npc2->pos.z = *z2++ + z;

        npc2->colliderPos.x = npc2->pos.x;
        npc2->colliderPos.y = npc2->pos.y;
        npc2->colliderPos.z = npc2->pos.z;
    }

    effect->data.somethingRotating->pos.x = N(D_8024F308) + x;
    effect->data.somethingRotating->pos.y = N(D_8024F30C) + y;
    effect->data.somethingRotating->pos.z = N(D_8024F310) + z;
    return ApiStatus_BLOCK;
}

extern EvtScript N(EVS_Scene_IntroStory);

EvtScript N(EVS_Intro_Main) = {
    UseArray(Ref(N(D_8024F380)))
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
    Call(N(InitWorldTintMode))
    Call(N(SetWorldColorParams), 255, 255, 255, 0, 0, 0, 0)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(N(AdjustCamVfov), 0, 62)
    Call(SetPanTarget, CAM_DEFAULT, 0, 157, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings1)))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(N(InitializeStoryGraphicsData))
    Thread
        Wait(2)
        Call(SetCamEnabled, CAM_DEFAULT, FALSE)
    EndThread
    Call(EnableTexPanning, MODEL_o33, FALSE)
    Call(EnableTexPanning, MODEL_o34, FALSE)
    Call(EnableGroup, MODEL_g271, FALSE)
    Call(EnableGroup, MODEL_g272, FALSE)
    Call(EnableGroup, MODEL_g273, FALSE)
    Call(N(InitializeStoryCamera))
    Call(EnableGroup, MODEL_g277, FALSE)
    Call(EnableModel, MODEL_o8, FALSE)
    Exec(N(EVS_Scene_IntroStory))
    Return
    End
};

f32 N(AnimBowser_FlyOff_Time) = 0.0;

API_CALLABLE(N(AnimBowser_FlyOff)) {
    Npc* bowserMain = resolve_npc(script, NPC_Bowser_Body);
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
    if (N(AnimBowser_FlyOff_Time) > (int)(40 * DT)) {
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
    if (N(AnimKammy_FlyOff_Time) > (int)(40 * DT)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80244934_A2EB74)) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        set_screen_overlay_params_back(OVERLAY_VIEWPORT_COLOR, 255.0f);
        set_screen_overlay_color(SCREEN_LAYER_BACK, 250, 250, 250);
        return ApiStatus_BLOCK;
    }
    script->functionTemp[0]++;
    if (script->functionTemp[0] == 10) {
        set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, 0.0f);
        set_screen_overlay_color(SCREEN_LAYER_BACK, 250, 250, 250);
        return ApiStatus_DONE2;
    }
    set_screen_overlay_params_back(OVERLAY_VIEWPORT_COLOR, (10 - script->functionTemp[0]) * 25);
    set_screen_overlay_color(SCREEN_LAYER_BACK, 250, 250, 250);
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_Scene_IntroStory) = {
    Call(SetNpcPaletteSwapMode, NPC_StarRod, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapLower, NPC_StarRod, 0, 1, 20, 5)
    Call(SetNpcPaletteSwapMode, NPC_Eldstar, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Mamar, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Skolar, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Muskular, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Misstar, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Klevar, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Kalmar, NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS)
    Call(SetNpcPaletteSwapping, NPC_Eldstar, 0, 1, 25, 12, 4, 18, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Mamar, 0, 1, 25, 12, 4, 18, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Skolar, 0, 1, 25, 12, 4, 18, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Muskular, 0, 1, 25, 12, 4, 18, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Misstar, 0, 1, 25, 12, 4, 18, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Klevar, 0, 1, 25, 12, 4, 18, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Kalmar, 0, 1, 25, 12, 4, 18, 0, 0)
    Call(SetNpcFlagBits, NPC_StarRod, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarStill)
    Call(SetNpcAnimation, NPC_Bowser_Prop, ANIM_WorldBowser_ClownCarPropeller)
    Call(EnableNpcShadow, NPC_Bowser_Body, FALSE)
    Call(EnableNpcShadow, NPC_Bowser_Prop, FALSE)
    Call(EnableNpcShadow, NPC_StarRod, FALSE)
    Call(EnableNpcShadow, NPC_Eldstar, FALSE)
    Call(EnableNpcShadow, NPC_Mamar, FALSE)
    Call(EnableNpcShadow, NPC_Skolar, FALSE)
    Call(EnableNpcShadow, NPC_Muskular, FALSE)
    Call(EnableNpcShadow, NPC_Misstar, FALSE)
    Call(EnableNpcShadow, NPC_Klevar, FALSE)
    Call(EnableNpcShadow, NPC_Kalmar, FALSE)
    Call(EnableNpcShadow, NPC_Kammy, FALSE)
    Thread
        Call(N(ForceStarRodAlwaysFaceCamera))
    EndThread
    Call(InterpNpcYaw, NPC_Bowser_Body, 90, 0)
    Call(InterpNpcYaw, NPC_Bowser_Prop, 90, 0)
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarTalk)
    Call(SetNpcAnimation, NPC_Bowser_Prop, ANIM_WorldBowser_ClownCarPropeller)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim17)
    Call(InterpNpcYaw, NPC_Kammy, 45, 0)
    Call(SetNpcPos, NPC_Kammy, -145, 147, 84)
    Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Still)
    Call(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
    Call(N(SetWorldColorParams), 130, 130, 130, 0, 0, 0, 15)
    Call(N(AdjustCamVfov), 0, 35)
    Call(SetPanTarget, CAM_DEFAULT, -145, 147, 84)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings6)))
    Call(N(AnimateStorybookPages))
    Wait(50 * DT)
    Call(SetNpcImgFXParams, NPC_Bowser_Body, IMGFX_SET_TINT, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Bowser_Prop, IMGFX_SET_TINT, 0, 0, 0, 0)
    Call(SetNpcPos, NPC_Bowser_Body, -64, 135, 85)
    Call(SetNpcPos, NPC_Bowser_Prop, -64, 135, 85)
    Thread
        Set(LVar0, 0)
        Loop(50 * DT)
            Add(LVar0, 6)
            IfGt(LVar0, 255)
                Set(LVar0, 255)
            EndIf
            Call(SetNpcImgFXParams, NPC_Bowser_Body, IMGFX_SET_TINT, 0, 0, 0, LVar0)
            Call(SetNpcImgFXParams, NPC_Bowser_Prop, IMGFX_SET_TINT, 0, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_Bowser_Prop, 90, 0)
        Set(LVar0, 0)
        Loop(40 * DT)
            Add(LVar0, 36)
            Call(SetNpcRotation, NPC_Bowser_Body, 0, LVar0, 0)
            Wait(1)
        EndLoop
        Call(SetNpcRotation, NPC_Bowser_Body, 0, 0, 0)
        Call(InterpNpcYaw, NPC_Bowser_Body, 90, 0)
    EndThread
    Thread
        Call(N(SetWorldColorParams), 117, 28, 42, 0, 0, 0, 15)
    EndThread
    PlayEffect(EFFECT_LIGHTNING, 1, 0, 20, 0, 0, 0)
    Set(ArrayVar(17), LVarF)
    Thread
        Call(N(FadeAwayTapeGraphic))
    EndThread
    Wait(16 * DT)
    Thread
        Call(N(func_80244934_A2EB74))
    EndThread
    Loop(2)
        Call(N(SetWorldColorParams), 117, 28, 42, 165, 96, 152, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 975, 1000)
        Wait(1)
        Call(N(SetWorldColorParams), 117, 28, 42, 64, 34, 58, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 995, 1000)
        Wait(1)
        Call(N(SetWorldColorParams), 117, 28, 42, 0, 0, 0, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
        Wait(5)
    EndLoop
    Wait(30 * DT)
    Call(SetNpcImgFXParams, NPC_Bowser_Body, IMGFX_SET_TINT, 0, 0, 0, 255)
    Call(SetNpcImgFXParams, NPC_Bowser_Prop, IMGFX_SET_TINT, 0, 0, 0, 255)
    Thread
        Set(LVar0, 0)
        Loop(4)
            Add(LVar0, 70)
            IfGt(LVar0, 255)
                Set(LVar0, 255)
            EndIf
            Call(SetNpcImgFXParams, NPC_Bowser_Body, IMGFX_SET_TINT, LVar0, LVar0, LVar0, 255)
            Call(SetNpcImgFXParams, NPC_Bowser_Prop, IMGFX_SET_TINT, LVar0, LVar0, LVar0, 255)
            Wait(1)
        EndLoop
    EndThread
    Wait(3)
    Call(DismissEffect, ArrayVar(17))
    Thread
        Call(EnableTexPanning, MODEL_o33, TRUE)
        Call(EnableTexPanning, MODEL_o34, TRUE)
        Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Hurt)
        Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Hurt)
        Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
        Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
        Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
        Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
        Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Panic)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
        PlayEffect(EFFECT_ENDING_DECALS, 2, 0, 180, 0, Float(2.59375), ArrayVar(15))
        PlayEffect(EFFECT_LIGHT_RAYS, 1, 0, 200, 0, Float(1.0), ArrayVar(16))
    EndThread
    Thread
        Call(N(AddBowserHoverOffset))
    EndThread
    Thread
        Call(N(AddKammyHoverOffset))
    EndThread
    Wait(50 * DT)
    Call(N(AdjustCamVfov), 0, 40)
    Call(SetPanTarget, CAM_DEFAULT, 0, 157, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings7)))
    Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
    Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
    Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
    Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
    Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Hurt)
    Thread
        Wait(10)
        Set(LVar0, 0)
        Loop(20)
            Add(LVar0, 36)
            Call(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
            Wait(1)
        EndLoop
        Wait(10)
        Set(LVar0, 0)
        Loop(20)
            Add(LVar0, 36)
            Call(SetNpcRotation, NPC_Eldstar, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(10)
        Set(LVar0, 0)
        Loop(20)
            Add(LVar0, 36)
            Call(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(34)
        Set(LVar0, 0)
        Loop(20)
            Add(LVar0, 36)
            Call(SetNpcRotation, NPC_Misstar, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(16)
        Set(LVar0, 0)
        Loop(20)
            Add(LVar0, 36)
            Call(SetNpcRotation, NPC_Klevar, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(28)
        Set(LVar0, 0)
        Loop(20)
            Add(LVar0, 36)
            Call(SetNpcRotation, NPC_Kalmar, 0, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    PlayEffect(EFFECT_LIGHTNING, 2, 0, 0, 0, 0, 0)
    Set(ArrayVar(17), LVarF)
    Set(LVar0, 120)
    Set(LVar1, 895)
    Loop(10)
        Add(LVar0, -12)
        Add(LVar1, 10)
        Call(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        Wait(1)
    EndLoop
    Loop(2)
        Call(N(SetWorldColorParams), 117, 28, 42, 165, 96, 152, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 975, 1000)
        Wait(1)
        Call(N(SetWorldColorParams), 117, 28, 42, 105, 60, 102, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 975, 1000)
        Wait(1)
        Call(N(SetWorldColorParams), 117, 28, 42, 64, 34, 58, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 995, 1000)
        Wait(1)
        Call(N(SetWorldColorParams), 117, 28, 42, 34, 14, 28, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 127, 0, 0, 0, 995, 1000)
        Wait(1)
        Call(N(SetWorldColorParams), 117, 28, 42, 0, 0, 0, 0)
        Call(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
        Wait(5)
    EndLoop
    Wait(27 * DT)
    Call(DismissEffect, ArrayVar(17))
    Call(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, 995, 1000)
    Call(N(AdjustCamVfov), 0, 25)
    Call(SetPanTarget, CAM_DEFAULT, -38, 210, 85)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings8)))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarCloseMouth)
    Call(SetNpcPos, NPC_Bowser_Body, -30, 150, 162)
    Call(SetNpcPos, NPC_Bowser_Prop, -30, 150, 162)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim11)
    Thread
        Call(N(SetWorldColorParams), 23, 10, 10, 0, 0, 0, 15)
        Wait(28)
        Call(N(SetWorldColorParams), 102, 45, 0, 114, 0, 0, 3)
        Call(N(SetWorldColorParams), 102, 45, 0, 0, 0, 0, 13)
        Call(N(SetWorldColorParams), 180, 180, 180, 0, 0, 0, 20)
    EndThread
    Thread
        Set(LVar0, 995)
        Loop(30)
            Sub(LVar0, 10)
            Call(N(SetWorldFogParams), 0, 0, 0, 0, 0, 0, 0, LVar0, 1000)
            Wait(1)
        EndLoop
        Wait(10)
        Set(LVar0, 875)
        Loop(60)
            Add(LVar0, 2)
            Call(N(SetWorldFogParams), 0, 0, 0, 0, 255, 0, 0, LVar0, 1000)
            Wait(1)
        EndLoop
    EndThread
    Set(LVar0, -28)
    Set(LVar1, 210)
    Set(LVar2, 155)
    Set(LVar3, -28)
    Set(LVar4, 209)
    Set(LVar5, 153)
    Call(N(CamPushIn_BowserInhale))
    PlayEffect(EFFECT_FIRE_BREATH, 0, -30, 210, 142, 0, 180, 0, 5, 2, 30)
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarFireBreath)
    Thread
        Call(N(CamPullBack_BowserExhale))
    EndThread
    Wait(20 * DT)
    PlayEffect(EFFECT_SHIMMER_BURST, 0, 0, 180, 0, Float(0.703125), 30)
    Thread
        Wait(2)
        Call(RemoveEffect, ArrayVar(15))
    EndThread
    Wait(20 * DT)
    Call(N(AdjustCamVfov), 0, 25)
    Call(SetPanTarget, CAM_DEFAULT, -38, 210, 85)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings9)))
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarOpenMouth)
    Thread
        Call(N(BowserFlyToStarRod))
    EndThread
    Wait(25 * DT)
    Call(N(AdjustCamVfov), 0, 35)
    Call(SetPanTarget, CAM_DEFAULT, -240, 200, 113)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings10)))
    Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
    Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    Thread
        Wait(5)
        UseBuf(Ref(N(StarSpiritLeapBackScalars)))
        Loop(10)
            FBufRead2(LVarA, LVarB)
            SetF(LVar3, LVar0)
            SetF(LVar4, LVar1)
            SetF(LVar5, LVar2)
            MulF(LVar3, LVarB)
            MulF(LVar4, LVarA)
            MulF(LVar5, LVarB)
            Call(SetNpcPos, NPC_Skolar, LVar3, LVar4, LVar5)
            Wait(1)
        EndLoop
    EndThread
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Thread
        Wait(9)
        UseBuf(Ref(N(StarSpiritLeapBackScalars)))
        Loop(10)
            FBufRead2(LVarA, LVarB)
            SetF(LVar3, LVar0)
            SetF(LVar4, LVar1)
            SetF(LVar5, LVar2)
            MulF(LVar3, LVarB)
            MulF(LVar4, LVarA)
            MulF(LVar5, LVarB)
            Call(SetNpcPos, NPC_Misstar, LVar3, LVar4, LVar5)
            Wait(1)
        EndLoop
    EndThread
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    MulF(LVar0, Float(0.9))
    MulF(LVar1, Float(0.93))
    MulF(LVar2, Float(0.9))
    Call(SetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    MulF(LVar0, Float(0.9))
    MulF(LVar1, Float(0.93))
    MulF(LVar2, Float(0.9))
    Call(SetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Wait(35 * DT)
    Call(N(AdjustCamVfov), 0, 35)
    Call(SetPanTarget, CAM_DEFAULT, 30, 232, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings11)))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarBrandish)
    Call(SetNpcPos, NPC_Bowser_Body, 0, 170, 0)
    Call(SetNpcPos, NPC_Bowser_Prop, 0, 170, 0)
    Call(SetNpcPos, NPC_StarRod, NPC_DISPOSE_LOCATION)
    Thread
        Call(N(SetWorldColorParams), 20, 20, 20, 0, 0, 0, 15)
    EndThread
    Set(LVar0, 21)
    Set(LVar1, 260)
    Set(LVar2, -21)
    Call(N(SetLightRayPos))
    Wait(35 * DT)
    Thread
        Wait(70 * DT)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 12)
            Call(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 0, 0, 995, 1000)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(92 * DT)
        Call(N(SetWorldColorParams), 106, 94, 110, 216, 195, 131, 8)
        Call(N(SetWorldColorParams), 100, 105, 107, 159, 118, 50, 20)
        Call(N(SetWorldColorParams), 122, 180, 110, 0, 0, 0, 15)
        Call(N(SetWorldColorParams), 128, 128, 128, 255, 255, 200, 60)
    EndThread
    Call(N(CamPullBack_BowserHoldingStarRod))
    Call(N(AdjustCamVfov), 0, 35)
    Call(SetPanTarget, CAM_DEFAULT, 0, 177, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings12)))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarStarRod)
    PlayEffect(EFFECT_LIGHT_RAYS, 2, 20, 265, -21, Float(1.0), ArrayVar(18))
    PlayEffect(EFFECT_BULB_GLOW, 2, 20, 265, -21, Float(1.0), ArrayVar(19))
    Set(LVar0, 120)
    Set(LVar1, 895)
    Loop(20)
        Add(LVar0, -6)
        Add(LVar1, 5)
        Call(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        Wait(1)
    EndLoop
    Wait(5)
    Call(N(AdjustCamVfov), 0, 40)
    Call(SetPanTarget, CAM_DEFAULT, 0, 157, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings7)))
    Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Panic)
    Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Panic)
    Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_IdleSad)
    Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Panic)
    Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Panic)
    Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Panic)
    Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Panic)
    Thread
        Wait(5)
        Call(DismissEffect, ArrayVar(18))
        Call(DismissEffect, ArrayVar(19))
    EndThread
    PlayEffect(EFFECT_ENERGY_SHOCKWAVE, 0, 18, 256, -21, Float(0.40625), 60)
    Set(LVar0, 120)
    SetF(LVar1, 895)
    Loop(40)
        Add(LVar0, -3)
        AddF(LVar1, Float(2.5))
        Call(N(SetWorldFogParams), 0, 0, 0, LVar0, 255, 255, 255, LVar1, 1000)
        Wait(1)
    EndLoop
    Call(N(AdjustCamVfov), 0, 35)
    Call(SetPanTarget, CAM_DEFAULT, 70, 200, -239)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings5)))
    Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Hurt)
    Call(SetNpcAnimation, NPC_Mamar, ANIM_WorldMamar_Hurt)
    Call(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Hurt)
    Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Hurt)
    Call(SetNpcAnimation, NPC_Misstar, ANIM_WorldMisstar_Hurt)
    Call(SetNpcAnimation, NPC_Klevar, ANIM_WorldKlevar_Hurt)
    Call(SetNpcAnimation, NPC_Kalmar, ANIM_WorldKalmar_Hurt)
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_AURA, FX_AURA_CAPTURE, LVar0, LVar1, LVar2, 1, ArrayVar(1))
    Call(GetNpcPos, NPC_Mamar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_AURA, FX_AURA_CAPTURE, LVar0, LVar1, LVar2, 1, ArrayVar(2))
    Call(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_AURA, FX_AURA_CAPTURE, LVar0, LVar1, LVar2, 1, ArrayVar(3))
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_AURA, FX_AURA_CAPTURE, LVar0, LVar1, LVar2, 1, ArrayVar(4))
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_AURA, FX_AURA_CAPTURE, LVar0, LVar1, LVar2, 1, ArrayVar(5))
    Call(GetNpcPos, NPC_Klevar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_AURA, FX_AURA_CAPTURE, LVar0, LVar1, LVar2, 1, ArrayVar(6))
    Call(GetNpcPos, NPC_Kalmar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_AURA, FX_AURA_CAPTURE, LVar0, LVar1, LVar2, 1, ArrayVar(7))
    Call(N(SetWorldColorParams), 110, 110, 110, 255, 255, 255, 0)
    Thread
        Call(N(SetWorldColorParams), 230, 230, 230, 0, 0, 0, 30)
    EndThread
    Thread
        Wait(28)
        Call(SetNpcImgFXParams, NPC_Eldstar, IMGFX_SET_ANIM, IMGFX_ANIM_SPIRIT_CAPTURE, 1, 1, 0)
    EndThread
    Set(LVar0, 255)
    Loop(20)
        Call(SetNpcImgFXParams, NPC_Mamar,    IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Skolar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Muskular, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Misstar,  IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Klevar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_Kalmar,   IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Wait(15 * DT)
    Call(SetNpcImgFXParams, NPC_Eldstar, IMGFX_SET_ALPHA, 255, 0, 0, 0)
    PlayEffect(EFFECT_SOMETHING_ROTATING, 2, -130, 220, 130, 1, 0)
    Set(ArrayVar(0), LVarF)
    Set(LVar0, -130)
    Set(LVar1, 220)
    Set(LVar2, 130)
    AddF(LVar1, Float(-30.0))
    Call(SetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    Exec(N(EVS_UpdateWorldFogParams))
    Call(DismissEffect, ArrayVar(1))
    Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_RING_BLAST, 1, LVar0, LVar1, LVar2, 4, 20)
    Thread
        Wait(3)
        Call(GetNpcPos, NPC_Eldstar, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_MISC_PARTICLES, 3, LVar0, LVar1, LVar2, 16, 16, 2, 20, 0)
        Set(ArrayVar(8), LVarF)
        Call(func_802428C8_A2CB08, 1, 30, Float(0.5))
        Call(LoadPath, LVar0, LVar1, LVar2, EASING_LINEAR)
        SetF(LVar4, Float(1.0))
        Label(1)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Eldstar, LVar1, LVar2, LVar3)
        Call(N(SetStarSpiritSparkleTrailPos), ArrayVar(8), ArrayVar(19), LVar1, LVar2, LVar3)
        AddF(LVar4, Float(-0.03125))
        Call(SetNpcScale, NPC_Eldstar, LVar4, LVar4, LVar4)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(1)
        EndIf
        Call(N(SetCardCaptureState1))
        Call(SetNpcAnimation, NPC_Eldstar, ANIM_WorldEldstar_Panic)
        Call(SetNpcImgFXParams, NPC_Eldstar, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetNpcFlagBits, NPC_Eldstar, NPC_FLAG_INVISIBLE, TRUE)
        Call(DismissEffect, ArrayVar(8))
    EndThread
    Wait(15 * DT)
    Call(N(AdjustCamVfov), 0, 50)
    Call(SetPanTarget, CAM_DEFAULT, 40, 200, -40)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings13)))
    Call(RemoveEffect, ArrayVar(16))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarIdle)
    Thread
        Wait(45)
        Call(NpcFaceNpc, NPC_Bowser_Body, NPC_Eldstar, 0)
    EndThread
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim12)
    Exec(N(EVS_CaptureSpirits))
    Call(N(CamPanAcrossRoom))
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim09)
    Thread
        Wait(10)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim12)
        Wait(20)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0D)
        Wait(40)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim09)
    EndThread
    Call(N(CamMove_OrbitKammy))
    Call(N(AdjustCamVfov), 0, 50)
    Call(SetPanTarget, CAM_DEFAULT, 0, 200, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(IntroCamSettings15)))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarLaugh)
    Thread
        Call(N(CamPullBack_Final))
    EndThread
    Wait(20 * DT)
    Thread
        Call(func_80244550_A2E790)
    EndThread
    Wait(1)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0B)
    Call(N(KammyFlyToBowser))
    Thread
        Call(N(SetCardCaptureState3))
        Call(N(SetCardCaptureState3))
        Call(N(SetCardCaptureState3))
        Call(N(SetCardCaptureState3))
        Call(N(SetCardCaptureState3))
        Call(N(SetCardCaptureState3))
        Call(N(SetCardCaptureState3))
    EndThread
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0D)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim11)
    Wait(32 * DT)
    Call(SetNpcJumpscale, NPC_Eldstar, Float(0.0))
    Call(SetNpcJumpscale, NPC_Mamar, Float(0.0))
    Call(SetNpcJumpscale, NPC_Skolar, Float(0.0))
    Call(SetNpcJumpscale, NPC_Muskular, Float(0.0))
    Call(SetNpcJumpscale, NPC_Misstar, Float(0.0))
    Call(SetNpcJumpscale, NPC_Klevar, Float(0.0))
    Call(SetNpcJumpscale, NPC_Kalmar, Float(0.0))
    Call(SetNpcAnimation, NPC_Bowser_Body, ANIM_WorldBowser_ClownCarStill)
    Thread
        Call(N(AnimBowser_FlyOff))
    EndThread
    Wait(10 * DT)
    Call(N(AnimKammy_FlyOff))
    Wait(20 * DT)
    Call(N(ResumeIntro))
    Return
    End
};
