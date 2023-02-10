/// @file jan_13.h
/// @brief Jade Jungle - Deep Jungle 2 (Block Puzzle)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_13_shape.h"
#include "mapfs/jan_13_hit.h"

enum {
    MV_PuzzleProgress       = MapVar(0),
};

enum {
    MF_GeyserSoundPlaying   = MapFlag(10),
};

#define NAMESPACE jan_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupPuzzle);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_MakeEntities);
