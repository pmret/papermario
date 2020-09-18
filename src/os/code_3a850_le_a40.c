#include "common.h"

#undef osMotorStop
s32 INCLUDE_ASM("os/code_3a850_le_a40", osMotorStop, OSPfs* unk);

INCLUDE_API_ASM("os/code_3a850_le_a40", contRmbControl);

INCLUDE_API_ASM("os/code_3a850_le_a40", nuContRmbMgrInit);

INCLUDE_API_ASM("os/code_3a850_le_a40", nuContRmbMgrRemove);

INCLUDE_API_ASM("os/code_3a850_le_a40", contRmbCheckMesg);

INCLUDE_API_ASM("os/code_3a850_le_a40", contRmbStartMesg);
