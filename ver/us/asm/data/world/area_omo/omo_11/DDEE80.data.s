.include "macro.inc"

.section .data

dlabel D_80242650_DDEE80
.word 0x40400000, 0x0000001E, 0x0000003C, 0x42C80000, 0x41F00000, 0x00000004, 0x40A00000, 0x00000008, 0x00000001, 0x430C0000, 0x41F00000, 0x00000001

dlabel D_80242680_DDEEB0
.word 0x00000043, 0x00000002, DoBasicAI, D_80242650_DDEE80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802426A0_DDEED0
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_80242680_DDEEB0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000F0000

dlabel D_802426CC_DDEEFC
.word 0x00000000, D_802426A0_DDEED0, 0xC3340000, 0x00000000, 0x428C0000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0xFFFFFF4C, 0x00000000, 0x00000046, 0x0000001E, 0x0000000A, 0xFFFF8001, 0x00000001, 0xFFFFFF4C, 0x00000000, 0x00000046, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003E0001, 0x003E0002, 0x003E0003, 0x003E0002, 0x003E0001, 0x003E0001, 0x003E0006, 0x003E0006, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_802428BC_DDF0EC
.word 0x00000001, D_802426A0_DDEED0, 0x43A50000, 0x00000000, 0x42A60000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x0000014A, 0x00000000, 0x00000053, 0x0000001E, 0x0000000A, 0xFFFF8001, 0x00000001, 0x0000014A, 0x00000000, 0x00000053, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003E0001, 0x003E0002, 0x003E0003, 0x003E0002, 0x003E0001, 0x003E0001, 0x003E0006, 0x003E0006, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x003E0001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802426CC_DDEEFC, 0x10220008, 0x00000001, D_802428BC_DDF0EC, 0x10240008, 0x00000000, 0x00000000, 0x00000000
