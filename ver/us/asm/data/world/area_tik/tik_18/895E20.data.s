.include "macro.inc"

.section .data

dlabel D_80240740_895E20
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, tik_18_UpdateTexturePanSmooth, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, tik_18_UpdateTexturePanStepped, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802407DC_895EBC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80241EF0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240838_895F18
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80241EF8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240894_895F74
.word 0x00000047, 0x00000005, D_802407DC_895EBC, 0x00080000, 0x00000008, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240838_895F18, 0x00080000, 0x0000000E, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000002, 0x00000043, 0x00000002, SetSpriteShading, 0x0000000D, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x80241D44, 0x00000046, 0x00000001, 0x80241D8C, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000000B, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000011, 0x7FFFFE00, 0x00000044, 0x00000001, D_80241588_896C68, 0x00000044, 0x00000001, 0x80240710, 0x00000043, 0x00000002, PlaySound, 0x80000043, 0x00000043, 0x00000003, EnableTexPanning, 0x00000007, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000032, 0x00000024, 0x00000002, 0xFE363C82, 0x000000C8, 0x00000024, 0x00000002, 0xFE363C83, 0x0000006E, 0x00000024, 0x00000002, 0xFE363C84, 0x000001F4, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240740_895E20, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x00000009, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFF38, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFF9C, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE0C, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240740_895E20, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x0000000A, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFF06, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFF9C, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE0C, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240740_895E20, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80240894_895F74, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D10_8963F0
.word 0x00000024, 0x00000002, 0xFE363C81, 0xF4ACD485, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0xF4ACD480, 0x00000024, 0x00000002, 0xFE363C83, 0xF4ACD481, 0x00000024, 0x00000002, 0xFE363C84, 0xF4ACD485, 0x00000027, 0x00000002, 0xFE363C84, 0x00000002, 0x00000024, 0x00000002, 0xFE363C85, 0xF4ACD480, 0x00000024, 0x00000002, 0xFE363C86, 0xF4ACD481, 0x00000024, 0x00000002, 0xFE363C87, 0xF4ACD485, 0x00000027, 0x00000002, 0xFE363C87, 0x00000003, 0x00000024, 0x00000002, 0xFE363C88, 0xF4ACD480, 0x00000024, 0x00000002, 0xFE363C89, 0xF4ACD481, 0x00000024, 0x00000002, 0xFE363C8A, 0xF4ACD485, 0x00000027, 0x00000002, 0xFE363C8A, 0x00000004, 0x00000024, 0x00000002, 0xFE363C8B, 0xF4ACD480, 0x00000024, 0x00000002, 0xFE363C8C, 0xF4ACD481, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0xFE363C84, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0xFE363C87, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0xFE363C8A, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000027, 0x00000002, 0xFE363C82, 0x00000001, 0x00000027, 0x00000002, 0xFE363C83, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0xFE363C81, 0xFE363C82, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000005, ScaleModel, 0xFE363C81, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000027, 0x00000002, 0xFE363C85, 0xFFFFFFFF, 0x00000027, 0x00000002, 0xFE363C86, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0xFE363C84, 0xFE363C85, 0xFE363C80, 0xFE363C86, 0x00000043, 0x00000005, ScaleModel, 0xFE363C84, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000027, 0x00000002, 0xFE363C88, 0x00000001, 0x00000027, 0x00000002, 0xFE363C89, 0xFFFFFFFF, 0x00000043, 0x00000005, TranslateModel, 0xFE363C87, 0xFE363C88, 0xFE363C80, 0xFE363C89, 0x00000043, 0x00000005, ScaleModel, 0xFE363C87, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000027, 0x00000002, 0xFE363C8B, 0xFFFFFFFF, 0x00000027, 0x00000002, 0xFE363C8C, 0xFFFFFFFF, 0x00000043, 0x00000005, TranslateModel, 0xFE363C8A, 0xFE363C8B, 0xFE363C80, 0xFE363C8C, 0x00000043, 0x00000005, ScaleModel, 0xFE363C8A, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000027, 0x00000002, 0xFE363C82, 0x00000001, 0x00000027, 0x00000002, 0xFE363C83, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0xFE363C81, 0xFE363C82, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000005, ScaleModel, 0xFE363C81, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000027, 0x00000002, 0xFE363C85, 0xFFFFFFFF, 0x00000027, 0x00000002, 0xFE363C86, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0xFE363C84, 0xFE363C85, 0xFE363C80, 0xFE363C86, 0x00000043, 0x00000005, ScaleModel, 0xFE363C84, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000027, 0x00000002, 0xFE363C88, 0x00000001, 0x00000027, 0x00000002, 0xFE363C89, 0xFFFFFFFF, 0x00000043, 0x00000005, TranslateModel, 0xFE363C87, 0xFE363C88, 0xFE363C80, 0xFE363C89, 0x00000043, 0x00000005, ScaleModel, 0xFE363C87, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000027, 0x00000002, 0xFE363C8B, 0xFFFFFFFF, 0x00000027, 0x00000002, 0xFE363C8C, 0xFFFFFFFF, 0x00000043, 0x00000005, TranslateModel, 0xFE363C8A, 0xFE363C8B, 0xFE363C80, 0xFE363C8C, 0x00000043, 0x00000005, ScaleModel, 0xFE363C8A, 0xF24A7C80, 0xF24A7C80, 0xF24A7C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C81, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C84, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C87, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0xFE363C8A, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411E0_8968C0
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000003C, 0x00000001, 0xFE363C8A, 0x00000024, 0x00000002, 0xFE363C85, 0xF4ACD485, 0x00000005, 0x00000001, 0x00000005, 0x00000043, 0x00000003, CloneModel, 0x00000012, 0xFE363C85, 0x00000043, 0x00000005, TranslateModel, 0xFE363C85, 0xF4ACD480, 0xF4ACD482, 0xF4ACD481, 0x00000027, 0x00000002, 0xFE363C85, 0x00000001, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x000000C8, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000032, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, EnableModel, 0xF4ACD485, 0x00000001, 0x00000043, 0x00000005, MakeLerp, 0xF4ACD482, 0xF4ACD483, 0xF4ACD484, 0x00000001, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD485, 0xF4ACD480, 0xFE363C80, 0xF4ACD481, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, tik_18_UnkPosFunc2, 0xF4ACD485, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, EnableModel, 0xF4ACD485, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x000003F6, 0x00000046, 0x00000001, D_80240D10_8963F0, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802413B8_896A98
.word 0x00000024, 0x00000002, 0xFE363C8F, 0x00002710, 0x00000030, 0x00000001, 0xFE363C80, 0x00000031, 0x00000001, 0xFE363C81, 0x00000005, 0x00000001, 0xFE363C81, 0x00000034, 0x00000004, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000031, 0x00000001, 0xFE363C89, 0x00000005, 0x00000001, 0xFE363C89, 0x0000003E, 0x00000002, 0x00000006, 0xFE363C8A, 0x0000003C, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000003, RandInt, 0xFE363C84, 0xFE363C8B, 0x00000043, 0x00000003, RandInt, 0xFE363C85, 0xFE363C8C, 0x00000024, 0x00000002, 0xFE363C8D, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C8E, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C8D, 0xFE363C8B, 0x00000027, 0x00000002, 0xFE363C8E, 0xFE363C8C, 0x00000024, 0x00000002, 0xF4ACD480, 0xFE363C8D, 0x00000024, 0x00000002, 0xF4ACD481, 0xFE363C8E, 0x00000024, 0x00000002, 0xF4ACD482, 0xFE363C86, 0x00000024, 0x00000002, 0xF4ACD483, 0xFE363C87, 0x00000024, 0x00000002, 0xF4ACD484, 0xFE363C88, 0x00000024, 0x00000002, 0xF4ACD485, 0xFE363C8F, 0x00000044, 0x00000001, D_802411E0_8968C0, 0x00000027, 0x00000002, 0xFE363C8F, 0x00000005, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000012, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241564_896C44
.word 0x00000001, 0xFFFFFF17, 0xFFFFFF8B, 0x00000221, 0x000000BB, 0x000000C8, 0xFFFFFFF6, 0x0000003C, 0x00000004

dlabel D_80241588_896C68
.word 0x00000024, 0x00000002, 0xFE363C80, D_80241564_896C44, 0x00000044, 0x00000001, D_802413B8_896A98, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
