.include "macro.inc"

.section .data

dlabel D_802414B0_917220
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024154C_9172BC
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F0012, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415CC_91733C
.word 0x3FE66666, 0x0000001E, 0x0000001E, 0x42B40000, 0x428C0000, 0x00000002, 0x40400000, 0x0000005A, 0x00000019, 0x42F00000, 0x428C0000, 0x00000001

dlabel D_802415FC_91736C
.word 0x00000043, 0x00000002, func_800445D4, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000064, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, IsPlayerWithin, 0xFE363C80, 0xFE363C82, 0x00000050, 0xFE363C83, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F000E, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000027, 0x00000002, 0xFE363C85, 0x0000001E, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7E80, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000323, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000014, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C80, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000000, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000043, 0x00000002, BasicAI_Main, D_802415CC_91733C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00180016, D_802414B0_917220, 0x00000000, D_802415FC_91736C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00080001, 0x00000000, 0x00180016, D_8024154C_9172BC, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00080001

dlabel D_802418A0_917610
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C82, 0x00000032, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241924_917694
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00040000, 0x00000001, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C82, 0x00000032, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F0013, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419BC_91772C
.word 0x3FE66666, 0x0000001E, 0x0000001E, 0x42B40000, 0x428C0000, 0x00000002, 0x40400000, 0x0000005A, 0x00000019, 0x42F00000, 0x428C0000, 0x00000001

dlabel D_802419EC_91775C
.word 0x00000043, 0x00000002, func_800445D4, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000064, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C82, 0x00000082, 0x00000043, 0x00000005, IsPlayerWithin, 0xFE363C80, 0xFE363C82, 0x00000050, 0xFE363C83, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C83, 0x00000032, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F000E, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000028, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C83, 0x00000050, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7D4D, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000323, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000014, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000000, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000002, BasicAI_Main, D_802419BC_91772C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C94_917A04
.word 0x00000000, 0x00180016, D_802418A0_917610, 0x00000000, D_802419EC_91775C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00080001

dlabel D_80241CC0_917A30
.word 0x00000000, 0x00180016, D_80241924_917694, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00080001

dlabel D_80241CEC_917A5C
.word 0x3F800000, 0x0000001E, 0x0000001E, 0x42F00000, 0x00000000, 0x00000003, 0x40E00000, 0x0000003C, 0x00000005, 0x42C80000, 0x42700000, 0x00000001

dlabel D_80241D1C_917A8C
.word 0x00000043, 0x00000003, func_80240C90_916A00, D_80241CEC_917A5C, 0x00000010, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D40_917AB0
.word 0x00000000, 0x001A0018, 0x00000000, 0x00000000, D_80241D1C_917A8C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000

dlabel D_80241D6C_917ADC
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D7C_917AEC
.word 0x00000000, 0x002A001A, D_80241D6C_917ADC, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel iwa_02_varStash
.word 0x00000000

dlabel D_80241DAC_917B1C
.word 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241E0C_917B7C
.word 0x00000000, D_80241D40_917AB0, 0x44038000, 0x436E0000, 0x428A0000, 0x00002400, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0x0000020E, 0x000000EE, 0x00000045, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000020E, 0x000000EE, 0x00000045, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00300002, 0x00300006, 0x00300007, 0x00300007, 0x00300002, 0x00300002, 0x00300008, 0x00300008, 0x00300014, 0x00300017, 0x00300013, 0x00300015, 0x00300010, 0x00300011, 0x00300016, 0x00300000, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241FFC_917D6C
.word 0x00000001, D_80241D40_917AB0, 0x43E10000, 0x42480000, 0x43570000, 0x00002400, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0x000001C2, 0x00000032, 0x000000D7, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000001C2, 0x00000032, 0x000000D7, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00300002, 0x00300006, 0x00300007, 0x00300007, 0x00300002, 0x00300002, 0x00300008, 0x00300008, 0x00300014, 0x00300017, 0x00300013, 0x00300015, 0x00300010, 0x00300011, 0x00300016, 0x00300000, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_802421EC_917F5C
.word 0x00000002, D_80241D40_917AB0, 0x42B40000, 0x00000000, 0x43200000, 0x00002400, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0x0000005A, 0x00000000, 0x000000A0, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000005A, 0x00000000, 0x000000A0, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00300002, 0x00300006, 0x00300007, 0x00300007, 0x00300002, 0x00300002, 0x00300008, 0x00300008, 0x00300014, 0x00300017, 0x00300013, 0x00300015, 0x00300010, 0x00300011, 0x00300016, 0x00300000, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_802423DC_91814C
.word 0x00000003, D_80241C94_917A04, 0x4458C000, 0x00000000, 0x42CA0000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800A00A4, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000363, 0x00000000, 0x00000065, 0x00000028, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000363, 0x00000000, 0x00000065, 0x00000096, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002F0019, 0x002F0002, 0x002F0003, 0x002F0003, 0x002F0019, 0x002F0019, 0x002F0009, 0x002F0009, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000004, D_80241CC0_917A30, 0x4458C000, 0x00000000, 0x42CA0000, 0x00000F21, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002F0019, 0x002F0002, 0x002F0003, 0x002F0003, 0x002F0019, 0x002F0019, 0x002F0009, 0x002F0009, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_802427BC_91852C
.word 0x0000000A, 0x00000002, 0xF9718881, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C80, 0x00000024, 0x00000002, 0xF9718881, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C81, 0x00000024, 0x00000002, 0xF9718881, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000005, 0x00990103, 0x00990102, 0x00000000, 0xFE363C82, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024284C_9185BC
.word 0x0000000A, 0x00000002, 0xF8405E4C, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000321, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000323, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00990105, 0x00000008, 0x00000001, 0x0000002D, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00990102, 0x00000043, 0x00000004, SetNpcCollisionSize, 0xFFFFFFFF, 0x0000002D, 0x0000001A, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24AA280, 0x00000000, 0x0000015E, 0xF24AB680, 0xF24A6080, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00990103, 0x00990102, 0x00000000, 0x000D001F, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000046, 0x00000001, D_80241DAC_917B1C, 0x00000043, 0x00000002, AddKeyItem, 0x0000002C, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00990103, 0x00990102, 0x00000000, 0x000D0020, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24AA280, 0x00000024, 0x00000002, 0xF8405E4C, 0x00000001, 0x00000043, 0x00000003, SetTattleMsg, 0x00000005, 0x001A0088, 0x00000012, 0x00000000, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFF1, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0021, 0x00000024, 0x00000002, 0xFE363C81, 0x000D0022, 0x00000018, 0x00000001, 0x00000020, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0023, 0x00000024, 0x00000002, 0xFE363C81, 0x000D0024, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0025, 0x00000024, 0x00000002, 0xFE363C81, 0x000D0026, 0x00000023, 0x00000000, 0x00000046, 0x00000001, D_802427BC_91852C, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242A70_9187E0
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_8024284C_9185BC, 0x0000000A, 0x00000002, 0xF8405E4C, 0x00000000, 0x00000043, 0x00000004, SetNpcCollisionSize, 0xFFFFFFFF, 0x00000019, 0x00000019, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00990107, 0x00000043, 0x00000003, SetTattleMsg, 0x00000005, 0x001A0087, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242AEC_91885C
.word 0x00000005, D_80241D7C_917AEC, 0x44866000, 0x42480000, 0x43660000, 0x00000801, D_80242A70_9187E0, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00990102, 0x0099010E, 0x0099010E, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00990102, 0x00000000, 0x00000000, 0x00000000, 0x001A0088, 0x00000001, D_80241E0C_917B7C, 0x09030002, 0x00000001, D_80241FFC_917D6C, 0x09010002, 0x00000001, D_802421EC_917F5C, 0x09000002, 0x00000002, D_802423DC_91814C, 0x09050002, 0x00000001, D_80242AEC_91885C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
