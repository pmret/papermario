.include "macro.inc"

.section .data

dlabel D_80241AE0_DE3F70
.word 0x40000000, 0x0000003C, 0x0000000F, 0x42C80000, 0x41F00000, 0x00000004, 0x40800000, 0x00000006, 0x00000001, 0x430C0000, 0x41F00000, 0x00000001

dlabel D_80241B10_DE3FA0
.word 0x00000043, 0x00000002, omo_13_ShyGuyWanderAI_Main, D_80241AE0_DE3F70, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B30_DE3FC0
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_80241B10_DE3FA0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001

dlabel D_80241B5C_DE3FEC
.word 0x3FD9999A, 0x00000050, 0x00000001, 0x42C80000, 0x00000000, 0x00000004, 0x40900000, 0x00000014, 0x00000001, 0x430C0000, 0x00000000, 0x00000001

dlabel D_80241B8C_DE401C
.word 0x00000043, 0x00000002, omo_13_GrooveGuyAI_Main, D_80241B5C_DE3FEC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241BAC_DE403C
.word 0x00000000, 0x00180016, 0x00000000, 0x00000000, D_80241B8C_DE401C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000F0001

dlabel D_80241BD8_DE4068
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, 0x00000000, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001

dlabel omo_13_ItemChoice_HasSelectedItem
.word 0x00000000

dlabel omo_13_ItemChoice_SelectedItemID
.word 0x00000000

dlabel D_80241C0C_DE409C
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowConsumableChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, omo_13_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, omo_13_ItemChoice_SaveSelected, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D40_DE41D0
.word 0x00000043, 0x00000002, func_80240F8C_DE341C, 0xFE363C80, 0x0000004E, 0x00000006, D_80241C0C_DE409C, 0x00000010, 0x00000000, omo_13_80243220, 0x00000000, 0x00000001, 0x00000043, 0x00000002, omo_13_ItemChoice_WaitForSelection, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D90_DE4220
.word 0x000000D0, 0xFFFFFFFF

dlabel D_80241D98_DE4228
.word 0x0000000A, 0x00000002, 0xF8405FD1, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x003B0515, 0x003B0515, 0x00000005, 0x000F004D, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8E80, 0x0000000A, 0xF24F2A80, 0xF24AB680, 0xF24A5C80, 0x00000043, 0x00000003, FindItem, 0x000000D0, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080011, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000057, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0046, 0x00000043, 0x00000005, EndSpeech, 0xFFFFFFFF, 0x003B0513, 0x003B0501, 0x00000000, 0x00000043, 0x00000002, ShowChoice, 0x001E0044, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0048, 0x00000012, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0047, 0x00000043, 0x00000002, ShowChoice, 0x001E0044, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0048, 0x00000012, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0049, 0x00000043, 0x00000004, SetNpcVar, 0xFFFFFFFF, 0x00000000, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F004A, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000262, 0x00000000, 0x00000043, 0x0000000A, ShowEmote, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x0000001E, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, EndSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0008001E, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010029, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000005, EndSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80241D90_DE4220, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000046, 0x00000001, D_80241D40_DE41D0, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F004B, 0x00000043, 0x00000002, ShowChoice, 0x001E0044, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0048, 0x00000012, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0047, 0x00000043, 0x00000002, ShowChoice, 0x001E0044, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0048, 0x00000012, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F0049, 0x00000043, 0x00000004, SetNpcVar, 0xFFFFFFFF, 0x00000000, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x003B0511, 0x003B0501, 0x00000000, 0x000F004C, 0x00000008, 0x00000001, 0x00000014, 0x00000024, 0x00000002, 0xF8405FD1, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000001F, 0x7FFFFE00, 0x00000043, 0x00000004, SetNpcVar, 0xFFFFFFFF, 0x00000000, 0x00000002, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8E80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802422A8_DE4738
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80241028_DE34B8, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000002, StartBossBattle, 0x00000003, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x003B0502, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C82, 0xFFFFFFC4, 0x0000000C, 0x00000002, 0xFE363C80, 0x0000006E, 0x00000027, 0x00000002, 0xFE363C80, 0x0000003C, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFC4, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000C, 0x00000002, 0xFE363C80, 0x0000006E, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFC4, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x0000003C, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8680, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFE363C80, 0xFFFFFF9C, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x003B0515, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000000, 0x00000003, 0x00000001, 0x00000009, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000009, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242538_DE49C8
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF8405FD1, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000001F, 0x7FFFFE00, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802425EC_DE4A7C
.word 0x0000000A, 0x00000002, 0xF8405FD1, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802422A8_DE4738, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241D98_DE4228, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80242538_DE49C8, 0x00000012, 0x00000000, 0x00000043, 0x00000002, RemoveEncounter, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242668_DE4AF8
.word 0x00000000, D_80241BD8_DE4068, 0x42DC0000, 0x00000000, 0xC1A00000, 0x00640D01, D_802425EC_DE4A7C, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0501, 0x003B0502, 0x003B0503, 0x003B0502, 0x003B0501, 0x003B0501, 0x003B050C, 0x003B050C, 0x003B0515, 0x003B0512, 0x003B0511, 0x003B0510, 0x003B0505, 0x003B0501, 0x003B0501, 0x003B0501, 0x00000000, 0x00000000, 0x00000000, 0x001A00BA

dlabel D_80242858_DE4CE8
.word 0x00000001, D_80241B30_DE3FC0, 0x43960000, 0x00000000, 0x42480000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005009A, 0x00020000, 0x008C0002, 0x00000084, 0x00020000, 0x008D0002, 0x0000008F, 0x00020000, 0x00900002, 0x00000098, 0x00020000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x0000012C, 0x00000000, 0x00000032, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000012C, 0x00000000, 0x00000032, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0401, 0x003B0402, 0x003B0403, 0x003B0403, 0x003B0401, 0x003B0401, 0x003B040C, 0x003B040C, 0x003B0415, 0x003B0412, 0x003B0411, 0x003B0410, 0x003B0405, 0x003B0401, 0x003B0401, 0x003B0401, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242A48_DE4ED8
.word 0x00000002, D_80241BAC_DE403C, 0xC35E0000, 0x00000000, 0x420C0000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80050096, 0x00050000, 0x00980005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0004, 0x33322666, 0x33320004, 0x33323FFF, 0x33320004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0xFFFFFF22, 0x00000000, 0x00000023, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFF22, 0x00000000, 0x00000023, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003C0001, 0x003C0003, 0x003C0004, 0x003C0003, 0x003C0001, 0x003C0001, 0x003C0008, 0x003C0008, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242668_DE4AF8, 0x102C0001, 0x00000001, D_80242858_DE4CE8, 0x10030001, 0x00000001, D_80242A48_DE4ED8, 0x10250001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
