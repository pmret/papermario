#include "common.h"
#include "audio.h"

#define SWAP16(in, out) \
{ \
    s16 t = out; \
    out = in; \
    in = t; \
}

static void _init_lpfilter(AuLowPass* lp);
static Acmd* _saveBuffer(AuFX* fx, s16* oldPos, s32 buff, s32 count, Acmd* cmdBufPos);
static f32 func_80059BD4(AuDelay* delay, s32 rsdelta);

/*
* the following constant is derived from:
*
*      ratio = 2^(cents/1200)
*
* and therefore for hundredths of a cent
*                     x
*      ln(ratio) = ---------------
*              (120,000)/ln(2)
* where
*      120,000/ln(2) = 173123.40...
*/
#define CONVERT 173123.404906676

/*
 * WARNING: THE FOLLOWING CONSTANT MUST BE KEPT IN SYNC
 * WITH SCALING IN MICROCODE!!!
 */
#define SCALE 16384

// #define ms *(((s32)((f32)44.1))&~0x7)

s32 SMALL_ROOM_PARAMS[] = {
    /* sections    length */
        3,             11,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,       9,  9830,  -9830,      0,      0,      0,      0,
        3,       7,  3276,  -3276, 0x3FFF,      0,      0,      0,
        0,      10,  5000,      0,      0,      0,      0, 0x5000
};

s32 BIG_ROOM_PARAMS[] = {
    /* sections    length */
        4,             14,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,       9,  9830,  -9830,      0,      0,      0,      0,
        2,       6,  3276,  -3276, 0x3FFF,      0,      0,      0,
        9,      12,  3276,  -3276, 0x3FFF,      0,      0,      0,
        0,      13,  6000,      0,      0,      0,      0,  0x5000
};

// unused
s32 D_8007F0C0[] = {
    /* sections    length */
        4,             17,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,     11,   9830,  -9830,      0,      0,      0,      0,
        4,      9,   3276,  -3276, 0x3FFF,      0,      0,      0,
       11,     15,   3276,  -3276, 0x3FFF,      0,      0,      0,
        0,     16,   8000,      0,      0,      0,      0, 0x5000
};

s32 ECHO_PARAMS[] = {
    /* sections    length */
        1,             14,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,     13,  20000,      0, 0x7FFF,      0,      0, 0x7FFF
};

s32 CHORUS_PARAMS[] = {
    /* sections    length */
        1,              3,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,      1,  16384,      0, 0x7FFF,   7600,    700,      0
};

s32 FLANGE_PARAMS[] = {
    /* sections    length */
        1,              3,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,      1,      0, 0x5FFF, 0x7FFF,    380,    500,      0
};

s32 NULL_PARAMS[] = {
    /* sections    length */
        0,              0,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,      0,      0,      0,      0,      0,      0,      0
};

// up to four custom effects can be defined and installed here at runtime
s32* AU_FX_CUSTOM_PARAMS[] = {
    NULL_PARAMS, NULL_PARAMS, NULL_PARAMS, NULL_PARAMS
};

static void _init_lpfilter(AuLowPass* lp) {
    f64 attenuation;
    s16 timeConstant;
    u32 temp;
    s32 i;

    lp->first = 1;
    temp = lp->fc;
    timeConstant = temp;
    timeConstant = timeConstant >> 1;
    lp->fgain = SCALE - timeConstant;

    for (i = 0; i < ARRAY_COUNT(lp->fccoef) / 2; i++) {
        lp->fccoef[i] = 0;
    }

    lp->fccoef[8] = timeConstant;

    // ith value is 16384 * (timeConstant / 16384)^(i-7)
    // ex: i = 9 --> timeConstant^2 / 16384
    attenuation = ((f64)timeConstant / SCALE);
    for (i = 9; i < ARRAY_COUNT(lp->fccoef); i++) {
        attenuation *= ((f64)timeConstant /SCALE);
        lp->fccoef[i] = attenuation * SCALE;
    }
}

// definately AuFX, evidenced by call to func_8005904C
// this is n_alFxNew
/// @param effectType from enum AuEffectType
void func_80058E84(AuFX* fx, u8 effectType, ALHeap* heap) {
    AuDelay* delay;
    u16 i;

    // allocate space for 4 AuDelay
    fx->delays = alHeapAlloc(heap, AU_FX_DELAY_COUNT, sizeof(AuDelay));
    fx->base = alHeapAlloc(heap, AU_FX_LENGTH, sizeof(s16));

    for (i = 0; i < AU_FX_DELAY_COUNT; i++) {
        delay = &fx->delays[i];
        delay->resampler_2C = alHeapAlloc(heap, 1, sizeof(AuResampler));
        delay->resampler_2C->state = alHeapAlloc(heap, 1, sizeof(RESAMPLE_STATE));
        delay->lowpass_24 = alHeapAlloc(heap, 1, sizeof(AuLowPass));
        delay->lowpass_24->fstate = alHeapAlloc(heap, 1, sizeof(POLEF_STATE));
    }

    func_8005904C(fx, effectType);
}

// no known calls to this function
void func_80058F88(AlUnkKappa* kappa, ALHeap* heap) {
    kappa->unk_00 = alHeapAlloc(heap, 0x1420, sizeof(s16));
    kappa->lowpass_10 = alHeapAlloc(heap, 1, sizeof(AuLowPass));
    kappa->lowpass_10->fstate = alHeapAlloc(heap, 1, sizeof(POLEF_STATE));
    func_80059008(kappa, 0, 0, 0x5000);
}

// no known entry point to this function, called only by func_80058F88
void func_80059008(AlUnkKappa* kappa, s16 arg1, s16 arg2, s16 fc) {
    kappa->unk_06 = arg1;
    kappa->unk_08 = arg2;

    if (fc != 0) {
        kappa->lowpass_0C = kappa->lowpass_10;
        kappa->lowpass_0C->fc = fc;
        _init_lpfilter(kappa->lowpass_0C);
        return;
    }

    kappa->lowpass_0C = NULL;
}

// part of n_alFxNew, extracted to allow reseting fx without reallocating AuFX
void func_8005904C(AuFX* fx, u8 effectType) {
    s32* params;
    s32* clr;
    s32 i, j;
    clr = (s32*)fx->base;

    switch (effectType) {
        case AU_FX_SMALLROOM:
            params = SMALL_ROOM_PARAMS;
            break;
        case AU_FX_BIGROOM:
            params = BIG_ROOM_PARAMS;
            break;
        case AU_FX_ECHO:
            params = ECHO_PARAMS;
            break;
        case AU_FX_CHORUS:
            params = CHORUS_PARAMS;
            break;
        case AU_FX_FLANGE:
            params = FLANGE_PARAMS;
            break;
        case AU_FX_CUSTOM_0:
            params = AU_FX_CUSTOM_PARAMS[0];
            break;
        case AU_FX_CUSTOM_1:
            params = AU_FX_CUSTOM_PARAMS[1];
            break;
        case AU_FX_CUSTOM_2:
            params = AU_FX_CUSTOM_PARAMS[2];
            break;
        case AU_FX_CUSTOM_3:
            params = AU_FX_CUSTOM_PARAMS[3];
            break;
        case AU_FX_OTHER_BIGROOM:
            params = BIG_ROOM_PARAMS;
            break;
        default:
            params = NULL_PARAMS;
            break;
    }

    j = 0;
    fx->delayCount = params[j++];
    fx->length = params[j++] * AUDIO_SAMPLES;
    fx->input = fx->base;

    for (i = 0; i < AU_FX_LENGTH/2; i++) {
        *clr++ = 0;
    }

    for (i = 0; i < fx->delayCount; i++) {
        AuDelay* delay = &fx->delays[i];
        delay->input  = params[j++] * AUDIO_SAMPLES;
        delay->output = params[j++] * AUDIO_SAMPLES;
        delay->fbcoef = (u16) params[j++];
        delay->ffcoef = (u16) params[j++];
        delay->gain   = (u16) params[j++];

        if (params[j]) {
            delay->rsinc = (2.0 * (params[j++] / 1000.0f)) / gActiveSynDriverPtr->outputRate;
            delay->rsgain = ((f32)params[j++] / CONVERT) * (delay->output - delay->input);
            delay->rsval = 1.0f;
            delay->rsdelta = 0.0f;
            delay->resampler_28 = delay->resampler_2C;
            delay->resampler_2C->delta = 0.0;
            delay->resampler_28->first = 1;
        } else {
            delay->resampler_28 = NULL;
            j++;
            j++;
        }

        if (params[j]) {
            delay->lowpass_20 = delay->lowpass_24;
            delay->lowpass_20->fc = params[j++];
            _init_lpfilter(delay->lowpass_20);
        } else {
            delay->lowpass_20 = NULL;
            j++;
        }
    }
}

// au_pull_fx -- based on alFxPull
// AuFX from gSynDriverPtr

Acmd* au_pull_fx(AuFX* fx, Acmd* ptr, s16 outputBuf, s16 arg3) {
    Acmd* cmdBufPos = ptr;
    s16 delayIdx;

    s16* inPtr;
    s16* outPtr;

    s16 buff1 = arg3 + N_AL_TEMP_0;
    s16 buff2 = arg3 + N_AL_TEMP_1;
    s16 rbuff = arg3 + N_AL_TEMP_2;
    s16* prevOutPtr = 0;
    s16 outputBufCopy = outputBuf;

    n_aSaveBuffer(cmdBufPos++, FIXED_SAMPLE<<1, outputBuf, osVirtualToPhysical(fx->input));
    aClearBuffer(cmdBufPos++, outputBuf, FIXED_SAMPLE<<1);

    for (delayIdx = 0; delayIdx < fx->delayCount; delayIdx++) {
        AuDelay* delay = &fx->delays[delayIdx];
        f32 fUnityPitch = UNITY_PITCH;

        inPtr = &fx->input[-delay->input];
        if (inPtr < fx->base) {
            inPtr += fx->length;
        }
        outPtr = &fx->input[-delay->output];
        if (outPtr < fx->base) {
            outPtr += fx->length;
        }
        if (inPtr == prevOutPtr) {
            SWAP16(buff1, buff2);
        } else {
            n_aLoadBuffer(cmdBufPos++, FIXED_SAMPLE<<1, buff1, osVirtualToPhysical(inPtr));
        }
        if (delay->resampler_28) {
            // modified _n_loadOutputBuffer
            s32 ratio;
            s32 length, count;
            f32 delta, fratio, fincount;
            s32 ramAlign;
            s16 tmp;
            s16* rsOutPtr;

            length = delay->output - delay->input;
            delta = func_80059BD4(delay, AUDIO_SAMPLES);
            delta /= length;
            delta = (s32)(delta * fUnityPitch);
            delta = delta / UNITY_PITCH;
            fratio = 1.0 - delta;
            fincount = delay->resampler_28->delta + (fratio * AUDIO_SAMPLES);
            count = (s32) fincount;
            delay->resampler_28->delta = fincount - count;

            rsOutPtr = &fx->input[-(delay->output - delay->rsdelta)];
            ramAlign = ((s32) rsOutPtr & 7) >> 1;

            rsOutPtr -= ramAlign;
            if (rsOutPtr < fx->base) {
                rsOutPtr += fx->length;
            }

            cmdBufPos = _saveBuffer(fx, rsOutPtr, rbuff, count + ramAlign, cmdBufPos);
            ratio = fratio * fUnityPitch;

            tmp = buff2 >> 8;
            n_aResample(cmdBufPos++, osVirtualToPhysical(delay->resampler_28->state),
                delay->resampler_28->first, ratio, rbuff + (ramAlign<<1), tmp);

            delay->resampler_28->first = 0;
            delay->rsdelta += count - AUDIO_SAMPLES;
        } else {
            n_aLoadBuffer(cmdBufPos++, FIXED_SAMPLE<<1, buff2, osVirtualToPhysical(outPtr));
        }
        if (delay->ffcoef) {
            aMix(cmdBufPos++, 0, (u16)delay->ffcoef, buff1, buff2);

            if (delay->resampler_28 == NULL && delay->lowpass_20 == NULL) {
                n_aSaveBuffer(cmdBufPos++, FIXED_SAMPLE<<1, buff2, osVirtualToPhysical(outPtr));
            }
        }
        if (delay->fbcoef) {
            aMix(cmdBufPos++, 0, (u16)delay->fbcoef, buff2, buff1);
            n_aSaveBuffer(cmdBufPos++, FIXED_SAMPLE<<1, buff1, osVirtualToPhysical(inPtr));
        }
        if (delay->lowpass_20 != NULL) {
            // modified _n_filterBuffer
            s16 tmp = buff2 >> 8;
            n_aLoadADPCM(cmdBufPos++, 32, osVirtualToPhysical(delay->lowpass_20->fccoef));
            n_aPoleFilter(cmdBufPos++, delay->lowpass_20->first, delay->lowpass_20->fgain, tmp, osVirtualToPhysical(delay->lowpass_20->fstate));
            delay->lowpass_20->first = 0;
        }
        if (!delay->resampler_28) {
            n_aSaveBuffer(cmdBufPos++, FIXED_SAMPLE<<1, buff2, osVirtualToPhysical(outPtr));
        }
        if (delay->gain) {
            aMix(cmdBufPos++, 0, (u16)delay->gain, buff2, outputBufCopy);
        }
        prevOutPtr = &fx->input[delay->output];
    }

    fx->input += AUDIO_SAMPLES;
    if (fx->input >= &fx->base[fx->length]) {
        fx->input = fx->base;
    }
    return cmdBufPos;
}


#define INPUT_PARAM         0
#define OUTPUT_PARAM        1
#define FBCOEF_PARAM        2
#define FFCOEF_PARAM        3
#define GAIN_PARAM          4
#define CHORUSRATE_PARAM    5
#define CHORUSDEPTH_PARAM   6
#define LPFILT_PARAM        7

// based on alFxParamHdl
s32 au_fx_param_hdl(AuFX* fx, s16 index, s16 paramID, s32 value) {
    switch (paramID) {
    case INPUT_PARAM:
        fx->delays[index].input = value & 0xFFFFFFF8;
        break;
    case OUTPUT_PARAM:
        fx->delays[index].output = value & 0xFFFFFFF8;
        break;
    case FFCOEF_PARAM:
        fx->delays[index].ffcoef = value;
        break;
    case FBCOEF_PARAM:
        fx->delays[index].fbcoef = value;
        break;
    case GAIN_PARAM:
        fx->delays[index].gain = value;
        break;
    case CHORUSRATE_PARAM:
        fx->delays[index].rsinc = (2.0 * (value / 1000.0f)) / gActiveSynDriverPtr->outputRate;
        break;
    case CHORUSDEPTH_PARAM:
        fx->delays[index].rsgain = ((f32)value / CONVERT) * (fx->delays[index].output - fx->delays[index].input);
        break;
    case LPFILT_PARAM:
        if (fx->delays[index].lowpass_20) {
            fx->delays[index].lowpass_20->fc = value;
            _init_lpfilter(fx->delays[index].lowpass_20);
        }
        break;
    }
    return 0;
}

// TODO: _n_loadBuffer
static Acmd* _saveBuffer(AuFX* fx, s16* oldPos, s32 buf, s32 count, Acmd* cmdBufPos) {
    Acmd *ptr = cmdBufPos;
    s16* newPos = oldPos + count;
    s16* delayEnd = &fx->base[fx->length];

    if (delayEnd < newPos) {
        s32 before = delayEnd - oldPos;
        s32 after = newPos - delayEnd;
        n_aLoadBuffer(ptr++, before<<1, buf, osVirtualToPhysical(oldPos));
        n_aLoadBuffer(ptr++, after<<1, buf + (before<<1), osVirtualToPhysical(fx->base));
    } else {
        n_aLoadBuffer(ptr++, count<<1, buf, osVirtualToPhysical(oldPos));
    }

    return ptr;
}

// updates rsval, producing a triangle wave between ±1
// time delta specified in samples
//TODO rename to _updateTriWaveModulation
static f32 func_80059BD4(AuDelay* delay, s32 rsdelta) {
    f32 result;

    delay->rsval += delay->rsinc * rsdelta;
    delay->rsval = (delay->rsval > 2.0) ? delay->rsval - 4.0 : delay->rsval;

    result = delay->rsval;
    if (result < 0.0f) {
        result = -result;
    }

    result = result - 1.0;

    return delay->rsgain * result;
}
