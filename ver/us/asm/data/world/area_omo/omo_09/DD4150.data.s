.include "macro.inc"

.section .data

glabel D_80247480_DD4150
.word 0x40000000, 0x0000003C, 0x0000000F, 0x42C80000, 0x41F00000, 0x00000004, 0x40800000, 0x00000006, 0x00000001, 0x430C0000, 0x41F00000, 0x00000001

glabel D_802474B0_DD4180
.word 0x00000043, 0x00000002, func_80240C18_DCD8E8, D_80247480_DD4150, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802474D0_DD41A0
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_802474B0_DD4180, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001

glabel D_802474FC_DD41CC
.word 0x40000000, 0x0000003C, 0x0000000F, 0x42C80000, 0x41F00000, 0x00000004, 0x40800000, 0x00000006, 0x00000001, 0x430C0000, 0x41F00000, 0x00000001

glabel D_8024752C_DD41FC
.word 0x00000043, 0x00000002, DoBasicAI, D_802474FC_DD41CC, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_8024752C_DD41FC, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0000

glabel D_80247578_DD4248
.word 0x40000000, 0x0000003C, 0x00000000, 0x42C80000, 0x41F00000, 0x00000004, 0x40800000, 0x00000006, 0x00000001, 0x43200000, 0x42480000, 0x00000001

glabel D_802475A8_DD4278
.word 0x00000043, 0x00000002, func_80242014_DCECE4, D_80247578_DD4248, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802475C8_DD4298
.word 0x00000043, 0x00000002, func_80241AE0_DCE7B0, D_80247578_DD4248, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802475E8_DD42B8
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_802475A8_DD4278, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001, 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_802475C8_DD4298, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001

glabel D_80247640_DD4310
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000005, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247710_DD43E0
.word 0x3FC00000, 0x0000003C, 0x0000000F, 0x42B40000, 0x42480000, 0x00000003, 0x40733333, 0x00000008, 0x00000001, 0x430C0000, 0x42700000, 0x00000001

glabel D_80247740_DD4410
.word 0x00000043, 0x00000001, func_8024356C_DD023C, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000002, func_8024324C_DCFF1C, D_80247710_DD43E0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802477BC_DD448C
.word 0x00000000, 0x00180016, 0x00000000, 0x00000000, D_80247740_DD4410, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000F0000

glabel D_802477E8_DD44B8
.word 0x41000000, 0x00000000, 0x00000000, 0x40800000, 0x3F000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80247818_DD44E8
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000D, 0x00000043, 0x00000002, func_802428B4_DCF584, D_802477E8_DD44B8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247888_DD4558
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247898_DD4568
.word 0x00000043, 0x00000001, omo_09_GetEncounterEnemyIsOwner, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80247888_DD4558, 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000003, 0x00000043, 0x00000001, func_80242DF0_DCFAC0, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000020, 0x00000000, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000004, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000007, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000001, func_800457F8, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80247818_DD44E8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247A60_DD4730
.word 0x00000000, 0x00070007, 0x00000000, 0x00000000, D_80247818_DD44E8, D_80247898_DD4568, 0x00000000, D_80247640_DD4310, 0x00000000, 0x00000000, 0x00000008

glabel D_80247A8C_DD475C
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00190000

glabel D_80247AB8_DD4788
.word 0x3FE66666, 0x00000032, 0x0000000A, 0x437A0000, 0x00000000, 0x00000002, 0x40600000, 0x0000002D, 0x00000006, 0x43960000, 0x00000000, 0x00000001

glabel D_80247AE8_DD47B8
.word 0x00000043, 0x00000001, func_802435B8_DD0288, 0x00000043, 0x00000002, DoBasicAI, D_80247AB8_DD4788, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247B14_DD47E4
.word 0x00000000, 0x0048000F, 0x00000000, 0x00000000, D_80247AE8_DD47B8, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00090000

glabel D_80247B40_DD4810
.word 0x00000000, 0x00220018, 0x00000000, 0x00000000, 0x00000000, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x001A0000

glabel D_80247B6C_DD483C
.word 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C8D, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C8E, 0xFE363C83, 0x00000043, 0x00000004, SetNpcVar, 0xFE363C8A, 0x0000000A, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C8A, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C83, 0x0000001A, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C8B, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C8A, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C83, 0x0000001A, 0x00000043, 0x00000005, SetItemPos, 0xFE363C89, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetNpcVar, 0xFE363C8A, 0x0000000A, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C89, 0x00000014, 0x00000001, 0xFE363C8D, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C8B, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x0000000C, 0xFE363C8E, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C8B, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x0000000D, 0xFE363C8E, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C8B, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x0000000E, 0xFE363C8E, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247D90_DD4A60
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF8405FFC, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x0000000A, 0x00000001, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000002, 0x00000016, 0x00000001, 0x00000003, 0x00000024, 0x00000002, 0xF8405FFC, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x0000000A, 0x00000001, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247E48_DD4B18
.word 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C80, 0x0000073A, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xFE363C81, 0x00000096, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000001, func_802435CC_DD029C, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000009, SetCamProperties, 0x00000000, 0xF24A8E80, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000012C, 0xF24AAE80, 0xF24A5480, 0x0000000A, 0x00000002, 0xF5DE025A, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000005, 0x00310004, 0x00310004, 0x00000000, 0x000F003E, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000006, 0x00580008, 0x00580001, 0x00000000, 0x000F003F, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000001, omo_09_UnsetCamera0Flag1000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8A80, 0x00000057, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, StartBossBattle, 0x00000003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247FE4_DD4CB4
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF8405FD0, 0x00000001, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80248058_DD4D28
.word 0x0000000A, 0x00000002, 0xF5DE025A, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80247E48_DD4B18, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80247FE4_DD4CB4, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802480CC_DD4D9C
.word 0x0000000A, 0x00000002, 0xF5DE025A, 0x00000001, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80247E48_DD4B18, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80247FE4_DD4CB4, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80248140_DD4E10
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, 0x80249F08, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80248164_DD4E34
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_802474B0_DD4180, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x00000019, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802482BC_DD4F8C
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000002, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80248164_DD4E34, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80248348_DD5018
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80248164_DD4E34, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_802482BC_DD4F8C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80248380_DD5050
.word 0x00000005, D_80247B14_DD47E4, 0x44ED8000, 0x43160000, 0xC1F00000, 0x00440F00, D_80248058_DD4D28, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00310004, 0x00310008, 0x00310008, 0x00310008, 0x00310004, 0x00310004, 0x0031000C, 0x0031000C, 0x00310008, 0x00310008, 0x00310008, 0x00310008, 0x00310008, 0x00310008, 0x00310008, 0x00310008, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80248570_DD5240
.word 0x00000006, D_80247A8C_DD475C, 0x44ED8000, 0x43160000, 0xC1F00000, 0x00440F00, D_802480CC_DD4D9C, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80248760_DD5430
.word 0x00000000, D_802474D0_DD41A0, 0x00000000, 0xC47A0000, 0x00000000, 0x00200004, D_80248348_DD5018, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000001CC, 0x00000000, 0x00000032, 0x00000050, 0x00000000, 0xFFFF8001, 0x00000000, 0x000001CC, 0x00000000, 0x00000032, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80248950_DD5620
.word 0x00000001, D_802474D0_DD41A0, 0x00000000, 0xC47A0000, 0x00000000, 0x00200004, D_80248348_DD5018, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000001F1, 0x00000000, 0x00000032, 0x00000050, 0x00000000, 0xFFFF8001, 0x00000000, 0x000001F1, 0x00000000, 0x00000032, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80248B40_DD5810
.word 0x00000002, D_802474D0_DD41A0, 0x00000000, 0xC47A0000, 0x00000000, 0x00200004, D_80248348_DD5018, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000217, 0x00000000, 0x00000032, 0x00000050, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000217, 0x00000000, 0x00000032, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80248D30_DD5A00
.word 0x00000003, D_802474D0_DD41A0, 0x00000000, 0xC47A0000, 0x00000000, 0x00200004, D_80248348_DD5018, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000023D, 0x00000000, 0x00000032, 0x00000050, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000023D, 0x00000000, 0x00000032, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80248F20_DD5BF0
.word 0x00000004, D_802474D0_DD41A0, 0x00000000, 0xC47A0000, 0x00000000, 0x00200004, D_80248348_DD5018, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000262, 0x00000000, 0x00000032, 0x00000050, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000262, 0x00000000, 0x00000032, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80249110_DD5DE0
.word 0x0060000E, 0x0060000F, 0x00600010, 0x00600013, 0x00600015, 0x00600016, 0xFFFFFFFF

glabel D_8024912C_DD5DFC
.word 0x00000007, D_80247B40_DD4810, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F04, D_80248140_DD4E10, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00600001, 0x00600002, 0x00600003, 0x00600003, 0x00600001, 0x00600001, 0x00600000, 0x00600000, 0x00600003, 0x00600003, 0x00600003, 0x00600003, 0x00600003, 0x00600003, 0x00600003, 0x00600003, 0x00000000, 0x00000000, D_80249110_DD5DE0, 0x00000000

glabel D_8024931C_DD5FEC
.word 0x0000000A, 0x00000002, 0xF8405FFC, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80247D90_DD4A60, 0x00000024, 0x00000002, 0xFE363C80, 0x00000008, 0x00000024, 0x00000002, 0xFE363C81, 0x00000025, 0x00000024, 0x00000002, 0xFE363C82, 0x00000001, 0x00000025, 0x00000002, 0xFE363C83, 0xF8405FFD, 0x00000044, 0x00000001, D_80247B6C_DD483C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802493BC_DD608C
.word 0x00000008, D_802475E8_DD42B8, 0x431B0000, 0x41200000, 0xC2C00000, 0x00000C00, D_8024931C_DD5FEC, 0x00000000, 0x00000000, 0x0000010E, 0x8005009A, 0x00020000, 0x008C0002, 0x00000084, 0x00020000, 0x008D0002, 0x0000008F, 0x00020000, 0x00900002, 0x00000098, 0x00020000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x00000002, 0x0000009B, 0x0000000A, 0xFFFFFFA0, 0x0000005A, 0x0000000A, 0xFFFFFFA0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000087, 0x0000000A, 0x00000000, 0x00000069, 0x0000008C, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0401, 0x003B0402, 0x003B0403, 0x003B0403, 0x003B0401, 0x003B0401, 0x003B040C, 0x003B040C, 0x003B0415, 0x003B0412, 0x003B0411, 0x003B0410, 0x003B0405, 0x003B0401, 0x003B0401, 0x003B0401, 0x00000001, 0x00000001, 0x00000000, 0x00000000

glabel D_802495AC_DD627C
.word 0x00000014, D_802477BC_DD448C, 0x44548000, 0x00000000, 0x00000000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x00020000, 0x00820002, 0x00000084, 0x00020000, 0x00860002, 0x00000085, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000352, 0x00000000, 0x00000000, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000352, 0x00000000, 0x00000000, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003F0002, 0x003F0004, 0x003F0005, 0x003F0004, 0x003F0002, 0x003F0002, 0x003F000B, 0x003F000B, 0x003F0015, 0x003F0016, 0x003F0002, 0x003F0002, 0x003F0002, 0x003F0002, 0x003F0002, 0x003F0002, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000015, D_80247A60_DD4730, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000016, D_80247A60_DD4730, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000017, D_80247A60_DD4730, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x003F0010, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80248380_DD5050, 0x12080005, 0x00000001, D_80248760_DD5430, 0x120A0005, 0x00000001, D_80248950_DD5620, 0x120A0005, 0x00000001, D_80248B40_DD5810, 0x120A0005, 0x00000001, D_80248D30_DD5A00, 0x120A0005, 0x00000001, D_80248F20_DD5BF0, 0x120A0005, 0x00000001, D_802493BC_DD608C, 0x10090001, 0x00000004, D_802495AC_DD627C, 0x10190001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80248570_DD5240, 0x12090005, 0x00000001, D_80248760_DD5430, 0x120A0005, 0x00000001, D_80248950_DD5620, 0x120A0005, 0x00000001, D_80248B40_DD5810, 0x120A0005, 0x00000001, D_80248D30_DD5A00, 0x120A0005, 0x00000001, D_80248F20_DD5BF0, 0x120A0005, 0x00000001, D_802493BC_DD608C, 0x10090001, 0x00000004, D_802495AC_DD627C, 0x10190001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80248760_DD5430, 0x120A0005, 0x00000001, D_80248950_DD5620, 0x120A0005, 0x00000001, D_80248B40_DD5810, 0x120A0005, 0x00000001, D_80248D30_DD5A00, 0x120A0005, 0x00000001, D_80248F20_DD5BF0, 0x120A0005, 0x00000001, D_802493BC_DD608C, 0x10090001, 0x00000004, D_802495AC_DD627C, 0x10190001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_8024912C_DD5DFC, 0x00000000, 0x00000001, D_80248380_DD5050, 0x12080005, 0x00000001, D_80248570_DD5240, 0x12090005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
