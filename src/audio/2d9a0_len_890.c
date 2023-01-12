#include "common.h"
#include "audio.h"

void func_800525A0(AuGlobals* globals) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AlUnkVoice* voice = &globals->voices[i];

        if (voice->unk_42 != 0) {
            au_pvoice_reset_filter(i);
            voice->unk_42 = 0;
            voice->unk_1C = NULL;
            voice->priority = AU_PRIORITY_FREE;
        }
    }
}

void func_80052614(AuGlobals* globals) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        AlUnkVoice* temp = &globals->voices[i];

        temp->unk_1C = NULL;
        temp->unk_20 = 0;
        temp->unk_24 = 0;
        temp->unk_28 = 0;
        temp->unk_3B = 0;
        temp->unk_3C = 0;
        temp->unk_flags_3D = 0;
        temp->unk_3E = 0;
        temp->unk_3F = 0x80;
    }
}

void func_80052660(AuGlobals* globals) {
    AlUnkVoice* voice;
    s8 var_a0;
    s16 unkTemp;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        voice = &globals->voices[i];
        if (voice->unk_1C == NULL) {
            continue;
        }
        if (voice->unk_flags_3D & AU_VOICE_3D_FLAG_HANDLED_VOL_CHANGE) {
            func_80052B44(voice);
            continue;
        }
        if (voice->unk_flags_3D & AU_VOICE_3D_FLAG_10) {
            voice->unk_flags_3D &= ~AU_VOICE_3D_FLAG_10;
            voice->unk_flags_3D |= AU_VOICE_3D_FLAG_1;
            voice->unk_1C = (u8*)voice->unk_14.unk_04;
            if (voice->unk_28 > AU_5750) {
                voice->unk_39 = voice->unk_39 + (s32) (voice->unk_2C * (f32) (voice->unk_24 - voice->unk_28));
            } else {
                voice->unk_39 = voice->unk_3A;
            }

            voice->unk_3B = *voice->unk_1C++;
            var_a0 = *voice->unk_1C;
            if (*(s8*)voice->unk_1C++ < 0) {
                var_a0 &= 0x7F;
                voice->unk_3E = 1;
                voice->unk_3F = voice->unk_39;
            }
            voice->unk_3A = var_a0;

            voice->unk_28 = D_800785A0[voice->unk_3B];
            voice->unk_24 = voice->unk_28;
            if (voice->unk_flags_3D & AU_VOICE_3D_FLAG_VOL_CHANGED) {
                voice->unk_flags_3D &= ~AU_VOICE_3D_FLAG_VOL_CHANGED;
                if (voice->unk_28 > AU_5750) {
                    voice->unk_28 -= AU_5750;
                    voice->unk_flags_3D |= AU_VOICE_3D_FLAG_HANDLED_VOL_CHANGE;
                    unkTemp = voice->unk_39 + (s32) (voice->unk_2C * (voice->unk_24 - voice->unk_28));
                } else {
                    unkTemp = voice->unk_3A;
                }
                voice->unk_08 = AUDIO_SAMPLES;
            } else {
                voice->unk_08 = func_80052BC0(voice->unk_24);
                unkTemp = voice->unk_3A;
            }
            voice->volume = (((unkTemp * voice->adjustedVolume * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
            voice->unk_flags_43 |= AU_VOICE_SYNC_FLAG_4;
        } else {
            if (voice->unk_28 == -1) {
                if (voice->unk_flags_3D & AU_VOICE_3D_FLAG_VOL_CHANGED) {
                    voice->unk_flags_3D &= ~AU_VOICE_3D_FLAG_VOL_CHANGED;
                    voice->volume = (((voice->unk_39 * voice->adjustedVolume * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
                    voice->unk_flags_43 |= AU_VOICE_SYNC_FLAG_4;
                }
            } else {
                voice->unk_28 -= AU_5750;
                if (voice->unk_28 <= 0) {
                    if (*voice->unk_1C == 0xFF) {
                        if (voice->unk_flags_3D & AU_VOICE_3D_FLAG_1) {
                            voice->unk_flags_3D = 0;
                            voice->unk_1C = NULL;
                            voice->unk_42 = 1;
                        } else {
                            voice->unk_28 = -1;
                            voice->unk_24 = -1;
                            voice->unk_3B = 0x3B;
                            voice->unk_08 = AUDIO_SAMPLES;
                            voice->unk_2C = 0.0f;
                            voice->unk_39 = voice->unk_3A;
                        }
                    } else {
                        voice->unk_3B = func_80052CFC(voice);
                        voice->unk_39 = voice->unk_3A;
                        voice->unk_3A = (*voice->unk_1C++) & 0x7F;
                        voice->unk_28 = D_800785A0[voice->unk_3B];
                        voice->unk_24 = voice->unk_28;
                        if (voice->unk_24 != 0) {
                            voice->unk_2C = ((f32) voice->unk_3A - (f32) voice->unk_39) / (f32) voice->unk_24;
                        } else {
                            voice->unk_2C = 0.0f;
                        }
                        if (voice->unk_flags_3D & AU_VOICE_3D_FLAG_VOL_CHANGED) {
                            voice->unk_flags_3D &= ~AU_VOICE_3D_FLAG_VOL_CHANGED;
                            if (voice->unk_28 > AU_5750) {
                                voice->unk_28 -= AU_5750;
                                voice->unk_flags_3D |= AU_VOICE_3D_FLAG_HANDLED_VOL_CHANGE;
                                unkTemp = voice->unk_39 + (s32) (voice->unk_2C * (voice->unk_24 - voice->unk_28));
                            } else {
                                unkTemp = voice->unk_3A;
                            }
                            voice->unk_08 = AUDIO_SAMPLES;
                        } else {
                            voice->unk_08 = func_80052BC0(voice->unk_24);
                            unkTemp = voice->unk_3A;
                        }
                        voice->volume = (((unkTemp * voice->adjustedVolume * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
                        voice->unk_flags_43 |= AU_VOICE_SYNC_FLAG_4;
                    }
                } else {
                    if (voice->unk_flags_3D & AU_VOICE_3D_FLAG_VOL_CHANGED) {
                        voice->unk_flags_3D &= ~AU_VOICE_3D_FLAG_VOL_CHANGED;
                        if (voice->unk_28 > AU_5750) {
                            voice->unk_28 -= AU_5750;
                            voice->unk_flags_3D |= AU_VOICE_3D_FLAG_HANDLED_VOL_CHANGE;
                            unkTemp = voice->unk_39 + (s32) (voice->unk_2C * (voice->unk_24 - voice->unk_28));
                        } else {
                            unkTemp = voice->unk_3A;
                        }
                        voice->unk_08 = AUDIO_SAMPLES;
                        voice->volume = (((unkTemp * voice->adjustedVolume * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
                        voice->unk_flags_43 |= AU_VOICE_SYNC_FLAG_4;
                    }
                }
            }
        }
    }
}

void func_80052B44(AlUnkVoice* arg0) {
    arg0->volume = (((arg0->unk_3A * arg0->adjustedVolume * arg0->unk_3F) >> 14) * arg0->unk_30) >> 7;
    arg0->unk_08 = func_80052BC0(arg0->unk_28);
    arg0->unk_flags_3D &= ~AU_VOICE_3D_FLAG_HANDLED_VOL_CHANGE;
    arg0->unk_flags_43 |= AU_VOICE_SYNC_FLAG_4;
}

s32 func_80052BC0(s32 arg0) {
    return (arg0 / AU_5750) * AUDIO_SAMPLES;
}

void func_80052BF8(AlUnkVoice* voice, AlUnkInstrumentData* arg1) {
    s32 x;

    voice->unk_14.unk_00 = arg1->unk_00;
    voice->unk_1C = voice->unk_14.unk_00;
    voice->unk_14.unk_04 = arg1->unk_04;
    voice->unk_30 = 0x80;
    voice->unk_34 = 0;

    x = func_80052CFC(voice);
    voice->unk_flags_3D = 0;
    voice->unk_39 = 0;
    voice->unk_3A = *voice->unk_1C++;
    voice->unk_3B = x;
    voice->unk_24 = D_800785A0[x];
    voice->unk_28 = voice->unk_24;

    voice->volume = (voice->unk_3A * voice->adjustedVolume * voice->unk_30) >> 14;
    voice->unk_08 = func_80052BC0(voice->unk_24);
    if (voice->unk_24 != 0) {
        voice->unk_2C = ((f32) voice->unk_3A - (f32) voice->unk_39) / voice->unk_24;
    } else {
        voice->unk_2C = 0.0f;
    }
    voice->unk_3E = 0;
    voice->unk_3F = 0x80;
}

INCLUDE_ASM(u8, "audio/2d9a0_len_890", func_80052CFC, AlUnkVoice* arg0);

void func_80052E18(AlUnkVoice* arg0) {
    arg0->unk_flags_3D |= AU_VOICE_3D_FLAG_VOL_CHANGED;
}
