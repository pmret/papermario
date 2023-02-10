/// @file jan_01.h
/// @brief Jade Jungle - Beach

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_01_shape.h"
#include "mapfs/jan_01_hit.h"

enum {
    NPC_Kolorado        = 0,
    NPC_JungleFuzzy_01  = 1,
    NPC_JungleFuzzy_02  = 2,
    NPC_JungleFuzzy_03  = 3,
    NPC_JungleFuzzy_04  = 4,
};

enum {
    AF_JAN01_TreeDrop_StarPiece = MapFlag(10),
};

#define NAMESPACE jan_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);
extern NpcGroupList N(DefaultNPCs);
