.include "macro.inc"

.section .data

dlabel D_80240450_C9A650
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, kzn_22_UpdateTexturePanSmooth, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, kzn_22_UpdateTexturePanStepped, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802404EC_C9A6EC
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0x00000003, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF38, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000258, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE70, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240450_C9A650, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240608_C9A808
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetTexPanner, 0xFE363C80, 0x00000004, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000004, 0x00000024, 0x00000002, 0xFE363C81, 0x000001F4, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE70, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80240450_C9A650, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240724_C9A924
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802420F0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240790_C9A990
.word 0x00000047, 0x00000005, D_80240724_C9A924, 0x00000080, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802407BC_C9A9BC
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x00000031, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000006, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000006, 0x00000001, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFBB4, 0x00000027, 0x00000002, 0xFE363C81, 0x0000012C, 0x00000027, 0x00000002, 0xFE363C82, 0xFFFFFE0C, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802408A8_C9AAA8
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x00000032, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000001, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000027, 0x00000002, 0xFE363C80, 0x0000012C, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFE0C, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240958_C9AB58
.word 0x00000005, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetModelCenter, 0x00000029, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C83, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C83, 0xFE363C81, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C81, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000008, 0x00000043, 0x00000001, func_802D2B6C, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000017, 0x00000008, 0x00000001, 0x0000001E, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A34_C9AC34
.word 0x0000004D, 0x00000001, 0x000000EF, 0x00000043, 0x00000003, SetTexPanner, 0x0000002B, 0x00000002, 0x00000043, 0x00000003, SetTexPanner, 0x00000029, 0x00000002, 0x00000043, 0x00000003, EnableModel, 0x00000029, 0x00000000, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000013, 0x00000029, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7A80, 0x00000026, 0x00000002, 0xFE363C85, 0xF24A7A80, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000013, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000002, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000002, 0x00000001, 0xFE363C82, 0xFE363C83, 0x00000028, 0x00000002, 0xFE363C80, 0x000002BC, 0x00000027, 0x00000002, 0xFE363C81, 0x000002BC, 0x00000027, 0x00000002, 0xFE363C82, 0x000000C8, 0x00000028, 0x00000002, 0xFE363C83, 0x0000012C, 0x00000014, 0x00000001, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, kzn_22_GetFloorCollider, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000009, 0x00000044, 0x00000001, D_80240958_C9AB58, 0x00000043, 0x00000003, EnableModel, 0x00000029, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000002B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000000A, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x0000000A, 0x0000000C, 0x00000002, 0xFE363C84, 0x0000008C, 0x00000024, 0x00000002, 0xFE363C85, 0xF24A8080, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF9718890, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xF24A7A80, 0x00000012, 0x00000000, 0x0000000C, 0x00000002, 0xFE363C84, 0x0000011D, 0x00000024, 0x00000002, 0xFE363C85, 0xF24A85B4, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xF24A7A80, 0x00000024, 0x00000002, 0xFE363C8A, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x0000002C, 0x00000002, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, TranslateModel, 0x00000029, 0x00000000, 0xFE363C84, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D30_C9AF30
.word 0x00000007, 0x43480000, 0x43160000, 0x43340000, 0x00000009, 0x43480000, 0x43160000, 0x43340000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000012, 0x00000043, 0x00000002, SetSpriteShading, 0x000A000F, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x802420C0, 0x00000046, 0x00000001, D_80240EE0_C9B0E0, 0x00000024, 0x00000002, 0xFE363C80, D_80240790_C9A990, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000044, 0x00000001, 0x802403E0, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000013, 0x00000003, 0x00000056, 0x00000000, 0x00000043, 0x00000002, ResetFromLava, D_80240D30_C9AF30, 0x00000057, 0x00000000, 0x00000044, 0x00000001, D_802407BC_C9A9BC, 0x00000044, 0x00000001, D_802408A8_C9AAA8, 0x00000044, 0x00000001, D_80240A34_C9AC34, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002E, 0x00000044, 0x00000001, D_802404EC_C9A6EC, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002F, 0x00000044, 0x00000001, D_80240608_C9A808, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240EE0_C9B0E0
.word 0x00000043, 0x00000008, MakeEntity, D_802EAE30, 0x000001E0, 0x000000EB, 0x000000AF, 0x00000000, 0x00000000, 0x80000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
