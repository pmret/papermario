#include "common.h"
#include "effects.h"
#include "entity.h"
#include "ld_addrs.h"

extern Gfx Entity_StarBoxLauncher_RenderBottom[];
extern Gfx Entity_StarBoxLauncher_RenderTop[];
extern unsigned char D_0A000D08_E56748[];
extern unsigned char D_0A000508_E55F48[];

u8 D_802BCAA0_E313F0[] = {
    0x00, 0x02,
    0xE0, 0x02,
    0xC0, 0x02,
    0xA0, 0x02,
    0x00, 0x02,
    0xE0, 0x02,
    0xC0, 0x02,
    0xA0, 0x02,
    0x00, 0x02,
    0xE0, 0x02,
    0xC0, 0x02,
    0xA0, 0x02,
    0x00, 0x02,
    0xE0, 0x02,
    0xC0, 0x02,
    0xA0, 0x02,
    0x00, 0x02,
    0xFF, 0x00
};

void entity_StarBoxLauncher_setupGfx(s32 entityIndex) {
    Gfx* gfxPos = gMainGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    Matrix4f sp10;
    Matrix4f sp50;

    guMtxIdentF(sp10);
    guTranslateF(sp50, entity->pos.x, data->basePosY, entity->pos.z);
    guMtxCatF(sp50, sp10, sp50);
    guMtxF2L(sp50, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfxPos++, ENTITY_ADDR(entity, Gfx*, Entity_StarBoxLauncher_RenderBottom));
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    gDPPipeSync(gfxPos++);
    gDPSetTextureLUT(gfxPos++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfxPos++, 0, D_0A000D08_E56748);
    gSPTexture(gfxPos++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineMode(gfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetTextureDetail(gfxPos++, G_TD_CLAMP);
    gDPSetTextureLOD(gfxPos++, G_TL_TILE);
    gDPLoadTextureBlock_4b(gfxPos++, D_0A000508_E55F48, G_IM_FMT_CI, 128, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 7, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTexturePersp(gfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gfxPos++, G_TF_BILERP);
    gDPSetTileSize(gfxPos++, G_TX_RENDERTILE, data->faceTexOffset * 4, 0, (data->faceTexOffset + 124) * 4, 31 * 4);

    gMainGfxPos = gfxPos;
}

void entity_StarBoxLauncher_check_launch(Entity* entity) {
    u16 currentFloor = gCollisionStatus.curFloor;
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actionState = playerStatus->actionState;
    f32 x,y,z,hitDepth;
    s32 result = 0;

    if ((currentFloor & COLLISION_WITH_ENTITY_BIT) && (currentFloor & 0xFF) == entity->listIndex && actionState == ACTION_STATE_HAMMER) {
        x = playerStatus->pos.x;
        y = playerStatus->pos.y + 5.0f;
        z = playerStatus->pos.z;
        hitDepth = 10.0f;

        add_vec2D_polar(&x, &z, 10.0f, func_800E5348());
        if (npc_raycast_down_sides(COLLISION_CHANNEL_10000, &x, &y, &z, &hitDepth) != 0) {
            if (NpcHitQueryColliderID & COLLISION_WITH_ENTITY_BIT) {
                result = get_entity_type(NpcHitQueryColliderID) == ENTITY_TYPE_STAR_BOX_LAUCHER;
            }
        }
    } else if ((entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) && (actionState == ACTION_STATE_SPIN_POUND || actionState == ACTION_STATE_TORNADO_POUND)) {
        result = 1;
    } else if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_HAMMER) {
        result = -1;
    }

    if (result != 0) {
        data->flags &= ~1;
        fx_damage_stars(3, entity->pos.x, entity->pos.y + 35.0f, entity->pos.z, 0, -1.0f, 0, 3);
        if (result > 0) {
            data->flags |= 1;
        }
        entity->pos.y -= 2.0f;
        exec_entity_commandlist(entity);
        data->timer = 4;
        disable_player_static_collisions();
        playerStatus->camResetDelay = 5;
    }
}

void entity_StarBoxLauncher_update_face_anim(Entity* entity) {
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    s32 i;

    data->faceAnimTimer--;
    if (data->faceAnimTimer <= 0) {
        i = data->faceDataIndex;
        if (D_802BCAA0_E313F0[i] != 0xFF) {
            data->faceTexOffset = D_802BCAA0_E313F0[i++];
            data->faceAnimTimer = D_802BCAA0_E313F0[i++];
            data->faceDataIndex = i;
        }
    }
}

void entity_StarBoxLauncher_shake_box(Entity* entity) {
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    entity->pos.x = data->basePosX + (data->timer & 1 ? 1.0f : -1.0f);
    data->timer--;
}

void entity_StarBoxLauncher_restore_pos(Entity* entity) {
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    entity->pos.x = data->basePosX;
    entity->pos.z = data->basePosZ;
}

void entity_StarBoxLauncher_launch(Entity* entity) {
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    f64 temp;

    switch (data->state) {
        case 0:
            data->faceAnimTimer = 0;
            data->faceDataIndex = 0;
            data->state++;
            data->riseSpeedPhase = 90.0f;
            data->faceTexOffset = D_802BCAA0_E313F0[0];
            data->faceAnimTimer = D_802BCAA0_E313F0[1];
            sfx_play_sound(SOUND_2085);
            // fallthrough
        case 1:
            temp = entity->pos.y;
            entity->pos.y = temp + 8.0 * sin_rad(DEG_TO_RAD(data->riseSpeedPhase));
            data->riseSpeedPhase += 2.0f;
            if (data->riseSpeedPhase >= 180.0f) {
                data->riseSpeedPhase = 180.0f;
            }

            if (entity->pos.y > data->basePosY + 50.0f) {
                entity->pos.y = data->basePosY + 50.0f;
                data->maxRotZ = 2.0f;
                data->state++;
                data->riseVel = 3.0f;
                data->rotZPhase = 90.0f;
            }
            break;
        case 2:
            entity->rot.z = data->maxRotZ * sin_rad(DEG_TO_RAD(data->rotZPhase));
            clamp_angle(entity->rot.z);
            data->rotZPhase += 30.0f;
            if (data->rotZPhase >= 360.0f) {
                data->rotZPhase -= 360.0f;
            }

            entity->pos.y += data->riseVel * cos_rad(DEG_TO_RAD(data->riseSpeedPhase));
            data->riseSpeedPhase += 30.0f;
            if (data->riseSpeedPhase >= 360.0f) {
                data->riseSpeedPhase -= 360.0f;
            }

            data->riseVel -= 0.08;
            if (data->riseVel < 2.8) {
                data->state++;
            }
            break;
        case 3:
            data->maxRotZ -= 0.1;
            if (data->maxRotZ <= 0.0f) {
                data->maxRotZ = 0.0f;
            }

            entity->rot.z = data->maxRotZ * sin_rad(DEG_TO_RAD(data->rotZPhase));
            clamp_angle(entity->rot.z);
            data->rotZPhase += 30.0f;
            if (data->rotZPhase >= 360.0f) {
                data->rotZPhase -= 360.0f;
            }

            entity_StarBoxLauncher_update_face_anim(entity);

            entity->pos.y += data->riseVel * cos_rad(DEG_TO_RAD(data->riseSpeedPhase));
            data->riseSpeedPhase += 30.0f;
            if (data->riseSpeedPhase >= 360.0f) {
                data->riseSpeedPhase -= 360.0f;
            }

            data->riseVel -= 0.08;
            if (data->riseVel <= 0.0f) {
                data->riseVel = 0.0f;
                data->timer = 8;
                data->state++;
                entity->rot.z = 0.0f;
            }
            break;
        case 4:
            if (--data->timer == 0) {
                data->state++;
            }
            break;
        case 5:
            entity->pos.y -= 8.0f;
            if (entity->pos.y <= data->basePosY) {
                entity->pos.y = data->basePosY;
                data->state++;
            }
            break;
        case 6:
            exec_entity_commandlist(entity);
            data->state = 0;
            enable_player_static_collisions();
            break;
    }
}

void func_802BC99C_E312EC(Entity* entity) {
    if (!(entity->flags & ENTITY_FLAG_2000000)) {
        exec_entity_commandlist(entity);
    }
}

void entity_StarBoxLauncher_start_script(Entity* entity) {
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    if (data->flags & 1) {
        entity_start_script(entity);
    }
}

void entity_StarBoxLauncher_init(Entity* entity) {
    StarBoxLauncherData* data = entity->dataBuf.starBoxLauncher;
    entity->renderSetupFunc = entity_StarBoxLauncher_setupGfx;
    data->basePosX = entity->pos.x;
    data->basePosY = entity->pos.y;
    data->basePosZ = entity->pos.z;
}

EntityScript Entity_StarBoxLauncher_Script = {
    es_SetCallback(entity_StarBoxLauncher_check_launch, 0)
    es_SetCallback(entity_StarBoxLauncher_shake_box, 4)
    es_Call(entity_StarBoxLauncher_restore_pos)
    es_SetCallback(NULL, 3)
    es_Call(entity_StarBoxLauncher_start_script)
    es_SetCallback(NULL, 1)
    es_SetCallback(entity_StarBoxLauncher_launch, 0)
    es_SetCallback(func_802BC99C_E312EC, 0)
    es_Restart
    es_End
};

EntityModelScript Entity_StarBoxLauncher_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_StarBoxLauncher_RenderTop, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_StarBoxLauncher = {
    .flags = ENTITY_FLAG_8000,
    .typeDataSize = sizeof(StarBoxLauncherData),
    .renderCommandList = Entity_StarBoxLauncher_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_StarBoxLauncher_init,
    .updateEntityScript = Entity_StarBoxLauncher_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(StarBoxLauncher) },
    .entityType = ENTITY_TYPE_STAR_BOX_LAUCHER,
    .aabbSize = { 35, 35, 35 }
};
