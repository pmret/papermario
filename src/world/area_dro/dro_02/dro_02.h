/// @file dro_02.h
/// @brief Dry Dry Outpost - Outpost 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dro.h"
#include "mapfs/dro_02_shape.h"
#include "mapfs/dro_02_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldMerlee.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Archeologist.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/Mouser.h"
#include "sprite/npc/DisguisedMoustafa.h"
#include "sprite/npc/Moustafa.h"

enum {
	NPC_Archeologist            = 0,
	NPC_Dryite_01               = 1,
	NPC_DisguisedMoustafa       = 2,
	NPC_Toad                    = 3,
	NPC_Merlee                  = 4,
	NPC_Moustafa                = 5,
	NPC_Dryite_02               = 6,
	NPC_Mouser_01               = 7,
	NPC_Mouser_02               = 8,
	NPC_Mouser_03               = 9,
	NPC_ChuckQuizmo             = 10,
	NPC_Dryite_03               = 11,
};

enum {
	MF_Unk_00			= MapFlag(0),
};

#define NAMESPACE dro_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayRestMusic);
extern EvtScript N(EVS_PlayMoustafaMusic);

API_CALLABLE(InitVirtualEntityList);

API_CALLABLE(N(ToadHouse_DisableStatusMenu));
API_CALLABLE(N(ToadHouse_ShowStatusMenu));
API_CALLABLE(N(ToadHouse_GetPartnerBackOut));
API_CALLABLE(N(Quizmo_GetCamVfov));
API_CALLABLE(N(Quizmo_ShouldQuizmoLeave));
API_CALLABLE(N(Quizmo_NPC_Aux_Impl));
API_CALLABLE(N(ToadHouse_PutPartnerAway));
API_CALLABLE(N(Quizmo_ShowEntities));
API_CALLABLE(N(Quizmo_HideEntities));
API_CALLABLE(N(Quizmo_SetCamVfov));
API_CALLABLE(N(LetterDelivery_Init));
API_CALLABLE(N(AddPlayerHandsOffset));
API_CALLABLE(N(Quizmo_HideWorld));
API_CALLABLE(N(Quizmo_AddViewRelativeOffset));
API_CALLABLE(N(Quizmo_FadeInWorld));
API_CALLABLE(N(Quizmo_UpdatePartnerPosition));
API_CALLABLE(N(Quizmo_SpinPartner));
API_CALLABLE(N(Quizmo_SpinPlayer));
API_CALLABLE(N(LetterDelivery_CalcLetterPos));
API_CALLABLE(N(Quizmo_ShouldAppear));
API_CALLABLE(N(Quizmo_RenderInit));
API_CALLABLE(N(Quizmo_UpdateRecords));
API_CALLABLE(N(Quizmo_CreateStage));
API_CALLABLE(N(Quizmo_DestroyEffects));
API_CALLABLE(N(Quizmo_SetStageLightsDelay));
API_CALLABLE(N(Quizmo_UnkStageEffectMode));
API_CALLABLE(N(Quizmo_SetVannaAnim_Idle));
API_CALLABLE(N(Quizmo_SetVannaAnim_Clap));
API_CALLABLE(N(Quizmo_SetVannaAnim_Wave));
API_CALLABLE(N(Quizmo_CreateWorker));
API_CALLABLE(N(func_80241394_96A554));
API_CALLABLE(N(func_802414C0_96A680));
API_CALLABLE(N(func_802415CC_96A78C));
API_CALLABLE(N(func_802416FC_96A8BC));
API_CALLABLE(N(func_80241874_96AA34));
API_CALLABLE(N(func_8024303C_96C1FC));
API_CALLABLE(N(func_80243068_96C228));
API_CALLABLE(N(ItemChoice_WaitForSelection));
API_CALLABLE(N(ItemChoice_SaveSelected));
API_CALLABLE(N(BuildKeyItemChoiceList));
API_CALLABLE(N(BuildItemChoiceList));
API_CALLABLE(N(ToadHouse_UpdateScreenOverlay));
API_CALLABLE(N(ToadHouse_CamSetFOV));
API_CALLABLE(N(ToadHouse_DoesPlayerNeedSleep));
API_CALLABLE(N(ToadHouse_InitScreenOverlay));
API_CALLABLE(N(LetterDelivery_SaveNpcAnim));
API_CALLABLE(N(LetterDelivery_RestoreNpcAnim));
void N(func_8024240C_96B5CC)(void);
void N(func_80242EAC_96C06C)(void);

extern EvtScript N(EVS_SetupBuildings);
extern EvtScript N(8024D434);
extern EvtScript N(8024D494);
extern EvtScript N(8024D700);
extern EvtScript N(main);
