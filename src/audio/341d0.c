//TODO rename file to reverb.c

#include "common.h"
#include "audio.h"

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
#define	SCALE 16384

#define ms *(((s32)((f32)44.1))&~0x7)

s32 SMALL_ROOM_PARAMS[] = {
    /* sections	   length */
        3,             11,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,       9,  9830,  -9830,      0,      0,      0,      0,
        3,       7,  3276,  -3276, 0x3FFF,      0,      0,      0,
        0,      10,  5000,      0,      0,      0,      0, 0x5000
};

s32 BIG_ROOM_PARAMS[] = {
    /* sections	   length */
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
    /* sections	   length */
        4,             17,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,      11,  9830,  -9830,      0,      0,      0,      0,
        4,       9,  3276,  -3276, 0x3FFF,      0,      0,      0,
       11,      15,  3276,  -3276, 0x3FFF,      0,      0,      0,
        0,      16,  8000,      0,      0,      0,      0, 0x5000
};

s32 ECHO_PARAMS[] = {
    /* sections	   length */
        1,              14,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,      13, 20000,      0, 0x7FFF,      0,      0, 0x7FFF
};

s32 CHORUS_PARAMS[] = {
    /* sections	   length */
        1,              3,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,       1, 16384,      0, 0x7FFF,   7600,    700,      0
};

s32 FLANGE_PARAMS[] = {
    /* sections	   length */
        1,              3,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,       1,     0, 0x5FFF, 0x7FFF,    380,    500,      0
};

s32 NULL_PARAMS[] = {
    /* sections	   length */
        0,              0,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,       0,     0,      0,      0,      0,      0,      0
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

    for (i = 0; i < 8; i++) {
        lp->fccoef[i] = 0;
    }

    lp->fccoef[8] = timeConstant;
    
    // ith value is 16384 * (timeConstant / 16384)^(i-7)
    // ex: i = 9 --> timeConstant^2 / 16384
    attenuation = ((f64)timeConstant / SCALE);
    for (i = 9; i < 16; i++) {
        attenuation *= ((f64)timeConstant /SCALE);
        lp->fccoef[i] = attenuation * SCALE;
    }
}

// definately AuFX, evidenced by call to func_8005904C
// this is n_alFxNew
void func_80058E84(AuFX* fx, u8 mode, ALHeap* heap) {
    AuDelay* delay;
    u16 i;

    // allocate space for 4 AuDelay
    fx->delays = alHeapAlloc(heap, AU_FX_DELAY_COUNT, sizeof(AuDelay));
    fx->base = alHeapAlloc(heap, AU_FX_LENGTH, sizeof(s16));
    
    for (i = 0; i < AU_FX_DELAY_COUNT; i++) {
        delay = &fx->delays[i];
        delay->resampler_2C = alHeapAlloc(heap, 1, sizeof(AuResampler));
        delay->resampler_2C->rs_state = alHeapAlloc(heap, 1, sizeof(RESAMPLE_STATE));
        delay->lowpass_24 = alHeapAlloc(heap, 1, sizeof(AuLowPass));
        delay->lowpass_24->fstate = alHeapAlloc(heap, 1, sizeof(POLEF_STATE));
    }
    
    func_8005904C(fx, mode);
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

// part of n_alFxNew, extracted to allow reseting fx without reallocating
// AuFX from gSynDriver
void func_8005904C(AuFX* fx, u8 effect) {
    s32* params;
    s32* clr;
    s32 i, j;
    clr = (s32*)fx->base;
    
    switch (effect) {
        case AL_FX_SMALLROOM:
            params = SMALL_ROOM_PARAMS;
            break;
        case AL_FX_BIGROOM:
            params = BIG_ROOM_PARAMS;
            break;
        case AL_FX_ECHO:
            params = ECHO_PARAMS;
            break;
        case AL_FX_CHORUS:
            params = CHORUS_PARAMS;
            break;
        case AL_FX_FLANGE:
            params = FLANGE_PARAMS;
            break;
        case 6:
            params = AU_FX_CUSTOM_PARAMS[0];
            break;
        case 7:
            params = AU_FX_CUSTOM_PARAMS[1];
            break;
        case 8:
            params = AU_FX_CUSTOM_PARAMS[2];
            break;
        case 9:
            params = AU_FX_CUSTOM_PARAMS[3];
            break;
        case 10:
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
            delay->rsinc = (2.0 * (params[j++] / 1000.0f)) / D_80078E50->outputRate;
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

// alFxPull
// AuFX from gSynDriver
INCLUDE_ASM(s32, "audio/341d0", func_80059310);

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
        fx->delays[index].rsinc = (2.0 * (value / 1000.0f)) / D_80078E50->outputRate;
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

static Acmd* _saveBuffer(AuFX* fx, s16* oldPos, s32 buff, s32 count, Acmd* cmdBufPos) {
    Acmd *ptr = cmdBufPos;
    s16* newPos = oldPos + count;
    s16* delayEnd = &fx->base[fx->length];

    if (delayEnd < newPos) {
        s32 before = delayEnd - oldPos;
        s32 after = newPos - delayEnd;
        n_aLoadBuffer(ptr++, before<<1, buff, osVirtualToPhysical(oldPos));
        n_aLoadBuffer(ptr++, after<<1, buff + (before<<1), osVirtualToPhysical(fx->base));
    } else {
        n_aLoadBuffer(ptr++, count<<1, buff, osVirtualToPhysical(oldPos));
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
