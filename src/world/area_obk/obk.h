#ifndef _WORLD_AREA_OBK_OBK_H_
#define _WORLD_AREA_OBK_OBK_H_

enum {
    AB_OBK_Unused_0     = AreaByte(0),
    AB_OBK_Unused_1     = AreaByte(1),
    AB_OBK_Unused_2     = AreaByte(2),
    AB_OBK_Unused_3     = AreaByte(3),
    AB_OBK_Unused_4     = AreaByte(4),
    AB_OBK_Unused_5     = AreaByte(5),
    AB_OBK_Unused_6     = AreaByte(6),
    AB_OBK_Unused_7     = AreaByte(7),
    AB_OBK_Unused_8     = AreaByte(8),
    AB_OBK_Unused_9     = AreaByte(9),
    AB_OBK_Unused_A     = AreaByte(10),
    AB_OBK_Unused_B     = AreaByte(11),
    AB_OBK_Unused_C     = AreaByte(12),
    AB_OBK_Unused_D     = AreaByte(13),
    AB_OBK_Unused_E     = AreaByte(14),
    AB_OBK_Unused_F     = AreaByte(15),
};

enum {
    AF_OBK01_CabinetMoved           = AreaFlag(1),
    AF_OBK01_IsPlayerNearPortrait   = AreaFlag(3),
    AF_OBK01_WasPlayerNearPortrait  = AreaFlag(4),
    AF_OBK03_HitFirstSwitch         = AreaFlag(5),
    AF_OBK03_HitSecondSwitch        = AreaFlag(6),
    AF_OBK03_HitThirdSwitch         = AreaFlag(7),
    AF_OBK08_KeepAwayStarted        = AreaFlag(8),
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
