.include "macro.inc"

.section .data

glabel D_80242890_9A3870
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000004F, 0x00000001, 0x00000001, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00D8, 0x000000A0, 0x00000028, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000050, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000050, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000024, 0x00000002, 0xF8405E0B, 0x00000001, 0x00000043, 0x00000005, trd_02_GetEntityPosition, 0xFD050F80, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, PlaySoundAt, 0x00000269, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F80, 0x00000043, 0x00000001, trd_02_SetEntityFlags100000, 0x00000050, 0x00000001, 0x00000001, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802429E4_9A39C4
.word 0x00000047, 0x00000005, D_80241C68_9A2C48, 0x00000100, 0x00000011, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E0B, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802BCD68, 0xFFFFFEF7, 0x000000C3, 0xFFFFFFC9, 0x00000050, D_80000000, 0x00000043, 0x00000002, AssignScript, D_802429E4_9A39C4, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFAF, 0x00000043, 0x00000007, MakeEntity, D_802E9BD4, 0x0000000A, 0x000000BB, 0x00000064, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignAreaFlag, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
