#ifndef _WORLD_AREA_ISK_ISK_H_
#define _WORLD_AREA_ISK_ISK_H_

enum {
    AB_ISK_Unused_0        = AreaByte(0),
    AB_ISK_Unused_1        = AreaByte(1),
    AB_ISK_Unused_2        = AreaByte(2),
    AB_ISK_Unused_3        = AreaByte(3),
    AB_ISK_Unused_4        = AreaByte(4),
    AB_ISK_Unused_5        = AreaByte(5),
    AB_ISK_Unused_6        = AreaByte(6),
    AB_ISK_Unused_7        = AreaByte(7),
    AB_ISK_Unused_8        = AreaByte(8),
    AB_ISK_Unused_9        = AreaByte(9),
    AB_ISK_Unused_A        = AreaByte(10),
    AB_ISK_Unused_B        = AreaByte(11),
    AB_ISK_Unused_C        = AreaByte(12),
    AB_ISK_Unused_D        = AreaByte(13),
    AB_ISK_Unused_E        = AreaByte(14),
    AB_ISK_Unused_F        = AreaByte(15),
};

enum {
    AF_ISK03_SandSwitchActivated    = AreaFlag(1),
    AF_ISK06_SandSwitchActivated    = AreaFlag(2),
    AF_ISK12_SandSwitchActivated    = AreaFlag(3),
    AF_ISK02_Sarcophagus1Opened     = AreaFlag(4),
    AF_ISK02_Sarcophagus2Opened     = AreaFlag(5),
    AF_ISK02_Sarcophagus3Opened     = AreaFlag(6),
    AF_ISK02_OpeningSarcophagus1    = AreaFlag(7),
    AF_ISK02_OpeningSarcophagus2    = AreaFlag(8),
    AF_ISK02_OpeningSarcophagus3    = AreaFlag(9),
    AF_ISK07_OpeningSarcophagus1    = AreaFlag(10),
    AF_ISK07_OpeningSarcophagus2    = AreaFlag(11),
    AF_ISK07_OpeningSarcophagus3    = AreaFlag(12),
    AF_ISK07_MummiesReleased        = AreaFlag(13),
    AF_ISK07_FlippingRedStairs      = AreaFlag(14),
    AF_ISK09_FlippingBlueStairs     = AreaFlag(15),
    AF_ISK09_FlippingRedStairs      = AreaFlag(16),
    AF_ISK05_StoneChompDefeated     = AreaFlag(17),
    AF_ISK12_StairSwitchActivated   = AreaFlag(18),
    AF_ISK14_StoneChompDefeated     = AreaFlag(19),
};

extern MapSettings isk_01_settings;
extern MapSettings isk_02_settings;
extern MapSettings isk_03_settings;
extern MapSettings isk_04_settings;
extern MapSettings isk_05_settings;
extern MapSettings isk_06_settings;
extern MapSettings isk_07_settings;
extern MapSettings isk_08_settings;
extern MapSettings isk_09_settings;
extern MapSettings isk_10_settings;
extern MapSettings isk_11_settings;
extern MapSettings isk_12_settings;
extern MapSettings isk_13_settings;
extern MapSettings isk_14_settings;
extern MapSettings isk_16_settings;
extern MapSettings isk_18_settings;
extern MapSettings isk_19_settings;

#endif
