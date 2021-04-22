#include "common.h"
#include "map.h"

#define NAMESPACE dro_02

ApiStatus N(Call800E9894)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Call800E98C4SyncStatusMenu)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Call800EB168)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetCamVfov)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetGameStatus75)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetNpcUnsafeOwner2)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetPartnerCall800EB168)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Set80151310_0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Set80151310_1)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetCamVfov)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetManyVars)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddPlayerHandsOffset)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkAlphaFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkCameraFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc26)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc27)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc29)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkMovePartner)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkRotatePartner)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkRotatePlayer)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkYawFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024043C_9695FC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc31)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802409EC_969BAC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240A70_969C30)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240C88_969E48)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240D3C_969EFC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240D70_969F30)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240DF0_969FB0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240E08_969FC8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240E24_969FE4)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241364_96A524)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241394_96A554)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802414C0_96A680)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802415CC_96A78C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802416FC_96A8BC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241874_96AA34)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024303C_96C1FC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243068_96C228)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802432C0_96C480)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243314_96C4D4)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024334C_96C50C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802433E8_96C5A8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc32)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc33)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc34)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc35)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802439FC_96CBBC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243A40_96CC00)(ScriptInstance* script, s32 isInitialCall);
void N(func_8024240C_96B5CC)(ScriptInstance *script, s32 isInitialCall);
void N(func_80242EAC_96C06C)(ScriptInstance *script, s32 isInitialCall);

NpcGroupList N(npcGroupList_8024EEF4);
Script N(80244C78);
Script N(8024D434);
Script N(8024D494);
Script N(8024D700);
Script N(main);
