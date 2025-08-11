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
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 700,
    .boomPitch = -0.9,
    .points = { .two = { 0.0, -1.0, 0.0, 500.0, -1.0, 0.0 }},
    .viewPitch = -17.4,
    .flag = false,
};

CameraControlSettings N(CamSettings_PostHeist) = {
    .type = CAM_CONTROL_FIXED_ORIENTATION,
    .boomLength = 665,
    .boomPitch = -0.9,
    .points = { .two = { 0.0, -1.0, 0.0, 500.0, -1.0, 0.0 }},
    .viewPitch = -17.4,
    .flag = false,
};

API_CALLABLE(N(SetCamVfov)) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ResumeIntroState)) {
    if (gGameStatusPtr->introPart > INTRO_PART_NONE && gGameStatusPtr->introPart < INTRO_PART_5) {
        gGameStatusPtr->introPart++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

API_CALLABLE(N(BlockForever)) {
    return ApiStatus_BLOCK;
}

#define INTRO_MATH_EXTENDED
#include "../common/IntroMathUtil.inc.c"

f32 N(TargetBoomLengthPre) = 700;
u16* N(ColorBufferPtr) = nullptr;

API_CALLABLE(N(AnimateBoomLengthPreHeist)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (nuGfxCfb_ptr == N(ColorBufferPtr)) {
        return ApiStatus_BLOCK;
    }

    N(ColorBufferPtr) = nuGfxCfb_ptr;
    N(lerp_value_with_max_step)(700.0f, 300.0f, N(TargetBoomLengthPre), 1.2f, &N(TargetBoomLengthPre));
    camera->panActive = true;
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
    N(interp_value_with_easing)(INTRO_MATH_EASING_SIN_OUT, N(CamSettings_PostHeist).boomLength, 700.0f,
        N(TargetBoomLengthPost), 70.0f, &N(CurrentBoomLengthPost));
    camera->panActive = true;
    camera->controlSettings.boomLength = N(CurrentBoomLengthPost);
    N(TargetBoomLengthPost)++;
    if (N(TargetBoomLengthPost) < (s32)(70 * DT)) {
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
    N(interp_value_with_easing)(INTRO_MATH_EASING_5, N(CamSettings_PostHeist).viewPitch, -80.0f,
        N(TargetViewPitch), 200.0f, &N(CurrentViewPitch));
    camera->panActive = true;
    camera->controlSettings.viewPitch = N(CurrentViewPitch);
    N(TargetViewPitch)++;
    if (N(TargetViewPitch) == (s32)(200 * DT)) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

extern EvtScript N(EVS_ControlTwink);

EvtScript N(EVS_Intro_PostHeist) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    Call(N(SetCamVfov), CAM_DEFAULT, 75)
    Call(SetPanTarget, CAM_DEFAULT, 0, 30, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(CamSettings_PostHeist)))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Thread
        Exec(N(EVS_ControlTwink))
    EndThread
    Return
    End
};

EvtScript N(EVS_ControlTwink) = {
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
    Call(SetNpcYaw, NPC_Twink, 180)
    Call(N(AnimateBoomLengthPostHeist))
#if VERSION_JP
    Wait(30 * DT)
#else
    Wait(15 * DT)
#endif
    Thread
        Wait(10 * DT)
        Call(InterpNpcYaw, NPC_Twink, 0, 0)
        Wait(2)
        Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Still)
        Wait(20 * DT)
        Call(InterpNpcYaw, NPC_Twink, 180, 0)
        Wait(2)
        Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
    EndThread
    Thread
        Wait(100 * DT)
        Call(N(AnimateViewPitchPostHeist))
    EndThread
    Call(LoadPath, 200 * DT, Ref(N(TwinkFlightPath)), ARRAY_COUNT(N(TwinkFlightPath)), EASING_LINEAR)
    Label(0)
    Call(GetNextPathPos)
    Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Call(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    Thread
        Wait(85 * DT)
        Call(N(BlockForever))
    EndThread
    Wait(120 * DT)
    Call(N(ResumeIntroState))
    Return
    End
};

// establishing shot of the star shrine; camera slowly moves along the path toward it
EvtScript N(EVS_Intro_PreHeist_Unused) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    Call(N(SetCamVfov), CAM_DEFAULT, 75)
    Call(SetPanTarget, CAM_DEFAULT, 0, 30, 0)
    Call(LoadSettings, CAM_DEFAULT, Ref(N(CamSettings_PreHeist)))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Thread
        Call(N(AnimateBoomLengthPreHeist))
    EndThread
    Thread
        Wait(300)
        Call(N(ResumeIntroState))
    EndThread
    Return
    End
};

// TODO: this has moved to starship.c in JP. This is a possible indication that
// file spitting in other versions might be off.
#if !VERSION_JP
#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Twink.h"

EvtScript N(EVS_NpcInit_Twink) = {
    Return
    End
};

NpcData N(NpcData_Twink) = {
    .id = NPC_Twink,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Twink),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = TWINK_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Twink)),
    {}
};
#endif
