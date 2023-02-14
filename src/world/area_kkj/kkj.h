#ifndef _WORLD_AREA_KKJ_KKJ_H_
#define _WORLD_AREA_KKJ_KKJ_H_

enum {
    CAKE_TYPE_NONE              = 0, // cake has not been started
    CAKE_TYPE_BEGUN             = 1, // the cake has been imagined
    CAKE_TYPE_READY_TO_MIX      = 2, // added sugar and eggs
    CAKE_TYPE_MIXED             = 3, // mixed the batter
    CAKE_TYPE_READY_TO_BAKE     = 4, // added flour and butter
    CAKE_TYPE_BAKED             = 5, // baked in the oven
    CAKE_TYPE_DONE              = 6, // decorated
};

enum {
    AB_KKJ19_CurrentBakeStep        = AreaByte(0),
    AB_KKJ_CompletedBakeStep        = AreaByte(1),
    AB_KKJ19_HeldIngredient         = AreaByte(2),
    AB_KKJ19_BakeStepProgress       = AreaByte(3),
    AB_KKJ19_CookwareItemIdx        = AreaByte(4),
    AB_KKJ19_CakeItemIdx            = AreaByte(5),
    AB_KKJ29_AnsweringContestant    = AreaByte(6),
    AB_KKJ29_AnswerScore            = AreaByte(7),
    AB_KKJ29_LeftKoopatrolScore     = AreaByte(8),
    AB_KKJ29_PeachScore             = AreaByte(9),
    AB_KKJ29_RightKoopatrolScore    = AreaByte(10),
    AB_KKJ_Unused_B                 = AreaByte(11),
    AB_KKJ_Unused_C                 = AreaByte(12),
    AB_KKJ_Unused_D                 = AreaByte(13),
    AB_KKJ_Unused_E                 = AreaByte(14),
    AB_KKJ_Unused_F                 = AreaByte(15),
};

enum {
    AF_KKJ_01                       = AreaFlag(1),
    AF_KKJ_02                       = AreaFlag(2),
    AF_KKJ_03                       = AreaFlag(3),
    AF_KKJ_04                       = AreaFlag(4),
    AF_KKJ_05                       = AreaFlag(5),
    AF_KKJ_06                       = AreaFlag(6),
    AF_KKJ_07                       = AreaFlag(7),
    AF_KKJ_08                       = AreaFlag(8),
    AF_KKJ19_FailedBakingTask       = AreaFlag(9),
    AF_KKJ19_AddedEgg               = AreaFlag(10),
    AF_KKJ19_AddedSugar             = AreaFlag(11),
    AF_KKJ19_AddedFlour             = AreaFlag(12),
    AF_KKJ19_AddedButter            = AreaFlag(13),
    AF_KKJ19_AddedNothingWrong      = AreaFlag(14),
    AB_KKJ19_AddedIcing             = AreaFlag(15),
    AB_KKJ19_AddedBerries           = AreaFlag(16),
    AF_KKJ_FinishedBakingCake       = AreaFlag(17),
    AF_KKJ19_CanTakeIngredients     = AreaFlag(18),
    AF_KKJ_13                       = AreaFlag(19),
    AF_KKJ_14                       = AreaFlag(20),
    AF_KKJ_15                       = AreaFlag(21),
    AF_KKJ_17                       = AreaFlag(23),
    AF_KKJ_18                       = AreaFlag(24),
    AF_KKJ_19                       = AreaFlag(25),
    AF_KKJ_1A                       = AreaFlag(26),
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
