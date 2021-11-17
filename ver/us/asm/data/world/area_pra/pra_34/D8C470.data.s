.include "macro.inc"

.section .data

dlabel D_802410C0_D8C470
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411D0_D8C580
.word 0x0000003E, 0x00000002, 0x00000010, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, pra_34_ReflectWall, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000001, pra_34_ReflectWall, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, pra_34_ReflectFloor, 0xFE363C80, 0x00000043, 0x00000002, pra_34_ReflectPartner, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241278_D8C628
.word 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0xFE363C82, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C81, 0xFE363C82, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000005, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetTexPanOffset, 0xFE363C82, 0x00000000, 0xFE363C8A, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8A, 0x00000BB8, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x000000A0, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024137C_D8C72C
.word 0x0000002E, 0x0000002F, 0xFFFFFFFF

dlabel D_80241388_D8C738
.word 0x00000031, 0x00000032, 0xFFFFFFFF

dlabel D_80241394_D8C744
.word 0x00000018, 0x00000019, 0xFFFFFFFF

dlabel D_802413A0_D8C750
.word 0x00000015, 0x00000016, 0xFFFFFFFF

dlabel D_802413AC_D8C75C
.word 0x0000002E, 0x0000002F, 0x00000018, 0x00000019, 0xFFFFFFFF

dlabel D_802413C0_D8C770
.word 0x00000031, 0x00000032, 0x00000015, 0x00000016, 0xFFFFFFFF

dlabel D_802413D4_D8C784
.word 0x00000028, 0x00000029, 0xFFFFFFFF

dlabel D_802413E0_D8C790
.word 0x0000002B, 0x0000002C, 0xFFFFFFFF

dlabel D_802413EC_D8C79C
.word 0x00000012, 0x00000013, 0xFFFFFFFF

dlabel D_802413F8_D8C7A8
.word 0x0000000F, 0x00000010, 0xFFFFFFFF

dlabel D_80241404_D8C7B4
.word 0x00000028, 0x00000029, 0x00000012, 0x00000013, 0xFFFFFFFF

dlabel D_80241418_D8C7C8
.word 0x0000002B, 0x0000002C, 0x0000000F, 0x00000010, 0xFFFFFFFF

dlabel D_8024142C_D8C7DC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x0000000D, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413AC_D8C75C, 0x00000024, 0x00000002, 0xFE363C83, D_802413C0_D8C770, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_8024137C_D8C72C, 0x00000024, 0x00000002, 0xFE363C83, D_80241388_D8C738, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241E90, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241510_D8C8C0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000015, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241404_D8C7B4, 0x00000024, 0x00000002, 0xFE363C83, D_80241418_D8C7C8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413D4_D8C784, 0x00000024, 0x00000002, 0xFE363C83, D_802413E0_D8C790, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241E98, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415F4_D8C9A4
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x00000019, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241404_D8C7B4, 0x00000024, 0x00000002, 0xFE363C83, D_80241418_D8C7C8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413EC_D8C79C, 0x00000024, 0x00000002, 0xFE363C83, D_802413F8_D8C7A8, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241E98, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802416D8_D8CA88
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0x00000011, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413AC_D8C75C, 0x00000024, 0x00000002, 0xFE363C83, D_802413C0_D8C770, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241394_D8C744, 0x00000024, 0x00000002, 0xFE363C83, D_802413A0_D8C750, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80285EEC_7E6D6C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241E90, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802417BC_D8CB6C
.word 0x00000014, 0x00000000

dlabel D_802417C4_D8CB74
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000004F, 0x00000001, 0x00000001, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00D8, 0x000000A0, 0x00000028, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000050, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000050, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000024, 0x00000002, 0xF8406170, 0x00000001, 0x00000043, 0x00000005, pra_34_GetEntityPosition, 0xFD050F80, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, PlaySoundAt, 0x00000269, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, pra_34_GetEntityPosition, 0xFD050F81, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, PlaySoundAt, 0x00000269, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F80, 0x00000043, 0x00000001, pra_34_SetEntityFlags100000, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000001, pra_34_SetEntityFlags100000, 0x00000050, 0x00000001, 0x00000001, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241970_D8CD20
.word 0x00000047, 0x00000005, D_8024142C_D8C7DC, 0x00000100, 0x0000000D, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802416D8_D8CA88, 0x00000100, 0x00000011, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8406170, 0x00000000, 0x0000004E, 0x00000006, D_802417C4_D8CB74, 0x00000100, 0x00004000, D_802417BC_D8CB6C, 0x00000000, 0x00000001, 0x0000004E, 0x00000006, D_802417C4_D8CB74, 0x00000100, 0x00004001, D_802417BC_D8CB6C, 0x00000000, 0x00000001, 0x00000012, 0x00000000, 0x00000047, 0x00000005, D_80241510_D8C8C0, 0x00000100, 0x00000015, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802415F4_D8C9A4, 0x00000100, 0x00000019, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A50_D8CE00
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413AC_D8C75C, 0x00000024, 0x00000002, 0xFE363C83, D_802413C0_D8C770, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_8024137C_D8C72C, 0x00000024, 0x00000002, 0xFE363C83, D_80241388_D8C738, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241404_D8C7B4, 0x00000024, 0x00000002, 0xFE363C83, D_80241418_D8C7C8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413D4_D8C784, 0x00000024, 0x00000002, 0xFE363C83, D_802413E0_D8C790, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241404_D8C7B4, 0x00000024, 0x00000002, 0xFE363C83, D_80241418_D8C7C8, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413EC_D8C79C, 0x00000024, 0x00000002, 0xFE363C83, D_802413F8_D8C7A8, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x0000000A, 0x00000002, 0xF8406152, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_802413AC_D8C75C, 0x00000024, 0x00000002, 0xFE363C83, D_802413C0_D8C770, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, D_80241394_D8C744, 0x00000024, 0x00000002, 0xFE363C83, D_802413A0_D8C750, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x00000046, 0x00000001, D_802861B0_7E7030, 0x00000044, 0x00000001, D_80241970_D8CD20, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000015, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000018, 0x00000018, 0x00000028, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000046, 0x00000001, 0x80241DD8, 0x00000044, 0x00000001, 0x80241080, 0x00000024, 0x00000002, 0xFE363C80, 0x0000001D, 0x00000024, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000044, 0x00000001, D_80241278_D8C628, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xF8406152, 0x00000044, 0x00000001, D_802411D0_D8C580, 0x00000044, 0x00000001, D_80241A50_D8CE00, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
