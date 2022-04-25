.include "macro.inc"

.section .data

dlabel D_802439A0_C89450
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_802439CC_C8947C
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243A88_C89538
.word 0x00000000, 0x0000001E, 0x0000001E, 0x43160000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243AB8_C89568
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000008, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000009, 0x00000009, 0x00000043, 0x00000003, SetSelfVar, 0x0000000A, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x0000000B, 0x00000007, 0x00000043, 0x00000003, SetSelfVar, 0x0000000C, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x0000000D, 0x0000000F, 0x00000043, 0x00000003, SetSelfVar, 0x0000000E, 0x00000012, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x0000000F, 0x00000043, 0x00000002, kzn_17_PiranhaPlantAI_Main, D_80243A88_C89538, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243B8C_C8963C
.word 0x00000000, 0x00320024, 0x00000000, 0x00000000, D_80243AB8_C89568, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000

dlabel D_80243BB8_C89668
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x0000000E, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x000020DE, 0x00000043, 0x00000001, kzn_17_MeleeHitbox_Main, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000003, GetSelfAnimationFromTable, 0x00000007, 0xFE363C80, 0x00000046, 0x00000001, 0x800936DC, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243CC4_C89774
.word 0x00000000, 0x0014001C, 0x00000000, 0x00000000, D_80243BB8_C89668, 0x00000000, 0x00000000, D_802439CC_C8947C, 0x00000000, 0x00000000, 0x00110000

dlabel D_80243CF0_C897A0
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40900000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_80243D20_C897D0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kzn_17_UnkNpcAIMainFunc5, D_80243CF0_C897A0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243D90_C89840
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40E00000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_80243DC0_C89870
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000003, 0x00000043, 0x00000002, kzn_17_UnkNpcAIMainFunc5, D_80243D90_C89840, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243E30_C898E0
.word 0x3F800000, 0x00000014, 0x00000005, 0x42F00000, 0x00000000, 0x00000003, 0x40C00000, 0x00000000, 0x00000000, 0x43160000, 0x00000000, 0x00000001

dlabel D_80243E60_C89910
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000006, 0x00000043, 0x00000002, kzn_17_UnkNpcAIMainFunc5, D_80243E30_C898E0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243ED0_C89980
.word 0x00000043, 0x00000001, kzn_17_func_80240814_97BE44, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0033000F, 0x00000043, 0x00000001, kzn_17_AwaitPlayerNearNpc, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00330000, 0x00000043, 0x00000001, kzn_17_func_802408B4_97BEE4, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kzn_17_UnkNpcAIMainFunc5, D_80243CF0_C897A0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80243D20_C897D0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80243ED0_C89980, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000

dlabel D_8024401C_C89ACC
.word 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80243DC0_C89870, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00180018, 0x00000000, 0x00000000, D_80243E60_C89910, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

dlabel kzn_17_varStash
.word 0x00000000

dlabel D_80244078_C89B28
.word 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802440D8_C89B88
.word 0x00000000

dlabel D_802440DC_C89B8C
.word 0x00000000

dlabel D_802440E0_C89B90
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, kzn_17_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80242934_C883E4, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_8024296C_C8841C, 0xFE363C80, 0x0000004E, 0x00000006, D_802440E0_C89B90, 0x00000010, 0x00000000, D_802465F0, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_802428E0_C88390, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244274_C89D24
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, kzn_17_UnkYawFunc, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, SetItemPos, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802442F4_C89DA4
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, kzn_17_UnkYawFunc, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000045, 0x00000002, D_80244274_C89D24, 0xFE363C8A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040002, 0x00000043, 0x00000004, GetAngleBetweenNPCs, 0xFE363C89, 0xFFFFFFFC, 0xFE363C8B, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C89, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x0000000E, 0x00000002, 0xFE363C8B, 0x000000B4, 0x00000027, 0x00000002, 0xFE363C86, 0x00000014, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C86, 0xFFFFFFEC, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C87, 0x0000000A, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000014, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C8A, 0x000000B4, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040001, 0x00000043, 0x00000004, NpcFaceNpc, 0xFFFFFFFC, 0xFE363C89, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000008, 0x00000001, 0x00000005, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80242934_C883E4, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244618_C8A0C8
.word 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, func_8024296C_C8841C, 0xFE363C80, 0x0000004E, 0x00000006, D_802442F4_C89DA4, 0x00000010, 0x00000000, D_802465F0, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_802428E0_C88390, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244688_C8A138
.word 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFBA, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80242C84_C88734, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x00000043, 0x00000003, FindKeyItem, 0xFE363C85, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000004, 0x0000000B, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFE363C82, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C82, 0xFE363C8D, 0xFE363C80, 0xFE363C8E, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C8E, 0xFE363C8F, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000A, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C80, 0xFE363C8F, 0x0000000A, 0x00000043, 0x00000007, SpeakToNpc, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000000, 0xFE363C82, 0xFE363C87, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000046, 0x00000001, D_80244618_C8A0C8, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C88, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000001, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C89, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000000, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x0000000B, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000046, 0x00000001, D_80244078_C89B28, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C86, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80242CC8_C88778, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244980_C8A430
.word 0x00000054, 0x00000000

dlabel D_80244988_C8A438
.word 0x00000043, 0x0000000B, kzn_17_SetManyVars, 0x00000000, 0x00B60008, 0x00B60001, 0x00000054, 0x00000000, 0x001000E4, 0x001000E5, 0x001000E6, 0x001000E7, D_80244980_C8A430, 0x00000046, 0x00000001, D_80244688_C8A138, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802449D8_C8A488
.word 0x00000043, 0x0000000B, kzn_17_SetManyVars, 0x00000000, 0x00B60008, 0x00B60001, 0x00000054, 0x00000000, 0x001000E8, 0x001000E9, 0x001000EA, 0x001000EB, D_80244980_C8A430, 0x00000046, 0x00000001, D_80244688_C8A138, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244A28_C8A4D8
.word 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x0000015C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000003, 0x00000046, 0x00000001, D_80244078_C89B28, 0x00000043, 0x00000002, AddStarPieces, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244A8C_C8A53C
.word 0x43DF8000, 0x00000000, 0x421C0000, 0x43D80000, 0x40A00000, 0x423C0000, 0x43D58000, 0x41A00000, 0x425C0000, 0x43D80000, 0x40A00000, 0x42780000, 0x43DF8000, 0x00000000, 0x428C0000

dlabel D_80244AC8_C8A578
.word 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x000001BF, 0x00000000, 0x00000027, 0x00000043, 0x00000003, SetNpcYaw, 0x00000000, 0x0000010E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00B60007, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244B1C_C8A5CC
.word 0x00000043, 0x00000004, SetEnemyFlagBits, 0x00000000, 0x00400000, 0x00000001, 0x00000043, 0x00000003, func_802CDE68, 0x00000000, 0x0000000D, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0x00000000, 0x000000FA, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00B6000C, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000004, 0xF24A8680, 0xF24A8680, 0x00000000, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000000E1, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetNpcCollisionSize, 0x00000000, 0x00000014, 0x00000018, 0x00000043, 0x00000005, LoadPath, 0x0000001E, D_80244A8C_C8A53C, 0x00000005, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B6000C, 0x00B6000C, 0x00000005, 0x001000F9, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244C8C_C8A73C
.word 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x000001BF, 0x00000000, 0x00000046, 0x00000043, 0x00000003, SetNpcYaw, 0x00000000, 0x0000010E, 0x00000043, 0x00000004, SetEnemyFlagBits, 0x00000000, 0x00400000, 0x00000001, 0x00000043, 0x00000003, func_802CDE68, 0x00000000, 0x0000000D, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0x00000000, 0x000000FA, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00B6000C, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000004, 0xF24A8680, 0xF24A8680, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244D4C_C8A7FC
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C80, 0x0000025D, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001000F7, 0x000000A0, 0x00000028, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000122, 0x00000000, 0x0000001E, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8E80, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60007, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000280, 0x00000050, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60002, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60009, 0x00B60002, 0x00000000, 0x001000F8, 0x00000024, 0x00000002, 0xF5DE0180, 0x0000001F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244EBC_C8A96C
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000020, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60009, 0x00B60002, 0x00000000, 0x001000FC, 0x00000046, 0x00000001, D_80244988_C8A438, 0x00000046, 0x00000001, D_80244A28_C8A4D8, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B6000C, 0x00000005, 0x001000FA, 0x00000046, 0x00000001, D_802449D8_C8A488, 0x00000046, 0x00000001, D_80244A28_C8A4D8, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244F5C_C8AA0C
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80244EBC_C8A96C, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x0000001F, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80244D4C_C8A7FC, 0x00000002, 0x00000000, 0x00000018, 0x00000001, 0x00000020, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000280, 0x00000000, 0x00000050, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60002, 0x00000002, 0x00000000, 0x00000016, 0x00000001, 0x00000020, 0x00000043, 0x00000004, SetNpcCollisionSize, 0x00000000, 0x00000014, 0x00000018, 0x00000044, 0x00000001, D_80244C8C_C8A73C, 0x00000002, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245050_C8AB00
.word 0x00000000, D_802439A0_C89450, 0x00000000, 0xC47A0000, 0x00000000, 0x00510509, D_80244F5C_C8AA0C, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B60001, 0x00B60004, 0x00B60006, 0x00B60006, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00000000, 0x00000000, 0x00000000, 0x001A0000

dlabel D_80245240_C8ACF0
.word 0x00000001, D_80243B8C_C8963C, 0xC3A28000, 0x00000000, 0x43160000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0xFFFFFEBB, 0x00000000, 0x00000096, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFE7A, 0x00000000, 0x00000082, 0x0000010E, 0x00000082, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_80243CC4_C89774, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245620_C8B0D0
.word 0x00000003, D_8024401C_C89ACC, 0xC3E10000, 0x00000000, 0x42C80000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005009B, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00030000, 0xFFFFFE3E, 0x00000000, 0x00000064, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFE3E, 0x00000000, 0x00000064, 0x0000010E, 0x00000082, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004D0003, 0x004D0006, 0x004D0008, 0x004D0008, 0x004D0003, 0x004D0003, 0x004D0013, 0x004D0013, 0x004D000B, 0x004D000A, 0x004D000C, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x004D0003, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80245050_C8AB00, 0x00000000, 0x00000002, D_80245240_C8ACF0, 0x16140001, 0x00000001, D_80245620_C8B0D0, 0x160D0001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245840_C8B2F0
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000001, func_802D2B6C, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000009, 0x00000004, 0x00000001, 0x00000002, 0x00000012, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetPlayerTargetYaw, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, kzn_17_UnkFunc48, 0x00000014, 0x00000012, 0x00000000, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000010E, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, kzn_17_UnkFunc48, 0xFFFFFFEC, 0x00000013, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001000F, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, kzn_17_SpinyTrompHit, 0x00000043, 0x00000007, func_802D2520, 0x0001000F, 0x00000004, 0xF24A8680, 0xF24A8680, 0x00000000, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF9718882, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000007, func_802D2520, 0x0001000F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010030, 0x00000043, 0x00000002, kzn_17_UnkFunc48, 0x00000000, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245AE0_C8B590
.word 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x000001F4, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24AA280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF9718886, 0x00000000, 0x0000000C, 0x00000002, 0xFD050F80, 0x00000226, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F80, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F80, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C81, 0x00000037, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C81, 0x00000043, 0x00000001, kzn_17_UnkFunc46, 0x00000028, 0x00000002, 0xFE363C82, 0x00000037, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245CA8_C8B758
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000001E, 0xF24A7E80, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000004D, 0x00000001, 0x000000EF, 0x0000000F, 0x00000002, 0xF5DE0180, 0x00000020, 0x00000043, 0x00000003, SetGroupEnabled, 0x0000001B, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000001C, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000020, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000006, 0x7FFFFE00, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000001E, 0x00000000, 0x00000024, 0x00000002, 0xF9718885, 0x00000000, 0x00000024, 0x00000002, 0xF9718886, 0x00000000, 0x00000024, 0x00000002, 0xF9718883, 0x00000000, 0x00000024, 0x00000002, 0xF9718882, 0x00000000, 0x00000024, 0x00000002, 0xF9718887, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFFFFFDB9, 0x00000024, 0x00000002, 0xFE363C82, 0x000000A5, 0x00000043, 0x00000005, TranslateGroup, 0x0000001B, 0xFE363C80, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000005, TranslateModel, 0x0000001C, 0xFE363C80, 0xFE363C82, 0x0000001E, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF84060AA, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000045, 0x00000002, D_80245AE0_C8B590, 0xFE363C8A, 0x00000044, 0x00000001, D_80244AC8_C8A578, 0x00000045, 0x00000002, D_80245CA8_C8B758, 0xFD050F8A, 0x00000043, 0x00000002, PlaySound, 0x8000001B, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFDB9, 0x000002EE, 0x0000010E, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000001, kzn_17_UnkFunc46, 0x00000043, 0x00000004, kzn_17_UnkFunc51, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000027, 0x00000002, 0xFD050F80, 0x00000014, 0x00000043, 0x00000005, TranslateGroup, 0x0000001B, 0xFE363C80, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000005, TranslateModel, 0x0000001C, 0xFE363C80, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000006, RotateGroup, 0x0000001B, 0xFE363C83, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x0000001C, 0xFE363C83, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000001, kzn_17_UnkFunc49, 0x00000043, 0x00000005, TranslateModel, 0x0000001C, 0xFE363C85, 0xFE363C86, 0x0000001E, 0x00000043, 0x00000001, kzn_17_UnkFunc50, 0x0000000A, 0x00000002, 0xF9718887, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C83, 0x00000014, 0x0000000C, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xF9718887, 0x00000001, 0x00000003, 0x00000001, 0x0000000C, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xF9718887, 0x00000000, 0x00000004, 0x00000001, 0x0000000C, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF9718885, 0x00000000, 0x0000000D, 0x00000002, 0xFE363C80, 0x000001AE, 0x00000044, 0x00000001, D_80244B1C_C8A5CC, 0x00000024, 0x00000002, 0xF9718885, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF9718886, 0x00000000, 0x0000000D, 0x00000002, 0xFE363C80, 0x00000276, 0x00000049, 0x00000001, 0xFD050F8A, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000006, 0x7FFFFE00, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000006, 0x000001E4, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000042, 0x00000002, 0x00000020, 0x00000020, 0x00000001, 0x0000000A, 0x0000002D, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000020, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000001E, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000014, 0xF24A8680, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A814D, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7C80, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xF9718886, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, kzn_17_UnkFunc47, 0x0000000C, 0x00000002, 0xFE363C84, 0x00000050, 0x0000000A, 0x00000002, 0xF9718883, 0x00000000, 0x00000043, 0x00000001, func_80242D20_C887D0, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000009, 0x00000024, 0x00000002, 0xF9718883, 0x00000001, 0x00000044, 0x00000001, D_80245840_C8B2F0, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000020, 0x00000008, 0x00000001, 0x00000032, 0x00000043, 0x00000002, StopSound, 0x8000001B, 0x00000043, 0x00000003, SetGroupEnabled, 0x0000001B, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000001C, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24BE280, 0x00000024, 0x00000002, 0xF9718887, 0x00000000, 0x00000024, 0x00000002, 0xF9718882, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000
