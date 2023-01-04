/// @file osr_00.h
/// @brief Peach's Castle Grounds - Intro Castle Grounds

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../osr.h"
#include "mapfs/osr_00_shape.h"
#include "mapfs/osr_00_hit.h"

enum {
    NPC_Luigi                   = 0,
    NPC_YoshiLeader             = 0,
    NPC_Yoshi                   = 1,
    NPC_YoshiKid                = 2,
    NPC_MayorPenguin            = 3,
    NPC_MayorPenguinWife        = 4,
    NPC_Penguin_01              = 5,
    NPC_Penguin_02              = 6,
    NPC_Moustafa                = 7,
    NPC_Mouser                  = 8,
    NPC_Boo_01                  = 9,
    NPC_Boo_02                  = 10,
    NPC_Toad                    = 12,
    NPC_ToadGuard_01            = 13,
    NPC_ToadGuard_02            = 14,
};

#define NAMESPACE osr_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_ShowInvitation);
extern EvtScript N(EVS_Scene_ApproachParty);
extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(EpilogueNPCs);
