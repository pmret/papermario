/// @file tik_07.h
/// @brief Toad Town Tunnels - Elevator Attic Room (B2)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_07_shape.h"
#include "mapfs/tik_07_hit.h"

enum {
    NPC_Paragoomba_01           = 0,
    NPC_Paragoomba_02           = 1,
};

enum {
    MV_SuperBlock       = MapVar(0),
};

#define NAMESPACE tik_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupPlatforms);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupDrips);
extern NpcGroupList N(DefaultNPCs);
