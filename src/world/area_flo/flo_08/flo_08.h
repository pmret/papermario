/// @file flo_08.h
/// @brief Flower Fields - (SE) Briar Platforming

#include "common.h"
#include "map.h"

#define NAMESPACE flo_08

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240D40_CAFA80)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFloAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_WaitForSelection)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall);
ApiStatus N(BuildItemChoiceList)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_SetItemEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_JudgeItemTastiness)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_MakeItemList)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc43)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80244EC4);
extern EvtScript N(80245914);
extern EvtScript N(80245F5C);
extern EvtScript N(main);
