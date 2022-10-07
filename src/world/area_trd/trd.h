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
    AF_TRD01_RaiseStairs        = AreaFlag(1),
    AF_TRD02_LowerStairs        = AreaFlag(2),
    AF_TRD_04                   = AreaFlag(4),
    AF_TRD_MetPrisoner1         = AreaFlag(6),
    AF_TRD_MetPrisoner2         = AreaFlag(7),
    AF_TRD_MetPrisoner3         = AreaFlag(8),
    AF_TRD_MetPrisoner4         = AreaFlag(9),
    AF_TRD08_FireBar1_Coins     = AreaFlag(11),
    AF_TRD08_FireBar2_Coins     = AreaFlag(12),
    AF_TRD_FakeBowserRevealed   = AreaFlag(13),
};

extern MapSettings trd_00_settings;
extern MapSettings trd_01_settings;
extern MapSettings trd_02_settings;
extern MapSettings trd_03_settings;
extern MapSettings trd_04_settings;
extern MapSettings trd_05_settings;
extern MapSettings trd_06_settings;
extern MapSettings trd_07_settings;
extern MapSettings trd_08_settings;
extern MapSettings trd_09_settings;
extern MapSettings trd_10_settings;

#endif
