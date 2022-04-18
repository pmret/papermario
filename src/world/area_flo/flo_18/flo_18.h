/// @file flo_18.h
/// @brief Flower Fields - (NE) Puff Puff Machine

#include "common.h"
#include "map.h"

#define NAMESPACE flo_18

ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(UpdateTexturePanSmooth)(Evt* script, s32 isInitialCall);
ApiStatus N(UpdateTexturePanStepped)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFloatFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024030C_CDC9AC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240340_CDC9E0)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024669C);
extern EvtScript N(802436BC);
extern EvtScript N(80244058);
extern EvtScript N(802456D4);
extern EvtScript N(80247024);
extern EvtScript N(main);
extern EvtScript N(unkFloatFunc);
