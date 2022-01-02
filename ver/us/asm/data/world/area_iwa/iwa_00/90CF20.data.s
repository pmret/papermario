.include "macro.inc"

.section .data

dlabel D_802402E0_90CF20
.word 0x425C0000, 0xC0A00000, 0xC1C80000, 0x42B40000, 0x44A42000, 0x42B40000, 0xC2200000, 0x43870000, 0x441C4000, 0xC1F00000, 0x43818000, 0x42340000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_802404E4_90D124, D_802402E0_90CF20, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x0019005A

dlabel D_80240350_90CF90
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80242A60, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802403AC_90CFEC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80242A68, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240408_90D048
.word 0x00000043, 0x00000003, EnableTexPanning, 0x00000017, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000016, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000BB8, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000001, 0x00000000, 0x00000000, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024049C_90D0DC
.word 0x00000047, 0x00000005, D_80240350_90CF90, 0x00080000, 0x00000001, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802403AC_90CFEC, 0x00080000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802404E4_90D124
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000008, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, D_80242780_90F3C0, 0x00000046, 0x00000001, D_80240640_90D280, 0x00000044, 0x00000001, D_80240408_90D048, 0x00000044, 0x00000001, D_802429F8_90F638, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000016, 0x00000000, 0x00000008, 0x00000043, 0x00000006, PlaySoundAtF, 0x8000000B, 0x00000001, 0x00000023, 0xFFFFFFB0, 0xFFFFFF88, 0x00000043, 0x00000006, PlaySoundAtF, 0x8000000C, 0x00000001, 0x000001F4, 0x00000055, 0xFFFFFF88, 0x00000024, 0x00000002, 0xFE363C80, D_8024049C_90D0DC, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240620_90D260
.word 0x00000024, 0x00000002, 0xF8405E4F, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240640_90D280
.word 0x0000000A, 0x00000002, 0xF8405E4F, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA154, 0x00000384, 0xFFFFFFE2, 0x000000DC, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80240620_90D260, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0x00000195, 0x00000019, 0x00000019, 0x00000011, 0xF8405E33, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0x000001D1, 0x00000035, 0x00000019, 0x00000011, 0xF8405E34, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0x00000203, 0x0000005C, 0x00000019, 0x00000011, 0xF8405E35, 0x00000043, 0x00000008, MakeEntity, 0x802EA564, 0x000004EC, 0x0000001E, 0x0000008C, 0x00000000, 0x0000008F, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405E4B, 0x00000043, 0x00000008, MakeEntity, 0x802BCD9C, 0x0000003A, 0xFFFFFFFB, 0xFFFFFFB7, 0xFFFFFFE2, 0x0000005A, 0x80000000, 0x00000043, 0x00000008, MakeEntity, 0x802BCD9C, 0x0000039E, 0x00000046, 0xFFFFFFD3, 0x00000016, 0x0000005A, 0x80000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240790_90D3D0
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024082C_90D46C
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F0012, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802408AC_90D4EC
.word 0x3FE66666, 0x0000001E, 0x0000001E, 0x42B40000, 0x428C0000, 0x00000002, 0x40400000, 0x0000005A, 0x00000019, 0x42F00000, 0x428C0000, 0x00000001

dlabel D_802408DC_90D51C
.word 0x00000043, 0x00000002, func_800445D4, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000064, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, IsPlayerWithin, 0xFE363C80, 0xFE363C82, 0x00000050, 0xFE363C83, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F000E, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000027, 0x00000002, 0xFE363C85, 0x0000001E, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7E80, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000323, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000014, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C80, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000000, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000043, 0x00000002, DoBasicAI, D_802408AC_90D4EC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B28_90D768
.word 0x00000000, 0x00180016, D_80240790_90D3D0, 0x00000000, D_802408DC_90D51C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00080001

dlabel D_80240B54_90D794
.word 0x00000000, 0x00180016, D_8024082C_90D46C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00080001

dlabel D_80240B80_90D7C0
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C82, 0x00000032, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C04_90D844
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00040000, 0x00000001, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C82, 0x00000032, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F0013, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C9C_90D8DC
.word 0x3FE66666, 0x0000001E, 0x0000001E, 0x42B40000, 0x428C0000, 0x00000002, 0x40400000, 0x0000005A, 0x00000019, 0x42F00000, 0x428C0000, 0x00000001

dlabel D_80240CCC_90D90C
.word 0x00000043, 0x00000002, func_800445D4, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000064, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C82, 0x00000082, 0x00000043, 0x00000005, IsPlayerWithin, 0xFE363C80, 0xFE363C82, 0x00000050, 0xFE363C83, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C83, 0x00000032, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000004, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x002F000E, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000028, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C83, 0x00000050, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7D4D, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000323, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000014, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x00000020, 0x00000000, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DoBasicAI, D_80240C9C_90D8DC, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F74_90DBB4
.word 0x00000000, 0x00180016, D_80240B80_90D7C0, 0x00000000, D_80240CCC_90D90C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00080001

dlabel D_80240FA0_90DBE0
.word 0x00000000, 0x00180016, D_80240C04_90D844, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00080001

dlabel D_80240FCC_90DC0C
.word 0x00000000, 0x001E001A, 0x00000000, 0x00000000, 0x00000000, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240FF8_90DC38
.word 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024105C_90DC9C
.word 0x00000000, D_80240B28_90D768, 0x445C0000, 0x428C0000, 0x42860000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800A00A4, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000370, 0x00000046, 0x00000043, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000370, 0x00000046, 0x00000043, 0x00000078, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002F0019, 0x002F0002, 0x002F0003, 0x002F0003, 0x002F0019, 0x002F0019, 0x002F0009, 0x002F0009, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80240B54_90D794, 0x445C0000, 0x428C0000, 0x42860000, 0x00000F21, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000370, 0x00000046, 0x00000043, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002F0019, 0x002F0002, 0x002F0003, 0x002F0003, 0x002F0019, 0x002F0019, 0x002F0009, 0x002F0009, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024143C_90E07C
.word 0x00000002, D_80240F74_90DBB4, 0x44988000, 0xC1F00000, 0x428C0000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x800A00A4, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x000004C4, 0xFFFFFFE2, 0x00000046, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x000004C4, 0xFFFFFFE2, 0x00000046, 0x00000078, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002F0019, 0x002F0002, 0x002F0003, 0x002F0003, 0x002F0019, 0x002F0019, 0x002F0009, 0x002F0009, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_80240FA0_90DBE0, 0x44988000, 0xC1F00000, 0x428C0000, 0x00000F21, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000004C4, 0xFFFFFFE2, 0x00000046, 0x00000000, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002F0019, 0x002F0002, 0x002F0003, 0x002F0003, 0x002F0019, 0x002F0019, 0x002F0009, 0x002F0009, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x002F0019, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024181C_90E45C
.word 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x0000000C, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000000, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xF5DE01FB, 0x00000016, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E52, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00920005, 0x00920001, 0x00000000, 0x000D0027, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00920005, 0x00920001, 0x00000000, 0x000D0028, 0x00000013, 0x00000000, 0x0000001A, 0x00000001, 0x00000002, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00920005, 0x00920001, 0x00000000, 0x000D0028, 0x0000001A, 0x00000001, 0x00000004, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00920005, 0x00920001, 0x00000000, 0x000D0029, 0x0000001A, 0x00000001, 0x00000006, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00920005, 0x00920001, 0x00000000, 0x000D002A, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00920005, 0x00920001, 0x00000000, 0x000D002B, 0x00000023, 0x00000000, 0x00000024, 0x00000002, 0xF8405E52, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419EC_90E62C
.word 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00920001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000005, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000002, 0xFE363C81, 0x00000014, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000258, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x0000000D, 0x00000002, 0xFE363C80, 0x00000352, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000321, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00920002, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000005, SetNpcPos, 0x00000005, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00920001, 0x00000008, 0x00000001, 0x0000001E, 0x00000003, 0x00000001, 0x0000000A, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000E, 0x00000002, 0xFE363C80, 0x00000384, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00920003, 0x00000043, 0x00000005, SetNpcPos, 0x00000005, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C6C_90E8AC
.word 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000004, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000001, 0x00000016, 0x00000001, 0x00000006, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000002, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000003, 0x00000013, 0x00000000, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000023, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, BindNpcInteract, 0x00000004, 0x00000000, 0x00000043, 0x00000003, EnableNpcAI, 0x00000004, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x0000000C, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000001, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xF5DE01FB, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000003, 0x00000027, 0x00000002, 0xF5DE01FB, 0x00000001, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8A, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000003, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000004, 0x000000E1, 0x00000000, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8A, 0x0000001D, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000002, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00920004, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000E, 0x00000012, 0x00000000, 0x00000028, 0x00000002, 0xFE363C80, 0x0000000E, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C82, 0x00000002, 0x00000043, 0x00000007, MakeItemEntity, 0x00000093, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000D, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00920001, 0x00000008, 0x00000001, 0x00000005, 0x00000020, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE01FB, 0x00000008, 0x00000014, 0x00000001, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00920005, 0x00920001, 0x00000000, 0x000D002C, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00920005, 0x00920001, 0x00000000, 0x000D002D, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00920005, 0x00920001, 0x00000000, 0x000D002E, 0x00000023, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00920003, 0x00000008, 0x00000001, 0x0000000F, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00920005, 0x00920001, 0x00000000, 0x000D002F, 0x00000008, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE01FB, 0x00000008, 0x00000043, 0x00000001, func_80240118_90CD58, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000005, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0x00000004, 0x00000043, 0x00000002, RemoveNpc, 0x00000005, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024228C_90EECC
.word 0x00000043, 0x00000004, SetNpcVar, 0x00000004, 0x00000008, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE01FB, 0x00000008, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_8024181C_90E45C, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802419EC_90E62C, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00200000, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242338_90EF78
.word 0x0000000C, 0x00000002, 0xF5DE01FB, 0x00000008, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcHit, 0xFFFFFFFF, D_80241C6C_90E8AC, 0x00000012, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802423A0_90EFE0
.word 0x00000004, D_80240FCC_90DC0C, 0x44354000, 0xC1F00000, 0x43610000, 0x00400D05, D_8024228C_90EECC, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00000000, 0x00000000, 0x00000000, 0x001A0089, 0x00000005, D_80240FCC_90DC0C, 0x44354000, 0xC1F00000, 0x43610000, 0x03704F0C, D_80242338_90EF78, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00920001, 0x00000000, 0x00000000, 0x00000000, 0x001A0089

dlabel D_80242780_90F3C0
.word 0x00000002, D_8024105C_90DC9C, 0x09060002, 0x00000002, D_8024143C_90E07C, 0x09070002, 0x00000002, D_802423A0_90EFE0, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802427B0_90F3F0
.word 0x43870000, 0x3ECCCCCD, 0xBD4CCCCD, 0x41A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802427D0_90F410
.word 0x00000024, 0x00000002, 0xFE363C80, D_802427B0_90F3F0, 0x00000043, 0x00000001, func_802402B0_90CEF0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802427FC_90F43C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000000, 0x000020A2, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000050, 0x0000000A, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000001E, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000000, 0x7FFFFE00, 0x00000043, 0x00000004, PlayerMoveTo, 0x0000021F, 0x00000011, 0x00000014, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000056, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000000, 0x000020A2, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000050, 0x00000000, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000001E, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x00000000, 0x7FFFFE00, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802429F8_90F638
.word 0x00000047, 0x00000005, D_802427FC_90F43C, 0x00000100, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802427D0_90F410, 0x00000080, 0x0000000C, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000C, 0x00000005, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
