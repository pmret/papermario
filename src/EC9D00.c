#include "dead.h"
#include "common.h"

// Copy of flo_08 (CAED40.c)

#define NAMESPACE EC9D00

#define gPartnerActionStatus dead_gPartnerActionStatus2
#define entity_upgrade_block_hide_content dead_entity_upgrade_block_hide_content

#include "world/common/SuperBlock_SetOverride40.inc.c"

#include "world/common/SuperBlock_ClearOverride40.inc.c"

#include "world/common/SuperBlock_HideBlockContent.inc.c"

#include "world/common/SuperBlock_GetPartnerRank.inc.c"

// SuperBlock_ShowSelectPartnerMenu
INCLUDE_ASM(s32, "EC9D00", func_802401CC_EC9ECC);

#include "world/common/SuperBlock_SwitchToPartner.inc.c"

#include "world/common/SuperBlock_LoadCurrentPartnerName.inc.c"

#include "world/common/SuperBlock_StartGlowEffect.inc.c"

#include "world/common/SuperBlock_EndGlowEffect.inc.c"

#include "world/common/SuperBlock_GatherEnergyFX.inc.c"

#include "world/common/SuperBlock_RadiateFaintEnergyFX.inc.c"

#include "world/common/SuperBlock_AnimateEnergyOrbs.inc.c"

#include "world/common/SuperBlock_WhiteScreenFlash.inc.c"

#include "world/common/UnkPartnerPosFuncs.inc.c"

#include "world/common/SuperBlock_WaitForPlayerToLand.inc.c"
