/// @file dro_01.h
/// @brief Dry Dry Outpost - Outpost 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dro.h"
#include "mapfs/dro_01_shape.h"
#include "mapfs/dro_01_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Mouser.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/Musician.h"
#include "sprite/npc/Toadette.h"

enum {
	NPC_Mouser_01               = 0,
	NPC_Dryite_01               = 1,
	NPC_Dryite_02               = 2,
	NPC_Dryite_03               = 3,
	NPC_Dryite_04               = 4,
	NPC_ArtistToad              = 5,
	NPC_Mouser_02               = 6,
	NPC_ThreeSisters_01         = 7,
	NPC_ThreeSisters_02         = 8,
	NPC_ThreeSisters_03         = 9,
	NPC_ChuckQuizmo             = 10,
	NPC_Dryite_05               = 11,
	NPC_Dryite_06               = 12,
};

#define NAMESPACE dro_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(Chapter3NPCs);

extern EvtScript N(EVS_SetupBuildings);
extern EvtScript N(EVS_SwingSign_Shop);
extern EvtScript N(EVS_OpenShopDoor);
extern EvtScript N(EVS_CloseShopDoor);

extern ShopItemData N(Shop_Inventory)[];
extern ShopSellPriceData N(Shop_PriceList)[];
extern ShopItemLocation N(Shop_ItemPositions)[];
extern ShopOwner N(Shop_Owner);

ApiStatus N(Quizmo_GetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_ShouldQuizmoLeave)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_NPC_Aux_Impl)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_ShowEntities)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_HideEntities)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetCamVfov)(Evt* script, s32 isInitialCall);
ApiStatus N(LetterDelivery_Init)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_HideWorld)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_AddViewRelativeOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UpdatePartnerPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SpinPartner)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SpinPlayer)(Evt* script, s32 isInitialCall);
ApiStatus N(LetterDelivery_CalcLetterPos)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc27)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc26)(Evt* script, s32 isInitialCall);
ApiStatus N(PatrolNoAttackAI_Main)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_ShouldAppear)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_RenderInit)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_FadeInWorld)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UpdateRecords)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_CreateStage)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_DestroyEffects)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetStageLightsDelay)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_UnkStageEffectMode)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetVannaAnim_Idle)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetVannaAnim_Clap)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_SetVannaAnim_Wave)(Evt* script, s32 isInitialCall);
ApiStatus N(Quizmo_CreateWorker)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80242730_95D930)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80242784_95D984)(Evt* script, s32 isInitialCall);
ApiStatus N(BuildKeyItemChoiceList)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80242858_95DA58)(Evt* script, s32 isInitialCall);
ApiStatus N(LetterDelivery_SaveNpcAnim)(Evt* script, s32 isInitialCall);
ApiStatus N(LetterDelivery_RestoreNpcAnim)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243084_95E284)(Evt* script, s32 isInitialCall);
ApiStatus N(GetFloorCollider)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802431B4_95E3B4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802431FC_95E3FC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80243350_95E550)(Evt* script, s32 isInitialCall);
ApiStatus N(HideCoinCounter)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_AwaitDownInput)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetCameraYaw)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetCurrentFloor)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetEntryPos)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_SetAnimFlag)(Evt* script, s32 isInitialCall);
ApiStatus N(dup_Pipe_GetPointAheadOfPlayer)(Evt* script, s32 isInitialCall);

extern EvtScript N(80244450);

extern EvtScript N(8024CDA0);
extern EvtScript N(8024DD78);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
extern EvtScript N(unk_80248088);
extern EvtScript N(unk_8024884C);

