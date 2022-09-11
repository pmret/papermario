MoveData gMoveTable[] = {
{   // move 0: Nothing
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 1: Unused_01
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 2: Unused_02
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3: Hammer1
    .nameMsg = MESSAGE_ID_1D0038,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_2300A3,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 4: Hammer2
    .nameMsg = MESSAGE_ID_1D0038,
    .fullDescMsg = MESSAGE_ID_2300A4,
    .shortDescMsg = MESSAGE_ID_2300A4,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 5: Hammer3
    .nameMsg = MESSAGE_ID_1D0038,
    .fullDescMsg = MESSAGE_ID_2300A5,
    .shortDescMsg = MESSAGE_ID_2300A5,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 6: Unused_Hammer4
    .nameMsg = MESSAGE_ID_1D0038,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 7: Unused_Hammer5
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8: SpinSmash
    .nameMsg = MESSAGE_ID_2A0010,
    .fullDescMsg = MESSAGE_ID_250068,
    .shortDescMsg = MESSAGE_ID_230068,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move 9: QuakeHammer
    .nameMsg = MESSAGE_ID_2A0012,
    .fullDescMsg = MESSAGE_ID_25006A,
    .shortDescMsg = MESSAGE_ID_23006A,
    .flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move A: DDownPound
    .nameMsg = MESSAGE_ID_2A0011,
    .fullDescMsg = MESSAGE_ID_250069,
    .shortDescMsg = MESSAGE_ID_230069,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 2
},
{   // move B: SmashCharge0
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move C: Unused_Hammer_0C
    .nameMsg = MESSAGE_ID_1D0038,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move D: HammerThrow
    .nameMsg = MESSAGE_ID_2A000E,
    .fullDescMsg = MESSAGE_ID_250066,
    .shortDescMsg = MESSAGE_ID_230066,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 2
},
{   // move E: MegaQuake
    .nameMsg = MESSAGE_ID_2A0014,
    .fullDescMsg = MESSAGE_ID_25006C,
    .shortDescMsg = MESSAGE_ID_23006C,
    .flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 7,
    .costBP = 3
},
{   // move F: SmashCharge
    .nameMsg = MESSAGE_ID_2A000C,
    .fullDescMsg = MESSAGE_ID_250064,
    .shortDescMsg = MESSAGE_ID_230064,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 10: Unused_Hammer_10
    .nameMsg = MESSAGE_ID_1D0038,
    .fullDescMsg = MESSAGE_ID_250064,
    .shortDescMsg = MESSAGE_ID_230064,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 11: SuperSmashCharge
    .nameMsg = MESSAGE_ID_2A000D,
    .fullDescMsg = MESSAGE_ID_250065,
    .shortDescMsg = MESSAGE_ID_230065,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 4,
    .costBP = 2
},
{   // move 12: Unused_Hammer_12
    .nameMsg = MESSAGE_ID_1D0038,
    .fullDescMsg = MESSAGE_ID_250065,
    .shortDescMsg = MESSAGE_ID_230065,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 13: AutoSmash
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 1
},
{   // move 14: PowerQuake
    .nameMsg = MESSAGE_ID_2A0013,
    .fullDescMsg = MESSAGE_ID_25006B,
    .shortDescMsg = MESSAGE_ID_23006B,
    .flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 4,
    .costBP = 2
},
{   // move 15: PowerSmash
    .nameMsg = MESSAGE_ID_2A000A,
    .fullDescMsg = MESSAGE_ID_250062,
    .shortDescMsg = MESSAGE_ID_230062,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move 16: SuperSmash
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 4,
    .costBP = 2
},
{   // move 17: MegaSmash
    .nameMsg = MESSAGE_ID_2A000B,
    .fullDescMsg = MESSAGE_ID_250063,
    .shortDescMsg = MESSAGE_ID_230063,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 6,
    .costBP = 3
},
{   // move 18: ShrinkSmash
    .nameMsg = MESSAGE_ID_2A000F,
    .fullDescMsg = MESSAGE_ID_250067,
    .shortDescMsg = MESSAGE_ID_230067,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move 19: ShellCrack
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 6,
    .costBP = 3
},
{   // move 1A: Jump1
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = MESSAGE_ID_2300A0,
    .shortDescMsg = MESSAGE_ID_2300A0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1B: Jump2
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = MESSAGE_ID_2300A1,
    .shortDescMsg = MESSAGE_ID_2300A1,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1C: Jump3
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = MESSAGE_ID_2300A2,
    .shortDescMsg = MESSAGE_ID_2300A2,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1D: Unused_Jump4
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1E: Unused_Jump5
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1F: Multibounce
    .nameMsg = MESSAGE_ID_2A0006,
    .fullDescMsg = MESSAGE_ID_25005E,
    .shortDescMsg = MESSAGE_ID_23005E,
    .flags = MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 20: PowerBounce
    .nameMsg = MESSAGE_ID_2A0009,
    .fullDescMsg = MESSAGE_ID_250061,
    .shortDescMsg = MESSAGE_ID_230061,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 3,
    .costBP = 2
},
{   // move 21: SleepStomp
    .nameMsg = MESSAGE_ID_2A0004,
    .fullDescMsg = MESSAGE_ID_25005C,
    .shortDescMsg = MESSAGE_ID_23005C,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 22: DizzyStomp
    .nameMsg = MESSAGE_ID_2A0005,
    .fullDescMsg = MESSAGE_ID_25005D,
    .shortDescMsg = MESSAGE_ID_23005D,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 23: JumpCharge0
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 24: Unused_24
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 1,
    .costBP = 1
},
{   // move 25: JumpCharge
    .nameMsg = MESSAGE_ID_2A0002,
    .fullDescMsg = MESSAGE_ID_25005A,
    .shortDescMsg = MESSAGE_ID_23005A,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 26: Unused_26
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = MESSAGE_ID_25005A,
    .shortDescMsg = MESSAGE_ID_23005A,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 27: SuperJumpCharge
    .nameMsg = MESSAGE_ID_2A0003,
    .fullDescMsg = MESSAGE_ID_25005B,
    .shortDescMsg = MESSAGE_ID_23005B,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 4,
    .costBP = 2
},
{   // move 28: Unused_28
    .nameMsg = MESSAGE_ID_1D0039,
    .fullDescMsg = MESSAGE_ID_25005B,
    .shortDescMsg = MESSAGE_ID_23005B,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 29: AutoJump
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 1
},
{   // move 2A: AutoMultibounce
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 5,
    .costBP = 2
},
{   // move 2B: PowerJump
    .nameMsg = MESSAGE_ID_2A0000,
    .fullDescMsg = MESSAGE_ID_250058,
    .shortDescMsg = MESSAGE_ID_230058,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 2C: SuperJump
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 4,
    .costBP = 2
},
{   // move 2D: MegaJump
    .nameMsg = MESSAGE_ID_2A0001,
    .fullDescMsg = MESSAGE_ID_250059,
    .shortDescMsg = MESSAGE_ID_230059,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 6,
    .costBP = 3
},
{   // move 2E: DDownJump
    .nameMsg = MESSAGE_ID_2A0008,
    .fullDescMsg = MESSAGE_ID_250060,
    .shortDescMsg = MESSAGE_ID_230060,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 2
},
{   // move 2F: ShrinkStomp
    .nameMsg = MESSAGE_ID_2A0007,
    .fullDescMsg = MESSAGE_ID_25005F,
    .shortDescMsg = MESSAGE_ID_23005F,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 30: EarthquakeJump
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_20,
    .costFP = 2,
    .costBP = 2
},
{   // move 31: Unused_DefendPlus
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_250074,
    .shortDescMsg = MESSAGE_ID_230074,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_3,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 32: Unused_32
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_3,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 8
},
{   // move 33: DamageDodge
    .nameMsg = MESSAGE_ID_260075,
    .fullDescMsg = MESSAGE_ID_250075,
    .shortDescMsg = MESSAGE_ID_230075,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_3,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 34: Items
    .nameMsg = MESSAGE_ID_1D003F,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D00A4,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 35: DoubleDip
    .nameMsg = MESSAGE_ID_2A0015,
    .fullDescMsg = MESSAGE_ID_25006D,
    .shortDescMsg = MESSAGE_ID_23006D,
    .flags = 0,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 3,
    .costBP = 1
},
{   // move 36: TripleDip
    .nameMsg = MESSAGE_ID_2A0016,
    .fullDescMsg = MESSAGE_ID_25006E,
    .shortDescMsg = MESSAGE_ID_23006E,
    .flags = 0,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 6,
    .costBP = 3
},
{   // move 37: Unused_37
    .nameMsg = "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_TACTICS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 38: QuickChange
    .nameMsg = MESSAGE_ID_2A0018,
    .fullDescMsg = MESSAGE_ID_250070,
    .shortDescMsg = MESSAGE_ID_230070,
    .flags = 0,
    .category = MOVE_TYPE_TACTICS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 39: Unused_39
    .nameMsg = "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_6,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3A: Unused_3A
    .nameMsg = "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3B: PowerPlus
    .nameMsg = MESSAGE_ID_260073,
    .fullDescMsg = MESSAGE_ID_250073,
    .shortDescMsg = MESSAGE_ID_230073,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 3C: AllorNothing
    .nameMsg = MESSAGE_ID_260093,
    .fullDescMsg = MESSAGE_ID_250093,
    .shortDescMsg = MESSAGE_ID_230093,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 3D: IcePower
    .nameMsg = MESSAGE_ID_260095,
    .fullDescMsg = MESSAGE_ID_250095,
    .shortDescMsg = MESSAGE_ID_230095,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 3E: PUpDDown
    .nameMsg = MESSAGE_ID_2A0019,
    .fullDescMsg = MESSAGE_ID_250076,
    .shortDescMsg = MESSAGE_ID_230076,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 3F: Unused_3F
    .nameMsg = "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 40: SpikeShield
    .nameMsg = MESSAGE_ID_26007F,
    .fullDescMsg = MESSAGE_ID_25007F,
    .shortDescMsg = MESSAGE_ID_23007F,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 41: FireShield
    .nameMsg = MESSAGE_ID_260097,
    .fullDescMsg = MESSAGE_ID_250097,
    .shortDescMsg = MESSAGE_ID_230097,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 42: PrettyLucky
    .nameMsg = MESSAGE_ID_260081,
    .fullDescMsg = MESSAGE_ID_250081,
    .shortDescMsg = MESSAGE_ID_230081,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 43: FeelingFine
    .nameMsg = MESSAGE_ID_26008C,
    .fullDescMsg = MESSAGE_ID_25008C,
    .shortDescMsg = MESSAGE_ID_23008C,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 44: ZapTap
    .nameMsg = MESSAGE_ID_260099,
    .fullDescMsg = MESSAGE_ID_250099,
    .shortDescMsg = MESSAGE_ID_230099,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 45: DefendPlus
    .nameMsg = MESSAGE_ID_260074,
    .fullDescMsg = MESSAGE_ID_250074,
    .shortDescMsg = MESSAGE_ID_230074,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 46: LastStand
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_250085,
    .shortDescMsg = MESSAGE_ID_230085,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 47: CloseCall
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_250083,
    .shortDescMsg = MESSAGE_ID_230083,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 48: LuckyDay
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_250082,
    .shortDescMsg = MESSAGE_ID_230082,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 7
},
{   // move 49: PDownDUp
    .nameMsg = MESSAGE_ID_2A001A,
    .fullDescMsg = MESSAGE_ID_250077,
    .shortDescMsg = MESSAGE_ID_230077,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 4A: HealthyHealthy
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 4B: Unused_4B
    .nameMsg = "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 4C: DodgeMaster
    .nameMsg = MESSAGE_ID_260080,
    .fullDescMsg = MESSAGE_ID_250080,
    .shortDescMsg = MESSAGE_ID_230080,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 4D: FirstAttack
    .nameMsg = MESSAGE_ID_260087,
    .fullDescMsg = MESSAGE_ID_250087,
    .shortDescMsg = MESSAGE_ID_230087,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 4E: SlowGo
    .nameMsg = MESSAGE_ID_260094,
    .fullDescMsg = MESSAGE_ID_250094,
    .shortDescMsg = MESSAGE_ID_230094,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 4F: RightOn
    .nameMsg = MESSAGE_ID_26009B,
    .fullDescMsg = MESSAGE_ID_25009B,
    .shortDescMsg = MESSAGE_ID_23009B,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 8
},
{   // move 50: BumpAttack
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_250088,
    .shortDescMsg = MESSAGE_ID_230088,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 5
},
{   // move 51: Unused_51
    .nameMsg = "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 52: HPPlus
    .nameMsg = MESSAGE_ID_260071,
    .fullDescMsg = MESSAGE_ID_250071,
    .shortDescMsg = MESSAGE_ID_230071,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 53: MysteryScroll
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 54: AttackFXA
    .nameMsg = MESSAGE_ID_26008D,
    .fullDescMsg = MESSAGE_ID_25008D,
    .shortDescMsg = MESSAGE_ID_23008D,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 55: AttackFXD
    .nameMsg = MESSAGE_ID_26008E,
    .fullDescMsg = MESSAGE_ID_25008E,
    .shortDescMsg = MESSAGE_ID_23008E,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 56: AttackFXB
    .nameMsg = MESSAGE_ID_26008F,
    .fullDescMsg = MESSAGE_ID_25008F,
    .shortDescMsg = MESSAGE_ID_23008F,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 57: AttackFXE
    .nameMsg = MESSAGE_ID_260090,
    .fullDescMsg = MESSAGE_ID_250090,
    .shortDescMsg = MESSAGE_ID_230090,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 58: AttackFXC
    .nameMsg = MESSAGE_ID_260091,
    .fullDescMsg = MESSAGE_ID_250091,
    .shortDescMsg = MESSAGE_ID_230091,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 59: AttackFXF
    .nameMsg = MESSAGE_ID_260092,
    .fullDescMsg = MESSAGE_ID_250092,
    .shortDescMsg = MESSAGE_ID_230092,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 5A: HPDrain
    .nameMsg = MESSAGE_ID_260078,
    .fullDescMsg = MESSAGE_ID_250078,
    .shortDescMsg = MESSAGE_ID_230078,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5B: FPPlus
    .nameMsg = MESSAGE_ID_260072,
    .fullDescMsg = MESSAGE_ID_250072,
    .shortDescMsg = MESSAGE_ID_230072,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5C: MoneyMoney
    .nameMsg = MESSAGE_ID_26009A,
    .fullDescMsg = MESSAGE_ID_25009A,
    .shortDescMsg = MESSAGE_ID_23009A,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 7
},
{   // move 5D: ChillOutBadge
    .nameMsg = MESSAGE_ID_260098,
    .fullDescMsg = MESSAGE_ID_250098,
    .shortDescMsg = MESSAGE_ID_230098,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 5E: HappyHeart
    .nameMsg = MESSAGE_ID_260079,
    .fullDescMsg = MESSAGE_ID_250079,
    .shortDescMsg = MESSAGE_ID_230079,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5F: MegaRush
    .nameMsg = MESSAGE_ID_260086,
    .fullDescMsg = MESSAGE_ID_250086,
    .shortDescMsg = MESSAGE_ID_230086,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 60: Berserker
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 8
},
{   // move 61: RunawayPay
    .nameMsg = MESSAGE_ID_26009C,
    .fullDescMsg = MESSAGE_ID_25009C,
    .shortDescMsg = MESSAGE_ID_23009C,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 62: FlowerSaver
    .nameMsg = MESSAGE_ID_26007B,
    .fullDescMsg = MESSAGE_ID_25007B,
    .shortDescMsg = MESSAGE_ID_23007B,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 63: PayOff
    .nameMsg = MESSAGE_ID_260096,
    .fullDescMsg = MESSAGE_ID_250096,
    .shortDescMsg = MESSAGE_ID_230096,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 64: PowerRush
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_250084,
    .shortDescMsg = MESSAGE_ID_230084,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 65: CrazyHeart
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 10
},
{   // move 66: MegaHPDrain
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 10
},
{   // move 67: FlowerFanatic
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 10
},
{   // move 68: HeartFinder
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_25007C,
    .shortDescMsg = MESSAGE_ID_23007C,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 69: FlowerFinder
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_25007D,
    .shortDescMsg = MESSAGE_ID_23007D,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 6A: SpinAttack
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_250089,
    .shortDescMsg = MESSAGE_ID_230089,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 6B: DizzyAttack
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_25008A,
    .shortDescMsg = MESSAGE_ID_23008A,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 6C: ISpy
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_25009E,
    .shortDescMsg = MESSAGE_ID_23009E,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6D: SpeedySpin
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID_25008B,
    .shortDescMsg = MESSAGE_ID_23008B,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6E: Refund
    .nameMsg = MESSAGE_ID_26009D,
    .fullDescMsg = MESSAGE_ID_25009D,
    .shortDescMsg = MESSAGE_ID_23009D,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6F: Unused_FinalGoompa
    .nameMsg = "ファイナルクリジイ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 70: Unused_FinalBombomb
    .nameMsg = "ファイナルボムヘイ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 71: DeepFocus
    .nameMsg = MESSAGE_ID_26007E,
    .fullDescMsg = MESSAGE_ID_25007E,
    .shortDescMsg = MESSAGE_ID_23007E,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 72: SuperFocus
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 5
},
{   // move 73: Kaiden
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_80000000,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 74: HappyFlower
    .nameMsg = MESSAGE_ID_26007A,
    .fullDescMsg = MESSAGE_ID_25007A,
    .shortDescMsg = MESSAGE_ID_23007A,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 75: GroupFocus
    .nameMsg = MESSAGE_ID_26006F,
    .fullDescMsg = MESSAGE_ID_25006F,
    .shortDescMsg = MESSAGE_ID_23006F,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 76: Peekaboo
    .nameMsg = MESSAGE_ID_26009F,
    .fullDescMsg = MESSAGE_ID_25009F,
    .shortDescMsg = MESSAGE_ID_23009F,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 77: Focus
    .nameMsg = MESSAGE_ID_1D0014,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0020,
    .flags = MOVE_DATA_FLAG_80000000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 78: Refresh
    .nameMsg = MESSAGE_ID_1D0015,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0021,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 79: Lullaby
    .nameMsg = MESSAGE_ID_1D0016,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0022,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 7A: StarStorm
    .nameMsg = MESSAGE_ID_1D0017,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0023,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7B: ChillOutMove
    .nameMsg = MESSAGE_ID_1D0018,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0024,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7C: Smooch
    .nameMsg = MESSAGE_ID_1D0019,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0025,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 3,
    .costBP = 3
},
{   // move 7D: TimeOut
    .nameMsg = MESSAGE_ID_1D001A,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0026,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7E: UpAndAway
    .nameMsg = MESSAGE_ID_1D001B,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0027,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7F: StarBeam
    .nameMsg = MESSAGE_ID_1D001C,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0028,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 80: PeachBeam
    .nameMsg = MESSAGE_ID_1D001D,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0029,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 81: PeachFocus
    .nameMsg = MESSAGE_ID_1D001E,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0020,
    .flags = MOVE_DATA_FLAG_100,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 82: TwinkDash
    .nameMsg = MESSAGE_ID_1D001F,
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID_1D0020,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 83: Headbonk1
    .nameMsg = MESSAGE_ID_2B0000,
    .fullDescMsg = MESSAGE_ID_280007,
    .shortDescMsg = MESSAGE_ID_280002,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 84: Headbonk2
    .nameMsg = MESSAGE_ID_2B0000,
    .fullDescMsg = MESSAGE_ID_280008,
    .shortDescMsg = MESSAGE_ID_280002,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 85: Headbonk3
    .nameMsg = MESSAGE_ID_2B0000,
    .fullDescMsg = MESSAGE_ID_280009,
    .shortDescMsg = MESSAGE_ID_280002,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 86: Tattle
    .nameMsg = MESSAGE_ID_2B0001,
    .fullDescMsg = MESSAGE_ID_28000A,
    .shortDescMsg = MESSAGE_ID_280003,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_20000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 87: Charge
    .nameMsg = MESSAGE_ID_2B0002,
    .fullDescMsg = MESSAGE_ID_28000B,
    .shortDescMsg = MESSAGE_ID_280004,
    .flags = MOVE_DATA_FLAG_100,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 0
},
{   // move 88: Multibonk
    .nameMsg = MESSAGE_ID_2B0003,
    .fullDescMsg = MESSAGE_ID_28000C,
    .shortDescMsg = MESSAGE_ID_280005,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 3,
    .costBP = 0
},
{   // move 89: ShellToss1
    .nameMsg = MESSAGE_ID_2B0004,
    .fullDescMsg = MESSAGE_ID_280014,
    .shortDescMsg = MESSAGE_ID_28000F,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8A: ShellToss2
    .nameMsg = MESSAGE_ID_2B0004,
    .fullDescMsg = MESSAGE_ID_280015,
    .shortDescMsg = MESSAGE_ID_28000F,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8B: ShellToss3
    .nameMsg = MESSAGE_ID_2B0004,
    .fullDescMsg = MESSAGE_ID_280016,
    .shortDescMsg = MESSAGE_ID_28000F,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8C: PowerShell
    .nameMsg = MESSAGE_ID_2B0005,
    .fullDescMsg = MESSAGE_ID_280017,
    .shortDescMsg = MESSAGE_ID_280010,
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 3,
    .costBP = 0
},
{   // move 8D: DizzyShell
    .nameMsg = MESSAGE_ID_2B0006,
    .fullDescMsg = MESSAGE_ID_280018,
    .shortDescMsg = MESSAGE_ID_280011,
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 4,
    .costBP = 0
},
{   // move 8E: FireShell
    .nameMsg = MESSAGE_ID_2B0007,
    .fullDescMsg = MESSAGE_ID_280019,
    .shortDescMsg = MESSAGE_ID_280012,
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 5,
    .costBP = 0
},
{   // move 8F: BodySlam1
    .nameMsg = MESSAGE_ID_2B0008,
    .fullDescMsg = MESSAGE_ID_280021,
    .shortDescMsg = MESSAGE_ID_28001C,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 90: BodySlam2
    .nameMsg = MESSAGE_ID_2B0008,
    .fullDescMsg = MESSAGE_ID_280022,
    .shortDescMsg = MESSAGE_ID_28001C,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 91: BodySlam3
    .nameMsg = MESSAGE_ID_2B0008,
    .fullDescMsg = MESSAGE_ID_280023,
    .shortDescMsg = MESSAGE_ID_28001C,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 92: Bomb
    .nameMsg = MESSAGE_ID_2B0009,
    .fullDescMsg = MESSAGE_ID_280024,
    .shortDescMsg = MESSAGE_ID_28001D,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 3,
    .costBP = 0
},
{   // move 93: PowerBomb
    .nameMsg = MESSAGE_ID_2B000A,
    .fullDescMsg = MESSAGE_ID_280025,
    .shortDescMsg = MESSAGE_ID_28001E,
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 6,
    .costBP = 0
},
{   // move 94: MegaBomb
    .nameMsg = MESSAGE_ID_2B000B,
    .fullDescMsg = MESSAGE_ID_280026,
    .shortDescMsg = MESSAGE_ID_28001F,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 8,
    .costBP = 0
},
{   // move 95: SkyDive1
    .nameMsg = MESSAGE_ID_2B000C,
    .fullDescMsg = MESSAGE_ID_28002E,
    .shortDescMsg = MESSAGE_ID_280029,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 96: SkyDive2
    .nameMsg = MESSAGE_ID_2B000C,
    .fullDescMsg = MESSAGE_ID_28002F,
    .shortDescMsg = MESSAGE_ID_280029,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 97: SkyDive3
    .nameMsg = MESSAGE_ID_2B000C,
    .fullDescMsg = MESSAGE_ID_280030,
    .shortDescMsg = MESSAGE_ID_280029,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 98: ShellShot
    .nameMsg = MESSAGE_ID_2B000D,
    .fullDescMsg = MESSAGE_ID_280031,
    .shortDescMsg = MESSAGE_ID_28002A,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_5,
    .costFP = 3,
    .costBP = 0
},
{   // move 99: AirLift
    .nameMsg = MESSAGE_ID_2B000E,
    .fullDescMsg = MESSAGE_ID_280032,
    .shortDescMsg = MESSAGE_ID_28002B,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_400 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 3,
    .costBP = 0
},
{   // move 9A: AirRaid
    .nameMsg = MESSAGE_ID_2B000F,
    .fullDescMsg = MESSAGE_ID_280033,
    .shortDescMsg = MESSAGE_ID_28002C,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 6,
    .costBP = 0
},
{   // move 9B: Unused_LoneFool1
    .nameMsg = "ひとりぼけ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9C: Unused_LoneFool2
    .nameMsg = "ひとりぼけ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9D: Unused_LoneFool3
    .nameMsg = "ひとりぼけ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9E: Unused_Mumble
    .nameMsg = "むにゃむにゃ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_4,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9F: Unused_Preach
    .nameMsg = "せっきょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move A0: Unused_Awakening
    .nameMsg = "かくせい",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move A1: ElectroDash1
    .nameMsg = MESSAGE_ID_2B0014,
    .fullDescMsg = MESSAGE_ID_280048,
    .shortDescMsg = MESSAGE_ID_280043,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A2: ElectroDash2
    .nameMsg = MESSAGE_ID_2B0014,
    .fullDescMsg = MESSAGE_ID_280049,
    .shortDescMsg = MESSAGE_ID_280043,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A3: ElectroDash3
    .nameMsg = MESSAGE_ID_2B0014,
    .fullDescMsg = MESSAGE_ID_28004A,
    .shortDescMsg = MESSAGE_ID_280043,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A4: PowerShock
    .nameMsg = MESSAGE_ID_2B0015,
    .fullDescMsg = MESSAGE_ID_28004B,
    .shortDescMsg = MESSAGE_ID_280044,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 2,
    .costBP = 0
},
{   // move A5: TurboCharge
    .nameMsg = MESSAGE_ID_2B0016,
    .fullDescMsg = MESSAGE_ID_28004C,
    .shortDescMsg = MESSAGE_ID_280045,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 3,
    .costBP = 0
},
{   // move A6: MegaShock
    .nameMsg = MESSAGE_ID_2B0017,
    .fullDescMsg = MESSAGE_ID_28004D,
    .shortDescMsg = MESSAGE_ID_280046,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_12,
    .costFP = 5,
    .costBP = 0
},
{   // move A7: BellyFlop1
    .nameMsg = MESSAGE_ID_2B0018,
    .fullDescMsg = MESSAGE_ID_280055,
    .shortDescMsg = MESSAGE_ID_280050,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move A8: BellyFlop2
    .nameMsg = MESSAGE_ID_2B0018,
    .fullDescMsg = MESSAGE_ID_280056,
    .shortDescMsg = MESSAGE_ID_280050,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move A9: BellyFlop3
    .nameMsg = MESSAGE_ID_2B0018,
    .fullDescMsg = MESSAGE_ID_280057,
    .shortDescMsg = MESSAGE_ID_280050,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move AA: Squirt
    .nameMsg = MESSAGE_ID_2B0019,
    .fullDescMsg = MESSAGE_ID_280058,
    .shortDescMsg = MESSAGE_ID_280051,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_14,
    .costFP = 3,
    .costBP = 0
},
{   // move AB: WaterBlock
    .nameMsg = MESSAGE_ID_2B001A,
    .fullDescMsg = MESSAGE_ID_280059,
    .shortDescMsg = MESSAGE_ID_280052,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 3,
    .costBP = 0
},
{   // move AC: TidalWave
    .nameMsg = MESSAGE_ID_2B001B,
    .fullDescMsg = MESSAGE_ID_28005A,
    .shortDescMsg = MESSAGE_ID_280053,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_8,
    .costFP = 6,
    .costBP = 0
},
{   // move AD: SpinyFlip1
    .nameMsg = MESSAGE_ID_2B001C,
    .fullDescMsg = MESSAGE_ID_280062,
    .shortDescMsg = MESSAGE_ID_28005D,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move AE: SpinyFlip2
    .nameMsg = MESSAGE_ID_2B001C,
    .fullDescMsg = MESSAGE_ID_280063,
    .shortDescMsg = MESSAGE_ID_28005D,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move AF: SpinyFlip3
    .nameMsg = MESSAGE_ID_2B001C,
    .fullDescMsg = MESSAGE_ID_280064,
    .shortDescMsg = MESSAGE_ID_28005D,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move B0: SpinySurge
    .nameMsg = MESSAGE_ID_2B001D,
    .fullDescMsg = MESSAGE_ID_280065,
    .shortDescMsg = MESSAGE_ID_28005E,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 4,
    .costBP = 0
},
{   // move B1: CloudNine
    .nameMsg = MESSAGE_ID_2B001E,
    .fullDescMsg = MESSAGE_ID_280066,
    .shortDescMsg = MESSAGE_ID_28005F,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 4,
    .costBP = 0
},
{   // move B2: Hurricane
    .nameMsg = MESSAGE_ID_2B001F,
    .fullDescMsg = MESSAGE_ID_280067,
    .shortDescMsg = MESSAGE_ID_280060,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_12,
    .costFP = 5,
    .costBP = 0
},
{   // move B3: Smack1
    .nameMsg = MESSAGE_ID_2B0010,
    .fullDescMsg = MESSAGE_ID_28003B,
    .shortDescMsg = MESSAGE_ID_280036,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B4: Smack2
    .nameMsg = MESSAGE_ID_2B0010,
    .fullDescMsg = MESSAGE_ID_28003C,
    .shortDescMsg = MESSAGE_ID_280036,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B5: Smack3
    .nameMsg = MESSAGE_ID_2B0010,
    .fullDescMsg = MESSAGE_ID_28003D,
    .shortDescMsg = MESSAGE_ID_280036,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B6: OuttaSight
    .nameMsg = MESSAGE_ID_2B0011,
    .fullDescMsg = MESSAGE_ID_28003E,
    .shortDescMsg = MESSAGE_ID_280037,
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 0
},
{   // move B7: Spook
    .nameMsg = MESSAGE_ID_2B0012,
    .fullDescMsg = MESSAGE_ID_28003F,
    .shortDescMsg = MESSAGE_ID_280038,
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 3,
    .costBP = 0
},
{   // move B8: FanSmack
    .nameMsg = MESSAGE_ID_2B0013,
    .fullDescMsg = MESSAGE_ID_280040,
    .shortDescMsg = MESSAGE_ID_280039,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 5,
    .costBP = 0
},
};
