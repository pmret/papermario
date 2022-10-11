/// @file sbk_30.h
/// @brief Dry Dry Desert - W3 Kolorado's Camp

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sbk.h"
#include "mapfs/sbk_30_shape.h"
#include "mapfs/sbk_30_hit.h"

#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/Archeologist.h"

enum {
    NPC_Kolorado                = 0,
    NPC_Archeologist_01         = 1,
    NPC_Archeologist_02         = 2,
};

enum {
    MF_TreeDrop_Letter          = MapFlag(10),
};

#define NAMESPACE sbk_30

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFoliage);
extern NpcGroupList N(DefaultNPCs);
