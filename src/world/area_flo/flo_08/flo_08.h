/// @file flo_08.h
/// @brief Flower Fields - (SE) Briar Platforming

#include "common.h"
#include "map.h"

#define NAMESPACE flo_08

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_SetOverride40)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_ClearOverride40)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_GetPartnerRank)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_LoadCurrentPartnerName)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_StartGlowEffect)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_GatherEnergyFX)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_RadiateFaintEnergyFX)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_WhiteScreenFlash)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_PartnerSparkles2)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_PartnerSparkles4)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_HideBlockContent)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_CountEligiblePartners)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_ShowSelectPartnerMenu)(Evt* script, s32 isInitialCall);
ApiStatus N(SwitchToPartner)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_EndGlowEffect)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_AnimateEnergyOrbs)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_WaitForPlayerToLand)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240D40_CAFA80)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024150C_CB024C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241970_CB06B0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802419C4_CB0704)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802419FC_CB073C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241A98_CB07D8)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241B5C_CB089C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241BCC_CB090C)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc43)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80244EC4);
extern EvtScript N(80245914);
extern EvtScript N(80245F5C);
extern EvtScript N(main);
extern s32 N(SuperBlock_CantUpgradeMessages)[];
extern s16 N(SuperBlock_PartnerIDs)[];
extern s32 N(SuperBlock_UpgradeDescMessages)[8][2];
extern f32 N(SuperBlock_UpgradeOrbAngles)[3];
extern s32 D_802462C0_B4AA30;
