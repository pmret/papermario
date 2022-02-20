.include "macro.inc"

.section .data

dlabel D_80241AA0_9A60F0
.word 0x3FC00000, 0x0000002D, 0x00000014, 0x428C0000, 0x42480000, 0x0000000A, 0x40F00000, 0x00000000, 0x00000000, 0x42A00000, 0x42700000, 0x00000001

dlabel D_80241AD0_9A6120
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000000, 0x00000043, 0x00000002, trd_03_UnkNpcAIMainFunc5, D_80241AA0_9A60F0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B40_9A6190
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, D_80241AD0_9A6120, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000

dlabel D_80241B6C_9A61BC
.word 0x00000000, 0x00220018, 0x00000000, 0x00000000, 0x00000000, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241B98_9A61E8
.word 0x3FC00000, 0x0000003C, 0x0000000A, 0x42DC0000, 0x42820000, 0x00000008, 0x4059999A, 0x00000078, 0x00000002, 0x42DC0000, 0x42820000, 0x00000001

dlabel D_80241BC8_9A6218
.word 0x00000043, 0x00000002, DoBasicAI, D_80241B98_9A61E8, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00170014, 0x00000000, 0x00000000, D_80241BC8_9A6218, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000044, 0x00000001, 0x80240ABC, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0xFFFFFD30, 0x00000000, 0x0000004B, 0x00000043, 0x00000004, SetPlayerPos, 0xFFFFFD44, 0x00000000, 0x00000050, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660305, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFFFFFDC6, 0x00000000, 0xFFFFFFC7, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000010E, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFDA1, 0x00000000, 0x00000050, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x00000140, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFDA1, 0x00000000, 0x00000050, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660304, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000005A, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660303, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A84E7, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFFFFFDD5, 0x00000014, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0x0000000A, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660304, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660314, 0x00000008, 0x00000001, 0x00000019, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660304, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000A, 0x00290109, 0x00000008, 0x00000001, 0x00000019, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000A, 0x00290101, 0x00000056, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000036, 0x0000026B, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000064, 0x00000000, 0x00000028, 0x00000001, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0x0000000C, 0x00000000, 0xFE363C80, 0xFFFFFFFF, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000036, 0x0000026C, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660303, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFFFFFDDA, 0x00000046, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660304, 0x00000008, 0x00000001, 0x0000000F, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00660314, 0x00660304, 0x00000005, 0x000C00D3, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000002, 0x000001C3, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000050, 0x0000000A, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000002D, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000002F, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000004, SetPlayerPos, 0xFFFFFD79, 0x00000000, 0x00000050, 0x00000046, 0x00000001, D_80240ED8_9A5528, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000010E, 0x00000005, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000005, 0x00000004, 0x00000002, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0066031E, 0x00000008, 0x00000001, 0x0000000C, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660304, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00660314, 0x00660304, 0x00000000, 0x000C00D4, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660302, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000002D, 0x00000002, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x00000173, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00660303, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7DB4, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x00000174, 0x00000000, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFFFFFED4, 0x00000046, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFA8, 0x00000043, 0x00000002, RemoveNpc, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000044, 0x00000001, 0x80240B04, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242334_9A6984
.word 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFFA8, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024236C_9A69BC
.word 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFA8, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00290103, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80241AD0_9A6120, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802423F8_9A6A48
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_8024236C_9A69BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024241C_9A6A6C
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x0000000C, 0x00000002, 0xFE363C80, 0xFFFFFF6A, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00290109, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7E80, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00290103, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x0000000C, 0x00000002, 0xFE363C80, 0xFFFFFF9C, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00290104, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A9680, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000023, 0xFFFFFF7E, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x0000005A, 0xFFFFFF7E, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000069, 0x0000000A, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00290103, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80241AD0_9A6120, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242620_9A6C70
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_8024241C_9A6A6C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242644_9A6C94
.word 0x00000000, D_80241B6C_9A61BC, 0xC40E4000, 0x00000000, 0xC2640000, 0x00000D01, D_80242334_9A6984, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00660304, 0x00660302, 0x00660303, 0x00660303, 0x00660304, 0x00660304, 0x0066030A, 0x0066030A, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242834_9A6E84
.word 0x0000000A, D_80241B40_9A6190, 0xC4020000, 0x00000000, 0x41700000, 0x00000C00, D_802423F8_9A6A48, 0x00000000, 0x00000000, 0x0000005A, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0xFFFFFDF8, 0x00000000, 0x0000000F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFDF8, 0x00000000, 0x0000000F, 0x0000015E, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242A24_9A7074
.word 0x0000000B, D_80241B40_9A6190, 0xC2500000, 0x00000000, 0xC1A80000, 0x00000C00, D_80242620_9A6C70, 0x00000000, 0x00000000, 0x0000005A, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0xFFFFFFCC, 0x00000000, 0xFFFFFFEB, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFCC, 0x00000000, 0xFFFFFFEB, 0x0000015E, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242C14_9A7264
.word 0x0000000C, D_80241B40_9A6190, 0x43BB8000, 0x00000000, 0x41700000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008A, 0x00050000, 0x00900005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00010000, 0x00000177, 0x00000000, 0x0000000F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000177, 0x00000000, 0x0000000F, 0x0000015E, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00290101, 0x00290103, 0x00290104, 0x00290104, 0x00290101, 0x00290101, 0x0029010B, 0x0029010B, 0x00290107, 0x00290106, 0x00290108, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00290104, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242644_9A6C94, 0x00000002, 0x00000001, D_80242834_9A6E84, 0x06030002, 0x00000001, D_80242A24_9A7074, 0x06040002, 0x00000001, D_80242C14_9A7264, 0x06030002, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000000E, 0x00000000, 0x00000000, 0xFFFFFFA1, 0x00000043, 0x00000005, TranslateModel, 0x0000000F, 0x00000000, 0x00000000, 0xFFFFFFA1, 0x00000043, 0x00000005, TranslateModel, 0x00000010, 0x00000000, 0x00000000, 0xFFFFFFA1, 0x00000043, 0x00000005, TranslateModel, 0x00000011, 0x00000000, 0x00000000, 0xFFFFFFA1, 0x00000043, 0x00000005, TranslateModel, 0x00000012, 0x00000000, 0x00000000, 0xFFFFFF6F, 0x00000043, 0x00000005, TranslateModel, 0x00000013, 0x00000000, 0x00000000, 0xFFFFFF6F, 0x00000043, 0x00000005, TranslateModel, 0x00000014, 0x00000000, 0x00000000, 0xFFFFFF6F, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000032, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000033, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000034, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000035, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000003B, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000003A, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000039, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFD050F80, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242FCC_9A761C
.word 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFE363C88, 0x00000007, 0x00000002, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xFE363C89, 0x00000000, 0x00000000, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0xFE363C87, 0x7FFFFE00, 0x00000043, 0x00000002, PlaySound, 0x00000026, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000002, 0xF24A7BB4, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802430A0_9A76F0
.word 0x00000043, 0x00000005, MakeLerp, 0xFE363C88, 0x00000000, 0x00000007, 0x00000002, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xFE363C89, 0x00000000, 0x00000000, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0xFE363C87, 0x7FFFFE00, 0x00000043, 0x00000002, PlaySound, 0x00000026, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000002, 0xF24A7BB4, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000003, 0x00000001, 0x0000007B, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x0000007B, 0x00000013, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFEC5, 0x00000078, 0xFFFFFFCE, 0x00000043, 0x00000004, func_80240880_9A4ED0, 0xFFFFFEC5, 0xFFFFFF9C, 0x0000003C, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000004, SetCamPosB, 0x00000000, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000F, 0x0000000A, 0x00000002, 0xFD050F80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000039, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000014, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000035, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000011, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000034, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000010, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003A, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000013, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000033, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000F, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000032, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000E, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003B, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000012, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFD050F80, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003B, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000012, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000032, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000E, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000033, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000F, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003A, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000013, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000034, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000010, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000035, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000011, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000039, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000014, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFD050F80, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8480, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000003, 0x00000001, 0x0000007B, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x0000007B, 0x00000013, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x000000D2, 0x00000078, 0xFFFFFFCE, 0x00000043, 0x00000004, func_80240880_9A4ED0, 0x000000D2, 0xFFFFFF9C, 0xFFFFFFC4, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000004, SetCamPosB, 0x00000000, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000F, 0x0000000A, 0x00000002, 0xFD050F80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003B, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000012, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000032, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000E, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000033, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000F, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003A, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000013, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000034, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000010, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000035, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000011, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000039, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000014, 0x00000044, 0x00000001, D_802430A0_9A76F0, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFD050F80, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0x00000039, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000014, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000035, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000011, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000034, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x00000010, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003A, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000013, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000033, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000F, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x00000032, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFFA1, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000E, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFE363C87, 0x0000003B, 0x00000024, 0x00000002, 0xFE363C88, 0xFFFFFF6F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000012, 0x00000044, 0x00000001, D_80242FCC_9A761C, 0x00000008, 0x00000001, 0x00000009, 0x00000024, 0x00000002, 0xFD050F80, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8480, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
