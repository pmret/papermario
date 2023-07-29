#include "tst_11.h"
#include "entity.h"
#include "sprite.h"

void N(test_reflection_worker_render_wall)(void);
void N(appendGfx_test_reflection_wall)(void*);
void N(test_reflection_worker_render_floor)(void);
void N(appendGfx_test_reflection_floor)(void*);
void N(test_reflection_worker_partner)(void);

// identical to final version
API_CALLABLE(N(EnableWallReflectionTest)) {
    script->array[0] = (s32) create_worker_frontUI(NULL, N(test_reflection_worker_render_wall));
    return ApiStatus_DONE2;
}

void N(test_reflection_worker_render_wall)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX, screenY, screenZ;

    if (playerStatus->flags & PS_FLAG_HAS_REFLECTION) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= ENTITY_MODEL_FLAG_REFLECT;

        get_screen_coords(gCurrentCamID, playerStatus->pos.x, playerStatus->pos.y, -playerStatus->pos.z,
                          &screenX, &screenY, &screenZ);

        renderTaskPtr->renderMode = playerStatus->renderMode;
        renderTaskPtr->appendGfxArg = playerStatus;
        renderTaskPtr->appendGfx = &N(appendGfx_test_reflection_wall);
        renderTaskPtr->dist = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

void N(appendGfx_test_reflection_wall)(void* data) {
    PlayerStatus* playerStatus = data;
    f32 yaw = -gCameras[gCurrentCamID].curYaw;
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
    guTranslateF(translation, playerStatus->pos.x, playerStatus->pos.y, -playerStatus->pos.z);
    guMtxCatF(main, translation, main);
    // draw sprite is handled differently in final version
    spr_update_player_sprite(PLAYER_SPRITE_AUX1, playerStatus->trueAnimation ^ SPRITE_ID_BACK_FACING, 1.0f);
    spr_draw_player_sprite(PLAYER_SPRITE_AUX1, 0, 0, NULL, main);
}

API_CALLABLE(N(EnableFloorReflectionTest)) {
    script->array[0] = (s32) create_worker_frontUI(NULL, &N(test_reflection_worker_render_floor));
    return ApiStatus_DONE2;
}

void N(test_reflection_worker_render_floor)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX, screenY, screenZ;

    if (playerStatus->flags & PS_FLAG_HAS_REFLECTION) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= ENTITY_MODEL_FLAG_REFLECT;

        get_screen_coords(gCurrentCamID, playerStatus->pos.x, -playerStatus->pos.y, playerStatus->pos.z,
                          &screenX, &screenY, &screenZ);

        renderTaskPtr->renderMode = playerStatus->renderMode;
        renderTaskPtr->appendGfxArg = playerStatus;
        renderTaskPtr->appendGfx = &N(appendGfx_test_reflection_floor);
        renderTaskPtr->dist = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

void N(appendGfx_test_reflection_floor)(void* data) {
    PlayerStatus* playerStatus = data;
    f32 yaw = -gCameras[gCurrentCamID].curYaw;
    s32 trueAnimation;
    Matrix4f sp20;
    Matrix4f sp60;
    Matrix4f spA0;
    Matrix4f spE0;

    guRotateF(spA0, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(sp20, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
    guMtxCatF(spA0, sp20, sp20);
    guRotateF(spA0, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp20, spA0, sp20);
    guRotateF(spA0, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp20, spA0, sp20);
    guScaleF(spE0, SPRITE_WORLD_SCALE_D, -SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D);
    guMtxCatF(sp20, spE0, sp20);
    guTranslateF(sp60, playerStatus->pos.x, -playerStatus->pos.y, playerStatus->pos.z);
    guMtxCatF(sp20, sp60, sp20);
    spr_draw_player_sprite(PLAYER_SPRITE_AUX1, 0, 0, 0, sp20);
    guRotateF(spA0, yaw, 0.0f, -1.0f, 0.0f);
    guRotateF(sp20, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
    guMtxCatF(spA0, sp20, sp20);
    guRotateF(spA0, yaw, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp20, spA0, sp20);
    guRotateF(spA0, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp20, spA0, sp20);
    guScaleF(spE0, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D);
    guMtxCatF(sp20, spE0, sp20);
    guTranslateF(sp60, playerStatus->pos.x, playerStatus->pos.y, 0.0f);
    guMtxCatF(sp20, sp60, sp20);
    trueAnimation = playerStatus->trueAnimation;
    set_player_imgfx_all(trueAnimation, IMGFX_SET_ALPHA, 255, 255, 255, 20, 0);
    spr_draw_player_sprite(PLAYER_SPRITE_AUX1, 0, 0, 0, sp20);
    set_player_imgfx_all(trueAnimation, IMGFX_CLEAR, 0, 0, 0, 0, 0);
}

API_CALLABLE(N(PartnerReflectTest)) {
    Npc* partner;

    script->array[1] = create_worker_world(N(test_reflection_worker_partner), NULL);
    partner = get_npc_safe(NPC_PARTNER);

    if (partner == NULL) {
        return ApiStatus_DONE2;
    }

    partner->flags |= (NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR);
    return ApiStatus_DONE2;
}

void N(test_reflection_worker_partner)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= (NPC_FLAG_REFLECT_WALL | NPC_FLAG_REFLECT_FLOOR);
    }
}

EvtScript N(EVS_SetupReflections) = {
    EVT_MALLOC_ARRAY(16, LVarA)
    EVT_CALL(N(EnableWallReflectionTest))
    EVT_CALL(N(EnableFloorReflectionTest))
    EVT_CALL(N(PartnerReflectTest))
    EVT_RETURN
    EVT_END
};
