#include "common.h"

INCLUDE_API_ASM(os/code_3a850_le_a40, nuPiInit);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuPiReadRom);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuGfxInit);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuContInit);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuContDataGet);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuContPakMgrInit);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuContPakMgrRemove);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakOpen);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakFree);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakFileReadWrite);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakFileOpen);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakFileDelete);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakFileState);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakFileNum);

INCLUDE_API_ASM(os/code_3a850_le_a40, contPakRepairId);

#undef osMotorStop
s32 INCLUDE_ASM(os/code_3a850_le_a40, osMotorStop, OSPfs* unk);

INCLUDE_API_ASM(os/code_3a850_le_a40, contRmbControl);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuContRmbMgrInit);

INCLUDE_API_ASM(os/code_3a850_le_a40, nuContRmbMgrRemove);

INCLUDE_API_ASM(os/code_3a850_le_a40, contRmbCheckMesg);

INCLUDE_API_ASM(os/code_3a850_le_a40, contRmbStartMesg);
