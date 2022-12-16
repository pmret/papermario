#include "include_asm.h"
#include "PR/os_internal.h"
#include "PR/rcp.h"

typedef struct
{
   /* 0x0 */ unsigned int inst1;
   /* 0x4 */ unsigned int inst2;
   /* 0x8 */ unsigned int inst3;
   /* 0xC */ unsigned int inst4;
} __osExceptionVector;
extern __osExceptionVector __osExceptionPreamble;

extern OSPiHandle __Dom1SpeedParam;
extern OSPiHandle __Dom2SpeedParam;

OSTime osClockRate = OS_CLOCK_RATE;
s32 osViClock = VI_NTSC_CLOCK;
u32 __osShutdown = 0;
u32 __OSGlobalIntMask = OS_IM_ALL;
#ifdef _FINALROM
extern u32 __osFinalrom;
#else
void* __printfunc = NULL;
u32 __kmc_pt_mode;
#endif

s32 D_80095904[3] = { 0 }; // padding?
s32 D_80095910[10] = { 0 };
s32 D_80095938[2] = { 0 };

void __createSpeedParam(void) {
    __Dom1SpeedParam.type = DEVICE_TYPE_INIT;
    __Dom1SpeedParam.latency = IO_READ(PI_BSD_DOM1_LAT_REG);
    __Dom1SpeedParam.pulse = IO_READ(PI_BSD_DOM1_PWD_REG);
    __Dom1SpeedParam.pageSize = IO_READ(PI_BSD_DOM1_PGS_REG);
    __Dom1SpeedParam.relDuration = IO_READ(PI_BSD_DOM1_RLS_REG);

    __Dom2SpeedParam.type = DEVICE_TYPE_INIT;
    __Dom2SpeedParam.latency = IO_READ(PI_BSD_DOM2_LAT_REG);
    __Dom2SpeedParam.pulse = IO_READ(PI_BSD_DOM2_PWD_REG);
    __Dom2SpeedParam.pageSize = IO_READ(PI_BSD_DOM2_PGS_REG);
    __Dom2SpeedParam.relDuration = IO_READ(PI_BSD_DOM2_RLS_REG);
}

void __osInitialize_common() {
    u32 pifdata;

#ifdef _FINALROM
    __osFinalrom = TRUE;
#endif

    __osSetSR(__osGetSR() | SR_CU1);    //enable fpu
    __osSetFpcCsr(FPCSR_FS | FPCSR_EV); //flush denorm to zero, enable invalid operation
    __osSetWatchLo(0x4900000);

    while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata)) { //last byte of joychannel ram
        ;
    }
    while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8)) {
        ; //todo: magic contant
    }
    *(__osExceptionVector *)UT_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)XUT_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)ECC_VEC = __osExceptionPreamble;
    *(__osExceptionVector *)E_VEC = __osExceptionPreamble;
    osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    __createSpeedParam();
    osUnmapTLBAll();
    osMapTLBRdb();
    osClockRate = osClockRate * 3 / 4;

    if (osResetType == 0 ) { // cold reset
        bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
    }

    if (osTvType == OS_TV_PAL) {
        osViClock = VI_PAL_CLOCK;
    } else if (osTvType == OS_TV_MPAL) {
        osViClock = VI_MPAL_CLOCK;
    } else {
        osViClock = VI_NTSC_CLOCK;
    }

    // Wait until there are no RCP interrupts
    if (__osGetCause() & CAUSE_IP5) {
        while (TRUE) {
            ;
        }
    }

    IO_WRITE(AI_CONTROL_REG, AI_CONTROL_DMA_ON);
    IO_WRITE(AI_DACRATE_REG, AI_MAX_DAC_RATE - 1);
    IO_WRITE(AI_BITRATE_REG, AI_MAX_BIT_RATE - 1);
}

void __osInitialize_autodetect(void) {
#ifndef _FINALROM
    if (__checkHardware_msp()) {
        __osInitialize_msp();
    } else if (__checkHardware_kmc()) {
        __osInitialize_kmc();
    } else if (__checkHardware_isv()) {
        __osInitialize_isv();
    } else {
        __osInitialize_emu();
    }
#endif
}
