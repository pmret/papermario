.include "macro.inc"

.section .data

dlabel D_802414D0_BC3F60
.word 0x00000008, 0x00000001, 0x0000000F, 0x00000056, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x0000212A, 0x00000000, 0x00000004, 0x0000001A, 0xFFFFFFF4, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFB0, 0x0000000A, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000032, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x0000212B, 0x00000000, 0x00000004, 0x0000001A, 0xFFFFFFF4, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A8080, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000006, PlaySoundAt, 0x0000212C, 0x00000000, 0x00000004, 0x0000001A, 0xFFFFFFF4, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFB0, 0x00000000, 0x00000014, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000032, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0008001F, 0x00000008, 0x00000001, 0x00000030, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000024, 0x00000002, 0xF8405F42, 0x00000001, 0x00000008, 0x00000001, 0x00000005, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802416FC_BC418C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000046, 0x00000001, D_802414D0_BC3F60, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, D_802EAE30, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignChestFlag, 0xF8405F43, 0x00000043, 0x00000002, AssignScript, D_802416FC_BC418C, 0x00000043, 0x00000008, MakeEntity, D_802EAB04, 0x00000064, 0xFFFFFF2E, 0x00000000, 0x00000000, 0x00000006, 0x80000000, 0x00000043, 0x00000002, AssignPanelFlag, 0xF8405F44, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
