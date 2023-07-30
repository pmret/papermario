#include "common.h"
#include "ld_addrs.h"
#include "entity.h"

extern Gfx Entity_RenderNone[];
extern Gfx* Entity_BoardedFloor_FragmentsRender[];
extern Mtx Entity_BoardedFloor_FragmentMatrices[];

void Entity_BoardedFloor_setupGfx(s32);

void Entity_BoardedFloor_init_fragments(Entity* entity, Gfx** dlists, Mtx* matrices) {
    BoardedFloorData* data = entity->dataBuf.boardedFloor;
    Matrix4f mtxFragment;
    Matrix4f mtxTrans;
    s32 i;
    s32 rotationSpeed;

    data->fragmentsGfx = ENTITY_ADDR(entity, Gfx**, dlists);
    entity->renderSetupFunc = Entity_BoardedFloor_setupGfx;
    entity->alpha = 255;
    entity->pos.y = data->inititalY;
    guTranslateF(mtxTrans, entity->pos.x, entity->pos.y, entity->pos.z);

    for (i = 0; i < 12; i++) {
        guMtxL2F(mtxFragment, ENTITY_ADDR(entity, Mtx*, matrices++));
        guMtxCatF(mtxTrans, mtxFragment, mtxFragment);
        data->fragmentPosX[i] = mtxFragment[3][0];
        data->fragmentPosY[i] = mtxFragment[3][1];
        data->fragmentPosZ[i] = mtxFragment[3][2];
        data->fragmentMoveAngle[i] = -rand_int(255);
        data->fragmentLateralSpeed[i] = 20;

        rotationSpeed = rand_int(5);
        if (i % 2 != 0) {
            data->fragmentRotSpeed[i] = rotationSpeed + 10;
        } else {
            data->fragmentRotSpeed[i] = -10 - rotationSpeed;
        }

        data->fragmentFallSpeed[i] = 10.0f;
        data->fragmentRebounds[i] = 0;
        data->fragmentRotX[i] = 0;
        data->fragmentRotY[i] = 0;
    }
}

void Entity_BoardedFloor_init(Entity* entity) {
    entity->dataBuf.boardedFloor->inititalY = entity->pos.y;
    Entity_BoardedFloor_init_fragments(entity, Entity_BoardedFloor_FragmentsRender, Entity_BoardedFloor_FragmentMatrices);
}

void Entity_BoardedFloor_update_fragments(Entity* entity) {
    BoardedFloorData* data = entity->dataBuf.boardedFloor;
    f32 rotSpeed, lateralSpeed, reboundSpeed;
    f32 moveAngle, yawRad;
    s32 i;
    s32 numFragmentsDisappeared;
    f32 hitX, hitY, hitZ, hitDepth;

    numFragmentsDisappeared = 0;
    rotSpeed = 0.0f;
    reboundSpeed = 0.0f;
    lateralSpeed = 0.0f;

    for (i = 0; i < 12; i++) {
        switch (data->fragmentRebounds[i]) {
            case 0:
                reboundSpeed = 2.0f;
                rotSpeed = data->fragmentRotSpeed[i];
                lateralSpeed = data->fragmentLateralSpeed[i] / 10.0f;
                if (rotSpeed >= 0.0f) {
                    data->fragmentRotSpeed[i] = rotSpeed - 0.4;
                } else {
                    data->fragmentRotSpeed[i] = rotSpeed + 0.5;
                }
                break;
            case 1:
                lateralSpeed = 1.0f;
                reboundSpeed = 0.0f;
                rotSpeed = data->fragmentRotSpeed[i] * 0.25f;
                break;
            case 2:
                data->fragmentRotSpeed[i] += 1.0f;
                if (data->fragmentRotSpeed[i] > 20.0f) {
                    data->fragmentRotSpeed[i] = 20.0f;
                }

                data->fragmentPosY[i] -= data->fragmentRotSpeed[i] / 70.0f;

                data->fragmentMoveAngle[i] -= 5;
                if (data->fragmentMoveAngle[i] <= 5) {
                    data->fragmentMoveAngle[i] = 0;
                    data->fragmentRebounds[i]++;
                }
                break;
            case 3:
                numFragmentsDisappeared++;
                break;
        }

        if (data->fragmentRebounds[i] < 2) {
            if (data->fragmentFallSpeed[i] >= 0.0f) {
                data->fragmentFallSpeed[i] -= 0.8;
                if (data->fragmentFallSpeed[i] < -10.2) {
                    data->fragmentFallSpeed[i] = -10.2f;
                }
            } else {
                data->fragmentFallSpeed[i] -= 1.6;
                if (data->fragmentFallSpeed[i] < -10.2) {
                    data->fragmentFallSpeed[i] = -10.2f;
                }
            }

            data->fragmentPosY[i] += data->fragmentFallSpeed[i];
            yawRad = data->fragmentMoveAngle[i] * 360.0f / 256;
            moveAngle = DEG_TO_RAD(yawRad);
            data->fragmentPosX[i] += lateralSpeed * sin_rad(moveAngle);
            data->fragmentPosZ[i] += lateralSpeed * cos_rad(moveAngle);

            hitX = data->fragmentPosX[i];
            hitY = data->fragmentPosY[i];
            hitZ = data->fragmentPosZ[i];
            if (npc_test_move_taller_with_slipping(COLLISION_IGNORE_ENTITIES, &hitX, &hitY, &hitZ, lateralSpeed, yawRad, 8.0f, 8.0f)) {
                data->fragmentPosX[i] = hitX;
                data->fragmentPosY[i] = hitY;
                data->fragmentPosZ[i] = hitZ;
                data->fragmentMoveAngle[i] += 0x80; // inverse yaw

                moveAngle = DEG_TO_RAD(data->fragmentMoveAngle[i] * 360.0f / 256);
                lateralSpeed = 8.0f;
                data->fragmentPosX[i] += lateralSpeed * sin_rad(moveAngle);
                data->fragmentPosZ[i] += lateralSpeed * cos_rad(moveAngle);

            }

            hitX = data->fragmentPosX[i];
            hitY = data->fragmentPosY[i];
            hitZ = data->fragmentPosZ[i];
            hitDepth = fabsf(data->fragmentFallSpeed[i]);
            if (npc_raycast_down_sides(COLLISION_IGNORE_ENTITIES, &hitX, &hitY, &hitZ, &hitDepth) || hitY < data->inititalY - 200.0f) {
                data->fragmentRebounds[i]++;
                data->fragmentPosY[i] = hitY + fabsf(data->fragmentFallSpeed[i]);
                data->fragmentFallSpeed[i] = reboundSpeed;
                if (data->fragmentRebounds[i] == 2) {
                    data->fragmentMoveAngle[i] = 254;
                    data->fragmentRotSpeed[i] = 0.0f;
                }
            }

            data->fragmentRotX[i] += rotSpeed;
            data->fragmentRotY[i] -= rotSpeed;
        }
    }

    if (numFragmentsDisappeared >= 12) {
        exec_entity_commandlist(entity);
    }
}

void Entity_BoardedFloor_setupGfx(s32 entityIndex) {
    s32 i;
    Matrix4f mtxTransInv;
    Matrix4f mtx;
    Matrix4f mtxRotX;
    Matrix4f mtxRotY;
    f32 x_inv;
    f32 y_inv;
    f32 z_inv;
    Gfx* gfxPos = gMainGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);
    BoardedFloorData* data = entity->dataBuf.boardedFloor;
    Gfx* fragmentDlist;
    Gfx** gfx = data->fragmentsGfx;

    x_inv = -entity->pos.x;
    y_inv = -entity->pos.y;
    z_inv = -entity->pos.z;

    for (i = 0; i < 12; i++) {
        if (data->fragmentRebounds[i] < 2) {
            gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            gDPSetCombineMode(gfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        } else {
            gDPSetCombineMode(gfxPos++, PM_CC_11, PM_CC_12);
            gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, data->fragmentMoveAngle[i]);
        }

        guTranslateF(mtxTransInv, x_inv, y_inv, z_inv);
        guRotateF(mtxRotX, data->fragmentRotX[i] * 360.0f / 256, 1.0f, 0.0f, 0.0f);
        guRotateF(mtxRotY, data->fragmentRotY[i] * 360.0f / 256, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtxRotX, mtxRotY, mtxRotY);
        guMtxCatF(mtxRotY, mtxTransInv, mtxTransInv);
        guTranslateF(mtx, data->fragmentPosX[i], data->fragmentPosY[i], data->fragmentPosZ[i]);
        guMtxCatF(mtxTransInv, mtx, mtx);
        guMtxF2L(mtx, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        fragmentDlist = ENTITY_ADDR(entity, Gfx*, *gfx++);
        gSPDisplayList(gfxPos++, fragmentDlist);
        gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);
    }

    gMainGfxPos = gfxPos;
}

void Entity_BoardedFloor_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (playerStatus->actionState == ACTION_STATE_SPIN_POUND
            || playerStatus->actionState == ACTION_STATE_TORNADO_POUND) {
            entity_start_script(entity);
            exec_entity_commandlist(entity);
        }
    }
}

EntityModelScript Entity_BoardedFloor_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RenderNone, RENDER_MODE_SURFACE_OPA);
EntityModelScript Entity_BoardedFloor_RenderScriptShattered = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RenderNone, RENDER_MODE_SURFACE_XLU_LAYER1);

void Entity_BoardedFloor_shatter(Entity* entity) {
    BoardedFloorData* data = entity->dataBuf.boardedFloor;
    s32 i;

    for (i = 0; i < 12; i++) {
        data->fragmentPosY[i] += 1.0f;
    }

    entity_set_render_script(entity, &Entity_BoardedFloor_RenderScriptShattered);
}

EntityModelScript Entity_BoardedFloor_Script = {
    es_ClearFlags(ENTITY_FLAG_DISABLE_COLLISION)
    es_SetCallback(Entity_BoardedFloor_idle, 0)
    es_PlaySound(SOUND_2092)
    es_SetFlags(ENTITY_FLAG_DISABLE_COLLISION)
    es_Call(Entity_BoardedFloor_shatter)
    es_SetCallback(Entity_BoardedFloor_update_fragments, 0)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityBlueprint Entity_BoardedFloor = {
    .flags = 0,
    .typeDataSize = sizeof(BoardedFloorData),
    .renderCommandList = Entity_BoardedFloor_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = Entity_BoardedFloor_init,
    .updateEntityScript = Entity_BoardedFloor_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(BoardedFloor) },
    .entityType = ENTITY_TYPE_BOARDED_FLOOR,
    .aabbSize = { 60, 5, 60 }
};
