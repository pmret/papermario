#include "tst_11.h"

void func_8024003C_B1CA8C(void);
void func_80240100_B1CB50(PlayerStatus*);
void func_802402F4_B1CD44(void);
void func_802403B8_B1CE08(RenderTask*);
void N(SetPartnerFlagsA0000)(void);

ApiStatus func_80240000_B1CA50(ScriptInstance* script, s32 isInitialCall) {
    script->array[0] = (s32) create_generic_entity_frontUI(NULL, func_8024003C_B1CA8C);
    return ApiStatus_DONE2;
}

void func_8024003C_B1CA8C(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    if (playerStatus->flags & 1) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= 0x200;

        get_screen_coords(gCurrentCamID, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        renderTask.renderMode = playerStatus->renderMode;
        renderTask.appendGfxArg = playerStatus;
        renderTask.appendGfx = func_80240100_B1CB50;
        renderTask.distance = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

void func_80240100_B1CB50(PlayerStatus* playerStatus) {
    f32 yaw = -CAM(gCurrentCamID)->currentYaw;
    Matrix4f main;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;

    guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(main, clamp_angle(playerStatus->unk_8C), 0.0f, 0.0f, 1.0f);
    guMtxCatF(rotation, main, main);
    guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(main, rotation, main);
    guScaleF(scale, SPRITE_WORLD_SCALE, SPRITE_WORLD_SCALE, SPRITE_WORLD_SCALE);
    guMtxCatF(main, scale, main);
    guTranslateF(translation, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z);
    guMtxCatF(main, translation, main);
    spr_update_player_sprite(1, playerStatus->trueAnimation ^ 0x1000000, 1.0f);
    spr_draw_player_sprite(1, 0, 0, NULL, main);
}

ApiStatus func_802402B8_B1CD08(ScriptInstance* script, s32 isInitialCall) {
    script->array[0] = (s32) create_generic_entity_frontUI(NULL, func_802402F4_B1CD44);
    return ApiStatus_DONE2;
}

void func_802402F4_B1CD44(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    if (playerStatus->flags & 1) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= 0x200;

        get_screen_coords(gCurrentCamID, playerStatus->position.x, -playerStatus->position.y, playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        renderTaskPtr->renderMode = playerStatus->renderMode;
        renderTaskPtr->appendGfxArg = playerStatus;
        renderTaskPtr->appendGfx = func_802403B8_B1CE08;
        renderTaskPtr->distance = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

INCLUDE_ASM(void, "world/area_tst/tst_11/B1CA50", func_802403B8_B1CE08, RenderTask* arg0);

ApiStatus func_802406D4_B1D124(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc;

    script->array[1] = create_generic_entity_world(N(SetPartnerFlagsA0000), NULL);

    npc = get_npc_safe(NPC_PARTNER);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->flags |= NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR;

    return ApiStatus_DONE2;
}

void N(SetPartnerFlagsA0000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR;
    }
}
