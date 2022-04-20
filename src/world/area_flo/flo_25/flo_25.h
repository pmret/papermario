/// @file flo_25.h
/// @brief Flower Fields - (SW) Path to Crystal Tree

#include "common.h"
#include "map.h"

#define NAMESPACE flo_25

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc43)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240000_CF2BD0)(Evt* script, s32 isInitialCall);
ApiStatus N(FlyingAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkNpcAIMainFunc10)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_WaitForSelection)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall);
ApiStatus N(BuildItemChoiceList)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_SetItemEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_JudgeItemTastiness)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_MakeItemList)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80243C5C);
extern EvtScript N(802446BC);
extern EvtScript N(80244D0C);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
