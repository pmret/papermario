.include "macro.inc"

.section .data

dlabel D_80252490_7FD1A0
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_802524BC_7FD1CC
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80252514_7FD224
.word 0x3FC00000, 0x0000003C, 0x0000001E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001

dlabel D_80252544_7FD254
.word 0x00000043, 0x00000002, DoBasicAI, D_80252514_7FD224, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80252564_7FD274
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, D_80252544_7FD254, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010, 0x00000000, 0x00170013, 0x00000000, 0x00000000, D_80252544_7FD254, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010

dlabel D_802525BC_7FD2CC
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x0000023A, 0x00000014, 0xFFFFFF6A, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802525FC_7FD30C
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000258, 0x00000014, 0xFFFFFF6F, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8025263C_7FD34C
.word 0x00A30000, 0x00A30001, 0x00A30004, 0xFFFFFFFF

dlabel D_8025264C_7FD35C
.word 0x00A40000, 0x00A40002, 0x00A40006, 0xFFFFFFFF

dlabel D_8025265C_7FD36C
.word 0x00000000, D_80252490_7FD1A0, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F0D, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802524BC_7FD1CC, 0xC3160000, 0x00000000, 0xC3898000, 0x00112D09, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830001, 0x00830002, 0x00830003, 0x00830003, 0x00830001, 0x00830001, 0x00830006, 0x00830006, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00000000, 0x00000000, 0x00000000, 0x001A0013, 0x00000002, D_80252564_7FD274, 0x435B0000, 0x00000000, 0xC2340000, 0x00012D09, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, 0x000000DB, 0x00000000, 0xFFFFFFD3, 0x00000090, 0x00000000, 0xFFFFFFF6, 0x000000A3, 0x00000000, 0xFFFFFFCE, 0x000000F0, 0x00000000, 0x00000032, 0x00000113, 0x00000000, 0x0000000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830001, 0x00830002, 0x00830003, 0x00830003, 0x00830001, 0x00830001, 0x00830006, 0x00830006, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00000000, 0x00000000, 0x00000000, 0x001A0014, 0x00000003, D_802524BC_7FD1CC, 0x43D40000, 0x41A00000, 0xC2AA0000, 0x00012D09, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830201, 0x00830202, 0x00830203, 0x00830203, 0x00830201, 0x00830201, 0x00830206, 0x00830206, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00830203, 0x00000000, 0x00000000, 0x00000000, 0x001A001B, 0x00000004, D_802524BC_7FD1CC, 0x439B0000, 0x42E60000, 0xC3C30000, 0x00112D09, D_802525BC_7FD2CC, 0x00000000, 0x00000000, 0x0000002D, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00A30001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_8025263C_7FD34C, 0x001A0010, 0x00000005, D_802524BC_7FD1CC, 0x43A50000, 0x42E60000, 0xC3CD0000, 0x00112D09, D_802525FC_7FD30C, 0x00000000, 0x00000000, 0x0000002D, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00A40002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_8025264C_7FD35C, 0x001A0011, 0x00000006, D_8025265C_7FD36C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
