/// @file dgb_08.h
/// @brief Tubba's Castle - East Hall (1/2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_08_shape.h"
#include "mapfs/dgb_08_hit.h"

#include "sprite/npc/WorldClubba.h"
#include "sprite/npc/Sentinel.h"
#include "sprite/npc/WorldTubba.h"

enum {
    NPC_Clubba_Unused       = 0,
    NPC_Clubba_01           = 1,
    NPC_Clubba_01_Hitbox    = 2,
    NPC_Clubba_02           = 3,
    NPC_Clubba_02_Hitbox    = 4,
    NPC_Clubba_03           = 5,
    NPC_Clubba_03_Hitbox    = 6,
    NPC_Sentinel_01         = 7,
    NPC_Sentinel_02         = 8,
    NPC_Tubba               = 9,
    NPC_Clubba_Last         = 11,
};

#define NAMESPACE dgb_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(BeforeNPCs);
extern NpcGroupList N(TubbaNPCs);
extern NpcGroupList N(AfterNPCs);
