#include "common.h"
#include "effects.h"

EvtScript N(EVS_FlowerSpawnRegion) = {
    SetGroup(EVT_GROUP_HOSTILE_NPC)
    // save input args
    Set(LVarA, LVar0) // minX
    Set(LVarB, LVar1) // minZ
    Set(LVarC, LVar2) // maxX
    Set(LVarD, LVar3) // maxZ
    Set(LVarE, LVar4) // posY
    // calculate spawn region size
    Sub(LVarC, LVar0) // sizeX
    Sub(LVarD, LVar1) // sizeZ
    // spawnDelay = 11 + (100.0 / (sizeX / 100.0))
    SetF(LVar0, LVarC)
    DivF(LVar0, Float(100.0))
    SetF(LVarF, Float(100.0))
    DivF(LVarF, LVar0)
    Add(LVarF, 11)
    // initial spawn count = 1 + (200 / spawnDelay)
    Set(LVar5, 200)
    Div(LVar5, LVarF)
    Add(LVar5, 1)
    // spawn intial flowers
    Loop(LVar5)
        Call(RandInt, LVarC, LVar0)
        Call(RandInt, LVarD, LVar1)
        Call(RandInt, 199, LVar2)
        Set(LVar3, 210)
        Sub(LVar3, LVar2)
        Add(LVar0, LVarA)
        Add(LVar1, LVarB)
        Add(LVar2, LVarE)
        PlayEffect(EFFECT_FLOATING_FLOWER, LVar0, LVar2, LVar1, LVar3, 0)
    EndLoop
    Wait(LVarF)
    // spawn flowers over time
    Label(0)
        Call(RandInt, LVarC, LVar0)
        Call(RandInt, LVarD, LVar1)
        Add(LVar0, LVarA)
        Add(LVar1, LVarB)
        PlayEffect(EFFECT_FLOATING_FLOWER, LVar0, LVarE, LVar1, 200, 0)
        Wait(LVarF)
        Goto(0)
    Return
    End
};

#define EVT_FLOWER_SPAWN_REGION(minX, minZ, maxX, maxZ, posY) \
    Set(LVar0, minX) \
    Set(LVar1, minZ) \
    Set(LVar2, maxX) \
    Set(LVar3, maxZ) \
    Set(LVar4, posY) \
    Exec(N(EVS_FlowerSpawnRegion))
