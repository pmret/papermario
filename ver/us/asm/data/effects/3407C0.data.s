.include "macro.inc"

.section .data

dlabel D_E002C940
.word 0x09001138

dlabel D_E002C944
.word 0x09001120, 0x09001108, 0x090010E8, 0x090010D0, 0x090010B8, 0x09001098, 0x09001080, 0x09001068

dlabel D_E002C964
.word 0xBF800000, 0xBF000000, 0x3F000000, 0x3F800000, 0xBF800000, 0xBF000000, 0x3F000000, 0x3F800000

dlabel D_E002C984
.word 0xC0A00000, 0xC0800000, 0xC0400000, 0xC0000000, 0x40000000, 0xC0400000, 0x40A00000, 0xC0800000, 0xC0800000, 0x40000000, 0xBF800000, 0x40800000, 0x40400000, 0x40000000, 0x40A00000, 0x40800000, 0x00000000, 0x00000000, 0x00000000

dlabel D_E002C9D0
.double 0.1

dlabel D_E002C9D8
.double -0.1

dlabel D_E002C9E0
.double 0.8

dlabel D_E002C9E8
.double -0.2

dlabel D_E002C9F0
.double 0.9, 0.0
