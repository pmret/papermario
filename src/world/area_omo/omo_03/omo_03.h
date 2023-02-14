/// @file omo_03.h
/// @brief Shy Guy's Toybox - BLU Station

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_03_shape.h"
#include "mapfs/omo_03_hit.h"

#include "sprite/npc/TrainToad.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/ShyGuy.h"

enum {
    NPC_Conductor       = 0,
    NPC_TrainToad               = 1,
    NPC_Parakarry       = 2,
    NPC_Watt            = 3,
    NPC_ShyGuy_01       = 4,
    NPC_ShyGuy_02       = 5,
    NPC_ShyGuy_03       = 6,
};

enum {
    MV_TrainUnk_00          = MapVar(0),
    MV_TrainUnk_01          = MapVar(1),
    MV_TrainUnk_02          = MapVar(2),
    MV_ArrowTexUOffset      = MapVar(9),
    MV_DroppedTrainAngle    = MapVar(10),
    MV_TrainPos             = MapVar(11),
    MV_TrainUnk_0C          = MapVar(12),
    MV_TrainUnk_0D          = MapVar(13),
};

enum {
    MF_TrainUnk_00          = MapFlag(0),
    MF_EitherSwitchPressed  = MapFlag(1),
    AF_JAN01_TreeDrop_StarPiece               = MapFlag(10),
};

#define NAMESPACE omo_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_EnterSpring);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_8024746C);
extern EvtScript N(EVS_8024705C);
extern EvtScript N(EVS_80246108);
extern EvtScript N(EVS_Scene_Epilogue);
extern EvtScript N(EVS_Scene_TrainDropped);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(EpilogueNPCs);
