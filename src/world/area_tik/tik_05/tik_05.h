/// @file tik_05.h
/// @brief Toad Town Tunnels - Spring Room (B2)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_05_shape.h"
#include "mapfs/tik_05_hit.h"

enum {
    NPC_SpikedGoomba_01         = 0,
    NPC_SpikedGoomba_02         = 1,
};

enum {
    MV_Unk_00       = MapVar(0),
};

#define NAMESPACE tik_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupDrips);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
