.include "macro.inc"

.section .data

dlabel D_802412E0_B7B330
.word 0xC37A0000, 0x00000000, 0x42F00000, 0x00000000, 0x437A0000, 0x00000000, 0xC2F00000, 0x43340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80241440_B7B490, D_802412E0_B7B330, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x001900FC

dlabel D_80241340_B7B390
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80243860, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024139C_B7B3EC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80243868, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802413F8_B7B448
.word 0x00000047, 0x00000005, D_8024139C_B7B3EC, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241340_B7B390, 0x00080000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241440_B7B490
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000024, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80243834, 0x00000044, 0x00000001, 0x80242270, 0x00000044, 0x00000001, 0x802430F4, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000001, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000005, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, D_802413F8_B7B448, 0x00000044, 0x00000001, EnterWalk, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000025, 0x00000000, 0x00000008, 0x00000043, 0x00000002, PlayAmbientSounds, 0x00000003, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
