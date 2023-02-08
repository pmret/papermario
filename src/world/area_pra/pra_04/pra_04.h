/// @file pra_04.h
/// @brief Crystal Palace - Reflected Save Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_04_shape.h"
#include "mapfs/pra_04_hit.h"

enum {
    NPC_Swoopula    = 0,
};

enum {
    MV_PlayerFloor  = MapVar(0),
};

#define NAMESPACE pra_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
