#ifndef _WORLD_AREA_NOK_NOK_H_
#define _WORLD_AREA_NOK_NOK_H_

enum {
    AB_NOK_0            = AreaByte(0),
    AB_NOK_1            = AreaByte(1),
    AB_NOK_2            = AreaByte(2),
    AB_NOK_Unused_3     = AreaByte(3),
    AB_NOK_Unused_4     = AreaByte(4),
    AB_NOK_Unused_5     = AreaByte(5),
    AB_NOK_Unused_6     = AreaByte(6),
    AB_NOK_Unused_7     = AreaByte(7),
    AB_NOK_Unused_8     = AreaByte(8),
    AB_NOK_Unused_9     = AreaByte(9),
    AB_NOK_Unused_A     = AreaByte(10),
    AB_NOK_Unused_B     = AreaByte(11),
    AB_NOK_Unused_C     = AreaByte(12),
    AB_NOK_Unused_D     = AreaByte(13),
    AB_NOK_Unused_E     = AreaByte(14),
    AB_NOK_Unused_F     = AreaByte(15),
};

enum {
    AF_NOK12_HitSwitch      = AreaFlag(1),
    AF_NOK14_HitSwitch      = AreaFlag(2),
    AF_NOK04_PlayingGame    = AreaFlag(3),
    AF_NOK04_BattleStarted  = AreaFlag(4),
    AF_NOK04_BattleDone     = AreaFlag(5),
    AF_NOK04_TauntMsgDone   = AreaFlag(6),
    AF_NOK04_FleeMsgDone    = AreaFlag(7),
    AF_NOK04_CamPanDone     = AreaFlag(8),
    AF_NOK01_Dialogue_RelaxedKoopa      = AreaFlag(9),
    AF_NOK01_Dialogue_Bobomb_01_Crisis  = AreaFlag(10),
    AF_NOK01_Dialogue_Bobomb_01         = AreaFlag(11),
    AF_NOK01_Dialogue_Bobomb_02         = AreaFlag(12),
    AF_NOK_0E               = AreaFlag(14),
    AF_NOK_0F               = AreaFlag(15),
    AF_NOK_10               = AreaFlag(16),
    AF_NOK_11               = AreaFlag(17),
    AF_NOK_12               = AreaFlag(18),
    AF_NOK_13               = AreaFlag(19),
    AF_NOK_14               = AreaFlag(20),
    AF_NOK_15               = AreaFlag(21),
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
