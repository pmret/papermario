/// @file tik_04.h
/// @brief Toad Town Tunnels - Scales Room (B2)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_04_shape.h"
#include "mapfs/tik_04_hit.h"

enum {
    NPC_SpikedGoomba_01         = 0,
    NPC_SpikedGoomba_02         = 1,
};

enum {
    MV_Unk_00       = MapVar(0),
};

#define NAMESPACE tik_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupDrips);
extern EvtScript N(EVS_SetupPlatforms);
extern NpcGroupList N(DefaultNPCs);
