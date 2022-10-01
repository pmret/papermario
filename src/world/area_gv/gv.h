#ifndef _WORLD_AREA_GV_GV_H_
#define _WORLD_AREA_GV_GV_H_

enum {
    AB_GV_0       = AreaByte(0),
    AB_GV_1       = AreaByte(1),
    AB_GV_2       = AreaByte(2),
    AB_GV_3       = AreaByte(3),
    AB_GV_4       = AreaByte(4),
    AB_GV_5       = AreaByte(5),
    AB_GV_6       = AreaByte(6),
    AB_GV_7       = AreaByte(7),
    AB_GV_8       = AreaByte(8),
    AB_GV_9       = AreaByte(9),
    AB_GV_A       = AreaByte(10),
    AB_GV_B       = AreaByte(11),
    AB_GV_C       = AreaByte(12),
    AB_GV_D       = AreaByte(13),
    AB_GV_E       = AreaByte(14),
    AB_GV_F       = AreaByte(15),
};

#define AF_GV(index) AreaFlag(index)

extern MapSettings gv_01_settings;

#endif
