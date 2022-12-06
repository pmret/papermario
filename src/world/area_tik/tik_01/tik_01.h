/// @file tik_01.h
/// @brief Toad Town Tunnels - Warp Zone 1 (B1)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_01_shape.h"
#include "mapfs/tik_01_hit.h"

enum {
    NPC_Blooper                 = 0,
};

enum {
    MV_Unk_01       = MapVar(1),
};

#define NAMESPACE tik_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayBlooperSong);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SpawnSwitch);
extern EvtScript N(EVS_SetupDrips);
extern NpcGroupList N(DefaultNPCs);
