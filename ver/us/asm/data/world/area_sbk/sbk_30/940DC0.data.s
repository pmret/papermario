.include "macro.inc"

.section .data

dlabel D_80241810_940DC0
.word 0xC3ED8000, 0x00000000, 0x00000000, 0x42B40000, 0x43ED8000, 0x00000000, 0x00000000, 0x43870000, 0x00000000, 0x00000000, 0xC3ED8000, 0x43340000, 0x00000000, 0x00000000, 0x43ED8000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80241D90_941340, D_80241810_940DC0, 0x00000006, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, sbk_30_get_tattle

dlabel D_802418B0_940E60
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000005, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000017, 0x00000000, 0x00000008, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241930_940EE0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80244870, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024198C_940F3C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80244878, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419E8_940F98
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80244880, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A44_940FF4
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000003, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80244888, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241AA0_941050
.word 0x00000047, 0x00000005, D_80241930_940EE0, 0x00080000, 0x00000009, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024198C_940F3C, 0x00080000, 0x00000005, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802419E8_940F98, 0x00080000, 0x00000003, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241A44_940FF4, 0x00080000, 0x00000007, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B20_9410D0
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8405EBE, 0x00000000, 0x00000024, 0x00000002, 0xF8405EBE, 0x00000001, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFBB, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000016, 0x00000001, 0x00000003, 0x00000016, 0x00000001, 0x00000004, 0x00000002, 0x00000000, 0x00000023, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80241AA0_941050, 0x00000044, 0x00000001, EnterWalk, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241BEC_94119C
.word 0x00000043, 0x00000002, PlaySound, 0x80000060, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x000000C1, 0x00000000, 0xFFFFFF13, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x000000C1, 0x00000000, 0xFFFFFF13, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000004, sbk_30_UnkFunc27, 0x00000002, 0x00000000, 0x00000003, 0x00000043, 0x00000004, sbk_30_UnkFunc27, 0x00000001, 0xFFFFFFFF, 0x00000003, 0x00000043, 0x0000000B, sbk_30_UnkFunc26, 0x00000003, 0x0000002C, 0x00000020, 0x000000B1, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000012C, 0xF24A7B80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000004, 0x00000043, 0x00000003, GotoMap, 0x80244890, 0x00000003, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x80244890, 0x00000004, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D90_941340
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x0000000A, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFFC1, 0x00000043, 0x00000002, DisablePulseStone, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFCC, 0x00000043, 0x00000003, EnableGroup, 0x0000002C, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, D_80243DF8_9433A8, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x0000002A, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000023, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000017, 0x7FFFFE00, 0x00000043, 0x00000003, SetZoneEnabled, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_802418B0_940E60, 0x00000044, 0x00000001, D_80241B20_9410D0, 0x00000044, 0x00000001, D_802447DC_943D8C, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000005, 0x00000046, 0x00000001, D_80241BEC_94119C, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000001, sbk_30_SpawnSunEffect, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241F70_941520
.word 0x00000000, 0x00280018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00230018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241FC8_941578
.word 0x00000000, 0x002A0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel sbk_30_varStash
.word 0x00000000

dlabel D_80241FF8_9415A8
.word 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242058_941608
.word 0x00000000

dlabel D_8024205C_94160C
.word 0x00000000

dlabel D_80242060_941610
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, sbk_30_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80241174_940724, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802421A4_941754
.word 0x00000043, 0x00000002, func_802411AC_94075C, 0xFE363C80, 0x0000004E, 0x00000006, D_80242060_941610, 0x00000010, 0x00000000, btl_state_update_end_battle, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_80241120_9406D0, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802421F4_9417A4
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowConsumableChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, sbk_30_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80241174_940724, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80241248_9407F8, 0xFE363C80, 0x0000004E, 0x00000006, D_802421F4_9417A4, 0x00000010, 0x00000000, D_80244C18, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_80241120_9406D0, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242378_941928
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, sbk_30_LetterDelivery_CalcLetterPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, SetItemPos, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802423F8_9419A8
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, sbk_30_LetterDelivery_CalcLetterPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000045, 0x00000002, D_80242378_941928, 0xFE363C8A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040002, 0x00000043, 0x00000004, GetAngleBetweenNPCs, 0xFE363C89, 0xFFFFFFFC, 0xFE363C8B, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C89, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x0000000E, 0x00000002, 0xFE363C8B, 0x000000B4, 0x00000027, 0x00000002, 0xFE363C86, 0x00000014, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C86, 0xFFFFFFEC, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C87, 0x0000000A, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000014, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C8A, 0x000000B4, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040001, 0x00000043, 0x00000004, NpcFaceNpc, 0xFFFFFFFC, 0xFE363C89, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000008, 0x00000001, 0x00000005, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80241174_940724, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024271C_941CCC
.word 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, func_802411AC_94075C, 0xFE363C80, 0x0000004E, 0x00000006, D_802423F8_9419A8, 0x00000010, 0x00000000, btl_state_update_end_battle, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_80241120_9406D0, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024278C_941D3C
.word 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFBA, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, sbk_30_LetterDelivery_SaveNpcAnim, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x00000043, 0x00000003, FindKeyItem, 0xFE363C85, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000004, 0x0000000B, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFE363C82, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C82, 0xFE363C8D, 0xFE363C80, 0xFE363C8E, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C8E, 0xFE363C8F, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000A, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C80, 0xFE363C8F, 0x0000000A, 0x00000043, 0x00000007, SpeakToNpc, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000000, 0xFE363C82, 0xFE363C87, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000046, 0x00000001, D_8024271C_941CCC, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C88, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000001, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C89, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000000, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x0000000B, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000046, 0x00000001, D_80241FF8_9415A8, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C86, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, sbk_30_LetterDelivery_RestoreNpcAnim, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242A84_942034
.word 0x00000054, 0x00000000

dlabel D_80242A8C_94203C
.word 0x00000043, 0x0000000B, sbk_30_LetterDelivery_Init, 0x00000000, 0x00B60008, 0x00B60001, 0x00000054, 0x00000000, 0x000D004A, 0x000D004B, 0x000D004C, 0x000D004D, D_80242A84_942034, 0x00000046, 0x00000001, D_8024278C_941D3C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242ADC_94208C
.word 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x0000015C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000003, 0x00000046, 0x00000001, D_80241FF8_9415A8, 0x00000043, 0x00000002, AddStarPieces, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242B40_9420F0
.word 0x00000053, 0x00000000

dlabel D_80242B48_9420F8
.word 0x00000024, 0x00000002, 0xF8405E92, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0044, 0x00000024, 0x00000002, 0xFE363C80, 0x0000015C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000003, 0x00000046, 0x00000001, D_80241FF8_9415A8, 0x00000043, 0x00000002, AddStarPieces, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0045, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242BE4_942194
.word 0x00000043, 0x00000003, GetNpcAnimation, 0xFFFFFFFF, 0xFE363C89, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60001, 0x0000000A, 0x00000002, 0xF8405E8E, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8A80, 0x00000000, 0xF24F2A80, 0xF24AB680, 0xF24A5C80, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0037, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0x00000004, 0x00000024, 0x00000002, 0xF8405E8E, 0x00000001, 0x00000004, 0x00000001, 0x00000032, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E92, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0046, 0x00000004, 0x00000001, 0x00000032, 0x00000013, 0x00000000, 0x00000043, 0x00000003, HasKeyItem, 0x00000053, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x0000000A, 0x00000002, 0xF8405E91, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0043, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xF8405E91, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0040, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80242B40_9420F0, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000046, 0x00000001, D_802421A4_941754, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001B, 0x00000001, 0x00000001, 0x00000046, 0x00000001, D_80242B48_9420F8, 0x00000004, 0x00000001, 0x00000032, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0041, 0x00000024, 0x00000002, 0xFE363C80, D_80242B40_9420F0, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000046, 0x00000001, D_802421A4_941754, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001B, 0x00000001, 0x00000001, 0x00000046, 0x00000001, D_80242B48_9420F8, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0042, 0x00000004, 0x00000001, 0x00000032, 0x00000023, 0x00000000, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFFBC, 0x0000000A, 0x00000002, 0xF8405E6A, 0x00000000, 0x0000000A, 0x00000002, 0xF9718884, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0039, 0x00000024, 0x00000002, 0xF9718884, 0x00000001, 0x00000004, 0x00000001, 0x00000032, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D003A, 0x00000004, 0x00000001, 0x00000032, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E6C, 0x00000000, 0x0000000A, 0x00000002, 0xF9718885, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D003B, 0x00000024, 0x00000002, 0xF8405E93, 0x00000001, 0x00000024, 0x00000002, 0xF9718885, 0x00000001, 0x00000004, 0x00000001, 0x00000032, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D003C, 0x00000004, 0x00000001, 0x00000032, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E93, 0x00000001, 0x0000000A, 0x00000002, 0xF8405E6D, 0x00000000, 0x0000000A, 0x00000002, 0xF9718886, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D003D, 0x00000024, 0x00000002, 0xF9718886, 0x00000001, 0x00000004, 0x00000001, 0x00000032, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D003E, 0x00000004, 0x00000001, 0x00000032, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D003F, 0x00000004, 0x00000001, 0x00000032, 0x00000013, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0x000D0038, 0x00000003, 0x00000001, 0x00000032, 0x00000003, 0x00000001, 0x0000005A, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000002, 0x0000000A, 0x00000002, 0xF8405ED1, 0x00000000, 0x00000024, 0x00000002, 0xF8405ED1, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000007, SpeakToNpc, 0xFFFFFFFC, 0x00020011, 0x00020003, 0x00000000, 0xFFFFFFFF, 0x000D0047, 0x00000043, 0x00000007, SpeakToNpc, 0xFFFFFFFF, 0x00B60008, 0x00B60001, 0x00000000, 0xFFFFFFFC, 0x000D0048, 0x00000043, 0x00000007, SpeakToNpc, 0xFFFFFFFC, 0x00020011, 0x00020003, 0x00000000, 0xFFFFFFFF, 0x000D0049, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0xFE363C89, 0x00000046, 0x00000001, D_80242A8C_94203C, 0x00000046, 0x00000001, D_80242ADC_94208C, 0x0000000B, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243248_9427F8
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60001, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60004, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000061, 0xFFFFFF4D, 0x00000078, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60001, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60004, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x000000C8, 0xFFFFFF9C, 0x00000078, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024330C_9428BC
.word 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B60007, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8A80, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000091, 0xFFFFFF6F, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x0000001E, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x00000005, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802433E4_942994
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000005, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x000000D2, 0x00000000, 0xFFFFFF2E, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_8024330C_9428BC, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80242BE4_942194, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80243248_9427F8, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243498_942A48
.word 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B80004, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000032, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000008, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x00000005, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243540_942AF0
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFC1, 0x0000000A, 0x00000002, 0xF9718882, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D004E, 0x00000024, 0x00000002, 0xF9718882, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D004F, 0x00000024, 0x00000002, 0xF9718882, 0x00000000, 0x00000013, 0x00000000, 0x0000001C, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E92, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0050, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0051, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B80004, 0x00B80001, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243638_942BE8
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80243540_942AF0, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000005, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80243498_942A48, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802436B4_942C64
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFC1, 0x0000000A, 0x00000002, 0xF9718883, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0052, 0x00000024, 0x00000002, 0xF9718883, 0x00000001, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0053, 0x00000024, 0x00000002, 0xF9718883, 0x00000000, 0x00000013, 0x00000000, 0x0000001C, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E92, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0054, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x000D0055, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B80004, 0x00B80001, 0x00000000, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802437AC_942D5C
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_802436B4_942C64, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000005, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80243498_942A48, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243828_942DD8
.word 0x00000000, D_80241F70_941520, 0x43480000, 0x00000000, 0xC2C80000, 0x00002D01, D_802433E4_942994, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B60001, 0x00B60004, 0x00B60006, 0x00B60006, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00B60001, 0x00000000, 0x00000000, 0x00000000, 0x001A008B, 0x00000001, D_80241FC8_941578, 0x436E0000, 0x00000000, 0xC2E00000, 0x00002D01, D_80243638_942BE8, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000064, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B80001, 0x00B80002, 0x00B80003, 0x00B80003, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00000000, 0x00000000, 0x00000000, 0x001A008C, 0x00000002, D_80241FC8_941578, 0x432A0000, 0x00000000, 0xC33E0000, 0x00002D01, D_802437AC_942D5C, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000064, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B80001, 0x00B80002, 0x00B80003, 0x00B80003, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00B80001, 0x00000000, 0x00000000, 0x00000000, 0x001A008D

dlabel D_80243DF8_9433A8
.word 0x00000003, D_80243828_942DD8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C8F, 0xFE363C87, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_30_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0x00000001, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000153, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_30_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xFFFFFFFF, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000033, 0x00000003, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000033, 0x00000003, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8A, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000046, 0x00000001, 0xFE363C84, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244170_943720
.word 0x0000004C, 0x00000001, 0xF24A8280, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C86, 0xFE363C8F, 0xFE363C88, 0x00000043, 0x00000002, PlaySound, 0x00000165, 0x00000043, 0x00000002, PlaySound, 0x00000166, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_30_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000166, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_30_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, sbk_30_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C84, 0x00000165, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, sbk_30_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000005, TranslateModel, 0xFE363C84, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000000, 0x00000030, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000005, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000033, 0x00000003, 0xFE363C89, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8B, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8B, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000030, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000005, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x0000000F, PlayEffect, 0x00000014, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C85, 0x00000000, 0x00000046, 0x00000001, 0xFE363C85, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244774_943D24
.word 0x00000001, 0x00000037

dlabel D_8024477C_943D2C
.word 0x00000001, 0x00000036

dlabel D_80244784_943D34
.word 0x00000001, 0x00000037, 0x000000CC, 0x0000005C, 0xFFFFFF24, 0x0000000D, 0xF8405EC0, 0xFAA2B58A

dlabel D_802447A4_943D54
.word D_80244774_943D24, D_8024477C_943D2C, 0x00000000, 0x00000000, 0x00000000

dlabel D_802447B8_943D68
.word D_80244774_943D24, D_8024477C_943D2C, D_80244784_943D34, 0x00000000, 0x00000000

dlabel D_802447CC_943D7C
.word 0x43850000, 0x00000000, 0xC3510000, 0x00000000

dlabel D_802447DC_943D8C
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFCC, 0x00000024, 0x00000002, 0xFE363C80, D_802447A4_943D54, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802447B8_943D68, 0x00000013, 0x00000000, 0x00000047, 0x00000005, D_80244170_943720, 0x00001000, 0x0000001B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80244170_943720, 0x00100000, D_802447CC_943D7C, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
