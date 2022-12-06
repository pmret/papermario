/// @file mim_10.h
/// @brief Forever Forest - Exit to Toad Town

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_10_shape.h"
#include "mapfs/mim_10_hit.h"

#include "sprite/npc/Bootler.h"
#include "sprite/npc/JrTroopa.h"

enum {
    NPC_Bootler         = 0,
    NPC_JrTroopa        = 1,
};

enum {
    MV_Unk_00           = MapVar(0),
};

#define NAMESPACE mim_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupBootlerTrigger);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
