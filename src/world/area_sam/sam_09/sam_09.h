/// @file sam_09.h
/// @brief Mt Shiver - Shiver Mountain Tunnel

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_09_shape.h"
#include "mapfs/sam_09_hit.h"

enum {
    MV_Socket1_ItemID       = MapVar(0),
    MV_Socket2_ItemID       = MapVar(1),
    MV_Socket3_ItemID       = MapVar(2),
    MV_Socket1_ItemEntityID       = MapVar(3),
    MV_Socket2_ItemEntityID       = MapVar(4),
    MV_Socket3_ItemEntityID       = MapVar(5),
};

#define NAMESPACE sam_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupSockets);
extern EvtScript N(EVS_MakeEntities);
