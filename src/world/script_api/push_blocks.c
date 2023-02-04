#include "common.h"
#include "entity.h"

extern PushBlockGrid* D_802DBC88[8];

f32 D_80285640_7E64C0[] = {
    0.04, 0.04, 0.08, 0.16, 0.21, 0.4, 0.6, 0.72, 0.84, 0.92, 0.96, 0.96, 1.0,
};

API_CALLABLE(func_80282880) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->position.x += (script->varTable[0] - playerStatus->position.x) / 2;
    playerStatus->position.z += (script->varTable[2] - playerStatus->position.z) / 2;

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802828DC) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Entity* entity = get_entity_by_index(script->varTable[11]);
    f32 temp_f4;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->varTable[0] = playerStatus->position.x;
        script->varTable[1] = playerStatus->position.y;
        script->varTable[2] = playerStatus->position.z;
        script->varTable[3] = entity->position.x;
        script->varTable[4] = entity->position.y;
        script->varTable[5] = entity->position.z;
        script->varTable[9] = entity->rotation.x;
        script->varTable[12] = entity->rotation.z;
    }

    temp_f4 = D_80285640_7E64C0[script->functionTemp[0]];
    playerStatus->position.x = script->varTable[0] + (script->varTable[6] * temp_f4 * BLOCK_GRID_SIZE);
    playerStatus->position.y = script->varTable[1] + (script->varTable[7] * temp_f4 * BLOCK_GRID_SIZE);
    playerStatus->position.z = script->varTable[2] + (script->varTable[8] * temp_f4 * BLOCK_GRID_SIZE);
    entity->position.x = script->varTable[3] + (script->varTable[6] * temp_f4 * BLOCK_GRID_SIZE);
    entity->position.y = script->varTable[4] + (script->varTable[7] * temp_f4 * BLOCK_GRID_SIZE);
    entity->position.z = script->varTable[5] + (script->varTable[8] * temp_f4 * BLOCK_GRID_SIZE);

    if (script->functionTemp[0] < 12) {
        entity->rotation.z = script->varTable[12] + (script->varTable[6] * temp_f4 * -90.0f);
        entity->rotation.x = script->varTable[9] + (script->varTable[8] * temp_f4 * 90.0f);
        entity->position.y = entity->position.y + (sin_deg(temp_f4 * 90.0f) * BLOCK_GRID_SIZE * 0.5);
        entity->position.x = entity->position.x - (script->varTable[6] * sin_deg(temp_f4 * 90.0f) * BLOCK_GRID_SIZE * 0.5);
        entity->position.z = entity->position.z - (script->varTable[8] * sin_deg(temp_f4 * 90.0f) * BLOCK_GRID_SIZE * 0.5);
    } else {
        entity->rotation.z = entity->rotation.x = 0.0f;
    }

    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;

    script->functionTemp[0]++;
    if (script->functionTemp[0] == ARRAY_COUNT(D_80285640_7E64C0)) {
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(func_80282C40) {
    PushBlockGrid* grid = script->varTablePtr[10];
    Entity* block = get_entity_by_index(script->varTable[11]);
    f32 hitX, hitY, hitZ, hitDepth;
    s32 hitResult;
    s32 i, j;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->varTable[0] = block->position.y;

        hitX = block->position.x;
        hitZ = block->position.z;
        hitY = block->position.y + 5.0f;

        hitDepth = 35.0f;
        hitResult = npc_raycast_down_sides(0, &hitX, &hitY, &hitZ, &hitDepth);
        script->functionTemp[1] = hitDepth;

        if (hitResult != 0 && hitDepth <= 6.0f) {
            return ApiStatus_DONE2;
        }
    }

    if (grid->dropCallback != NULL) {
        if (grid->dropCallback(block, script)) {
            i = (block->position.x - grid->centerPos.x) / BLOCK_GRID_SIZE;
            j = (block->position.z - grid->centerPos.z) / BLOCK_GRID_SIZE;
            grid->cells[i + (j * grid->numCellsX)] = 0;
            return ApiStatus_DONE1;
        } else {
            return ApiStatus_BLOCK;
        }
    } else {
        block->position.y = script->varTable[0] - (D_80285640_7E64C0[script->functionTemp[0]] * BLOCK_GRID_SIZE);
        script->functionTemp[0]++;
        if (script->functionTemp[0] != ARRAY_COUNT(D_80285640_7E64C0)) {
            return ApiStatus_BLOCK;
        }
        i = (block->position.x - grid->centerPos.x) / BLOCK_GRID_SIZE;
        j = (block->position.z - grid->centerPos.z) / BLOCK_GRID_SIZE;
        grid->cells[i + (j * grid->numCellsX)] = PUSH_GRID_EMPTY;
    }
    return ApiStatus_DONE1;
}

API_CALLABLE(func_80282E30);
// regalloc
#ifdef NON_MATCHING
API_CALLABLE(func_80282E30) {
    PushBlockGrid* grid = (PushBlockGrid*) script->varTable[10];
    Entity* entity = get_entity_by_index(script->varTable[11]);
    s32 xThing, yThing, zThing;
    s32 x, y, z;
    s32 entityY, entityZ;
    s32 varX, varY, varZ;
    s32 newX, newY, newZ;

    s32 temp_f4;
    s32 temp_t2_2;
    s32 temp_v0;
    s32 var_a0_2;
    s32 var_a1;
    s32 cellX, cellZ;

    x = grid->centerPos.x;
    y = grid->centerPos.y;
    z = grid->centerPos.z;

    xThing = gPlayerStatus.position.x;
    yThing = gPlayerStatus.position.y;
    zThing = gPlayerStatus.position.z;

    xThing = xThing - x;
    yThing = yThing - y;
    zThing = zThing - z;
    if (xThing < 0) {
        do {
            xThing -= BLOCK_GRID_SIZE;
        } while (0);
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

    script->varTable[0] = xThing += 12 + x;
    script->varTable[1] = yThing += y;
    script->varTable[2] = zThing += 12 + z;

    script->varTable[3] = xThing = entity->position.x;
    script->varTable[4] = yThing = entity->position.y;
    script->varTable[5] = entityZ = entity->position.z;

    xThing = (xThing - grid->centerPos.x);
    xThing /= BLOCK_GRID_SIZE;
    var_a1 = xThing - varX;
    entityZ = (entityZ - grid->centerPos.z);
    entityZ /= BLOCK_GRID_SIZE;
    var_a0_2 = entityZ - varZ;
    if (var_a1 != 0 && var_a0_2 != 0) {
        var_a0_2 = 0;
        var_a1 = 0;
    }
    script->varTable[6] = var_a1;
    script->varTable[7] = 0;
    script->varTable[8] = var_a0_2;

    cellX = xThing + var_a1;
    cellZ = entityZ + var_a0_2;
    if (var_a1 == 0 && var_a0_2 == 0) {
        do {
            script->varTable[9] = 2;
        } while (0);
        return ApiStatus_DONE2;
    }

    if ((cellX < grid->numCellsX) && (cellX >= 0) &&
        (cellZ < grid->numCellsZ) && (cellZ >= 0) &&
        (grid->cells[cellX + (cellZ * grid->numCellsX)] == PUSH_GRID_EMPTY) &&
        (gCollisionStatus.pushingAgainstWall != -1))
    {
        script->varTable[9] = 0;
    } else {
        script->varTable[9] = 1;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/script_api/push_blocks", func_80282E30);
#endif

API_CALLABLE(func_80283080) {
    PushBlockGrid* grid = script->varTablePtr[10];
    Entity* block = get_entity_by_index(script->varTable[11]);
    s32 ip, jp;
    s32 in, jn;

    ip = ((s32)block->position.x - grid->centerPos.x) / BLOCK_GRID_SIZE;
    jp = ((s32)block->position.z - grid->centerPos.z) / BLOCK_GRID_SIZE;
    in = ip + script->varTable[6];
    jn = jp + script->varTable[8];

    grid->cells[in + (jn * grid->numCellsX)] = grid->cells[ip + (jp * grid->numCellsX)];
    grid->cells[ip + (jp * grid->numCellsX)] = PUSH_GRID_EMPTY;

    return ApiStatus_DONE2;
}

API_CALLABLE(func_80283174) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 collider = script->varTable[11] + COLLISION_WITH_ENTITY_BIT;

    if (gCollisionStatus.pushingAgainstWall == collider) {
        if (playerStatus->actionState == ACTION_STATE_PUSHING_BLOCK
        || playerStatus->actionState == ACTION_STATE_WALK
        || playerStatus->actionState == ACTION_STATE_RUN) {
            if (playerStatus->animFlags & PA_FLAG_USING_WATT) {
                script->varTable[13] = FALSE;
            } else {
                script->varTable[13] = TRUE;
            }
        } else {
            script->varTable[13] = FALSE;
        }
    } else {
        script->varTable[13] = FALSE;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(CheckActionState) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    s32 checkState = evt_get_float_variable(script, *args++);

    evt_set_variable(script, outVar, gPlayerStatus.actionState == checkState);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80283240) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    Bytecode* sourceToFind = (Bytecode*)evt_get_variable(script, *args++);

    s32 retVal = FALSE;
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        Evt* iterScript = get_script_by_index(i);

        if (iterScript != NULL) {
            if (iterScript->ptrFirstLine == sourceToFind) {
                retVal = TRUE;
                break;
            }
        }
    }
    evt_set_variable(script, outVar, retVal);
    return ApiStatus_DONE2;
}

EvtScript D_80285674_7E64F4 = {
	EVT_SET(LVarA, LVar0)
	EVT_SET(LVarB, LVar1)
	EVT_CALL(func_80282E30)
	EVT_CALL(func_802D2884, LVar3, LVar5, 0)
	EVT_IF_NE(LVar9, 2)
		EVT_CALL(func_80282880)
	EVT_END_IF
	EVT_SET(LVarC, 0)
	EVT_CALL(CheckActionState, LVarD, ACTION_STATE_RUN)
	EVT_IF_EQ(LVarD, FALSE)
		EVT_CALL(CheckActionState, LVarD, ACTION_STATE_PUSHING_BLOCK)
		EVT_IF_EQ(LVarD, FALSE)
			EVT_RETURN
		EVT_END_IF
	EVT_END_IF
	EVT_IF_NE(LVar9, 0)
		EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
		EVT_RETURN
	EVT_END_IF
	EVT_SET(LVarC, 0)
	EVT_LABEL(0)
	EVT_ADD(LVarC, 1)
	EVT_CALL(func_80283174)
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
	EVT_CALL(func_80282880)
	EVT_IF_LT(LVarC, 8)
		EVT_WAIT(1)
		EVT_GOTO(0)
	EVT_END_IF
	EVT_CALL(func_80283080)
	EVT_CALL(PlaySound, SOUND_2088)
	EVT_CALL(DisablePlayerPhysics, TRUE)
	EVT_CALL(func_802828DC)
	EVT_CALL(func_80282C40)
	EVT_THREAD
		EVT_WAIT(2)
		EVT_CALL(CheckActionState, LVarD, ACTION_STATE_PUSHING_BLOCK)
		EVT_IF_NE(LVarD, FALSE)
			EVT_CALL(func_80283240, LVarD, EVT_PTR(D_80285674_7E64F4))
			EVT_IF_EQ(LVarD, 0)
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

    D_802DBC88[blockSystemID] = blockGrid = general_heap_malloc(sizeof(*blockGrid));

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

    PushBlockGrid* blockGrid = D_802DBC88[blockSystemID];
    s32 blockEntityID;
    s32 cellIndex;

    cellIndex = gridX + (gridZ * blockGrid->numCellsX);
    blockGrid->cells[cellIndex] = occupant;

    if (occupant == PUSH_GRID_BLOCK) {
        s32 posX = blockGrid->centerPos.x + (gridX * BLOCK_GRID_SIZE) + (BLOCK_GRID_SIZE / 2);
        s32 posY = blockGrid->centerPos.y;
        s32 posZ = blockGrid->centerPos.z + (gridZ * BLOCK_GRID_SIZE) + (BLOCK_GRID_SIZE / 2);
        blockEntityID = create_entity(&Entity_PushBlock, posX, posY, posZ, 0, 0, 0, 0, MAKE_ENTITY_END);
        bind_trigger_1(&D_80285674_7E64F4, TRIGGER_WALL_PUSH, blockEntityID + EVT_ENTITY_ID_BIT, (s32)blockGrid, blockEntityID, 3);
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

    PushBlockGrid* blockGrid = D_802DBC88[blockSystemID];
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

    PushBlockGrid* blockGrid = D_802DBC88[blockSystemID];
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

    D_802DBC88[blockSystemID]->dropCallback = fallCallback;

    return ApiStatus_DONE2;
}
