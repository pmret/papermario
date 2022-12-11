/// @file iwa_00.h
/// @brief Mt Rugged - Mt Rugged 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_00_shape.h"
#include "mapfs/iwa_00_hit.h"

enum {
    NPC_MontyMole_01            = 0,
    NPC_MontyMole_01_Hole       = 1,
    NPC_MontyMole_02            = 2,
    NPC_MontyMole_02_Hole       = 3,
    NPC_Whacka_01               = 4,
    NPC_Whacka_02               = 5,
};

#define NAMESPACE iwa_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_BindSlideTriggers);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
