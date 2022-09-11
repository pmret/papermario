/// @file dgb_16.h
/// @brief Tubba's Castle - Sleeping Clubbas Room (3F)

#include "common.h"
#include "../dgb.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE dgb_16

ApiStatus N(ClubbaNappingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Main)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024318C);
extern EvtScript N(80241780);
extern EvtScript N(main);
