.include "macro.inc"

.section .data

dlabel D_80240A10_8778F0
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000002, HidePlayerShadow, 0x00000001, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFC, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000043, 0x00000001, tik_06_Pipe_GetEntryPos, 0x00000028, 0x00000002, 0xFE363C82, 0x00000028, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000003, InterpPlayerYaw, 0xFE363C84, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x00000163, 0x00000043, 0x00000002, func_802D286C, 0x00000100, 0x00000043, 0x00000007, func_802D2520, 0x00010000, 0x00000005, 0x00000002, 0x00000001, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000005, 0x00000001, 0x00000028, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C82, 0x00000003, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000002, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFC, 0x00000001, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000007, func_802D2520, 0x00010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, HidePlayerShadow, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, tik_06_Pipe_GetCurrentFloor, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, 0xFE363C8A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D64_877C44
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, HidePlayerShadow, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0xFE363C8B, 0x7FFFFE00, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000043, 0x00000001, tik_06_Pipe_GetEntryPos, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C82, 0x00000002, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000003, InterpPlayerYaw, 0xFE363C84, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C84, 0x0000005A, 0x00000027, 0x00000002, 0xFE363C85, 0x00000028, 0x00000012, 0x00000000, 0x00000028, 0x00000002, 0xFE363C85, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFC, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0xFE363C80, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, PlaySound, 0x00000163, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000019, 0x00000043, 0x00000002, HidePlayerShadow, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000002, func_802D286C, 0x00000900, 0x00000043, 0x00000007, func_802D2520, 0x00010002, 0x00000005, 0x00000003, 0x00000001, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000028, 0x00000043, 0x00000002, tik_06_Pipe_GetPointAheadOfPlayer, 0xF24A7E80, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C82, 0x00000003, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFC, 0x00000001, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000007, func_802D2520, 0x00010002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0xFE363C8B, 0x7FFFFE00, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000044, 0x00000001, 0xFE363C8A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241154_878034
.word 0x00000043, 0x00000001, tik_06_Pipe_AwaitDownInput, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C81, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000006, 0x00000002, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000001, InterruptUsePartner, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_80241230_878110, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241230_878110
.word 0x00000043, 0x00000001, tik_06_Pipe_SetAnimFlag, 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, HidePlayerShadow, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000043, 0x00000001, tik_06_Pipe_GetEntryPos, 0x00000043, 0x00000004, PlayerMoveTo, 0xFE363C81, 0xFE363C83, 0x00000003, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000043, 0x00000001, tik_06_Pipe_GetEntryPos, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000003, SetPlayerFlagBits, 0x00200000, 0x00000001, 0x00000043, 0x00000001, tik_06_Pipe_GetCameraYaw, 0x00000043, 0x00000003, InterpPlayerYaw, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000003, SetPlayerFlagBits, 0x00200000, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x00000163, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000004, 0x00000005, 0x00000001, 0x00000028, 0x00000028, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000002, func_802D286C, 0x00000800, 0x00000043, 0x00000007, func_802D2520, 0x00010002, 0x00000005, 0x00000002, 0x00000001, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000019, 0x00000046, 0x00000001, 0xFE363C8C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024140C_8782EC
.word 0x00000043, 0x00000002, IsPlayerOnValidFloor, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x0000001A, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C81, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000006, 0x00000002, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000001, InterruptUsePartner, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000013, 0x00000000, 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000001, tik_06_Pipe_SetAnimFlag, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0xFE363C8B, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000043, 0x00000001, tik_06_Pipe_GetEntryPos, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C86, 0x00000002, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C88, 0x000000B4, 0x0000000F, 0x00000002, 0xFE363C84, 0x00000168, 0x00000028, 0x00000002, 0xFE363C84, 0x00000168, 0x00000013, 0x00000000, 0x00000043, 0x00000003, InterpPlayerYaw, 0xFE363C88, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, PlaySound, 0x00000163, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C86, 0xFE363C87, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010000, 0x00000043, 0x00000002, func_802D286C, 0x00000800, 0x00000043, 0x00000007, func_802D2520, 0x00010000, 0x00000005, 0x00000003, 0x00000001, 0x00000001, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000002, HidePlayerShadow, 0x00000001, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000005, 0x00000001, 0x00000028, 0x00000043, 0x00000002, tik_06_Pipe_GetPointAheadOfPlayer, 0xF24A7E80, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000019, 0x00000046, 0x00000001, 0xFE363C8C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241740_878620
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, tik_06_UpdateTexturePanSmooth, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, tik_06_UpdateTexturePanStepped, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802417DC_8786BC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80242CD0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241838_878718
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80242CD8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241894_878774
.word 0x00000043, 0x00000003, GotoMap, 0x80242CE0, 0x00000004, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802418C4_8787A4
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000003, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000019, 0x00000024, 0x00000002, 0xFE363C8C, D_80241894_878774, 0x00000046, 0x00000001, D_8024140C_8782EC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024191C_8787FC
.word 0x00000043, 0x00000003, GotoMap, 0x80242CE8, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024194C_87882C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000016, 0x00000024, 0x00000002, 0xFE363C8C, D_8024191C_8787FC, 0x00000046, 0x00000001, D_80241154_878034, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419A4_878884
.word 0x00000047, 0x00000005, D_802417DC_8786BC, 0x00080000, 0x0000000B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241838_878718, 0x00080000, 0x00000011, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802418C4_8787A4, 0x00000040, 0x00000019, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024194C_87882C, 0x00000080, 0x00000016, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A24_878904
.word 0x00000043, 0x00000002, GetLoadType, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000044, 0x00000001, EnterSavePoint, 0x00000044, 0x00000001, D_802419A4_878884, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8A, D_802419A4_878884, 0x00000044, 0x00000001, D_80240A10_8778F0, 0x00000016, 0x00000001, 0x00000003, 0x00000024, 0x00000002, 0xFE363C8A, D_802419A4_878884, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000019, 0x00000044, 0x00000001, D_80240D64_877C44, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802419A4_878884, 0x00000044, 0x00000001, EnterWalk, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000002, 0x00000043, 0x00000002, SetSpriteShading, 0x00000005, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF840632D, 0x00000001, 0x00000046, 0x00000001, 0x80242B38, 0x00000044, 0x00000001, 0x802409E0, 0x00000043, 0x00000002, PlaySound, 0x8000002F, 0x00000043, 0x00000006, PlaySoundAtF, 0x80000030, 0x00000001, 0xFFFFFFAB, 0xFFFFFF4C, 0x00000078, 0x00000043, 0x00000006, PlaySoundAtF, 0x80000031, 0x00000001, 0xFFFFFFE7, 0xFFFFFF74, 0xFFFFFF7E, 0x00000043, 0x00000006, PlaySoundAtF, 0x80000032, 0x00000001, 0xFFFFFFDD, 0xFFFFFF4C, 0x00000082, 0x00000044, 0x00000001, 0x80242948, 0x00000043, 0x00000003, EnableTexPanning, 0x0000000D, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000032, 0x00000024, 0x00000002, 0xFE363C82, 0x000000C8, 0x00000024, 0x00000002, 0xFE363C83, 0x0000006E, 0x00000024, 0x00000002, 0xFE363C84, 0x000001F4, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80241740_878620, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x0000000F, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFF38, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFF9C, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE0C, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80241740_878620, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x00000010, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFF06, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFF9C, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFE0C, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80241740_878620, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x00000011, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000013, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000015, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000004, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFFCE, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFC7C, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFBA, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFB50, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_80241740_878620, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xF8405C87, 0x00000000, 0x00000044, 0x00000001, D_80241A24_878904, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
