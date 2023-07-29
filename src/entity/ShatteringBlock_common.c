#include "common.h"
#include "entity.h"

void entity_shattering_setupGfx(s32 entityIndex);

void entity_BrickBlock_idle(Entity* entity) {
    entity_base_block_idle(entity);
}

void entity_shattering_init_pieces(Entity* entity, Gfx** dlists, Mtx* matrices) {
    ShatteringBlockData* data = entity->dataBuf.shatteringBlock;
    s32 s7;
    s32 i;
    Matrix4f mtxFragment;
    Matrix4f mtxTrans;
    s32 rotSpeed;
    f32 fallSpeed;

    data->fragmentDisplayLists = ENTITY_ADDR(entity, Gfx**, dlists);
    entity->renderSetupFunc = entity_shattering_setupGfx;
    entity->alpha = 255;
    entity->pos.y = data->originalPosY;
    guTranslateF(mtxTrans, entity->pos.x, entity->pos.y, entity->pos.z);

    s7 = 2;
    if (!is_block_on_ground(entity)) {
        s7 = 1;
    }

    data->fadeOutCounter = 0;
    data->alpha = 255;

    for (i = 0; i < 24; i++) {
        guMtxL2F(mtxFragment, ENTITY_ADDR(entity, Mtx*, matrices++));
        guMtxCatF(mtxTrans, mtxFragment, mtxFragment);
        data->fragmentPosX[i] = mtxFragment[3][0];
        data->fragmentPosY[i] = mtxFragment[3][1];
        data->fragmentPosZ[i] = mtxFragment[3][2];
        data->fragmentMoveAngle[i] = -rand_int(255);

        if (s7 == 1) {
            rotSpeed = 20;
            fallSpeed = 6.4f;
            data->fragmentFlags[i] |= 1;
        } else {
            rotSpeed = 40;
            fallSpeed = 8.6f;
            data->fragmentFlags[i] |= 2;
        }
        rotSpeed += rand_int(10);
        data->fragmentRotSpeed[i] = rotSpeed;
        if ((i % 2) == 0) {
            data->fragmentRotSpeed[i] = -rotSpeed;
        }

        data->fragmentFallSpeed[i] = fallSpeed + (f32)(rand_float() * 2.7);
        data->fragmentRebounds[i] = 0;
        data->fragmentRotX[i] = 0;
        data->fragmentRotY[i] = 0;
    }
}

void entity_shattering_idle(Entity* entity) {
    ShatteringBlockData* data = entity->dataBuf.shatteringBlock;
    f32 rotSpeed = 0.0f;
    f32 reboundSpeed = 0.0f;
    f32 lateralSpeed = 0.0f;
    f32 angle;
    s32 i;
    f32 sinTheta;
    f32 cosTheta;
    f32 hitX, hitY, hitZ, hitDepth;

    for (i = 0; i < 24; i++) {
        switch (data->fragmentRebounds[i]) {
            case 0:
                if (data->fragmentFlags[i] & 1) {
                    lateralSpeed = 1.5f;
                } else {
                    lateralSpeed = 2.4f;
                }
                reboundSpeed = 6.0f;
                rotSpeed = data->fragmentRotSpeed[i];
                break;
            case 1:
                lateralSpeed = 1.2f;
                reboundSpeed = 3.0f;
                rotSpeed = data->fragmentRotSpeed[i] >> 2;
                break;
            case 2:
                lateralSpeed = 1.0f;
                reboundSpeed = 2.0f;
                rotSpeed = data->fragmentRotSpeed[i] >> 2;
                if (data->alpha == 0) {
                    data->fragmentRebounds[i]++;
                }
                break;
            case 3:
                data->fragmentPosY[i] -= 0.3;
                continue;
        }

        data->fragmentFallSpeed[i] -= 1.2;
        if (data->fragmentFallSpeed[i] < -12.2) {
            data->fragmentFallSpeed[i] = -12.2f;
        }
        data->fragmentPosY[i] += data->fragmentFallSpeed[i];

        angle = data->fragmentMoveAngle[i] * 360.0 / 256;
        sin_cos_rad(DEG_TO_RAD(angle), &sinTheta, &cosTheta);
        data->fragmentPosX[i] += lateralSpeed * sinTheta;
        data->fragmentPosZ[i] += lateralSpeed * cosTheta;

        hitX = data->fragmentPosX[i];
        hitY = data->fragmentPosY[i];
        hitZ = data->fragmentPosZ[i];
        if (npc_test_move_taller_with_slipping(COLLISION_IGNORE_ENTITIES, &hitX, &hitY, &hitZ, lateralSpeed, angle, 8.0f, 8.0f)) {
            data->fragmentPosX[i] = hitX;
            data->fragmentPosY[i] = hitY;
            data->fragmentPosZ[i] = hitZ;
            data->fragmentMoveAngle[i] += 0x80; // inverse yaw

            sin_cos_rad(DEG_TO_RAD(data->fragmentMoveAngle[i] * 360.0 / 256), &sinTheta, &cosTheta);
            lateralSpeed = 8.0f;
            data->fragmentPosX[i] += lateralSpeed * sinTheta;
            data->fragmentPosZ[i] += lateralSpeed * cosTheta;
        }

        hitX = data->fragmentPosX[i];
        hitY = data->fragmentPosY[i];
        hitZ = data->fragmentPosZ[i];
        hitDepth = fabsf(data->fragmentFallSpeed[i]);
        if (npc_raycast_down_sides(COLLISION_IGNORE_ENTITIES, &hitX, &hitY, &hitZ, &hitDepth) || hitY < data->originalPosY - 200.0f) {
            data->fragmentRebounds[i]++;
            data->fragmentPosY[i] = hitY + fabsf(data->fragmentFallSpeed[i]) * 1.2f;
            data->fragmentFallSpeed[i] = reboundSpeed;
        }

        data->fragmentRotX[i] += rotSpeed;
        data->fragmentRotY[i] -= rotSpeed;
    }

    data->fadeOutCounter++;
    if (data->fadeOutCounter >= 10) {
        data->fadeOutCounter = 10;
        data->alpha -= 8;
        if (data->alpha <= 0) {
            data->alpha = 0;
            exec_entity_commandlist(entity);
        }
    }
}

void entity_shattering_setupGfx(s32 entityIndex) {
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
    ShatteringBlockData* data = entity->dataBuf.shatteringBlock;
    Gfx* fragmentDlist;
    Gfx** gfx = data->fragmentDisplayLists;

    x_inv = -entity->pos.x;
    y_inv = -entity->pos.y;
    z_inv = -entity->pos.z;

    for (i = 0; i < 24; i++) {
        if (data->alpha == 255) {
            gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            gDPSetCombineMode(gfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        } else {
            gDPSetCombineMode(gfxPos++, PM_CC_11, PM_CC_12);
            gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, data->alpha);
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

EntityScript Entity_ShatteringBlock_Script = {
    es_SetFlags(ENTITY_FLAG_DISABLE_COLLISION)
    es_SetCallback(entity_shattering_idle, 0)
    es_SetFlags(ENTITY_FLAG_HIDDEN)
    es_SetFlags(ENTITY_FLAG_PENDING_INSTANCE_DELETE)
    es_End
};
