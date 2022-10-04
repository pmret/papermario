#include "tst_04.h"
#include "sprite.h"
#include "model.h"

void N(worker_render_player_reflection)(void);
void N(appendGfx_test_player_reflection)(void* data);
void N(worker_update_partner_reflection)(void);

static s32 N(Animator);

API_CALLABLE(N(EnablePlayerReflection)) {
    script->array[0] = (s32) create_generic_entity_frontUI(NULL, &N(worker_render_player_reflection));
    return ApiStatus_DONE2;
}

void N(worker_render_player_reflection)(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EntityModel* entityModel;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    if (playerStatus->flags & PS_FLAGS_HAS_REFLECTION) {
        entityModel = get_entity_model(get_shadow_by_index(playerStatus->shadowID)->entityModelID);
        entityModel->flags |= MODEL_FLAGS_FLAG_200;

        get_screen_coords(gCurrentCamID, playerStatus->position.x, playerStatus->position.y, -playerStatus->position.z,
                          &screenX, &screenY, &screenZ);

        renderTaskPtr->renderMode = playerStatus->renderMode;
        renderTaskPtr->appendGfxArg = playerStatus;
        renderTaskPtr->appendGfx = &N(appendGfx_test_player_reflection);
        renderTaskPtr->distance = -screenZ;
        queue_render_task(renderTaskPtr);
    }
}

void N(appendGfx_test_player_reflection)(void* data) {
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

API_CALLABLE(N(EnablePartnerReflection)) {
    Npc* partner;

    script->array[1] = create_generic_entity_world(&N(worker_update_partner_reflection), NULL);
    partner = get_npc_safe(NPC_PARTNER);

    if (partner == NULL) {
        return ApiStatus_DONE2;
    }

    partner->flags |= NPC_FLAG_REFLECT_WALL;
    partner->flags |= NPC_FLAG_REFLECT_FLOOR;
    return ApiStatus_DONE2;
}

void N(worker_update_partner_reflection)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= NPC_FLAG_REFLECT_WALL;
        partner->flags |= NPC_FLAG_REFLECT_FLOOR;
    }
}

void N(worker_update_animator)(void) {
    update_model_animator(N(Animator));
}

void N(worker_render_animator)(void) {
    Matrix4f m0;
    Matrix4f m1;
    Matrix4f m2;
    Matrix4f m3;
    Mtx m4;

    guTranslateF(m1, -484.0f, 25.0f, -40.0f);
    guMtxF2L(m1, &m4);
    render_animated_model(N(Animator), &m4);
}

API_CALLABLE(N(SetupAnimatedModel)) {
    create_generic_entity_world(N(worker_update_animator), N(worker_render_animator));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupReflection) = {
    EVT_CALL(N(SetupAnimatedModel))
    EVT_MALLOC_ARRAY(16, LVarA)
    EVT_CALL(N(EnablePlayerReflection))
    EVT_CALL(N(EnablePartnerReflection))
    EVT_RETURN
    EVT_END
};
