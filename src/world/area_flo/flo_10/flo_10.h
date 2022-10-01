/// @file flo_10.h
/// @brief Flower Fields - (SE) Lily's Fountain

#include "common.h"
#include "../flo.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE flo_10

ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(UpdateTexturePanSmooth)(Evt* script, s32 isInitialCall);
ApiStatus N(UpdateTexturePanStepped)(Evt* script, s32 isInitialCall);
s32 N(get_tattle)(void);
ApiStatus N(func_80240040_CB9240)(Evt* script, s32 isInitialCall);

extern s32 N(D_80244070_CBD270);
extern s32** N(varStash);
extern NpcGroupList N(npcGroupList_80244054);
extern EvtScript N(802427EC);
extern EvtScript N(80242AE8);
extern EvtScript N(8024324C);
extern EvtScript N(802435F8);
extern EvtScript N(80244074);
extern EvtScript N(80244A50);
extern EvtScript N(main);
