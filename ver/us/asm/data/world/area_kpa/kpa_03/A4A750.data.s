.include "macro.inc"

.section .data

dlabel D_80242190_A4A750
.word 0x3F800000, 0x0000001E, 0x00000032, 0x42B40000, 0x42200000, 0x00000002, 0x41300000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_802421C0_A4A780
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000005, 0x00000043, 0x00000002, kpa_03_TackleAI_Main, D_80242190_A4A750, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242230_A4A7F0
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, D_802421C0_A4A780, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

dlabel D_8024225C_A4A81C
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40900000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_8024228C_A4A84C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kpa_03_TackleAI_Main, D_8024225C_A4A81C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802422FC_A4A8BC
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40E00000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_8024232C_A4A8EC
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000003, 0x00000043, 0x00000002, kpa_03_TackleAI_Main, D_802422FC_A4A8BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024239C_A4A95C
.word 0x3F800000, 0x00000014, 0x00000005, 0x42F00000, 0x00000000, 0x00000003, 0x40C00000, 0x00000000, 0x00000000, 0x43160000, 0x00000000, 0x00000001

dlabel D_802423CC_A4A98C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000006, 0x00000043, 0x00000002, kpa_03_TackleAI_Main, D_8024239C_A4A95C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024243C_A4A9FC
.word 0x00000043, 0x00000001, kpa_03_func_80240814_97BE44, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0033000F, 0x00000043, 0x00000001, kpa_03_AwaitPlayerNearNpc, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00330000, 0x00000043, 0x00000001, kpa_03_func_802408B4_97BEE4, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kpa_03_TackleAI_Main, D_8024225C_A4A81C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_8024228C_A4A84C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_8024243C_A4A9FC, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_8024232C_A4A8EC, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000

dlabel D_802425B4_A4AB74
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, D_802423CC_A4A98C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

dlabel kpa_03_MagikoopaAI_TeleportAnim
.float 0.8

dlabel D_802425E4_A4ABA4
.float 1.0

dlabel D_802425E8_A4ABA8
.byte 0xC8, 0x00, 0x00, 0x00, 0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x80, 0x00, 0x00, 0xB4, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x3E, 0xCC, 0xCC, 0xCD, 0x3F, 0x80, 0x00, 0x00, 0x8C, 0x00, 0x00, 0x00, 0x3E, 0x99, 0x99, 0x9A, 0x3F, 0x8C, 0xCC, 0xCD, 0x78, 0x00, 0x00, 0x00, 0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0xA6, 0x66, 0x66, 0x6E, 0x00, 0x00, 0x00, 0x3E, 0x19, 0x99, 0x9A, 0x3F, 0xCC, 0xCC, 0xCD, 0x64, 0x00, 0x00, 0x00, 0x3D, 0xF5, 0xC2, 0x8F, 0x40, 0x00, 0x00, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x3D, 0xE1, 0x47, 0xAE, 0x40, 0x40, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x3D, 0xCC, 0xCC, 0xCD, 0x40, 0x80, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

dlabel D_80242664_A4AC24
.word 0x3F800000, 0x00000078, 0x0000001E, 0x42C80000, 0x00000000, 0x0000000A, 0x40400000, 0x0000005A, 0x0000000F, 0x43480000, 0x00000000, 0x00000001

dlabel D_80242694_A4AC54
.word 0x00000043, 0x00000002, kpa_03_MagikoopaAI_Main, D_80242664_A4AC24, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802426B4_A4AC74
.word 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, GetSelfAnimationFromTable, 0x00000007, 0xFE363C80, 0x00000046, 0x00000001, 0x800936DC, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242740_A4AD00
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, kpa_03_MagikoopaAI_OnPlayerWon, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000001, kpa_03_MagikoopaAI_OnPlayerFled, 0x00000043, 0x00000002, func_80045900, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802427C0_A4AD80
.word 0x00000000, 0x0020001C, 0x00000000, 0x00000000, D_80242694_A4AC54, D_802426B4_A4AC74, 0x00000000, D_80242740_A4AD00, 0x00000000, 0x00000000, 0x001A0000

dlabel D_802427EC_A4ADAC
.word 0x00560000, 0x00560001, 0x00560001, 0x00560001, 0x00560002, 0x00560003, 0x00560004, 0xFFFFFFFF

dlabel D_8024280C_A4ADCC
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000028, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242844_A4AE04
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000037, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024287C_A4AE3C
.word 0x00000043, 0x00000001, kpa_03_MagikoopaAI_SpellMain, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242898_A4AE58
.word 0x00000043, 0x00000001, kpa_03_MagikoopaAI_OnHitInit, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, kpa_03_MagikoopaAI_OnHit, 0x00000044, 0x00000001, EnemyNpcHit, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802428EC_A4AEAC
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802429A8_A4AF68
.word 0x00560000, 0x00000000, D_8024280C_A4ADCC, 0x00000000, D_8024287C_A4AE3C, D_80242898_A4AE58, 0x00000000, D_802428EC_A4AEAC, 0x00000000, 0x00000000, 0x00000000, 0x00570000, 0x00000000, D_80242844_A4AE04, 0x00000000, D_8024287C_A4AE3C, D_80242898_A4AE58, 0x00000000, D_802428EC_A4AEAC, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242A00_A4AFC0
.word 0x00580001, 0x00580004, 0x00580006, 0x00580010, 0x0058000B, 0xFFFFFFFF

dlabel D_80242A18_A4AFD8
.word 0x00000000, D_80242230_A4A7F0, 0x4482A000, 0xC37F0000, 0xC3420000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980005, 0x3FFF2666, 0x4CCC0005, 0x3FFF3FFF, 0x3FFF0005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000415, 0xFFFFFF01, 0xFFFFFF3E, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000415, 0xFFFFFF01, 0xFFFFFF3E, 0x0000012C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000003, 0x00000000, D_80242A00_A4AFC0, 0x00000000

dlabel D_80242C08_A4B1C8
.word 0x00000001, D_80242230_A4A7F0, 0x446D8000, 0xC3848000, 0x00000000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980005, 0x3FFF2666, 0x4CCC0005, 0x3FFF3FFF, 0x3FFF0005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x000003B6, 0xFFFFFEF7, 0x00000000, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000003B6, 0xFFFFFEF7, 0x00000000, 0x0000012C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000003, 0x00000000, D_80242A00_A4AFC0, 0x00000000

dlabel D_80242DF8_A4B3B8
.word 0x00000002, D_802425B4_A4AB74, 0xC46B0000, 0x430C0000, 0xC3110000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980005, 0x3FFF2666, 0x4CCC0005, 0x3FFF3FFF, 0x3FFF0005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0xFFFFFC54, 0x0000008C, 0xFFFFFF6F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFC54, 0x0000008C, 0xFFFFFF6F, 0x0000012C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00550004, 0x0055000C, 0x0055000E, 0x0055000E, 0x00550004, 0x00550004, 0x00550018, 0x00550018, 0x00550010, 0x00550016, 0x00550012, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242FE8_A4B5A8
.word 0x00000003, D_802425B4_A4AB74, 0x432F0000, 0xC3020000, 0x00000000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00040000, 0x000000AF, 0xFFFFFF7E, 0x00000000, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000AF, 0xFFFFFF7E, 0x00000000, 0x0000012C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00550004, 0x0055000C, 0x0055000E, 0x0055000E, 0x00550004, 0x00550004, 0x00550018, 0x00550018, 0x00550010, 0x00550016, 0x00550012, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_802431D8_A4B798
.word 0x00000004, D_802427C0_A4AD80, 0xC47A0000, 0xC3200000, 0xC3160000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x00050000, 0x00A30005, 0x00000082, 0x00050000, 0x00920005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0005, 0x33322666, 0x33320005, 0x33323FFF, 0x33320005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0xFFFFFC18, 0xFFFFFF60, 0xFFFFFF6A, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFC18, 0xFFFFFF60, 0xFFFFFF6A, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00560001, 0x00560001, 0x00560001, 0x00560001, 0x00560001, 0x00560001, 0x00560004, 0x00560004, 0x00560002, 0x00560003, 0x00560001, 0x00560001, 0x00560001, 0x00560001, 0x00560001, 0x00560001, 0x00000003, 0x00000000, D_802427EC_A4ADAC, 0x00000000, 0x00000005, D_802429A8_A4AF68, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00560000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242A18_A4AFD8, 0x22200004, 0x00000001, D_80242C08_A4B1C8, 0x221F0004, 0x00000001, D_80242DF8_A4B3B8, 0x22010004, 0x00000001, D_80242FE8_A4B5A8, 0x22040004, 0x00000002, D_802431D8_A4B798, 0x222F0004, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243600_A4BBC0
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000002, 0xFE363C81, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C83, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetCamTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243690_A4BC50
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000006, 0x0000000A, 0x00000002, 0xFD050F80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFEED, 0x00000045, 0x00000002, D_80243600_A4BBC0, 0xFE363C8A, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7D4D, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFE05, 0xFFFFFEE0, 0xFFFFFF61, 0x00000014, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000045, 0x00000002, D_80243600_A4BBC0, 0xFE363C8A, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7EE7, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFE0C, 0x00000000, 0xFFFFFF6A, 0x00000028, 0x00000013, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80241E50_A4A410, 0x00000057, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_ScriptSpring, 0xFFFFFE70, 0xFFFFFED4, 0xFFFFFF6A, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80243690_A4BC50, 0x00000043, 0x00000008, MakeEntity, Entity_YellowBlock, 0x0000026C, 0xFFFFFFBF, 0xFFFFFF38, 0x00000000, 0x00000083, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF840618A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
