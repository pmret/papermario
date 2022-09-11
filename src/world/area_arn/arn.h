#ifndef _WORLD_AREA_ARN_ARN_H_
#define _WORLD_AREA_ARN_ARN_H_

enum {
    AB_ARN_0       = AreaByte(0),
    AB_ARN_1       = AreaByte(1),
    AB_ARN_2       = AreaByte(2),
    AB_ARN_3       = AreaByte(3),
    AB_ARN_4       = AreaByte(4),
    AB_ARN_5       = AreaByte(5),
    AB_ARN_6       = AreaByte(6),
    AB_ARN_7       = AreaByte(7),
    AB_ARN_8       = AreaByte(8),
    AB_ARN_9       = AreaByte(9),
    AB_ARN_A       = AreaByte(10),
    AB_ARN_B       = AreaByte(11),
    AB_ARN_C       = AreaByte(12),
    AB_ARN_D       = AreaByte(13),
    AB_ARN_E       = AreaByte(14),
    AB_ARN_F       = AreaByte(15),
};

#define AF_ARN(index) AreaFlag(index)

extern MapSettings arn_02_settings;
extern MapSettings arn_03_settings;
extern MapSettings arn_04_settings;
extern MapSettings arn_05_settings;
extern MapSettings arn_07_settings;
extern MapSettings arn_08_settings;
extern MapSettings arn_09_settings;
extern MapSettings arn_10_settings;
extern MapSettings arn_11_settings;
extern MapSettings arn_12_settings;
extern MapSettings arn_13_settings;

#endif
