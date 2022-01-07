.include "macro.inc"

.section .data

dlabel D_8023A1D0_70DEE0
.word 0x00000001, 0x00100002, 0x0000000D, 0x00100008, 0x00000012, 0x00100000, 0x00000000

dlabel D_8023A1EC_70DEFC
.word 0x00000001, 0x00100014, 0x00000000

dlabel D_8023A1F8_70DF08
.word 0x00000001, 0x00000000, 0x00000000

dlabel D_8023A204_70DF14
.word 0x00000001, 0x00000064, 0x00000002, 0x00000064, 0x00000006, 0x00000064, 0x00000009, 0x00000064, 0x00000007, 0x00000064, 0x00000004, 0x00000064, 0x00000003, 0x00000064, 0x0000000B, 0x00000064, 0x00000005, 0x00000064, 0x0000000A, 0x00000064, 0x00000008, 0x00000064, 0x0000001F, 0x00000000, 0x00000020, 0x00000000, 0x00000025, 0x00000000, 0x00000022, 0x00000000, 0x00000024, 0x00000000, 0x00000023, 0x00000000, 0x00000021, 0x00000000, 0x00000026, 0x00000000, 0x00000027, 0x00000000, 0x00000029, 0x00000000, 0x00000000

dlabel D_8023A2B0_70DFC0
.word 0x00000000, 0x01000000, 0x0C1E00FF, D_8023A1D0_70DEE0, D_8023A1F8_70DF08, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00100001, 0x02000000, 0x000000FF, D_8023A1EC_70DEFC, D_8023A1F8_70DF08, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000200, 0x00760063, 0x00020000, D_8023A2B0_70DFC0, D_8023A320_70E030, D_8023A204_70DF14, 0x00000000, 0x00045000, 0x2C280000, 0xF61E0D1F

dlabel D_8023A320_70E030
.word 0x00000043, 0x00000003, BindTakeTurn, 0xFFFFFF81, D_8023A6FC_70E40C, 0x00000043, 0x00000003, BindIdle, 0xFFFFFF81, D_8023A380_70E090, 0x00000043, 0x00000003, BindHandleEvent, 0xFFFFFF81, D_8023A390_70E0A0, 0x00000043, 0x00000003, BindNextTurn, 0xFFFFFF81, D_8023A8DC_70E5EC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A380_70E090
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A390_70E0A0
.word 0x00000043, 0x00000003, UseIdleAnimation, 0x00000100, 0x00000000, 0x00000043, 0x00000001, CloseActionCommandInfo, 0x00000043, 0x00000003, GetLastEvent, 0x00000100, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000009, 0x0000001D, 0x00000001, 0x0000000A, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000025, 0x00000002, 0xFE363C82, 0x0010000A, 0x00000046, 0x00000001, D_802976E8, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000046, 0x00000001, D_80296014, 0x00000020, 0x00000000, 0x0000001D, 0x00000001, 0x00000017, 0x0000001D, 0x00000001, 0x00000019, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x0000208C, 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000046, 0x00000001, D_80297814, 0x00000020, 0x00000000, 0x00000016, 0x00000001, 0x0000002A, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000025, 0x00000002, 0xFE363C82, 0x00000014, 0x00000046, 0x00000001, D_80294FE4, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000046, 0x00000001, D_80296014, 0x00000016, 0x00000001, 0x0000002C, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000C, 0x00000024, 0x00000002, 0xFE363C82, 0x00000014, 0x00000025, 0x00000002, 0xFE363C83, 0x0010000D, 0x00000046, 0x00000001, D_80294C68, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000046, 0x00000001, D_80296014, 0x00000016, 0x00000001, 0x0000000E, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000C, 0x00000025, 0x00000002, 0xFE363C82, 0x0010000D, 0x00000046, 0x00000001, D_8029621C, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000046, 0x00000001, D_80296014, 0x00000016, 0x00000001, 0x0000002F, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000024, 0x00000002, 0xFE363C82, 0x00000014, 0x00000046, 0x00000001, D_80295744, 0x00000016, 0x00000001, 0x00000033, 0x00000025, 0x00000002, 0xFE363C81, 0x0010000A, 0x00000046, 0x00000001, D_80296014, 0x00000016, 0x00000001, 0x00000034, 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x00100002, 0x00000025, 0x00000002, 0xFE363C82, 0x00100003, 0x00000024, 0x00000002, 0xFE363C83, 0x0000000A, 0x00000046, 0x00000001, D_80295EC4, 0x0000001D, 0x00000001, 0x00000018, 0x0000001D, 0x00000001, 0x0000001A, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x0000208C, 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x0010001A, 0x00000046, 0x00000001, D_80297814, 0x00000008, 0x00000001, 0x0000000A, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000003, UseIdleAnimation, 0x00000100, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A6FC_70E40C
.word 0x00000043, 0x00000002, GetBattlePhase, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000046, 0x00000001, D_8023A8EC_70E5FC, 0x00000016, 0x00000001, 0x00000005, 0x00000046, 0x00000001, D_8023A790_70E4A0, 0x00000016, 0x00000001, 0x00000003, 0x00000046, 0x00000001, D_8023A7EC_70E4FC, 0x00000016, 0x00000001, 0x00000007, 0x00000046, 0x00000001, D_8023A828_70E538, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A790_70E4A0
.word 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x00100007, 0x00000025, 0x00000002, 0xFE363C82, 0x00100002, 0x00000025, 0x00000002, 0xFE363C83, 0x00100002, 0x00000046, 0x00000001, D_80294720, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A7EC_70E4FC
.word 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x00100003, 0x00000046, 0x00000001, D_80294AFC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A828_70E538
.word 0x00000043, 0x00000003, UseIdleAnimation, 0x00000100, 0x00000000, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000003, SetActorSpeed, 0x00000100, 0xF24A9280, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100003, 0x00000043, 0x00000003, SetActorYaw, 0x00000100, 0x00000000, 0x00000043, 0x00000003, RunToGoal, 0x00000100, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100002, 0x00000043, 0x00000003, UseIdleAnimation, 0x00000100, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A8DC_70E5EC
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023A8EC_70E5FC
.word 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, func_802694A4, 0x00000001, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000008, 0x00000043, 0x00000001, LoadStarPowerScript, 0x00000046, 0x00000001, 0xFE363C80, 0x00000002, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C82, 0x00000016, 0x00000001, 0x000000AD, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00004000, 0x00000000, 0x00000046, 0x00000001, D_8023AB84_70E894, 0x00000016, 0x00000001, 0x000000AE, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00004000, 0x00000000, 0x00000046, 0x00000001, D_8023AB84_70E894, 0x00000016, 0x00000001, 0x000000AF, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00004000, 0x00000000, 0x00000046, 0x00000001, D_8023AB84_70E894, 0x00000016, 0x00000001, 0x000000B0, 0x00000046, 0x00000001, D_8023B45C_70F16C, 0x00000016, 0x00000001, 0x000000B1, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00004000, 0x00000000, 0x00000046, 0x00000001, D_8023CC64_710974, 0x00000016, 0x00000001, 0x000000B2, 0x00000046, 0x00000001, D_8023CCC4_7109D4, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023AA70_70E780
.word 0x00000043, 0x00000001, func_80280818, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000004, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100003, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x0000000F, 0x00000000, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100002, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023AAF8_70E808
.word 0x00000043, 0x00000001, func_80280818, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000033, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100003, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x0000000F, 0x00000000, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100002, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023AB80_70E890
.word 0x8029370C

dlabel D_8023AB84_70E894
.word 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80238000_70BD10, 0x00000057, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100003, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000028, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000005, SetGoalPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x0000001E, 0x00000000, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100001, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000100, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000013, 0x00000043, 0x00000004, SetBattleCamTarget, 0x0000002F, 0x0000002E, 0x0000000C, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000007, 0x00000043, 0x00000002, SetBattleCamZoom, 0x000001A0, 0x00000043, 0x00000002, MoveBattleCamOver, 0x0000001E, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000003, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C82, 0x00000005, 0x00000043, 0x00000006, SetPartPos, 0x00000100, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, SetPartFlagBits, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000002, 0x00100014, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x0010000F, 0x00000005, 0x00000001, 0x00000004, 0x00000027, 0x00000002, 0xFE363C81, 0x00000006, 0x00000043, 0x00000006, SetPartPos, 0x00000100, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000008, 0x00000027, 0x00000002, 0xFE363C81, 0x00000028, 0x00000027, 0x00000002, 0xFE363C82, 0x00000005, 0x00000043, 0x0000000F, PlayEffect, 0x0000006B, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7E80, 0x00000050, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetActorVar, 0x00000100, 0x00000000, 0x00000001, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000028, 0x00000043, 0x00000005, SetActorDispOffset, 0x00000100, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, SetPartDispOffset, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, SetActorDispOffset, 0x00000100, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000043, 0x00000006, SetPartDispOffset, 0x00000100, 0x00000002, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetActorVar, 0x00000100, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetActorDispOffset, 0x00000100, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000006, SetPartDispOffset, 0x00000100, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000100, 0x00000043, 0x00000001, func_8023803C_70BD4C, 0x00000043, 0x00000004, SetActorVar, 0x00000100, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100012, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000007, PartnerTestEnemy, 0xFE363C80, 0x00000000, 0x00000014, 0x00000000, 0x00000002, 0x00000010, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000006, 0x00000024, 0x00000002, 0xFE363C8F, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x0000201B, 0x00000014, 0x00000001, 0xFE363C8F, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000002, 0x00100015, 0x00000043, 0x00000004, SetPartJumpGravity, 0x00000100, 0x00000002, 0xF24A8080, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C87, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C89, 0x00000043, 0x00000007, JumpPartTo, 0x00000100, 0x00000002, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000014, 0x00000043, 0x00000003, LandJumpPart, 0x00000100, 0x00000002, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000002, 0x00100015, 0x00000043, 0x00000004, SetPartJumpGravity, 0x00000100, 0x00000002, 0xF24A8080, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C87, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C89, 0x00000043, 0x00000007, JumpPartTo, 0x00000100, 0x00000002, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000014, 0x00000043, 0x00000003, LandJumpPart, 0x00000100, 0x00000002, 0x0000001C, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000002, 0x00100015, 0x00000043, 0x00000005, GetGoalPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetPartJumpGravity, 0x00000100, 0x00000002, 0xF24A8080, 0x00000043, 0x00000007, JumpPartTo, 0x00000100, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000023, 0x00000000, 0x00000056, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000032, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000004, SetPartJumpGravity, 0x00000100, 0x00000002, 0xF24A8080, 0x00000043, 0x00000007, JumpPartTo, 0x00000100, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000043, 0x00000005, SetPartFlagBits, 0x00000100, 0x00000002, 0x00000001, 0x00000001, 0x00000057, 0x00000000, 0x00000043, 0x00000004, GetMenuSelection, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000001, 0xFE363C82, 0x00000016, 0x00000001, 0x000000AD, 0x00000024, 0x00000002, 0xFE363C8E, 0x00000003, 0x00000016, 0x00000001, 0x000000AE, 0x00000024, 0x00000002, 0xFE363C8E, 0x00000004, 0x00000016, 0x00000001, 0x000000AF, 0x00000024, 0x00000002, 0xFE363C8E, 0x00000005, 0x00000023, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8F, 0x00000019, 0x00000001, 0x00000000, 0x00000043, 0x00000007, PartnerDamageEnemy, 0xFE363C80, 0x10010000, 0x00000000, 0x00000000, 0xFE363C8E, 0x00000070, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000023, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8F, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000004, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000033, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000003, 0x00000046, 0x00000001, D_8023AA70_70E780, 0x00000020, 0x00000000, 0x0000001D, 0x00000001, 0x00000000, 0x0000001D, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_8023AAF8_70E808, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023B45C_70F16C
.word 0x00000043, 0x00000002, LoadActionCommand, 0x00000013, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000043, 0x00000003, GetActorLevel, 0x00000100, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000007, SetupMashMeter, 0x00000002, 0x00000063, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000007, SetupMashMeter, 0x00000003, 0x00000046, 0x00000063, 0x00000064, 0x00000000, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000007, SetupMashMeter, 0x00000004, 0x00000028, 0x00000046, 0x00000063, 0x00000064, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80269344, 0x0000000A, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000013, 0x00000043, 0x00000004, SetBattleCamTarget, 0x0000002D, 0x0000003C, 0x00000000, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000000, 0x00000043, 0x00000002, SetBattleCamZoom, 0x00000190, 0x00000043, 0x00000002, MoveBattleCamOver, 0x0000001E, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100003, 0x00000043, 0x00000005, AddGoalPos, 0x00000100, 0x0000003C, 0x00000014, 0x00000000, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x0000001E, 0x00000000, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, GetActorLevel, 0x00000100, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000003C, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000003C, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000003C, 0x00000023, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C8B, 0xFFFFFFFD, 0x00000043, 0x00000004, func_802A916C_425CBC, 0x00000000, 0xFE363C8B, 0x00000003, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00004000, 0x00000000, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000004, SetActorVar, 0x00000100, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E282, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E283, 0x00000000, 0x00000005, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, GetActionResult, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000043, 0x00000005, SetPartFlagBits, 0x00000100, 0x00000002, 0x00000001, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100001, 0x00000016, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000001, 0x00000022, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetPartFlagBits, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000003, 0x00000027, 0x00000002, 0xFE363C81, 0x00000022, 0x00000027, 0x00000002, 0xFE363C82, 0x00000005, 0x00000043, 0x00000006, SetPartPos, 0x00000100, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x0010000F, 0x00000024, 0x00000002, 0xFE363C89, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000000, 0x00000022, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E282, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x0000201B, 0x00000024, 0x00000002, 0xFBD3E282, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x0000201C, 0x00000024, 0x00000002, 0xFBD3E282, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80238A6C_70C77C, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100013, 0x00000043, 0x00000005, SetPartFlagBits, 0x00000100, 0x00000002, 0x00000001, 0x00000001, 0x00000058, 0x00000000, 0x00000043, 0x00000004, GetActorVar, 0x00000100, 0x00000000, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000004, SetActorVar, 0x00000100, 0x00000000, 0xFE363C80, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, GetActorVar, 0x00000100, 0x00000000, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000004, SetActorVar, 0x00000100, 0x00000000, 0xFE363C80, 0x00000059, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E283, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetPartFlagBits, 0x00000100, 0x00000002, 0x00000001, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetActorVar, 0x00000100, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xFBD3E283, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8F, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000004, 0x00000001, 0x0000000D, 0x00000013, 0x00000000, 0x00000043, 0x00000001, InitTargetIterator, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetGoalToTarget, 0x00000100, 0x00000043, 0x00000007, PartnerTestEnemy, 0xFE363C80, 0x00000000, 0x00000014, 0x00000000, 0x00000002, 0x00000010, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000006, 0x00000004, 0x00000001, 0x0000000C, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetActionCommandResult, 0xFE363C8A, 0x00000043, 0x00000001, func_80238B50_70C860, 0x00000014, 0x00000001, 0xFE363C80, 0x00000019, 0x00000001, 0x00000000, 0x00000043, 0x00000007, PartnerDamageEnemy, 0xFE363C80, 0x30010000, 0x00000000, 0x00000000, 0xFE363C8F, 0x00000070, 0x0000001C, 0x00000000, 0x00000043, 0x00000007, PartnerDamageEnemy, 0xFE363C80, 0x30010000, 0x00000000, 0x00000000, 0xFE363C8F, 0x00000030, 0x00000023, 0x00000000, 0x00000014, 0x00000001, 0xFE363C80, 0x00000019, 0x00000001, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000004, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000033, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x00000006, 0x00000003, 0x00000001, 0x0000000C, 0x00000043, 0x00000003, ChooseNextTarget, 0x00000000, 0xFE363C81, 0x0000000B, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000003, 0x00000001, 0x0000000D, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000001, 0x0000001D, 0x00000001, 0x00000003, 0x00000046, 0x00000001, D_8023AA70_70E780, 0x00000020, 0x00000000, 0x0000001D, 0x00000001, 0x00000000, 0x0000001D, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_8023AAF8_70E808, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023BD7C_70FA8C
.word 0x00000043, 0x00000003, UseIdleAnimation, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000008, 0x00000000, 0x00000043, 0x00000004, SetActorFlagBits, 0x00000000, 0x20000000, 0x00000001, 0x00000043, 0x00000002, LoadActionCommand, 0x00000016, 0x00000043, 0x00000002, action_command_jump_CreateHudElements, 0x00000002, 0x00000043, 0x00000002, func_80269344, 0x00000032, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000000A, 0x00000043, 0x00000002, BattleCamTargetActor, 0xFFFFFF81, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000011, 0x00000043, 0x00000002, SetBattleCamZoom, 0x0000012C, 0x00000043, 0x00000002, MoveBattleCamOver, 0x0000001E, 0x00000043, 0x00000001, func_8024EDA4, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000028, 0x00000043, 0x00000005, SetGoalPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x0000001E, 0x00000000, 0x0000000A, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C80, 0x00000012, 0x00000043, 0x00000003, SetActorYaw, 0x00000100, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100005, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100004, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFF4, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000D, 0x00000027, 0x00000002, 0xFE363C82, 0xFFFFFFFB, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000003, SetActorJumpGravity, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00010020, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, func_80273444, 0x00000012, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010020, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000043, 0x00000004, func_802A9398_42A888, 0x00000000, 0x00000061, 0x00000003, 0x00000043, 0x00000002, AddBattleCamZoom, 0xFFFFFFB5, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000064, 0x00000043, 0x00000004, func_8024ECF8, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, AddBattleCamZoom, 0x00000032, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000005, 0x00000043, 0x00000002, GetActionCommandResult, 0xFE363C8A, 0x0000000D, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000001, func_80238C14_70C924, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x0000201D, 0x00000043, 0x00000001, func_80238C58_70C968, 0x00000043, 0x00000001, func_80238D48_70CA58, 0x00000043, 0x00000004, SetActorFlagBits, 0x00000000, 0x08000000, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000003, UseIdleAnimation, 0x00000000, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100006, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000005, 0x00000001, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C85, 0x00000043, 0x00000003, RandInt, 0x00000028, 0xFE363C86, 0x00000028, 0x00000002, 0xFE363C86, 0x00000014, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C86, 0x00000043, 0x00000003, RandInt, 0x0000001E, 0xFE363C86, 0x00000028, 0x00000002, 0xFE363C86, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C86, 0x00000043, 0x0000000F, PlayEffect, 0x00000069, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7E80, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000006, SetJumpAnimations, 0x00000000, 0x00000000, 0x00010007, 0x00010008, 0x00010020, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, PlayerFallToGoal, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100002, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010020, 0x00000008, 0x00000001, 0x00000007, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000056, 0x00000000, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000043, 0x00000004, SetActorFlagBits, 0x00000000, 0x20000000, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C81, 0x00000028, 0x00000043, 0x00000005, SetGoalPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x0000001E, 0x00000000, 0x0000000A, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000005, 0x00000001, 0x0000000A, 0x00000028, 0x00000002, 0xFE363C80, 0x00000012, 0x00000043, 0x00000003, SetActorYaw, 0x00000100, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000002, 0x00000043, 0x00000002, MoveBattleCamOver, 0x0000001E, 0x00000008, 0x00000001, 0x0000000A, 0x0000000D, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000003, ShowMessageBox, 0x00000028, 0x0000003C, 0x00000043, 0x00000001, WaitForMessageBoxDone, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00000008, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023C588_710298
.word 0x00000043, 0x00000003, UseIdleAnimation, 0x00000000, 0x00000000, 0x00000043, 0x00000002, LoadActionCommand, 0x00000016, 0x00000043, 0x00000002, action_command_jump_CreateHudElements, 0x00000002, 0x00000043, 0x00000002, func_80269344, 0x00000032, 0x00000043, 0x00000001, func_80238C14_70C924, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000002, UseBattleCamPreset, 0x0000000A, 0x00000043, 0x00000002, BattleCamTargetActor, 0xFFFFFF81, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000000, 0x00000043, 0x00000002, SetBattleCamZoom, 0x0000012C, 0x00000043, 0x00000002, MoveBattleCamOver, 0x0000001E, 0x00000043, 0x00000001, func_8024EDA4, 0x00000008, 0x00000001, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C80, 0x00000012, 0x00000043, 0x00000003, SetActorYaw, 0x00000100, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100005, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000C, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFF9, 0x00000027, 0x00000002, 0xFE363C82, 0x00000005, 0x00000043, 0x00000005, SetGoalPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x00000014, 0xFFFFFFF6, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000028, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, FlyToGoal, 0x00000000, 0x00000014, 0x00000000, 0x0000000A, 0x00000057, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000028, 0x00000043, 0x00000005, SetGoalPos, 0x00000100, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x00000014, 0x00000000, 0x0000000A, 0x00000043, 0x00000004, func_802A9398_42A888, 0x00000000, 0x00000061, 0x00000003, 0x00000043, 0x00000002, AddBattleCamZoom, 0xFFFFFFB5, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000064, 0x00000043, 0x00000004, func_8024ECF8, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, AddBattleCamZoom, 0x00000032, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000005, 0x00000043, 0x00000002, GetActionCommandResult, 0xFE363C8A, 0x0000000D, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x0000201D, 0x00000043, 0x00000001, func_80238C58_70C968, 0x00000043, 0x00000001, func_80238D48_70CA58, 0x00000013, 0x00000000, 0x00000043, 0x00000003, UseIdleAnimation, 0x00000000, 0x00000001, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100006, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000005, 0x00000001, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C85, 0x00000043, 0x00000003, RandInt, 0x00000028, 0xFE363C86, 0x00000028, 0x00000002, 0xFE363C86, 0x00000014, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C86, 0x00000043, 0x00000003, RandInt, 0x0000001E, 0xFE363C86, 0x00000028, 0x00000002, 0xFE363C86, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C86, 0x00000043, 0x0000000F, PlayEffect, 0x00000069, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7E80, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, GetActorPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000005, SetGoalPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, FallToGoal, 0x00000000, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100002, 0x00000056, 0x00000000, 0x00000043, 0x00000002, SetGoalToHome, 0x00000000, 0x00000043, 0x00000003, SetActorSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010005, 0x00000043, 0x00000002, PlayerRunToGoal, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0x00000000, 0x00000000, 0x00010002, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x00000014, 0x00000000, 0x0000000A, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000005, 0x00000001, 0x0000000A, 0x00000028, 0x00000002, 0xFE363C80, 0x00000012, 0x00000043, 0x00000003, SetActorYaw, 0x00000100, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000001, func_80280818, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000002, 0x00000043, 0x00000002, MoveBattleCamOver, 0x0000001E, 0x00000008, 0x00000001, 0x0000000A, 0x0000000D, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000003, ShowMessageBox, 0x00000028, 0x0000003C, 0x00000043, 0x00000001, WaitForMessageBoxDone, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023CC64_710974
.word 0x00000043, 0x00000003, GetStatusFlags, 0x00000000, 0xFE363C80, 0x00000010, 0x00000002, 0xFE363C80, 0x0035D000, 0x00000046, 0x00000001, D_8023C588_710298, 0x00000012, 0x00000000, 0x00000046, 0x00000001, D_8023BD7C_70FA8C, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023CCC0_7109D0
.word 0x8023D1E8

dlabel D_8023CCC4_7109D4
.word 0x00000043, 0x00000002, LoadActionCommand, 0x00000014, 0x00000043, 0x00000001, action_command_jump_CreateHudElements, 0x00000043, 0x00000007, SetupMashMeter, 0x00000001, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, func_80269344, 0x0000000F, 0x00000043, 0x00000002, func_80269EAC, 0x00000014, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000013, 0x00000043, 0x00000004, SetBattleCamTarget, 0xFFFFFFD3, 0x00000036, 0x00000000, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000000, 0x00000043, 0x00000002, SetBattleCamZoom, 0x00000118, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000028, 0x00000043, 0x00000001, InitTargetIterator, 0x00000043, 0x00000002, SetGoalToHome, 0x00000100, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100003, 0x00000043, 0x00000005, AddGoalPos, 0x00000100, 0x00000028, 0x00000014, 0x00000000, 0x00000043, 0x00000005, FlyToGoal, 0x00000100, 0x0000001E, 0x00000000, 0x0000000A, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100001, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000001, func_80238D8C_70CA9C, 0x00000043, 0x00000005, func_802A91A0_42DBB0, 0x00000000, 0x00000093, 0x00000003, 0xFE363C80, 0x00000043, 0x00000003, SetBattleFlagBits, 0x00004000, 0x00000000, 0x00000043, 0x00000005, SetActorRotationOffset, 0x00000100, 0x00000000, 0x00000014, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000013, 0x00000043, 0x00000004, SetBattleCamTarget, 0x00000023, 0x00000036, 0x00000000, 0x00000043, 0x00000002, SetBattleCamOffsetZ, 0x00000000, 0x00000043, 0x00000002, SetBattleCamZoom, 0x000001AE, 0x00000043, 0x00000002, MoveBattleCamOver, 0x00000096, 0x00000043, 0x00000004, func_8024ECF8, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, PlaySoundAtActor, 0x00000100, 0x00000288, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80239140_70CE50, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000005, 0x00000001, 0x00000096, 0x00000043, 0x00000001, func_8023A1B0_70DEC0, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetActionSuccessCopy, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000064, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, GetActionSuccessCopy, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000019, 0x00000001, 0x00000063, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000004, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, UseBattleCamPreset, 0x00000033, 0x00000023, 0x00000000, 0x00000043, 0x00000001, InitTargetIterator, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetGoalToTarget, 0xFFFFFF81, 0x00000043, 0x00000001, func_8023906C_70CD7C, 0x0000000D, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80239F84_70DC94, 0x00000043, 0x00000003, SetBattleFlagBits, 0x01000000, 0x00000001, 0x00000043, 0x00000002, RemoveActor, 0xFE363C8A, 0x00000057, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000007, PartnerDamageEnemy, 0xFE363C82, 0x10000000, 0x00000000, 0x00000000, 0x00000000, 0x00000820, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x0000000B, 0x00000043, 0x00000003, ChooseNextTarget, 0x00000000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000022, 0x00000043, 0x00000005, SetActorRotation, 0x00000100, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetActorRotationOffset, 0x00000100, 0x00000000, 0x00000000, 0x00000000, 0x00000046, 0x00000001, D_8023AAF8_70E808, 0x00000043, 0x00000004, SetAnimation, 0x00000100, 0xFFFFFFFF, 0x00100002, 0x00000043, 0x00000001, func_8023A19C_70DEAC, 0x00000043, 0x00000001, func_80280818, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8023D1B0_710EC0
.double 6.7

dlabel D_8023D1B8_710EC8
.double 0.2

dlabel D_8023D1C0_710ED0
.double 0.1

dlabel D_8023D1C8_710ED8
.double 2.8

dlabel D_8023D1D0_710EE0
.double 1.4, 0.0
