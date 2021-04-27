.include "macro.inc"

.section .data

glabel D_80243F80_8EFDA0
.word 0x00000043, 0x00000006, RotateGroup, 0x0000006F, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80243FB0_8EFDD0
.word 0x00000043, 0x00000006, RotateGroup, 0x00000075, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000072, 0xFE363C80, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x0000005A, 0x00000024, 0x00000002, 0xFAA2B58C, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000000, 0x00000002, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000075, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000072, 0x00000000, 0x00000016, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B58C, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x00000080, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B58C, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000000, 0x00000002, 0x00000001, 0x00000013, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000075, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x00000072, 0x00000001, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80244100_8EFF20
.word 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80240330_8EC150, 0x00000043, 0x00000003, EnableGroup, 0x00000091, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x000000A5, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x000000B2, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000010C, 0x00000001, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000001, func_80240358_8EC178, 0x00000043, 0x00000003, EnableGroup, 0x00000091, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x000000A5, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x000000B2, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000010C, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000080, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80244220_8F0040
.word 0x00000000, 0xFFFFFFFF, 0x00000043, 0x0000000A, MakeDoorAdvanced, 0x00000000, D_80243F80_8EFDA0, D_80243FB0_8EFDD0, 0x00000000, D_80244100_8EFF20, 0x00000017, 0x00000016, 0x0000010D, D_80244220_8F0040, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000003, 0x00000043, 0x00000003, EnableGroup, 0x00000091, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x000000A5, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x000000B2, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000010C, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x00000080, 0x00000000, 0x00000043, 0x00000001, func_80241C9C_8EDABC, 0x00000043, 0x00000006, RotateGroup, 0x00000075, 0x0000005A, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000072, 0x0000005A, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000075, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000072, 0x00000000, 0x00000043, 0x00000001, func_80240330_8EC150, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000044, 0x00000001, D_80244100_8EFF20, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
