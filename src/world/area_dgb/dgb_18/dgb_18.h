/// @file dgb_18.h
/// @brief Tubba's Castle - Master Bedroom (3F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_18_shape.h"
#include "mapfs/dgb_18_hit.h"

#include "sprite/npc/WorldTubba.h"
#include "sprite/npc/Yakkey.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldBow.h"

enum {
    NPC_Tubba                   = 0,
    NPC_Yakkey                  = 1,
};

enum {
    MF_Sync_YakkeyDialogue      = MapFlag(0),
};

#define NAMESPACE dgb_18

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
