.include "macro.inc"

.section .data

dlabel D_80242EB0_89D200
.word 0x40000000, 0x0000003C, 0x00000005, 0x42A00000, 0x42700000, 0x00000003, 0x41100000, 0x00000000, 0x00000000, 0x42B40000, 0x428C0000, 0x00000001

dlabel D_80242EE0_89D230
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000D, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000001, 0x00000043, 0x00000002, tik_20_LungeAI_Main, D_80242EB0_89D200, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242F50_89D2A0
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_80242EE0_89D230, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00120000

dlabel D_80242F7C_89D2CC
.word 0x00000000, D_80242F50_89D2A0, 0xC2480000, 0xC1A00000, 0x42C80000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80140090, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0xFFFFFFCE, 0xFFFFFFEC, 0x00000064, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFCE, 0xFFFFFFEC, 0x00000064, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x0029000B, 0x0029000B, 0x00290007, 0x00290006, 0x00290008, 0x00290000, 0x00290004, 0x00290004, 0x00290004, 0x00290004, 0x00000002, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024316C_89D4BC
.word 0x00000001, D_80242F50_89D2A0, 0x437A0000, 0xC1A00000, 0x42C80000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80140090, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0x000000FA, 0xFFFFFFEC, 0x00000064, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000FA, 0xFFFFFFEC, 0x00000064, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x0029000B, 0x0029000B, 0x00290007, 0x00290006, 0x00290008, 0x00290000, 0x00290004, 0x00290004, 0x00290004, 0x00290004, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242F7C_89D2CC, 0x1A040004, 0x00000001, D_8024316C_89D4BC, 0x1A050004, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EA564, 0x000001DB, 0x00000046, 0xFFFFFF9C, 0x00000000, 0x00000083, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405D1A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
