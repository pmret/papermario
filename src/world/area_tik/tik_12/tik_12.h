/// @file tik_12.h
/// @brief Toad Town Tunnels - Metal Block Room (B3)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_12_shape.h"
#include "mapfs/tik_12_hit.h"

#include "sprite/npc/BuzzyBeetle.h"

enum {
    NPC_BuzzyBeetle             = 0,
};

enum {
    MV_SuperBlock       = MapVar(0),
};

#define NAMESPACE tik_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupDrips);
extern NpcGroupList N(DefaultNPCs);
