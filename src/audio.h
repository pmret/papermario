#ifndef _AUDIO_H_
#define _AUDIO_H_
#include "nu/nusys.h"
#include "nu/nualsgi.h"
#include "common.h"

// temporary to keep track of unk portions of alUnk structs (not just unk fields)
typedef s8  UNK_TYPE_08;
typedef s16 UNK_TYPE_16;
typedef s32 UNK_TYPE_32;
typedef void* UNK_TYPE_PTR;

#define SAMPLES               184
#define SAMPLE184(delta)      (((delta) + (SAMPLES / 2)) / SAMPLES) * SAMPLES
#define FIXED_SAMPLE          SAMPLES

#define N_AL_DECODER_IN	        0
#define	N_AL_RESAMPLER_OUT	0
#define N_AL_TEMP_0	        0
#define	N_AL_DECODER_OUT        368
#define	N_AL_TEMP_1	        368
#define	N_AL_TEMP_2	        736
#define	N_AL_MAIN_L_OUT	        1248
#define	N_AL_MAIN_R_OUT	        1616
#define	N_AL_AUX_L_OUT	        1984
#define	N_AL_AUX_R_OUT	        2352

#define ALIGN16_(val) (((val) + 0xF) & 0xFFF0)

#define AUDIO_HEAP_SIZE 0x56000
 // NU_AU_AUDIO_SAMPLES ?
#define	AUDIO_SAMPLES	184
#define AUDIO_COMMAND_LIST_BUFFER_SIZE 0x4000

#define SND_MAX_VOLUME_8  0x7F // 127
#define SND_MAX_VOLUME_16 0x7FFF

#define BGM_SAMPLE_RATE 156250
#define BGM_DEFAULT_TEMPO 15600

#define SND_MIN_DURATION 250
#define SND_MAX_DURATION 10000

#define BGM_MAX_VOLUME 127

#define BGM_SEGMENT_LABEL 3

typedef u32 SegData;

typedef enum BGMPlayerState {
    BGM_PLAY_STATE_0                = 0,    // INITIALIZED
    BGM_PLAY_STATE_1                = 1,    // PLAYING
    BGM_PLAY_STATE_2                = 2,    // BGM LOADED (blocks)
    BGM_PLAY_STATE_3                = 3,    // ???
    BGM_PLAY_STATE_4                = 4,    // DONE? (blocks)
} BGMPlayerState;

typedef enum SegmentControlCommands {
    BGM_SEGMENT_END                 = 0,
    BGM_SEGMENT_SUBSEG              = 1,
    BGM_SEGMENT_START_LOOP          = 3,
    BGM_SEGMENT_HALT                = 4,
    BGM_SEGMENT_END_LOOP            = 5,
    BGM_SEGMENT_6                   = 6,
    BGM_SEGMENT_7                   = 7
} SegmentControlCommands;

typedef union Q32 {
    u8 u8[4];
    u16 u16[2];
    s32 s32;
} Q32;

typedef union Vol32 {
    s32 full;
    s16 half;
    s8 byte;
} Vol32;

struct BGMPlayer;
struct SndGlobals;
struct AlUnkVoice;

typedef void (*UnkFuncAl)(void);

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
        u8 bank;
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
        u32 unk_00;
    } UnkCmdFD;
    struct { // cmd FE
        u16 offset;
        u8 unk_02;
    } UnkCmdFE;
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

typedef struct Fade {
    /* 0x0 */ VolumeField currentVolume;
    /* 0x4 */ s32 fadeStep;
    /* 0x8 */ s16 targetVolume;
    /* 0xA */ s16 fadeTime;
    /* 0xC */ UnkFuncAl onCompleteCallback;
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
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ char pad_0E[2];
    /* 0x10 */ f32 rsinc;
    /* 0x14 */ f32 rsval;
    /* 0x18 */ s32 rsdelta;
    /* 0x1C */ f32 rsgain;
    /* 0x20 */ struct AuLowPass* lowpass_20; // [ALLowPass] ?
    /* 0x24 */ struct AuLowPass* lowpass_24; // [ALLowPass] ?
    /* 0x28 */ struct AlUnkChi* unk_chi_28; // [ALResampler] ?
    /* 0x2C */ struct AuResampler* unk_psi_2C; // [ALResampler] ?
} AuDelay; // size = 0x30

// based on ALFx
typedef struct AuFX {
    /* 0x00 */ s16* base;
    /* 0x04 */ s16* input;
    /* 0x08 */ s32 length;
    /* 0x0C */ AuDelay* delays;
    /* 0x10 */ u8 delayCount;
} AuFX; // size = 0x14

// POLEF_STATE
typedef struct AlUnkChi {
    /* 0x00 */ UNK_TYPE_32 unk__00;
    /* 0x04 */ UNK_TYPE_32 unk__04;
} AlUnkChi; // size = 0x8

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
    /* 0x0C */ AuLowPass* unk_phi_0C;
    /* 0x10 */ AuLowPass* unk_phi_10;
} AlUnkKappa; // size unk

typedef struct AlUnkGamma {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ AuFX* fxL;
    /* 0x08 */ AuFX* fxR;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ char unk_0D[0x3];
    /* 0x10 */ struct AuPVoice* unk_beta_10;
    /* 0x14 */ struct AuPVoice* unk_beta_14;
} AlUnkGamma; // size = 0x18

// [ALLoadFilter]
typedef struct AuLoadFilter {
    /* 0x04 */ ADPCM_STATE* dc_state;
    /* 0x08 */ ADPCM_STATE* dc_lstate;
    /* 0x0C */ ALRawLoop dc_loop;
    /* 0x18 */ struct Instrument* dc_table;
    /* 0x1C */ s32 dc_bookSize;
    /* 0x20 */ s32 (*dc_dmaFunc)(s32 addr, s32 len, void* state, u8 unk); // ALDMAproc with extra arg
    /* 0x24 */ NUDMAState* dc_dmaState;
    /* 0x28 */ s32 dc_sample;
    /* 0x2C */ s32 dc_lastsam;
    /* 0x30 */ s32 dc_first;
    /* 0x34 */ s32 dc_memin;
} AuLoadFilter;

// [ALResampler]
typedef struct AuResampler {
    /* 0x38 */ RESAMPLE_STATE* rs_state;
    /* 0x3C */ f32 rs_ratio;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
} AuResampler;

// envelope mixer -- based on ALEnvMixer
typedef struct AuEnvMixer {
    /* 0x38 */ ENVMIX_STATE* em_state;
    /* 0x4C */ s16 em_pan;
    /* 0x4E */ s16 em_volume;
    /* 0x50 */ s16 em_cvolL;
    /* 0x52 */ s16 em_cvolR;
    /* 0x54 */ s16 em_dryamt;
    /* 0x56 */ s16 em_wetamt;
    /* 0x58 */ s16 em_lratl;
    /* 0x5A */ s16 em_lratm;
    /* 0x5C */ s16 em_ltgt;
    /* 0x5E */ s16 em_rratl;
    /* 0x60 */ s16 em_rratm;
    /* 0x62 */ s16 em_rtgt;
    /* 0x64 */ s32 em_delta;
    /* 0x68 */ s32 em_segEnd;
    /* 0x6C */ s32 em_first;
    /* 0x70 */ s32 em_motion;
} AuEnvMixer; // size = 0x74

// [N_PVoice]
typedef struct AuPVoice {
    /* 0x00 */ struct AuPVoice* next;
    /* 0x04 */ AuLoadFilter loadFilter;
    /* 0x38 */ AuResampler resampler;
    /* 0x48 */ AuEnvMixer envMixer;
    /* 0x74 */ s16 unk_74;
    /* 0x76 */ s16 unk_76;
    /* 0x78 */ u8 unk_78;
    /* 0x79 */ u8 unk_79;
    /* 0x7A */ u8 unk_7A[2];
} AuPVoice;

// [N_ALSynth]
typedef struct AuSynDriver {
    /* 0x00 */ s32 curSamples;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 outputRate;
    /* 0x0C */ s32 num_pvoice;
    /* 0x10 */ s32 unk_num_gamma;
    /* 0x14 */ void* dmaNew; // pointer to nuAuDmaNew
    /* 0x18 */ ALHeap* heap;
    /* 0x1C */ AuPVoice* pvoices;
    /* 0x20 */ AlUnkGamma* al_unk_gamma;
    /* 0x24 */ s32* unk_drvr_24; // struct size = 0x170
    /* 0x28 */ s32* unk_drvr_28; // struct size = 0x170
} AuSynDriver;

typedef struct SoundSFXEntry {
    /* 0x0 */ u16 soundID;
    /* 0x2 */ s16 upperSoundID;
    /* 0x4 */ s16 volume;
    /* 0x6 */ s16 pitchShift;
    /* 0x8 */ s8 pan;
    /* 0x9 */ char unk_9[0x1];
} SoundSFXEntry; // size = 0xA

typedef struct InstrumentEffectSub {
    /* 0x00 */ u16 unkOffset1;
    /* 0x02 */ u16 unkOffset2;
} InstrumentEffectSub; // size = 0x4;

typedef struct InstrumentEffect {
    /* 0x00 */ u8 count;
    /* 0x01 */ char unk_01[3];
    /* 0x04 */ InstrumentEffectSub unk_04[1]; // variable size
} InstrumentEffect;

typedef struct Instrument {
    /* 0x00 */ UNK_PTR base;
    /* 0x04 */ u32 wavDataLength;
    /* 0x08 */ s32 loopPredictorOffset;
    /* 0x0C */ s32 loopStart;
    /* 0x10 */ s32 loopEnd;
    /* 0x14 */ s32 loopCount;
    /* 0x18 */ UNK_PTR predictorOffset;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 detune;
    /* 0x20 */ f32 pitchRatio;
    /* 0x24 */ u8 type;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ s8 unk_26;
    /* 0x27 */ s8 unk_27;
    /* 0x28 */ s8 unk_28;
    /* 0x29 */ s8 unk_29;
    /* 0x2A */ s8 unk_2A;
    /* 0x2B */ s8 unk_2B;
    /* 0x2C */ InstrumentEffect* unkOffset;
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
    /* 0x00 */ s8* sefDataReadPos;
    /* 0x04 */ char pad4[0xC];
    /* 0x10 */ s8* unk10;
    /* 0x14 */ s8* unk14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ Instrument* sfxInstrumentRef;
    /* 0x20 */ Instrument sfxInstrument;
    /* 0x50 */ s8* sefReadStart;
    /* 0x54 */ SoundPlayChange changed;
    /* 0x58 */ f32 actualSampleRate;
    /* 0x5C */ s16 sfxVolume;
    /* 0x5E */ s16 unk_5E;
    /* 0x60 */ SoundLerp tuneLerp;
    /* 0x6C */ SoundLerp volumeLerp;
    /* 0x78 */ u8 locatorB;
    /* 0x79 */ u8 locatorC;
    /* 0x7A */ u8 locatorD;
    /* 0x7B */ u8 unk_7B;
    /* 0x7C */ u8 unk_7C;
    /* 0x7D */ u8 unk_7D;
    /* 0x7E */ u8 unk_7E;
    /* 0x7F */ u8 unk_7F;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s8 unk_84;
    /* 0x85 */ u8 soundC00;
    /* 0x86 */ char unk_86[0x2];
    /* 0x88 */ s8* loopStartPos;
    /* 0x8C */ s8 loopIterCount;
    /* 0x8D */ char unk_8D;
    /* 0x8E */ u16 unk_8E;
    /* 0x90 */ u16 unk_90;
    /* 0x92 */ s16 unk_92;
    /* 0x94 */ s8 unk_94;
    /* 0x95 */ char unk_05;
    /* 0x96 */ u16 currentSoundID;
    /* 0x98 */ u8 unk_98;
    /* 0x99 */ u8 unk_99;
    /* 0x9A */ u8 sfxParamsFlags;
    /* 0x9B */ u8 sfxPan;
    /* 0x9C */ u8 reverb;
    /* 0x9D */ u8 instrumentIndex; // ?
    /* 0x9E */ u8 unk_9E;
    /* 0x9F */ u8 unk_9F;
    /* 0xA0 */ u8 unk_A0;
    /* 0xA1 */ u8 unk_A1;
    /* 0xA2 */ u8 unk_A2;
    /* 0xA3 */ s8 unk_A3;
    /* 0xA4 */ s16 masterPitchShift;
    /* 0xA6 */ s16 masterVolume;
    /* 0xA8 */ u8 masterPan;
    /* 0xA8 */ u8 unk_A9;
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

typedef struct SoundManagerA0 {
    /* 0x0 */ u16 unk_00;
    /* 0x2 */ u16 unk_02;
    /* 0x4 */ u16 unk_04;
} SoundManagerA0; // size = 6

typedef struct SoundManager {
    /* 0x000 */ struct SndGlobals* soundData;
    /* 0x004 */ struct AlUnkVoice* currentVoice;
    /* 0x008 */ s32* sefData;
    /* 0x00C */ s32* normalSounds[8];
    /* 0x02C */ s32* soundsWithBit2000;
    /* 0x030 */ s32 playCounter; //?
    /* 0x034 */ s32 nextUpdateStep;
    /* 0x038 */ s32 nextUpdateInterval;
    /* 0x03C */ s32 nextUpdateCounter;
    /* 0x040 */ struct Fade unk_40;
    /* 0x05C */ s32 unk_5C;
    /* 0x060 */ s32 unk_60;
    /* 0x064 */ s32* unk_64[8];
    /* 0x084 */ s8 unk_84[8];
    /* 0x08C */ u8 unk_8C;
    /* 0x08D */ s8 unk_8D;
    /* 0x08E */ char unk_8E[0x2];
    /* 0x090 */ SoundManager90 unk_90[4];
    /* 0x0A0 */ SoundManagerA0 unk_A0[4];
    /* 0x0B8 */ u16 unk_B8;
    /* 0x0BA */ s16 unk_BA;
    /* 0x0BC */ u8 unk_BC;
    /* 0x0BD */ u8 sfxPlayerSelector;
    /* 0x0BE */ u8 unk_BE;
    /* 0x0BF */ u8 unk_BF;
    /* 0x0C0 */ u8 unk_C0;
    /* 0x0C1 */ char unk_C1[0x1];
    /* 0x0C2 */ SoundSFXEntry soundQueue[16];
    /* 0x162 */ s8 unk_162;
    /* 0x163 */ u8 sfxQueuePosOffset;
    /* 0x164 */ u8 sfxQueueNextPos;
    /* 0x165 */ s8 unk_165;
    /* 0x166 */ char unk_166[0x2];
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ SoundPlayer unk_16C[8];
} SoundManager; // size = 0x6CC

typedef struct AlUnkVoice {
    /* 0x00 */ Instrument* instrument;
    /* 0x04 */ f32 pitchRatio;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 pan;
    /* 0x0F */ u8 reverb;
    /* 0x10 */ u8 reverbType;
    /* 0x11 */ char unk_11[0x3];
    /* 0x14 */ s32* unk_14; // ultimately from bgm_player->unk_10 ?
    /* 0x18 */ s32* unk_18; // ultimately from bgm_player->unk_14 ? u8* ?
    /* 0x1C */ u8* unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u8* unk_34;
    /* 0x38 */ u8 unk_38;
    /* 0x39 */ u8 unk_39;
    /* 0x3A */ u8 unk_3A;
    /* 0x3B */ u8 unk_3B;
    /* 0x3C */ u8 unk_3C;
    /* 0x3D */ u8 unk_3D;
    /* 0x3E */ u8 unk_3E;
    /* 0x3F */ u8 unk_3F;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ u8 unk_42;
    /* 0x43 */ u8 unk_flags_43;
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ u8 unk_45;
    /* 0x46 */ char unk_46[2];
} AlUnkVoice; // size = 0x48

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
    /* 0x2 */ s16 unk_02;
    /* 0x4 */ u8 unk_04;
    /* 0x5 */ s8 unk_05;
    /* 0x6 */ s8 unk_06;
    /* 0x7 */ u8 unk_07;
    /* 0x8 */ u8 unk_08;
    /* 0x9 */ u8 unk_09;
    /* 0xA */ u8 unk_0A;
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

typedef struct SBNHeader {
    /* 0x00 */ s32 signature; // 'SBN '
    /* 0x04 */ s32 size;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 tableOffset; // = 0x40
    /* 0x14 */ s32 numEntries;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 INIToffset;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
} SBNHeader; // size = 0x40

typedef struct SEFHeader {
    /* 0x00 */ s32 signature; // 'SEF '
    /* 0x04 */ s32 size;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s8 unkC; // 0
    /* 0x0D */ s8 unkD; // 0
    /* 0x0E */ u8 hasExtraSection; // 1
    /* 0x0F */ s8 unkF; // 0
    /* 0x10 */ u16 sections[8];
    /* 0x14 */ u16 section2000;
} SEFHeader; // size = 0x16

typedef struct INITHeader {
    /* 0x00 */ s32 signature; // 'INIT'
    /* 0x04 */ s32 size;
    /* 0x08 */ u16 entriesOffset;
    /* 0x0A */ u16 entriesSize;
    /* 0x0C */ u16 tblOffset;
    /* 0x0E */ u16 tblSize;
    /* 0x10 */ u16 shortsOffset;
    /* 0x12 */ u16 shortsSize;
    /* 0x14 */ char unk_14[0xC];
} INITHeader; // size = 0x20

typedef struct PERHeader {
    /* 0x00 */ s32 signature; // 'PER ' or 'PRG '
    /* 0x04 */ s32 size; // including this header
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

typedef struct SndGlobalsSub40 {
    /* 0x0 */ u8 unk_00;
    /* 0x1 */ u8 unk_01;
    /* 0x2 */ char unk_02[2];
} SndGlobalsSub40;

typedef struct SndGlobalsSub6C {
    /* 0x00 */ struct BGMPlayer* bgmPlayer;
    /* 0x04 */ u8 unk_4;
    /* 0x05 */ u8 unk_5;
} SndGlobalsSub6C;

typedef struct SndGlobals {
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
    /* 0x0040 */ SndGlobalsSub40 unk_globals_40[4];
    /* 0x0050 */ u8 unk_50;
    /* 0x0051 */ u8 unk_51;
    /* 0x0052 */ u8 unk_52;
    /* 0x0053 */ u8 unk_53;
    /* 0x0054 */ PEREntry* dataPER;
    /* 0x0058 */ BGMInstrumentInfo* dataPRG;
    /* 0x005C */ s32* currentTrackData[4];
    /* 0x006C */ SndGlobalsSub6C unk_globals_6C[1];
    /* 0x0074 */ struct BGMPlayer* unk_74;
    /* 0x0078 */ struct BGMPlayer* unk_78;
    /* 0x007C */ s32 unkSongName;
    /* 0x0080 */ s32 unk_80;
    /* 0x0084 */ s32 unkFadeTime;
    /* 0x0088 */ s32 unkFadeStart;
    /* 0x008C */ s32 unkFadeEnd;
    /* 0x0090 */ s32* unk_90;
    /* 0x0094 */ s32* unk_arr_94; // contains 16 * 4 bytes
    /* 0x0098 */ u32 unk_98;
    /* 0x009C */ s32 unk_9C;
    /* 0x00A0 */ SEFHeader* dataSEF;
    /* 0x00A4 */ UnkFuncAl unk_A4[2];
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
    /* 0x1320 */ AlUnkVoice voices[24];
} SndGlobals; // size = 0x19E0

typedef struct BGMPlayerTrack {
    /* 0x00 */ u8* bgmReadPos;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ u8* prevReadPos; //? see snd_BGMCmd_FC_Jump
    /* 0x0C */ Instrument* instrument;
    /* 0x10 */ s32* unk_10[2];
    /* 0x18 */ s32 subTrackVolume;
    /* 0x1C */ s32 subTrackVolumeFadeDelta;
    /* 0x20 */ s32 subTrackVolumeFadeVolume;
    /* 0x24 */ s32 subTrackVolumeFadeTime;
    /* 0x28 */ s32 delayTime;
    //TODO Fade struct?
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ s16 unk36;
    /* 0x38 */ s16 segTrackTune;
    /* 0x3A */ s16 trackTremoloAmount;
    /* 0x3C */ char unk_3C[0x2];
    /* 0x3E */ s16 unk_3E;
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
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ u8 trackTremoloSpeed;
    /* 0x56 */ u8 trackTremoloTime;
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ u8 isDrumTrack;
    /* 0x59 */ u8 unk_59;
    /* 0x5A */ u8 unk_5A;
    /* 0x5B */ s8 subtrackReverbType;
    /* 0x5C */ u8 unk_5C;
    /* 0x5D */ char unk_5D[0x3];
} BGMPlayerTrack; // size = 0x60;

typedef struct SeqNote {
    /* 0x00 */ Instrument* ins;
    /* 0x00 */ f32 pitchRatio;
    /* 0x08 */ s16 unk_08;
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
    /* 0x000 */ SndGlobals* globals;
    /* 0x004 */ SoundManager* soundManager;
    /* 0x008 */ s32 unkFrequency; //?
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ s32 unk_14;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 songName;
    /* 0x020 */ s32 fadeSongName;
    /* 0x024 */ s32 bgmFileIndex;
    /* 0x028 */ s32 songID;
    /* 0x02C */ Fade fadeInfo;
    /* 0x048 */ s32 unk_48;
    /* 0x04C */ u8 effectIndices[4];
    /* 0x050 */ s32 unk_50;
    /* 0x054 */ s32 unk_54;
    /* 0x058 */ u16 unk_58;
    /* 0x05A */ s16 unk_5A;
    /* 0x05C */ s16 unk_5C;
    /* 0x05E */ char pad5E[2];
    /* 0x060 */ u32 curSegmentID;
    /* 0x064 */ struct BGMHeader* bgmFile;
    /* 0x068 */ SegData* segmentReadPos;
    /* 0x06C */ SegData* segmentStartPos;
    /* 0x070 */ s32 unk_70;
    /* 0x074 */ s32 unk_74;
    /* 0x078 */ BGMDrumInfo* drumsInfo;
    /* 0x07C */ BGMInstrumentInfo* instrumentsInfo;
    /* 0x080 */ BGMDrumInfo* drums[12];
    /* 0x0B0 */ s32 masterTempo;
    /* 0x0B4 */ s32 masterTempoFadeDelta;
    /* 0x0B8 */ s32 masterTempoFadeTempo;
    /* 0x0BC */ s32 masterTempoFadeTime;
    /* 0x0C0 */ s32 masterVolume;
    /* 0x0C4 */ s32 masterVolumeFadeDelta;
    /* 0x0C8 */ s32 masterVolumeFadeVolume;
    /* 0x0CC */ s32 masterVolumeFadeTime;
    /* 0x0D0 */ f32 unk_D0;
    /* 0x0D4 */ SeqArgs seqCmdArgs;
    /* 0x0D8 */ SegData* segLoopStartLabels[32];
    /* 0x158 */ SegData* segActiveLoopEndPos[4];
    /* 0x168 */ Q32 unk_168; // might be u8 loopCounters[4]?
    /* 0x16C */ s32 proxMixValue;
    /* 0x170 */ u8 proxMixID;
    /* 0x171 */ u8 proxMixVolume;
    /* 0x172 */ char unk_172[0x2];
    /* 0x174 */ s16 unk_174[8][9];
    /* 0x204 */ u8* unk_204;
    /* 0x208 */ u16 masterTempoBPM;
    /* 0x20A */ u16 maxTempo;
    /* 0x20C */ u16 masterPitchShift;
    /* 0x20E */ s16 unk_20E;
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
    /* 0x22A */ u8 unk_22A;
    /* 0x22B */ u8 unk_22B;
    /* 0x22C */ u8 unk_22C;
    /* 0x22D */ u8 unk_22D;
    /* 0x22E */ u8 unk_22E;
    /* 0x22F */ u8 unk_22F;
    /* 0x230 */ u8 unk_230;
    /* 0x231 */ u8 unk_231;
    /* 0x232 */ u8 unk_232;
    /* 0x233 */ u8 unk_233;
    /* 0x234 */ u8 unk_234;
    /* 0x235 */ u8 defaultReverbType;
    /* 0x236 */ char unk_236[0x2];
    /* 0x238 */ s32 unk_238[8];
    /* 0x258 */ u8 unk_258;
    /* 0x259 */ u8 unk_259;
    /* 0x25A */ u8 unk_25A;
    /* 0x25B */ u8 unk_25B;
    /* 0x25C */ BGMPlayerTrack tracks[16];
    /* 0x85C */ SeqNote notes[24];
} BGMPlayer; // size = 0xA9C

typedef struct AlUnkIota {
    /* 0x00 */ Q32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ u8 unk_07;
} AlUnkIota; // size = 0x8

typedef struct AlUnkMSEQData {
    u8 unk_00;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    u16 unk_06;
} AlUnkMSEQData;

typedef struct MSEQHeader {
    /* 0x00 */ s32 signature; // 'MSEQ '
    /* 0x04 */ s32 size; // including header
    /* 0x08 */ s32 name;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unkCount;
    /* 0x0E */ u16 unkOffset;
    /* 0x10 */ u16 dataStart;
} MSEQHeader; // size variable

typedef struct AlUnkXi {
    /* 0x00 */ Instrument* instrument;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ Vol32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s8 pan;
    /* 0x25 */ s8 reverb;
    /* 0x26 */ u8 flags;
    /* 0x27 */ char unk_26[1];
} AlUnkXi; // size = 0x28

typedef struct AlUnkOmega {
    u8 unk_00;
    u8 unk_01;
    s8 unk_02;
    s8 unk__03;
} AlUnkOmega;

typedef struct AlUnkLambda {
    /* 0x000 */ MSEQHeader* unk_00;
    /* 0x004 */ u8* unk_04;
    /* 0x008 */ u8* unk_08;
    /* 0x00C */ u8* unk_0C;
    /* 0x010 */ u8* unk_10;
    /* 0x014 */ Q32 unk_14;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ u8 unk_24;
    /* 0x025 */ u8 unk_25;
    /* 0x026 */ u8 unk_26;
    /* 0x027 */ u8 unk_27;
    /* 0x028 */ u16 time;
    /* 0x02A */ u8 unk_2A;
    /* 0x02B */ u8 volume;
    /* 0x02C */ char unk_2C[4];
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ u32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03C */ s32 unk_3C;
    /* 0x040 */ u16 unk_lam_40;
    /* 0x042 */ u8 unk_42;
    /* 0x043 */ u8 unk_43;
    /* 0x044 */ AlUnkXi unk_44[10];
    /* 0x1D4 */ AlUnkOmega unk_1D4[4];
} AlUnkLambda; // size = 0x1E4

//TODO possibly StreamingSoundManager
typedef struct AmbientSoundManager {
    /* 0x000 */ SndGlobals* unk_00;
    /* 0x004 */ s32 nextUpdateStep;
    /* 0x008 */ s32 nextUpdateInterval;
    /* 0x00C */ s32 nextUpdateCounter;
    /* 0x010 */ s32* unk_10[4];
    /* 0x020 */ u8 unk_20;
    /* 0x021 */ u8 unk_21;
    /* 0x022 */ u8 unk_22;
    /* 0x023 */ u8 defaultReverbType;
    /* 0x024 */ AlUnkLambda unk_24[4];
    /* 0x7B4 */ AlUnkIota unk_7B4[16];
} AmbientSoundManager;

typedef struct ALConfig {
    /* 0x00 */ s32 num_pvoice;
    /* 0x04 */ s32 unk_num_gamma;
    /* 0x08 */ s32 outputRate;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ char unk_0D[3];
    /* 0x10 */ void* dmaNew;
    /* 0x14 */ ALHeap* heap;
} ALConfig; // size = 0x18;

extern volatile u8 D_80078181;
extern s32 D_80078190;
extern s32 D_800781D0;
extern s32 D_80078290;
extern s32 D_800782F8;
extern s32 D_80078348;
extern s32 D_80078320;
extern s32 D_80078544;
extern s32 D_800785A0;
extern s32 D_80078DB0;
extern u16 D_80078DB6;

extern AuSynDriver* D_80078E50;
extern AuSynDriver* gSynDriver;
extern u8 D_80078E58;
extern u16 D_80078E5A;
extern u8 D_80078E5C;

extern SndGlobals* gSoundGlobals;
extern BGMPlayer* gBGMPlayerC;
extern BGMPlayer* gBGMPlayerB;
extern UnkFuncAl D_8009A5E8;
extern AmbientSoundManager* D_8009A628;
extern SoundManager* gSoundManager;
extern BGMPlayer* gBGMPlayerA;

extern u16 D_800A0F50;

extern s16* D_800A3FE0;
extern s16* D_800A3FE4;
extern s32 D_800A3FE8;
extern u8 D_800A3FEC;
extern s16 D_800A3FEE;
extern s32 D_800A3FF0;

void snd_load_BK_headers(SndGlobals* arg0, ALHeap*);

void func_8004B440(SoundManager*, u8, u8, SndGlobals*, u8);
void snd_load_sfx_groups_from_SEF(SoundManager*);
void snd_clear_sfx_queue(SoundManager*);
void snd_enqueue_sfx_event(SoundManager*, s32, s16, s16, u8);
void func_8004B748(SoundManager*);
s32 func_8004B9E4(SoundManager*, s32);
void func_8004BA54(SoundManager*, s32);
s16 snd_sound_manager_update(SoundManager*);

void func_8004D510(BGMPlayer*);
BGMPlayer* snd_get_player_with_song_name(s32);
MusicError func_8004DA0C(s32);
void func_8004DAA8(BGMPlayer*);
s32 func_8004DB28(BGMPlayer*);
MusicError func_8004DC80(s32);
void func_8004DFD4(SndGlobals*);
void func_8004E158(BGMPlayer*, s32, s32, SndGlobals*);
void func_8004E344(BGMPlayer*, u8*);
void snd_update_bgm_fade(BGMPlayer*);
void func_8004E444(BGMPlayer*);
s32 func_8004E4B8(BGMPlayer*);
void func_8004E880(BGMPlayer*, s32, s32);
void snd_BGMCmd_E0_MasterTempo(BGMPlayer*, BGMPlayerTrack*);
s32 snd_bpm_to_tempo(BGMPlayer*, u32);
void snd_BGMCmd_E1_MasterVolume(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E2_MasterPitchShift(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E3(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E6_MasterEffect(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E4_MasterTempoFade(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E5_MasterVolumeFade(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E8_TrackOverridePatch(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E9_SubTrackVolume(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F6_TrackVolumeFade(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_EA_SubTrackPan(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_EB_SubTrackReverb(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_EC_SegTrackVolume(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_ED_SubTrackCoarseTune(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_EE_SubTrackFineTune(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_EF_SegTrackTune(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F0_TrackTremolo(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F1_TrackTremoloSpeed(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F2_TrackTremoloTime(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F3_TrackTremoloStop(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F4(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F5_TrackVoice(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_F7_SubTrackReverbType(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_FD(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_FE(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_FC_Jump(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_FF(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_NOP(BGMPlayer*, BGMPlayerTrack*);
void func_80050770(BGMPlayer*, f32);
void func_80050818(BGMPlayer*, s32);
void func_8005087C(BGMPlayer*, s32*, s32);
void bgm_set_proximity_mix_full(s32, u8);
void snd_set_bgm_proximity_mix(s32, u32);
void func_80050B90(AmbientSoundManager*, s8, s8, SndGlobals*);
s32 func_80050C30(u32);
void func_80050D50(AlUnkLambda*);
void snd_ambient_manager_update(AmbientSoundManager*);
void func_80051334(AmbientSoundManager*, AlUnkLambda*);
void func_80051434(AmbientSoundManager*, AlUnkLambda*);
void func_800521E8(AmbientSoundManager*, AlUnkLambda*);
void func_800522A8(AmbientSoundManager*, AlUnkLambda*);
void func_8005232C(AmbientSoundManager*, AlUnkLambda*);

void func_800525A0(SndGlobals*);
void func_80052614(SndGlobals*);
void func_80052660(SndGlobals*);
void func_80052B44(AlUnkVoice*);
void func_80052BF8(AlUnkVoice*, s32*);

void snd_reset_instrument(Instrument*);
void snd_reset_drum_entry(BGMDrumInfo*);
void snd_reset_instrument_entry(BGMInstrumentInfo*);
void func_80053654(SndGlobals*);
void snd_initialize_bgm_fade(Fade*, s32, s32, s32);
void snd_clear_bgm_fade(Fade*);
void func_80053A28(Fade*);
void func_80053A98(u8, u16, s32);
void snd_set_fade_vol_scale(Fade*, s16);
void func_80053BA8(Fade*);
Instrument* func_80053BE8(SndGlobals*, u32, u32, s32**);
s32 snd_load_BK(s32, s32);
void func_80054CE0(s32, s32);

void func_80055050(ALHeap*);
void func_80055110(BGMPlayer*);
void bgm_set_proximity_mix_far(s32, u8);
void bgm_set_proximity_mix_near(s32, u8);
void func_8005608C(u32**, s32*);
void func_800560A8(void);
void func_8005610C(void);
void func_80056144(UnkFuncAl, s32);
void audio_set_stereo(void);
void audio_set_mono(void);
void func_800561A4(s32);
void func_800561C4(s32);
void func_800561E4(s32);
void func_80056204(void);
void func_80056228(void);

void func_80056D44(s16);
s16 func_80056D50(void);
void func_80056D78(u8, u16);
void func_80056DCC(u8, u8);
void func_80056EC0(u8, s8);
void func_80056EE8(u8);
void func_80056FA4(u8, u8, Instrument*, f32, s16, u8, u8, s32);
void func_80057224(u8, Instrument*);
void func_80057344(u8, f32);
void func_8005736C(u8, s16, s32, u8, u8);
void func_80057548(u8, u8, u8);
void func_800576EC(u8, s16, s32);
void func_80057DC8(s32);
void func_80057E08(u8);
void func_80057E5C(u8);
void func_80057EB0(void);
void func_80057ED0(s16);

SoundBank* snd_load_BK_to_bank(s32 bkFileOffset, SoundBank* bank, s32 bankIndex, s32 bankGroup);
void snd_load_INIT(SndGlobals*, s32, ALHeap*);
s32 snd_fetch_SBN_file(u32, s32, SBNFileEntry*);
void snd_load_PER(SndGlobals*, s32);
void snd_load_PRG(SndGlobals*, s32);
void snd_read_rom(s32, void*, u32);
void snd_copy_words(void*, void*, s32);

f32 snd_compute_pitch_ratio(s32);

void func_8005083C(BGMPlayer* player, s32 trackIdx, s16 arg2, u8 arg3);

#undef alHeapAlloc
void* alHeapAlloc(ALHeap* heap, s32 arg1, s32 size);


#define	n_aADPCMdec(pkt, s, f, c, a, d)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(s, 0, 24));   \
	_a->words.w1 = (_SHIFTL(f, 28, 4) | _SHIFTL(c, 16, 12) |        \
			_SHIFTL(a, 12, 4) | _SHIFTL(d, 0, 12));         \
}

#define n_aPoleFilter(pkt, f, g, t, s)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_POLEF, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(g, 0, 16)); 				\
	_a->words.w1 = (_SHIFTL(t, 24, 8) |                             \
			_SHIFTL((unsigned int)(s), 0, 24));		\
}

#define n_aEnvMixer(pkt, f, t, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_ENVMIXER, 24, 8) | _SHIFTL(f, 16, 8) |\
			_SHIFTL(t, 0, 16));                     	\
	_a->words.w1 = (unsigned int)(s);				\
}

#define n_aInterleave(pkt)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_INTERLEAVE, 24, 8);    		\
}

#define n_aLoadBuffer(pkt, c, d, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_LOADBUFF, 24, 8) | _SHIFTL(c, 12, 12)|\
			_SHIFTL(d, 0, 12));                             \
	_a->words.w1 = (unsigned int)(s);				\
}

#define n_aResample(pkt, s, f, p, i, o)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(s, 0, 24));\
	_a->words.w1 = (_SHIFTL(f, 30, 2) | _SHIFTL(p, 14, 16) |        \
			_SHIFTL(i, 2, 12) | _SHIFTL(o, 0, 2));          \
}

#define n_aSaveBuffer(pkt, c, d, s)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_SAVEBUFF, 24, 8) | _SHIFTL(c, 12, 12)|\
			_SHIFTL(d, 0, 12));                             \
	_a->words.w1 = (unsigned int)(s);				\
}

#define n_aSetVolume(pkt, f, v, t, r)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(v, 0, 16)); 				\
	_a->words.w1 = _SHIFTL(t, 16, 16) | _SHIFTL(r, 0, 16);		\
}

#define n_aLoadADPCM(pkt, c, d)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24);	\
        _a->words.w1 = (unsigned int) d;                                \
}

#define aLoadBufferSize(pkt,s,u,b) { \
    Acmd *_a = (Acmd *)pkt; \
    _a->words.w0 = _SHIFTL(A_LOADBUFF, 24, 8) | _SHIFTL(s, 12, 12) | _SHIFTL(u, 0, 12); \
    _a->words.w1 = (unsigned int)(b); \
}

#define aSaveBufferSize(pkt,s,u,b) { \
    Acmd *_a = (Acmd *)pkt; \
    _a->words.w0 = _SHIFTL(A_SAVEBUFF, 24, 8) | _SHIFTL(s, 12, 12) | _SHIFTL(u, 0, 12); \
    _a->words.w1 = (unsigned int)(b); \
}

#define aInterleavePart(pkt) { \
    Acmd *_a = (Acmd *)pkt; \
    _a->words.w0 = _SHIFTL(A_INTERLEAVE, 24, 8); \
}

#endif
