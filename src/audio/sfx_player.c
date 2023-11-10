#include "common.h"
#include "audio.h"

static void au_sfx_play_sound(SoundManager* manager, SoundPlayer* player, s8* readPos, SoundSFXEntry* sfxEntry, s32 arg4, s32 arg5);
static void au_sfx_set_triggers(SoundManager* manager, u32 soundID);
static void au_sfx_stop_by_id(SoundManager* manager, u32 soundID);
static void au_sfx_stop_by_exlusive_id(SoundManager* manager, u32 soundID);
static void au_sfx_set_modifiers(SoundManager* manager, SoundSFXEntry* sfxEntry);
static void au_sfx_set_player_modifiers(SoundPlayer* player, SoundSFXEntry* sfxEntry);

static void au_sfx_update_basic(SoundManager* manager, SoundPlayer* player, AuVoice* arg2, u8 arg3);
static s16 au_sfx_get_scaled_volume(SoundManager* manager, SoundPlayer* player);
static void au_sfx_update_sequence(SoundManager* manager, SoundPlayer* player, AuVoice* arg2, u8 arg3);
static void snd_set_voice_volume(AuVoice* voice, SoundManager* manager, SoundPlayer* player);
static u8 au_sfx_get_random_pan(s32 arg0, s32 arg1, s32 arg2);
static void au_SEFCmd_00_SetVolume(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_01_SetPan(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_02_SetInstrument(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_03_SetReverb(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_04_SetEnvelope(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_05_CoarseTune(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_06_FineTune(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_07_WaitForEnd(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_08_PitchSweep(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_09_StartLoop(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_0A_EndLoop(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_0B_WaitForRelease(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_0C_SetCurrentVolume(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_0D_VolumeRamp(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_0E_SetAlternativeSound(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_0F_Stop(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_10_Jump(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_11_Restart(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_12_NOP(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_13_SetRandomPitch(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_14_SetRandomVelocity(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_15_SetUnkA3(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_16_SetEnvelopePress(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_17_PlaySound(SoundManager* manager, SoundPlayer* player);
static void au_SEFCmd_18_SetAlternativeVolume(SoundManager* manager, SoundPlayer* player);
static s32 au_sfx_get_random_pitch(s32 arg0, s32 arg1, s32 arg2);
static u8 au_sfx_get_random_vol(s32 arg0, s32 arg1, s32 arg2);
static void au_sfx_reset_players(SoundManager* manager);

enum SoundEffectParamFlags {
    // 8 bytes: flags, instrument, volume, pan, reverb, pitch, randomPitch
    SFX_PARAM_MODE_ADVANCED         = 0x00000000,
    // arbitrary sequence of commands
    SFX_PARAM_MODE_SEQUENCE         = 0x00000001,
    // 4 bytes: flags, instrument, volume and randomPitch
    SFX_PARAM_MODE_BASIC            = 0x00000002,
    SFX_PARAM_FLAG_MODE             = 0x00000003,
    // when flags below are set, these params can't be changed from api functions like sfx_play_sound_with_params
    SFX_PARAM_FLAG_VOLUME           = 0x00000004,
    SFX_PARAM_FLAG_PAN              = 0x00000008,
    SFX_PARAM_FLAG_PITCH            = 0x00000010,
    // prevents from changing reverb amount via SetReverb command
    SFX_PARAM_FLAG_FIXED_REVERB     = 0x00000020
};

u16 DummyInstrumentPredictor[32] = {
    0xF803, 0x0125, 0x07D0, 0xFDBC, 0xF886, 0x0355, 0x06FC, 0xFBAB,
    0xFEDA, 0xF82D, 0x0245, 0x077D, 0xFCA9, 0xF901, 0x0456, 0x065D,
    0xFC33, 0xFBB2, 0xFCEF, 0xFE94, 0xFFD8, 0x0080, 0x00A4, 0x007D,
    0x090E, 0x0673, 0x02FF, 0x0053, 0xFEF2, 0xFEA7, 0xFEF9, 0xFF7B
};

u8 DummyInstrumentBase[190] = {
    0xB1, 0x01, 0x11, 0x10, 0x00, 0xFF, 0xFE, 0x34, 0xBB, 0x90, 0xE2, 0x1E, 0x00, 0xFB, 0x10, 0xEF,
    0xF2, 0xD1, 0x80, 0xC4, 0xB3, 0xB1, 0xD3, 0xCF, 0xD1, 0xFD, 0xFE, 0x80, 0x1D, 0x2D, 0x3D, 0x3B,
    0x2C, 0x3B, 0xFC, 0x1D, 0x80, 0xDE, 0xF0, 0xD0, 0xD3, 0xD2, 0xB3, 0xD1, 0xF4, 0x80, 0xA2, 0x03,
    0xD0, 0x0D, 0xA9, 0xEA, 0xCB, 0x72, 0x90, 0x41, 0x4E, 0x1D, 0x2D, 0x0C, 0x1E, 0x10, 0x2F, 0x90,
    0xF2, 0x12, 0x03, 0xF0, 0xC2, 0xD1, 0xD4, 0xF3, 0x80, 0xB0, 0xA1, 0xBF, 0xD2, 0x1E, 0x12, 0x70,
    0x4D, 0x80, 0x4C, 0x39, 0x2C, 0x7E, 0x30, 0x6D, 0xB9, 0xCF, 0x90, 0xE1, 0xF2, 0xF3, 0xF2, 0xE1,
    0xE2, 0x16, 0x22, 0xC1, 0xE7, 0x28, 0xF4, 0xF0, 0x21, 0x10, 0x10, 0xFF, 0xA1, 0xED, 0x9F, 0x2F,
    0xF5, 0x61, 0x33, 0x3C, 0xD0, 0xA1, 0xDA, 0xC2, 0xFF, 0x14, 0x41, 0x22, 0x2D, 0xEF, 0xA1, 0xFA,
    0xE1, 0x0E, 0x23, 0x30, 0x32, 0x0E, 0xF0, 0x91, 0x9A, 0xF2, 0xCF, 0x55, 0x13, 0x61, 0xEE, 0x1C,
    0x91, 0x9D, 0x0F, 0xD2, 0x52, 0x06, 0x4D, 0xE1, 0x09, 0x91, 0xD0, 0x1B, 0x15, 0x2E, 0x36, 0xFD,
    0x12, 0xCB, 0x81, 0x22, 0xBC, 0x65, 0xF0, 0x73, 0xCE, 0x3F, 0xAE, 0x71, 0x4E, 0x93, 0x70, 0xF5,
    0x6E, 0xD2, 0x1B, 0xD1, 0x61, 0x0A, 0x5D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// copy of SMALL_ROOM_PARAMS
s32 CUSTOM_SMALL_ROOM_PARAMS[] = {
    /* sections    length */
        3,             11,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,      9,   9830,  -9830,      0,      0,      0,      0,
        3,      7,   3276,  -3276, 0x3FFF,      0,      0,      0,
        0,     10,   5000,      0,      0,      0,      0, 0x5000
};

// modified ECHO_PARAMS -- length and output changed
s32 CUSTOM_ECHO_PARAMS_1[] = {
    /* sections    length */
        1,             11,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,     10,  20000,      0, 0x7FFF,      0,      0, 0x7FFF
};

// modified ECHO_PARAMS -- length and output changed
s32 CUSTOM_ECHO_PARAMS_2[] = {
    /* sections    length */
        1,             13,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,     12,  20000,      0, 0x7FFF,      0,      0, 0x7FFF
};

// modified ECHO_PARAMS -- length and output changed
s32 CUSTOM_ECHO_PARAMS_3[] = {
    /* sections    length */
        1,             14,
    /*                                      chorus  chorus   filter
    input  output  fbcoef  ffcoef   gain     rate   depth     coef  */
        0,     13,  20000,      0, 0x7FFF,      0,      0, 0x7FFF
};

AlUnkGemini D_80078370[] = {
    {
    .sound1 = SOUND_SHORT_CLAP,
    .sound2 = SOUND_LRAW_CHEERING,
    .flags = 1
    }
};

// TODO: figure out how to make struct properly
EnvelopePreset SFXEnvelopeFast = {
    .count = 1,
    .offsets = { { 0x08, 0x12 } },
};

u8 SFXEnvelopeFastData[] = {
    // press
    ENV_TIME_290MS,     127,
    ENV_TIME_900MS,     127,
    ENV_TIME_1S,        95,
    ENV_TIME_3S,        0,
    ENV_CMD_END,        0,
    // release
    ENV_TIME_1400MS,    0,
    ENV_CMD_END,        0
};

EnvelopePreset SFXEnvelopeSlow = {
    .count = 1,
    .offsets = { { 0x08, 0x1A } },
};

u8 SFXEnvelopeSlowData[] = {
    // press
    ENV_TIME_290MS,     127,
    ENV_TIME_1800MS,    127,
    ENV_TIME_290MS,     63,
    ENV_TIME_1100MS,    31,
    ENV_TIME_1100MS,    15,
    ENV_TIME_1100MS,    7,
    ENV_TIME_1100MS,    3,
    ENV_TIME_450MS,     0,
    ENV_CMD_END,        0,
    // release
    ENV_TIME_450MS,     0,
    ENV_CMD_END,        0,
};

// looks like envelope data, but it's not aligned and not used
s32 D_800783B0[] = {
    0x34337F26, 0x3F1600FF, 0x343B7F3B, 0x3FFF0000
};

EnvelopePreset* SFXEnvelopePresets[] = {
    &SFXEnvelopeFast,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow,
    &SFXEnvelopeSlow
};

void (*SefCmdHandlers[])(SoundManager*, SoundPlayer*) = {
    au_SEFCmd_00_SetVolume,
    au_SEFCmd_01_SetPan,
    au_SEFCmd_02_SetInstrument,
    au_SEFCmd_03_SetReverb,
    au_SEFCmd_04_SetEnvelope,
    au_SEFCmd_05_CoarseTune,
    au_SEFCmd_06_FineTune,
    au_SEFCmd_07_WaitForEnd,
    au_SEFCmd_08_PitchSweep,
    au_SEFCmd_09_StartLoop,
    au_SEFCmd_0A_EndLoop,
    au_SEFCmd_0B_WaitForRelease,
    au_SEFCmd_0C_SetCurrentVolume,
    au_SEFCmd_0D_VolumeRamp,
    au_SEFCmd_0E_SetAlternativeSound,
    au_SEFCmd_0F_Stop,
    au_SEFCmd_10_Jump,
    au_SEFCmd_11_Restart,
    au_SEFCmd_12_NOP,
    au_SEFCmd_13_SetRandomPitch,
    au_SEFCmd_14_SetRandomVelocity,
    au_SEFCmd_15_SetUnkA3,
    au_SEFCmd_16_SetEnvelopePress,
    au_SEFCmd_17_PlaySound,
    au_SEFCmd_18_SetAlternativeVolume
};

u8 BlankSEFData[] = {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

// --------------------------------------------
// the following are only referenced in audio/28910_len_5090

void (*SeqCmdHandlers[])(BGMPlayer*, BGMPlayerTrack*) = {
    au_BGMCmd_E0_MasterTempo,
    au_BGMCmd_E1_MasterVolume,
    au_BGMCmd_E2_MasterPitchShift,
    au_BGMCmd_E3,
    au_BGMCmd_E4_MasterTempoFade,
    au_BGMCmd_E5_MasterVolumeFade,
    au_BGMCmd_E6_MasterEffect,
    au_BGMCmd_NOP,
    au_BGMCmd_E8_TrackOverridePatch,
    au_BGMCmd_E9_SubTrackVolume,
    au_BGMCmd_EA_SubTrackPan,
    au_BGMCmd_EB_SubTrackReverb,
    au_BGMCmd_EC_SegTrackVolume,
    au_BGMCmd_ED_SubTrackCoarseTune,
    au_BGMCmd_EE_SubTrackFineTune,
    au_BGMCmd_EF_SegTrackTune,
    au_BGMCmd_F0_TrackTremolo,
    au_BGMCmd_F1_TrackTremoloSpeed,
    au_BGMCmd_F2_TrackTremoloTime,
    au_BGMCmd_F3_TrackTremoloStop,
    au_BGMCmd_F4,
    au_BGMCmd_F5_TrackVoice,
    au_BGMCmd_F6_TrackVolumeFade,
    au_BGMCmd_F7_SubTrackReverbType,
    au_BGMCmd_NOP,
    au_BGMCmd_NOP,
    au_BGMCmd_NOP,
    au_BGMCmd_NOP,
    au_BGMCmd_FC_Jump,
    au_BGMCmd_FD_EventTrigger,
    au_BGMCmd_FE_Detour,
    au_BGMCmd_FF,
};

s8 SeqCmdArgCounts[] = {
    2, 1, 1, 1, 4, 3, 2, 0,
    2, 1, 1, 1, 1, 1, 1, 2,
    3, 1, 1, 0, 2, 1, 3, 1,
    0, 0, 0, 0, 3, 3, 3, 3
};

s8 BgmDivisors[] = {
    48, 24, 32, 40, 48, 56, 64, 48,
     0,  0,  0,  0,  0,  0,  0,  0
};

// --------------------------------------------
// the following are only referenced in audio/2BF90

u8 BlankMseqData[] = {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

// --------------------------------------------
// the following are only referenced in audio/2e230_len_2190

s16 D_80078530[] = {
    0x0000, 0x0200, 0x0800, 0x1200, 0x2000, 0x3200, 0x4800, 0x6200, 0x8000
};

// TODO: figure out how to make struct properly
EnvelopePreset DummyInstrumentEnvelope = {
    .count = 1,
    .offsets = { { 0x8, 0xC } }, // EnvelopePressDefault, EnvelopePressDefault
};

u8 EnvelopePressDefault[] = {
    ENV_TIME_280MS, 127,
    ENV_CMD_END, 0
};

u8 EnvelopeReleaseDefault[] = {
    ENV_TIME_550MS, 0,
    ENV_CMD_END, 0
};

u8 EnvelopeReleaseDefaultFast[] = {
    ENV_TIME_2UNITS, 0,
    ENV_CMD_END, 0
};

// --------------------------------------------
// the following are only referenced in 28910_len_5090

s8 D_80078558[] = {
    0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x58, 0x56, 0x53,
    0x51, 0x4F, 0x4A, 0x45, 0x40, 0x3B, 0x37, 0x35,
    0x33, 0x31, 0x2F, 0x2D, 0x2B, 0x29, 0x27, 0x26,
    0x25, 0x23, 0x21, 0x20, 0x1F, 0x1E, 0x1D, 0x1C,
    0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14
};

// --------------------------------------------
// the following are only referenced in audio/2e230_len_2190

u8 AmbientSoundIDtoMSEQFileIndex[] = {
    0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
    0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12,
    0x13, 0x14, 0x15, 0x16, 0x17, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// --------------------------------------------
// the following are only referenced in audio/2d9a0_len_890

// convert seconds to microseconds and round to number multiple to 5750
#define SEC(x) ((s32)(x * 1000000) / AU_5750 * AU_5750)

s32 AuEnvelopeIntervals[] = {
    SEC(60),   SEC(55),   SEC(50),   SEC(45),   SEC(40),   SEC(35),   SEC(30),    SEC(27.5), SEC(25),    SEC(22.5),
    SEC(20),   SEC(19),   SEC(18),   SEC(17),   SEC(16),   SEC(15),   SEC(14),    SEC(13),   SEC(12),    SEC(11),
    SEC(10),   SEC(9),    SEC(8),    SEC(7),    SEC(6),    SEC(5),    SEC(4.5),   SEC(4),    SEC(3.5),   SEC(3),
    SEC(2.75), SEC(2.5),  SEC(2.25), SEC(2),    SEC(1.9),  SEC(1.8),  SEC(1.7),   SEC(1.6),  SEC(1.5),   SEC(1.4),
    SEC(1.3),  SEC(1.2),  SEC(1.1),  SEC(1),    SEC(0.95), SEC(0.9),  SEC(0.85),  SEC(0.8),  SEC(0.75),  SEC(0.7),
    SEC(0.65), SEC(0.6),  SEC(0.55), SEC(0.5),  SEC(0.45), SEC(0.4),  SEC(0.375), SEC(0.35), SEC(0.325), SEC(0.3),
    SEC(0.29), SEC(0.28), SEC(0.27), SEC(0.26), SEC(0.25), SEC(0.24), SEC(0.23),  SEC(0.22), SEC(0.21),  SEC(0.2),
    SEC(0.19), SEC(0.18), SEC(0.17), SEC(0.16), SEC(0.15), SEC(0.14), SEC(0.13),  SEC(0.12), SEC(0.11),  SEC(0.1),
    16 * AU_5750, 14 * AU_5750, 12 * AU_5750, 11 * AU_5750, 10 * AU_5750,
     9 * AU_5750,  8 * AU_5750,  7 * AU_5750,  6 * AU_5750, 5 * AU_5750,
     4 * AU_5750,  3 * AU_5750,  2 * AU_5750,  1 * AU_5750, 0, 0, 0, 0, 0, 0,
};

#undef SEC

// --------------------------------------------
// the following are only referenced in audio/2e230_len_2190

f32 AlTuneScaling[] = {
    // TUNE_SCALING_ARR_AMPLIFY_FINE
    1.00000000f, 1.00057781f, 1.00115597f, 1.00173450f, 1.00231326f, 1.00289237f, 1.00347185f, 1.00405169f,
    1.00463188f, 1.00521231f, 1.00579309f, 1.00637424f, 1.00695574f, 1.00753760f, 1.00811982f, 1.00870228f,
    1.00928509f, 1.00986826f, 1.01045179f, 1.01103568f, 1.01161981f, 1.01220429f, 1.01278913f, 1.01337433f,
    1.01395988f, 1.01454580f, 1.01513207f, 1.01571858f, 1.01630545f, 1.01689267f, 1.01748025f, 1.01806819f,
    1.01865649f, 1.01924503f, 1.01983392f, 1.02042317f, 1.02101278f, 1.02160275f, 1.02219307f, 1.02278376f,
    1.02337468f, 1.02396595f, 1.02455759f, 1.02514958f, 1.02574193f, 1.02633464f, 1.02692771f, 1.02752113f,
    1.02811480f, 1.02870882f, 1.02930319f, 1.02989793f, 1.03049302f, 1.03108847f, 1.03168428f, 1.03228045f,
    1.03287685f, 1.03347361f, 1.03407073f, 1.03466821f, 1.03526604f, 1.03586423f, 1.03646278f, 1.03706169f,
    1.03766096f, 1.03826058f, 1.03886044f, 1.03946066f, 1.04006124f, 1.04066217f, 1.04126346f, 1.04186511f,
    1.04246712f, 1.04306948f, 1.04367220f, 1.04427528f, 1.04487872f, 1.04548252f, 1.04608655f, 1.04669094f,
    1.04729569f, 1.04790080f, 1.04850626f, 1.04911208f, 1.04971826f, 1.05032480f, 1.05093169f, 1.05153894f,
    1.05214655f, 1.05275452f, 1.05336285f, 1.05397153f, 1.05458057f, 1.05518997f, 1.05579972f, 1.05640972f,
    1.05702007f, 1.05763078f, 1.05824184f, 1.05885327f, 1.05946505f, 1.06007719f, 1.06068969f, 1.06130254f,
    1.06191576f, 1.06252933f, 1.06314325f, 1.06375754f, 1.06437218f, 1.06498718f, 1.06560254f, 1.06621826f,
    1.06683433f, 1.06745076f, 1.06806755f, 1.06868470f, 1.06930220f, 1.06992006f, 1.07053828f, 1.07115686f,
    1.07177579f, 1.07239509f, 1.07301474f, 1.07363474f, 1.07425511f, 1.07487583f, 1.07549691f, 1.07611835f,
    // TUNE_SCALING_ARR_AMPLIFY_COARSE
    1.00000000f, 1.07674015f, 1.15936935f, 1.24833953f, 1.34413731f, 1.44728661f, 1.55835164f, 1.67793977f,
    1.80670512f, 1.94535196f, 2.09463859f, 2.25538135f, 2.42845964f, 2.61482000f, 2.81548166f, 3.03154206f,
    3.26418304f, 3.51467681f, 3.78439355f, 4.07480860f, 4.38750982f, 4.72420788f, 5.08674431f, 5.47710180f,
    5.89741516f, 6.34998369f, 6.83728218f, 7.36197615f, 7.92693520f, 8.53524971f, 9.19024563f, 9.89550686f,
    // TUNE_SCALING_ARR_ATTENUATE_FINE
    1.00000000f, 0.99942255f, 0.99884546f, 0.99826866f, 0.99769223f, 0.99711609f, 0.99654031f, 0.99596488f,
    0.99538976f, 0.99481499f, 0.99424052f, 0.99366641f, 0.99309260f, 0.99251914f, 0.99194598f, 0.99137318f,
    0.99080074f, 0.99022859f, 0.98965681f, 0.98908532f, 0.98851418f, 0.98794335f, 0.98737288f, 0.98680270f,
    0.98623288f, 0.98566335f, 0.98509419f, 0.98452532f, 0.98395681f, 0.98338860f, 0.98282075f, 0.98225319f,
    0.98168600f, 0.98111910f, 0.98055255f, 0.97998631f, 0.97942042f, 0.97885484f, 0.97828960f, 0.97772467f,
    0.97716010f, 0.97659582f, 0.97603190f, 0.97546828f, 0.97490501f, 0.97434205f, 0.97377944f, 0.97321713f,
    0.97265512f, 0.97209346f, 0.97153211f, 0.97097111f, 0.97041041f, 0.96985006f, 0.96929002f, 0.96873033f,
    0.96817094f, 0.96761185f, 0.96705312f, 0.96649468f, 0.96593660f, 0.96537882f, 0.96482134f, 0.96426421f,
    0.96370739f, 0.96315092f, 0.96259475f, 0.96203887f, 0.96148336f, 0.96092814f, 0.96037328f, 0.95981872f,
    0.95926446f, 0.95871055f, 0.95815694f, 0.95760363f, 0.95705068f, 0.95649803f, 0.95594567f, 0.95539367f,
    0.95484197f, 0.95429057f, 0.95373952f, 0.95318878f, 0.95263839f, 0.95208830f, 0.95153850f, 0.95098901f,
    0.95043987f, 0.94989103f, 0.94934249f, 0.94879431f, 0.94824642f, 0.94769883f, 0.94715160f, 0.94660467f,
    0.94605803f, 0.94551176f, 0.94496578f, 0.94442010f, 0.94387472f, 0.94332969f, 0.94278497f, 0.94224054f,
    0.94169647f, 0.94115269f, 0.94060922f, 0.94006604f, 0.93952322f, 0.93898070f, 0.93843848f, 0.93789655f,
    0.93735498f, 0.93681371f, 0.93627274f, 0.93573207f, 0.93519175f, 0.93465173f, 0.93411201f, 0.93357259f,
    0.93303353f, 0.93249476f, 0.93195629f, 0.93141812f, 0.93088025f, 0.93034273f, 0.92980552f, 0.92926860f,
    // TUNE_SCALING_ARR_ATTENUATE_COARSE
    1.00000000f, 0.92873198f, 0.86254311f, 0.80107135f, 0.74398059f, 0.69095856f, 0.64171529f, 0.59598154f,
    0.55350709f, 0.51405972f, 0.47742370f, 0.44339865f, 0.41179851f, 0.38245043f, 0.35519394f, 0.32987997f,
    0.30637008f, 0.28453568f, 0.26425737f, 0.24542427f, 0.22793336f, 0.21168900f, 0.19660234f, 0.18259089f,
    0.16957800f, 0.15749252f, 0.14626834f, 0.13584408f, 0.12616274f, 0.11717137f, 0.10882080f, 0.10106535f,
    0.09386262f, 0.08717322f, 0.08096056f, 0.07519066f, 0.06983197f, 0.06485518f, 0.06023308f, 0.05594039f,
    0.05195362f, 0.04825099f, 0.04481224f, 0.04161856f, 0.03865249f, 0.03589780f, 0.03333944f, 0.03096340f,
    0.02875670f, 0.02670727f, 0.02480390f, 0.02303617f, 0.02139443f, 0.01986969f, 0.01845361f, 0.01713846f,
    0.01591704f, 0.01478266f, 0.01372913f, 0.01275068f, 0.01184197f, 0.01099801f, 0.01021421f, 0.00948626f,
    0.00881019f, 0.00818231f, 0.00759917f, 0.00705759f, 0.00655461f, 0.00608748f, 0.00565364f, 0.00525071f,
    0.00487650f, 0.00452897f, 0.00420620f, 0.00390643f, 0.00362802f, 0.00336946f, 0.00312933f, 0.00290631f,
    0.00269918f, 0.00250681f, 0.00232816f, 0.00216224f, 0.00200814f, 0.00186502f, 0.00173211f, 0.00160866f,
    0.00149402f, 0.00138754f, 0.00128865f, 0.00119681f, 0.00111152f, 0.00103230f, 0.00095873f, 0.00089041f,
    0.00082695f, 0.00076801f, 0.00071328f, 0.00066244f, 0.00061523f, 0.00057139f, 0.00053067f, 0.00049285f,
    0.00045772f, 0.00042510f, 0.00039480f, 0.00036667f, 0.00034054f, 0.00031627f, 0.00029373f, 0.00027279f,
    0.00025335f, 0.00023530f, 0.00021853f, 0.00020295f, 0.00018849f, 0.00017506f, 0.00016258f, 0.00015099f,
    0.00014023f, 0.00013024f, 0.00012096f, 0.00011234f, 0.00010433f, 0.00009689f, 0.00008999f, 0.00008358f
};

extern s32* AU_FX_CUSTOM_PARAMS[0]; // points to 80078290

SHIFT_BSS void (*CurrentSeqCmdHandler)(BGMPlayer*, BGMPlayerTrack*);
SHIFT_BSS void (*CurrentSefCmdHandler)(SoundManager*, SoundPlayer*);

void au_sfx_init(SoundManager* manager, u8 priority, u8 busId, AuGlobals* globals, u8 minVoiceIdx) {
    u32 i;
    s32 c = 434782;

    manager->globals = globals;
    manager->nextUpdateStep = 312500;
    manager->nextUpdateCounter = c;
    manager->nextUpdateInterval = c;
    manager->priority = priority;
    manager->busId = busId;

    if (minVoiceIdx > 16) {
        manager->sfxPlayerSelector = 16;
    } else {
        manager->sfxPlayerSelector = minVoiceIdx;
    }

    manager->busVolume = 0x8000;
    manager->baseVolume = 0x8000;
    manager->playCounter = 0;
    manager->randomValue = 0;

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        SoundPlayer* player = &manager->players[i];

        player->sefDataReadPos = NULL;
        player->sfxVolume = 0;
        player->delay = 0;
        player->playLength = 0;
        player->coarseTune = 0;
        player->fineTune = 0;
        player->sfxPan = 0;
        player->reverb = 0;
        player->instrumentIndex = 0;
        player->envelopePreset = 0;
        player->playVelocity = 0;
        player->exclusiveID = 0;
        player->cmdList_mode2[0] = 0;
        player->cmdList_mode2[1] = 0;
        player->cmdList_mode2[2] = 0;
        player->cmdList_mode2[3] = 64; // default pan
        player->cmdList_mode2[4] = 0;
        player->cmdList_mode2[5] = 0x80 + 48; // default tune, higher bit is meaningless
        player->cmdList_mode2[6] = 0;
        player->cmdList_mode2[7] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(manager->bgmSounds); i++) {
        manager->bgmSounds[i].s32 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(manager->customCmdList); i++) {
        manager->customCmdList[i].data[0] = 0;
    }

    manager->resetPending = FALSE;
    au_sfx_set_state(manager, SND_MANAGER_STATE_ENABLED);
    au_sfx_clear_queue(manager);
    au_fade_init(&manager->fadeInfo, 0, 0x7FFF, 0x7FFF);
    au_fade_set_volume(manager->busId, manager->fadeInfo.curVolume.u16, manager->busVolume);
    manager->lastCustomEffectIdx = 0xFF;

    manager->customReverbParams[0] = CUSTOM_SMALL_ROOM_PARAMS;
    manager->customReverbParams[1] = CUSTOM_ECHO_PARAMS_1;
    manager->customReverbParams[2] = CUSTOM_ECHO_PARAMS_2;
    manager->customReverbParams[3] = CUSTOM_ECHO_PARAMS_3;
    manager->customReverbParams[4] = CUSTOM_ECHO_PARAMS_3;
    manager->customReverbParams[5] = CUSTOM_ECHO_PARAMS_3;
    manager->customReverbParams[6] = CUSTOM_ECHO_PARAMS_3;
    manager->customReverbParams[7] = CUSTOM_ECHO_PARAMS_3;

    manager->customReverbAmounts[0] = 0x10;
    manager->customReverbAmounts[1] = 0x20;
    manager->customReverbAmounts[2] = 0x20;
    manager->customReverbAmounts[3] = 0x20;
    manager->customReverbAmounts[4] = 0x20;
    manager->customReverbAmounts[5] = 0x30;
    manager->customReverbAmounts[6] = 0x40;
    manager->customReverbAmounts[7] = 0x50;

    au_sfx_set_reverb_type(manager, 0);
}

void au_sfx_load_groups_from_SEF(SoundManager* manager) {
    SEFHeader* sefData = manager->globals->dataSEF;
    s32 sections = ARRAY_COUNT(sefData->sections);
    u32 i;

    manager->sefData = (u8*)sefData;

    for (i = 0; i < sections; i++) {
        if (sefData->sections[i] != 0) {
            manager->normalSounds[i] = AU_FILE_RELATIVE(sefData, sefData->sections[i]);
        }
    }

    if (sefData->hasExtraSection == 1) {
        if (sefData->section2000 != 0) {
            manager->extraSounds = AU_FILE_RELATIVE(sefData, sefData->section2000);
        }
    }
}

void au_sfx_clear_queue(SoundManager* manager) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->soundQueue); i++) {
        manager->soundQueue[i].soundID = 0;
        manager->soundQueue[i].upperSoundID = 0;
        manager->soundQueue[i].volume = 0;
        manager->soundQueue[i].pitchShift = 0;
        manager->soundQueue[i].pan = 0;
    }

    manager->unk_165 = 0;
    manager->sfxQueueNextPos = 0;
    manager->sfxQueuePosOffset = 0;
    manager->unk_162 = 0;
}

void au_sfx_enqueue_event(SoundManager* manager, u32 soundID, s16 volume, s16 pitchShift, u8 pan) {
    u32 queuePos = manager->sfxQueueNextPos;
    s32 queueAmt = manager->sfxQueueNextPos - manager->sfxQueuePosOffset;

    if (queueAmt < 0) {
        queueAmt += 16;
    }

    if (queueAmt < 16) {
        u32 queueNextPos = queuePos;

        manager->soundQueue[queueNextPos].soundID = soundID & (SOUND_ID_LOWER | SOUND_ID_STOP | SOUND_ID_ADJUST | SOUND_ID_TRIGGER_MASK);
        manager->soundQueue[queueNextPos].upperSoundID = ((soundID >> 0x10) & 0x3FF);
        manager->soundQueue[queueNextPos].volume = volume;
        manager->soundQueue[queueNextPos].pitchShift = pitchShift;
        manager->soundQueue[queueNextPos].pan = pan;

        queueNextPos++;
        if (queueNextPos >= 16) {
            queueNextPos = 0;
        }

        manager->sfxQueueNextPos = queueNextPos;
    }
}

void au_sfx_update_main(SoundManager* manager) {
    SoundSFXEntry newEntry;
    SoundSFXEntry* sfxEntry;
    u32 i, j, k;
    s32 count;

    manager->playCounter++;
    if (manager->resetPending) {
        au_sfx_reset_players(manager);
        manager->resetPending = FALSE;
    }

    // sounds started by special seq command FF-05
    for (i = 0; i < ARRAY_COUNT(manager->bgmSounds); i++) {
        k = manager->bgmSounds[i].unk_0;
        if (k == 0) {
            // do nothing
        } else if (k < 2) {
            AlUnkGemini* unkData = &D_80078370[k-1];
            u16 sound2 = unkData->sound2;
            if (sound2 != 0) {
                for (j = 0; j < ARRAY_COUNT(manager->players); j++) {
                    if (manager->players[j].curSoundID == sound2) {
                        newEntry.soundID = unkData->sound1;
                        newEntry.upperSoundID = 0;
                        newEntry.pitchShift = 0;
                        if ((unkData->flags & 1) && (manager->bgmSounds[i].volume != 0)) {
                            newEntry.volume = (manager->bgmSounds[i].volume << 8) + 0xFF;
                        } else {
                            newEntry.volume = 0;
                        }
                        newEntry.pan = 0;
                        au_sfx_load_sound(manager, &newEntry, NULL);
                        break;
                    }
                }
            } else {
                newEntry.soundID = unkData->sound1;
                newEntry.upperSoundID = 0;
                newEntry.volume = 0;
                newEntry.pitchShift = 0;
                newEntry.pan = 0;
                au_sfx_load_sound(manager, &newEntry, NULL);
            }
        }
        manager->bgmSounds[i].s32 = 0;
    }

    // sounds started from sef command 17
    for (i = 0; i < ARRAY_COUNT(manager->customCmdList); i++) {
        if (manager->customCmdList[i].data[0] != 0) {
            newEntry.soundID = 1;
            newEntry.upperSoundID = 0;
            newEntry.volume = 0;
            newEntry.pitchShift = 0;
            newEntry.pan = 0;
            au_sfx_load_sound(manager, &newEntry, &manager->customCmdList[i]);
        }
        manager->customCmdList[i].data[0] = 0;
    }

    count = manager->sfxQueueNextPos - manager->sfxQueuePosOffset;
    if (count < 0) {
        count += ARRAY_COUNT(manager->soundQueue);
    }
    j = manager->sfxQueuePosOffset;
    if (count > 0 && count < ARRAY_COUNT(manager->soundQueue)) {
        for (i = 0; i < count; i++) {
            sfxEntry = &manager->soundQueue[j];
            if (sfxEntry->soundID & SOUND_ID_LOWER) {
                if (sfxEntry->soundID & SOUND_ID_STOP) {
                    au_sfx_stop_by_id(manager, sfxEntry->soundID);
                } else if (!(sfxEntry->soundID & (SOUND_ID_ADJUST | SOUND_ID_TRIGGER_MASK))) {
                    au_sfx_load_sound(manager, sfxEntry, NULL);
                } else {
                    if (sfxEntry->soundID & SOUND_ID_TRIGGER_MASK) {
                        au_sfx_set_triggers(manager, sfxEntry->soundID);
                    }
                    if (sfxEntry->soundID & SOUND_ID_ADJUST) {
                        au_sfx_set_modifiers(manager, sfxEntry);
                    }
                }
            }
            sfxEntry->soundID = SOUND_NONE;

            j++;
            if (j >= ARRAY_COUNT(manager->soundQueue)) {
                j = 0;
            }
        }
        manager->sfxQueuePosOffset = manager->sfxQueueNextPos;
    }
}

// also affects ambience because it uses same fx bus
s32 au_sfx_set_reverb_type(SoundManager* manager, s32 arg1) {
    s32 customIdx = (u8) arg1;

    if (customIdx != 0xF0) {
        if (customIdx < ARRAY_COUNT(manager->customReverbParams)) {
            if (manager->lastCustomEffectIdx != customIdx) {
                manager->lastCustomEffectIdx = customIdx;
                manager->globals->effectChanges[FX_BUS_SOUND].type = AU_FX_CUSTOM_0;
                manager->globals->effectChanges[FX_BUS_SOUND].changed = TRUE;
                AU_FX_CUSTOM_PARAMS[0] = manager->customReverbParams[customIdx];
            }
            manager->defaultReverbAmt = manager->customReverbAmounts[customIdx];
        } else {
            manager->lastCustomEffectIdx = 0xFF;
            manager->defaultReverbAmt = 0;
        }
    }
    return manager->lastCustomEffectIdx;
}

void au_sfx_set_state(SoundManager* manager, s32 state) {
    if (state == SND_MANAGER_STATE_ENABLED) {
        manager->state = SND_MANAGER_STATE_ENABLED;
    } else if (state == SND_MANAGER_STATE_DISABLED) {
        manager->state = SND_MANAGER_STATE_DISABLED;
    }
}

void au_sfx_load_sound(SoundManager* manager, SoundSFXEntry* entry, SoundManagerCustomCmdList* customSEF) {
    SoundPlayer* player;
    s32 playerIndex;
    u16* cmdList;
    s32 trackCount;
    s32 foundPlayer = FALSE;
    u32 exclusiveID;
    s32 sectionIndex;
    u16 soundInfo;
    u32 priority, polyphonyMode, useSpecificPlayerMode;
    s32 v1;
    s32* normalSounds;

    #define NEXT_CMD trackCount--; if (trackCount <= 0 ) { break; } cmdList += 2;

    u32 soundIndex = (entry->soundID - 1) & 0xFF;
    u16 soundIDLower = entry->soundID & SOUND_ID_LOWER;
    u16 soundID = entry->soundID;

    if (soundID & SOUND_ID_UNK) {
        // sound from extra section
        soundIndex = (entry->soundID - 1) & SOUND_ID_UNK_INDEX_MASK;
        if (soundIndex < 0x140) {
            cmdList = (u16*)&manager->extraSounds[soundIndex];
            if (*cmdList != 0) {
                // check if any player is playing this sound
                for (playerIndex = 7; playerIndex >= 0; playerIndex--) {
                    player = &manager->players[playerIndex];
                    if (player->curSoundID == soundIDLower) {
                        foundPlayer = TRUE;
                        break;
                    }
                }

                if (!foundPlayer) {
                    //find free player
                    for (playerIndex = 7; playerIndex >= 0; playerIndex--) {
                        player = &manager->players[playerIndex];
                        if (player->sefDataReadPos == NULL) {
                            foundPlayer = TRUE;
                            break;
                        }
                    }
                }

                if (foundPlayer) {
                    au_sfx_play_sound(manager, player, (s8*)cmdList, entry, 0, 0);
                }
            }
        }
    } else {
        if (soundIndex >= 0xC0) {
            if (customSEF != NULL) {
                cmdList = (u16*)customSEF;
            } else {
                sectionIndex = ((soundIDLower - 1) >> 8) + 4;
                normalSounds = manager->normalSounds[sectionIndex];
                v1 = soundIndex - 0xC0;
                cmdList = (u16*)&manager->normalSounds[sectionIndex][v1];
            }

            if (*cmdList != 0) {
                // check if any player is playing this sound
                for (playerIndex = 7; playerIndex >= 0; playerIndex--) {
                    player = &manager->players[playerIndex];
                    if (player->curSoundID == soundIDLower) {
                        foundPlayer = TRUE;
                        break;
                    }
                }

                if (!foundPlayer) {
                    //find free player
                    for (playerIndex = 7; playerIndex >= 0; playerIndex--) {
                        player = &manager->players[playerIndex];
                        if (player->sefDataReadPos == NULL) {
                            foundPlayer = TRUE;
                            break;
                        }
                    }
                }

                if (foundPlayer) {
                    au_sfx_play_sound(manager, player, (u8*)cmdList, entry, 0, 0);
                }
            }
        } else {
            if (customSEF != NULL) {
                cmdList = (u16*)customSEF;
            } else {
                sectionIndex = ((soundID) >> 8) & 3;
                cmdList = (u16*)&manager->normalSounds[sectionIndex][soundIndex];
            }

            if (*cmdList != 0) {
                // read sound info chunk
                soundInfo = cmdList[1];

                priority = (soundInfo & 0x300) >> 8; // bits 8, 9
                polyphonyMode = (soundInfo & 0x60) >> 5; // bits 5, 6,
                useSpecificPlayerMode = soundInfo;
                useSpecificPlayerMode = (useSpecificPlayerMode & 0x80) >> 7; // bit 7

                if (polyphonyMode == 0) {
                    if (entry->upperSoundID != 0) {
                        for (playerIndex = 0; playerIndex < 8; playerIndex++) {
                            player = &manager->players[playerIndex];
                            if (player->curSoundID == entry->upperSoundID) {
                                foundPlayer = TRUE;
                                break;
                            }
                        }
                    }

                    if (useSpecificPlayerMode == 0) {
                        if (!foundPlayer) {
                            playerIndex = soundInfo & 0x7;
                            player = &manager->players[playerIndex];
                            if (player->sefDataReadPos == NULL || priority >= player->priority) {
                                au_sfx_play_sound(manager, player, AU_FILE_RELATIVE(manager->sefData, *cmdList), entry, priority, 0);
                            }
                            return;
                        }
                    }

                    if (!foundPlayer) {
                        // lower 4 bits of soundInfo: max playerIndex
                        // check if any player is playing this sound
                        for (playerIndex = soundInfo & 0x7; playerIndex >= 0; playerIndex--) {
                            player = &manager->players[playerIndex];
                            if (player->curSoundID == soundIDLower) {
                                foundPlayer = TRUE;
                                break;
                            }
                        }
                    }

                    if (!foundPlayer) {
                        // find free player
                        for (playerIndex = soundInfo & 0x7; playerIndex >= 0; playerIndex--) {
                            player = &manager->players[playerIndex];
                            if (player->sefDataReadPos == NULL) {
                                foundPlayer = TRUE;
                                break;
                            }
                        }
                    }

                    if (!foundPlayer) {
                        // if there is no free player try stealing one with lower priority
                        for (playerIndex = soundInfo & 0x7; playerIndex >= 0; playerIndex--) {
                            player = &manager->players[playerIndex];
                            if (player->priority < priority) {
                                foundPlayer = TRUE;
                                break;
                            }
                        }
                    }

                    if (!foundPlayer) {
                        playerIndex = soundInfo & 0x7;
                        player = &manager->players[playerIndex];
                        if (player->priority <= priority) {
                            foundPlayer = TRUE;
                        }
                    }

                    if (foundPlayer) {
                        au_sfx_play_sound(manager, player, AU_FILE_RELATIVE(manager->sefData, *cmdList), entry, priority, 0);
                    }
                } else {
                    cmdList = AU_FILE_RELATIVE(manager->sefData, *cmdList);
                    exclusiveID = (soundInfo & 0x1800) >> 11; // bits 11, 12
                    if (exclusiveID != 0) {
                        au_sfx_stop_by_exlusive_id(manager, exclusiveID);
                    } else {
                        au_sfx_stop_by_id(manager, entry->soundID);
                    }

                    trackCount = 2 << (polyphonyMode - 1); // 2 or 4 or 8

                    if (useSpecificPlayerMode != 0) {
                        for (playerIndex = 7; playerIndex >= 0; playerIndex--) {
                            if (*cmdList != 0) {
                                // first check the players that were stopped just now
                                player = &manager->players[playerIndex];
                                if (player->sefDataReadPos == BlankSEFData) {
                                    au_sfx_play_sound(manager, player, AU_FILE_RELATIVE(manager->sefData, *cmdList), entry, priority, exclusiveID);
                                    NEXT_CMD;
                                }
                            } else {
                                NEXT_CMD;
                            }

                        }

                        if (trackCount != 0) {
                            for (playerIndex = 7; playerIndex >= 0;){
                                if (*cmdList != 0) {
                                    // then check any free players
                                    player = &manager->players[playerIndex];
                                    if (player->sefDataReadPos == NULL) {
                                        au_sfx_play_sound(manager, player, AU_FILE_RELATIVE(manager->sefData, *cmdList), entry, priority, exclusiveID);
                                        NEXT_CMD;
                                    }
                                    playerIndex--;
                                } else {
                                    NEXT_CMD;
                                }
                            }
                        }

                        if (trackCount != 0) {
                            for (playerIndex = 7; playerIndex >= 0; playerIndex--) {
                                if (*cmdList != 0) {
                                    // then try to steal
                                    player = &manager->players[playerIndex];
                                    if (exclusiveID > player->exclusiveID && priority >= player->priority) {
                                        au_sfx_play_sound(manager, player, AU_FILE_RELATIVE(manager->sefData, *cmdList), entry, priority, exclusiveID);
                                        NEXT_CMD;
                                    }
                                } else {
                                    NEXT_CMD;
                                }
                            }
                        }
                    } else {
                        s32 i;
                        for (i = 0; i < trackCount; i++) {
                            if (*cmdList != 0) {
                                soundInfo = cmdList[1];
                                playerIndex = soundInfo & 7;
                                player = &manager->players[playerIndex];
                                priority = (soundInfo & 0x300) >> 8; // bits 8, 9
                                if (player->sefDataReadPos == NULL || priority >= player->priority) {
                                    au_sfx_play_sound(manager, player, AU_FILE_RELATIVE(manager->sefData, *cmdList), entry, priority, exclusiveID);
                                }
                                cmdList += 2;
                            }
                        }
                    }
                }
            }
        }
    }
    #undef NEXT_CMD
}

static void au_sfx_play_sound(SoundManager* manager, SoundPlayer* player, s8* readPos, SoundSFXEntry* sfxEntry, s32 priority, s32 exclusiveID) {
    if (manager->state == SND_MANAGER_STATE_ENABLED) {
        player->sefDataReadPos = readPos;
        player->sefReadStart = readPos;
        player->sfxInstrumentRef = manager->globals->defaultInstrument;
        player->sfxPan = 0x40;
        player->sfxVolume = 0x7FFF;
        player->alternativeVolume = 0x7FFF;
        player->reverb = 0;
        player->instrumentIndex = 0;
        player->envelopePreset = 0;
        player->playVelocity = 0x7F;
        player->coarseTune = 0;
        player->fineTune = 0;
        player->loopStartPos = NULL;
        player->loopIterCount = 0;
        player->delay = 1;
        player->playLength = 0;
        player->curSoundID = sfxEntry->soundID & SOUND_ID_LOWER;
        player->priority = priority;
        player->exclusiveID = exclusiveID;
        player->envelopCustomPressProfile = NULL;
        player->changed.all = 0;
        player->unk_A0 = 0;
        player->randomPitch = 0;
        player->randomVelocity = 0;
        player->unk_A3 = 0;
        player->volumeLerp.current = 0x7FFFFFFF;
        player->volumeLerp.time = 0;
        player->volumeLerp.step = 0;
        player->volumeLerp.goal = 0;
        player->tuneLerp.current = 0;
        player->tuneLerp.time = 0;
        player->tuneLerp.step = 0;
        player->tuneLerp.goal = 0;
        player->alternativeDataPos = NULL;
        player->alternativeType = 0;
        player->triggers = 0;
        player->sfxParamsFlags = *player->sefDataReadPos++;
        switch (player->sfxParamsFlags & SFX_PARAM_FLAG_MODE) {
            case SFX_PARAM_MODE_ADVANCED:
                player->state = SND_PLAYER_STATE_INIT;
                break;
            case SFX_PARAM_MODE_SEQUENCE:
                player->state = SND_PLAYER_STATE_INIT;
                break;
            case SFX_PARAM_MODE_BASIC:
                player->sfxParamsFlags = (player->sfxParamsFlags & ~SFX_PARAM_FLAG_MODE) | SFX_PARAM_MODE_ADVANCED;
                player->state = SND_PLAYER_STATE_INIT;
                player->cmdList_mode2[0] = player->sefDataReadPos[0]; // instrument bank
                player->cmdList_mode2[1] = player->sefDataReadPos[1]; // instrument patch
                // volume and random pitch may overlap
                player->cmdList_mode2[2] = (player->sefDataReadPos[2] >> 1) | 3; // volume
                player->cmdList_mode2[6] = player->sefDataReadPos[2] & 7; // random pitch
                player->sefDataReadPos = player->cmdList_mode2;
                break;
        }
        au_sfx_set_player_modifiers(player, sfxEntry);
    }
}

static void au_sfx_set_triggers(SoundManager* manager, u32 soundID) {
    s32 triggers = (soundID & SOUND_ID_TRIGGER_MASK) >> 0xA;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        SoundPlayer* player = &manager->players[i];
        if (player->curSoundID == (soundID & SOUND_ID_LOWER)) {
            player->triggers = triggers;
        }
    }
}

static void au_sfx_stop_by_id(SoundManager* manager, u32 soundID) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        SoundPlayer* player = &manager->players[i];
        if (player->curSoundID == (soundID & SOUND_ID_LOWER)) {
            player->sefDataReadPos = BlankSEFData;
            player->alternativeDataPos = NULL;
            player->sfxParamsFlags = SFX_PARAM_MODE_SEQUENCE;
            player->state = SND_PLAYER_STATE_CONTINUE;
            player->delay = 1;
            player->priority = 0;
            player->exclusiveID = 0;
        }
    }
}

static void au_sfx_stop_by_exlusive_id(SoundManager* manager, u32 exclusiveID) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        SoundPlayer* player = &manager->players[i];
        if (exclusiveID == player->exclusiveID) {
            player->sefDataReadPos = BlankSEFData;
            player->alternativeDataPos = NULL;
            player->sfxParamsFlags = SFX_PARAM_MODE_SEQUENCE;
            player->state = SND_PLAYER_STATE_CONTINUE;
            player->delay = 1;
            player->priority = 0;
            player->exclusiveID = 0;
        }
    }
}

static void au_sfx_set_modifiers(SoundManager* manager, SoundSFXEntry* sfxEntry) {
    s32 soundID = sfxEntry->soundID & SOUND_ID_LOWER;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        SoundPlayer* player = &manager->players[i];
        if (player->curSoundID == soundID) {
            au_sfx_set_player_modifiers(player, sfxEntry);
        }
    }
}

static void au_sfx_set_player_modifiers(SoundPlayer* player, SoundSFXEntry* sfxEntry) {
    if (player->sfxParamsFlags & SFX_PARAM_FLAG_VOLUME) {
        player->masterVolume = 0;
    } else {
        player->masterVolume = sfxEntry->volume;
        player->changed.volume = TRUE;
    }
    if (player->sfxParamsFlags & SFX_PARAM_FLAG_PAN) {
        player->masterPan = 0;
    } else {
        player->masterPan = sfxEntry->pan;
        player->changed.pan = TRUE;
    }
    if (player->sfxParamsFlags & SFX_PARAM_FLAG_PITCH) {
        player->masterPitchShift = 0;
    } else {
        player->masterPitchShift = sfxEntry->pitchShift;
        player->changed.tune = TRUE;
    }
}

s16 au_sfx_manager_update(SoundManager* manager) {
    SoundPlayer* player;
    AuVoice* voice;
    u32 start;
    u8 end;
    u8 i;

    // update pseudorandom number with fast 'good enough' method
    manager->randomValue = (u16)manager->randomValue + (u16)manager->playCounter;

    start = manager->sfxPlayerSelector;
    for (i = start, end = start + 8; i < end; i++) {
        player = &manager->players[i - manager->sfxPlayerSelector];
        if (player->sefDataReadPos != NULL) {
            voice = &manager->globals->voices[i];
            manager->curVoice = voice;
            if (voice->priority <= manager->priority) {
                manager->curVoiceIndex = i;
                switch (player->sfxParamsFlags & SFX_PARAM_FLAG_MODE) {
                    case SFX_PARAM_MODE_ADVANCED:
                        au_sfx_update_basic(manager, player, voice, i);
                        break;
                    case SFX_PARAM_MODE_SEQUENCE:
                        au_sfx_update_sequence(manager, player, voice, i);
                        break;
                    case SFX_PARAM_MODE_BASIC:
                        break;
                }
            } else {
                player->sefDataReadPos = NULL;
                player->curSoundID = 0;
                player->priority = 0;
            }
        }
    }
    return 0;
}

static void au_sfx_update_basic(SoundManager* manager, SoundPlayer* player, AuVoice* voice, u8 voiceIdx) {
    s16 volume;
    s32 tune;
    s32 pan;
    s32 a;
    s32 b;

    switch (player->state) {
        case SND_PLAYER_STATE_CONTINUE:
            if (voice->priority != manager->priority) {
                player->sefDataReadPos = NULL;
                player->curSoundID = 0;
                player->priority = 0;
            } else {
                if (!(player->sfxParamsFlags & SFX_PARAM_FLAG_PITCH)) {
                    player->pitchRatio = au_compute_pitch_ratio(
                        ((player->tuneLerp.current >> 0x10) - player->sfxInstrumentRef->keyBase) + player->masterPitchShift) * player->sfxInstrumentRef->pitchRatio;
                    if (voice->pitchRatio != player->pitchRatio) {
                        voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
                        voice->pitchRatio = player->pitchRatio;
                    }
                }

                if (!(player->sfxParamsFlags & SFX_PARAM_FLAG_PAN) && player->masterPan != 0) {
                    pan = player->masterPan;
                } else {
                    pan = player->sfxPan;
                }
                if (voice->pan != pan) {
                    voice->pan = pan;
                    voice->syncFlags |= AU_VOICE_SYNC_FLAG_PAN_FXMIX;
                 }

                volume = au_sfx_get_scaled_volume(manager, player);
                if (voice->clientVolume != volume) {
                    voice->clientVolume = volume;
                    voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
                }
            }
            break;
        case SND_PLAYER_STATE_INIT:
            au_SEFCmd_02_SetInstrument(manager, player); // 2 bytes
            au_SEFCmd_00_SetVolume(manager, player);     // 1 byte
            au_SEFCmd_01_SetPan(manager, player);        // 1 byte
            au_SEFCmd_03_SetReverb(manager, player);     // 1 byte
            a = (*player->sefDataReadPos++ & 0x7F);      // 1 byte
            b = (*player->sefDataReadPos & 0xF) << 3;    // 1 byte
            tune = a * 100;
            player->randomPitch = b;
            if (player->randomPitch != 0) {
                player->tuneLerp.current = au_sfx_get_random_pitch(manager->randomValue, player->randomPitch, tune) << 0x10;
            } else {
                player->tuneLerp.current = tune << 0x10;
            }
            if (player->sfxParamsFlags & SFX_PARAM_FLAG_PITCH) {
                tune = (player->tuneLerp.current >> 0x10) - player->sfxInstrumentRef->keyBase;
            } else {
                tune = ((player->tuneLerp.current >> 0x10) - player->sfxInstrumentRef->keyBase) + player->masterPitchShift;
            }
            player->pitchRatio = au_compute_pitch_ratio(tune) * player->sfxInstrumentRef->pitchRatio;
            if (voice->priority <= manager->priority) {
                au_reset_nonfree_voice(voice, voiceIdx);
                if (!(player->sfxParamsFlags & SFX_PARAM_FLAG_PAN) && player->masterPan != 0) {
                    voice->pan = player->masterPan;
                } else {
                    voice->pan = player->sfxPan;
                }

                voice->reverb = player->reverb;
                voice->clientVolume = au_sfx_get_scaled_volume(manager, player);
                voice->envelope.cmdListPress = player->envelope.cmdListPress;
                voice->envelope.cmdListRelease = player->envelope.cmdListRelease;
                voice->instrument = player->sfxInstrumentRef;
                voice->pitchRatio = player->pitchRatio;
                voice->syncFlags = AU_VOICE_SYNC_FLAG_ALL;
                voice->priority = manager->priority;
                voice->clientPriority = voice->priority;
                voice->busId = manager->busId;
            }
            player->state = SND_PLAYER_STATE_CONTINUE;
            break;
        default:
            player->sefDataReadPos = NULL;
            player->curSoundID = 0;
            player->priority = 0;
            break;
    }
}

static s16 au_sfx_get_scaled_volume(SoundManager* manager, SoundPlayer* player) {
    s32 outVolume;

    outVolume = (manager->baseVolume * player->sfxVolume) >> 15;
    if (!(player->sfxParamsFlags & SFX_PARAM_FLAG_VOLUME) && (player->masterVolume != 0)) {
        outVolume = (outVolume * player->masterVolume) >> 15;
    }
    return outVolume;
}

static void au_sfx_update_sequence(SoundManager* manager, SoundPlayer* player, AuVoice* voice, u8 voiceIdx) {
    s32* var_v0_3;
    s32 pitchShift;
    s32 temp_a0;
    u8 opcode;
    u32 playLength;
    s32 startedNewVoice;
    void (**CmdHandlers)(SoundManager*, SoundPlayer*);

    startedNewVoice = FALSE;
    if (player->state == SND_PLAYER_STATE_INIT) {
        player->state = SND_PLAYER_STATE_CONTINUE;
        if (voice->priority == manager->priority) {
            au_reset_voice(voice, voiceIdx);
        }
    }

    if (player->alternativeDataPos != NULL) {
        if (player->triggers == 1) {
            player->sefDataReadPos = player->alternativeDataPos;
            player->alternativeDataPos = NULL;
            player->triggers = 0;
            player->delay = 1;
        }
    }
    if (player->triggers == 2) {
        player->changed.volume = TRUE;
        player->sfxVolume = player->alternativeVolume;
    }
    player->delay--;
    while (player->delay == 0) {
        CmdHandlers = SefCmdHandlers;
        opcode = *player->sefDataReadPos++;
        if (opcode < 0x80) {
            if (opcode == 0) {
                if (voice->priority == manager->priority) {
                    au_reset_voice(voice, voiceIdx);
                }
                player->sefDataReadPos = NULL;
                player->curSoundID = 0;
                player->priority = 0;
                player->exclusiveID = 0;
                return;
            }
            if (opcode >= 0x78) {
                // long delay
                player->delay = (u8)(*player->sefDataReadPos++) + ((opcode & 7) << 8) + 0x78;
            } else {
                // short delay
                player->delay = opcode;
            }
        } else if (opcode < 0xD8) {
            // play sound
            // (opcode & 0x7F) = pitch
            if (player->randomPitch != 0) {
                player->tuneLerp.current = au_sfx_get_random_pitch(manager->randomValue, player->randomPitch, (opcode & 0x7F) * 100) << 0x10;
            } else {
                player->tuneLerp.current = ((opcode & 0x7F) * 100) << 0x10;
            }

            if (player->randomVelocity != 0) {
                player->playVelocity = au_sfx_get_random_vol(manager->randomValue, player->randomVelocity, player->sefDataReadPos[0] & 0x7F);
            } else {
                player->playVelocity = player->sefDataReadPos[0] & 0x7F;
            }

            playLength = player->sefDataReadPos[1];
            if (playLength >= 0xC0) {
                playLength = player->sefDataReadPos[2] + ((playLength & 0x3F) << 8) + 0xC0;
                player->sefDataReadPos += 3;
            } else {
                player->sefDataReadPos += 2;
            }
            player->playLength = playLength;

            if (voice->priority <= manager->priority) {
                au_reset_nonfree_voice(voice, voiceIdx);
                if ((player->sfxParamsFlags & SFX_PARAM_FLAG_PAN) || (player->masterPan == 0)) {
                    voice->pan = player->sfxPan;
                } else {
                    voice->pan = player->masterPan;
                }

                voice->reverb = player->reverb;
                snd_set_voice_volume(voice, manager, player);
                if (player->envelopCustomPressProfile == NULL) {
                    voice->envelope.cmdListPress = player->envelope.cmdListPress;
                    voice->envelope.cmdListRelease = player->envelope.cmdListRelease;
                } else {
                    voice->envelope.cmdListPress = player->envelopCustomPressProfile;
                    voice->envelope.cmdListRelease = player->envelope.cmdListRelease;
                }

                voice->instrument = player->sfxInstrumentRef;
                voice->busId = manager->busId;

                voice->priority = manager->priority;
                voice->syncFlags = AU_VOICE_SYNC_FLAG_ALL;
                startedNewVoice = TRUE;
                voice->clientPriority = manager->priority;
                player->changed.tune = TRUE;
            }
        } else {
            s32 index = opcode - 0xE0;
            CurrentSefCmdHandler = CmdHandlers[index];
            CurrentSefCmdHandler(manager, player);
        }
    }

    if (player->volumeLerp.time != 0) {
        player->volumeLerp.time--;
        if (player->volumeLerp.time != 0) {
            player->volumeLerp.current += player->volumeLerp.step;
        } else {
            player->volumeLerp.current = player->volumeLerp.goal << 0x10;
        }
        player->changed.volume = TRUE;
    }

    if (!startedNewVoice) {
        if (player->playLength != 0) {
            player->playLength--;
            if ((player->playLength == 0) && (voice->priority == manager->priority)) {
                voice->envelopeFlags |= AU_VOICE_ENV_FLAG_KEY_RELEASED;
            }
        }
        if (player->tuneLerp.time != 0) {
            player->tuneLerp.time--;
            if (player->tuneLerp.time != 0) {
                player->tuneLerp.current += player->tuneLerp.step;
            } else {
                player->tuneLerp.current = player->tuneLerp.goal << 0x10;
            }
            player->changed.tune = TRUE;
        }
        if (player->changed.pan || player->changed.reverb) {
            if ((player->sfxParamsFlags & SFX_PARAM_FLAG_PAN) || (player->masterPan == 0)) {
                voice->pan = player->sfxPan;
            } else {
                voice->pan = player->masterPan;
            }
            voice->syncFlags |= AU_VOICE_SYNC_FLAG_PAN_FXMIX;
            voice->reverb = player->reverb;
        }
    }
    if (player->changed.volume && voice->priority == manager->priority) {
        snd_set_voice_volume(voice, manager, player);
        voice->envelopeFlags |= AU_VOICE_ENV_FLAG_VOL_CHANGED;
    }
    if (player->changed.tune) {
        f32 adjustedPitchRatio;
        if (player->sfxParamsFlags & SFX_PARAM_FLAG_PITCH) {
            pitchShift = (player->coarseTune + (s16)(player->tuneLerp.current >> 0x10)) - player->sfxInstrumentRef->keyBase;
            adjustedPitchRatio = au_compute_pitch_ratio(pitchShift + player->fineTune) * player->sfxInstrumentRef->pitchRatio;
            player->pitchRatio = adjustedPitchRatio;
        } else {
            pitchShift = ((player->coarseTune + (s16)(player->tuneLerp.current >> 0x10)) - player->sfxInstrumentRef->keyBase) + player->fineTune;
            adjustedPitchRatio = au_compute_pitch_ratio(pitchShift + player->masterPitchShift) * player->sfxInstrumentRef->pitchRatio;
            player->pitchRatio = adjustedPitchRatio;
        }
        if ((voice->priority == manager->priority) && (voice->pitchRatio != adjustedPitchRatio)) {
            voice->syncFlags |= AU_VOICE_SYNC_FLAG_PITCH;
            voice->pitchRatio = player->pitchRatio;
        }
    }
    player->changed.all = 0;
}

static void snd_set_voice_volume(AuVoice* voice, SoundManager* manager, SoundPlayer* player) {
    s32 x = ((((manager->baseVolume
        * player->sfxVolume) >> 0xF)
        * player->playVelocity) >> 7)
        * (player->volumeLerp.current >> 0x10) >> 0xF;

    if (player->sfxParamsFlags & SFX_PARAM_FLAG_VOLUME || player->masterVolume == 0) {
        voice->clientVolume = x;
    } else {
        voice->clientVolume = (x * player->masterVolume) >> 0xF;
    }
}

/*
Uses bit masks:
1F00 = 0001 1111 0000 0000 -> 0001 1111
001C = 0000 0000 0001 1100 -> 1110 0000
*/
static u8 au_sfx_get_random_pan(s32 seed, s32 pan, s32 amplitude) {
    s32 tap5, tap3, parity;
    s32 lo, hi, random;
    s32 retPan;

    pan = pan & 0xFF;
    tap5 = seed >> 5;
    tap3 = seed >> 3;
    parity = (tap5 + tap3) & 1;

    lo = (seed >> 8) & 0x1F; // bitmask 0x1F00
    hi = (seed << 3) & 0xE0; // bitmask 0x001C
    random = lo + hi;

    if (parity) {
        retPan = pan + (((amplitude & 0xFF) * random) >> 8);
    } else {
        retPan = pan - (((amplitude & 0xFF) * random) >> 8);
    }
    if (retPan < 0) {
        retPan = 0;
    } else if (retPan > 0x7F) {
        retPan = 0x7F;
    }
    return retPan;
}

static void au_SEFCmd_00_SetVolume(SoundManager* manager, SoundPlayer* player) {
    player->sfxVolume = *player->sefDataReadPos++;
    if (player->sfxVolume != 0) {
        player->sfxVolume = player->sfxVolume << 8 | 0xFF;
    }
    player->changed.volume = TRUE;
}

static void au_SEFCmd_01_SetPan(SoundManager* manager, SoundPlayer* player) {
    s32 sfxPan = *player->sefDataReadPos++;

    player->changed.pan = TRUE;
    player->sfxPan = sfxPan;
}

static void au_SEFCmd_02_SetInstrument(SoundManager* manager, SoundPlayer* player) {
    AuFilePos buf = player->sefDataReadPos;
    s32 bank = buf[0];
    s32 patch = buf[1];
    player->sefDataReadPos += 2;

    player->instrumentIndex = patch;
    player->sfxInstrumentRef = au_get_instrument(manager->globals, bank, patch, &player->envelope);
}

static void au_SEFCmd_03_SetReverb(SoundManager* manager, SoundPlayer* player) {
    u8 reverb = *player->sefDataReadPos++;

    if (player->sfxParamsFlags & SFX_PARAM_FLAG_FIXED_REVERB) {
        reverb = manager->defaultReverbAmt;
    }
    player->reverb = reverb;
    player->changed.reverb = TRUE;
}

static void au_SEFCmd_04_SetEnvelope(SoundManager* manager, SoundPlayer* player) {
    Instrument* other;
    EnvelopePreset* envPreset;

    u8 envelope = *player->sefDataReadPos++;

    player->envelopePreset = envelope & 0x7F;
    other = player->sfxInstrumentRef;

    player->sfxInstrument.base = other->base;
    player->sfxInstrument.wavDataLength = other->wavDataLength;
    player->sfxInstrument.loopPredictor = other->loopPredictor;
    player->sfxInstrument.loopStart = other->loopStart;
    player->sfxInstrument.loopEnd = other->loopEnd;
    player->sfxInstrument.loopCount = other->loopCount;
    player->sfxInstrument.predictor = other->predictor;
    player->sfxInstrument.dc_bookSize = other->dc_bookSize;
    player->sfxInstrument.keyBase = other->keyBase;
    player->sfxInstrument.pitchRatio = other->pitchRatio;
    player->sfxInstrument.type = other->type;
    player->sfxInstrument.unk_25 = other->unk_25;

    player->sfxInstrument.envelopes = SFXEnvelopePresets[player->envelopePreset];
    player->sfxInstrumentRef = &player->sfxInstrument;

    envPreset = player->sfxInstrument.envelopes;
    if (envPreset != NULL && envPreset->count != 0) {
        player->envelope.cmdListPress = AU_FILE_RELATIVE(envPreset, envPreset->offsets[0].offsetPress);
        player->envelope.cmdListRelease = AU_FILE_RELATIVE(envPreset, envPreset->offsets[0].offsetRelease);
    }
}

static void au_SEFCmd_05_CoarseTune(SoundManager* manager, SoundPlayer* player) {
    player->coarseTune = (*(s8*)player->sefDataReadPos++) * 100;
}

static void au_SEFCmd_06_FineTune(SoundManager* manager, SoundPlayer* player) {
    player->fineTune = *player->sefDataReadPos++;
}

static void au_SEFCmd_07_WaitForEnd(SoundManager* manager, SoundPlayer* player) {
    if (manager->curVoice->priority == manager->priority) {
        player->delay = 2;
        player->sefDataReadPos--;
    }
}

static void au_SEFCmd_08_PitchSweep(SoundManager* manager, SoundPlayer* player) {
    s32 hi = player->sefDataReadPos[0];
    s32 lo = player->sefDataReadPos[1];
    s16 newValue = (player->sefDataReadPos[2] & 0x7F) * 100;
    s16 time = lo + (hi << 8);
    player->sefDataReadPos += 3;

    if (time <= 0) {
        time = 1;
    }

    player->tuneLerp.time = time;
    player->tuneLerp.goal = newValue;
    player->tuneLerp.step = ((newValue << 0x10) - player->tuneLerp.current) / time;
}

static void au_SEFCmd_09_StartLoop(SoundManager* manager, SoundPlayer* player) {
    s32 loopIterCount = *player->sefDataReadPos++;

    player->loopStartPos = player->sefDataReadPos;
    player->loopIterCount = loopIterCount;
}

static void au_SEFCmd_0A_EndLoop(SoundManager* manager, SoundPlayer* player) {
    if (player->loopIterCount == 0 || --player->loopIterCount != 0) {
        player->sefDataReadPos = player->loopStartPos;
    }
}

static void au_SEFCmd_0B_WaitForRelease(SoundManager* manager, SoundPlayer* player) {
    if (player->playLength != 0) {
        player->delay = 3;
        player->sefDataReadPos--;
    }
}

static void au_SEFCmd_0C_SetCurrentVolume(SoundManager* manager, SoundPlayer* player) {
    s32 vol = *player->sefDataReadPos++;

    if (vol != 0) {
        vol = (vol << 0x18) | 0xFFFFFF;
    }
    player->volumeLerp.current = vol;
    player->changed.volume = TRUE;
}

static void au_SEFCmd_0D_VolumeRamp(SoundManager* manager, SoundPlayer* player) {
    s32 hi = player->sefDataReadPos[0];
    s32 lo = player->sefDataReadPos[1];
    s32 newValue = player->sefDataReadPos[2];
    s16 time = lo + (hi << 8);
    player->sefDataReadPos += 3;

    if (newValue != 0) {
        newValue = (newValue << 8) | 0xFF;
    }
    if (time <= 0) {
        time = 1;
    }

    player->volumeLerp.time = time;
    player->volumeLerp.goal = newValue;
    player->volumeLerp.step = ((newValue << 0x10) - player->volumeLerp.current) / time;
}

static void au_SEFCmd_0E_SetAlternativeSound(SoundManager* manager, SoundPlayer* player) {
    s32 hi = player->sefDataReadPos[1];
    s32 lo = player->sefDataReadPos[2];
    AuFilePos pos = AU_FILE_RELATIVE(manager->sefData, (hi << 8) + lo);
    u8 type = player->sefDataReadPos[0];
    player->sefDataReadPos += 3;

    player->alternativeType = type;
    switch (type) {
        case 1:
            player->alternativeDataPos = pos;
            break;
        case 2:
            player->alternativeDataPos = pos;
            break;
        case 3:
            player->alternativeDataPos = pos;
            break;
        default:
            player->alternativeDataPos = NULL;
            break;
    }
}

static void au_SEFCmd_0F_Stop(SoundManager* manager, SoundPlayer* player) {
    AuVoice* voice = manager->curVoice;
    if (voice->priority == manager->priority) {
        au_reset_voice(voice, manager->curVoiceIndex);
    }
}

static void au_SEFCmd_10_Jump(SoundManager* manager, SoundPlayer* player) {
    AuFilePos buf = player->sefDataReadPos;
    player->sefReadStart = &buf[2];
    player->sefDataReadPos = AU_FILE_RELATIVE(manager->sefData, (buf[0] << 8) + buf[1]);
}

static void au_SEFCmd_11_Restart(SoundManager* manager, SoundPlayer* player) {
    player->sefDataReadPos = player->sefReadStart;
}

static void au_SEFCmd_12_NOP(SoundManager* manager, SoundPlayer* player) {
}

static void au_SEFCmd_13_SetRandomPitch(SoundManager* manager, SoundPlayer* player) {
    player->randomPitch = *player->sefDataReadPos++;
}

static void au_SEFCmd_14_SetRandomVelocity(SoundManager* manager, SoundPlayer* player) {
    player->randomVelocity = *player->sefDataReadPos++;
}

static void au_SEFCmd_15_SetUnkA3(SoundManager* manager, SoundPlayer* player) {
    player->unk_A3 = *player->sefDataReadPos++;;
}

static void au_SEFCmd_16_SetEnvelopePress(SoundManager* manager, SoundPlayer* player) {
    AuFilePos buf = player->sefDataReadPos;
    s32 offset = (buf[0] << 8) + buf[1];

    if (offset != 0) {
        player->envelopCustomPressProfile = AU_FILE_RELATIVE(manager->sefData, offset);
    } else {
        player->envelopCustomPressProfile = NULL;
    }

    player->sefDataReadPos = &buf[2];
}

static void au_SEFCmd_17_PlaySound(SoundManager* manager, SoundPlayer* player) {
    AuFilePos buf = player->sefDataReadPos;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(manager->customCmdList); i++) {
        if (manager->customCmdList[i].data[0] == 0) {
            manager->customCmdList[i].data[0] = buf[1] + (buf[0] << 8);
            manager->customCmdList[i].data[1] = buf[3] + (buf[2] << 8);
            break;
        }
    }
    player->sefDataReadPos = &buf[4];
}

static void au_SEFCmd_18_SetAlternativeVolume(SoundManager* manager, SoundPlayer* player) {
    player->alternativeVolume = *player->sefDataReadPos++;
    if (player->alternativeVolume != 0) {
        player->alternativeVolume = player->alternativeVolume << 8 | 0xFF;
    }
}

/*
Uses bit masks:
780 = 0111 1000 0000 -> 0000 1111
01E = 0000 0001 1110 -> 1111 0000
*/
static s32 au_sfx_get_random_pitch(s32 seed, s32 amplitude, s32 pitch) {
    s32 lo = (seed >> 7) & 0xF;  // bitmask 0x780
    s32 hi = (seed << 3) & 0xF0; // bitmask 0x01E
    s32 random = (lo + hi);
    s32 tap5 = (seed >> 5);
    s32 tap2 = (seed >> 2);
    s32 parity = (tap5 + tap2) & 1;

    if (parity) {
        return pitch + ((amplitude * 5 * random) >> 8);
    } else {
        return pitch - ((amplitude * 5 * random) >> 8);
    }
}

/*
Uses bit masks:
CC = 1100 1100 -> 0011 0011
13 = 0001 0011 -> 0100 1100
*/
static u8 au_sfx_get_random_vol(s32 seed, s32 amplitude, s32 volume) {
    s32 lo = (seed & 0xCC) >> 2;
    s32 hi = (seed & 0x13) << 2;
    s32 random = lo + hi;

    return volume * (0x8000 - (amplitude * random)) >> 0xF;
}

static void au_sfx_reset_players(SoundManager* manager) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->players); i++) {
        SoundPlayer* player = &manager->players[i];
        player->sefDataReadPos = BlankSEFData;
        player->alternativeDataPos = NULL;
        player->sfxParamsFlags = SFX_PARAM_MODE_SEQUENCE;
        player->state = SND_PLAYER_STATE_CONTINUE;
        player->delay = 1;
        player->priority = 0;
        player->exclusiveID = 0;
    }
}
