.include "macro.inc"

.section .data

dlabel D_80231000_552440
.word 0x00000001, 0x00000000, 0x00000000

dlabel D_8023100C_55244C
.word 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000006, 0x00000000, 0x00000009, 0x00000000, 0x00000007, 0x00000000, 0x00000004, 0x00000000, 0x00000003, 0x00000000, 0x0000000B, 0x00000000, 0x00000005, 0x00000000, 0x0000000A, 0x00000000, 0x00000008, 0x00000000, 0x0000001F, 0x00000000, 0x00000020, 0x00000000, 0x00000025, 0x00000000, 0x00000022, 0x00000000, 0x00000024, 0x00000000, 0x00000023, 0x00000000, 0x00000021, 0x00000000, 0x00000026, 0x00000000, 0x00000027, 0x00000000, 0x00000029, 0x00000000, 0x00000000

dlabel D_802310B8_5524F8
.word 0x20820000, 0x01000000, 0x001800FF, D_80231104_552544, D_80231000_552440, 0x00000000, 0x00000000, 0xFFF60000, 0x00000000,
0x02000000, 0x00AC0008, 0x00010000, D_802310B8_5524F8,
D_80231110_552550, D_8023100C_55244C, 0x00000000, 0x00045000,
0x1E1E0000, 0xF6140A14

dlabel D_80231104_552544
.word 0x00000001, 0x006F0001, 0x00000000

dlabel D_80231110_552550
.word 0x00000043, 0x00000003, BindTakeTurn, 0xFFFFFF81, D_80231754_552B94, 0x00000043, 0x00000003, BindIdle, 0xFFFFFF81, D_8023129C_5526DC, 0x00000043, 0x00000003, BindHandleEvent, 0xFFFFFF81, D_802312D0_552710, 0x00000043, 0x00000005, SetActorPos, 0xFFFFFF81, 0x000000B4, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ForceHomePos, 0xFFFFFF81, 0x000000B4, 0x00000000, 0x00000000, 0x00000043, 0x00000002, HPBarToHome, 0xFFFFFF81, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F000F, 0x00000043, 0x00000003, SetActorSpeed, 0xFFFFFF81, 0xF24A8E80, 0x00000043, 0x00000005, SetGoalPos, 0xFFFFFF81, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, RunToGoal, 0xFFFFFF81, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetActorYaw, 0xFFFFFF81, 0x000000B4, 0x00000043, 0x00000003, PlaySoundAtActor, 0xFFFFFF81, 0x00000395, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F0004, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F0005, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F0009, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8023129C_5526DC
.word 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802312D0_552710
.word 0x00000043, 0x00000003, UseIdleAnimation, 0xFFFFFF81, 0x00000000, 0x00000043, 0x00000003, GetLastEvent, 0xFFFFFF81, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000038, 0x0000001D, 0x00000001, 0x00000009, 0x0000001D, 0x00000001, 0x0000000A, 0x0000001D, 0x00000001, 0x0000000E, 0x0000001D, 0x00000001, 0x00000024, 0x0000001D, 0x00000001, 0x0000000B, 0x0000001D, 0x00000001, 0x00000021, 0x0000001D, 0x00000001, 0x0000002F, 0x0000001D, 0x00000001, 0x00000017, 0x0000001D, 0x00000001, 0x00000019, 0x0000001D, 0x00000001, 0x0000001B, 0x0000001D, 0x00000001, 0x00000020, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F000A, 0x00000043, 0x00000003, SetActorJumpGravity, 0xFFFFFF81, 0xF24A8080, 0x00000043, 0x00000005, GetActorPos, 0xFFFFFF81, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C80, 0x00000023, 0x00000043, 0x00000005, SetGoalPos, 0xFFFFFF81, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, JumpToGoal, 0xFFFFFF81, 0x00000008, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetActorYaw, 0xFFFFFF81, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F0002, 0x00000008, 0x00000001, 0x00000018, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F0003, 0x00000043, 0x00000005, GetActorPos, 0xFFFFFF81, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000005, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000005, 0x00000001, 0x00000004, 0x00000043, 0x0000000F, PlayEffect, 0x00000028, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x0000002D, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000006, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetActorSounds, 0xFFFFFF81, 0x00000000, 0x000020BA, 0x000003B4, 0x00000043, 0x00000005, SetActorSounds, 0xFFFFFF81, 0x00000004, 0x0000000A, 0x00000000, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0x006F000C, 0x00000043, 0x00000003, SetActorSpeed, 0xFFFFFF81, 0xF24A9280, 0x00000043, 0x00000005, AddActorDecoration, 0xFFFFFF81, 0x00000001, 0x00000000, 0x00000008, 0x00000043, 0x00000005, SetGoalPos, 0xFFFFFF81, 0xFFFFFF38, 0x00000000, 0x00000014, 0x00000043, 0x00000004, RunToGoal, 0xFFFFFF81, 0x00000000, 0x00000000, 0x00000043, 0x00000004, RemoveActorDecoration, 0xFFFFFF81, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, RemoveActor, 0xFFFFFF81, 0x00000002, 0x00000000, 0x00000020, 0x00000000, 0x00000016, 0x00000001, 0x00000035, 0x00000043, 0x00000002, HPBarToHome, 0xFFFFFF81, 0x00000016, 0x00000001, 0x00000031, 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x006F0001, 0x00000046, 0x00000001, DoRecover, 0x00000016, 0x00000001, 0x00000030, 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x006F000A, 0x00000046, 0x00000001, DoNormalHit, 0x00000008, 0x00000001, 0x000003E8, 0x00000016, 0x00000001, 0x00000039, 0x00000025, 0x00000002, 0xFE363C80, 0x00000001, 0x00000025, 0x00000002, 0xFE363C81, 0x006F0001, 0x00000025, 0x00000002, 0xFE363C82, 0x006F000A, 0x00000046, 0x00000001, DoScareAway, 0x00000002, 0x00000000, 0x0000001C, 0x00000000, 0x00000025, 0x00000002, 0xFE363C81, 0x006F000A, 0x00000043, 0x00000004, SetAnimation, 0xFFFFFF81, 0x00000001, 0xFE363C81, 0x00000008, 0x00000001, 0x00000014, 0x00000023, 0x00000000, 0x00000043, 0x00000003, UseIdleAnimation, 0xFFFFFF81, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80231754_552B94
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
