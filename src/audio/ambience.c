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
    AMBIENT_SOUND_IDLE        = 0,
    AMBIENT_SOUND_FADE_OUT    = 1,  // fade out old sounds
    AMBIENT_SOUND_FADE_IN     = 2   // fade in new sounds
} AmbientSoundState;

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
        case AMBIENT_SOUND_IDLE:
            break;
        case AMBIENT_SOUND_FADE_OUT:
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
            ambientSoundState->fadeState = AMBIENT_SOUND_FADE_IN;
            break;
        case AMBIENT_SOUND_FADE_IN:
            if (ambientSoundState->flags & 1) {
                if (snd_ambient_is_stopped(0) != AU_RESULT_OK) {
                    return;
                }
                ambientSoundState->flags &= ~1;
            }
            if (ambientSoundState->soundID < 0) {
                ambientSoundState->fadeState = AMBIENT_SOUND_IDLE;
            } else if (snd_load_ambient(ambientSoundState->soundID) == AU_RESULT_OK) {
                if (snd_ambient_play(0, 0) == AU_RESULT_OK) {
                    ambientSoundState->fadeState = AMBIENT_SOUND_IDLE;
                    ambientSoundState->flags |= 1;
                }
            }
            break;
    }
}

s32 play_ambient_sounds(s32 soundID, s32 fadeTime) {
    AmbientSoundSettings* state = &AmbientSoundData;

    if (!gGameStatusPtr->musicEnabled) {
        snd_ambient_stop_quick(state->soundID);
        state->flags &= ~1;
        return 1;
    }

    if (state->soundID == soundID) {
        return 2;
    }

    state->soundID = soundID;
    state->fadeTime = fadeTime;
    state->fadeState = AMBIENT_SOUND_FADE_OUT;
    return 1;
}
