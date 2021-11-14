.include "macro.inc"

.section .data

dlabel D_80247380_807C00
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0170, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000060, 0x00000043, 0x00000007, MakeEntity, D_802E9A18, 0x00000118, 0x00000050, 0xFFFFFF7E, 0x00000000, D_80000000, 0x00000013, 0x00000000, 0x00000047, 0x00000005, D_80247380_807C00, 0x00000100, 0x00000033, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247430_807CB0
.word 0x00000026, 0x00000002, 0xFE363C81, 0xFE363C80, 0x0000002F, 0x00000002, 0xFE363C81, 0xF24B2E80, 0x00000043, 0x00000005, TranslateModel, 0x00000050, 0xFE363C81, 0x00000000, 0x00000000, 0x00000026, 0x00000002, 0xFE363C81, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C81, 0xF24A7E4D, 0x00000043, 0x00000006, RotateModel, 0x00000050, 0xFE363C81, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x004B004C, 0x003F0040, 0x00410042, 0x00430046, 0x00480049, 0x0047004D, 0x0044003D, 0x003E0000

dlabel D_802474DC_807D5C
.word 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C80, 0x00000043, 0x00000006, RotateModel, 0x00000044, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000003D, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000003E, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000003F, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000040, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000041, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000042, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000043, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000046, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000048, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000049, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000047, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000004B, 0xFE363C81, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000004C, 0xFE363C81, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000004D, 0xFE363C81, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x0000005A, 0x00000043, 0x00000003, EnableGroup, 0x0000004F, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x0000004F, 0x00000001, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024772C_807FAC
.word 0x00000043, 0x00000006, RotateModel, 0x00000050, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024775C_807FDC
.word 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000062, 0x00000001, 0x00000046, 0x00000001, 0x80257844, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000062, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802477CC_80804C
.word 0x00000043, 0x00000006, RotateModel, 0x0000006D, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00650066, 0x00670069, 0x006A006B, 0x00640000

dlabel D_8024780C_80808C
.word 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C81, 0xF24A7E80, 0x00000043, 0x00000006, RotateModel, 0x00000064, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000065, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000066, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000067, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000069, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006B, 0xFE363C81, 0x00000001, 0x00000000, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x0000005A, 0x00000043, 0x00000003, EnableGroup, 0x00000076, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000076, 0x00000001, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024796C_8081EC
.word 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000083, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B58F, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000083, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B58F, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802479F0_808270
.word 0x00000043, 0x00000006, RotateModel, 0x00000027, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247A20_8082A0
.word 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C80, 0x00000029, 0x00000002, 0xFE363C81, 0x00000002, 0x00000043, 0x00000006, RotateGroup, 0x00000026, 0xFE363C81, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247A70_8082F0
.word 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFF9A, 0x00000046, 0x00000001, 0x802502AC, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000021, 0x00000002, 0x0000003C, 0x0000003D, 0x00000044, 0x00000001, 0x80252EB0, 0x00000021, 0x00000002, 0xFFFFFFD8, 0x0000005F, 0x0000000A, 0x00000002, 0xF5DE0180, 0x0000003C, 0x00000022, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405C7D, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00A50004, 0x00A50001, 0x00000000, 0x0003003C, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000001B, 0x00000001, 0x00000060, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x0001003F, 0x000000A0, 0x00000028, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000031, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B58A, 0x00000001, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000031, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B58A, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247C28_8084A8
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x0000002C, 0x00000002, 0xFE363C80, 0xF24A8680, 0x0000000D, 0x00000002, 0xFE363C80, 0x00000168, 0x0000002D, 0x00000002, 0xFE363C80, 0xF2501A80, 0x00000013, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000039, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x0000003C, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247CF0_808570
.word 0x00000003, 0x00000004, 0x00000006, 0xFFFFFFFF

dlabel D_80247D00_808580
.word 0x00000010, 0x00000007, 0xFFFFFFFF

dlabel D_80247D0C_80858C
.word 0x00000000, 0x0000001D, 0xFFFFFFFF, 0x00000043, 0x0000000A, MakeDoorAdvanced, 0x00000002, D_80247430_807CB0, D_802474DC_807D5C, D_8024772C_807FAC, D_8024775C_807FDC, 0x00000016, 0x0000001C, 0x00000063, D_80247CF0_808570, 0x00000043, 0x0000000A, MakeDoorAdvanced, 0x00000002, D_802477CC_80804C, D_8024780C_80808C, 0x00000000, D_8024796C_8081EC, 0x00000021, 0x00000022, 0x00000084, D_80247D00_808580, 0x00000043, 0x0000000A, MakeDoorAdvanced, 0x00000002, D_802479F0_808270, D_80247A20_8082A0, 0x00000000, D_80247A70_8082F0, 0x00000052, 0x00000054, 0x00000035, D_80247D0C_80858C, 0x00000044, 0x00000001, D_80247C28_8084A8, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000044, 0x00000001, D_8024775C_807FDC, 0x00000044, 0x00000001, D_8024796C_8081EC, 0x00000044, 0x00000001, D_80247A70_8082F0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
