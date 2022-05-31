.include "macro.inc"

.section .data

dlabel D_80242AB0_A052F0
.word 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0179, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242B54_A05394
.word 0x0000000A, 0x00000002, 0xF8405DC5, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000005, 0x00000001, 0x00000019, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetItemPos, 0xFD050F80, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFFFFFEA7, 0x0000004B, 0xFFFFFF8B, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000004, 0xF24A8080, 0x0000000E, 0x00000002, 0xFE363C80, 0xFFFFFEA7, 0x00000043, 0x00000006, NpcJump0, 0x00000004, 0xFFFFFEE8, 0x00000000, 0xFFFFFF90, 0x00000014, 0x00000012, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000004, 0xFFFFFE66, 0x00000000, 0xFFFFFF90, 0x00000014, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802EAFDC, 0xFFFFFF6A, 0x00000000, 0xFFFFFF51, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80242AB0_A052F0, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFA5, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_BlueSwitch, 0x00000064, 0x00000000, 0xFFFFFF47, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignAreaFlag, 0x00000002, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0xFFFFFD71, 0x0000004B, 0xFFFFFFDD, 0x00000011, 0xF8405DC6, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0xFFFFFD80, 0x0000004B, 0xFFFFFFEC, 0x00000011, 0xF8405DC7, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0xFFFFFD80, 0x0000004B, 0xFFFFFFCE, 0x00000011, 0xF8405DC8, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0xFFFFFD62, 0x0000004B, 0xFFFFFFEC, 0x00000011, 0xF8405DC9, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0xFFFFFD62, 0x0000004B, 0xFFFFFFCE, 0x00000011, 0xF8405DCA, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0xFFFFFEA7, 0x0000004D, 0xFFFFFF8B, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80242B54_A05394, 0x00000043, 0x00000007, MakeItemEntity, 0x00000084, 0xFFFFFEA7, 0x00000066, 0xFFFFFF8B, 0x00000011, 0xF8405DC5, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x000000C8, 0x0000003C, 0xFFFFFF60, 0x00000000, 0x80000000, 0x00000043, 0x00000008, MakeEntity, Entity_D_802EA588, 0x000000FA, 0x0000003C, 0xFFFFFF60, 0x00000000, 0x00000080, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405DD7, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x0000012C, 0x0000003C, 0xFFFFFF60, 0x00000000, 0x80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAB04, 0xFFFFFD76, 0x0000004B, 0xFFFFFFCE, 0x00000000, 0x00000008, 0x80000000, 0x00000043, 0x00000002, AssignPanelFlag, 0xF8405DE1, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
