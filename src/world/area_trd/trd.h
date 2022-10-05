#ifndef _WORLD_AREA_TRD_TRD_H_
#define _WORLD_AREA_TRD_TRD_H_

enum {
    AB_TRD_0        = AreaByte(0),
    AB_TRD_1        = AreaByte(1),
    AB_TRD_2        = AreaByte(2),
    AB_TRD_3        = AreaByte(3),
    AB_TRD_4        = AreaByte(4),
    AB_TRD_5        = AreaByte(5),
    AB_TRD_6        = AreaByte(6),
    AB_TRD_7        = AreaByte(7),
    AB_TRD_8        = AreaByte(8),
    AB_TRD_9        = AreaByte(9),
    AB_TRD_A        = AreaByte(10),
    AB_TRD_B        = AreaByte(11),
    AB_TRD_C        = AreaByte(12),
    AB_TRD_D        = AreaByte(13),
    AB_TRD_E        = AreaByte(14),
    AB_TRD_F        = AreaByte(15),
};

enum {
    AF_TRD_04               = AreaFlag(4),
    AF_TRD08_FireBar1_Coins = AreaFlag(11),
    AF_TRD08_FireBar2_Coins = AreaFlag(12),
};

extern MapSettings trd_04_settings;
extern MapSettings trd_08_settings;

#endif
