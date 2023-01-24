/// @file omo_16.h
/// @brief Shy Guy's Toybox - Riding the Train

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_16_shape.h"
#include "mapfs/omo_16_hit.h"

#include "sprite/npc/TrainToad.h"

enum {
    NPC_Conductor       = 0,
};

enum {
    MV_TrainUnk_00          = MapVar(0),
    MV_TrainUnk_01          = MapVar(1),
    MV_TrainUnk_02          = MapVar(2),
    MV_TrainPos             = MapVar(11),
    MV_TrainUnk_0C          = MapVar(12),
    MV_TrainUnk_0D          = MapVar(13),
};

enum {
    MF_TrainUnk_00          = MapFlag(0),
};

#define NAMESPACE omo_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_802429C4);
extern NpcGroupList N(DefaultNPCs);
