.include "macro.inc"

.section .data

dlabel kpa_14_varStash
.word 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024196C_A58E1C
.word 0x0000001A, 0x00000000

dlabel D_80241974_A58E24
.word 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00D8, 0x000000A0, 0x00000028, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000024, 0x00000002, 0xF8406190, 0x00000001, 0x00000043, 0x00000005, kpa_14_GetEntityPosition, 0xFD050F80, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, PlaySoundAt, 0x00000269, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F80, 0x00000043, 0x00000001, kpa_14_RemovePadlock, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000047, 0x00000005, 0x80240A88, 0x00000100, 0x00000058, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8406190, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_Padlock, 0x000007CB, 0x00000028, 0xFFFFFF5E, 0x0000010E, 0x80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x0000004E, 0x00000006, D_80241974_A58E24, 0x00000100, 0x00004000, D_8024196C_A58E1C, 0x00000000, 0x00000001, 0x00000012, 0x00000000, 0x00000047, 0x00000005, 0x80240A88, 0x00000100, 0x00000058, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0x00000096, 0x0000015E, 0x0000001E, 0xFFFFFF6A, 0x00000011, 0xF8406191, 0x00000043, 0x00000007, MakeItemEntity, 0x00000082, 0x00000320, 0x0000001E, 0xFFFFFF6A, 0x00000011, 0xF8406192, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
