.include "macro.inc"

.section .data

dlabel D_802A12E0_74D850
.word 0x00000009, 0x00000003, 0x00000009, 0x00000003, 0x00000009, 0x00000003, 0x00000008, 0x00000003, 0x00000007, 0x00000003, 0x00000006, 0x00000002, 0x00000005, 0x00000002, 0x00000004, 0x00000002

dlabel D_802A1320_74D890
.word 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010006, 0x00000005, 0x00000001, 0x00000005, 0x00000043, 0x00000003, CheckButtonPress, 0x00008000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802A139C_74D90C
.word 0x00000043, 0x00000002, SetGoalToFirstTarget, 0xFFFFFF81, 0x00000043, 0x00000005, GetGoalPos, 0xFFFFFF81, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x00000028, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, GetGoalPos, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000028, 0x00000002, 0xFE363C83, 0xF24B9280, 0x0000000C, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000001A, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A8E80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000003, CancelablePlayerRunToGoal, 0x00000000, 0xFE363C80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000046, 0x00000001, D_802A1320_74D890, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010006, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802A1510_74DA80
.word 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, GetGoalPos, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x0000000D, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000028, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000012, 0x00000000, 0x00000028, 0x00000002, 0xFE363C87, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000013, 0x00000000, 0x00000028, 0x00000002, 0xFE363C86, 0x00000014, 0x0000002F, 0x00000002, 0xFE363C86, 0xF24AA4DB, 0x0000002C, 0x00000002, 0xFE363C86, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802A15F8_74DB68
.word 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, GetGoalPos, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x0000000D, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000028, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000012, 0x00000000, 0x00000028, 0x00000002, 0xFE363C87, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000013, 0x00000000, 0x00000028, 0x00000002, 0xFE363C86, 0x00000014, 0x0000002F, 0x00000002, 0xFE363C86, 0xF24AD480, 0x0000002C, 0x00000002, 0xFE363C86, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802A16E0_74DC50
.word 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000005, GetGoalPos, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x0000000D, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000028, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000012, 0x00000000, 0x00000028, 0x00000002, 0xFE363C87, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C87, 0x00000013, 0x00000000, 0x00000028, 0x00000002, 0xFE363C86, 0x00000014, 0x0000002F, 0x00000002, 0xFE363C86, 0xF24AC280, 0x0000002C, 0x00000002, 0xFE363C86, 0x00000016, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C86, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000100, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000003, 0x00000043, 0x00000001, func_802693F0, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000005, GetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000028, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00010009, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7FB4, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000001, battle_move_jump_charge_0_UnkMoveFunc1, 0x00000043, 0x00000004, func_80273444, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0xFFFFFFEC, 0x00000000, 0x00000000, 0x00000043, 0x00000004, func_80273444, 0x00000006, 0x00000000, 0x00000002, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000100, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000003, 0x00000043, 0x00000001, func_802693F0, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x00000032, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00010009, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7DB4, 0x00000043, 0x00000001, battle_move_jump_charge_0_UnkMoveFunc1, 0x00000043, 0x00000004, func_80273444, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0xFFFFFFE2, 0x00000000, 0x00000000, 0x00000043, 0x00000004, func_80273444, 0x00000006, 0x00000000, 0x00000002, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000100, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000001D, 0x00000043, 0x00000001, func_802693F0, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x00000028, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00010009, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000001, battle_move_jump_charge_0_UnkMoveFunc1, 0x00000043, 0x00000004, func_80273444, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0xFFFFFFEC, 0x00000000, 0x00000000, 0x00000043, 0x00000004, func_80273444, 0x00000006, 0x00000000, 0x00000002, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000100, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000003, 0x00000043, 0x00000001, func_802693F0, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x0000003C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00010009, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7DB4, 0x00000043, 0x00000001, battle_move_jump_charge_0_UnkMoveFunc1, 0x00000043, 0x00000004, func_80273444, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0xFFFFFFEC, 0x00000000, 0x00000000, 0x00000043, 0x00000004, func_80273444, 0x00000006, 0x00000000, 0x00000002, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000100, 0x00000000, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000003, 0x00000043, 0x00000001, func_802693F0, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000005, GetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000003C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010017, 0x00010017, 0x00010009, 0x00000043, 0x00000001, battle_move_jump_charge_0_UnkMoveFunc1, 0x00000043, 0x00000004, func_80273444, 0xFE363C80, 0x00000000, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x00000004, 0xF24A7E80, 0x00000059, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0xFFFFFFE2, 0x00000000, 0x00000000, 0x00000043, 0x00000004, func_80273444, 0x00000008, 0x00000000, 0x00000002, 0x00000058, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x00000004, 0xF24A7E80, 0x00000059, 0x00000000, 0x00000043, 0x00000005, AddGoalPos, 0x00000000, 0xFFFFFFEC, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_80273444, 0x00000006, 0x00000000, 0x00000002, 0x00000058, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x00000004, 0xF24A7E80, 0x00000059, 0x00000000, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000004, func_80273444, 0x00000004, 0x00000000, 0x00000002, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0001000C, 0x00000043, 0x00000001, PlayerLandJump, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x0001000C, 0x00000008, 0x00000001, 0x00000002, 0x00000058, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000001, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000059, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000162, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010030, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010031, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000100, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000003, 0x00000043, 0x00000001, func_802693F0, 0x00000043, 0x00000002, EnablePlayerBlur, 0xFFFFFFFF, 0x00000043, 0x00000001, func_80276EFC, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, LoadActionCommand, 0x00000001, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A139C_74D90C, 0x00000046, 0x00000001, D_802A1510_74DA80, 0x00000043, 0x00000003, func_802A9120_421B10, 0xFE363C8A, 0x00000003, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000022, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00030000, 0x00000043, 0x00000003, func_80274A18, 0xFE363C8A, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, LoadActionCommand, 0x00000001, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A139C_74D90C, 0x00000043, 0x00000001, InitTargetIterator, 0x00000046, 0x00000001, D_802A15F8_74DB68, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C8B, 0x0000000E, 0x00000027, 0x00000002, 0xFE363C8B, 0xFFFFFFFD, 0x00000043, 0x00000003, func_802A9120_421B10, 0xFE363C8B, 0x00000003, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000025, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x0001000A, 0x0001000B, 0x00000043, 0x00000003, func_802752AC, 0xFE363C8A, 0x00000000, 0x00000008, 0x00000001, 0x00000007, 0x00000043, 0x00000002, DidActionSucceed, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000019, 0x00000001, 0x00000000, 0x00000043, 0x00000003, func_802752AC, 0x00000003, 0x00000001, 0x0000001C, 0x00000000, 0x00000043, 0x00000003, func_802752AC, 0x00000005, 0x00000001, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, LoadActionCommand, 0x00000001, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000046, 0x00000001, D_802A139C_74D90C, 0x00000046, 0x00000001, D_802A16E0_74DC50, 0x00000043, 0x00000002, func_8026919C, D_802A12E0_74D850, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C8A, 0x00000028, 0x00000002, 0xFE363C8B, 0x00000004, 0x00000027, 0x00000002, 0xFE363C8B, 0xFFFFFFFD, 0x00000043, 0x00000003, func_802A9120_421B10, 0xFE363C8B, 0x00000003, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000026, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000000, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00080000, 0x00030000, 0x00000043, 0x00000003, func_80275F00, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000001, CloseActionCommandInfo, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000043, 0x00000002, DidActionSucceed, 0xFE363C80, 0x0000000D, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00030000, 0x00000043, 0x00000005, SetActorRotation, 0xFFFFFF81, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetActorDispOffset, 0xFFFFFF81, 0x00000000, 0xFFFFFFFE, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetActorDispOffset, 0xFFFFFF81, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, LoadActionCommand, 0x00000001, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000043, 0x00000003, func_802A9120_421B10, 0x0000000D, 0x00000003, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000027, 0x00000043, 0x00000003, func_80275F00, 0x0000000F, 0x00000002, 0x00000004, 0x00000001, 0x0000000A, 0x00000012, 0x00000000, 0x00000043, 0x00000002, LoadActionCommand, 0x00000001, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000043, 0x00000003, func_802A9120_421B10, 0x00000002, 0x00000003, 0x00000043, 0x00000003, func_80275F00, 0x00000004, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000020, 0x00000008, 0x00000001, 0x0000000A, 0x00000058, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000156, 0x00000008, 0x00000001, 0x00000008, 0x00000059, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010020, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, func_802A120C_74D77C, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7F4D, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000005, func_802A120C_74D77C, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7DB4, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000002, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000005, 0x00000043, 0x00000001, battle_move_jump_charge_0_IsJumpMaxCharged, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C81, 0x00000019, 0x00000027, 0x00000002, 0xFE363C82, 0x00000005, 0x00000043, 0x00000004, func_802A1108_74D678, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x0000208F, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000000, 0x00000160, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00010009, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_80273444, 0x00000014, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000043, 0x00000003, UseIdleAnimation, 0x00000000, 0x00000001, 0x00000043, 0x00000004, ShowVariableMessageBox, 0x00000006, 0x0000003C, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, ShowMessageBox, 0x00000008, 0x0000003C, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, IsMessageBoxDisplayed, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, UseIdleAnimation, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
