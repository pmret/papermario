.include "macro.inc"

.section .data

dlabel D_80240E10_DA6050
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFE98, 0x00000064, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000003D, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x0000003F, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000041, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000043, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F1C_DA615C
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000000A0, 0x0000003C, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000004C, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000004E, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000000A0, 0x00000000, 0x0000003C, 0x0000000A, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000004C, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000004E, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024108C_DA62CC
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFE98, 0x00000064, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000046, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241138_DA6378
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000046, 0x0000001E, 0x0000000A, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000057, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000001F, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x000001F1, 0x00000000, 0xFFFFFE48, 0x0000000A, 0x00000028, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x0000001C, 0x7FFFFE00, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFF48, 0x0000000A, 0xFFFFFF1B, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFF48, 0x0000000A, 0xFFFFFF1B, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF252901A, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0xF247AA80, 0xF2457280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ADE80, 0xF24A6280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000006, PlaySoundAt, 0x000001F2, 0x00000000, 0xFFFFFF7E, 0x00000000, 0xFFFFFF29, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000000B4, 0x0000001E, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000005B, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000005C, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000005A, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x00000051, 0x00000000, 0xFFFFFF7E, 0x00000000, 0xFFFFFF29, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A7E80, 0x00000043, 0x00000002, GetModelCenter, 0x00000017, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000024, 0x00000002, 0xF8405FCD, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x008C0001, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24BE280, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000044, 0x00000001, D_80240E10_DA6050, 0x00000044, 0x00000001, D_80240F1C_DA615C, 0x00000044, 0x00000001, D_8024108C_DA62CC, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000001F, 0x00000057, 0x0000000A, 0x00000002, 0xF8405FCD, 0x00000000, 0x00000047, 0x00000005, D_80241138_DA6378, 0x00000100, 0x0000001B, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000001C, 0x7FFFFE00, 0x00000012, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000057, 0x00000046, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000001F, 0x00000043, 0x00000006, RotateModel, 0x0000005B, 0x000000B4, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000005C, 0x000000B4, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000005A, 0x000000B4, 0x00000001, 0x00000000, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415E0_DA6820
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetCamTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241648_DA6888
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000003, 0x00000008, 0x00000001, 0x00000001, 0x00000045, 0x00000002, D_802415E0_DA6820, 0xFE363C8A, 0x0000000A, 0x00000002, 0xF9718884, 0x00000000, 0x00000043, 0x00000001, omo_03_UnsetCamera0MoveFlag1, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000006, 0x00000043, 0x00000003, GotoMap, 0x80248180, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000057, 0x00000000, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7D4D, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFF0B, 0x0000010E, 0x000000FA, 0x00000014, 0x00000012, 0x00000000, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7E80, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFFA1, 0x00000000, 0x000000FA, 0x00000019, 0x00000024, 0x00000002, 0xF9718884, 0x00000000, 0x00000013, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000003, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000200, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000064, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000045, 0x00000002, D_802415E0_DA6820, 0xFE363C8A, 0x00000056, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000004, 0x00000016, 0x00000001, 0x00000008, 0x00000016, 0x00000001, 0x00000009, 0x00000016, 0x00000001, 0x00000006, 0x0000001C, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7D4D, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFC, 0xFFFFFF6A, 0x00000019, 0x000000FA, 0x00000025, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFC, 0xFFFFFF92, 0x00000000, 0x000000BE, 0x00000014, 0x00000023, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000200, 0x00000001, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000057, 0x00000000, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7D4D, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFF6A, 0x00000019, 0x000000FA, 0x00000019, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802E9A18, 0xFFFFFF06, 0x0000003C, 0x00000032, 0x00000000, D_80000000, 0x00000043, 0x00000007, MakeEntity, 0x802EAA30, 0xFFFFFF6A, 0x00000000, 0x000000FA, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80241648_DA6888, 0x00000043, 0x00000008, MakeEntity, 0x802EAB04, 0x000000CB, 0x00000000, 0x000000C8, 0x00000000, 0x00000019, D_80000000, 0x00000043, 0x00000002, AssignPanelFlag, 0xF8406026, 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0x00000190, 0x0000003C, 0xFFFFFFCE, 0x00000000, 0x00000088, D_80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405FDD, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AA0_DA6CE0
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AB0_DA6CF0
.word 0x00000000, 0x00200018, D_80241AA0_DA6CE0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241ADC_DA6D1C
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010

dlabel D_80241B08_DA6D48
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, 0x00000000, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001

dlabel D_80241B34_DA6D74
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFFB, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000043, 0x00000001, CloseChoicePopup, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000021, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x008C0004, 0x008C0001, 0x00000000, 0x000F0002, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF9718885, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x008C0006, 0x008C0002, 0x00000000, 0x000F0000, 0x00000024, 0x00000002, 0xF9718885, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x008C0006, 0x008C0002, 0x00000000, 0x000F0001, 0x00000024, 0x00000002, 0xF9718885, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF8405FCC, 0x00000000, 0x0000000A, 0x00000002, 0xF9718885, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000000, 0x00000100, 0x00000001, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000006, NpcJump1, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000006, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000000, 0x00000100, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xFAA2B581, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x008C0004, 0x008C0001, 0x00000000, 0x000F0003, 0x00000043, 0x00000005, EndSpeech, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x008C0004, 0x008C0001, 0x00000000, 0x000F0003, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x008C0004, 0x008C0001, 0x00000000, 0x000F0005, 0x00000024, 0x00000002, 0xF8405FCC, 0x00000001, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF9718885, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x008C0004, 0x008C0001, 0x00000000, 0x000F0004, 0x00000024, 0x00000002, 0xF8405FCC, 0x00000001, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF9718886, 0x00000000, 0x00000046, 0x00000001, 0x8024705C, 0x00000012, 0x00000000, 0x00000046, 0x00000001, 0x80246108, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241E78_DA70B8
.word 0x00000021, 0x00000000

dlabel D_80241E80_DA70C0
.word 0x0000004E, 0x00000006, D_80241B34_DA6D74, 0x00000010, 0x00000000, D_80241E78_DA70B8, 0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241EB0_DA70F0
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFFB, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x008C0002, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241E80_DA70C0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241F00_DA7140
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFF8, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0206, 0x008C0202, 0x00000000, 0x000F0017, 0x00000018, 0x00000001, 0xFFFFFFF9, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F0018, 0x00000018, 0x00000001, 0xFFFFFFFB, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F0019, 0x00000018, 0x00000001, 0xFFFFFFFC, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F001A, 0x00000018, 0x00000001, 0xFFFFFFFD, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F001B, 0x00000018, 0x00000001, 0xFFFFFFFE, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F001C, 0x00000018, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F001D, 0x00000018, 0x00000001, 0x00000000, 0x00000043, 0x00000003, FindKeyItem, 0x00000025, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F001E, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F001F, 0x00000013, 0x00000000, 0x00000018, 0x00000001, 0x00000002, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F0020, 0x00000018, 0x00000001, 0x00000004, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F0021, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x008C0204, 0x008C0201, 0x00000000, 0x000F0022, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242158_DA7398
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241F00_DA7140, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024217C_DA73BC
.word 0x00000000, D_80241AB0_DA6CF0, 0x432A0000, 0x42480000, 0xC2E60000, 0x00400D05, D_80241EB0_DA70F0, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x008C0001, 0x008C0003, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x008C0001, 0x00000000, 0x00000000, 0x00000000, 0x001A00B8, 0x00000001, D_80241AB0_DA6CF0, 0x431E0000, 0x00000000, 0x42AA0000, 0x00400D05, D_80242158_DA7398, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x008C0201, 0x00000000, 0x00000000, 0x00000000, 0x001A00B8

dlabel D_8024255C_DA779C
.word 0x00000002, D_80241ADC_DA6D1C, 0x00000000, 0xC47A0000, 0x00000000, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00040001, 0x00040002, 0x00040003, 0x00040003, 0x00040001, 0x00040001, 0x00040000, 0x00040000, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_80241B08_DA6D48, 0x42480000, 0x41700000, 0x43200000, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00060001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, D_80241B08_DA6D48, 0x42C80000, 0x00000000, 0x43200000, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, D_80241B08_DA6D48, 0x42E60000, 0x00000000, 0x43480000, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, D_80241B08_DA6D48, 0x43110000, 0x00000000, 0x43160000, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003B0001, 0x003B0002, 0x003B0003, 0x003B0003, 0x003B0001, 0x003B0001, 0x003B000C, 0x003B000C, 0x003B0015, 0x003B0012, 0x003B0011, 0x003B0010, 0x003B0005, 0x003B0001, 0x003B0001, 0x003B0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_8024217C_DA73BC, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_8024217C_DA73BC, 0x00000000, 0x00000005, D_8024255C_DA779C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
