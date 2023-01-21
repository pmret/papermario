#ifndef _WORLD_AREA_SAM_SAM_H_
#define _WORLD_AREA_SAM_SAM_H_

enum {
    AB_SAM_0        = AreaByte(0),
    AB_SAM_1        = AreaByte(1),
    AB_SAM_2        = AreaByte(2),
    AB_SAM_3        = AreaByte(3),
    AB_SAM_4        = AreaByte(4),
    AB_SAM_5        = AreaByte(5),
    AB_SAM_6        = AreaByte(6),
    AB_SAM_7        = AreaByte(7),
    AB_SAM_8        = AreaByte(8),
    AB_SAM_9        = AreaByte(9),
    AB_SAM_A        = AreaByte(10),
    AB_SAM_B        = AreaByte(11),
    AB_SAM_C        = AreaByte(12),
    AB_SAM_D        = AreaByte(13),
    AB_SAM_E        = AreaByte(14),
    AB_SAM_F        = AreaByte(15),
};

enum {
    AF_SAM06_Snowing       = AreaFlag(1),
    AF_SAM06_LastSnowing       = AreaFlag(2),
    AF_SAM_05       = AreaFlag(5),
};

extern MapSettings sam_01_settings;
extern MapSettings sam_02_settings;
extern MapSettings sam_03_settings;
extern MapSettings sam_04_settings;
extern MapSettings sam_05_settings;
extern MapSettings sam_06_settings;
extern MapSettings sam_07_settings;
extern MapSettings sam_08_settings;
extern MapSettings sam_09_settings;
extern MapSettings sam_10_settings;
extern MapSettings sam_11_settings;
extern MapSettings sam_12_settings;

#endif
