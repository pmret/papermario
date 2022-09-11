.include "macro.inc"

.section .data

dlabel D_80241760_C69890
.word 0xC40C0000, 0x43FA0000, 0x40A00000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80241B0C_C69C3C, D_80241760_C69890, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00190106

dlabel D_802417B0_C698E0
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, kzn_04_UpdateTexturePanSmooth, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, kzn_04_UpdateTexturePanStepped, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024184C_C6997C
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0x00000003, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF38, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000258, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE70, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_802417B0_C698E0, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241968_C69A98
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0x00000004, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000004, 0x00000024, 0x00000002, 0xFE363C81, 0x000001F4, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE70, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_802417B0_C698E0, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A84_C69BB4
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80243F90, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AE0_C69C10
.word 0x00000047, 0x00000005, D_80241A84_C69BB4, 0x00080000, 0x00000008, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B0C_C69C3C
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000012, 0x00000043, 0x00000002, SetSpriteShading, 0x000A0003, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x80243F54, 0x00000046, 0x00000001, 0x80242288, 0x00000024, 0x00000002, 0xFE363C80, D_80241AE0_C69C10, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000029, 0x00000000, 0x00000008, 0x00000043, 0x00000002, PlayAmbientSounds, 0x00000004, 0x00000024, 0x00000002, 0xFE363C80, 0x00000018, 0x00000044, 0x00000001, D_8024184C_C6997C, 0x00000024, 0x00000002, 0xFE363C80, 0x00000019, 0x00000044, 0x00000001, D_80241968_C69A98, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
