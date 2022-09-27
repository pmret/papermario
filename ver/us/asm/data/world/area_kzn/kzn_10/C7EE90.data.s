.include "macro.inc"

.section .data

dlabel D_80240D10_C7EE90
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000001, InterruptUsePartner, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000009, 0x00000004, 0x00000001, 0x00000002, 0x00000012, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetPlayerTargetYaw, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, kzn_10_UnkFunc48, 0x00000014, 0x00000012, 0x00000000, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000010E, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, kzn_10_UnkFunc48, 0xFFFFFFEC, 0x00000013, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001000F, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, kzn_10_SpinyTrompHit, 0x00000043, 0x00000007, func_802D2520, 0x0001000F, 0x00000004, 0xF24A8680, 0xF24A8680, 0x00000000, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF9718882, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000007, func_802D2520, 0x0001000F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010030, 0x00000043, 0x00000002, kzn_10_UnkFunc48, 0x00000000, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240FB0_C7F130
.word 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24AA280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF9718883, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F80, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F80, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C83, 0x00000018, 0x00000001, 0xFFFFFEA2, 0x00000024, 0x00000002, 0xFE363C86, 0x000001F4, 0x00000018, 0x00000001, 0xFFFFFF38, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C86, 0x00000352, 0x00000018, 0x00000001, 0x00000096, 0x00000024, 0x00000002, 0xFE363C86, 0x0000028A, 0x00000018, 0x00000001, 0x0000012C, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C86, 0x00000320, 0x00000028, 0x00000002, 0xFE363C86, 0xFE363C80, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C86, 0x000001F4, 0x00000023, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000001, kzn_10_UnkFunc46, 0x00000028, 0x00000002, 0xFE363C82, 0x00000037, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C83, 0xFE363C82, 0x00000000, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241224_C7F3A4
.word 0x0000004D, 0x00000001, 0x0000000A, 0x00000005, 0x00000001, 0x00000005, 0x00000043, 0x0000000F, PlayEffect, 0x00000015, 0x00000001, 0xFFFFFE52, 0x00000064, 0x00000000, 0x0000001E, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetCamPosition, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000064, 0x00000043, 0x0000000F, PlayEffect, 0x00000015, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000028, 0x00000002, 0xFE363C80, 0x00000064, 0x00000027, 0x00000002, 0xFE363C81, 0x00000032, 0x00000043, 0x0000000F, PlayEffect, 0x00000015, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x0000000A, 0x00000002, 0xF9718884, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000005, 0x00000001, 0x00000008, 0x00000043, 0x0000000F, PlayEffect, 0x00000015, 0x00000001, 0x00000190, 0xFFFFFFB0, 0x00000000, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241424_C7F5A4
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000001E, 0xF24A7E80, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000004D, 0x00000001, 0x000000EF, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000029, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000002A, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000029, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000029, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000024, 0x00000002, 0xF9718884, 0x00000000, 0x00000024, 0x00000002, 0xF9718883, 0x00000000, 0x00000024, 0x00000002, 0xF9718882, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C83, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C83, 0x00000000, 0x0000000F, 0x00000002, 0xFE363C80, 0xFFFFFE70, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000E, 0x00000002, 0xFE363C80, 0xFFFFFE70, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000001, InterruptUsePartner, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000029, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000002A, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFE2B, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000001, kzn_10_UnkFunc46, 0x00000043, 0x00000005, MakeLerp, 0x000000C8, 0xFE363C82, 0x00000014, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, UpdateLerp, 0x00000024, 0x00000002, 0xFD050F80, 0xFFFFFE2B, 0x00000043, 0x00000005, TranslateGroup, 0x00000029, 0xFFFFFE2B, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000002A, 0xFFFFFE2B, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000028, 0x00000002, 0xFE363C82, 0x00000037, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000004, 0xFFFFFE2B, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000044, 0x00000001, D_80241224_C7F3A4, 0x00000056, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000004, 0x00000016, 0x00000001, 0x00000009, 0x0000001C, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A8480, 0x00000043, 0x00000005, PlayerJump1, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000010E, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000008, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002B, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x000001E3, 0x00000000, 0xFFFFFE2F, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A8480, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7F4D, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000045, 0x00000002, D_80240FB0_C7F130, 0xFE363C8A, 0x00000045, 0x00000002, D_80241424_C7F5A4, 0xFD050F8A, 0x00000043, 0x00000006, PlaySoundAt, 0x8000001B, 0x00000000, 0xFFFFFE2F, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFE2B, 0x000001A2, 0x000000B4, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000001, kzn_10_UnkFunc46, 0x00000043, 0x00000004, kzn_10_UnkFunc51, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000005, TranslateGroup, 0x00000029, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000002A, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C82, 0x00000043, 0x00000006, RotateGroup, 0x00000029, 0xFE363C83, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x0000002A, 0xFE363C83, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000001, kzn_10_UnkFunc49, 0x00000043, 0x00000005, TranslateModel, 0x0000002A, 0xFE363C85, 0xFE363C86, 0x00000000, 0x00000043, 0x00000001, kzn_10_UnkFunc50, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, kzn_10_UnkFunc47, 0x0000000C, 0x00000002, 0xFE363C84, 0x00000050, 0x0000000A, 0x00000002, 0xF9718883, 0x00000000, 0x00000043, 0x00000001, func_80240350_C7E4D0, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000009, 0x00000044, 0x00000001, D_80240D10_C7EE90, 0x0000000A, 0x00000002, 0xF9718883, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000024, 0x00000002, 0xF9718883, 0x00000001, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8280, 0x00000008, 0x00000001, 0x0000002D, 0x00000024, 0x00000002, 0xF9718882, 0x00000001, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000024, 0x00000002, 0xF9718884, 0x00000001, 0x00000049, 0x00000001, 0xFD050F8A, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000023, 0xF24A8280, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000014, 0xF24A7E80, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A7C80, 0x00000057, 0x00000000, 0x00000043, 0x00000002, StopSound, 0x8000001B, 0x00000043, 0x00000006, PlaySoundAt, 0x000001E4, 0x00000000, 0x0000019F, 0xFFFFFF10, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000002A, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000001A2, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000001, kzn_10_UnkFunc46, 0x00000043, 0x0000000F, PlayEffect, 0x00000000, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000001, 0x00000014, 0x00000003, 0x00000008, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C89, 0x00000005, 0x00000001, 0x0000005A, 0x00000043, 0x00000005, TranslateModel, 0x00000015, 0xFE363C86, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000016, 0xFE363C86, 0xFE363C83, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000018, 0xFE363C84, 0xFE363C85, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000017, 0xFE363C84, 0xFE363C87, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000001A, 0xFE363C82, 0xFE363C83, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000001B, 0xFE363C82, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000001C, 0xFE363C80, 0xFE363C87, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000001D, 0xFE363C80, 0xFE363C85, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000001F, 0xFE363C80, 0xFE363C85, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000020, 0xFE363C80, 0xFE363C87, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000021, 0xFE363C82, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000022, 0xFE363C82, 0xFE363C83, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000024, 0xFE363C84, 0xFE363C87, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000025, 0xFE363C84, 0xFE363C85, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000026, 0xFE363C86, 0xFE363C83, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x00000027, 0xFE363C86, 0xFE363C81, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000002, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFF9, 0x00000027, 0x00000002, 0xFE363C82, 0xFFFFFFFB, 0x00000027, 0x00000002, 0xFE363C83, 0x00000007, 0x00000027, 0x00000002, 0xFE363C84, 0x00000009, 0x00000027, 0x00000002, 0xFE363C85, 0xFFFFFFFD, 0x00000027, 0x00000002, 0xFE363C86, 0xFFFFFFFA, 0x00000027, 0x00000002, 0xFE363C87, 0x00000007, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000029, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000002A, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xF9718883, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24BE280, 0x00000024, 0x00000002, 0xF9718882, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000
