#include "common.h"
#include "audio.h"
#include "audio/core.h"

#define SWAP16(in, out) \
{ \
    s16 t = out; \
    out = in; \
    in = t; \
}

static Acmd* _loadDelayLineBuffer(AuFX* fx, s16* oldPos, s32 buff, s32 count, Acmd* cmdBufPos);
static f32 updateTriangleModulation(AuDelay* delay, s32 rsdelta);

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

#define SCALE 16384

#define INPUT_PARAM         0
#define OUTPUT_PARAM        1
#define FBCOEF_PARAM        2
#define FFCOEF_PARAM        3
#define GAIN_PARAM          4
#define CHORUSRATE_PARAM    5
#define CHORUSDEPTH_PARAM   6
#define LPFILT_PARAM        7

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

static void _init_lpfilter(AuLowPass* filter) {
    f64 attenuation;
    s16 timeConstant;
    u32 temp;
    s32 i;

    filter->first = 1;
    temp = filter->fc;
    timeConstant = temp;
    timeConstant = timeConstant >> 1;
    filter->fgain = SCALE - timeConstant;

    for (i = 0; i < 8; i++) {
        filter->fccoef[i] = 0;
    }

    filter->fccoef[8] = timeConstant;

    // ith value is 16384 * (timeConstant / 16384)^(i-7)
    // ex: i = 9 --> timeConstant^2 / 16384
    attenuation = ((f64)timeConstant / SCALE);
    for (i = 9; i < ARRAY_COUNT(filter->fccoef); i++) {
        attenuation *= ((f64)timeConstant / SCALE);
        filter->fccoef[i] = attenuation * SCALE;
    }
}

/// @param effectType from enum AuEffectType
void au_fx_create(AuFX* fx, u8 effectType, ALHeap* heap) {
    AuDelay* delay;
    u16 i;

    // allocate space for 4 AuDelay
    fx->delays = alHeapAlloc(heap, AU_FX_MAX_TAPS, sizeof(AuDelay));
    fx->base = alHeapAlloc(heap, AU_FX_LENGTH, sizeof(s16));

    for (i = 0; i < AU_FX_MAX_TAPS; i++) {
        delay = &fx->delays[i];
        delay->resamplerTemplate = alHeapAlloc(heap, 1, sizeof(AuResampler));
        delay->resamplerTemplate->state = alHeapAlloc(heap, 1, sizeof(RESAMPLE_STATE));
        delay->lowpassTemplate = alHeapAlloc(heap, 1, sizeof(AuLowPass));
        delay->lowpassTemplate->fstate = alHeapAlloc(heap, 1, sizeof(POLEF_STATE));
    }

    au_fx_load_preset(fx, effectType);
}

// no known calls to this function
void au_filter_create(AuFilter* filter, ALHeap* heap) {
    filter->base = alHeapAlloc(heap, AU_FILTER_LENGTH, sizeof(s16));
    filter->lowpassTemplate = alHeapAlloc(heap, 1, sizeof(AuLowPass));
    filter->lowpassTemplate->fstate = alHeapAlloc(heap, 1, sizeof(POLEF_STATE));
    au_filter_init(filter, 0, 0, 0x5000);
}

// no known entry point to this function, called only by au_filter_create
void au_filter_init(AuFilter* filter, s16 arg1, s16 arg2, s16 cutoff) {
    filter->unused_06 = arg1;
    filter->unused_08 = arg2;

    if (cutoff != 0) {
        filter->activeLowpass = filter->lowpassTemplate;
        filter->activeLowpass->fc = cutoff;
        _init_lpfilter(filter->activeLowpass);
        return;
    }

    filter->activeLowpass = nullptr;
}

// reset fx without reallocating AuFX
void au_fx_load_preset(AuFX* fx, u8 effectType) {
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
            delay->activeResampler = delay->resamplerTemplate;
            delay->resamplerTemplate->delta = 0.0;
            delay->activeResampler->first = true;
        } else {
            delay->activeResampler = nullptr;
            j++;
            j++;
        }

        if (params[j]) {
            delay->activeLowpass = delay->lowpassTemplate;
            delay->activeLowpass->fc = params[j++];
            _init_lpfilter(delay->activeLowpass);
        } else {
            delay->activeLowpass = nullptr;
            j++;
        }
    }
}

/**
 * Applies a chain of delay-line based effects to audio and mixes into output.
 *
 * For each delay tap in the FX chain:
 * - Loads delay input/output from circular buffer.
 * - Applies optional modulation and resampling.
 * - Applies feedforward/feedback mixing.
 * - Applies optional lowpass filtering.
 * - Mixes result into wet output buffer.
 *
 * @param fx         Pointer to FX state (delay taps, buffers, etc.)
 * @param ptr        Pointer to the current audio command list position.
 * @param wetDmem    DMEM offset to mix wet output into.
 * @param tempDmem   Base DMEM offset for temporary working buffers.
 * @return           Updated command list pointer.
 */
Acmd* au_pull_fx(AuFX* fx, Acmd* ptr, s16 wetDmem, s16 tempDmem) {
    Acmd* cmdBufPos = ptr;
    s16 delayIdx;

    s16* inPtr;
    s16* outPtr;

    // DMEM temp buffer layout:
    s16 inputTapBuffer  = tempDmem;
    s16 outputTapBuffer = tempDmem + 2 * AUDIO_SAMPLES;
    s16 resampleBuffer  = tempDmem + 4 * AUDIO_SAMPLES;

    s16* prevOutPtr = 0;
    s16 outDmem = wetDmem;

    // save wet input from voice mixing into circular delay buffer
    n_aSaveBuffer(cmdBufPos++, 2 * AUDIO_SAMPLES, wetDmem, osVirtualToPhysical(fx->input));

    // clear the wet output buffer for this frame
    aClearBuffer(cmdBufPos++, wetDmem, 2 * AUDIO_SAMPLES);

    for (delayIdx = 0; delayIdx < fx->delayCount; delayIdx++) {
        AuDelay* delay = &fx->delays[delayIdx];
        f32 fUnityPitch = UNITY_PITCH;

        // calculate read positions for input and output taps, wrapping the circular buffer if necessary
        inPtr = &fx->input[-delay->input];
        if (inPtr < fx->base) {
            inPtr += fx->length;
        }
        outPtr = &fx->input[-delay->output];
        if (outPtr < fx->base) {
            outPtr += fx->length;
        }

        // if output is same as previous tap, reuse loaded data by swapping buffers
        if (inPtr == prevOutPtr) {
            SWAP16(inputTapBuffer, outputTapBuffer);
        } else {
            // load from input tap into buffer
            n_aLoadBuffer(cmdBufPos++, 2 * AUDIO_SAMPLES, inputTapBuffer, osVirtualToPhysical(inPtr));
        }

        if (delay->activeResampler) {
            // triangle wave modulation for chorus/flange
            s32 ratio;
            s32 length, count;
            f32 delta, fratio, fincount;
            s32 ramAlign;
            s16 tmp;
            s16* rsOutPtr;

            // modulate delay time (triangle wave)
            length = delay->output - delay->input;
            delta = updateTriangleModulation(delay, AUDIO_SAMPLES);
            delta /= length;
            delta = (s32)(delta * fUnityPitch);
            delta = delta / UNITY_PITCH;

            fratio = 1.0 - delta;

            // calculate fractional resampling count
            fincount = delay->activeResampler->delta + (fratio * AUDIO_SAMPLES);
            count = (s32) fincount;
            delay->activeResampler->delta = fincount - count;

            // prepare delay line for resampling (wrap if needed)
            rsOutPtr = &fx->input[-(delay->output - delay->rsdelta)];
            ramAlign = ((s32) rsOutPtr & 7) >> 1;
            rsOutPtr -= ramAlign;
            if (rsOutPtr < fx->base) {
                rsOutPtr += fx->length;
            }

            // load from delay line
            cmdBufPos = _loadDelayLineBuffer(fx, rsOutPtr, resampleBuffer, count + ramAlign, cmdBufPos);

            // process resampler
            ratio = fratio * fUnityPitch;
            tmp = outputTapBuffer >> 8;
            n_aResample(cmdBufPos++, osVirtualToPhysical(delay->activeResampler->state),
                delay->activeResampler->first, ratio, resampleBuffer + (ramAlign<<1), tmp);
            delay->activeResampler->first = false;
            delay->rsdelta += count - AUDIO_SAMPLES;
        } else {
            // no resampling -- just load from output pointer
            n_aLoadBuffer(cmdBufPos++, 2 * AUDIO_SAMPLES, outputTapBuffer, osVirtualToPhysical(outPtr));
        }

        // feedforward: input -> output
        if (delay->ffcoef) {
            aMix(cmdBufPos++, 0, (u16)delay->ffcoef, inputTapBuffer, outputTapBuffer);

            // save output if no additional processing needed
            if (delay->activeResampler == nullptr && delay->activeLowpass == nullptr) {
                n_aSaveBuffer(cmdBufPos++, 2 * AUDIO_SAMPLES, outputTapBuffer, osVirtualToPhysical(outPtr));
            }
        }

        // feedback: output -> input
        if (delay->fbcoef) {
            aMix(cmdBufPos++, 0, (u16)delay->fbcoef, outputTapBuffer, inputTapBuffer);
            n_aSaveBuffer(cmdBufPos++, 2 * AUDIO_SAMPLES, inputTapBuffer, osVirtualToPhysical(inPtr));
        }

        // Save processed output back into delay line (if not resampled)
        if (delay->activeLowpass != nullptr) {
            // modified _n_filterBuffer
            s16 alignedBuffer = outputTapBuffer >> 8;
            n_aLoadADPCM(cmdBufPos++, 32, osVirtualToPhysical(delay->activeLowpass->fccoef));
            n_aPoleFilter(cmdBufPos++, delay->activeLowpass->first, delay->activeLowpass->fgain, alignedBuffer, osVirtualToPhysical(delay->activeLowpass->fstate));
            delay->activeLowpass->first = 0;
        }

        // save output (if not already saved earlier)
        if (!delay->activeResampler) {
            n_aSaveBuffer(cmdBufPos++, 2 * AUDIO_SAMPLES, outputTapBuffer, osVirtualToPhysical(outPtr));
        }

        // mix input from this delay into wet output buffer
        if (delay->gain) {
            aMix(cmdBufPos++, 0, (u16)delay->gain, outputTapBuffer, outDmem);
        }
        prevOutPtr = &fx->input[delay->output];
    }

    // advance position in ring buffer
    fx->input += AUDIO_SAMPLES;
    if (fx->input >= &fx->base[fx->length]) {
        fx->input = fx->base;
    }

    return cmdBufPos;
}

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
        if (fx->delays[index].activeLowpass) {
            fx->delays[index].activeLowpass->fc = value;
            _init_lpfilter(fx->delays[index].activeLowpass);
        }
        break;
    }
    return 0;
}

/**
 * Loads a possibly wrapped segment of the FX delay line into DMEM.
 * Used to prepare samples for resampling or filtering.
 */
static Acmd* _loadDelayLineBuffer(AuFX* fx, s16* oldPos, s32 buf, s32 count, Acmd* cmdBufPos) {
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
static f32 updateTriangleModulation(AuDelay* delay, s32 numSamples) {
    f32 result;

    delay->rsval += delay->rsinc * numSamples;
    delay->rsval = (delay->rsval > 2.0) ? delay->rsval - 4.0 : delay->rsval;

    result = delay->rsval;
    if (result < 0.0f) {
        result = -result;
    }

    result -= 1.0;

    return delay->rsgain * result;
}
