/// @file tik_20.h
/// @brief Toad Town Tunnels - Room with Spikes (B2)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_20_shape.h"
#include "mapfs/tik_20_hit.h"

enum {
    NPC_DarkTroopa_01          = 0,
    NPC_DarkTroopa_02          = 1,
};

#define NAMESPACE tik_20

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);
