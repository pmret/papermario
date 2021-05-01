#include "common.h"

void func_802E9050(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 val = fabsf(clamp_angle(180.0f - entity->rotation.y) - clamp_angle(atan2(entity->position.x, entity->position.z,
                    playerStatus->position.x, playerStatus->position.z)));

    if (!(playerStatus->animFlags & 1) && !(entity->collisionFlags & 1) && (val <= 40.0f || val >= 320.0f)) {
        entity->flags |= 0x1000;
        if ((playerStatus->animFlags & PLAYER_ANIM_FLAG_INTERACT_PROMPT) && (entity->collisionFlags & 8)) {
            func_80110678(entity);
        }
    } else {
        entity->flags &= ~0x1000;
        playerStatus->unk_C6 = -1;
    }
}
