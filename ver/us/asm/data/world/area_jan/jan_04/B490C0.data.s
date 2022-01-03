.include "macro.inc"

.section .data

dlabel D_80244950_B490C0
.word 0xC2200000, 0x43A50000, 0xC4610000, 0xC2EA0000, 0x43D20000, 0xC4160000, 0xC3430000, 0x43E88000, 0xC3960000, 0xC3880000, 0x43E88000, 0x00000000, 0xC3AF0000, 0x43A28000, 0x43960000, 0xC3AF0000, 0x437A0000, 0x43960000

dlabel D_80244998_B49108
.word 0x41200000, 0x43020000, 0xC1A00000, 0x40A00000, 0x42960000, 0xC1A00000, 0x00000000, 0x00000000, 0xC1A00000

dlabel D_802449BC_B4912C
.word 0x00000000, 0x00000000, 0xC1A00000, 0x00000000, 0x41F00000, 0xC1000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x0000000A, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000200, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000002, PlaySound, 0x00000302, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFEA2, 0x0000012C, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFEA2, 0x0000012C, 0x00000000, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0x0000000A, 0xF24A5E80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000007, MakeEntity, 0x802EAE30, 0x00000000, 0x00000A5A, 0x00000000, 0x00000094, 0x80000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80240BE8_B45358, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C8A, 0x00000043, 0x00000005, LoadPath, 0x00000046, D_80244950_B490C0, 0x00000006, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, jan_04_SetEntityPositionF, 0xFE363C89, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000032, 0x00000043, 0x00000003, GotoMap, 0x802462E8, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000012, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000000, 0x000000AA, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x0000015E, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0x00000010, 0xF24A6280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7F4D, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000007, MakeEntity, 0x802EAE30, 0x00000000, 0x00000A5A, 0x00000000, 0x00000000, 0x80000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80240D0C_B4547C, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C8A, 0x00000043, 0x00000005, LoadPath, 0x0000000C, D_80244998_B49108, 0x00000003, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, jan_04_SetEntityPositionF, 0xFE363C89, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x000001AF, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000056, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000007, 0x00000002, 0xFFFFFFF1, 0x00000000, 0x00000000, 0x0000000A, 0x0000000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000007, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000007, 0x00000002, 0x0000000F, 0x00000000, 0x00000000, 0x0000015E, 0x0000015E, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000001E, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000043, 0x00000005, LoadPath, 0x0000000A, D_802449BC_B4912C, 0x00000003, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, jan_04_SetEntityPositionF, 0xFE363C89, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x000001AF, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x0000000F, PlayEffect, 0x00000007, 0x00000002, 0xFFFFFFF6, 0x00000000, 0x0000000F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000007, 0x00000002, 0xFFFFFFF6, 0x00000000, 0x0000000F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000044, 0x00000001, 0x8024134C, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
