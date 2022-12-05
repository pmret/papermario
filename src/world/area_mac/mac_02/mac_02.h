/// @file mac_02.h
/// @brief Toad Town - Southern District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_02_shape.h"
#include "mapfs/mac_02_hit.h"

#include "sprite/npc/TayceT.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/FiceT.h"
#include "sprite/npc/ShyGuy.h"

enum {
    NPC_TayceT                  = 0,
    NPC_FiceT                   = 1,
    NPC_Bubulb                  = 2,
    NPC_Toad_01                 = 3,
    NPC_CookingApprentice       = 4,
    NPC_Toad_02                 = 5,
    NPC_ToadKid                 = 6,
    NPC_Toad_03                 = 7,
    NPC_Toad_04                 = 8,
    NPC_Bootler                 = 9,
    NPC_ShyGuy                  = 11,
    NPC_ChuckQuizmo             = 12,
};

enum {
    MV_BlueHouseLockEntityID    = MapVar(0),
};

enum {
    MF_MusicMixTrigger1         = MapFlag(10),
    MF_MusicMixTrigger2         = MapFlag(11),
};

#define NAMESPACE mac_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupMusicTriggers);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(NpcGroup1);
extern NpcGroupList N(NpcGroup3);
extern NpcGroupList N(NpcGroup4);
