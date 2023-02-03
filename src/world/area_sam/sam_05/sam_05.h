/// @file sam_05.h
/// @brief Mt Shiver - Path to Starborn Valley

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_05_shape.h"
#include "mapfs/sam_05_hit.h"

#include "sprite/npc/Monstar.h"

enum {
    NPC_Gulpit                  = 0,
    NPC_Gulpit_Hitbox           = 1,
    NPC_FrostPiranha_01         = 2,
    NPC_FrostPiranha_01_Hitbox  = 3,
    NPC_FrostPiranha_02         = 4,
    NPC_FrostPiranha_02_Hitbox  = 5,
    NPC_Monstar                 = 6,
    NPC_StarKid_01              = 7,
    NPC_StarKid_02              = 8,
    NPC_StarKid_03              = 9,
    NPC_StarKid_04              = 10,
    NPC_StarKid_05              = 11,
    NPC_StarKid_06              = 12,
    NPC_StarKid_07              = 13,
    NPC_StarKid_08              = 14,
    NPC_StarKid_09              = 15,
    NPC_StarKid_10              = 16,
    NPC_StarKid_11              = 17,
    NPC_StarKid_12              = 18,
    NPC_StarKid_13              = 19,
    NPC_StarKid_14              = 20,
    NPC_StarKid_15              = 21,
    NPC_StarKid_16              = 22,
};

#define NAMESPACE sam_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_MonstarAppears);
extern EvtScript N(EVS_Scene_MonstarDefeated);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(BeforeNPCs);
extern NpcGroupList N(AfterNPCs);

extern Gfx N(monstar_gfx)[];
extern Vtx N(monstar_vtx)[];
