/// @file dgb_02.h
/// @brief Tubba's Castle - West Hall (1F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_02_shape.h"
#include "mapfs/dgb_02_hit.h"

enum {
    NPC_Clubba_01           = 10,
    NPC_Clubba_01_Hitbox    = 11,
    NPC_Clubba_02           = 30,
    NPC_Clubba_02_Hitbox    = 31,
};

#define NAMESPACE dgb_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
