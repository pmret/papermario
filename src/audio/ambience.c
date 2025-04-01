#include "common.h"
//#include "audio/public.h"

typedef struct {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 fadeState;
    /* 0x4 */ s32 fadeTime;
    /* 0x8 */ s32 soundID;
    /* 0xC */ s32 unkC;
} AmbientSoundSettings;

typedef enum AmbientSoundState {
    AMBIENCE_STATE_IDLE         = 0,
    AMBIENCE_STATE_FADE_OUT     = 1,  // fade out old sounds
    AMBIENCE_STATE_FADE_IN      = 2   // fade in new sounds
} AmbientSoundState;

typedef enum AmbientSoundFlag {
    AMBIENCE_FLAG_PLAYING       = 1,
} AmbientSoundFlag;

AmbientSoundSettings DefaultAmbientSoundData = {
    .flags = 0,
    .fadeState = 0,
    .fadeTime = 0,
    .soundID = -1,
    .unkC = -1
};

AmbientSoundSettings AmbientSoundData;

void reset_ambient_sounds(void) {
    AmbientSoundData = DefaultAmbientSoundData;
}

void update_ambient_sounds(void) {
    AmbientSoundSettings* ambientSoundState = &AmbientSoundData;
    s32 error;

    switch (ambientSoundState->fadeState) {
        case AMBIENCE_STATE_IDLE:
            break;
        case AMBIENCE_STATE_FADE_OUT:
            if (ambientSoundState->flags & 1) {
                if (ambientSoundState->fadeTime < 250) {
                    error = snd_ambient_stop_quick(0);
                } else {
                    error = snd_ambient_stop_slow(0, ambientSoundState->fadeTime);
                }

                if (error != AU_RESULT_OK) {
                    return;
                }
            }
            ambientSoundState->fadeState = AMBIENCE_STATE_FADE_IN;
            break;
        case AMBIENCE_STATE_FADE_IN:
            if (ambientSoundState->flags & AMBIENCE_FLAG_PLAYING) {
                if (snd_ambient_is_stopped(0) != AU_RESULT_OK) {
                    return;
                }
                ambientSoundState->flags &= ~AMBIENCE_FLAG_PLAYING;
            }
            if (ambientSoundState->soundID < 0) {
                ambientSoundState->fadeState = AMBIENCE_STATE_IDLE;
            } else if (snd_load_ambient(ambientSoundState->soundID) == AU_RESULT_OK) {
                if (snd_ambient_play(0, 0) == AU_RESULT_OK) {
                    ambientSoundState->fadeState = AMBIENCE_STATE_IDLE;
                    ambientSoundState->flags |= AMBIENCE_FLAG_PLAYING;
                }
            }
            break;
    }
}

s32 play_ambient_sounds(s32 soundID, s32 fadeTime) {
    AmbientSoundSettings* state = &AmbientSoundData;

    if (!gGameStatusPtr->musicEnabled) {
        snd_ambient_stop_quick(state->soundID);
        state->flags &= ~AMBIENCE_FLAG_PLAYING;
        return 1;
    }

    if (state->soundID == soundID) {
        return 2;
    }

    state->soundID = soundID;
    state->fadeTime = fadeTime;
    state->fadeState = AMBIENCE_STATE_FADE_OUT;
    return 1;
}
