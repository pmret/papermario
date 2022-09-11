/// @file dgb_03.h
/// @brief Tubba's Castle - Table/Clock Room (1/2F)

#include "common.h"
#include "../dgb.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE dgb_03

ApiStatus N(UnkFunc11)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc12)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(WanderMeleeAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(ClubbaPatrolAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(ClubbaNappingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(GetEntityPosition)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80244988);
extern EvtScript N(80243608);
extern EvtScript N(80243740);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
