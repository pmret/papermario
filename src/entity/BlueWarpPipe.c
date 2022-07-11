#include "common.h"
#include "npc.h"
#include "sprite.h"
#include "ld_addrs.h"
#include "entity.h"

extern Gfx Entity_BlueWarpPipe_RenderPipe[];
extern Gfx Entity_BlueWarpPipe_RenderBase[];

void entity_BlueWarpPipe_setupGfx(s32 entityIndex);

void entity_BlueWarpPipe_check_if_active(Entity* entity) {
    BlueWarpPipeData* pipeData;

    pipeData = entity->dataBuf.bluePipe;
    if (get_global_flag(pipeData->flagIndex)) {
        pipeData->timer = 16;
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_rise_up(Entity* entity) {
    BlueWarpPipeData* pipeData = entity->dataBuf.bluePipe;

    pipeData->timer--;
    if ((pipeData->timer != -1) && (pipeData->isRaised == 0)) {
        entity->position.y += 2.3125;
    } else {
        pipeData->timer = 0;
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_wait_for_player_to_get_off(Entity* entity) {
    BlueWarpPipeData* pipeData = entity->dataBuf.bluePipe;

    if (pipeData->entryID == gGameStatusPtr->entryID) {
        switch (pipeData->timer) {
            case 0:
                if (gCollisionStatus.currentFloor > 0) {
                    pipeData->timer = 1;
                }
                break;
            case 1:
                if (gCollisionStatus.currentFloor < 0) {
                    pipeData->timer = 2;
                }
                break;
            default:
                exec_entity_commandlist(entity);
                break;
        }
    } else {
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) != 0) {
        gOverrideFlags |= GLOBAL_OVERRIDES_40;

        if (!(playerStatus->flags & (PLAYER_STATUS_FLAGS_1000 | PLAYER_STATUS_FLAGS_INPUT_DISABLED))) {
            s32 stickAxisX = abs(playerStatus->stickAxis[0]);
            s32 stickAxisZ = playerStatus->stickAxis[1];

            if ((stickAxisX != 0) || (stickAxisZ != 0)) {
                if (atan2(0.0f, 0.0f, stickAxisX, stickAxisZ) < 60.0f) {
                    exec_entity_commandlist(entity);
                }
            }
        }
    } else {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
    }
}

void entity_BlueWarpPipe_set_player_move_to_center(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlueWarpPipeData* pipeData = entity->dataBuf.bluePipe;
    MapConfig* mapConfig = get_current_map_header();
    f32 angle;
    f32 entryX;
    f32 entryZ;

    entryX = (*mapConfig->entryList)[pipeData->entryID].x;
    entryZ = (*mapConfig->entryList)[pipeData->entryID].z;
    pipeData->timer = get_xz_dist_to_player(entryX, entryZ) / playerStatus->runSpeed;
    if (pipeData->timer == 0) {
        pipeData->timer = 1;
    }

    entryX = (*mapConfig->entryList)[pipeData->entryID].x;
    entryZ = (*mapConfig->entryList)[pipeData->entryID].z;
    angle = atan2(playerStatus->position.x, playerStatus->position.z, entryX, entryZ);
    disable_player_input();
    disable_player_static_collisions();
    move_player(pipeData->timer, angle, playerStatus->runSpeed);
}

void entity_BlueWarpPipe_wait_player_move_to_center(Entity* entity) {
    BlueWarpPipeData* pipeData = entity->dataBuf.bluePipe;

    if (--pipeData->timer == -1) {
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_enter_pipe_init(Entity* bluePipe) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlueWarpPipeData* pipeData = bluePipe->dataBuf.bluePipe;

    playerStatus->targetYaw = gCameras[gCurrentCameraID].currentYaw + 180.0f;
    pipeData->timer = 25;
    playerStatus->renderMode = RENDER_MODE_ALPHATEST;

    func_802DDFF8(0x10002, 5, 2, 1, 1, 0, 0);
    sfx_play_sound(SOUND_ENTER_PIPE);
    disable_player_shadow();
}

void entity_BlueWarpPipe_enter_pipe_update(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlueWarpPipeData* pipeData = entity->dataBuf.bluePipe;

    playerStatus->position.y--;
    pipeData->timer--;

    if (pipeData->timer == -1) {
        playerStatus->renderMode = RENDER_MODE_ALPHATEST;
        playerStatus->position.y -= 50.0f;
        func_802DDFF8(0x10002, 0, 0, 0, 0, 0, 0);
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_start_bound_script(Entity* entity) {
    EvtScript* triggerScriptStart = entity->dataBuf.bluePipe->onEnterPipeEvt;

    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
    entity->boundScriptBytecode = triggerScriptStart;
    entity_start_script(entity);
}

void entity_BlueWarpPipe_setupGfx(s32 entityIndex) {
    Gfx* gfxPos = gMasterGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);
    BlueWarpPipeData* data = entity->dataBuf.bluePipe;
    Matrix4f sp10;
    Matrix4f sp50;

    guScaleF(sp10, entity->scale.x, entity->scale.y, entity->scale.z);
    guTranslateF(sp50, entity->position.x, data->finalPosY + 1.0f, entity->position.z);
    guMtxCatF(sp10, sp50, sp50);
    guMtxF2L(sp50, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfxPos++, Entity_BlueWarpPipe_RenderBase);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);
    gMasterGfxPos = gfxPos;
}

void entity_init_BlueWarpPipe(Entity* entity) {
    BlueWarpPipeData* data;
    s32 entryID = CreateEntityVarArgBuffer[0];
    EvtScript* enterPipeEvt = (EvtScript*)CreateEntityVarArgBuffer[1];
    s32 flagIndex = CreateEntityVarArgBuffer[2];

    entity->renderSetupFunc = &entity_BlueWarpPipe_setupGfx;

    data = entity->dataBuf.bluePipe;
    data->entryID = entryID;
    data->onEnterPipeEvt = enterPipeEvt;
    data->flagIndex = flagIndex;
    data->finalPosY = entity->position.y;
    data->isRaised = get_global_flag(data->flagIndex);

    entity->position.y -= (data->isRaised ? 15.0 : 52.0);
}

EntityScript Entity_BlueWarpPipe_Script = {
    es_SetCallback(entity_BlueWarpPipe_check_if_active, 0)
    es_SetCallback(entity_BlueWarpPipe_rise_up, 0)
    es_SetCallback(entity_BlueWarpPipe_wait_for_player_to_get_off, 0)
    es_SetCallback(entity_BlueWarpPipe_idle, 0)
    es_Call(entity_BlueWarpPipe_set_player_move_to_center)
    es_SetCallback(entity_BlueWarpPipe_wait_player_move_to_center, 0)
    es_Call(entity_BlueWarpPipe_enter_pipe_init)
    es_SetCallback(entity_BlueWarpPipe_enter_pipe_update, 0)
    es_Call(entity_BlueWarpPipe_start_bound_script)
    es_End
};

EntityModelScript Entity_BlueWarpPipe_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_BlueWarpPipe_RenderPipe, RENDER_MODE_SURFACE_OPA);

EntityBlueprint Entity_BlueWarpPipe = {
    .flags = 0,
    .typeDataSize = sizeof(BlueWarpPipeData),
    .renderCommandList = Entity_BlueWarpPipe_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_init_BlueWarpPipe,
    .updateEntityScript = Entity_BlueWarpPipe_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(BlueWarpPipe) },
    .entityType = ENTITY_TYPE_BLUE_WARP_PIPE,
    .aabbSize = { 40, 50, 40}
};
