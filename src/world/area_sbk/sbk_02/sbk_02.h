/// @file sbk_02.h
/// @brief Dry Dry Desert - N3W1 Ruins Entrance

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sbk.h"
#include "mapfs/sbk_02_shape.h"
#include "mapfs/sbk_02_hit.h"

#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/Toad.h"

enum {
    NPC_Mamar           = 1,
    NPC_TradingToad     = 2,
};

enum {
    MV_Unk_00           = MapVar(0),
};

#define NAMESPACE sbk_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupRuins);
extern EvtScript N(EVS_Ruins_Arise_Continued);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
