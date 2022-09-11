.include "macro.inc"

.section .data

dlabel D_80240470_A54DC0
.word 0x41F00000, 0x41F00000, 0xC3160000, 0x42B40000, 0x44B7C000, 0x41F00000, 0xC3160000, 0x43870000, 0x41880000, 0xC1A00000, 0xC1880000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_802409F8_A55348, D_80240470_A54DC0, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, kpa_12_get_tattle

dlabel D_802404E0_A54E30
.word 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000064, 0x00000000, 0x00000008, 0x0000000A, 0x00000002, 0xF8406194, 0x00000000, 0x00000043, 0x00000002, PlayAmbientSounds, 0x00000004, 0x00000013, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000001, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetMusicTrackVolumes, 0x00000005, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240570_A54EC0
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, kpa_12_UpdateTexturePanSmooth, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, kpa_12_UpdateTexturePanStepped, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024060C_A54F5C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x0000000A, 0x00000002, 0xF8406194, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x802415B8, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x802415B0, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024069C_A54FEC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x0000000A, 0x00000002, 0xF8406194, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x802415B8, 0x00000004, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x802415B0, 0x00000004, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024072C_A5507C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802415C0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240788_A550D8
.word 0x00000047, 0x00000005, D_8024060C_A54F5C, 0x00080000, 0x00000049, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024069C_A54FEC, 0x00080000, 0x0000004C, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024072C_A5507C, 0x00080000, 0x00000046, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802407EC_A5513C
.word 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFE70, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFCE0, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240570_A54EC0, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x00000069, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000006A, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000006B, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000006C, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000006D, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000006E, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000006F, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x00000070, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240988_A552D8
.word 0x00000003, 0x42C80000, 0x41F00000, 0xC3160000, 0x00000004, 0x43750000, 0x41F00000, 0xC3160000, 0x00000005, 0x43C80000, 0x41F00000, 0xC3160000, 0x00000006, 0x442F0000, 0x41F00000, 0xC3160000, 0x00000007, 0x4455C000, 0x41F00000, 0xC2C80000, 0x00000002, 0x44B4A000, 0x41F00000, 0xC3070000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000

dlabel D_802409F8_A55348
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000016, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x0000000A, 0x00000002, 0xF8406194, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x000000E5, 0x00000000, 0x00000044, 0x00000001, D_802407EC_A5513C, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000072, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_802404E0_A54E30, 0x0000000A, 0x00000002, 0xF8406194, 0x00000000, 0x00000044, 0x00000001, 0x802414C4, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80240788_A550D8, 0x00000044, 0x00000001, EnterWalk, 0x0000000A, 0x00000002, 0xF8406194, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000009, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000A, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000B, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000C, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000D, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000E, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000F, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000010, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000011, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000012, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000013, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000050, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000051, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000004C, 0x00000003, 0x00000056, 0x00000000, 0x00000043, 0x00000002, ResetFromLava, D_80240988_A552D8, 0x00000057, 0x00000000, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
