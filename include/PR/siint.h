#ifndef _SIINT_H
#define _SIINT_H

#include "PR/os_internal.h"
#include "PR/rcp.h"

extern s32 __osEepromRead16K;
extern u8 __osPfsInodeCacheBank;

void __osSiGetAccess(void);
void __osSiRelAccess(void);
int __osSiDeviceBusy(void);
void __osSiCreateAccessQueue(void);

#endif
