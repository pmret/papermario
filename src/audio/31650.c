#include "common.h"
#include "audio.h"
#include "nu/nualsgi.h"

static s16 _getVol(s16 arg0, s32 arg1, s16 arg2, u16 arg3);

AuSynDriver* gActiveSynDriverPtr = NULL;
AuSynDriver* gSynDriverPtr = NULL;
u8 AuUseGlobalVolume = FALSE;
u16 AuGlobalVolume = 0x7FFF;
u8 AuSynStereoDirty = FALSE;

extern s16 AuEqPower[128];

#define AU_EQPOW_MID_IDX 64
#define AU_EQPOW_MAX_IDX 127

void au_driver_init(AuSynDriver* driver, ALConfig* config) {
    ALHeap* heap = config->heap;
    s32 i;

    if (gActiveSynDriverPtr != NULL) {
        return;
    }

    driver->num_pvoice = config->num_pvoice;
    driver->num_voice_groups = config->num_voice_groups;
    driver->curSamples = 0;
    driver->unk_04 = 0;
    driver->outputRate = config->outputRate;
    driver->dmaNew = config->dmaNew;

    gActiveSynDriverPtr = driver;
    gSynDriverPtr = driver;
    AuUseGlobalVolume = FALSE;
    AuGlobalVolume = 0x7FFF;
    AuSynStereoDirty = TRUE;

    gSynDriverPtr->pvoices = alHeapAlloc(heap, config->num_pvoice, sizeof(*gSynDriverPtr->pvoices));

    // this is inlined alN_PVoiceNew
    for (i = 0; i < config->num_pvoice; i++) {
        AuPVoice* voice = &gSynDriverPtr->pvoices[i];
        voice->decoder.state = alHeapAlloc(heap, 1, sizeof(*voice->decoder.state));
        voice->decoder.lstate = alHeapAlloc(heap, 1, sizeof(*voice->decoder.lstate));
        voice->decoder.dmaFunc = gSynDriverPtr->dmaNew(&voice->decoder.dmaState);
        voice->decoder.lastsam = 0;
        voice->decoder.first = 1;
        voice->decoder.memin = NULL;
        voice->resampler.state = alHeapAlloc(heap, 1, sizeof(*voice->resampler.state));
        voice->resampler.delta = 0;
        voice->resampler.first = 1;
        voice->resampler.ratio = 1.0f;
        voice->envMixer.state = alHeapAlloc(heap, 1, sizeof(*voice->envMixer.state));
        voice->envMixer.first = 1;
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
        voice->unk_74 = 0;
        voice->next = NULL;
        voice->groupID = 0;
        voice->index = i;
    }

    gSynDriverPtr->voiceGroups = alHeapAlloc(heap, config->num_voice_groups, sizeof(*gSynDriverPtr->voiceGroups));

    for (i = 0; i < config->num_voice_groups; i++) {
        AuPVoiceGroup* voiceGroup = &gSynDriverPtr->voiceGroups[i];
        voiceGroup->head = NULL;
        voiceGroup->tail = NULL;
        voiceGroup->gain = 0x7FFF;
        voiceGroup->currentEffectType = AU_FX_NONE;
        voiceGroup->fxL = alHeapAlloc(heap, 1, sizeof(*voiceGroup->fxL));
        voiceGroup->fxR = alHeapAlloc(heap, 1, sizeof(*voiceGroup->fxR));
        func_80058E84(voiceGroup->fxL, voiceGroup->currentEffectType, heap);
        func_80058E84(voiceGroup->fxR, voiceGroup->currentEffectType, heap);
    }

    gSynDriverPtr->savedMainOut = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    gSynDriverPtr->savedAuxOut = alHeapAlloc(heap, 2 * AUDIO_SAMPLES, 2);
    AuDelayedVoiceGroup = 0;
    AuDelayedChannel = 0;
    AuDelayCount = 4;

    AuDelayBufferMain = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    AuDelayBufferAux = alHeapAlloc(heap, 4 * AUDIO_SAMPLES, 2);
    for (i = 0; i < 4 * AUDIO_SAMPLES; i++) {
        AuDelayBufferAux[i] = AuDelayBufferMain[i] = 0;
    }

    gSynDriverPtr->heap = heap;
}

void au_driver_release(void) {
    if (gActiveSynDriverPtr != NULL) {
        gActiveSynDriverPtr = NULL;
    }
}

Acmd* alAudioFrame(Acmd* cmdList, s32* cmdLen, s16* outBuf, s32 outLen) {
    Acmd* cmdListPos;
    AuPVoice* pvoice;
    AuPVoiceGroup* voiceGroup;

    s16* bufPos;
    s16 auxOut;
    s16 mainOut;

    s32 i;
    s32 first = FALSE;

    cmdListPos = cmdList;
    bufPos = outBuf;
    if (gActiveSynDriverPtr == NULL) {
        *cmdLen = 0;
    } else {
        au_update_players_main();
        if (AuSynStereoDirty) {
            for (i = 0; i < gSynDriverPtr->num_pvoice; i++) {
                pvoice = &gSynDriverPtr->pvoices[i];
                if (pvoice->envMixer.motion == AL_PLAYING) {
                    au_syn_set_pan(i, pvoice->envMixer.pan);
                }
            }
            AuSynStereoDirty = FALSE;
        }
        while (outLen > 0) {
            au_update_clients_2();
            for (i = 0; i < gSynDriverPtr->num_pvoice; i++) {
                pvoice = &gSynDriverPtr->pvoices[i];

                if ((pvoice->groupID != 0xFF) && (pvoice->groupID < gSynDriverPtr->num_voice_groups)) {
                    voiceGroup = &gSynDriverPtr->voiceGroups[pvoice->groupID];
                    if (voiceGroup->tail != NULL) {
                        voiceGroup->tail->next = pvoice;
                    } else {
                        voiceGroup->head = pvoice;
                    }
                    voiceGroup->tail = pvoice;
                }
            }
            first = TRUE;
            for (i = 0; i < gSynDriverPtr->num_voice_groups; i++) {
                voiceGroup = &gSynDriverPtr->voiceGroups[i];
                if (voiceGroup->head != NULL) {
                    // clear all main and aux outputs
                    aClearBuffer(cmdListPos++, N_AL_MAIN_L_OUT, 8 * AUDIO_SAMPLES);
                    if (voiceGroup->head != NULL) {
                        AuPVoice* next;
                        do {
                            cmdListPos = au_pull_voice(voiceGroup->head, cmdListPos);
                            next = voiceGroup->head->next;
                            voiceGroup->head->next = NULL;
                            voiceGroup->head = next;
                        } while (next != NULL);
                        voiceGroup->tail = NULL;
                    }
                    if (voiceGroup->currentEffectType != AU_FX_NONE) {
                        cmdListPos = au_pull_fx(voiceGroup->fxL, cmdListPos, N_AL_AUX_L_OUT, 0);
                        cmdListPos = au_pull_fx(voiceGroup->fxR, cmdListPos, N_AL_AUX_R_OUT, 0);
                    }

                    // apply channel delay
                    if (i == AuDelayedVoiceGroup) {
                        mainOut = -1;
                        switch (AuDelayedChannel) {
                            case 1:
                                mainOut = N_AL_MAIN_L_OUT;
                                auxOut = N_AL_AUX_L_OUT;
                                break;
                            case 2:
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

                    // mix voice groups
                    if (first) {
                        aClearBuffer(cmdListPos++, 0, 4 * AUDIO_SAMPLES);
                    } else {
                        n_aLoadBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->savedAuxOut));
                    }
                    aMix(cmdListPos++, 0, voiceGroup->gain, N_AL_AUX_L_OUT, 0);
                    aMix(cmdListPos++, 0, voiceGroup->gain, N_AL_AUX_R_OUT, 2 * AUDIO_SAMPLES);
                    n_aSaveBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->savedAuxOut));
                    if (first) {
                        aClearBuffer(cmdListPos++, 0, 4 * AUDIO_SAMPLES);
                        first = FALSE;
                    } else {
                        n_aLoadBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->savedMainOut));
                    }
                    aMix(cmdListPos++, 0, voiceGroup->gain, N_AL_MAIN_L_OUT, 0);
                    aMix(cmdListPos++, 0, voiceGroup->gain, N_AL_MAIN_R_OUT, 2 * AUDIO_SAMPLES);
                    n_aSaveBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, 0, osVirtualToPhysical(gSynDriverPtr->savedMainOut));
                }
            }

            aDMEMMove(cmdListPos++, 0, N_AL_MAIN_L_OUT, 4 * AUDIO_SAMPLES);
            n_aLoadBuffer(cmdListPos++, 4 * AUDIO_SAMPLES, N_AL_AUX_L_OUT, osVirtualToPhysical(gSynDriverPtr->savedAuxOut));
            aMix(cmdListPos++, 0, 0x7FFF, N_AL_AUX_L_OUT, N_AL_MAIN_L_OUT);
            aMix(cmdListPos++, 0, 0x7FFF, N_AL_AUX_R_OUT, N_AL_MAIN_R_OUT);

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
    }
    return cmdListPos;
}

void au_use_global_volume(void) {
    AuUseGlobalVolume = TRUE;
}

void au_set_global_volume(s16 arg0) {
    AuGlobalVolume = arg0;
}

s16 au_get_global_volume(void) {
    return AuGlobalVolume;
}

void func_80056D5C(u8 bStereoSound) {
    AuSynUseStereo = bStereoSound;
    AuSynStereoDirty = TRUE;
}

void au_voice_group_set_gain(u8 index, u16 arg1) {
    AuPVoiceGroup* voiceGroup = &gSynDriverPtr->voiceGroups[index];

    voiceGroup->gain = arg1 & 0x7FFF;
}

u16 au_voice_group_get_gain(u8 index, u16 arg1) {
    AuPVoiceGroup* voiceGroup = &gSynDriverPtr->voiceGroups[index];

    return voiceGroup->gain;
}

void au_voice_group_set_effect(u8 index, u8 effectType) {
    AuPVoiceGroup* voiceGroup = &gSynDriverPtr->voiceGroups[index];

    voiceGroup->currentEffectType = effectType;
    func_8005904C(voiceGroup->fxL, effectType);
    func_8005904C(voiceGroup->fxR, effectType);
}

void au_voice_group_set_fx_params(u8 index, s16 delayIndex, s16 paramID, s32 value) {
    AuPVoiceGroup* voiceGroup = &gSynDriverPtr->voiceGroups[index];

    au_fx_param_hdl(voiceGroup->fxL, delayIndex, paramID, value);
    au_fx_param_hdl(voiceGroup->fxR, delayIndex, paramID, value);
}

void au_pvoice_set_group(u8 index, s8 groupID) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[index];

    pvoice->groupID = groupID;
}

// based on n_alSynStopVoice
void au_syn_stop_voice(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* decoder = &pvoice->decoder;

    pvoice->envMixer.motion = AL_STOPPED;
    pvoice->envMixer.first = 1;
    pvoice->envMixer.volume = 1;
    pvoice->resampler.delta = 0;
    pvoice->resampler.first = 1;
    decoder->lastsam = 0;
    decoder->first = 1;
    decoder->sample = 0;
    if (decoder->instrument != NULL) {
        decoder->memin = (s32)decoder->instrument->base;
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
void au_syn_start_voice_params(u8 voiceIdx, u8 groupIdx, Instrument* instrument, f32 pitch, s16 vol, u8 pan, u8 fxMix, s32 delta) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* decoder = &pvoice->decoder;
    AuEnvMixer* envMixer = &pvoice->envMixer;
    AuResampler* resampler = &pvoice->resampler;

    pvoice->groupID = groupIdx;
    decoder->instrument = instrument;

    pvoice->decoder.memin = (s32)decoder->instrument->base;
    pvoice->decoder.sample = 0;

    switch (decoder->instrument->type) {
        case AL_ADPCM_WAVE:
            decoder->instrument->wavDataLength = (decoder->instrument->wavDataLength / ADPCMFBYTES) * ADPCMFBYTES;
            pvoice->decoder.bookSize = decoder->instrument->dc_bookSize;
            if (decoder->instrument->loopEnd == 0) {
                decoder->loop.count = 0;
                decoder->loop.end = 0;
                decoder->loop.start = 0;
            } else {
                decoder->loop.start = decoder->instrument->loopStart;
                decoder->loop.end = decoder->instrument->loopEnd;
                decoder->loop.count = decoder->instrument->loopCount;
                alCopy(decoder->instrument->loopPredictor, decoder->lstate, sizeof(ADPCM_STATE));
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
    envMixer->first = 1;
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
    resampler->ratio = pitch;
}

void au_syn_set_wavetable(u8 voiceIdx, Instrument* instrument) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];
    AuLoadFilter* decoder = &pvoice->decoder;

    pvoice->decoder.instrument = instrument;
    pvoice->decoder.memin = (s32)decoder->instrument->base;
    pvoice->decoder.sample = 0;

    switch (decoder->instrument->type) {
        case AL_ADPCM_WAVE:
            decoder->instrument->wavDataLength = (decoder->instrument->wavDataLength / ADPCMFBYTES) * ADPCMFBYTES;
            pvoice->decoder.bookSize = decoder->instrument->dc_bookSize;
            if (decoder->instrument->loopEnd == 0) {
                pvoice->decoder.loop.count = 0;
                pvoice->decoder.loop.end = 0;
                pvoice->decoder.loop.start = 0;
            } else {
                pvoice->decoder.loop.start = decoder->instrument->loopStart;
                pvoice->decoder.loop.end = decoder->instrument->loopEnd;
                pvoice->decoder.loop.count = decoder->instrument->loopCount;
                alCopy(decoder->instrument->loopPredictor, pvoice->decoder.lstate, sizeof(ADPCM_STATE));
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
    envMixer->first = 1;
}

void func_80057548(u8 voiceIdx, u8 pan, u8 fxMix) {
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
    envMixer->first = 1;
}

void func_800576EC(u8 voiceIdx, s16 vol, s32 delta) {
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
    envMixer->first = 1;
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
    envMixer->first = 1;
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
    envMixer->first = 1;
}

s32 func_80057B64(u8 voiceIdx) {
    AuPVoice* pvoice = &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.motion;
}

s32 func_80057B8C(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->groupID;
}

f32 func_80057BB4(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->resampler.ratio;
}

u8 func_80057BDC(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.pan;
}

s16 func_80057C04(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.dryamt;
}

s16 func_80057C2C(u8 voiceIdx) {
    AuPVoice* pvoice =  &gSynDriverPtr->pvoices[voiceIdx];

    return pvoice->envMixer.wetamt;
}

s32 func_80057C54(u8 voiceIdx) {
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

s32 func_80057D0C(u8 voiceIdx) {
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

void au_set_delay_time(s32 arg0) {
    if (arg0 < 2) {
        AuDelayCount = 0;
        AuDelayedChannel = 0;
    }

    AuDelayCount = arg0;
    if (arg0 > 4) {
        AuDelayCount = 4;
    }
}

void au_delay_left_channel(u8 groupIdx) {
    s32* phi_a1 = (s32*)AuDelayBufferMain;
    s32* phi_v1 = (s32*)AuDelayBufferAux;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    AuDelayedVoiceGroup = groupIdx;
    AuDelayedChannel = 1;
    AuDelayCounter = 0;
}

void au_delay_right_channel(u8 groupIdx) {
    s32* phi_a1 = (s32*)AuDelayBufferMain;
    s32* phi_v1 = (s32*)AuDelayBufferAux;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    AuDelayedVoiceGroup = groupIdx;
    AuDelayedChannel = 2;
    AuDelayCounter = 0;
}

void au_disable_channel_delay(void) {
    AuDelayedVoiceGroup = 0;
    AuDelayedChannel = 0;
    AuDelayCounter = 0;
}

void au_delay_channel(s16 arg0) {
    s32* phi_a1 = (s32*)AuDelayBufferMain;
    s32* phi_v1 = (s32*)AuDelayBufferAux;
    s32 i;

    for (i = 0; i < 2 * AUDIO_SAMPLES; i++) {
        *phi_a1++ = 0;
        *phi_v1++ = 0;
    }

    AuDelayedVoiceGroup = 0;
    AuDelayedChannel = arg0;
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
    void* ret = NULL;
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
