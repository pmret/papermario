/// @file mgm_02.h
/// @brief Minigame - Smash Attack Minigame

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mgm.h"
#include "mapfs/mgm_02_shape.h"
#include "mapfs/mgm_02_hit.h"

#include "sprite/npc/Toad.h"
#include "sprite/npc/Fuzzy.h"
#include "sprite/npc/Bobomb.h"
#include "sprite/npc/Luigi.h"

enum {
    NPC_Toad                    = 0,
    NPC_Fuzzy_01                = 10,
    NPC_Fuzzy_02                = 11,
    NPC_Fuzzy_03                = 12,
    NPC_Fuzzy_04                = 13,
    NPC_Fuzzy_05                = 14,
    NPC_Bobomb_01               = 30,
    NPC_Bobomb_02               = 31,
    NPC_Bobomb_03               = 32,
    NPC_Bobomb_04               = 33,
    NPC_Bobomb_05               = 34,
    NPC_Luigi_01                = 100,
    NPC_Luigi_02                = 101,
    NPC_Luigi_03                = 102,
    NPC_Luigi_04                = 103,
    NPC_Luigi_05                = 104,
    NPC_Luigi_06                = 105,
    NPC_Luigi_07                = 106,
    NPC_Luigi_08                = 107,
    NPC_Luigi_09                = 108,
    NPC_Luigi_10                = 109,
};

#define NAMESPACE mgm_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_Dummy);
extern EvtScript N(EVS_InitializeMinigame);
extern NpcGroupList N(DefaultNPCs);

#if VERSION_PAL
extern s32 N(pal_variable);
#endif
