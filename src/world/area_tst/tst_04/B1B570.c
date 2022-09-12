#include "tst_04.h"
#include "sprite.h"
#include "model.h"

static char* N(exit_str_0) = "tst_03";
static char* N(exit_str_1) = "";

void func_8024029C_B1B80C(void);
void func_80240360_B1B8D0(void* data);
void func_80240574_B1BAE4(void);

// BSS
static s32 B_80240FD0_tst_04;

ApiStatus func_80240000_B1B570(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(0);

    if (npc != NULL && npc->currentFloor == 5) {
        f32 sinTheta;
        f32 cosTheta;
        f32 xTemp;
        f32 zTemp;

        dist2D(npc->pos.x, npc->pos.z, 0.0f, -100.0f);
        sinTheta = sin_rad(1 / 180.0f * PI_S);
        cosTheta = cos_rad(1 / 180.0f * PI_S);
        xTemp = npc->pos.x - 0.0f;
        zTemp = npc->pos.z - -100.0f;
        npc->pos.x = npc->pos.x + (((cosTheta * xTemp) + (sinTheta * zTemp)) - xTemp);
        npc->pos.z = npc->pos.z + (((-sinTheta * xTemp) + (cosTheta * zTemp)) - zTemp);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802400FC_B1B66C(Evt *script, s32 isInitialCall)
{
    Npc *npc = get_npc_safe(NPC_PARTNER);
    f32 angle, sinAngle, cosAngle;
    f32 dist;
    f32 x0, x1;
    f32 z0, z1;
    
    if (npc == NULL) {
        return ApiStatus_DONE2;
    }
    
    dist = dist2D(npc->pos.x, npc->pos.z, -250.0f, -100.0f);
    
    angle = evt_get_variable(script, LVar0) - 1;
    sinAngle = sin_rad((angle * TAU) / 360.0f);
    cosAngle = cos_rad((angle * TAU) / 360.0f);
    x0 = dist * cosAngle;
    z0 = dist * -sinAngle;
    
    angle = evt_get_variable(script, LVar0);
    sinAngle = sin_rad((angle * TAU) / 360.0f);
    cosAngle = cos_rad((angle * TAU) / 360.0f);
    x1 = dist * cosAngle;
    z1 = dist * -sinAngle;
    
    npc->pos.x += x1 - x0;
    npc->pos.z += z1 - z0;
    
    return ApiStatus_DONE2;
}

ApiStatus func_80240260_B1B7D0(Evt* script, s32 isInitialCall) {
    script->array[0] = (s32) create_generic_entity_frontUI(NULL, func_8024029C_B1B80C);
    return ApiStatus_DONE2;
}

void func_8024029C_B1B80C(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    if (playerStatus->flags & 1) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= MODEL_FLAGS_FLAG_200;

        get_screen_coords(gCurrentCamID, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        renderTaskPtr->renderMode = playerStatus->renderMode;
        renderTaskPtr->appendGfxArg = playerStatus;
        renderTaskPtr->appendGfx = func_80240360_B1B8D0;
        renderTaskPtr->distance = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

void func_80240360_B1B8D0(void* data) {
    PlayerStatus* playerStatus = data;
    f32 yaw = -gCameras[gCurrentCamID].currentYaw;
    Matrix4f main;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;

    guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(main, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
    guMtxCatF(rotation, main, main);
    guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guScaleF(scale, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
    guMtxCatF(main, scale, main);
    guTranslateF(translation, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z);
    guMtxCatF(main, translation, main);
    spr_update_player_sprite(1, playerStatus->trueAnimation, 1.0f);
    spr_draw_player_sprite(1, 0, 0, NULL, main);
}

ApiStatus func_80240510_B1BA80(Evt* script, s32 isInitialCall) {
    Npc* partner;

    script->array[1] = create_generic_entity_world(func_80240574_B1BAE4, NULL);
    partner = get_npc_safe(NPC_PARTNER);

    if (partner == NULL) {
        return ApiStatus_DONE2;
    }

    partner->flags |= 0x20000;
    partner->flags |= 0x80000;
    return ApiStatus_DONE2;
}

void func_80240574_B1BAE4(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0x20000;
        partner->flags |= 0x80000;
    }
}

void func_802405B0_B1BB20(void) {
    update_model_animator(B_80240FD0_tst_04);
}

void func_802405D4_B1BB44(void) {
    Matrix4f m0;
    Matrix4f m1;
    Matrix4f m2;
    Matrix4f m3;
    Mtx m4;

    guTranslateF(m1, -484.0f, 25.0f, -40.0f);
    guMtxF2L(m1, &m4);
    render_animated_model(B_80240FD0_tst_04, &m4);
}

ApiStatus func_80240628_B1BB98(Evt* script, s32 isInitialCall) {
    create_generic_entity_world(func_802405B0_B1BB20, func_802405D4_B1BB44);
    return ApiStatus_DONE2;
}
