#ifndef _AUDIO_H_
#define _AUDIO_H_
#include "nu/nusys.h"
#include "nu/nualsgi.h"
#include "PR/n_abi.h"
#include "common.h"

// temporary to keep track of unk portions of alUnk structs (not just unk fields)
typedef s8  UNK_TYPE_08;
typedef s16 UNK_TYPE_16;
typedef s32 UNK_TYPE_32;
typedef void* UNK_TYPE_PTR;

typedef u8* AuFilePos;
typedef u8* WaveData;

#define NO_INSTRUMENT ((Instrument*) -1)

#define AU_FX_DELAY_COUNT     4
#define AU_FX_LENGTH          0xA10

#define AU_5750               5750

#define SAMPLES               184
#define SAMPLE184(delta)      (((delta) + (SAMPLES / 2)) / SAMPLES) * SAMPLES
#define FIXED_SAMPLE          SAMPLES

#define N_AL_DECODER_IN         0
#define N_AL_RESAMPLER_OUT      0
#define N_AL_TEMP_0             0
#define N_AL_DECODER_OUT        0x170
#define N_AL_TEMP_1             0x170
#define N_AL_TEMP_2             0x2E0
#define N_AL_MAIN_L_OUT         0x4E0
#define N_AL_MAIN_R_OUT         0x650
#define N_AL_AUX_L_OUT          0x7C0
#define N_AL_AUX_R_OUT          0x930

#define ALIGN16_(val) (((val) + 0xF) & 0xFFF0)
#define AU_FILE_RELATIVE(base,offset) ((void*)((s32)(offset) + (s32)(base)))

#define AUDIO_HEAP_SIZE 0x56000
 // NU_AU_AUDIO_SAMPLES ?
#define AUDIO_SAMPLES   184
#define AUDIO_COMMAND_LIST_BUFFER_SIZE 0x4000

#define ADPCMFBYTES     9

#define SND_MAX_VOLUME_8  0x7F // 127
#define SND_MAX_VOLUME_16 0x7FFF

#define BGM_SAMPLE_RATE 156250
#define BGM_DEFAULT_TEMPO 15600

#define SND_MIN_DURATION 250
#define SND_MAX_DURATION 10000

#define BGM_MAX_VOLUME 127

#define BGM_SEGMENT_LABEL 3

typedef u32 SegData;

typedef enum AuPriority {
    AU_PRIORITY_FREE            = 0,
    AU_PRIORITY_BGM_PLAYER_MAIN = 1,
    AU_PRIORITY_BGM_PLAYER_AUX  = 2,
    AU_PRIORITY_SFX_MANAGER     = 4,
    AU_PRIORITY_MSEQ_MANAGER    = 6,
} AuPriority;

enum AuVoiceEnvelopeFlags {
    AU_VOICE_ENV_FLAG_STOP                  = 0x01,
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
    AU_FX_NONE          = 0,
    AU_FX_SMALLROOM     = 1,
    AU_FX_BIGROOM       = 2,
    AU_FX_CHORUS        = 3,
    AU_FX_FLANGE        = 4,
    AU_FX_ECHO          = 5,
    AU_FX_CUSTOM_0      = 6,
    AU_FX_CUSTOM_1      = 7,
    AU_FX_CUSTOM_2      = 8,
    AU_FX_CUSTOM_3      = 9,
    AU_FX_OTHER_BIGROOM = 10
} AuEffectType;

typedef enum BGMPlayerState {
    BGM_PLAY_STATE_IDLE             = 0,
    BGM_STATE_PLAY_SUBSEG           = 1,
    BGM_PLAY_STATE_NEXT_SUBSEG      = 2,
    BGM_PLAY_STATE_INIT             = 3,
    BGM_PLAY_STATE_STOP             = 4
} BGMPlayerState;

typedef enum SegmentControlCommands {
    BGM_SEGMENT_END                 = 0,
    BGM_SEGMENT_SUBSEG              = 1,
    BGM_SEGMENT_START_LOOP          = 3,
    BGM_SEGMENT_WAIT                = 4,
    BGM_SEGMENT_END_LOOP            = 5,
    BGM_SEGMENT_6                   = 6,
    BGM_SEGMENT_7                   = 7
} SegmentControlCommands;

typedef enum FxBus {
    FX_BUS_BGMA_MAIN    = 0,
    FX_BUS_SOUND        = 1,
    FX_BUS_BGMB         = 2,
    FX_BUS_BGMA_AUX     = 3,
} FxBus;

typedef enum EnvelopeCommand {
    ENV_CMD_END_LOOP        = 0xFB,
    ENV_CMD_START_LOOP      = 0xFC,
    ENV_CMD_ADD_MULTIPLIER  = 0xFD,
    ENV_CMD_SET_MULTIPLIER  = 0xFE,
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

typedef union AmbVoiceStateInfo {
    struct {
        u8 playerIndex;
        u8 trackIndex;
        u8 tune;
        u8 released;
    };
    s32 all;
} AmbVoiceStateInfo;

struct BGMPlayer;
struct AuGlobals;
struct AuVoice;

typedef void (*AuCallback)(void);

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
    } TrackOverridePatch;
    struct { // cmd E9
        u8 value;
    } SubTrackVolume;
    struct { // cmd EA
        u8 value;
    } SubTrackPan;
    struct { // cmd EB
        u8 value;
    } SubTrackReverb;
    struct { // cmd EC
        u8 value;
    } SegTrackVolume;
    struct { // cmd ED
        u8 cent;
    } SubTrackCoarseTune;
    struct { // cmd EE
        u8 value;
    } SubTrackFineTune;
    struct { // cmd EF
        u16 value;
    } SegTrackTune;
    struct { // cmd F0
        u8 amount;
        u8 speed;
        u8 time;
    } TrackTremolo;
    struct { // cmd F1
        u8 value;
    } TrackTremoloSpeed;
    struct { // cmd F2
        u8 time;
    } TrackTremoloTime;
    // no args for F3 (TrackTremoloStop)
    struct { // cmd F4
        u8 pan0;
        u8 pan1;
    } UnkCmdF4;
    struct { // cmd F5
        u8 index;
    } SetTrackVoice;
    struct { // cmd F6
        u16 time;
        u8 value;
    } TrackVolumeFade;
    struct { // cmd F7
        u8 index;
    } SubTrackReverbType;
    // commands F8-FB unused
    struct { // cmd FC
        u16 unk_00;
        u8 unk_02;
    } Jump;
    struct { // cmd FD
        u32 eventInfo;
    } EventTrigger;
    struct { // cmd FE
        u16 offset;
        u8 length;
    } Detour;
    struct { // cmd FF
        u8 unk_00;
        u8 unk_01;
        u8 unk_02;
    } UnkCmdFF;
} SeqArgs;

typedef union VolumeField {
    u16 u16;
    s32 s32;
} VolumeField;

// envelope related?
typedef struct Fade {
    /* 0x0 */ VolumeField curVolume;
    /* 0x4 */ s32 fadeStep;
    /* 0x8 */ s16 targetVolume;
    /* 0xA */ s16 fadeTime;
              union {
    /* 0xC */ AuCallback onCompleteCallback;
    /* 0xC */ s32 variation;
              };
    // fields below are envelope?
    /* 0x10 */ VolumeField volScale;
    /* 0x14 */ s32 volScaleStep;
    /* 0x18 */ s16 targetVolScale;
    /* 0x1A */ s16 volScaleTime;
} Fade; // size = 0x10

typedef struct AlUnkPi {
    /* 0x00 */ UNK_TYPE_32 unk_00;
    /* 0x04 */ UNK_TYPE_32 unk__04;
    /* 0x08 */ UNK_TYPE_32 unk_08;
    /* 0x0C */ UNK_TYPE_32 unk_0C;
} AlUnkPi; // size = 0x8

// based on ALDelay
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
    /* 0x20 */ struct AuLowPass* lowpass_20; // [ALLowPass] ?
    /* 0x24 */ struct AuLowPass* lowpass_24; // [ALLowPass] ?
    /* 0x28 */ struct AuResampler* resampler_28; // [ALResampler] ?
    /* 0x2C */ struct AuResampler* resampler_2C; // [ALResampler] ?
} AuDelay; // size = 0x30

// based on ALFx
typedef struct AuFX {
    /* 0x00 */ s16* base;
    /* 0x04 */ s16* input;
    /* 0x08 */ s32 length;
    /* 0x0C */ AuDelay* delays;
    /* 0x10 */ u8 delayCount;
} AuFX; // size = 0x14

// based on ALLowPass
typedef struct AuLowPass {
    /* 0x00 */ s16 fc;
    /* 0x02 */ s16 fgain;
    // ALLowPass uses a union with force_aligned to create this padding
    /* 0x04 */ char pad_04[4];
    /* 0x08 */ s16 fccoef[16];
    /* 0x28 */ POLEF_STATE* fstate;
    /* 0x2C */ s32 first;
} AuLowPass; // size = 0x30

typedef struct AlUnkKappa {
    /* 0x00 */ UNK_TYPE_PTR unk_00; // size = 2 * 1420h
    /* 0x04 */ UNK_TYPE_16 unk__04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ UNK_TYPE_16 unk__0A;
    /* 0x0C */ AuLowPass* lowpass_0C;
    /* 0x10 */ AuLowPass* lowpass_10;
} AlUnkKappa; // size unk

typedef struct AuFxBus {
    /* 0x00 */ u16 gain;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ AuFX* fxL;
    /* 0x08 */ AuFX* fxR;
    /* 0x0C */ u8 curEffectType;
    /* 0x0D */ char unk_0D[0x3];
    /* 0x10 */ struct AuPVoice* head;
    /* 0x14 */ struct AuPVoice* tail;
} AuFxBus; // size = 0x18

 // ALDMAproc in PM supposedly has an extra arg added, so that's why we have ALDMAproc2 and ALDMANew2
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
    /* 0x0C */ s32 first;
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
    /* 0x24 */ s32 first;
    /* 0x28 */ s32 motion;
} AuEnvMixer; // size = 0x2C

// based on N_PVoice
typedef struct AuPVoice {
    /* 0x00 */ struct AuPVoice* next;
    /* 0x04 */ AuLoadFilter decoder;
    /* 0x38 */ AuResampler resampler;
    /* 0x48 */ AuEnvMixer envMixer;
    /* 0x74 */ s16 unk_74;
    /* 0x76 */ s16 unk_76;
    /* 0x78 */ u8 busId;
    /* 0x79 */ u8 index;
    /* 0x7A */ u8 unk_7A[2];
} AuPVoice;

// based on N_ALSynth
typedef struct AuSynDriver {
    /* 0x00 */ s32 curSamples;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 outputRate;
    /* 0x0C */ s32 num_pvoice;
    /* 0x10 */ s32 num_bus;
    /* 0x14 */ ALDMANew2 dmaNew; // pointer to nuAuDmaNew
    /* 0x18 */ ALHeap* heap;
    /* 0x1C */ AuPVoice* pvoices;
    /* 0x20 */ AuFxBus* fxBus;
    /* 0x24 */ s32* savedMainOut; // struct size = 0x170
    /* 0x28 */ s32* savedAuxOut; // struct size = 0x170
} AuSynDriver;

typedef struct SoundSFXEntry {
    /* 0x0 */ u16 soundID;
    /* 0x2 */ u16 upperSoundID;
    /* 0x4 */ s16 volume;
    /* 0x6 */ s16 pitchShift;
    /* 0x8 */ s8 pan;
    /* 0x9 */ char unk_9[0x1];
} SoundSFXEntry; // size = 0xA

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
    /* 0x01 */ char unk_01[3];
    /* 0x04 */ EnvelopeOffset offsets[1]; // variable size
} EnvelopePreset;

// partially ALWaveTable?
typedef struct Instrument {
    /* 0x00 */ u8* base;
    /* 0x04 */ u32 wavDataLength;
    /* 0x08 */ UNK_PTR loopPredictor;
    /* 0x0C */ s32 loopStart;
    /* 0x10 */ s32 loopEnd;
    /* 0x14 */ s32 loopCount;
    /* 0x18 */ u16* predictor;
    /* 0x1C */ u16 dc_bookSize;
    /* 0x1E */ u16 keyBase;
    /* 0x20 */ union {
                    f32 pitchRatio;
                    s32 outputRate;
               };
    /* 0x24 */ u8 type;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ s8 unk_26;
    /* 0x27 */ s8 unk_27;
    /* 0x28 */ s8 unk_28;
    /* 0x29 */ s8 unk_29;
    /* 0x2A */ s8 unk_2A;
    /* 0x2B */ s8 unk_2B;
    /* 0x2C */ EnvelopePreset* envelopes;
} Instrument; // size = 0x30;

typedef Instrument* InstrumentGroup[16];

typedef struct SoundLerp {
    /* 0x0 */ s32 current;
    /* 0x4 */ s32 step;
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
    /* 0x04 */ char pad4[0xC];
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
    /* 0x78 */ u8 cmdList_mode2[8];
    /* 0x80 */ AuFilePos alternativeDataPos;
    /* 0x84 */ s8 alternativeType;
    /* 0x85 */ u8 triggers;
    /* 0x86 */ char unk_86[0x2];
    /* 0x88 */ s8* loopStartPos;
    /* 0x8C */ u8 loopIterCount; // loopIterCount = 0 for infinite loop
    /* 0x8D */ char unk_8D;
    /* 0x8E */ u16 delay;
    /* 0x90 */ u16 playLength;
    /* 0x92 */ s16 coarseTune;
    /* 0x94 */ s8 fineTune;
    /* 0x95 */ char unk_05;
    /* 0x96 */ u16 curSoundID;
    /* 0x98 */ u8 priority;
    /* 0x99 */ u8 exclusiveID;
    /* 0x9A */ u8 sfxParamsFlags;
    /* 0x9B */ u8 sfxPan;
    /* 0x9C */ u8 reverb;
    /* 0x9D */ u8 instrumentIndex; // ?
    /* 0x9E */ u8 envelopePreset;
    /* 0x9F */ u8 playVelocity;
    /* 0xA0 */ u8 unk_A0;
    /* 0xA1 */ u8 randomPitch;
    /* 0xA2 */ u8 randomVelocity;
    /* 0xA3 */ s8 unk_A3;
    /* 0xA4 */ s16 masterPitchShift;
    /* 0xA6 */ s16 masterVolume;
    /* 0xA8 */ u8 masterPan;
    /* 0xA8 */ u8 state;
    /* 0xA9 */ char unk_AA[0x2];
} SoundPlayer; // size = 0xAC

typedef struct SoundManager90 {
    union {
    /* 0x0 */ s32 s32;
        struct {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ u8 unk_2;
    /* 0x3 */ u8 volume;
        };
    };
} SoundManager90; // size = 4

typedef struct SoundManagerCustomCmdList {
    /* 0x0 */ u16 data[3];
} SoundManagerCustomCmdList; // size = 6

typedef struct SoundManager {
    /* 0x000 */ struct AuGlobals* globals;
    /* 0x004 */ struct AuVoice* curVoice;
    /* 0x008 */ u8* sefData;
    /* 0x00C */ s32* normalSounds[8];
    /* 0x02C */ s32* extraSounds;
    /* 0x030 */ s32 playCounter; //?
    /* 0x034 */ s32 nextUpdateStep;
    /* 0x038 */ s32 nextUpdateInterval;
    /* 0x03C */ s32 nextUpdateCounter;
    /* 0x040 */ struct Fade fadeInfo;
    /* 0x05C */ s32 busVolume;
    /* 0x060 */ s32 randomValue;
    /* 0x064 */ s32* customReverbParams[8];
    /* 0x084 */ s8 customReverbAmounts[8];
    /* 0x08C */ u8 lastCustomEffectIdx;
    /* 0x08D */ s8 defaultReverbAmt;
    /* 0x08E */ char unk_8E[0x2];
    /* 0x090 */ SoundManager90 bgmSounds[4];
    /* 0x0A0 */ SoundManagerCustomCmdList customCmdList[4];
    /* 0x0B8 */ u16 baseVolume;
    /* 0x0BA */ s16 unk_BA;
    /* 0x0BC */ u8 priority;
    /* 0x0BD */ u8 sfxPlayerSelector;
    /* 0x0BE */ u8 busId;
    /* 0x0BF */ u8 curVoiceIndex;
    /* 0x0C0 */ u8 state;
    /* 0x0C1 */ char unk_C1[0x1];
    /* 0x0C2 */ SoundSFXEntry soundQueue[16];
    /* 0x162 */ s8 unk_162;
    /* 0x163 */ u8 sfxQueuePosOffset;
    /* 0x164 */ u8 sfxQueueNextPos;
    /* 0x165 */ s8 unk_165;
    /* 0x166 */ char unk_166[0x2];
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
    /* 0x0C */ s16 p_volume; // volume for pvoice
    /* 0x0E */ u8 pan;
    /* 0x0F */ u8 reverb;
    /* 0x10 */ u8 busId;
    /* 0x11 */ char unk_11[0x3];
    /* 0x14 */ EnvelopeData envelope;
    /* 0x1C */ u8* cmdPtr;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 volChangeTime;
    /* 0x28 */ s32 timeLeft;
    /* 0x2C */ f32 rate;
    /* 0x30 */ s32 volMult;
    /* 0x34 */ u8* loopStart;
    /* 0x38 */ u8 loopCounter;
    /* 0x39 */ u8 initialAmp;
    /* 0x3A */ u8 targetAmp;
    /* 0x3B */ u8 timeIntervalIndex;
    /* 0x3C */ u8 unk_3C;
    /* 0x3D */ u8 envelopeFlags;
    /* 0x3E */ u8 relativeReleaseVolumes;
    /* 0x3F */ u8 releaseVolumeMult;
    /* 0x40 */ s16 clientVolume;
    /* 0x42 */ u8 stopPending;
    /* 0x43 */ u8 syncFlags;
    /* 0x44 */ s8 clientPriority;
    /* 0x45 */ u8 priority;
    /* 0x46 */ char unk_46[2];
} AuVoice; // size = 0x48

typedef struct BGMFileInfo {
    /* 0x10 */ u8 numSegments;
    /* 0x11 */ char pad_11[3];
    /* 0x14 */ u16 segments[4];
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
    /* 0x0 */ s16 bankPatch;
    /* 0x2 */ s16 keyBase;
    /* 0x4 */ u8 volume;
    /* 0x5 */ s8 pan;
    /* 0x6 */ s8 reverb;
    /* 0x7 */ u8 randTune;
    /* 0x8 */ u8 randVolume;
    /* 0x9 */ u8 randPan;
    /* 0xA */ u8 randReverb;
    /* 0xB */ char pad_B[1];
} BGMDrumInfo; // size = 0xC

typedef struct BGMInstrumentInfo {
    /* 0x00 */ u16 bankPatch; // upper = bank, lower = patch
    /* 0x02 */ u8 volume;
    /* 0x03 */ s8 pan;
    /* 0x04 */ s8 reverb;
    /* 0x05 */ s8 coarseTune;
    /* 0x06 */ s8 fineTune;
    /* 0x07 */ char pad_7[1];
} BGMInstrumentInfo; // size = 0x8

typedef struct AUFileMetadata {
    /* 0x00 */ s32 signature;   // file type identifer: 'SBN ', 'SEF ', etc
    /* 0x04 */ s32 size;        // full file size, including header and data
} AUFileMetadata;

typedef struct SBNHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'SBN '
    /* 0x08 */ char unused_08[8];
    /* 0x10 */ s32 tableOffset; // offset in the SBN file of the file table (== sizeof(SBNHeader))
    /* 0x14 */ s32 numEntries;  // number of entries in the SBN file table
    /* 0x18 */ s32 fileSize;    // full size of the SBN file (unread)
    /* 0x1C */ s32 versionOffset;
    /* 0x20 */ char unused_04[4];
    /* 0x24 */ s32 INIToffset;
    /* 0x28 */ char reserved[24];
} SBNHeader; // size = 0x40

typedef struct SEFHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'SEF '
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s8 unkC; // 0
    /* 0x0D */ s8 unkD; // 0
    /* 0x0E */ u8 hasExtraSection; // 1
    /* 0x0F */ s8 unkF; // 0
    /* 0x10 */ u16 sections[8];
    /* 0x20 */ u16 section2000;
} SEFHeader; // size = 0x22

typedef struct INITHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'INIT'
    /* 0x08 */ u16 entriesOffset;
    /* 0x0A */ u16 entriesSize;
    /* 0x0C */ u16 tblOffset;
    /* 0x0E */ u16 tblSize;
    /* 0x10 */ u16 shortsOffset;
    /* 0x12 */ u16 shortsSize;
    /* 0x14 */ char unk_14[0xC];
} INITHeader; // size = 0x20

typedef struct PERHeader {
    /* 0x00 */ AUFileMetadata mdata; // uses identifer 'PER ' or 'PRG '
    /* 0x08 */ char unk_08[8];
} PERHeader; // size = 0x10

typedef struct PEREntry {
    /* 0x00 */ BGMDrumInfo drums[12];
} PEREntry; // size = 0x90;

typedef struct SBNFileEntry {
    /* 0x0 */ s32 offset;
    union {
    /* 0x4 */ u32 data;
    //TODO try replacing the data field with these
    struct {
    /* 0x4 */ s8 fmt;
    /* 0x5 */ UNK_TYPE_08 unk__05;
    /* 0x6 */ s16 size;
    };
    };
} SBNFileEntry; // size = 0x8

typedef struct BKHeader {
    /* 0x00 */ u16 signature; // 'BK'
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s32 size;
    /* 0x08 */ s32 name;
    /* 0x0C */ u16 format; // 'CR', 'DR', 'SR'
    /* 0x0E */ char unk_0E[2];
    /* 0x10 */ char unk_10[2];
    /* 0x12 */ u16 instruments[16];
    /* 0x32 */ u16 instrumetsSize;
    /* 0x34 */ u16 unkStartA;
    /* 0x36 */ u16 unkSizeA;
    /* 0x38 */ u16 predictorsStart;
    /* 0x3A */ u16 predictorsSize;
    /* 0x3C */ u16 unkStartB;
    /* 0x3E */ u16 unkSizeB;
} BKHeader; // size = 0x40

typedef struct InitSongEntry {
    /* 0x0 */ u16 bgmFileIndex; // required BGM file
    /* 0x2 */ u16 bkFileIndex[3]; // optional BK files for this track
} InitSongEntry; // size = 0x8

typedef struct SoundBank {
    /* 0x000 */ char unk_00[0xE];
    /* 0x00E */ u8 swizzled;
    /* 0x010 */ char unk_0F[0x831];
} SoundBank; // size = 0x840

typedef struct AuEffectChange {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 changed;
    /* 0x2 */ char unk_02[2];
} AuEffectChange;

typedef struct SndGlobalsSub6C {
    /* 0x00 */ struct BGMPlayer* bgmPlayer;
    /* 0x04 */ u8 unk_4;
    /* 0x05 */ u8 unk_5;
} SndGlobalsSub6C;

// found at 801D57A0
typedef struct AuGlobals {
    /* 0x0000 */ f32 outputRate;
    /* 0x0004 */ Instrument* defaultInstrument;
    /* 0x0008 */ BGMDrumInfo defaultDrumEntry;
    /* 0x0014 */ BGMInstrumentInfo defaultPRGEntry;
    /* 0x001C */ s32 baseRomOffset;
    /* 0x0020 */ SBNFileEntry* sbnFileList;
    /* 0x0024 */ s32 fileListLength;
    /* 0x0028 */ char unk_28[0x4];
    /* 0x002C */ InitSongEntry* songList;
    /* 0x0030 */ s32 songListLength;
    /* 0x0034 */ s32 bkFileListOffset;
    /* 0x0038 */ s32 bkListLength;
    /* 0x003C */ u16* mseqFileList;
    /* 0x0040 */ AuEffectChange effectChanges[4];
    /* 0x0050 */ u8 channelDelayPending;
    /* 0x0051 */ u8 channelDelayBusId;
    /* 0x0052 */ u8 channelDelayTime;
    /* 0x0053 */ u8 channelDelaySide;
    /* 0x0054 */ PEREntry* dataPER;
    /* 0x0058 */ BGMInstrumentInfo* dataPRG;
    /* 0x005C */ struct BGMHeader* dataBGM[2];
    /* 0x0064 */ struct MSEQHeader* dataMSEQ[2];
    /* 0x006C */ SndGlobalsSub6C unk_globals_6C[1];
    /* 0x0074 */ struct BGMPlayer* unk_74;
    /* 0x0078 */ struct BGMPlayer* unk_78;
    /* 0x007C */ s32 unkSongName;
    /* 0x0080 */ s32 unk_80;
    /* 0x0084 */ s32 unkFadeTime;
    /* 0x0088 */ s32 unkFadeStart;
    /* 0x008C */ s32 unkFadeEnd;
    /* 0x0090 */ MusicEventTrigger* musicEventQueuePos;
    /* 0x0094 */ MusicEventTrigger* musicEventQueue;
    /* 0x0098 */ u32 musicEventQueueCount;
    /* 0x009C */ s32 flushMusicEventQueue;
    /* 0x00A0 */ SEFHeader* dataSEF;
    /* 0x00A4 */ AuCallback audioThreadCallbacks[2]; // 0 = on begin update, 1 = unimplemented
    /* 0x00AC */ InstrumentGroup instrumentGroupX[1];
    /* 0x00EC */ InstrumentGroup instrumentGroup3[16];
    /* 0x04EC */ InstrumentGroup instrumentGroup1[4];
    /* 0x05EC */ InstrumentGroup instrumentGroup2[16];
    /* 0x09EC */ InstrumentGroup instrumentGroup4[16];
    /* 0x0DEC */ InstrumentGroup instrumentGroup5[16];
    /* 0x11EC */ InstrumentGroup instrumentGroup6[4];
    /* 0x12EC */ InstrumentGroup* instrumentGroups[8];
    /* 0x130C */ u8 unk_130C;
    /* 0x130D */ char unk_130D[3];
    /* 0x1310 */ SoundBank* banks[3];
    /* 0x131C */ char unk_131C[4];
    /* 0x1320 */ AuVoice voices[24];
} AuGlobals; // size = 0x19E0

typedef struct BGMPlayerTrack {
    /* 0x00 */ AuFilePos bgmReadPos;
    /* 0x04 */ AuFilePos savedPos;
    /* 0x08 */ AuFilePos prevReadPos;
    /* 0x0C */ Instrument* instrument;
    /* 0x10 */ EnvelopeData envelope;
    /* 0x18 */ s32 subTrackVolume;
    /* 0x1C */ s32 subTrackVolumeStep;
    /* 0x20 */ s32 subTrackVolumeTarget;
    /* 0x24 */ s32 subTrackVolumeTime;
    /* 0x28 */ s32 delayTime;
    //TODO Fade struct?
    /* 0x2C */ s32 unkVolume;
    /* 0x30 */ s32 unkVolumeStep;
    /* 0x34 */ s16 unkVolumeTarget;
    /* 0x36 */ s16 unkVolumeTime;
    /* 0x38 */ s16 segTrackTune;
    /* 0x3A */ s16 trackTremoloAmount;
    /* 0x3C */ char unk_3C[0x2];
    /* 0x3E */ s16 detourLength;
    /* 0x40 */ SoundPlayChange changed;
    /* 0x44 */ u16 patch;
    /* 0x46 */ u16 subTrackCoarseTune;
    /* 0x48 */ s8 subTrackFineTune;
    /* 0x49 */ s8 segTrackVolume;
    /* 0x4A */ u8 subTrackPan;
    /* 0x4B */ u8 subTrackReverb;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ u8 unk_4E;
    /* 0x4F */ u8 unk_4F;
    /* 0x50 */ u8 unk_50;
    /* 0x51 */ u8 unk_51;
    /* 0x52 */ u8 unk_52; // voice idx start
    /* 0x53 */ u8 unk_53; // voice idx end
    /* 0x54 */ u8 polyphonicIdx;
    /* 0x55 */ u8 trackTremoloSpeed;
    /* 0x56 */ u8 trackTremoloTime;
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ u8 isDrumTrack;
    /* 0x59 */ u8 parentTrackIdx;
    /* 0x5A */ u8 unk_5A;
    /* 0x5B */ s8 subtrackBusId;
    /* 0x5C */ u8 index;
    /* 0x5D */ char unk_5D[0x3];
} BGMPlayerTrack; // size = 0x60;

typedef struct SeqNote {
    /* 0x00 */ Instrument* ins;
    /* 0x00 */ f32 pitchRatio;
    /* 0x08 */ s16 volume;
    /* 0x0A */ s16 adjustedPitch;
    /* 0x0C */ s32 noteLength;
    /* 0x10 */ u16 tremoloAmount;
    /* 0x12 */ u8 tremoloTime;
    /* 0x12 */ u8 unk_13;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u8 noteVelocity;
    /* 0x17 */ u8 unk_note_17;
} SeqNote; // size = 0x18;

typedef struct BGMPlayer {
    /* 0x000 */ AuGlobals* globals;
    /* 0x004 */ SoundManager* soundManager;
    /* 0x008 */ s32 nextUpdateStep;
    /* 0x00C */ s32 nextUpdateInterval;
    /* 0x010 */ s32 nextUpdateCounter;
    /* 0x014 */ s32 updateCounter;
    /* 0x018 */ s32 songPlayingCounter;
    /* 0x01C */ s32 songName;
    /* 0x020 */ s32 fadeSongName;
    /* 0x024 */ s32 bgmFileIndex;
    /* 0x028 */ s32 songID;
    /* 0x02C */ Fade fadeInfo;
    /* 0x048 */ s32 busVolume;
    /* 0x04C */ u8 effectIndices[4];
    /* 0x050 */ s32 randomValue1;
    /* 0x054 */ s32 randomValue2;
    /* 0x058 */ u16 unk_58;
    /* 0x05A */ s16 unk_5A;
    /* 0x05C */ s16 unk_5C;
    /* 0x05E */ char pad5E[2];
    /* 0x060 */ u32 curSegmentID;
    /* 0x064 */ struct BGMHeader* bgmFile;
    /* 0x068 */ SegData* segmentReadPos;
    /* 0x06C */ SegData* segmentStartPos;
    /* 0x070 */ SegData* subSegmentStartPos;
    /* 0x074 */ s32 unk_74;
    /* 0x078 */ BGMDrumInfo* drumsInfo;
    /* 0x07C */ BGMInstrumentInfo* instrumentsInfo;
    /* 0x080 */ BGMDrumInfo* drums[12];
    /* 0x0B0 */ s32 masterTempo;
    /* 0x0B4 */ s32 masterTempoStep;
    /* 0x0B8 */ s32 masterTempoTarget;
    /* 0x0BC */ s32 masterTempoTime;
    /* 0x0C0 */ s32 masterVolume;
    /* 0x0C4 */ s32 masterVolumeStep;
    /* 0x0C8 */ s32 masterVolumeTarget;
    /* 0x0CC */ s32 masterVolumeTime;
    /* 0x0D0 */ f32 playbackRate;
    /* 0x0D4 */ SeqArgs seqCmdArgs;
    /* 0x0D8 */ SegData* segLoopStartLabels[32];
    /* 0x158 */ SegData* segActiveLoopEndPos[4];
    /* 0x168 */ u8 segLoopCounters[4];
    /* 0x16C */ s32 proxMixValue;
    /* 0x170 */ u8 proxMixID;
    /* 0x171 */ u8 proxMixVolume;
    /* 0x172 */ char unk_172[0x2];
    /* 0x174 */ s16 unk_174[8][9];
    /* 0x204 */ u8* trackVolsConfig;
    /* 0x208 */ u16 masterTempoBPM;
    /* 0x20A */ u16 maxTempo;
    /* 0x20C */ u16 masterPitchShift;
    /* 0x20E */ s16 detune;
    /* 0x210 */ u8 segLoopDepth;
    /* 0x211 */ u8 unk_211;
    /* 0x212 */ u8 unk_212[8];
    /* 0x21A */ s8 volumeChanged;
    /* 0x21B */ u8 unk_21B;
    /* 0x21C */ u8 bgmDrumCount;
    /* 0x21D */ u8 bgmInstrumentCount;
    /* 0x21E */ u8 unk_21E;
    /* 0x21F */ char unk_21F[0x1];
    /* 0x220 */ u8 unk_220;
    /* 0x221 */ u8 masterState;
    /* 0x222 */ u8 unk_222;
    /* 0x223 */ u8 unk_223;
    /* 0x224 */ u8 effectValues[4];
    /* 0x227 */ char unk_228[0x2];
    /* 0x22A */ u8 unk_22A[8];
    /* 0x232 */ u8 bFadeConfigSetsVolume;
    /* 0x233 */ u8 unk_233;
    /* 0x234 */ u8 priority;
    /* 0x235 */ u8 busId;
    /* 0x236 */ char unk_236[0x2];
    /* 0x238 */ s32 unk_238[8];
    /* 0x258 */ u8 unk_258;
    /* 0x259 */ u8 unk_259;
    /* 0x25A */ u8 unk_25A;
    /* 0x25B */ u8 unk_25B;
    /* 0x25C */ BGMPlayerTrack tracks[16];
    /* 0x85C */ SeqNote notes[24];
} BGMPlayer; // size = 0xA9C

typedef struct MSEQTrackData {
    /* 0x0 */ u8 trackIndex;
    /* 0x1 */ u8 type;
    /* 0x2 */ s16 time;
    /* 0x4 */ s16 delta;
    /* 0x6 */ u16 goal;
} MSEQTrackData; // size = 0x8

typedef struct MSEQHeader {
    /* 0x00 */ s32 signature; // 'MSEQ '
    /* 0x04 */ s32 size; // including header
    /* 0x08 */ s32 name;
    /* 0x0C */ u8 firstVoiceIdx;
    /* 0x0D */ u8 trackSettingsCount;
    /* 0x0E */ u16 trackSettingsOffset;
    /* 0x10 */ u16 dataStart;
} MSEQHeader; // size variable

typedef struct AmbienceTrack {
    /* 0x00 */ Instrument* instrument;
    /* 0x04 */ EnvelopeData envelope;
    /* 0x0C */ SoundLerp tuneLerp;
    /* 0x18 */ SoundLerp volumeLerp;
    /* 0x24 */ s8 pan;
    /* 0x25 */ s8 reverb;
    /* 0x26 */ u8 flags;
    /* 0x27 */ char unk_27[1];
} AmbienceTrack; // size = 0x28

typedef struct AmbienceSavedVoice {
    /* 0x0 */ u8 trackIndex;
    /* 0x1 */ u8 tune;
    /* 0x2 */ s8 volume;
    /* 0x4 */ char unk_03[1];
} AmbienceSavedVoice; // size = 0x4

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
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 mseqName;
    /* 0x024 */ u8 mode;
    /* 0x025 */ u8 playState;
    /* 0x026 */ u8 fadeSettingsType;
    /* 0x027 */ char unk_27[1];
    /* 0x028 */ u16 fadeSettingsTime;
    /* 0x02A */ u8 fadeSettingsInitial; // 255 means from current volume
    /* 0x02B */ u8 fadeSettingsGoal;
    /* 0x02C */ u8 loopCount[2];
    /* 0x02E */ char unk_2E[2];
    /* 0x030 */ u32 firstVoiceIdx;
    /* 0x034 */ u32 lastVoiceIdx;
    /* 0x038 */ s32 fadeVolume;
    /* 0x03C */ s32 fadeStep;
    /* 0x040 */ u16 fadeTime;
    /* 0x042 */ u8 fadeGoal;
    /* 0x043 */ u8 resetRequired;
    /* 0x044 */ AmbienceTrack tracks[10];
    /* 0x1D4 */ AmbienceSavedVoice savedVoices[4];
} AmbiencePlayer; // size = 0x1E4

//TODO AuStreamingManager ?
// 801D57A0
typedef struct AmbienceManager {
    /* 0x000 */ AuGlobals* globals;
    /* 0x004 */ s32 nextUpdateStep;
    /* 0x008 */ s32 nextUpdateInterval;
    /* 0x00C */ s32 nextUpdateCounter;
    /* 0x010 */ MSEQHeader* mseqFiles[4];
    /* 0x020 */ u8 numActivePlayers;
    /* 0x021 */ u8 loadTracksFadeInfo;
    /* 0x022 */ u8 priority;
    /* 0x023 */ u8 busId;
    /* 0x024 */ AmbiencePlayer players[4];
    /* 0x7B4 */ AmbienceVoiceState voiceStates[16];
} AmbienceManager;

typedef struct AlUnkGemini {
    /* 0x00 */ u16 sound1;
    /* 0x02 */ u16 sound2;
    /* 0x04 */ u8 flags;
} AlUnkGemini; // size = 0x5

typedef struct ALConfig {
    /* 0x00 */ s32 num_pvoice;
    /* 0x04 */ s32 num_bus;
    /* 0x08 */ s32 outputRate;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ char unk_0D[3];
    /* 0x10 */ void* dmaNew;
    /* 0x14 */ ALHeap* heap;
} ALConfig; // size = 0x18;

#ifndef NO_EXTERN_VARIABLES

extern volatile u8 AuSynUseStereo;
extern u16 DummyInstrumentPredictor[32];
extern u8 DummyInstrumentBase[190];
extern s32 CUSTOM_SMALL_ROOM_PARAMS[];
extern s32 CUSTOM_ECHO_PARAMS_1[];
extern s32 CUSTOM_ECHO_PARAMS_3[];
extern s32 CUSTOM_ECHO_PARAMS_2[];
extern EnvelopePreset DummyInstrumentEnvelope;
extern u8 AmbientSoundIDtoMSEQFileIndex[];
extern s32 AuEnvelopeIntervals[];
extern s32 PreventBGMPlayerUpdate;
extern u16 AuAmbiencePlayOnlyIndex;

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
