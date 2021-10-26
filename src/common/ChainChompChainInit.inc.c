#include "common.h"

ApiStatus N(ChainChompChainInit)(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actor);
    ActorPart* actorPart;
    ChainAnimationState* it;
    s32 partOffset = 3;
    f32 x, y, z;
    s32 i;

    it = heap_malloc(8 * sizeof(ChainAnimationState));
    actor->state.unk_6C = it;

    x = actor->currentPos.x + 12.0;
    y = actor->currentPos.y + 5.0;
    z = actor->currentPos.z;

    for (i = 0; i < 8; i++, it++) {
        it->scale.x = 7.0f;
        it->scale.z = 7.0f;
        it->scale.y = 7.0f;
        it->currentPos.x = x;
        it->currentPos.y = y;
        it->currentPos.z = z;
        it->unk_1C = 0;
        it->unk_20 = 0.6f;
        it->unk_14 = 3.0f;
        it->unk_18 = 0;
        actorPart = get_actor_part(actor, partOffset + i);
        actorPart->absolutePosition.x = it->currentPos.x;
        actorPart->absolutePosition.y = it->currentPos.y;
        actorPart->absolutePosition.z = it->currentPos.z;
    }
    return ApiStatus_DONE2;
}
