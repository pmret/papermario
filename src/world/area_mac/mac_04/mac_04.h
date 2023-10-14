/// @file mac_04.h
/// @brief Toad Town - Residental District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_04_shape.h"
#include "mapfs/mac_04_hit.h"

#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/HarryT.h"
#include "sprite/npc/ChetRippo.h"
#include "sprite/npc/WorldGoombario.h"

enum {
    NPC_HarryT                  = 0,
    NPC_NewResident1            = 1,
    NPC_NewResident2            = 2,
    NPC_Toad_01                 = 3,
    NPC_Toad_02                 = 4,
    NPC_ToadKid_01              = 5,
    NPC_ToadKid_02              = 6,
    NPC_ToadKid_03              = 7,
    NPC_Toadette_03             = 8,
    NPC_Toad_03                 = 9,
    NPC_GossipTrio1             = 10,
    NPC_GossipTrio2             = 11,
    NPC_GossipTrio3             = 12,
    NPC_ChetRippo               = 13,
    NPC_ShyGuy_01               = 14,
    NPC_ShyGuy_02               = 15,
    NPC_Twink                   = 16,
    NPC_Muskular                = 17,
    NPC_Goomama                 = 18,
    NPC_Goombaria               = 19,
    NPC_ChuckQuizmo             = 20,
    NPC_WishingToadKid          = 21,
};

enum {
    MV_StoreroomLockEntityID        = MapVar(0),
    MV_PlayerShrinkScale            = MapVar(10),
    MV_DrawShinkingPlayerWorker     = MapVar(11),
};

enum {
    MF_MusicMixTrigger              = MapFlag(10),
};

#define NAMESPACE mac_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupMusicTriggers);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_MakeStoreroom);
extern EvtScript N(EVS_MakeHiddenRoom);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

extern EvtScript N(EVS_OnEnterShop);
extern EvtScript N(EVS_HiddenRoom_WaitForOuttaSight);
extern EvtScript N(EVS_ExitToybox);
extern EvtScript N(EVS_Toybox_SetupTrainPrompt);
extern EvtScript N(D_8024697C_84954C);
extern EvtScript N(EVS_ForceStoreroomUnlock);
extern EvtScript N(EVS_Scene_WishingToadKid);

extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(Chapter4NPCs);
extern NpcGroupList N(PostChapter4NPCs);
extern NpcGroupList N(Chapter7NPCs);
extern NpcGroupList N(WishSceneNPCs);
