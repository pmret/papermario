#include "common.h"
#include "model.h"

void func_800EF414(s32, s32);
void get_flat_collider_normal(s32, f32*, f32*, f32*);
s32 get_current_item_entity_render_group(void);
void set_current_item_entity_render_group(s32);

extern EvtScript EVS_EnterRoomDoor;
extern EvtScript EVS_ExitRoomDoor;

typedef enum RoomState {
    ROOM_STATE_IDLE             = 0,
    ROOM_STATE_ENTERING         = 1,
    ROOM_STATE_EXITING          = 2,
} RoomState;

typedef struct MapRoom {
    /* 0x00 */ RoomState state;
    /* 0x04 */ s32 flags;
    /* 0x08 */ s16 newItemVisGroup;
    /* 0x0A */ s16 prevItemVisGroup;
    /* 0x0C */ VecXZf posEnterA;
    /* 0x14 */ VecXZf posEnterB;
    /* 0x1C */ VecXZf posExitA;
    /* 0x24 */ VecXZf posExitB;
    /* 0x2C */ EvtScript* overrideOpenDoor;
    /* 0x2C */ EvtScript* overrideMoveWall;
    /* 0x2C */ EvtScript* overrideDropDoor;
    /* 0x2C */ EvtScript* stateListenerScript;
    /* 0x3C */ s32 modelID;
    /* 0x40 */ s32 bgColor[3];
    /* 0x4C */ s32 scriptIDs[4];
    /* 0x5C */ s32* npcList;
    /* 0x60 */ s32 colliderID;
} MapRoom; // size = 0x64

// data fetched with GetDoorData is stored in these local vars
enum {
    ROOM_DATA_FLAGS             = LVar2,
    ROOM_DATA_ENTER_POS_AX      = LVar3,
    ROOM_DATA_ENTER_POS_AZ      = LVar4,
    ROOM_DATA_ENTER_POS_BX      = LVar5,
    ROOM_DATA_ENTER_POS_BZ      = LVar6,
    ROOM_DATA_EXIT_POS_AX       = LVar7,
    ROOM_DATA_EXIT_POS_AZ       = LVar8,
    ROOM_DATA_EXIT_POS_BX       = LVar9,
    ROOM_DATA_EXIT_POS_BZ       = LVarA,
    ROOM_DATA_EVT_OPEN_DOOR     = LVarB,
    ROOM_DATA_EVT_MOVE_WALL     = LVarC,
    ROOM_DATA_EVT_DROP_DOOR     = LVarD,
    ROOM_DATA_EVT_LISTENER      = LVarE,
    ROOM_DATA_MODEL_ID          = LVarF,
};

enum {
    ROOM_SCRIPT_IDX_0       = 0,
    ROOM_SCRIPT_IDX_1       = 1,
    ROOM_SCRIPT_IDX_2       = 2,
    ROOM_SCRIPT_IDX_3       = 3,
};

enum {
    ROOM_VISIBILITY_SHOW        = 0,
    ROOM_VISIBILITY_HIDE        = 3,
};

API_CALLABLE(MovePartnerThroughDoor) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);

    func_800EF414(posX, posZ);
    partner_set_tether_distance(0.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(ResetPartnerMovement) {
    func_800EF3E4();
    partner_reset_tether_distance();
    return ApiStatus_DONE2;
}

/* ARGS:
    s32 packed flags and itemVisGroup via PACK_ROOM_FLAGS()
    EvtScript* openDoor
    EvtScript* moveWalls
    EvtScript* dropDoor
    EvtScript* stateListener
    s32 doorInColliderID
    s32 doorOutColliderID
    s32 interiorModelGroup
    s32* interiorNPCs
*/
API_CALLABLE(CreateMapRoom) {
    Bytecode* args = script->ptrReadPos;
    MapRoom* room = heap_malloc(sizeof(*room));
    EvtScript* openDoorScript;
    EvtScript* moveWallsScript;
    EvtScript* dropDoorScript;
    EvtScript* stateListenerScript;
    s32 colliderID;
    s32 triggerColliderID;
    s32 roomFlags;
    f32 centerX, centerZ;
    f32 nX, nZ;
    f32 tempY;

    room->state = ROOM_STATE_IDLE;
    roomFlags = evt_get_variable(script, *args++);
    room->flags = roomFlags & (ROOM_FLAGS_MASK | ROOM_FLAGS_DOOR_TYPE_MASK);
    room->newItemVisGroup = (roomFlags & ROOM_FLAGS_VISGROUP_MASK) >> 0xC;
    room->prevItemVisGroup = VIS_GROUP_0;
    openDoorScript  = (EvtScript*) evt_get_variable(script, *args++);
    moveWallsScript = (EvtScript*) evt_get_variable(script, *args++);
    dropDoorScript  = (EvtScript*) evt_get_variable(script, *args++);
    stateListenerScript = (EvtScript*) evt_get_variable(script, *args++);
    room->colliderID = colliderID = evt_get_variable(script, *args++);
    triggerColliderID = evt_get_variable(script, *args++);
    room->modelID = evt_get_variable(script, *args++);
    room->npcList = (s32*) evt_get_variable(script, *args++);
    if (dropDoorScript != NULL) {
        roomFlags |= ROOM_FLAG_EXIT_DOOR_DROPS;
        room->flags = roomFlags;
    }
    get_collider_center(colliderID, &centerX, &tempY, &centerZ);
    get_flat_collider_normal(colliderID, &nX, &tempY, &nZ);

    switch (roomFlags & ROOM_FLAGS_DOOR_TYPE_MASK) {
        case ROOM_DOOR_RIGHT_HINGE_OPENS_OUT:
            room->posEnterA.x = centerX + (nX * 30.0f) - (nZ * 20.0f);
            room->posEnterA.z = centerZ + (nZ * 30.0f) + (nX * 20.0f);
            room->posEnterB.x = centerX - (nX * 30.0f);
            room->posEnterB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT:
            room->posEnterA.x = centerX + (nX * 60.0f) - (nZ * 20.0f);
            room->posEnterA.z = centerZ + (nZ * 60.0f) + (nX * 20.0f);
            room->posEnterB.x = centerX - (nX * 30.0f);
            room->posEnterB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_DOOR_RIGHT_HINGE_OPENS_IN:
            room->posEnterA.x = centerX + (nX * 30.0f);
            room->posEnterA.z = centerZ + (nZ * 30.0f);
            room->posEnterB.x = centerX - (nX * 30.0f) - (nZ * 20.0f);
            room->posEnterB.z = centerZ - (nZ * 30.0f) - (nX * 20.0f);
            break;
        case ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_IN:
            room->posEnterA.x = centerX + (nX * 30.0f);
            room->posEnterA.z = centerZ + (nZ * 30.0f);
            room->posEnterB.x = centerX - (nX * 60.0f) - (nZ * 20.0f);
            room->posEnterB.z = centerZ - (nZ * 60.0f) - (nX * 20.0f);
            break;
        case ROOM_DOOR_LEFT_HINGE_OPENS_OUT:
            room->posEnterA.x = centerX + (nX * 30.0f) + (nZ * 20.0f);
            room->posEnterA.z = centerZ + (nZ * 30.0f) - (nX * 20.0f);
            room->posEnterB.x = centerX - (nX * 30.0f);
            room->posEnterB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_LARGE_DOOR_LEFT_HINGE_OPENS_OUT:
            room->posEnterA.x = centerX + (nX * 60.0f) + (nZ * 20.0f);
            room->posEnterA.z = centerZ + (nZ * 60.0f) - (nX * 20.0f);
            room->posEnterB.x = centerX - (nX * 30.0f);
            room->posEnterB.z = centerZ - (nZ * 30.0f);
            break;
        case ROOM_DOOR_LEFT_HINGE_OPENS_IN:
            room->posEnterA.x = centerX + (nX * 30.0f);
            room->posEnterA.z = centerZ + (nZ * 30.0f);
            room->posEnterB.x = centerX - (nX * 30.0f) + (nZ * 20.0f);
            room->posEnterB.z = centerZ - (nZ * 30.0f) + (nX * 20.0f);
            break;
        case ROOM_DOOR_STRAIGHT_THROUGH:
            room->posEnterA.x = centerX + (nX * 30.0f);
            room->posEnterA.z = centerZ + (nZ * 30.0f);
            room->posEnterB.x = centerX - (nX * 30.0f);
            room->posEnterB.z = centerZ - (nZ * 30.0f);
            break;
    }
    room->overrideOpenDoor = openDoorScript;
    room->overrideMoveWall = moveWallsScript;
    room->overrideDropDoor = dropDoorScript;
    room->stateListenerScript = stateListenerScript;

    room->posExitA.x = room->posEnterB.x;
    room->posExitA.z = room->posEnterB.z;
    room->posExitB.x = room->posEnterA.x;
    room->posExitB.z = room->posEnterA.z;

    room->bgColor[0] = gCameras[CAM_DEFAULT].bgColor[0];
    room->bgColor[1] = gCameras[CAM_DEFAULT].bgColor[1];
    room->bgColor[2] = gCameras[CAM_DEFAULT].bgColor[2];

    bind_trigger_1(&EVS_EnterRoomDoor, TRIGGER_WALL_PRESS_A, colliderID, 0, (s32) room, 3);
    if (roomFlags & ROOM_FLAG_EXIT_DOOR_DROPS) {
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
        if (script->varTable[0] == ROOM_VISIBILITY_SHOW) {
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
        }
        script->functionTemp[1] = 0;
    }
    script->functionTemp[1] += 32;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }
    if (script->varTable[0] == ROOM_VISIBILITY_SHOW) {
        alpha = script->functionTemp[1];
    } else {
        alpha = 255 - script->functionTemp[1];
    }
    mdl_set_shroud_tint_params(0, 0, 0, alpha);
    r = door->bgColor[0] * (255 - alpha) / 255;
    g = door->bgColor[1] * (255 - alpha) / 255;
    b = door->bgColor[2] * (255 - alpha) / 255;
    gCameras[CAM_DEFAULT].bgColor[0] = r;
    gCameras[CAM_DEFAULT].bgColor[1] = g;
    gCameras[CAM_DEFAULT].bgColor[2] = b;

    if (script->functionTemp[1] >= 255) {
        if (script->varTable[0] == ROOM_VISIBILITY_HIDE) {
            // ROOM_DATA_MODEL_ID
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_NONE, TRUE);
        }
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

// saves the previous value, call again with a negative value to restore it
API_CALLABLE(SetRoomCamMoveSpeed) {
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
    gEntityHideMode = ENTITY_HIDE_MODE_1;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetEntityHideMode2) {
    gEntityHideMode = ENTITY_HIDE_MODE_2;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetEntityHideMode0) {
    gEntityHideMode = ENTITY_HIDE_MODE_0;
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
    script->varTable[3] = door->posEnterA.x;
    script->varTable[4] = door->posEnterA.z;
    script->varTable[5] = door->posEnterB.x;
    script->varTable[6] = door->posEnterB.z;
    script->varTable[7] = door->posExitA.x;
    script->varTable[8] = door->posExitA.z;
    script->varTable[9] = door->posExitB.x;
    script->varTable[10] = door->posExitB.z;
    script->varTablePtr[11] = door->overrideOpenDoor;
    script->varTablePtr[12] = door->overrideMoveWall;
    script->varTablePtr[13] = door->overrideDropDoor;
    script->varTablePtr[14] = door->stateListenerScript;
    script->varTable[15] = door->modelID;
    return ApiStatus_DONE2;
}

API_CALLABLE(GetDoorPtr) {
    script->varTable[1] = script->functionTemp[1];
    return ApiStatus_DONE2;
}

EvtScript EVS_RoomContentVisiblityToggle = {
    EVT_CALL(RoomVisibilityToggleImpl)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_EnterRoom_MovePlayerA = {
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_ENTER_POS_AX)
    EVT_SET(LVarD, ROOM_DATA_ENTER_POS_AZ)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_ENTER_POS_AX, ROOM_DATA_ENTER_POS_AZ, LVarE)
    EVT_CALL(FacePlayerTowardPoint, ROOM_DATA_ENTER_POS_BX, ROOM_DATA_ENTER_POS_BZ, 0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_EnterRoom_MovePlayerB = {
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_ENTER_POS_BX)
    EVT_SET(LVarD, ROOM_DATA_ENTER_POS_BZ)
    EVT_SET(LVarE, 20)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_ENTER_POS_BX, ROOM_DATA_ENTER_POS_BZ, LVarE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_EnterRoom_MoveCam = {
    EVT_CALL(SetRoomCamMoveSpeed, EVT_FLOAT(1.796))
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_ENTER_POS_BX)
    EVT_SET(LVarD, ROOM_DATA_ENTER_POS_BZ)
    EVT_SET(LVarE, 10)
    EVT_CALL(InterpCamTargetPos, 0, 1, LVarB, LVarC, LVarD, LVarE)
    EVT_CALL(SetRoomCamMoveSpeed, -1)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ExitRoom_MovePlayerA = {
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_EXIT_POS_AX)
    EVT_SET(LVarD, ROOM_DATA_EXIT_POS_AZ)
    EVT_SET(LVarE, 10)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_EXIT_POS_AX, ROOM_DATA_EXIT_POS_AZ, LVarE)
    EVT_CALL(FacePlayerTowardPoint, ROOM_DATA_EXIT_POS_BX, ROOM_DATA_EXIT_POS_BZ, 0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ExitRoom_MovePlayerB = {
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_EXIT_POS_BX)
    EVT_SET(LVarD, ROOM_DATA_EXIT_POS_BZ)
    EVT_SET(LVarE, 20)
    EVT_CALL(PlayerMoveTo, ROOM_DATA_EXIT_POS_BX, ROOM_DATA_EXIT_POS_BZ, LVarE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ExitRoom_MoveCam = {
    EVT_CALL(SetRoomCamMoveSpeed, EVT_FLOAT(1.796))
    EVT_CALL(GetPlayerPos, LVarB, LVarC, LVarD)
    EVT_SET(LVarB, ROOM_DATA_EXIT_POS_BX)
    EVT_SET(LVarD, ROOM_DATA_EXIT_POS_BZ)
    EVT_SET(LVarE, 10)
    EVT_CALL(InterpCamTargetPos, 0, 1, LVarB, LVarC, LVarD, LVarE)
    EVT_CALL(SetRoomCamMoveSpeed, -1)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Default_AnimateDoorRot = {
    EVT_CALL(SaveDoorPtr)
    EVT_SET(LVar2, ROOM_DATA_EVT_OPEN_DOOR)
    EVT_SET(LVar3, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_MOVE_DOOR_ENTER_OPEN)
            EVT_CALL(MakeLerp, 0, 90, 10, EASING_CUBIC_OUT)
            EVT_CALL(PlayRoomDoorSound, SOUND_ROOM_DOOR_OPEN)
        EVT_CASE_EQ(ROOM_MOVE_DOOR_ENTER_CLOSE)
            EVT_CALL(MakeLerp, 90, 0, 10, EASING_CUBIC_IN)
        EVT_CASE_EQ(ROOM_MOVE_DOOR_EXIT_OPEN)
            EVT_CALL(MakeLerp, 0, 90, 10, EASING_CUBIC_OUT)
            EVT_CALL(PlayRoomDoorSound, SOUND_ROOM_DOOR_OPEN)
        EVT_CASE_EQ(ROOM_MOVE_DOOR_EXIT_CLOSE)
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
        EVT_CASE_EQ(ROOM_MOVE_DOOR_ENTER_CLOSE)
            EVT_CALL(PlayRoomDoorSound, SOUND_ROOM_DOOR_CLOSE)
        EVT_CASE_EQ(ROOM_MOVE_DOOR_EXIT_CLOSE)
            EVT_CALL(PlayRoomDoorSound, SOUND_ROOM_DOOR_CLOSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Default_AnimateWallRot = {
    EVT_SET(LVar2, ROOM_DATA_EVT_MOVE_WALL)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_MOVE_WALL_OPEN)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_OUT)
        EVT_CASE_EQ(ROOM_MOVE_WALL_1)
            EVT_CALL(MakeLerp, 90, 0, 20, EASING_CUBIC_IN)
        EVT_CASE_EQ(ROOM_MOVE_WALL_2)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_OUT)
        EVT_CASE_EQ(ROOM_MOVE_WALL_CLOSE)
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
    EVT_SET(LVar2, ROOM_DATA_EVT_DROP_DOOR)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_DROP_DOOR_ENTER)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_IN)
        EVT_CASE_EQ(ROOM_DROP_DOOR_1)
            EVT_CALL(MakeLerp, 90, 0, 10, EASING_CUBIC_OUT)
        EVT_CASE_EQ(ROOM_DROP_DOOR_2)
            EVT_CALL(MakeLerp, 0, 90, 20, EASING_CUBIC_IN)
        EVT_CASE_EQ(ROOM_DROP_DOOR_EXIT)
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

// executed from trigger activatation with MapRoom* stored in LVar1
EvtScript EVS_EnterRoomDoor = {
    EVT_SET_GROUP(EVT_GROUP_00)
    // ensure valid player action state
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

    // notify listener ROOM_UPDATE_ENTER_BEGIN
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_UPDATE_ENTER_BEGIN)
    EVT_IF_NE(ROOM_DATA_EVT_LISTENER, NULL)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_LISTENER)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ROOM_UPDATE_REQUEST_CANCEL)
        EVT_GOTO(1)
    EVT_END_IF

    // adjust camera to face door
    EVT_CALL(GetDoorData)
    EVT_EXEC(EVS_EnterRoom_MoveCam)

    // move player to door
    EVT_CALL(GetDoorData)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAGS_DOOR_TYPE_MASK)
    EVT_SET(LVarE, 10)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ROOM_DOOR_RIGHT_HINGE_OPENS_OUT)
            EVT_EXEC_WAIT(EVS_EnterRoom_MovePlayerA)
        EVT_CASE_EQ(ROOM_DOOR_LEFT_HINGE_OPENS_OUT)
            EVT_EXEC_WAIT(EVS_EnterRoom_MovePlayerA)
        EVT_CASE_EQ(ROOM_DOOR_STRAIGHT_THROUGH)
            EVT_EXEC_WAIT(EVS_EnterRoom_MovePlayerA)
        EVT_CASE_EQ(ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT)
            EVT_SET(LVarE, 20)
            EVT_EXEC_WAIT(EVS_EnterRoom_MovePlayerA)
        EVT_CASE_EQ(ROOM_LARGE_DOOR_LEFT_HINGE_OPENS_OUT)
            EVT_SET(LVarE, 20)
            EVT_EXEC_WAIT(EVS_EnterRoom_MovePlayerA)
    EVT_END_SWITCH

    // reveal room interior and hide world
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_VISIBILITY_SHOW)
    EVT_CALL(GetDoorPtr)
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_EXEC_GET_TID(EVS_RoomContentVisiblityToggle, LVar5)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_0, LVar5)
    EVT_END_IF
    EVT_CALL(SetEntityHideMode1)
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_0)
    EVT_END_IF

    // wall movement animation
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_MOVE_WALL_OPEN)
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

    // open the door
    EVT_SET(LVar0, ROOM_MOVE_DOOR_ENTER_OPEN)
    EVT_BITWISE_AND_CONST(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(ROOM_DATA_FLAGS, 0)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    EVT_ELSE
        EVT_EXEC_GET_TID(EVS_Default_AnimateDoorRot, LVar5)
    EVT_END_IF
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar5)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)

    // move party through the doorway
    EVT_CALL(SetEntityHideMode2)
    EVT_EXEC_GET_TID(EVS_EnterRoom_MovePlayerB, LVar7)
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar7)
    EVT_WAIT(10)
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(MovePartnerThroughDoor, ROOM_DATA_ENTER_POS_BX, ROOM_DATA_ENTER_POS_BZ)

    // allow input when movement is done
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(ResetPartnerMovement)

    // close the door
    EVT_SET(LVar0, ROOM_MOVE_DOOR_ENTER_CLOSE)
    EVT_BITWISE_AND_CONST(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(ROOM_DATA_FLAGS, 0)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    EVT_ELSE
        EVT_EXEC_GET_TID(EVS_Default_AnimateDoorRot, LVar5)
    EVT_END_IF
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar5)

    // drop the door
    EVT_SET(LVar0, ROOM_DROP_DOOR_ENTER)
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

    // notify listener ROOM_UPDATE_ENTER_DONE
    EVT_SET(LVar0, ROOM_UPDATE_ENTER_DONE)
    EVT_IF_NE(ROOM_DATA_EVT_LISTENER, NULL)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_LISTENER, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_LISTENER, NULL)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_2, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_LISTENER, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_2)
    EVT_END_IF

    // wait for all anim scripts
    EVT_IF_NE(ROOM_DATA_EVT_MOVE_WALL, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_0)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_EVT_DROP_DOOR, NULL)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    EVT_END_IF

    // reset and return
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_RETURN

    // handle ROOM_UPDATE_REQUEST_CANCEL from callback to ROOM_UPDATE_ENTER_BEGIN
    EVT_LABEL(1)
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_LABEL(0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

// executed from trigger activatation with MapRoom* stored in LVar1
EvtScript EVS_ExitRoomDoor = {
    EVT_SET_GROUP(EVT_GROUP_00)
    // ensure valid player action state
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
    EVT_CALL(SetDoorState, ROOM_STATE_EXITING)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)

    // notify listener ROOM_UPDATE_EXIT_BEGIN
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_BEGIN)
    EVT_IF_NE(ROOM_DATA_EVT_LISTENER, NULL)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_LISTENER)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ROOM_UPDATE_REQUEST_CANCEL)
        EVT_GOTO(1)
    EVT_END_IF

    // adjust camera to face door
    EVT_CALL(GetDoorData)
    EVT_EXEC(EVS_ExitRoom_MoveCam)

    // move player to door
    EVT_CALL(GetDoorData)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAGS_DOOR_TYPE_MASK)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ROOM_DOOR_RIGHT_HINGE_OPENS_IN)
            EVT_EXEC_WAIT(EVS_ExitRoom_MovePlayerA)
        EVT_CASE_EQ(ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_IN)
            EVT_EXEC_WAIT(EVS_ExitRoom_MovePlayerA)
        EVT_CASE_EQ(ROOM_DOOR_LEFT_HINGE_OPENS_IN)
            EVT_EXEC_WAIT(EVS_ExitRoom_MovePlayerA)
    EVT_END_SWITCH

    // wall movement animation
    EVT_CALL(GetDoorData)
    EVT_CALL(GetDoorPtr)
    EVT_SET(LVar0, ROOM_MOVE_WALL_CLOSE)
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

    // raise the door if its been dropped
    EVT_SET(LVar0, ROOM_DROP_DOOR_EXIT)
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

    // open the door
    EVT_SET(LVar0, ROOM_MOVE_DOOR_EXIT_OPEN)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(LVar2, 0)
        EVT_EXEC_GET_TID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    EVT_ELSE
        EVT_EXEC_GET_TID(EVS_Default_AnimateDoorRot, LVar5)
    EVT_END_IF
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)

    // move party through the doorway
    EVT_CALL(GetDoorPtr)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SaveDoorPtr)
    EVT_CALL(GetDoorData)
    EVT_CALL(MovePartnerThroughDoor, ROOM_DATA_EXIT_POS_BX, ROOM_DATA_EXIT_POS_BZ)
    EVT_EXEC_GET_TID(EVS_ExitRoom_MovePlayerB, LVar5)
    EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EVT_CALL(SetEntityHideMode0)

    // hide room interior and reveal world
    EVT_SET(LVar0, ROOM_VISIBILITY_HIDE)
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_EXEC_GET_TID(EVS_RoomContentVisiblityToggle, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_CALL(SaveUseDoorScript, ROOM_SCRIPT_IDX_2, LVar5)
    EVT_END_IF
    EVT_IF_NE(ROOM_DATA_MODEL_ID, 0)
        EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_2)
    EVT_END_IF

    // allow input when movement is done
    EVT_CALL(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(ResetPartnerMovement)

    // close the door
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_MOVE_DOOR_EXIT_CLOSE)
    EVT_BITWISE_AND_CONST(LVar2, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    EVT_IF_NE(LVar2, 0)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_OPEN_DOOR)
    EVT_ELSE
        EVT_EXEC_WAIT(EVS_Default_AnimateDoorRot)
    EVT_END_IF

    // notify listener ROOM_UPDATE_EXIT_END
    EVT_CALL(GetDoorData)
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_IF_NE(ROOM_DATA_EVT_LISTENER, NULL)
        EVT_EXEC_WAIT(ROOM_DATA_EVT_LISTENER)
    EVT_END_IF

    // reset and return
    EVT_CALL(RevealHiddenRoomNPCs)
    EVT_CALL(RestorePrevItemVisGroup)
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_RETURN

    // handle ROOM_UPDATE_REQUEST_CANCEL from callback to ROOM_UPDATE_ENTER_BEGIN
    EVT_LABEL(1)
    EVT_CALL(SetDoorState, ROOM_STATE_IDLE)
    EVT_LABEL(0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
