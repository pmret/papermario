.include "macro.inc"

.section .data

dlabel D_802408B0_AD4940
.word 0xC2960000, 0x00000000, 0x00000000, 0x42B40000, 0x4492E000, 0x42DC0000, 0x00000000, 0x43870000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80240B7C_AD4C0C, D_802408B0_AD4940, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0019000D

dlabel D_80240910_AD49A0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0x00000005, 0x00000024, 0x00000002, 0xFE363C83, 0x00000007, 0x00000044, 0x00000001, ExitDoubleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241E10, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802409B4_AD4A44
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000004, 0x00000024, 0x00000002, 0xFE363C82, 0x00000019, 0x00000024, 0x00000002, 0xFE363C83, 0x00000017, 0x00000044, 0x00000001, ExitDoubleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80241E18, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A58_AD4AE8
.word 0x00000047, 0x00000005, D_80240910_AD49A0, 0x00000100, 0x00000001, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF5DE0180, 0x0000003A, 0x0000000A, 0x00000002, 0xF8405D77, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000047, 0x00000005, D_802409B4_AD4A44, 0x00000100, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240AD8_AD4B68
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000005, 0x00000024, 0x00000002, 0xFE363C83, 0x00000007, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0x00000019, 0x00000024, 0x00000002, 0xFE363C83, 0x00000017, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B7C_AD4C0C
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001A, 0x00000043, 0x00000002, SetSpriteShading, 0x00050002, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x0000000A, 0x00000002, 0xF5DE0180, 0x0000003A, 0x00000043, 0x00000002, func_80240034_AD40C4, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, D_80241DF0_AD5E80, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000007C, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000007D, 0x00000000, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0x0000005E, 0x00000043, 0x00000001, func_80240000_AD4090, 0x00000013, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000002, 0x00000044, 0x00000001, D_80240A58_AD4AE8, 0x00000044, 0x00000001, D_80240AD8_AD4B68, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CC0_AD4D50
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00190000

dlabel D_80240CEC_AD4D7C
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240D18_AD4DA8
.word 0x00580000, 0x00580001, 0x00580002, 0x00580004, 0x00580005, 0x00580006, 0x00580007, 0x00580008, 0x00580009, 0x00580012, 0x00580014, 0x0058001B, 0xFFFFFFFF

dlabel D_80240D4C_AD4DDC
.word 0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390008, 0x00390007, 0x00390013, 0x00390014, 0xFFFFFFFF

dlabel D_80240D74_AD4E04
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, func_802406E8_AD4778, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000003, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140143, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140141, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140142, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240E90_AD4F20
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, func_802406E8_AD4778, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000003, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8E80, 0x00000000, 0xF24FF280, 0xF24AB680, 0xF24A5E80, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140147, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF8405D77, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00580005, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8280, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x0000041A, 0x00000000, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140148, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000384, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFE0C, 0x00000000, 0x00000024, 0x00000002, 0xF8405D77, 0x00000001, 0x00000047, 0x00000005, D_802409B4_AD4A44, 0x00000100, 0x00000004, 0x00000001, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D75, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8E80, 0x00000000, 0xF24FF280, 0xF24AB680, 0xF24A5E80, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140144, 0x00000008, 0x00000001, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C80, 0x0000006A, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C80, 0x00000024, 0x00000002, 0xF8405D75, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140145, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8E80, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000010, 0x00140146, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411C0_AD5250
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000001, func_80240714_AD47A4, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000262, 0x00000000, 0x00000043, 0x0000000A, ShowEmote, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000014, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000005, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x000C0005, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00580002, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140174, 0x00000043, 0x00000005, kkj_12_UnkGooberFunc, 0xFFFFFFFF, 0xFE363C83, 0xFE363C80, 0xFE363C82, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00580007, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8E80, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00580002, 0x00000013, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00580009, 0x00580002, 0x00000000, 0x00140175, 0x00000043, 0x00000002, SetPlayerAnimation, 0x000C0017, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, GotoMapSpecial, 0x80241E38, 0x0000000B, 0x0000000D, 0x00000008, 0x00000001, 0x00000064, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802413D4_AD5464
.word 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000008, kkj_12_UnkModelMatrixFunc2, 0xFE363C80, 0x00000064, 0x0000005A, 0x00000000, 0x00000028, 0x0000007C, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000002, func_802406E8_AD4778, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x08000000, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_802411C0_AD5250, 0x00000024, 0x00000002, 0xFE363C82, 0x00000001, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x08000000, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8280, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000384, 0x00000000, 0x00000000, 0x00000043, 0x00000006, kkj_12_UnkAtan2Func, 0xFE363C80, 0x00000384, 0x00000000, 0x00000320, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x0000000F, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000320, 0x00000000, 0x00000000, 0x00000043, 0x00000006, kkj_12_UnkAtan2Func, 0xFE363C80, 0x00000320, 0x00000000, 0x00000384, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x0000000F, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415C8_AD5658
.word 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000008, kkj_12_UnkModelMatrixFunc2, 0xFE363C80, 0x00000064, 0x0000005A, 0x00000000, 0x00000028, 0x0000007D, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000002, func_802406E8_AD4778, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x08000000, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_802411C0_AD5250, 0x00000024, 0x00000002, 0xFE363C82, 0x00000001, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x08000000, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802416EC_AD577C
.word 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00580005, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000320, 0x0000006E, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802413D4_AD5464, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80240D74_AD4E04, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241754_AD57E4
.word 0x0000000B, 0x00000002, 0xF8405D77, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000007D, 0x00000000, 0x00000043, 0x00000001, func_8024089C_AD492C, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00580002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000492, 0x0000006E, 0x00000000, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802415C8_AD5658, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80240E90_AD4F20, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241820_AD58B0
.word 0x00000000, D_80240CC0_AD4D50, 0x00000000, 0xC3FA0000, 0x00000000, 0x00000D0D, D_802416EC_AD577C, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000000, 0x00000000, D_80240D18_AD4DA8, 0x00000000, 0x00000001, D_80240CC0_AD4D50, 0x00000000, 0xC3FA0000, 0x00000000, 0x00400D0D, D_80241754_AD57E4, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00580001, 0x00580004, 0x00580006, 0x00580006, 0x00580001, 0x00580001, 0x00580010, 0x00580010, 0x0058000C, 0x0058000B, 0x0058000D, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00580001, 0x00000000, 0x00000000, D_80240D18_AD4DA8, 0x00000000, 0x00000002, D_80240CEC_AD4D7C, 0x00000000, 0xC47A0000, 0x00000000, 0x00000D0D, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00390002, 0x00390003, 0x00390004, 0x00390004, 0x00390002, 0x00390002, 0x0039000C, 0x0039000C, 0x00390011, 0x00390012, 0x00390007, 0x00390008, 0x00390001, 0x00390002, 0x00390002, 0x00390002, 0x00000000, 0x00000000, D_80240D4C_AD4DDC, 0x00000000

dlabel D_80241DF0_AD5E80
.word 0x00000003, D_80241820_AD58B0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
