.include "macro.inc"

.section .data

dlabel D_80242DE0_9B9760
.word 0x3FC00000, 0x0000002D, 0x00000014, 0x428C0000, 0x42480000, 0x0000000A, 0x40F00000, 0x00000000, 0x00000000, 0x42A00000, 0x42700000, 0x00000001

dlabel D_80242E10_9B9790
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000000, 0x00000043, 0x00000002, trd_07_UnkNpcAIMainFunc5, D_80242DE0_9B9760, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242E80_9B9800
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_80242E10_9B9790, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

dlabel trd_07_sixFloats
.float 4.5, 3.5, 2.6, 2.0, 1.5, 20.0

dlabel D_80242EC4_9B9844
.word 0x40000000, 0x0000001E, 0x0000001E, 0x42C80000, 0x41A00000, 0x0000000A, 0x40266666, 0x0000003C, 0x0000000A, 0x43160000, 0x41A00000, 0x00000001

dlabel D_80242EF4_9B9874
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0xFFFFFD76, 0x00000043, 0x00000003, SetSelfVar, 0x00000006, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000258, 0x00000043, 0x00000002, func_8024231C_9B8C9C, D_80242EC4_9B9844, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242F64_9B98E4
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, D_80242EF4_9B9874, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060001

dlabel D_80242F90_9B9910
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_8024256C_9B8EEC, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xF8405E1A, 0x00000001, 0x00000044, 0x00000001, 0x8024475C, 0x00000013, 0x00000000, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, func_80045900, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243070_9B99F0
.word 0x00000043, 0x00000002, SetSelfEnemyFlags, 0x00800000, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80242F90_9B9910, 0x0000000A, 0x00000002, 0xF8405E1A, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802430CC_9B9A4C
.word 0x00000000, D_80242E80_9B9800, 0xC2960000, 0x00000000, 0xC1F00000, 0x00040C00, D_80243070_9B99F0, 0x00000000, 0x00000000, 0x0000005A, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0xFFFFFFB5, 0x00000000, 0xFFFFFFE2, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000003E8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802432BC_9B9C3C
.word 0x00000001, D_80242F64_9B98E4, 0x00000000, 0x42480000, 0x41F00000, 0x00040C00, D_80243070_9B99F0, 0x00000000, 0x00000000, 0x0000010E, 0x80050090, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0x00000000, 0x00000032, 0x0000001E, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000032, 0x0000001E, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002A0101, 0x002A0102, 0x002A0103, 0x002A0103, 0x002A0101, 0x002A0101, 0x002A0106, 0x002A0106, 0x002A0104, 0x002A010C, 0x002A010A, 0x002A010E, 0x002A0103, 0x002A0103, 0x002A0103, 0x002A0103, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802434AC_9B9E2C
.word 0x00000002, D_80242F64_9B98E4, 0x42960000, 0x42480000, 0xC1F00000, 0x00040C00, D_80243070_9B99F0, 0x00000000, 0x00000000, 0x0000010E, 0x80050090, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0x0000004B, 0x00000032, 0xFFFFFFE2, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000004B, 0x00000032, 0xFFFFFFE2, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002A0101, 0x002A0102, 0x002A0103, 0x002A0103, 0x002A0101, 0x002A0101, 0x002A0106, 0x002A0106, 0x002A0104, 0x002A010C, 0x002A010A, 0x002A010E, 0x002A0103, 0x002A0103, 0x002A0103, 0x002A0103, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802430CC_9B9A4C, 0x06010004, 0x00000001, D_802432BC_9B9C3C, 0x06080004, 0x00000001, D_802434AC_9B9E2C, 0x060A0004, 0x00000000, 0x00000000, 0x00000000, 0x00000000
