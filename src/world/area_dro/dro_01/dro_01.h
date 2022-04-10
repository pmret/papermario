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

ApiStatus N(Quizmo_GetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_ShouldQuizmoLeave)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_NPC_Aux_Impl)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_ShowEntities)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_HideEntities)(Evt* script, s32 isInitialCall);
ApiStatus N(SetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(SetManyVars)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_HideWorld)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_AddViewRelativeOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UpdatePartnerPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SpinPartner)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SpinPlayer)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkYawFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc27)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc26)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkNpcAIMainFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_ShouldAppear)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_RenderInit)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_FadeInWorld)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UpdateRecords)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_CreateStage)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_DestroyEffects)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetStageLightsMode)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkStageEffectMode)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetVannaAnim_Idle)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetVannaAnim_Clap)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetVannaAnim_Wave)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_CreateWorker)(Evt* script, s32 isInitialCall);
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

extern s32** N(VarStash);
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
