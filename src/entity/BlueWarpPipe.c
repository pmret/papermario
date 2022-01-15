#include "common.h"
#include "npc.h"
#include "sprite.h"

typedef struct BlueWarpPipeData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 timer;
    /* 0x08 */ s32 isRaised;
    /* 0x0C */ s32 entryID;
    /* 0x10 */ EvtScript* onEnterPipeEvt;
    /* 0x14 */ s32 flagIndex;
    /* 0x18 */ f32 finalPosY;
} BlueWarpPipeData;

void entity_BlueWarpPipe_setupGfx();

void entity_BlueWarpPipe_check_if_active(Entity* entity) {
    BlueWarpPipeData* pipeData;

    pipeData = entity->dataBuf;
    if (get_global_flag(pipeData->flagIndex)) {
        pipeData->timer = 0x10;
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_rise_up(Entity* entity) {
    BlueWarpPipeData* pipeData = entity->dataBuf;

    pipeData->timer--;
    if ((pipeData->timer != -1) && (pipeData->isRaised == 0)) {
        entity->position.y += 2.3125;
    } else {
        pipeData->timer = 0;
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_wait_for_player_to_get_off(Entity* entity) {
    BlueWarpPipeData* pipeData = entity->dataBuf;

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

    if ((entity->collisionFlags & 1) != 0) {
        gOverrideFlags |= 0x40;

        if (!(playerStatus->flags & 0x3000)) {
            s32 stickAxis0 = abs(playerStatus->stickAxis[0]);
            s32 stickAxis1 = playerStatus->stickAxis[1];

            if ((stickAxis0 != 0) || (stickAxis1 != 0)) {
                if (atan2(0.0f, 0.0f, stickAxis0, stickAxis1) < 60.0f) {
                    exec_entity_commandlist(entity);
                }
            }
        }
    } else {
        gOverrideFlags &= ~0x40;
    }
}

void entity_BlueWarpPipe_set_player_move_to_center(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlueWarpPipeData* pipeData = entity->dataBuf;
    MapConfig* mapConfig = get_current_map_header();
    f32 temp_f20;
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
    temp_f20 = atan2(playerStatus->position.x, playerStatus->position.z, entryX, entryZ);
    disable_player_input();
    disable_player_static_collisions();
    move_player(pipeData->timer, temp_f20, playerStatus->runSpeed);
}

void entity_BlueWarpPipe_wait_player_move_to_center(Entity* entity) {
    BlueWarpPipeData* pipeData = (BlueWarpPipeData*)entity->dataBuf;

    if (--pipeData->timer == -1) {
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_enter_pipe_init(Entity* bluePipe) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlueWarpPipeData* pipeData = (BlueWarpPipeData*)bluePipe->dataBuf;

    playerStatus->targetYaw = gCameras[gCurrentCameraID].currentYaw + 180.0f;
    pipeData->timer = 25;
    playerStatus->renderMode = 0xD;

    func_802DDFF8(0x10002, 5, 2, 1, 1, 0, 0);
    sfx_play_sound(0x163);
    disable_player_shadow();
}

void entity_BlueWarpPipe_enter_pipe_update(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    BlueWarpPipeData* pipeData = (BlueWarpPipeData*)entity->dataBuf;

    playerStatus->position.y--;
    pipeData->timer--;

    if (pipeData->timer == -1) {
        playerStatus->renderMode = 0xD;
        playerStatus->position.y -= 50.0f;
        func_802DDFF8(0x10002, 0, 0, 0, 0, 0, 0);
        exec_entity_commandlist(entity);
    }
}

void entity_BlueWarpPipe_start_bound_script(Entity* entity) {
    Bytecode* triggerScriptStart = ((BlueWarpPipeData*)entity->dataBuf)->onEnterPipeEvt;

    gOverrideFlags &= ~0x40;
    entity->boundScriptBytecode = triggerScriptStart;
    entity_start_script(entity);
}

INCLUDE_ASM(s32, "entity/BlueWarpPipe", entity_BlueWarpPipe_setupGfx);

f32 entity_init_BlueWarpPipe(Entity* entity) {
    BlueWarpPipeData* data;
    s32* args = &CreateEntityVarArgBuffer;
    s32 entryID;
    s32 enterPipeEvt;
    s32 flagIndex;
    f32* temp5;

    entryID = args[0];
    enterPipeEvt = args[1];
    flagIndex = args[2];
    entity->renderSetupFunc = &entity_BlueWarpPipe_setupGfx;
    data = entity->dataBuf;
    temp5 = &entity->position.y; // required... wtf
    data->entryID = entryID;
    data->onEnterPipeEvt = enterPipeEvt;
    data->flagIndex = flagIndex;
    data->finalPosY = entity->position.y;
    data->isRaised = get_global_flag(data->flagIndex);
    *temp5 = entity->position.y - (data->isRaised ? 15.0 : 52.0);
}
