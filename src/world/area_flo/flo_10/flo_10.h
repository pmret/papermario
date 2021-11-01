/// @file flo_10.h
/// @brief Flower Fields - (SE) Lily's Fountain

#include "common.h"
#include "map.h"

#define NAMESPACE flo_10

ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkTexturePanFunc2)(Evt* script, s32 isInitialCall);
s32 N(func_80240000_CB9200)(void);
ApiStatus N(func_80240040_CB9240)(Evt* script, s32 isInitialCall);

extern s32 N(D_80244070_CBD270);
extern s32** N(D_80241CB0_CBAEB0);
extern NpcGroupList N(npcGroupList_80244054);
extern EvtSource N(802427EC);
extern EvtSource N(80242AE8);
extern EvtSource N(8024324C);
extern EvtSource N(802435F8);
extern EvtSource N(80244074);
extern EvtSource N(80244A50);
extern EvtSource N(main);
