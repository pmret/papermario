/// @file mim_07.h
/// @brief Forever Forest - Flowers Vanish

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_07_shape.h"
#include "mapfs/mim_07_hit.h"

#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/Fuzzy.h"

enum {
    NPC_Fuzzy_01                = 0,
    NPC_Fuzzy_02                = 1,
    NPC_JrTroopa                = 2,
};

#define NAMESPACE mim_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_PlayForestMusic);
extern EvtScript N(EVS_JrTroopaMusic);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_SetupExitHint);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
