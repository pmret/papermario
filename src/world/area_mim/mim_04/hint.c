#include "mim_04.h"

enum {
    EVIL_TREE_HIDDEN    = 0,
    EVIL_TREE_BEGIN     = 1,
    EVIL_TREE_FADE_IN   = 2,
    EVIL_TREE_VISIBLE   = 3,
    EVIL_TREE_FADE_OUT  = 4,
};

s32 N(EvilTreeState) = EVIL_TREE_HIDDEN;
s32 N(EvilTreeVisibleTime) = 0;
s32 N(EvilTreeFaceAlpha) = 0;

void N(gfx_build_evil_tree_face)(s32 index) {
    switch (N(EvilTreeState)) {
        case EVIL_TREE_BEGIN:
            N(EvilTreeFaceAlpha) = 0;
            N(EvilTreeState) = EVIL_TREE_FADE_IN;
            break;
        case EVIL_TREE_FADE_IN:
            N(EvilTreeFaceAlpha) += 10;
            if (N(EvilTreeFaceAlpha) >= 256) {
                N(EvilTreeFaceAlpha) = 255;
                N(EvilTreeVisibleTime) = 20;
                N(EvilTreeState) = EVIL_TREE_VISIBLE;
            }
            break;
        case EVIL_TREE_VISIBLE:
            N(EvilTreeVisibleTime)--;
            if (N(EvilTreeVisibleTime) < 0) {
                N(EvilTreeVisibleTime) = 0;
                N(EvilTreeState) = EVIL_TREE_FADE_OUT;
            }
            break;
        case EVIL_TREE_FADE_OUT:
            N(EvilTreeFaceAlpha) -= 10;
            if (N(EvilTreeFaceAlpha) < 0) {
                N(EvilTreeFaceAlpha) = 0;
                N(EvilTreeState) = EVIL_TREE_HIDDEN;
            }
            break;
    }

    gDPSetCycleType(gMainGfxPos++, G_CYC_2CYCLE);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(EvilTreeFaceAlpha));
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_06);
    gDPSetRenderMode(gMainGfxPos++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2);
}

API_CALLABLE(N(TryEvilTreeLaugh)) {
    if (N(EvilTreeState) == EVIL_TREE_HIDDEN) {
        N(EvilTreeState) = EVIL_TREE_BEGIN;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ManageEvilTree) = {
    Label(0)
        Call(AwaitPlayerApproach, 0, -340, 50)
        Call(AwaitPlayerLeave, 0, -340, 50)
        Call(N(TryEvilTreeLaugh))
        Call(PlaySoundAt, SOUND_TREE_LAUGHTER, SOUND_SPACE_DEFAULT, 55, 96, -254)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupExitHint) = {
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(gfx_build_evil_tree_face)), NULL)
    Call(SetModelCustomGfx, MODEL_kao, CUSTOM_GFX_1, -1)
    Call(SetModelFlags, MODEL_kao, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
    Wait(20)
    Exec(N(EVS_ManageEvilTree))
    Thread
        Call(SetTexPanner, MODEL_kao, TEX_PANNER_0)
        Label(0)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
        Wait(2)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
        Wait(3)
        Goto(0)
    EndThread
    Return
    End
};
