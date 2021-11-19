.include "macro.inc"

.section .data

dlabel D_80240000_B1C540
.word 0x00000000, 0x00000000, 0xC3F00000, 0x43340000, 0xC3F00000, 0x00000000, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x43F00000, 0x00000000, 0x43F00000, 0x00000000, 0x00000000, 0x43870000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_802402F0_B1C830, D_80240000_B1C540, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x00000000

dlabel D_80240080_B1C5C0
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80240500, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802400E0_B1C620
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80240500, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240140_B1C680
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80240500, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802401A0_B1C6E0
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000003, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80240500, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240200_B1C740
.word 0x00000043, 0x00000003, SetZoneEnabled, 0x00000010, 0x00000000, 0x00000043, 0x00000003, SetZoneEnabled, 0x0000000F, 0x00000000, 0x00000043, 0x00000003, SetZoneEnabled, 0x00000011, 0x00000000, 0x00000043, 0x00000003, SetZoneEnabled, 0x0000000E, 0x00000000, 0x00000024, 0x00000002, 0xF9718880, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240270_B1C7B0
.word 0x00000047, 0x00000005, D_80240080_B1C5C0, 0x00000080, 0x00000001, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802400E0_B1C620, 0x00000080, 0x0000000B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240140_B1C680, 0x00000080, 0x00000008, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802401A0_B1C6E0, 0x00000080, 0x00000005, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802402F0_B1C830
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000017, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000046, 0x00000001, D_80240498_B1C9D8, 0x0000000A, 0x00000002, 0xF9718880, 0x00000001, 0x00000043, 0x00000003, SetZoneEnabled, 0x00000010, 0x00000000, 0x00000043, 0x00000003, SetZoneEnabled, 0x0000000F, 0x00000000, 0x00000043, 0x00000003, SetZoneEnabled, 0x00000011, 0x00000000, 0x00000043, 0x00000003, SetZoneEnabled, 0x0000000E, 0x00000000, 0x00000024, 0x00000002, 0xF9718880, 0x00000000, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xF9718880, 0x00000001, 0x00000047, 0x00000005, D_80240200_B1C740, 0x00000080, 0x0000000E, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80240270_B1C7B0, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240450_B1C990
.word 0xFFFFFFBF, 0x00000000, 0x000000D9, 0xFFFFFEFA, 0x00000000, 0xFFFFFFC0, 0x00000039, 0x00000000, 0xFFFFFEE2, 0x00000147, 0x00000000, 0x00000008, 0x80000001, D_80240450_B1C990, D_80240450_B1C990, D_80240450_B1C990, D_80240450_B1C990, 0xFFFFFFFF

dlabel D_80240498_B1C9D8
.word 0x00000043, 0x00000007, MakeEntity, 0x802EA7E0, 0xFFFFFFF3, 0x0000003C, 0xFFFFFFCE, 0x00000000, D_80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAB04, 0xFFFFFF91, 0x00000000, 0xFFFFFFC9, 0x00000000, 0x00000003, D_80000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
