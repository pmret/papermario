/// @file flo_11.h
/// @brief Flower Fields - (West) Maze

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_11_shape.h"
#include "mapfs/flo_11_hit.h"

enum {
    NPC_Lakitu_01       = 0,
    NPC_Lakitu_02       = 1,
};

enum {
    MV_LakituAmbushState    = MapVar(0),
    MV_LakituSearchSync     = MapVar(10),
    MV_FlyingSoundsScript   = MapVar(11),
};

#define NAMESPACE flo_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_Scene_LakituAmbush);
extern NpcGroupList N(DefaultNPCs);
