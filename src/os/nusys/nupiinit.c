#include "common.h"
#include "nu/nusys.h"

static OSMesgQueue D_800AC5D0;
static OSMesg D_800AC5E8[NU_PI_MESG_NUM];
OSPiHandle* nuPiCartHandle;

void nuPiInit(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800AC5D0, D_800AC5E8, NU_PI_MESG_NUM);
    nuPiCartHandle = osCartRomInit();
}
