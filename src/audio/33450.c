#include "common.h"
#include "audio.h"

// values for cosine from 0 to pi/2 multiplied by 32767
// called n_eqpower in libultra
s16 AuEqPower[128] = {
    32767, 32764, 32757, 32744, 32727, 32704, 32677, 32644,
    32607, 32564, 32517, 32464, 32407, 32344, 32277, 32205,
    32127, 32045, 31958, 31866, 31770, 31668, 31561, 31450,
    31334, 31213, 31087, 30957, 30822, 30682, 30537, 30388,
    30234, 30075, 29912, 29744, 29572, 29395, 29214, 29028,
    28838, 28643, 28444, 28241, 28033, 27821, 27605, 27385,
    27160, 26931, 26698, 26461, 26220, 25975, 25726, 25473,
    25216, 24956, 24691, 24423, 24151, 23875, 23596, 23313,
    23026, 22736, 22442, 22145, 21845, 21541, 21234, 20924,
    20610, 20294, 19974, 19651, 19325, 18997, 18665, 18331,
    17993, 17653, 17310, 16965, 16617, 16266, 15913, 15558,
    15200, 14840, 14477, 14113, 13746, 13377, 13006, 12633,
    12258, 11881, 11503, 11122, 10740, 10357, 9971,  9584,
    9196,  8806,  8415,  8023,  7630,  7235,  6839,  6442,
    6044,  5646,  5246,  4845,  4444,  4042,  3640,  3237,
    2833,  2429,  2025,  1620,  1216,  810,   405,   0
};

Acmd* _decodeChunk(Acmd* cmdBufPos, AuLoadFilter* arg1, s32 count, s32 size, s16 arg4, s16 arg5, s32 flags);
s16 func_80058C6C(f64 arg0, f64 arg1, s32 arg4, u16* arg5);

// n_alAdpcmPull
INCLUDE_ASM(s32, "audio/33450", func_80058050);

Acmd* _decodeChunk(Acmd* cmdBufPos, AuLoadFilter* arg1, s32 tsam, s32 nbytes, s16 output, s16 input, s32 flags) {
    s32 endAddr;
    s32 endAlign;
    s32 paddedSize;
    
    if (nbytes > 0) {
        endAddr = arg1->dc_dmaFunc(arg1->wavTable, nbytes, arg1->dc_dmaState, arg1->instrument->unk_25); // ALDMAproc has an extra arg added
        endAlign = endAddr & 7;
        nbytes += endAlign;
        paddedSize = nbytes + 8 - (nbytes & 7);
        n_aLoadBuffer(cmdBufPos++, paddedSize, input, endAddr - endAlign);
    } else {
        endAlign = 0;
    }
    
    if (flags & 2) {
        aSetLoop(cmdBufPos++, (s32) arg1->dc_lstate & 0x1FFFFFFF);
    }

    n_aADPCMdec(cmdBufPos++, arg1->dc_state, flags, tsam << 1, endAlign, output);
    
    arg1->unk_30 = 0;
    return cmdBufPos;
}

s16 func_80058C6C(f64 arg0, f64 arg1, s32 arg4, u16* arg5) {
    f64 inv;
    f64 a;
    f64 b;
    s16 c_int;
    s16 a_int;
    s16 b_int;

    if (arg4 == 0) {
        if (arg1 >= arg0) {
            *arg5 = 0xFFFF;
            return 0x7FFF;
        } else {
            *arg5 = 0;
            return 0;
        }
    }
    inv = (1.0 / arg4);
    
    if (arg1 < 1.0) {
        arg1 = 1.0;
    }
    if (arg0 <= 0.0) {
        arg0 = 1.0;
    }

    a = (arg1 - arg0) * inv * 8.0;
    a_int = a;
    c_int = (a_int - 1);
    
    b = (a - a_int) + 1.0;
    b_int = b;
    c_int += b_int;
    
    *arg5 = (b - b_int) * 0xFFFF;
    return c_int;
}
