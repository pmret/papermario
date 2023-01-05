#ifndef _WORLD_AREA_OSR_OSR_H_
#define _WORLD_AREA_OSR_OSR_H_

enum {
    AB_OSR_Unused_0     = AreaByte(0),
    AB_OSR_Unused_1     = AreaByte(1),
    AB_OSR_Unused_2     = AreaByte(2),
    AB_OSR_Unused_3     = AreaByte(3),
    AB_OSR_Unused_4     = AreaByte(4),
    AB_OSR_Unused_5     = AreaByte(5),
    AB_OSR_Unused_6     = AreaByte(6),
    AB_OSR_Unused_7     = AreaByte(7),
    AB_OSR_Unused_8     = AreaByte(8),
    AB_OSR_Unused_9     = AreaByte(9),
    AB_OSR_Unused_A     = AreaByte(10),
    AB_OSR_Unused_B     = AreaByte(11),
    AB_OSR_Unused_C     = AreaByte(12),
    AB_OSR_Unused_D     = AreaByte(13),
    AB_OSR_Unused_E     = AreaByte(14),
    AB_OSR_Unused_F     = AreaByte(15),
};

enum {
    AF_OSR_01       = AreaFlag(1),
};

extern MapSettings osr_00_settings;
extern MapSettings osr_01_settings;
extern MapSettings osr_02_settings;
extern MapSettings osr_03_settings;
extern MapSettings osr_04_settings;

s32 osr_01_map_init(void);
s32 osr_02_map_init(void);
s32 osr_03_map_init(void);
s32 osr_04_map_init(void);

#endif
