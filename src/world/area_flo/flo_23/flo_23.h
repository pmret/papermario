/// @file flo_23.h
/// @brief Flower Fields - (West) Path to Maze

#include "common.h"
#include "map.h"

#define NAMESPACE flo_23

extern s32 D_802EA0C4;

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240000_CEE260)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_WaitForSelection)(Evt* script, s32 isInitialCall);
ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall);
ApiStatus N(BuildItemChoiceList)(Evt* script, s32 isInitialCall);
ApiStatus N(TackleAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_SetItemEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_JudgeItemTastiness)(Evt* script, s32 isInitialCall);
ApiStatus N(FlowerGuard_MakeItemList)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80242568);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
