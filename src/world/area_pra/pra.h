#ifndef _WORLD_AREA_PRA_PRA_H_
#define _WORLD_AREA_PRA_PRA_H_

enum {
    AB_PRA_Unused_0     = AreaByte(0),
    AB_PRA_Unused_1     = AreaByte(1),
    AB_PRA_Unused_2     = AreaByte(2),
    AB_PRA_Unused_3     = AreaByte(3),
    AB_PRA_Unused_4     = AreaByte(4),
    AB_PRA_Unused_5     = AreaByte(5),
    AB_PRA_Unused_6     = AreaByte(6),
    AB_PRA_Unused_7     = AreaByte(7),
    AB_PRA_Unused_8     = AreaByte(8),
    AB_PRA_Unused_9     = AreaByte(9),
    AB_PRA_Unused_A     = AreaByte(10),
    AB_PRA_Unused_B     = AreaByte(11),
    AB_PRA_Unused_C     = AreaByte(12),
    AB_PRA_Unused_D     = AreaByte(13),
    AB_PRA_Unused_E     = AreaByte(14),
    AB_PRA_Unused_F     = AreaByte(15),
};

enum {
    AF_PRA09_HitSwitch      = AreaFlag(2),
    AF_PRA33_FlippingWall   = AreaFlag(3),
};

extern MapSettings pra_01_settings;
extern MapSettings pra_02_settings;
extern MapSettings pra_03_settings;
extern MapSettings pra_04_settings;
extern MapSettings pra_05_settings;
extern MapSettings pra_06_settings;
extern MapSettings pra_09_settings;
extern MapSettings pra_10_settings;
extern MapSettings pra_11_settings;
extern MapSettings pra_12_settings;
extern MapSettings pra_13_settings;
extern MapSettings pra_14_settings;
extern MapSettings pra_15_settings;
extern MapSettings pra_16_settings;
extern MapSettings pra_18_settings;
extern MapSettings pra_19_settings;
extern MapSettings pra_20_settings;
extern MapSettings pra_21_settings;
extern MapSettings pra_22_settings;
extern MapSettings pra_27_settings;
extern MapSettings pra_28_settings;
extern MapSettings pra_29_settings;
extern MapSettings pra_31_settings;
extern MapSettings pra_32_settings;
extern MapSettings pra_33_settings;
extern MapSettings pra_34_settings;
extern MapSettings pra_35_settings;
extern MapSettings pra_36_settings;
extern MapSettings pra_37_settings;
extern MapSettings pra_38_settings;
extern MapSettings pra_39_settings;
extern MapSettings pra_40_settings;

s32 pra_01_map_init(void);
s32 pra_02_map_init(void);
s32 pra_03_map_init(void);
s32 pra_04_map_init(void);
s32 pra_05_map_init(void);
s32 pra_06_map_init(void);
s32 pra_09_map_init(void);
s32 pra_10_map_init(void);
s32 pra_11_map_init(void);
s32 pra_12_map_init(void);
s32 pra_13_map_init(void);
s32 pra_14_map_init(void);
s32 pra_15_map_init(void);
s32 pra_16_map_init(void);
s32 pra_18_map_init(void);
s32 pra_19_map_init(void);
s32 pra_20_map_init(void);
s32 pra_21_map_init(void);
s32 pra_22_map_init(void);
s32 pra_27_map_init(void);
s32 pra_28_map_init(void);
s32 pra_29_map_init(void);
s32 pra_31_map_init(void);
s32 pra_32_map_init(void);
s32 pra_33_map_init(void);
s32 pra_34_map_init(void);
s32 pra_35_map_init(void);
s32 pra_36_map_init(void);
s32 pra_37_map_init(void);
s32 pra_38_map_init(void);
s32 pra_39_map_init(void);
s32 pra_40_map_init(void);

#endif
