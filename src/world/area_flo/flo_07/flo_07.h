/// @file flo_07.h
/// @brief Flower Fields - (SW) Posie and Crystal Tree

#include "common.h"
#include "../flo.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE flo_07

ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(SpawnSunEffect)(Evt* script, s32 isInitialCall);
ApiStatus N(UpdateTexturePanSmooth)(Evt* script, s32 isInitialCall);
ApiStatus N(UpdateTexturePanStepped)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240344_CAC534)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80242B0C);
extern EvtScript N(80241C14);
extern EvtScript N(802424F4);
extern EvtScript N(802428C4);
extern EvtScript N(main);
