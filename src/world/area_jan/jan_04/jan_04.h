/// @file jan_04.h
/// @brief Jade Jungle - Sushi Tree

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_04_shape.h"
#include "mapfs/jan_04_hit.h"

#include "sprite/npc/WorldSushie.h"
#include "sprite/npc/YoshiKid.h"

enum {
    NPC_Sushie                  = 0,
    NPC_Bubulb                  = 1,
    NPC_YoshiKid_01             = 2,
    NPC_YoshiKid_02             = 3,
    NPC_YoshiKid_03             = 4,
    NPC_YoshiKid_04             = 5,
    NPC_YoshiKid_05             = 6,
};

enum {
    MV_Unk_00       = MapVar(0),
    MV_Unk_01       = MapVar(1),
};

enum {
    MF_TreeDrop_Letter  = MapFlag(10),
};

#define NAMESPACE jan_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushNewPartnerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_GotoMap_kmr_24_0);
extern EvtScript N(EVS_Scene_TreasureChest);
extern EvtScript N(EVS_Scene_Epilogue);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_SetupUnused);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_PlayDemoScene);

extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(EpilogueNPCs);

API_CALLABLE(N(LoadPartyImage));
