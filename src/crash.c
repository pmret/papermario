#include "common.h"
#include "stdlib/stdarg.h"

typedef struct {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ char stack[0x800];
    /* 0x9B0 */ OSMesgQueue queue;
    /* 0x9C8 */ OSMesg mesg;
    /* 0x9CC */ u16* frameBuf;
    /* 0x9D0 */ u16 width;
    /* 0x9D2 */ u16 height;
} CrashScreen; // size unknown

extern CrashScreen gCrashScreen; // bss, externed for now
// D_80077210
s32 D_80077210[] = {
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF29FFFF,
    0xFF2BFFFF, 0x2526FF2A, 0xFF272CFF, 0x00010203, 0x04050607, 0x080924FF, 0xFFFFFF28, 0xFF0A0B0C, 0x0D0E0F10,
    0x11121314, 0x15161718, 0x191A1B1C, 0x1D1E1F20, 0x212223FF, 0xFFFFFFFF, 0xFF0A0B0C, 0x0D0E0F10, 0x11121314,
    0x15161718, 0x191A1B1C, 0x1D1E1F20, 0x212223FF, 0xFFFFFFFF,
};

s32 D_80077290[] = {
    0x70871C30, 0x8988A250, 0x88808290, 0x88831C90, 0x888402F8, 0x88882210, 0x71CF9C10, 0xF9CF9C70, 0x8228A288,
    0xF200A288, 0x0BC11C78, 0x0A222208, 0x8A222288, 0x71C21C70, 0x23C738F8, 0x5228A480, 0x8A282280, 0x8BC822F0,
    0xFA282280, 0x8A28A480, 0x8BC738F8, 0xF9C89C08, 0x82288808, 0x82088808, 0xF2EF8808, 0x82288888, 0x82288888,
    0x81C89C70, 0x8A08A270, 0x920DA288, 0xA20AB288, 0xC20AAA88, 0xA208A688, 0x9208A288, 0x8BE8A270, 0xF1CF1CF8,
    0x8A28A220, 0x8A28A020, 0xF22F1C20, 0x82AA0220, 0x82492220, 0x81A89C20, 0x8A28A288, 0x8A28A288, 0x8A289488,
    0x8A2A8850, 0x894A9420, 0x894AA220, 0x70852220, 0xF8011000, 0x08020800, 0x10840400, 0x20040470, 0x40840400,
    0x80020800, 0xF8011000, 0x70800000, 0x88822200, 0x08820400, 0x108F8800, 0x20821000, 0x00022200, 0x20800020,
    0x00000000,
};

char* gFaultCauses[18] = {
    "Interrupt",
    "TLB modification",
    "TLB exception on load",
    "TLB exception on store",
    "Address error on load",
    "Address error on store",
    "Bus error on inst.",
    "Bus error on data",
    "System call exception",
    "Breakpoint exception",
    "Reserved instruction",
    "Coprocessor unusable",
    "Arithmetic overflow",
    "Trap exception",
    "Virtual coherency on inst.",
    "Floating point exception",
    "Watchpoint exception",
    "Virtual coherency on data",
};

char* gFPCSRFaultCauses[6] = {
    "Unimplemented operation",
    "Invalid operation",
    "Division by zero",
    "Overflow",
    "Underflow",
    "Inexact operation",
};

void crash_screen_sleep(s32 ms) {
    u64 cycles = ms * 1000LL * 46875000LL / 1000000ULL;

    osSetTime(0);

    while (osGetTime() < cycles) {
        // wait
    }
}

void crash_screen_draw_rect(s32 x, s32 y, s32 width, s32 height) {
    u16* ptr;
    s32 i;
    s32 j;

    if (gCrashScreen.width == 640) {
        x <<= 1;
        y <<= 1;
        width <<= 1;
        height <<= 1;
    }

    ptr = gCrashScreen.frameBuf + gCrashScreen.width * y + x;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *ptr = ((*ptr & 0xE738) >> 2) | 1;
            ptr++;
        }

        ptr += gCrashScreen.width - width;
    }
}

void func_8002C054(s32 x, s32 y, s32 character) {
    s32 shift = ((character % 5) * 6);
    u16 width = gCrashScreen.width;
    const u32* data = &D_80077290[character / 5 * 7];
    s32 i;
    s32 j;

    if (width == 320) {
        u16* ptr = gCrashScreen.frameBuf + (gCrashScreen.width) * y + x;

        for (i = 0; i < 7; i++) {
            u32 bit = 0x80000000U >> shift;
            u32 rowMask = *data++;

            for (j = 0; j < 6; j++) {
                *ptr++ = (bit & rowMask) ? 0xFFFF : 1;
                bit >>= 1;
            }

            ptr += gCrashScreen.width - 6;
        }
    } else if (width == 640) {
        u16* ptr = gCrashScreen.frameBuf + (y * 0x500) + (x * 2);

        for (i = 0; i < 7; i++) {
            u32 bit = 0x80000000U >> shift;
            u32 rowMask = *data++;

            for (j = 0; j < 6; j++) {
                u16 temp = (bit & rowMask) ? 0xFFFF : 1;

                ptr[0] = temp;
                ptr[1] = temp;
                ptr[640] = temp;
                ptr[641] = temp;
                ptr += 2;
                bit >>= 1;
            }

            ptr += (0x9E8 / 2);
        }
    }
}

u8* crash_screen_copy_to_buf(u8* dest, const u8* src, u32 size) {
    memcpy(dest, src, size);
    return dest + size;
}

void crash_screen_printf(s32 x, s32 y, const char* fmt, ...) {
    u8* ptr;
    u32 glyph;
    s32 size;
    u8 buf[0x100];
    va_list args;
    va_start(args, fmt);

    size = _Printf(crash_screen_copy_to_buf, buf, fmt, args);

    if (size > 0) {
        ptr = buf;

        while (size > 0) {
            u8* chartoglyph = D_80077210;

            glyph = chartoglyph[*ptr & 0x7F];

            if (glyph != 0xFF) {
                func_8002C054(x, y, glyph);
            }

            x += 6;
            size--;
            ptr++;
        }
    }

    va_end(args);
}

void crash_screen_print_fpr(s32 x, s32 y, s32 regNum, void* addr) {
    u32 bits = *(u32*)addr;
    s32 exponent = ((bits & 0x7F800000U) >> 0x17) - 0x7F;

    if ((exponent >= -0x7E && exponent <= 0x7F) || bits == 0) {
        crash_screen_printf(x, y, "F%02d:%+.3e", regNum, *(f32*)addr);
    } else {
        crash_screen_printf(x, y, "F%02d:---------", regNum);
    }
}

void crash_screen_print_fpcsr(u32 value) {
    s32 i;
    u32 flag = 0x20000;

    crash_screen_printf(30, 155, "FPCSR:%08XH", value);

    for (i = 0; i < 6;) {
        if (value & flag) {
            crash_screen_printf(132, 155, "(%s)", gFPCSRFaultCauses[i]);
            break;
            do {} while (0);
        }
        i++;
        flag >>= 1;
    }
}

void crash_screen_draw(OSThread* faultedThread) {
    s16 causeIndex;
    __OSThreadContext* ctx;

    ctx = &faultedThread->context;
    causeIndex = ((faultedThread->context.cause >> 2) & 0x1F);

    if (causeIndex == 23) {
        causeIndex = 16;
    }

    if (causeIndex == 31) {
        causeIndex = 17;
    }

    osWritebackDCacheAll();

    crash_screen_draw_rect(0x19, 0x14, 0x10E, 0x19);
    crash_screen_printf(0x1E, 0x19, "THREAD:%d  (%s)", faultedThread->id, gFaultCauses[causeIndex]);
    crash_screen_printf(0x1E, 0x23, "PC:%08XH   SR:%08XH   VA:%08XH", ctx->pc, ctx->sr, ctx->badvaddr);

    crash_screen_sleep(2000);

    osViBlack(0);
    osViRepeatLine(0);
    osViSwapBuffer(gCrashScreen.frameBuf);

    crash_screen_draw_rect(0x19, 0x2D, 0x10E, 0xB9);

    crash_screen_printf(0x1E, 0x32, "AT:%08XH   V0:%08XH   V1:%08XH", (u32)ctx->at, (u32)ctx->v0, (u32)ctx->v1);
    crash_screen_printf(0x1E, 0x3C, "A0:%08XH   A1:%08XH   A2:%08XH", (u32)ctx->a0, (u32)ctx->a1, (u32)ctx->a2);
    crash_screen_printf(0x1E, 0x46, "A3:%08XH   T0:%08XH   T1:%08XH", (u32)ctx->a3, (u32)ctx->t0, (u32)ctx->t1);
    crash_screen_printf(0x1E, 0x50, "T2:%08XH   T3:%08XH   T4:%08XH", (u32)ctx->t2, (u32)ctx->t3, (u32)ctx->t4);
    crash_screen_printf(0x1E, 0x5A, "T5:%08XH   T6:%08XH   T7:%08XH", (u32)ctx->t5, (u32)ctx->t6, (u32)ctx->t7);
    crash_screen_printf(0x1E, 0x64, "S0:%08XH   S1:%08XH   S2:%08XH", (u32)ctx->s0, (u32)ctx->s1, (u32)ctx->s2);
    crash_screen_printf(0x1E, 0x6E, "S3:%08XH   S4:%08XH   S5:%08XH", (u32)ctx->s3, (u32)ctx->s4, (u32)ctx->s5);
    crash_screen_printf(0x1E, 0x78, "S6:%08XH   S7:%08XH   T8:%08XH", (u32)ctx->s6, (u32)ctx->s7, (u32)ctx->t8);
    crash_screen_printf(0x1E, 0x82, "T9:%08XH   GP:%08XH   SP:%08XH", (u32)ctx->t9, (u32)ctx->gp, (u32)ctx->sp);
    crash_screen_printf(0x1E, 0x8C, "S8:%08XH   RA:%08XH", (u32)ctx->s8, (u32)ctx->ra);

    crash_screen_print_fpcsr(ctx->fpcsr);

    crash_screen_print_fpr(0x1E, 0xAA, 0, &ctx->fp0.f.f_even);
    crash_screen_print_fpr(0x78, 0xAA, 2, &ctx->fp2.f.f_even);
    crash_screen_print_fpr(0xD2, 0xAA, 4, &ctx->fp4.f.f_even);
    crash_screen_print_fpr(0x1E, 0xB4, 6, &ctx->fp6.f.f_even);
    crash_screen_print_fpr(0x78, 0xB4, 8, &ctx->fp8.f.f_even);
    crash_screen_print_fpr(0xD2, 0xB4, 0xA, &ctx->fp10.f.f_even);
    crash_screen_print_fpr(0x1E, 0xBE, 0xC, &ctx->fp12.f.f_even);
    crash_screen_print_fpr(0x78, 0xBE, 0xE, &ctx->fp14.f.f_even);
    crash_screen_print_fpr(0xD2, 0xBE, 0x10, &ctx->fp16.f.f_even);
    crash_screen_print_fpr(0x1E, 0xC8, 0x12, &ctx->fp18.f.f_even);
    crash_screen_print_fpr(0x78, 0xC8, 0x14, &ctx->fp20.f.f_even);
    crash_screen_print_fpr(0xD2, 0xC8, 0x16, &ctx->fp22.f.f_even);
    crash_screen_print_fpr(0x1E, 0xD2, 0x18, &ctx->fp24.f.f_even);
    crash_screen_print_fpr(0x78, 0xD2, 0x1A, &ctx->fp26.f.f_even);
    crash_screen_print_fpr(0xD2, 0xD2, 0x1C, &ctx->fp28.f.f_even);
    crash_screen_print_fpr(0x1E, 0xDC, 0x1E, &ctx->fp30.f.f_even);

    crash_screen_sleep(500);

    // all of these null terminators needed to pad the rodata section for this file
    // can potentially fix this problem in another way?
    crash_screen_printf(0xD2, 0x8C, "MM:%08XH\0\0\0\0\0\0\0\0", *(u32*)ctx->pc);
}

OSThread* crash_screen_get_faulted_thread(void) {
    OSThread* iter = osGetActiveQueue();

    while (iter->priority != -1) {
        if (iter->priority > 0 && iter->priority < 0x7F && (iter->flags & 3)) {
            return iter;
        }
        iter = iter->tlnext;
    }

    return NULL;
}

void crash_screen_thread_entry(void* unused) {
    OSMesg mesg;
    OSThread* faultedThread;

    osSetEventMesg(OS_EVENT_CPU_BREAK, &gCrashScreen.queue, (OSMesg)1);
    osSetEventMesg(OS_EVENT_FAULT, &gCrashScreen.queue, (OSMesg)2);

    do {
        osRecvMesg(&gCrashScreen.queue, &mesg, 1);
        faultedThread = crash_screen_get_faulted_thread();
    } while (faultedThread == NULL);

    osStopThread(faultedThread);
    crash_screen_draw(faultedThread);

    while (TRUE) {}
}

void crash_screen_set_draw_info(u16* frameBufPtr, s16 width, s16 height) {
    gCrashScreen.frameBuf = (u16*)((u32)frameBufPtr | 0xA0000000);
    gCrashScreen.width = width;
    gCrashScreen.height = height;
}

void crash_screen_init(void) {
    gCrashScreen.width = SCREEN_WIDTH;
    gCrashScreen.height = 16;
    gCrashScreen.frameBuf = (u16*)((osMemSize | 0xA0000000) - ((SCREEN_WIDTH * SCREEN_HEIGHT) * 2));
    osCreateMesgQueue(&gCrashScreen.queue, &gCrashScreen.mesg, 1);
    osCreateThread(&gCrashScreen.thread, 2, crash_screen_thread_entry, NULL,
                   gCrashScreen.stack + sizeof(gCrashScreen.stack), 0x80);
    osStartThread(&gCrashScreen.thread);
}

// unused
// almost the same as crash_screen_printf but it has a call to crash_screen_draw_rect
void func_8002C94C(s16 x, s16 y, const char* fmt, ...) {
    u8* ptr;
    u32 glyph;
    s32 size;
    u8 buf[0x100];
    va_list args;

    va_start(args, fmt);

    size = _Printf(crash_screen_copy_to_buf, buf, fmt, args);

    if (size > 0) {
        crash_screen_draw_rect(x - 6, y - 6, (size + 2) * 6, 19);
        ptr = buf;

        while (size > 0) {
            u8* chartoglyph = D_80077210;

            glyph = chartoglyph[*ptr & 0x7F];

            if (glyph != 0xFF) {
                func_8002C054(x, y, glyph);
            }

            x += 6;
            size--;
            ptr++;
        }
    }

    va_end(args);
}
