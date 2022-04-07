/// @file flo_11.h
/// @brief Flower Fields - (West) Maze

#include "common.h"
#include "map.h"

#define NAMESPACE flo_11

ApiStatus N(Pipe_GetCameraYaw)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_GetCurrentFloor)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_GetEntryPos)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_SetAnimFlag)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_GetPointAheadOfPlayer)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_AwaitDownInput)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802402E0_CBDFB0)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_802430D4);
extern EvtScript N(80240F1C);
extern EvtScript N(80242240);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
