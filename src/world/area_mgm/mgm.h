#ifndef _WORLD_AREA_MGM_MGM_H_
#define _WORLD_AREA_MGM_MGM_H_

enum {
    AB_MGM_Unused_0     = AreaByte(0),
    AB_MGM_Unused_1     = AreaByte(1),
    AB_MGM_Unused_2     = AreaByte(2),
    AB_MGM_Unused_3     = AreaByte(3),
    AB_MGM_Unused_4     = AreaByte(4),
    AB_MGM_Unused_5     = AreaByte(5),
    AB_MGM_Unused_6     = AreaByte(6),
    AB_MGM_Unused_7     = AreaByte(7),
    AB_MGM_Unused_8     = AreaByte(8),
    AB_MGM_Unused_9     = AreaByte(9),
    AB_MGM_Unused_A     = AreaByte(10),
    AB_MGM_Unused_B     = AreaByte(11),
    AB_MGM_Unused_C     = AreaByte(12),
    AB_MGM_Unused_D     = AreaByte(13),
    AB_MGM_Unused_E     = AreaByte(14),
    AB_MGM_Unused_F     = AreaByte(15),
};

#define AF_MGM(index) AreaFlag(index)

extern MapSettings mgm_00_settings;
extern MapSettings mgm_01_settings;
extern MapSettings mgm_02_settings;
extern MapSettings mgm_03_settings;

#endif
