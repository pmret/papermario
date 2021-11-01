/// @file dro_02.h
/// @brief Dry Dry Outpost - Outpost 2

#include "common.h"
#include "map.h"

#define NAMESPACE dro_02

ApiStatus N(Call800E9894)(Evt* script, s32 isInitialCall);
ApiStatus N(Call800E98C4SyncStatusMenu)(Evt* script, s32 isInitialCall);
ApiStatus N(Call800EB168)(Evt* script, s32 isInitialCall);
ApiStatus N(GetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(GetGameStatus75)(Evt* script, s32 isInitialCall);
ApiStatus N(GetNpcUnsafeOwner2)(Evt* script, s32 isInitialCall);
ApiStatus N(GetPartnerCall800EB168)(Evt* script, s32 isInitialCall);
ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall);
ApiStatus N(Set80151310_1)(Evt* script, s32 isInitialCall);
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
ApiStatus N(UnkQuizFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc31)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802409EC_969BAC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240A70_969C30)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240C88_969E48)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240D3C_969EFC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240D70_969F30)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240DF0_969FB0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240E08_969FC8)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240E24_969FE4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241364_96A524)(Evt* script, s32 isInitialCall);
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
ApiStatus N(UnkFunc32)(Evt* script, s32 isInitialCall);
ApiStatus N(CamSetFOV)(Evt* script, s32 isInitialCall);
ApiStatus N(DoesPlayerNeedSleep)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc35)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802439FC_96CBBC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243A40_96CC00)(Evt* script, s32 isInitialCall);
void N(func_8024240C_96B5CC)(Evt *script, s32 isInitialCall);
void N(func_80242EAC_96C06C)(Evt *script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024EEF4);
extern EvtSource N(80244C78);
extern EvtSource N(8024D434);
extern EvtSource N(8024D494);
extern EvtSource N(8024D700);
extern EvtSource N(main);
