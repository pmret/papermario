.include "macro.inc"

.section .data

dlabel D_802444E0_856650
.word 0x0000004D, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C85, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C86, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C87, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C88, 0x00000001, 0x00000043, 0x00000001, mac_05_UnkTexturePanFunc, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, mac_05_UnkTexturePanFunc2, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024457C_8566EC
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x0000000F, 0x00000002, 0xFE363C8C, 0x0000003C, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000008, func_8024030C_85247C, 0xFE363C8C, 0xFE363C80, 0xF24A7680, 0xF24A7E80, 0x0000001E, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ScaleModel, 0x00000063, 0x00000001, 0xFE363C80, 0x00000001, 0x00000027, 0x00000002, 0xFE363C8C, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244648_8567B8
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000258, 0xFFFFFF10, 0x00000140, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0x00000061, 0xFE363C80, 0xFFFFFFE7, 0xFFFFFFB5, 0x00000043, 0x00000006, RotateModel, 0x00000061, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFF10, 0x00000258, 0x00000140, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0x00000061, 0xFE363C80, 0xFFFFFFE7, 0xFFFFFFB5, 0x00000043, 0x00000006, RotateModel, 0x00000061, 0x000000B4, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802447B4_856924
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802527A0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244810_856980
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000003, 0x00000044, 0x00000001, ExitWalk, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000009, 0x00000043, 0x00000003, GotoMap, 0x802527A8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024487C_8569EC
.word 0x00000047, 0x00000005, D_802447B4_856924, 0x00080000, 0x00000003, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80244810_856980, 0x00000080, 0x0000000C, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802448C4_856A34
.word 0x00000043, 0x00000002, GetLoadType, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000044, 0x00000001, EnterSavePoint, 0x00000044, 0x00000001, D_8024487C_8569EC, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_8024487C_8569EC, 0x00000044, 0x00000001, EnterWalk, 0x00000016, 0x00000001, 0x00000001, 0x00000044, 0x00000001, 0x802496FC, 0x00000044, 0x00000001, D_8024487C_8569EC, 0x00000016, 0x00000001, 0x00000002, 0x00000044, 0x00000001, 0x80248878, 0x00000044, 0x00000001, D_8024487C_8569EC, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000004, SetPlayerPos, 0xFFFFFF60, 0xFFFFFFF6, 0x00000173, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0xFFFFFF60, 0xFFFFFFF6, 0x00000173, 0x00000043, 0x00000004, SetEnemyFlagBits, 0x00000000, 0x08000000, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000001, func_802D2B6C, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFF60, 0xFFFFFF24, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFFFFFFF6, 0x00000173, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0xFE363C80, 0xFFFFFFF6, 0x00000173, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00B60002, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000004, SetPlayerPos, 0xFFFFFEE8, 0xFFFFFFF6, 0x00000173, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_8024487C_8569EC, 0x00000046, 0x00000001, EnterWalk, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFFFFFF24, 0x0000000A, 0x00000174, 0x00000043, 0x00000004, SetEnemyFlagBits, 0x00000000, 0x08000000, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000001, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x00000007, 0x00000024, 0x00000002, 0xFE363C80, 0x80250948, 0x00000018, 0x00000001, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C80, 0x8025099C, 0x00000018, 0x00000001, 0x00000029, 0x00000043, 0x00000002, GetEntryID, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x0000000A, 0x00000002, 0xF8406042, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x802509F0, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x8025099C, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x80250948, 0x00000013, 0x00000000, 0x00000018, 0x00000001, 0x0000003A, 0x00000024, 0x00000002, 0xFE363C80, 0x80250948, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x80250948, 0x00000023, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0xFE363C80, 0x00000046, 0x00000001, 0x80244400, 0x00000044, 0x00000001, 0x8025194C, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000044, 0x00000001, 0x802526E0, 0x00000044, 0x00000001, 0x802441E0, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000004, 0x7FFFFE00, 0x00000044, 0x00000001, D_802448C4_856A34, 0x00000008, 0x00000001, 0x00000001, 0x00000044, 0x00000001, D_8024457C_8566EC, 0x00000043, 0x00000003, SetTexPanner, 0x00000063, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000064, 0x00000024, 0x00000002, 0xFE363C82, 0x00000064, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFBA, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFFCE, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000024, 0x00000002, 0xFE363C86, 0x00000001, 0x00000024, 0x00000002, 0xFE363C87, 0x00000001, 0x00000024, 0x00000002, 0xFE363C88, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000044, 0x00000001, D_802444E0_856650, 0x00000057, 0x00000000, 0x00000044, 0x00000001, D_80244648_8567B8, 0x00000044, 0x00000001, 0x80252748, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
