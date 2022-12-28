.include "macro.inc"

.section .data

dlabel D_80240FF0_D77390
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241100_D774A0
.word 0x0000003E, 0x00000002, 0x00000010, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, pra_20_EnableWallReflection, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000001, pra_20_EnableWallReflection, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, pra_20_EnableFloorReflection, 0xFE363C80, 0x00000043, 0x00000002, pra_20_EnablePartnerReflection, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411A8_D77548
.word 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0xFE363C82, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C81, 0xFE363C82, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000005, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetTexPanOffset, 0xFE363C82, 0x00000000, 0xFE363C8A, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8A, 0x00000BB8, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x000000A0, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802412AC_D7764C
.word 0x0000003C, 0x0000003D, 0xFFFFFFFF

dlabel D_802412B8_D77658
.word 0x00000000, 0x00000001, 0xFFFFFFFF

dlabel D_802412C4_D77664
.word 0x0000002A, 0x0000002B, 0xFFFFFFFF

dlabel D_802412D0_D77670
.word 0x0000002D, 0x0000002E, 0xFFFFFFFF

dlabel D_802412DC_D7767C
.word 0x00000014, 0x00000015, 0xFFFFFFFF

dlabel D_802412E8_D77688
.word 0x00000011, 0x00000012, 0xFFFFFFFF

dlabel D_802412F4_D77694
.word 0x0000002A, 0x0000002B, 0x00000014, 0x00000015, 0xFFFFFFFF

dlabel D_80241308_D776A8
.word 0x0000002D, 0x0000002E, 0x00000011, 0x00000012, 0xFFFFFFFF

dlabel D_8024131C_D776BC
.word 0xFFFFFFFF

dlabel D_80241320_D776C0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80241B60, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024137C_D7771C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000020, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412AC_D7764C, 0x00000024, 0x00000002, 0xFE363C83, D_802412B8_D77658, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412AC_D7764C, 0x00000024, 0x00000002, 0xFE363C83, D_8024131C_D776BC, 0x00000013, 0x00000000, 0x00000044, 0x00000001, BaseExitDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241B68, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241460_D77800
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x00000013, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412F4_D77694, 0x00000024, 0x00000002, 0xFE363C83, D_80241308_D776A8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412C4_D77664, 0x00000024, 0x00000002, 0xFE363C83, D_802412D0_D77670, 0x00000013, 0x00000000, 0x00000044, 0x00000001, BaseExitDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241B70, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241544_D778E4
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0x00000017, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412F4_D77694, 0x00000024, 0x00000002, 0xFE363C83, D_80241308_D776A8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412DC_D7767C, 0x00000024, 0x00000002, 0xFE363C83, D_802412E8_D77688, 0x00000013, 0x00000000, 0x00000044, 0x00000001, BaseExitDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241B70, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241628_D779C8
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000004, 0x00000024, 0x00000002, 0xFE363C81, 0x0000001C, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412AC_D7764C, 0x00000024, 0x00000002, 0xFE363C83, D_802412B8_D77658, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_8024131C_D776BC, 0x00000024, 0x00000002, 0xFE363C83, D_802412B8_D77658, 0x00000013, 0x00000000, 0x00000044, 0x00000001, BaseExitDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241B78, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024170C_D77AAC
.word 0x00000047, 0x00000005, D_80241320_D776C0, 0x00080000, 0x0000000B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024137C_D7771C, 0x00000100, 0x00000020, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241460_D77800, 0x00000100, 0x00000013, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241544_D778E4, 0x00000100, 0x00000017, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241628_D779C8, 0x00000100, 0x0000001C, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802417A8_D77B48
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_8024170C_D77AAC, 0x00000044, 0x00000001, EnterWalk, 0x00000016, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412AC_D7764C, 0x00000024, 0x00000002, 0xFE363C83, D_802412B8_D77658, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412AC_D7764C, 0x00000024, 0x00000002, 0xFE363C83, D_8024131C_D776BC, 0x00000013, 0x00000000, 0x00000046, 0x00000001, BaseEnterDoor, 0x00000044, 0x00000001, D_8024170C_D77AAC, 0x00000016, 0x00000001, 0x00000002, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412F4_D77694, 0x00000024, 0x00000002, 0xFE363C83, D_80241308_D776A8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412C4_D77664, 0x00000024, 0x00000002, 0xFE363C83, D_802412D0_D77670, 0x00000013, 0x00000000, 0x00000046, 0x00000001, BaseEnterDoor, 0x00000044, 0x00000001, D_8024170C_D77AAC, 0x00000016, 0x00000001, 0x00000003, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412F4_D77694, 0x00000024, 0x00000002, 0xFE363C83, D_80241308_D776A8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412DC_D7767C, 0x00000024, 0x00000002, 0xFE363C83, D_802412E8_D77688, 0x00000013, 0x00000000, 0x00000046, 0x00000001, BaseEnterDoor, 0x00000044, 0x00000001, D_8024170C_D77AAC, 0x00000016, 0x00000001, 0x00000004, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412AC_D7764C, 0x00000024, 0x00000002, 0xFE363C83, D_802412B8_D77658, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802412B8_D77658, 0x00000024, 0x00000002, 0xFE363C83, D_8024131C_D776BC, 0x00000013, 0x00000000, 0x00000046, 0x00000001, BaseEnterDoor, 0x00000044, 0x00000001, D_8024170C_D77AAC, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000015, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000018, 0x00000018, 0x00000028, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000044, 0x00000001, 0x80240FB0, 0x00000043, 0x00000003, EnableModel, 0x00000034, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000026, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, 0x00000019, 0x00000024, 0x00000002, 0xFE363C81, 0x0000001A, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000044, 0x00000001, D_802411A8_D77548, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xF8406152, 0x00000044, 0x00000001, D_80241100_D774A0, 0x00000044, 0x00000001, D_802417A8_D77B48, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000
