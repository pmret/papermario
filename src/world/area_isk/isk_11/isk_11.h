/// @file isk_11.h
/// @brief Dry Dry Ruins - Stone Puzzle Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_11_shape.h"
#include "mapfs/isk_11_hit.h"

#define NAMESPACE isk_11

enum {
    MV_LockEntityID             = MapVar(0),
    MV_HiddenStairsRevealed     = MapVar(0),
    MV_PlayerPanicDone          = MapVar(1),
    MV_Socket1_ItemEntity       = MapVar(10),
    MV_Socket2_ItemEntity       = MapVar(11),
    MV_Socket3_ItemEntity       = MapVar(12),
    MV_Socket4_ItemEntity       = MapVar(13),
    MV_Socket5_ItemEntity       = MapVar(14),
};

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupPuzzle);
extern EvtScript N(EVS_ManageSecretPassage);
extern EvtScript N(EVS_SetupLock);
extern EvtScript N(EVS_MakeEntities);
