/// @file sbk_56.h
/// @brief Dry Dry Desert - S2E3 Oasis

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sbk.h"
#include "mapfs/sbk_56_shape.h"
#include "mapfs/sbk_56_hit.h"

enum {
    MV_SuperBlock   = MapVar(0),
};

enum {
    MF_TreeDrop_Lemon   = MapFlag(10),
    MF_TreeDrop_Lime    = MapFlag(12),
};

#define NAMESPACE sbk_56
