#ifndef _WORLD_AREA_HOS_HOS_H_
#define _WORLD_AREA_HOS_HOS_H_

enum {
    AB_HOS_Unused_0     = AreaByte(0),
    AB_HOS_Unused_1     = AreaByte(1),
    AB_HOS_Unused_2     = AreaByte(2),
    AB_HOS_Unused_3     = AreaByte(3),
    AB_HOS_Unused_4     = AreaByte(4),
    AB_HOS_Unused_5     = AreaByte(5),
    AB_HOS_Unused_6     = AreaByte(6),
    AB_HOS_Unused_7     = AreaByte(7),
    AB_HOS_Unused_8     = AreaByte(8),
    AB_HOS_Unused_9     = AreaByte(9),
    AB_HOS_Unused_A     = AreaByte(10),
    AB_HOS_Unused_B     = AreaByte(11),
    AB_HOS_Unused_C     = AreaByte(12),
    AB_HOS_Unused_D     = AreaByte(13),
    AB_HOS_Unused_E     = AreaByte(14),
    AB_HOS_Unused_F     = AreaByte(15),
};

enum {  
    AF_HOS06_BadgeHints         = AreaFlag(3),
    AF_HOS06_SuperBlocksHints   = AreaFlag(100),
    AF_HOS06_StarPieceHints     = AreaFlag(116),
    AF_HOS_B4                   = AreaFlag(180),
    AF_HOS06_SpokeWithMerluvlee = AreaFlag(182),
};

extern MapSettings hos_00_settings;
extern MapSettings hos_01_settings;
extern MapSettings hos_02_settings;
extern MapSettings hos_03_settings;
extern MapSettings hos_04_settings;
extern MapSettings hos_05_settings;
extern MapSettings hos_06_settings;
extern MapSettings hos_10_settings;
extern MapSettings hos_20_settings;

s32 hos_00_map_init(void);
s32 hos_10_map_init(void);

#endif
