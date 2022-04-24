/// @file dgb_02.h
/// @brief Tubba's Castle - West Hall (1F)

#include "common.h"
#include "map.h"

#define NAMESPACE dgb_02

ApiStatus N(WanderMeleeAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(ClubbaNappingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Control)(Evt *script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_802425C8);
extern EvtScript N(main);
