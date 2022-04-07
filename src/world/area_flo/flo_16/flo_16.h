/// @file flo_16.h
/// @brief Flower Fields - (NE) Elevators

#include "common.h"
#include "map.h"

#define NAMESPACE flo_16

ApiStatus N(SuperBlock_SetOverride40)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_ClearOverride40)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_GetPartnerRank)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_LoadCurrentPartnerName)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_StartGlowEffect)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_GatherEnergyFX)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_RadiateFaintEnergyFX)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_WhiteScreenFlash)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_WaitForPlayerToLand)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_CountEligiblePartners)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_EndGlowEffect)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc43)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_PartnerSparkles2)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_PartnerSparkles4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240000_CD1E30)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_HideBlockContent)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_ShowSelectPartnerMenu)(Evt* script, s32 isInitialCall);
ApiStatus N(SwitchToPartner)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_AnimateEnergyOrbs)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc44)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkNpcAIMainFunc10)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80242940_CD4770)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_802444D4);
extern EvtScript N(8024346C);
extern EvtScript N(802451C4);
extern EvtScript N(main);
extern EvtScript N(makeEntities);
extern EvtScript N(unkFunc23);
