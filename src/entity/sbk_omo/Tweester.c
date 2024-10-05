#include "common.h"
#include "entity.h"
#include "ld_addrs.h"

u8 Entity_Tweester_FaceAnimationData[] = {
      0,  2,
     32,  2,
      0,  3,
     32,  2,
      0, 80,
    255,  0
};

extern unsigned char D_0A000BF0_E57A50[];
extern unsigned char D_0A000FF0_E57E50[];
extern unsigned char D_0A0018A0_E58700[];
extern unsigned char D_0A0014A0_E58300[];
extern Mtx Entity_Tweester_mtxInnerWhirl;
extern Mtx Entity_Tweester_mtxOuterWhirl;
extern Gfx Entity_Tweester_RenderInnerWhirl[];
extern Gfx Entity_Tweester_RenderOuterWhirl[];
extern Gfx Entity_Tweester_Render[];


void entity_Tweester_render_inner_whirl(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    TweesterData* data = entity->dataBuf.tweester;
    Matrix4f sp18;
    Matrix4f sp58;
    Gfx* gfx;

    guMtxL2F(sp18, ENTITY_ADDR(entity, Mtx*, &Entity_Tweester_mtxInnerWhirl));
    guRotateF(sp58, data->innerWhirlRotY, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &data->mtxInnerWhirl);
    gDisplayContext->matrixStack[gMatrixListPos] = data->mtxInnerWhirl;
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gfx = ENTITY_ADDR(entity, Gfx*, Entity_Tweester_RenderInnerWhirl);
    gSPDisplayList(gMainGfxPos++, gfx);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void entity_Tweester_render_outer_whirl(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    TweesterData* data = entity->dataBuf.tweester;
    Matrix4f sp18;
    Matrix4f sp58;
    Gfx* gfx;

    guMtxL2F(sp18, ENTITY_ADDR(entity, Mtx*, &Entity_Tweester_mtxOuterWhirl));
    guRotateF(sp58, data->outerWhirlRotY, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &data->mtxOuterWhirl);
    gDisplayContext->matrixStack[gMatrixListPos] = data->mtxOuterWhirl;
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gfx = ENTITY_ADDR(entity, Gfx*, Entity_Tweester_RenderOuterWhirl);
    gSPDisplayList(gMainGfxPos++, gfx);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}

void entity_Tweester_render_face(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    TweesterData* data = entity->dataBuf.tweester;

    gDPPipeSync(gMainGfxPos++);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMainGfxPos++, 0, D_0A0018A0_E58700);
    gSPTexture(gMainGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPLoadTextureBlock_4b(gMainGfxPos++, D_0A0014A0_E58300, G_IM_FMT_CI, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, data->faceAnimTexOffset * 4, 0, (data->faceAnimTexOffset + 124) * 4, 31 * 4);
}

void entity_Tweester_setupGfx(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    TweesterData* data = entity->dataBuf.tweester;

    gDPPipeSync(gMainGfxPos++);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gSPTexture(gMainGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_ALT_INTERFERENCE, G_CC_MODULATEIA2);
    gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 32, D_0A000BF0_E57A50);
    gDPSetTile(gMainGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(gMainGfxPos++);
    gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x007C, 0x007C);
    gDPPipeSync(gMainGfxPos++);
    gDPSetTile(gMainGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);
    gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 32, D_0A000FF0_E57E50);
    gDPSetTile(gMainGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0080, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(gMainGfxPos++);
    gDPLoadTile(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 0x007C, 0x007C);
    gDPPipeSync(gMainGfxPos++);
    gDPSetTile(gMainGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0080, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize(gMainGfxPos++, 1, 0, 0, 0x007C, 0x007C);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, data->innerWhirlTexOffsetX, data->innerWhirlTexOffsetY, data->innerWhirlTexOffsetX + 124, data->innerWhirlTexOffsetY + 124);
    entity_Tweester_render_inner_whirl(entityIndex);
    gDPPipeSync(gMainGfxPos++);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, data->outerWhirlTexOffsetX, data->outerWhirlTexOffsetY, data->outerWhirlTexOffsetX + 124, data->outerWhirlTexOffsetY + 124);
    entity_Tweester_render_outer_whirl(entityIndex);
    entity_Tweester_render_face(entityIndex);
}


void entity_Tweester_update_face_anim(Entity* entity) {
    TweesterData* data = entity->dataBuf.tweester;
    s32 i;

    data->faceAnimTimer--;
    if (data->faceAnimTimer <= 0) {
        i = data->faceAnimState;
        if (Entity_Tweester_FaceAnimationData[i] == 255) {
            i = 0;
        }
        data->faceAnimTexOffset = Entity_Tweester_FaceAnimationData[i++];
        data->faceAnimTimer = Entity_Tweester_FaceAnimationData[i++];
        data->faceAnimState = i;
    }
}

s32 entity_Tweester_has_reached_target(Entity* entity) {
    TweesterData* data = entity->dataBuf.tweester;
    s32 count = 0;
    f32 deltaX = fabsf(data->targetX - entity->pos.x);
    f32 deltaZ = fabsf(data->targetZ - entity->pos.z);

    if (deltaX <= 10.0f) {
        count++;
    }
    if (deltaZ <= 10.0f) {
        count++;
    }

    return count >= 2;
}

void entity_Tweester_select_target_point(Entity* entity) {
    TweesterData* data = entity->dataBuf.tweester;
    s32 pathOffset;
    s32** paths;
    s32 i, j;
    s32* pathPtr;

    pathOffset = data->pathOffset;
    paths = data->paths;

    if (pathOffset == 0) {
        for (i = 0; *paths != PTR_LIST_END; paths++, i++) {
        }
        j = rand_int(i * 10 - 1) / 10;
        paths = data->paths;
        data->curPath = paths[j];
    }
    pathPtr = &data->curPath[pathOffset];
    if (*pathPtr != TWEESTER_PATH_STOP) {
        pathOffset += 3;
        if (*pathPtr == TWEESTER_PATH_LOOP){
            pathOffset = 0;
            pathPtr = data->curPath;
            data->targetX = *pathPtr++;
            data->targetY = *pathPtr++;
            data->targetZ = *pathPtr++;
        } else {
            data->targetX = *pathPtr++;
            data->targetY = *pathPtr++;
            data->targetZ = *pathPtr++;
        }
    }
    data->pathOffset = pathOffset;
}

void entity_Tweester_move(Entity* entity) {
    TweesterData* data = entity->dataBuf.tweester;
    f32 yawRad;

    f32 temp_f4 = (atan2(entity->pos.x, entity->pos.z, data->targetX, data->targetZ) - data->yaw) * 0.03125f;
    if (temp_f4 >= 0.0f && temp_f4 < 0.01) {
        temp_f4 = 0.01f;
    }
    if (temp_f4 < 0.0f && temp_f4 > -0.01) {
        temp_f4 = -0.01f;
    }

    data->yaw = clamp_angle(data->yaw + temp_f4);
    yawRad = DEG_TO_RAD(data->yaw);
    entity->pos.x += sin_rad(yawRad);
    entity->pos.z -= cos_rad(yawRad);

    if (entity_Tweester_has_reached_target(entity)) {
        entity_Tweester_select_target_point(entity);
    }
}

void entity_Tweester_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerData* playerData = &gPlayerData;
    TweesterData* data = entity->dataBuf.tweester;
    f32 delta;
    f32 targetRotationSpeed;

    if (get_time_freeze_mode() == TIME_FREEZE_NONE &&
        !is_picking_up_item() &&
        !(playerStatus->flags & PS_FLAG_PAUSED) &&
        (playerData->curPartner != PARTNER_GOOMBARIO ||
         playerStatus->inputDisabledCount == 0 ||
         playerStatus->actionState == ACTION_STATE_USE_TWEESTER
        )) {
        entity_Tweester_move(entity);
    }

    entity_Tweester_update_face_anim(entity);
    data->frameCounter++;

    if (data->frameCounter < 100) {
        targetRotationSpeed = 3.5f;
        delta = (targetRotationSpeed - data->rotSpeed) / 28.0f;
        if (delta < 0.02) {
            delta = 0.02f;
        }
        data->rotSpeed += delta;
        if (data->rotSpeed >= targetRotationSpeed){
            data->rotSpeed = targetRotationSpeed;
        }
    } else {
        targetRotationSpeed = 1.3f;
        delta = (targetRotationSpeed - data->rotSpeed) * 0.0625f;
        if (delta > -0.02) {
            delta = -0.02f;
        }
        data->rotSpeed += delta;
        if (data->rotSpeed <= targetRotationSpeed){
            data->rotSpeed = targetRotationSpeed;
            data->frameCounter = 0;
        }
    }

    data->innerWhirlRotY += data->rotSpeed;
    if (data->innerWhirlRotY > 360.0f) {
        data->innerWhirlRotY = 0.0f;
    }

    delta = data->innerWhirlRotY - data->outerWhirlRotY;
    if (delta < 0.0f) {
        delta += 360.0f;
    }
    delta *= 0.25;
    data->outerWhirlRotY += delta;
    if (data->outerWhirlRotY > 360.0f) {
        data->outerWhirlRotY = 0.0f;
    }

    data->innerWhirlTexOffsetX += 4;
    data->innerWhirlTexOffsetY -= 8;
    data->outerWhirlTexOffsetX += 4;
    data->outerWhirlTexOffsetY -= 16;

    entity->rot.y = -gCameras[CAM_DEFAULT].curYaw;

    if (partnerStatus->partnerActionState == PARTNER_ACTION_NONE || partnerStatus->actingPartner != PARTNER_BOW) {
        if (playerStatus->actionState == ACTION_STATE_USE_TWEESTER) {
            Npc* npc = npc_find_closest_simple(entity->pos.x, entity->pos.y, entity->pos.z, 50.0f);
            if (npc != NULL && (npc->flags & NPC_FLAG_PARTNER)) {
                TweesterTouchingPartner = entity;
            }
        }

        if (!is_picking_up_item() &&
            !(playerStatus->flags & PS_FLAG_PAUSED) &&
            playerStatus->actionState != ACTION_STATE_USE_TWEESTER &&
            playerStatus->blinkTimer == 0 &&
            fabs(dist2D(entity->pos.x, entity->pos.z, playerStatus->pos.x, playerStatus->pos.z)) <= 50.0
            ) {
            TweesterTouchingPlayer = entity;
            playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
            set_action_state(ACTION_STATE_USE_TWEESTER);
        }
    }
}

void entity_Tweester_anim_scale(Entity* entity) {
    entity->scale.x += 0.1;
    if (entity->scale.x >= 1.0) {
        entity->scale.x = 1.0f;
    }
    entity->scale.z = entity->scale.y = entity->scale.x;
}

void entity_Tweester_init(Entity* entity) {
    TweesterData* data = entity->dataBuf.tweester;

    data->paths = (s32**)CreateEntityVarArgBuffer[0];
    entity_Tweester_select_target_point(entity);
    data->faceAnimTexOffset = 0;
    entity->renderSetupFunc = entity_Tweester_setupGfx;
    entity->scale.x = 0;
    entity->scale.y = 0;
    entity->scale.z = 0;
}

EntityScript Entity_Tweester_Script ={
    es_SetCallback(entity_Tweester_anim_scale, 20)
    es_SetCallback(entity_Tweester_idle, 0)
    es_End
};

EntityModelScript Entity_Tweester_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_Tweester_Render, RENDER_MODE_SURFACE_XLU_LAYER1);

EntityBlueprint Entity_Tweester = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION,
    .typeDataSize = sizeof(TweesterData),
    .renderCommandList = Entity_Tweester_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_Tweester_init,
    .updateEntityScript = Entity_Tweester_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(Tweester) },
    .entityType = ENTITY_TYPE_TWEESTER,
    .aabbSize = { 50, 70, 50 }
};

