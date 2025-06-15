#include "audio.h"
#include "audio/core.h"

void au_flush_finished_voices(AuGlobals* globals) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AuVoice* voice = &globals->voices[i];

        if (voice->donePending) {
            au_syn_stop_voice(i);
            voice->donePending = FALSE;
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
        voice->unused_20 = 0;
        voice->envDuration = 0;
        voice->envTimeLeft = 0;
        voice->envIntervalIndex = 0;
        voice->unused_3C = 0;
        voice->envelopeFlags = 0;
        voice->isRelativeRelease = FALSE;
        voice->envRelativeStart = ENV_VOL_MAX;
    }
}

void au_update_voices(AuGlobals* globals) {
    AuVoice* voice;
    s16 current;
    s8 temp;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        voice = &globals->voices[i];

        // skip inactive voices
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
            voice->envelopeFlags |= AU_VOICE_ENV_FLAG_RELEASING;
            voice->cmdPtr = (u8*)voice->envelope.cmdListRelease;

            // the key can be released before the press envelope is complete
            if (voice->envTimeLeft > AU_FRAME_USEC) {
                // get interpolated "current" value
                voice->envInitial += (s32) (voice->envDelta * (f32) (voice->envDuration - voice->envTimeLeft));
            } else {
                voice->envInitial = voice->envTarget;
            }

            // read the first interval of the release envelope
            voice->envIntervalIndex = *voice->cmdPtr++;
            temp = *voice->cmdPtr;
            if (*(s8*)voice->cmdPtr++ < 0) {
                // in this case release volumes are relative to last press volume
                temp &= 0x7F;
                voice->isRelativeRelease = TRUE;
                voice->envRelativeStart = voice->envInitial;
            }
            voice->envTarget = temp;
            voice->envTimeLeft = AuEnvelopeIntervals[voice->envIntervalIndex];
            voice->envDuration = voice->envTimeLeft;

            if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                if (voice->envTimeLeft > AU_FRAME_USEC) {
                    voice->envTimeLeft -= AU_FRAME_USEC;
                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
                    current = voice->envInitial + (s32) (voice->envDelta * (voice->envDuration - voice->envTimeLeft));
                } else {
                    current = voice->envTarget;
                }
                voice->delta = AUDIO_SAMPLES;
            } else {
                voice->delta = au_voice_get_delta(voice->envDuration);
                current = voice->envTarget;
            }
            voice->volume = VOL_MULT_4(current, voice->clientVolume, voice->envRelativeStart, voice->envScale);
            voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
        } else {
            if (voice->envTimeLeft == -1) {
                // keep current volume, this is 'sustain' phase
                if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                    voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                    voice->volume = VOL_MULT_4(voice->envInitial, voice->clientVolume, voice->envRelativeStart, voice->envScale);
                    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
                }
            } else {
                voice->envTimeLeft -= AU_FRAME_USEC;
                if (voice->envTimeLeft <= 0) {
                    if (*voice->cmdPtr == ENV_CMD_END) {
                        if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_RELEASING) {
                            // if we reached the end after key release, stop the voice completely
                            voice->envelopeFlags = 0;
                            voice->cmdPtr = NULL;
                            voice->donePending = TRUE;
                        } else {
                            // we reached the end of press cmdlist, keep the last volume until the key is released
                            voice->envTimeLeft = -1;
                            voice->envDuration = -1;
                            voice->envIntervalIndex = ENV_TIME_300MS; // doesn't seem to affect anything
                            voice->delta = AUDIO_SAMPLES;
                            voice->envDelta = 0.0f;
                            voice->envInitial = voice->envTarget;
                        }
                    } else {
                        // get next envelope point
                        voice->envIntervalIndex = au_voice_step(voice);
                        voice->envInitial = voice->envTarget;
                        voice->envTarget = (*voice->cmdPtr++) & 0x7F;
                        voice->envTimeLeft = AuEnvelopeIntervals[voice->envIntervalIndex];
                        voice->envDuration = voice->envTimeLeft;
                        if (voice->envDuration != 0) {
                            voice->envDelta = ((f32) voice->envTarget - (f32) voice->envInitial) / (f32) voice->envDuration;
                        } else {
                            voice->envDelta = 0.0f;
                        }
                        if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                            voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                            if (voice->envTimeLeft > AU_FRAME_USEC) {
                                voice->envTimeLeft -= AU_FRAME_USEC;
                                voice->envelopeFlags |= AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
                                current = voice->envInitial + (s32) (voice->envDelta * (voice->envDuration - voice->envTimeLeft));
                            } else {
                                current = voice->envTarget;
                            }
                            voice->delta = AUDIO_SAMPLES;
                        } else {
                            voice->delta = au_voice_get_delta(voice->envDuration);
                            current = voice->envTarget;
                        }
                        voice->volume = VOL_MULT_4(current, voice->clientVolume, voice->envRelativeStart, voice->envScale);
                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
                    }
                } else {
                    // we are between two envelope points, do nothing, just handle client volume change
                    if (voice->envelopeFlags & AU_VOICE_ENV_FLAG_VOL_CHANGED) {
                        voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_VOL_CHANGED;
                        if (voice->envTimeLeft > AU_FRAME_USEC) {
                            voice->envTimeLeft -= AU_FRAME_USEC;
                            voice->envelopeFlags |= AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
                            current = voice->envInitial + (s32) (voice->envDelta * (voice->envDuration - voice->envTimeLeft));
                        } else {
                            current = voice->envTarget;
                        }
                        voice->delta = AUDIO_SAMPLES;
                        voice->volume = VOL_MULT_4(current, voice->clientVolume, voice->envRelativeStart, voice->envScale);
                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
                    }
                }
            }
        }
    }
}

void au_voice_after_volume_change(AuVoice* voice) {
    voice->volume = VOL_MULT_4(voice->envTarget, voice->clientVolume, voice->envRelativeStart, voice->envScale);
    voice->delta = au_voice_get_delta(voice->envTimeLeft);
    voice->envelopeFlags &= ~AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE;
    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PARAMS;
}

s32 au_voice_get_delta(s32 usecs) {
    return (usecs / AU_FRAME_USEC) * AUDIO_SAMPLES;
}

void au_voice_start(AuVoice* voice, EnvelopeData* envData) {
    s32 intervalIndex;

    voice->envelope.cmdListPress = envData->cmdListPress;
    voice->cmdPtr = voice->envelope.cmdListPress;
    voice->envelope.cmdListRelease = envData->cmdListRelease;
    voice->envScale = ENV_VOL_MAX;
    voice->loopStart = NULL;

    intervalIndex = au_voice_step(voice);
    voice->envelopeFlags = 0;
    voice->envInitial = 0;
    voice->envTarget = *voice->cmdPtr++;
    voice->envIntervalIndex = intervalIndex;
    voice->envDuration = AuEnvelopeIntervals[intervalIndex];
    voice->envTimeLeft = voice->envDuration;

    voice->volume = VOL_MULT_3(voice->envTarget, voice->clientVolume, voice->envScale);
    voice->delta = au_voice_get_delta(voice->envDuration);
    if (voice->envDuration != 0) {
        voice->envDelta = ((f32) voice->envTarget - (f32) voice->envInitial) / voice->envDuration;
    } else {
        voice->envDelta = 0.0f;
    }
    voice->isRelativeRelease = FALSE;
    voice->envRelativeStart = ENV_VOL_MAX;
}

u8 au_voice_step(AuVoice* voice) {
    u32 op;
    u8 arg;

    while (TRUE) {
        if ((s8)(op = *voice->cmdPtr++) >= 0) {
            break;
        }
        switch ((u8)op) {
            case ENV_CMD_SET_SCALE:
                arg = *voice->cmdPtr++;
                if (arg > ENV_VOL_MAX) {
                    arg = ENV_VOL_MAX;
                }
                voice->envScale = arg;
                break;
            case ENV_CMD_ADD_SCALE:
                voice->envScale += (s8) *voice->cmdPtr++;
                if (voice->envScale > ENV_VOL_MAX) {
                    voice->envScale = ENV_VOL_MAX;
                } else if (voice->envScale < 0) {
                    voice->envScale = 0;
                }
                break;
            case ENV_CMD_START_LOOP:
                voice->loopCounter = *voice->cmdPtr++; // 0 = infinite loop
                voice->loopStart = voice->cmdPtr;
                break;
            case ENV_CMD_END_LOOP:
                voice->cmdPtr++;
                if (voice->loopCounter == 0 || --voice->loopCounter != 0) {
                    voice->cmdPtr = voice->loopStart;
                }
                break;
            default:
                // unknown command, skip argument
                voice->cmdPtr++;
                break;
        }
    }
    return op;
}

void au_voice_set_vol_changed(AuVoice* voice) {
    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
}
