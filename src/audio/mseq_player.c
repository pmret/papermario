#include "audio.h"
#include "audio/core.h"

extern u8 BlankMseqData[];

#define TRACK_ID_DRUM 9

enum MseqMode {
    MSEQ_MODE_PLAYING       = 0,
    MSEQ_MODE_RESUMING      = 1,
    MSEQ_MODE_STOPPED       = 2,
    MSEQ_MODE_PAUSING       = 3,
};

enum MseqFadeState {
    MSEQ_FADE_IN            = 0,
    MSEQ_FADE_OUT           = 1,
    MSEQ_FADE_OUT_PAUSING   = 2,
};

enum MseqPlayState {
    MSEQ_PLAYER_PLAYING     = 0,
    MSEQ_PLAYER_STOPPED     = 1,
    MSEQ_PLAYER_STOPPING    = 2,
};

enum MseqTrackFlags {
    MSEQ_TRACK_RESUMABLE    = 1,
};

enum MseqCommand {
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

void au_mseq_manager_init(AmbienceManager* manager, s8 priority, s8 busID, AuGlobals* globals) {
    AmbiencePlayer* player;
    s32 i;

    au_memset(manager, sizeof(*manager), 0);

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        player = &manager->players[i];
        player->id.playerIndex = i;
        player->delay = 1;
        player->fadeVolume = AU_MAX_VOLUME_8 << 24;
    }

    manager->globals = globals;
    manager->nextUpdateStep = 1;
    manager->nextUpdateCounter = 2;
    manager->nextUpdateInterval = 2;
    manager->priority = priority;
    manager->busID = busID;
}

AuResult au_mseq_check_player_index(u32 index) {
    if (gAuAmbienceManager->numActivePlayers <= index) {
        return AU_AMBIENCE_ERROR_3;
    } else {
        return AU_RESULT_OK;
    }
}

void au_mseq_load_tracks_fade(s32 arg0, s32 arg1) {
    gAuAmbienceManager->loadTracksFadeInfo = arg1;
}

void au_mseq_set_disabled(s32 index, s32 disable) {
    AmbienceManager* manager = gAuAmbienceManager;
    AmbiencePlayer* player = &manager->players[index];

    if (!disable) {
        player->playState = MSEQ_PLAYER_PLAYING;
    } else {
        player->playState = MSEQ_PLAYER_STOPPING;
    }
}

AuResult au_mseq_start(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];
    MSEQHeader* mseq = gAuAmbienceManager->mseqFiles[index];
    AuResult status = AU_RESULT_OK;

    if (mseq != nullptr) {
        if (player->mseqName == 0) {
            au_mseq_play_sequence(gAuAmbienceManager, mseq, index);
            if (time != 0) {
                player->fadeSettingsTime = time;
                player->fadeSettingsInitial = 0;
                player->fadeSettingsGoal = AU_MAX_VOLUME_8;
                player->fadeSettingsType = MSEQ_FADE_IN;
                au_mseq_fade_setup(player);
            }
        } else {
            status = AU_AMBIENCE_ERROR_PLAYER_BUSY;
        }
    } else {
        status = AU_AMBIENCE_ERROR_MSEQ_NOT_FOUND;
    }
    return status;
}

void au_mseq_fade_setup(AmbiencePlayer* player) {
    u16 time = player->fadeSettingsTime;

    if (player->fadeSettingsInitial == 255) {
        player->fadeSettingsInitial = player->fadeVolume >> 24;
    }

    if (time >= SND_MIN_DURATION && time <= SND_MAX_DURATION) {
        player->fadeVolume = player->fadeSettingsInitial << 24;
        player->fadeGoal = player->fadeSettingsGoal;

        // converts a fade time in milliseconds to the number of player update ticks needed to complete the fade
        // the ambience manager updates every other audio frame, so given outputRate = 32000 and frameSize = 184,
        // update ticks needed = (32000 / 184) / 2, and then we divide by 1000 (since fade time has units of ms).
        // this reduces to 16/184, which is exactly 1.6 times 10/115
        // why this odd reduction was chosen unstead of 16/184 is unknown
        player->fadeTime = (u32)(time * 10) / 115;
        player->fadeStep = ((player->fadeSettingsGoal - player->fadeSettingsInitial) << 24) / ((s16)player->fadeTime & 0xFFFF);
    }

    player->fadeSettingsTime = 0;
    player->fadeSettingsInitial = 0;
    player->fadeSettingsGoal = 0;
}

void au_mseq_pause(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != nullptr && player->mseqReadPos != nullptr) {
        if (time != 0) {
            player->fadeSettingsInitial = 255;
            player->fadeSettingsTime = time;
            player->fadeSettingsGoal = 0;
            player->fadeSettingsType = MSEQ_FADE_OUT_PAUSING;
            return;
        }
        player->mode = MSEQ_MODE_PAUSING;
    }
}

void au_mseq_resume(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != nullptr && player->mseqReadPos != nullptr) {
        player->mode = MSEQ_MODE_RESUMING;
        if (time != 0) {
            player->fadeSettingsTime = time;
        } else {
            player->fadeSettingsTime = SND_MIN_DURATION;
        }
        player->fadeSettingsInitial = 0;
        player->fadeSettingsGoal = AU_MAX_VOLUME_8;
        player->fadeSettingsType = MSEQ_FADE_IN;
    }
}

void au_mseq_stop_quick(s32 index) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != nullptr && player->mseqReadPos != nullptr) {
        if (player->mode != MSEQ_MODE_PLAYING) {
            player->mseqReadPos = nullptr;
            player->mseqName = 0;
            player->mode = MSEQ_MODE_PLAYING;
            return;
        }
        player->mseqReadPos = BlankMseqData;
        player->delay = 1;
    }
}

void au_mseq_stop_slow(s32 index, s32 time) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];

    if (player->mseqReadStart != nullptr && player->mseqReadPos != nullptr) {
        if (time != 0) {
            player->fadeSettingsTime = time;
        } else {
            player->fadeSettingsTime = SND_MIN_DURATION;
        }
        player->fadeSettingsInitial = 255;
        player->fadeSettingsGoal = 0;
        player->fadeSettingsType = MSEQ_FADE_OUT;
    }
}

void au_mseq_set_volume(s32 index, s32 time, s32 volume) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];
    if ((player->mseqReadStart != 0) && (player->mseqReadPos != 0)) {
        if (volume <= 0) {
            volume = 1;
        } else if (volume > AU_MAX_VOLUME_8) {
            volume = AU_MAX_VOLUME_8;
        }
        if (time != 0) {
            player->fadeSettingsTime = time;
        } else {
            player->fadeSettingsTime = SND_MIN_DURATION;
        }
        player->fadeSettingsInitial = 255;
        player->fadeSettingsGoal = volume;
        player->fadeSettingsType = MSEQ_FADE_IN;
    }
}

AuResult au_mseq_check_stopped(s32 index) {
    AmbiencePlayer* player = &gAuAmbienceManager->players[index];
    AuResult status = AU_RESULT_OK;

    if (player->mseqReadStart != nullptr && player->mseqReadPos != nullptr) {
        status = AU_AMBIENCE_STOP_ERROR_1;
        if (player->mode != MSEQ_MODE_PLAYING) {
            status = AU_AMBIENCE_STOP_ERROR_2;
        }
    }
    return status;
}

void au_mseq_play_sequence(AmbienceManager* manager, MSEQHeader* mseqFile, s32 index) {
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
    player->fadeVolume = AU_MAX_VOLUME_8 << 24;
    player->fadeGoal = AU_MAX_VOLUME_8;

    player->mseqName = player->mseqFile->name;
    player->firstVoiceIdx = player->mseqFile->firstVoiceIdx;
    player->lastVoiceIdx = player->firstVoiceIdx + 16;
    if (player->lastVoiceIdx > 24) {
        player->lastVoiceIdx = 24;
    }
    for (i = 0; i < ARRAY_COUNT(player->tracks); i++) {
        track = &player->tracks[i];
        track->instrument = manager->globals->defaultInstrument;
        track->volumeLerp.current = AU_MAX_VOLUME_32;
        track->pan = 64;
    }
    player->resetRequired = true;
}

void au_mseq_manager_audio_frame_update(AmbienceManager* manager) {
    u32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(manager->voiceStates); i++) {
        AmbienceVoiceState* voiceState = &manager->voiceStates[i];

        // potential @bug, any voice which is not properly released via MSEQ_CMD_80_STOP_SOUND will eventaully
        // end and set its priority to AU_PRIORITY_FREE, where another client can steal it and begin using it
        // without it being considered 'free' by this AmbienceManager. this can be fixed by removing the check
        // for released == true from the conditional
        if (voiceState->info.released == true && manager->globals->voices[i].priority != manager->priority) {
            voiceState->info.all = 0;
        }
    }

    for (j = 0; j < ARRAY_COUNT(manager->players); j++) {
        AmbiencePlayer* player = &manager->players[j];
        s32 mode;

        if (player->mseqReadPos != nullptr) {
            if (manager->loadTracksFadeInfo) {
                au_mseq_load_track_fade_info(manager, player);
            }

            mode = player->mode;
            if (mode != MSEQ_MODE_PLAYING) {
                if (mode == MSEQ_MODE_PAUSING) {
                    player->mode = MSEQ_MODE_STOPPED;
                    au_mseq_save_voices(manager, player);
                    au_mseq_player_stop(manager, player);
                } else if (player->mode == MSEQ_MODE_RESUMING) {
                    player->mode = MSEQ_MODE_PLAYING;
                    if (player->fadeSettingsTime != 0) {
                        au_mseq_fade_setup(player);
                    }
                    au_mseq_restore_voices(manager, player);
                }
            } else {
                // case MSEQ_MODE_PLAYING
                if (player->fadeSettingsTime != 0) {
                    au_mseq_fade_setup(player);
                }
                if (player->playState == MSEQ_PLAYER_STOPPING) {
                    au_mseq_player_stop(manager, player);
                    player->playState = MSEQ_PLAYER_STOPPED;
                }
                au_mseq_player_update(manager, player);
            }
        }
    }

    manager->loadTracksFadeInfo = false;
}

void au_mseq_load_track_fade_info(AmbienceManager* manager, AmbiencePlayer* player) {
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
                track->tuneLerp.step = (trackData->delta << 16) / trackData->time;
                track->tuneLerp.goal = trackData->goal;
            } else if (trackData->type == 1) {
                track->volumeLerp.time = trackData->time;
                track->volumeLerp.step = (trackData->delta << 16) / trackData->time;
                track->volumeLerp.goal = trackData->goal;
            }
            trackData++;
        }
    }
}

void au_mseq_player_update(AmbienceManager* manager, AmbiencePlayer* player) {
    u8 isVolumeChanged[16];
    u8 isPitchChanged[16];
    AuGlobals* globals;
    u8 fadeVolChanged;
    AmbienceVoiceState* voiceState;
    AuVoice* voice;
    BGMDrumInfo* drum;
    u32 trackIdx;
    s32 voiceSelector;
    s32 i;
    u16 bankPatch;
    u32 count;
    s32 loopID;
    u8 op, arg1, arg2;
    AmbienceTrack* track;

    globals = manager->globals;
    fadeVolChanged = false;
    for (i = 0; i < 16U; i++) { // required to use unsigned literal
        isVolumeChanged[i] = false;
        isPitchChanged[i] = false;
    }

    if (player->resetRequired == true) {
        au_mseq_player_stop(manager, player);
        player->resetRequired = false;
    }

    if (player->fadeTime != 0) {
        player->fadeVolume += player->fadeStep;
        player->fadeTime--;
        if (player->fadeTime == 0) {
            player->fadeVolume = player->fadeGoal << 24;
            if (player->fadeSettingsType == MSEQ_FADE_IN) {
                // do nothing
            } else if (player->fadeSettingsType == MSEQ_FADE_OUT) {
                player->mseqReadPos = BlankMseqData;
                player->delay = 1;
            } else if (player->fadeSettingsType == MSEQ_FADE_OUT_PAUSING) {
                player->mode = MSEQ_MODE_PAUSING;
            }
        }
        fadeVolChanged = true;
    }

    // update pitch
    for (trackIdx = 0; trackIdx < ARRAY_COUNT(player->tracks); trackIdx++) {
        track = &player->tracks[trackIdx];
        if (track->tuneLerp.time != 0) {
            track->tuneLerp.time--;
            if (track->tuneLerp.time != 0) {
                track->tuneLerp.current += track->tuneLerp.step;
            } else {
                track->tuneLerp.current = track->tuneLerp.goal << 16;
            }

            voiceSelector = player->id.all + (trackIdx << 16);
            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                // update all voices belonging to current track
                if ((voiceState->info.all & 0xFFFF0000) == voiceSelector) {
                    voice = &globals->voices[i];
                    if (voice->priority == manager->priority && trackIdx != TRACK_ID_DRUM) {
                        voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 16)) * track->instrument->pitchRatio;
                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                        isPitchChanged[i - player->firstVoiceIdx] = true;
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
                track->volumeLerp.current = track->volumeLerp.goal << 16;
            }

            voiceSelector = player->id.all + (trackIdx << 16);
            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                // update all voices belonging to current track
                if ((voiceState->info.all & 0xFFFF0000) == voiceSelector) {
                    voice = &globals->voices[i];
                    if (voice->priority == manager->priority) {
                        track = &player->tracks[voiceState->info.trackIndex];
                        voice->clientVolume = VOL_MULT_3(player->fadeVolume >> 24, track->volumeLerp.current >> 16, voiceState->volume);
                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                    }
                }
            }
        }
    }

    player->delay--;
    if (player->delay <= 0) {
        while (player->delay == 0) {
            op = au_mseq_read_next(player);
            if ((s8)op >= 0) {
                if (op == 0) {
                    // stop
                    player->mseqReadPos = nullptr;
                    player->mseqName = 0;
                    au_mseq_player_stop(manager, player);
                    break;
                }
                if (op >= 0x78) {
                    // long delay
                    player->delay = ((op & 7) << 8) + au_mseq_read_next(player) + 0x78;
                } else {
                    //short delay
                    player->delay = op;
                }
                continue;
            }

            // op >= 0x80
            // op & 0xF0 : command
            // op & 0xF : track index

            arg1 = au_mseq_read_next(player);
            trackIdx = op & 0xF;
            track = &player->tracks[trackIdx];

            switch (op & 0xF0) {
                case MSEQ_CMD_80_STOP_SOUND:
                    // arg1: sound index
                    if (player->playState == MSEQ_PLAYER_PLAYING) {
                        voiceSelector = player->id.all + (trackIdx << 16) + (arg1 << 8);
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            if (manager->voiceStates[i - player->firstVoiceIdx].info.all == voiceSelector) {
                                manager->voiceStates[i - player->firstVoiceIdx].info.released = true;
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
                    arg2 = au_mseq_read_next(player);
                    if (player->playState == MSEQ_PLAYER_PLAYING) {
                        // find free voice
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            voice = &globals->voices[i];
                            if (voice->priority == AU_PRIORITY_FREE) {
                                break;
                            }
                        }
                        if (i >= player->lastVoiceIdx) {
                            // try stealing a voice from the current player (or one with the same priority)
                            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                                voice = &globals->voices[i];
                                if (voice->priority == manager->priority) {
                                    au_reset_voice(voice, i);
                                    break;
                                }
                            }
                        }
                        if (i >= player->lastVoiceIdx) {
                            // try stealing a voice from a different player with a lower priority
                            for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                                voice = &globals->voices[i];
                                if (voice->priority < manager->priority) {
                                    au_reset_voice(voice, i);
                                    break;
                                }
                            }
                        }
                        if (i < player->lastVoiceIdx) {
                            isVolumeChanged[i - player->firstVoiceIdx] = true;
                            isPitchChanged[i - player->firstVoiceIdx] = true;
                            voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                            // set playerIndex, trackIndex and tune
                            voiceState->info.all = player->id.all + (trackIdx << 16) + (arg1 << 8);
                            if (track->flags & MSEQ_TRACK_RESUMABLE) {
                                voiceState->isResumable = true;
                            } else {
                                voiceState->isResumable = false;
                            }
                            if (trackIdx != TRACK_ID_DRUM) {
                                if (track->flags & MSEQ_TRACK_RESUMABLE) {
                                    voiceState->isResumable = true;
                                } else {
                                    voiceState->isResumable = false;
                                }

                                voiceState->pitch = (arg1 & 0x7F) * 100 - track->instrument->keyBase;
                                voiceState->volume = arg2 & 0x7F;
                                voice->clientVolume = VOL_MULT_3(player->fadeVolume >> 24, track->volumeLerp.current >> 16, voiceState->volume);
                                voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 16)) * track->instrument->pitchRatio;
                                voice->pan = track->pan;
                                voice->reverb = track->reverb;
                                voice->instrument = track->instrument;
                                voice->busID = manager->busID;
                                voice->envelope.cmdListPress = track->envelope.cmdListPress;
                                voice->envelope.cmdListRelease = track->envelope.cmdListRelease;
                            } else {
                                voiceState->isResumable = false;
                                drum = &manager->globals->dataPER->drums[arg1 & 0x7F];
                                bankPatch = drum->bankPatch;
                                voice->instrument = au_get_instrument(manager->globals, bankPatch >> 8, bankPatch & 0xFF, &voice->envelope);
                                voiceState->pitch = drum->keyBase - voice->instrument->keyBase;
                                voiceState->volume = VOL_MULT_2(arg2 & 0x7F, drum->volume);
                                voice->clientVolume = VOL_MULT_3(player->fadeVolume >> 24, track->volumeLerp.current >> 16, voiceState->volume);
                                voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch) * voice->instrument->pitchRatio;
                                voice->pan = drum->pan;
                                voice->reverb = drum->reverb;
                                voice->busID = manager->busID;
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
                        voiceSelector = player->id.all + (trackIdx << 16);
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                            if ((voiceState->info.all & 0xFFFF0000) == voiceSelector) {
                                voice = &globals->voices[i];
                                if (voice->priority == manager->priority && trackIdx != TRACK_ID_DRUM) {
                                    voice->pan = track->pan;
                                    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PAN_FXMIX;
                                }
                            }
                        }
                    } else {
                        track->volumeLerp.current = arg1 << 24;
                        if (track->volumeLerp.current != 0) {
                            track->volumeLerp.current |= 0xFFFFFF;
                        }
                        voiceSelector = player->id.all + (trackIdx << 16);
                        for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                            voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                            if ((voiceState->info.all & 0xFFFF0000) == voiceSelector) {
                                voice = &globals->voices[i];
                                if (voice->priority == manager->priority) {
                                    voice->clientVolume = VOL_MULT_3(player->fadeVolume >> 24, track->volumeLerp.current >> 16, voiceState->volume);
                                    if (!isVolumeChanged[i - player->firstVoiceIdx]) {
                                        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                                        isVolumeChanged[i - player->firstVoiceIdx] = true;
                                    }
                                }
                            }
                        }
                    }
                    break;
                case MSEQ_CMD_B0_MULTI:
                    // arg1: sub command
                    // arg2: depends on sub command
                    arg2 = au_mseq_read_next(player);
                    switch (arg1) {
                        case MSEQ_CMD_SUB_66_START_LOOP:
                            // arg2: loop id
                            player->loopStartPos[arg2 & 1] = player->mseqReadPos;
                            break;
                        case MSEQ_CMD_SUB_67_END_LOOP:
                            // arg2 lower bit: loop id
                            // (arg2 & 0x7C) >> 2: loop count
                            loopID = arg2 & 1;
                            count = (arg2 & 0x7C) >> 2;
                            if (count != 0) {
                                if (player->loopCount[loopID] != 0) {
                                    player->loopCount[loopID]--;
                                    // if it's the last iteration then don't jump to the loop start
                                    if (player->loopCount[loopID] != 0) {
                                        player->mseqReadPos = player->loopStartPos[loopID];
                                    }
                                } else {
                                    // first iteration, set loop counter
                                    player->mseqReadPos = player->loopStartPos[loopID];
                                    player->loopCount[loopID] = count;
                                }
                            } else {
                                // infinite loop
                                player->mseqReadPos = player->loopStartPos[loopID];
                                player->loopCount[loopID] = 0;
                            }
                            break;
                        case MSEQ_CMD_SUB_68_SET_REVERB:
                            track->reverb = arg2;
                            break;
                        case MSEQ_CMD_SUB_69_SET_RESUMABLE:
                            if (arg2 == 1) {
                                track->flags |= MSEQ_TRACK_RESUMABLE;
                            }
                            break;
                    }
                    break;
                case MSEQ_CMD_C0_SET_INSTRUMENT:
                    // arg1: bank
                    // arg2: patch
                    arg2 = au_mseq_read_next(player);
                    if (trackIdx != TRACK_ID_DRUM) {
                        track->instrument = au_get_instrument(manager->globals, arg1, arg2, &track->envelope);
                    }
                    break;
                case MSEQ_CMD_E0_TUNING:
                    // arg1: coarse tune
                    // arg2: fine tune
                    track->tuneLerp.current = (arg1 << 24) + (au_mseq_read_next(player) << 16);
                    voiceSelector = player->id.all + (trackIdx << 16);
                    for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
                        voiceState = &manager->voiceStates[i - player->firstVoiceIdx];
                        if ((voiceState->info.all & 0xFFFF0000) == voiceSelector) {
                            voice = &globals->voices[i];
                            if (voice->priority == manager->priority && trackIdx != TRACK_ID_DRUM) {
                                voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 16)) * track->instrument->pitchRatio;
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
                    voice->clientVolume = VOL_MULT_3(player->fadeVolume >> 24, track->volumeLerp.current >> 16, voiceState->volume);
                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                }
            }
        }
    }
}

u8 au_mseq_read_next(AmbiencePlayer* state) {
    u8 value = *state->mseqReadPos++;
    return value;
}

void au_mseq_player_stop(AmbienceManager* manager, AmbiencePlayer* player) {
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

void au_mseq_save_voices(AmbienceManager* manager, AmbiencePlayer* player) {
    AmbienceSavedVoice* savedVoice = player->savedVoices;
    u32 numSaved = 0;
    s32 i;

    for (i = player->firstVoiceIdx; i < player->lastVoiceIdx; i++) {
        AmbienceVoiceState* voiceState = &manager->voiceStates[i - player->firstVoiceIdx];

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

void au_mseq_restore_voices(AmbienceManager* manager, AmbiencePlayer* player) {
    AuGlobals* globals;
    AuVoice* voice;
    AmbienceSavedVoice* savedVoice;
    AmbienceVoiceState* voiceState;
    AmbienceTrack* track;
    u32 i, j;

    globals = manager->globals;
    if (player->playState == MSEQ_PLAYER_PLAYING) {
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
                    voiceState->info.all = player->id.all + (savedVoice->trackIndex << 16) + (savedVoice->tune << 8);
                    voiceState->pitch = (savedVoice->tune & 0x7F) * 100 - track->instrument->keyBase;
                    voiceState->volume = savedVoice->volume & 0x7F;
                    voice->clientVolume = VOL_MULT_3(player->fadeVolume >> 24, track->volumeLerp.current >> 16, voiceState->volume);
                    voice->pitchRatio = au_compute_pitch_ratio(voiceState->pitch + (track->tuneLerp.current >> 16)) * track->instrument->pitchRatio;
                    voice->pan = track->pan;
                    voice->reverb = track->reverb;
                    voice->instrument = track->instrument;
                    voice->busID = manager->busID;
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
