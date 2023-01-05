/// @file dgb_16.h
/// @brief Tubba's Castle - Sleeping Clubbas Room (3F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_16_shape.h"
#include "mapfs/dgb_16_hit.h"

enum {
    NPC_Clubba_01               = 0,
    NPC_Clubba_01_Hitbox        = 1,
    NPC_Clubba_02               = 5,
    NPC_Clubba_02_Hitbox        = 6,
    NPC_Clubba_03               = 10,
    NPC_Clubba_03_Hitbox        = 11,
    NPC_Clubba_04               = 15,
    NPC_Clubba_04_Hitbox        = 16,
    NPC_Clubba_05               = 20,
    NPC_Clubba_05_Hitbox        = 21,
    NPC_Clubba_06               = 25,
    NPC_Clubba_06_Hitbox        = 26,
};

#define NAMESPACE dgb_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
