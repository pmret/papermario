.include "macro.inc"

.section .data

dlabel D_80241C00_ACFD40
.word 0x0000006A, 0x00000000

dlabel D_80241C08_ACFD48
.word 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00D8, 0x000000A0, 0x00000028, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x00000269, 0x00000000, 0x00000000, 0x0000000A, 0x000001EA, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F80, 0x00000043, 0x00000001, kkj_11_SetEntityFlags100000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000024, 0x00000002, 0xF8405D74, 0x00000001, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000047, 0x00000005, D_802411A0_ACF2E0, 0x00000100, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000E, 0x00000002, 0xF5DE0180, 0x00000006, 0x0000000A, 0x00000002, 0xF8405D74, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802BCD68, 0x00000000, 0x0000000A, 0x000001EA, 0x000000B4, 0x80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x0000004E, 0x00000006, D_80241C08_ACFD48, 0x00000100, 0x00004000, D_80241C00_ACFD40, 0x00000000, 0x00000001, 0x00000012, 0x00000000, 0x00000047, 0x00000005, D_802411A0_ACF2E0, 0x00000100, 0x00000000, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
