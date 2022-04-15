/// @file arn_03.h
/// @brief Gusty Gulch - Ghost Town 1

#include "common.h"
#include "map.h"
#include "message_ids.h"
#include "../arn.h"

#define NAMESPACE arn_03

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall);
ApiStatus N(BuildKeyItemChoiceList)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_WaitForSelection)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024113C_BDFECC)(Evt* script, s32 isInitialCall);

extern EvtScript N(main);
extern EvtScript N(80241780);
extern NpcGroupList N(npcGroupList_80244740);
extern NpcGroupList N(npcGroupList_80244788);
extern EvtScript N(makeEntities);
