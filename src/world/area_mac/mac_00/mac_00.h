/// @file mac_00.h
/// @brief Toad Town - Gate District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_00_shape.h"
#include "mapfs/mac_00_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/RussT.h"
#include "sprite/npc/HarryT.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/Chan.h"
#include "sprite/npc/TheMaster.h"
#include "sprite/npc/Lee.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/ToadKid.h"
#include "sprite/npc/Luigi.h"
#include "sprite/npc/Goompapa.h"
#include "sprite/npc/Goomama.h"
#include "sprite/npc/Gooma.h"
#include "sprite/npc/VannaT.h"

enum {
    NPC_Luigi_Intro             = 0,
    NPC_RussT                   = 0,
    NPC_Toad_01                 = 1,
    NPC_Toad_02                 = 2,
    NPC_Toad_03                 = 3,
    NPC_TheMaster               = 3,
    NPC_Chan                    = 4,
    NPC_Lee                     = 5,
    NPC_ChuckQuizmo             = 6,
    NPC_Toad_04                 = 7,
    NPC_Toad_05                 = 8,
    NPC_Toad_06                 = 9,
    NPC_FickleLover             = 10,
    NPC_ShamelessLover          = 11,
    NPC_KrisT                   = 12,
    NPC_MissT                   = 13,
    NPC_FelissaT                = 14,
    NPC_DojoSpectator           = 15,
    NPC_DojoFan                 = 16,
    NPC_Waterfront_Dad          = 17,
    NPC_Waterfront_Mom          = 18,
    NPC_Waterfront_Kid1         = 19,
    NPC_Waterfront_Kid2         = 20,
    NPC_ShyGuyThief             = 21,
    NPC_ShyGuy_02               = 22,
    NPC_GardenShyGuy1           = 23,
    NPC_Toad_11                 = 24,
    NPC_Luigi_Epilogue          = 25,
    NPC_Goompapa_Epilogue       = 26,
    NPC_Goomama_Epilogue        = 27,
    NPC_Gooma_Epilogue          = 28,
    NPC_HarryT                  = 29,
    NPC_VannaT_Epilogue         = 30,
};

enum {
    MF_MusicMixTrigger1       = MapFlag(10),
    MF_MusicMixTrigger2       = MapFlag(11),
};

#define NAMESPACE mac_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupMusicTriggers);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupWaterCustomGfx);
extern EvtScript N(EVS_SetupDemo);
extern EvtScript N(EVS_Scene_Intro);
extern EvtScript N(EVS_Scene_BeginEpilogue);
extern EvtScript N(EVS_Scene_ToadTownGreeting);
extern EvtScript N(EVS_BlockExitToGoomaRoad);
extern EvtScript N(EVS_WaterfrontHouse_DoorLocked);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(DefaultNPCs);
