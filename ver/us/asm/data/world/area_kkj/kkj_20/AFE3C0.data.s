.include "macro.inc"

.section .data

dlabel kkj_20_VarStash
.word 0x00000000

dlabel D_80240884_AFE3C4
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000046, 0x00000001, D_80240884_AFE3C4, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8B, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, AddItem, 0xFE363C8A, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, AddBadge, 0xFE363C8A, 0xFE363C80, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802409CC_AFE50C
.word 0x00000024, 0x00000002, 0xFE363C8A, 0x00000111, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000046, 0x00000001, D_80240884_AFE3C4, 0x0000000F, 0x00000002, 0xF5DE0180, 0x0000005F, 0x00000043, 0x00000003, AddBadge, 0xFE363C8A, 0xFE363C80, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF8405D67, 0x00000001, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE30, 0x0000005F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignChestFlag, 0xF8405D67, 0x00000043, 0x00000002, AssignScript, D_802409CC_AFE50C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
