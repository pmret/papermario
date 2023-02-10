/// @file jan_22.h
/// @brief Jade Jungle - Path to the Volcano

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_22_shape.h"
#include "mapfs/jan_22_hit.h"

#include "sprite/npc/Raven.h"
#include "sprite/npc/RaphaelRaven.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/SpearGuy.h"
#include "sprite/npc/WorldMisstar.h"

enum {
    NPC_Kolorado_01             = 0,
    NPC_Kolorado_02             = 1,
    NPC_ZiplineDummy1           = 2,
    NPC_ZiplineDummy2           = 3,
    NPC_SpearGuy                = 4,
    NPC_RaphaelRaven            = 5,
    NPC_Raven_01                = 6,
    NPC_Raven_02                = 7,
    NPC_Raven_03                = 8,
    NPC_Raven_04                = 9,
    NPC_Raven_05                = 10,
    NPC_Misstar                 = 11,
};

enum {
    MV_BushOffsetL      = MapVar(0),
    MV_BushOffsetR      = MapVar(1),
};

enum {
    MF_RidingZipline1   = MapFlag(10),
    MF_RidingZipline2   = MapFlag(11),
};

#define NAMESPACE jan_22

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SyncZiplineDummyNPC1);
extern EvtScript N(EVS_SyncZiplineDummyNPC2);
extern EvtScript N(EVS_SeparateBushesImmediately);
extern EvtScript N(EVS_Scene_RaphaelComingThrough);
extern EvtScript N(EVS_SetupZiplines);
extern EvtScript N(EVS_SetupBasketElevator);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_MoveBushes);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList(N(DefaultNPCs));
extern NpcGroupList(N(RavenNPCs));
