.include "macro.inc"

.section .data

dlabel D_80240CE0_9793F0
.word 0x3FE66666, 0x00000028, 0x0000000A, 0x42C80000, 0x00000000, 0x00000003, 0x40400000, 0x0000002D, 0x00000006, 0x43960000, 0x00000000, 0x00000001

dlabel D_80240D10_979420
.word 0x00000043, 0x00000001, isk_02_SetNpcB5_3, 0x00000043, 0x00000002, DoBasicAI, D_80240CE0_9793F0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D3C_97944C
.word 0x00000000, 0x0048000F, 0x00000000, 0x00000000, D_80240D10_979420, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000

dlabel D_80240D68_979478
.word 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x17100000, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000001, 0x00000003, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF9718887, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x17100000, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFFFFFEC5, 0x000001C7, 0x0000000A, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80240D10_979420, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240E74_979584
.word 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x17100000, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000001, 0x00000003, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF9718888, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x17100000, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFFFFFF6F, 0x00000217, 0x0000000A, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80240D10_979420, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F80_979690
.word 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x17100000, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000001, 0x00000003, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF9718889, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x17100000, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000032, 0x00000226, 0x0000000A, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80240D10_979420, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024108C_97979C
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80240D68_979478, 0x00000043, 0x00000002, func_800457C4, 0x00000003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410C0_9797D0
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80240E74_979584, 0x00000043, 0x00000002, func_800457C4, 0x00000003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410F4_979804
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80240F80_979690, 0x00000043, 0x00000002, func_800457C4, 0x00000003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241128_979838
.word 0x00000000, D_80240D3C_97944C, 0xC3940000, 0x00000000, 0x43D28000, 0x00000A00, D_8024108C_97979C, 0x00000000, 0x00000000, 0x00000130, 0x80050089, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x3FFF2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x33326665, 0x3FFF0002, 0x33327FFF, 0x33320002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0xFFFFFED3, 0x00000000, 0x000001AB, 0x000000C8, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFED3, 0x00000000, 0x000001AB, 0x00000190, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00310104, 0x00310108, 0x00310108, 0x00310108, 0x00310104, 0x00310104, 0x0031010C, 0x0031010C, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241318_979A28
.word 0x00000001, D_80240D3C_97944C, 0xC3050000, 0x00000000, 0x43F88000, 0x00000A00, D_802410C0_9797D0, 0x00000000, 0x00000000, 0x0000011C, 0x80050089, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x3FFF2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x33326665, 0x3FFF0002, 0x33327FFF, 0x33320002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0xFFFFFF7A, 0x00000000, 0x000001EF, 0x000000C8, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFF74, 0x00000000, 0x000001FE, 0x00000190, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00310104, 0x00310108, 0x00310108, 0x00310108, 0x00310104, 0x00310104, 0x0031010C, 0x0031010C, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241508_979C18
.word 0x00000002, D_80240D3C_97944C, 0x42340000, 0x00000000, 0x43FC8000, 0x00000A00, D_802410F4_979804, 0x00000000, 0x00000000, 0x00000108, 0x80050089, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x3FFF2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x33326665, 0x3FFF0002, 0x33327FFF, 0x33320002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0x0000002E, 0x00000000, 0x00000202, 0x000000C8, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000002F, 0x00000000, 0x00000206, 0x00000190, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00310104, 0x00310108, 0x00310108, 0x00310108, 0x00310104, 0x00310104, 0x0031010C, 0x0031010C, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00310108, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80241128_979838, 0x0B000006, 0x00000001, D_80241318_979A28, 0x0B000006, 0x00000001, D_80241508_979C18, 0x0B010006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
