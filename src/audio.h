#ifndef _AUDIO_H_
#define _AUDIO_H_
#include "nu/nusys.h"
#include "nu/nualsgi.h"
#include "common.h"

#define ALIGN16_(val) (((val) + 0xF) & 0xFFF0)

struct BGMPlayer;
struct SndGlobals;
struct UnkAl48;

typedef void (*UnkFuncAl)(void);

typedef union UnkField {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s32 s32;
} UnkField;

typedef union SeqArgs {
    u8 u8[4];
    s8 s8[4];
    u16 u16[2];
    u32 u32;
} SeqArgs;

typedef struct UnkAl1 {
    /* 0x00 */ UnkField unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ UnkFuncAl unk_0C;
    /* 0x10 */ UnkField unk_10;
    ///* 0x12 */ char unk_12[2];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} UnkAl1; // size unknown (currently 0x1C)

typedef struct Fade {
    /* 0x0 */ UnkField currentVolume;
    /* 0x4 */ s32 fadeStep;
    /* 0x8 */ s16 endVolume;
    /* 0xA */ s16 fadeTime;
    /* 0xC */ UnkFuncAl fpFadeCallback;
    /* 0x10 */ UnkField unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} Fade; // size = 0x10

typedef struct InstrumentCFG { // maybe same as UnkAlC?
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
} InstrumentCFG;

typedef struct UnkLen18 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ s32* unk_04;
    /* 0x08 */ s32* unk_08;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ char unk_0D[0x3];
    /* 0x10 */ s32* unk_10;
    /* 0x14 */ s32* unk_14;
} UnkLen18;

typedef struct UnkAl7C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32* unk_04;
    /* 0x08 */ s32* unk_08;
    /* 0x0C */ char unk_0C[0x8];
    /* 0x14 */ s32* unk_14;
    /* 0x18 */ s32* unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ ALDMAproc dmaProc;
    /* 0x24 */ NUDMAState* dmaState;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32* unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32* unk_48;
    /* 0x4C */ union {
                    s16 unk_4C;
                    struct {
                        u8 unk_4C;
                        u8 unk_4D;
                    } unk_4C_s;
               };
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ s16 unk_58;
    /* 0x5A */ s16 unk_5A;
    /* 0x5C */ s16 unk_5C;
    /* 0x5E */ s16 unk_5E;
    /* 0x60 */ s16 unk_60;
    /* 0x62 */ s16 unk_62;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ s32 unk_68;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ s16 unk_74;
    /* 0x76 */ s16 unk_76;
    /* 0x78 */ u8 unk_78;
    /* 0x79 */ u8 unk_79;
    /* 0x7A */ u8 unk_7A[2];
} UnkAl7C;

typedef struct UnkAl0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 frequency;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ void* dmaNew; // pointer to nuAuDmaNew
    /* 0x18 */ ALHeap* heap;
    /* 0x1C */ UnkAl7C* unk_1C; // pointer to list of UnkAl7C
    /* 0x20 */ UnkLen18* unk_20; // amt unknown
    /* 0x24 */ s32* unk_24;
    /* 0x28 */ s32* unk_28;
} UnkAl0;

typedef struct SoundSFXEntry {
    /* 0x0 */ s16 soundID;
    /* 0x2 */ s16 upperSoundID;
    /* 0x4 */ s16 volume;
    /* 0x6 */ s16 pitchShift;
    /* 0x8 */ s8 pan;
    /* 0x9 */ char unk_9[0x1];
} SoundSFXEntry; // size = 0xA

typedef struct Instrument {
    /* 0x00 */ UNK_PTR wavOffset;
    /* 0x04 */ s32 wavLength;
    /* 0x08 */ s32 loopPredictorOffset;
    /* 0x0C */ s32 loopStart;
    /* 0x10 */ s32 loopEnd;
    /* 0x14 */ s32 loopCount;
    /* 0x18 */ UNK_PTR predictorOffset;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ f32 sampleRate;
    /* 0x24 */ s8 skipLoopPredictor;
    /* 0x25 */ s8 unk_25;
    /* 0x26 */ s8 unk_26;
    /* 0x27 */ s8 unk_27;
    /* 0x28 */ s8 unk_28;
    /* 0x29 */ s8 unk_29;
    /* 0x2A */ s8 unk_2A;
    /* 0x2B */ s8 unk_2B;
    /* 0x2C */ UNK_PTR unkOffset;
} Instrument; // size = 0x30;

typedef Instrument* InstrumentGroup[16];

typedef struct SoundLerp {
    /* 0x0 */ s32 current;
    /* 0x4 */ s32 step;
    /* 0x8 */ s16 goal;
    /* 0xA */ s16 time;
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
    /* 0x10 */ s32* unk10;
    /* 0x14 */ char pad14[4];
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
    /* 0x85 */ s8 soundC00;
    /* 0x86 */ char unk_86[0x2];
    /* 0x88 */ s8* loopStartPos;
    /* 0x8C */ s8 loopIterCount;
    /* 0x8D */ char unk_8D;
    /* 0x8E */ u16 unk_8E;
    /* 0x90 */ u16 unk_90;
    /* 0x92 */ u16 unk_92;
    /* 0x94 */ u8 unk_94;
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
    /* 0xA1 */ s8 unk_A1;
    /* 0xA2 */ s8 unk_A2;
    /* 0xA3 */ s8 unk_A3;
    /* 0xA4 */ s16 masterPitchShift;
    /* 0xA6 */ s16 masterVolume;
    /* 0xA8 */ s8 masterPan;
    /* 0xA8 */ s8 unk_A9;
    /* 0xA9 */ char unk_AA[0x2];
} SoundPlayer; // size = 0xAC

typedef struct SoundSefHeader {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ s16 groupOffsets[8];
    /* 0x20 */ char unk_20[0x2];
} SoundSefHeader; // size = 0x22

typedef struct SoundManager {
    /* 0x000 */ struct SndGlobals* soundData;
    /* 0x004 */ struct UnkAl48* unk_04;
    /* 0x008 */ s32* sefData;
    /* 0x00C */ s32* normalSounds[8];
    /* 0x02C */ s32* soundsWithBit2000;
    /* 0x030 */ s32 playCounter; //?
    /* 0x034 */ s32 unkCounterStep;
    /* 0x038 */ s32 unkCounterMax;
    /* 0x03C */ s32 unkCounter;
    /* 0x040 */ struct Fade unk_40;
    /* 0x05C */ s32 unk_5C;
    /* 0x060 */ s32 unk_60;
    /* 0x064 */ s32* unk_64[8];
    /* 0x084 */ s8 unk_84[8];
    /* 0x08C */ u8 unk_8C;
    /* 0x08D */ s8 unk_8D;
    /* 0x08E */ char unk_8E[0x2];
    /* 0x090 */ s32 unk_90[4];
    /* 0x0A0 */ Vec3s unk_A0[4];
    /* 0x0B8 */ u16 unk_B8;
    /* 0x0BA */ s16 unk_BA;
    /* 0x0BC */ u8 unk_BC;
    /* 0x0BD */ u8 sfxPlayerSelector;
    /* 0x0BE */ u8 unk_BE;
    /* 0x0BF */ u8 unk_BF;
    /* 0x0C0 */ u8 unk_C0;
    /* 0x0C1 */ char unk_C1[0x1];
    /* 0x0C2 */ SoundSFXEntry unk_C2[16];
    /* 0x162 */ s8 unk_162;
    /* 0x163 */ u8 sfxQueuePosOffset;
    /* 0x164 */ u8 sfxQueueNextPos;
    /* 0x165 */ s8 unk_165;
    /* 0x166 */ char unk_166[0x2];
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ SoundPlayer unk_16C[8];
} SoundManager;

typedef struct UnkAlC {
    /* 0x0 */ s16 unk_00;
    /* 0x2 */ s16 unk_02;
    /* 0x4 */ s8 unk_04;
    /* 0x5 */ s8 unk_05;
    /* 0x6 */ s8 unk_06;
    /* 0x7 */ s8 unk_07;
    /* 0x8 */ s8 unk_08;
    /* 0x9 */ s8 unk_09;
    /* 0xA */ s8 unk_0A;
} UnkAlC;

typedef struct UnkAl48 { // Track?
    /* 0x00 */ s32 unk_00; // pointer to something
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ char unk_11[0x3];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32* unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk_38[0x1];
    /* 0x39 */ u8 unk_39;
    /* 0x3A */ u8 unk_3A;
    /* 0x3B */ u8 unk_3B;
    /* 0x3C */ u8 unk_3C;
    /* 0x3D */ u8 unk_3D;
    /* 0x3E */ u8 unk_3E;
    /* 0x3F */ u8 unk_3F;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ u8 unk_42;
    /* 0x43 */ u8 unk_43;
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ u8 unk_45;
    /* 0x46 */ char unk_46[2];
} UnkAl48; // size = 0x48

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
    /* 0x00 */ char unk_00[0x90];
} PEREntry; // size = 0x90;

typedef struct SBNFileEntry {
    /* 0x0 */ s32 offset;
    /* 0x4 */ u32 data;
} SBNFileEntry; // size = 0x8

typedef struct BKHeader {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ char unk_0E[2];
    /* 0x10 */ char unk_10[2];
    /* 0x12 */ u16 unk_12[0x10];
    /* 0x32 */ u16 unk_32;
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u16 unk_3A;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 unk_3E;
} BKHeader; // size = 0x40

typedef struct InitSongEntry {
    /* 0x0 */ u16 bgmFileIndex; // required BGM file
    /* 0x2 */ u16 bkFileIndex[3]; // optional BK files for this track
} InitSongEntry; // size = 0x8

typedef struct UnkAl19E0Sub {
    /* 0x0 */ u16 unk_0;
} UnkAl19E0Sub;

typedef struct UnkAl19E0Sub2 {
    /* 0x0 */ u8 unk_00;
    /* 0x1 */ u8 unk_01;
    /* 0x2 */ char unk_02[2];
} UnkAl19E0Sub2;

typedef struct UnkAl19E0Sub3 {
    /* 0x00 */ struct BGMPlayer* unk_0;
    /* 0x04 */ s8 unk_4;
    /* 0x05 */ s8 unk_5;
} UnkAl19E0Sub3;

typedef struct SoundBank {
    /* 0x000 */ char unk_00[0xE];
    /* 0x00E */ u8 swizzled;
    /* 0x010 */ char unk_0F[0x831];
} SoundBank; // size = 0x840

typedef struct SndGlobals {
    /* 0x0000 */ f32 actualFrequency;
    /* 0x0004 */ Instrument* defaultInstrument;
    /* 0x0008 */ UnkAlC unk_08;
    /* 0x0014 */ InstrumentCFG defaultPRGEntry;
    /* 0x001C */ s32 baseRomOffset;
    /* 0x0020 */ SBNFileEntry* sbnFileList;
    /* 0x0024 */ s32 fileListLength;
    /* 0x0028 */ char unk_28[0x4];
    /* 0x002C */ InitSongEntry* songList;
    /* 0x0030 */ s32 songListLength;
    /* 0x0034 */ s32 bkFileListOffset;
    /* 0x0038 */ s32 bkListLength;
    /* 0x003C */ UnkAl19E0Sub* mseqFileList;
    /* 0x0040 */ UnkAl19E0Sub2 unk_40[4];
    /* 0x0050 */ u8 unk_50;
    /* 0x0051 */ u8 unk_51;
    /* 0x0052 */ u8 unk_52;
    /* 0x0053 */ u8 unk_53;
    /* 0x0054 */ PEREntry* dataPER;
    /* 0x0058 */ InstrumentCFG* dataPRG;
    /* 0x005C */ s32* currentTrackData[4];
    /* 0x006C */ UnkAl19E0Sub3 unk_6C[1];
    /* 0x0074 */ char unk_74[0x8];
    /* 0x007C */ s32 unkSongName;
    /* 0x0080 */ s32 unk_80;
    /* 0x0084 */ s32 unkFadeTime;
    /* 0x0088 */ s32 unkFadeStart;
    /* 0x008C */ s32 unkFadeEnd;
    /* 0x0090 */ s32 unk_90;
    /* 0x0094 */ s32* unk_94;
    /* 0x0098 */ u32 unk_98;
    /* 0x009C */ s32 unk_9C;
    /* 0x00A0 */ s32* dataSEF;
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
    /* 0x1320 */ UnkAl48 unk_1320[24];
} SndGlobals; // size = 0x19E0

typedef struct BGMPlayerTrack {
    /* 0x00 */ u32 bgmReadPos;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ char unk_08[0x4];
    /* 0x0C */ Instrument* unk_0C;
    /* 0x10 */ s32* unk_10[2];
    /* 0x18 */ s32 subTrackVolume;
    /* 0x1C */ s32 subTrackVolumeFadeDelta;
    /* 0x20 */ s32 subTrackVolumeFadeVolume;
    /* 0x24 */ s32 subTrackVolumeFadeTime;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ s16 unk36;
    /* 0x38 */ u16 segTrackTune;
    /* 0x3A */ s16 trackTremoloAmount;
    /* 0x3C */ char unk_3C[0x2];
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ s8 tuneChanged;  //TODO may be a SoundPlayChange here
    /* 0x41 */ s8 volumeChanged;
    /* 0x42 */ s8 panChanged;
    /* 0x43 */ s8 reverbChanged;
    /* 0x44 */ u16 unk_44;
    /* 0x46 */ u16 subTrackCoarseTune;
    /* 0x48 */ u8 subTrackFineTune;
    /* 0x49 */ u8 segTrackVolume;
    /* 0x4A */ u8 subTrackPan;
    /* 0x4B */ u8 subTrackReverb;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ u8 unk_4E;
    /* 0x4F */ u8 unk_4F;
    /* 0x50 */ u8 unk_50;
    /* 0x51 */ char unk_51[0x1];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ char unk_54[0x1];
    /* 0x55 */ s8 trackTremoloSpeed;
    /* 0x56 */ s8 trackTremoloTime;
    /* 0x57 */ s8 unk_57;
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ u8 unk_59;
    /* 0x5A */ u8 unk_5A;
    /* 0x5B */ s8 subtrackReverbType;
    /* 0x5C */ u8 unk_5C;
    /* 0x5D */ char unk_5D[0x3];
} BGMPlayerTrack; // size = 0x60;

typedef struct UnkAl24 {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk_10[0x4];
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u8 unk_16;
    /* 0x17 */ u8 unk_17;
} UnkAl24; // size = 0x18;

typedef struct BGMPlayer {
    /* 0x000 */ SndGlobals* data;
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
    /* 0x04C */ u8 unk_4C[4];
    /* 0x050 */ s32 unk_50;
    /* 0x054 */ char pad54[4];
    /* 0x058 */ s16 unk_58;
    /* 0x05A */ s16 unk_5A;
    /* 0x05C */ s16 unk_5C;
    /* 0x05E */ char unk_5E[0x6];
    /* 0x064 */ struct UnkAlTrack* unk_64;
    /* 0x068 */ s32* unk_68;
    /* 0x06C */ s32 unk_6C;
    /* 0x070 */ s32 unk_70;
    /* 0x074 */ s32 unk_74;
    /* 0x078 */ s32 unk_78;
    /* 0x07C */ s32 unk_7C;
    /* 0x080 */ char unk_80[0x30];
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
    /* 0x0D8 */ s32* unk_D8;
    /* 0x0DC */ char padDC[0x7C];
    /* 0x158 */ s32 unk_158;
    /* 0x15C */ s32 unk_15C;
    /* 0x160 */ s32 unk_160;
    /* 0x164 */ s32 unk_164;
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ s32 unk_16C;
    /* 0x170 */ u8 unk_170;
    /* 0x171 */ s8 unk_171;
    /* 0x172 */ char unk_172[0x2];
    /* 0x174 */ s16 unk_174[8][9];
    /* 0x204 */ s32* unk_204;
    /* 0x208 */ u16 masterTempoBPM;
    /* 0x20A */ u16 bgmKhz;
    /* 0x20C */ s16 masterTranspose;
    /* 0x20E */ s16 unk_20E;
    /* 0x210 */ s8 unk_210;
    /* 0x211 */ s8 unk_211;
    /* 0x212 */ s8 unk_212[8];
    /* 0x21A */ u8 unk_21A;
    /* 0x21B */ char unk_21B[0x1];
    /* 0x21C */ u8 bgmDrumCount;
    /* 0x21D */ u8 bgmInstrumentCount;
    /* 0x21E */ s8 unk_21E;
    /* 0x21F */ char unk_21F[0x1];
    /* 0x220 */ u8 unk_220;
    /* 0x221 */ u8 unk_221;
    /* 0x222 */ u8 unk_222;
    /* 0x223 */ u8 unk_223;
    /* 0x224 */ u8 unk_224[3];
    /* 0x227 */ char unk_227[0x3];
    /* 0x22A */ u8 unk_22A;
    /* 0x22B */ u8 unk_22B;
    /* 0x22C */ u8 unk_22C;
    /* 0x22D */ u8 unk_22D;
    /* 0x22E */ u8 unk_22E;
    /* 0x22F */ u8 unk_22F;
    /* 0x230 */ u8 unk_230;
    /* 0x231 */ u8 unk_231;
    /* 0x232 */ u8 unk_232;
    /* 0x233 */ s8 unk_233;
    /* 0x234 */ u8 unk_234;
    /* 0x235 */ u8 unk_235;
    /* 0x236 */ char unk_236[0x2];
    /* 0x238 */ s32 unk_238[8];
    /* 0x258 */ u8 unk_258;
    /* 0x259 */ s8 unk_259;
    /* 0x25A */ u8 unk_25A;
    /* 0x25B */ u8 unk_25B;
    /* 0x25C */ BGMPlayerTrack unk_25C[16];
    /* 0x85C */ UnkAl24 unk_85C[24];
} BGMPlayer; // size = 0xA9C

typedef union Q32 {
    u8 u8[4];
    u16 u16[2];
    s32 s32;
} Q32;

typedef struct UnkAl8 {
    /* 0x00 */ Q32 unk_00;
    /* 0x04 */ char unk_04[0x4];
} UnkAl8; // size = 0x8

typedef struct UnkAl1E4 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s8 unk_14;
    /* 0x15 */ char unk_15[3];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u8 unk_26;
    /* 0x26 */ u8 unk_27;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u8 unk_2A;
    /* 0x2B */ u8 unk_2B;
    /* 0x2C */ char unk_2C[0xC];
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s8 unk_42;
    /* 0x43 */ char unk_43[0x1A1];
} UnkAl1E4; // size = 0x1E4

//TODO possibly AmbientSoundManager
typedef struct UnkAl834 {
    /* 0x000 */ SndGlobals* unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ s32* unk_10[4];
    /* 0x020 */ u8 unk_20;
    /* 0x021 */ u8 unk_21;
    /* 0x022 */ u8 unk_22;
    /* 0x023 */ u8 unk_23;
    /* 0x024 */ UnkAl1E4 unk_24[4];
    /* 0x7B4 */ UnkAl8 unk_7B4[16];
} UnkAl834;

typedef struct ALConfig {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 frequency;
    /* 0x0C */ u8 unk_0C;
    /* 0x10 */ void* dmaNew;
    /* 0x14 */ ALHeap* heap;
} ALConfig; // size = 0x18;

typedef struct UnkAl4PlusSub {
    /* 0x00 */ u16 unkOffset1;
    /* 0x02 */ u16 unkOffset2;
} UnkAl4PlusSub; // size = 0x4;

typedef struct UnkAl4Plus {
    /* 0x00 */ u8 count;
    /* 0x01 */ char unk_01[3];
    /* 0x04 */ struct UnkAl4PlusSub unk_04[1]; // variable size
} UnkAl4Plus;

typedef struct UnkAlTrack {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} UnkAlTrack;

extern u8 D_80078181;
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

extern UnkAl0* D_80078E50;
extern UnkAl0* D_80078E54;
extern s8 D_80078E58;
extern s16 D_80078E5A;
extern s8 D_80078E5C;
extern s32* D_8007F1F8[1]; // points to 80078290

extern SndGlobals* D_8009A5C0;
extern BGMPlayer* D_8009A5CC;
extern BGMPlayer* D_8009A5FC;
extern UnkFuncAl D_8009A5E8;
extern UnkAl834* D_8009A628;
extern SoundManager* D_8009A640;
extern BGMPlayer* D_8009A664;

extern u16 D_800A0F50;

extern s16* D_800A3FE0;
extern s16* D_800A3FE4;
extern s32 D_800A3FE8;
extern s8 D_800A3FEC;
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
s16 func_8004C444(SoundManager*);

void func_8004D510(BGMPlayer*);
BGMPlayer* snd_get_player_with_song_name(s32);
s32 func_8004DA0C(UNK_TYPE);
void func_8004DAA8(BGMPlayer*);
s32 func_8004DB28(BGMPlayer*);
void func_8004DC80(s32);
void func_8004DFD4(SndGlobals*);
void func_8004E158(BGMPlayer*, s32, s32, SndGlobals*);
void func_8004E344(BGMPlayer*, u8*);
void snd_update_bgm_fade(BGMPlayer*);
void func_8004E444(BGMPlayer*);
s16 func_8004E4B8(BGMPlayer*);
void func_8004E880(BGMPlayer*, s32, s32);
void snd_BGMCmd_E0_MasterTempo(BGMPlayer*, BGMPlayerTrack*);
s32 snd_bpm_to_tempo(BGMPlayer*, u32);
void snd_BGMCmd_E1_MasterVolume(BGMPlayer*, BGMPlayerTrack*);
void snd_BGMCmd_E2_MasterTranspose(BGMPlayer*, BGMPlayerTrack*);
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
void func_80056068(s32, u8);
void func_800506C8(s32, u32);
void func_80050B90(UnkAl834*, s8, s8, SndGlobals*);
s32 func_80050C30(u32);
void func_80050D50(UnkAl1E4*);
void func_800511BC(UnkAl834*);
void func_80051334(UnkAl834*, UnkAl1E4*);
void func_80051434(UnkAl834*, UnkAl1E4*);
void func_800521E8(UnkAl834*, UnkAl1E4*);
void func_800522A8(UnkAl834*, UnkAl1E4*);
void func_8005232C(UnkAl834*, UnkAl1E4*);

void func_800525A0(SndGlobals*);
void func_80052614(SndGlobals*);
void func_80052660(SndGlobals*);
void func_80052B44(UnkAl48*);
void func_80052BF8(UnkAl48*, s32*);

void snd_reset_instrument(Instrument*);
void func_80053370(UnkAlC*);
void func_800533A8(InstrumentCFG*);
void func_80053654(SndGlobals*);
void snd_initialize_bgm_fade(Fade*, s32, s32, s16);
void snd_clear_bgm_fade(Fade*);
void func_80053A28(Fade*);
void func_80053A98(u8, u16, s32);
void func_80053AEC(Fade*, s16);
void func_80053BA8(Fade*);
Instrument* func_80053BE8(SndGlobals*, u32, u32, s32**);
s32 snd_load_BK(s32, s32);
void func_80054CE0(s32, s32);

void func_80055050(ALHeap*);
void func_80055110(BGMPlayer*);
s32 func_80055FF0(s32, s32);
s32 func_8005600C(s32, s32);
void func_80056028(s32, u8);
void func_80056044(s32, u8);
void func_8005608C(s32*, s32*);
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
void func_80056FA4(u8, u8, s32, f32, s16, u8, u8, s32);
void func_80057224(u8, Instrument*);
void func_80057344(u8, f32);
void func_8005736C(u8, s16, s32, u8, u8);
void func_80057548(u8, u8, u8);
void func_800576EC(u8, s32, s32);
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

void func_80058E84(s32*, u8, ALHeap*);
void func_8005904C(s32*, u8);
#undef alHeapAlloc
void* alHeapAlloc(ALHeap *heap, s32 arg1, s32 size);

#endif
