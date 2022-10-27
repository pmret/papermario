#ifndef _WORLD_AREA_FLO_FLO_H_
#define _WORLD_AREA_FLO_FLO_H_

enum {
    AB_FLO_0                    = AreaByte(0),
    AB_FLO_1                    = AreaByte(1),
    AB_FLO_CrystalTreeHitCount  = AreaByte(2),
    AB_FLO_PoiseKickedOutCount  = AreaByte(3),
    AB_FLO_4                    = AreaByte(4),
    AB_FLO_5                    = AreaByte(5),
    AB_FLO_6                    = AreaByte(6),
    AB_FLO_7                    = AreaByte(7),
    AB_FLO_8                    = AreaByte(8),
    AB_FLO_9                    = AreaByte(9),
    AB_FLO_A                    = AreaByte(10),
    AB_FLO_B                    = AreaByte(11),
    AB_FLO_C                    = AreaByte(12),
    AB_FLO_D                    = AreaByte(13),
    AB_FLO_E                    = AreaByte(14),
    AB_FLO_F                    = AreaByte(15),
};

enum {
    AF_FLO_05                   = AreaFlag(5),
    AF_FLO_MadeCrystalBerry     = AreaFlag(6),
    // flo_03
    AF_FLO_17                   = AreaFlag(23),
    AF_FLO_18                   = AreaFlag(24),
    AF_FLO_19                   = AreaFlag(25),
    AF_FLO_1A                   = AreaFlag(26),
    AF_FLO_TreeDrop_RedBerry1   = AreaFlag(27),
    AF_FLO_TreeDrop_RedBerry2   = AreaFlag(28),
};

#endif
