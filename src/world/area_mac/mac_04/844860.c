#include "mac_04.h"

void func_80241D30_844900(void);
void func_80241DAC_84497C(void*);

ApiStatus func_80241C90_844860(Evt* script, s32 isInitialCall) {
    gPlayerStatus.animFlags |= PA_FLAGS_IN_DISGUISE;
    evt_set_variable(script, MapVar(11), create_generic_entity_world(NULL, func_80241D30_844900));

    return ApiStatus_DONE2;
}

ApiStatus func_80241CEC_8448BC(Evt* script, s32 isInitialCall) {
    s32 index = evt_get_variable(script, MapVar(11));
    gPlayerStatus.animFlags &= ~PA_FLAGS_IN_DISGUISE;
    free_generic_entity(index);

    return ApiStatus_DONE2;
}

void func_80241D30_844900(void) {
    RenderTask renderTask;
    s32 screenX, screenY, screenZ;

    get_screen_coords(gCurrentCamID, gPlayerStatus.position.x, gPlayerStatus.position.y, gPlayerStatus.position.z, &screenX, &screenY, &screenZ);

    renderTask.appendGfxArg = &gPlayerStatus;
    renderTask.appendGfx = func_80241DAC_84497C;
    renderTask.renderMode = gPlayerStatus.renderMode;
    renderTask.distance = screenZ;

    queue_render_task(&renderTask);
}

// problem with asm file improperly including strings "omo_03" and "kmr_22"
#ifdef NON_MATCHING
void func_80241DAC_84497C(PlayerStatus* playerStatus) {
    f32 scale = evt_get_float_variable(NULL, MapVar(10));
    f32 scale_2;
    Matrix4f transformMtx;
    Matrix4f tempMtx;
    
    guRotateF(transformMtx, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    scale_2 = (f32) ((f64) scale * SPRITE_WORLD_SCALE_D);
    guScaleF(tempMtx, scale_2, scale_2, scale_2);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    guTranslateF(tempMtx, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
    guMtxCatF(transformMtx, tempMtx, transformMtx);
    playerStatus->unk_BC = spr_update_player_sprite(0, playerStatus->trueAnimation, 1.0f);
    spr_draw_player_sprite(0, 0, 0, NULL, transformMtx);
}
#else
INCLUDE_ASM(s32, "world/area_mac/mac_04/844860", func_80241DAC_84497C);
#endif

#include "world/common/SetEntityFlags100000.inc.c"
