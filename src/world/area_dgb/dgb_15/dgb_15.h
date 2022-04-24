/// @file dgb_15.h
/// @brief Tubba's Castle - West Hall (3F)

#include "common.h"
#include "map.h"

#define NAMESPACE dgb_15

ApiStatus N(GetEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(WanderMeleeAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(PatrolNoAttackAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Main)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80242AB0);
extern EvtScript N(80242AD0);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
extern EvtScript N(npcAI_8024274C);
extern EvtScript N(unk_80241F8C);
