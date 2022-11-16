.include "macro.inc"

.section .data

dlabel D_80241140_ABC3D0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000005, 0x00000024, 0x00000002, 0xFE363C82, 0x00000008, 0x00000024, 0x00000002, 0xFE363C83, 0x0000000A, 0x00000044, 0x00000001, ExitDoubleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80249D20, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411F4_ABC484
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0x00000014, 0x00000024, 0x00000002, 0xFE363C82, 0x00000014, 0x00000024, 0x00000002, 0xFE363C83, 0x00000001, 0x00000044, 0x00000001, ExitSingleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80249D28, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802412A8_ABC538
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0163, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802412F0_ABC580
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, EnableNpcAI, 0x00000000, 0x00000000, 0x00000043, 0x00000003, EnableNpcAI, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00820004, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00830001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00820014, 0x00820004, 0x00000010, 0x00000026, 0x00000043, 0x00000003, EnableNpcAI, 0x00000000, 0x00000001, 0x00000043, 0x00000003, EnableNpcAI, 0x00000001, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802413C4_ABC654
.word 0x00000047, 0x00000005, D_802412F0_ABC580, 0x00000100, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802412A8_ABC538, 0x00000100, 0x0000000A, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802412A8_ABC538, 0x00000100, 0x00000019, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241140_ABC3D0, 0x00000100, 0x00000005, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802411F4_ABC484, 0x00000100, 0x00000014, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241460_ABC6F0
.word 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C83, 0x0000000D, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, UseDoorSounds, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000008, 0x00000024, 0x00000002, 0xFE363C83, 0x0000000A, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000012, 0x00000024, 0x00000002, 0xFE363C83, 0x00000001, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000016, 0x00000001, 0x00000003, 0x00000024, 0x00000002, 0xFE363C82, 0x00000014, 0x00000024, 0x00000002, 0xFE363C83, 0x00000001, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000016, 0x00000001, 0x00000004, 0x00000024, 0x00000002, 0xFE363C82, 0x00000016, 0x00000024, 0x00000002, 0xFE363C83, 0x00000001, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000016, 0x00000001, 0x00000005, 0x00000044, 0x00000001, 0x80243B7C, 0x00000016, 0x00000001, 0x00000006, 0x00000044, 0x00000001, 0x80249178, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024160C_ABC89C
.word 0x43B34000, 0x3F000000, 0x41A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024162C_ABC8BC
.word 0x3FC00000, 0x3F000000, 0x41A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024164C_ABC8DC
.word 0x00000043, 0x00000002, func_80240040_ABB2D0, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80240040_ABB2D0, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000019, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFF80, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, D_802439C4_ABEC54, 0x00000012, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80248DC4, 0x00000013, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000001, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000006, 0x00000000, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFF80, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x0000003F, 0x00000001, 0x00000008, 0x00000012, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000005A, 0x00000043, 0x00000003, FadeOutMusic, 0x00000000, 0x00000BB8, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_802413C4_ABC654, 0x00000044, 0x00000001, D_80241460_ABC6F0, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241820_ABCAB0
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024184C_ABCADC
.word 0x3FC00000, 0x0000001E, 0x0000001E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001

dlabel D_8024187C_ABCB0C
.word 0x00000043, 0x00000002, kkj_00_PatrolNoAttackAI_Main, D_8024184C_ABCADC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024189C_ABCB2C
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, D_8024187C_ABCB0C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010, 0x00000000, 0x00170013, 0x00000000, 0x00000000, D_8024187C_ABCB0C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010

dlabel D_802418F4_ABCB84
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024194C_ABCBDC
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241978_ABCC08
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000006, 0x00A90004, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x009B0104, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x0000003C, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000006, 0x00A90001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x009B0101, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A7C_ABCD0C
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00840104, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000005, 0x00840204, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x0000003C, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00840101, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000005, 0x00840201, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B80_ABCE10
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000005, 0x00000043, 0x00000001, WaitForPlayerInputEnabled, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, AwaitPlayerLeave, 0xFE363C80, 0xFE363C82, 0x00000064, 0x00000008, 0x00000001, 0x00000032, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000001, 0xF24A8280, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00830002, 0x00000043, 0x00000005, NpcMoveTo, 0x00000001, 0x0000003C, 0x00000140, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00830001, 0x00000013, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00830004, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00820014, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x0000003C, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00820004, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00830001, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D4C_ABCFDC
.word 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000096, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000007, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000007, 0x00000008, 0x00000001, 0x00000014, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241DD8_ABD068
.word 0x00000043, 0x00000003, EnableNpcAI, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00820004, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00830001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00820014, 0x00820004, 0x00000010, 0x00000025, 0x00000043, 0x00000003, EnableNpcAI, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241E64_ABD0F4
.word 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00830001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00820004, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00830004, 0x00830001, 0x00000010, 0x00000029, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241EC8_ABD158
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00830004, 0x00830001, 0x00000010, 0x0000002A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241EF8_ABD188
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00830304, 0x00830301, 0x00000000, 0x0000002B, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241F28_ABD1B8
.word 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00840101, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000005, 0x00840201, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00840104, 0x00840101, 0x00000010, 0x0000002C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241F8C_ABD21C
.word 0x00000043, 0x00000003, EnableNpcAI, 0x00000004, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000005, 0x00840201, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00840101, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00840204, 0x00840201, 0x00000010, 0x0000002D, 0x00000043, 0x00000003, EnableNpcAI, 0x00000004, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242018_ABD2A8
.word 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x009B0101, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000006, 0x00A90001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00A90004, 0x00A90001, 0x00000010, 0x00000027, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024207C_ABD30C
.word 0x00000043, 0x00000003, EnableNpcAI, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000006, 0x00A90001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000007, 0x009B0101, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x009B0104, 0x009B0101, 0x00000010, 0x00000028, 0x00000043, 0x00000003, EnableNpcAI, 0x00000006, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242108_ABD398
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x009A0004, 0x009A0001, 0x00000000, 0x00000030, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242138_ABD3C8
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870004, 0x00870001, 0x00000010, 0x0000002E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242168_ABD3F8
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00870204, 0x00870201, 0x00000010, 0x0000002F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242198_ABD428
.word 0x00000043, 0x00000004, SetNpcCollisionSize, 0xFFFFFFFF, 0x0000002E, 0x0000001A, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000005, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000244, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000014, 0x00000000, 0x00000140, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241DD8_ABD068, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242264_ABD4F4
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000005, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x0000003C, 0x00000000, 0x00000140, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000013, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241B80_ABCE10, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241E64_ABD0F4, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802422F4_ABD584
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241EC8_ABD158, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242318_ABD5A8
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241D4C_ABCFDC, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241EF8_ABD188, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242350_ABD5E0
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241A7C_ABCD0C, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241F28_ABD1B8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242388_ABD618
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241F8C_ABD21C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802423AC_ABD63C
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241978_ABCC08, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242018_ABD2A8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802423E4_ABD674
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_8024207C_ABD30C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242408_ABD698
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242108_ABD398, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024242C_ABD6BC
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242138_ABD3C8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242450_ABD6E0
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242168_ABD3F8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242474_ABD704
.word 0x00000000, D_80241820_ABCAB0, 0x00000000, 0xC47A0000, 0x00000000, 0x00400D0D, D_80242198_ABD428, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00820000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802418F4_ABCB84, 0x43360000, 0x00000000, 0x43A00000, 0x00400D0D, D_80242264_ABD4F4, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830001, 0x00830002, 0x00830003, 0x00830003, 0x00830001, 0x00830001, 0x00830006, 0x00830006, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_8024189C_ABCB2C, 0xC37A0000, 0x00000000, 0x437A0000, 0x00000D0D, D_802422F4_ABD584, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0xFFFFFF06, 0x00000000, 0x000000FA, 0x000000FA, 0x00000000, 0x000000FA, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF8001, 0xFFFFFF06, 0x00000000, 0x000000FA, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830001, 0x00830002, 0x00830003, 0x00830003, 0x00830001, 0x00830001, 0x00830006, 0x00830006, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00830003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_802418F4_ABCB84, 0x43160000, 0x00000000, 0x00000000, 0x00000D0D, D_80242318_ABD5A8, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00830301, 0x00830302, 0x00830303, 0x00830303, 0x00830301, 0x00830301, 0x00830306, 0x00830306, 0x00830303, 0x00830303, 0x00830303, 0x00830303, 0x00830303, 0x00830303, 0x00830303, 0x00830303, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, D_802418F4_ABCB84, 0xC3960000, 0x00000000, 0x42C80000, 0x00400D0D, D_80242350_ABD5E0, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00840101, 0x00840102, 0x00840103, 0x00840103, 0x00840101, 0x00840101, 0x00840106, 0x00840106, 0x00840103, 0x00840103, 0x00840103, 0x00840103, 0x00840103, 0x00840103, 0x00840103, 0x00840103, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, D_802418F4_ABCB84, 0xC3870000, 0x00000000, 0x42AA0000, 0x00400D0D, D_80242388_ABD618, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00840201, 0x00840202, 0x00840203, 0x00840203, 0x00840201, 0x00840201, 0x00840206, 0x00840206, 0x00840203, 0x00840203, 0x00840203, 0x00840203, 0x00840203, 0x00840203, 0x00840203, 0x00840203, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, D_802418F4_ABCB84, 0x43960000, 0x00000000, 0x43160000, 0x00400D0D, D_802423AC_ABD63C, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00A90001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000007, D_802418F4_ABCB84, 0x43A50000, 0x00000000, 0x43070000, 0x00400D0D, D_802423E4_ABD674, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x009B0101, 0x009B0102, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x009B0101, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, D_8024194C_ABCBDC, 0xC2F00000, 0x42C80000, 0xC3988000, 0x00000D0D, D_80242408_ABD698, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x009A0001, 0x009A0002, 0x009A0003, 0x009A0003, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x009A0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000009, D_802418F4_ABCB84, 0x42C80000, 0x00000000, 0x43160000, 0x00400D0D, D_8024242C_ABD6BC, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00870001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, D_802418F4_ABCB84, 0xC2480000, 0x42C80000, 0xC3B68000, 0x00400D0D, D_80242450_ABD6E0, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00870201, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802439C4_ABEC54
.word 0x0000000B, D_80242474_ABD704, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
