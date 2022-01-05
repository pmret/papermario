.include "macro.inc"

.section .data

dlabel D_80241FA0_8A7A20
.word 0x40000000, 0x0000003C, 0x00000005, 0x42A00000, 0x42700000, 0x00000003, 0x41100000, 0x00000000, 0x00000000, 0x42B40000, 0x428C0000, 0x00000001

dlabel D_80241FD0_8A7A50
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000D, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000001, 0x00000043, 0x00000002, tik_24_UnkNpcAIMainFunc5, D_80241FA0_8A7A20, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242040_8A7AC0
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_80241FD0_8A7A50, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00120000

dlabel D_8024206C_8A7AEC
.word 0x00000000, D_80242040_8A7AC0, 0xC2960000, 0xC1200000, 0x42480000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80140090, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0xFFFFFFB5, 0xFFFFFFF6, 0x00000032, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFB5, 0xFFFFFFF6, 0x00000032, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x0029000B, 0x0029000B, 0x00290007, 0x00290006, 0x00290008, 0x00290000, 0x00290004, 0x00290004, 0x00290004, 0x00290004, 0x00000002, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024225C_8A7CDC
.word 0x00000001, D_80242040_8A7AC0, 0x432F0000, 0xC1200000, 0xC2480000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80140090, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0x000000AF, 0xFFFFFFF6, 0xFFFFFFCE, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000AF, 0xFFFFFFF6, 0xFFFFFFCE, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x00290002, 0x0029000B, 0x0029000B, 0x00290007, 0x00290006, 0x00290008, 0x00290000, 0x00290004, 0x00290004, 0x00290004, 0x00290004, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_8024206C_8A7AEC, 0x1A060001, 0x00000001, D_8024225C_8A7CDC, 0x1A070001, 0x00000000, 0x00000000, 0x00000000
