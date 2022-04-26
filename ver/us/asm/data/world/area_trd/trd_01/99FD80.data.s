.include "macro.inc"

.section .data

dlabel D_802433F0_99FD80
.word 0x3FC00000, 0x0000002D, 0x00000014, 0x428C0000, 0x42480000, 0x0000000A, 0x40F00000, 0x00000000, 0x00000000, 0x42A00000, 0x42700000, 0x00000001

dlabel D_80243420_99FDB0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000000, 0x00000043, 0x00000002, trd_01_LungeAI_Main, D_802433F0_99FD80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243490_99FE20
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_80243420_99FDB0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

dlabel D_802434BC_99FE4C
.word 0x42DC0000, 0x42820000, 0x00000008, 0x4059999A, 0x00000078, 0x00000002, 0x42DC0000, 0x42820000, 0x00000001

dlabel D_802434E0_99FE70
.word 0x00000043, 0x00000002, trd_01_Unk4AI_Main, D_802434BC_99FE4C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243500_99FE90
.word 0x00000000, 0x00170014, 0x00000000, 0x00000000, D_802434E0_99FE70, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

dlabel D_8024352C_99FEBC
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000008, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x0000002D, 0xFFFFFFE2, 0x00000014, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFFFFFFBA, 0xFFFFFFE2, 0xFFFFFFEC, 0x00000013, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xF24A7280, 0xF24A8280, 0x0000001E, 0x0000000A, 0x00000003, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFFB0, 0x00000004, 0x00000001, 0x00000064, 0x00000013, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C85, 0xFE363C80, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C85, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000005, MakeLerp, 0xF24A8280, 0xF24A7280, 0x0000001E, 0x0000000A, 0x00000003, 0x00000001, 0x00000014, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFFB0, 0x00000004, 0x00000001, 0x00000064, 0x00000013, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C85, 0xFE363C80, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C85, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x00000014, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000004, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000001, 0x00000064, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x0000000A, 0x00000002, 0xFAA2B58A, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000064, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B58B, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000064, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000008, 0x00000000, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8680, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x000000BE, 0x00000014, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x000000F5, 0x0000004B, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A88E7, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x000000D2, 0xFFFFFFEC, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000104, 0x00000019, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8080, 0x00000043, 0x00000001, func_80241630_99DFC0, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000008, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80243420_99FDB0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243A1C_9A03AC
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFB0, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_8024352C_99FEBC, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0029010E, 0x00000012, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000000, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x000000F0, 0x000000DC, 0x00000082, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000050, 0x000000DC, 0x00000109, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243AF4_9A0484
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF8405E19, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, PlaySound, 0x0000000B, 0x00000043, 0x00000007, MakeItemEntity, 0x00000010, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000005, 0xF8405E05, 0x00000044, 0x00000001, D_80242FD0_99F960, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243BC4_9A0554
.word 0x0000000A, 0x00000002, 0xF8405E19, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80243AF4_9A0484, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243C18_9A05A8
.word 0x00000000, D_80243490_99FE20, 0x43820000, 0x00000000, 0x41F00000, 0x00802C00, D_80243BC4_9A0554, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000104, 0x00000000, 0x00000028, 0x0000001E, 0x00000019, 0xFFFF8001, 0x00000001, 0x00000104, 0x00000000, 0x00000028, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243E08_9A0798
.word 0x00000001, D_80243490_99FE20, 0x00000000, 0x00000000, 0x00000000, 0x00002C00, D_80243A1C_9A03AC, 0x00000000, 0x00000000, 0x0000010E, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0x000000F0, 0x000000DC, 0x00000082, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000F0, 0x000000DC, 0x00000082, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243FF8_9A0988
.word 0x00000002, D_80243490_99FE20, 0x00000000, 0x00000000, 0x00000000, 0x00002400, D_80243A1C_9A03AC, 0x00000000, 0x00000000, 0x0000005A, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0x00000050, 0x000000DC, 0x00000109, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000050, 0x000000DC, 0x00000109, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_802441E8_9A0B78
.word 0x00000003, D_80243500_99FE90, 0xC37F0000, 0x44200000, 0x420C0000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x000000B4, 0x800500A4, 0x00050000, 0x00800005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0xFFFFFF01, 0x00000280, 0x00000023, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFF01, 0x00000280, 0x00000023, 0x00000064, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002C0002, 0x002C0004, 0x002C0006, 0x002C0006, 0x002C0002, 0x002C0002, 0x002C000E, 0x002C000E, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x002C0006, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80243C18_9A05A8, 0x06030003, 0x00000001, D_80243E08_9A0798, 0x06010008, 0x00000001, D_80243FF8_9A0988, 0x06000008, 0x00000001, D_802441E8_9A0B78, 0x06100008, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
