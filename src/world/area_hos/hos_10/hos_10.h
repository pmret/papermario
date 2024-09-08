/// @file hos_10.h
/// @brief Shooting Star Summit - Ending Descent Scene

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_10_shape.h"
#include "mapfs/hos_10_hit.h"

#include "sprite/npc/Twink.h"

enum {
    NPC_Peach       = 0,
    NPC_Twink       = 1,
    NPC_Eldstar     = 2,
    NPC_Mamar       = 3,
    NPC_Skolar      = 4,
    NPC_Muskular    = 5,
    NPC_Misstar     = 6,
    NPC_Klevar      = 7,
    NPC_Kalmar      = 8,
};

enum {
    MV_BubbleFXPtr  = MapVar(0),
    MV_Unk_01   = MapVar(1),
};

#define NAMESPACE hos_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_CastleDescending);
extern EvtScript N(EVS_Scene_SpiritsFlyingAway);
extern EvtScript N(EVS_Scene_RisingAboveClouds);
extern EvtScript N(EVS_Scene_UnusedWhiteScreen);
extern EvtScript N(EVS_Scene_PreTitle);
#if VERSION_JP
extern EvtScript N(EVS_SetupNarrator);
#endif
extern NpcGroupList N(NpcGroup_Descent);
extern NpcGroupList N(NpcGroup_FlyAway);
