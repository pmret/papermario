#include "common.h"

void entity_Signpost_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 val = fabsf(clamp_angle(180.0f - entity->rotation.y) - clamp_angle(atan2(entity->position.x, entity->position.z,
                    playerStatus->position.x, playerStatus->position.z)));

    if (!(playerStatus->animFlags & 1) && !(entity->collisionFlags & 1) && (val <= 40.0f || val >= 320.0f)) {
        entity->flags |= ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
        if ((playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_INTERACT_PROMPT_AVAILABLE) && (entity->collisionFlags & 8)) {
            entity_start_script(entity);
        }
    } else {
        entity->flags &= ~ENTITY_FLAGS_SHOWS_INSPECT_PROMPT;
        playerStatus->unk_C6 = -1;
    }
}
