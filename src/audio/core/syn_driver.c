#include "common.h"
#include "audio.h"
#include "audio/core.h"

static s16 _getVol(s16 arg0, s32 arg1, s16 arg2, u16 arg3);

BSS s16* AuDelayBufferMain;
BSS s16* AuDelayBufferAux;
BSS s32 AuDelayCounter;
BSS u8 AuDelayedBusID;
BSS s16 AuDelayedChannel;
BSS s32 AuDelayCount;

AuSynDriver* gActiveSynDriverPtr = nullptr;
AuSynDriver* gSynDriverPtr = nullptr;
u8 AuUseGlobalVolume = false;
u16 AuGlobalVolume = AU_MAX_VOLUME_16;
u8 AuSynStereoDirty = false;

extern s16 AuEqPower[128];

#define AU_EQPOW_MID_IDX 64
#define AU_EQPOW_MAX_IDX 127

void au_driver_init(AuSynDriver* driver, ALConfig* config) {
    ALHeap* heap = config->heap;
    s32 i;

    if (gActiveSynDriverPtr != nullptr) {
        return;
    }

    driver->num_pvoice = config->num_pvoice;
    driver->num_bus = config->num_bus;
    driver->curSamples = 0;
    driver->unused_04 = 0;
    driver->outputRate = config->outputRate;
    driver->dmaNew = config->dmaNew;

    gActiveSynDriverPtr = driver;
    gSynDriverPtr = driver;
    AuUseGlobalVolume = false;
    AuGlobalVolume = AU_MAX_VOLUME_16;
    AuSynStereoDirty = true;

    gSynDriverPtr->pvoices = alHeapAlloc(heap, config->num_pvoice, sizeof(*gSynDriverPtr->pvoices));

    // this is inlined alN_PVoiceNew
    for (i = 0; i < config->num_pvoice; i++) {
        AuPVoice* voice = &gSynDriverPtr->pvoices[i];
        voice->decoder.state = alHeapAlloc(heap, 1, sizeof(*voice->decoder.state));
        voice->decoder.lstate = alHeapAlloc(heap, 1, sizeof(*voice->decoder.lstate));
        voice->decoder.dmaFunc = gSynDriverPtr->dmaNew(&voice->decoder.dmaState);
        voice->decoder.lastsam = 0;
        voice->decoder.first = 1;
        voice->decoder.memin = (s32)nullptr;
        voice->resampler.state = alHeapAlloc(heap, 1, sizeof(*voice->resampler.state));
        voice->resampler.delta = 0;
        voice->resampler.first = true;
        voice->resampler.ratio = 1.0f;
        voice->envMixer.state = alHeapAlloc(heap, 1, sizeof(*voice->envMixer.state));
        voice->envMixer.dirty = true;
        voice->envMixer.motion = AL_STOPPED;
        voice->envMixer.volume = 1;
        voice->envMixer.ltgt = 1;
        voice->envMixer.rtgt = 1;
        voice->envMixer.cvolL = 1;
        voice->envMixer.cvolR = 1;
        voice->envMixer.dryamt = 0;
        voice->envMixer.wetamt = 0;
        voice->envMixer.lratm = 1;
        voice->envMixer.lratl = 0;
        voice->envMixer.rratm = 1;
        voice->envMixer.rratl = 0;
        voice->envMixer.delta = 0;
        voice->envMixer.segEnd = 0;
        voice->envMixer.pan = 64;
        voice->unused_74 = 0;
        voice->next = nullptr;
        voice->busID = FX_BUS_BGMA_MAIN;
        voice->index = i;
    }

    gSynDriverPtr->fxBus = alHeapAlloc(heap, config->num_bus, sizeof(*gSynDriverPtr->fxBus));

    for (i = 0; i < config->num_bus; i++) {
        AuFxBus* fxBus = &gSynDriverPtr->fxBus[i];
        fxBus->head = nullptr;
        fxBus->tail = nullptr;
        fxBus->gain = 0x7FFF;
        fxBus->curEffectType = AU_FX_NONE;
        fxBus->fxL = alHeapAlloc(heap, 1, sizeof(*fxBus->fxL));
        fxBus->fxR = alHeapAlloc(heap, 1, sizeof(*fxBus->fxR));
        au_fx_create(fxBus->fxL, fxBus->curEffectType, heap);
        au_fx_create(fxBus->fxR, fxBus->curEffectType, heap);
    }

    gSynDriverPtr->dryAccumBuffer = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    gSynDriverPtr->wetAccumBuffer = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    AuDelayedBusID = 0;
    AuDelayedChannel = AU_DELAY_CHANNEL_NONE;
    AuDelayCount = 4;

    AuDelayBufferMain = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    AuDelayBufferAux = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    for (i = 0; i < 4 * AUDIO_SAMPLES; i++) {
        AuDelayBufferAux[i] = AuDelayBufferMain[i] = 0;
    }

    gSynDriverPtr->heap = heap;
}

void au_driver_release(void) {
    if (gActiveSynDriverPtr != nullptr) {
        gActiveSynDriverPtr = nullptr;
    }
}

Acmd* alAudioFrame(Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen) {
    Acmd* cmdListPos = cmdList;
    s16* bufPos = outBuf;
    AuPVoice* pvoice;
    AuFxBus* fxBus;
    s16 mainOut;
    s16 auxOut;
    s32 busID;
    bool firstBus;

    // sanity check: ensure audio system is initialized
    if (gActiveSynDriverPtr == nullptr) {
        *cmdLen = 0;
        return cmdListPos;
    }

    au_update_clients_for_video_frame();

    // reapply panning if dirty
    if (AuSynStereoDirty) {
        for (busID = 0; busID < gSynDriverPtr->num_pvoice; busID++) {
            pvoice = &gSynDriverPtr->pvoices[busID];
            if (pvoice->envMixer.motion == AL_PLAYING) {
                au_syn_set_pan(busID, pvoice->envMixer.pan);
            }
        }
        AuSynStereoDirty = false;
    }

    // process blocks of AUDIO_SAMPLES until outLen is consumed
    while (outLen > 0) {
        au_update_clients_for_audio_frame();

        // organize all voices by which FX bus they send to
        for (busID = 0; busID < gSynDriverPtr->num_pvoice; busID++) {
            pvoice = &gSynDriverPtr->pvoices[busID];

            if ((pvoice->busID != 0xFF) && (pvoice->busID < gSynDriverPtr->num_bus)) {
                fxBus = &gSynDriverPtr->fxBus[pvoice->busID];
                if (fxBus->tail != nullptr) {
                    fxBus->tail->next = pvoice;
                } else {
                    fxBus->head = pvoice;
                }
                fxBus->tail = pvoice;
            }
        }

        // render each effects bus
        firstBus = true;
        for (busID = 0; busID < gSynDriverPtr->num_bus; busID++) {
            fxBus = &gSynDriverPtr->fxBus[busID];
            if (fxBus->head != nullptr) {
                // clear all main and aux outputs (each is 2 * AUDIO_SAMPLES long, starting at N_AL_MAIN_L_OUT)
                aClearBuffer(cmdListPos++, N_AL_MAIN_L_OUT, 8 * AUDIO_SAMPLES);

                // render all voices for this bus
                // these will implicitly accumulate dry to N_AL_MAIN_*_OUT and wet to N_AL_AUX_*_OUT
                if (fxBus->head != nullptr) {
                    AuPVoice* next;
                    do {
                        cmdListPos = au_pull_voice(fxBus->head, cmdListPos);
                        next = fxBus->head->next;
                        fxBus->head->next = nullptr;
                        fxBus->head = next;
                    } while (next != nullptr);
                    fxBus->tail = nullptr;
                }

                // process fx for this bus
                if (fxBus->curEffectType != AU_FX_NONE) {
                    cmdListPos = au_pull_fx(fxBus->fxL, cmdListPos, N_AL_AUX_L_OUT, N_AL_TEMP_0);
                    cmdListPos = au_pull_fx(fxBus->fxR, cmdListPos, N_AL_AUX_R_OUT, N_AL_TEMP_0);
                }

                // apply channel delay
                if (busID == AuDelayedBusID) {
                    mainOut = -1;
                    switch (AuDelayedChannel) {
                        case AU_DELAY_CHANNEL_LEFT:
                            mainOut = N_AL_MAIN_L_OUT;
                            auxOut = N_AL_AUX_L_OUT;
                            break;
                        case AU_DELAY_CHANNEL_RIGHT:
                            mainOut = N_AL_MAIN_R_OUT;
                            auxOut = N_AL_AUX_R_OUT;
                            break;
                    }
                    if (mainOut != -1) {
                        n_aSaveBuffer(cmdListPos++, 2 * AUDIO_SAMPLES, mainOut, osVirtualToPhysical(AuDelayBufferMain + (AuDelayCounter % AuDelayCount) * AUDIO_SAMPLES));
                        n_aLoadBuffer(cmdListPos++, 2 * AUDIO_SAMPLES, mainOut, osVirtualToPhysical(AuDelayBufferMain + ((AuDelayCounter + 1) % AuDelayCount) * AUDIO_SAMPLES));
                        n_aSaveBuffer(cmdListPos++, 2 * AUDIO_SAMPLES, auxOut, osVirtualToPhysical(AuDelayBufferAux + (AuDelayCounter % AuDelayCount) * AUDIO_SAMPLES));
                        n_aLoadBuffer(cmdListPos++, 2 * AUDIO_SAMPLES, auxOut, osVirtualToPhysical(AuDelayBufferAux + ((AuDelayCounter + 1) % AuDelayCount) * AUDIO_SAMPLES));
                    }
                }

                // wet mix down for this bus
                if (firstBus) {
                    // clear accumulation buffer if first bus with output
                    aClearBuffer(cmdListPos++, N_AL_TEMP_0, 4 * AUDIO_SAMPLES);
                } else {
                    // load accumulation buffer from DRAM
                    n_aLoadBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_TEMP_0, osVirtualToPhysical(gSynDriverPtr->wetAccumBuffer));
                }
                aMix(cmdListPos++, 0, fxBus->gain, N_AL_AUX_L_OUT, N_AL_TEMP_0);
                aMix(cmdListPos++, 0, fxBus->gain, N_AL_AUX_R_OUT, N_AL_TEMP_1);
                // save accumulation buffer to DRAM
                n_aSaveBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_TEMP_0, osVirtualToPhysical(gSynDriverPtr->wetAccumBuffer));

                // dry mix down for this bus
                if (firstBus) {
                    // clear accumulation buffer if first bus with output
                    aClearBuffer(cmdListPos++, N_AL_TEMP_0, 4 * AUDIO_SAMPLES);
                    firstBus = false;
                } else {
                    // load accumulation buffer from DRAM
                    n_aLoadBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_TEMP_0, osVirtualToPhysical(gSynDriverPtr->dryAccumBuffer));
                }
                aMix(cmdListPos++, 0, fxBus->gain, N_AL_MAIN_L_OUT, N_AL_TEMP_0);
                aMix(cmdListPos++, 0, fxBus->gain, N_AL_MAIN_R_OUT, N_AL_TEMP_1);
                // save accumulation buffer to DRAM
                n_aSaveBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_TEMP_0, osVirtualToPhysical(gSynDriverPtr->dryAccumBuffer));
            }
        }

        // final output mix stage
        aDMEMMove(cmdListPos++, 0, N_AL_MAIN_L_OUT, 4 * AUDIO_SAMPLES);
        n_aLoadBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_AUX_L_OUT, osVirtualToPhysical(gSynDriverPtr->wetAccumBuffer));
        aMix(cmdListPos++, 0, 0x7FFF, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
        aMix(cmdListPos++, 0, 0x7FFF, N_AL_AUX_R_OUT, N_AL_MAIN_R_OUT);

        // global volume control (used to fade out during console reset)
        if (AuUseGlobalVolume) {
            u16 vol;
            aDMEMMove(cmdListPos++, N_AL_MAIN_L_OUT, 0, 4 * AUDIO_SAMPLES);
            aClearBuffer(cmdListPos++, N_AL_MAIN_L_OUT, 4 * AUDIO_SAMPLES);
            vol = AuGlobalVolume;
            aMix(cmdListPos++, 0, vol, 0, N_AL_MAIN_L_OUT);
            aMix(cmdListPos++, 0, vol, 2 * AUDIO_SAMPLES, N_AL_MAIN_R_OUT);
        }

        outLen -= AUDIO_SAMPLES;
        n_aInterleave(cmdListPos++);
        n_aSaveBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, 0, bufPos);
        bufPos += 2 * AUDIO_SAMPLES;
        AuDelayCounter++;
        gSynDriverPtr->curSamples += AUDIO_SAMPLES;
    }
    *cmdLen = (cmdListPos - cmdList);

    return cmdListPos;
}

void au_use_global_volume(void) {
    AuUseGlobalVolume = true;
}

void au_set_global_volume(s16 volume) {
    AuGlobalVolume = volume;
}

s16 au_get_global_volume(void) {
    return AuGlobalVolume;
}

void au_set_stereo_enabled(b8 enabled) {
    AuSynUseStereo = enabled;
    AuSynStereoDirty = true;
}

void au_bus_set_volume(u8 busID, u16 value) {
    AuFxBus* fxBus = &gSynDriverPtr->fxBus[busID];

    fxBus->gain = value & 0x7FFF;
}

u16 au_bus_get_volume(u8 busID) {
    AuFxBus* fxBus = &gSynDriverPtr->fxBus[busID];

    return fxBus->gain;
}

void au_bus_set_effect(u8 busID, u8 effectType) {
    AuFxBus* fxBus = &gSynDriverPtr->fxBus[busID];

    fxBus->curEffectType = effectType;
    au_fx_load_preset(fxBus->fxL, effectType);
    au_fx_load_preset(fxBus->fxR, effectType);
}

void au_bus_set_fx_params(u8 busID, s16 delayIndex, s16 paramID, s32 value) {
    AuFxBus* fxBus = &gSynDriverPtr->fxBus[busID];

    au_fx_param_hdl(fxBus->fxL, delayIndex, paramID, value);
    au_fx_param_hdl(fxBus->fxR, delayIndex, paramID, value);
}

void au_pvoice_set_bus(u8 voiceIdx, s8 busID) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];

    pvoice->busID = busID;
}

// based on n_alSynStopVoice
void au_syn_stop_voice(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* decoder = &pvoice->decoder;

    pvoice->envMixer.motion = AL_STOPPED;
    pvoice->envMixer.dirty = true;
    pvoice->envMixer.volume = 1;
    pvoice->resampler.delta = 0;
    pvoice->resampler.first = 1;
    decoder->lastsam = 0;
    decoder->first = true;
    decoder->sample = 0;
    if (decoder->instrument != nullptr) {
        decoder->memin = (s32)decoder->instrument->wavData;
        if (decoder->instrument->type == AL_ADPCM_WAVE) {
            if (decoder->instrument->loopEnd != 0){
                decoder->loop.count = decoder->instrument->loopCount;
            }
        } else if (decoder->instrument->type == AL_RAW16_WAVE) {
            if (decoder->instrument->loopEnd != 0){
                decoder->loop.count = decoder->instrument->loopCount;
            }
        }
    }
}

// based on n_alSynStartVoice, but without setting new wavetable
void au_syn_start_voice(u8 voiceIdx) {
    AuPVoice* pvoice = (AuPVoice*)&gSynDriverPtr->pvoices[voiceIdx];

    pvoice->envMixer.motion = AL_PLAYING;
}

// based on n_alSynStartVoiceParams
void au_syn_start_voice_params(u8 voiceIdx, u8 busID, Instrument* instrument, f32 pitchRatio, s16 vol, u8 pan, u8 fxMix, s32 delta) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* decoder = &pvoice->decoder;
    AuEnvMixer* envMixer = &pvoice->envMixer;
    AuResampler* resampler = &pvoice->resampler;

    pvoice->busID = busID;
    decoder->instrument = instrument;

    pvoice->decoder.memin = (s32)decoder->instrument->wavData;
    pvoice->decoder.sample = 0;

    switch (decoder->instrument->type) {
        case AL_ADPCM_WAVE:
            decoder->instrument->wavDataLength = (decoder->instrument->wavDataLength / ADPCMFBYTES) * ADPCMFBYTES;
            pvoice->decoder.bookSize = decoder->instrument->codebookSize;
            if (decoder->instrument->loopEnd != 0) {
                decoder->loop.start = decoder->instrument->loopStart;
                decoder->loop.end = decoder->instrument->loopEnd;
                decoder->loop.count = decoder->instrument->loopCount;
                alCopy(decoder->instrument->loopState, decoder->lstate, sizeof(ADPCM_STATE));
            } else {
                decoder->loop.count = 0;
                decoder->loop.end = 0;
                decoder->loop.start = 0;
            }
            break;
        case AL_RAW16_WAVE:
            if (decoder->instrument->loopEnd != 0) {
                decoder->loop.start = decoder->instrument->loopStart;
                decoder->loop.end = decoder->instrument->loopEnd;
                decoder->loop.count = decoder->instrument->loopCount;
            } else {
                decoder->loop.count = 0;
                decoder->loop.end = 0;
                decoder->loop.start = 0;
            }
            break;
    }

    envMixer->motion = AL_PLAYING;
    envMixer->dirty = true;
    envMixer->delta = 0;
    envMixer->segEnd = delta;
    envMixer->pan = pan;
    envMixer->volume = SQ(vol) >> 0xF;
    envMixer->dryamt = AuEqPower[fxMix];
    envMixer->wetamt = AuEqPower[AU_EQPOW_MAX_IDX - fxMix];
    if (envMixer->segEnd != 0) {
        envMixer->cvolL = 1;
        envMixer->cvolR = 1;
    } else {
        if (!AuSynUseStereo) {
            envMixer->cvolL = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->cvolL = (envMixer->volume * AuEqPower[envMixer->pan]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->pan]) >> 0xF;
        }
    }
    resampler->ratio = pitchRatio;
}

void au_syn_set_wavetable(u8 voiceIdx, Instrument* instrument) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* decoder = &pvoice->decoder;

    pvoice->decoder.instrument = instrument;
    pvoice->decoder.memin = (s32)decoder->instrument->wavData;
    pvoice->decoder.sample = 0;

    switch (decoder->instrument->type) {
        case AL_ADPCM_WAVE:
            decoder->instrument->wavDataLength = (decoder->instrument->wavDataLength / ADPCMFBYTES) * ADPCMFBYTES;
            pvoice->decoder.bookSize = decoder->instrument->codebookSize;
            if (decoder->instrument->loopEnd != 0) {
                pvoice->decoder.loop.start = decoder->instrument->loopStart;
                pvoice->decoder.loop.end = decoder->instrument->loopEnd;
                pvoice->decoder.loop.count = decoder->instrument->loopCount;
                alCopy(decoder->instrument->loopState, pvoice->decoder.lstate, sizeof(ADPCM_STATE));
            } else {
                pvoice->decoder.loop.count = 0;
                pvoice->decoder.loop.end = 0;
                pvoice->decoder.loop.start = 0;
            }
            break;
        case AL_RAW16_WAVE:
            if (decoder->instrument->loopEnd != 0) {
                pvoice->decoder.loop.start = decoder->instrument->loopStart;
                pvoice->decoder.loop.end = decoder->instrument->loopEnd;
                pvoice->decoder.loop.count = decoder->instrument->loopCount;
            } else {
                pvoice->decoder.loop.count = 0;
                pvoice->decoder.loop.end = 0;
                pvoice->decoder.loop.start = 0;
            }
            break;
    }
}

// based on n_alSynSetPitch
void au_syn_set_pitch(u8 voiceIdx, f32 pitch) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];

    pvoice->resampler.ratio = pitch;
}

void au_syn_set_mixer_params(u8 voiceIdx, s16 volume, s32 delta, u8 pan, u8 fxMix) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->delta >= envMixer->segEnd) {
        envMixer->delta = envMixer->segEnd;
        if (!AuSynUseStereo) {
            envMixer->cvolL = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->cvolL = (envMixer->volume * AuEqPower[envMixer->pan]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->pan]) >> 0xF;
        }
    } else {
        envMixer->cvolL = _getVol(envMixer->cvolL, envMixer->delta, envMixer->lratm, envMixer->lratl);
        envMixer->cvolR = _getVol(envMixer->cvolR, envMixer->delta, envMixer->rratm, envMixer->rratl);
    }
    if (envMixer->cvolL == 0) {
        envMixer->cvolL = 1;
    }
    if (envMixer->cvolR == 0) {
        envMixer->cvolR = 1;
    }

    envMixer->delta = 0;
    envMixer->segEnd = delta;
    envMixer->pan = pan;
    envMixer->volume = SQ(volume) >> 0xF;
    envMixer->dryamt = AuEqPower[fxMix];
    envMixer->wetamt = AuEqPower[AU_EQPOW_MAX_IDX - fxMix];
    envMixer->dirty = true;
}

void au_syn_set_pan_fxmix(u8 voiceIdx, u8 pan, u8 fxMix) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->delta >= envMixer->segEnd) {
        envMixer->delta = envMixer->segEnd;
        if (!AuSynUseStereo) {
            envMixer->cvolL = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->cvolL = (envMixer->volume * AuEqPower[envMixer->pan]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->pan]) >> 0xF;
        }
    } else {
        envMixer->cvolL = _getVol(envMixer->cvolL, envMixer->delta, envMixer->lratm, envMixer->lratl);
        envMixer->cvolR = _getVol(envMixer->cvolR, envMixer->delta, envMixer->rratm, envMixer->rratl);
    }
    if (envMixer->cvolL == 0) {
        envMixer->cvolL = 1;
    }
    if (envMixer->cvolR == 0) {
        envMixer->cvolR = 1;
    }

    envMixer->pan = pan;
    envMixer->dryamt = AuEqPower[fxMix];
    envMixer->wetamt = AuEqPower[AU_EQPOW_MAX_IDX - fxMix];
    envMixer->dirty = true;
}

void au_syn_set_volume_delta(u8 voiceIdx, s16 vol, s32 delta) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->delta >= envMixer->segEnd) {
        envMixer->delta = envMixer->segEnd;
        if (!AuSynUseStereo) {
            envMixer->cvolL = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->cvolL = (envMixer->volume * AuEqPower[envMixer->pan]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->pan]) >> 0xF;
        }
    } else {
        envMixer->cvolL = _getVol(envMixer->cvolL, envMixer->delta, envMixer->lratm, envMixer->lratl);
        envMixer->cvolR = _getVol(envMixer->cvolR, envMixer->delta, envMixer->rratm, envMixer->rratl);
    }
    if (envMixer->cvolL == 0) {
        envMixer->cvolL = 1;
    }
    if (envMixer->cvolR == 0) {
        envMixer->cvolR = 1;
    }

    envMixer->volume = SQ(vol) >> 0xF;
    envMixer->delta = 0;
    envMixer->segEnd = delta;
    envMixer->dirty = true;
}

void au_syn_set_pan(u8 voiceIdx, u8 pan) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->delta >= envMixer->segEnd) {
        envMixer->delta = envMixer->segEnd;
        if (!AuSynUseStereo) {
            envMixer->cvolL = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->cvolL = (envMixer->volume * AuEqPower[envMixer->pan]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->pan]) >> 0xF;
        }
    } else {
        envMixer->cvolL = _getVol(envMixer->cvolL, envMixer->delta, envMixer->lratm, envMixer->lratl);
        envMixer->cvolR = _getVol(envMixer->cvolR, envMixer->delta, envMixer->rratm, envMixer->rratl);
    }
    if (envMixer->cvolL == 0) {
        envMixer->cvolL = 1;
    }
    if (envMixer->cvolR == 0) {
        envMixer->cvolR = 1;
    }

    envMixer->pan = pan;
    envMixer->dirty = true;
}

void au_syn_set_fxmix(u8 voiceIdx, u8 fxMix) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envMixer = &pvoice->envMixer;

    if (envMixer->delta >= envMixer->segEnd) {
        envMixer->delta = envMixer->segEnd;
        if (!AuSynUseStereo) {
            envMixer->cvolL = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MID_IDX]) >> 0xF;
        } else {
            envMixer->cvolL = (envMixer->volume * AuEqPower[envMixer->pan]) >> 0xF;
            envMixer->cvolR = (envMixer->volume * AuEqPower[AU_EQPOW_MAX_IDX - envMixer->pan]) >> 0xF;
        }
    } else {
        envMixer->cvolL = _getVol(envMixer->cvolL, envMixer->delta, envMixer->lratm, envMixer->lratl);
        envMixer->cvolR = _getVol(envMixer->cvolR, envMixer->delta, envMixer->rratm, envMixer->rratl);
    }
    if (envMixer->cvolL == 0) {
        envMixer->cvolL = 1;
    }
    if (envMixer->cvolR == 0) {
        envMixer->cvolR = 1;
    }

    envMixer->dryamt = AuEqPower[fxMix];
    envMixer->wetamt = AuEqPower[AU_EQPOW_MAX_IDX - fxMix];
    envMixer->dirty = true;
}

s32 au_syn_get_playing(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.motion;
}

s32 au_syn_get_bus(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->busID;
}

f32 au_syn_get_pitch(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->resampler.ratio;
}

u8 au_syn_get_pan(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.pan;
}

s16 au_syn_get_dryamt(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.dryamt;
}

s16 au_syn_get_wetamt(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.wetamt;
}

s32 au_syn_get_volume_left(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envmixer = &pvoice->envMixer;
    u32 retVal;

    if (envmixer->delta >= envmixer->segEnd) {
        if (!AuSynUseStereo) {
            retVal = (envmixer->volume * AuEqPower[AU_EQPOW_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = (envmixer->volume * AuEqPower[envmixer->pan] * 2) >> 0x10;
        }
    } else {
        retVal = _getVol(envmixer->cvolL, envmixer->delta, envmixer->lratm, envmixer->lratl);
    }
    return retVal;
}

s32 au_syn_get_volume_right(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuEnvMixer* envmixer = &pvoice->envMixer;
    u32 retVal;

    if (envmixer->delta >= envmixer->segEnd) {
        if (!AuSynUseStereo) {
            retVal = (envmixer->volume * AuEqPower[AU_EQPOW_MID_IDX] * 2) >> 0x10;
        } else {
            retVal = (envmixer->volume * AuEqPower[AU_EQPOW_MAX_IDX - envmixer->pan] * 2) >> 0x10;
        }
    } else {
        retVal = _getVol(envmixer->cvolL, envmixer->delta, envmixer->lratm, envmixer->lratl);
    }
    return retVal;
}

void au_set_delay_time(s32 numFrames) {
    if (numFrames < 2) {
        AuDelayCount = 0;
        AuDelayedChannel = AU_DELAY_CHANNEL_NONE;
    }

    AuDelayCount = numFrames;
    if (numFrames > 4) {
        AuDelayCount = 4;
    }
}

void au_delay_left_channel(u8 busID) {
    s32* mainBuf = (s32*)AuDelayBufferMain;
    s32* auxBuf = (s32*)AuDelayBufferAux;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *mainBuf++ = 0;
        *auxBuf++ = 0;
    }

    AuDelayedBusID = busID;
    AuDelayedChannel = AU_DELAY_CHANNEL_LEFT;
    AuDelayCounter = 0;
}

void au_delay_right_channel(u8 busID) {
    s32* mainBuf = (s32*)AuDelayBufferMain;
    s32* auxBuf = (s32*)AuDelayBufferAux;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *mainBuf++ = 0;
        *auxBuf++ = 0;
    }

    AuDelayedBusID = busID;
    AuDelayedChannel = AU_DELAY_CHANNEL_RIGHT;
    AuDelayCounter = 0;
}

void au_disable_channel_delay(void) {
    AuDelayedBusID = 0;
    AuDelayedChannel = AU_DELAY_CHANNEL_NONE;
    AuDelayCounter = 0;
}

void au_init_delay_channel(s16 channel) {
    s32* mainBuf = (s32*)AuDelayBufferMain;
    s32* auxBuf = (s32*)AuDelayBufferAux;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *mainBuf++ = 0;
        *auxBuf++ = 0;
    }

    AuDelayedBusID = 0;
    AuDelayedChannel = channel;
    AuDelayCounter = 0;
}

void alHeapInit(ALHeap* hp, u8* base, s32 len) {
    u32 i;
    s32 alignBytes = 0x10 - ((s32)base & 0xF);

    if (alignBytes != 0x10) {
        hp->base = base + alignBytes;
    } else {
        hp->base = base;
    }
    hp->len = len;
    hp->count = 0;
    hp->cur = hp->base;

    for (i = 0; i < (u32)(hp->len) >> 2; i++) {
        ((u32*)hp->base)[i] = 0;
    }
}

void* alHeapAlloc(ALHeap* heap, s32 count, s32 size) {
    void* ret = nullptr;
    u8* newCur = &heap->cur[ALIGN16(count * size)];

    if (&heap->base[heap->len] >= newCur) {
        ret = heap->cur;
        heap->cur = newCur;
    }

    return ret;
}

void alCopy(void* src, void* dst, s32 size) {
    s32 i;
    u8* srcIt = src;
    u8* dstIt = dst;

    for (i = 0; i < size; i++) {
        *dstIt++ = *srcIt++;
    }
}

static s16 _getVol(s16 ivol, s32 samples, s16 ratem, u16 ratel) {
    s32 tmpl;
    samples = samples >> 3;
    if (samples == 0) {
        return ivol;
    }
    tmpl = ratel * samples;
    tmpl = tmpl >> 16;
    tmpl += ratem * samples;
    return ivol + tmpl;
}
