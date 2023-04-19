#include "common.h"
#include "npc.h"
#include "model.h"

API_CALLABLE(N(CheckDripCollisionWithNPC)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 treeIndex = evt_get_variable(script, *args++);
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));
    f32 xDiff, zDiff, yVal;
    f32 sqrtTemp;
    s32 i;

    script->varTable[2] = 0;
    xDiff = playerStatus->position.x - model->center.x;
    zDiff = playerStatus->position.z - model->center.z;
    yVal = playerStatus->position.y + playerStatus->colliderHeight - 1.5f - model->center.y;
    sqrtTemp = sqrtf(SQ(xDiff) + SQ(zDiff));

    if (yVal > 0.0f && yVal < playerStatus->colliderHeight && sqrtTemp < playerStatus->colliderDiameter * 0.5f) {
        script->varTable[2] = 1;
    }

    xDiff = partner->pos.x - model->center.x;
    zDiff = partner->pos.z - model->center.z;
    yVal = partner->pos.y + partner->collisionHeight - 1.5f - model->center.y;
    sqrtTemp = sqrtf(SQ(xDiff) + SQ(zDiff));

    if (yVal > 0.0f && yVal < partner->collisionHeight && sqrtTemp < partner->collisionDiameter * 0.5f) {
        script->varTable[2] = 1;
    }

    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = get_npc_safe(i);

        if (npc != NULL) {
            xDiff = npc->pos.x - model->center.x;
            zDiff = npc->pos.z - model->center.z;
            yVal = npc->pos.y + npc->collisionHeight - 1.5f - model->center.y;
            sqrtTemp = sqrtf(SQ(xDiff) + SQ(zDiff));

            if (yVal > 0.0f && yVal < npc->collisionHeight && sqrtTemp < npc->collisionDiameter * 0.5f) {
                script->varTable[2] = 1;
                break;
            }
        }
    }
    return ApiStatus_DONE2;
}
