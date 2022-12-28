/// @file tik_18.h
/// @brief Toad Town Tunnels - Hall to Blooper 1 (B1)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_18_shape.h"
#include "mapfs/tik_18_hit.h"

enum {
    NPC_Gloomba             = 0,
    NPC_SpikedGloomba       = 1,
};

#define NAMESPACE tik_18

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupDrips);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
