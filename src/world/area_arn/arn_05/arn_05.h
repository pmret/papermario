/// @file arn_05.h
/// @brief Gusty Gulch - Ghost Town 2

#include "common.h"
#include "../arn.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE arn_05

ApiStatus func_802D2B50(void);

ApiStatus N(SwitchToPartner)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802412B0_BE8E90)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024113C_BE8D1C)(Evt* script, s32 isInitialCall);

extern EvtScript N(makeEntities);
extern EvtScript N(main);
extern EvtScript N(80241360);
extern EvtScript N(802441FC);
extern NpcGroupList N(npcGroupList_80244FC8);
extern NpcGroupList N(npcGroupList_80244FA4);
