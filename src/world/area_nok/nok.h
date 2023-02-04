#ifndef _WORLD_AREA_NOK_NOK_H_
#define _WORLD_AREA_NOK_NOK_H_

enum {
    AB_NOK_0        = AreaByte(0),
    AB_NOK_1        = AreaByte(1),
    AB_NOK_2        = AreaByte(2),
    AB_NOK_3        = AreaByte(3),
    AB_NOK_4        = AreaByte(4),
    AB_NOK_5        = AreaByte(5),
    AB_NOK_6        = AreaByte(6),
    AB_NOK_7        = AreaByte(7),
    AB_NOK_8        = AreaByte(8),
    AB_NOK_9        = AreaByte(9),
    AB_NOK_A        = AreaByte(10),
    AB_NOK_B        = AreaByte(11),
    AB_NOK_C        = AreaByte(12),
    AB_NOK_D        = AreaByte(13),
    AB_NOK_E        = AreaByte(14),
    AB_NOK_F        = AreaByte(15),
};

enum {
    AF_NOK_01       = AreaFlag(1),
    AF_NOK_02       = AreaFlag(2),
    AF_NOK_09       = AreaFlag(9),
    AF_NOK_0A       = AreaFlag(10),
    AF_NOK_0B       = AreaFlag(11),
    AF_NOK_0C       = AreaFlag(12),
    AF_NOK_0E       = AreaFlag(14),
    AF_NOK_0F       = AreaFlag(15),
    AF_NOK_10       = AreaFlag(16),
    AF_NOK_11       = AreaFlag(17),
    AF_NOK_12       = AreaFlag(18),
    AF_NOK_13       = AreaFlag(19),
    AF_NOK_15       = AreaFlag(21),
};

extern MapSettings nok_01_settings;
extern MapSettings nok_02_settings;
extern MapSettings nok_03_settings;
extern MapSettings nok_04_settings;
extern MapSettings nok_11_settings;
extern MapSettings nok_12_settings;
extern MapSettings nok_13_settings;
extern MapSettings nok_14_settings;
extern MapSettings nok_15_settings;

#endif
