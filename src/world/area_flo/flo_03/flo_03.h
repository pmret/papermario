/// @file flo_03.h
/// @brief Flower Fields - (East) Petunia's Field

#include "common.h"
#include "../flo.h"
#include "message_ids.h"
#include "map.h"

#define NAMESPACE flo_03

ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240000_CA72A0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240158_CA73F8)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240460_CA7700)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024442C);
extern EvtScript N(80240FFC);
extern EvtScript N(80241EF4);
extern EvtScript N(80244E54);
extern EvtScript N(80244ED0);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
