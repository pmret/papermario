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
ApiStatus N(GetCurrentCameraYawClamped180)(Evt* script, s32 isInitialCall);
ApiStatus N(GetCurrentFloor)(Evt* script, s32 isInitialCall);
ApiStatus N(GetEntryPos)(Evt* script, s32 isInitialCall);
ApiStatus N(GetGameStatus75)(Evt* script, s32 isInitialCall);
ApiStatus N(GetNpcUnsafeOwner2)(Evt* script, s32 isInitialCall);
ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall);
ApiStatus N(Set80151310_1)(Evt* script, s32 isInitialCall);
ApiStatus N(SetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(SetManyVars)(Evt* script, s32 isInitialCall);
ApiStatus N(SetPlayerStatusAnimFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(SomeXYZFunc2)(Evt* script, s32 isInitialCall);
ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkAlphaFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkCameraFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkMovePartner)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkRotatePartner)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkRotatePlayer)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkYawFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc25)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc27)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc26)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241174_95C374)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802415AC_95C7AC)(Evt* script, s32 isInitialCall);
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
ApiStatus N(dup_UnkFunc25)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_GetCurrentCameraYawClamped180)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_GetCurrentFloor)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_GetEntryPos)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_SetPlayerStatusAnimFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_SomeXYZFunc2)(Evt* script, s32 isInitialCall);

extern s32** N(D_8024B5B0_9667B0);
extern N(shopInventory) N(shopInventory_8024B4FC)[];
extern N(shopPrice) N(shopPriceList_8024B550)[];

extern NpcGroupList N(npcGroupList_8024B464);
extern NpcGroupList N(npcGroupList_8024B47C);
extern EvtSource N(80244450);
extern EvtSource N(8024C218);
extern EvtSource N(8024C2EC);
extern EvtSource N(8024C41C);
extern EvtSource N(8024C4C8);
extern EvtSource N(8024CDA0);
extern EvtSource N(8024DD78);
extern EvtSource N(main);
extern EvtSource N(makeEntities);
extern EvtSource N(shopItemPositions_8024BA68);
extern EvtSource N(shopOwnerNPC_8024BA80);
extern EvtSource N(unk_80248088);
extern EvtSource N(unk_8024884C);
