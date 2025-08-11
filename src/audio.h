#ifndef _AUDIO_H_
#define _AUDIO_H_
#include "nu/nusys.h"
#include "nu/nualsgi.h"
#include "PR/n_abi.h"
#include "common.h"

typedef s32 s8_24; // 8.24 fixed point
typedef s32 s16_16; // 16.16 fixed point

typedef u8* AuFilePos;
typedef u8* WaveData;

#define NO_INSTRUMENT ((Instrument*) -1)

#define AUDIO_SAMPLES   184

#define AU_FX_MAX_TAPS          4
#define AU_FX_LENGTH            (14 * AUDIO_SAMPLES) // 0xA10

#define AU_FILTER_LENGTH        (28 * AUDIO_SAMPLES) // 0x1420

#define HARDWARE_OUTPUT_RATE    32000

// duration of a single audio frame sent to the RSP in microseconds (note: this is *not* the FPS of the game loop)
// determined by: (AUDIO_SAMPLES / HARDWARE_OUTPUT_RATE) = (184 / 32000), expressed in microseconds
#define AU_FRAME_USEC           5750

#define N_AL_DECODER_IN         0
#define N_AL_RESAMPLER_OUT      0
#define N_AL_TEMP_0             0
#define N_AL_DECODER_OUT        0x170
#define N_AL_TEMP_1             0x170 // size = 0x170 = 2 * AUDIO_SAMPLES
#define N_AL_TEMP_2             0x2E0 // size = 0x200 > 2 * AUDIO_SAMPLES
#define N_AL_MAIN_L_OUT         0x4E0 // size = 0x170 = 2 * AUDIO_SAMPLES
#define N_AL_MAIN_R_OUT         0x650 // size = 0x170 = 2 * AUDIO_SAMPLES
#define N_AL_AUX_L_OUT          0x7C0 // size = 0x170 = 2 * AUDIO_SAMPLES
#define N_AL_AUX_R_OUT          0x930

#define AU_MAX_BUS_VOLUME       0x8000

#define ALIGN16_(val) (((val) + 0xF) & 0xFFF0)
#define AU_FILE_RELATIVE(base,offset) ((void*)((s32)(offset) + (s32)(base)))

#if VERSION_PAL
#define VIDEO_FRAMES_PER_SECOND 50
#define AUDIO_HEAP_SIZE 0x5B000
#define AUDIO_MAX_SAMPLES   (AUDIO_SAMPLES * 2)
#define AUDIO_COMMAND_LIST_BUFFER_SIZE 0x5558
#else
#define VIDEO_FRAMES_PER_SECOND 60
#define AUDIO_HEAP_SIZE 0x56000
#define AUDIO_MAX_SAMPLES   AUDIO_SAMPLES
#define AUDIO_COMMAND_LIST_BUFFER_SIZE 0x4000
#endif

#define ADPCMFBYTES     9

#define DEFAULT_KEYBASE 4800 // 48 semitones --> C3

#define AU_MAX_VOLUME_8  0x7F // 127
#define AU_MAX_VOLUME_16 0x7FFF
#define AU_MAX_VOLUME_32 0x7FFFFFFF

#define AU_PAN_MIN 0
#define AU_PAN_MID 64
#define AU_PAN_MAX 127

// converts an 8-bit volume to a 16-bit volume. only valid for vol != 0.
#define AU_VOL_8_TO_16(vol) (((vol) << 8) | 0xFF)
// converts an 8-bit volume to a 32-bit volume. only valid for vol != 0.
#define AU_VOL_8_TO_32(vol) (((vol) << 0x18) | 0xFFFFFF)

// maximum number of instrument presets for a BGM file
#define BGM_MAX_INSTRUMNETS 0x80

#define BGM_DEFAULT_TICKS_PER_BEAT 48

// fixed scale for update counter to avoid precision loss of fractional frames; 1 unit = 0.001 audio frame
// (ie, prevent truncation when updating tick every 1.5 frames)
#define BGM_UPDATE_SCALE (1000)
// 1 unit = 0.01 BPM
#define BGM_TEMPO_SCALE (100)

// number of audio frames per minute x BGM_UPDATE_SCALE --> units = milli-frames per minute
#define BGM_MFRAMES_PER_MINUTE (BGM_UPDATE_SCALE * (60 * HARDWARE_OUTPUT_RATE) / AUDIO_SAMPLES)

// default BPM for BGMPlayer
#define BGM_DEFAULT_BPM 156
// default masterTempo for BGMPlayer, derived from BGM_DEFAULT_BPM
#define BGM_DEFAULT_TEMPO (BGM_DEFAULT_BPM * BGM_TEMPO_SCALE)

// just over 100x the default tempo, seemingly chosen to make each tick = 256 audio samples
// solves (AUDIO_SAMPLES * BGM_MFRAMES_PER_MINUTE) / (BGM_DEFAULT_TICKS_PER_BEAT * x) = 256
//   -->  (184 * 10434782) / (48 * x) = 256
//   -->  x = (184 * 10434782) / (48 * 256)
#define BGM_DEFAULT_UPDATE_STEP 156250

// converts a 'tempo' value from BGM command to units suitable for the player update counter
#define BGM_TEMPO_TO_UPDATE_UNITS(tempo) (BGM_UPDATE_SCALE * (u32)(tempo) / BGM_TEMPO_SCALE)

#define SND_MIN_DURATION 250
#define SND_MAX_DURATION 10000

#define AU_SONG_NONE -1

#define MUS_QUEUE_SIZE 16
#define SFX_QUEUE_SIZE 16

// semitone pitch interval in cents
#define AU_SEMITONE_CENTS 100

// octave pitch interval in cents
#define AU_OCTAVE_CENTS (12 * AU_SEMITONE_CENTS)

#define ENV_VOL_MAX     0x80    // for 7-bit volumes, 128 (1 << 7) represents full volume
#define ENV_VOL_SHIFT   7       // Shift required to divide by 128 (normalize 7-bit volumes after a multiply)

#define PRG_MAX_COUNT   0x40

// Multiplies two 7-bit volume values and normalizes the result.
#define VOL_MULT_2(a, b) ((a)*(b) >> ENV_VOL_SHIFT)

// Multiplies three 7-bit volume values and normalizes the result.
#define VOL_MULT_3(a, b, c) ((a)*(b)*(c) >> ENV_VOL_SHIFT >> ENV_VOL_SHIFT)

// Multiplies four 7-bit volume values and normalizes the result.
#define VOL_MULT_4(a, b, c, d) (VOL_MULT_2(VOL_MULT_3(a, b, c), d))

typedef u32 SegData;

typedef enum AuPriority {
    AU_PRIORITY_FREE            = 0,
    AU_PRIORITY_BGM_PLAYER_MAIN = 1,
    AU_PRIORITY_BGM_PLAYER_AUX  = 2,
    AU_PRIORITY_SFX_MANAGER     = 4,
    AU_PRIORITY_MSEQ_MANAGER    = 6,
} AuPriority;

enum AuVoiceEnvelopeFlags {
    AU_VOICE_ENV_FLAG_RELEASING             = 0x01,
    AU_VOICE_ENV_FLAG_HANDLED_VOL_CHANGE    = 0x02,
    AU_VOICE_ENV_FLAG_KEY_RELEASED          = 0x10,
    AU_VOICE_ENV_FLAG_VOL_CHANGED           = 0x20,
};

enum AuVoiceSyncFlags {
    AU_VOICE_SYNC_FLAG_ALL          = 0x02,
    AU_VOICE_SYNC_FLAG_PARAMS       = 0x04,
    AU_VOICE_SYNC_FLAG_PITCH        = 0x08,
    AU_VOICE_SYNC_FLAG_PAN_FXMIX    = 0x10,
};

typedef enum AuEffectType {
    AU_FX_NONE                  = 0,
    AU_FX_SMALLROOM             = 1,
    AU_FX_BIGROOM               = 2,
    AU_FX_CHORUS                = 3,
    AU_FX_FLANGE                = 4,
    AU_FX_ECHO                  = 5,
    AU_FX_CUSTOM_0              = 6,
    AU_FX_CUSTOM_1              = 7,
    AU_FX_CUSTOM_2              = 8,
    AU_FX_CUSTOM_3              = 9,
    AU_FX_OTHER_BIGROOM         = 10,
} AuEffectType;

typedef enum MusicPlayer {
    MUSIC_PLAYER_MAIN           = 0,
    MUSIC_PLAYER_AUX            = 1,
} MusicPlayer;

typedef enum MusicState {
    MUSIC_STATE_IDLE            = 0,
    MUSIC_STATE_STOP_CURRENT    = 1,
    MUSIC_STATE_AWAIT_FADEOUT   = 2,
    MUSIC_STATE_DELAY_2         = 3,
    MUSIC_STATE_DELAY_1         = 4,
    MUSIC_STATE_PLAY_NEXT       = 5,
} MusicState;

typedef enum MusicFlags {
    MUSIC_FLAG_PLAYING              = 0x01,
    MUSIC_FLAG_ENABLE_PROX_MIX      = 0x02,
    MUSIC_FLAG_PUSHING              = 0x04,
    MUSIC_FLAG_POPPING              = 0x08,
    MUSIC_FLAG_IGNORE_POP           = 0x10,
    MUSIC_FLAG_FADE_IN_NEXT         = 0x20,
} MusicFlags;

typedef enum BGMSnapshots {
    BGM_SNAPSHOT_0              = 0,
} BGMSnapshots;

typedef enum BGMPolyphony {
    BGM_POLYPHONY_0             = 0,
    BGM_POLYPHONY_1             = 1,
    BGM_POLYPHONY_UNUSED_A      = 2,
    BGM_POLYPHONY_UNUSED_B      = 3,
    BGM_POLYPHONY_UNUSED_C      = 4,
    BGM_POLYPHONY_2             = 5,
    BGM_POLYPHONY_3             = 6,
    BGM_POLYPHONY_4             = 7,
} BGMPolyphony;

typedef enum BGMPlayerState {
    BGM_PLAY_STATE_IDLE         = 0,
    BGM_PLAY_STATE_ACTIVE       = 1,
    BGM_PLAY_STATE_FETCH        = 2,
    BGM_PLAY_STATE_INIT         = 3,
    BGM_PLAY_STATE_STOP         = 4,
} BGMPlayerState;

typedef enum BGMCompositionCommands {
    BGM_COMP_END                    = 0,
    BGM_COMP_PLAY_PHRASE            = 1,
    BGM_COMP_START_LOOP             = 3,
    BGM_COMP_WAIT                   = 4,
    BGM_COMP_END_LOOP               = 5,
    BGM_COMP_END_COND_LOOP_false    = 6,
    BGM_COMP_END_COND_LOOP_true     = 7,
} BGMCompositionCommands;

typedef enum BGMSpecialSubops {
    BGM_SPECIAL_SET_STEREO_DELAY    = 1, // sets delay to desync the left or right channel
    BGM_SPECIAL_SEEK_CUSTOM_ENV     = 2, // set active custom envelope index for writing
    BGM_SPECIAL_WRITE_CUSTOM_ENV    = 3, // write custom envelope data
    BGM_SPECIAL_USE_CUSTOM_ENV      = 4, // select which custom envelope to use
    BGM_SPECIAL_TRIGGER_SOUND       = 5,
    BGM_SPECIAL_PROX_MIX_OVERRIDE   = 6,
} BGMSpecialSubops;

typedef enum FxBus {
    FX_BUS_BGMA_MAIN    = 0,
    FX_BUS_SOUND        = 1,
    FX_BUS_BGMB         = 2,
    FX_BUS_BGMA_AUX     = 3,
} FxBus;

typedef enum DelayChannel {
    AU_DELAY_CHANNEL_NONE   = 0,
    AU_DELAY_CHANNEL_LEFT   = 1,
    AU_DELAY_CHANNEL_RIGHT  = 2,
} DelayChannel;

typedef enum DelayState {
    AU_DELAY_STATE_ON           = 0, /// channel delay is enabled (though not necessarily applied)
    AU_DELAY_STATE_OFF          = 1, /// channel delay is disabled
    AU_DELAY_STATE_REQUEST_OFF  = 2, /// game thread has scheduled the channel delay to be disabled
} DelayState;

typedef enum EnvelopeCommand {
    ENV_CMD_END_LOOP        = 0xFB,
    ENV_CMD_START_LOOP      = 0xFC,
    ENV_CMD_ADD_SCALE       = 0xFD,
    ENV_CMD_SET_SCALE       = 0xFE,
    ENV_CMD_END             = 0xFF,
} EnvelopeCommand;

enum EnvelopeTimeIntervals {
    ENV_TIME_60S        = 0,
    ENV_TIME_55S        = 1,
    ENV_TIME_50S        = 2,
    ENV_TIME_45S        = 3,
    ENV_TIME_40S        = 4,
    ENV_TIME_35S        = 5,
    ENV_TIME_30S        = 6,
    ENV_TIME_27_5S      = 7,
    ENV_TIME_25S        = 8,
    ENV_TIME_22_5S      = 9,
    ENV_TIME_20S        = 10,
    ENV_TIME_19S        = 11,
    ENV_TIME_18S        = 12,
    ENV_TIME_17S        = 13,
    ENV_TIME_16S        = 14,
    ENV_TIME_15S        = 15,
    ENV_TIME_14S        = 16,
    ENV_TIME_13S        = 17,
    ENV_TIME_12S        = 18,
    ENV_TIME_11S        = 19,
    ENV_TIME_10S        = 20,
    ENV_TIME_9S         = 21,
    ENV_TIME_8S         = 22,
    ENV_TIME_7S         = 23,
    ENV_TIME_6S         = 24,
    ENV_TIME_5S         = 25,
    ENV_TIME_4_5S       = 26,
    ENV_TIME_4S         = 27,
    ENV_TIME_3_5S       = 28,
    ENV_TIME_3S         = 29,
    ENV_TIME_2750MS     = 30,
    ENV_TIME_2500MS     = 31,
    ENV_TIME_2250MS     = 32,
    ENV_TIME_2S         = 33,
    ENV_TIME_1900MS     = 34,
    ENV_TIME_1800MS     = 35,
    ENV_TIME_1700MS     = 36,
    ENV_TIME_1600MS     = 37,
    ENV_TIME_1500MS     = 38,
    ENV_TIME_1400MS     = 39,
    ENV_TIME_1300MS     = 40,
    ENV_TIME_1200MS     = 41,
    ENV_TIME_1100MS     = 42,
    ENV_TIME_1S         = 43,
    ENV_TIME_950MS      = 44,
    ENV_TIME_900MS      = 45,
    ENV_TIME_850MS      = 46,
    ENV_TIME_800MS      = 47,
    ENV_TIME_750MS      = 48,
    ENV_TIME_700MS      = 49,
    ENV_TIME_650MS      = 50,
    ENV_TIME_600MS      = 51,
    ENV_TIME_550MS      = 52,
    ENV_TIME_500MS      = 53,
    ENV_TIME_450MS      = 54,
    ENV_TIME_400MS      = 55,
    ENV_TIME_375MS      = 56,
    ENV_TIME_350MS      = 57,
    ENV_TIME_325MS      = 58,
    ENV_TIME_300MS      = 59,
    ENV_TIME_290MS      = 60,
    ENV_TIME_280MS      = 61,
    ENV_TIME_270MS      = 62,
    ENV_TIME_260MS      = 63,
    ENV_TIME_250MS      = 64,
    ENV_TIME_240MS      = 65,
    ENV_TIME_230MS      = 66,
    ENV_TIME_220MS      = 67,
    ENV_TIME_210MS      = 68,
    ENV_TIME_200MS      = 69,
    ENV_TIME_190MS      = 70,
    ENV_TIME_180MS      = 71,
    ENV_TIME_170MS      = 72,
    ENV_TIME_160MS      = 73,
    ENV_TIME_150MS      = 74,
    ENV_TIME_140MS      = 75,
    ENV_TIME_130MS      = 76,
    ENV_TIME_120MS      = 77,
    ENV_TIME_110MS      = 78,
    ENV_TIME_100MS      = 79,
    ENV_TIME_16UNITS    = 80,
    ENV_TIME_14UNITS    = 81,
    ENV_TIME_12UNITS    = 81,
    ENV_TIME_11UNITS    = 83,
    ENV_TIME_10UNITS    = 84,
    ENV_TIME_9UNITS     = 85,
    ENV_TIME_8UNITS     = 86,
    ENV_TIME_7UNITS     = 87,
    ENV_TIME_6UNITS     = 88,
    ENV_TIME_5UNITS     = 89,
    ENV_TIME_4UNITS     = 90,
    ENV_TIME_3UNITS     = 91,
    ENV_TIME_2UNITS     = 92,
    ENV_TIME_1UNITS     = 93,
    ENV_TIME_0          = 94,
};

enum SoundPlayerState {
    SND_PLAYER_STATE_CONTINUE   = 0,
    SND_PLAYER_STATE_INIT       = 1,
};

enum SoundManagerState {
    SND_MANAGER_STATE_ENABLED   = 0,
    SND_MANAGER_STATE_DISABLED  = 1,
};

enum SoundInstanceFlags {
    SOUND_INSTANCE_FLAG_ACTIVE = 1,
    SOUND_INSTANCE_FLAG_POSITION_CHANGED = 2,
};

/// corresponds with bank group IDs from INIT file bank list (InitBankEntry.bankSet)
typedef enum BankSet {
    BANK_SET_AUX        = 1, // extra banks loaded at request of BGM file
    BANK_SET_2          = 2, // loaded during INIT
    BANK_SET_MUSIC      = 3, // loaded during INIT, contains instrument samples for BGM
    BANK_SET_4          = 4, // loaded during INIT
    BANK_SET_5          = 5, // loaded during INIT
    BANK_SET_6          = 6, // loaded during INIT
} BankSet;

/// The bank indices used by audio assets when choosing an intrument. These are similar to values in BankSet,
/// but not identical
typedef enum BankSetIndex {
    BANK_SET_IDX_0      = 0, // BANK_SET_AUX
    BANK_SET_IDX_1      = 1, // BANK_SET_2
    BANK_SET_IDX_2      = 2, // used only for au_reset_drum_entry/au_reset_instrument_entry
    BANK_SET_IDX_3      = 3, // BANK_SET_MUSIC
    BANK_SET_IDX_4      = 4, // BANK_SET_4
    BANK_SET_IDX_5      = 5, // BANK_SET_5
    BANK_SET_IDX_6      = 6, // BANK_SET_6
    BANK_SET_IDX_7      = 7, // also BANK_SET_AUX
    // higher values are not supported, as bankPatch values
} BankSetIndex;

typedef enum AudioType {
    AUDIO_TYPE_BGM      = 0x01,
    AUDIO_TYPE_SFX      = 0x10,
} AudioType;

struct BGMPlayer;
struct AuGlobals;
struct AuVoice;

typedef union SeqArgs {
    u8 raw[4];
    struct { // cmd E0
        u16 value;
    } MasterTempo;
    struct { // cmd E1
        u8 value;
    } MasterVolume;
    struct { // cmd E2
        u8 cent;
    } MasterPitchShift;
    struct { // cmd E3
        u8 effectType;
    } UnkCmdE3;
    struct { // cmd E4
        u16 time;
        u16 value;
    } MasterTempoFade;
    struct { // cmd E5
        u16 time;
        u8 value;
    } MasterVolumeFade;
    struct { // cmd E6
        u8 index;
        u8 value;
    } MasterEffect;
    // command E7 unused
    struct { // cmd E8
        u8 bank;
        u8 patch;
    } OverridePatch;
    struct { // cmd E9
        u8 value;
    } InstrumentVolume;
    struct { // cmd EA
        u8 value;
    } InstrumentPan;
    struct { // cmd EB
        u8 value;
    } InstrumentReverb;
    struct { // cmd EC
        u8 value;
    } TrackVolume;
    struct { // cmd ED
        s8 semitone;
    } InstrumentCoarseTune;
    struct { // cmd EE
        s8 cent;
    } InstrumentFineTune;
    struct { // cmd EF
        s16 cents;
    } TrackDetune;
    struct { // cmd F0
        u8 delay;
        u8 speed;
        u8 depth;
    } TrackTremolo;
    struct { // cmd F1
        u8 value;
    } TrackTremoloRate;
    struct { // cmd F2
        u8 value;
    } TrackTremoloDepth;
    // no args for F3 (TrackTremoloStop)
    struct { // cmd F4
        u8 pan0;
        u8 pan1;
    } RandomPan;
    struct { // cmd F5
        u8 index;
    } UseInstrument;
    struct { // cmd F6
        u16 time;
        u8 value;
    } TrackVolumeFade;
    struct { // cmd F7
        u8 index;
    } ReverbType;
    // commands F8-FB unused
    struct { // cmd FC
        u16 offset;
        u8 tableCount;
    } Branch;
    struct { // cmd FD
        u32 eventInfo;
    } EventTrigger;
    struct { // cmd FE
        u16 offset;
        u8 length;
    } Detour;
    struct { // cmd FF
        u8 type;
        u8 arg1;
        u8 arg2;
    } Special;
} SeqArgs;

/// Structure for volume fading for SFX and BGM. Has independent controls for base and envelope volumes.
typedef struct Fade {
    /* 0x0 */ s16_16 baseVolume;
    /* 0x4 */ s32 baseStep;
    /* 0x8 */ s16 baseTarget;
    /* 0xA */ s16 baseTicks;
    /* 0xC */ AuCallback onCompleteCallback;
    /* 0x10 */ s16_16 envelopeVolume;
    /* 0x14 */ s32 envelopeStep;
    /* 0x18 */ s16 envelopeTarget;
    /* 0x1A */ s16 envelopeTicks;
} Fade; // size = 0x10

typedef struct AuDelay {
    /* 0x00 */ u32 input;
    /* 0x04 */ u32 output;
    /* 0x08 */ s16 ffcoef; // feedforward coef
    /* 0x0A */ s16 fbcoef; // feedback coef
    /* 0x0C */ s16 gain;
    /* 0x0E */ char pad_0E[2];
    /* 0x10 */ f32 rsinc;
    /* 0x14 */ f32 rsval;
    /* 0x18 */ s32 rsdelta;
    /* 0x1C */ f32 rsgain;
    /* 0x20 */ struct AuLowPass* activeLowpass; // can be null, same as lowpassTemplate when in use
    /* 0x24 */ struct AuLowPass* lowpassTemplate; // pre-allocated and reused for active AuLowPass
    /* 0x28 */ struct AuResampler* activeResampler; // can be null, same as resamplerTemplate when in use
    /* 0x2C */ struct AuResampler* resamplerTemplate; // pre-allocated and reused for active AuResampler
} AuDelay; // size = 0x30

typedef struct AuFX {
    /* 0x00 */ s16* base; // start of the delay line buffer
    /* 0x04 */ s16* input; // current read position of the delay line buffer
    /* 0x08 */ s32 length; // length of the delay line buffer
    /* 0x0C */ AuDelay* delays; // set of delays/taps that constitute this effect
    /* 0x10 */ u8 delayCount; // number of AuDelay in delays
} AuFX; // size = 0x14

typedef struct AuLowPass {
    /* 0x00 */ s16 fc;
    /* 0x02 */ s16 fgain;
    /* 0x04 */ char pad_04[4];
    /* 0x08 */ s16 fccoef[16];
    /* 0x28 */ POLEF_STATE* fstate;
    /* 0x2C */ s32 first;
} AuLowPass; // size = 0x30

typedef struct AuFilter {
    /* 0x00 */ s16* base; // (unused) buffer for filter history
    /* 0x04 */ char pad_04[2];
    /* 0x06 */ s16 unused_06;
    /* 0x08 */ s16 unused_08;
    /* 0x0A */ char pad_0A[2];
    /* 0x0C */ AuLowPass* activeLowpass;
    /* 0x10 */ AuLowPass* lowpassTemplate;
} AuFilter; // size = 0x14

typedef struct AuFxBus {
    /* 0x00 */ u16 gain;
    /* 0x02 */ char pad_02[2];
    /* 0x04 */ AuFX* fxL;
    /* 0x08 */ AuFX* fxR;
    /* 0x0C */ u8 curEffectType;
    /* 0x0D */ char pad_0D[3];
    /* 0x10 */ struct AuPVoice* head;
    /* 0x14 */ struct AuPVoice* tail;
} AuFxBus; // size = 0x18

 // ALDMAproc in PM has an extra arg added for bypassing DMA transfers for static audio data
 // (which is always available in RAM), so we have ALDMAproc2 and ALDMANew2.
typedef s32 (*ALDMAproc2)(s32 addr, s32 len, void *state, u8 arg3);
typedef ALDMAproc2 (*ALDMANew2)(void *state);

// based on ALLoadFilter
typedef struct AuLoadFilter {
    /* 0x00 */ ADPCM_STATE* state;
    /* 0x04 */ ADPCM_STATE* lstate;
    /* 0x08 */ ALRawLoop loop;
    /* 0x14 */ struct Instrument* instrument;
    /* 0x18 */ s32 bookSize;
    /* 0x1C */ ALDMAproc2 dmaFunc;
    /* 0x20 */ NUDMAState* dmaState;
    /* 0x24 */ s32 sample;
    /* 0x28 */ s32 lastsam;
    /* 0x2C */ s32 first;
    /* 0x30 */ s32 memin;
} AuLoadFilter; // size = 0x34

// based on ALResampler
typedef struct AuResampler {
    /* 0x00 */ RESAMPLE_STATE* state;
    /* 0x04 */ f32 ratio;
    /* 0x08 */ f32 delta;
    /* 0x0C */ bool first;
} AuResampler; // size = 0x10

// envelope mixer -- based on ALEnvMixer
typedef struct AuEnvMixer {
    /* 0x00 */ ENVMIX_STATE* state;
    /* 0x04 */ s16 pan;
    /* 0x06 */ s16 volume;
    /* 0x08 */ s16 cvolL;
    /* 0x0A */ s16 cvolR;
    /* 0x0C */ s16 dryamt;
    /* 0x0E */ s16 wetamt;
    /* 0x10 */ s16 lratl;
    /* 0x12 */ s16 lratm;
    /* 0x14 */ s16 ltgt;
    /* 0x16 */ s16 rratl;
    /* 0x18 */ s16 rratm;
    /* 0x1A */ s16 rtgt;
    /* 0x1C */ s32 delta;
    /* 0x20 */ s32 segEnd;
    /* 0x24 */ bool dirty;
    /* 0x28 */ s32 motion;
} AuEnvMixer; // size = 0x2C

// based on N_PVoice
typedef struct AuPVoice {
    /* 0x00 */ struct AuPVoice* next; // next voice on the same fx bux
    /* 0x04 */ AuLoadFilter decoder;
    /* 0x38 */ AuResampler resampler;
    /* 0x48 */ AuEnvMixer envMixer;
    /* 0x74 */ s16 unused_74;
    /* 0x76 */ char pad_76[2];
    /* 0x78 */ u8 busID;
    /* 0x79 */ u8 index;
    /* 0x7A */ char pad_7A[2];
} AuPVoice; // size = 0x7C

// based on N_ALSynth
typedef struct AuSynDriver {
    /* 0x00 */ s32 curSamples;
    /* 0x04 */ s32 unused_04;
    /* 0x08 */ s32 outputRate;
    /* 0x0C */ s32 num_pvoice;
    /* 0x10 */ s32 num_bus;
    /* 0x14 */ ALDMANew2 dmaNew; // pointer to nuAuDmaNew
    /* 0x18 */ ALHeap* heap;
    /* 0x1C */ AuPVoice* pvoices;
    /* 0x20 */ AuFxBus* fxBus;
    /* 0x24 */ s32* dryAccumBuffer; // buffer to accumulate dry samples from each bus during audio rendering
    /* 0x28 */ s32* wetAccumBuffer; // buffer to accumulate wet samples from each bus during audio rendering
} AuSynDriver;

typedef struct SoundRequest {
    /* 0x0 */ u16 soundID;
    /* 0x2 */ u16 toReplaceID; // if nonzero, the new sound will prefer stealing a voice from any player with this soundID
    /* 0x4 */ s16 volume;
    /* 0x6 */ s16 pitchShift;
    /* 0x8 */ s8 pan;
    /* 0x9 */ char pad_9[1];
} SoundRequest; // size = 0xA

typedef struct EnvelopeData {
    /* 0x00 */ u8* cmdListPress;
    /* 0x04 */ u8* cmdListRelease;
} EnvelopeData; // size = 0x8

typedef struct EnvelopeOffset {
    /* 0x00 */ u16 offsetPress;
    /* 0x02 */ u16 offsetRelease;
} EnvelopeOffset; // size = 0x4;

typedef struct EnvelopePreset {
    /* 0x00 */ u8 count;
    /* 0x01 */ char pad_01[3];
    /* 0x04 */ EnvelopeOffset offsets[1]; // variable size
} EnvelopePreset;

// partially ALWaveTable?
typedef struct Instrument {
    /* 0x00 */ u8* wavData;
    /* 0x04 */ u32 wavDataLength;
    /* 0x08 */ ADPCM_STATE* loopState;
    /* 0x0C */ s32 loopStart;
    /* 0x10 */ s32 loopEnd;
    /* 0x14 */ s32 loopCount;
    /* 0x18 */ s16* predictor;
    /* 0x1C */ u16 codebookSize;
    /* 0x1E */ u16 keyBase;
    /* 0x20 */ union {
                    f32 pitchRatio; // ratio of sample rate to hardware output rate
                    s32 sampleRate;
               };
    /* 0x24 */ u8 type;
    /* 0x25 */ b8 useDma; // set to false to bypass DMA transfer while loading data -- only do this if the audio samples/codebook are static
    /* 0x26 */ s8 unused_26;
    /* 0x27 */ s8 unused_27;
    /* 0x28 */ s8 unused_28;
    /* 0x29 */ s8 unused_29;
    /* 0x2A */ s8 unused_2A;
    /* 0x2B */ s8 unused_2B;
    /* 0x2C */ EnvelopePreset* envelopes;
} Instrument; // size = 0x30;

typedef Instrument* InstrumentBank[16];

typedef struct SoundLerp {
    /* 0x0 */ s16_16 current;
    /* 0x4 */ s16_16 step;
    /* 0xA */ s16 time;
    /* 0x8 */ s16 goal;
} SoundLerp; // size = 0xC

typedef struct SoundPlayChange {
    union {
        u32 all;
        struct {
            u8 tune;
            u8 volume;
            u8 pan;
            u8 reverb;
        };
    };
} SoundPlayChange;

typedef struct SoundPlayer {
    /* 0x00 */ AuFilePos sefDataReadPos;
    /* 0x04 */ char pad_4[0xC];
    /* 0x10 */ EnvelopeData envelope;
    /* 0x18 */ u8* envelopCustomPressProfile;
    /* 0x1C */ Instrument* sfxInstrumentRef;
    /* 0x20 */ Instrument sfxInstrument;
    /* 0x50 */ AuFilePos sefReadStart;
    /* 0x54 */ SoundPlayChange changed;
    /* 0x58 */ f32 pitchRatio;
    /* 0x5C */ s16 sfxVolume;
    /* 0x5E */ s16 alternativeVolume;
    /* 0x60 */ SoundLerp tuneLerp;
    /* 0x6C */ SoundLerp volumeLerp;
    /* 0x78 */ u8 cmdListOneShot[8];
    /* 0x80 */ AuFilePos alternativeDataPos;
    /* 0x84 */ s8 alternativeType;
    /* 0x85 */ u8 triggers;
    /* 0x86 */ char pad_86[2];
    /* 0x88 */ s8* loopStartPos;
    /* 0x8C */ u8 loopIterCount; // loopIterCount = 0 for infinite loop
    /* 0x8D */ char pad_8D[1];
    /* 0x8E */ u16 delay;
    /* 0x90 */ u16 playLength;
    /* 0x92 */ s16 coarseTune;
    /* 0x94 */ s8 fineTune;
    /* 0x95 */ char pad_95[1];
    /* 0x96 */ u16 curSoundID;
    /* 0x98 */ u8 priority;
    /* 0x99 */ u8 exclusiveID;
    /* 0x9A */ u8 sfxParamsFlags;
    /* 0x9B */ u8 sfxPan;
    /* 0x9C */ u8 reverb;
    /* 0x9D */ u8 instrumentIndex; // ?
    /* 0x9E */ u8 envelopePreset;
    /* 0x9F */ u8 playVelocity;
    /* 0xA0 */ u8 unused_A0;
    /* 0xA1 */ u8 randomPitch;
    /* 0xA2 */ u8 randomVelocity;
    /* 0xA3 */ s8 randomUnused; /// unused; presumably another random parameter matching randomPitch and randomVelocity
    /* 0xA4 */ s16 masterPitchShift;
    /* 0xA6 */ s16 masterVolume;
    /* 0xA8 */ u8 masterPan;
    /* 0xA8 */ u8 state;
    /* 0xA9 */ char pad_AA[2];
} SoundPlayer; // size = 0xAC

typedef struct SoundManagerMusicEvent {
    union {
    /* 0x0 */ s32 raw;
        struct {
    /* 0x0 */ u8 index;
    /* 0x1 */ char pad_01[0x2];
    /* 0x3 */ u8 volume;
        };
    };
} SoundManagerMusicEvent; // size = 4

typedef struct SoundManagerCustomCmdList {
    /* 0x0 */ u16 data[3];
} SoundManagerCustomCmdList; // size = 6

typedef struct SoundManager {
    /* 0x000 */ struct AuGlobals* globals;
    /* 0x004 */ struct AuVoice* curVoice;
    /* 0x008 */ u8* sefData;
    /* 0x00C */ s32* normalSounds[8];
    /* 0x02C */ s32* extraSounds;
    /* 0x030 */ s32 frameCounter; ///< Number of video frame updates, used to update random numnber
    /* 0x034 */ s32 nextUpdateStep;
    /* 0x038 */ s32 nextUpdateInterval;
    /* 0x03C */ s32 nextUpdateCounter;
    /* 0x040 */ Fade fadeInfo;
    /* 0x05C */ s32 busVolume;
    /* 0x060 */ s32 randomValue;
    /* 0x064 */ s32* customReverbParams[8];
    /* 0x084 */ s8 customReverbAmounts[8];
    /* 0x08C */ u8 lastCustomEffectIdx;
    /* 0x08D */ s8 defaultReverbAmt;
    /* 0x08E */ char pad_8E[2];
    /* 0x090 */ SoundManagerMusicEvent bgmSounds[4];
    /* 0x0A0 */ SoundManagerCustomCmdList customCmdList[4];
    /* 0x0B8 */ u16 baseVolume;
    /* 0x0BA */ s16 prevUpdateResult; ///< Unused, may indicate error status
    /* 0x0BC */ u8 priority;
    /* 0x0BD */ u8 firstVoice;
    /* 0x0BE */ u8 busID;
    /* 0x0BF */ u8 curVoiceIndex;
    /* 0x0C0 */ u8 state;
    /* 0x0C1 */ char pad_C1[1];
    /* 0x0C2 */ SoundRequest soundQueue[SFX_QUEUE_SIZE]; ///< Lock-free ring buffer for queueing sound effects from game thread
    /* 0x162 */ s8 unused_162;
    /* 0x163 */ u8 sfxQueueReadPos; ///< Read index for the soundQueue ring buffer (audio thread)
    /* 0x164 */ u8 sfxQueueWritePos; ///< Write index for the soundQueue ring buffer (game thread)
    /* 0x165 */ s8 unused_165;
    /* 0x166 */ char pad_166[2];
    /* 0x168 */ s32 resetPending;
    /* 0x16C */ SoundPlayer players[8];
} SoundManager; // size = 0x6CC

typedef struct SoundInstance {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 soundID;
    /* 0x08 */ s32 sourceFlags;
    /* 0x0C */ u8 volume;
    /* 0x0D */ u8 pan;
    /* 0x0E */ s16 pitchShift;
    /* 0x10 */ Vec3f pos;
} SoundInstance; // size = 0x1C

typedef struct AlternatingSoundSet {
    /* 0x00 */ s32* sounds;
    /* 0x04 */ s16 soundCount;
    /* 0x06 */ s16 curIndex;
} AlternatingSoundSet; // size = 0x08

typedef struct AuVoice {
    /* 0x00 */ Instrument* instrument;
    /* 0x04 */ f32 pitchRatio;
    /* 0x08 */ s32 delta;
    /* 0x0C */ s16 volume; // final combined output volume
    /* 0x0E */ u8 pan;
    /* 0x0F */ u8 reverb;
    /* 0x10 */ u8 busID;
    /* 0x11 */ char pad_11[3];
    /* 0x14 */ EnvelopeData envelope;
    /* 0x1C */ u8* cmdPtr;
    /* 0x20 */ s32 unused_20;
    /* 0x24 */ s32 envDuration;
    /* 0x28 */ s32 envTimeLeft;
    /* 0x2C */ f32 envDelta;
    /* 0x30 */ s32 envScale;
    /* 0x34 */ u8* loopStart; // start position in command list for loop
    /* 0x38 */ u8 loopCounter;
    /* 0x39 */ u8 envInitial;
    /* 0x3A */ u8 envTarget;
    /* 0x3B */ u8 envIntervalIndex;
    /* 0x3C */ u8 unused_3C;
    /* 0x3D */ u8 envelopeFlags;
    /* 0x3E */ b8 isRelativeRelease;
    /* 0x3F */ u8 envRelativeStart;
    /* 0x40 */ s16 clientVolume; // volume set by the client (BGM/MSEQ/Sound player) before any envelope is applied
    /* 0x42 */ u8 donePending; // true when a voice has completed its release phase and is ready for cleanup
    /* 0x43 */ u8 syncFlags;
    /* 0x44 */ s8 clientPriority;
    /* 0x45 */ u8 priority;
    /* 0x46 */ char pad_46[2];
} AuVoice; // size = 0x48

typedef struct BGMFileInfo {
    /* 0x10 */ u8 timingPreset;
    /* 0x11 */ char pad_11[3];
    /* 0x14 */ u16 compositions[4];
    /* 0x1C */ u16 drums;
    /* 0x1E */ u16 drumCount;
    /* 0x20 */ u16 instruments;
    /* 0x22 */ u16 instrumentCount;
} BGMFileInfo; // size = 0x14

typedef struct BGMHeader {
    /* 0x00 */ s32 signature; // 'BGM '
    /* 0x04 */ s32 size; // including header
    /* 0x08 */ s32 name;
    /* 0x0C */ char pad_C[4];
    /* 0x10 */ BGMFileInfo info;
} BGMHeader; // size = 0x24

typedef struct BGMDrumInfo {
    /* 0x0 */ u16 bankPatch; // upper = BankSetIndex, lower = patch
    /* 0x2 */ u16 keyBase;
    /* 0x4 */ u8 volume;
    /* 0x5 */ s8 pan;
    /* 0x6 */ u8 reverb;
    /* 0x7 */ u8 randTune;
    /* 0x8 */ u8 randVolume;
    /* 0x9 */ u8 randPan;
    /* 0xA */ u8 randReverb;
    /* 0xB */ char pad_B[1];
} BGMDrumInfo; // size = 0xC

typedef struct BGMInstrumentInfo {
    /* 0x00 */ u16 bankPatch; // upper = BankSetIndex, lower = patch
    /* 0x02 */ u8 volume;
    /* 0x03 */ s8 pan;
    /* 0x04 */ u8 reverb;
    /* 0x05 */ s8 coarseTune;
    /* 0x06 */ s8 fineTune;
    /* 0x07 */ char pad_7[1];
} BGMInstrumentInfo; // size = 0x8

typedef struct AUFileMetadata {
    /* 0x00 */ s32 signature;   // file type identifer: 'SBN ', 'SEF ', etc
    /* 0x04 */ s32 size;        // full file size, including header and data
} AUFileMetadata;

typedef struct SBNFileEntry {
    /* 0x0 */ s32 offset;
    union {
    /* 0x4 */ u32 data;
    //TODO try replacing the data field with these
    struct {
    /* 0x4 */ s8 fmt;
    /* 0x5 */ char pad_05[1];
    /* 0x6 */ s16 size;
    };
    };
} SBNFileEntry; // size = 0x8

typedef struct SBNHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'SBN '
    /* 0x08 */ char unused_08[8];
    /* 0x10 */ s32 fileListOffset; // offset in the SBN file of the file table (== sizeof(SBNHeader))
    /* 0x14 */ s32 numEntries; // number of entries in the SBN file table
    /* 0x18 */ s32 fullFileSize; // full size of the SBN file (unread)
    /* 0x1C */ s32 versionOffset;
    /* 0x20 */ char unused_04[4];
    /* 0x24 */ s32 INIToffset;
    /* 0x28 */ char unused_28[24];
    /* 0x40 */ SBNFileEntry entries[0];
} SBNHeader; // size = 0x40

typedef struct SEFHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'SEF '
    /* 0x08 */ s32 name;
    /* 0x0C */ char unused_0C[2]; // always 0
    /* 0x0E */ u8 hasExtraSection; // always 1
    /* 0x0F */ char unused_0F[1]; // always 0
    /* 0x10 */ u16 sections[8];
    /* 0x20 */ u16 section2000;
} SEFHeader; // size = 0x22

typedef struct INITHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'INIT'
    /* 0x08 */ u16 bankListOffset;
    /* 0x0A */ u16 bankListSize;
    /* 0x0C */ u16 songListOffset;
    /* 0x0E */ u16 songListSize;
    /* 0x10 */ u16 mseqListOffset;
    /* 0x12 */ u16 mseqListSize;
    /* 0x14 */ char pad_14[0xC];
} INITHeader; // size = 0x20

typedef struct InitSongEntry {
    /* 0x0 */ u16 bgmFileIndex; // required BGM file
    /* 0x2 */ u16 bkFileIndex[3]; // optional BK files for this track
} InitSongEntry; // size = 0x8

typedef struct InitBankEntry {
    /* 0x0 */ u16 fileIndex;
    /* 0x2 */ u8 bankIndex;
    /* 0x3 */ u8 bankSet;
} InitBankEntry; // size = 4

#define INIT_BANK_BUFFER_SIZE 80

typedef struct PERHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'PER ' or 'PRG '
    /* 0x08 */ char pad_08[8];
} PERHeader; // size = 0x10

typedef struct PEREntry {
    /* 0x00 */ BGMDrumInfo drums[12];
} PEREntry; // size = 0x90;

typedef struct BKHeader {
    /* 0x00 */ u16 signature; // 'BK'
    /* 0x02 */ char pad_02[2];
    /* 0x04 */ s32 size;
    /* 0x08 */ s32 name;
    /* 0x0C */ u16 format; // 'CR', 'DR', 'SR'
    /* 0x0E */ u8 swizzled;
    /* 0x0E */ char pad_0E[3];
    /* 0x12 */ u16 instruments[16];
    /* 0x32 */ u16 instrumetsLength;
    /* 0x34 */ u16 loopStatesStart;
    /* 0x36 */ u16 loopStatesLength;
    /* 0x38 */ u16 predictorsStart;
    /* 0x3A */ u16 predictorsLength;
    /* 0x3C */ u16 envelopesStart;
    /* 0x3E */ u16 envelopesLength;
} BKHeader; // size = 0x40

/// Represents a dummy BK file large enough to hold everything except the wave data.
/// Note: The BK file sizes listed in the SBN table match their length excluding wav data.
/// The size of 0x840 bytes was probably chosen to hold the largest BK file in the SBN table,
/// 'GM06' -- listed at exactly 0x840 bytes. However, the devs may have missed that 'GM03'
/// is actually even larger at 0x990 bytes! In both cases, the culprits are unusually long
/// envelope scripts for all 16 instruments.
typedef struct BKFileBuffer {
    /* 0x00 */ BKHeader header;
    /* 0x40 */ u8 data[0x800];
} BKFileBuffer; // size 0x840

typedef struct AuEffectChange {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 changed;
    /* 0x2 */ char pad_02[2];
} AuEffectChange;

typedef struct BGMPlayerSnapshot {
    /* 0x00 */ struct BGMPlayer* bgmPlayer;
    /* 0x04 */ u8 assigned;
    /* 0x05 */ u8 priority;
} BGMPlayerSnapshot;

// found at 801D57A0
typedef struct AuGlobals {
    /* 0x0000 */ f32 outputRate;
    /* 0x0004 */ Instrument* defaultInstrument;
    /* 0x0008 */ BGMDrumInfo defaultDrumEntry;
    /* 0x0014 */ BGMInstrumentInfo defaultPRGEntry;
    /* 0x001C */ s32 baseRomOffset;
    /* 0x0020 */ SBNFileEntry* sbnFileList; /// copied from SBN to the audio heap
    /* 0x0024 */ s32 fileListLength;
    /* 0x0028 */ char pad_28[4];
    /* 0x002C */ InitSongEntry* songList; /// copied from INIT to the audio heap
    /* 0x0030 */ s32 songListLength;
    /* 0x0034 */ s32 bkFileListOffset;
    /* 0x0038 */ s32 bkListLength;
    /* 0x003C */ u16* extraFileList; /// copied from INIT to the audio heap, seems to exist only to find SEF, PER, and PRG
    /* 0x0040 */ AuEffectChange effectChanges[4]; ///< set this to change the effect on an effect bus
    /* 0x0050 */ u8 channelDelayPending;
    /* 0x0051 */ u8 channelDelayBusID;
    /* 0x0052 */ u8 channelDelayTime;
    /* 0x0053 */ u8 channelDelaySide;
    /* 0x0054 */ PEREntry* dataPER;
    /* 0x0058 */ BGMInstrumentInfo* dataPRG;
    /* 0x005C */ struct BGMHeader* dataBGM[2];
    /* 0x0064 */ struct MSEQHeader* dataMSEQ[2];
    /* 0x006C */ BGMPlayerSnapshot snapshots[1];
    /* 0x0074 */ struct BGMPlayer* resumeCopyTo;
    /* 0x0078 */ struct BGMPlayer* resumeCopyFrom;
    /* 0x007C */ s32 resumeSongName;
    /* 0x0080 */ bool resumeRequested;
    /* 0x0084 */ s32 resumeFadeTime;
    /* 0x0088 */ s32 resumeFadeStart;
    /* 0x008C */ s32 resumeFadeEnd;
    /* 0x0090 */ MusicEventTrigger* musicEventQueuePos;
    /* 0x0094 */ MusicEventTrigger* musicEventQueue;
    /* 0x0098 */ u32 musicEventQueueCount;
    /* 0x009C */ s32 flushMusicEventQueue;
    /* 0x00A0 */ SEFHeader* dataSEF;
    /* 0x00A4 */ AuCallback audioThreadCallbacks[2]; // 0 = on begin update, 1 = unimplemented
    /* 0x00AC */ InstrumentBank defaultBankSet[1];
    /* 0x00EC */ InstrumentBank musicBankSet[16];
    /* 0x04EC */ InstrumentBank auxBankSet[4];
    /* 0x05EC */ InstrumentBank bankSet2[16];
    /* 0x09EC */ InstrumentBank bankSet4[16];
    /* 0x0DEC */ InstrumentBank bankSet5[16];
    /* 0x11EC */ InstrumentBank bankSet6[4];
    /* 0x12EC */ InstrumentBank* bankSets[8];
    /* 0x130C */ u8 channelDelayState;
    /* 0x130D */ char pad_130D[3];
    /* 0x1310 */ BKFileBuffer* auxBanks[3];
    /* 0x131C */ char pad_131C[4];
    /* 0x1320 */ AuVoice voices[24];
} AuGlobals; // size = 0x19E0

typedef struct BGMPlayerTrack {
    /* 0x00 */ AuFilePos bgmReadPos;
    /* 0x04 */ AuFilePos savedPos;
    /* 0x08 */ AuFilePos prevReadPos;
    /* 0x0C */ Instrument* instrument;
    /* 0x10 */ EnvelopeData envelope;
    /* 0x18 */ s8_24 insVolume; /// volume for current instrument, reset if instrument is changed
    /* 0x1C */ s16_16 insVolumeStep;
    /* 0x20 */ s16_16 insVolumeTarget;
    /* 0x24 */ s32 insVolumeTicks;
    /* 0x28 */ s32 delayTime;
    /* 0x2C */ s16_16 proxVolume;
    /* 0x30 */ s16_16 proxVolumeStep;
    /* 0x34 */ s16 proxVolumeTarget;
    /* 0x36 */ s16 proxVolumeTicks;
    /* 0x38 */ s16 detune; /// live track detune, independent of instrument, instantly affects all active voices and subsequent notes played
    /* 0x3A */ s16 tremoloDelay;
    /* 0x3C */ char pad_3C[2];
    /* 0x3E */ s16 detourLength;
    /* 0x40 */ SoundPlayChange changed;
    /* 0x44 */ u16 patch;
    /* 0x46 */ u16 insCoarseDetune; /// semitone detune for instrument, reset if instrument is changed
    /* 0x48 */ s8 insFineDetune; /// cent detune for instrument, reset if instrument is changed
    /* 0x49 */ s8 volume; /// track volume, independent of instrument,
    /* 0x4A */ u8 insPan;
    /* 0x4B */ u8 insReverb;
    /* 0x4C */ u8 pressOverride;
    /* 0x4D */ u8 proxMixSetChanged;
    /* 0x4E */ u8 proxMixValChanged;
    /* 0x4F */ u8 proxVol1;
    /* 0x50 */ u8 proxVol2;
    /* 0x51 */ u8 polyVoiceCount; /// number of polyphonic voices for this track
    /* 0x52 */ u8 firstVoice; /// voice idx start
    /* 0x53 */ u8 lastVoice; /// voice idx end, exclusive
    /* 0x54 */ u8 polyphonicIdx;
    /* 0x55 */ u8 tremoloRate;
    /* 0x56 */ u8 tremoloDepth;
    /* 0x57 */ u8 randomPanAmount;
    /* 0x58 */ u8 isDrumTrack;
    /* 0x59 */ u8 linkedTrackID;
    /* 0x5A */ u8 muted; /// prevents notes from this track from being assigned voices, implemented for linked track pairs
    /* 0x5B */ s8 busID;
    /* 0x5C */ u8 index;
    /* 0x5D */ char pad_5D[3];
} BGMPlayerTrack; // size = 0x60;

typedef struct SeqNote {
    /* 0x00 */ Instrument* ins;
    /* 0x00 */ f32 pitchRatio;
    /* 0x08 */ s16 volume;
    /* 0x0A */ s16 detune;
    /* 0x0C */ s32 length; /// attack + sustain time
    /* 0x10 */ u16 tremoloDelay;
    /* 0x12 */ u8 tremoloDepth;
    /* 0x12 */ u8 tremoloPhase;
    /* 0x14 */ s16 randDetune;
    /* 0x16 */ u8 velocity;
    /* 0x17 */ u8 pendingTick;
} SeqNote; // size = 0x18;

typedef struct BGMPlayer {
    /* 0x000 */ AuGlobals* globals;
    /* 0x004 */ SoundManager* soundManager;
    /* 0x008 */ s32 nextUpdateStep; /// update counter amount to add per audio frame
    /* 0x00C */ s32 tickUpdateInterval; /// update counter threshold for a single tick
    /* 0x010 */ s32 nextUpdateCounter; /// current update counter value
    /* 0x014 */ s32 frameCounter; /// video frames (60 fps)
    /* 0x018 */ s32 songPlayingCounter;
    /* 0x01C */ s32 songName;
    /* 0x020 */ s32 pushSongName;
    /* 0x024 */ s32 bgmFileIndex;
    /* 0x028 */ s32 songID;
    /* 0x02C */ Fade fadeInfo;
    /* 0x048 */ s32 busVolume;
    /* 0x04C */ u8 effectIndices[4];
    /* 0x050 */ s32 randomValue1;
    /* 0x054 */ s32 randomValue2;
    /* 0x058 */ u16 unk_58; // related to legacy command system, unused
    /* 0x05A */ u16 unk_5A; // related to legacy command system, unused
    /* 0x05C */ s16 prevUpdateResult; // unused, may indicate error status
    /* 0x05E */ char pad_5E[2];
    /* 0x060 */ s32 curVariation;
    /* 0x064 */ struct BGMHeader* bgmFile;
    /* 0x068 */ SegData* compReadPos;
    /* 0x06C */ SegData* compStartPos;
    /* 0x070 */ SegData* phraseStartPos;
    /* 0x074 */ u8* tickRatePtr; // related to legacy command system, unused
    /* 0x078 */ BGMDrumInfo* drumsInfo;
    /* 0x07C */ BGMInstrumentInfo* instrumentsInfo;
    /* 0x080 */ BGMDrumInfo* drums[12];
    /* 0x0B0 */ s32 masterTempo;
    /* 0x0B4 */ s32 masterTempoStep;
    /* 0x0B8 */ s32 masterTempoTarget;
    /* 0x0BC */ s32 masterTempoTicks;
    /* 0x0C0 */ s8_24 masterVolume;
    /* 0x0C4 */ s32 masterVolumeStep;
    /* 0x0C8 */ s32 masterVolumeTarget;
    /* 0x0CC */ s32 masterVolumeTicks;
    /* 0x0D0 */ f32 playbackRate;
    /* 0x0D4 */ SeqArgs seqCmdArgs;
    /* 0x0D8 */ SegData* compLoopStartLabels[32];
    /* 0x158 */ SegData* compActiveLoopEndPos[4];
    /* 0x168 */ u8 compLoopCounters[4];
    /* 0x16C */ s32 proxMixValue;
    /* 0x170 */ u8 proxMixID;
    /* 0x171 */ u8 proxMixVolume;
    /* 0x172 */ char pad_172[2];
    /* 0x174 */ s16 customPressEnvelopes[8][9]; /// Dynamically customizable press envelopes
    /* 0x204 */ u8* trackVolsConfig;
    /* 0x208 */ u16 masterTempoBPM;
    /* 0x20A */ u16 maxTempo;
    /* 0x20C */ u16 masterPitchShift;
    /* 0x20E */ s16 detune;
    /* 0x210 */ u8 compLoopDepth;
    /* 0x211 */ u8 writingCustomEnvelope; /// Currently active (for writing) custom envelope
    /* 0x212 */ u8 customEnvelopeWritePos[8]; /// Current write position for each custom envelope
    /* 0x21A */ s8 volumeChanged;
    /* 0x21B */ u8 totalVoices;
    /* 0x21C */ u8 bgmDrumCount;
    /* 0x21D */ u8 bgmInstrumentCount;
    /* 0x21E */ u8 unused_21E;
    /* 0x21F */ char pad_21F[1];
    /* 0x220 */ u8 paused;
    /* 0x221 */ u8 masterState;
    /* 0x222 */ u8 unused_222;
    /* 0x223 */ u8 conditionalLoopFlags; /// No means to modify value is implemented
    /* 0x224 */ u8 effectValues[4];
    /* 0x227 */ char pad_228[2];
    /* 0x22A */ u8 polyphonyCounts[8];
    /* 0x232 */ u8 bFadeConfigSetsVolume;
    /* 0x233 */ u8 initLinkMute; /// Used to mute any linked tracks after the first one encountered.
    /* 0x234 */ u8 priority;
    /* 0x235 */ u8 busID;
    /* 0x236 */ char pad_236[2];
    /* 0x238 */ s32 cmdBufData[8]; /// Buffer for an unused (legacy) system for controlling the BGMPlayer from the main thread
    /* 0x258 */ u8 cmdBufPending;
    /* 0x259 */ u8 cmdBufReadPos;
    /* 0x25A */ u8 cmdBufWritePos;
    /* 0x25B */ u8 cmdBufOverflows;
    /* 0x25C */ BGMPlayerTrack tracks[16];
    /* 0x85C */ SeqNote notes[24]; /// Currently playing notes
} BGMPlayer; // size = 0xA9C

// all Song*Request structs are probably one struct with a union for args 0/1/2/3 at offsets 0x10-0x1C
// keeping them separated lets us type-check the arguments to functions which accept them

typedef struct SongStartRequest {
    /* 0x00 */ s32 songName;
    /* 0x04 */ s32 duration;
    /* 0x08 */ s32 startVolume;
    /* 0x0C */ s32 finalVolume;
    /* 0x10 */ s32 variation;
    /* 0x14 */ s32 unused_14;
    /* 0x18 */ char pad_18[8];
} SongStartRequest; // size = 0x1C or 0x20

typedef struct SongFadeOutRequest {
    /* 0x00 */ s32 songName;
    /* 0x04 */ s32 duration;
    /* 0x08 */ s32 unused_08;
    /* 0x0C */ s32 finalVolume;
    /* 0x10 */ AuCallback doneCallback;
    /* 0x14 */ s32 onPush;
    /* 0x18 */ char pad_18[8];
} SongFadeOutRequest; // size = 0x1C or 0x20

typedef struct SongSuspendRequest {
    /* 0x00 */ s32 songName;
    /* 0x04 */ s32 duration;
    /* 0x08 */ s32 startVolume;
    /* 0x0C */ s32 finalVolume;
    /* 0x10 */ s32 index;
    /* 0x14 */ s32 pauseMode; /// if true, the player is paused, else it will be saved to a snapshot
    /* 0x18 */ char pad_18[8];
} SongSuspendRequest; // size = 0x1C or 0x20

typedef struct SongResumeRequest {
    /* 0x00 */ s32 songName;
    /* 0x04 */ s32 duration;
    /* 0x08 */ s32 startVolume;
    /* 0x0C */ s32 finalVolume;
    /* 0x10 */ s32 index;
    /* 0x14 */ s32 pauseMode;
    /* 0x18 */ char pad_18[8];
} SongResumeRequest; // size = 0x1C or 0x20

typedef struct SongSwapLinkedRequest {
    /* 0x00 */ s32 songName;
    /* 0x04 */ char unused_04[4];
    /* 0x08 */ char unused_08[4];
    /* 0x0C */ char unused_0C[4];
    /* 0x10 */ bool enabled; // 0 or 1
    /* 0x18 */ char pad_14[0xC];
} SongSwapLinkedRequest; // size = 0x1C or 0x20

typedef struct MSEQTrackData {
    /* 0x0 */ u8 trackIndex;
    /* 0x1 */ u8 type;
    /* 0x2 */ s16 time;
    /* 0x4 */ s16 delta;
    /* 0x6 */ s16 goal;
} MSEQTrackData; // size = 0x8

typedef struct MSEQHeader {
    /* 0x00 */ s32 signature; // 'MSEQ '
    /* 0x04 */ s32 size; // including header
    /* 0x08 */ s32 name;
    /* 0x0C */ u8 firstVoiceIdx;
    /* 0x0D */ u8 trackSettingsCount;
    /* 0x0E */ u16 trackSettingsOffset;
    /* 0x10 */ u16 dataStart;
    /* 0x12 */ char pad_12[6];
} MSEQHeader; // size = 0x18

typedef struct AmbienceTrack {
    /* 0x00 */ Instrument* instrument;
    /* 0x04 */ EnvelopeData envelope;
    /* 0x0C */ SoundLerp tuneLerp;
    /* 0x18 */ SoundLerp volumeLerp;
    /* 0x24 */ s8 pan;
    /* 0x25 */ s8 reverb;
    /* 0x26 */ u8 flags;
    /* 0x27 */ char pad_27[1];
} AmbienceTrack; // size = 0x28

typedef struct AmbienceSavedVoice {
    /* 0x0 */ u8 trackIndex;
    /* 0x1 */ u8 tune;
    /* 0x2 */ s8 volume;
    /* 0x4 */ char pad_03[1];
} AmbienceSavedVoice; // size = 0x4

/**
 * @brief Compact identifier for a voice used by the ambience system.
 *
 * This union is used to track ownership and identity of each voice slot
 * controlled by an ambience player. It can be accessed either as individual
 * fields (player, track, tune, release flag) or as a single 32-bit key.
 *
 * This allows fast comparisons and matching of voices during updates, fades,
 * and command execution (e.g. stop or pitch/volume changes).
 */
typedef union AmbVoiceStateInfo {
    struct {
        u8 playerIndex;     /// Index of the owning ambience player
        u8 trackIndex;      ///< Track index within the player (0–9)
        u8 tune;            ///< Note or drum ID used to differentiate voices on the same track
        u8 released;        ///< Set to true when the voice should be released/stopped
    };
    s32 all;
} AmbVoiceStateInfo;

typedef struct AmbienceVoiceState {
    /* 0x00 */ AmbVoiceStateInfo info;
    /* 0x04 */ s16 pitch;
    /* 0x06 */ s8 volume;
    /* 0x07 */ u8 isResumable;
} AmbienceVoiceState; // size = 0x8

typedef struct AmbiencePlayer {
    /* 0x000 */ MSEQHeader* mseqFile;
    /* 0x004 */ AuFilePos mseqReadStart;
    /* 0x008 */ AuFilePos mseqReadPos;
    /* 0x00C */ AuFilePos loopStartPos[2];
    /* 0x014 */ AmbVoiceStateInfo id;
    /* 0x018 */ s32 delay;
    /* 0x01C */ char pad_1C[4];
    /* 0x020 */ s32 mseqName;
    /* 0x024 */ u8 mode;
    /* 0x025 */ u8 playState;
    /* 0x026 */ u8 fadeSettingsType;
    /* 0x027 */ char pad_27[1];
    /* 0x028 */ u16 fadeSettingsTime;
    /* 0x02A */ u8 fadeSettingsInitial; // 255 means from current volume
    /* 0x02B */ u8 fadeSettingsGoal;
    /* 0x02C */ u8 loopCount[2];
    /* 0x02E */ char pad_2E[2];
    /* 0x030 */ u32 firstVoiceIdx;
    /* 0x034 */ u32 lastVoiceIdx;
    /* 0x038 */ s8_24 fadeVolume;
    /* 0x03C */ s8_24 fadeStep;
    /* 0x040 */ u16 fadeTime;
    /* 0x042 */ u8 fadeGoal;
    /* 0x043 */ u8 resetRequired;
    /* 0x044 */ AmbienceTrack tracks[10];
    /* 0x1D4 */ AmbienceSavedVoice savedVoices[4];
} AmbiencePlayer; // size = 0x1E4

typedef struct AmbienceManager {
    /* 0x000 */ AuGlobals* globals;
    /* 0x004 */ s32 nextUpdateStep;
    /* 0x008 */ s32 nextUpdateInterval;
    /* 0x00C */ s32 nextUpdateCounter;
    /* 0x010 */ MSEQHeader* mseqFiles[4];
    /* 0x020 */ u8 numActivePlayers;
    /* 0x021 */ u8 loadTracksFadeInfo;
    /* 0x022 */ u8 priority;
    /* 0x023 */ u8 busID;
    /* 0x024 */ AmbiencePlayer players[4];
    /* 0x7B4 */ AmbienceVoiceState voiceStates[16];
} AmbienceManager;

typedef struct ALConfig {
    /* 0x00 */ s32 num_pvoice;
    /* 0x04 */ s32 num_bus;
    /* 0x08 */ s32 outputRate; /// hardware sample output rate
    /* 0x0C */ u8 unused_0C;
    /* 0x0D */ char pad_0D[3];
    /* 0x10 */ void* dmaNew;
    /* 0x14 */ ALHeap* heap;
} ALConfig; // size = 0x18;

#ifndef NO_EXTERN_VARIABLES

extern volatile u8 AuSynUseStereo;
extern s16 DummyInstrumentCodebook[32];
extern u8 DummyInstrumentWavData[190];
extern s32 CUSTOM_SMALL_ROOM_PARAMS[];
extern s32 CUSTOM_ECHO_PARAMS_1[];
extern s32 CUSTOM_ECHO_PARAMS_3[];
extern s32 CUSTOM_ECHO_PARAMS_2[];
extern EnvelopePreset DummyInstrumentEnvelope;
extern u8 AmbientSoundIDtoMSEQFileIndex[];
extern s32 AuEnvelopeIntervals[];
extern s32 PreventBGMPlayerUpdate;
extern u16 AmbienceRadioChannel;

extern AuSynDriver* gActiveSynDriverPtr;
extern AuSynDriver* gSynDriverPtr;
extern u8 AuUseGlobalVolume;
extern u16 AuGlobalVolume;
extern u8 AuSynStereoDirty;

extern AuGlobals* gSoundGlobals;
extern BGMPlayer* gBGMPlayerC;
extern BGMPlayer* gBGMPlayerB;
extern AmbienceManager* gAuAmbienceManager;
extern SoundManager* gSoundManager;
extern BGMPlayer* gBGMPlayerA;

#endif

#include "audio/private.h"

#endif
