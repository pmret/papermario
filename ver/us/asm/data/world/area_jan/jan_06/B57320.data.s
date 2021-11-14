.include "macro.inc"

.section .data

dlabel D_80244AF0_B57320
.word 0x3FC00000, 0x0000001E, 0x0000000A, 0x43160000, 0x00000000, 0x00000003, 0x40A00000, 0x00000046, 0x00000005, 0x43480000, 0x00000000, 0x00000001

dlabel D_80244B20_B57350
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, func_80241330_B53B60, D_80244AF0_B57320, 0x00000002, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244B5C_B5738C
.word 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80244B20_B57350, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00100000

dlabel D_80244B88_B573B8
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244BD4_B57404
.word 0x00000008, 0x00000001, 0x0000002D, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80244C04_B57434, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244C04_B57434
.word 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00002099, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00430000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, func_80241554_B53D84, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00430001, 0x00000056, 0x00000000, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, 0x00000000, 0x00000044, 0x00000001, D_80244BD4_B57404, 0x00000008, 0x00000001, 0x0000002D, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00430000, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244D10_B57540
.word 0x00000000, 0x0014001C, D_80244B88_B573B8, D_80244C04_B57434, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80244D3C_B5756C
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00440001, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00440008, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x0000209A, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002B, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00440002, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000043, 0x00000001, StartBattle, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244EB8_B576E8
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244EDC_B5770C
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80244D3C_B5756C, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244F7C_B577AC
.word 0x00000000, 0x0014001C, 0x00000000, D_80244EB8_B576E8, D_80244D3C_B5756C, 0x00000000, 0x00000000, D_80244EDC_B5770C, 0x00000000, 0x00000000, 0x00100000, 0x00440000, 0x00440001, 0x00440002, 0x00440008, 0xFFFFFFFF, 0x00420000, 0x00420003, 0x00420005, 0x00420006, 0x00420007, 0x0042000F, 0x00420010, 0x0042001A, 0x0042001B, 0xFFFFFFFF

dlabel D_80244FE4_B57814
.word 0x00420000, 0xFFFFFFFF

dlabel D_80244FEC_B5781C
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802450A8_B578D8
.word 0x3FD9999A, 0x00000064, 0x00000001, 0x42C80000, 0x41F00000, 0x00000001, 0x40600000, 0x00000014, 0x00000001, 0x42F00000, 0x00000000, 0x00000001

dlabel D_802450D8_B57908
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000009, 0x00000043, 0x00000002, jan_06_UnkNpcAIFunc28, D_802450A8_B578D8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245148_B57978
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_802450D8_B57908, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00100000

dlabel D_80245174_B579A4
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000016, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000028, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x00000000, 0x00000043, 0x00000001, jan_06_UnkFunc7, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024521C_B57A4C
.word 0x00000000, 0x00080014, 0x00000000, 0x00000000, D_80245174_B579A4, 0x00000000, 0x00000000, D_80244FEC_B5781C, 0x00000000, 0x00000000, 0x00100008

dlabel D_80245248_B57A78
.word 0x002B0201, 0x002B0202, 0x002B0203, 0x002B0208, 0xFFFFFFFF

dlabel D_8024525C_B57A8C
.word 0x00000000, D_80244B5C_B5738C, 0x439B0000, 0x41C00000, 0x420C0000, 0x00400400, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x800A009A, 0x00050000, 0x008B0005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000136, 0x00000018, 0x00000023, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000136, 0x00000018, 0x00000023, 0x00000096, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002B0302, 0x002B0302, 0x002B0303, 0x002B0303, 0x002B0301, 0x002B0301, 0x002B0308, 0x002B0308, 0x002B0303, 0x002B0303, 0x002B0303, 0x002B0303, 0x002B0303, 0x002B0303, 0x002B0303, 0x002B0303, 0x00000003, 0x00000000, D_80245248_B57A78, 0x00000000

dlabel D_8024544C_B57C7C
.word 0x00420003, 0x00420004, 0x00420005, 0x00420006, 0x0042000F, 0x00420010, 0x00420007, 0x00420008, 0x00420009, 0x0042000D, 0x0042001A, 0x0042001B, 0xFFFFFFFF

dlabel D_80245480_B57CB0
.word 0x00000001, D_80245148_B57978, 0xC3950000, 0x420C0000, 0x42140000, 0x00400400, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008F, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0xFFFFFED6, 0x00000000, 0x00000025, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFED6, 0x00000000, 0x00000025, 0x00000096, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00420003, 0x00420005, 0x00420006, 0x00420006, 0x00420003, 0x00420003, 0x00420007, 0x00420007, 0x0042001A, 0x0042001B, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00000003, 0x00000000, D_8024544C_B57C7C, 0x00000000, 0x00000002, D_8024521C_B57A4C, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00420003, 0x00420005, 0x00420006, 0x00420006, 0x00420003, 0x00420003, 0x00420007, 0x00420007, 0x0042001A, 0x0042001B, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00000000, 0x00000000, D_80244FE4_B57814, 0x00000000

dlabel D_80245860_B58090
.word 0x00000003, D_80244D10_B57540, 0x43CD0000, 0x00000000, 0xC1F00000, 0x00408D01, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00000000, 0x00000000, 0x00000000, 0x001A00D3

dlabel D_80245A50_B58280
.word 0x00000004, D_80244F7C_B577AC, 0x42DC0000, 0x00000000, 0x425C0000, 0x00408D01, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x800A0089, 0x00050000, 0x009B0005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x0044000E, 0x0044000E, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00000000, 0x00000000, 0x00000000, 0x001A00D3

dlabel D_80245C40_B58470
.word 0x00000005, D_80244F7C_B577AC, 0xC3D70000, 0x00000000, 0xC2A00000, 0x00408D01, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x800A0089, 0x00050000, 0x009B0005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x0044000E, 0x0044000E, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00440001, 0x00000000, 0x00000000, 0x00000000, 0x001A00D3, 0x00000001, D_8024525C_B57A8C, 0x140D0002, 0x00000002, D_80245480_B57CB0, 0x14020002, 0x00000001, D_80245860_B58090, 0x00000000, 0x00000001, D_80245A50_B58280, 0x14080002, 0x00000001, D_80245C40_B58470, 0x14080002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
