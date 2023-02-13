/// @file nok_03.h
/// @brief Koopa Region - Behind Koopa Village

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_03_shape.h"
#include "mapfs/nok_03_hit.h"

#include "sprite/npc/WorldKooper.h"

enum {
    NPC_Fuzzy_01        = 0,
    NPC_Fuzzy_02        = 1,
    NPC_Fuzzy_03        = 4,
    NPC_KoopersShell    = 5,
};

#define NAMESPACE nok_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
