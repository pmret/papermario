/// @file isk_09.h
/// @brief Dry Dry Ruins - Super Hammer Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_09_shape.h"
#include "mapfs/isk_09_hit.h"

enum {
    MF_BlueStairsFlipped    = MapFlag(0),
    MF_RedStairsFlipped     = MapFlag(1),
};

#define NAMESPACE isk_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupSwitches);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayUpgradeSong);
extern EvtScript N(EVS_SetupStairs);
extern EvtScript N(EVS_MakeEntities);
