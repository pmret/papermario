#ifndef _WORLD_AREA_KPA_KPA_H_
#define _WORLD_AREA_KPA_KPA_H_

enum {
    AB_KPA_Unused_0             = AreaByte(0),
    AB_KPA17_Toad1_Dialogue     = AreaByte(1),
    AB_KPA17_Toad2_Dialogue     = AreaByte(2),
    AB_KPA17_Toad3_Dialogue     = AreaByte(3),
    AB_KPA17_Toad4_Dialogue     = AreaByte(4),
    AB_KPA91_Toad2_Dialogue     = AreaByte(5),
    AB_KPA91_Toad3_Dialogue     = AreaByte(6),
    AB_KPA91_Dryite_Dialogue    = AreaByte(7),
    AB_KPA95_Toad2_Dialogue     = AreaByte(8),
    AB_KPA95_Toad3_Dialogue     = AreaByte(9),
    AB_KPA95_Penguin_Dialogue   = AreaByte(10),
    AB_KPA_MazeProgress         = AreaByte(11),
    AB_KPA82_QuizRound          = AreaByte(12),
    AB_KPA82_RightAnswers       = AreaByte(13),
    AB_KPA82_WrongAnswers       = AreaByte(14),
    AB_KPA_Unused_F             = AreaByte(15),
};

enum {
    AF_KPA08_PlatformRaised     = AreaFlag(3),
    AF_KPA09_PlatformRaised     = AreaFlag(4),
    AF_KPA13_HitSwitchA         = AreaFlag(5),
    AF_KPA13_HitSwitchB         = AreaFlag(6),
    AF_KPA16_HitSwitch          = AreaFlag(7),
    AF_KPA133_HitWaterSwitch    = AreaFlag(8),
    AF_KPA134_HitWaterSwitch    = AreaFlag(9),
};

extern MapSettings kpa_01_settings;
extern MapSettings kpa_03_settings;
extern MapSettings kpa_04_settings;
extern MapSettings kpa_08_settings;
extern MapSettings kpa_09_settings;
extern MapSettings kpa_10_settings;
extern MapSettings kpa_11_settings;
extern MapSettings kpa_12_settings;
extern MapSettings kpa_13_settings;
extern MapSettings kpa_14_settings;
extern MapSettings kpa_15_settings;
extern MapSettings kpa_16_settings;
extern MapSettings kpa_17_settings;
extern MapSettings kpa_32_settings;
extern MapSettings kpa_33_settings;
extern MapSettings kpa_40_settings;
extern MapSettings kpa_41_settings;
extern MapSettings kpa_50_settings;
extern MapSettings kpa_51_settings;
extern MapSettings kpa_52_settings;
extern MapSettings kpa_53_settings;
extern MapSettings kpa_60_settings;
extern MapSettings kpa_61_settings;
extern MapSettings kpa_62_settings;
extern MapSettings kpa_63_settings;
extern MapSettings kpa_70_settings;
extern MapSettings kpa_81_settings;
extern MapSettings kpa_82_settings;
extern MapSettings kpa_83_settings;
extern MapSettings kpa_90_settings;
extern MapSettings kpa_91_settings;
extern MapSettings kpa_94_settings;
extern MapSettings kpa_95_settings;
extern MapSettings kpa_96_settings;
extern MapSettings kpa_100_settings;
extern MapSettings kpa_101_settings;
extern MapSettings kpa_102_settings;
extern MapSettings kpa_111_settings;
extern MapSettings kpa_112_settings;
extern MapSettings kpa_113_settings;
extern MapSettings kpa_114_settings;
extern MapSettings kpa_115_settings;
extern MapSettings kpa_116_settings;
extern MapSettings kpa_117_settings;
extern MapSettings kpa_118_settings;
extern MapSettings kpa_119_settings;
extern MapSettings kpa_121_settings;
extern MapSettings kpa_130_settings;
extern MapSettings kpa_133_settings;
extern MapSettings kpa_134_settings;

s32 kpa_51_map_init(void);
s32 kpa_53_map_init(void);
s32 kpa_81_map_init(void);
s32 kpa_82_map_init(void);
s32 kpa_83_map_init(void);
s32 kpa_100_map_init(void);
s32 kpa_101_map_init(void);
s32 kpa_114_map_init(void);

#endif
