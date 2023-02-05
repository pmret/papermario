#include "common.h"
#include "model.h"

void set_current_item_entity_render_group(s32);
s32 get_current_item_entity_render_group(void);
void func_800EF414(s32, s32);
void get_flat_collider_normal(s32, f32*, f32*, f32*);

extern EvtScript EVS_EnterRoomDoor;
extern EvtScript EVS_ExitRoomDoor;

enum RoomScriptType {
    DOOR_SCRIPT_OPEN_DOOR           = 0,
    DOOR_SCRIPT_MOVE_WALLS          = 1,
    DOOR_SCRIPT_DROP_DOOR           = 2,
    DOOR_SCRIPT_TOGGLE_VIS          = 3,
};

typedef enum RoomState {
    ROOM_STATE_IDLE             = 0,
    ROOM_STATE_ENTERING         = 1,
    ROOM_STATE_EXITING          = 2,
} RoomState;

enum {
    ROOM_OPEN_DOOR_0            = 0,
    ROOM_OPEN_DOOR_1            = 1,
    ROOM_OPEN_DOOR_2            = 2,
    ROOM_OPEN_DOOR_3            = 3,
};

enum {
    ROOM_MOVE_WALL_0            = 0,
    ROOM_MOVE_WALL_1            = 1,
    ROOM_MOVE_WALL_2            = 2,
    ROOM_MOVE_WALL_3            = 3,
};

enum {
    ROOM_DROP_DOOR_0            = 0,
    ROOM_DROP_DOOR_1            = 1,
    ROOM_DROP_DOOR_2            = 2,
    ROOM_DROP_DOOR_3            = 3,
};

// data fetched with GetDoorData is stored in these local vars
enum {
    ROOM_DATA_FLAGS             = LVar2,
    ROOM_DATA_POS_AX            = LVar3,
    ROOM_DATA_POS_AZ            = LVar4,
    ROOM_DATA_POS_BX            = LVar5,
    ROOM_DATA_POS_BZ            = LVar6,
    ROOM_DATA_POS_CX            = LVar7,
    ROOM_DATA_POS_CZ            = LVar8,
    ROOM_DATA_POS_DX            = LVar9,
    ROOM_DATA_POS_DZ            = LVarA,
    ROOM_DATA_EVT_OPEN_DOOR     = LVarB,
    ROOM_DATA_EVT_MOVE_WALL     = LVarC,
    ROOM_DATA_EVT_DROP_DOOR     = LVarD,
    ROOM_DATA_EVT_TOGGLE_VIS    = LVarE,
    ROOM_DATA_MODEL_ID          = LVarF,
};

enum {
    ROOM_SCRIPT_IDX_0       = 0,
    ROOM_SCRIPT_IDX_1       = 1,
    ROOM_SCRIPT_IDX_2       = 2,
    ROOM_SCRIPT_IDX_3       = 3,
};

typedef struct MapRoom {
    /* 0x00 */ RoomState state;
    /* 0x04 */ s32 flags;
    /* 0x08 */ s16 newItemVisGroup;
    /* 0x0A */ s16 prevItemVisGroup;
    /* 0x0C */ VecXZf posA;
    /* 0x14 */ VecXZf posB;
    /* 0x1C */ VecXZf posC;
    /* 0x24 */ VecXZf posD;
    /* 0x2C */ EvtScript* overrideOpenDoor;
    /* 0x2C */ EvtScript* overrideMoveWall;
    /* 0x2C */ EvtScript* overrideDropDoor;
    /* 0x2C */ EvtScript* toggleVisScript;
    /* 0x3C */ s32 modelID;
    /* 0x40 */ s32 bgColor[3];
    /* 0x4C */ s32 scriptIDs[4];
    /* 0x5C */ s32* npcList;
    /* 0x60 */ s32 colliderID;
} MapRoom; // size = 0x64

API_CALLABLE(func_80281C20) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);

    func_800EF414(posX, posZ);
    partner_set_tether_distance(0.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80281C84) {
    func_800EF3E4();
    partner_reset_tether_distance();
    return ApiStatus_DONE2;
}

/* ARGS:
    s16 group1;
    s16 group2;
    EvtScript* openDoor;
    EvtScript* moveWalls;
    EvtScript* dropDoor;
    EvtScript* toggleVis;
    s32 doorInColliderID;
    s32 doorOutColliderID;
    s32 interiorModelGroup;
    s32* interiorNPCs;
*/
API_CALLABLE(CreateMapRoom) {
    Bytecode* args = script->ptrReadPos;
    MapRoom* room = heap_malloc(sizeof(*room));
    EvtScript* openDoorScript;
    EvtScript* moveWallsScript;
    EvtScript* dropDoorScript;
    EvtScript* toggleVisScript;
    s32 colliderID;
    s32 triggerColliderID;
    s32 roomFlags;
    s32 orientation;
    f32 centerX, centerZ;
    f32 nX, nZ;
    f32 tempY;

    room->state = ROOM_STATE_IDLE;
    roomFlags = evt_get_variable(script, *args++);
    room->flags = roomFlags & (ROOM_FLAGS_MASK | ROOM_FLAGS_DOOR_TYPE_MASK);
    room->newItemVisGroup = (roomFlags & ROOM_FLAGS_VISGROUP_MASK) >> 0xC;
    room->prevItemVisGroup = 0;
    openDoorScript  = (EvtScript*) evt_get_variable(script, *args++);
    moveWallsScript = (EvtScript*) evt_get_variable(script, *args++);
    dropDoorScript  = (EvtScript*) evt_get_variable(script, *args++);
    toggleVisScript = (EvtScript*) evt_get_variable(script, *args++);
    colliderID = evt_get_variable(script, *args++);
    room->colliderID = colliderID;
    triggerColliderID = evt_get_variable(script, *args++);
    room->modelID = evt_get_variable(script, *args++);
    room->npcList = (s32*) evt_get_variable(script, *args++);
    if (dropDoorScript != 0) {
        roomFlags |= ROOM_FLAG_800;
        room->flags = roomFlags;
    }
    get_collider_center(colliderID, &centerX, &tempY, &centerZ);
    get_flat_collider_normal(colliderID, &nX, &tempY, &nZ);

    orientation = roomFlags & 0xFF;
    switch (orientation) {
        case ROOM_DOOR_TYPE_0:
            room->posA.x = centerX + (nX * 30.0f) - (nZ * 20.0f);
            room->posA.z = centerZ + (nZ * 30.0f) + (nX * 20.0f);
            room->posB.x = centerX - (nX * 30.0f);
            room->posB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_DOOR_TYPE_5:
            room->posA.x = centerX + (nX * 60.0f) - (nZ * 20.0f);
            room->posA.z = centerZ + (nZ * 60.0f) + (nX * 20.0f);
            room->posB.x = centerX - (nX * 30.0f);
            room->posB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_DOOR_TYPE_1:
            room->posA.x = centerX + (nX * 30.0f);
            room->posA.z = centerZ + (nZ * 30.0f);
            room->posB.x = centerX - (nX * 30.0f) - (nZ * 20.0f);
            room->posB.z = centerZ - (nZ * 30.0f) - (nX * 20.0f);
            break;
        case ROOM_DOOR_TYPE_6:
            room->posA.x = centerX + (nX * 30.0f);
            room->posA.z = centerZ + (nZ * 30.0f);
            room->posB.x = centerX - (nX * 60.0f) - (nZ * 20.0f);
            room->posB.z = centerZ - (nZ * 60.0f) - (nX * 20.0f);
            break;
        case ROOM_DOOR_TYPE_2:
            room->posA.x = centerX + (nX * 30.0f) + (nZ * 20.0f);
            room->posA.z = centerZ + (nZ * 30.0f) - (nX * 20.0f);
            room->posB.x = centerX - (nX * 30.0f);
            room->posB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_DOOR_TYPE_7:
            room->posA.x = centerX + (nX * 60.0f) + (nZ * 20.0f);
            room->posA.z = centerZ + (nZ * 60.0f) - (nX * 20.0f);
            room->posB.x = centerX - (nX * 30.0f);
            room->posB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_DOOR_TYPE_3:
            room->posA.x = centerX + (nX * 30.0f);
            room->posA.z = centerZ + (nZ * 30.0f);
            room->posB.x = centerX - (nX * 30.0f) + (nZ * 20.0f);
            room->posB.z = centerZ - (nZ * 30.0f) + (nX * 20.0f);
            break;
        case ROOM_DOOR_TYPE_4:
            room->posA.x = centerX + (nX * 30.0f);
            room->posA.z = centerZ + (nZ * 30.0f);
            room->posB.x = centerX - (nX * 30.0f);
            room->posB.z = centerZ - (nZ * 30.0f);
            break;
    }
    room->overrideOpenDoor = openDoorScript;
    room->overrideMoveWall = moveWallsScript;
    room->overrideDropDoor = dropDoorScript;
    room->toggleVisScript = toggleVisScript;

    room->posC.x = room->posB.x;
    room->posC.z = room->posB.z;
    room->posD.x = room->posA.x;
    room->posD.z = room->posA.z;

    room->bgColor[0] = gCameras[CAM_DEFAULT].bgColor[0];
    room->bgColor[1] = gCameras[CAM_DEFAULT].bgColor[1];
    room->bgColor[2] = gCameras[CAM_DEFAULT].bgColor[2];

    bind_trigger_1(&EVS_EnterRoomDoor, TRIGGER_WALL_PRESS_A, colliderID, 0, (s32) room, 3);
    if (roomFlags & ROOM_FLAG_800) {
        bind_trigger_1(&EVS_ExitRoomDoor, TRIGGER_WALL_PUSH, triggerColliderID, 1, (s32) room, 3);
    } else {
        bind_trigger_1(&EVS_ExitRoomDoor, TRIGGER_WALL_PRESS_A, triggerColliderID, 1, (s32) room, 3);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(PlayRoomDoorSound) {
    Bytecode* args = script->ptrReadPos;
    MapRoom* door = script->functionTempPtr[1];
    s32 sound = evt_get_variable(script, *args++);
    f32 posX, posY, posZ;

    get_collider_center(door->colliderID, &posX, &posY, &posZ);
    sfx_play_sound_at_position(sound, 0, posX, posY, posZ);
    return ApiStatus_DONE2;
}

//TODO name?
API_CALLABLE(SaveDoorPtr) {
    script->functionTemp[1] = script->varTable[1];
    return ApiStatus_DONE2;
}

API_CALLABLE(GetDoorState) {
    MapRoom* door = script->functionTempPtr[1];

    script->varTable[0] = door->state;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetDoorState) {
    MapRoom* door = script->functionTempPtr[1];

    door->state = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(AwaitUseDoorScript) {
    Bytecode* args = script->ptrReadPos;
    MapRoom* door = script->functionTempPtr[1];
    s32 index = evt_get_variable(script, *args++);

    if (does_script_exist(door->scriptIDs[index])) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(SaveUseDoorScript) {
    Bytecode* args = script->ptrReadPos;
    MapRoom* door = script->functionTempPtr[1];
    s32 index = evt_get_variable(script, *args++);
    s32 scriptID = evt_get_variable(script, *args++);

    door->scriptIDs[index] = scriptID;
    return ApiStatus_DONE2;
}

API_CALLABLE(RoomVisibilityToggleImpl) {
    MapRoom* door = script->varTablePtr[1];
    s32 alpha, r, g, b;

    if (isInitialCall) {
        if (script->varTable[0] == 0) {
            func_8011B950(script->varTable[15], -1, FOG_MODE_1, 1);
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
            // ROOM_DATA_MODEL_ID
            func_8011B950(script->varTable[15], -1, FOG_MODE_0, 1);
        }
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(func_80282594) {
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

API_CALLABLE(SetEntityHideMode1) {
    gEntityHideMode = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetEntityHideMode2) {
    gEntityHideMode = 2;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetEntityHideMode0) {
    gEntityHideMode = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(HideRoomNPCs) {
    MapRoom* door = script->functionTempPtr[1];
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
                npc->flags |= NPC_FLAG_HIDING;
            }
        }
    }

    endOfList = -1;
    mask = ~NPC_FLAG_HIDING;

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

API_CALLABLE(RevealHiddenRoomNPCs) {
    MapRoom* door = script->functionTempPtr[1];
    s32 i;

    if (door->npcList == NULL) {
        return ApiStatus_DONE2;
    }

    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = get_npc_by_index(i);
        if (npc != NULL) {
            if (npc->flags != 0) {
                npc->flags &= ~NPC_FLAG_HIDING;
            }
        }
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(UseRoomItemVisGroup) {
    MapRoom* door = script->functionTempPtr[1];

    door->prevItemVisGroup = get_current_item_entity_render_group();
    set_current_item_entity_render_group(door->newItemVisGroup);
    return ApiStatus_DONE2;
}

API_CALLABLE(RestorePrevItemVisGroup) {
    MapRoom* door = script->functionTempPtr[1];

    set_current_item_entity_render_group(door->prevItemVisGroup);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetDoorData) {
    MapRoom* door = script->functionTempPtr[1];

    script->varTable[2] = door->flags;
    script->varTable[3] = door->posA.x;
    script->varTable[4] = door->posA.z;
    script->varTable[5] = door->posB.x;
    script->varTable[6] = door->posB.z;
    script->varTable[7] = door->posC.x;
    script->varTable[8] = door->posC.z;
    script->varTable[9] = door->posD.x;
    script->varTable[10] = door->posD.z;
    script->varTablePtr[11] = door->overrideOpenDoor;
    script->varTablePtr[12] = door->overrideMoveWall;
    script->varTablePtr[13] = door->overrideDropDoor;
    script->varTablePtr[14] = door->toggleVisScript;
    script->varTable[15] = door->modelID;
    return ApiStatus_DONE2;
}

API_CALLABLE(GetDoorPtr) {
    script->varTable[1] = script->functionTemp[1];
    return ApiStatus_DONE2;
}

EvtScript EVS_AdvancedDoorVisiblityToggle = {
    EVT_CALL(RoomVisibilityToggleImpl)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_8028408C = {
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_POS_AX)
    EVT_SET(LVarD, ROOM_DATA_POS_AZ)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_POS_AX, ROOM_DATA_POS_AZ, LVarE)
    EVT_CALL(func_802D2884, ROOM_DATA_POS_BX, ROOM_DATA_POS_BZ, 0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_80284104 = {
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_POS_BX)
    EVT_SET(LVarD, ROOM_DATA_POS_BZ)
    EVT_SET(LVarE, 20)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_POS_BX, ROOM_DATA_POS_BZ, LVarE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_8028418C = {
    EVT_CALL(func_80282594, EVT_FLOAT(1.796875))
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_POS_BX)
    EVT_SET(LVarD, ROOM_DATA_POS_BZ)
    EVT_SET(LVarE, 10)
    EVT_CALL(InterpCamTargetPos, 0, 1, LVarB, LVarC, LVarD, LVarE)
    EVT_CALL(func_80282594, -1)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_80284228 = {
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_POS_CX)
    EVT_SET(LVarD, ROOM_DATA_POS_CZ)
    EVT_SET(LVarE, 10)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_POS_CX, ROOM_DATA_POS_CZ, LVarE)
    EVT_CALL(func_802D2884, ROOM_DATA_POS_DX, ROOM_DATA_POS_DZ, 0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_802842B0 = {
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_POS_DX)
    EVT_SET(LVarD, ROOM_DATA_POS_DZ)
    EVT_SET(LVarE, 20)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_POS_DX, ROOM_DATA_POS_DZ, LVarE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_80284338 = {
    EVT_CALL(func_80282594, EVT_FLOAT(1.796875))
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_POS_DX)
    EVT_SET(LVarD, ROOM_DATA_POS_DZ)
    EVT_SET(LVarE, 10)
    EVT_CALL(InterpCamTargetPos, 0, 1, LVarB, LVarC, LVarD, LVarE)
    EVT_CALL(func_80282594, -1)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Default_AnimateOpenDoor = {
    EVT_CALL(SaveDoorPtr)
    EVT_SET(LVar2, ROOM_DATA_EVT_OPEN_DOOR)
    EVT_SET(LVar3, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_OPEN_DOOR_0)
            EVT_CALL(MakeLerp, 0, 90, 10, EASING_CUBIC_OUT)
            EVT_CALL(PlayRoomDoorSound, SOUND_A0000000)
        EVT_CASE_EQ(ROOM_OPEN_DOOR_1)
            EVT_CALL(MakeLerp, 90, 0, 10, EASING_CUBIC_IN)
        EVT_CASE_EQ(ROOM_OPEN_DOOR_2)
            EVT_CALL(MakeLerp, 0, 90, 10, EASING_CUBIC_OUT)
            EVT_CALL(PlayRoomDoorSound, SOUND_A0000000)
        EVT_CASE_EQ(ROOM_OPEN_DOOR_3)
            EVT_CALL(MakeLerp, 90, 0, 10, EASING_CUBIC_IN)
    EVT_END_SWITCH
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_EXEC(LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_SWITCH(LVar3)
        EVT_CASE_EQ(ROOM_OPEN_DOOR_1)
            EVT_CALL(PlayRoomDoorSound, SOUND_A0000001)
        EVT_CASE_EQ(ROOM_OPEN_DOOR_3)
            EVT_CALL(PlayRoomDoorSound, SOUND_A0000001)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Default_AnimateWallRot = {
    EVT_SET(LVar2, ROOM_DATA_EVT_MOVE_WALL)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_MOVE_WALL_0)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_OUT)
        EVT_CASE_EQ(ROOM_MOVE_WALL_1)
            EVT_CALL(MakeLerp, 90, 0, 20, EASING_CUBIC_IN)
        EVT_CASE_EQ(ROOM_MOVE_WALL_2)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_OUT)
        EVT_CASE_EQ(ROOM_MOVE_WALL_3)
            EVT_CALL(MakeLerp, 90, 0, 20, EASING_CUBIC_IN)
    EVT_END_SWITCH
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_EXEC(LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Default_AnimateDropDoor = {
    EVT_SET(LVar2, LVarD)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_IN)
        EVT_CASE_EQ(1)
            EVT_CALL(MakeLerp, 90, 0, 10, EASING_CUBIC_OUT)
        EVT_CASE_EQ(2)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_IN)
        EVT_CASE_EQ(3)
            EVT_CALL(MakeLerp, 90, 0, 10, EASING_CUBIC_OUT)
    EVT_END_SWITCH
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_EXEC(LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

/*
    Called from triger activatation with:
        LVar0   ?
        LVar1   MapRoom*
*/
EvtScript EVS_EnterRoomDoor = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(GetPlayerActionState, LVar3)
    EVT_SET(LVar4, 0)
    EVT_IF_EQ(LVar3, ACTION_STATE_IDLE)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_WALK)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_RUN)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar4, 0)
        EVT_RETURN
    EVT_END_IF

    // initialize
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorState)
    EVT_IF_NE(LVar0, ROOM_STATE_IDLE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetDoorState, ROOM_STATE_ENTERING)
    EVT_CALL(HideRoomNPCs)
    EVT_CALL(UseRoomItemVisGroup)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)

    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_UPDATE_ENTER_BEGIN)
    EVT_IF_NE(ROOM_DATA_EVT_TOGGLE_VIS, NULL)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_TOGGLE_VIS)
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF

    EVT_CALL(GetDoorData)
    EVT_EXEC(EVS_8028418C)
    EVT_CALL(GetDoorData)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAGS_DOOR_TYPE_MASK)
    EVT_SET(LVarE, 10)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ROOM_DOOR_TYPE_0)
            EVT_EXEC_WAIT(EVS_8028408C)
        EVT_CASE_EQ(ROOM_DOOR_TYPE_2)
            EVT_EXEC_WAIT(EVS_8028408C)
        EVT_CASE_EQ(ROOM_DOOR_TYPE_4)
            EVT_EXEC_WAIT(EVS_8028408C)
        EVT_CASE_EQ(ROOM_DOOR_TYPE_5)
            EVT_SET(LVarE, 20)
            EVT_EXEC_WAIT(EVS_8028408C)
        EVT_CASE_EQ(ROOM_DOOR_TYPE_7)
            EVT_SET(LVarE, 20)
            EVT_EXEC_WAIT(EVS_8028408C)
    EVT_END_SWITCH
    
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, 0)
    EVT_CALL(GetDoorPtr)
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_EXEC_GET_TID(EVS_AdvancedDoorVisiblityToggle, LVar5)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_0, LVar5)
    EVT_END_IF
    EVT_CALL(SetEntityHideMode1)
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_0)
    EVT_END_IF

    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_MOVE_WALL_0)
    EVT_BITWISE_AND_CONST(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_WALL_ROT)
    EVT_IF_NE(ROOM_DATA_EVT_MOVE_WALL, NULL)
        EVT_IF_NE(ROOM_DATA_FLAGS, 0)
            EVT_EXEC_GET_TID(ROOM_DATA_EVT_MOVE_WALL, LVar5)
        EVT_ELSE
            EVT_EXEC_GET_TID(EVS_Default_AnimateWallRot, LVar5)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_MOVE_WALL, NULL)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_0, LVar5)
    EVT_END_IF

    EVT_SET(LVar0, ROOM_OPEN_DOOR_0)
    EVT_BITWISE_AND_CONST(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(ROOM_DATA_FLAGS, 0)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    EVT_ELSE
        EVT_EXEC_GET_TID(EVS_Default_AnimateOpenDoor, LVar5)
    EVT_END_IF
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar5)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, TRUE)
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)

    EVT_CALL(SetEntityHideMode2)
    EVT_EXEC_GET_TID(EVS_80284104, LVar7)
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar7)
    EVT_WAIT(10)
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(func_80281C20, ROOM_DATA_POS_BX, ROOM_DATA_POS_BZ)
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)

    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, FALSE)
    EVT_CALL(func_80281C84)

    EVT_SET(LVar0, ROOM_OPEN_DOOR_1)
    EVT_BITWISE_AND_CONST(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(ROOM_DATA_FLAGS, 0)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    EVT_ELSE
        EVT_EXEC_GET_TID(EVS_Default_AnimateOpenDoor, LVar5)
    EVT_END_IF
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar5)

    EVT_SET(LVar0, ROOM_DROP_DOOR_0)
    EVT_BITWISE_AND_CONST(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_DROP_DOOR)
    EVT_IF_NE(ROOM_DATA_EVT_DROP_DOOR, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)
        EVT_IF_NE(ROOM_DATA_FLAGS, 0)
            EVT_EXEC_GET_TID(ROOM_DATA_EVT_DROP_DOOR, LVar5)
        EVT_ELSE
            EVT_EXEC_GET_TID(EVS_Default_AnimateDropDoor, LVar5)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_DROP_DOOR, NULL)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EVT_END_IF
    EVT_SET(LVar0, ROOM_UPDATE_ENTER_DONE)
    EVT_IF_NE(ROOM_DATA_EVT_TOGGLE_VIS, NULL)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_TOGGLE_VIS, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_TOGGLE_VIS, NULL)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_2, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_TOGGLE_VIS, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_2)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_MOVE_WALL, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_0)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_DROP_DOOR, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    EVT_END_IF
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_RETURN
    EVT_LABEL(1)
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_LABEL(0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ExitRoomDoor = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(GetPlayerActionState, LVar3)
    EVT_SET(LVar4, 0)
    EVT_IF_EQ(LVar3, ACTION_STATE_IDLE)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_WALK)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_RUN)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar4, 0)
        EVT_RETURN
    EVT_END_IF

    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorState)
    EVT_IF_NE(LVar0, ROOM_STATE_IDLE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetDoorState, ROOM_STATE_EXITING)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_BEGIN)
    EVT_IF_NE(ROOM_DATA_EVT_TOGGLE_VIS, NULL)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_TOGGLE_VIS)
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF

    EVT_CALL(GetDoorData)
    EVT_EXEC(EVS_80284338)
    EVT_CALL(GetDoorData)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAGS_DOOR_TYPE_MASK)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(EVS_80284228)
        EVT_CASE_EQ(6)
            EVT_EXEC_WAIT(EVS_80284228)
        EVT_CASE_EQ(3)
            EVT_EXEC_WAIT(EVS_80284228)
    EVT_END_SWITCH

    EVT_CALL(GetDoorData)
    EVT_CALL(GetDoorPtr)
    EVT_SET(LVar0, ROOM_MOVE_WALL_3)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAG_CUSTOM_ANIM_WALL_ROT)
    EVT_IF_NE(ROOM_DATA_EVT_MOVE_WALL, NULL)
        EVT_IF_NE(LVar2, 0)
            EVT_EXEC_GET_TID(ROOM_DATA_EVT_MOVE_WALL, LVar5)
        EVT_ELSE
            EVT_EXEC_GET_TID(EVS_Default_AnimateWallRot, LVar5)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_MOVE_WALL, NULL)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_0, LVar5)
    EVT_END_IF

    EVT_SET(LVar0, ROOM_DROP_DOOR_3)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAG_CUSTOM_ANIM_DROP_DOOR)
    EVT_IF_NE(ROOM_DATA_EVT_DROP_DOOR, NULL)
        EVT_IF_NE(LVar2, 0)
            EVT_EXEC_GET_TID(ROOM_DATA_EVT_DROP_DOOR, LVar5)
        EVT_ELSE
            EVT_EXEC_GET_TID(EVS_Default_AnimateDropDoor, LVar5)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_DROP_DOOR, NULL)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_DROP_DOOR, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    EVT_END_IF

    EVT_SET(LVar0, ROOM_OPEN_DOOR_2)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(LVar2, 0)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    EVT_ELSE
        EVT_EXEC_GET_TID(EVS_Default_AnimateOpenDoor, LVar5)
    EVT_END_IF
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)

    EVT_CALL(GetDoorPtr)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, TRUE)
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(func_80281C20, ROOM_DATA_POS_DX, ROOM_DATA_POS_DZ)
    EVT_EXEC_GET_TID(EVS_802842B0, LVar5)
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EVT_CALL(SetEntityHideMode0)

    // begin part 3

    EVT_SET(LVar0, 3)
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_EXEC_GET_TID(EVS_AdvancedDoorVisiblityToggle, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_2, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_2)
    EVT_END_IF
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, FALSE)
    EVT_CALL(func_80281C84)

    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_OPEN_DOOR_3)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(LVar2, 0)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_OPEN_DOOR)
    EVT_ELSE
        EVT_EXEC_WAIT(EVS_Default_AnimateOpenDoor)
    EVT_END_IF

    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_IF_NE(ROOM_DATA_EVT_TOGGLE_VIS, NULL)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_TOGGLE_VIS)
    EVT_END_IF

    EVT_CALL(RevealHiddenRoomNPCs)
    EVT_CALL(RestorePrevItemVisGroup)
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_RETURN
    EVT_LABEL(1)
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_LABEL(0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
