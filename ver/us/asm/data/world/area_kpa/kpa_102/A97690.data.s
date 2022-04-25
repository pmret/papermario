.include "macro.inc"

.section .data

dlabel D_80243F50_A97690
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000005, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244020_A97760
.word 0x3FC00000, 0x0000001E, 0x0000001E, 0x42F00000, 0x41A00000, 0x00000005, 0x40400000, 0x0000005A, 0x00000003, 0x430C0000, 0x41A00000, 0x00000000

dlabel D_80244050_A97790
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000046, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000006, 0x00000043, 0x00000002, kpa_102_ProjectileAI_Main, D_80244020_A97760, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802440C0_A97800
.word 0x00000000, 0x00240018, 0x00000000, 0x00000000, D_80244050_A97790, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x001B0000

dlabel D_802440EC_A9782C
.word 0x40ACCCCD, 0x00000000, 0x00000000, 0x41500000, 0x3FB33333, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024411C_A9785C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000014, 0x00000043, 0x00000002, kpa_102_UnkFunc54, D_802440EC_A9782C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244178_A978B8
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244188_A978C8
.word 0x00000043, 0x00000001, kpa_102_GetEncounterEnemyIsOwner, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80244178_A978B8, 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000003, 0x00000043, 0x00000001, kpa_102_UnkFunc55, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000020, 0x00000000, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000004, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000007, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000001, func_800457F8, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_8024411C_A9785C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244350_A97A90
.word 0x00000000, 0x000C000C, 0x00000000, 0x00000000, D_8024411C_A9785C, D_80244188_A978C8, 0x00000000, D_80243F50_A97690, 0x00000000, 0x00000000, 0x00000008

dlabel D_8024437C_A97ABC
.word 0x005A000D, 0xFFFFFFFF

dlabel D_80244384_A97AC4
.word 0x3F800000, 0x0000001E, 0x00000032, 0x42B40000, 0x42200000, 0x00000002, 0x41300000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_802443B4_A97AF4
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000005, 0x00000043, 0x00000002, kpa_102_UnkNpcAIMainFunc5, D_80244384_A97AC4, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244424_A97B64
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, D_802443B4_A97AF4, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

dlabel D_80244450_A97B90
.word 0x3FC00000, 0x0000003C, 0x0000001E, 0x42C80000, 0x41A00000, 0x00000003, 0x40A00000, 0x0000003C, 0x0000000A, 0x43160000, 0x41A00000, 0x00000001

dlabel D_80244480_A97BC0
.word 0x00000043, 0x00000002, func_80243270_A969B0, D_80244450_A97B90, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802444A0_A97BE0
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, func_80045900, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024453C_A97C7C
.word 0x00000000, 0x00210020, 0x00000000, 0x00000000, D_80244480_A97BC0, EnemyNpcHit, 0x00000000, D_802444A0_A97BE0, 0x00000000, 0x00000000, 0x001A0000

dlabel D_80244568_A97CA8
.word 0x00570000, 0x00570001, 0x00570001, 0x00570001, 0x00570002, 0x00570003, 0x00570004, 0xFFFFFFFF

dlabel D_80244588_A97CC8
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000028, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802445C0_A97D00
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000037, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802445F8_A97D38
.word 0x00000043, 0x00000001, kpa_102_UnkFunc57, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244614_A97D54
.word 0x00000043, 0x00000001, dup_kpa_102_GetEncounterEnemyIsOwner, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_8024353C_A96C7C, 0x00000044, 0x00000001, EnemyNpcHit, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244668_A97DA8
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00560000, 0x00000000, D_80244588_A97CC8, 0x00000000, D_802445F8_A97D38, D_80244614_A97D54, 0x00000000, D_80244668_A97DA8, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244750_A97E90
.word 0x00570000, 0x00000000, D_802445C0_A97D00, 0x00000000, D_802445F8_A97D38, D_80244614_A97D54, 0x00000000, D_80244668_A97DA8, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024477C_A97EBC
.word 0x00000000, D_80244424_A97B64, 0xC3480000, 0x00000000, 0xC3610000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980005, 0x3FFF2666, 0x4CCC0005, 0x3FFF3FFF, 0x3FFF0005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0xFFFFFF38, 0x00000000, 0xFFFFFF1F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFF38, 0x00000000, 0xFFFFFF1F, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024496C_A980AC
.word 0x00000001, D_8024453C_A97C7C, 0x42FA0000, 0x42480000, 0xC3610000, 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x00050000, 0x00A30005, 0x00000082, 0x00050000, 0x00920005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0005, 0x33322666, 0x33320005, 0x33323FFF, 0x33320005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0x0000007D, 0x00000032, 0xFFFFFF1F, 0x00000078, 0x00000019, 0xFFFF8001, 0x00000001, 0x0000007D, 0x00000032, 0xFFFFFF1F, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00570000, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570004, 0x00570004, 0x00570002, 0x00570003, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00000003, 0x00000000, D_80244568_A97CA8, 0x00000000, 0x00000002, D_80244750_A97E90, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80244D4C_A9848C
.word 0x00000032, D_802440C0_A97800, 0x43E10000, 0x00000000, 0xC3610000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x00050000, 0x00A30005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0003, 0x33322666, 0x33320003, 0x33323FFF, 0x33320003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x000001C2, 0x00000000, 0xFFFFFF1F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000001C2, 0x00000000, 0xFFFFFF1F, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005A0002, 0x005A0004, 0x005A0007, 0x005A0007, 0x005A0002, 0x005A0002, 0x005A000E, 0x005A000E, 0x005A0018, 0x005A0019, 0x005A0002, 0x005A0002, 0x005A0002, 0x005A0002, 0x005A0002, 0x005A0002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000033, D_80244350_A97A90, 0x00000000, 0xC47A0000, 0x00000000, 0x00800C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x00000000, 0x00000000, D_8024437C_A97ABC, 0x00000000, 0x00000034, D_80244350_A97A90, 0x00000000, 0xC47A0000, 0x00000000, 0x00800C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x00000000, 0x00000000, D_8024437C_A97ABC, 0x00000000, 0x00000035, D_80244350_A97A90, 0x00000000, 0xC47A0000, 0x00000000, 0x00800C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x00000000, 0x00000000, D_8024437C_A97ABC, 0x00000000, 0x00000036, D_80244350_A97A90, 0x00000000, 0xC47A0000, 0x00000000, 0x00800C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x00000000, 0x00000000, D_8024437C_A97ABC, 0x00000000, 0x00000037, D_80244350_A97A90, 0x00000000, 0xC47A0000, 0x00000000, 0x00800C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x00000000, 0x00000000, D_8024437C_A97ABC, 0x00000000, 0x00000038, D_80244350_A97A90, 0x00000000, 0xC47A0000, 0x00000000, 0x00800C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x005A000D, 0x00000000, 0x00000000, D_8024437C_A97ABC, 0x00000000, 0x00000001, D_8024477C_A97EBC, 0x2224000B, 0x00000002, D_8024496C_A980AC, 0x2232000B, 0x00000007, D_80244D4C_A9848C, 0x2216000B, 0x00000000, 0x00000000, 0x00000000, 0x00000000
