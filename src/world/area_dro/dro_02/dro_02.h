/// @file dro_02.h
/// @brief Dry Dry Outpost - Outpost 2

#include "common.h"
#include "map.h"

#define NAMESPACE dro_02

ApiStatus N(ToadHouse_DisableStatusMenu)(Evt* script, s32 isInitialCall);
ApiStatus N(ToadHouse_ShowStatusMenu)(Evt* script, s32 isInitialCall);
ApiStatus N(ToadHouse_GetPartnerBackOut)(Evt* script, s32 isInitialCall);
ApiStatus N(GetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(GetGameStatus75)(Evt* script, s32 isInitialCall);
ApiStatus N(GetNpcUnsafeOwner2)(Evt* script, s32 isInitialCall);
ApiStatus N(ToadHouse_PutPartnerAway)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_Set80151310_0)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_Set80151310_1)(Evt* script, s32 isInitialCall);
ApiStatus N(SetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(SetManyVars)(Evt* script, s32 isInitialCall);
ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkAlphaFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkCameraFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc26)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc27)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc29)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkMovePartner)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkRotatePartner)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkRotatePlayer)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkYawFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkQuizFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc31)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkA)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkB)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkC)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkD)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkE)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkF)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkG)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkH)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkJ)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241394_96A554)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802414C0_96A680)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802415CC_96A78C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802416FC_96A8BC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241874_96AA34)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024303C_96C1FC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243068_96C228)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802432C0_96C480)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243314_96C4D4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024334C_96C50C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802433E8_96C5A8)(Evt* script, s32 isInitialCall);
ApiStatus N(ToadHouse_UpdateScreenOverlay)(Evt* script, s32 isInitialCall);
ApiStatus N(ToadHouse_CamSetFOV)(Evt* script, s32 isInitialCall);
ApiStatus N(ToadHouse_DoesPlayerNeedSleep)(Evt* script, s32 isInitialCall);
ApiStatus N(ToadHouse_InitScreenOverlay)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802439FC_96CBBC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243A40_96CC00)(Evt* script, s32 isInitialCall);
void N(func_8024240C_96B5CC)(Evt *script, s32 isInitialCall);
void N(func_80242EAC_96C06C)(Evt *script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024EEF4);
extern EvtScript N(80244C78);
extern EvtScript N(8024D434);
extern EvtScript N(8024D494);
extern EvtScript N(8024D700);
extern EvtScript N(main);
