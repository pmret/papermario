/// @file tik_09.h
/// @brief Toad Town Tunnels - Warp Zone 2 (B2)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_09_shape.h"
#include "mapfs/tik_09_hit.h"

enum {
    NPC_KoopaTroopa_01          = 0,
    NPC_KoopaTroopa_02          = 1,
    NPC_KoopaTroopa_03          = 2,
};

enum {
    MV_Unk_00       = MapVar(0),
};

#define NAMESPACE tik_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupDrips);
extern EvtScript N(EVS_SpawnSwitch);
extern NpcGroupList N(DefaultNPCs);
