.include "macro.inc"

.section .data

dlabel D_80240FD0_D6AAF0
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410E0_D6AC00
.word 0x0000003E, 0x00000002, 0x00000010, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, pra_16_EnableWallReflection, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000001, pra_16_EnableWallReflection, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, pra_16_EnableFloorReflection, 0xFE363C80, 0x00000043, 0x00000002, pra_16_EnablePartnerReflection, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241188_D6ACA8
.word 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0xFE363C82, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C81, 0xFE363C82, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000005, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetTexPanOffset, 0xFE363C82, 0x00000000, 0xFE363C8A, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8A, 0x00000BB8, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x000000A0, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024128C_D6ADAC
.word 0x00000021, 0x00000022, 0xFFFFFFFF

dlabel D_80241298_D6ADB8
.word 0x0000001E, 0x0000001F, 0xFFFFFFFF

dlabel D_802412A4_D6ADC4
.word 0x00000024, 0x00000025, 0xFFFFFFFF

dlabel D_802412B0_D6ADD0
.word 0x00000027, 0x00000028, 0xFFFFFFFF

dlabel D_802412BC_D6ADDC
.word 0x00000021, 0x00000022, 0x00000024, 0x00000025, 0xFFFFFFFF

dlabel D_802412D0_D6ADF0
.word 0x0000001E, 0x0000001F, 0x00000027, 0x00000028, 0xFFFFFFFF

dlabel D_802412E4_D6AE04
.word 0x0000002B, 0x0000002C, 0xFFFFFFFF

dlabel D_802412F0_D6AE10
.word 0x0000002E, 0x0000002F, 0xFFFFFFFF

dlabel D_802412FC_D6AE1C
.word 0x00000034, 0x00000035, 0xFFFFFFFF

dlabel D_80241308_D6AE28
.word 0x00000031, 0x00000032, 0xFFFFFFFF

dlabel D_80241314_D6AE34
.word 0x0000002B, 0x0000002C, 0x00000034, 0x00000035, 0xFFFFFFFF

dlabel D_80241328_D6AE48
.word 0x0000002E, 0x0000002F, 0x00000031, 0x00000032, 0xFFFFFFFF

dlabel D_8024133C_D6AE5C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000003, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000015, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412BC_D6ADDC, 0x00000024, 0x00000002, 0xFE363C83, D_802412D0_D6ADF0, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_8024128C_D6ADAC, 0x00000024, 0x00000002, 0xFE363C83, D_80241298_D6ADB8, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241AF0, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241430_D6AF50
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x0000001D, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241314_D6AE34, 0x00000024, 0x00000002, 0xFE363C83, D_80241328_D6AE48, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412E4_D6AE04, 0x00000024, 0x00000002, 0xFE363C83, D_802412F0_D6AE10, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241AF8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241524_D6B044
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x00000021, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241314_D6AE34, 0x00000024, 0x00000002, 0xFE363C83, D_80241328_D6AE48, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412FC_D6AE1C, 0x00000024, 0x00000002, 0xFE363C83, D_80241308_D6AE28, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241AF8, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241618_D6B138
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000003, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0x00000019, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412BC_D6ADDC, 0x00000024, 0x00000002, 0xFE363C83, D_802412D0_D6ADF0, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412A4_D6ADC4, 0x00000024, 0x00000002, 0xFE363C83, D_802412B0_D6ADD0, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241AF0, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024170C_D6B22C
.word 0x00000047, 0x00000005, D_8024133C_D6AE5C, 0x00000100, 0x00000015, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241430_D6AF50, 0x00000100, 0x0000001D, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241524_D6B044, 0x00000100, 0x00000021, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241618_D6B138, 0x00000100, 0x00000019, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024178C_D6B2AC
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000003, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412BC_D6ADDC, 0x00000024, 0x00000002, 0xFE363C83, D_802412D0_D6ADF0, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_8024128C_D6ADAC, 0x00000024, 0x00000002, 0xFE363C83, D_80241298_D6ADB8, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241314_D6AE34, 0x00000024, 0x00000002, 0xFE363C83, D_80241328_D6AE48, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412E4_D6AE04, 0x00000024, 0x00000002, 0xFE363C83, D_802412F0_D6AE10, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241314_D6AE34, 0x00000024, 0x00000002, 0xFE363C83, D_80241328_D6AE48, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412FC_D6AE1C, 0x00000024, 0x00000002, 0xFE363C83, D_80241308_D6AE28, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000002, UseDoorSounds, 0x00000003, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412BC_D6ADDC, 0x00000024, 0x00000002, 0xFE363C83, D_802412D0_D6ADF0, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412A4_D6ADC4, 0x00000024, 0x00000002, 0xFE363C83, D_802412B0_D6ADD0, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x00000046, 0x00000001, D_802861B0_7E7030, 0x00000044, 0x00000001, D_8024170C_D6B22C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000015, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000018, 0x00000018, 0x00000028, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000044, 0x00000001, 0x80240FA0, 0x00000024, 0x00000002, 0xFE363C80, 0x0000003B, 0x00000024, 0x00000002, 0xFE363C81, 0x0000003C, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000044, 0x00000001, D_80241188_D6ACA8, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xF8406152, 0x00000044, 0x00000001, D_802410E0_D6AC00, 0x00000044, 0x00000001, D_8024178C_D6B2AC, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
