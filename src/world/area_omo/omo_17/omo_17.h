/// @file omo_17.h
/// @brief Shy Guy's Toybox - PNK Tracks Hallway

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_17_shape.h"
#include "mapfs/omo_17_hit.h"

#include "sprite/npc/TrainToad.h"
#include "sprite/npc/SpyGuy.h"
#include "sprite/npc/PyroGuy.h"
#include "sprite/npc/GrooveGuy.h"

enum {
    NPC_Conductor           = 0,
    NPC_SpyGuy              = 1,
    NPC_SpyGuy_Rock1        = 2,
    NPC_SpyGuy_Rock2        = 3,
    NPC_SpyGuy_Rock3        = 4,
    NPC_PyroGuy             = 5,
    NPC_GrooveGuy           = 6,
};

enum {
    MV_TrainUnk_00      = MapVar(0),
    MV_TrainUnk_01      = MapVar(1),
    MV_TrainUnk_02      = MapVar(2),
    MV_TrainPos         = MapVar(11),
    MV_TrainUnk_0C      = MapVar(12),
    MV_TrainUnk_0D      = MapVar(13),
};

enum {
    MF_TrainUnk_00      = MapFlag(0),
};

#define NAMESPACE omo_17

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_EnterTrain);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
