.include "macro.inc"

.section .data

dlabel D_80240F10_9EC700
.word 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802423A0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F60_9EC750
.word 0x00000043, 0x00000003, UseExitHeading, 0x0000007B, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802423A8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240FB0_9EC7A0
.word 0x00000047, 0x00000005, D_80240F10_9EC700, 0x00080000, 0x00000006, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240F60_9EC750, 0x00080000, 0x00000008, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240FF8_9EC7E8
.word 0x00000043, 0x00000003, SetTexPanner, 0x00000034, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000005, 0x00000001, 0x0000000C, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x0000000C, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000000, 0x00000000, 0x00004000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410AC_9EC89C
.word 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x00000036, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000001, 0x00000001, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x00000064, 0x00000028, 0x00000002, 0xFE363C81, 0x00000190, 0x00000027, 0x00000002, 0xFE363C81, 0x000003E8, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x00000035, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000003, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000002, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000002, 0x00000001, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x00000064, 0x00000027, 0x00000002, 0xFE363C81, 0x00000320, 0x00000028, 0x00000002, 0xFE363C81, 0x00000190, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000014, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000021, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFA4, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80242368, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_802413A0_9ECB90, 0x00000044, 0x00000001, D_80240FF8_9EC7E8, 0x00000044, 0x00000001, D_802410AC_9EC89C, 0x00000044, 0x00000001, 0x80240E80, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000007, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000009, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, D_80240FB0_9EC7A0, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802413A0_9ECB90
.word 0x00000043, 0x00000007, MakeItemEntity, 0x00000134, 0x000000DA, 0x00000040, 0xFFFFFF9C, 0x00000011, 0xF8405DC2, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
