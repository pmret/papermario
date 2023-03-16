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
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 2: Unused_02
    .nameMsg = 0,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3: Hammer1
    .nameMsg = MSG_Menus_Hammer,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_ItemShortDesc_Hammer,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 4: Hammer2
    .nameMsg = MSG_Menus_Hammer,
    .fullDescMsg = MSG_ItemShortDesc_SuperHammer,
    .shortDescMsg = MSG_ItemShortDesc_SuperHammer,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 5: Hammer3
    .nameMsg = MSG_Menus_Hammer,
    .fullDescMsg = MSG_ItemShortDesc_UltraHammer,
    .shortDescMsg = MSG_ItemShortDesc_UltraHammer,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 6: Unused_Hammer4
    .nameMsg = MSG_Menus_Hammer,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 7: Unused_Hammer5
    .nameMsg = MSG_MoveName_Berserker,
    .fullDescMsg = MSG_ItemFullDesc_Berserker,
    .shortDescMsg = MSG_ItemShortDesc_Berserker,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8: SpinSmash
    .nameMsg = MSG_PlayerMoveName_SpinSmash,
    .fullDescMsg = MSG_ItemFullDesc_SpinSmash,
    .shortDescMsg = MSG_ItemShortDesc_SpinSmash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move 9: QuakeHammer
    .nameMsg = MSG_PlayerMoveName_QuakeHammer,
    .fullDescMsg = MSG_ItemFullDesc_QuakeHammer,
    .shortDescMsg = MSG_ItemShortDesc_QuakeHammer,
    .flags = TARGET_FLAG_20 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move A: DDownPound
    .nameMsg = MSG_PlayerMoveName_DDownPound,
    .fullDescMsg = MSG_ItemFullDesc_DDownPound,
    .shortDescMsg = MSG_ItemShortDesc_DDownPound,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 2
},
{   // move B: SmashCharge0
    .nameMsg = MSG_MoveName_SmashCharge0,
    .fullDescMsg = MSG_ItemFullDesc_SmashCharge0,
    .shortDescMsg = MSG_ItemShortDesc_SmashCharge0,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move C: Unused_Hammer_0C
    .nameMsg = MSG_Menus_Hammer,
    .fullDescMsg = MSG_ItemFullDesc_SmashCharge0,
    .shortDescMsg = MSG_ItemShortDesc_SmashCharge0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_1000 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move D: HammerThrow
    .nameMsg = MSG_PlayerMoveName_HammerThrow,
    .fullDescMsg = MSG_ItemFullDesc_HammerThrow,
    .shortDescMsg = MSG_ItemShortDesc_HammerThrow,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 2
},
{   // move E: MegaQuake
    .nameMsg = MSG_PlayerMoveName_MegaQuake,
    .fullDescMsg = MSG_ItemFullDesc_MegaQuake,
    .shortDescMsg = MSG_ItemShortDesc_MegaQuake,
    .flags = TARGET_FLAG_20 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 7,
    .costBP = 3
},
{   // move F: SmashCharge
    .nameMsg = MSG_PlayerMoveName_SmashCharge,
    .fullDescMsg = MSG_ItemFullDesc_SmashCharge,
    .shortDescMsg = MSG_ItemShortDesc_SmashCharge,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 10: Unused_Hammer_10
    .nameMsg = MSG_Menus_Hammer,
    .fullDescMsg = MSG_ItemFullDesc_SmashCharge,
    .shortDescMsg = MSG_ItemShortDesc_SmashCharge,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 11: SuperSmashCharge
    .nameMsg = MSG_PlayerMoveName_SuperSmashCharge,
    .fullDescMsg = MSG_ItemFullDesc_SSmashChg,
    .shortDescMsg = MSG_ItemShortDesc_SSmashChg,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 4,
    .costBP = 2
},
{   // move 12: Unused_Hammer_12
    .nameMsg = MSG_Menus_Hammer,
    .fullDescMsg = MSG_ItemFullDesc_SSmashChg,
    .shortDescMsg = MSG_ItemShortDesc_SSmashChg,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_1000 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 13: AutoSmash
    .nameMsg = MSG_MoveName_AutoSmash,
    .fullDescMsg = MSG_ItemFullDesc_AutoSmash,
    .shortDescMsg = MSG_ItemShortDesc_AutoSmash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 1
},
{   // move 14: PowerQuake
    .nameMsg = MSG_PlayerMoveName_PowerQuake,
    .fullDescMsg = MSG_ItemFullDesc_PowerQuake,
    .shortDescMsg = MSG_ItemShortDesc_PowerQuake,
    .flags = TARGET_FLAG_20 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 4,
    .costBP = 2
},
{   // move 15: PowerSmash
    .nameMsg = MSG_PlayerMoveName_PowerSmash,
    .fullDescMsg = MSG_ItemFullDesc_PowerSmash,
    .shortDescMsg = MSG_ItemShortDesc_PowerSmash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move 16: SuperSmash
    .nameMsg = MSG_MoveName_SuperSmash,
    .fullDescMsg = MSG_ItemFullDesc_SuperSmash,
    .shortDescMsg = MSG_ItemShortDesc_SuperSmash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 4,
    .costBP = 2
},
{   // move 17: MegaSmash
    .nameMsg = MSG_PlayerMoveName_MegaSmash,
    .fullDescMsg = MSG_ItemFullDesc_MegaSmash,
    .shortDescMsg = MSG_ItemShortDesc_MegaSmash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 6,
    .costBP = 3
},
{   // move 18: ShrinkSmash
    .nameMsg = MSG_PlayerMoveName_ShrinkSmash,
    .fullDescMsg = MSG_ItemFullDesc_ShrinkSmash,
    .shortDescMsg = MSG_ItemShortDesc_ShrinkSmash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 2,
    .costBP = 1
},
{   // move 19: ShellCrack
    .nameMsg = MSG_ItemName_ShellCrack,
    .fullDescMsg = MSG_ItemFullDesc_ShellCrack,
    .shortDescMsg = MSG_ItemShortDesc_ShellCrack,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_1000 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_HAMMER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 6,
    .costBP = 3
},
{   // move 1A: Jump1
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = MSG_ItemShortDesc_Jump,
    .shortDescMsg = MSG_ItemShortDesc_Jump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1B: Jump2
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = MSG_ItemShortDesc_SpinJump,
    .shortDescMsg = MSG_ItemShortDesc_SpinJump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1C: Jump3
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = MSG_ItemShortDesc_TornadoJump,
    .shortDescMsg = MSG_ItemShortDesc_TornadoJump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1D: Unused_Jump4
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1E: Unused_Jump5
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = MSG_ItemFullDesc_Berserker,
    .shortDescMsg = MSG_ItemShortDesc_Berserker,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 1F: Multibounce
    .nameMsg = MSG_PlayerMoveName_Multibounce,
    .fullDescMsg = MSG_ItemFullDesc_Multibounce,
    .shortDescMsg = MSG_ItemShortDesc_Multibounce,
    .flags = TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_8000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 20: PowerBounce
    .nameMsg = MSG_PlayerMoveName_PowerBounce,
    .fullDescMsg = MSG_ItemFullDesc_PowerBounce,
    .shortDescMsg = MSG_ItemShortDesc_PowerBounce,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 3,
    .costBP = 2
},
{   // move 21: SleepStomp
    .nameMsg = MSG_PlayerMoveName_SleepStomp,
    .fullDescMsg = MSG_ItemFullDesc_SleepStomp,
    .shortDescMsg = MSG_ItemShortDesc_SleepStomp,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 22: DizzyStomp
    .nameMsg = MSG_PlayerMoveName_DizzyStomp,
    .fullDescMsg = MSG_ItemFullDesc_DizzyStomp,
    .shortDescMsg = MSG_ItemShortDesc_DizzyStomp,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 23: JumpCharge0
    .nameMsg = MSG_MoveName_JumpCharge0,
    .fullDescMsg = MSG_ItemFullDesc_JumpCharge0,
    .shortDescMsg = MSG_ItemShortDesc_JumpCharge0,
    .flags = TARGET_FLAG_PLAYER | TARGET_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 24: Unused_24
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = MSG_ItemFullDesc_JumpCharge0,
    .shortDescMsg = MSG_ItemShortDesc_JumpCharge0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 1,
    .costBP = 1
},
{   // move 25: JumpCharge
    .nameMsg = MSG_PlayerMoveName_JumpCharge,
    .fullDescMsg = MSG_ItemFullDesc_JumpCharge,
    .shortDescMsg = MSG_ItemShortDesc_JumpCharge,
    .flags = TARGET_FLAG_PLAYER | TARGET_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 26: Unused_26
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = MSG_ItemFullDesc_JumpCharge,
    .shortDescMsg = MSG_ItemShortDesc_JumpCharge,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 27: SuperJumpCharge
    .nameMsg = MSG_PlayerMoveName_SuperJumpCharge,
    .fullDescMsg = MSG_ItemFullDesc_SJumpChg,
    .shortDescMsg = MSG_ItemShortDesc_SJumpChg,
    .flags = TARGET_FLAG_PLAYER | TARGET_FLAG_800,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 4,
    .costBP = 2
},
{   // move 28: Unused_28
    .nameMsg = MSG_Menus_Jump,
    .fullDescMsg = MSG_ItemFullDesc_SJumpChg,
    .shortDescMsg = MSG_ItemShortDesc_SJumpChg,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 29: AutoJump
    .nameMsg = MSG_MoveName_AutoJump,
    .fullDescMsg = MSG_ItemFullDesc_AutoJump,
    .shortDescMsg = MSG_ItemShortDesc_AutoJump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 1
},
{   // move 2A: AutoMultibounce
    .nameMsg = MSG_MoveName_AutoMultibounce,
    .fullDescMsg = MSG_ItemFullDesc_AutoMultibounce,
    .shortDescMsg = MSG_ItemShortDesc_AutoMultibounce,
    .flags = TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_8000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 5,
    .costBP = 2
},
{   // move 2B: PowerJump
    .nameMsg = MSG_PlayerMoveName_PowerJump,
    .fullDescMsg = MSG_ItemFullDesc_PowerJump,
    .shortDescMsg = MSG_ItemShortDesc_PowerJump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 2C: SuperJump
    .nameMsg = MSG_MoveName_SuperJump,
    .fullDescMsg = MSG_ItemFullDesc_SuperJump,
    .shortDescMsg = MSG_ItemShortDesc_SuperJump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 4,
    .costBP = 2
},
{   // move 2D: MegaJump
    .nameMsg = MSG_PlayerMoveName_MegaJump,
    .fullDescMsg = MSG_ItemFullDesc_MegaJump,
    .shortDescMsg = MSG_ItemShortDesc_MegaJump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 6,
    .costBP = 3
},
{   // move 2E: DDownJump
    .nameMsg = MSG_PlayerMoveName_DDownJump,
    .fullDescMsg = MSG_ItemFullDesc_DDownJump,
    .shortDescMsg = MSG_ItemShortDesc_DDownJump,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 2
},
{   // move 2F: ShrinkStomp
    .nameMsg = MSG_PlayerMoveName_ShrinkStomp,
    .fullDescMsg = MSG_ItemFullDesc_ShrinkStomp,
    .shortDescMsg = MSG_ItemShortDesc_ShrinkStomp,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 2,
    .costBP = 1
},
{   // move 30: EarthquakeJump
    .nameMsg = MSG_MoveName_EarthquakeJump,
    .fullDescMsg = MSG_ItemFullDesc_EarthquakeJump,
    .shortDescMsg = MSG_ItemShortDesc_EarthquakeJump,
    .flags = TARGET_FLAG_20 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_JUMP,
    .actionTip = MOVE_ACTION_TIP_20,
    .costFP = 2,
    .costBP = 2
},
{   // move 31: Unused_DefendPlus
    .nameMsg = MSG_MoveName_DefendPlus,
    .fullDescMsg = MSG_ItemFullDesc_DefendPlus,
    .shortDescMsg = MSG_ItemShortDesc_DefendPlus,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_3,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 32: Unused_32
    .nameMsg = MSG_MoveName_32,
    .fullDescMsg = MSG_FullDesc_32,
    .shortDescMsg = MSG_ShortDesc_32,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_3,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 8
},
{   // move 33: DamageDodge
    .nameMsg = MSG_ItemName_DamageDodge,
    .fullDescMsg = MSG_ItemFullDesc_DamageDodge,
    .shortDescMsg = MSG_ItemShortDesc_DamageDodge,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_3,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 34: Items
    .nameMsg = MSG_Menus_Items,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_Action_UseItem,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 35: DoubleDip
    .nameMsg = MSG_PlayerMoveName_DoubleDip,
    .fullDescMsg = MSG_ItemFullDesc_DoubleDip,
    .shortDescMsg = MSG_ItemShortDesc_DoubleDip,
    .flags = 0,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 3,
    .costBP = 1
},
{   // move 36: TripleDip
    .nameMsg = MSG_PlayerMoveName_TripleDip,
    .fullDescMsg = MSG_ItemFullDesc_TripleDip,
    .shortDescMsg = MSG_ItemShortDesc_TripleDip,
    .flags = 0,
    .category = MOVE_TYPE_ITEMS,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 6,
    .costBP = 3
},
{   // move 37: Unused_37
    .nameMsg = (s32) "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_SWITCH,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 38: QuickChange
    .nameMsg = MSG_PlayerMoveName_QuickChange,
    .fullDescMsg = MSG_ItemFullDesc_QuickChange,
    .shortDescMsg = MSG_ItemShortDesc_QuickChange,
    .flags = 0,
    .category = MOVE_TYPE_SWITCH,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 39: Unused_39
    .nameMsg = (s32) "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_6,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3A: Unused_3A
    .nameMsg = (s32) "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 3B: PowerPlus
    .nameMsg = MSG_ItemName_PowerPlus,
    .fullDescMsg = MSG_ItemFullDesc_PowerPlus,
    .shortDescMsg = MSG_ItemShortDesc_PowerPlus,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 3C: AllorNothing
    .nameMsg = MSG_ItemName_AllorNothing,
    .fullDescMsg = MSG_ItemFullDesc_AllorNothing,
    .shortDescMsg = MSG_ItemShortDesc_AllorNothing,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 3D: IcePower
    .nameMsg = MSG_ItemName_IcePower,
    .fullDescMsg = MSG_ItemFullDesc_IcePower,
    .shortDescMsg = MSG_ItemShortDesc_IcePower,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 3E: PUpDDown
    .nameMsg = MSG_PlayerMoveName_PUpDDown,
    .fullDescMsg = MSG_ItemFullDesc_PUpDDown,
    .shortDescMsg = MSG_ItemShortDesc_PUpDDown,
    .flags = 0,
    .category = MOVE_TYPE_ATTACK_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 3F: Unused_3F
    .nameMsg = (s32) "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 40: SpikeShield
    .nameMsg = MSG_ItemName_SpikeShield,
    .fullDescMsg = MSG_ItemFullDesc_SpikeShield,
    .shortDescMsg = MSG_ItemShortDesc_SpikeShield,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 41: FireShield
    .nameMsg = MSG_ItemName_FireShield,
    .fullDescMsg = MSG_ItemFullDesc_FireShield,
    .shortDescMsg = MSG_ItemShortDesc_FireShield,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 42: PrettyLucky
    .nameMsg = MSG_ItemName_PrettyLucky,
    .fullDescMsg = MSG_ItemFullDesc_PrettyLucky,
    .shortDescMsg = MSG_ItemShortDesc_PrettyLucky,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 43: FeelingFine
    .nameMsg = MSG_ItemName_FeelingFine,
    .fullDescMsg = MSG_ItemFullDesc_FeelingFine,
    .shortDescMsg = MSG_ItemShortDesc_FeelingFine,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 44: ZapTap
    .nameMsg = MSG_ItemName_ZapTap,
    .fullDescMsg = MSG_ItemFullDesc_ZapTap,
    .shortDescMsg = MSG_ItemShortDesc_ZapTap,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 4
},
{   // move 45: DefendPlus
    .nameMsg = MSG_ItemName_DefendPlus,
    .fullDescMsg = MSG_ItemFullDesc_DefendPlus,
    .shortDescMsg = MSG_ItemShortDesc_DefendPlus,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 46: LastStand
    .nameMsg = MSG_MoveName_LastStand,
    .fullDescMsg = MSG_ItemFullDesc_LastStand,
    .shortDescMsg = MSG_ItemShortDesc_LastStand,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 47: CloseCall
    .nameMsg = MSG_MoveName_CloseCall,
    .fullDescMsg = MSG_ItemFullDesc_CloseCall,
    .shortDescMsg = MSG_ItemShortDesc_CloseCall,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 48: LuckyDay
    .nameMsg = MSG_MoveName_LuckyDay,
    .fullDescMsg = MSG_ItemFullDesc_LuckyDay,
    .shortDescMsg = MSG_ItemShortDesc_LuckyDay,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 7
},
{   // move 49: PDownDUp
    .nameMsg = MSG_PlayerMoveName_PDownDUp,
    .fullDescMsg = MSG_ItemFullDesc_PDownDUp,
    .shortDescMsg = MSG_ItemShortDesc_PDownDUp,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 4A: HealthyHealthy
    .nameMsg = MSG_MoveName_HealthyHealthy,
    .fullDescMsg = MSG_ItemFullDesc_HealthyHealthy,
    .shortDescMsg = MSG_ItemShortDesc_HealthyHealthy,
    .flags = 0,
    .category = MOVE_TYPE_DEFENSE_UP,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 4B: Unused_4B
    .nameMsg = (s32) "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 4C: DodgeMaster
    .nameMsg = MSG_ItemName_DodgeMaster,
    .fullDescMsg = MSG_ItemFullDesc_DodgeMaster,
    .shortDescMsg = MSG_ItemShortDesc_DodgeMaster,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 4D: FirstAttack
    .nameMsg = MSG_ItemName_FirstAttack,
    .fullDescMsg = MSG_ItemFullDesc_FirstAttack,
    .shortDescMsg = MSG_ItemShortDesc_FirstAttack,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 4E: SlowGo
    .nameMsg = MSG_ItemName_SlowGo,
    .fullDescMsg = MSG_ItemFullDesc_SlowGo,
    .shortDescMsg = MSG_ItemShortDesc_SlowGo,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 4F: RightOn
    .nameMsg = MSG_ItemName_RightOn,
    .fullDescMsg = MSG_ItemFullDesc_RightOn,
    .shortDescMsg = MSG_ItemShortDesc_RightOn,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 8
},
{   // move 50: BumpAttack
    .nameMsg = MSG_MoveName_BumpAttack,
    .fullDescMsg = MSG_ItemFullDesc_BumpAttack,
    .shortDescMsg = MSG_ItemShortDesc_BumpAttack,
    .flags = 0,
    .category = MOVE_TYPE_9,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 5
},
{   // move 51: Unused_51
    .nameMsg = (s32) "つうじょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 52: HPPlus
    .nameMsg = MSG_ItemName_HPPlus,
    .fullDescMsg = MSG_ItemFullDesc_HPPlus,
    .shortDescMsg = MSG_ItemShortDesc_HPPlus,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 53: MysteryScroll
    .nameMsg = MSG_ItemName_MysteryScroll,
    .fullDescMsg = MSG_ItemFullDesc_MysteryScroll,
    .shortDescMsg = MSG_ItemShortDesc_MysteryScroll,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 54: AttackFXA
    .nameMsg = MSG_ItemName_AttackFXA,
    .fullDescMsg = MSG_ItemFullDesc_AttackFXA,
    .shortDescMsg = MSG_ItemShortDesc_AttackFXA,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 55: AttackFXD
    .nameMsg = MSG_ItemName_AttackFXD,
    .fullDescMsg = MSG_ItemFullDesc_AttackFXD,
    .shortDescMsg = MSG_ItemShortDesc_AttackFXD,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 56: AttackFXB
    .nameMsg = MSG_ItemName_AttackFXB,
    .fullDescMsg = MSG_ItemFullDesc_AttackFXB,
    .shortDescMsg = MSG_ItemShortDesc_AttackFXB,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 57: AttackFXE
    .nameMsg = MSG_ItemName_AttackFXE,
    .fullDescMsg = MSG_ItemFullDesc_AttackFXE,
    .shortDescMsg = MSG_ItemShortDesc_AttackFXE,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 58: AttackFXC
    .nameMsg = MSG_ItemName_AttackFXC,
    .fullDescMsg = MSG_ItemFullDesc_AttackFXC,
    .shortDescMsg = MSG_ItemShortDesc_AttackFXC,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 59: AttackFXF
    .nameMsg = MSG_ItemName_AttackFXF,
    .fullDescMsg = MSG_ItemFullDesc_AttackFXF,
    .shortDescMsg = MSG_ItemShortDesc_AttackFXF,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 5A: HPDrain
    .nameMsg = MSG_ItemName_HPDrain,
    .fullDescMsg = MSG_ItemFullDesc_HPDrain,
    .shortDescMsg = MSG_ItemShortDesc_HPDrain,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5B: FPPlus
    .nameMsg = MSG_ItemName_FPPlus,
    .fullDescMsg = MSG_ItemFullDesc_FPPlus,
    .shortDescMsg = MSG_ItemShortDesc_FPPlus,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5C: MoneyMoney
    .nameMsg = MSG_ItemName_MoneyMoney,
    .fullDescMsg = MSG_ItemFullDesc_MoneyMoney,
    .shortDescMsg = MSG_ItemShortDesc_MoneyMoney,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 7
},
{   // move 5D: ChillOutBadge
    .nameMsg = MSG_ItemName_ChillOut,
    .fullDescMsg = MSG_ItemFullDesc_ChillOut,
    .shortDescMsg = MSG_ItemShortDesc_ChillOut,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 5E: HappyHeart
    .nameMsg = MSG_ItemName_HappyHeart,
    .fullDescMsg = MSG_ItemFullDesc_HappyHeart,
    .shortDescMsg = MSG_ItemShortDesc_HappyHeart,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 5F: MegaRush
    .nameMsg = MSG_ItemName_MegaRush,
    .fullDescMsg = MSG_ItemFullDesc_MegaRush,
    .shortDescMsg = MSG_ItemShortDesc_MegaRush,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 60: Berserker
    .nameMsg = MSG_ItemName_Berserker,
    .fullDescMsg = MSG_ItemFullDesc_Berserker,
    .shortDescMsg = MSG_ItemShortDesc_Berserker,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 8
},
{   // move 61: RunawayPay
    .nameMsg = MSG_ItemName_RunawayPay,
    .fullDescMsg = MSG_ItemFullDesc_RunawayPay,
    .shortDescMsg = MSG_ItemShortDesc_RunawayPay,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 62: FlowerSaver
    .nameMsg = MSG_ItemName_FlowerSaver,
    .fullDescMsg = MSG_ItemFullDesc_FlowerSaver,
    .shortDescMsg = MSG_ItemShortDesc_FlowerSaver,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 6
},
{   // move 63: PayOff
    .nameMsg = MSG_ItemName_PayOff,
    .fullDescMsg = MSG_ItemFullDesc_PayOff,
    .shortDescMsg = MSG_ItemShortDesc_PayOff,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 64: PowerRush
    .nameMsg = MSG_MoveName_PowerRush,
    .fullDescMsg = MSG_ItemFullDesc_PowerRush,
    .shortDescMsg = MSG_ItemShortDesc_PowerRush,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 65: CrazyHeart
    .nameMsg = MSG_MoveName_CrazyHeart,
    .fullDescMsg = MSG_ItemFullDesc_CrazyHeart,
    .shortDescMsg = MSG_ItemShortDesc_CrazyHeart,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 10
},
{   // move 66: MegaHPDrain
    .nameMsg = MSG_MoveName_MegaHPDrain,
    .fullDescMsg = MSG_ItemFullDesc_MegaHPDrain,
    .shortDescMsg = MSG_ItemShortDesc_MegaHPDrain,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 10
},
{   // move 67: FlowerFanatic
    .nameMsg = MSG_MoveName_FlowerFanatic,
    .fullDescMsg = MSG_ItemFullDesc_FlowerFanatic,
    .shortDescMsg = MSG_ItemShortDesc_FlowerFanatic,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 10
},
{   // move 68: HeartFinder
    .nameMsg = MSG_MoveName_HeartFinder,
    .fullDescMsg = MSG_ItemFullDesc_HeartFinder,
    .shortDescMsg = MSG_ItemShortDesc_HeartFinder,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 69: FlowerFinder
    .nameMsg = MSG_MoveName_FlowerFinder,
    .fullDescMsg = MSG_ItemFullDesc_FlowerFinder,
    .shortDescMsg = MSG_ItemShortDesc_FlowerFinder,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 6A: SpinAttack
    .nameMsg = MSG_MoveName_SpinAttack,
    .fullDescMsg = MSG_ItemFullDesc_SpinAttack,
    .shortDescMsg = MSG_ItemShortDesc_SpinAttack,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 6B: DizzyAttack
    .nameMsg = MSG_MoveName_DizzyAttack,
    .fullDescMsg = MSG_ItemFullDesc_DizzyAttack,
    .shortDescMsg = MSG_ItemShortDesc_DizzyAttack,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 6C: ISpy
    .nameMsg = MSG_MoveName_ISpy,
    .fullDescMsg = MSG_ItemFullDesc_ISpy,
    .shortDescMsg = MSG_ItemShortDesc_ISpy,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6D: SpeedySpin
    .nameMsg = MSG_MoveName_SpeedySpin,
    .fullDescMsg = MSG_ItemFullDesc_SpeedySpin,
    .shortDescMsg = MSG_ItemShortDesc_SpeedySpin,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6E: Refund
    .nameMsg = MSG_ItemName_Refund,
    .fullDescMsg = MSG_ItemFullDesc_Refund,
    .shortDescMsg = MSG_ItemShortDesc_Refund,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 6F: Unused_FinalGoompa
    .nameMsg = (s32) "ファイナルクリジイ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 70: Unused_FinalBobomb
    .nameMsg = (s32) "ファイナルボムヘイ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 71: DeepFocus
    .nameMsg = MSG_ItemName_DeepFocus,
    .fullDescMsg = MSG_ItemFullDesc_DeepFocus,
    .shortDescMsg = MSG_ItemShortDesc_DeepFocus,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 1
},
{   // move 72: SuperFocus
    .nameMsg = MSG_ItemName_SuperFocus,
    .fullDescMsg = MSG_ItemFullDesc_SuperFocus,
    .shortDescMsg = MSG_ItemShortDesc_SuperFocus,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 5
},
{   // move 73: Kaiden
    .nameMsg = MSG_ItemName_Kaiden,
    .fullDescMsg = MSG_ItemFullDesc_Kaiden,
    .shortDescMsg = MSG_ItemShortDesc_Kaiden,
    .flags = TARGET_FLAG_80000000,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 74: HappyFlower
    .nameMsg = MSG_ItemName_HappyFlower,
    .fullDescMsg = MSG_ItemFullDesc_HappyFlower,
    .shortDescMsg = MSG_ItemShortDesc_HappyFlower,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 75: GroupFocus
    .nameMsg = MSG_ItemName_GroupFocus,
    .fullDescMsg = MSG_ItemFullDesc_GroupFocus,
    .shortDescMsg = MSG_ItemShortDesc_GroupFocus,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 2
},
{   // move 76: Peekaboo
    .nameMsg = MSG_ItemName_Peekaboo,
    .fullDescMsg = MSG_ItemFullDesc_Peekaboo,
    .shortDescMsg = MSG_ItemShortDesc_Peekaboo,
    .flags = TARGET_FLAG_2,
    .category = MOVE_TYPE_NONE,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 3
},
{   // move 77: Focus
    .nameMsg = MSG_Menus_StarPower_Focus,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_Focus,
    .flags = TARGET_FLAG_80000000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 78: Refresh
    .nameMsg = MSG_Menus_StarPower_Refresh,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_Refresh,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 79: Lullaby
    .nameMsg = MSG_Menus_StarPower_Lullaby,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_Lullaby,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 1
},
{   // move 7A: StarStorm
    .nameMsg = MSG_Menus_StarPower_StarStorm,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_StarStorm,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7B: ChillOutMove
    .nameMsg = MSG_Menus_StarPower_ChillOut,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_ChillOut,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7C: Smooch
    .nameMsg = MSG_Menus_StarPower_Smooch,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_Smooch,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 3,
    .costBP = 3
},
{   // move 7D: TimeOut
    .nameMsg = MSG_Menus_StarPower_TimeOut,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_TimeOut,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7E: UpAndAway
    .nameMsg = MSG_Menus_StarPower_UpAndAway,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_UpAndAway,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 2
},
{   // move 7F: StarBeam
    .nameMsg = MSG_Menus_StarPower_StarBeam,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_StarBeam,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 80: PeachBeam
    .nameMsg = MSG_Menus_StarPower_PeachBeam,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_PeachBeam,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 81: PeachFocus
    .nameMsg = MSG_Menus_StarPower_Peach_Focus,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_Focus,
    .flags = TARGET_FLAG_100,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 82: TwinkDash
    .nameMsg = MSG_Menus_StarPower_Twink_Dash,
    .fullDescMsg = 0,
    .shortDescMsg = MSG_Menus_StarPowerDesc_Focus,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_STAR_POWER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 83: Headbonk1
    .nameMsg = MSG_PartnerMoveName_Headbonk1,
    .fullDescMsg = MSG_PartnerDesc_Goombario_Pause_Headbonk1,
    .shortDescMsg = MSG_PartnerDesc_Goombario_Battle_Headbonk,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 84: Headbonk2
    .nameMsg = MSG_PartnerMoveName_Headbonk2,
    .fullDescMsg = MSG_PartnerDesc_Goombario_Pause_Headbonk2,
    .shortDescMsg = MSG_PartnerDesc_Goombario_Battle_Headbonk,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 85: Headbonk3
    .nameMsg = MSG_PartnerMoveName_Headbonk3,
    .fullDescMsg = MSG_PartnerDesc_Goombario_Pause_Headbonk3,
    .shortDescMsg = MSG_PartnerDesc_Goombario_Battle_Headbonk,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 0,
    .costBP = 0
},
{   // move 86: Tattle
    .nameMsg = MSG_PartnerMoveName_Tattle,
    .fullDescMsg = MSG_PartnerDesc_Goombario_Pause_Tattle,
    .shortDescMsg = MSG_PartnerDesc_Goombario_Battle_Tattle,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2 | TARGET_FLAG_8000 | TARGET_FLAG_10000 | TARGET_FLAG_20000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 0,
    .costBP = 0
},
{   // move 87: Charge
    .nameMsg = MSG_PartnerMoveName_Charge,
    .fullDescMsg = MSG_PartnerDesc_Goombario_Pause_Charge,
    .shortDescMsg = MSG_PartnerDesc_Goombario_Battle_Charge,
    .flags = TARGET_FLAG_100,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 1,
    .costBP = 0
},
{   // move 88: Multibonk
    .nameMsg = MSG_PartnerMoveName_Multibonk,
    .fullDescMsg = MSG_PartnerDesc_Goombario_Pause_Multibonk,
    .shortDescMsg = MSG_PartnerDesc_Goombario_Battle_Multibonk,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_2,
    .costFP = 3,
    .costBP = 0
},
{   // move 89: ShellToss1
    .nameMsg = MSG_PartnerMoveName_ShellToss1,
    .fullDescMsg = MSG_PartnerDesc_Kooper_Pause_ShellToss1,
    .shortDescMsg = MSG_PartnerDesc_Kooper_Battle_ShellToss,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8A: ShellToss2
    .nameMsg = MSG_PartnerMoveName_ShellToss2,
    .fullDescMsg = MSG_PartnerDesc_Kooper_Pause_ShellToss2,
    .shortDescMsg = MSG_PartnerDesc_Kooper_Battle_ShellToss,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8B: ShellToss3
    .nameMsg = MSG_PartnerMoveName_ShellToss3,
    .fullDescMsg = MSG_PartnerDesc_Kooper_Pause_ShellToss3,
    .shortDescMsg = MSG_PartnerDesc_Kooper_Battle_ShellToss,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move 8C: PowerShell
    .nameMsg = MSG_PartnerMoveName_PowerShell,
    .fullDescMsg = MSG_PartnerDesc_Kooper_Pause_PowerShell,
    .shortDescMsg = MSG_PartnerDesc_Kooper_Battle_PowerShell,
    .flags = TARGET_FLAG_4 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 3,
    .costBP = 0
},
{   // move 8D: DizzyShell
    .nameMsg = MSG_PartnerMoveName_DizzyShell,
    .fullDescMsg = MSG_PartnerDesc_Kooper_Pause_DizzyShell,
    .shortDescMsg = MSG_PartnerDesc_Kooper_Battle_DizzyShell,
    .flags = TARGET_FLAG_4 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 4,
    .costBP = 0
},
{   // move 8E: FireShell
    .nameMsg = MSG_PartnerMoveName_FireShell,
    .fullDescMsg = MSG_PartnerDesc_Kooper_Pause_FireShell,
    .shortDescMsg = MSG_PartnerDesc_Kooper_Battle_FireShell,
    .flags = TARGET_FLAG_4 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 5,
    .costBP = 0
},
{   // move 8F: BodySlam1
    .nameMsg = MSG_PartnerMoveName_BodySlam1,
    .fullDescMsg = MSG_PartnerDesc_Bombette_Pause_BodySlam1,
    .shortDescMsg = MSG_PartnerDesc_Bombette_Battle_BodySlam,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 90: BodySlam2
    .nameMsg = MSG_PartnerMoveName_BodySlam2,
    .fullDescMsg = MSG_PartnerDesc_Bombette_Pause_BodySlam2,
    .shortDescMsg = MSG_PartnerDesc_Bombette_Battle_BodySlam,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 91: BodySlam3
    .nameMsg = MSG_PartnerMoveName_BodySlam3,
    .fullDescMsg = MSG_PartnerDesc_Bombette_Pause_BodySlam3,
    .shortDescMsg = MSG_PartnerDesc_Bombette_Battle_BodySlam,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move 92: Bomb
    .nameMsg = MSG_PartnerMoveName_Bomb,
    .fullDescMsg = MSG_PartnerDesc_Bombette_Pause_Bomb,
    .shortDescMsg = MSG_PartnerDesc_Bombette_Battle_Bomb,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_4 | TARGET_FLAG_2000 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 3,
    .costBP = 0
},
{   // move 93: PowerBomb
    .nameMsg = MSG_PartnerMoveName_PowerBomb,
    .fullDescMsg = MSG_PartnerDesc_Bombette_Pause_PowerBomb,
    .shortDescMsg = MSG_PartnerDesc_Bombette_Battle_PowerBomb,
    .flags = TARGET_FLAG_4 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 6,
    .costBP = 0
},
{   // move 94: MegaBomb
    .nameMsg = MSG_PartnerMoveName_MegaBomb,
    .fullDescMsg = MSG_PartnerDesc_Bombette_Pause_MegaBomb,
    .shortDescMsg = MSG_PartnerDesc_Bombette_Battle_MegaBomb,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 8,
    .costBP = 0
},
{   // move 95: SkyDive1
    .nameMsg = MSG_PartnerMoveName_SkyDive1,
    .fullDescMsg = MSG_PartnerDesc_Parakarry_Pause_SkyDive1,
    .shortDescMsg = MSG_PartnerDesc_Parakarry_Battle_SkyDive,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 96: SkyDive2
    .nameMsg = MSG_PartnerMoveName_SkyDive2,
    .fullDescMsg = MSG_PartnerDesc_Parakarry_Pause_SkyDive2,
    .shortDescMsg = MSG_PartnerDesc_Parakarry_Battle_SkyDive,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 97: SkyDive3
    .nameMsg = MSG_PartnerMoveName_SkyDive3,
    .fullDescMsg = MSG_PartnerDesc_Parakarry_Pause_SkyDive3,
    .shortDescMsg = MSG_PartnerDesc_Parakarry_Battle_SkyDive,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 98: ShellShot
    .nameMsg = MSG_PartnerMoveName_ShellShot,
    .fullDescMsg = MSG_PartnerDesc_Parakarry_Pause_ShellShot,
    .shortDescMsg = MSG_PartnerDesc_Parakarry_Battle_ShellShot,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2 | TARGET_FLAG_10000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_5,
    .costFP = 3,
    .costBP = 0
},
{   // move 99: AirLift
    .nameMsg = MSG_PartnerMoveName_AirLift,
    .fullDescMsg = MSG_PartnerDesc_Parakarry_Pause_AirLift,
    .shortDescMsg = MSG_PartnerDesc_Parakarry_Battle_AirLift,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2 | TARGET_FLAG_400 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 3,
    .costBP = 0
},
{   // move 9A: AirRaid
    .nameMsg = MSG_PartnerMoveName_AirRaid,
    .fullDescMsg = MSG_PartnerDesc_Parakarry_Pause_AirRaid,
    .shortDescMsg = MSG_PartnerDesc_Parakarry_Battle_AirRaid,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 6,
    .costBP = 0
},
{   // move 9B: Unused_LoneFool1
    .nameMsg = (s32) "ひとりぼけ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9C: Unused_LoneFool2
    .nameMsg = (s32) "ひとりぼけ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9D: Unused_LoneFool3
    .nameMsg = (s32) "ひとりぼけ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9E: Unused_Mumble
    .nameMsg = (s32) "むにゃむにゃ",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_4,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move 9F: Unused_Preach
    .nameMsg = (s32) "せっきょう",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move A0: Unused_Awakening
    .nameMsg = (s32) "かくせい",
    .fullDescMsg = 0,
    .shortDescMsg = 0,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_0,
    .costFP = 0,
    .costBP = 0
},
{   // move A1: ElectroDash1
    .nameMsg = MSG_PartnerMoveName_ElectroDash1,
    .fullDescMsg = MSG_PartnerDesc_Watt_Pause_ElectroDash1,
    .shortDescMsg = MSG_PartnerDesc_Watt_Battle_ElectroDash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A2: ElectroDash2
    .nameMsg = MSG_PartnerMoveName_ElectroDash2,
    .fullDescMsg = MSG_PartnerDesc_Watt_Pause_ElectroDash2,
    .shortDescMsg = MSG_PartnerDesc_Watt_Battle_ElectroDash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A3: ElectroDash3
    .nameMsg = MSG_PartnerMoveName_ElectroDash3,
    .fullDescMsg = MSG_PartnerDesc_Watt_Pause_ElectroDash3,
    .shortDescMsg = MSG_PartnerDesc_Watt_Battle_ElectroDash,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_15,
    .costFP = 0,
    .costBP = 0
},
{   // move A4: PowerShock
    .nameMsg = MSG_PartnerMoveName_PowerShock,
    .fullDescMsg = MSG_PartnerDesc_Watt_Pause_PowerShock,
    .shortDescMsg = MSG_PartnerDesc_Watt_Battle_PowerShock,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_3,
    .costFP = 2,
    .costBP = 0
},
{   // move A5: TurboCharge
    .nameMsg = MSG_PartnerMoveName_TurboCharge,
    .fullDescMsg = MSG_PartnerDesc_Watt_Pause_TurboCharge,
    .shortDescMsg = MSG_PartnerDesc_Watt_Battle_TurboCharge,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 3,
    .costBP = 0
},
{   // move A6: MegaShock
    .nameMsg = MSG_PartnerMoveName_MegaShock,
    .fullDescMsg = MSG_PartnerDesc_Watt_Pause_MegaShock,
    .shortDescMsg = MSG_PartnerDesc_Watt_Battle_MegaShock,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_12,
    .costFP = 5,
    .costBP = 0
},
{   // move A7: BellyFlop1
    .nameMsg = MSG_PartnerMoveName_BellyFlop1,
    .fullDescMsg = MSG_PartnerDesc_Sushie_Pause_BellyFlop1,
    .shortDescMsg = MSG_PartnerDesc_Sushie_Battle_BellyFlop,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move A8: BellyFlop2
    .nameMsg = MSG_PartnerMoveName_BellyFlop2,
    .fullDescMsg = MSG_PartnerDesc_Sushie_Pause_BellyFlop2,
    .shortDescMsg = MSG_PartnerDesc_Sushie_Battle_BellyFlop,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move A9: BellyFlop3
    .nameMsg = MSG_PartnerMoveName_BellyFlop3,
    .fullDescMsg = MSG_PartnerDesc_Sushie_Pause_BellyFlop3,
    .shortDescMsg = MSG_PartnerDesc_Sushie_Battle_BellyFlop,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_80 | TARGET_FLAG_800 | TARGET_FLAG_4000 | TARGET_FLAG_10000 | TARGET_FLAG_40000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_1,
    .costFP = 0,
    .costBP = 0
},
{   // move AA: Squirt
    .nameMsg = MSG_PartnerMoveName_Squirt,
    .fullDescMsg = MSG_PartnerDesc_Sushie_Pause_Squirt,
    .shortDescMsg = MSG_PartnerDesc_Sushie_Battle_Squirt,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_14,
    .costFP = 3,
    .costBP = 0
},
{   // move AB: WaterBlock
    .nameMsg = MSG_PartnerMoveName_WaterBlock,
    .fullDescMsg = MSG_PartnerDesc_Sushie_Pause_WaterBlock,
    .shortDescMsg = MSG_PartnerDesc_Sushie_Battle_WaterBlock,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 3,
    .costBP = 0
},
{   // move AC: TidalWave
    .nameMsg = MSG_PartnerMoveName_TidalWave,
    .fullDescMsg = MSG_PartnerDesc_Sushie_Pause_TidalWave,
    .shortDescMsg = MSG_PartnerDesc_Sushie_Battle_TidalWave,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_8,
    .costFP = 6,
    .costBP = 0
},
{   // move AD: SpinyFlip1
    .nameMsg = MSG_PartnerMoveName_SpinyFlip1,
    .fullDescMsg = MSG_PartnerDesc_Lakilester_Pause_SpinyFlip1,
    .shortDescMsg = MSG_PartnerDesc_Lakilester_Battle_SpinyFlip,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move AE: SpinyFlip2
    .nameMsg = MSG_PartnerMoveName_SpinyFlip2,
    .fullDescMsg = MSG_PartnerDesc_Lakilester_Pause_SpinyFlip2,
    .shortDescMsg = MSG_PartnerDesc_Lakilester_Battle_SpinyFlip,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move AF: SpinyFlip3
    .nameMsg = MSG_PartnerMoveName_SpinyFlip3,
    .fullDescMsg = MSG_PartnerDesc_Lakilester_Pause_SpinyFlip3,
    .shortDescMsg = MSG_PartnerDesc_Lakilester_Battle_SpinyFlip,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_16,
    .costFP = 0,
    .costBP = 0
},
{   // move B0: SpinySurge
    .nameMsg = MSG_PartnerMoveName_SpinySurge,
    .fullDescMsg = MSG_PartnerDesc_Lakilester_Pause_SpinySurge,
    .shortDescMsg = MSG_PartnerDesc_Lakilester_Battle_SpinySurge,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 4,
    .costBP = 0
},
{   // move B1: CloudNine
    .nameMsg = MSG_PartnerMoveName_CloudNine,
    .fullDescMsg = MSG_PartnerDesc_Lakilester_Pause_CloudNine,
    .shortDescMsg = MSG_PartnerDesc_Lakilester_Battle_CloudNine,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_10,
    .costFP = 4,
    .costBP = 0
},
{   // move B2: Hurricane
    .nameMsg = MSG_PartnerMoveName_Hurricane,
    .fullDescMsg = MSG_PartnerDesc_Lakilester_Pause_Hurricane,
    .shortDescMsg = MSG_PartnerDesc_Lakilester_Battle_Hurricane,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_12,
    .costFP = 5,
    .costBP = 0
},
{   // move B3: Smack1
    .nameMsg = MSG_PartnerMoveName_Smack1,
    .fullDescMsg = MSG_PartnerDesc_Bow_Pause_Smack1,
    .shortDescMsg = MSG_PartnerDesc_Bow_Battle_Smack,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B4: Smack2
    .nameMsg = MSG_PartnerMoveName_Smack2,
    .fullDescMsg = MSG_PartnerDesc_Bow_Pause_Smack2,
    .shortDescMsg = MSG_PartnerDesc_Bow_Battle_Smack,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B5: Smack3
    .nameMsg = MSG_PartnerMoveName_Smack3,
    .fullDescMsg = MSG_PartnerDesc_Bow_Pause_Smack3,
    .shortDescMsg = MSG_PartnerDesc_Bow_Battle_Smack,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 0,
    .costBP = 0
},
{   // move B6: OuttaSight
    .nameMsg = MSG_PartnerMoveName_OuttaSight,
    .fullDescMsg = MSG_PartnerDesc_Bow_Pause_OuttaSight,
    .shortDescMsg = MSG_PartnerDesc_Bow_Battle_OuttaSight,
    .flags = TARGET_FLAG_PLAYER,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_NONE,
    .costFP = 2,
    .costBP = 0
},
{   // move B7: Spook
    .nameMsg = MSG_PartnerMoveName_Spook,
    .fullDescMsg = MSG_PartnerDesc_Bow_Pause_Spook,
    .shortDescMsg = MSG_PartnerDesc_Bow_Battle_Spook,
    .flags = TARGET_FLAG_2 | TARGET_FLAG_8000,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 3,
    .costBP = 0
},
{   // move B8: FanSmack
    .nameMsg = MSG_PartnerMoveName_FanSmack,
    .fullDescMsg = MSG_PartnerDesc_Bow_Pause_FanSmack,
    .shortDescMsg = MSG_PartnerDesc_Bow_Battle_FanSmack,
    .flags = TARGET_FLAG_ENEMY | TARGET_FLAG_2,
    .category = MOVE_TYPE_PARTNER,
    .actionTip = MOVE_ACTION_TIP_4,
    .costFP = 5,
    .costBP = 0
},
};
