.include "macro.inc"

.section .data

dlabel D_80240A70_C6D390
.word 0x43C08000, 0x42E60000, 0x425C0000, 0x43870000, 0xC3C08000, 0x42960000, 0x42880000, 0x42B40000, 0x43C80000, 0x40A00000, 0x432F0000, 0x43870000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80240F98_C6D8B8, D_80240A70_C6D390, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00190108

dlabel D_80240AE0_C6D400
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, kzn_06_UnkTexturePanFunc, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, kzn_06_UnkTexturePanFunc2, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B7C_C6D49C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802419E0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240BD8_C6D4F8
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802419E8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C34_C6D554
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802419F0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C90_C6D5B0
.word 0x00000047, 0x00000005, D_80240B7C_C6D49C, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240BD8_C6D4F8, 0x00080000, 0x00000002, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240C34_C6D554, 0x00080000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CF4_C6D614
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x00000017, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x00000015, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFE70, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240AE0_C6D400, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x00000012, 0x00000001, 0x00000043, 0x00000003, SetTexPanner, 0x00000013, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000190, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000320, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240AE0_C6D400, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F38_C6D858
.word 0x00000027, 0x41200000, 0x43110000, 0xC20C0000, 0x00000026, 0xC3160000, 0x43110000, 0xC20C0000, 0x00000025, 0xC3520000, 0x42960000, 0x42C80000, 0x00000024, 0x42700000, 0x42960000, 0x42C80000, 0x0000000A, 0x42700000, 0x42960000, 0x42C80000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000

dlabel D_80240F98_C6D8B8
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000012, 0x00000043, 0x00000002, SetSpriteShading, 0x000A0005, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000024, 0x00000002, 0xF840609F, 0x00000001, 0x00000046, 0x00000001, D_802411B0_C6DAD0, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000029, 0x00000000, 0x00000008, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000001B, 0x00000043, 0x00000002, PlayAmbientSounds, 0x00000005, 0x00000012, 0x00000000, 0x00000043, 0x00000002, PlayAmbientSounds, 0x00000004, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80240C90_C6D5B0, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000001B, 0x00000003, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000001A, 0x00000003, 0x00000056, 0x00000000, 0x00000043, 0x00000002, ResetFromLava, D_80240F38_C6D858, 0x00000057, 0x00000000, 0x00000044, 0x00000001, D_80240CF4_C6D614, 0x00000044, 0x00000001, D_80241880_C6E1A0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241120_C6DA40
.float 0.02, 0.02, 0.04, 0.08, 0.11, 0.2, 0.3, 0.31, 0.42, 0.46, 0.5, 0.53, 0.56, 0.59, 0.62, 0.65, 0.68, 0.71, 0.74, 0.77, 0.8, 0.83, 0.86, 0.89, 0.92, 0.95, 0.98, 1.0

dlabel D_80241190_C6DAB0
.word 0x00000024, 0x00000002, 0xF84060A1, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411B0_C6DAD0
.word 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0x00000145, 0x000000CD, 0xFFFFFFE2, 0x00000000, 0x00000095, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF84060A0, 0x0000000A, 0x00000002, 0xF84060A1, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA274, 0x00000181, 0x00000005, 0x000000B4, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80241190_C6DAB0, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000001B, 0x00000043, 0x00000008, CreatePushBlockGrid, 0x00000000, 0x0000000C, 0x00000001, 0xFFFFFEB6, 0x00000091, 0xFFFFFFA6, 0x00000000, 0x00000043, 0x00000003, SetPushBlockFallEffect, 0x00000000, func_80240310_C6CC30, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x00000004, 0x00000000, 0x00000001, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x00000006, 0x00000000, 0x00000001, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x00000008, 0x00000000, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000008, CreatePushBlockGrid, 0x00000000, 0x0000000C, 0x00000001, 0xFFFFFEB6, 0x00000078, 0xFFFFFFA6, 0x00000000, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x00000009, 0x00000000, 0x00000001, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x0000000A, 0x00000000, 0x00000001, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x0000000B, 0x00000000, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241370_C6DC90
.word 0x00000000

dlabel D_80241374_C6DC94
.word 0x00010014

dlabel D_80241378_C6DC98
.word 0x0001000C, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000007, func_802407FC_C6D11C, D_80241378_C6DC98, 0x00000000, 0x00000000, 0x000000FF, 0x0000003C, 0x00000001, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000007, func_802407FC_C6D11C, D_80241378_C6DC98, 0x00000000, 0x00000000, 0x000000FF, 0x0000003C, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241404_C6DD24
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000001, func_80240A44_C6D364, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFEC, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF253DA80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24A8E80, 0xF24A9A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000F, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000028, 0x0000002C, 0x00000002, 0xFD050F80, 0xF24A7A70, 0x00000008, 0x00000001, 0x00000003, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFE7, 0x00000064, 0x00000004, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A7A80, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A7A80, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0x00000012, 0x00000000, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0x00000013, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000015, 0x00000000, 0xFE363C80, 0xFE363C82, 0x0000000D, 0x00000002, 0xFE363C84, 0x00000014, 0x0000000D, 0x00000002, 0xFE363C82, 0xFFFFFFB5, 0x0000002D, 0x00000002, 0xFE363C82, 0xF24A7C80, 0x0000002D, 0x00000002, 0xFE363C83, 0xF24A7CB4, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C84, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000002D, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000001A, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x0000001B, 0x7FFFFE00, 0x00000043, 0x00000003, EnableGroup, 0x0000001D, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000020, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241744_C6E064
.word 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetPushBlock, 0x00000000, 0x0000000B, 0x00000000, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x00000028, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000014, 0x0000002D, 0x00000002, 0xFE363C80, 0xF24A7D4D, 0x0000002D, 0x00000002, 0xFE363C81, 0xF24A7AE7, 0x00000043, 0x00000005, TranslateGroup, 0x00000019, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000008, 0x00000001, 0x00000002, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000046, 0x00000001, D_80241404_C6DD24, 0x00000024, 0x00000002, 0xF5DE0180, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241880_C6E1A0
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000001B, 0x00000043, 0x00000003, EnableGroup, 0x00000020, 0x00000000, 0x00000044, 0x00000001, D_80241744_C6E064, 0x00000026, 0x00000002, 0xFD050F80, 0xF24A7E80, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000001A, 0x7FFFFE00, 0x00000043, 0x00000003, EnableGroup, 0x0000001D, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000019, 0x00000000, 0xFFFFFFF2, 0xFFFFFFFE, 0x00000043, 0x00000005, TranslateModel, 0x00000012, 0x00000000, 0xFFFFFFE7, 0xFFFFFFCE, 0x00000043, 0x00000005, TranslateModel, 0x00000013, 0x00000000, 0xFFFFFFE7, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000015, 0x00000000, 0xFFFFFFE7, 0xFFFFFFD8, 0x00000026, 0x00000002, 0xFD050F80, 0xF24A7C80, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, func_802403F0_C6CD10, 0x00000001, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, func_80240738_C6D058, D_80241374_C6DC94, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
