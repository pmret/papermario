/// @file tik_23.h
/// @brief Toad Town Tunnels - Windy Path (B3)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_23_shape.h"
#include "mapfs/tik_23_hit.h"

enum {
    NPC_Spiny_01                = 0,
    NPC_Spiny_02                = 1,
    NPC_Spiny_03                = 2,
};

#define NAMESPACE tik_23

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
