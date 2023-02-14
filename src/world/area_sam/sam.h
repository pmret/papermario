#ifndef _WORLD_AREA_SAM_SAM_H_
#define _WORLD_AREA_SAM_SAM_H_

enum {
    AB_SAM_Unused_0     = AreaByte(0),
    AB_SAM_Unused_1     = AreaByte(1),
    AB_SAM_Unused_2     = AreaByte(2),
    AB_SAM_Unused_3     = AreaByte(3),
    AB_SAM_Unused_4     = AreaByte(4),
    AB_SAM_Unused_5     = AreaByte(5),
    AB_SAM_Unused_6     = AreaByte(6),
    AB_SAM_Unused_7     = AreaByte(7),
    AB_SAM_Unused_8     = AreaByte(8),
    AB_SAM_Unused_9     = AreaByte(9),
    AB_SAM_Unused_A     = AreaByte(10),
    AB_SAM_Unused_B     = AreaByte(11),
    AB_SAM_Unused_C     = AreaByte(12),
    AB_SAM_Unused_D     = AreaByte(13),
    AB_SAM_Unused_E     = AreaByte(14),
    AB_SAM_Unused_F     = AreaByte(15),
};

enum {
    AF_SAM_Snowing      = AreaFlag(1),
    AF_SAM_LastSnowing  = AreaFlag(2),
    AF_SAM_03           = AreaFlag(3),
    AF_SAM_04           = AreaFlag(4),
    AF_SAM_05           = AreaFlag(5),
    AF_SAM_06           = AreaFlag(6),
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
