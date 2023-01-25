#include "common.h"
#include "effects.h"

EvtScript N(EVS_FlowerSpawnRegion) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    // save input args
    EVT_SET(LVarA, LVar0) // minX
    EVT_SET(LVarB, LVar1) // minZ
    EVT_SET(LVarC, LVar2) // maxX
    EVT_SET(LVarD, LVar3) // maxZ
    EVT_SET(LVarE, LVar4) // posY
    // calculate spawn region size
    EVT_SUB(LVarC, LVar0) // sizeX
    EVT_SUB(LVarD, LVar1) // sizeZ
    // spawnDelay = 11 + (100.0 / (sizeX / 100.0))
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    // initial spawn count = 1 + (200 / spawnDelay)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    // spawn intial flowers
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, LVar0, LVar2, LVar1, LVar3, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    // spawn flowers over time
    EVT_LABEL(0)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, LVar0, LVarE, LVar1, 200, 0)
        EVT_WAIT(LVarF)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#define EVT_FLOWER_SPAWN_REGION(minX, minZ, maxX, maxZ, posY) \
    EVT_SET(LVar0, minX) \
    EVT_SET(LVar1, minZ) \
    EVT_SET(LVar2, maxX) \
    EVT_SET(LVar3, maxZ) \
    EVT_SET(LVar4, posY) \
    EVT_EXEC(N(EVS_FlowerSpawnRegion))
