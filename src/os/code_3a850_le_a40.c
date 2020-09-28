#include "common.h"

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuPiInit);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuPiReadRom);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuGfxInit);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuContInit);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuContDataGet);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuContPakMgrInit);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuContPakMgrRemove);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakOpen);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakFree);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakFileReadWrite);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakFileOpen);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakFileDelete);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakFileState);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakFileNum);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contPakRepairId);

#undef osMotorStop
INCLUDE_ASM(s32, "os/code_3a850_le_a40", osMotorStop, OSPfs* unk);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contRmbControl);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuContRmbMgrInit);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", nuContRmbMgrRemove);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contRmbCheckMesg);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", contRmbStartMesg);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", func_8005FDE4);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", func_8005FE0C);

INCLUDE_ASM(s32, "os/code_3a850_le_a40", func_8005FE54);
