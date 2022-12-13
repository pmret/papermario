#ifndef _WORLD_AREA_OBK_OBK_H_
#define _WORLD_AREA_OBK_OBK_H_

enum {
    AB_OBK_0        = AreaByte(0),
    AB_OBK_1        = AreaByte(1),
    AB_OBK_2        = AreaByte(2),
    AB_OBK_3        = AreaByte(3),
    AB_OBK_4        = AreaByte(4),
    AB_OBK_5        = AreaByte(5),
    AB_OBK_6        = AreaByte(6),
    AB_OBK_7        = AreaByte(7),
    AB_OBK_8        = AreaByte(8),
    AB_OBK_9        = AreaByte(9),
    AB_OBK_A        = AreaByte(10),
    AB_OBK_B        = AreaByte(11),
    AB_OBK_C        = AreaByte(12),
    AB_OBK_D        = AreaByte(13),
    AB_OBK_E        = AreaByte(14),
    AB_OBK_F        = AreaByte(15),
};

enum {
    AF_OBK01_CabinetMoved           = AreaFlag(1),
    AF_OBK01_IsPlayerNearPortrait   = AreaFlag(3),
    AF_OBK01_WasPlayerNearPortrait  = AreaFlag(4),
    AF_OBK03_HitFirstSwitch         = AreaFlag(5),
    AF_OBK03_HitSecondSwitch        = AreaFlag(6),
    AF_OBK03_HitThirdSwitch         = AreaFlag(7),
};

extern MapSettings obk_01_settings;
extern MapSettings obk_02_settings;
extern MapSettings obk_03_settings;
extern MapSettings obk_04_settings;
extern MapSettings obk_05_settings;
extern MapSettings obk_06_settings;
extern MapSettings obk_07_settings;
extern MapSettings obk_08_settings;
extern MapSettings obk_09_settings;

#endif
