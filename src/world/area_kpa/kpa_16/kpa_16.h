/// @file kpa_16.h
/// @brief Bowser's Castle - Lava Control Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_16_shape.h"
#include "mapfs/kpa_16_hit.h"

#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite/npc/WorldLakilester.h"
#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/Magikoopa.h"

enum {
    NPC_Koopatrol_01            = 0,
    NPC_Koopatrol_02            = 1,
    NPC_Koopatrol_03            = 2,
    NPC_Magikoopa               = 3,
};

#define NAMESPACE kpa_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_TexPan_Steam);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
