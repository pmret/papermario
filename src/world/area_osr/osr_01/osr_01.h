/// @file osr_01.h
/// @brief Peach's Castle Grounds - Ruined Castle Grounds

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../osr.h"
#include "mapfs/osr_01_shape.h"
#include "mapfs/osr_01_hit.h"

enum {
    NPC_Toad        = 0,
};

#define NAMESPACE osr_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlaySong_Starship);
extern EvtScript N(EVS_Scene_Wishing);
extern NpcGroupList N(DefaultNPCs);
