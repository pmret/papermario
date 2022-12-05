/// @file iwa_04.h
/// @brief Mt Rugged - Suspension Bridge

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_04_shape.h"
#include "mapfs/iwa_04_hit.h"

#include "sprite/npc/Buzzar.h"

enum {
    NPC_Cleft       = 0,
    NPC_Buzzar      = 1,
};

enum {
    MV_PlayerCliffLevel     = MapVar(9),
};

#define NAMESPACE iwa_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
