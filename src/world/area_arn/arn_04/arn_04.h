/// @file arn_04.h
/// @brief Gusty Gulch - Wasteland Ascent 2

#include "common.h"
#include "map.h"
#include "../arn.h"

#define NAMESPACE arn_04

ApiStatus N(PatrolAI_NoAttack_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(FlyingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243018_BE67C8)(Evt* script, s32 isInitialCall);

extern EvtScript N(main);
extern EvtScript N(802433D0);
extern NpcGroupList N(npcGroupList_80244000);
extern EvtScript N(makeEntities);
