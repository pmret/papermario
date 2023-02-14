#ifndef _WORLD_AREA_KMR_KMR_H_
#define _WORLD_AREA_KMR_KMR_H_

enum {
    AB_KMR_0            = AreaByte(0),
    AB_KMR_Unused_1     = AreaByte(1),
    AB_KMR_2            = AreaByte(2),
    AB_KMR_Unused_3     = AreaByte(3),
    AB_KMR_Unused_4     = AreaByte(4),
    AB_KMR_Unused_5     = AreaByte(5),
    AB_KMR_Unused_6     = AreaByte(6),
    AB_KMR_Unused_7     = AreaByte(7),
    AB_KMR_Unused_8     = AreaByte(8),
    AB_KMR_Unused_9     = AreaByte(9),
    AB_KMR_Unused_A     = AreaByte(10),
    AB_KMR_Unused_B     = AreaByte(11),
    AB_KMR_Unused_C     = AreaByte(12),
    AB_KMR_Unused_D     = AreaByte(13),
    AB_KMR_Unused_E     = AreaByte(14),
    AB_KMR_Unused_F     = AreaByte(15),
};

enum {
    AF_KMR_04       = AreaFlag(4),
    AF_KMR_06       = AreaFlag(6),
    AF_KMR_07       = AreaFlag(7),
    AF_KMR_08       = AreaFlag(8),
    AF_KMR_09       = AreaFlag(9),
    AF_KMR_0B       = AreaFlag(11),
    AF_KMR_0C       = AreaFlag(12),
    AF_KMR_0D       = AreaFlag(13),
};

extern MapSettings kmr_00_settings;
extern MapSettings kmr_02_settings;
extern MapSettings kmr_03_settings;
extern MapSettings kmr_04_settings;
extern MapSettings kmr_05_settings;
extern MapSettings kmr_06_settings;
extern MapSettings kmr_07_settings;
extern MapSettings kmr_09_settings;
extern MapSettings kmr_10_settings;
extern MapSettings kmr_11_settings;
extern MapSettings kmr_12_settings;
extern MapSettings kmr_20_settings;
extern MapSettings kmr_21_settings;
extern MapSettings kmr_22_settings;
extern MapSettings kmr_23_settings;
extern MapSettings kmr_24_settings;
extern MapSettings kmr_30_settings;

s32 kmr_21_map_init(void);
s32 kmr_22_map_init(void);
s32 kmr_23_map_init(void);
s32 kmr_24_map_init(void);

#endif
