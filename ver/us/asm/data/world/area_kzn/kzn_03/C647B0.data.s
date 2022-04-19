.include "macro.inc"

.section .data

dlabel D_80243AA0_C647B0
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40900000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_80243AD0_C647E0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kzn_03_UnkNpcAIMainFunc5, D_80243AA0_C647B0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243B40_C64850
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40E00000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_80243B70_C64880
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000003, 0x00000043, 0x00000002, kzn_03_UnkNpcAIMainFunc5, D_80243B40_C64850, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243BE0_C648F0
.word 0x3F800000, 0x00000014, 0x00000005, 0x42F00000, 0x00000000, 0x00000003, 0x40C00000, 0x00000000, 0x00000000, 0x43160000, 0x00000000, 0x00000001

dlabel D_80243C10_C64920
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000006, 0x00000043, 0x00000002, kzn_03_UnkNpcAIMainFunc5, D_80243BE0_C648F0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243C80_C64990
.word 0x00000043, 0x00000001, kzn_03_func_80240814_97BE44, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0033000F, 0x00000043, 0x00000001, kzn_03_AwaitPlayerNearNpc, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00330000, 0x00000043, 0x00000001, kzn_03_func_802408B4_97BEE4, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kzn_03_UnkNpcAIMainFunc5, D_80243AA0_C647B0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80243AD0_C647E0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80243C80_C64990, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000

dlabel D_80243DCC_C64ADC
.word 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80243B70_C64880, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00180018, 0x00000000, 0x00000000, D_80243C10_C64920, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

dlabel D_80243E24_C64B34
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243EE0_C64BF0
.word 0x00000000, 0x0000001E, 0x0000001E, 0x43160000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243F10_C64C20
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000008, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000009, 0x00000009, 0x00000043, 0x00000003, SetSelfVar, 0x0000000A, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x0000000B, 0x00000007, 0x00000043, 0x00000003, SetSelfVar, 0x0000000C, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x0000000D, 0x0000000F, 0x00000043, 0x00000003, SetSelfVar, 0x0000000E, 0x00000012, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x0000000F, 0x00000043, 0x00000002, kzn_03_PiranhaAI_Main, D_80243EE0_C64BF0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243FE4_C64CF4
.word 0x00000000, 0x00320024, 0x00000000, 0x00000000, D_80243F10_C64C20, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000

dlabel D_80244010_C64D20
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x0000000E, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x000020DE, 0x00000043, 0x00000001, kzn_03_AttackAheadHitbox_Control, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, GetSelfAnimationFromTable, 0x00000007, 0xFE363C80, 0x00000046, 0x00000001, 0x800936DC, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024411C_C64E2C
.word 0x00000000, 0x0014001C, 0x00000000, 0x00000000, D_80244010_C64D20, 0x00000000, 0x00000000, D_80243E24_C64B34, 0x00000000, 0x00000000, 0x00110000

dlabel D_80244148_C64E58
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80244174_C64E84
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel kzn_03_varStash
.word 0x00000000

dlabel D_802441A4_C64EB4
.word 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244204_C64F14
.word 0x00000000

dlabel D_80244208_C64F18
.word 0x00000000

dlabel D_8024420C_C64F1C
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, kzn_03_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80242934_C63644, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_8024296C_C6367C, 0xFE363C80, 0x0000004E, 0x00000006, D_8024420C_C64F1C, 0x00000010, 0x00000000, D_80247420_C7E100, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_802428E0_C635F0, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802443A0_C650B0
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, kzn_03_UnkYawFunc, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, SetItemPos, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244420_C65130
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, kzn_03_UnkYawFunc, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000045, 0x00000002, D_802443A0_C650B0, 0xFE363C8A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040002, 0x00000043, 0x00000004, GetAngleBetweenNPCs, 0xFE363C89, 0xFFFFFFFC, 0xFE363C8B, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C89, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x0000000E, 0x00000002, 0xFE363C8B, 0x000000B4, 0x00000027, 0x00000002, 0xFE363C86, 0x00000014, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C86, 0xFFFFFFEC, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C87, 0x0000000A, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000014, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C8A, 0x000000B4, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040001, 0x00000043, 0x00000004, NpcFaceNpc, 0xFFFFFFFC, 0xFE363C89, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000008, 0x00000001, 0x00000005, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80242934_C63644, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244744_C65454
.word 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, func_8024296C_C6367C, 0xFE363C80, 0x0000004E, 0x00000006, D_80244420_C65130, 0x00000010, 0x00000000, D_80247420_C7E100, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_802428E0_C635F0, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802447B4_C654C4
.word 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFBA, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80242C84_C63994, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x00000043, 0x00000003, FindKeyItem, 0xFE363C85, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000004, 0x0000000B, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFE363C82, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C82, 0xFE363C8D, 0xFE363C80, 0xFE363C8E, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C8E, 0xFE363C8F, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000A, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C80, 0xFE363C8F, 0x0000000A, 0x00000043, 0x00000007, SpeakToNpc, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000000, 0xFE363C82, 0xFE363C87, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000046, 0x00000001, D_80244744_C65454, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C88, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000001, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C89, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000000, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x0000000B, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000046, 0x00000001, D_802441A4_C64EB4, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C86, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80242CC8_C639D8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244AAC_C657BC
.word 0x00000054, 0x00000000

dlabel D_80244AB4_C657C4
.word 0x00000043, 0x0000000B, kzn_03_SetManyVars, 0x00000000, 0x00B60008, 0x00B60001, 0x00000054, 0x00000000, 0x001000E4, 0x001000E5, 0x001000E6, 0x001000E7, D_80244AAC_C657BC, 0x00000046, 0x00000001, D_802447B4_C654C4, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244B04_C65814
.word 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x0000015C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000003, 0x00000046, 0x00000001, D_802441A4_C64EB4, 0x00000043, 0x00000002, AddStarPieces, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244B68_C65878
.word 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8280, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60004, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C83, 0xFFFFFFD3, 0x00000024, 0x00000002, 0xFE363C87, 0x0000005A, 0x00000005, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C82, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0xFE363C87, 0x00000005, 0x00000043, 0x00000005, MakeLerp, 0xFE363C82, 0xFE363C83, 0x0000002D, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0xFE363C87, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C85, 0xFE363C86, 0x00000008, 0x00000001, 0x00000001, 0x0000000F, 0x00000002, 0xF5DE0180, 0x0000001D, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0x0000001D, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C87, 0x000000B4, 0x0000000F, 0x00000002, 0xFE363C87, 0x00000168, 0x00000027, 0x00000002, 0xFE363C87, 0xFFFFFE98, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60001, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A8480, 0x00000003, 0x00000001, 0x00000005, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x0000032C, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000009, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000008, 0x00000001, 0x00000006, 0x00000004, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60009, 0x00B60007, 0x00000200, 0x001000F3, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000012, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244EF8_C65C08
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000001, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000001D, 0x0000000A, 0x00000002, 0xF84060AD, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A87B4, 0x00000000, 0x0000015E, 0xF24AB680, 0xF24A5E80, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x001000F1, 0x00000024, 0x00000002, 0xF84060AD, 0x00000001, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8E80, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x001000F2, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A8480, 0x00000003, 0x00000001, 0x00000005, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x0000032C, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000009, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000008, 0x00000001, 0x00000006, 0x00000004, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60009, 0x00B60007, 0x00000200, 0x001000F3, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000012, 0x00000013, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000000, 0x00000046, 0x00000001, D_80244AB4_C657C4, 0x00000046, 0x00000001, D_80244B04_C65814, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245134_C65E44
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x0000001D, 0x0000000A, 0x00000002, 0xF840609F, 0x00000001, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80244B68_C65878, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80244EF8_C65C08, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x0000001D, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80244EF8_C65C08, 0x00000002, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0x00000035, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0x0000003B, 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024529C_C65FAC
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000001, 0x00000043, 0x00000005, SetNpcScale, 0xFFFFFFFF, 0xF24A7BB4, 0x00000001, 0xF24A7BB4, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802452E0_C65FF0
.word 0x00000000, D_80244174_C64E84, 0x43C40000, 0x43EB0000, 0x435A0000, 0x00110509, D_80245134_C65E44, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B60001, 0x00B60004, 0x00B60006, 0x00B60006, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00000000, 0x00000000, 0x00000000, 0x001A0000, 0x00000001, D_80244148_C64E58, 0x43C40000, 0x43EB0000, 0x435A0000, 0x00200F01, D_8024529C_C65FAC, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B60001, 0x00B60004, 0x00B60006, 0x00B60006, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00000000, 0x00000000, 0x00000000, 0x001A0000, 0x00000002, D_80244148_C64E58, 0x43C40000, 0x43EB0000, 0x435A0000, 0x00200F01, D_8024529C_C65FAC, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B60001, 0x00B60004, 0x00B60006, 0x00B60006, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00000000, 0x00000000, 0x00000000, 0x001A0000

dlabel D_802458B0_C665C0
.word 0x00000003, D_80243DCC_C64ADC, 0x430C0000, 0x44278000, 0xC1A00000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005009B, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00030000, 0x0000008C, 0x0000029E, 0xFFFFFFEC, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFCE, 0x0000029E, 0xFFFFFFE7, 0x000000F0, 0x00000073, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004D0003, 0x004D0006, 0x004D0008, 0x004D0008, 0x004D0003, 0x004D0003, 0x004D0013, 0x004D0013, 0x004D000B, 0x004D000A, 0x004D000C, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245AA0_C667B0
.word 0x00000004, D_80243DCC_C64ADC, 0xC3480000, 0x44278000, 0xC20C0000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005009B, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00030000, 0xFFFFFF38, 0x0000029E, 0xFFFFFFDD, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFCE, 0x0000029E, 0xFFFFFFE7, 0x000000F0, 0x00000073, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004D0003, 0x004D0006, 0x004D0008, 0x004D0008, 0x004D0003, 0x004D0003, 0x004D0013, 0x004D0013, 0x004D000B, 0x004D000A, 0x004D000C, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245C90_C669A0
.word 0x00000005, D_80243DCC_C64ADC, 0x41F00000, 0x41A00000, 0x43A00000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005009B, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00030000, 0x0000001E, 0x00000014, 0x00000140, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000008C, 0x00000014, 0x00000113, 0x000000B4, 0x0000005F, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004D0003, 0x004D0006, 0x004D0008, 0x004D0008, 0x004D0003, 0x004D0003, 0x004D0013, 0x004D0013, 0x004D000B, 0x004D000A, 0x004D000C, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245E80_C66B90
.word 0x00000006, D_80243FE4_C64CF4, 0x43820000, 0x41A00000, 0x437F0000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000104, 0x00000014, 0x000000FF, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000104, 0x00000014, 0x000000FF, 0x00000064, 0x00000032, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000007, D_8024411C_C64E2C, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_802452E0_C65FF0, 0x00000000, 0x00000001, D_802458B0_C665C0, 0x16080002, 0x00000001, D_80245AA0_C667B0, 0x16090002, 0x00000001, D_80245C90_C669A0, 0x160A0002, 0x00000002, D_80245E80_C66B90, 0x16130002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
