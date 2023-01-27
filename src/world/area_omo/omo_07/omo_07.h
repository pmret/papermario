/// @file omo_07.h
/// @brief Shy Guy's Toybox - PNK Playhouse

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_07_shape.h"
#include "mapfs/omo_07_hit.h"

#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/Fuzzy.h"
#include "sprite/npc/HammerBros.h"
#include "sprite/npc/SkyGuy.h"
#include "sprite/npc/WorldKammy.h"

enum {
    NPC_ShyGuy_01       = 1,
    NPC_ShyGuy_02       = 2,
    NPC_ShyGuy_03       = 3,
    NPC_ShyGuy_04       = 4, // never appears
    NPC_Fuzzy           = 5,
    NPC_HammerBros      = 6,
    NPC_Kammy           = 7,
    NPC_SkyGuy_01       = 8,
    NPC_SkyGuy_02       = 9,
};

enum {
    MV_SecretDoorAngle  = MapVar(0),
    MV_AmbushID         = MapVar(10), // npcID or itemID depending on GB_OMO_PeachChoice1
};

#define NAMESPACE omo_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupShyGuyPool);
extern EvtScript N(EVS_Scene_KammySetAmbush);
extern EvtScript N(EVS_NpcIdle_Kammy);
extern NpcGroupList N(KammySceneNPCs);
extern NpcGroupList N(FuzzyAmbushNPCs);
extern NpcGroupList N(HammerBrosAmbushNPCs);
extern NpcGroupList N(DefaultNPCs);
