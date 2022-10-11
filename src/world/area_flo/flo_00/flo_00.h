/// @file flo_00.h
/// @brief Flower Fields - Center

#include "common.h"
#include "../flo.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE flo_00

ApiStatus N(SyncStatusMenu)(Evt* script, s32 isInitialCall);
ApiStatus N(PostChapter6StatUpdate)(Evt* script, s32 isInitialCall);
ApiStatus N(CosInterpMinMax)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240000_C9DF20)(Evt* script, s32 isInitialCall);
ApiStatus N(PatrolNoAttackAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240ED0_C9EDF0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240F10_C9EE30)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240F80_C9EEA0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802410B4_C9EFD4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802411EC_C9F10C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024137C_C9F29C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024139C_C9F2BC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802413BC_C9F2DC)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80245DE4);
extern NpcGroupList N(npcGroupList_80246834);
extern EvtScript N(80242998);
extern EvtScript N(80242FCC);
extern EvtScript N(80245EB8);
extern EvtScript N(80247BCC);
extern EvtScript N(8024834C);
extern EvtScript N(80248E30);
extern EvtScript N(80248F48);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
