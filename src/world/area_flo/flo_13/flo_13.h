/// @file flo_13.h
/// @brief Flower Fields - (NW) Lakilester

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_13_shape.h"
#include "mapfs/flo_13_hit.h"

#include "sprite/npc/Lakilulu.h"
#include "sprite/npc/WorldLakilester.h"
#include "sprite/npc/Lakitu.h"
#include "sprite/npc/Spiny.h"

enum {
    NPC_Lakilester              = 0,
    NPC_Lakilulu                = 1,
    NPC_Lakilulu_Spiny          = 2,
    NPC_Lakitu_01               = 3,
    NPC_Lakitu_02               = 4,
    NPC_Spiny_01                = 50,
    NPC_Spiny_02                = 51,
    NPC_Spiny_03                = 52,
    NPC_Spiny_04                = 53,
    NPC_Spiny_05                = 54,
    NPC_Spiny_06                = 55,
};

enum {
    MV_LakiluluSpinySceneState  = MapVar(10),
};

#define NAMESPACE flo_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushPartnerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(LoadPartyImage));
