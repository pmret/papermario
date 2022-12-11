/// @file kmr_07.h
/// @brief Goomba Region - Goomba Road 3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_07_shape.h"
#include "mapfs/kmr_07_hit.h"

enum {
    NPC_GoombaBros_Red          = 0,
    NPC_GoombaBros_Blue         = 1,
};

enum {
    MV_SpringEntityIndex        = MapVar(0),
    MV_GoombaBrosDefeated       = MapVar(0), // reused
};

#define NAMESPACE kmr_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
