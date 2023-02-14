#ifndef _WORLD_AREA_END_END_H_
#define _WORLD_AREA_END_END_H_

enum {
    AB_END_Unused_0       = AreaByte(0),
    AB_END_Unused_1       = AreaByte(1),
    AB_END_Unused_2       = AreaByte(2),
    AB_END_Unused_3       = AreaByte(3),
    AB_END_Unused_4       = AreaByte(4),
    AB_END_Unused_5       = AreaByte(5),
    AB_END_Unused_6       = AreaByte(6),
    AB_END_Unused_7       = AreaByte(7),
    AB_END_Unused_8       = AreaByte(8),
    AB_END_Unused_9       = AreaByte(9),
    AB_END_Unused_A       = AreaByte(10),
    AB_END_Unused_B       = AreaByte(11),
    AB_END_Unused_C       = AreaByte(12),
    AB_END_Unused_D       = AreaByte(13),
    AB_END_Unused_E       = AreaByte(14),
    AB_END_Unused_F       = AreaByte(15),
};

#define AF_END(index) AreaFlag(index)

extern MapSettings end_00_settings;
s32 end_00_map_init(void);
extern MapSettings end_01_settings;
s32 end_01_map_init(void);

#endif
