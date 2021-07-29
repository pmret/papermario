#include "common.h"
#include "audio.h"

void func_8004B440(SoundManager* manager, u8 arg1, u8 arg2, UnkAl19E0* arg3, u8 arg4) {
    u32 i;
    s32 c = 0x6A25E;

    manager->soundData = arg3;
    manager->unkCounterStep = 312500;
    manager->unkCounterMax = manager->unkCounter = c;
    manager->unk_BC = arg1;
    manager->unk_BE = arg2;

    if (arg4 > 0x10) {
        manager->sfxPlayerSelector = 0x10;
    } else {
        manager->sfxPlayerSelector = arg4;
    }

    manager->unk_5C = 0x8000;
    manager->unk_B8 = 0x8000;
    manager->playCounter = 0;
    manager->unk_60 = 0;

    for (i = 0; i < ARRAY_COUNT(manager->unk_16C); i++) {
        SoundPlayer* sub = &manager->unk_16C[i];

        sub->counter = 0;
        sub->unk_5C = 0;
        sub->unk_8E = 0;
        sub->unk_90 = 0;
        sub->unk_92 = 0;
        sub->unk_94 = 0;
        sub->unk_9B = 0;
        sub->unk_9C = 0;
        sub->unk_9D = 0;
        sub->unk_9E = 0;
        sub->unk_9F = 0;
        sub->unk_99 = 0;
        sub->locatorB = 0;
        sub->locatorC = 0;
        sub->locatorD = 0;
        sub->unk_7B = 0x40;
        sub->unk_7C = 0;
        sub->unk_7D = 0xB0;
        sub->unk_7E = 0;
        sub->unk_7F = 0;
    }

    for (i = 0; i < ARRAY_COUNT(manager->unk_90); i++) {
        manager->unk_90[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(manager->unk_A0); i++) {
        manager->unk_A0[i].x = 0;
    }

    manager->unk_168 = 0;
    func_8004BA54(manager, 0);
    snd_clear_sfx_queue(manager);
    snd_initialize_bgm_fade(&manager->unk_40, 0, 0x7FFF, 0x7FFF);
    func_80053A98(manager->unk_BE, manager->unk_40.unk_00.u16, manager->unk_5C);
    manager->unk_8C = 0xFF;

    manager->unk_64[0] = &D_80078290;
    manager->unk_64[1] = &D_800782F8;
    manager->unk_64[2] = &D_80078320;
    manager->unk_64[3] = &D_80078348;
    manager->unk_64[4] = &D_80078348;
    manager->unk_64[5] = &D_80078348;
    manager->unk_64[6] = &D_80078348;
    manager->unk_64[7] = &D_80078348;

    manager->unk_84[0] = 0x10;
    manager->unk_84[1] = 0x20;
    manager->unk_84[2] = 0x20;
    manager->unk_84[3] = 0x20;
    manager->unk_84[4] = 0x20;
    manager->unk_84[5] = 0x30;
    manager->unk_84[6] = 0x40;
    manager->unk_84[7] = 0x50;

    func_8004B9E4(manager, 0);
}

INCLUDE_ASM(void, "26840_len_20d0", snd_load_sfx_groups_from_SEF, SoundManager* manager);

void snd_clear_sfx_queue(SoundManager* manager) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(manager->unk_C2); i++) {
        manager->unk_C2[i].soundID = 0;
        manager->unk_C2[i].upperSoundID = 0;
        manager->unk_C2[i].volume = 0;
        manager->unk_C2[i].pitchShift = 0;
        manager->unk_C2[i].pan = 0;
    }

    manager->unk_165 = 0;
    manager->sfxQueueNextPos = 0;
    manager->sfxQueuePosOffset = 0;
    manager->unk_162 = 0;
}

void snd_enqueue_sfx_event(SoundManager* manager, s32 soundID, s16 volume, s16 pitchShift, u8 pan) {
    u32 queuePos = manager->sfxQueueNextPos;
    s32 queueAmt = manager->sfxQueueNextPos - manager->sfxQueuePosOffset;

    if (queueAmt < 0) {
        queueAmt += 16;
    }

    if (queueAmt < 16) {
        u32 queueNextPos = queuePos;

        manager->unk_C2[queueNextPos].soundID = soundID & 0xBFFF;
        manager->unk_C2[queueNextPos].upperSoundID = (((u32) soundID >> 0x10) & 0x3FF);
        manager->unk_C2[queueNextPos].volume = volume;
        manager->unk_C2[queueNextPos].pitchShift = pitchShift;
        manager->unk_C2[queueNextPos].pan = pan;

        queueNextPos++;
        if (queueNextPos >= 16) {
            queueNextPos = 0;
        }

        manager->sfxQueueNextPos = queueNextPos;
    }
}

INCLUDE_ASM(void, "26840_len_20d0", func_8004B748, SoundManager* manager);

s32 func_8004B9E4(SoundManager* manager, s32 arg1) {
    s32 a1 = (u8) arg1;

    if (a1 != 0xF0) {
        if (a1 < 8) {
            if (manager->unk_8C != a1) {
                manager->unk_8C = a1;
                manager->soundData->unk_40[1].unk_00 = 6;
                manager->soundData->unk_40[1].unk_01 = 1;
                D_8007F1F8 = manager->unk_64[a1];
            }
            manager->unk_8D = manager->unk_84[a1];
        } else {
            manager->unk_8C = 0xFF;
            manager->unk_8D = 0;
        }
    }
    return manager->unk_8C;
}

void func_8004BA54(SoundManager* manager, s32 arg1) {
    if (arg1 == 0) {
        manager->unk_C0 = 0;
    } else if (arg1 == 1) {
        manager->unk_C0 = 1;
    }
}

INCLUDE_ASM(s32, "26840_len_20d0", func_8004BA74);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004C0E4);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004C268);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004C2A4);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004C300);

INCLUDE_ASM(void, "26840_len_20d0", snd_set_modifiers, SoundManager* manager, SoundSFXEntry* sfxEntry);

void snd_set_player_modifiers(SoundManager* manager, SoundSFXEntry* sfxEntry);
INCLUDE_ASM(void, "26840_len_20d0", snd_set_player_modifiers, SoundManager* manager, SoundSFXEntry* sfxEntry);

INCLUDE_ASM(s16, "26840_len_20d0", func_8004C444, SoundManager* manager);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004C578);

INCLUDE_ASM(s32, "26840_len_20d0", snd_get_scaled_volume);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004C884);

INCLUDE_ASM(s32, "26840_len_20d0", snd_set_voice_volume);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004CDF8);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_00_SetVolume, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_01_SetPan, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_02_SetInstrument, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_03_SetReverb, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_04, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_05, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_06, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_07, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_08, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_09_StartLoop, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_0A_EndLoop, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_0B, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_0C, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_0D, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_0E, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_0F, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_10_Jump, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_11_Restart, SoundManager* manager, SoundPlayer* player);

void snd_SEFCmd_12_NOP(SoundManager* manager, SoundPlayer* player) {
}

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_13, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_14, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_15, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_16, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_17, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(void, "26840_len_20d0", snd_SEFCmd_18, SoundManager* manager, SoundPlayer* player);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004D428);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004D484);

INCLUDE_ASM(s32, "26840_len_20d0", func_8004D4BC);
