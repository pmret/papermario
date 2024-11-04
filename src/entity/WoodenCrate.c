#include "common.h"
#include "npc.h"
#include "ld_addrs.h"
#include "entity.h"

extern Gfx Entity_RenderNone[];
extern Gfx Entity_WoodenCrate_Render[];
extern Gfx* Entity_WoodenCrate_FragmentsRender[];
extern Mtx Entity_WoodenCrate_FragmentsMatrices[];
extern s32 Entity_WoodenCrate_RenderShatteredScript[];

void entity_WoodenCrate_setupGfx(s32);

void entity_WoodenCrate_init_fragments(Entity* entity, Gfx** dlists, Mtx* matrices) {
    WoodenCrateData* data = entity->dataBuf.crate;
    Matrix4f mtxFragment;
    Matrix4f mtxTrans;
    s32 i;
    s32 rotationSpeed;

    data->fragmentsGfx = ENTITY_ADDR(entity, Gfx**, dlists);
    entity->renderSetupFunc = entity_WoodenCrate_setupGfx;
    entity->alpha = 255;
    entity->pos.y = data->basePosY;
    guTranslateF(mtxTrans, entity->pos.x, entity->pos.y, entity->pos.z);

    for (i = 0; i < 35; i++) {
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

void entity_WoodenCrate_init(Entity* entity) {
    WoodenCrateData* data = entity->dataBuf.crate;

    entity->scale.y = 0.85714287f;
    data->itemID = CreateEntityVarArgBuffer[0];
    data->globalFlagIndex = 0xFFFF;
}

void entity_WoodenCrate_reset_fragments(Entity* entity) {
    WoodenCrateData* data = entity->dataBuf.crate;

    data->basePosY = entity->pos.y;
    entity_WoodenCrate_init_fragments(entity, Entity_WoodenCrate_FragmentsRender, Entity_WoodenCrate_FragmentsMatrices);
}

void entity_WoodenCrate_update_fragments(Entity* entity) {
    WoodenCrateData* data = entity->dataBuf.crate;
    f32 rotSpeed, lateralSpeed, reboundSpeed;
    f32 moveAngle, yawRad;
    s32 i;
    s32 numFragmentsDisappeared;
    f32 hitX, hitY, hitZ, hitDepth;

    numFragmentsDisappeared = 0;
    rotSpeed = 0.0f;
    reboundSpeed = 0.0f;
    lateralSpeed = 0.0f;

    for (i = 0; i < 35; i++) {
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
            hitY = data->fragmentPosY[i] + 8.0f;
            hitZ = data->fragmentPosZ[i];
            hitDepth = fabsf(data->fragmentFallSpeed[i]);
            if (npc_raycast_down_sides(COLLISION_IGNORE_ENTITIES, &hitX, &hitY, &hitZ, &hitDepth) || hitY < data->basePosY - 200.0f) {
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

    if (numFragmentsDisappeared >= 35) {
        exec_entity_commandlist(entity);
    }
}

void entity_WoodenCrate_setupGfx(s32 entityIndex) {
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
    WoodenCrateData* data = entity->dataBuf.crate;
    Gfx* fragmentDlist;
    Gfx** gfx = data->fragmentsGfx;

    x_inv = -entity->pos.x;
    y_inv = -entity->pos.y;
    z_inv = -entity->pos.z;

    for (i = 0; i < 35; i++) {
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

s32 entity_WoodenCrate_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 shouldBreak = FALSE;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if ((playerStatus->actionState == ACTION_STATE_SPIN_POUND)
            || (playerStatus->actionState == ACTION_STATE_TORNADO_POUND)) {
            set_action_state(ACTION_STATE_FALLING);
            shouldBreak = TRUE;
        }
    }

    if (shouldBreak) {
        entity_WoodenCrate_reset_fragments(entity);
        entity_set_render_script(entity, &Entity_WoodenCrate_RenderShatteredScript);
        entity_start_script(entity);
        exec_entity_commandlist(entity);
        sfx_play_sound(SOUND_BREAK_CRATE);
    }
}

f32 player_get_camera_facing_angle(void);

void entity_WoodenCrate_shatter(Entity* entity, f32 arg1) {
    WoodenCrateData* data = entity->dataBuf.crate;

    if (data->itemID != -1) {
        s32 flag = FALSE;

        if (data->globalFlagIndex == 0xFFFF) {
            flag = TRUE;
        } else if (!get_global_flag(data->globalFlagIndex)) {
            flag = TRUE;
        }

        if (flag) {
            make_item_entity(data->itemID, entity->pos.x, entity->pos.y + 33.0, entity->pos.z,
                ITEM_SPAWN_MODE_ITEM_BLOCK_ITEM, 0, player_get_camera_facing_angle(), data->globalFlagIndex);
        }
    }
}

EntityModelScript Entity_WoodenCrate_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_WoodenCrate_Render, RENDER_MODE_SURFACE_OPA);
EntityModelScript Entity_WoodenCrate_RenderShatteredScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_RenderNone, RENDER_MODE_SURFACE_XLU_LAYER1);

EntityScript Entity_WoodenCrate_Script = {
    es_SetCallback(entity_WoodenCrate_idle, 0)
    es_SetFlags(ENTITY_FLAG_DISABLE_COLLISION)
    es_Call(entity_WoodenCrate_shatter)
    es_SetCallback(entity_WoodenCrate_update_fragments, 0)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};

EntityBlueprint Entity_WoodenCrate = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(WoodenCrateData),
    .renderCommandList = Entity_WoodenCrate_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_WoodenCrate_init,
    .updateEntityScript = Entity_WoodenCrate_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(WoodenCrate) },
    .entityType = ENTITY_TYPE_WOODEN_CRATE,
    .aabbSize = { 35, 30, 35 }
};
