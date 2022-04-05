/// @file flo_21.h
/// @brief Flower Fields - Huff N Puff Room

#include "common.h"
#include "map.h"

#define NAMESPACE flo_21

ApiStatus N(UpdateTexturePanSmooth)(Evt* script, s32 isInitialCall);
ApiStatus N(UpdateTexturePanStepped)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFloatFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(flo_21_StarSpiritEffectFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(flo_21_StarSpiritEffectFunc2)(Evt* script, s32 isInitialCall);
ApiStatus N(flo_21_StarSpiritEffectFunc3)(Evt* script, s32 isInitialCall);
ApiStatus N(flo_21_StarSpiritEffectFunc4)(Evt* script, s32 isInitialCall);
ApiStatus N(flo_21_StarSpiritEffectFunc5)(Evt* script, s32 isInitialCall);
ApiStatus N(flo_21_StarSpiritEffectFunc6)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240B00_CE7200)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80245AEC);
extern EvtScript N(80241600);
extern EvtScript N(80241B98);
extern EvtScript N(main);
