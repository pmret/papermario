.include "macro.inc"

.section .data

glabel D_80241780_BC5A00
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, obk_03_GetEntityPosition, 0xFE363C87, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000006, PlaySoundAt, 0x00000301, 0x00000000, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C85, 0xFE363C86, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, obk_03_SetEntityPosition, 0xFE363C87, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, obk_03_GetEntityPosition, 0xFE363C87, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000006, PlaySoundAt, 0x00000048, 0x00000000, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0xFE363C88, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802418F0_BC5B70
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, obk_03_GetEntityPosition, 0xFE363C87, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000006, PlaySoundAt, 0x00000303, 0x00000000, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C85, 0xFE363C86, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, obk_03_SetEntityPosition, 0xFE363C87, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, obk_03_GetEntityPosition, 0xFE363C87, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000006, PlaySoundAt, 0x000000DD, 0x00000000, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0xFE363C88, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241A60_BC5CE0
.word 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000E, 0x00000002, 0xFE363C80, 0x00000154, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xFE363C80, 0x00000174, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000E, 0x00000002, 0xFE363C82, 0xFFFFFF8D, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xFE363C82, 0xFFFFFFAB, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0008001F, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A8280, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002B, 0x00000043, 0x00000005, PlayerJump1, 0x0000014A, 0xFFFFFF2E, 0xFFFFFFCF, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000008, 0x00000001, 0x00000005, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241B9C_BC5E1C
.word 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000E, 0x00000002, 0xFE363C80, 0x0000018A, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xFE363C80, 0x000001D6, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000E, 0x00000002, 0xFE363C82, 0xFFFFFF79, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xFE363C82, 0xFFFFFFC2, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0008001F, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A8280, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002B, 0x00000043, 0x00000005, PlayerJump1, 0x00000160, 0xFFFFFF2E, 0xFFFFFFFB, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000008, 0x00000001, 0x00000005, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241CD8_BC5F58
.word 0x00000043, 0x00000007, MakeEntity, D_802E9BD4, 0x00000168, 0xFFFFFF2E, 0xFFFFFF9C, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignAreaFlag, 0x00000006, 0x00000043, 0x00000002, AssignScript, D_80241DB4_BC6034, 0x00000044, 0x00000001, D_80241A60_BC5CE0, 0x00000024, 0x00000002, 0xFE363C82, 0x00000168, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFF9C, 0x00000024, 0x00000002, 0xFE363C85, 0xFFFFFF2E, 0x00000024, 0x00000002, 0xFE363C86, 0x00000014, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C88, 0x00000005, 0x00000046, 0x00000001, D_80241780_BC5A00, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241DB4_BC6034
.word 0x00000043, 0x00000007, MakeEntity, D_802E9BF8, 0x000001B8, 0xFFFFFF2E, 0xFFFFFF9C, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignAreaFlag, 0x00000007, 0x00000043, 0x00000002, AssignScript, D_80241E90_BC6110, 0x00000044, 0x00000001, D_80241B9C_BC5E1C, 0x00000024, 0x00000002, 0xFE363C82, 0x000001B8, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFF9C, 0x00000024, 0x00000002, 0xFE363C85, 0xFFFFFF2E, 0x00000024, 0x00000002, 0xFE363C86, 0x00000014, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C88, 0x0000001E, 0x00000046, 0x00000001, D_802418F0_BC5B70, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241E90_BC6110
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFD9, 0x00000044, 0x00000001, 0x80242320, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFD9, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFD9, 0x00000043, 0x00000007, MakeEntity, D_802E9BD4, 0x0000012C, 0xFFFFFF2E, 0xFFFFFF9C, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignAreaFlag, 0x00000005, 0x00000043, 0x00000002, AssignScript, D_80241CD8_BC5F58, 0x00000013, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAED4, 0xFFFFFF7E, 0x00000000, 0xFFFFFFCE, 0x00000000, 0x0000008C, D_80000000, 0x00000043, 0x00000002, AssignCrateFlag, 0xF8405F45, 0x00000043, 0x00000008, MakeEntity, 0x802EAED4, 0x0000009B, 0x00000000, 0xFFFFFF9C, 0x00000000, 0xFFFFFFFF, D_80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAED4, 0xFFFFFF5B, 0x00000000, 0xFFFFFFCE, 0x00000000, 0xFFFFFFFF, D_80000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
