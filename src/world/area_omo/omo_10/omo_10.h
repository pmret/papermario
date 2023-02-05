/// @file omo_10.h
/// @brief Shy Guy's Toybox - RED Station

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_10_shape.h"
#include "mapfs/omo_10_hit.h"

#include "sprite/npc/TrainToad.h"

enum {
    NPC_Conductor           = 0,
    NPC_TrainToad    = 1,
};

enum {
    MV_TrainUnk_00          = MapVar(0),
    MV_TrainUnk_01          = MapVar(1),
    MV_TrainUnk_02          = MapVar(2),
    MV_ArrowTexUOffset      = MapVar(9),
    MV_TrainPos             = MapVar(11),
    MV_TrainUnk_0C          = MapVar(12),
    MV_TrainUnk_0D          = MapVar(13),
};

enum {
    MF_TrainUnk_00          = MapFlag(0),
    MF_EitherSwitchPressed  = MapFlag(1),
    AF_JAN01_TreeDrop_StarPiece               = MapFlag(10),
};

#define NAMESPACE omo_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_SetupTrain);
extern EvtScript N(D_802444A0_DDBE50);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
