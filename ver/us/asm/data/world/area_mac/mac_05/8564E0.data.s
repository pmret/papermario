.include "macro.inc"

.section .data

dlabel D_80244370_8564E0
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0174, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802443B8_856528
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D016C, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_SavePoint, 0xFFFFFF6A, 0x0000003C, 0xFFFFFE89, 0x00000000, 0x80000000, 0x00000043, 0x00000008, MakeEntity, Entity_HiddenPanel, 0xFFFFFFCE, 0x00000000, 0xFFFFFED4, 0x00000000, 0x00000003, 0x80000000, 0x00000043, 0x00000002, AssignPanelFlag, 0xF8405CAC, 0x00000043, 0x00000007, MakeEntity, Entity_MulticoinBlock, 0xFFFFFE16, 0x00000082, 0x000000A0, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405CB2, 0x00000047, 0x00000005, D_80244370_8564E0, 0x00000100, 0x0000000E, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802443B8_856528, 0x00000100, 0x0000002E, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
