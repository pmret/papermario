#include "mim_07.h"

API_CALLABLE(N(ResetForeverForestFog)) {
    enable_world_fog();
    set_world_fog_dist(990, 1000);
    set_world_fog_color(0, 0, 0, 255);

    enable_entity_fog();
    set_entity_fog_dist(990, 1000);
    set_entity_fog_color(0, 0, 0, 255);

    return ApiStatus_DONE2;
}

enum {
    EVIL_ROCK_HIDDEN    = 0,
    EVIL_ROCK_BEGIN     = 1,
    EVIL_ROCK_FADE_IN   = 2,
    EVIL_ROCK_VISIBLE   = 3,
    EVIL_ROCK_FADE_OUT  = 4,
};

s32 N(EvilRockState) = EVIL_ROCK_HIDDEN;
s32 N(EvilRockVisibleTime) = 0;
s32 N(EvilRockAlpha) = 0;

void N(gfx_build_evil_rock_face)(s32 index) {
    switch (N(EvilRockState)) {
        case EVIL_ROCK_BEGIN:
            N(EvilRockAlpha) = 0;
            N(EvilRockState) = EVIL_ROCK_FADE_IN;
            break;
        case EVIL_ROCK_FADE_IN:
            N(EvilRockAlpha) += 10;
            if (N(EvilRockAlpha) > 255) {
                N(EvilRockAlpha) = 255;
                N(EvilRockVisibleTime) = 50;
                N(EvilRockState) = EVIL_ROCK_VISIBLE;
            }
            break;
        case EVIL_ROCK_VISIBLE:
            N(EvilRockVisibleTime)--;
            if (N(EvilRockVisibleTime) < 0) {
                N(EvilRockVisibleTime) = 0;
                N(EvilRockState) = EVIL_ROCK_FADE_OUT;
            }
            break;
        case EVIL_ROCK_FADE_OUT:
            N(EvilRockAlpha) -= 7;
            if (N(EvilRockAlpha) < 0) {
                N(EvilRockAlpha) = 0;
                N(EvilRockState) = EVIL_ROCK_HIDDEN;
            }
            break;
    }

    gDPSetCycleType(gMainGfxPos++, G_CYC_2CYCLE);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(EvilRockAlpha));
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_06);
    gDPSetRenderMode(gMainGfxPos++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2);
}

API_CALLABLE(N(TryEvilRockLaugh)) {
    if (N(EvilRockState) == EVIL_ROCK_HIDDEN) {
        N(EvilRockState) = EVIL_ROCK_BEGIN;
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ManageEvilRock) = {
    Label(0)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
        Wait(3)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
        Wait(3)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_OnInspectEvilRock) = {
    Set(LVar0, 0)
    Call(N(TryEvilRockLaugh))
    IfEq(LVar0, 1)
        Wait(10)
        ExecGetTID(N(EVS_ManageEvilRock), LVar9)
        Call(PlaySoundAt, SOUND_ROCK_LAUGHTER, SOUND_SPACE_DEFAULT, -34, 0, -300)
        Loop(18)
            Call(TranslateModel, MODEL_o289, Float(1.0), 0, Float(1.0))
            Call(TranslateModel, MODEL_o440, Float(1.0), 0, Float(1.0))
            Wait(2)
            Call(TranslateModel, MODEL_o289, Float(-1.0), 0, Float(-1.0))
            Call(TranslateModel, MODEL_o440, Float(-1.0), 0, Float(-1.0))
            Wait(2)
        EndLoop
        Loop(10)
            Call(TranslateModel, MODEL_o289, Float(0.5), 0, Float(0.5))
            Call(TranslateModel, MODEL_o440, Float(0.5), 0, Float(0.5))
            Wait(2)
            Call(TranslateModel, MODEL_o289, Float(-0.5), 0, Float(-0.5))
            Call(TranslateModel, MODEL_o440, Float(-0.5), 0, Float(-0.5))
            Wait(2)
        EndLoop
        KillThread(LVar9)
        Call(TranslateModel, MODEL_o289, 0, 0, 0)
        Call(TranslateModel, MODEL_o440, 0, 0, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupExitHint) = {
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(gfx_build_evil_rock_face)), nullptr)
    Call(SetModelCustomGfx, MODEL_o440, CUSTOM_GFX_1, -1)
    Call(SetModelFlags, MODEL_o440, MODEL_FLAG_USES_CUSTOM_GFX, true)
    BindTrigger(Ref(N(EVS_OnInspectEvilRock)), TRIGGER_WALL_PRESS_A, COLLIDER_o491, 1, 0)
    Call(SetTexPanner, MODEL_o440, TEX_PANNER_0)
    Return
    End
};
