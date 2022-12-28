/// @file tik_02.h
/// @brief Toad Town Tunnels - Blooper Boss 1 (B1)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_02_shape.h"
#include "mapfs/tik_02_hit.h"

enum {
    NPC_Blooper                 = 0,
};

#define NAMESPACE tik_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayBlooperSong);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupDrips);
extern NpcGroupList N(DefaultNPCs);
