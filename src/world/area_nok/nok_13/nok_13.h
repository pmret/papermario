/// @file nok_13.h
/// @brief Koopa Region - Pleasant Crossroads

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_13_shape.h"
#include "mapfs/nok_13_hit.h"

enum {
    NPC_UnusedFuzzy     = 1,
};

#define NAMESPACE nok_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupMusicalHill);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

