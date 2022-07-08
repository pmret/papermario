#include "common.h"
#include "audio.h"

u8 func_80052CFC(AlUnkVoice* voice);

void func_800525A0(SndGlobals* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->voices); i++) {
        AlUnkVoice* temp = &arg0->voices[i];

        if (temp->unk_42 != 0) {
            func_80056EE8(i);
            temp->unk_42 = 0;
            temp->unk_1C = NULL;
            temp->unk_45 = 0;
        }
    }
}

void func_80052614(SndGlobals* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->voices); i++) {
        AlUnkVoice* temp = &arg0->voices[i];

        temp->unk_1C = 0;
        temp->unk_20 = 0;
        temp->unk_24 = 0;
        temp->unk_28 = 0;
        temp->unk_3B = 0;
        temp->unk_3C = 0;
        temp->unk_3D = 0;
        temp->unk_3E = 0;
        temp->unk_3F = 0x80;
    }
}

void func_80052660(SndGlobals* globals) {
    AlUnkVoice* voice;
    s8 var_a0;
    s16 unkTemp;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(globals->voices); i++) {
        voice = &globals->voices[i];
        if (voice->unk_1C == NULL) {
            continue;
        }
        if (voice->unk_3D & 2) {
            func_80052B44(voice);
            continue;
        }
        if (voice->unk_3D & 0x10) {
            voice->unk_3D &= 0xEF;
            voice->unk_3D |= 1;
            voice->unk_1C = voice->unk_18;
            if (voice->unk_28 > 5750) {
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
            
            voice->unk_28 = (&D_800785A0)[voice->unk_3B];
            voice->unk_24 = voice->unk_28;
            if (voice->unk_3D & 0x20) {
                voice->unk_3D &= 0xDF;
                if (voice->unk_28 > 5750) {
                    voice->unk_28 -= 5750;
                    voice->unk_3D |= 2;
                    unkTemp = voice->unk_39 + (s32) (voice->unk_2C * (voice->unk_24 - voice->unk_28));
                } else {
                    unkTemp = voice->unk_3A;
                }
                voice->unk_08 = AUDIO_SAMPLES;
            } else {
                voice->unk_08 = func_80052BC0(voice->unk_24);
                unkTemp = voice->unk_3A;
            }
            voice->unk_0C = (((unkTemp * voice->unk_40 * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
            voice->unk_flags_43 |= 4;
        } else {
            if (voice->unk_28 == -1) {
                if (voice->unk_3D & 0x20) {
                    voice->unk_3D &= 0xDF;
                    voice->unk_0C = (((voice->unk_39 * voice->unk_40 * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
                    voice->unk_flags_43 |= 4;
                }
            } else {
                voice->unk_28 -= 5750;
                if (voice->unk_28 <= 0) {
                    if (*voice->unk_1C == 0xFF) {
                        if (voice->unk_3D & 1) {
                            voice->unk_3D = 0;
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
                        voice->unk_28 = (&D_800785A0)[voice->unk_3B];
                        voice->unk_24 = voice->unk_28;
                        if (voice->unk_24 != 0) {
                            voice->unk_2C = ((f32) voice->unk_3A - (f32) voice->unk_39) / (f32) voice->unk_24;
                        } else {
                            voice->unk_2C = 0.0f;
                        }
                        if (voice->unk_3D & 0x20) {
                            voice->unk_3D &= 0xDF;
                            if (voice->unk_28 > 5750) {
                                voice->unk_28 -= 5750;
                                voice->unk_3D |= 2;
                                unkTemp = voice->unk_39 + (s32) (voice->unk_2C * (voice->unk_24 - voice->unk_28));
                            } else {
                                unkTemp = voice->unk_3A;
                            }
                            voice->unk_08 = AUDIO_SAMPLES;
                        } else {
                            voice->unk_08 = func_80052BC0(voice->unk_24);
                            unkTemp = voice->unk_3A;
                        }
                        voice->unk_0C = (((unkTemp * voice->unk_40 * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
                        voice->unk_flags_43 |= 4;
                    }
                } else {
                    if (voice->unk_3D & 0x20) {
                        voice->unk_3D &= 0xDF;
                        if (voice->unk_28 > 5750) {
                            voice->unk_28 -= 5750;
                            voice->unk_3D |= 2;
                            unkTemp = voice->unk_39 + (s32) (voice->unk_2C * (voice->unk_24 - voice->unk_28));
                        } else {
                            unkTemp = voice->unk_3A;
                        }
                        voice->unk_08 = AUDIO_SAMPLES;
                        voice->unk_0C = (((unkTemp * voice->unk_40 * voice->unk_3F) >> 0xE) * voice->unk_30) >> 7;
                        voice->unk_flags_43 |= 4;
                    }
                }
            }
        }
    }
}

void func_80052B44(AlUnkVoice* arg0) {
    s32 temp_lo = ((arg0->unk_3A * arg0->unk_40 * arg0->unk_3F) >> 14) * arg0->unk_30;

    arg0->unk_0C = temp_lo >> 7;
    arg0->unk_08 = func_80052BC0(arg0->unk_28);
    arg0->unk_3D &= ~0x2;
    arg0->unk_flags_43 |= 0x4;
}

s32 func_80052BC0(s32 arg0) {
    return (arg0 / 5750) * AUDIO_SAMPLES;
}

void func_80052BF8(AlUnkVoice* voice, s32* arg1) {
    s32 x;
    
    voice->unk_14 = (u8*)arg1[0];
    voice->unk_1C = voice->unk_14;
    voice->unk_18 = arg1[1];
    voice->unk_30 = 0x80;
    voice->unk_34 = 0;
    
    x = func_80052CFC(voice);
    voice->unk_3D = 0;
    voice->unk_39 = 0;
    voice->unk_3A = *voice->unk_1C++;
    voice->unk_3B = x;
    voice->unk_24 = (&D_800785A0)[x];
    voice->unk_28 = voice->unk_24;
    
    voice->unk_0C = (voice->unk_3A * voice->unk_40 * voice->unk_30) >> 14;
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
    arg0->unk_3D |= 0x20;
}
