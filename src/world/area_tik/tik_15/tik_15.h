/// @file tik_15.h
/// @brief Toad Town Tunnels - Rip Cheato's Home (B3)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_15_shape.h"
#include "mapfs/tik_15_hit.h"

#include "sprite/npc/RipCheato.h"

enum {
    NPC_RipCheato               = 1,
};

#define NAMESPACE tik_15

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupDrips);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
