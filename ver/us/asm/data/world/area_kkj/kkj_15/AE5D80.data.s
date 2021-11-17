.include "macro.inc"

.section .data

dlabel D_802407F0_AE5D80
.word 0xE7000000, 0x00000000, 0xD7000002, 0xFFFFFFFF, 0xE3000A01, 0x00100000, 0xE3000C00, 0x00080000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3001201, 0x00002000, 0xE3001402, 0x00000C00, 0xFA000000, 0x4B1F13FF, 0xFB000000, 0xFF764D00, 0xFC10E5E0, 0x230B1D52, 0xE200001C, 0x0C184B50, 0xD9FDFFFF, 0x00000000, 0xD9FFFFFF, 0x00200404, 0xDF000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xF5DE01CE, 0x00000043, 0x00000001, func_8024030C_AE589C, 0x00000043, 0x00000002, PlaySound, 0x000000DC, 0x00000043, 0x00000004, GotoMapSpecial, 0x80247E50, 0x00000000, 0x0000000C, 0x00000008, 0x00000001, 0x00000064, 0x00000024, 0x00000002, 0xFE363C80, 0xF5DE01CE, 0x00000043, 0x00000001, func_8024030C_AE589C, 0x00000043, 0x00000002, PlaySound, 0x000000DC, 0x00000043, 0x00000004, GotoMapSpecial, 0x80247E58, 0x00000005, 0x0000000C, 0x00000008, 0x00000001, 0x00000064, 0x00000024, 0x00000002, 0xFE363C80, 0xF5DE01CE, 0x00000043, 0x00000001, func_8024030C_AE589C, 0x00000043, 0x00000002, PlaySound, 0x000000DC, 0x00000043, 0x00000004, GotoMapSpecial, 0x80247E60, 0x00000003, 0x0000000C, 0x00000008, 0x00000001, 0x00000064

dlabel D_80240960_AE5EF0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000044, 0x00000001, ExitSingleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80247E68, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A04_AE5F94
.word 0x00000047, 0x00000005, D_80240960_AE5EF0, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A30_AE5FC0
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000044, 0x00000001, D_80240A04_AE5F94, 0x00000016, 0x00000001, 0x00000001, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000016, 0x00000001, 0xFFFFFFB4, 0x00000044, 0x00000001, 0x80241550, 0x00000044, 0x00000001, 0x80244AF4, 0x00000016, 0x00000001, 0xFFFFFFCA, 0x00000044, 0x00000001, 0x80241550, 0x00000044, 0x00000001, 0x80244C70, 0x00000016, 0x00000001, 0xFFFFFFF2, 0x00000044, 0x00000001, 0x802453F4, 0x0000001C, 0x00000000, 0x00000044, 0x00000001, 0x80241550, 0x00000044, 0x00000001, D_80240A04_AE5F94, 0x00000023, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000044, 0x00000001, 0x80241A70, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001A, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFF94, 0x00000023, 0x00000000, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000016, 0x00000001, 0xFFFFFF94, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80246F08, 0x00000016, 0x00000001, 0xFFFFFFB4, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x8024757C, 0x00000016, 0x00000001, 0xFFFFFFF2, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80247E34, 0x00000023, 0x00000000, 0x0000000B, 0x00000002, 0xF5DE0180, 0xFFFFFFB4, 0x00000043, 0x00000003, EnableModel, 0x00000013, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000000A, 0x7FFFFE00, 0x00000013, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000020, 0x7FFFFE00, 0x00000043, 0x00000003, SetTexPanner, 0x0000004A, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000028, 0x00000024, 0x00000002, 0xFE363C84, 0x00000384, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240750_AE5CE0, 0x00000057, 0x00000000, 0x00000043, 0x00000004, SetModelCustomGfx, 0x0000004A, 0x00000000, 0xFFFFFFFF, 0x00000043, 0x00000004, SetCustomGfx, 0x00000000, D_802407F0_AE5D80, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000004E, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000028, 0x00000024, 0x00000002, 0xFE363C84, 0x00000384, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240750_AE5CE0, 0x00000057, 0x00000000, 0x00000043, 0x00000004, SetModelCustomGfx, 0x0000004E, 0x00000000, 0xFFFFFFFF, 0x00000043, 0x00000004, SetCustomGfx, 0x00000000, D_802407F0_AE5D80, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000044, 0x00000001, 0x80240680, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFFF2, 0x00000043, 0x00000002, StopSound, 0x00000093, 0x00000012, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x00000093, 0x00000000, 0x00000032, 0x00000005, 0xFFFFFF38, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80240A30_AE5FC0, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
