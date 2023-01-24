#ifndef _WORLD_AREA_OMO_OMO_H_
#define _WORLD_AREA_OMO_OMO_H_

enum {
    AB_OMO_0        = AreaByte(0),
    AB_OMO_1        = AreaByte(1),
    AB_OMO_2        = AreaByte(2),
    AB_OMO09_IsPlayerNearSlotMachine    = AreaByte(3),
    AB_OMO_CurrentPeachChoice           = AreaByte(4),
    AB_OMO_5        = AreaByte(5),
    AB_OMO_6        = AreaByte(6),
    AB_OMO_7        = AreaByte(7),
    AB_OMO_8        = AreaByte(8),
    AB_OMO_9        = AreaByte(9),
    AB_OMO_A        = AreaByte(10),
    AB_OMO_B        = AreaByte(11),
    AB_OMO_C        = AreaByte(12),
    AB_OMO_D        = AreaByte(13),
    AB_OMO_E        = AreaByte(14),
    AB_OMO_F        = AreaByte(15),
};

enum {
    AF_OMO_UsingRightSwitch         = AreaFlag(2),
    AF_OMO_03                       = AreaFlag(3),
    AF_OMO07_NpcPool0               = AreaFlag(7),
    AF_OMO07_NpcPool1               = AreaFlag(8),
    AF_OMO07_NpcPool2               = AreaFlag(9),
    AF_OMO07_NpcPool3               = AreaFlag(10),
    AF_OMO09_StartBlock_DontBlink   = AreaFlag(11),
    AF_OMO09_Block1_DontBlink       = AreaFlag(12),
    AF_OMO09_Block2_DontBlink       = AreaFlag(13),
    AF_OMO09_Block3_DontBlink       = AreaFlag(14),
    AF_OMO07_DoorOpening            = AreaFlag(15),
    AF_OMO_11                       = AreaFlag(17),
};

extern MapSettings omo_01_settings;
extern MapSettings omo_02_settings;
extern MapSettings omo_03_settings;
extern MapSettings omo_04_settings;
extern MapSettings omo_05_settings;
extern MapSettings omo_06_settings;
extern MapSettings omo_07_settings;
extern MapSettings omo_08_settings;
extern MapSettings omo_09_settings;
extern MapSettings omo_10_settings;
extern MapSettings omo_11_settings;
extern MapSettings omo_12_settings;
extern MapSettings omo_13_settings;
extern MapSettings omo_14_settings;
extern MapSettings omo_15_settings;
extern MapSettings omo_16_settings;
extern MapSettings omo_17_settings;

#endif
