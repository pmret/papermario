#include "common.h"

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
    Bytecode outVar;
    Bytecode* sourceToFind;
    s32 retVal;
    s32 i;

    outVar = *args++;
    sourceToFind = (Bytecode*)evt_get_variable(script, *args++);
    retVal = FALSE;

    for(i = 0; i < MAX_SCRIPTS; i++)
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

extern PushBlockGrid* D_802DBC88[8];

ApiStatus CreatePushBlockGrid(Evt* script, s32 isInitialCall) {
    PushBlockGrid* blockGrid;
    Bytecode* arg = script->ptrReadPos;
    s32 blockGridID;
    s8* inputGridData;
    s8* dataToCopy;
    s32 sizeNz, sizeNx;
    s32 centerX, centerY, centerZ;
    s32 i;
    
    blockGridID = evt_get_variable(script, *arg++);
    sizeNx = evt_get_variable(script, *arg++);
    sizeNz = evt_get_variable(script, *arg++);
    centerX = evt_get_variable(script, *arg++);
    centerY = evt_get_variable(script, *arg++);
    centerZ = evt_get_variable(script, *arg++);
    inputGridData = (s8*)evt_get_variable(script, *arg++);
    
    D_802DBC88[blockGridID] = blockGrid = general_heap_malloc(sizeof(PushBlockGrid));
    
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

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", SetPushBlock, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", GetPushBlock, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", GetGridIndexFromPos, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", SetPushBlockFallEffect, Evt* script, s32 isInitialCall);
