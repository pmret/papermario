#ifndef _WORLD_AREA_KGR_KGR_H_
#define _WORLD_AREA_KGR_KGR_H_

enum {
    AB_KGR_Unused_0       = AreaByte(0),
    AB_KGR_Unused_1       = AreaByte(1),
    AB_KGR_Unused_2       = AreaByte(2),
    AB_KGR_Unused_3       = AreaByte(3),
    AB_KGR_Unused_4       = AreaByte(4),
    AB_KGR_Unused_5       = AreaByte(5),
    AB_KGR_Unused_6       = AreaByte(6),
    AB_KGR_Unused_7       = AreaByte(7),
    AB_KGR_Unused_8       = AreaByte(8),
    AB_KGR_Unused_9       = AreaByte(9),
    AB_KGR_Unused_A       = AreaByte(10),
    AB_KGR_Unused_B       = AreaByte(11),
    AB_KGR_Unused_C       = AreaByte(12),
    AB_KGR_Unused_D       = AreaByte(13),
    AB_KGR_Unused_E       = AreaByte(14),
    AB_KGR_Unused_F       = AreaByte(15),
};

#define AF_KGR(index) AreaFlag(index)

extern MapSettings kgr_01_settings;
extern MapSettings kgr_02_settings;

#endif
