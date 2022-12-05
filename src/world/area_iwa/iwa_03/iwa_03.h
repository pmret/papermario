/// @file iwa_03.h
/// @brief Mt Rugged - Mt Rugged 4

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_03_shape.h"
#include "mapfs/iwa_03_hit.h"

enum {
    NPC_Cleft_01                = 0,
    NPC_Cleft_02                = 1,
    NPC_Cleft_03                = 2,
    NPC_MontyMole               = 3,
    NPC_MontyMole_Hole          = 4,
};

enum {
    MV_PlayerCliffLevel     = MapVar(9),
};

#define NAMESPACE iwa_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_BindSlideTriggers);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
