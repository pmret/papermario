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

ApiStatus N(GetCamVfov)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetCurrentCameraYawClamped180)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetCurrentFloor)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetEntryPos)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetGameStatus75)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetNpcUnsafeOwner2)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Set80151310_0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(Set80151310_1)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetCamVfov)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetManyVars)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetPlayerStatusAnimFlags100000)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SomeMatrixOperation2)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SomeXYZFunc2)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddPlayerHandsOffset)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkAlphaFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkCameraFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkMovePartner)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkRotatePartner)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkRotatePlayer)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkYawFunc)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc25)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc27)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc26)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241174_95C374)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802415AC_95C7AC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc31)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc29)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241B5C_95CD5C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241BE0_95CDE0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241DF8_95CFF8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241EAC_95D0AC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241EE0_95D0E0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241F60_95D160)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241F78_95D178)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241F94_95D194)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802424D4_95D6D4)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242730_95D930)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242784_95D984)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802427BC_95D9BC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80242858_95DA58)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243014_95E214)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243058_95E258)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243084_95E284)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc30)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802431B4_95E3B4)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802431FC_95E3FC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243350_95E550)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80243578_95E778)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(dup_UnkFunc25)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(dup_GetCurrentCameraYawClamped180)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(dup_GetCurrentFloor)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(dup_GetEntryPos)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(dup_SetPlayerStatusAnimFlags100000)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(dup_SomeXYZFunc2)(ScriptInstance* script, s32 isInitialCall);

extern s32** N(D_8024B5B0_9667B0);
extern N(shopInventory) N(shopInventory_8024B4FC)[];
extern N(shopPrice) N(shopPriceList_8024B550)[];

extern NpcGroupList N(npcGroupList_8024B464);
extern NpcGroupList N(npcGroupList_8024B47C);
extern Script N(80244450);
extern Script N(8024C218);
extern Script N(8024C2EC);
extern Script N(8024C41C);
extern Script N(8024C4C8);
extern Script N(8024CDA0);
extern Script N(8024DD78);
extern Script N(main);
extern Script N(makeEntities);
extern Script N(shopItemPositions_8024BA68);
extern Script N(shopOwnerNPC_8024BA80);
extern Script N(unk_80248088);
extern Script N(unk_8024884C);
