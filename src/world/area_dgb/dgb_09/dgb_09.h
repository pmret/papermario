/// @file dgb_09.h
/// @brief Tubba's Castle - West Hall (2F)

#include "common.h"
#include "../dgb.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE dgb_09

ApiStatus N(WanderMeleeAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(ClubbaNappingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(SentinelAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Main)(Evt *script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024533C);
extern EvtScript N(80243F6C);
extern EvtScript N(main);
