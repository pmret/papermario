.include "macro.inc"

.section .data

dlabel D_802408F0_985720
.word 0xC3FF0000, 0xC3C30000, 0x434F0000, 0x43160000, 0xC40B4000, 0xC4020000, 0x43600000, 0x43160000, 0xC3C88000, 0xC3C30000, 0x43DF8000, 0x43A00000, 0xC3C88000, 0xC4020000, 0x43DF8000, 0x43A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80240B60_985990, D_802408F0_985720, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0019009C

dlabel D_80240970_9857A0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x00000028, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80241630, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802409CC_9857FC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x00000028, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80241638, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A28_985858
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x00000028, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80241640, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A84_9858B4
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x00000028, 0x00000003, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80241648, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240AE0_985910
.word 0x00000047, 0x00000005, D_80240970_9857A0, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802409CC_9857FC, 0x00080000, 0x00000004, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240A28_985858, 0x00080000, 0x00000009, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240A84_9858B4, 0x00080000, 0x0000000D, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B60_985990
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x0000000B, 0x00000043, 0x00000002, SetSpriteShading, 0x00020005, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x80241244, 0x00000046, 0x00000001, 0x80241260, 0x00000046, 0x00000001, 0x8024154C, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFC7, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000018, 0x00000000, 0x00000008, 0x00000018, 0x00000001, 0xFFFFFFC8, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000019, 0x00000000, 0x00000008, 0x0000001B, 0x00000001, 0xFFFFFFC8, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000018, 0x00000000, 0x00000008, 0x00000023, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80240AE0_985910, 0x00000044, 0x00000001, EnterWalk, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
