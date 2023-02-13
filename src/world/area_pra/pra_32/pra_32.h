/// @file pra_32.h
/// @brief Crystal Palace - Crystal Summit

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_32_shape.h"
#include "mapfs/pra_32_hit.h"

enum {
    NPC_CrystalKing_01  = 0,
    NPC_CrystalKing_02  = 1,
    NPC_Kalmar          = 2,
    NPC_CrystalKing_03  = 3,
};

enum {
    MV_CamDistance      = MapVar(0),
    MV_Unk_01           = MapVar(1),
};

#define NAMESPACE pra_32

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_RespawnStarCard);
extern EvtScript N(EVS_SpawnStarCard);
extern EvtScript N(EVS_80240D3C);
extern NpcGroupList N(DefaultNPCs);
