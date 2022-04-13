#include "mac_00.h"

#include "world/common/atomic/enemy/UnkAI_1.inc.c"

static char* N(exit_str_0) = "mac_01";

#define NAMESPACE dup_mac_00
#include "world/common/StashVars.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/GetItemName.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/GetNpcCollisionHeight.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE mac_00

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243744_7EE454);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243798_7EE4A8);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_802437D0_7EE4E0);

#define NAMESPACE dup_mac_00
#include "world/common/SetManyVars.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/UnkYawFunc.inc.c"
#define NAMESPACE mac_00

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243AE8_7EE7F8);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243B2C_7EE83C);
