/// @file sam_03.h
/// @brief Mt Shiver - Road to Shiver Snowfield

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_03_shape.h"
#include "mapfs/sam_03_hit.h"

#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/Gulpit.h"

enum {
    NPC_JrTroopa            = 0,
    NPC_JrTroopa_Hitbox     = 1,
    NPC_Gulpit_01           = 0,
    NPC_Gulpit_01_Hitbox    = 1,
    NPC_Gulpit_02           = 2,
    NPC_Gulpit_02_Hitbox    = 3,
};

#define NAMESPACE sam_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(BeforeNPCs);
extern NpcGroupList N(AfterNPCs);
