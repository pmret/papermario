/// @file hos_01.h
/// @brief Shooting Star Summit - Shooting Star Summit

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_01_shape.h"
#include "mapfs/hos_01_hit.h"

#include "sprite/npc/WorldGoombario.h"

enum {
    NPC_Eldstar                 = 0,
    NPC_Mamar                   = 1,
    NPC_Skolar                  = 2,
    NPC_Muskular                = 3,
    NPC_Misstar                 = 4,
    NPC_Klevar                  = 5,
    NPC_Kalmar                  = 6,
};

enum {
    MV_AlphaAmt_Eldstar = MapVar(0),
    MV_AlphaAmt_Others  = MapVar(1),
    MV_StarBeamFXPtr    = MapVar(10),
    MV_StarBeamState    = MapVar(11),
};

enum {
    MF_SpiritsGone      = MapFlag(0),
};

#define NAMESPACE hos_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupModelFX);
extern EvtScript N(EVS_Scene_StarWayOpened);
extern EvtScript N(EVS_AscendStarBeam);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);

API_CALLABLE(N(func_80240AAC_A1132C));
API_CALLABLE(N(func_80240B10_A11390));
API_CALLABLE(N(SetStarBeamMasterAlpha));
