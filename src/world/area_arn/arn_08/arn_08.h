/// @file arn_08.h
/// @brief Gusty Gulch - Windmill Interior

#include "common.h"
#include "map.h"
#include "../arn.h"

#define NAMESPACE arn_08

f32 player_check_collision_below(f32, s32*);
f32 func_800E34D8(void);

ApiStatus N(func_80240000_BF47A0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024008C_BF482C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802400C0_BF4860)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802400D4_BF4874)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802400F4_BF4894)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024019C_BF493C)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80241828);
extern EvtSource N(80240B50);
extern EvtSource N(80240BA0);
extern EvtSource N(8024118C);
extern EvtSource N(80240300);
extern EvtSource N(main);
extern EvtSource N(makeEntities);
