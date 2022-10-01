/// @file dgb_07.h
/// @brief Tubba's Castle - Study (1F)

#include "common.h"
#include "../dgb.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE dgb_07

ApiStatus N(ClubbaNappingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Main)(Evt *script, s32 isInitialCall);

NpcGroupList N(npcGroupList_80241E5C);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
