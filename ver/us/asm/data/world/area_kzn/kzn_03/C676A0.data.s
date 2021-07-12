.include "macro.inc"

.section .data

glabel D_80246990_C676A0
.word 0xC3A3C000, 0x447C2CCD, 0xC25C0000, 0x4369E666, 0x44648000, 0xC25C0000

glabel D_802469A8_C676B8
.word 0x43948000, 0x44180000, 0x437F0000, 0xC3B50000, 0x43858000, 0x437F0000

glabel D_802469C0_C676D0
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetCamTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80246A28_C67738
.word 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C89, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000002, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000003, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000003C, 0x00000001, 0xFE363C80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000003, 0x00000008, 0x00000001, 0x00000001, 0x00000045, 0x00000002, D_802469C0_C676D0, 0xFE363C89, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000007, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000200, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000140, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xF4ACD484, 0x00000028, 0x00000002, 0xFE363C80, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C81, 0xF4ACD485, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFFB, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7C80, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFC, 0xF4ACD483, 0xFE363C80, 0xFE363C81, 0x00000008, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00000106, 0x00000057, 0x00000000, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7B4D, 0x00000043, 0x00000005, PlayerJump, 0xF4ACD483, 0xF4ACD484, 0xF4ACD485, 0x00000005, 0x00000043, 0x00000002, SetPlayerActionState, 0x0000000A, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0008000D, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000002, PlaySound, 0x80000019, 0x00000058, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B58A, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xF4ACD486, 0x00000024, 0x00000002, 0xF70F2E80, 0xF4ACD486, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000005, func_80242DB0_C63AC0, 0xFAA2B58A, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x0000000B, 0x00000002, 0xF70F2E80, 0xFE363C80, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000059, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000003E8, 0x00000046, 0x00000001, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000002, btl_state_draw_begin_partner_turn_C63C08, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD481, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD482, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, func_80243070_C63D80, 0x0000000A, 0x00000002, 0xFE363C88, 0x00008000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x00002087, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetPlayerFlagBits, 0x00800000, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B58A, 0x00000000, 0x00000043, 0x00000002, StopSound, 0x80000019, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000040, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000049, 0x00000001, 0xFE363C89, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, PlaySound, 0x8000001A, 0x00000058, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B58B, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xF4ACD486, 0x00000024, 0x00000002, 0xF70F2E81, 0xF4ACD486, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000005, func_80242E54_C63B64, 0xFAA2B58B, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x0000000B, 0x00000002, 0xF70F2E81, 0xFE363C80, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000059, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002A, 0x00000002, 0xFE363C82, 0x0000000A, 0x00000043, 0x00000005, MakeLerp, 0xFE363C80, 0x00000000, 0xFE363C82, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000002, btl_state_draw_begin_partner_turn_C63C08, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD481, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD482, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B58B, 0x00000000, 0x00000043, 0x00000002, StopSound, 0x8000001A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000003E, 0x00000002, 0x00000007, 0xFE363C80, 0x0000003C, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD480, D_80246990_C676A0, 0x00000024, 0x00000002, 0xF4ACD481, 0x00000035, 0x00000024, 0x00000002, 0xF4ACD482, 0x00000037, 0x00000024, 0x00000002, 0xF4ACD483, 0xFFFFFEB9, 0x00000024, 0x00000002, 0xF4ACD484, 0x0000037F, 0x00000024, 0x00000002, 0xF4ACD485, 0xFFFFFFD2, 0x00000024, 0x00000002, 0xF4ACD486, 0x00000001, 0x00000047, 0x00000005, D_80246A28_C67738, 0x00000800, 0x0000002F, 0x00000001, 0x00000000, 0x00000044, 0x00000001, 0x802451E4, 0x0000003E, 0x00000002, 0x00000007, 0xFE363C80, 0x0000003C, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD480, D_802469A8_C676B8, 0x00000024, 0x00000002, 0xF4ACD481, 0x0000003B, 0x00000024, 0x00000002, 0xF4ACD482, 0x00000039, 0x00000024, 0x00000002, 0xF4ACD483, 0x0000012A, 0x00000024, 0x00000002, 0xF4ACD484, 0x000001EF, 0x00000024, 0x00000002, 0xF4ACD485, 0x00000109, 0x00000024, 0x00000002, 0xF4ACD486, 0x00000002, 0x00000047, 0x00000005, D_80246A28_C67738, 0x00000800, 0x00000030, 0x00000001, 0x00000000, 0x00000044, 0x00000001, 0x80245240, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
