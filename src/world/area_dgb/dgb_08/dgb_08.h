/// @file dgb_08.h
/// @brief Tubba's Castle - East Hall (1/2F)

#include "common.h"
#include "../dgb.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE dgb_08

ApiStatus N(UnkFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(PatrolNoAttackAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(MeleeHitbox_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(WanderMeleeAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(SentinelAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243B98_C43948)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243C10_C439C0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243C50_C43A00)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80246958);
extern NpcGroupList N(npcGroupList_802469AC);
extern NpcGroupList N(npcGroupList_802469C4);
extern EvtScript N(802469E0);
extern EvtScript N(main);
extern EvtScript N(npcAI_80244D7C);
extern EvtScript N(unk_80244100);
