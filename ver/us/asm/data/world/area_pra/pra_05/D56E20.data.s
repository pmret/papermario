.include "macro.inc"

.section .data

glabel D_80241270_D56E20
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000003E, 0x00000002, 0x00000010, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, pra_05_ReflectWall, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000001, pra_05_ReflectWall, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, pra_05_ReflectFloor, 0xFE363C80, 0x00000043, 0x00000002, pra_05_ReflectPartner, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C82, 0x00000016, 0x00000024, 0x00000002, 0xFE363C83, 0x00000013, 0x00000024, 0x00000002, 0xFE363C84, 0x00000017, 0x00000024, 0x00000002, 0xFE363C85, 0x00000014, 0x00000044, 0x00000001, 0x80285E9C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241870, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241428, 0x00000100, 0x0000000A, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000016, 0x00000024, 0x00000002, 0xFE363C83, 0x00000013, 0x00000024, 0x00000002, 0xFE363C84, 0x00000017, 0x00000024, 0x00000002, 0xFE363C85, 0x00000014, 0x00000046, 0x00000001, 0x80285EC4, 0x00000044, 0x00000001, 0x802414EC, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000015, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000018, 0x00000018, 0x00000028, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000046, 0x00000001, 0x80241818, 0x00000044, 0x00000001, 0x80241230, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0xF8406152, 0x00000044, 0x00000001, 0x80241380, 0x00000044, 0x00000001, 0x80241518, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241680_D57230
.word 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_802D5830, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, func_802D5830, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000046, 0x00000001, 0x80241684, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8B, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, AddItem, 0xFE363C8A, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, AddBadge, 0xFE363C8A, 0xFE363C80, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000034, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000001, 0x00000024, 0x00000002, 0xF8406155, 0x00000001, 0x00000046, 0x00000001, 0x802416EC, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE30, 0x000000C8, 0x00000014, 0x0000005E, 0x00000000, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignFlag, 0xF8406155, 0x00000043, 0x00000002, AssignScript, 0x802417CC, 0x00000002, 0x00000000, 0x00000001, 0x00000000
