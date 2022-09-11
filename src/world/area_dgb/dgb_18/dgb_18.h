/// @file dgb_18.h
/// @brief Tubba's Castle - Master Bedroom (3F)

#include "common.h"
#include "../dgb.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE dgb_18

ApiStatus N(UnkFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(PatrolNoAttackAI_Main)(Evt* script, s32 isInitialCall);

extern s32** N(varStash);

extern NpcGroupList N(npcGroupList_802436B4);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
extern EvtScript N(npcAI_80242834);
