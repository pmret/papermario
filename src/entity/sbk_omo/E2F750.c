#include "common.h"
#include "entity_script.h"
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

    guMtxL2F(sp18, (Mtx*)((s32)entity->vertexData + (u16)&Entity_Tweester_mtxInnerWhirl));
    guRotateF(sp58, data->innerWhirlRotY, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &data->mtxInnerWhirl);
    gDisplayContext->matrixStack[gMatrixListPos] = data->mtxInnerWhirl;
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gfx = (Gfx*)((s32)entity->vertexData + (u16)Entity_Tweester_RenderInnerWhirl);
    gSPDisplayList(gMasterGfxPos++, gfx);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void entity_Tweester_render_outer_whirl(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    TweesterData* data = entity->dataBuf.tweester;
    Matrix4f sp18;
    Matrix4f sp58;
    Gfx* gfx;

    guMtxL2F(sp18, (Mtx*)((s32)entity->vertexData + (u16)&Entity_Tweester_mtxOuterWhirl));
    guRotateF(sp58, data->outerWhirlRotY, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guMtxF2L(sp18, &data->mtxOuterWhirl);
    gDisplayContext->matrixStack[gMatrixListPos] = data->mtxOuterWhirl;
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gfx = (Gfx*)((s32)entity->vertexData + (u16)Entity_Tweester_RenderOuterWhirl);
    gSPDisplayList(gMasterGfxPos++, gfx);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

void entity_Tweester_render_face(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    TweesterData* data = entity->dataBuf.tweester;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMasterGfxPos++, 0, D_0A0018A0_E58700);
    gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPLoadTextureBlock_4b(gMasterGfxPos++, D_0A0014A0_E58300, G_IM_FMT_CI, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, data->faceAnimTexOffset * 4, 0, (data->faceAnimTexOffset + 124) * 4, 31 * 4);
}

s32 entity_Tweester_setupGfx(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    TweesterData* data = entity->dataBuf.tweester;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    gSPTexture(gMasterGfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL1, 0, TEXEL0, 0, TEXEL1, 0, TEXEL0, 0, COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 32, D_0A000BF0_E57A50);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 0x007C, 0x007C);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);
    gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 32, D_0A000FF0_E57E50);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0080, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync(gMasterGfxPos++);
    gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 0x007C, 0x007C);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTile(gMasterGfxPos++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0080, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize(gMasterGfxPos++, 1, 0, 0, 0x007C, 0x007C);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, data->innerWhirlTexOffsetX, data->innerWhirlTexOffsetY, data->innerWhirlTexOffsetX + 124, data->innerWhirlTexOffsetY + 124);
    entity_Tweester_render_inner_whirl(entityIndex);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, data->outerWhirlTexOffsetX, data->outerWhirlTexOffsetY, data->outerWhirlTexOffsetX + 124, data->outerWhirlTexOffsetY + 124);
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
    f32 deltaX = fabsf(data->targetX - entity->position.x);
    f32 deltaZ = fabsf(data->targetZ - entity->position.z);

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
        for (i = 0; *paths != -1; paths++, i++) {
        }
        j = rand_int(i * 10 - 1) / 10;
        paths = data->paths;
        data->currentPath = paths[j];
    }
    pathPtr = &data->currentPath[pathOffset];
    if (*pathPtr != 0x80000000) {
        pathOffset += 3;
        if (*pathPtr == 0x80000001){
            pathOffset = 0;
            pathPtr = data->currentPath;
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

    f32 temp_f4 = (atan2(entity->position.x, entity->position.z, data->targetX, data->targetZ) - data->yaw) * 0.03125f;
    if (temp_f4 >= 0.0f && temp_f4 < 0.01) {
        temp_f4 = 0.01f;
    }
    if (temp_f4 < 0.0f && temp_f4 > -0.01) {
        temp_f4 = -0.01f;
    }

    data->yaw = clamp_angle(data->yaw + temp_f4);
    yawRad = data->yaw * TAU / 360.0f;
    entity->position.x += sin_rad(yawRad);
    entity->position.z -= cos_rad(yawRad);

    if (entity_Tweester_has_reached_target(entity)) {
        entity_Tweester_select_target_point(entity);
    }
}

void entity_Tweester_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerData* playerData = &gPlayerData;
    TweesterData* data = entity->dataBuf.tweester;
    f32 delta;
    f32 targetRotationSpeed;

    if (get_time_freeze_mode() == TIME_FREEZE_NORMAL &&
        !is_picking_up_item() &&
        !(playerStatus->flags & PLAYER_STATUS_FLAGS_20) &&
        (playerData->currentPartner != PARTNER_GOOMBARIO ||
         playerStatus->inputEnabledCounter == 0 ||
         playerStatus->actionState == ACTION_STATE_USE_TWEESTER
        )) {
        entity_Tweester_move(entity);
    }

    entity_Tweester_update_face_anim(entity);
    data->frameCounter++;

    if (data->frameCounter < 100) {
        targetRotationSpeed = 3.5f;
        delta = (targetRotationSpeed - data->rotationSpeed) / 28.0f;
        if (delta < 0.02) {
            delta = 0.02f;
        }
        data->rotationSpeed += delta;
        if (data->rotationSpeed >= targetRotationSpeed){
            data->rotationSpeed = targetRotationSpeed;
        }
    } else {
        targetRotationSpeed = 1.3f;
        delta = (targetRotationSpeed - data->rotationSpeed) * 0.0625f;
        if (delta > -0.02) {
            delta = -0.02f;
        }
        data->rotationSpeed += delta;
        if (data->rotationSpeed <= targetRotationSpeed){
            data->rotationSpeed = targetRotationSpeed;
            data->frameCounter = 0;
        }
    }

    data->innerWhirlRotY += data->rotationSpeed;
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

    entity->rotation.y = -gCameras[CAM_DEFAULT].currentYaw;

    if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE || partnerActionStatus->actingPartner != PARTNER_BOW) {
        if (playerStatus->actionState == ACTION_STATE_USE_TWEESTER) {
            Npc* npc = npc_find_closest_simple(entity->position.x, entity->position.y, entity->position.z, 50.0f);
            if (npc != NULL && (npc->flags & NPC_FLAG_PARTICLE)) {
                TweesterTouchingPartner = entity;
            }
        }

        if (!is_picking_up_item() &&
            !(playerStatus->flags & PLAYER_STATUS_FLAGS_20) &&
            playerStatus->actionState != ACTION_STATE_USE_TWEESTER &&
            playerStatus->blinkTimer == 0 &&
            fabs(dist2D(entity->position.x, entity->position.z, playerStatus->position.x, playerStatus->position.z)) <= 50.0
            ) {
            TweesterTouchingPlayer = entity;
            playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_4;
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

    data->paths = CreateEntityVarArgBuffer[0];
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

EntityBlueprint D_802BCA74_E313C4 = {
    .flags = ENTITY_FLAGS_SKIP_UPDATE_INVERSE_ROTATION_MATRIX,
    .typeDataSize = sizeof(TweesterData),
    .renderCommandList = Entity_Tweester_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_Tweester_init,
    .updateEntityScript = Entity_Tweester_Script,
    .fpHandleCollision = NULL,
    {{ entity_model_Tweester_ROM_START, entity_model_Tweester_ROM_END }},
    .entityType = ENTITY_TYPE_TWEESTER,
    .aabbSize = { 50, 70, 50 }
};

