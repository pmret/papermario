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
    .nameMsg = MESSAGE_ID(0x1D, 0x038),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x23, 0x0A3),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 4: Hammer2
    .nameMsg = MESSAGE_ID(0x1D, 0x038),
    .fullDescMsg = MESSAGE_ID(0x23, 0x0A4),
    .shortDescMsg = MESSAGE_ID(0x23, 0x0A4),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 5: Hammer3
    .nameMsg = MESSAGE_ID(0x1D, 0x038),
    .fullDescMsg = MESSAGE_ID(0x23, 0x0A5),
    .shortDescMsg = MESSAGE_ID(0x23, 0x0A5),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 6: Unused_Hammer4
    .nameMsg = MESSAGE_ID(0x1D, 0x038),
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
    .nameMsg = MESSAGE_ID(0x2A, 0x010),
    .fullDescMsg = MESSAGE_ID(0x25, 0x068),
    .shortDescMsg = MESSAGE_ID(0x23, 0x068),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move 9: QuakeHammer
    .nameMsg = MESSAGE_ID(0x2A, 0x012),
    .fullDescMsg = MESSAGE_ID(0x25, 0x06A),
    .shortDescMsg = MESSAGE_ID(0x23, 0x06A),
    .flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move A: DDownPound
    .nameMsg = MESSAGE_ID(0x2A, 0x011),
    .fullDescMsg = MESSAGE_ID(0x25, 0x069),
    .shortDescMsg = MESSAGE_ID(0x23, 0x069),
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
    .nameMsg = MESSAGE_ID(0x1D, 0x038),
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move D: HammerThrow
    .nameMsg = MESSAGE_ID(0x2A, 0x00E),
    .fullDescMsg = MESSAGE_ID(0x25, 0x066),
    .shortDescMsg = MESSAGE_ID(0x23, 0x066),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 2
},
{   // move E: MegaQuake
    .nameMsg = MESSAGE_ID(0x2A, 0x014),
    .fullDescMsg = MESSAGE_ID(0x25, 0x06C),
    .shortDescMsg = MESSAGE_ID(0x23, 0x06C),
    .flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 7,
    .costBP = 3
},
{   // move F: SmashCharge
    .nameMsg = MESSAGE_ID(0x2A, 0x00C),
    .fullDescMsg = MESSAGE_ID(0x25, 0x064),
    .shortDescMsg = MESSAGE_ID(0x23, 0x064),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 10: Unused_Hammer_10
    .nameMsg = MESSAGE_ID(0x1D, 0x038),
    .fullDescMsg = MESSAGE_ID(0x25, 0x064),
    .shortDescMsg = MESSAGE_ID(0x23, 0x064),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 11: SuperSmashCharge
    .nameMsg = MESSAGE_ID(0x2A, 0x00D),
    .fullDescMsg = MESSAGE_ID(0x25, 0x065),
    .shortDescMsg = MESSAGE_ID(0x23, 0x065),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 4,
    .costBP = 2
},
{   // move 12: Unused_Hammer_12
    .nameMsg = MESSAGE_ID(0x1D, 0x038),
    .fullDescMsg = MESSAGE_ID(0x25, 0x065),
    .shortDescMsg = MESSAGE_ID(0x23, 0x065),
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
    .nameMsg = MESSAGE_ID(0x2A, 0x013),
    .fullDescMsg = MESSAGE_ID(0x25, 0x06B),
    .shortDescMsg = MESSAGE_ID(0x23, 0x06B),
    .flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 4,
    .costBP = 2
},
{   // move 15: PowerSmash
    .nameMsg = MESSAGE_ID(0x2A, 0x00A),
    .fullDescMsg = MESSAGE_ID(0x25, 0x062),
    .shortDescMsg = MESSAGE_ID(0x23, 0x062),
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
    .nameMsg = MESSAGE_ID(0x2A, 0x00B),
    .fullDescMsg = MESSAGE_ID(0x25, 0x063),
    .shortDescMsg = MESSAGE_ID(0x23, 0x063),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 6,
    .costBP = 3
},
{   // move 18: ShrinkSmash
    .nameMsg = MESSAGE_ID(0x2A, 0x00F),
    .fullDescMsg = MESSAGE_ID(0x25, 0x067),
    .shortDescMsg = MESSAGE_ID(0x23, 0x067),
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
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = MESSAGE_ID(0x23, 0x0A0),
    .shortDescMsg = MESSAGE_ID(0x23, 0x0A0),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1B: Jump2
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = MESSAGE_ID(0x23, 0x0A1),
    .shortDescMsg = MESSAGE_ID(0x23, 0x0A1),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1C: Jump3
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = MESSAGE_ID(0x23, 0x0A2),
    .shortDescMsg = MESSAGE_ID(0x23, 0x0A2),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1D: Unused_Jump4
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1E: Unused_Jump5
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1F: Multibounce
    .nameMsg = MESSAGE_ID(0x2A, 0x006),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05E),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05E),
    .flags = MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 20: PowerBounce
    .nameMsg = MESSAGE_ID(0x2A, 0x009),
    .fullDescMsg = MESSAGE_ID(0x25, 0x061),
    .shortDescMsg = MESSAGE_ID(0x23, 0x061),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 3,
    .costBP = 2
},
{   // move 21: SleepStomp
    .nameMsg = MESSAGE_ID(0x2A, 0x004),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05C),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05C),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 22: DizzyStomp
    .nameMsg = MESSAGE_ID(0x2A, 0x005),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05D),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05D),
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
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 1,
    .costBP = 1
},
{   // move 25: JumpCharge
    .nameMsg = MESSAGE_ID(0x2A, 0x002),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05A),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05A),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 26: Unused_26
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05A),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05A),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 27: SuperJumpCharge
    .nameMsg = MESSAGE_ID(0x2A, 0x003),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05B),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05B),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 4,
    .costBP = 2
},
{   // move 28: Unused_28
    .nameMsg = MESSAGE_ID(0x1D, 0x039),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05B),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05B),
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
    .nameMsg = MESSAGE_ID(0x2A, 0x000),
    .fullDescMsg = MESSAGE_ID(0x25, 0x058),
    .shortDescMsg = MESSAGE_ID(0x23, 0x058),
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
    .nameMsg = MESSAGE_ID(0x2A, 0x001),
    .fullDescMsg = MESSAGE_ID(0x25, 0x059),
    .shortDescMsg = MESSAGE_ID(0x23, 0x059),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 6,
    .costBP = 3
},
{   // move 2E: DDownJump
    .nameMsg = MESSAGE_ID(0x2A, 0x008),
    .fullDescMsg = MESSAGE_ID(0x25, 0x060),
    .shortDescMsg = MESSAGE_ID(0x23, 0x060),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 2
},
{   // move 2F: ShrinkStomp
    .nameMsg = MESSAGE_ID(0x2A, 0x007),
    .fullDescMsg = MESSAGE_ID(0x25, 0x05F),
    .shortDescMsg = MESSAGE_ID(0x23, 0x05F),
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
    .fullDescMsg = MESSAGE_ID(0x25, 0x074),
    .shortDescMsg = MESSAGE_ID(0x23, 0x074),
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
    .nameMsg = MESSAGE_ID(0x26, 0x075),
    .fullDescMsg = MESSAGE_ID(0x25, 0x075),
    .shortDescMsg = MESSAGE_ID(0x23, 0x075),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_3,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 34: Items
    .nameMsg = MESSAGE_ID(0x1D, 0x03F),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x0A4),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 35: DoubleDip
    .nameMsg = MESSAGE_ID(0x2A, 0x015),
    .fullDescMsg = MESSAGE_ID(0x25, 0x06D),
    .shortDescMsg = MESSAGE_ID(0x23, 0x06D),
    .flags = 0,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 3,
    .costBP = 1
},
{   // move 36: TripleDip
    .nameMsg = MESSAGE_ID(0x2A, 0x016),
    .fullDescMsg = MESSAGE_ID(0x25, 0x06E),
    .shortDescMsg = MESSAGE_ID(0x23, 0x06E),
    .flags = 0,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 6,
    .costBP = 3
},
{   // move 37: Unused_37
    .nameMsg = 0x80098A04,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_TACTICS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 38: QuickChange
    .nameMsg = MESSAGE_ID(0x2A, 0x018),
    .fullDescMsg = MESSAGE_ID(0x25, 0x070),
    .shortDescMsg = MESSAGE_ID(0x23, 0x070),
    .flags = 0,
    .category = MOVE_TYPE_TACTICS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 39: Unused_39
    .nameMsg = 0x80098A04,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_6,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3A: Unused_3A
    .nameMsg = 0x80098A04,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3B: PowerPlus
    .nameMsg = MESSAGE_ID(0x26, 0x073),
    .fullDescMsg = MESSAGE_ID(0x25, 0x073),
    .shortDescMsg = MESSAGE_ID(0x23, 0x073),
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 3C: AllorNothing
    .nameMsg = MESSAGE_ID(0x26, 0x093),
    .fullDescMsg = MESSAGE_ID(0x25, 0x093),
    .shortDescMsg = MESSAGE_ID(0x23, 0x093),
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 3D: IcePower
    .nameMsg = MESSAGE_ID(0x26, 0x095),
    .fullDescMsg = MESSAGE_ID(0x25, 0x095),
    .shortDescMsg = MESSAGE_ID(0x23, 0x095),
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 3E: PUpDDown
    .nameMsg = MESSAGE_ID(0x2A, 0x019),
    .fullDescMsg = MESSAGE_ID(0x25, 0x076),
    .shortDescMsg = MESSAGE_ID(0x23, 0x076),
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 3F: Unused_3F
    .nameMsg = 0x80098A04,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 40: SpikeShield
    .nameMsg = MESSAGE_ID(0x26, 0x07F),
    .fullDescMsg = MESSAGE_ID(0x25, 0x07F),
    .shortDescMsg = MESSAGE_ID(0x23, 0x07F),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 41: FireShield
    .nameMsg = MESSAGE_ID(0x26, 0x097),
    .fullDescMsg = MESSAGE_ID(0x25, 0x097),
    .shortDescMsg = MESSAGE_ID(0x23, 0x097),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 42: PrettyLucky
    .nameMsg = MESSAGE_ID(0x26, 0x081),
    .fullDescMsg = MESSAGE_ID(0x25, 0x081),
    .shortDescMsg = MESSAGE_ID(0x23, 0x081),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 43: FeelingFine
    .nameMsg = MESSAGE_ID(0x26, 0x08C),
    .fullDescMsg = MESSAGE_ID(0x25, 0x08C),
    .shortDescMsg = MESSAGE_ID(0x23, 0x08C),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 44: ZapTap
    .nameMsg = MESSAGE_ID(0x26, 0x099),
    .fullDescMsg = MESSAGE_ID(0x25, 0x099),
    .shortDescMsg = MESSAGE_ID(0x23, 0x099),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 45: DefendPlus
    .nameMsg = MESSAGE_ID(0x26, 0x074),
    .fullDescMsg = MESSAGE_ID(0x25, 0x074),
    .shortDescMsg = MESSAGE_ID(0x23, 0x074),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 46: LastStand
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x085),
    .shortDescMsg = MESSAGE_ID(0x23, 0x085),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 47: CloseCall
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x083),
    .shortDescMsg = MESSAGE_ID(0x23, 0x083),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 48: LuckyDay
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x082),
    .shortDescMsg = MESSAGE_ID(0x23, 0x082),
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 7
},
{   // move 49: PDownDUp
    .nameMsg = MESSAGE_ID(0x2A, 0x01A),
    .fullDescMsg = MESSAGE_ID(0x25, 0x077),
    .shortDescMsg = MESSAGE_ID(0x23, 0x077),
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
    .nameMsg = 0x80098A04,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 4C: DodgeMaster
    .nameMsg = MESSAGE_ID(0x26, 0x080),
    .fullDescMsg = MESSAGE_ID(0x25, 0x080),
    .shortDescMsg = MESSAGE_ID(0x23, 0x080),
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 4D: FirstAttack
    .nameMsg = MESSAGE_ID(0x26, 0x087),
    .fullDescMsg = MESSAGE_ID(0x25, 0x087),
    .shortDescMsg = MESSAGE_ID(0x23, 0x087),
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 4E: SlowGo
    .nameMsg = MESSAGE_ID(0x26, 0x094),
    .fullDescMsg = MESSAGE_ID(0x25, 0x094),
    .shortDescMsg = MESSAGE_ID(0x23, 0x094),
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 4F: RightOn
    .nameMsg = MESSAGE_ID(0x26, 0x09B),
    .fullDescMsg = MESSAGE_ID(0x25, 0x09B),
    .shortDescMsg = MESSAGE_ID(0x23, 0x09B),
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 8
},
{   // move 50: BumpAttack
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x088),
    .shortDescMsg = MESSAGE_ID(0x23, 0x088),
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 5
},
{   // move 51: Unused_51
    .nameMsg = 0x80098A04,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 52: HPPlus
    .nameMsg = MESSAGE_ID(0x26, 0x071),
    .fullDescMsg = MESSAGE_ID(0x25, 0x071),
    .shortDescMsg = MESSAGE_ID(0x23, 0x071),
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
    .nameMsg = MESSAGE_ID(0x26, 0x08D),
    .fullDescMsg = MESSAGE_ID(0x25, 0x08D),
    .shortDescMsg = MESSAGE_ID(0x23, 0x08D),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 55: AttackFXD
    .nameMsg = MESSAGE_ID(0x26, 0x08E),
    .fullDescMsg = MESSAGE_ID(0x25, 0x08E),
    .shortDescMsg = MESSAGE_ID(0x23, 0x08E),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 56: AttackFXB
    .nameMsg = MESSAGE_ID(0x26, 0x08F),
    .fullDescMsg = MESSAGE_ID(0x25, 0x08F),
    .shortDescMsg = MESSAGE_ID(0x23, 0x08F),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 57: AttackFXE
    .nameMsg = MESSAGE_ID(0x26, 0x090),
    .fullDescMsg = MESSAGE_ID(0x25, 0x090),
    .shortDescMsg = MESSAGE_ID(0x23, 0x090),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 58: AttackFXC
    .nameMsg = MESSAGE_ID(0x26, 0x091),
    .fullDescMsg = MESSAGE_ID(0x25, 0x091),
    .shortDescMsg = MESSAGE_ID(0x23, 0x091),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 59: AttackFXF
    .nameMsg = MESSAGE_ID(0x26, 0x092),
    .fullDescMsg = MESSAGE_ID(0x25, 0x092),
    .shortDescMsg = MESSAGE_ID(0x23, 0x092),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 5A: HPDrain
    .nameMsg = MESSAGE_ID(0x26, 0x078),
    .fullDescMsg = MESSAGE_ID(0x25, 0x078),
    .shortDescMsg = MESSAGE_ID(0x23, 0x078),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5B: FPPlus
    .nameMsg = MESSAGE_ID(0x26, 0x072),
    .fullDescMsg = MESSAGE_ID(0x25, 0x072),
    .shortDescMsg = MESSAGE_ID(0x23, 0x072),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5C: MoneyMoney
    .nameMsg = MESSAGE_ID(0x26, 0x09A),
    .fullDescMsg = MESSAGE_ID(0x25, 0x09A),
    .shortDescMsg = MESSAGE_ID(0x23, 0x09A),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 7
},
{   // move 5D: ChillOutBadge
    .nameMsg = MESSAGE_ID(0x26, 0x098),
    .fullDescMsg = MESSAGE_ID(0x25, 0x098),
    .shortDescMsg = MESSAGE_ID(0x23, 0x098),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 5E: HappyHeart
    .nameMsg = MESSAGE_ID(0x26, 0x079),
    .fullDescMsg = MESSAGE_ID(0x25, 0x079),
    .shortDescMsg = MESSAGE_ID(0x23, 0x079),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5F: MegaRush
    .nameMsg = MESSAGE_ID(0x26, 0x086),
    .fullDescMsg = MESSAGE_ID(0x25, 0x086),
    .shortDescMsg = MESSAGE_ID(0x23, 0x086),
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
    .nameMsg = MESSAGE_ID(0x26, 0x09C),
    .fullDescMsg = MESSAGE_ID(0x25, 0x09C),
    .shortDescMsg = MESSAGE_ID(0x23, 0x09C),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 62: FlowerSaver
    .nameMsg = MESSAGE_ID(0x26, 0x07B),
    .fullDescMsg = MESSAGE_ID(0x25, 0x07B),
    .shortDescMsg = MESSAGE_ID(0x23, 0x07B),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 63: PayOff
    .nameMsg = MESSAGE_ID(0x26, 0x096),
    .fullDescMsg = MESSAGE_ID(0x25, 0x096),
    .shortDescMsg = MESSAGE_ID(0x23, 0x096),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 64: PowerRush
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x084),
    .shortDescMsg = MESSAGE_ID(0x23, 0x084),
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
    .fullDescMsg = MESSAGE_ID(0x25, 0x07C),
    .shortDescMsg = MESSAGE_ID(0x23, 0x07C),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 69: FlowerFinder
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x07D),
    .shortDescMsg = MESSAGE_ID(0x23, 0x07D),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 6A: SpinAttack
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x089),
    .shortDescMsg = MESSAGE_ID(0x23, 0x089),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 6B: DizzyAttack
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x08A),
    .shortDescMsg = MESSAGE_ID(0x23, 0x08A),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 6C: ISpy
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x09E),
    .shortDescMsg = MESSAGE_ID(0x23, 0x09E),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6D: SpeedySpin
    .nameMsg = 0,
    .fullDescMsg = MESSAGE_ID(0x25, 0x08B),
    .shortDescMsg = MESSAGE_ID(0x23, 0x08B),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6E: Refund
    .nameMsg = MESSAGE_ID(0x26, 0x09D),
    .fullDescMsg = MESSAGE_ID(0x25, 0x09D),
    .shortDescMsg = MESSAGE_ID(0x23, 0x09D),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6F: Unused_FinalGoompa
    .nameMsg = 0x800989F0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 70: Unused_FinalBombomb
    .nameMsg = 0x800989DC,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 71: DeepFocus
    .nameMsg = MESSAGE_ID(0x26, 0x07E),
    .fullDescMsg = MESSAGE_ID(0x25, 0x07E),
    .shortDescMsg = MESSAGE_ID(0x23, 0x07E),
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
    .nameMsg = MESSAGE_ID(0x26, 0x07A),
    .fullDescMsg = MESSAGE_ID(0x25, 0x07A),
    .shortDescMsg = MESSAGE_ID(0x23, 0x07A),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 75: GroupFocus
    .nameMsg = MESSAGE_ID(0x26, 0x06F),
    .fullDescMsg = MESSAGE_ID(0x25, 0x06F),
    .shortDescMsg = MESSAGE_ID(0x23, 0x06F),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 76: Peekaboo
    .nameMsg = MESSAGE_ID(0x26, 0x09F),
    .fullDescMsg = MESSAGE_ID(0x25, 0x09F),
    .shortDescMsg = MESSAGE_ID(0x23, 0x09F),
    .flags = MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 77: Focus
    .nameMsg = MESSAGE_ID(0x1D, 0x014),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x020),
    .flags = MOVE_DATA_FLAG_80000000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 78: Refresh
    .nameMsg = MESSAGE_ID(0x1D, 0x015),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x021),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 79: Lullaby
    .nameMsg = MESSAGE_ID(0x1D, 0x016),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x022),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 7A: StarStorm
    .nameMsg = MESSAGE_ID(0x1D, 0x017),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x023),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7B: ChillOutMove
    .nameMsg = MESSAGE_ID(0x1D, 0x018),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x024),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7C: Smooch
    .nameMsg = MESSAGE_ID(0x1D, 0x019),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x025),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 3,
    .costBP = 3
},
{   // move 7D: TimeOut
    .nameMsg = MESSAGE_ID(0x1D, 0x01A),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x026),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7E: UpAndAway
    .nameMsg = MESSAGE_ID(0x1D, 0x01B),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x027),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7F: StarBeam
    .nameMsg = MESSAGE_ID(0x1D, 0x01C),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x028),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 80: PeachBeam
    .nameMsg = MESSAGE_ID(0x1D, 0x01D),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x029),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 81: PeachFocus
    .nameMsg = MESSAGE_ID(0x1D, 0x01E),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x020),
    .flags = MOVE_DATA_FLAG_100,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 82: TwinkDash
    .nameMsg = MESSAGE_ID(0x1D, 0x01F),
    .fullDescMsg = 0,
    .shortDescMsg = MESSAGE_ID(0x1D, 0x020),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 83: Headbonk1
    .nameMsg = MESSAGE_ID(0x2B, 0x000),
    .fullDescMsg = MESSAGE_ID(0x28, 0x007),
    .shortDescMsg = MESSAGE_ID(0x28, 0x002),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 84: Headbonk2
    .nameMsg = MESSAGE_ID(0x2B, 0x000),
    .fullDescMsg = MESSAGE_ID(0x28, 0x008),
    .shortDescMsg = MESSAGE_ID(0x28, 0x002),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 85: Headbonk3
    .nameMsg = MESSAGE_ID(0x2B, 0x000),
    .fullDescMsg = MESSAGE_ID(0x28, 0x009),
    .shortDescMsg = MESSAGE_ID(0x28, 0x002),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 86: Tattle
    .nameMsg = MESSAGE_ID(0x2B, 0x001),
    .fullDescMsg = MESSAGE_ID(0x28, 0x00A),
    .shortDescMsg = MESSAGE_ID(0x28, 0x003),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_20000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 87: Charge
    .nameMsg = MESSAGE_ID(0x2B, 0x002),
    .fullDescMsg = MESSAGE_ID(0x28, 0x00B),
    .shortDescMsg = MESSAGE_ID(0x28, 0x004),
    .flags = MOVE_DATA_FLAG_100,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 0
},
{   // move 88: Multibonk
    .nameMsg = MESSAGE_ID(0x2B, 0x003),
    .fullDescMsg = MESSAGE_ID(0x28, 0x00C),
    .shortDescMsg = MESSAGE_ID(0x28, 0x005),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 3,
    .costBP = 0
},
{   // move 89: ShellToss1
    .nameMsg = MESSAGE_ID(0x2B, 0x004),
    .fullDescMsg = MESSAGE_ID(0x28, 0x014),
    .shortDescMsg = MESSAGE_ID(0x28, 0x00F),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8A: ShellToss2
    .nameMsg = MESSAGE_ID(0x2B, 0x004),
    .fullDescMsg = MESSAGE_ID(0x28, 0x015),
    .shortDescMsg = MESSAGE_ID(0x28, 0x00F),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8B: ShellToss3
    .nameMsg = MESSAGE_ID(0x2B, 0x004),
    .fullDescMsg = MESSAGE_ID(0x28, 0x016),
    .shortDescMsg = MESSAGE_ID(0x28, 0x00F),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8C: PowerShell
    .nameMsg = MESSAGE_ID(0x2B, 0x005),
    .fullDescMsg = MESSAGE_ID(0x28, 0x017),
    .shortDescMsg = MESSAGE_ID(0x28, 0x010),
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 3,
    .costBP = 0
},
{   // move 8D: DizzyShell
    .nameMsg = MESSAGE_ID(0x2B, 0x006),
    .fullDescMsg = MESSAGE_ID(0x28, 0x018),
    .shortDescMsg = MESSAGE_ID(0x28, 0x011),
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 4,
    .costBP = 0
},
{   // move 8E: FireShell
    .nameMsg = MESSAGE_ID(0x2B, 0x007),
    .fullDescMsg = MESSAGE_ID(0x28, 0x019),
    .shortDescMsg = MESSAGE_ID(0x28, 0x012),
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 5,
    .costBP = 0
},
{   // move 8F: BodySlam1
    .nameMsg = MESSAGE_ID(0x2B, 0x008),
    .fullDescMsg = MESSAGE_ID(0x28, 0x021),
    .shortDescMsg = MESSAGE_ID(0x28, 0x01C),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 90: BodySlam2
    .nameMsg = MESSAGE_ID(0x2B, 0x008),
    .fullDescMsg = MESSAGE_ID(0x28, 0x022),
    .shortDescMsg = MESSAGE_ID(0x28, 0x01C),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 91: BodySlam3
    .nameMsg = MESSAGE_ID(0x2B, 0x008),
    .fullDescMsg = MESSAGE_ID(0x28, 0x023),
    .shortDescMsg = MESSAGE_ID(0x28, 0x01C),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 92: Bomb
    .nameMsg = MESSAGE_ID(0x2B, 0x009),
    .fullDescMsg = MESSAGE_ID(0x28, 0x024),
    .shortDescMsg = MESSAGE_ID(0x28, 0x01D),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 3,
    .costBP = 0
},
{   // move 93: PowerBomb
    .nameMsg = MESSAGE_ID(0x2B, 0x00A),
    .fullDescMsg = MESSAGE_ID(0x28, 0x025),
    .shortDescMsg = MESSAGE_ID(0x28, 0x01E),
    .flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 6,
    .costBP = 0
},
{   // move 94: MegaBomb
    .nameMsg = MESSAGE_ID(0x2B, 0x00B),
    .fullDescMsg = MESSAGE_ID(0x28, 0x026),
    .shortDescMsg = MESSAGE_ID(0x28, 0x01F),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 8,
    .costBP = 0
},
{   // move 95: SkyDive1
    .nameMsg = MESSAGE_ID(0x2B, 0x00C),
    .fullDescMsg = MESSAGE_ID(0x28, 0x02E),
    .shortDescMsg = MESSAGE_ID(0x28, 0x029),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 96: SkyDive2
    .nameMsg = MESSAGE_ID(0x2B, 0x00C),
    .fullDescMsg = MESSAGE_ID(0x28, 0x02F),
    .shortDescMsg = MESSAGE_ID(0x28, 0x029),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 97: SkyDive3
    .nameMsg = MESSAGE_ID(0x2B, 0x00C),
    .fullDescMsg = MESSAGE_ID(0x28, 0x030),
    .shortDescMsg = MESSAGE_ID(0x28, 0x029),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 98: ShellShot
    .nameMsg = MESSAGE_ID(0x2B, 0x00D),
    .fullDescMsg = MESSAGE_ID(0x28, 0x031),
    .shortDescMsg = MESSAGE_ID(0x28, 0x02A),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_5,
    .costFP = 3,
    .costBP = 0
},
{   // move 99: AirLift
    .nameMsg = MESSAGE_ID(0x2B, 0x00E),
    .fullDescMsg = MESSAGE_ID(0x28, 0x032),
    .shortDescMsg = MESSAGE_ID(0x28, 0x02B),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_400 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 3,
    .costBP = 0
},
{   // move 9A: AirRaid
    .nameMsg = MESSAGE_ID(0x2B, 0x00F),
    .fullDescMsg = MESSAGE_ID(0x28, 0x033),
    .shortDescMsg = MESSAGE_ID(0x28, 0x02C),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 6,
    .costBP = 0
},
{   // move 9B: Unused_LoneFool1
    .nameMsg = 0x800989D0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9C: Unused_LoneFool2
    .nameMsg = 0x800989D0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9D: Unused_LoneFool3
    .nameMsg = 0x800989D0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9E: Unused_Mumble
    .nameMsg = 0x800989C0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_4,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9F: Unused_Preach
    .nameMsg = 0x800989B4,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move A0: Unused_Awakening
    .nameMsg = 0x800989A8,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move A1: ElectroDash1
    .nameMsg = MESSAGE_ID(0x2B, 0x014),
    .fullDescMsg = MESSAGE_ID(0x28, 0x048),
    .shortDescMsg = MESSAGE_ID(0x28, 0x043),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A2: ElectroDash2
    .nameMsg = MESSAGE_ID(0x2B, 0x014),
    .fullDescMsg = MESSAGE_ID(0x28, 0x049),
    .shortDescMsg = MESSAGE_ID(0x28, 0x043),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A3: ElectroDash3
    .nameMsg = MESSAGE_ID(0x2B, 0x014),
    .fullDescMsg = MESSAGE_ID(0x28, 0x04A),
    .shortDescMsg = MESSAGE_ID(0x28, 0x043),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A4: PowerShock
    .nameMsg = MESSAGE_ID(0x2B, 0x015),
    .fullDescMsg = MESSAGE_ID(0x28, 0x04B),
    .shortDescMsg = MESSAGE_ID(0x28, 0x044),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 2,
    .costBP = 0
},
{   // move A5: TurboCharge
    .nameMsg = MESSAGE_ID(0x2B, 0x016),
    .fullDescMsg = MESSAGE_ID(0x28, 0x04C),
    .shortDescMsg = MESSAGE_ID(0x28, 0x045),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 3,
    .costBP = 0
},
{   // move A6: MegaShock
    .nameMsg = MESSAGE_ID(0x2B, 0x017),
    .fullDescMsg = MESSAGE_ID(0x28, 0x04D),
    .shortDescMsg = MESSAGE_ID(0x28, 0x046),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_12,
    .costFP = 5,
    .costBP = 0
},
{   // move A7: BellyFlop1
    .nameMsg = MESSAGE_ID(0x2B, 0x018),
    .fullDescMsg = MESSAGE_ID(0x28, 0x055),
    .shortDescMsg = MESSAGE_ID(0x28, 0x050),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move A8: BellyFlop2
    .nameMsg = MESSAGE_ID(0x2B, 0x018),
    .fullDescMsg = MESSAGE_ID(0x28, 0x056),
    .shortDescMsg = MESSAGE_ID(0x28, 0x050),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move A9: BellyFlop3
    .nameMsg = MESSAGE_ID(0x2B, 0x018),
    .fullDescMsg = MESSAGE_ID(0x28, 0x057),
    .shortDescMsg = MESSAGE_ID(0x28, 0x050),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move AA: Squirt
    .nameMsg = MESSAGE_ID(0x2B, 0x019),
    .fullDescMsg = MESSAGE_ID(0x28, 0x058),
    .shortDescMsg = MESSAGE_ID(0x28, 0x051),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_14,
    .costFP = 3,
    .costBP = 0
},
{   // move AB: WaterBlock
    .nameMsg = MESSAGE_ID(0x2B, 0x01A),
    .fullDescMsg = MESSAGE_ID(0x28, 0x059),
    .shortDescMsg = MESSAGE_ID(0x28, 0x052),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 3,
    .costBP = 0
},
{   // move AC: TidalWave
    .nameMsg = MESSAGE_ID(0x2B, 0x01B),
    .fullDescMsg = MESSAGE_ID(0x28, 0x05A),
    .shortDescMsg = MESSAGE_ID(0x28, 0x053),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_8,
    .costFP = 6,
    .costBP = 0
},
{   // move AD: SpinyFlip1
    .nameMsg = MESSAGE_ID(0x2B, 0x01C),
    .fullDescMsg = MESSAGE_ID(0x28, 0x062),
    .shortDescMsg = MESSAGE_ID(0x28, 0x05D),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move AE: SpinyFlip2
    .nameMsg = MESSAGE_ID(0x2B, 0x01C),
    .fullDescMsg = MESSAGE_ID(0x28, 0x063),
    .shortDescMsg = MESSAGE_ID(0x28, 0x05D),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move AF: SpinyFlip3
    .nameMsg = MESSAGE_ID(0x2B, 0x01C),
    .fullDescMsg = MESSAGE_ID(0x28, 0x064),
    .shortDescMsg = MESSAGE_ID(0x28, 0x05D),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move B0: SpinySurge
    .nameMsg = MESSAGE_ID(0x2B, 0x01D),
    .fullDescMsg = MESSAGE_ID(0x28, 0x065),
    .shortDescMsg = MESSAGE_ID(0x28, 0x05E),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 4,
    .costBP = 0
},
{   // move B1: CloudNine
    .nameMsg = MESSAGE_ID(0x2B, 0x01E),
    .fullDescMsg = MESSAGE_ID(0x28, 0x066),
    .shortDescMsg = MESSAGE_ID(0x28, 0x05F),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 4,
    .costBP = 0
},
{   // move B2: Hurricane
    .nameMsg = MESSAGE_ID(0x2B, 0x01F),
    .fullDescMsg = MESSAGE_ID(0x28, 0x067),
    .shortDescMsg = MESSAGE_ID(0x28, 0x060),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_12,
    .costFP = 5,
    .costBP = 0
},
{   // move B3: Smack1
    .nameMsg = MESSAGE_ID(0x2B, 0x010),
    .fullDescMsg = MESSAGE_ID(0x28, 0x03B),
    .shortDescMsg = MESSAGE_ID(0x28, 0x036),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B4: Smack2
    .nameMsg = MESSAGE_ID(0x2B, 0x010),
    .fullDescMsg = MESSAGE_ID(0x28, 0x03C),
    .shortDescMsg = MESSAGE_ID(0x28, 0x036),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B5: Smack3
    .nameMsg = MESSAGE_ID(0x2B, 0x010),
    .fullDescMsg = MESSAGE_ID(0x28, 0x03D),
    .shortDescMsg = MESSAGE_ID(0x28, 0x036),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B6: OuttaSight
    .nameMsg = MESSAGE_ID(0x2B, 0x011),
    .fullDescMsg = MESSAGE_ID(0x28, 0x03E),
    .shortDescMsg = MESSAGE_ID(0x28, 0x037),
    .flags = MOVE_DATA_FLAG_TARGET_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 0
},
{   // move B7: Spook
    .nameMsg = MESSAGE_ID(0x2B, 0x012),
    .fullDescMsg = MESSAGE_ID(0x28, 0x03F),
    .shortDescMsg = MESSAGE_ID(0x28, 0x038),
    .flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 3,
    .costBP = 0
},
{   // move B8: FanSmack
    .nameMsg = MESSAGE_ID(0x2B, 0x013),
    .fullDescMsg = MESSAGE_ID(0x28, 0x040),
    .shortDescMsg = MESSAGE_ID(0x28, 0x039),
    .flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 5,
    .costBP = 0
},
};
