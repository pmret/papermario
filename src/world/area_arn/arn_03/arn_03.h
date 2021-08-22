#include "common.h"
#include "map.h"
#include "message_ids.h"
#include "../arn.h"

#define NAMESPACE arn_03

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241648_BE03D8)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241680_BE0410)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802415F4_BE0384)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024113C_BDFECC)(Evt* script, s32 isInitialCall);

extern EvtSource N(main);
extern EvtSource N(80241780);
extern NpcGroupList N(npcGroupList_80244740);
extern NpcGroupList N(npcGroupList_80244788);
extern EvtSource N(makeEntities);
