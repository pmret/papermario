#include "common.h"
#include "npc.h"
#include "model.h"

API_CALLABLE(N(UnkPhysicsFunc)) {
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
    s32 channel;

    add_vec2D_polar(&x, &z, r, npc->yaw);
    xDist = dist2D(x, 0.0f, playerStatus->pos.x, 0.0f);
    zDist = dist2D(0.0f, z, 0.0f, playerStatus->pos.z);

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
        r = dist2D(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);

        channel = COLLISION_IGNORE_ENTITIES | COLLISION_CHANNEL_20000 | COLLISION_CHANNEL_10000 | COLLISION_CHANNEL_8000;
        if (npc_test_move_taller_with_slipping(channel, &x, &y, &z, r,
                    atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z),
                    npc->collisionDiameter, npc->collisionHeight))
        {
            outVal = FALSE;
        }
    }
    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

void N(set_spotlight_pos_scale)(s32 modelID, f32 x, f32 y, f32 z, f32 scale) {
    Matrix4f mtxTemp;
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));

    guTranslateF(model->userTransformMtx, x, y, z);
    guScaleF(mtxTemp, scale, 1.0f, scale);
    guMtxCatF(mtxTemp, model->userTransformMtx, model->userTransformMtx);
    model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
}

API_CALLABLE(N(UpdateSearchlight)) {
    SpriteShadingLightSource* lightSource;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    // radius and distance from NPC of the first spotlight
    f32 radius = *args++;
    f32 offsetDist = *args++;
    // radius and distance from NPC of the second 'extra' spotlight
    f32 extraRadius = *args++;
    f32 extraOffsetDist = *args++;
    // spotlight model and sprite shading light source index
    s32 spotlightModel = *args++;
    s32 lightSourceIdx = *args++;

    f32 x = npc->pos.x;
    f32 z = npc->pos.z;
    s32 outVal = 0;
    f32 dist;
    f32 y;

    // place light source 30 units ahead of the flashlight
    add_vec2D_polar(&x, &z, 30.0f, npc->yaw);

    lightSource = &gSpriteShadingProfile->sources[lightSourceIdx];
    lightSource->pos.x = x;
    lightSource->pos.y = npc->pos.y + 20.0f;
    lightSource->pos.z = z;

    // check if player is inside the first spotlight
    x = npc->pos.x;
    z = npc->pos.z;
    add_vec2D_polar(&x, &z, radius, npc->yaw);

    if (dist2D(x, z, playerStatus->pos.x, playerStatus->pos.z) <= offsetDist) {
        outVal |= 1;
    }

    N(set_spotlight_pos_scale)(spotlightModel, x, npc->pos.y, z, (2.0 * offsetDist / 100.0) + 0.3);

    // check if player is inside the second spotlight
    x = npc->pos.x;
    z = npc->pos.z;
    add_vec2D_polar(&x, &z, extraRadius, npc->yaw);

    if (dist2D(x, z, playerStatus->pos.x, playerStatus->pos.z) <= extraOffsetDist) {
        outVal |= 0x10;
    }

    // cancel alert if enemy does not have line of sight to player
    if (outVal & 1) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;

        dist = dist2D(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
        if (npc_test_move_taller_with_slipping(0, &x, &y, &z, dist,
                atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z),
                npc->collisionDiameter, npc->collisionHeight)) {
            outVal = 0;
        }
    }

    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetAngleBetweenPoints)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 Ax = evt_get_variable(script, *args++);
    s32 Az = evt_get_variable(script, *args++);
    s32 Bx = evt_get_variable(script, *args++);
    s32 Bz = evt_get_variable(script, *args++);

    evt_set_variable(script, outVar, atan2(Ax, Az, Bx, Bz));
    return ApiStatus_DONE2;
}
