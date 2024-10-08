#include "common.h"
#include "audio.h"

void au_update_stopped_voices(AuGlobals* globals) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AuVoice* voice = &globals->voices[i];

        if (voice->stopPending) {
            au_syn_stop_voice(i);
            voice->stopPending = FALSE;
            voice->cmdPtr = NULL;
            voice->priority = AU_PRIORITY_FREE;
        }
    }
}

void au_init_voices(AuGlobals* globals) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AuVoice* voice = &globals->voices[i];

        voice->cmdPtr = NULL;
        voice->unk_20 = 0;
        voice->volChangeTime = 0;
        voice->timeLeft = 0;
        voice->timeIntervalIndex = 0;
        voice->unk_3C = 0;
        voice->envelopeFlags = 0;
        voice->relativeReleaseVolumes = FALSE;
        voice->releaseVolumeMult = 0x80;
    }
}

void au_update_voices(AuGlobals* globals) {
    AuVoice* voice;
    s8 var_a0;
    s16 currentAmp;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        voice = &globals->voices[i];
        if (voice->cmdPtr == NULL) {
            continue;
        }
        if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE) {
            // client volume changed on previous frame
            au_voice_after_volume_change(voice);
            continue;
        }
        if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_KEY_RELEASED) {
            // client released the key
            voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_KEY_RELEASED;
            voice->envelopeFlags |= AU_VOICE_ENV_FLAG_STOP;
            voice->cmdPtr = (u8*)voice->envelope.cmdListRelease;

            // the key can be released before press cmdlist processed completely, we must handle this case properly
            if (voice->timeLeft > AU_5750) {
                voice->initialAmp = voice->initialAmp + (s32) (voice->rate * (f32) (voice->volChangeTime - voice->timeLeft));
            } else {
                voice->initialAmp = voice->targetAmp;
            }

            voice->timeIntervalIndex = *voice->cmdPtr++;
            var_a0 = *voice->cmdPtr;
            if (*(s8*)voice->cmdPtr++ < 0) {
                // in this case release volumes are relative to last press volume
                var_a0 &= 0x7F;
                voice->relativeReleaseVolumes = TRUE;
                voice->releaseVolumeMult = voice->initialAmp;
            }
            voice->targetAmp = var_a0;

            voice->timeLeft = AuEnvelopeIntervals[voice->timeIntervalIndex];
            voice->volChangeTime = voice->timeLeft;
            if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                if (voice->timeLeft > AU_5750) {
                    voice->timeLeft -= AU_5750;
                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
                    currentAmp = voice->initialAmp + (s32) (voice->rate * (voice->volChangeTime - voice->timeLeft));
                } else {
                    currentAmp = voice->targetAmp;
                }
                voice->delta = AUDIO_SAMPLES;
            } else {
                voice->delta = au_voice_get_delta(voice->volChangeTime);
                currentAmp = voice->targetAmp;
            }
            voice->p_volume = (((currentAmp * voice->clientVolume * voice->releaseVolumeMult) >> 0xE) * voice->volMult) >> 7;
            voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
        } else {
            if (voice->timeLeft == -1) {
                // keep current volume, this is 'sustain' phase
                if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                    voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                    voice->p_volume = (((voice->initialAmp * voice->clientVolume * voice->releaseVolumeMult) >> 0xE) * voice->volMult) >> 7;
                    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
                }
            } else {
                voice->timeLeft -= AU_5750;
                if (voice->timeLeft <= 0) {
                    if (*voice->cmdPtr == ENV_CMD_END) {
                        if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_STOP) {
                            // if we reached the end after key release, stop the voice completely
                            voice->envelopeFlags = 0;
                            voice->cmdPtr = NULL;
                            voice->stopPending = TRUE;
                        } else {
                            // we reached the end of press cmdlist, keep the last volume until the key is released
                            voice->timeLeft = -1;
                            voice->volChangeTime = -1;
                            voice->timeIntervalIndex = ENV_TIME_300MS; // doesn't seem to affect anything
                            voice->delta = AUDIO_SAMPLES;
                            voice->rate = 0.0f;
                            voice->initialAmp = voice->targetAmp;
                        }
                    } else {
                        // get next envelope point
                        voice->timeIntervalIndex = au_voice_step(voice);
                        voice->initialAmp = voice->targetAmp;
                        voice->targetAmp = (*voice->cmdPtr++) & 0x7F;
                        voice->timeLeft = AuEnvelopeIntervals[voice->timeIntervalIndex];
                        voice->volChangeTime = voice->timeLeft;
                        if (voice->volChangeTime != 0) {
                            voice->rate = ((f32) voice->targetAmp - (f32) voice->initialAmp) / (f32) voice->volChangeTime;
                        } else {
                            voice->rate = 0.0f;
                        }
                        if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                            voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                            if (voice->timeLeft > AU_5750) {
                                voice->timeLeft -= AU_5750;
                                voice->envelopeFlags |= AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
                                currentAmp = voice->initialAmp + (s32) (voice->rate * (voice->volChangeTime - voice->timeLeft));
                            } else {
                                currentAmp = voice->targetAmp;
                            }
                            voice->delta = AUDIO_SAMPLES;
                        } else {
                            voice->delta = au_voice_get_delta(voice->volChangeTime);
                            currentAmp = voice->targetAmp;
                        }
                        voice->p_volume = (((currentAmp * voice->clientVolume * voice->releaseVolumeMult) >> 0xE) * voice->volMult) >> 7;
                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
                    }
                } else {
                    // we are between two envelope points, do nothing, just handle client volume change
                    if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                        voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                        if (voice->timeLeft > AU_5750) {
                            voice->timeLeft -= AU_5750;
                            voice->envelopeFlags |= AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
                            currentAmp = voice->initialAmp + (s32) (voice->rate * (voice->volChangeTime - voice->timeLeft));
                        } else {
                            currentAmp = voice->targetAmp;
                        }
                        voice->delta = AUDIO_SAMPLES;
                        voice->p_volume = (((currentAmp * voice->clientVolume * voice->releaseVolumeMult) >> 0xE) * voice->volMult) >> 7;
                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
                    }
                }
            }
        }
    }
}

void au_voice_after_volume_change(AuVoice* voice) {
    voice->p_volume = (((voice->targetAmp * voice->clientVolume * voice->releaseVolumeMult) >> 14) * voice->volMult) >> 7;
    voice->delta = au_voice_get_delta(voice->timeLeft);
    voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
}

s32 au_voice_get_delta(s32 msecs) {
    return (msecs / AU_5750) * AUDIO_SAMPLES;
}

void au_voice_start(AuVoice* voice, EnvelopeData* envData) {
    s32 intervalIndex;

    voice->envelope.cmdListPress = envData->cmdListPress;
    voice->cmdPtr = voice->envelope.cmdListPress;
    voice->envelope.cmdListRelease = envData->cmdListRelease;
    voice->volMult = 0x80;
    voice->loopStart = NULL;

    intervalIndex = au_voice_step(voice);
    voice->envelopeFlags = 0;
    voice->initialAmp = 0;
    voice->targetAmp = *voice->cmdPtr++;
    voice->timeIntervalIndex = intervalIndex;
    voice->volChangeTime = AuEnvelopeIntervals[intervalIndex];
    voice->timeLeft = voice->volChangeTime;

    voice->p_volume = (voice->targetAmp * voice->clientVolume * voice->volMult) >> 14;
    voice->delta = au_voice_get_delta(voice->volChangeTime);
    if (voice->volChangeTime != 0) {
        voice->rate = ((f32) voice->targetAmp - (f32) voice->initialAmp) / voice->volChangeTime;
    } else {
        voice->rate = 0.0f;
    }
    voice->relativeReleaseVolumes = FALSE;
    voice->releaseVolumeMult = 0x80;
}

// performs special commands and returns interval index
u8 au_voice_step(AuVoice* voice) {
    u32 op;
    u8 arg;

    while (TRUE) {
        if (((s8)(op = *voice->cmdPtr++)) >= 0) {
            break;
        }
        switch ((u8)op) {
            case ENV_CMD_SET_MULTIPLIER:
                arg = *voice->cmdPtr++;
                if (arg > 0x80) {
                    arg = 0x80;
                }
                voice->volMult = arg;
                break;
            case ENV_CMD_ADD_MULTIPLIER:
                voice->volMult += (s8) *voice->cmdPtr++;
                if (voice->volMult > 0x80) {
                    voice->volMult = 0x80;
                } else if (voice->volMult < 0) {
                    voice->volMult = 0;
                }
                break;
            case ENV_CMD_START_LOOP:
                voice->loopCounter = *voice->cmdPtr++; // 0 means infinite loop
                voice->loopStart = voice->cmdPtr;
                break;
            case ENV_CMD_END_LOOP:
                voice->cmdPtr++;
                if (voice->loopCounter == 0 || --voice->loopCounter != 0) {
                    voice->cmdPtr = voice->loopStart;
                }
                break;
            default:
                voice->cmdPtr++;
                break;
        }
    }
    return op;
}

void au_voice_set_vol_changed(AuVoice* voice) {
    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
}
