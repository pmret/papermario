.include "macro.inc"

.section .data

dlabel D_80240E10_AA8290
.word 0x0000000A, 0x00000002, 0xF84061B3, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_BlueSwitch, 0x0000003C, 0x00000073, 0x0000000A, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignAreaFlag, 0x00000008, 0x00000043, 0x00000002, AssignScript, D_80241540_AA89C0, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF84061B3, 0x00000001, 0x00000043, 0x00000008, MakeEntity, 0x802EAA54, 0x00000096, 0x00000073, 0x00000000, 0x0000005A, 0x0000003C, 0x80000000, 0x00000012, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAA54, 0x00000096, 0x00000096, 0xFFFFFF97, 0x0000005A, 0x0000003C, 0x80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000004, func_80240310_AA7790, 0xFFFFFFA6, 0x00000000, 0x00000000, 0x00000044, 0x00000001, D_80240F44_AA83C4, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0x0000001A, 0xFFFFFEA2, 0x000000D7, 0xFFFFFFCE, 0x00000000, 0xF84061B2, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F44_AA83C4
.word 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFD050F81, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xF84061B3, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000002, 0xFE363C80, 0x00000073, 0x0000000E, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000096, 0x00000027, 0x00000002, 0xFE363C83, 0xFFFFFFD8, 0x00000024, 0x00000002, 0xFE363C84, 0x0000005A, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C83, 0x00000028, 0x00000024, 0x00000002, 0xFE363C84, 0x0000010E, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000003, InterpPlayerYaw, 0xFE363C84, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A8280, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002B, 0x00000043, 0x00000005, PlayerJump1, 0xFE363C83, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000008, 0x00000001, 0x00000005, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000050, 0x0000000F, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000045, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0x00000087, 0x00000073, 0xFFFFFFBA, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0x000000B4, 0x00000073, 0xFFFFFFBA, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0x00000087, 0x00000073, 0xFFFFFFC9, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0x000000B4, 0x00000073, 0xFFFFFFC9, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0x00000087, 0x00000073, 0xFFFFFFD8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000001, 0x000000B4, 0x00000073, 0xFFFFFFD8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, EnableModel, 0x00000045, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000029, 0x7FFFFE00, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000012, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000001EF, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFA6, 0x00000000, 0x0000000F, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000004, func_80240310_AA7790, 0xFE363C80, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000017, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_802403C0_AA7840, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000096, 0x00000096, 0xFFFFFF97, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0x00000096, 0x00000073, 0x00000000, 0x00000011, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241540_AA89C0
.word 0x00000024, 0x00000002, 0xFD050F81, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241560_AA89E0
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_802415B8_AA8A38
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415E0_AA8A60
.word 0x00000000, D_80241560_AA89E0, 0x00000000, 0xC47A0000, 0x00000000, 0x00206F01, D_802415B8_AA8A38, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830001, 0x00830002, 0x00830003, 0x00830003, 0x00830001, 0x00830001, 0x00830006, 0x00830006, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802415E0_AA8A60, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
