.include "macro.inc"

.section .data

dlabel D_802420C0_A026C0
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80241360_A01960, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000006, RotateModel, 0x0000007A, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242134_A02734
.word 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242160_A02760
.word 0xFFFFFE94, 0x000000BE, 0xFFFFFF79, 0x00000032, 0x00000064, func_802413CC_A019CC, 0x00000044, 0x00000001, D_802420C0_A026C0, 0x00000043, 0x00000002, func_80240E20_A01420, D_80242160_A02760, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
