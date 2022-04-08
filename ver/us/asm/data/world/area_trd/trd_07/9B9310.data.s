.include "macro.inc"

.section .data

dlabel D_80242990_9B9310
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, trd_07_UpdateTexturePanSmooth, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, trd_07_UpdateTexturePanStepped, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242A2C_9B93AC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80244810, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242A88_9B9408
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80244818, 0x00000004, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242AE4_9B9464
.word 0x00000047, 0x00000005, D_80242A2C_9B93AC, 0x00080000, 0x00000001, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242A88_9B9408, 0x00080000, 0x00000007, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242B2C_9B94AC
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000001, 0x00000001, 0xFE363C81, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000064, 0x00000028, 0x00000002, 0xFE363C81, 0x00000064, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000007, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x8024369C, 0x00000044, 0x00000001, 0x80242950, 0x00000044, 0x00000001, D_80242B2C_9B94AC, 0x00000046, 0x00000001, 0x80244778, 0x00000024, 0x00000002, 0xFE363C80, D_80242AE4_9B9464, 0x00000045, 0x00000002, EnterWalk, 0xFD050F80, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000005, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x0000005A, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFC4, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFFBA, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80242990_9B9310, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
