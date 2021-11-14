.include "macro.inc"

.section .data

dlabel D_80241A40_A02040
.word 0x0000000A, 0x00000002, 0xF70F2E81, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E81, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A78_A02078
.word 0x0000000A, 0x00000002, 0xF70F2E81, 0x00000001, 0x00000024, 0x00000002, 0xF70F2E81, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AB0_A020B0
.word 0x0000000A, 0x00000002, 0xF70F2E81, 0x00000002, 0x00000043, 0x00000002, PlaySound, 0x0000000B, 0x00000043, 0x00000006, PlaySoundAt, 0x00002108, 0x00000000, 0x00000028, 0x0000003C, 0xFFFFFEE3, 0x00000024, 0x00000002, 0xF70F2E81, 0x00000003, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000000, 0x00000028, 0x00000049, 0xFFFFFEE3, 0x0000000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EA5AC, 0x00000028, 0x0000003C, 0xFFFFFEE3, 0x0000005A, 0x00000146, D_80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405DD6, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B94_A02194
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0178, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802EAFDC, 0xFFFFFE52, 0x00000096, 0xFFFFFFB5, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80241B94_A02194, 0x0000000A, 0x00000002, 0xF8405DD6, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E81, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x00000046, 0x00000000, 0xFFFFFF06, 0x0000005A, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80241A40_A02040, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x00000046, 0x00000000, 0xFFFFFEC0, 0x0000005A, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80241A78_A02078, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0xFFFFFFF6, 0x00000000, 0xFFFFFEE3, 0x0000005A, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80241AB0_A020B0, 0x00000012, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x00000046, 0x00000000, 0xFFFFFF06, 0x0000005A, D_80000000, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x00000046, 0x00000000, 0xFFFFFEC0, 0x0000005A, D_80000000, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0xFFFFFFF6, 0x00000000, 0xFFFFFEE3, 0x0000005A, D_80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EA5AC, 0x00000028, 0x0000003C, 0xFFFFFEE3, 0x0000005A, 0x00000146, D_80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405DD6, 0x00000013, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAB04, 0xFFFFFF01, 0x00000096, 0xFFFFFF9C, 0x0000005A, 0x00000068, D_80000000, 0x00000043, 0x00000002, AssignPanelFlag, 0xF8405DE0, 0x00000043, 0x00000007, MakeItemEntity, 0x000000A4, 0xFFFFFF65, 0x00000096, 0xFFFFFF7E, 0x00000011, 0xF8405DE8, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
