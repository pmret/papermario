.include "macro.inc"

.section .data

glabel D_802A1320_75E8F0
.word 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, GetGoalPos, 0xFFFFFF81, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x00000020, 0x00000043, 0x00000005, SetGoalPos, 0xFFFFFF81, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000001A, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A8E80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A13FC_75E9CC
.word 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFFFFFFDF, 0x00000000, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000001A, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A8E80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A1474_75EA44
.word 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000D, 0x00000006, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000D, 0x00000014, 0x00000001, 0xFE363C81, 0x00000018, 0x00000001, 0x00000003, 0x00000008, 0x00000001, 0x00000004, 0x00000018, 0x00000001, 0x00000005, 0x00000008, 0x00000001, 0x00000003, 0x00000018, 0x00000001, 0x00000007, 0x00000008, 0x00000001, 0x00000002, 0x00000018, 0x00000001, 0x00000009, 0x00000008, 0x00000001, 0x00000001, 0x00000018, 0x00000001, 0x0000000B, 0x00000008, 0x00000001, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A15F8_75EBC8
.word 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030014, 0x00000006, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030014, 0x00000014, 0x00000001, 0xFE363C81, 0x00000018, 0x00000001, 0x00000003, 0x00000008, 0x00000001, 0x00000004, 0x00000018, 0x00000001, 0x00000005, 0x00000008, 0x00000001, 0x00000003, 0x00000018, 0x00000001, 0x00000007, 0x00000008, 0x00000001, 0x00000002, 0x00000018, 0x00000001, 0x00000009, 0x00000008, 0x00000001, 0x00000001, 0x00000018, 0x00000001, 0x0000000B, 0x00000008, 0x00000001, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A177C_75ED4C
.word 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001B, 0x00000006, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001B, 0x00000014, 0x00000001, 0xFE363C81, 0x00000018, 0x00000001, 0x00000003, 0x00000008, 0x00000001, 0x00000004, 0x00000018, 0x00000001, 0x00000005, 0x00000008, 0x00000001, 0x00000003, 0x00000018, 0x00000001, 0x00000007, 0x00000008, 0x00000001, 0x00000002, 0x00000018, 0x00000001, 0x00000009, 0x00000008, 0x00000001, 0x00000001, 0x00000018, 0x00000001, 0x0000000B, 0x00000008, 0x00000001, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002B, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000008, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010B, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000E, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0x00000024, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000F, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionResult, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030010, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030011, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030012, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A1B1C_75F0EC
.word 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000004, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000005, 0x00000043, 0x00000001, func_802693F0, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000001, func_802693F0, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A1CD4_75F2A4
.word 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000001D, 0x00000043, 0x00000001, func_802693F0, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A1DB0_75F380
.word 0x00000043, 0x00000002, LoadActionCommand, 0x00000002, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A1320_75E8F0, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00000001, D_802A1474_75EA44, 0x00000043, 0x00000007, PlayerTestEnemy, 0xFE363C80, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000010, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002B, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000008, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010B, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000E, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsBerserkerEquipped, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000F, 0x00000043, 0x00000002, GetActionCommandMode, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsRightOnEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000002D, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8D, 0x00000006, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C8D, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionResult, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030010, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetActionCommandMode, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000002, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionSuccess, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C81, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000F, 0x00000028, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000008, 0x00000001, 0xFE363C81, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030010, 0x00000008, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetActionCommandMode, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000002, SetActionCommandMode, 0x00000003, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000002, GetActionCommandMode, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000002, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030011, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002115, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030012, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002118, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A2270_75F840
.word 0x00000043, 0x00000002, LoadActionCommand, 0x00000002, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A1320_75E8F0, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00000001, D_802A15F8_75EBC8, 0x00000043, 0x00000007, PlayerTestEnemy, 0xFE363C80, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000010, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002B, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000008, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010B, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030015, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsBerserkerEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030016, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsRightOnEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000002D, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8D, 0x00000006, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C8D, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionResult, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030017, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionSuccess, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C81, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030016, 0x00000028, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000008, 0x00000001, 0xFE363C81, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030017, 0x00000008, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030018, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002116, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030019, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002119, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, LoadActionCommand, 0x00000002, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A1320_75E8F0, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00000001, D_802A177C_75ED4C, 0x00000043, 0x00000007, PlayerTestEnemy, 0xFE363C80, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000010, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002B, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000008, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010B, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001C, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsBerserkerEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001D, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsRightOnEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000002D, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8D, 0x00000006, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C8D, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionResult, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001E, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionSuccess, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C81, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001D, 0x00000028, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000008, 0x00000001, 0xFE363C81, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001E, 0x00000008, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001F, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002117, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030020, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000211A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, ChooseNextTarget, 0x0000000A, 0xFE363C80, 0x00000043, 0x00000002, LoadActionCommand, 0x00000002, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A13FC_75E9CC, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00000001, D_802A1474_75EA44, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002B, 0x00000043, 0x00000002, AddBattleCamZoom, 0x00000050, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010B, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000E, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003000F, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsRightOnEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000002D, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8D, 0x00000006, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C8D, 0x00000003, 0x00000043, 0x00000002, SetActionResult, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionResult, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030010, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionSuccess, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002115, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030011, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030012, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002118, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, ChooseNextTarget, 0x0000000A, 0xFE363C80, 0x00000043, 0x00000002, LoadActionCommand, 0x00000002, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A13FC_75E9CC, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00000001, D_802A15F8_75EBC8, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002B, 0x00000043, 0x00000002, AddBattleCamZoom, 0x00000050, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010B, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030015, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030016, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsRightOnEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000002D, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8D, 0x00000006, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C8D, 0x00000003, 0x00000005, 0x00000001, 0x0000003C, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionSuccess, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002116, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030018, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030019, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002119, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, ChooseNextTarget, 0x0000000A, 0xFE363C80, 0x00000043, 0x00000002, LoadActionCommand, 0x00000002, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A13FC_75E9CC, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00000001, D_802A177C_75ED4C, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002B, 0x00000043, 0x00000002, AddBattleCamZoom, 0x00000050, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010B, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001C, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001D, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsRightOnEquipped, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000002D, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C8D, 0x00000006, 0x00000043, 0x00000004, func_802A9258_422258, 0x00000000, 0xFE363C8D, 0x00000003, 0x00000005, 0x00000001, 0x0000003C, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, CheckButtonDown, 0x00040000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetActionSuccess, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00002117, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0003001F, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030020, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000211A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C81, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8D, 0x00000041, 0x00000024, 0x00000002, 0xFE363C8E, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8F, 0x00000002, 0x00000046, 0x00000001, D_802A33C8_760998, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8D, 0x00000041, 0x00000024, 0x00000002, 0xFE363C8E, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8F, 0x00000004, 0x00000046, 0x00000001, D_802A33C8_760998, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8D, 0x00000041, 0x00000024, 0x00000002, 0xFE363C8E, 0x00000004, 0x00000024, 0x00000002, 0xFE363C8F, 0x00000006, 0x00000046, 0x00000001, D_802A33C8_760998, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A33C8_760998
.word 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C81, 0x00000016, 0x00000001, 0x00000000, 0x00000046, 0x00000001, D_802A1DB0_75F380, 0x00000016, 0x00000001, 0x00000001, 0x00000046, 0x00000001, D_802A2270_75F840, 0x00000016, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_802A1DB0_75F380, 0x00000023, 0x00000000, 0x00000043, 0x00000007, PlayerTestEnemy, 0xFE363C80, 0x00000040, 0x00000019, 0x00000000, 0xFE363C89, 0x00000010, 0x00000043, 0x00000002, DidActionSucceed, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000019, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C81, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, StartRumble, 0x00000007, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x0000000A, 0xF24A7FB4, 0x00000057, 0x00000000, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, StartRumble, 0x00000008, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x0000000A, 0xF24A80E7, 0x00000057, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, StartRumble, 0x00000009, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x0000000A, 0xF24A821A, 0x00000057, 0x00000000, 0x00000023, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C81, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, StartRumble, 0x00000007, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x00000002, 0xF24A7FB4, 0x00000057, 0x00000000, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, StartRumble, 0x00000008, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x00000002, 0xF24A80E7, 0x00000057, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, StartRumble, 0x00000009, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x00000002, 0xF24A821A, 0x00000057, 0x00000000, 0x00000023, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000002C, 0x00000043, 0x00000007, PlayerTestEnemy, 0xFE363C80, 0x00000040, 0x00000019, 0x00000000, 0x00000000, 0x00000010, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000006, 0x00000046, 0x00000001, D_802A1CD4_75F2A4, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000043, 0x00000002, DidActionSucceed, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000019, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C81, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x000000E9, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010E, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010E, 0x00000023, 0x00000000, 0x00000043, 0x00000007, PlayerDamageEnemy, 0xFE363C80, 0x00000040, 0x00000019, 0x00000000, 0xFE363C8F, 0x00000030, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x0000001C, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C81, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x000000E9, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010E, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000010E, 0x00000023, 0x00000000, 0x00000043, 0x00000007, PlayerDamageEnemy, 0xFE363C80, 0x00000040, 0x00000019, 0x00000000, 0xFE363C8E, 0x00000020, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000023, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000003, 0x00000046, 0x00000001, D_802A1B1C_75F0EC, 0x00000020, 0x00000000, 0x0000001D, 0x00000001, 0x00000000, 0x0000001D, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_802A1CD4_75F2A4, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C81, 0x00000016, 0x00000001, 0x00000000, 0x00000046, 0x00000001, D_802A39C8_760F98, 0x00000016, 0x00000001, 0x00000001, 0x00000046, 0x00000001, D_802A3CF4_7612C4, 0x00000016, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_802A4020_7615F0, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A39C8_760F98
.word 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000020, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000057, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00050004, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, battle_move_hammer_charge_2_UnkMoveFunc3, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7F4D, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000005, battle_move_hammer_charge_2_UnkMoveFunc3, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7DB4, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000002, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000005, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsHammerMaxCharged, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C81, 0x00000023, 0x00000043, 0x00000004, func_802A10C8_75E698, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000208F, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000160, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00050005, 0x00050005, 0x00050005, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_80273444, 0x00000014, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000043, 0x00000001, func_802A12FC_75E8CC, 0x00000043, 0x00000004, ShowVariableMessageBox, 0xFE363C80, 0x0000003C, 0x00000003, 0x00000012, 0x00000000, 0x00000043, 0x00000003, ShowMessageBox, 0x00000008, 0x0000003C, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, IsMessageBoxDisplayed, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A3CF4_7612C4
.word 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000020, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000057, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00050006, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, battle_move_hammer_charge_2_UnkMoveFunc3, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7F4D, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000005, battle_move_hammer_charge_2_UnkMoveFunc3, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7DB4, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000002, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000005, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsHammerMaxCharged, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C81, 0x00000023, 0x00000043, 0x00000004, func_802A10C8_75E698, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000208F, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000160, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00050007, 0x00050007, 0x00050007, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_80273444, 0x00000014, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000043, 0x00000001, func_802A12FC_75E8CC, 0x00000043, 0x00000004, ShowVariableMessageBox, 0xFE363C80, 0x0000003C, 0x00000003, 0x00000012, 0x00000000, 0x00000043, 0x00000003, ShowMessageBox, 0x00000008, 0x0000003C, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, IsMessageBoxDisplayed, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802A4020_7615F0
.word 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000020, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000057, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00050008, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, battle_move_hammer_charge_2_UnkMoveFunc3, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7F4D, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000005, battle_move_hammer_charge_2_UnkMoveFunc3, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7DB4, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000002, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000005, 0x00000043, 0x00000001, battle_move_hammer_charge_2_IsHammerMaxCharged, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C81, 0x00000023, 0x00000043, 0x00000004, func_802A10C8_75E698, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000208F, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000160, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00050009, 0x00050009, 0x00050009, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_80273444, 0x00000014, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000043, 0x00000001, func_802A12FC_75E8CC, 0x00000043, 0x00000004, ShowVariableMessageBox, 0xFE363C80, 0x0000003C, 0x00000003, 0x00000012, 0x00000000, 0x00000043, 0x00000003, ShowMessageBox, 0x00000008, 0x0000003C, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, IsMessageBoxDisplayed, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
