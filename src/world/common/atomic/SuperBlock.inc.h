#ifndef SUPER_BLOCK_INC_H
#define SUPER_BLOCK_INC_H

#include "common.h"

#define SUPER_BLOCK_NUM_ORBS 3

ApiStatus N(SuperBlock_SetOverride40)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_ClearOverride40)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_HideBlockContent)(Evt *script, s32 isInitialCall);
ApiStatus N(SuperBlock_GetPartnerRank)(Evt* script, s32 isInitialCall);
s32 N(SuperBlock_get_partner_rank)(s32 idx, s16 maxLevel);
ApiStatus N(SuperBlock_CountEligiblePartners)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_ShowSelectPartnerMenu)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_SwitchToPartner)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_LoadCurrentPartnerName)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_StartGlowEffect)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_EndGlowEffect)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_GatherEnergyFX)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_RadiateFaintEnergyFX)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_AnimateEnergyOrbs)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_WhiteScreenFlash)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_PartnerSparkles2)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_PartnerSparkles4)(Evt* script, s32 isInitialCall);
ApiStatus N(SuperBlock_WaitForPlayerToLand)(Evt* script, s32 isInitialCall);

extern s32 N(SuperBlock_CantUpgradeMessages)[2];
extern s16 N(SuperBlock_PartnerIDs)[8];
extern s32 N(SuperBlock_UpgradeDescMessages)[8][2];
extern f32 N(SuperBlock_UpgradeOrbAngles)[SUPER_BLOCK_NUM_ORBS];

#endif
