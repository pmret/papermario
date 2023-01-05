#ifndef _WORLD_AREA_DGB_DGB_H_
#define _WORLD_AREA_DGB_DGB_H_

enum {
    AB_DGB_Unused_0     = AreaByte(0),
    AB_DGB_Unused_1     = AreaByte(1),
    AB_DGB_Unused_2     = AreaByte(2),
    AB_DGB_Unused_3     = AreaByte(3),
    AB_DGB_Unused_4     = AreaByte(4),
    AB_DGB_Unused_5     = AreaByte(5),
    AB_DGB_Unused_6     = AreaByte(6),
    AB_DGB_Unused_7     = AreaByte(7),
    AB_DGB_Unused_8     = AreaByte(8),
    AB_DGB_Unused_9     = AreaByte(9),
    AB_DGB_Unused_A     = AreaByte(10),
    AB_DGB_Unused_B     = AreaByte(11),
    AB_DGB_Unused_C     = AreaByte(12),
    AB_DGB_Unused_D     = AreaByte(13),
    AB_DGB_Unused_E     = AreaByte(14),
    AB_DGB_Unused_F     = AreaByte(15),
};

enum {
    AF_DGB_01               = AreaFlag(1),
    AF_DGB_02               = AreaFlag(2),
    AF_DGB_03               = AreaFlag(3),
    AF_DGB06_Boo_Dialogue   = AreaFlag(4),
};

extern MapSettings dgb_00_settings;
extern MapSettings dgb_01_settings;
extern MapSettings dgb_02_settings;
extern MapSettings dgb_03_settings;
extern MapSettings dgb_04_settings;
extern MapSettings dgb_05_settings;
extern MapSettings dgb_06_settings;
extern MapSettings dgb_07_settings;
extern MapSettings dgb_08_settings;
extern MapSettings dgb_09_settings;
extern MapSettings dgb_10_settings;
extern MapSettings dgb_11_settings;
extern MapSettings dgb_12_settings;
extern MapSettings dgb_13_settings;
extern MapSettings dgb_14_settings;
extern MapSettings dgb_15_settings;
extern MapSettings dgb_16_settings;
extern MapSettings dgb_17_settings;
extern MapSettings dgb_18_settings;

s32 dgb_00_map_init(void);

#endif
