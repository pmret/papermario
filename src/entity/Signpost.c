#include "common.h"
#include "ld_addrs.h"
#include "entity_script.h"

extern Gfx Entity_SignPost_Render[];

void entity_Signpost_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 val = fabsf(clamp_angle(180.0f - entity->rotation.y) - clamp_angle(atan2(entity->position.x, entity->position.z,
                    playerStatus->position.x, playerStatus->position.z)));

    if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT) && !(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) && (val <= 40.0f || val >= 320.0f)) {
        entity->flags |= ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
        if ((playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_INTERACT_PROMPT_AVAILABLE) && (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_WALL)) {
            entity_start_script(entity);
        }
    } else {
        entity->flags &= ~ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
        playerStatus->interactingWithID = -1;
    }
}

EntityScript Entity_SignPost_Script = {
    es_SetCallback(entity_Signpost_idle, 0)
    es_End
};

EntityModelScript Entity_SignPost_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_SignPost_Render, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_SignPost = {
    .flags = ENTITY_FLAGS_SQUARE_SHADOW | ENTITY_FLAGS_400 | ENTITY_FLAGS_SET_SHADOW_FLAG200,
    .typeDataSize = sizeof(SignPostData),
    .renderCommandList = Entity_SignPost_RenderScript,
    .modelAnimationNodes = 0x00000000,
    .fpInit = NULL,
    .updateEntityScript = Entity_SignPost_Script,
    .fpHandleCollision = NULL,
    {{ entity_model_SignPost_ROM_START, entity_model_SignPost_ROM_END }},
    .entityType = ENTITY_TYPE_SIGNPOST,
    .aabbSize = { 40, 50, 20 }
};
