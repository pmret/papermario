/// @file iwa_11.h
/// @brief Mt Rugged - Train Ride Scene

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_11_shape.h"
#include "mapfs/iwa_11_hit.h"

enum {
	NPC_TrainConductorToad        = 0,
};

enum {
    MV_TrainMoveDist    = MapVar(0),
    MV_TrainMoveSpeed   = MapVar(1),
};

enum {
    MF_Unk_00           = MapFlag(0),
    MF_Unk_01           = MapFlag(1),
    MF_Unk_02           = MapFlag(2),
    MF_Unk_03           = MapFlag(3),
    MF_TrainScrolling   = MapFlag(4),
    MF_TrainReverseDir  = MapFlag(5),
};

#define NAMESPACE iwa_11
