#include "common.h"
#include "npc.h"
#include "model.h"

ApiStatus N(UnkPhysicsFunc)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    f32 inDist1 = *args++;
    f32 r = *args++;
    f32 inDist2 = *args++;
    f32 x = npc->pos.x;
    f32 z = npc->pos.z;
    f32 y;
    f32 xDist;
    f32 zDist;
    s32 outVal;

    add_vec2D_polar(&x, &z, r, npc->yaw);
    xDist = dist2D(x, 0.0f, playerStatus->position.x, 0.0f);
    zDist = dist2D(0.0f, z, 0.0f, playerStatus->position.z);

    if (npc->yaw == 90.0 || npc->yaw == 270.0) {
        if (xDist <= inDist1 && zDist <= inDist2) {
            outVal = TRUE;
        } else {
            outVal = FALSE;
        }
    } else {
        if (zDist <= inDist1 && xDist <= inDist2) {
            outVal = TRUE;
        } else {
            outVal = FALSE;
        }
    }

    if (outVal) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;
        // required to match, has to be r
        r = dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);

        if (npc_test_move_taller_with_slipping(0x78000, &x, &y, &z, r,
                                               atan2(npc->pos.x, npc->pos.z, playerStatus->position.x,
                                                     playerStatus->position.z),
                                               npc->collisionRadius,
                                               npc->collisionHeight))
        {
            outVal = FALSE;
        }
    }
    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

void N(UnkModelMatrixFunc)(s32 treeIndex, f32 x, f32 y, f32 z, f32 scale) {
    Matrix4f sp10;
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    guTranslateF(model->transformMatrix, x, y, z);
    guScaleF(sp10, scale, 1.0f, scale);
    guMtxCatF(sp10, model->transformMatrix, model->transformMatrix);
    model->flags |= MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED;
}

ApiStatus N(UnkModelMatrixFunc2)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    f32 r = *args++;
    f32 distCheck1 = *args++;
    f32 r2 = *args++;
    f32 distCheck2 = *args++;
    s32 treeIndex = *args++;
    s32 lightSourceIdx = *args++;
    f32 x = npc->pos.x;
    f32 z = npc->pos.z;
    SpriteShadingLightSource* ssls;
    f32 y;
    f32 dist;
    s32 outVal;

    add_vec2D_polar(&x, &z, 30.0f, npc->yaw);

    ssls = &D_80151328->sources[lightSourceIdx];
    ssls->pos.x = x;
    ssls->pos.y = npc->pos.y + 20.0f;
    ssls->pos.z = z;

    x = npc->pos.x;
    z = npc->pos.z;
    add_vec2D_polar(&x, &z, r, npc->yaw);

    if (dist2D(x, z, playerStatus->position.x, playerStatus->position.z) <= distCheck1) {
        outVal = 1;
    } else {
        outVal = 0;
    }

    N(UnkModelMatrixFunc)(treeIndex, x, npc->pos.y, z, (2.0 * distCheck1 / 100.0) + 0.3);

    x = npc->pos.x;
    z = npc->pos.z;
    add_vec2D_polar(&x, &z, r2, npc->yaw);

    if (dist2D(x, z, playerStatus->position.x, playerStatus->position.z) <= distCheck2) {
        outVal |= 0x10;
    }

    if (outVal & 1) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;

        dist = dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
        if (npc_test_move_taller_with_slipping(0, &x, &y, &z, dist,
                                               atan2(npc->pos.x, npc->pos.z,
                                                     playerStatus->position.x, playerStatus->position.z),
                                               npc->collisionRadius, npc->collisionHeight)) {
            outVal = 0;
        }
    }

    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}
