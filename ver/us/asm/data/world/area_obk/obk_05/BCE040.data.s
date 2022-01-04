.include "macro.inc"

.section .data

dlabel D_80240FE0_BCE040
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024100C_BCE06C
.short 0x0032, 0x003C, 0x00C8, 0x00F0

dlabel D_80241014_BCE074
.word 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000001, func_802407A0_BCD800, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_802407AC_BCD80C, 0x00000043, 0x00000001, func_80240934_BCD994, 0x00000043, 0x00000007, func_802CFD30, 0xFFFFFFFF, 0x00000007, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcRenderMode, 0xFFFFFFFF, 0x00000011, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410C0_BCE120
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241014_BCE074, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410E4_BCE144
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241014_BCE074, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241108_BCE168
.word 0x00000000, D_80240FE0_BCE040, 0x4402C000, 0xC30B0000, 0x43410000, 0x00000F01, D_802410C0_BCE120, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00950001, 0x00950002, 0x00950003, 0x00950003, 0x00950001, 0x00950001, 0x00950000, 0x00950000, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80240FE0_BCE040, 0x43EC8000, 0xC2F40000, 0x43770000, 0x00000F01, D_802410E4_BCE144, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00950001, 0x00950002, 0x00950003, 0x00950003, 0x00950001, 0x00950001, 0x00950000, 0x00950000, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00950003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_80241108_BCE168, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241500_BCE560
.word 0x00000024, 0x00000002, 0xF8405F4D, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8405F4D, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802BCE84, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80241500_BCE560, 0x00000013, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAED4, 0x000000C8, 0x00000000, 0xFFFFFF9C, 0x00000000, 0x00000094, 0x80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAED4, 0x000000C8, 0x0000001E, 0xFFFFFF9C, 0x00000000, 0xFFFFFFFF, 0x80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAED4, 0x000000A5, 0x00000000, 0xFFFFFF9C, 0x00000000, 0x00000094, 0x80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAED4, 0xFFFFFF97, 0x00000000, 0xFFFFFFC9, 0x00000000, 0xFFFFFFFF, 0x80000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
