.include "macro.inc"

.section .data

dlabel D_80245D00_9DCD20
.word 0x00000043, 0x00000007, nok_02_ItemEntityJumpToPos, 0xFD050F8A, 0xF24E0680, 0xF24A7A80, 0xF24E5680, 0x00000014, 0xF24A7E80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245D34_9DCD54
.word 0x00000043, 0x00000003, GotoMap, 0x80254610, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802EA0C4, 0x00000097, 0x00000051, 0x000000FB, 0x00000000, 0x80000000, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFA4, 0x0000000A, 0x00000002, 0xF8405DBC, 0x00000000, 0x00000043, 0x00000002, AssignScript, 0x8024B488, 0x00000013, 0x00000000, 0x0000001B, 0x00000001, 0xFFFFFFA4, 0x0000000A, 0x00000002, 0xF8405DC3, 0x00000000, 0x00000043, 0x00000002, AssignScript, D_80245D00_9DCD20, 0x00000043, 0x00000007, MakeItemEntity, 0x0000015C, 0x00000096, 0x0000006A, 0x000000FA, 0x00000011, 0xF8405DC3, 0x00000024, 0x00000002, 0xFD050F8A, 0xFE363C80, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000008, CreatePushBlockGrid, 0x00000000, 0x00000005, 0x00000005, 0x00000058, 0xFFFFFFFC, 0x000000BC, 0x00000000, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x0000000A, 0x00000002, 0xF8406312, 0x00000000, 0x0000000A, 0x00000002, 0xF840630D, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xF8406312, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x0000000A, MakeEntity, D_802EAF80, 0x0000016D, 0x00000000, 0x0000005A, 0x0000001E, 0x00000002, D_80245D34_9DCD54, 0x00000792, 0x80000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
