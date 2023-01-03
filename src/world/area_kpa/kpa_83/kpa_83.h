/// @file kpa_83.h
/// @brief Bowser's Castle - Guard Door 3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_80_shape.h"
#include "mapfs/kpa_80_hit.h"

#include "sprite/npc/KoopaBros.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/JrTroopa.h"

enum {
    NPC_Door            = 0,
    NPC_KoopaBrosBlk    = 1,
    NPC_KoopaBrosRed    = 2,
    NPC_KoopaBrosYlw    = 3,
    NPC_KoopaBrosGrn    = 4,
    NPC_JrTroopa        = 5,
};

enum {
    MV_KoopaBrosRed_HopScript       = MapVar(0),
    MV_KoopaBrosBlk_HopScript       = MapVar(1),
    MV_KoopaBrosYlw_HopScript       = MapVar(2),
    MV_KoopaBrosGrn_HopScript       = MapVar(3),
    MV_Sync_AfterBattleCamMovement  = MapVar(4),
};

enum {
    MF_DoneIntroMessage = MapFlag(0),
};

#define NAMESPACE kpa_83

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
