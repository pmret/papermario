#include "common.h"

INCLUDE_ASM(os/code_3a850_le_a40, nuPiInit);

INCLUDE_ASM(os/code_3a850_le_a40, nuPiReadRom);

INCLUDE_ASM(os/code_3a850_le_a40, nuGfxInit);

INCLUDE_ASM(os/code_3a850_le_a40, nuContInit);

INCLUDE_ASM(os/code_3a850_le_a40, nuContDataGet);

INCLUDE_ASM(os/code_3a850_le_a40, nuContPakMgrInit);

INCLUDE_ASM(os/code_3a850_le_a40, nuContPakMgrRemove);

INCLUDE_ASM(os/code_3a850_le_a40, contPakOpen);

INCLUDE_ASM(os/code_3a850_le_a40, contPakFree);

INCLUDE_ASM(os/code_3a850_le_a40, contPakFileReadWrite);

INCLUDE_ASM(os/code_3a850_le_a40, contPakFileOpen);

INCLUDE_ASM(os/code_3a850_le_a40, contPakFileDelete);

INCLUDE_ASM(os/code_3a850_le_a40, contPakFileState);

INCLUDE_ASM(os/code_3a850_le_a40, contPakFileNum);

INCLUDE_ASM(os/code_3a850_le_a40, contPakRepairId);

#undef osMotorStop
s32 INCLUDE_ASM(os/code_3a850_le_a40, osMotorStop, OSPfs *unk);

INCLUDE_ASM(os/code_3a850_le_a40, contRmbControl);

INCLUDE_ASM(os/code_3a850_le_a40, nuContRmbMgrInit);

INCLUDE_ASM(os/code_3a850_le_a40, nuContRmbMgrRemove);

INCLUDE_ASM(os/code_3a850_le_a40, contRmbCheckMesg);

INCLUDE_ASM(os/code_3a850_le_a40, contRmbStartMesg);

