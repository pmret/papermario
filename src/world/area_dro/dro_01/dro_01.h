/// @file dro_01.h
/// @brief Dry Dry Outpost - Outpost 1

#include "common.h"
#include "map.h"

#define NAMESPACE dro_01

typedef struct {
    u32 itemID;
    u32 buyPrice;
    u32 descriptionID;
} N(shopInventory);

typedef struct {
    u32 itemID;
    u32 sellPrice;
    u32 unk_08;
} N(shopPrice);

ApiStatus N(GetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(GetGameStatus75)(Evt* script, s32 isInitialCall);
ApiStatus N(GetNpcUnsafeOwner2)(Evt* script, s32 isInitialCall);
ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall);
ApiStatus N(Set80151310_1)(Evt* script, s32 isInitialCall);
ApiStatus N(SetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(SetManyVars)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkAlphaFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkCameraFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkMovePartner)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkRotatePartner)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkRotatePlayer)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkYawFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc27)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc26)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkNpcAIMainFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkQuizFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc31)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc29)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241B5C_95CD5C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241BE0_95CDE0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241DF8_95CFF8)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241EAC_95D0AC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241EE0_95D0E0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241F60_95D160)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241F78_95D178)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241F94_95D194)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802424D4_95D6D4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80242730_95D930)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80242784_95D984)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802427BC_95D9BC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80242858_95DA58)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243014_95E214)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243058_95E258)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243084_95E284)(Evt* script, s32 isInitialCall);
ApiStatus N(GetFloorCollider)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802431B4_95E3B4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802431FC_95E3FC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243350_95E550)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243578_95E778)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_AwaitDownInput)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetCameraYaw)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetCurrentFloor)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetEntryPos)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_SetAnimFlag)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetPointAheadOfPlayer)(Evt* script, s32 isInitialCall);

extern s32** N(varTable);
extern N(shopInventory) N(shopInventory_8024B4FC)[];
extern N(shopPrice) N(shopPriceList_8024B550)[];

extern NpcGroupList N(npcGroupList_8024B464);
extern NpcGroupList N(npcGroupList_8024B47C);
extern EvtScript N(80244450);
extern EvtScript N(8024C218);
extern EvtScript N(8024C2EC);
extern EvtScript N(8024C41C);
extern EvtScript N(8024C4C8);
extern EvtScript N(8024CDA0);
extern EvtScript N(8024DD78);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
extern EvtScript N(shopItemPositions_8024BA68);
extern ShopOwner N(shopOwnerNPC_8024BA80);
extern EvtScript N(unk_80248088);
extern EvtScript N(unk_8024884C);
