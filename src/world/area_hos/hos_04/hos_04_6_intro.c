#include "hos_04.h"
#include "nu/nusys.h"

Vec3f N(TwinkFlightPath)[] = {
    { -669.0,    98.0,  -34.0 },
    { -669.0,    68.0,  -34.0 },
    { -644.0,    14.0,  -23.0 },
    { -564.0,     8.0,   40.0 },
    { -324.0,   136.0,  175.0 },
    {  -38.0,   118.0,    0.0 },
    {  205.0,   111.0,    0.0 },
    {  305.0,   101.0,    0.0 },
};

s32 N(Unused) = 0;

CameraControlSettings N(CamSettings_PreHeist) = {
    .type = CAMERA_SETTINGS_TYPE_0,
    .boomLength = 700,
    .boomPitch = -0.9,
    .posA = { 0.0,   -1.0, 0.0 },
    .posB = { 500.0, -1.0, 0.0 },
    .viewPitch = -17.4,
    .flag = FALSE,
};

CameraControlSettings N(CamSettings_PostHeist) = {
    .type = CAMERA_SETTINGS_TYPE_0,
    .boomLength = 665,
    .boomPitch = -0.9,
    .posA = { 0.0,   -1.0, 0.0 },
    .posB = { 500.0, -1.0, 0.0 },
    .viewPitch = -17.4,
    .flag = FALSE,
};

API_CALLABLE(N(SetCamVfov)) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ResumeIntroState)) {
    if (
        gGameStatusPtr->creditsViewportMode == 0 ||
        gGameStatusPtr->creditsViewportMode == 1 ||
        gGameStatusPtr->creditsViewportMode == 2 ||
        gGameStatusPtr->creditsViewportMode == 3 ||
        gGameStatusPtr->creditsViewportMode == 4)
    {
        gGameStatusPtr->creditsViewportMode++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

API_CALLABLE(N(BlockForever)) {
    return ApiStatus_BLOCK;
}

void N(lerp_value_with_max_step)(f32 start, f32 end, f32 current, f32 maximum, f32* out) {
    f32 remaining = end - current;

    if (end - start > 0.0f) {
        if (remaining < 0.0f) {
            *out = end;
        } else if (maximum < remaining) {
            *out += maximum;
        } else {
            *out += remaining;
        }
    } else if (remaining > 0.0f) {
        *out = end;
    } else if (remaining < -maximum) {
        *out -= maximum;
    } else {
        *out += remaining;
    }
}

void N(interp_value_with_easing)(s32 easingMode, f32 start, f32 end, f32 curent, f32 max, f32* out) {
    f32 alpha;

    if (curent > max) {
        curent = max;
    }

    switch (easingMode) {
        case 1:
            alpha = sin_deg((curent / max) * 90.0f);
            break;
        case 2:
            if (curent < 30.0f) {
                alpha = 0.0f;
            } else {
                alpha = sin_deg((((curent - 30.0f) / (max - 30.0f)) * 90.0f) + -90.0f) + 1.0f;
            }
            break;
        case 3:
            alpha = (sin_deg(((curent / max) * 180.0f) - 90.0f) + 1.0f) * 0.5;
            break;
        case 4:
            alpha = sin_deg(((curent / max) * 90.0f) - 90.0f) + 1.0f;
            break;
        case 5:
            alpha = (2.0 * (sin_deg(((curent / max) * 60.0f) - 60.0f) + 0.8660254f)) / 1.7320507764816284;
            break;
        default:
            alpha = curent / max;
            break;
    }
    *out = start + ((end - start) * alpha);
}

f32 N(TargetBoomLengthPre) = 700;
u16* N(ColorBufferPtr) = NULL;

API_CALLABLE(N(AnimateBoomLengthPreHeist)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == N(ColorBufferPtr)) {
        return ApiStatus_BLOCK;
    }

    N(ColorBufferPtr) = nuGfxCfb_ptr;
    N(lerp_value_with_max_step)(700.0f, 300.0f, N(TargetBoomLengthPre), 1.2f, &N(TargetBoomLengthPre));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(TargetBoomLengthPre);
    return ApiStatus_BLOCK;
}

s32 N(TargetBoomLengthPost) = 0;
BSS f32 N(CurrentBoomLengthPost);

API_CALLABLE(N(AnimateBoomLengthPostHeist)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        N(CurrentBoomLengthPost) = N(CamSettings_PostHeist).boomLength;
    }
    N(interp_value_with_easing)(1, N(CamSettings_PostHeist).boomLength, 700.0f, N(TargetBoomLengthPost), 70.0f, &N(CurrentBoomLengthPost));
    camera->panActive = TRUE;
    camera->controlSettings.boomLength = N(CurrentBoomLengthPost);
    N(TargetBoomLengthPost)++;
    if (N(TargetBoomLengthPost) < 70) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE1;
}

s32 N(TargetViewPitch) = 0;
BSS f32 N(CurrentViewPitch);

API_CALLABLE(N(AnimateViewPitchPostHeist)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (isInitialCall) {
        N(CurrentViewPitch) = N(CamSettings_PostHeist).viewPitch;
    }
    N(interp_value_with_easing)(5, N(CamSettings_PostHeist).viewPitch, -80.0f, N(TargetViewPitch), 200.0f, &N(CurrentViewPitch));
    camera->panActive = TRUE;
    camera->controlSettings.viewPitch = N(CurrentViewPitch);
    N(TargetViewPitch)++;
    if (N(TargetViewPitch) == 200) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

extern EvtScript N(EVS_ControlTwink);

EvtScript N(EVS_Intro_PostHeist) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(N(SetCamVfov), CAM_DEFAULT, 75)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 30, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(CamSettings_PostHeist)))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_THREAD
        EVT_EXEC(N(EVS_ControlTwink))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ControlTwink) = {
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
    EVT_CALL(SetNpcYaw, NPC_Twink, 180)
    EVT_CALL(N(AnimateBoomLengthPostHeist))
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_Twink, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Still)
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_Twink, 180, 0)
        EVT_WAIT(2)
        EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(100)
        EVT_CALL(N(AnimateViewPitchPostHeist))
    EVT_END_THREAD
    EVT_CALL(LoadPath, 200, EVT_PTR(N(TwinkFlightPath)), ARRAY_COUNT(N(TwinkFlightPath)), EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    EVT_THREAD
        EVT_WAIT(85)
        EVT_CALL(N(BlockForever))
    EVT_END_THREAD
    EVT_WAIT(120)
    EVT_CALL(N(ResumeIntroState))
    EVT_RETURN
    EVT_END
};

// establishing shot of the star shrine; camera slowly moves along the path toward it
EvtScript N(EVS_Intro_PreHeist_Unused) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(N(SetCamVfov), CAM_DEFAULT, 75)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 30, 0)
    EVT_CALL(LoadSettings, CAM_DEFAULT, EVT_PTR(N(CamSettings_PreHeist)))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_THREAD
        EVT_CALL(N(AnimateBoomLengthPreHeist))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(300)
        EVT_CALL(N(ResumeIntroState))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcInit_Twink) = {
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Twink) = {
    .id = NPC_Twink,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Twink),
    .drops = NPC_NO_DROPS,
    .animations = TWINK_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Twink)),
    {}
};
