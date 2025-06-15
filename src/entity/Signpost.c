#include "common.h"
#include "ld_addrs.h"
#include "entity.h"

extern Gfx Entity_Signpost_Render[];

void entity_Signpost_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 val = fabsf(clamp_angle(180.0f - entity->rot.y) - clamp_angle(atan2(entity->pos.x, entity->pos.z,
                    playerStatus->pos.x, playerStatus->pos.z)));

    if (!(playerStatus->animFlags & PA_FLAG_USING_WATT) && !(entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) && (val <= 40.0f || val >= 320.0f)) {
        entity->flags |= ENTITY_FLAG_SHOWS_INSPECT_PROMPT;
        if ((playerStatus->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) && (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_WALL)) {
            entity_start_script(entity);
        }
    } else {
        entity->flags &= ~ENTITY_FLAG_SHOWS_INSPECT_PROMPT;
        playerStatus->interactingWithID = NO_COLLIDER;
    }
}

EntityScript Entity_Signpost_Script = {
    es_SetCallback(entity_Signpost_idle, 0)
    es_End
};

EntityModelScript Entity_Signpost_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_Signpost_Render, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_Signpost = {
    .flags = ENTITY_FLAG_CIRCULAR_SHADOW | ENTITY_FLAG_400 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(SignpostData),
    .renderCommandList = Entity_Signpost_RenderScript,
    .modelAnimationNodes = nullptr,
    .fpInit = nullptr,
    .updateEntityScript = Entity_Signpost_Script,
    .fpHandleCollision = nullptr,
    {{ entity_model_Signpost_ROM_START, entity_model_Signpost_ROM_END }},
    .entityType = ENTITY_TYPE_SIGNPOST,
    .aabbSize = { 40, 50, 20 }
};
