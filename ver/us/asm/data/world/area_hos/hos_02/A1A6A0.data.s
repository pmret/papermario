.include "macro.inc"

.section .data

dlabel D_80244480_A1A6A0
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel hos_02_sixFloats
.float 4.5, 3.5, 2.6, 2.0, 1.5, 20.0

dlabel D_802444A8_A1A6C8
.word 0x3F4CCCCD, 0x00000064, 0x00000000, 0x42B40000, 0x00000000, 0x00000004, 0x40733333, 0x0000000A, 0x00000001, 0x42C80000, 0x00000000, 0x00000001

dlabel D_802444D8_A1A6F8
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000043, 0x00000002, hos_02_UnkNpcAIMainFunc10, D_802444A8_A1A6C8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244548_A1A768
.word 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_802444D8_A1A6F8, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00180000

dlabel D_80244574_A1A794
.word 0x00000000, D_80244548_A1A768, 0xC3CD0000, 0xC1700000, 0x43820000, 0x00000D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80050083, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0xFFFFFE66, 0xFFFFFFF1, 0x00000104, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFE66, 0xFFFFFFF1, 0x00000104, 0x000003E8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00460101, 0x00460102, 0x00460103, 0x00460103, 0x00460101, 0x00460101, 0x00460107, 0x00460107, 0x00460104, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00000002, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244764_A1A984
.word 0x00000001, D_80244548_A1A768, 0x435C0000, 0x43480000, 0xC34D0000, 0x00000D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80050083, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0x000000DC, 0x000000C8, 0xFFFFFF33, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000DC, 0x000000C8, 0xFFFFFF33, 0x000003E8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00460101, 0x00460102, 0x00460103, 0x00460103, 0x00460101, 0x00460101, 0x00460107, 0x00460107, 0x00460104, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00000002, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244954_A1AB74
.word 0x00000002, D_80244548_A1A768, 0xC3070000, 0x43B90000, 0x43870000, 0x00000D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80050083, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0xFFFFFF79, 0x00000172, 0x0000010E, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFF79, 0x00000172, 0x0000010E, 0x000003E8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00460101, 0x00460102, 0x00460103, 0x00460103, 0x00460101, 0x00460101, 0x00460107, 0x00460107, 0x00460104, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00460101, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80244574_A1A794, 0x04010002, 0x00000001, D_80244764_A1A984, 0x04010002, 0x00000001, D_80244954_A1AB74, 0x04010002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
