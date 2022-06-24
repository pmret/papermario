.include "macro.inc"

.section .data

dlabel D_802549D0_8C4A40
.word 0x00000043, 0x00000003, GotoMap, 0x80257F00, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80254A00_8C4A70
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000003, 0x00A00004, 0x00A00001, 0x00000000, 0x000B0066, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, func_80243370_8B33E0, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000003, 0x00A00004, 0x00A00001, 0x00000000, 0x000B0067, 0x00000008, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000014, 0x7FFFFE00, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFF8E, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x0000207A, 0x00000000, 0x00000175, 0x00000058, 0x000000FF, 0x00000043, 0x00000005, GetNpcPos, 0x00000007, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000013, 0x00000000, 0x00000175, 0x00000058, 0x000000FF, 0x00000001, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000006, PlaySoundAt, 0x0000207B, 0x00000000, 0x00000146, 0x00000096, 0x00000105, 0x00000043, 0x0000000F, PlayEffect, 0x00000013, 0x00000001, 0x00000146, 0x00000096, 0x00000105, 0x00000001, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000013, 0x00000001, 0x00000146, 0x00000096, 0x00000105, 0x00000001, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x0000000F, PlayEffect, 0x00000013, 0x00000001, 0x00000146, 0x00000096, 0x00000105, 0x00000001, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x0000000F, PlayEffect, 0x00000013, 0x00000001, 0x00000146, 0x00000096, 0x00000105, 0x00000001, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x0000000F, PlayEffect, 0x00000013, 0x00000001, 0x00000146, 0x00000096, 0x00000105, 0x00000001, 0x0000003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_Hammer1Block, 0x00000146, 0x00000078, 0x00000105, 0x00000094, 0x80000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000043, 0x00000002, AssignScript, D_80254A00_8C4A70, 0x00000043, 0x00000001, func_80243514_8B3584, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C8A, 0x00000043, 0x00000005, kmr_02_GetEntityPosition, 0xFE363C89, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0x0000012C, 0x00000014, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, kmr_02_SetEntityPositionF, 0xFE363C89, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x0000207C, 0x00000000, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x0060000F, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000004, 0xFE363C82, 0x00000000, 0xFE363C84, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x0000207D, 0x00000000, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000043, 0x00000005, MakeLerp, 0x0000012C, 0x00000000, 0x00000014, 0x00000002, 0x00000003, 0x00000001, 0x00000014, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, kmr_02_SetEntityPositionF, 0xFE363C89, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000014, 0x00000013, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x000000B8, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x000000B4, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x000000DD, 0x00000000, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000F, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFF85, 0x00000018, 0x00000001, 0xFFFFFF8E, 0x00000043, 0x00000007, MakeEntity, Entity_Hammer1Block_WideHitbox, 0x00000146, 0x00000000, 0x00000105, 0x0000010E, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80254A00_8C4A70, 0x00000018, 0x00000001, 0xFFFFFF98, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000014, 0x7FFFFE00, 0x00000023, 0x00000000, 0x0000000A, 0x00000002, 0xF8406311, 0x00000000, 0x0000000A, 0x00000002, 0xF840630D, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xF8406311, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x0000000A, MakeEntity, D_802EAF80, 0x00000000, 0x00000000, 0x00000163, 0x00000000, 0x00000003, D_802549D0_8C4A40, 0x00000791, 0x80000000, 0x00000043, 0x00000007, MakeEntity, Entity_SavePoint, 0x000000FA, 0x0000003C, 0x0000004B, 0xFFFFFFF1, 0x80000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFF98, 0x00000043, 0x00000007, MakeItemEntity, 0x00000083, 0x000001FE, 0x00000000, 0xFFFFFEAC, 0x00000011, 0xF8405BAE, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
