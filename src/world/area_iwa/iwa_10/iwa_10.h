/// @file iwa_10.h
/// @brief Mt Rugged - Train Station

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_10_shape.h"
#include "mapfs/iwa_10_hit.h"

#include "sprite/npc/TrainStationToad.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/WorldParakarry.h"

enum {
	NPC_TrainStationToad_01     = 0,
	NPC_TrainStationToad_02     = 1,
	NPC_Dryite                  = 2,
	NPC_ThreeSisters_01         = 3,
	NPC_Parakarry               = 4,
	NPC_Toad                    = 5,
	NPC_ThreeSisters_02         = 6,
	NPC_ThreeSisters_03         = 7,
	NPC_ThreeSisters_04         = 8,
};

enum {
    MF_Unk_00               = MapFlag(0),
    MF_Unk_01               = MapFlag(1),
    MF_Unk_02               = MapFlag(2),
    MF_Unk_03               = MapFlag(3),
    MF_TrainMoving          = MapFlag(4),
    MF_TrainReverseDir      = MapFlag(5),
    MF_DropBush1            = MapFlag(10),
    MF_DropBush2            = MapFlag(11),
    MF_DropBush3            = MapFlag(12),
    MF_DropBush4            = MapFlag(13),
};

enum {
    MV_TrainMoveDist        = MapVar(0),
    MV_TrainMoveSpeed       = MapVar(1),
    MV_Unk_0A               = MapVar(10),
    MV_SuperBlock           = MapVar(11),
};

#define NAMESPACE iwa_10
