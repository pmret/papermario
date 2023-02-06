#include "audio.h"

extern u8 BlankMseqData[];

#define TRACK_ID_DRUM 9

enum AmbientMode {
    AMB_MODE_NORMAL         = 0,
    AMB_MODE_RESUMING       = 1,
    AMB_MODE_STOPPED        = 2,
    AMB_MODE_PAUSING        = 3
};

enum AmbientFadeState {
    AMB_FADE_IN             = 0,
    AMB_FADE_OUT            = 1,
    AMB_FADE_OUT_PAUSING    = 2,
};

enum AmbientPlayState {
    AMB_PLAYER_PLAYING      = 0,
    AMB_PLAYER_STOPPED      = 1,
    AMB_PLAYER_STOPPING     = 2
};

enum MSEQCommand {
    MSEQ_CMD_80_STOP_SOUND          = 0x80,
    MSEQ_CMD_90_PLAY_SOUND          = 0x90,
    MSEQ_CMD_A0_SET_VOLUME_PAN      = 0xA0,
    MSEQ_CMD_B0_MULTI               = 0xB0,
    MSEQ_CMD_C0_SET_INSTRUMENT      = 0xC0,
    MSEQ_CMD_E0_TUNING              = 0xE0,
    MSEQ_CMD_SUB_66_START_LOOP      = 0x66,
    MSEQ_CMD_SUB_67_END_LOOP        = 0x67,
    MSEQ_CMD_SUB_68_SET_REVERB      = 0x68,
    MSEQ_CMD_SUB_69_SET_RESUMABLE   = 0x69,
};

void au_amb_manager_init(AmbienceManager* manager, s8 priority, s8 busId, AuGlobals* globals) {
    AmbiencePlayer* player;
    s32 i;

    au_memset(manager, sizeof(*manager), 0);

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        player = &manager->players[i];
        player->id.playerIndex = i;
        player->delay = 1;
        player->fadeVolume = 0x7F000000;
    }

    manager->globals = globals;
    manager->nextUpdateStep = 1;
    manager->nextUpdateCounter = 2;
    manager->nextUpdateInterval = 2;
    manager->priority = priority;
    manager->busId = busId;
}

AuResult au_amb_check_player_index(u32 index) {
    if (gAuAmbienceManager->numActivePlayers <= index) {
        return AU_AMBIENCE_ERROR_3;
    } else {
        return AU_RESULT_OK;
    }
}

void au_amb_load_tracks_fade(s32 arg0, s32 arg1) {
    gAuAmbienceManager->loadTracksFadeInfo = arg1;
}

void au_amb_set_disabled(s32 index, s32 disable) {
    AmbienceManager* manager = gAuAmbienceManager;
    AmbiencePlayer* ambPlayer = &manager->players[index];

    if (!disable) {
        ambPlayer->playState = AMB_PLAYER_PLAYING;
    } else {
        ambPlayer->playState = AMB_PLAYER_STOPPING;
    }
}

AuResult au_amb_start(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];
    MSEQHeader* mseq = gAuAmbienceManager->mseqFiles[index];
    AuResult status = AU_RESULT_OK;

    if (mseq != NULL) {
        if (player->mseqName == 0) {
            au_amb_play_sequence(gAuAmbienceManager, mseq, index);
            if (time != 0) {
                player->fadeSettingsTime = time;
                player->fadeSettingsInitial = 0;
                player->fadeSettingsGoal = 127;
                player->fadeSettingsType = AMB_FADE_IN;
                au_amb_fade_setup(player);
            }
        } else {
            status = AU_AMBIENCE_ERROR_1;
        }
    } else {
        status = AU_AMBIENCE_ERROR_2;
    }
    return status;
}

void au_amb_fade_setup(AmbiencePlayer* player) {
    u16 time = player->fadeSettingsTime;

    if (player->fadeSettingsInitial == 255) {
        player->fadeSettingsInitial = player->fadeVolume >> 0x18;
    }

    if (time >= SND_MIN_DURATION && time <= SND_MAX_DURATION) {
        player->fadeVolume = player->fadeSettingsInitial << 0x18;
        player->fadeGoal = player->fadeSettingsGoal;
        player->fadeTime = (u32)(time * 10) / 115; // TODO figure out why is the ratio like this
        player->fadeStep = ((player->fadeSettingsGoal - player->fadeSettingsInitial) << 0x18) / ((s16)player->fadeTime & 0xFFFF);
    }

    player->fadeSettingsTime = 0;
    player->fadeSettingsInitial = 0;
    player->fadeSettingsGoal = 0;
}

void au_amb_pause(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != NULL && player->mseqReadPos != NULL) {
        if (time != 0) {
            player->fadeSettingsInitial = 255;
            player->fadeSettingsTime = time;
            player->fadeSettingsGoal = 0;
            player->fadeSettingsType = AMB_FADE_OUT_PAUSING;
            return;
        }
        player->mode = AMB_MODE_PAUSING;
    }
}

void au_amb_resume(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != NULL && player->mseqReadPos != NULL) {
        player->mode = AMB_MODE_RESUMING;
        if (time != 0) {
            player->fadeSettingsTime = time;
        } else {
            player->fadeSettingsTime = SND_MIN_DURATION;
        }
        player->fadeSettingsInitial = 0;
        player->fadeSettingsGoal = SND_MAX_VOLUME_8;
        player->fadeSettingsType = AMB_FADE_IN;
    }
}

void au_amb_stop_quick(s32 index) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != NULL && player->mseqReadPos != NULL) {
        if (player->mode != AMB_MODE_NORMAL) {
            player->mseqReadPos = NULL;
            player->mseqName = 0;
            player->mode = AMB_MODE_NORMAL;
            return;
        }
        player->mseqReadPos = BlankMseqData;
        player->delay = 1;
    }
}

void au_amb_stop_slow(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != NULL && player->mseqReadPos != NULL) {
        if (time != 0) {
            player->fadeSettingsTime = time;
        } else {
            player->fadeSettingsTime = SND_MIN_DURATION;
        }
        player->fadeSettingsInitial = 255;
        player->fadeSettingsGoal = 0;
        player->fadeSettingsType = AMB_FADE_OUT;
    }
}

void au_amb_set_volume(s32 index, s32 time, s32 volume) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];
    if ((player->mseqReadStart != 0) && (player->mseqReadPos != 0)) {
        if (volume <= 0) {
            volume = 1;
        } else if (volume > SND_MAX_VOLUME_8) {
            volume = SND_MAX_VOLUME_8;
        }
        if (time != 0) {
            player->fadeSettingsTime = time;
        } else {
            player->fadeSettingsTime = SND_MIN_DURATION;
        }
        player->fadeSettingsInitial = 255;
        player->fadeSettingsGoal = volume;
        player->fadeSettingsType = AMB_FADE_IN;
    }
}

AuResult au_amb_is_stopped(s32 index) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];
    AuResult status = AU_RESULT_OK;

    if (player->mseqReadStart != NULL && player->mseqReadPos != NULL) {
        status = AU_AMBIENCE_ERROR_1;
        if (player->mode != AMB_MODE_NORMAL) {
            status = AU_AMBIENCE_ERROR_2;
        }
    }
    return status;
}

void au_amb_play_sequence(AmbienceManager* manager, MSEQHeader* mseqFile, s32 index) {
    AmbiencePlayer* player;
    AmbienceTrack* track;
    AuFilePos readPos;
    s32 i;

    player = &manager->players[index];
    au_memset(player, sizeof(*player), 0);

    player->mseqFile = mseqFile;
    readPos = AU_FILE_RELATIVE(mseqFile->dataStart, mseqFile);
    player->id.playerIndex = index;
    player->mseqReadPos = readPos;
    player->loopStartPos[1] = readPos;
    player->loopStartPos[0] = readPos;
    player->mseqReadStart = readPos;

    player->delay = 1;
    player->fadeVolume = 0x7F000000;
    player->fadeGoal = 0x7F;

    player->mseqName = player->mseqFile->name;
    player->firstVoiceIdx = player->mseqFile->firstVoiceIdx;
    player->lastVoiceIdx = player->firstVoiceIdx + 16;
    if (player->lastVoiceIdx > 24) {
        player->lastVoiceIdx = 24;
    }
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        track = &player->tracks[i];
        track->instrument = manager->globals->defaultInstrument;
        track->volumeLerp.current = 0x7FFFFFFF;
        track->pan = 64;
    }
    player->resetRequired = TRUE;
}

void au_amb_manager_update(AmbienceManager* manager) {
    u32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(manager->voiceStates); i++) {
        AmbienceVoiceState* voiceState = &manager->voiceStates[i];

        if (voiceState->info.released == TRUE && manager->globals->voices[i].priority != manager->priority) {
            voiceState->info.all = 0;
        }
    }

    for (j = 0; j < ARRAY_COUNT(manager->players); j++) {
        AmbiencePlayer* player = &manager->players[j];
        s32 mode;

        if (player->mseqReadPos != NULL) {
            if (manager->loadTracksFadeInfo) {
                au_amb_load_track_fade_info(manager, player);
            }

            mode = player->mode;
            if (mode != AMB_MODE_NORMAL) {
                if (mode == AMB_MODE_PAUSING) {
                    player->mode = AMB_MODE_STOPPED;
                    au_amb_save_voices(manager, player);
                    au_amb_player_stop(manager, player);
                } else if (player->mode == AMB_MODE_RESUMING) {
                    player->mode = AMB_MODE_NORMAL;
                    if (player->fadeSettingsTime != 0) {
                        au_amb_fade_setup(player);
                    }
                    au_amb_restore_voices(manager, player);
                }
            } else {
                // case AMB_MODE_NORMAL
                if (player->fadeSettingsTime != 0) {
                    au_amb_fade_setup(player);
                }
                if (player->playState == AMB_PLAYER_STOPPING) {
                    au_amb_player_stop(manager, player);
                    player->playState = AMB_PLAYER_STOPPED;
                }
                au_amb_player_update(manager, player);
            }
        }
    }

    manager->loadTracksFadeInfo = FALSE;
}

void au_amb_load_track_fade_info(AmbienceManager* manager, AmbiencePlayer* player) {
    MSEQHeader* mseqFile;
    MSEQTrackData* trackData;
    AmbienceTrack* track;
    s32 offset;
    s32 count;

    mseqFile = player->mseqFile;
    count = mseqFile->trackSettingsCount;
    if (count != 0 && mseqFile->trackSettingsOffset != 0) {
        trackData = AU_FILE_RELATIVE(mseqFile->trackSettingsOffset, mseqFile);
        while (count--) {
            track = &player->tracks[trackData->trackIndex];
            if (trackData->type == 0) {
                track->tuneLerp.time = trackData->time;
                track->tuneLerp.step = (trackData->delta << 0x10) / trackData->time;
                track->tuneLerp.goal = trackData->goal;
            } else if (trackData->type == 1) {
                track->volumeLerp.time = trackData->time;
                track->volumeLerp.step = (trackData->delta << 0x10) / trackData->time;
                track->volumeLerp.goal = trackData->goal;
            }
            trackData++;
        }
    }
}

void au_amb_player_update(AmbienceManager* manager, AmbiencePlayer* player) {
    u8 isVolumeChanged[16];
    u8 isPitchChanged[16];
    AuGlobals* globals;
    u8 fadeVolChanged;
    AmbienceVoiceState* voiceState;
    AuVoice* voice;
    BGMDrumInfo* drum;
    u32 trackIdx;
    s32 temp;
    s32 i;
    u16 bankPatch;
    u32 count;
    s32 loopId;
    u8 op, arg1, arg2;
    AmbienceTrack* track;

    globals = manager->globals;
    fadeVolChanged = FALSE;
    for (i = 0; i < 16U; i++) { // required to use unsigned literal
        isVolumeChanged[i] = FALSE;
        isPitchChanged[i] = FALSE;
    }

    if (player->resetRequired == TRUE) {
        au_amb_player_stop(manager, player);
        player->resetRequired = FALSE;
    }

    if (player->fadeTime != 0) {
        player->fadeVolume += player->fadeStep;
        player->fadeTime--;
        if (player->fadeTime == 0) {
            player->fadeVolume = player->fadeGoal << 0x18;
            if (player->fadeSettingsType == AMB_FADE_IN) {
                // do nothing
            } else if (player->fadeSettingsType == AMB_FADE_OUT) {
                player->mseqReadPos = BlankMseqData;
                player->delay = 1;
            } else if (player->fadeSettingsType == AMB_FADE_OUT_PAUSING) {
                player->mode = AMB_MODE_PAUSING;
            }
        }
        fadeVolChanged = TRUE;
    }

    // update pitch
    for (trackIdx = 0; trackIdx < ARRAY_COUNT(player->tracks); trackIdx++) {
        track = &player->tracks[trackIdx];
        if (track->tuneLerp.time != 0) {
            track->tuneLerp.time--;
            if (track->tuneLerp.time != 0) {
                track->tuneLerp.current += track->tuneLerp.step;
            } else {
                track->tuneLerp.current = track->tuneLerp.goal << 0x10;
            }

            temp = player->id.all + (trackIdx << 0x10);
            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                // update all voices belonging to current track
                if ((voiceState->info.all & 0xFFFF0000) == temp) {
                    voice = &globals->voices[i];
                    if (voice->priority == manager->priority && trackIdx != TRACK_ID_DRUM) {
                        voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 0x10)) * track->instrument->pitchRatio;
                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                        isPitchChanged[i - player->firstVoiceIdx] = TRUE;
                    }
                }
            }
        }
    }

    // update volume
    for (trackIdx = 0; trackIdx < ARRAY_COUNT(player->tracks); trackIdx++) {
        track = &player->tracks[trackIdx];
        if (track->volumeLerp.time != 0) {
            track->volumeLerp.time--;
            if (track->volumeLerp.time != 0) {
                track->volumeLerp.current += track->volumeLerp.step;
            } else {
                track->volumeLerp.current = track->volumeLerp.goal << 0x10;
            }

            temp = player->id.all + (trackIdx << 0x10);
            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                // update all voices belonging to current track
                if ((voiceState->info.all & 0xFFFF0000) == temp) {
                    voice = &globals->voices[i];
                    if (voice->priority == manager->priority) {
                        track = &player->tracks[voiceState->info.trackIndex];
                        voice->clientVolume = ((player->fadeVolume >> 0x18) * (track->volumeLerp.current >> 0x10) * voiceState->volume) >> 0xE;
                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                    }
                }
            }
        }
    }

    player->delay--;
    if (player->delay <= 0) {
        while (player->delay == 0) {
            op = au_amb_read_next(player);
            if ((s8)op >= 0) {
                if (op == 0) {
                    // stop
                    player->mseqReadPos = NULL;
                    player->mseqName = 0;
                    au_amb_player_stop(manager, player);
                    break;
                }
                if (op >= 0x78) {
                    // long delay
                    player->delay = ((op & 7) << 8) + au_amb_read_next(player) + 0x78;
                } else {
                    //short delay
                    player->delay = op;
                }
                continue;
            }

            // op >= 0x80
            // op & 0xF0 : command
            // op & 0xF : track index

            arg1 = au_amb_read_next(player);
            trackIdx = op & 0xF;
            track = &player->tracks[trackIdx];

            switch (op & 0xF0) {
                case MSEQ_CMD_80_STOP_SOUND:
                    // arg1: sound index
                    if (player->playState == AMB_PLAYER_PLAYING) {
                        temp = player->id.all + (trackIdx << 0x10) + (arg1 << 8);
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            if (manager->voiceStates[i - player->firstVoiceIdx].info.all == temp) {
                                manager->voiceStates[i - player->firstVoiceIdx].info.released = 1;
                                voice = &globals->voices[i];
                                if (voice->priority == manager->priority) {
                                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
                                }
                            }
                        }
                    }
                    break;
                case MSEQ_CMD_90_PLAY_SOUND:
                    // arg1: pitch or drum sound id
                    // arg2: volume
                    arg2 = au_amb_read_next(player);
                    if (player->playState == AMB_PLAYER_PLAYING) {
                        // find free voice
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            voice = &globals->voices[i];
                            if (voice->priority == AU_PRIORITY_FREE) {
                                break;
                            }
                        }
                        if (i >= player->lastVoiceIdx) {
                            // use another ambience voice
                            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                                voice = &globals->voices[i];
                                if (voice->priority == manager->priority) {
                                    au_reset_voice(voice, i);
                                    break;
                                }
                            }
                        }
                        if (i >= player->lastVoiceIdx) {
                            // try stealing voice with lower priority
                            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                                voice = &globals->voices[i];
                                if (voice->priority < manager->priority) {
                                    au_reset_voice(voice, i);
                                    break;
                                }
                            }
                        }
                        if (i < player->lastVoiceIdx) {
                            isVolumeChanged[i - player->firstVoiceIdx] = TRUE;
                            isPitchChanged[i - player->firstVoiceIdx] = TRUE;
                            voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                            // set playerIndex, trackIndex and tune
                            voiceState->info.all = player->id.all + (trackIdx << 0x10) + (arg1 << 8);
                            if (track->flags & 1) {
                                voiceState->isResumable = TRUE;
                            } else {
                                voiceState->isResumable = FALSE;
                            }
                            if (trackIdx != TRACK_ID_DRUM) {
                                if (track->flags & 1) {
                                    voiceState->isResumable = TRUE;
                                } else {
                                    voiceState->isResumable = FALSE;
                                }

                                voiceState->pitch = (arg1 & 0x7F) * 100 - track->instrument->keyBase;
                                voiceState->volume = arg2 & 0x7F;
                                voice->clientVolume = ((player->fadeVolume >> 0x18) * (track->volumeLerp.current >> 0x10) * voiceState->volume) >> 0xE;
                                voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 0x10)) * track->instrument->pitchRatio;
                                voice->pan = track->pan;
                                voice->reverb = track->reverb;
                                voice->instrument = track->instrument;
                                voice->busId = manager->busId;
                                voice->envelope.cmdListPress = track->envelope.cmdListPress;
                                voice->envelope.cmdListRelease = track->envelope.cmdListRelease;
                            } else {
                                voiceState->isResumable = FALSE;
                                drum = &manager->globals->dataPER->drums[arg1 & 0x7F];
                                bankPatch = drum->bankPatch;
                                voice->instrument = au_get_instrument(manager->globals, bankPatch >> 8, bankPatch & 0xFF, &voice->envelope);
                                voiceState->pitch = drum->keyBase - voice->instrument->keyBase;
                                voiceState->volume = ((arg2 & 0x7F) * drum->volume) >> 7;
                                voice->clientVolume = ((player->fadeVolume >> 0x18) * (track->volumeLerp.current >> 0x10) * voiceState->volume) >> 0xE;
                                voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch) * voice->instrument->pitchRatio;
                                voice->pan = drum->pan;
                                voice->reverb = drum->reverb;
                                voice->busId = manager->busId;
                            }
                            voice->syncFlags = AU_VOICE_SYNC_FLAG_ALL;
                            voice->priority = manager->priority;
                            voice->clientPriority = voice->priority;
                        }
                    }
                    break;
                case MSEQ_CMD_A0_SET_VOLUME_PAN:
                    // higher bit: set pan (1) or volume (0)
                    // lower 7 bits: value
                    if (arg1 & 0x80) {
                        track->pan = arg1 & 0x7F;
                        temp = player->id.all + (trackIdx << 0x10);
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                            if ((voiceState->info.all & 0xFFFF0000) == temp) {
                                voice = &globals->voices[i];
                                if (voice->priority == manager->priority && trackIdx != TRACK_ID_DRUM) {
                                    voice->pan = track->pan;
                                    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PAN_FXMIX;
                                }
                            }
                        }
                    } else {
                        track->volumeLerp.current = arg1 << 0x18;
                        if (track->volumeLerp.current != 0) {
                            track->volumeLerp.current |= 0xFFFFFF;
                        }
                        temp = player->id.all + (trackIdx << 0x10);
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                            if ((voiceState->info.all & 0xFFFF0000) == temp) {
                                voice = &globals->voices[i];
                                if (voice->priority == manager->priority) {
                                    voice->clientVolume = ((player->fadeVolume >> 0x18) * (track->volumeLerp.current >> 0x10) * voiceState->volume) >> 0xE;
                                    if (!isVolumeChanged[i - player->firstVoiceIdx]) {
                                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                                        isVolumeChanged[i - player->firstVoiceIdx] = TRUE;
                                    }
                                }
                            }
                        }
                    }
                    break;
                case MSEQ_CMD_B0_MULTI:
                    // arg1: sub command
                    // arg2: depends on sub command
                    arg2 = au_amb_read_next(player);
                    switch (arg1) {
                        case MSEQ_CMD_SUB_66_START_LOOP:
                            // arg2: loop id
                            player->loopStartPos[arg2 & 1] = player->mseqReadPos;
                            break;
                        case MSEQ_CMD_SUB_67_END_LOOP:
                            // arg2 lower bit: loop id
                            // (arg2 & 0x7C) >> 2: loop count
                            loopId = arg2 & 1;
                            count = (arg2 & 0x7C) >> 2;
                            if (count != 0) {
                                if (player->loopCount[loopId] != 0) {
                                    player->loopCount[loopId]--;
                                    // if it's the last iteration then don't jump to the loop start
                                    if (player->loopCount[loopId] != 0) {
                                        player->mseqReadPos = player->loopStartPos[loopId];
                                    }
                                } else {
                                    // first iteration, set loop counter
                                    player->mseqReadPos = player->loopStartPos[loopId];
                                    player->loopCount[loopId] = count;
                                }
                            } else {
                                // infinite loop
                                player->mseqReadPos = player->loopStartPos[loopId];
                                player->loopCount[loopId] = 0;
                            }
                            break;
                        case MSEQ_CMD_SUB_68_SET_REVERB:
                            track->reverb = arg2;
                            break;
                        case MSEQ_CMD_SUB_69_SET_RESUMABLE:
                            if (arg2 == 1) {
                                track->flags |= 1;
                            }
                            break;
                    }
                    break;
                case MSEQ_CMD_C0_SET_INSTRUMENT:
                    // arg1: bank
                    // arg2: patch
                    arg2 = au_amb_read_next(player);
                    if (trackIdx != TRACK_ID_DRUM) {
                        track->instrument = au_get_instrument(manager->globals, arg1, arg2, &track->envelope);
                    }
                    break;
                case MSEQ_CMD_E0_TUNING:
                    // arg1: coarse tune
                    // arg2: fine tune
                    track->tuneLerp.current = (arg1 << 0x18) + (au_amb_read_next(player) << 0x10);
                    temp = player->id.all + (trackIdx << 0x10);
                    for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                        voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                        if ((voiceState->info.all & 0xFFFF0000) == temp) {
                            voice = &globals->voices[i];
                            if (voice->priority == manager->priority && trackIdx != TRACK_ID_DRUM) {
                                voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 0x10)) * track->instrument->pitchRatio;
                                voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                                isPitchChanged[i - player->firstVoiceIdx] = 1;
                            }
                        }
                    }
                    break;
                case 0xF0: // required to match
                    break;
            }
        }
    }
    if (fadeVolChanged) {
        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
            voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
            // update all voices belonging to this player
            if ((voiceState->info.all & 0xFF000000) == player->id.all) {
                voice = &globals->voices[i];
                if (voice->priority == manager->priority && !isVolumeChanged[i - player->firstVoiceIdx]) {
                    track = &player->tracks[voiceState->info.trackIndex];
                    voice->clientVolume = ((player->fadeVolume >> 0x18) * (track->volumeLerp.current >> 0x10) * voiceState->volume) >> 0xE;
                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                }
            }
        }
    }
}

u8 au_amb_read_next(AmbiencePlayer* state) {
    u8 value = *state->mseqReadPos++;
    return value;
}

void au_amb_player_stop(AmbienceManager* manager, AmbiencePlayer* player) {
    AuVoice* voice;
    AmbienceVoiceState* voiceState;
    s32 i;

    for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
        voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
        if (voiceState->info.playerIndex == player->id.playerIndex) {
            voice = &manager->globals->voices[i];
            if (voice->priority == manager->priority) {
                au_reset_voice(voice, i);
            }
            voiceState->info.all = 0;
        }
    }
}

void au_amb_save_voices(AmbienceManager* arg0, AmbiencePlayer* player) {
    AmbienceSavedVoice* savedVoice = player->savedVoices;
    u32 numSaved = 0;
    s32 i;

    for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
        AmbienceVoiceState* voiceState = &arg0->voiceStates[i - player->firstVoiceIdx];

        if (!voiceState->isResumable) {
            continue;
        }

        savedVoice->trackIndex = voiceState->info.trackIndex;
        savedVoice->tune = voiceState->info.tune;
        savedVoice->volume = voiceState->volume;

        savedVoice++;
        numSaved++;
        if (numSaved >= ARRAY_COUNT(player->savedVoices)) {
            break;
        }
    }
}

void au_amb_restore_voices(AmbienceManager* manager, AmbiencePlayer* player) {
    AuGlobals* globals;
    AuVoice* voice;
    AmbienceSavedVoice* savedVoice;
    AmbienceVoiceState* voiceState;
    AmbienceTrack* track;
    u32 i, j;

    globals = manager->globals;
    if (player->playState == AMB_PLAYER_PLAYING) {
        for (i = 0; i < ARRAY_COUNT(player->savedVoices); i++) {
            savedVoice = &player->savedVoices[i];
            if (savedVoice->tune != 0) {
                track = &player->tracks[savedVoice->trackIndex];

                // find first free voice
                for (j = player->firstVoiceIdx; j < player->lastVoiceIdx; j++) {
                    voice = &globals->voices[j];
                    if (voice->priority == AU_PRIORITY_FREE) {
                        break;
                    }
                }

                // try stealing a voice with lower priority
                if (j >= player->lastVoiceIdx) {
                    for (j = player->firstVoiceIdx; j < player->lastVoiceIdx; j++) {
                        voice = &globals->voices[j];
                        if (voice->priority < manager->priority) {
                            au_reset_voice(voice, j);
                            break;
                        }
                    }
                }

                if (j < player->lastVoiceIdx) {
                    voiceState = &manager->voiceStates[j - player->firstVoiceIdx];
                    voiceState->info.all = player->id.all + (savedVoice->trackIndex << 0x10) + (savedVoice->tune << 8);
                    voiceState->pitch = (savedVoice->tune & 0x7F) * 100 - track->instrument->keyBase;
                    voiceState->volume = savedVoice->volume & 0x7F;
                    voice->clientVolume = ((player->fadeVolume >> 0x18) * (track->volumeLerp.current >> 0x10) * voiceState->volume) >> 0xE;
                    voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 0x10)) * track->instrument->pitchRatio;
                    voice->pan = track->pan;
                    voice->reverb = track->reverb;
                    voice->instrument = track->instrument;
                    voice->busId = manager->busId;
                    voice->envelope.cmdListPress = track->envelope.cmdListPress;
                    voice->envelope.cmdListRelease = track->envelope.cmdListRelease;
                    voice->syncFlags = AU_VOICE_SYNC_FLAG_ALL;
                    voice->priority = manager->priority;
                    voice->clientPriority = voice->priority;
                }
            }
            savedVoice->trackIndex = 0;
            savedVoice->tune = 0;
            savedVoice->volume = 0;
        }
    }
}
