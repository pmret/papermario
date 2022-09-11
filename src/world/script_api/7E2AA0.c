#include "common.h"

void set_current_item_entity_render_group(s32);
s32 get_current_item_entity_render_group(void);
void func_800EF414(s32, s32);
void get_flat_collider_normal(s32, f32*, f32*, f32*);

extern EvtScript D_802847D4_7E5654;
extern EvtScript D_80284F80_7E5E00;

enum DoorScriptType {
    DOOR_SCRIPT_OPEN_DOOR           = 0,
    DOOR_SCRIPT_MOVE_WALLS          = 1,
    DOOR_SCRIPT_DROP_DOOR           = 2,
    DOOR_SCRIPT_TOGGLE_VIS          = 3,
};

typedef enum DoorState {
    DOOR_STATE_0                    = 0,
} DoorState;

typedef struct AdvancedDoor {
    /* 0x00 */ DoorState state;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 newItemVisGroup;
    /* 0x0A */ s16 prevItemVisGroup;
    /* 0x0C */ VecXZf unk_0C;
    /* 0x14 */ VecXZf unk_14;
    /* 0x1C */ VecXZf unk_1C;
    /* 0x24 */ VecXZf unk_24;
    /* 0x2C */ EvtScript* scripts[4];
    /* 0x3C */ s32 modelID;
    /* 0x40 */ s32 bgColor[3];
    /* 0x4C */ s32 scriptIDs[4];
    /* 0x5C */ s32* npcList;
    /* 0x60 */ s32 colliderID;
} AdvancedDoor; // size = 0x64

ApiStatus func_80281C20(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    func_800EF414(evt_get_variable(script, *args++), evt_get_variable(script, *args++));
    partner_set_tether_distance(0.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80281C84(Evt* script, s32 isInitialCall) {
    func_800EF3E4();
    repartner_set_tether_distance();
    return ApiStatus_DONE2;
}

ApiStatus MakeDoorAdvanced(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    AdvancedDoor* door = heap_malloc(sizeof(*door));
    EvtScript* openDoorScript;
    EvtScript* moveWallsScript;
    EvtScript* dropDoorScript;
    EvtScript* toggleVisScript;
    s32 colliderID;
    s32 triggerColliderID;
    s32 visGroups;
    s32 orientation;
    f32 centerX, centerZ;
    f32 nX, nZ;
    f32 tempY;

    door->state = DOOR_STATE_0;
    visGroups = evt_get_variable(script, *args++);
    door->unk_04 = visGroups & 0xFFF;
    door->newItemVisGroup = (visGroups & 0xF000) >> 0xC;
    door->prevItemVisGroup = 0;
    openDoorScript  = (EvtScript*) evt_get_variable(script, *args++);
    moveWallsScript = (EvtScript*) evt_get_variable(script, *args++);
    dropDoorScript  = (EvtScript*) evt_get_variable(script, *args++);
    toggleVisScript = (EvtScript*) evt_get_variable(script, *args++);
    colliderID = evt_get_variable(script, *args++);
    door->colliderID = colliderID;
    triggerColliderID = evt_get_variable(script, *args++);
    door->modelID = evt_get_variable(script, *args++);
    door->npcList = (s32*) evt_get_variable(script, *args++);
    if (dropDoorScript != 0) {
        visGroups |= 0x800;
        door->unk_04 = visGroups;
    }
    get_collider_center(colliderID, &centerX, &tempY, &centerZ);
    get_flat_collider_normal(colliderID, &nX, &tempY, &nZ);

    orientation = visGroups & 0xFF;
    switch (orientation) {
        case 0:
            door->unk_0C.x = centerX + (nX * 30.0f) - (nZ * 20.0f);
            door->unk_0C.z = centerZ + (nZ * 30.0f) + (nX * 20.0f);
            door->unk_14.x = centerX - (nX * 30.0f);
            door->unk_14.z = centerZ - (nZ * 30.0f);
            break;
        case 5:
            door->unk_0C.x = centerX + (nX * 60.0f) - (nZ * 20.0f);
            door->unk_0C.z = centerZ + (nZ * 60.0f) + (nX * 20.0f);
            door->unk_14.x = centerX - (nX * 30.0f);
            door->unk_14.z = centerZ - (nZ * 30.0f);
            break;
        case 1:
            door->unk_0C.x = centerX + (nX * 30.0f);
            door->unk_0C.z = centerZ + (nZ * 30.0f);
            door->unk_14.x = centerX - (nX * 30.0f) - (nZ * 20.0f);
            door->unk_14.z = centerZ - (nZ * 30.0f) - (nX * 20.0f);
            break;
        case 6:
            door->unk_0C.x = centerX + (nX * 30.0f);
            door->unk_0C.z = centerZ + (nZ * 30.0f);
            door->unk_14.x = centerX - (nX * 60.0f) - (nZ * 20.0f);
            door->unk_14.z = centerZ - (nZ * 60.0f) - (nX * 20.0f);
            break;
        case 2:
            door->unk_0C.x = centerX + (nX * 30.0f) + (nZ * 20.0f);
            door->unk_0C.z = centerZ + (nZ * 30.0f) - (nX * 20.0f);
            door->unk_14.x = centerX - (nX * 30.0f);
            door->unk_14.z = centerZ - (nZ * 30.0f);
            break;
        case 7:
            door->unk_0C.x = centerX + (nX * 60.0f) + (nZ * 20.0f);
            door->unk_0C.z = centerZ + (nZ * 60.0f) - (nX * 20.0f);
            door->unk_14.x = centerX - (nX * 30.0f);
            door->unk_14.z = centerZ - (nZ * 30.0f);
            break;
        case 3:
            door->unk_0C.x = centerX + (nX * 30.0f);
            door->unk_0C.z = centerZ + (nZ * 30.0f);
            door->unk_14.x = centerX - (nX * 30.0f) + (nZ * 20.0f);
            door->unk_14.z = centerZ - (nZ * 30.0f) + (nX * 20.0f);
            break;
        case 4:
            door->unk_0C.x = centerX + (nX * 30.0f);
            door->unk_0C.z = centerZ + (nZ * 30.0f);
            door->unk_14.x = centerX - (nX * 30.0f);
            door->unk_14.z = centerZ - (nZ * 30.0f);
            break;
    }
    door->scripts[0] = openDoorScript;
    door->scripts[1] = moveWallsScript;
    door->scripts[2] = dropDoorScript;
    door->scripts[3] = toggleVisScript;

    door->unk_1C.x = door->unk_14.x;
    door->unk_1C.z = door->unk_14.z;
    door->unk_24.x = door->unk_0C.x;
    door->unk_24.z = door->unk_0C.z;
    
    door->bgColor[0] = gCameras[CAM_DEFAULT].bgColor[0];
    door->bgColor[1] = gCameras[CAM_DEFAULT].bgColor[1];
    door->bgColor[2] = gCameras[CAM_DEFAULT].bgColor[2];

    bind_trigger_1(&D_802847D4_7E5654, 0x100, colliderID, 0, (s32) door, 3);
    if (visGroups & 0x800) {
        bind_trigger_1(&D_80284F80_7E5E00, 0x40, triggerColliderID, 1, (s32) door, 3);
    } else {
        bind_trigger_1(&D_80284F80_7E5E00, 0x100, triggerColliderID, 1, (s32) door, 3);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802822A8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    AdvancedDoor* door = script->functionTempPtr[1];
    s32 sound = evt_get_variable(script, *args++);
    f32 posX, posY, posZ;

    get_collider_center(door->colliderID, &posX, &posY, &posZ);
    sfx_play_sound_at_position(sound, 0, posX, posY, posZ);
    return ApiStatus_DONE2;
}

ApiStatus func_80282314(Evt* script, s32 isInitialCall) {
    script->functionTemp[1] = script->varTable[1];
    return ApiStatus_DONE2;
}

ApiStatus GetDoorState(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->functionTempPtr[1];
    
    script->varTable[0] = door->state;
    return ApiStatus_DONE2;
}

ApiStatus SetDoorState(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->functionTempPtr[1];

    door->state = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
ApiStatus func_8028236C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    AdvancedDoor* door = script->functionTempPtr[1];
    s32 index = evt_get_variable(script, *args++);

    if (does_script_exist(door->scriptIDs[index])) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

ApiStatus func_802823B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    AdvancedDoor* door = script->functionTempPtr[1];
    s32 index = evt_get_variable(script, *args++);
    s32 scriptID = evt_get_variable(script, *args++);
    
    door->scriptIDs[index] = scriptID;
    return ApiStatus_DONE2;
}

ApiStatus func_80282414(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->varTablePtr[1];
    s32 alpha, r, g, b;
    
    if (isInitialCall) {
        if (script->varTable[0] == 0) {
            func_8011B950(script->varTable[15], -1, 1, 1);
        }
        script->functionTemp[1] = 0;
    }
    script->functionTemp[1] += 32;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }
    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[1];
    } else {
        alpha = 255 - script->functionTemp[1];
    }
    set_background_color_blend(0, 0, 0, alpha);
    r = door->bgColor[0] * (255 - alpha) / 255;
    g = door->bgColor[1] * (255 - alpha) / 255;
    b = door->bgColor[2] * (255 - alpha) / 255;
    gCameras[CAM_DEFAULT].bgColor[0] = r;
    gCameras[CAM_DEFAULT].bgColor[1] = g;
    gCameras[CAM_DEFAULT].bgColor[2] = b;
    
    if (script->functionTemp[1] >= 255) {
        if (script->varTable[0] == 3) {
            func_8011B950(script->varTable[15], -1, 0, 1);
        }
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80282594(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 newMoveSpeed = evt_get_float_variable(script, *args++);
    Camera* camera = &gCameras[CAM_DEFAULT];
    static f32 savedCamMoveSpeed;

    if (newMoveSpeed >= 0.0f) {
        savedCamMoveSpeed = camera->moveSpeed;
        camera->moveSpeed = newMoveSpeed;
    } else {
        camera->moveSpeed = savedCamMoveSpeed;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetEntityHideMode1(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 1;
    return ApiStatus_DONE2;
}

ApiStatus SetEntityHideMode2(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 2;
    return ApiStatus_DONE2;
}

ApiStatus SetEntityHideMode0(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80282634(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->functionTempPtr[1];
    s32* npcList = door->npcList;
    s32 endOfList;
    s32 mask;
    s32 i;
    
    if (npcList == NULL) {
        return ApiStatus_DONE2;
    }
    
    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = get_npc_by_index(i);
        if (npc != NULL) {
            if ((npc->flags != 0) && (npc->npcID != NPC_PARTNER)) {
                npc->flags |= NPC_FLAG_NO_DROPS;
            }
        }
    }

    endOfList = -1;
    mask = ~NPC_FLAG_NO_DROPS;

    do {
        Npc* npc;
        if (*npcList == endOfList) {
            return ApiStatus_DONE2;
        }
        npc = get_npc_safe(*npcList++);
        if (npc != NULL) {
            npc->flags &= mask; 
        }
    } while (TRUE);
    
    return ApiStatus_DONE2;
}

ApiStatus func_80282700(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->functionTempPtr[1];
    s32 i;

    if (door->npcList == NULL) {
        return ApiStatus_DONE2;
    }
    
    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = get_npc_by_index(i);
        if (npc != NULL) {
            if (npc->flags != 0) {
                npc->flags &= ~NPC_FLAG_NO_DROPS;
            }
        }
    }
    
    return ApiStatus_DONE2;
}

ApiStatus SetNewItemVisGroup(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->functionTempPtr[1];

    door->prevItemVisGroup = get_current_item_entity_render_group();
    set_current_item_entity_render_group(door->newItemVisGroup);
    return ApiStatus_DONE2;
}

ApiStatus RestorePrevItemVisGroup(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->functionTempPtr[1];
    
    set_current_item_entity_render_group(door->prevItemVisGroup);
    return ApiStatus_DONE2;
}

ApiStatus GetDoorData(Evt* script, s32 isInitialCall) {
    AdvancedDoor* door = script->functionTempPtr[1];

    script->varTable[2] = door->unk_04;
    script->varTable[3] = door->unk_0C.x;
    script->varTable[4] = door->unk_0C.z;
    script->varTable[5] = door->unk_14.x;
    script->varTable[6] = door->unk_14.z;
    script->varTable[7] = door->unk_1C.x;
    script->varTable[8] = door->unk_1C.z;
    script->varTable[9] = door->unk_24.x;
    script->varTable[10] = door->unk_24.z;
    script->varTablePtr[11] = door->scripts[0];
    script->varTablePtr[12] = door->scripts[1];
    script->varTablePtr[13] = door->scripts[2];
    script->varTablePtr[14] = door->scripts[3];
    script->varTable[15] = door->modelID;
    return ApiStatus_DONE2;
}

ApiStatus GetDoorPtr(Evt* script, s32 isInitialCall) {
    script->varTable[1] = script->functionTemp[1];
    return ApiStatus_DONE2;
}
