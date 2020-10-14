#include "common.h"
#include "nu/nusys.h"

extern OSMesgQueue D_800AC5D0;
extern OSMesg D_800AC5E8[NU_PI_MESG_NUM];

void nuPiInit(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800AC5D0, D_800AC5E8, NU_PI_MESG_NUM);
    carthandle = osCartRomInit();
}
