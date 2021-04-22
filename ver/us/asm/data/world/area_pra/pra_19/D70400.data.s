.include "macro.inc"

.section .data

glabel D_80241A50_D70400
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000003E, 0x00000002, 0x00000010, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, pra_19_ReflectWall, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000001, pra_19_ReflectWall, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, pra_19_ReflectFloor, 0xFE363C80, 0x00000043, 0x00000002, pra_19_ReflectPartner, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0xFE363C82, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C81, 0xFE363C82, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000005, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetTexPanOffset, 0xFE363C82, 0x00000000, 0xFE363C8A, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8A, 0x00000BB8, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x000000A0, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000002E, 0x0000002F, 0xFFFFFFFF, 0x0000002B, 0x0000002C, 0xFFFFFFFF, 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000013, 0x00000024, 0x00000002, 0xFE363C82, 0x80241D0C, 0x00000024, 0x00000002, 0xFE363C83, 0x80241D18, 0x00000044, 0x00000001, 0x80285EEC, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x802479E0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802479E8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241D24, 0x00000100, 0x00000013, 0x00000001, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0x00000052, 0x00000047, 0x00000005, 0x80241DC8, 0x00080000, 0x00000019, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x80241D0C, 0x00000024, 0x00000002, 0xFE363C83, 0x80241D18, 0x00000046, 0x00000001, 0x802861B0, 0x00000044, 0x00000001, 0x80241E24, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x80241E24, 0x00000044, 0x00000001, EnterWalk, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000015, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000018, 0x00000018, 0x00000028, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x802479AC, 0x00000044, 0x00000001, 0x80241A10, 0x0000000F, 0x00000002, 0xF5DE0180, 0x00000052, 0x00000043, 0x00000003, EnableModel, 0x00000022, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000021, 0x7FFFFE00, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000024, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x0000003B, 0x00000024, 0x00000002, 0xFE363C81, 0x0000003C, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000044, 0x00000001, 0x80241C08, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000044, 0x00000001, 0x80241B60, 0x00000044, 0x00000001, 0x80241E84, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
