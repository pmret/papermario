/// @file dgb_15.h
/// @brief Tubba's Castle - West Hall (3F)

#include "common.h"
#include "map.h"

#define NAMESPACE dgb_15

ApiStatus N(GetEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024061C_C4FB2C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241464_C50974)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc7)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80242AB0);
extern EvtSource N(80242AD0);
extern EvtSource N(main);
extern EvtSource N(makeEntities);
extern EvtSource N(npcAI_8024274C);
extern EvtSource N(unk_80241F8C);
