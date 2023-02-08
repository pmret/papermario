/// @file pra_09.h
/// @brief Crystal Palace - Red Key Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_09_shape.h"
#include "mapfs/pra_09_hit.h"

enum {
    NPC_Bombette_01             = 0,
    NPC_Bombette_02             = 1,
    NPC_Bombette_03             = 2,
    NPC_Bombette_04             = 3,
    NPC_Bombette_05             = 4,
    NPC_Duplighost_01           = 5,
    NPC_Duplighost_02           = 6,
    NPC_Duplighost_03           = 7,
    NPC_Duplighost_04           = 8,
    NPC_Duplighost_05           = 9,
    NPC_Bombette_01_Target      = 10,
    NPC_Bombette_02_Target      = 11,
    NPC_Bombette_03_Target      = 12,
    NPC_Bombette_04_Target      = 13,
    NPC_Bombette_05_Target      = 14,
};

enum {
    MV_UnmaskingState           = MapVar(0),
    MV_RevealedFakeBombette1    = MapVar(2),
    MV_RevealedFakeBombette2    = MapVar(3),
    MV_RevealedFakeBombette3    = MapVar(4),
    MV_RevealedFakeBombette4    = MapVar(5),
};

#define NAMESPACE pra_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitWalk_pra_11_0);
extern NpcGroupList N(DefaultNPCs);
