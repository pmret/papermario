/// @file flo_16.h
/// @brief Flower Fields - (NE) Elevators

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_16_shape.h"
#include "mapfs/flo_16_hit.h"

#include "sprite/npc/RuffPuff.h"

enum {
    NPC_RuffPuff_01     = 0,
    NPC_RuffPuff_02     = 1,
};

enum {
    MV_SuperBlock       = MapVar(0),
};

#define NAMESPACE flo_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupVines);
extern EvtScript N(EVS_SetupPillarPuzzle);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
