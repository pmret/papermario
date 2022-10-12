#ifndef _WORLD_AREA_MIM_MIM_H_
#define _WORLD_AREA_MIM_MIM_H_

enum {
    AB_MIM_0        = AreaByte(0),
    AB_MIM_1        = AreaByte(1),
    AB_MIM_2        = AreaByte(2),
    AB_MIM_3        = AreaByte(3),
    AB_MIM_4        = AreaByte(4),
    AB_MIM_5        = AreaByte(5),
    AB_MIM_6        = AreaByte(6),
    AB_MIM_7        = AreaByte(7),
    AB_MIM_8        = AreaByte(8),
    AB_MIM_9        = AreaByte(9),
    AB_MIM_A        = AreaByte(10),
    AB_MIM_B        = AreaByte(11),
    AB_MIM_C        = AreaByte(12),
    AB_MIM_D        = AreaByte(13),
    AB_MIM_E        = AreaByte(14),
    AB_MIM_F        = AreaByte(15),
};

enum {
    AF_MIM_01                           = AreaFlag(1),
    AF_MIM03_Oaklie_DialogueToggle      = AreaFlag(2),
    AF_MIM04_Bulbulb_DialogueToggle     = AreaFlag(4),
    AF_MIM12_BackgroundLitUp            = AreaFlag(3),
};

extern MapSettings mim_01_settings;
extern MapSettings mim_02_settings;
extern MapSettings mim_03_settings;
extern MapSettings mim_04_settings;
extern MapSettings mim_05_settings;
extern MapSettings mim_06_settings;
extern MapSettings mim_07_settings;
extern MapSettings mim_08_settings;
extern MapSettings mim_09_settings;
extern MapSettings mim_10_settings;
extern MapSettings mim_11_settings;
extern MapSettings mim_12_settings;

#endif
