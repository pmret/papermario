#include "common.h"

extern PushBlockGrid* D_802DBC88[]; //TODO determind length
extern EvtScript D_80285674_7E64F4;
extern EntityBlueprint D_802EA2BC;

#define BLOCK_GRID_SIZE 25

ApiStatus func_80282880(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->position.x += (script->varTable[0] - playerStatus->position.x) / 2;
    playerStatus->position.z += (script->varTable[2] - playerStatus->position.z) / 2;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/script_api/7E3700", func_802828DC);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80282C40);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80282E30);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283080);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283174);

ApiStatus CheckActionState(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;
    s32 var = evt_get_float_variable(script, *args);

    evt_set_variable(script, a0, gPlayerActionState == var);
    return ApiStatus_DONE2;
}

ApiStatus func_80283240(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    Bytecode* sourceToFind = (Bytecode*)evt_get_variable(script, *args++);

    s32 retVal = FALSE;
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++)
    {
        Evt* iterScript = get_script_by_index(i);
        if (iterScript != 0) {
            if (iterScript->ptrFirstLine == sourceToFind) {
                retVal = TRUE;
                break;
            }
        }
    }
    evt_set_variable(script, outVar, retVal);
    return ApiStatus_DONE2;
}

ApiStatus CreatePushBlockGrid(Evt* script, s32 isInitialCall) {
    Bytecode* arg = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *arg++);
    s32 sizeNx = evt_get_variable(script, *arg++);
    s32 sizeNz = evt_get_variable(script, *arg++);
    s32 centerX = evt_get_variable(script, *arg++);
    s32 centerY = evt_get_variable(script, *arg++);
    s32 centerZ = evt_get_variable(script, *arg++);
    u8* inputGridData = (u8*)evt_get_variable(script, *arg++);

    PushBlockGrid* blockGrid;
    u8* dataToCopy;
    s32 i;

    D_802DBC88[blockSystemID] = blockGrid = general_heap_malloc(sizeof(PushBlockGrid));
    
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
    blockGrid->centerPos[0] = centerX;
    blockGrid->centerPos[1] = centerY;
    blockGrid->centerPos[2] = centerZ;
    blockGrid->dropCallback = NULL;
    
    return ApiStatus_DONE2;
}

ApiStatus SetPushBlock(Evt* script, s32 isInitialCall) {
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
        s32 posX = blockGrid->centerPos[0] + (gridX * BLOCK_GRID_SIZE) + (BLOCK_GRID_SIZE / 2);
        s32 posY = blockGrid->centerPos[1];
        s32 posZ = blockGrid->centerPos[2] + (gridZ * BLOCK_GRID_SIZE) + (BLOCK_GRID_SIZE / 2);
        blockEntityID = create_entity(&D_802EA2BC, posX, posY, posZ, 0, 0, 0, 0, MAKE_ENTITY_END);
        bind_trigger_1(&D_80285674_7E64F4, TRIGGER_WALL_PUSH, blockEntityID + EVT_ENTITY_ID_BIT, (s32)blockGrid, blockEntityID, 3);
        script->varTable[0] = blockEntityID;
    }
    
    return ApiStatus_DONE2;
}

ApiStatus GetPushBlock(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *args++);
    s32 gridX = evt_get_variable(script, *args++);
    s32 gridZ = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    PushBlockGrid* blockGrid = D_802DBC88[blockSystemID];
    s32 cellIndex;
    
    if (gridX >= blockGrid->numCellsX || gridX < 0 || gridZ >= blockGrid->numCellsZ || gridZ < 0) {
         // vanilla bug: sets error value and then performs lookup anyway -- return statement forgotten here
        evt_set_variable(script, outVar, PUSH_GRID_OUT_OF_BOUNDS);
    }
    cellIndex = gridX + (gridZ * blockGrid->numCellsX);
    evt_set_variable(script, outVar, blockGrid->cells[cellIndex]);

    return ApiStatus_DONE2;
}

ApiStatus GetGridIndexFromPos(Evt* script, s32 isInitialCall) {
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
    
    posX -= blockGrid->centerPos[0];
    gridX = posX / BLOCK_GRID_SIZE;
    posZ -= blockGrid->centerPos[2];
    gridZ = posZ / BLOCK_GRID_SIZE;
    
    evt_set_variable(script, outVarX, gridX);
    evt_set_variable(script, outVarZ, gridZ);
    
    return ApiStatus_DONE2;
}

ApiStatus SetPushBlockFallEffect(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 blockSystemID = evt_get_variable(script, *args++);
    PushBlockFallCallback fallCallback = (PushBlockFallCallback)evt_get_variable(script, *args++);
    
    D_802DBC88[blockSystemID]->dropCallback = fallCallback;
    
    return ApiStatus_DONE2;
}
