.include "macro.inc"

.section .data

dlabel D_802429D0_EEFAD0
.word 0xC4340000, 0x00000000, 0x00000000, 0x42B40000, 0x44318000, 0x42C80000, 0x00000000, 0x43870000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80242BD0_EEFCD0, D_802429D0_EEFAD0, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x00190120

dlabel D_80242A30_EEFB30
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x00000035, 0x00000043, 0x00000005, 0x802E339C, 0x00000000, 0x00000030, 0x00000000, 0x00000008, 0x0000001C, 0x00000000, 0x00000043, 0x00000005, 0x802E339C, 0x00000000, 0x00000031, 0x00000000, 0x00000008, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242AA0_EEFBA0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, 0x802DF78C, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, 0x80286004, 0x00000043, 0x00000003, 0x802D78AC, D_80245440_EF2540, 0x00000004, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242AFC_EEFBFC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, 0x802DF78C, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, 0x80286004, 0x00000043, 0x00000003, 0x802D78AC, D_80245448_EF2548, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242B58_EEFC58
.word 0x00000047, 0x00000005, D_80242AA0_EEFBA0, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242AFC_EEFBFC, 0x00080000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242BA0_EEFCA0
.word 0x0000000A, 0xC39B0000, 0x00000000, 0x00000000, 0x0000000B, 0x43988000, 0x42C80000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242BD0_EEFCD0
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000026, 0x00000043, 0x00000002, 0x802E6F50, 0xFFFFFFFF, 0x00000043, 0x00000006, 0x802D7CD8, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, func_802D8248, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, 0x802D7B70, 0x00000000, 0x00000001, 0x00000043, 0x00000003, 0x80048338, 0x00000000, D_80244534_EF1634, 0x00000046, 0x00000001, D_80243FA4_EF10A4, 0x00000044, 0x00000001, D_802434CC_EF05CC, 0x00000043, 0x00000004, AddCoin, 0x00000003, 0x00000009, 0x00000002, 0x00000056, 0x00000000, 0x00000043, 0x00000002, 0x802D7384, D_80242BA0_EEFCA0, 0x00000057, 0x00000000, 0x00000043, 0x00000003, 0x802D6688, 0x00000010, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000011, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000012, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000014, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000016, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000018, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000013, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000015, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000017, 0x00000001, 0x00000043, 0x00000003, 0x802D6688, 0x00000019, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x0000008C, 0x0000000D, 0x00000002, 0xFE363C80, 0x00010000, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFF0000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, 0x802D67E4, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFF38, 0x0000000C, 0x00000002, 0xFE363C81, 0x00000000, 0x00000027, 0x00000002, 0xFE363C81, 0x00010000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, 0x802D67E4, 0x00000002, 0x00000000, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000057, 0x00000000, 0x00000044, 0x00000001, D_80245224_EF2324, 0x00000043, 0x00000004, AddCoin, 0x00000000, 0x00000001, 0x7FFFFE00, 0x00000043, 0x00000004, AddCoin, 0x00000000, 0x00000005, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, D_80242B58_EEFC58, 0x00000044, 0x00000001, 0x80285C70, 0x00000046, 0x00000001, D_80242A30_EEFB30, 0x0000000F, 0x00000002, 0xF5DE0180, 0x00000035, 0x00000043, 0x00000001, EED100_DeadUnkFunc1, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242F00_EF0000
.word 0x0000004D, 0x00000001, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C8C, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C8D, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C8E, 0xFE363C84, 0x00000028, 0x00000002, 0xFE363C8C, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C8D, 0xFE363C81, 0x00000026, 0x00000002, 0xFE363C80, 0xFE363C8C, 0x0000002F, 0x00000002, 0xFE363C80, 0xF24C0A80, 0x00000026, 0x00000002, 0xFE363C8F, 0xF24C0A80, 0x0000002F, 0x00000002, 0xFE363C8F, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C8F, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C85, 0x000000C8, 0x0000002A, 0x00000002, 0xFE363C85, 0xFE363C8F, 0x00000027, 0x00000002, 0xFE363C85, 0x00000001, 0x00000005, 0x00000001, 0xFE363C85, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8C, 0xFE363C80, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8D, 0xFE363C81, 0x00000043, 0x00000003, 0x802E1D00, 0x000000C7, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C83, 0x000000D2, 0x00000028, 0x00000002, 0xFE363C83, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C8B, 0x00000027, 0x00000002, 0xFE363C82, 0xFE363C8E, 0x00000043, 0x0000000F, 0x802E58EC, 0x0000000D, 0xFE363C80, 0xFE363C82, 0xFE363C81, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0xFE363C8F, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8C, 0xFE363C80, 0x00000043, 0x00000003, 0x802E1D00, 0xFE363C8D, 0xFE363C81, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C8B, 0x00000043, 0x0000000F, 0x802E58EC, 0x0000000D, 0xFE363C80, 0xFE363C8E, 0xFE363C81, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0xFE363C8F, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802431AC_EF02AC
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000043, 0x00000003, 0x802D6708, 0xFE363C86, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000001, EED140_UnkFunc43, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, 0x802D6708, 0xFE363C86, 0x00000001, 0x00000057, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C85, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C82, 0x00000008, 0x00000043, 0x0000000F, 0x802E58EC, 0x00000011, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000028, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000043, 0x00000007, 0x802E4310, 0xFE363C8A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000E, 0x00000000, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, 0x802E382C, 0x000000F8, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000057, 0x00000000, 0x00000043, 0x00000005, 0x802E1C00, 0x00000000, 0x000000B4, 0x00000014, 0x00000002, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, 0x802E1C7C, 0x00000043, 0x00000006, 0x802D60E4, 0xFE363C88, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D60E4, 0xFE363C89, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000003, 0x802D6708, 0xFE363C87, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802434CC_EF05CC
.word 0x00000043, 0x00000004, AddCoin, 0x00000003, 0x00000014, 0x00000006, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFD1C, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF74, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFEFC, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFC9, 0x00000024, 0x00000002, 0xFE363C84, 0x00000064, 0x00000044, 0x00000001, D_80242F00_EF0000, 0x00000024, 0x00000002, 0xFE363C80, 0x000000FA, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF74, 0x00000024, 0x00000002, 0xFE363C82, 0x000002D5, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFC9, 0x00000024, 0x00000002, 0xFE363C84, 0x000000B4, 0x00000044, 0x00000001, D_80242F00_EF0000, 0x00000043, 0x00000002, 0x802D6400, 0x00000041, 0x00000024, 0x00000002, 0xFE363C83, 0x00000041, 0x00000024, 0x00000002, 0xFE363C84, 0x00000042, 0x00000024, 0x00000002, 0xFE363C85, 0x00000043, 0x00000024, 0x00000002, 0xFE363C86, 0x00000044, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000044, 0x00000001, D_802431AC_EF02AC, 0x00000043, 0x00000002, 0x802D6400, 0x00000047, 0x00000024, 0x00000002, 0xFE363C83, 0x00000047, 0x00000024, 0x00000002, 0xFE363C84, 0x00000048, 0x00000024, 0x00000002, 0xFE363C85, 0x00000049, 0x00000024, 0x00000002, 0xFE363C86, 0x0000004A, 0x00000024, 0x00000002, 0xFE363C8A, 0x000000AE, 0x00000044, 0x00000001, D_802431AC_EF02AC, 0x00000043, 0x00000002, 0x802D6400, 0x0000004F, 0x00000024, 0x00000002, 0xFE363C83, 0x0000004F, 0x00000024, 0x00000002, 0xFE363C84, 0x00000050, 0x00000024, 0x00000002, 0xFE363C85, 0x00000051, 0x00000024, 0x00000002, 0xFE363C86, 0x00000052, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000044, 0x00000001, D_802431AC_EF02AC, 0x00000043, 0x00000002, 0x802D6400, 0x00000055, 0x00000024, 0x00000002, 0xFE363C83, 0x00000055, 0x00000024, 0x00000002, 0xFE363C84, 0x00000056, 0x00000024, 0x00000002, 0xFE363C85, 0x00000057, 0x00000024, 0x00000002, 0xFE363C86, 0x00000058, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000044, 0x00000001, D_802431AC_EF02AC, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80243760_EF0860
.word 0x001D00F0, 0x001D00F1

dlabel D_80243768_EF0868
.word 0x00010002, 0x00030004, 0x00090006, 0x00070008

dlabel D_80243778_EF0878
.word 0x001D00E0, 0x001D00E1, 0x001D00E2, 0x001D00E3, 0x001D00E4, 0x001D00E5, 0x001D00E6, 0x001D00E7, 0x001D00E8, 0x001D00E9, 0x001D00EA, 0x001D00EB, 0x001D00EC, 0x001D00ED, 0x001D00EE, 0x001D00EF

dlabel D_802437B8_EF08B8
.word 0x430C0000, 0x43340000, 0x435C0000

dlabel D_802437C4_EF08C4
.word 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, 0x802E37A0, 0x0000212D, 0x00000043, 0x00000002, EED1E0_UnkFunc21, 0xFD050F80, 0x00000008, 0x00000001, 0x00000055, 0x00000056, 0x00000000, 0x00000043, 0x00000002, 0x802E37A0, 0x0000212E, 0x00000043, 0x00000003, EED1E0_UnkFunc23, 0x00000046, 0x00000046, 0x00000008, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, 0x802E37A0, 0x0000208E, 0x00000043, 0x00000003, EED1E0_UnkFunc23, 0x00000032, 0x00000032, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_8024011C_EED21C, 0xFD050F80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002F, 0x00000043, 0x00000001, EED1E0_UnkFunc22, 0x00000043, 0x00000001, EED1E0_UnkPartnerPosFunc, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, EED1E0_UnkPartnerPosFunc2, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, EED1E0_UnkPartnerPosFunc, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_802406E0_EED7E0, 0xFD050F80, 0x00000008, 0x00000001, 0x0000001E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243928_EF0A28
.word 0x0000000A, 0x00000002, 0xF84060FB, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x80048290, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, EED1E0_UnkFunc40, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, 0x802E2EAC, 0x00000001, 0x00200000, 0x00000043, 0x00000001, EED1E0_SetOverrideFlags_40, 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x00000043, 0x00000002, 0x802DCA48, 0x00000000, 0x00000043, 0x00000004, 0x802DC5C0, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x00000043, 0x00000003, EED1E0_UnkFunc20, 0xFD050F80, 0xFE363C89, 0x00000043, 0x00000003, 0x802E4064, 0x0000000F, 0xFE363C8C, 0x00000043, 0x00000001, EED1E0_UnkFunc38, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000004, 0x802DDE0C, 0x001D00DC, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, EED1E0_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000043, 0x00000001, 0x802DCA8C, 0x00000043, 0x00000003, 0x802E2EAC, 0x00000000, 0x00200000, 0x00000043, 0x00000001, EED1E0_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D36, 0x00000000, 0x00000024, 0x00000002, 0xF8405D36, 0x00000001, 0x00000043, 0x00000004, 0x802DDE0C, 0x001D00DA, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, 0x802DDE0C, 0x001D00DB, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_802402AC_EED3AC, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000002, EED1E0_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000043, 0x00000001, 0x802DCA8C, 0x00000043, 0x00000003, 0x802E2EAC, 0x00000000, 0x00200000, 0x00000043, 0x00000001, EED1E0_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000043, 0x00000001, 0x802DCA8C, 0x00000043, 0x00000002, 0x802DD1D4, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000043, 0x00000002, EED1E0_SwitchToPartner, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000002, 0x802DCACC, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, 0x802DDE0C, 0x001D00DF, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, 0x802DE138, 0x001E000D, 0x00000043, 0x00000001, 0x802DE040, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, EED1E0_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000043, 0x00000001, 0x802DCA8C, 0x00000043, 0x00000003, 0x802E2EAC, 0x00000000, 0x00200000, 0x00000043, 0x00000001, EED1E0_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_802437C4_EF08C4, 0x00000043, 0x00000003, EED1E0_UnkFunc18, 0xFE363C8B, 0xFE363C8D, 0x00000024, 0x00000002, 0xF84060FB, 0x00000001, 0x00000043, 0x00000002, EED1E0_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000001, EED1E0_UnkFunc19, 0x0000000A, 0x00000002, 0xFE363C8D, 0x00000001, 0x00000043, 0x00000004, 0x802DDE0C, 0x001D00DD, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, 0x802DDE0C, 0x001D00DE, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000043, 0x00000001, 0x802DCA8C, 0x00000043, 0x00000003, 0x802E2EAC, 0x00000000, 0x00200000, 0x00000043, 0x00000001, EED1E0_UnkFunc17, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243DA8_EF0EA8
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, 0x802D83DC, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243E10_EF0F10
.word 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x00000043, 0x00000002, 0x802DE404, 0x00000001, 0x00000043, 0x00000002, 0x802DE6F8, 0x00000006, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000045, 0x00000002, D_80243DA8_EF0EA8, 0xFE363C8A, 0x00000043, 0x00000002, 0x802DE674, 0xF24A7D4D, 0x00000043, 0x00000005, 0x802DEF08, 0x000001C2, 0x000000B4, 0xFFFFFF88, 0x0000001E, 0x00000043, 0x00000002, 0x802DE6F8, 0x00000000, 0x00000043, 0x00000002, 0x802DE404, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243EE0_EF0FE0
.word 0x0000000A, 0x00000002, 0xF97188A7, 0x00000000, 0x00000043, 0x00000001, EED1E0_UnkFunc44, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, 0x802DF41C, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C80, 0x00000021, 0x00000002, 0x0000026C, 0x00000294, 0x00000043, 0x00000007, 0x802E4310, 0x0000015C, 0x00000280, 0x00000091, 0xFFFFFF9C, 0x0000000D, 0xF84060EC, 0x00000024, 0x00000002, 0xF97188A7, 0x00000001, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243FA4_EF10A4
.word 0x00000024, 0x00000002, 0xF97188A7, 0x00000000, 0x00000047, 0x00000005, D_80243EE0_EF0FE0, 0x00000080, 0x00000014, 0x00000001, 0x00000000, 0x00000043, 0x00000007, 0x8011A58C, 0x802F8DC0, 0x0000015E, 0x000000F0, 0xFFFFFF9C, 0x00000000, D_80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000002, 0x8011A8C0, 0xF84060FB, 0x00000043, 0x00000002, 0x8011A804, D_80243928_EF0A28, 0x00000043, 0x00000007, 0x8011A58C, 0x802F8EE0, 0x000001D8, 0x00000064, 0xFFFFFF9C, 0x00000000, D_80000000, 0x00000043, 0x00000002, 0x8011A804, D_80243E10_EF0F10, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244070_EF1170
.float 4.5, 3.5, 2.6, 2.0, 1.5, 20.0

dlabel D_80244088_EF1188
.word 0x3F800000, 0x0000002D, 0x0000003C, 0x42C80000, 0x00000000, 0x00000003, 0x40666666, 0x0000000A, 0x00000001, 0x42F00000, 0x00000000, 0x00000001

dlabel D_802440B8_EF11B8
.word 0x00000043, 0x00000003, 0x8004930C, 0x00000000, 0x00000001, 0x00000043, 0x00000003, 0x8004930C, 0x00000005, 0x00000000, 0x00000043, 0x00000003, 0x8004930C, 0x00000006, 0x00000000, 0x00000043, 0x00000003, 0x8004930C, 0x00000001, 0x00000258, 0x00000043, 0x00000002, func_80242780_EEF880, D_80244088_EF1188, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244128_EF1228
.word 0x00000000, 0x0018001C, 0x00000000, 0x00000000, D_802440B8_EF11B8, 0x8007D3C0, 0x00000000, 0x8007D4EC, 0x00000000, 0x00000000, 0x00130000

dlabel D_80244154_EF1254
.word 0x00000000, D_80244128_EF1228, 0x43DC0000, 0x43110000, 0x41700000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x800A0082, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x000001B8, 0x00000091, 0x0000000F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000001E5, 0x00000091, 0x00000037, 0x000000E1, 0x0000005F, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x007D0000, 0x007D0000, 0x007D0005, 0x007D0005, 0x007D0000, 0x007D0000, 0x007D0006, 0x007D0006, 0x007D0005, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244344_EF1444
.word 0x00000001, D_80244128_EF1228, 0x44160000, 0x43110000, 0x41700000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x800A0082, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x00000258, 0x00000091, 0x0000000F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000001E5, 0x00000091, 0x00000037, 0x000000E1, 0x0000005F, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x007D0000, 0x007D0000, 0x007D0005, 0x007D0005, 0x007D0000, 0x007D0000, 0x007D0006, 0x007D0006, 0x007D0005, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x007D0001, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244534_EF1634
.word 0x00000001, D_80244154_EF1254, 0x1A240006, 0x00000001, D_80244344_EF1444, 0x1A200006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244560_EF1660
.word 0x00000043, 0x00000001, func_802429A0_EEFAA0, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x0000000A, 0x00000002, 0xF97188A9, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C86, 0x00000032, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x000000B4, 0x00000024, 0x00000002, 0xF97188A9, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000032, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x000000B4, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xF97188A9, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, 0x802E37A0, 0x0000204D, 0x00000056, 0x00000000, 0x00000043, 0x00000005, 0x802D8758, 0x00000000, 0x00000000, 0x0000001E, 0xF24A7DB4, 0x00000043, 0x00000005, 0x802D8758, 0x00000000, 0x00000000, 0x00000005, 0xF24A7B4D, 0x00000057, 0x00000000, 0x00000043, 0x00000005, 0x802E1C00, 0xFE363C85, 0xFE363C86, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, 0x802E1C7C, 0x00000043, 0x00000005, 0x802D5FE0, 0x0000005E, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000061, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x0000006C, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x0000006F, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000061, 0xFE363C87, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x0000006F, 0xFE363C87, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000002, 0x802D7634, 0x0000001A, 0x00000043, 0x00000002, 0x802D7634, 0x0000001B, 0x00000043, 0x00000002, 0x802D7634, 0x00000020, 0x00000043, 0x00000002, 0x802D7634, 0x00000021, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, 0x802E1C00, 0xFE363C87, 0xFE363C88, 0x0000000F, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, 0x802E1C7C, 0x00000043, 0x00000005, 0x802D5FE0, 0x0000005E, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000061, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x0000006C, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x0000006F, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000061, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x0000006F, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024495C_EF1A5C
.word 0x00000043, 0x00000001, func_802429A0_EEFAA0, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x0000000A, 0x00000002, 0xF97188AA, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C86, 0x00000032, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x000000B4, 0x00000024, 0x00000002, 0xF97188AA, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000032, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x000000B4, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xF97188AA, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, 0x802E37A0, 0x0000204D, 0x00000056, 0x00000000, 0x00000043, 0x00000005, 0x802D8758, 0x00000000, 0x00000000, 0x0000001E, 0xF24A7DB4, 0x00000043, 0x00000005, 0x802D8758, 0x00000000, 0x00000000, 0x00000005, 0xF24A7B4D, 0x00000057, 0x00000000, 0x00000043, 0x00000005, 0x802E1C00, 0xFE363C85, 0xFE363C86, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, 0x802E1C7C, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000065, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000068, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000073, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000076, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000081, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000084, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000068, 0xFE363C87, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000076, 0xFE363C87, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000084, 0xFE363C87, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000002, 0x802D7634, 0x0000001D, 0x00000043, 0x00000002, 0x802D7634, 0x0000001E, 0x00000043, 0x00000002, 0x802D7634, 0x00000023, 0x00000043, 0x00000002, 0x802D7634, 0x00000024, 0x00000043, 0x00000002, 0x802D7634, 0x00000029, 0x00000043, 0x00000002, 0x802D7634, 0x0000002A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, 0x802E1C00, 0xFE363C87, 0xFE363C88, 0x0000000F, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, 0x802E1C7C, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000065, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000068, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000073, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000076, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000081, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x00000084, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000068, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000076, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x00000084, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244E28_EF1F28
.word 0x00000043, 0x00000001, func_802429A0_EEFAA0, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000001, 0x0000000A, 0x00000002, 0xF97188AB, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C86, 0xFFFFFFCE, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x000000B4, 0x00000024, 0x00000002, 0xF97188AB, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xFFFFFFCE, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x000000B4, 0x00000024, 0x00000002, 0xFE363C88, 0x00000000, 0x00000024, 0x00000002, 0xF97188AB, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, 0x802E37A0, 0x0000204D, 0x00000056, 0x00000000, 0x00000043, 0x00000005, 0x802D8758, 0x00000000, 0x00000000, 0x0000001E, 0xF24A7DB4, 0x00000043, 0x00000005, 0x802D8758, 0x00000000, 0x00000000, 0x00000005, 0xF24A7B4D, 0x00000057, 0x00000000, 0x00000043, 0x00000005, 0x802E1C00, 0xFE363C85, 0xFE363C86, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, 0x802E1C7C, 0x00000043, 0x00000005, 0x802D5FE0, 0x0000007A, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x0000007D, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000088, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x0000008B, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x0000007D, 0xFE363C87, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x0000008B, 0xFE363C87, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000002, 0x802D7634, 0x00000026, 0x00000043, 0x00000002, 0x802D7634, 0x00000027, 0x00000043, 0x00000002, 0x802D7634, 0x0000002C, 0x00000043, 0x00000002, 0x802D7634, 0x0000002D, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, 0x802DE448, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, 0x802E1C00, 0xFE363C87, 0xFE363C88, 0x0000000F, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, 0x802E1C7C, 0x00000043, 0x00000005, 0x802D5FE0, 0x0000007A, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x0000007D, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D5FE0, 0x00000088, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000005, 0x802D6C60, 0x0000008B, 0x00000000, 0xFE363C86, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x0000007D, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, 0x802D6D84, 0x0000008B, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245224_EF2324
.word 0x00000024, 0x00000002, 0xF97188A9, 0x00000000, 0x00000024, 0x00000002, 0xF97188AA, 0x00000000, 0x00000024, 0x00000002, 0xF97188AB, 0x00000000, 0x00000043, 0x00000003, 0x802D75C0, 0x0000001A, 0x0000005E, 0x00000043, 0x00000003, 0x802D75C0, 0x0000001B, 0x0000005E, 0x00000043, 0x00000003, 0x802D75C0, 0x0000001D, 0x00000065, 0x00000043, 0x00000003, 0x802D75C0, 0x0000001E, 0x00000065, 0x00000043, 0x00000003, 0x802D75C0, 0x00000020, 0x0000006C, 0x00000043, 0x00000003, 0x802D75C0, 0x00000021, 0x0000006C, 0x00000043, 0x00000003, 0x802D75C0, 0x00000023, 0x00000073, 0x00000043, 0x00000003, 0x802D75C0, 0x00000024, 0x00000073, 0x00000043, 0x00000003, 0x802D75C0, 0x00000026, 0x0000007A, 0x00000043, 0x00000003, 0x802D75C0, 0x00000027, 0x0000007A, 0x00000043, 0x00000003, 0x802D75C0, 0x00000029, 0x00000081, 0x00000043, 0x00000003, 0x802D75C0, 0x0000002A, 0x00000081, 0x00000043, 0x00000003, 0x802D75C0, 0x0000002C, 0x00000088, 0x00000043, 0x00000003, 0x802D75C0, 0x0000002D, 0x00000088, 0x00000047, 0x00000005, D_80244560_EF1660, 0x00000080, 0x0000001A, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024495C_EF1A5C, 0x00000080, 0x0000001D, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80244560_EF1660, 0x00000080, 0x00000020, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024495C_EF1A5C, 0x00000080, 0x00000023, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80244E28_EF1F28, 0x00000080, 0x00000026, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024495C_EF1A5C, 0x00000080, 0x00000029, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80244E28_EF1F28, 0x00000080, 0x0000002C, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245440_EF2540
.word 0x666C6F5F, 0x30300000

dlabel D_80245448_EF2548
.word 0x666C6F5F, 0x31370000
