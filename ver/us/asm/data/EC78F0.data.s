.include "macro.inc"

.section .data

dlabel D_80240740_EC78F0
.word 0x43BB8000, 0x00000000, 0x00000000, 0x43870000, 0x43A28000, 0x00000000, 0x00000000, 0x43870000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80240CA0_EC7E50, D_80240740_EC78F0, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x00190116

dlabel D_802407A0_EC7950
.word 0x00000043, 0x00000002, 0x802D790C, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, 0x802E339C, 0x00000000, 0x0000007F, 0x00000000, 0x00000008, 0x00000012, 0x00000000, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x00000035, 0x00000043, 0x00000005, 0x802E339C, 0x00000000, 0x00000030, 0x00000000, 0x00000008, 0x0000001C, 0x00000000, 0x00000043, 0x00000005, 0x802E339C, 0x00000000, 0x00000031, 0x00000000, 0x00000008, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x802E37A0, 0x80000021, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024086C_EC7A1C
.word 0x00000043, 0x00000003, 0x802E3648, 0x00000089, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240890_EC7A40
.word 0x00000043, 0x00000003, 0x802E3330, 0x00000000, 0x000000FA, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, 0x802E3628, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_802408D0_EC7A80
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, EC71B0_UpdateTexturePanSmooth, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, EC71B0_UpdateTexturePanStepped, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024096C_EC7B1C
.word 0x0000004D, 0x00000001, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C8C, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C8D, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C8E, 0xFE363C84, 0x00000028, 0x00000002, 0xFE363C8C, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C8D, 0xFE363C81, 0x00000026, 0x00000002, 0xFE363C80, 0xFE363C8C, 0x0000002F, 0x00000002, 0xFE363C80, 0xF24C0A80, 0x00000026, 0x00000002, 0xFE363C8F, 0xF24C0A80, 0x0000002F, 0x00000002, 0xFE363C8F, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C8F, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C85, 0x000000C8, 0x0000002A, 0x00000002, 0xFE363C85, 0xFE363C8F, 0x00000027, 0x00000002, 0xFE363C85, 0x00000001, 0x00000005, 0x00000001, 0xFE363C85, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8C, 0xFE363C80, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8D, 0xFE363C81, 0x00000043, 0x00000003, 0x802E1D00, 0x000000C7, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C83, 0x000000D2, 0x00000028, 0x00000002, 0xFE363C83, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C8B, 0x00000027, 0x00000002, 0xFE363C82, 0xFE363C8E, 0x00000043, 0x0000000F, 0x802E58EC, 0x0000000D, 0xFE363C80, 0xFE363C82, 0xFE363C81, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0xFE363C8F, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8C, 0xFE363C80, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8D, 0xFE363C81, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C8B, 0x00000043, 0x0000000F, 0x802E58EC, 0x0000000D, 0xFE363C80, 0xFE363C8E, 0xFE363C81, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0xFE363C8F, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C18_EC7DC8
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, 0x802DF78C, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, 0x80286004, 0x00000043, 0x00000003, 0x802D78AC, D_80242B30_EC9CE0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C74_EC7E24
.word 0x00000047, 0x00000005, D_80240C18_EC7DC8, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CA0_EC7E50
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000026, 0x00000043, 0x00000002, 0x802E6F50, 0xFFFFFFFF, 0x00000043, 0x00000003, 0x802D8B60, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D7CD8, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, func_802D8248, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, 0x802D7B70, 0x00000000, 0x00000001, 0x00000024, 0x00000002, 0xF9718886, 0x00000000, 0x00000043, 0x00000003, 0x80048338, 0x00000000, D_80242B0C_EC9CBC, 0x00000046, 0x00000001, D_802428C4_EC9A74, 0x00000043, 0x00000004, AddCoin, 0x00000003, 0x00000006, 0x00000006, 0x00000024, 0x00000002, 0xFE363C80, 0x00000129, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C82, 0x0000017F, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFBF, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000044, 0x00000001, D_8024096C_EC7B1C, 0x00000024, 0x00000002, 0xFE363C80, 0x00000125, 0x00000024, 0x00000002, 0xFE363C81, 0x00000047, 0x00000024, 0x00000002, 0xFE363C82, 0x0000017A, 0x00000024, 0x00000002, 0xFE363C83, 0x00000071, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000044, 0x00000001, D_8024096C_EC7B1C, 0x00000024, 0x00000002, 0xFE363C80, 0x00000015, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFEA6, 0x00000024, 0x00000002, 0xFE363C82, 0x00000093, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFF0E, 0x00000024, 0x00000002, 0xFE363C84, 0x00000014, 0x00000044, 0x00000001, D_8024096C_EC7B1C, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFEA2, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF42, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFFAF, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFF96, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000044, 0x00000001, D_8024096C_EC7B1C, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFE84, 0x00000024, 0x00000002, 0xFE363C81, 0x00000055, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C83, 0x00000096, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000044, 0x00000001, D_8024096C_EC7B1C, 0x00000043, 0x00000003, 0x802D6688, 0x00000033, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000031, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000032, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF9C, 0x00000024, 0x00000002, 0xFE363C82, 0x00000064, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_802408D0_EC7A80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFB50, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_802408D0_EC7A80, 0x00000057, 0x00000000, 0x00000043, 0x00000002, 0x802D790C, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000044, 0x00000001, D_80241C14_EC8DC4, 0x00000012, 0x00000000, 0x00000043, 0x00000004, AddCoin, 0x00000000, 0x00000001, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, D_80240C74_EC7E24, 0x00000044, 0x00000001, 0x80285C70, 0x00000044, 0x00000001, D_802424F4_EC96A4, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_802407A0_EC7950, 0x0000000F, 0x00000002, 0xF5DE0180, 0x00000035, 0x00000043, 0x00000001, EC71B0_SpawnSunEffect, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80240344_EC74F4, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241220_EC83D0
.word 0x00000000, 0x00380028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C85, 0xFE363C8F, 0xFE363C87, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, EC7590_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0x00000001, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, 0x802D7A04, 0xFE363C83, 0x00000153, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, EC7590_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xFFFFFFFF, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, 0x802D5FE0, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000033, 0x00000003, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000033, 0x00000003, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000007, 0x802E4410, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000012, 0x00000000, 0x00000043, 0x00000003, 0x802E2F8C, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000003, 0x802E2F30, 0xFE363C8A, 0x00000001, 0x00000043, 0x00000007, 0x802E4410, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000046, 0x00000001, 0xFE363C84, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415AC_EC875C
.word 0x0000004C, 0x00000001, 0xF24A8280, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C86, 0xFE363C8F, 0xFE363C88, 0x00000043, 0x00000002, 0x802E37A0, 0x00000165, 0x00000043, 0x00000002, 0x802E37A0, 0x00000166, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, EC7590_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, 0x802D7A04, 0xFE363C83, 0x00000166, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, EC7590_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, 0x802D5FE0, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, EC7590_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, 0x802D7A04, 0xFE363C84, 0x00000165, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, EC7590_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000005, 0x802D5FE0, 0xFE363C84, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000000, 0x00000030, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000005, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000033, 0x00000003, 0xFE363C89, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000007, 0x802E4410, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000012, 0x00000000, 0x00000043, 0x00000003, 0x802E2F8C, 0xFE363C8B, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000043, 0x00000003, 0x802E2F30, 0xFE363C8B, 0x00000001, 0x00000043, 0x00000007, 0x802E4410, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000030, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000005, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x0000000F, 0x802E58EC, 0x00000014, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C85, 0x00000000, 0x00000046, 0x00000001, 0xFE363C85, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel EC7590_varStash
.word 0x00000000

dlabel D_80241BB4_EC8D64
.word 0x00000043, 0x00000004, 0x802E49F4, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, 0x802E49F4, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C14_EC8DC4
.word 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x00000043, 0x00000002, 0x802DE404, 0x00000001, 0x00000043, 0x00000005, 0x802DC654, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, 0x802D8D40, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000005, 0x802D9320, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, 0x802D90D8, 0x00000000, 0x0000012C, 0x00000043, 0x00000004, 0x802D903C, 0x00000000, 0xF24AA680, 0xF24A4E80, 0x00000043, 0x00000003, 0x802D93E4, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, 0x802D8C7C, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, 0x802D9848, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80002, 0x00C80001, 0x00000000, 0x001100C5, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, 0x802D78AC, D_80242B38_EC9CE8, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D6C_EC8F1C
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, 0x802D8758, 0x00000000, 0x00000000, 0x00000001, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241DBC_EC8F6C
.word 0x0000000A, 0x00000002, 0xF9718886, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80002, 0x00C80001, 0x00000000, 0x00110068, 0x00000056, 0x00000000, 0x00000043, 0x00000003, 0x802D90D8, 0x00000000, 0x0000012C, 0x00000043, 0x00000004, 0x802D903C, 0x00000000, 0xF24AC280, 0xF24A5C80, 0x00000043, 0x00000003, 0x802D93E4, 0x00000000, 0xF24A7C80, 0x00000043, 0x00000004, 0x802D8C7C, 0x00000000, 0x00000000, 0x00000001, 0x00000057, 0x00000000, 0x00000043, 0x00000002, 0x802E37A0, 0x8000006B, 0x00000045, 0x00000002, D_80241D6C_EC8F1C, 0xFD050F80, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80006, 0x00C80006, 0x00000000, 0x00110069, 0x00000049, 0x00000001, 0xFD050F80, 0x00000043, 0x00000003, 0x802D90D8, 0x00000000, 0x0000015E, 0x00000043, 0x00000004, 0x802D903C, 0x00000000, 0xF24AC280, 0xF24A5C80, 0x00000043, 0x00000003, 0x802D93E4, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, 0x802D8C7C, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, 0x802D9848, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C80, 0xFFFFFF06, 0x00000043, 0x00000007, 0x802E4310, 0x0000001E, 0xFFFFFF1F, 0x00000064, 0xFFFFFFE7, 0x0000000D, 0xF84060DE, 0x00000012, 0x00000000, 0x00000043, 0x00000007, 0x802E4310, 0x0000001E, 0xFFFFFEF7, 0x00000064, 0x00000036, 0x0000000D, 0xF84060DE, 0x00000024, 0x00000002, 0xF84060F4, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x802E37A0, 0x000007BC, 0x00000043, 0x00000002, 0x802E3934, 0x000003BC, 0x00000024, 0x00000002, 0xF9718886, 0x00000001, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80002, 0x00C80001, 0x00000000, 0x0011006A, 0x00000024, 0x00000002, 0xF5DE0180, 0x0000002F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242044_EC91F4
.word 0x00000046, 0x00000001, D_8024086C_EC7A1C, 0x00000043, 0x00000003, 0x802DC228, 0xFFFFFFFF, 0x00000001, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x0000002D, 0x0000000A, 0x00000002, 0xF9718885, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110070, 0x00000024, 0x00000002, 0xF9718885, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110071, 0x00000013, 0x00000000, 0x00000018, 0x00000001, 0x0000002E, 0x00000043, 0x00000007, 0x802D9B68, 0x00000000, 0xF24A8A80, 0x00000000, 0xF24FF280, 0xF24AC280, 0xF24A5C80, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110065, 0x00000043, 0x00000003, 0x802DB654, 0xFFFFFFFF, 0x00C80005, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, 0x802DB654, 0xFFFFFFFF, 0x00C80000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000059, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000046, 0x00000001, D_80241BB4_EC8D64, 0x00000043, 0x00000002, 0x802E3F18, 0x00000059, 0x00000024, 0x00000002, 0xF5DE0180, 0x0000002E, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110066, 0x0000000A, 0x00000002, 0xF84060E3, 0x00000001, 0x00000046, 0x00000001, D_80241DBC_EC8F6C, 0x00000013, 0x00000000, 0x00000043, 0x00000003, 0x802D9DE4, 0x00000000, 0xF24A8A80, 0x00000018, 0x00000001, 0x0000002F, 0x0000000A, 0x00000002, 0xF84060E3, 0x00000001, 0x0000000A, 0x00000002, 0xF9718886, 0x00000000, 0x00000043, 0x00000007, 0x802D9B68, 0x00000000, 0xF24A8A80, 0x00000000, 0xF24FF280, 0xF24AC280, 0xF24A5C80, 0x00000046, 0x00000001, D_80241DBC_EC8F6C, 0x00000043, 0x00000003, 0x802D9DE4, 0x00000000, 0xF24A8A80, 0x00000012, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110072, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110072, 0x00000013, 0x00000000, 0x00000018, 0x00000001, 0x00000035, 0x0000000A, 0x00000002, 0xF84060DE, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110072, 0x00000012, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000030, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110073, 0x00000012, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110074, 0x00000013, 0x00000000, 0x00000043, 0x00000006, 0x802DD848, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110075, 0x00000013, 0x00000000, 0x00000018, 0x00000001, 0x0000003C, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110076, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0xFFFFFFFF, 0x00C80002, 0x00C80001, 0x00000000, 0x00110077, 0x00000023, 0x00000000, 0x00000046, 0x00000001, D_80240890_EC7A40, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242428_EC95D8
.word 0x0000000A, 0x00000002, 0xF5DE0180, 0x0000002F, 0x0000000A, 0x00000002, 0xF84060DE, 0x00000000, 0x0000000A, 0x00000002, 0xF84060F4, 0x00000000, 0x00000043, 0x00000007, 0x802E4310, 0x0000001E, 0xFFFFFF1F, 0x00000000, 0xFFFFFFE7, 0x00000011, 0xF84060DE, 0x00000012, 0x00000000, 0x00000043, 0x00000007, 0x802E4310, 0x0000001E, 0xFFFFFEF7, 0x00000000, 0x00000036, 0x00000011, 0xF84060DE, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF9718885, 0x00000000, 0x00000043, 0x00000003, 0x80049154, 0xFFFFFFFF, D_80242044_EC91F4, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802424F4_EC96A4
.word 0x0000000B, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x0000000C, 0x00000002, 0xF70F2E83, 0x00000005, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80002, 0x00C80001, 0x00000000, 0x0011006E, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000004, 0x802DE754, 0x0000019A, 0xFE363C83, 0x0000000A, 0x00000027, 0x00000002, 0xF70F2E83, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80002, 0x00C80001, 0x00000000, 0x0011006F, 0x00000024, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802425F8_EC97A8
.word 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000002F, 0x00000043, 0x00000003, 0x802DC228, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80004, 0x00C80001, 0x00000000, 0x00110067, 0x0000000A, 0x00000002, 0xF5DE0180, 0x0000002E, 0x0000000A, 0x00000002, 0xF84060E3, 0x00000001, 0x00000043, 0x00000005, 0x802D8D40, 0x00000000, 0xFFFFFF06, 0x00000000, 0x00000000, 0x00000043, 0x00000005, 0x802D9320, 0x00000000, 0xFFFFFF06, 0x00000000, 0x00000000, 0x00000043, 0x00000003, 0x802D90D8, 0x00000000, 0x0000015E, 0x00000043, 0x00000004, 0x802D8C7C, 0x00000000, 0x00000000, 0x00000001, 0x00000046, 0x00000001, D_80241DBC_EC8F6C, 0x00000043, 0x00000003, 0x802D9DE4, 0x00000000, 0xF24A8A80, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF84060DE, 0x00000000, 0x00000043, 0x00000003, 0x802DC228, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80004, 0x00C80001, 0x00000000, 0x00110067, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xF70F2E82, 0x00000001, 0x00000014, 0x00000001, 0xF70F2E82, 0x00000018, 0x00000001, 0x00000002, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80003, 0x00C80001, 0x00000000, 0x0011006B, 0x00000018, 0x00000001, 0x00000005, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80003, 0x00C80001, 0x00000000, 0x0011006C, 0x0000001B, 0x00000001, 0x00000005, 0x00000043, 0x00000006, 0x802DD810, 0x00000000, 0x00C80003, 0x00C80001, 0x00000000, 0x0011006D, 0x00000024, 0x00000002, 0xF70F2E83, 0x00000001, 0x00000043, 0x00000003, 0x802D78AC, D_80242B40_EC9CF0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, 0x802D9DE4, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242888_EC9A38
.word 0x00000003, 0x00000013, 0x00000014, 0x00000015

dlabel D_80242898_EC9A48
.word 0x00000001, 0x00000012

dlabel D_802428A0_EC9A50
.word D_80242888_EC9A38, D_80242898_EC9A48, 0x00000000, 0x00000000, D_802425F8_EC97A8

dlabel D_802428B4_EC9A64
.word 0xC39A8000, 0x00000000, 0x41F80000, 0x00000000

dlabel D_802428C4_EC9A74
.word 0x00000024, 0x00000002, 0xFE363C80, D_802428A0_EC9A50, 0x00000047, 0x00000005, D_802415AC_EC875C, 0x00001000, 0x00000004, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802415AC_EC875C, 0x00100000, D_802428B4_EC9A64, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024291C_EC9ACC
.word 0x00000000, D_80241220_EC83D0, 0xC3820000, 0x00000000, 0x00000000, 0x00000D01, D_80242428_EC95D8, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00C80001, 0x00000000, 0x00000000, 0x00000000, 0x001A00DE

dlabel D_80242B0C_EC9CBC
.word 0x00000001, D_8024291C_EC9ACC, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242B30_EC9CE0
.word 0x666C6F5F, 0x32350000

dlabel D_80242B38_EC9CE8
.word 0x666C6F5F, 0x31300000

dlabel D_80242B40_EC9CF0
.word 0x666C6F5F, 0x32350000, 0x00000000, 0x00000000
