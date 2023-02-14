#ifndef _WORLD_AREA_GV_GV_H_
#define _WORLD_AREA_GV_GV_H_

enum {
    AB_GV_Unused_0       = AreaByte(0),
    AB_GV_Unused_1       = AreaByte(1),
    AB_GV_Unused_2       = AreaByte(2),
    AB_GV_Unused_3       = AreaByte(3),
    AB_GV_Unused_4       = AreaByte(4),
    AB_GV_Unused_5       = AreaByte(5),
    AB_GV_Unused_6       = AreaByte(6),
    AB_GV_Unused_7       = AreaByte(7),
    AB_GV_Unused_8       = AreaByte(8),
    AB_GV_Unused_9       = AreaByte(9),
    AB_GV_Unused_A       = AreaByte(10),
    AB_GV_Unused_B       = AreaByte(11),
    AB_GV_Unused_C       = AreaByte(12),
    AB_GV_Unused_D       = AreaByte(13),
    AB_GV_Unused_E       = AreaByte(14),
    AB_GV_Unused_F       = AreaByte(15),
};

#define AF_GV(index) AreaFlag(index)

extern MapSettings gv_01_settings;

#endif
