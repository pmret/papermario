.include "macro.inc"

.section .data

dlabel D_80242050_B728B0
.word 0x00000000, 0x001C0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024207C_B728DC
.word 0x00000024, 0x00000002, 0xF9718882, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000001F0, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x0000000A, 0x00000002, 0xF9718882, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802420F4_B72954
.word 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, jan_11_GetFloorCollider, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x0000000A, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_802407DC_B7103C, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x0000000C, 0x00000002, 0xFE363C82, 0x00000055, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x0000000C, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFCE, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000013, 0x00000000, 0x00000043, 0x00000002, SetPlayerSpeed, 0xF24A7E80, 0x00000043, 0x00000004, PlayerMoveTo, 0xFE363C81, 0xFE363C83, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFFFFFFFF, 0x00000000, 0x00000028, 0x00000002, 0xFE363C84, 0xFE363C81, 0x0000002A, 0x00000002, 0xFE363C84, 0x00000002, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8A80, 0xFE363C84, 0x0000015E, 0xF24ABE80, 0xF24A5E80, 0x00000024, 0x00000002, 0xF9718882, 0x00000001, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000057, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x0097000B, 0x0097000A, 0x00000000, 0x001000AE, 0x00000043, 0x00000005, EndSpeech, 0xFFFFFFFF, 0x00970004, 0x00970001, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000300, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00970003, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8E80, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFFFFFF9C, 0x00000032, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xF8406052, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0xF840604E, 0x00000027, 0x00000002, 0xFE363C80, 0xF840604F, 0x00000027, 0x00000002, 0xFE363C80, 0xF8406050, 0x00000027, 0x00000002, 0xFE363C80, 0xF8406051, 0x00000027, 0x00000002, 0xFE363C80, 0xF8406052, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000005, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x0000004E, 0x00000000, 0x00000008, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000010, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010032, 0x00000008, 0x00000001, 0x00000078, 0x00000044, 0x00000001, 0x80240850, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000012, 0x00000000, 0x00000008, 0x00000001, 0x00000023, 0x00000013, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242544_B72DA4
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00970006, 0x00970006, 0x00000000, 0x001000AD, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242574_B72DD4
.word 0x0000000A, 0x00000002, 0xF5DE0180, 0x0000000F, 0x00000044, 0x00000001, D_8024207C_B728DC, 0x0000000A, 0x00000002, 0xF8406052, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00970006, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000084, 0x00000055, 0x0000000B, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802420F4_B72954, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242544_B72DA4, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242630_B72E90
.word 0x00000000, D_80242050_B728B0, 0xC3E10000, 0x00000000, 0xC3200000, 0x0040090D, D_80242574_B72DD4, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00970001, 0x00970002, 0x00970003, 0x00970003, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00970001, 0x00000000, 0x00000000, 0x00000000, 0x001A00C3, 0x00000001, D_80242630_B72E90, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
