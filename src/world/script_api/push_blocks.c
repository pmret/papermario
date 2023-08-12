#include "common.h"
#include "entity.h"

extern PushBlockGrid* wPushBlockGrids[8];

// outVars for values returned by FetchPushedBlockProperties
// TODO fix ordering (swap XYZ, IJK)
enum {
    BLOCK_PROP_X    = LVar0,
    BLOCK_PROP_Y    = LVar1,
    BLOCK_PROP_Z    = LVar2,
    BLOCK_PROP_I    = LVar3,
    BLOCK_PROP_J    = LVar4,
    BLOCK_PROP_K    = LVar5,
    BLOCK_PROP_DI   = LVar6,
    BLOCK_PROP_DJ   = LVar7,
    BLOCK_PROP_DK   = LVar8,
    BLOCK_PROP_RESULT   = LVar9,
};

// values for BLOCK_PROP_RESULT
enum {
    PUSH_BLOCK_READY        = 0,
    PUSH_BLOCK_OBSTRUCTED   = 1,
    PUSH_BLOCK_INVALID      = 2,
};

f32 PushBlockMovePositions[] = {
    0.04, 0.04, 0.08, 0.16, 0.21, 0.4, 0.6, 0.72, 0.84, 0.92, 0.96, 0.96, 1.0,
};

API_CALLABLE(MovePlayerTowardBlock) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->pos.x += (script->varTable[0] - playerStatus->pos.x) / 2;
    playerStatus->pos.z += (script->varTable[2] - playerStatus->pos.z) / 2;

    return ApiStatus_DONE2;
}

API_CALLABLE(UpdatePushBlockMotion) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Entity* entity = get_entity_by_index(script->varTable[11]);
    f32 moveRatio;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->varTable[0] = playerStatus->pos.x;
        script->varTable[1] = playerStatus->pos.y;
        script->varTable[2] = playerStatus->pos.z;
        script->varTable[3] = entity->pos.x;
        script->varTable[4] = entity->pos.y;
        script->varTable[5] = entity->pos.z;
        script->varTable[9] = entity->rot.x;
        script->varTable[12] = entity->rot.z;
    }

    moveRatio = PushBlockMovePositions[script->functionTemp[0]];
    playerStatus->pos.x = script->varTable[0] + (script->varTable[6] * moveRatio * BLOCK_GRID_SIZE);
    playerStatus->pos.y = script->varTable[1] + (script->varTable[7] * moveRatio * BLOCK_GRID_SIZE);
    playerStatus->pos.z = script->varTable[2] + (script->varTable[8] * moveRatio * BLOCK_GRID_SIZE);
    entity->pos.x = script->varTable[3] + (script->varTable[6] * moveRatio * BLOCK_GRID_SIZE);
    entity->pos.y = script->varTable[4] + (script->varTable[7] * moveRatio * BLOCK_GRID_SIZE);
    entity->pos.z = script->varTable[5] + (script->varTable[8] * moveRatio * BLOCK_GRID_SIZE);

    if (script->functionTemp[0] < 12) {
        entity->rot.z = script->varTable[12] + (script->varTable[6] * moveRatio * -90.0f);
        entity->rot.x = script->varTable[9] + (script->varTable[8] * moveRatio * 90.0f);
        entity->pos.y = entity->pos.y + (sin_deg(moveRatio * 90.0f) * BLOCK_GRID_SIZE * 0.5);
        entity->pos.x = entity->pos.x - (script->varTable[6] * sin_deg(moveRatio * 90.0f) * BLOCK_GRID_SIZE * 0.5);
        entity->pos.z = entity->pos.z - (script->varTable[8] * sin_deg(moveRatio * 90.0f) * BLOCK_GRID_SIZE * 0.5);
    } else {
        entity->rot.z = entity->rot.x = 0.0f;
    }

    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;

    script->functionTemp[0]++;
    if (script->functionTemp[0] == ARRAY_COUNT(PushBlockMovePositions)) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(FinishPushBlockMotion) {
    PushBlockGrid* grid = script->varTablePtr[10];
    Entity* block = get_entity_by_index(script->varTable[11]);
    f32 hitX, hitY, hitZ, hitDepth;
    s32 hitResult;
    s32 i, j;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->varTable[0] = block->pos.y;

        hitX = block->pos.x;
        hitZ = block->pos.z;
        hitY = block->pos.y + 5.0f;

        hitDepth = 35.0f;
        hitResult = npc_raycast_down_sides(0, &hitX, &hitY, &hitZ, &hitDepth);
        script->functionTemp[1] = hitDepth;

        if (hitResult != 0 && hitDepth <= 6.0f) {
            return ApiStatus_DONE2;
        }
    }

    if (grid->dropCallback != NULL) {
        if (grid->dropCallback(block, script)) {
            i = (block->pos.x - grid->centerPos.x) / BLOCK_GRID_SIZE;
            j = (block->pos.z - grid->centerPos.z) / BLOCK_GRID_SIZE;
            grid->cells[i + (j * grid->numCellsX)] = 0;
            return ApiStatus_DONE1;
        } else {
            return ApiStatus_BLOCK;
        }
    } else {
        block->pos.y = script->varTable[0] - (PushBlockMovePositions[script->functionTemp[0]] * BLOCK_GRID_SIZE);
        script->functionTemp[0]++;
        if (script->functionTemp[0] != ARRAY_COUNT(PushBlockMovePositions)) {
            return ApiStatus_BLOCK;
        }
        i = (block->pos.x - grid->centerPos.x) / BLOCK_GRID_SIZE;
        j = (block->pos.z - grid->centerPos.z) / BLOCK_GRID_SIZE;
        grid->cells[i + (j * grid->numCellsX)] = PUSH_GRID_EMPTY;
    }
    return ApiStatus_DONE1;
}

API_CALLABLE(FetchPushedBlockProperties) {
    PushBlockGrid* grid = (PushBlockGrid*) script->varTable[10];
    Entity* entity = get_entity_by_index(script->varTable[11]);
    s32 gridCenterX, gridCenterY, gridCenterZ;
    s32 xThing, yThing, zThing;
    s32 entityX, entityY, entityZ;
    s32 varX, varZ;
    s32 deltaX, deltaZ;
    s32 cellX, cellZ;
    s32 x2, z2;

    gridCenterX = grid->centerPos.x;
    gridCenterY = grid->centerPos.y;
    gridCenterZ = grid->centerPos.z;

    xThing = gPlayerStatus.pos.x;
    yThing = gPlayerStatus.pos.y;
    zThing = gPlayerStatus.pos.z;

    xThing -= gridCenterX;
    yThing -= gridCenterY;
    zThing -= gridCenterZ;

    if (xThing < 0) {
        xThing -= BLOCK_GRID_SIZE;
    }
    if (zThing < 0) {
        zThing -= BLOCK_GRID_SIZE;
    }

    xThing /= BLOCK_GRID_SIZE;
    yThing /= BLOCK_GRID_SIZE;
    zThing /= BLOCK_GRID_SIZE;

    varX = xThing;
    varZ = zThing;

    xThing *= BLOCK_GRID_SIZE;
    yThing *= BLOCK_GRID_SIZE;
    zThing *= BLOCK_GRID_SIZE;

    xThing += (BLOCK_GRID_SIZE / 2) + gridCenterX;
    yThing += gridCenterY;
    zThing += (BLOCK_GRID_SIZE / 2) + gridCenterZ;

    script->varTable[0] = xThing;
    script->varTable[1] = yThing;
    script->varTable[2] = zThing;

    script->varTable[3] = entityX = entity->pos.x;
    script->varTable[4] = entityY = entity->pos.y;
    script->varTable[5] = entityZ = entity->pos.z;

    xThing = entityX - grid->centerPos.x;
    zThing = entityZ - grid->centerPos.z;
    x2 = xThing / BLOCK_GRID_SIZE;
    z2 = zThing / BLOCK_GRID_SIZE;

    deltaX = x2 - varX;
    deltaZ = z2 - varZ;

    if (deltaX != 0 && deltaZ != 0) {
        deltaX = deltaZ = 0;
    }

    script->varTable[6] = deltaX;
    script->varTable[7] = 0;
    script->varTable[8] = deltaZ;

    cellX = x2 + deltaX;
    cellZ = z2 + deltaZ;

    if (deltaX == 0 && deltaZ == 0) {
        do {
            script->varTable[9] = 2;
        } while (0);
        return ApiStatus_DONE2;
    }

    if (cellX < grid->numCellsX && cellX >= 0
        && cellZ < grid->numCellsZ && cellZ >= 0
        && grid->cells[cellX + (cellZ * grid->numCellsX)] == PUSH_GRID_EMPTY
        && gCollisionStatus.pushingAgainstWall != NO_COLLIDER)
    {
        script->varTable[9] = 0;
    } else {
        script->varTable[9] = 1;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(ClearPushedBlockFromGrid) {
    PushBlockGrid* grid = script->varTablePtr[10];
    Entity* block = get_entity_by_index(script->varTable[11]);
    s32 ip, jp; // prev grid pos (i,j)
    s32 in, jn; // next grid pos (i,j)

    ip = ((s32)block->pos.x - grid->centerPos.x) / BLOCK_GRID_SIZE;
    jp = ((s32)block->pos.z - grid->centerPos.z) / BLOCK_GRID_SIZE;
    in = ip + script->varTable[6];
    jn = jp + script->varTable[8];

    grid->cells[in + (jn * grid->numCellsX)] = grid->cells[ip + (jp * grid->numCellsX)];
    grid->cells[ip + (jp * grid->numCellsX)] = PUSH_GRID_EMPTY;

    return ApiStatus_DONE2;
}

API_CALLABLE(CanPlayerPushBlock) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 blockCollider = script->varTable[11] + COLLISION_WITH_ENTITY_BIT;

    if ((gCollisionStatus.pushingAgainstWall == blockCollider)
        && (playerStatus->actionState == ACTION_STATE_PUSHING_BLOCK
        || playerStatus->actionState == ACTION_STATE_WALK
        || playerStatus->actionState == ACTION_STATE_RUN)
        && !(playerStatus->animFlags & PA_FLAG_USING_WATT))
    {
        script->varTable[13] = TRUE;
    } else {
        script->varTable[13] = FALSE;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(CheckPlayerActionState) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    s32 checkState = evt_get_float_variable(script, *args++);

    evt_set_variable(script, outVar, gPlayerStatus.actionState == checkState);
    return ApiStatus_DONE2;
}

API_CALLABLE(IsEventForSourceRunning) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    Bytecode* sourceToFind = (Bytecode*)evt_get_variable(script, *args++);

    s32 foundScript = FALSE;
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        Evt* iterScript = get_script_by_index(i);

        if (iterScript != NULL) {
            if (iterScript->ptrFirstLine == sourceToFind) {
                foundScript = TRUE;
                break;
            }
        }
    }
    evt_set_variable(script, outVar, foundScript);
    return ApiStatus_DONE2;
}

EvtScript EVS_PushWall_PushBlock = {
    EVT_SET(LVarA, LVar0) // grid system
    EVT_SET(LVarB, LVar1) // block entity ID
    // check cell where the block will move to
    EVT_CALL(FetchPushedBlockProperties)
    EVT_CALL(FacePlayerTowardPoint, BLOCK_PROP_I, BLOCK_PROP_K, 0)
    EVT_IF_NE(LVar9, PUSH_BLOCK_INVALID)
        EVT_CALL(MovePlayerTowardBlock)
    EVT_END_IF
    // try setting the player action state
    EVT_SET(LVarC, 0)
    EVT_CALL(CheckPlayerActionState, LVarD, ACTION_STATE_RUN)
    EVT_IF_EQ(LVarD, FALSE)
        EVT_CALL(CheckPlayerActionState, LVarD, ACTION_STATE_PUSHING_BLOCK)
        EVT_IF_EQ(LVarD, FALSE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    // cancel state change if the block can't be pushed
    EVT_IF_NE(LVar9, PUSH_BLOCK_READY)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_RETURN
    EVT_END_IF
    // wait for 8 frames of pushing
    EVT_SET(LVarC, 0)
    EVT_LABEL(0)
        EVT_ADD(LVarC, 1)
        EVT_CALL(CanPlayerPushBlock)
        EVT_IF_EQ(LVarD, TRUE)
            EVT_GOTO(1)
        EVT_END_IF
            EVT_CALL(GetPlayerActionState, LVarD)
            EVT_IF_EQ(LVarD, ACTION_STATE_JUMP)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
            EVT_RETURN
        EVT_LABEL(1)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_CALL(MovePlayerTowardBlock)
        EVT_IF_LT(LVarC, 8)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    // perform the push
    EVT_CALL(ClearPushedBlockFromGrid)
    EVT_CALL(PlaySound, SOUND_PUSH_BLOCK)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(UpdatePushBlockMotion)
    EVT_CALL(FinishPushBlockMotion)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(CheckPlayerActionState, LVarD, ACTION_STATE_PUSHING_BLOCK)
        EVT_IF_NE(LVarD, FALSE)
            EVT_CALL(IsEventForSourceRunning, LVarD, EVT_PTR(EVS_PushWall_PushBlock))
            EVT_IF_EQ(LVarD, FALSE)
                EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(CreatePushBlockGrid) {
    Bytecode* arg = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *arg++);
    s32 sizeNx = evt_get_variable(script, *arg++);
    s32 sizeNz = evt_get_variable(script, *arg++);
    s32 centerX = evt_get_variable(script, *arg++);
    s32 centerY = evt_get_variable(script, *arg++);
    s32 centerZ = evt_get_variable(script, *arg++);
    u8* inputGridData = (u8*) evt_get_variable(script, *arg++);

    PushBlockGrid* blockGrid;
    u8* dataToCopy;
    s32 i;

    wPushBlockGrids[blockSystemID] = blockGrid = general_heap_malloc(sizeof(*blockGrid));

    blockGrid->cells = general_heap_malloc(sizeNx*sizeNz);

    if (inputGridData == NULL) {
        for (i = 0; i < sizeNx*sizeNz; i++) {
            blockGrid->cells[i] = 0;
        }
    } else {
        dataToCopy = inputGridData;
        for (i = 0; i < sizeNx*sizeNz; i++) {
            blockGrid->cells[i] = dataToCopy[i];
        }
    }

    blockGrid->numCellsX = sizeNx;
    blockGrid->numCellsZ = sizeNz;
    blockGrid->centerPos.x = centerX;
    blockGrid->centerPos.y = centerY;
    blockGrid->centerPos.z = centerZ;
    blockGrid->dropCallback = NULL;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPushBlock) {
    Bytecode* args = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *args++);
    s32 gridX = evt_get_variable(script, *args++);
    s32 gridZ = evt_get_variable(script, *args++);
    s32 occupant = evt_get_variable(script, *args++);

    PushBlockGrid* blockGrid = wPushBlockGrids[blockSystemID];
    s32 blockEntityID;
    s32 cellIndex;

    cellIndex = gridX + (gridZ * blockGrid->numCellsX);
    blockGrid->cells[cellIndex] = occupant;

    if (occupant == PUSH_GRID_BLOCK) {
        s32 posX = blockGrid->centerPos.x + (gridX * BLOCK_GRID_SIZE) + (BLOCK_GRID_SIZE / 2);
        s32 posY = blockGrid->centerPos.y;
        s32 posZ = blockGrid->centerPos.z + (gridZ * BLOCK_GRID_SIZE) + (BLOCK_GRID_SIZE / 2);
        blockEntityID = create_entity(&Entity_PushBlock, posX, posY, posZ, 0, 0, 0, 0, MAKE_ENTITY_END);
        bind_trigger_1(&EVS_PushWall_PushBlock, TRIGGER_WALL_PUSH, blockEntityID + EVT_ENTITY_ID_BIT, (s32)blockGrid, blockEntityID, 3);
        script->varTable[0] = blockEntityID;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPushBlock) {
    Bytecode* args = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *args++);
    s32 gridX = evt_get_variable(script, *args++);
    s32 gridZ = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    PushBlockGrid* blockGrid = wPushBlockGrids[blockSystemID];
    s32 cellIndex;

    if (gridX >= blockGrid->numCellsX || gridX < 0 || gridZ >= blockGrid->numCellsZ || gridZ < 0) {
         // @bug: sets error value and then performs lookup anyway -- return statement forgotten here
        evt_set_variable(script, outVar, PUSH_GRID_OUT_OF_BOUNDS);
    }
    cellIndex = gridX + (gridZ * blockGrid->numCellsX);
    evt_set_variable(script, outVar, blockGrid->cells[cellIndex]);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetGridIndexFromPos) {
    Bytecode* args = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *args++);
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    Bytecode outVarX = *args++;
    Bytecode outVarZ = *args++;

    PushBlockGrid* blockGrid = wPushBlockGrids[blockSystemID];
    s32 gridX;
    s32 gridZ;

    posX -= blockGrid->centerPos.x;
    gridX = posX / BLOCK_GRID_SIZE;
    posZ -= blockGrid->centerPos.z;
    gridZ = posZ / BLOCK_GRID_SIZE;

    evt_set_variable(script, outVarX, gridX);
    evt_set_variable(script, outVarZ, gridZ);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPushBlockFallEffect) {
    Bytecode* args = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *args++);
    PushBlockFallCallback fallCallback = (PushBlockFallCallback)evt_get_variable(script, *args++);

    wPushBlockGrids[blockSystemID]->dropCallback = fallCallback;

    return ApiStatus_DONE2;
}
