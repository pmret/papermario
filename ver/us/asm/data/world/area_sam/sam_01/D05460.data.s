.include "macro.inc"

.section .data

dlabel D_8024D8F0_D05460
.word 0x00000000

dlabel D_8024D8F4_D05464
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024D95C_D054CC
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000046, 0x00000001, D_8024D8F4_D05464, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8B, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, AddItem, 0xFE363C8A, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, AddBadge, 0xFE363C8A, 0xFE363C80, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024DA3C_D055AC
.word 0x00000024, 0x00000002, 0xFE363C8A, 0x00000147, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000002, 0x00000024, 0x00000002, 0xF840611B, 0x00000001, 0x00000046, 0x00000001, D_8024D95C_D054CC, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE30, 0x0000005F, 0x00000000, 0xFFFFFF4C, 0x0000010E, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignFlag, 0xF840611B, 0x00000043, 0x00000002, AssignScript, D_8024DA3C_D055AC, 0x00000043, 0x00000002, SetEntityCullMode, 0x00000001, 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000043, 0x00000043, 0x00000007, MakeItemEntity, 0x0000015D, 0xFFFFFEBB, 0x00000000, 0xFFFFFF10, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFD050F84, 0xFE363C80, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0x00000031, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFD050F85, 0xFE363C80, 0x00000043, 0x00000008, MakeEntity, 0x802EAB04, 0xFFFFFF92, 0x00000000, 0x00000000, 0x00000000, 0x00000005, D_80000000, 0x00000043, 0x00000002, AssignPanelFlag, 0xF840611C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
