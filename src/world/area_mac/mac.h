#ifndef _WORLD_AREA_MAC_MAC_H_
#define _WORLD_AREA_MAC_MAC_H_

enum {
    AB_MAC_0        = AreaByte(0),
    AB_MAC_1        = AreaByte(1),
    AB_MAC_2        = AreaByte(2),
    AB_MAC_3        = AreaByte(3),
    AB_MAC_4        = AreaByte(4),
    AB_MAC_5        = AreaByte(5),
    AB_MAC_6        = AreaByte(6),
    AB_MAC_7        = AreaByte(7),
    AB_MAC_8        = AreaByte(8),
    AB_MAC_9        = AreaByte(9),
    AB_MAC_A        = AreaByte(10),
    AB_MAC_B        = AreaByte(11),
    AB_MAC_C        = AreaByte(12),
    AB_MAC_D        = AreaByte(13),
    AB_MAC_E        = AreaByte(14),
    AB_MAC_F        = AreaByte(15),
};

enum {
    AF_MAC_20       = AreaFlag(32),
    AF_MAC_21       = AreaFlag(33),
    AF_MAC_22       = AreaFlag(34),
    AF_MAC_23       = AreaFlag(35),
    AF_MAC_24       = AreaFlag(36),
    AF_MAC_25       = AreaFlag(37),
};

extern MapSettings machi_settings;
extern MapSettings mac_00_settings;
extern MapSettings mac_01_settings;
extern MapSettings mac_02_settings;
extern MapSettings mac_03_settings;
extern MapSettings mac_04_settings;
extern MapSettings mac_05_settings;
extern MapSettings mac_06_settings;

#endif
