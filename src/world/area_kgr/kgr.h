#ifndef _WORLD_AREA_KGR_KGR_H_
#define _WORLD_AREA_KGR_KGR_H_

enum {
    AB_KGR_0       = AreaByte(0),
    AB_KGR_1       = AreaByte(1),
    AB_KGR_2       = AreaByte(2),
    AB_KGR_3       = AreaByte(3),
    AB_KGR_4       = AreaByte(4),
    AB_KGR_5       = AreaByte(5),
    AB_KGR_6       = AreaByte(6),
    AB_KGR_7       = AreaByte(7),
    AB_KGR_8       = AreaByte(8),
    AB_KGR_9       = AreaByte(9),
    AB_KGR_A       = AreaByte(10),
    AB_KGR_B       = AreaByte(11),
    AB_KGR_C       = AreaByte(12),
    AB_KGR_D       = AreaByte(13),
    AB_KGR_E       = AreaByte(14),
    AB_KGR_F       = AreaByte(15),
};

#define AF_KGR(index) AreaFlag(index)

extern MapSettings kgr_01_settings;
extern MapSettings kgr_02_settings;

#endif
