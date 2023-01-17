.include "macro.inc"

.section .data

dlabel D_80241160_D7FEC0
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241170_D7FED0
.word 0x00000000, 0x00460032, D_80241160_D7FEC0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00630000

dlabel pra_31_ItemChoice_HasSelectedItem
.word 0x00000000

dlabel pra_31_ItemChoice_SelectedItemID
.word 0x00000000

dlabel D_802411A4_D7FF04
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, pra_31_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, pra_31_ItemChoice_SaveSelected, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_802402D8_D7F038, 0xFE363C80, 0x0000004E, 0x00000006, D_802411A4_D7FF04, 0x00000010, 0x00000000, D_80247CA0, 0x00000000, 0x00000001, 0x00000043, 0x00000002, pra_31_ItemChoice_WaitForSelection, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241338_D80098
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowConsumableChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, pra_31_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, pra_31_ItemChoice_SaveSelected, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80240374_D7F0D4, 0xFE363C80, 0x0000004E, 0x00000006, D_80241338_D80098, 0x00000010, 0x00000000, D_80247E68, 0x00000000, 0x00000001, 0x00000043, 0x00000002, pra_31_ItemChoice_WaitForSelection, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802414BC_D8021C
.word 0x00000043, 0x00000001, func_80240410_D7F170, 0x00000014, 0x00000001, 0xFE363C80, 0x00000021, 0x00000002, 0x0000002D, 0x00000086, 0x00000024, 0x00000002, 0xFE363C85, 0x0000005A, 0x00000024, 0x00000002, 0xFE363C86, 0x004F0000, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000005A, 0x00000021, 0x00000002, 0x00000087, 0x000000E0, 0x00000024, 0x00000002, 0xFE363C85, 0x000000B4, 0x00000024, 0x00000002, 0xFE363C86, 0x004F0001, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000010E, 0x00000021, 0x00000002, 0x000000E1, 0x0000013A, 0x00000024, 0x00000002, 0xFE363C85, 0x0000010E, 0x00000024, 0x00000002, 0xFE363C86, 0x004F0000, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000010E, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C86, 0x004F0002, 0x00000024, 0x00000002, 0xFE363C8A, 0x0000010E, 0x00000023, 0x00000000, 0x00000014, 0x00000001, 0xFE363C83, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F83, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F84, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0xFD050F85, 0x00000023, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C85, 0xFE363C80, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80240468_D7F1C8, 0x00000043, 0x00000005, MakeLerp, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000014, 0x00000001, 0xFE363C83, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFD050F86, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFD050F87, 0xFE363C80, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFD050F88, 0xFE363C80, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x000001ED, 0x00000000, 0x00000014, 0x00000001, 0xFE363C85, 0x0000001D, 0x00000001, 0x0000005A, 0x0000001D, 0x00000001, 0x0000010E, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000021C, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0xFFFFFFFF, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0xFE363C8A, 0x0000001C, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0xFE363C8A, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000168, 0x00000014, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0xFFFFFFFF, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0xFE363C86, 0x00000014, 0x00000001, 0xFE363C83, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFD050F83, 0xFE363C85, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFD050F84, 0xFE363C85, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFD050F85, 0xFE363C85, 0x00000023, 0x00000000, 0x00000043, 0x00000003, func_80240818_D7F578, 0xFE363C83, 0xFE363C85, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0xFE363C86, 0xFE363C86, 0x00000005, 0xFE363C84, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419B4_D80714
.word 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0x00120167, 0x00000046, 0x00000001, D_802414BC_D8021C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419F0_D80750
.word 0x00000024, 0x00000002, 0xFE363C83, 0x00000001, 0x00000024, 0x00000002, 0xFE363C84, 0x00120168, 0x00000046, 0x00000001, D_802414BC_D8021C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A2C_D8078C
.word 0x00000024, 0x00000002, 0xFE363C83, 0x00000002, 0x00000024, 0x00000002, 0xFE363C84, 0x00120169, 0x00000046, 0x00000001, D_802414BC_D8021C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A68_D807C8
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_802419B4_D80714, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A8C_D807EC
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_802419F0_D80750, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AB0_D80810
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241A2C_D8078C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AD4_D80834
.word 0x00000000, D_80241170_D7FED0, 0x433E0000, 0xC1200000, 0x43250000, 0x00400D09, D_80241A68_D807C8, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0003, 0x004F0003, 0x004F0003, 0x004F0000, 0x00000000, 0x00000000, 0x00000000, 0x001A010B, 0x00000001, D_80241170_D7FED0, 0x43960000, 0xC1200000, 0x42B20000, 0x00400D09, D_80241A8C_D807EC, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0003, 0x004F0003, 0x004F0003, 0x004F0000, 0x00000000, 0x00000000, 0x00000000, 0x001A010B, 0x00000002, D_80241170_D7FED0, 0x43E20000, 0xC1200000, 0x430B0000, 0x00400D09, D_80241AB0_D80810, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0000, 0x004F0003, 0x004F0003, 0x004F0003, 0x004F0000, 0x00000000, 0x00000000, 0x00000000, 0x001A010B, 0x00000003, D_80241AD4_D80834, 0x21010002, 0x00000000, 0x00000000, 0x00000000, 0x00000000
