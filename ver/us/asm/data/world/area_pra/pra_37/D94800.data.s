.include "macro.inc"

.section .data

dlabel D_802418C0_D94800
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419D0_D94910
.word 0x0000003E, 0x00000002, 0x00000010, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, pra_37_ReflectWall, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000001, pra_37_ReflectWall, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, pra_37_ReflectFloor, 0xFE363C80, 0x00000043, 0x00000002, pra_37_ReflectPartner, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A78_D949B8
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x0000000D, 0x00000024, 0x00000002, 0xFE363C82, 0x00000017, 0x00000024, 0x00000002, 0xFE363C83, 0x00000014, 0x00000024, 0x00000002, 0xFE363C84, 0x00000018, 0x00000024, 0x00000002, 0xFE363C85, 0x00000015, 0x00000044, 0x00000001, 0x80285E9C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x802424FC, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B3C_D94A7C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000011, 0x00000024, 0x00000002, 0xFE363C82, 0x0000001B, 0x00000024, 0x00000002, 0xFE363C83, 0x0000001E, 0x00000024, 0x00000002, 0xFE363C84, 0x0000001C, 0x00000024, 0x00000002, 0xFE363C85, 0x0000001F, 0x00000044, 0x00000001, 0x80285E9C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80242504, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C00_D94B40
.word 0x00000047, 0x00000005, D_80241A78_D949B8, 0x00000100, 0x0000000D, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241B3C_D94A7C, 0x00000100, 0x00000011, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C48_D94B88
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000017, 0x00000024, 0x00000002, 0xFE363C83, 0x00000014, 0x00000024, 0x00000002, 0xFE363C84, 0x00000018, 0x00000024, 0x00000002, 0xFE363C85, 0x00000015, 0x00000046, 0x00000001, 0x80285EC4, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0x0000001B, 0x00000024, 0x00000002, 0xFE363C83, 0x0000001E, 0x00000024, 0x00000002, 0xFE363C84, 0x0000001C, 0x00000024, 0x00000002, 0xFE363C85, 0x0000001F, 0x00000046, 0x00000001, 0x80285EC4, 0x00000023, 0x00000000, 0x00000044, 0x00000001, D_80241C00_D94B40, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000015, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000018, 0x00000018, 0x00000028, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, D_802424C4_D95404, 0x00000044, 0x00000001, 0x80241880, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0xF8406152, 0x00000044, 0x00000001, D_802419D0_D94910, 0x00000044, 0x00000001, D_80241C48_D94B88, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241E30_D94D70
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x0039000C, 0x00390007, 0x00390008, 0x00390011, 0x00390012, 0xFFFFFFFF

dlabel D_80241F14_D94E54
.word 0x00390000, 0xFFFFFFFF

dlabel D_80241F1C_D94E5C
.word 0x3FC00000, 0x00000078, 0x0000001E, 0x42C80000, 0x42200000, 0x00000007, 0x40733333, 0x0000005A, 0x0000000F, 0x43480000, 0x43200000, 0x00000001

dlabel D_80241F4C_D94E8C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000007, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000006, 0x00000043, 0x00000002, pra_37_UnkNpcAIFunc27, D_80241F1C_D94E5C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241FBC_D94EFC
.word 0x00000000, 0x00240022, 0x00000000, 0x00000000, D_80241F4C_D94E8C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00170000

dlabel D_80241FE8_D94F28
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000020, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000030, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x000020C5, 0x00000043, 0x00000001, pra_37_UnkFunc7, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242090_D94FD0
.word 0x00000000, 0x000E0010, 0x00000000, 0x00000000, D_80241FE8_D94F28, 0x00000000, 0x00000000, D_80241E30_D94D70, 0x00000000, 0x00000000, 0x00170008

dlabel D_802420BC_D94FFC
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00080000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802420E4_D95024
.word 0x00000000, D_80241FBC_D94EFC, 0x432F0000, 0x00000000, 0x42960000, 0x00000C00, D_802420BC_D94FFC, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x000000AF, 0x00000000, 0x0000004B, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000AF, 0x00000000, 0x0000004B, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00390102, 0x00390103, 0x00390104, 0x00390104, 0x00390102, 0x00390102, 0x0039010C, 0x0039010C, 0x00390111, 0x00390112, 0x00390107, 0x00390108, 0x00390102, 0x00390102, 0x00390102, 0x00390102, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242090_D94FD0, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00390102, 0x00390103, 0x00390104, 0x00390104, 0x00390102, 0x00390102, 0x0039010C, 0x0039010C, 0x00390111, 0x00390112, 0x00390107, 0x00390108, 0x00390102, 0x00390102, 0x00390102, 0x00390102, 0x00000000, 0x00000000, D_80241F14_D94E54, 0x00000000

dlabel D_802424C4_D95404
.word 0x00000002, D_802420E4_D95024, 0x1F0D0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
