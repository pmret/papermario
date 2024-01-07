#include "iwa_01.h"
#include "include_asset.h"

INCLUDE_IMG("world/area_iwa/iwa_01/splash.png", iwa_01_splash_img);
#include "world/area_iwa/iwa_01/splash.vtx.inc.c"
#include "world/area_iwa/iwa_01/splash.gfx.inc.c"

#define NUM_SPLASHES (20)

typedef struct SplashState {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ Vec3f vel;
} SplashState; // size = 0x28

void N(gfx_build_splashes)(s32 index) {
    s32 i;
    s32 alpha;
    SplashState* splash = (SplashState*)evt_get_variable(NULL, MV_SplashState);

    for (i = 0; i < NUM_SPLASHES; i++, splash++) {
        if (splash->pos.y < -30.0f) {
            splash->pos.x = 0.0f;
            splash->pos.y = 5.0f;
            splash->pos.z = -20.0f;

            splash->vel.x = (rand_int(8) - 4) / 10.0f;
            splash->vel.y = rand_int(10) / 10.0f;
            splash->vel.z = (rand_int(10) + 30) / 10.0f;

            splash->scale = 1.0f;

            splash->rot.x = rand_int(20) + 80;
            splash->rot.y = rand_int(359);
            splash->rot.z = 0;
        }

        splash->vel.x *= 0.98;
        splash->vel.y += -0.1;
        splash->vel.z *= 0.98;

        splash->pos.x += splash->vel.x;
        splash->pos.y += splash->vel.y;
        splash->pos.z += splash->vel.z;

        splash->rot.x += 2.0f;

        alpha = splash->pos.y * 255.0f / -30.0f;
        if (alpha < 0) {
            alpha = 0;
        }
        if (alpha > 255) {
            alpha = 255;
        }

        gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 255, 255, 255);
        gDPSetBlendColor(gMainGfxPos++, 0, 0, 0, alpha);
        guPosition(&gDisplayContext->matrixStack[gMatrixListPos],
                   splash->rot.x, splash->rot.y, splash->rot.z,
                   splash->scale,
                   splash->pos.x, splash->pos.y, splash->pos.z);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, N(splash_gfx));
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
    gDPPipeSync(gMainGfxPos++);
}

API_CALLABLE(N(InitSplashes)) {
    SplashState* splash = heap_malloc(NUM_SPLASHES * sizeof(*splash));
    s32 i;

    evt_set_variable(NULL, MV_SplashState, (s32)splash);

    for (i = 0; i < NUM_SPLASHES; i++, splash++) {
        splash->pos.x = 0.0f;
        splash->pos.y = -i * 30 / NUM_SPLASHES;
        splash->pos.z = 0.0f;

        splash->vel.x = 0.0f;
        splash->vel.y = rand_int(10) / 10.0f - (f32)i * 0.1;
        splash->vel.z = 0.0f;

        splash->scale = 1.0f;

        splash->rot.x = rand_int(359);
        splash->rot.y = rand_int(359);
        splash->rot.z = rand_int(359);
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_MakeSplashes) = {
    EVT_CALL(N(InitSplashes))
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, 0, EVT_PTR(N(gfx_build_splashes)))
    EVT_CALL(SetModelCustomGfx, MODEL_dummy_sprash2, CUSTOM_GFX_0, -1)
    EVT_RETURN
    EVT_END
};
