/// @file jan_16.h
/// @brief Jade Jungle - Base of Great Tree

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_16_shape.h"
#include "mapfs/jan_16_hit.h"

#include "sprite/npc/Raven.h"
#include "sprite/npc/RaphaelRaven.h"

enum {
    NPC_RaphaelRaven    = 0,
    NPC_Raven_01        = 1,
    NPC_Raven_02        = 2,
    NPC_Raven_03        = 3,
    NPC_Raven_04        = 4,
    NPC_Raven_05        = 5,
};

enum {
    MV_Unk_0A       = MapVar(10),
};

#define NAMESPACE jan_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(D_802412D4_B812D4);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
