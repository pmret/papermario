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

extern CrashScreen gCrashScreen; // bss, externed for now until issues are figured out

u8 gCrashScreencharToGlyph[128] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 41, -1, -1, -1, 43, -1, -1, 37, 38, -1, 42,
    -1, 39, 44, -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  36, -1, -1, -1, -1, 40, -1, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, -1,
};

u32 gCrashScreenFont[] = {
    0x70871C30, 0x8988A250, 0x88808290, 0x88831C90, 0x888402F8, 0x88882210, 0x71CF9C10, 0xF9CF9C70, 0x8228A288,
    0xF200A288, 0x0BC11C78, 0x0A222208, 0x8A222288, 0x71C21C70, 0x23C738F8, 0x5228A480, 0x8A282280, 0x8BC822F0,
    0xFA282280, 0x8A28A480, 0x8BC738F8, 0xF9C89C08, 0x82288808, 0x82088808, 0xF2EF8808, 0x82288888, 0x82288888,
    0x81C89C70, 0x8A08A270, 0x920DA288, 0xA20AB288, 0xC20AAA88, 0xA208A688, 0x9208A288, 0x8BE8A270, 0xF1CF1CF8,
    0x8A28A220, 0x8A28A020, 0xF22F1C20, 0x82AA0220, 0x82492220, 0x81A89C20, 0x8A28A288, 0x8A28A288, 0x8A289488,
    0x8A2A8850, 0x894A9420, 0x894AA220, 0x70852220, 0xF8011000, 0x08020800, 0x10840400, 0x20040470, 0x40840400,
    0x80020800, 0xF8011000, 0x70800000, 0x88822200, 0x08820400, 0x108F8800, 0x20821000, 0x00022200, 0x20800020,
    0x00000000,
};

const char* gFaultCauses[18] = {
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

const char* gFPCSRFaultCauses[6] = {
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

void crash_screen_draw_glyph(s32 x, s32 y, s32 glyph) {
    s32 shift = ((glyph % 5) * 6);
    u16 width = gCrashScreen.width;
    const u32* data = &gCrashScreenFont[glyph / 5 * 7];
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

void* crash_screen_copy_to_buf(void* dest, const char* src, u32 size) {
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
            u8* charToGlyph = gCrashScreencharToGlyph;

            glyph = charToGlyph[*ptr & 0x7F];

            if (glyph != 0xFF) {
                crash_screen_draw_glyph(x, y, glyph);
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

    crash_screen_draw_rect(25, 20, 270, 25);
    crash_screen_printf(30, 25, "THREAD:%d  (%s)", faultedThread->id, gFaultCauses[causeIndex]);
    crash_screen_printf(30, 35, "PC:%08XH   SR:%08XH   VA:%08XH", ctx->pc, ctx->sr, ctx->badvaddr);

    crash_screen_sleep(2000);

    osViBlack(0);
    osViRepeatLine(0);
    osViSwapBuffer(gCrashScreen.frameBuf);

    crash_screen_draw_rect(25, 45, 270, 185);

    crash_screen_printf(30, 50, "AT:%08XH   V0:%08XH   V1:%08XH", (u32)ctx->at, (u32)ctx->v0, (u32)ctx->v1);
    crash_screen_printf(30, 60, "A0:%08XH   A1:%08XH   A2:%08XH", (u32)ctx->a0, (u32)ctx->a1, (u32)ctx->a2);
    crash_screen_printf(30, 70, "A3:%08XH   T0:%08XH   T1:%08XH", (u32)ctx->a3, (u32)ctx->t0, (u32)ctx->t1);
    crash_screen_printf(30, 80, "T2:%08XH   T3:%08XH   T4:%08XH", (u32)ctx->t2, (u32)ctx->t3, (u32)ctx->t4);
    crash_screen_printf(30, 90, "T5:%08XH   T6:%08XH   T7:%08XH", (u32)ctx->t5, (u32)ctx->t6, (u32)ctx->t7);
    crash_screen_printf(30, 100, "S0:%08XH   S1:%08XH   S2:%08XH", (u32)ctx->s0, (u32)ctx->s1, (u32)ctx->s2);
    crash_screen_printf(30, 110, "S3:%08XH   S4:%08XH   S5:%08XH", (u32)ctx->s3, (u32)ctx->s4, (u32)ctx->s5);
    crash_screen_printf(30, 120, "S6:%08XH   S7:%08XH   T8:%08XH", (u32)ctx->s6, (u32)ctx->s7, (u32)ctx->t8);
    crash_screen_printf(30, 130, "T9:%08XH   GP:%08XH   SP:%08XH", (u32)ctx->t9, (u32)ctx->gp, (u32)ctx->sp);
    crash_screen_printf(30, 140, "S8:%08XH   RA:%08XH", (u32)ctx->s8, (u32)ctx->ra);

    crash_screen_print_fpcsr(ctx->fpcsr);

    crash_screen_print_fpr(30, 170, 0, &ctx->fp0.f.f_even);
    crash_screen_print_fpr(120, 170, 2, &ctx->fp2.f.f_even);
    crash_screen_print_fpr(210, 170, 4, &ctx->fp4.f.f_even);
    crash_screen_print_fpr(30, 180, 6, &ctx->fp6.f.f_even);
    crash_screen_print_fpr(120, 180, 8, &ctx->fp8.f.f_even);
    crash_screen_print_fpr(210, 180, 10, &ctx->fp10.f.f_even);
    crash_screen_print_fpr(30, 190, 12, &ctx->fp12.f.f_even);
    crash_screen_print_fpr(120, 190, 14, &ctx->fp14.f.f_even);
    crash_screen_print_fpr(210, 190, 16, &ctx->fp16.f.f_even);
    crash_screen_print_fpr(30, 200, 18, &ctx->fp18.f.f_even);
    crash_screen_print_fpr(120, 200, 20, &ctx->fp20.f.f_even);
    crash_screen_print_fpr(210, 200, 22, &ctx->fp22.f.f_even);
    crash_screen_print_fpr(30, 210, 24, &ctx->fp24.f.f_even);
    crash_screen_print_fpr(120, 210, 26, &ctx->fp26.f.f_even);
    crash_screen_print_fpr(210, 210, 28, &ctx->fp28.f.f_even);
    crash_screen_print_fpr(30, 220, 30, &ctx->fp30.f.f_even);

    crash_screen_sleep(500);

    // all of these null terminators needed to pad the rodata section for this file
    // can potentially fix this problem in another way?
    crash_screen_printf(210, 140, "MM:%08XH\0\0\0\0\0\0\0\0", *(u32*)ctx->pc);
}

OSThread* crash_screen_get_faulted_thread(void) {
    OSThread* thread = osGetActiveQueue();

    while (thread->priority != -1) {
        if (thread->priority > 0 && thread->priority < 0x7F && (thread->flags & 3)) {
            return thread;
        }

        thread = thread->tlnext;
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
void crash_screen_printf_with_bg(s16 x, s16 y, const char* fmt, ...) {
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
            u8* charToGlyph = gCrashScreencharToGlyph;

            glyph = charToGlyph[*ptr & 0x7F];

            if (glyph != 0xFF) {
                crash_screen_draw_glyph(x, y, glyph);
            }

            x += 6;
            size--;
            ptr++;
        }
    }

    va_end(args);
}
