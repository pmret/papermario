/// @file tik_10.h
/// @brief Toad Town Tunnels - Block Puzzle Room (B2)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_10_shape.h"
#include "mapfs/tik_10_hit.h"

enum {
    MV_SuperBlock       = MapVar(0),
};

#define NAMESPACE tik_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupDrips);
