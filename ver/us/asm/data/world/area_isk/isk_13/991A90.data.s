.include "macro.inc"

.section .data

dlabel D_802422B0_991A90
.word 0x00000024, 0x00000002, 0xF8405F02, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0x00000015, 0x000001CC, 0xFFFFFDC8, 0xFFFFFEAA, 0x00000000, 0xF8405EF1, 0x0000000A, 0x00000002, 0xF8405F02, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_Hammer2Block_WideX, 0x00000238, 0xFFFFFD76, 0xFFFFFED2, 0x00000019, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_802422B0_991A90, 0x00000013, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0x0000019F, 0xFFFFFE3B, 0xFFFFFEDD, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0x0000019F, 0xFFFFFDB9, 0xFFFFFEDD, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0x000001E9, 0xFFFFFE3B, 0xFFFFFF7D, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0x000001E9, 0xFFFFFDB9, 0xFFFFFF7D, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242460_991C40
.word 0x00000043, 0x00000001, isk_13_StoneChompFXA, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024247C_991C5C
.word 0x40000000, 0x0000001E, 0x0000001E, 0x42C80000, 0x00000000, 0x0000000A, 0x40A9999A, 0x00000046, 0x0000000A, 0x43FA0000, 0x00000000, 0x00000001

dlabel D_802424AC_991C8C
.word 0x00000058, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, isk_13_StoneChompFXB, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000059, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x00000043, 0x00000002, isk_13_StoneChompAI_Main, D_8024247C_991C5C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024251C_991CFC
.word 0x00000043, 0x00000002, SetBattleMusic, 0x00000003, 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, GetSelfAnimationFromTable, 0x00000007, 0xFE363C80, 0x00000046, 0x00000001, 0x800936DC, 0x00000016, 0x00000001, 0x00000003, 0x00000056, 0x00000000, 0x00000043, 0x00000002, func_800458CC, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C8A, 0x00000028, 0x00000043, 0x00000005, SetNpcRotation, 0xFFFFFFFF, 0x00000000, 0xFE363C8A, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242658_991E38
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, isk_13_StoneChompFXC, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802426C8_991EA8
.word 0x00000000, 0x00200020, D_80242460_991C40, 0x00000000, D_802424AC_991C8C, D_8024251C_991CFC, 0x00000000, D_80242658_991E38, 0x00000000, 0x00000000, 0x000E0000

dlabel D_802426F4_991ED4
.word 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF8405EF1, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000001, func_80241BA8_991388, 0x00000043, 0x00000005, func_80241EF8_9916D8, 0x000000FF, 0x00000080, 0x000000FF, 0x00000000, 0x00000056, 0x00000000, 0x00000026, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x0000002C, 0x00000002, 0xFE363C80, 0xF24AADB0, 0x00000043, 0x00000005, func_80241EF8_9916D8, 0x000000FF, 0x00000080, 0x000000FF, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, func_80241EF8_9916D8, 0x000000FF, 0x00000080, 0x000000FF, 0x00000080, 0x00000026, 0x00000002, 0xFE363C80, 0x00000080, 0x00000005, 0x00000001, 0x00000014, 0x0000002C, 0x00000002, 0xFE363C80, 0xF24A93E0, 0x00000043, 0x00000005, func_80241EF8_9916D8, 0x000000FF, 0xFE363C80, 0x000000FF, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, func_80241EF8_9916D8, 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000168, 0x0000000A, 0x0000000A, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000004, func_80241E34_991614, 0xFE363C80, 0x00000000, 0xF24BE280, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000043, 0x00000004, func_80241D38_991518, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C86, 0x00000014, 0x00000002, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000043, 0x00000004, func_80241D38_991518, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80242044_991824, 0x00000056, 0x00000000, 0x00000043, 0x00000003, InterpPlayerYaw, 0x000000B4, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7E80, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000005, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080013, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000005, 0x00000001, 0x00000014, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_80241D38_991518, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, StartBossBattle, 0x00000003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242B20_992300
.word 0x00000024, 0x00000002, 0xF8405F09, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000007, func_802CFD30, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000001, func_80241D08_9914E8, 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, isk_13_StoneChompFXC, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242BFC_9923DC
.word 0x0000000A, 0x00000002, 0xF8405F09, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802426F4_991ED4, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80242B20_992300, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000001, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242C90_992470
.word 0x00000001, D_802426C8_991EA8, 0x43DC0000, 0xC3EB0000, 0xC3960000, 0x00140B00, D_80242BFC_9923DC, 0x00000001, 0xFFFFFD76, 0x00000140, 0x800500A4, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650003, 0x3FFF2666, 0x59980003, 0x3FFF3FFF, 0x4CCC0003, 0x33326665, 0x3FFF0003, 0x33327FFF, 0x33320003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000001D4, 0x00000000, 0xFFFFFE86, 0x000000C8, 0x00000000, 0xFFFF8001, 0x00000000, 0x000001D4, 0x00000000, 0xFFFFFE86, 0x00000190, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00350001, 0x00350005, 0x00350004, 0x00350004, 0x00350001, 0x00350001, 0x00350006, 0x00350006, 0x00350000, 0x00350000, 0x00350000, 0x00350000, 0x00350000, 0x00350000, 0x00350000, 0x00350000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242C90_992470, 0x0B07000B, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
