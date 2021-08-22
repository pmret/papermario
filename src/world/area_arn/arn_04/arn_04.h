#include "common.h"
#include "map.h"
#include "../arn.h"

#define NAMESPACE arn_04

s32 func_800493EC(Enemy* enemy, s32 arg1, f32 arg2, f32 arg3);
ApiStatus N(func_80240B94_BE4344)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024219C_BE594C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243018_BE67C8)(Evt* script, s32 isInitialCall);

extern EvtSource N(main);
extern EvtSource N(802433D0);
extern NpcGroupList N(npcGroupList_80244000);
extern EvtSource N(makeEntities);

extern s16 gCurrentCamID;
