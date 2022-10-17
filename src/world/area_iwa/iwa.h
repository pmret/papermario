#ifndef _WORLD_AREA_IWA_IWA_H_
#define _WORLD_AREA_IWA_IWA_H_

enum {
    AB_IWA_0        = AreaByte(0),
    AB_IWA_1        = AreaByte(1),
    AB_IWA_2        = AreaByte(2),
    AB_IWA_3        = AreaByte(3),
    AB_IWA_4        = AreaByte(4),
    AB_IWA_5        = AreaByte(5),
    AB_IWA_6        = AreaByte(6),
    AB_IWA_7        = AreaByte(7),
    AB_IWA_8        = AreaByte(8),
    AB_IWA_9        = AreaByte(9),
    AB_IWA_A        = AreaByte(10),
    AB_IWA_B        = AreaByte(11),
    AB_IWA_C        = AreaByte(12),
    AB_IWA_D        = AreaByte(13),
    AB_IWA_E        = AreaByte(14),
    AB_IWA_F        = AreaByte(15),
};

enum {
    AF_IWA_SpokeWithBubulb     = AreaFlag(1),
    AF_IWA_SpokeWIthDryite      = AreaFlag(2),
};

extern MapSettings iwa_00_settings;
extern MapSettings iwa_01_settings;
extern MapSettings iwa_02_settings;
extern MapSettings iwa_03_settings;
extern MapSettings iwa_04_settings;
extern MapSettings iwa_10_settings;
extern MapSettings iwa_11_settings;

#endif
