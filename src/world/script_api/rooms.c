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
    if (dropDoorScript != nullptr) {
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
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_SHROUD, true);
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
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_NONE, true);
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

    if (npcList == nullptr) {
        return ApiStatus_DONE2;
    }

    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = get_npc_by_index(i);
        if (npc != nullptr) {
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
        if (npc != nullptr) {
            npc->flags &= mask;
        }
    } while (true);

    return ApiStatus_DONE2;
}

API_CALLABLE(RevealHiddenRoomNPCs) {
    MapRoom* door = script->functionTempPtr[1];
    s32 i;

    if (door->npcList == nullptr) {
        return ApiStatus_DONE2;
    }

    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = get_npc_by_index(i);
        if (npc != nullptr) {
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
    Call(RoomVisibilityToggleImpl)
    Return
    End
};

EvtScript EVS_EnterRoom_MovePlayerA = {
    Call(GetPlayerPos, LVarB, LVarC, LVarD)
    Set(LVarB, ROOM_DATA_ENTER_POS_AX)
    Set(LVarD, ROOM_DATA_ENTER_POS_AZ)
    Call(PlayerMoveTo, ROOM_DATA_ENTER_POS_AX, ROOM_DATA_ENTER_POS_AZ, LVarE)
    Call(FacePlayerTowardPoint, ROOM_DATA_ENTER_POS_BX, ROOM_DATA_ENTER_POS_BZ, 0)
    Return
    End
};

EvtScript EVS_EnterRoom_MovePlayerB = {
    Call(SaveDoorPtr)
    Call(GetDoorData)
    Call(GetPlayerPos, LVarB, LVarC, LVarD)
    Set(LVarB, ROOM_DATA_ENTER_POS_BX)
    Set(LVarD, ROOM_DATA_ENTER_POS_BZ)
    Set(LVarE, 20)
    Call(PlayerMoveTo, ROOM_DATA_ENTER_POS_BX, ROOM_DATA_ENTER_POS_BZ, LVarE)
    Return
    End
};

EvtScript EVS_EnterRoom_MoveCam = {
    Call(SetRoomCamMoveSpeed, Float(1.796))
    Call(GetPlayerPos, LVarB, LVarC, LVarD)
    Set(LVarB, ROOM_DATA_ENTER_POS_BX)
    Set(LVarD, ROOM_DATA_ENTER_POS_BZ)
    Set(LVarE, 10)
    Call(InterpCamTargetPos, 0, 1, LVarB, LVarC, LVarD, LVarE)
    Call(SetRoomCamMoveSpeed, -1)
    Return
    End
};

EvtScript EVS_ExitRoom_MovePlayerA = {
    Call(GetPlayerPos, LVarB, LVarC, LVarD)
    Set(LVarB, ROOM_DATA_EXIT_POS_AX)
    Set(LVarD, ROOM_DATA_EXIT_POS_AZ)
    Set(LVarE, 10)
    Call(PlayerMoveTo, ROOM_DATA_EXIT_POS_AX, ROOM_DATA_EXIT_POS_AZ, LVarE)
    Call(FacePlayerTowardPoint, ROOM_DATA_EXIT_POS_BX, ROOM_DATA_EXIT_POS_BZ, 0)
    Return
    End
};

EvtScript EVS_ExitRoom_MovePlayerB = {
    Call(SaveDoorPtr)
    Call(GetDoorData)
    Call(GetPlayerPos, LVarB, LVarC, LVarD)
    Set(LVarB, ROOM_DATA_EXIT_POS_BX)
    Set(LVarD, ROOM_DATA_EXIT_POS_BZ)
    Set(LVarE, 20)
    Call(PlayerMoveTo, ROOM_DATA_EXIT_POS_BX, ROOM_DATA_EXIT_POS_BZ, LVarE)
    Return
    End
};

EvtScript EVS_ExitRoom_MoveCam = {
    Call(SetRoomCamMoveSpeed, Float(1.796))
    Call(GetPlayerPos, LVarB, LVarC, LVarD)
    Set(LVarB, ROOM_DATA_EXIT_POS_BX)
    Set(LVarD, ROOM_DATA_EXIT_POS_BZ)
    Set(LVarE, 10)
    Call(InterpCamTargetPos, 0, 1, LVarB, LVarC, LVarD, LVarE)
    Call(SetRoomCamMoveSpeed, -1)
    Return
    End
};

EvtScript EVS_Default_AnimateDoorRot = {
    Call(SaveDoorPtr)
    Set(LVar2, ROOM_DATA_EVT_OPEN_DOOR)
    Set(LVar3, LVar0)
    Switch(LVar0)
        CaseEq(ROOM_MOVE_DOOR_ENTER_OPEN)
            Call(MakeLerp, 0, 90, 10, EASING_CUBIC_OUT)
            Call(PlayRoomDoorSound, SOUND_ROOM_DOOR_OPEN)
        CaseEq(ROOM_MOVE_DOOR_ENTER_CLOSE)
            Call(MakeLerp, 90, 0, 10, EASING_CUBIC_IN)
        CaseEq(ROOM_MOVE_DOOR_EXIT_OPEN)
            Call(MakeLerp, 0, 90, 10, EASING_CUBIC_OUT)
            Call(PlayRoomDoorSound, SOUND_ROOM_DOOR_OPEN)
        CaseEq(ROOM_MOVE_DOOR_EXIT_CLOSE)
            Call(MakeLerp, 90, 0, 10, EASING_CUBIC_IN)
    EndSwitch
    Label(0)
        Call(UpdateLerp)
        Exec(LVar2)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Switch(LVar3)
        CaseEq(ROOM_MOVE_DOOR_ENTER_CLOSE)
            Call(PlayRoomDoorSound, SOUND_ROOM_DOOR_CLOSE)
        CaseEq(ROOM_MOVE_DOOR_EXIT_CLOSE)
            Call(PlayRoomDoorSound, SOUND_ROOM_DOOR_CLOSE)
    EndSwitch
    Return
    End
};

EvtScript EVS_Default_AnimateWallRot = {
    Set(LVar2, ROOM_DATA_EVT_MOVE_WALL)
    Switch(LVar0)
        CaseEq(ROOM_MOVE_WALL_OPEN)
            Call(MakeLerp, 0, 90, 20, EASING_CUBIC_OUT)
        CaseEq(ROOM_MOVE_WALL_1)
            Call(MakeLerp, 90, 0, 20, EASING_CUBIC_IN)
        CaseEq(ROOM_MOVE_WALL_2)
            Call(MakeLerp, 0, 90, 20, EASING_CUBIC_OUT)
        CaseEq(ROOM_MOVE_WALL_CLOSE)
            Call(MakeLerp, 90, 0, 20, EASING_CUBIC_IN)
    EndSwitch
    Label(0)
        Call(UpdateLerp)
        Exec(LVar2)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript EVS_Default_AnimateDropDoor = {
    Set(LVar2, ROOM_DATA_EVT_DROP_DOOR)
    Switch(LVar0)
        CaseEq(ROOM_DROP_DOOR_ENTER)
            Call(MakeLerp, 0, 90, 20, EASING_CUBIC_IN)
        CaseEq(ROOM_DROP_DOOR_1)
            Call(MakeLerp, 90, 0, 10, EASING_CUBIC_OUT)
        CaseEq(ROOM_DROP_DOOR_2)
            Call(MakeLerp, 0, 90, 20, EASING_CUBIC_IN)
        CaseEq(ROOM_DROP_DOOR_EXIT)
            Call(MakeLerp, 90, 0, 10, EASING_CUBIC_OUT)
    EndSwitch
    Label(0)
        Call(UpdateLerp)
        Exec(LVar2)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Return
    End
};

// executed from trigger activatation with MapRoom* stored in LVar1
EvtScript EVS_EnterRoomDoor = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    // ensure valid player action state
    Call(GetPlayerActionState, LVar3)
    Set(LVar4, 0)
    IfEq(LVar3, ACTION_STATE_IDLE)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_WALK)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_RUN)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar4, 0)
        Return
    EndIf

    // initialize
    Call(SaveDoorPtr)
    Call(GetDoorState)
    IfNe(LVar0, ROOM_STATE_IDLE)
        Return
    EndIf
    Call(SetDoorState, ROOM_STATE_ENTERING)
    Call(HideRoomNPCs)
    Call(UseRoomItemVisGroup)
    Call(DisablePlayerPhysics, true)
    Call(DisablePlayerInput, true)

    // notify listener ROOM_UPDATE_ENTER_BEGIN
    Call(GetDoorData)
    Set(LVar0, ROOM_UPDATE_ENTER_BEGIN)
    IfNe(ROOM_DATA_EVT_LISTENER, nullptr)
        ExecWait(ROOM_DATA_EVT_LISTENER)
    EndIf
    IfEq(LVar0, ROOM_UPDATE_REQUEST_CANCEL)
        Goto(1)
    EndIf

    // adjust camera to face door
    Call(GetDoorData)
    Exec(EVS_EnterRoom_MoveCam)

    // move player to door
    Call(GetDoorData)
    BitwiseAndConst(LVar2, ROOM_FLAGS_DOOR_TYPE_MASK)
    Set(LVarE, 10)
    Switch(LVar2)
        CaseEq(ROOM_DOOR_RIGHT_HINGE_OPENS_OUT)
            ExecWait(EVS_EnterRoom_MovePlayerA)
        CaseEq(ROOM_DOOR_LEFT_HINGE_OPENS_OUT)
            ExecWait(EVS_EnterRoom_MovePlayerA)
        CaseEq(ROOM_DOOR_STRAIGHT_THROUGH)
            ExecWait(EVS_EnterRoom_MovePlayerA)
        CaseEq(ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT)
            Set(LVarE, 20)
            ExecWait(EVS_EnterRoom_MovePlayerA)
        CaseEq(ROOM_LARGE_DOOR_LEFT_HINGE_OPENS_OUT)
            Set(LVarE, 20)
            ExecWait(EVS_EnterRoom_MovePlayerA)
    EndSwitch

    // reveal room interior and hide world
    Call(GetDoorData)
    Set(LVar0, ROOM_VISIBILITY_SHOW)
    Call(GetDoorPtr)
    IfNe(ROOM_DATA_MODEL_ID, 0)
        ExecGetTID(EVS_RoomContentVisiblityToggle, LVar5)
        Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_0, LVar5)
    EndIf
    Call(SetEntityHideMode1)
    IfNe(ROOM_DATA_MODEL_ID, 0)
        Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_0)
    EndIf

    // wall movement animation
    Call(GetDoorData)
    Set(LVar0, ROOM_MOVE_WALL_OPEN)
    BitwiseAndConst(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_WALL_ROT)
    IfNe(ROOM_DATA_EVT_MOVE_WALL, nullptr)
        IfNe(ROOM_DATA_FLAGS, 0)
            ExecGetTID(ROOM_DATA_EVT_MOVE_WALL, LVar5)
        Else
            ExecGetTID(EVS_Default_AnimateWallRot, LVar5)
        EndIf
    EndIf
    IfNe(ROOM_DATA_EVT_MOVE_WALL, nullptr)
        Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_0, LVar5)
    EndIf

    // open the door
    Set(LVar0, ROOM_MOVE_DOOR_ENTER_OPEN)
    BitwiseAndConst(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    IfNe(ROOM_DATA_FLAGS, 0)
        ExecGetTID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    Else
        ExecGetTID(EVS_Default_AnimateDoorRot, LVar5)
    EndIf
    Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar5)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
    Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)

    // move party through the doorway
    Call(SetEntityHideMode2)
    ExecGetTID(EVS_EnterRoom_MovePlayerB, LVar7)
    Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar7)
    Wait(10)
    Call(SaveDoorPtr)
    Call(GetDoorData)
    Call(MovePartnerThroughDoor, ROOM_DATA_ENTER_POS_BX, ROOM_DATA_ENTER_POS_BZ)

    // allow input when movement is done
    Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)
    Call(DisablePlayerInput, false)
    Call(DisablePlayerPhysics, false)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, false)
    Call(ResetPartnerMovement)

    // close the door
    Set(LVar0, ROOM_MOVE_DOOR_ENTER_CLOSE)
    BitwiseAndConst(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    IfNe(ROOM_DATA_FLAGS, 0)
        ExecGetTID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    Else
        ExecGetTID(EVS_Default_AnimateDoorRot, LVar5)
    EndIf
    Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_3, LVar5)

    // drop the door
    Set(LVar0, ROOM_DROP_DOOR_ENTER)
    BitwiseAndConst(ROOM_DATA_FLAGS, ROOM_FLAG_CUSTOM_ANIM_DROP_DOOR)
    IfNe(ROOM_DATA_EVT_DROP_DOOR, nullptr)
        Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_3)
        IfNe(ROOM_DATA_FLAGS, 0)
            ExecGetTID(ROOM_DATA_EVT_DROP_DOOR, LVar5)
        Else
            ExecGetTID(EVS_Default_AnimateDropDoor, LVar5)
        EndIf
    EndIf
    IfNe(ROOM_DATA_EVT_DROP_DOOR, nullptr)
        Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EndIf

    // notify listener ROOM_UPDATE_ENTER_DONE
    Set(LVar0, ROOM_UPDATE_ENTER_DONE)
    IfNe(ROOM_DATA_EVT_LISTENER, nullptr)
        ExecGetTID(ROOM_DATA_EVT_LISTENER, LVar5)
    EndIf
    IfNe(ROOM_DATA_EVT_LISTENER, nullptr)
        Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_2, LVar5)
    EndIf
    IfNe(ROOM_DATA_EVT_LISTENER, nullptr)
        Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_2)
    EndIf

    // wait for all anim scripts
    IfNe(ROOM_DATA_EVT_MOVE_WALL, nullptr)
        Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_0)
    EndIf
    IfNe(ROOM_DATA_EVT_DROP_DOOR, nullptr)
        Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    EndIf

    // reset and return
    Call(SetDoorState, ROOM_STATE_IDLE)
    Return

    // handle ROOM_UPDATE_REQUEST_CANCEL from callback to ROOM_UPDATE_ENTER_BEGIN
    Label(1)
    Call(SetDoorState, ROOM_STATE_IDLE)
    Label(0)
    Call(DisablePlayerInput, false)
    Call(DisablePlayerPhysics, false)
    Return
    End
};

// executed from trigger activatation with MapRoom* stored in LVar1
EvtScript EVS_ExitRoomDoor = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    // ensure valid player action state
    Call(GetPlayerActionState, LVar3)
    Set(LVar4, 0)
    IfEq(LVar3, ACTION_STATE_IDLE)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_WALK)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_RUN)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar4, 0)
        Return
    EndIf

    // initialize
    Call(SaveDoorPtr)
    Call(GetDoorState)
    IfNe(LVar0, ROOM_STATE_IDLE)
        Return
    EndIf
    Call(SetDoorState, ROOM_STATE_EXITING)
    Call(DisablePlayerPhysics, true)
    Call(DisablePlayerInput, true)

    // notify listener ROOM_UPDATE_EXIT_BEGIN
    Call(GetDoorData)
    Set(LVar0, ROOM_UPDATE_EXIT_BEGIN)
    IfNe(ROOM_DATA_EVT_LISTENER, nullptr)
        ExecWait(ROOM_DATA_EVT_LISTENER)
    EndIf
    IfEq(LVar0, ROOM_UPDATE_REQUEST_CANCEL)
        Goto(1)
    EndIf

    // adjust camera to face door
    Call(GetDoorData)
    Exec(EVS_ExitRoom_MoveCam)

    // move player to door
    Call(GetDoorData)
    BitwiseAndConst(LVar2, ROOM_FLAGS_DOOR_TYPE_MASK)
    Switch(LVar2)
        CaseEq(ROOM_DOOR_RIGHT_HINGE_OPENS_IN)
            ExecWait(EVS_ExitRoom_MovePlayerA)
        CaseEq(ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_IN)
            ExecWait(EVS_ExitRoom_MovePlayerA)
        CaseEq(ROOM_DOOR_LEFT_HINGE_OPENS_IN)
            ExecWait(EVS_ExitRoom_MovePlayerA)
    EndSwitch

    // wall movement animation
    Call(GetDoorData)
    Call(GetDoorPtr)
    Set(LVar0, ROOM_MOVE_WALL_CLOSE)
    BitwiseAndConst(LVar2, ROOM_FLAG_CUSTOM_ANIM_WALL_ROT)
    IfNe(ROOM_DATA_EVT_MOVE_WALL, nullptr)
        IfNe(LVar2, 0)
            ExecGetTID(ROOM_DATA_EVT_MOVE_WALL, LVar5)
        Else
            ExecGetTID(EVS_Default_AnimateWallRot, LVar5)
        EndIf
    EndIf
    IfNe(ROOM_DATA_EVT_MOVE_WALL, nullptr)
        Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_0, LVar5)
    EndIf

    // raise the door if its been dropped
    Set(LVar0, ROOM_DROP_DOOR_EXIT)
    BitwiseAndConst(LVar2, ROOM_FLAG_CUSTOM_ANIM_DROP_DOOR)
    IfNe(ROOM_DATA_EVT_DROP_DOOR, nullptr)
        IfNe(LVar2, 0)
            ExecGetTID(ROOM_DATA_EVT_DROP_DOOR, LVar5)
        Else
            ExecGetTID(EVS_Default_AnimateDropDoor, LVar5)
        EndIf
    EndIf
    IfNe(ROOM_DATA_EVT_DROP_DOOR, nullptr)
        Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    EndIf
    IfNe(ROOM_DATA_EVT_DROP_DOOR, nullptr)
        Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    EndIf

    // open the door
    Set(LVar0, ROOM_MOVE_DOOR_EXIT_OPEN)
    BitwiseAndConst(LVar2, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    IfNe(LVar2, 0)
        ExecGetTID(ROOM_DATA_EVT_OPEN_DOOR, LVar5)
    Else
        ExecGetTID(EVS_Default_AnimateDoorRot, LVar5)
    EndIf
    Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)

    // move party through the doorway
    Call(GetDoorPtr)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
    Call(SaveDoorPtr)
    Call(GetDoorData)
    Call(MovePartnerThroughDoor, ROOM_DATA_EXIT_POS_BX, ROOM_DATA_EXIT_POS_BZ)
    ExecGetTID(EVS_ExitRoom_MovePlayerB, LVar5)
    Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_1, LVar5)
    Call(SetEntityHideMode0)

    // hide room interior and reveal world
    Set(LVar0, ROOM_VISIBILITY_HIDE)
    IfNe(ROOM_DATA_MODEL_ID, 0)
        ExecGetTID(EVS_RoomContentVisiblityToggle, LVar5)
    EndIf
    IfNe(ROOM_DATA_MODEL_ID, 0)
        Call(SaveUseDoorScript, ROOM_SCRIPT_IDX_2, LVar5)
    EndIf
    IfNe(ROOM_DATA_MODEL_ID, 0)
        Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_2)
    EndIf

    // allow input when movement is done
    Call(AwaitUseDoorScript, ROOM_SCRIPT_IDX_1)
    Call(DisablePlayerInput, false)
    Call(DisablePlayerPhysics, false)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, false)
    Call(ResetPartnerMovement)

    // close the door
    Call(GetDoorData)
    Set(LVar0, ROOM_MOVE_DOOR_EXIT_CLOSE)
    BitwiseAndConst(LVar2, ROOM_FLAG_CUSTOM_ANIM_OPEN_DOOR)
    IfNe(LVar2, 0)
        ExecWait(ROOM_DATA_EVT_OPEN_DOOR)
    Else
        ExecWait(EVS_Default_AnimateDoorRot)
    EndIf

    // notify listener ROOM_UPDATE_EXIT_END
    Call(GetDoorData)
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    IfNe(ROOM_DATA_EVT_LISTENER, nullptr)
        ExecWait(ROOM_DATA_EVT_LISTENER)
    EndIf

    // reset and return
    Call(RevealHiddenRoomNPCs)
    Call(RestorePrevItemVisGroup)
    Call(SetDoorState, ROOM_STATE_IDLE)
    Return

    // handle ROOM_UPDATE_REQUEST_CANCEL from callback to ROOM_UPDATE_ENTER_BEGIN
    Label(1)
    Call(SetDoorState, ROOM_STATE_IDLE)
    Label(0)
    Call(DisablePlayerPhysics, false)
    Call(DisablePlayerInput, false)
    Return
    End
};
