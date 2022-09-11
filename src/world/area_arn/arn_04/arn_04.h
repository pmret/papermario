/// @file arn_04.h
/// @brief Gusty Gulch - Wasteland Ascent 2

#include "common.h"
#include "../arn.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE arn_04

ApiStatus N(PatrolNoAttackAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(FlyingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(CleftAI_Main)(Evt* script, s32 isInitialCall);

extern EvtScript N(main);
extern EvtScript N(802433D0);
extern NpcGroupList N(npcGroupList_80244000);
extern EvtScript N(makeEntities);
