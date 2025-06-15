#include "audio.h"
#include "audio/core.h"

#define LFSAMPLES       4
#define AUEQPOWER_LENGTH 128

// lookup table for constant-power panning
// these are values for cosine from 0 to pi/2 multiplied by 32767
// called n_eqpower in libultra
s16 AuEqPower[AUEQPOWER_LENGTH] = {
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

static Acmd* _decodeChunk(Acmd* cmdBufPos, AuLoadFilter* filter, s32 tsam, s32 nbytes, s16 output, s16 input, s32 flags);
static s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel);

// decode, resample, and mix
Acmd* au_pull_voice(AuPVoice* pvoice, Acmd* cmdBufPos) {
    Acmd* ptr = cmdBufPos;
    AuLoadFilter* decoder;
    AuResampler* resampler;
    AuEnvMixer* envMixer;
    s16 inp;
    f32 finCount;
    s16 outp;
    s32 startZero;
    s32 outCount;
    s32 incr;

    envMixer = &pvoice->envMixer;
    resampler = &pvoice->resampler;
    decoder = &pvoice->decoder;

    // return if voice is not playing
    if (envMixer->motion != AL_PLAYING) {
        return ptr;
    }

    // buffer to store decoded (or raw) samples before mixing
    outp = N_AL_DECODER_OUT;

    if (resampler->ratio > MAX_RATIO) {
        resampler->ratio = MAX_RATIO;
    }

    // convert pitch ratio to fixed-point resampling increment
    resampler->ratio = (s32)(resampler->ratio * UNITY_PITCH);
    resampler->ratio = resampler->ratio / UNITY_PITCH;

    // determine how many output samples are needed for this frame
    finCount = resampler->delta + resampler->ratio * (f32)AUDIO_SAMPLES;
    outCount = (s32) finCount;
    resampler->delta = finCount - (f32) outCount;

    if (outCount != 0) {
        if (decoder->instrument->type == AL_ADPCM_WAVE) {
            s32 nSam;
            s32 nbytes;
            s32 nframes;
            s32 op;
            s32 tsam;
            s32 nLeft;
            s32 bEnd;
            s32 nOver;
            s32 overFlow;
            s32 decoded = FALSE;
            s32 looped = FALSE;
            inp = N_AL_DECODER_IN;

            // load ADPCM predictor
            aLoadADPCM(ptr++, decoder->bookSize, K0_TO_PHYS(decoder->instrument->predictor));

            // will loop be triggered during this frame? if so, only process up to loop end
            looped = (decoder->loop.end < outCount + decoder->sample) && (decoder->loop.count != 0);

            if (looped) {
                nSam = decoder->loop.end - decoder->sample;
            } else {
                nSam = outCount;
            }

            if (decoder->lastsam != 0) {
                nLeft = ADPCMFSIZE - decoder->lastsam;
            } else {
                nLeft = 0;
            }

            tsam = nSam - nLeft;
            if (tsam < 0) {
                tsam = 0;
            }

            nframes = (tsam + ADPCMFSIZE - 1) >> LFSAMPLES;
            nbytes = nframes * ADPCMFBYTES;

            if (looped) {
                ptr = _decodeChunk(ptr, decoder, tsam, nbytes, outp, inp, decoder->first);
                if (decoder->lastsam != 0) {
                    outp += (decoder->lastsam << 1);
                } else {
                    outp += (ADPCMFSIZE << 1);
                }

                decoder->lastsam = decoder->loop.start & 0xF;
                decoder->memin = (s32)decoder->instrument->wavData + ADPCMFBYTES * ((s32)(decoder->loop.start >> LFSAMPLES) + 1);
                decoder->sample = decoder->loop.start;

                // continue decoding looped portion if needed
                bEnd = outp;
                while (outCount > nSam) {
                    outCount -= nSam;
                    op = (bEnd + ((nframes + 1) << (LFSAMPLES + 1)) + 16) & ~0x1F;
                    bEnd += nSam << 1;
                    if (decoder->loop.count != -1 && decoder->loop.count != 0) {
                        decoder->loop.count--;
                    }
                    nSam = MIN(outCount, decoder->loop.end - decoder->loop.start);
                    tsam = nSam - ADPCMFSIZE + decoder->lastsam;
                    if (tsam < 0) {
                        tsam = 0;
                    }
                    nframes = (tsam + ADPCMFSIZE - 1) >> LFSAMPLES;
                    nbytes = nframes * ADPCMFBYTES;
                    ptr = _decodeChunk(ptr, decoder, tsam, nbytes, op, inp, decoder->first | A_LOOP);
                    aDMEMMove(ptr++, op + (decoder->lastsam << 1), bEnd, nSam << 1);
                }
                decoder->lastsam = (outCount + decoder->lastsam) & 0xF;
                decoder->sample += outCount;
                decoder->memin += ADPCMFBYTES * nframes;
            } else {
                nSam = nframes << LFSAMPLES;
                overFlow = decoder->memin + nbytes - ((s32)decoder->instrument->wavData + decoder->instrument->wavDataLength);

                if (overFlow <= 0) {
                    overFlow = 0;
                } else {
                    envMixer->motion = AL_STOPPED;
                }
                nOver = (overFlow / ADPCMFBYTES) << LFSAMPLES;
                if (nOver > nSam + nLeft) {
                    nOver = nSam + nLeft;
                }
                nbytes -= overFlow;
                if (nOver - (nOver & 0xF) < outCount) {
                    decoded = TRUE;
                    ptr = _decodeChunk(ptr, decoder, nSam - nOver, nbytes, outp, inp, decoder->first);
                    if (decoder->lastsam != 0) {
                        outp += decoder->lastsam << 1;
                    } else {
                        outp += ADPCMFSIZE << 1;
                    }
                    decoder->lastsam = (outCount + decoder->lastsam) & 0xF;
                    decoder->sample += outCount;
                    decoder->memin += ADPCMFBYTES * nframes;
                } else {
                    decoder->lastsam = 0;
                    decoder->memin += ADPCMFBYTES * nframes;
                }

                if (nOver != 0) {
                    decoder->lastsam = 0;
                    if (decoded) {
                        startZero = (nLeft + nSam - nOver) << 1;
                    } else {
                        startZero = 0;
                    }
                    aClearBuffer(ptr++, startZero + outp, nOver << 1);
                }
            }
        } else {
            s32 nSam;
            s32 nbytes;
            s32 op;
            s32 dramAlign;
            s32 dramLoc;
            s32 dmemAlign;
            s32 overFlow;
            if (decoder->loop.end < outCount + decoder->sample && decoder->loop.count != 0) {
                nSam = decoder->loop.end - decoder->sample;
                nbytes = nSam << 1;
                if (nSam > 0) {
                    dramLoc = decoder->dmaFunc(decoder->memin, nbytes, decoder->dmaState, decoder->instrument->useDma);
                    dramAlign = dramLoc & 7;
                    nbytes += dramAlign;
                    n_aLoadBuffer(ptr++, nbytes + 8 - (nbytes & 7), outp, dramLoc - dramAlign);
                } else {
                    dramAlign = 0;
                }
                outp += dramAlign;
                decoder->memin = (s32)decoder->instrument->wavData + (decoder->loop.start << 1);
                decoder->sample = decoder->loop.start;
                op = outp;
                while (outCount > nSam){
                    op += nSam << 1;
                    outCount -= nSam;
                    if (decoder->loop.count != -1 && decoder->loop.count != 0) {
                        decoder->loop.count--;
                    }
                    nSam = MIN(outCount, decoder->loop.end - decoder->loop.start);
                    nbytes = nSam << 1;
                    dramLoc = decoder->dmaFunc(decoder->memin, nbytes, decoder->dmaState, decoder->instrument->useDma);
                    dramAlign = dramLoc & 7;
                    nbytes += dramAlign;
                    if ((op & 7) != 0) {
                        dmemAlign = 8 - (op & 7);
                    } else {
                        dmemAlign = 0;
                    }
                    n_aLoadBuffer(ptr++, nbytes + 8 - (nbytes & 7), op + dmemAlign, dramLoc - dramAlign);

                    if (dramAlign != 0 || dmemAlign != 0) {
                        aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam * 2);
                    }
                }
                decoder->sample += outCount;
                decoder->memin += outCount << 1;
            } else {
                nbytes = outCount << 1;
                overFlow = decoder->memin + nbytes - ((s32)decoder->instrument->wavData + decoder->instrument->wavDataLength);
                if (overFlow <= 0) {
                    overFlow = 0;
                } else {
                    envMixer->motion = AL_STOPPED;
                }
                if (nbytes < overFlow) {
                    overFlow = nbytes;
                }
                if (overFlow < nbytes) {
                    if (outCount > 0) {
                        nbytes -= overFlow;
                        dramLoc = decoder->dmaFunc(decoder->memin, nbytes, decoder->dmaState, decoder->instrument->useDma);
                        dramAlign = dramLoc & 7;
                        nbytes += dramAlign;
                        n_aLoadBuffer(ptr++, nbytes + 8 - (nbytes & 7), outp, dramLoc - dramAlign);
                    } else {
                        dramAlign = 0;
                    }
                    outp += dramAlign;
                    decoder->sample += outCount;
                    decoder->memin += outCount << 1;
                } else {
                    decoder->memin += outCount << 1;
                }

                if (overFlow != 0) {
                    startZero = (outCount << 1) - overFlow;
                    if (startZero < 0) {
                        startZero = 0;
                    }
                    aClearBuffer(ptr++, startZero + outp, overFlow);
                }
            }
        }
    }

    // resample audio from source buffer to output buffer
    incr = (s32)(resampler->ratio * UNITY_PITCH);
    n_aResample(ptr++, osVirtualToPhysical(resampler->state), resampler->first, incr, outp, 0);
    resampler->first = FALSE;

    // set up envelope mixing
    if (envMixer->dirty) {
        envMixer->dirty = FALSE;
        if (!AuSynUseStereo) {
            envMixer->ltgt = (envMixer->volume * AuEqPower[AUEQPOWER_LENGTH / 2]) >> 15;
            envMixer->rtgt = (envMixer->volume * AuEqPower[AUEQPOWER_LENGTH / 2]) >> 15;
        } else {
            envMixer->ltgt = (envMixer->volume * AuEqPower[envMixer->pan]) >> 15;
            envMixer->rtgt = (envMixer->volume * AuEqPower[AUEQPOWER_LENGTH - envMixer->pan - 1]) >> 15;
        }
        envMixer->lratm = _getRate(envMixer->cvolL, envMixer->ltgt, envMixer->segEnd, &envMixer->lratl);
        envMixer->rratm = _getRate(envMixer->cvolR, envMixer->rtgt, envMixer->segEnd, &envMixer->rratl);
        n_aSetVolume(ptr++, A_RATE, envMixer->ltgt, envMixer->lratm, envMixer->lratl);
        n_aSetVolume(ptr++, A_VOL | A_LEFT, envMixer->cvolL, envMixer->dryamt, envMixer->wetamt);
        n_aSetVolume(ptr++, A_VOL | A_RIGHT, envMixer->rtgt, envMixer->rratm, envMixer->rratl);
        n_aEnvMixer(ptr++, A_INIT, envMixer->cvolR, osVirtualToPhysical(envMixer->state));
    } else {
        n_aEnvMixer(ptr++, A_CONTINUE, 0, osVirtualToPhysical(envMixer->state));
    }

    // advance envelope segment
    envMixer->delta += AUDIO_SAMPLES;
    if (envMixer->segEnd < envMixer->delta) {
        envMixer->delta = envMixer->segEnd;
    }

    // if stopped, reset state
    if (envMixer->motion == AL_STOPPED) {
        envMixer->dirty = TRUE;
        envMixer->volume = 1;
        resampler->delta = 0.0f;
        resampler->first = TRUE;
        decoder->lastsam = 0;
        decoder->first = 1;
        decoder->sample = 0;
        decoder->memin = (s32) decoder->instrument->wavData;
        decoder->loop.count = decoder->instrument->loopCount;
        au_release_voice(pvoice->index);
    }
    return ptr;
}

/// loads and decodes a chunk of ADPCM data into RSP memory
static Acmd* _decodeChunk(Acmd* cmdBufPos, AuLoadFilter* filter, s32 tsam, s32 nbytes, s16 output, s16 input, s32 flags) {
    s32 endAddr;
    s32 endAlign;
    s32 paddedSize;

    if (nbytes > 0) {
        endAddr = filter->dmaFunc((s32) filter->memin, nbytes, filter->dmaState, filter->instrument->useDma);
        endAlign = endAddr & 7;
        nbytes += endAlign;
        paddedSize = nbytes + 8 - (nbytes & 7);
        n_aLoadBuffer(cmdBufPos++, paddedSize, input, endAddr - endAlign);
    } else {
        endAlign = 0;
    }

    if (flags & A_LOOP) {
        aSetLoop(cmdBufPos++, K0_TO_PHYS(filter->lstate));
    }

    n_aADPCMdec(cmdBufPos++, filter->state, flags, tsam << 1, endAlign, output);

    filter->first = 0;
    return cmdBufPos;
}

// computes an audio volume ramp rate
// used for smooth volume transitions in envelope segments
static s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel) {
    f64 inv;
    f64 a;
    f64 b;
    s16 c_int;
    s16 a_int;
    s16 b_int;

    if (count == 0) {
        if (tgt >= vol) {
            *ratel = 0xFFFF;
            return 0x7FFF;
        } else {
            *ratel = 0;
            return 0;
        }
    }
    inv = (1.0 / count);

    if (tgt < 1.0) {
        tgt = 1.0;
    }
    if (vol <= 0.0) {
        vol = 1.0;
    }

    a = (tgt - vol) * inv * 8.0;
    a_int = a;
    c_int = (a_int - 1);

    b = (a - a_int) + 1.0;
    b_int = b;
    c_int += b_int;

    *ratel = (b - b_int) * 0xFFFF;
    return c_int;
}
