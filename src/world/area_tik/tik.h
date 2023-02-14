#ifndef _WORLD_AREA_TIK_TIK_H_
#define _WORLD_AREA_TIK_TIK_H_

enum {
    AB_TIK_Unused_0     = AreaByte(0),
    AB_TIK_Unused_1     = AreaByte(1),
    AB_TIK_Unused_2     = AreaByte(2),
    AB_TIK_Unused_3     = AreaByte(3),
    AB_TIK_Unused_4     = AreaByte(4),
    AB_TIK_Unused_5     = AreaByte(5),
    AB_TIK_Unused_6     = AreaByte(6),
    AB_TIK_Unused_7     = AreaByte(7),
    AB_TIK_Unused_8     = AreaByte(8),
    AB_TIK_Unused_9     = AreaByte(9),
    AB_TIK_Unused_A     = AreaByte(10),
    AB_TIK_Unused_B     = AreaByte(11),
    AB_TIK_Unused_C     = AreaByte(12),
    AB_TIK_Unused_D     = AreaByte(13),
    AB_TIK_Unused_E     = AreaByte(14),
    AB_TIK_Unused_F     = AreaByte(15),
};

enum {
    AF_TIK_02       = AreaFlag(2),
    AF_TIK_03       = AreaFlag(3),
    AF_TIK_04       = AreaFlag(4),
    AF_TIK_05       = AreaFlag(5),
};

extern MapSettings tik_01_settings;
extern MapSettings tik_02_settings;
extern MapSettings tik_03_settings;
extern MapSettings tik_04_settings;
extern MapSettings tik_05_settings;
extern MapSettings tik_06_settings;
extern MapSettings tik_07_settings;
extern MapSettings tik_08_settings;
extern MapSettings tik_09_settings;
extern MapSettings tik_10_settings;
extern MapSettings tik_12_settings;
extern MapSettings tik_14_settings;
extern MapSettings tik_15_settings;
extern MapSettings tik_17_settings;
extern MapSettings tik_18_settings;
extern MapSettings tik_19_settings;
extern MapSettings tik_20_settings;
extern MapSettings tik_21_settings;
extern MapSettings tik_22_settings;
extern MapSettings tik_23_settings;
extern MapSettings tik_24_settings;
extern MapSettings tik_25_settings;

s32 tik_24_map_init(void);

#endif
