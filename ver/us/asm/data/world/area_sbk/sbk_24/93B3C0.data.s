.include "macro.inc"

.section .data

dlabel D_80240790_93B3C0
.word 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C8A, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000001, 0x00000000, 0x00000043, 0x00000004, sbk_24_Bandit_DropCoin, 0xFE363C8A, 0xFE363C80, 0xF9718881, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240828_93B458
.word 0x402CCCCD, 0x0000002D, 0x0000001E, 0x43E10000, 0x00000000, 0x0000000A, 0x4104CCCD, 0x000000B4, 0x00000064, 0x44098000, 0x42C80000, 0x00000001

dlabel D_80240858_93B488
.word 0x00000043, 0x00000002, DoBasicAI, D_80240828_93B458, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240878_93B4A8
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, func_80045900, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xF9718881, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00320002, 0x00000043, 0x00000002, GetSelfNpcID, 0xFE363C80, 0x00000044, 0x00000001, D_80240790_93B3C0, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7E80, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000027, 0x00000002, 0xFE363C87, 0x00000014, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C87, 0x00000000, 0xFE363C89, 0x00000006, 0x00000027, 0x00000002, 0xFE363C87, 0x00000014, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C87, 0x00000000, 0xFE363C89, 0x00000006, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00320008, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24ABA80, 0x00000027, 0x00000002, 0xFE363C87, 0x000000C8, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFE363C87, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xF9718881, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x001A0018, 0x00000000, 0x00000000, D_80240858_93B488, EnemyNpcHit, 0x00000000, D_80240878_93B4A8, 0x00000000, 0x00000000, 0x00090005, 0x00000043, 0x00000008, MakeEntity, 0x802EA5D0, 0x00000154, 0x0000003C, 0xFFFFFF56, 0x00000000, 0x00000103, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405EAA, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
