.include "macro.inc"

.section .data

dlabel D_80242C00_A70FE0
.word 0x3F800000, 0x0000001E, 0x00000032, 0x42B40000, 0x42200000, 0x00000002, 0x41300000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_80242C30_A71010
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000005, 0x00000043, 0x00000002, kpa_61_TackleAI_Main, D_80242C00_A70FE0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242CA0_A71080
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, D_80242C30_A71010, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

dlabel D_80242CCC_A710AC
.word 0x3FC00000, 0x0000003C, 0x0000001E, 0x42C80000, 0x41A00000, 0x00000003, 0x40A00000, 0x0000003C, 0x0000000A, 0x43160000, 0x41A00000, 0x00000001

dlabel D_80242CFC_A710DC
.word 0x00000043, 0x00000002, kpa_61_FlyingMagikoopaAI_Main, D_80242CCC_A710AC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242D1C_A710FC
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, OnPlayerFled, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242DB8_A71198
.word 0x00000000, 0x00210020, 0x00000000, 0x00000000, D_80242CFC_A710DC, EnemyNpcHit, 0x00000000, D_80242D1C_A710FC, 0x00000000, 0x00000000, 0x001A0000

dlabel D_80242DE4_A711C4
.word 0x00570000, 0x00570001, 0x00570001, 0x00570001, 0x00570002, 0x00570003, 0x00570004, 0xFFFFFFFF

dlabel D_80242E04_A711E4
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000028, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242E3C_A7121C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000037, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242E74_A71254
.word 0x00000043, 0x00000001, kpa_61_MagikoopaAI_SpellMain, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242E90_A71270
.word 0x00000043, 0x00000001, kpa_61_FlyingMagikoopaAI_OnHitInit, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, kpa_61_FlyingMagikoopaAI_OnHit, 0x00000044, 0x00000001, EnemyNpcHit, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242EE4_A712C4
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, OnPlayerFled, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00560000, 0x00000000, D_80242E04_A711E4, 0x00000000, D_80242E74_A71254, D_80242E90_A71270, 0x00000000, D_80242EE4_A712C4, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242FCC_A713AC
.word 0x00570000, 0x00000000, D_80242E3C_A7121C, 0x00000000, D_80242E74_A71254, D_80242E90_A71270, 0x00000000, D_80242EE4_A712C4, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242FF8_A713D8
.word 0x00000000, D_80242CA0_A71080, 0x43960000, 0xC3200000, 0x430C0000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980005, 0x3FFF2666, 0x4CCC0005, 0x3FFF3FFF, 0x3FFF0005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x0000012C, 0xFFFFFF60, 0x0000008C, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000012C, 0xFFFFFF60, 0x0000008C, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802431E8_A715C8
.word 0x00000001, D_80242CA0_A71080, 0x44548000, 0xC3200000, 0x43C30000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980005, 0x3FFF2666, 0x4CCC0005, 0x3FFF3FFF, 0x3FFF0005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000352, 0xFFFFFF60, 0x00000186, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000352, 0xFFFFFF60, 0x00000186, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802433D8_A717B8
.word 0x00000002, D_80242DB8_A71198, 0x43FA0000, 0x437A0000, 0xC2480000, 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x00050000, 0x00A30005, 0x00000082, 0x00050000, 0x00920005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0005, 0x33322666, 0x33320005, 0x33323FFF, 0x33320005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0x000001F4, 0x000000FA, 0xFFFFFFCE, 0x00000078, 0x00000019, 0xFFFF8001, 0x00000001, 0x000001F4, 0x000000FA, 0xFFFFFFCE, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00570000, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570004, 0x00570004, 0x00570002, 0x00570003, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00000003, 0x00000000, D_80242DE4_A711C4, 0x00000000, 0x00000003, D_80242FCC_A713AC, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802437B8_A71B98
.word 0x00000004, D_80242DB8_A71198, 0x43480000, 0x437A0000, 0xC2480000, 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x00050000, 0x00A30005, 0x00000082, 0x00050000, 0x00920005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0005, 0x33322666, 0x33320005, 0x33323FFF, 0x33320005, 0x33326665, 0x33320005, 0x33327FFF, 0x26660005, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0x000000C8, 0x000000FA, 0xFFFFFFCE, 0x00000078, 0x00000019, 0xFFFF8001, 0x00000001, 0x000000C8, 0x000000FA, 0xFFFFFFCE, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00570000, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570004, 0x00570004, 0x00570002, 0x00570003, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00570001, 0x00000003, 0x00000000, D_80242DE4_A711C4, 0x00000000, 0x00000005, D_80242FCC_A713AC, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00570000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242FF8_A713D8, 0x22230009, 0x00000001, D_802431E8_A715C8, 0x22210009, 0x00000002, D_802433D8_A717B8, 0x22350009, 0x00000002, D_802437B8_A71B98, 0x22330009, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
