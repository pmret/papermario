/// @file hos_00.h
/// @brief Shooting Star Summit - Shooting Star Path

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_00_shape.h"
#include "mapfs/hos_00_hit.h"

#include "sprite/npc/ToadKid.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "sprite/npc/WorldGoombario.h"

enum {
    NPC_Twink                   = 0,
    NPC_FlyingMagikoopa         = 1,
    NPC_Toadette                = 2,
    NPC_ToadKid                 = 3,
};

enum {
    MV_LuckyStarItem        = MapVar(10),
};

#define NAMESPACE hos_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayKammyKoopaSong);
extern EvtScript N(EVS_Scene_MeetingTwink);
extern EvtScript N(EVS_Scene_TwinkDeparts);
extern EvtScript N(EVS_Scene_Wishing);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupBackgroundShade);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(WishingNPCs);
