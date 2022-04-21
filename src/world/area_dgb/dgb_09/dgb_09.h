/// @file dgb_09.h
/// @brief Tubba's Castle - West Hall (2F)

#include "common.h"
#include "map.h"

#define NAMESPACE dgb_09

ApiStatus N(func_8024061C_C471FC)(Evt* script, s32 isInitialCall);
ApiStatus N(ClubbaNappingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(SentinelAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Control)(Evt *script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024533C);
extern EvtScript N(80243F6C);
extern EvtScript N(main);
