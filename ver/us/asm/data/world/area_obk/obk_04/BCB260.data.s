.include "macro.inc"

.section .data

dlabel D_80243400_BCB260
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, SetPlayerSpeed, 0xF24A8680, 0x00000043, 0x00000004, PlayerMoveTo, 0xFFFFFF6A, 0xFE363C82, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000000D, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000000F, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000043, 0x00000003, EnableModel, 0x0000000D, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000000F, 0x00000001, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFA6, 0x0000000F, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000000B, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0xFFFFFF29, 0x00000000, 0x00000019, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0xFFFFFF29, 0x00000000, 0xFFFFFFE7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0xFFFFFF38, 0x00000000, 0x00000019, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0xFFFFFF38, 0x00000000, 0xFFFFFFE7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0xFFFFFF47, 0x00000000, 0x00000019, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0xFFFFFF47, 0x00000000, 0xFFFFFFE7, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, EnableModel, 0x0000000B, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000000A, 0x0000000F, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0x0000000D, 0xFE363C80, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000010, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802437FC_BCB65C
.word 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000001E, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0x0000001F, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000003, 0x00000001, 0x00000014, 0x00000027, 0x00000002, 0xFE363C80, 0x0000012C, 0x00000027, 0x00000002, 0xFE363C81, 0x00000064, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000000, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000014, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000000D, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x8024336C, 0x00000046, 0x00000001, 0x80241014, 0x00000044, 0x00000001, D_802439C0_BCB820, 0x00000044, 0x00000001, D_802437FC_BCB65C, 0x00000044, 0x00000001, D_80243400_BCB260, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000012, 0x7FFFFE00, 0x00000044, 0x00000001, 0x80240ED0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802439C0_BCB820
.word 0x00000043, 0x00000001, func_80240910_BC8770, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000003, GotoMap, 0x802451D0, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
