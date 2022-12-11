#ifndef _WORLD_DEAD_AREA_FLO_FLO_H_
#define _WORLD_DEAD_AREA_FLO_FLO_H_

enum {
    AB_FLO_TolielupDialogue             = AreaByte(0),
    AB_FLO_PetuniaDialogue              = AreaByte(1),
    AB_FLO_CrystalTreeHitCount          = AreaByte(2),
    AB_FLO_PoiseKickedOutCount          = AreaByte(3),
    AB_FLO_TreePuzzle_FirstCorrect      = AreaByte(4),
    AB_FLO_TreePuzzle_SecondCorrect     = AreaByte(5),
    AB_FLO_GuardLakituTalkCount         = AreaByte(6),
    AB_FLO_GuardedMachineHitCount       = AreaByte(7),
};

enum {
    // flo_07
    AF_FLO_PoiseHintDialogue            = AreaFlag(5),
    AF_FLO_MadeCrystalBerry             = AreaFlag(6),
    // flo_00
    AF_FLO_BeanstalkFacingRight         = AreaFlag(16),
    AF_FLO_PlatingInstructionsToggle    = AreaFlag(17),
    AF_FLO_PinkBubulbDialogueToggle     = AreaFlag(18),
    AF_FLO_PurpleBubulbDialogueToggle   = AreaFlag(19),
    AF_FLO_GreenBubulbDialogueToggle    = AreaFlag(20),
    AF_FLO_YellowBubulbDialogueToggle   = AreaFlag(21),
    // flo_12
    AF_FLO_GivenCrystalBerry            = AreaFlag(22),
    // flo_03
    AF_FLO_IsUnderground_Mole_01        = AreaFlag(23),
    AF_FLO_IsUnderground_Mole_02        = AreaFlag(24),
    AF_FLO_IsUnderground_Mole_03        = AreaFlag(25),
    AF_FLO_IsUnderground_Mole_04        = AreaFlag(26),
    AF_FLO_TreeDrop_RedBerry1           = AreaFlag(27),
    AF_FLO_TreeDrop_RedBerry2           = AreaFlag(28),
    // flo_08
    AF_FLO_TreeDrop_BlueBerry1          = AreaFlag(29),
    AF_FLO_TreeDrop_BlueBerry2          = AreaFlag(30),
    // flo_24
    AF_FLO_TreeDrop_BubbleBerry1        = AreaFlag(31),
    AF_FLO_TreeDrop_BubbleBerry2        = AreaFlag(32),
    // flo_25
    AF_FLO_TreeDrop_YellowBerry1        = AreaFlag(33),
    AF_FLO_TreeDrop_YellowBerry2        = AreaFlag(34),
    // flo_14
    AF_FLO_PauseBlowingBubbles          = AreaFlag(35),
    AF_FLO_BlowingBigBubble             = AreaFlag(36),
    AF_FLO_BigBubbleReady               = AreaFlag(37),
    // flo_15
    AF_FLO_MetTheSun                    = AreaFlag(38),
    // flo_16
    AF_FLO16_FoundHiddenStarPiece       = AreaFlag(39),
    // flo_19
    AF_FLO_BeanstalkGrowing             = AreaFlag(40),
    // flo_16
    AF_FLO_RaisedRedPillar              = AreaFlag(41),
    AF_FLO_RaisedGreenPillar            = AreaFlag(42),
    AF_FLO_LoweredPurplePillar          = AreaFlag(43),
    AF_FLO_RidingBeanstalk              = AreaFlag(44),
    AF_FLO_BeanstalkFadedOut            = AreaFlag(45),
};

#endif
