#ifndef _WORLD_AREA_KKJ_KKJ_H_
#define _WORLD_AREA_KKJ_KKJ_H_

enum {
    AB_KKJ_Unused_0     = AreaByte(0),
    AB_KKJ_Unused_1     = AreaByte(1),
    AB_KKJ_Unused_2     = AreaByte(2),
    AB_KKJ_Unused_3     = AreaByte(3),
    AB_KKJ_Unused_4     = AreaByte(4),
    AB_KKJ_Unused_5     = AreaByte(5),
    AB_KKJ_Unused_6     = AreaByte(6),
    AB_KKJ_Unused_7     = AreaByte(7),
    AB_KKJ_Unused_8     = AreaByte(8),
    AB_KKJ_Unused_9     = AreaByte(9),
    AB_KKJ_Unused_A     = AreaByte(10),
    AB_KKJ_Unused_B     = AreaByte(11),
    AB_KKJ_Unused_C     = AreaByte(12),
    AB_KKJ_Unused_D     = AreaByte(13),
    AB_KKJ_Unused_E     = AreaByte(14),
    AB_KKJ_Unused_F     = AreaByte(15),
};

enum {
    AF_KKJ_01   = AreaFlag(1),
    AF_KKJ_02   = AreaFlag(2),
    AF_KKJ_07   = AreaFlag(7),
};

extern MapSettings kkj_00_settings;
extern MapSettings kkj_01_settings;
extern MapSettings kkj_02_settings;
extern MapSettings kkj_03_settings;
extern MapSettings kkj_10_settings;
extern MapSettings kkj_11_settings;
extern MapSettings kkj_12_settings;
extern MapSettings kkj_13_settings;
extern MapSettings kkj_14_settings;
extern MapSettings kkj_15_settings;
extern MapSettings kkj_16_settings;
extern MapSettings kkj_17_settings;
extern MapSettings kkj_18_settings;
extern MapSettings kkj_19_settings;
extern MapSettings kkj_20_settings;
extern MapSettings kkj_21_settings;
extern MapSettings kkj_22_settings;
extern MapSettings kkj_23_settings;
extern MapSettings kkj_24_settings;
extern MapSettings kkj_25_settings;
extern MapSettings kkj_26_settings;
extern MapSettings kkj_27_settings;
extern MapSettings kkj_28_settings;
extern MapSettings kkj_29_settings;

s32 kkj_00_map_init(void);
s32 kkj_03_map_init(void);
s32 kkj_13_map_init(void);
s32 kkj_14_map_init(void);
s32 kkj_23_map_init(void);
s32 kkj_25_map_init(void);

#endif
