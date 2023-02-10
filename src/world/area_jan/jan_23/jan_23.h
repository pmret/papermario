/// @file jan_23.h
/// @brief Jade Jungle - Great Treetop Roost

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_23_shape.h"
#include "mapfs/jan_23_hit.h"

#include "sprite/npc/RaphaelRaven.h"
#include "sprite/npc/Raven.h"

enum {
    NPC_RaphaelRaven    = 0,
    NPC_Raven_01        = 1,
    NPC_Raven_02        = 2,
    NPC_Raven_03        = 3,
    NPC_Raven_04        = 4,
    NPC_Raven_05        = 5,
};

enum {
    MV_Unk_05       = MapVar(5),
};

enum {
    MF_Unk_00       = MapFlag(0),
};

#define NAMESPACE jan_23

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
