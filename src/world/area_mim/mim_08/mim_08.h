/// @file mim_08.h
/// @brief Forever Forest - Laughing Rock

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_08_shape.h"
#include "mapfs/mim_08_hit.h"

#include "sprite/npc/Bzzap.h"
#include "sprite/npc/SmallPiranha.h"

enum {
    NPC_Bzzap                   = 0,
    NPC_PiranhaPlant_01         = 1,
    NPC_PiranhaPlant_01_Hitbox  = 2,
    NPC_PiranhaPlant_02         = 3,
    NPC_PiranhaPlant_02_Hitbox  = 4,
};

enum {
    MV_Unk_00                   = MapVar(0),
};

#define NAMESPACE mim_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
