#ifndef _WORLD_AREA_OMO_OMO_H_
#define _WORLD_AREA_OMO_OMO_H_

// "CrowdScript" used in omo_02 and omo_15
enum {
    op_CS_MOVE      = 0,
    op_CS_JUMP      = 1,
    op_CS_FALL      = 2,
    op_CS_END       = -1,
};

#define CS_MOVE(x, y)       op_CS_MOVE, x, y,
#define CS_JUMP(x, y, z)    op_CS_JUMP, x, y, z,
#define CS_FALL()           op_CS_FALL,
#define CS_END              op_CS_END,

enum {
    AB_OMO_0        = AreaByte(0),
    AB_OMO12_LightSource                = AreaByte(1),
    AB_OMO12_LightPowerMod              = AreaByte(2),
    AB_OMO09_IsPlayerNearSlotMachine    = AreaByte(3),
    AB_OMO_CurrentPeachChoice           = AreaByte(4),
    AB_OMO_5        = AreaByte(5),
    AB_OMO_6        = AreaByte(6),
    AB_OMO_Unused_7                     = AreaByte(7),
    AB_OMO_Unused_8                     = AreaByte(8),
    AB_OMO_Unused_9                     = AreaByte(9),
    AB_OMO_Unused_A                     = AreaByte(10),
    AB_OMO_Unused_B                     = AreaByte(11),
    AB_OMO_Unused_C                     = AreaByte(12),
    AB_OMO_Unused_D                     = AreaByte(13),
    AB_OMO_Unused_E                     = AreaByte(14),
    AB_OMO_Unused_F                     = AreaByte(15),
};

enum {
    AF_OMO_UsingRightSwitch         = AreaFlag(2),
    AF_OMO_03                       = AreaFlag(3),
    AF_OMO_04                       = AreaFlag(4),
    AF_OMO_05                       = AreaFlag(5),
    AF_OMO_06                       = AreaFlag(6),
    AF_OMO07_NpcPool0               = AreaFlag(7),
    AF_OMO07_NpcPool1               = AreaFlag(8),
    AF_OMO07_NpcPool2               = AreaFlag(9),
    AF_OMO07_NpcPool3               = AreaFlag(10),
    AF_OMO09_StartBlock_DontBlink   = AreaFlag(11),
    AF_OMO09_Block1_DontBlink       = AreaFlag(12),
    AF_OMO09_Block2_DontBlink       = AreaFlag(13),
    AF_OMO09_Block3_DontBlink       = AreaFlag(14),
    AF_OMO07_DoorOpening            = AreaFlag(15),
    AF_OMO_10                       = AreaFlag(16),
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
