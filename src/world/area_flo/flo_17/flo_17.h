/// @file flo_17.h
/// @brief Flower Fields - (NE) Fallen Logs

#include "common.h"
#include "../flo.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE flo_17

ApiStatus N(func_80240000_CD72E0)(Evt* script, s32 isInitialCall);
ApiStatus N(LakituAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(SpinyAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240040_CD7320)(Evt *script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80245228);
extern EvtScript N(80244284);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
