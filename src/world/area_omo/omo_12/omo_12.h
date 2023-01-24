/// @file omo_12.h
/// @brief Shy Guy's Toybox - RED Lantern Ghost

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_12_shape.h"
#include "mapfs/omo_12_hit.h"

#include "sprite/npc/BigLanternGhost.h"
#include "sprite/npc/WorldWatt.h"

enum {
    NPC_BigLanternGhost     = 0,
    NPC_Watt                = 1,
    NPC_LaternTop           = 2,
    NPC_LaternBottom        = 3,
};

enum {
    MF_LanternGhost_DoneSpeaking    = MapFlag(0),
};

#define NAMESPACE omo_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushPartnerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_SetupLightSource);
extern EvtScript N(EVS_EnterScene);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(LoadPartyImage));
