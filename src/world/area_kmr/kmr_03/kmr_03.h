/// @file kmr_03.h
/// @brief Goomba Region - Bottom of the Cliff

#include "common.h"
#include "../kmr.h"
#include "message_ids.h"
#include "map.h"
#include "../kmr.h"

#define NAMESPACE kmr_03

ApiStatus N(UnkPositionFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc41)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802401B0_8C8140)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80241450);
extern EvtScript N(802422B8);
extern EvtScript N(80242340);
extern EvtScript N(802406C0);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
