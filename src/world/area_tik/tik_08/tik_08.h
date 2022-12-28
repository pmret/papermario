/// @file tik_08.h
/// @brief Toad Town Tunnels - Second Level Entry (B2)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_08_shape.h"
#include "mapfs/tik_08_hit.h"

enum {
    NPC_Blooper                 = 0,
};

enum {
    MV_BlueSwitch       = MapVar(0),
};

#define NAMESPACE tik_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayBlooperSong);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SpawnSwitch);
extern EvtScript N(EVS_SetupDrips);
extern NpcGroupList N(DefaultNPCs);
