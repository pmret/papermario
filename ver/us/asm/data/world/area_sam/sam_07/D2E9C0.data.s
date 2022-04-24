.include "macro.inc"

.section .data

dlabel D_80242C90_D2E9C0
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242D4C_D2EA7C
.word 0x3F000000, 0x0000003C, 0x0000000F, 0x42C80000, 0x00000000, 0x0000000A, 0x40600000, 0x000000B4, 0x00000014, 0x43160000, 0x00000000, 0x00000001

dlabel D_80242D7C_D2EAAC
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x0000000D, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000001E, 0x00000043, 0x00000002, sam_07_WanderMeleeAI_Main, D_80242D4C_D2EA7C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242DEC_D2EB1C
.word 0x00000000, 0x00300024, 0x00000000, 0x00000000, D_80242D7C_D2EAAC, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00160000

dlabel D_80242E18_D2EB48
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000037, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000020, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x00000000, 0x00000043, 0x00000001, sam_07_MeleeHitbox_Main, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242EC0_D2EBF0
.word 0x00000000, 0x00200016, 0x00000000, 0x00000000, D_80242E18_D2EB48, 0x00000000, 0x00000000, D_80242C90_D2E9C0, 0x00000000, 0x00000000, 0x00160008

dlabel D_80242EEC_D2EC1C
.word 0x00520000, 0xFFFFFFFF, 0x00520000, 0x00520001, 0x0052000B, 0x00520004, 0x00520002, 0x00520003, 0xFFFFFFFF

dlabel D_80242F10_D2EC40
.word 0x00000000, 0x0000001E, 0x0000001E, 0x43160000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242F40_D2EC70
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000008, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000009, 0x00000009, 0x00000043, 0x00000003, SetSelfVar, 0x0000000A, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x0000000B, 0x00000007, 0x00000043, 0x00000003, SetSelfVar, 0x0000000C, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x0000000D, 0x0000000F, 0x00000043, 0x00000003, SetSelfVar, 0x0000000E, 0x00000012, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x0000000F, 0x00000043, 0x00000002, sam_07_PiranhaAI_Main, D_80242F10_D2EC40, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243014_D2ED44
.word 0x00000000, 0x00320024, 0x00000000, 0x00000000, D_80242F40_D2EC70, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00160000

dlabel D_80243040_D2ED70
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x0000000E, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x000020DE, 0x00000043, 0x00000001, sam_07_MeleeHitbox_Main, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, GetSelfAnimationFromTable, 0x00000007, 0xFE363C80, 0x00000046, 0x00000001, 0x800936DC, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024314C_D2EE7C
.word 0x00000000, 0x0014001C, 0x00000000, 0x00000000, D_80243040_D2ED70, 0x00000000, 0x00000000, D_80242C90_D2E9C0, 0x00000000, 0x00000000, 0x00160000

dlabel D_80243178_D2EEA8
.word 0x00360100, 0xFFFFFFFF, 0x00360100, 0x00360101, 0x0036010E, 0x00360105, 0x00360106, 0x00360118, 0x00360117, 0xFFFFFFFF

dlabel D_802431A0_D2EED0
.word 0x00000000, D_80242DEC_D2EB1C, 0xC3FA0000, 0xC3160000, 0xC2960000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050085, 0x00020000, 0x008C0008, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0xFFFFFE0C, 0xFFFFFF6A, 0xFFFFFFB5, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFE0C, 0xFFFFFF6A, 0xFFFFFFB5, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00520001, 0x00520002, 0x00520003, 0x00520003, 0x00520001, 0x00520001, 0x0052000B, 0x0052000B, 0x00520004, 0x00520004, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242EC0_D2EBF0, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00520001, 0x00520002, 0x00520003, 0x00520003, 0x00520001, 0x00520001, 0x0052000B, 0x0052000B, 0x00520004, 0x00520004, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00000000, 0x00000000, D_80242EEC_D2EC1C, 0x00000000

dlabel D_80243580_D2F2B0
.word 0x00000002, D_80243014_D2ED44, 0x437A0000, 0x42F00000, 0xC2960000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0004, 0x33322666, 0x33320004, 0x33323FFF, 0x33320004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0x000000FA, 0x00000078, 0xFFFFFFB5, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000014A, 0x00000078, 0xFFFFFFBF, 0x00000104, 0x00000041, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360101, 0x00360102, 0x00360103, 0x00360103, 0x00360101, 0x00360101, 0x0036010E, 0x0036010E, 0x00360118, 0x00360117, 0x00360105, 0x00360106, 0x00360112, 0x00360113, 0x00360114, 0x00360101, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_8024314C_D2EE7C, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360101, 0x00360102, 0x00360103, 0x00360103, 0x00360101, 0x00360101, 0x0036010E, 0x0036010E, 0x00360118, 0x00360117, 0x00360105, 0x00360106, 0x00360112, 0x00360113, 0x00360114, 0x00360101, 0x00000000, 0x00000000, D_80243178_D2EEA8, 0x00000000

dlabel D_80243960_D2F690
.word 0x00000004, D_80243014_D2ED44, 0x43C80000, 0x42F00000, 0xC2960000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0004, 0x33322666, 0x33320004, 0x33323FFF, 0x33320004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0x00000190, 0x00000078, 0xFFFFFFB5, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000014A, 0x00000078, 0xFFFFFFBF, 0x00000104, 0x00000041, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360101, 0x00360102, 0x00360103, 0x00360103, 0x00360101, 0x00360101, 0x0036010E, 0x0036010E, 0x00360118, 0x00360117, 0x00360105, 0x00360106, 0x00360112, 0x00360113, 0x00360114, 0x00360101, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000005, D_8024314C_D2EE7C, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360101, 0x00360102, 0x00360103, 0x00360103, 0x00360101, 0x00360101, 0x0036010E, 0x0036010E, 0x00360118, 0x00360117, 0x00360105, 0x00360106, 0x00360112, 0x00360113, 0x00360114, 0x00360101, 0x00000000, 0x00000000, D_80243178_D2EEA8, 0x00000000, 0x00000002, D_802431A0_D2EED0, 0x1D030003, 0x00000002, D_80243580_D2F2B0, 0x1D090003, 0x00000002, D_80243960_D2F690, 0x1D070003, 0x00000000, 0x00000000, 0x00000000
