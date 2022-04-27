.include "macro.inc"

.section .data

dlabel D_80245570_9AD960
.word 0x3FC00000, 0x0000002D, 0x00000014, 0x428C0000, 0x42480000, 0x0000000A, 0x40F00000, 0x00000000, 0x00000000, 0x42A00000, 0x42700000, 0x00000001

dlabel D_802455A0_9AD990
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000000, 0x00000043, 0x00000002, trd_04_LungeAI_Main, D_80245570_9AD960, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245610_9ADA00
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_802455A0_9AD990, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

dlabel D_8024563C_9ADA2C
.word 0x3FC00000, 0x00000019, 0x00000014, 0x428C0000, 0x42480000, 0x0000000A, 0x40E00000, 0x00000000, 0x00000000, 0x42A00000, 0x42700000, 0x00000001

dlabel D_8024566C_9ADA5C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000002, trd_04_KoopaPatrolAI_Main, D_8024563C_9ADA2C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802456C8_9ADAB8
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_8024566C_9ADA5C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

dlabel trd_04_sixFloats
.float 4.5, 3.5, 2.6, 2.0, 1.5, 20.0

dlabel D_8024570C_9ADAFC
.word 0x40000000, 0x0000001E, 0x0000001E, 0x42C80000, 0x41A00000, 0x0000000A, 0x40266666, 0x0000003C, 0x0000000A, 0x43160000, 0x41A00000, 0x00000001

dlabel D_8024573C_9ADB2C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0xFFFFFD76, 0x00000043, 0x00000003, SetSelfVar, 0x00000006, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000258, 0x00000043, 0x00000002, trd_04_ParatroopaAI_Main, D_8024570C_9ADAFC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802457AC_9ADB9C
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, D_8024573C_9ADB2C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060001

dlabel D_802457D8_9ADBC8
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFA9, 0x00000056, 0x00000000, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000057, 0x00000000, 0x00000046, 0x00000001, 0x80245198, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245850_9ADC40
.word 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFFA9, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_802457D8_9ADBC8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802458A4_9ADC94
.word 0x00000000, D_80245610_9ADA00, 0x00000000, 0x00000000, 0x42FA0000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0x00000000, 0x00000000, 0x0000007D, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x0000007D, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245A94_9ADE84
.word 0x00000000, D_802456C8_9ADAB8, 0x435C0000, 0x00000000, 0x41F00000, 0x00802C00, D_80245850_9ADC40, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x000000DC, 0x00000000, 0x0000001E, 0x000000F0, 0x00000000, 0x000000A0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x000000DC, 0x00000000, 0x0000001E, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245C84_9AE074
.word 0x00000001, D_802457AC_9ADB9C, 0xC0A00000, 0x436D0000, 0x431D0000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050090, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0xFFFFFFFB, 0x000000ED, 0x0000009D, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFFB, 0x000000ED, 0x0000009D, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002A0101, 0x002A0102, 0x002A0103, 0x002A0103, 0x002A0101, 0x002A0101, 0x002A0106, 0x002A0106, 0x002A0104, 0x002A010C, 0x002A010A, 0x002A010E, 0x002A0103, 0x002A0103, 0x002A0103, 0x002A0103, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802458A4_9ADC94, 0x0605000D, 0x00000001, D_80245C84_9AE074, 0x060D0006, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80245A94_9ADE84, 0x0605000D, 0x00000001, D_80245C84_9AE074, 0x060D0006, 0x00000000, 0x00000000, 0x00000000, 0x00000000
