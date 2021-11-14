.include "macro.inc"

.section .data

dlabel D_802405C0_B7DEE0
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00170013, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240618_B7DF38
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240664_B7DF84
.word 0x00000008, 0x00000001, 0x0000002D, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80240694_B7DFB4, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240694_B7DFB4
.word 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00002099, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00430000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, func_80240000_B7D920, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00430001, 0x00000056, 0x00000000, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, 0x00000000, 0x00000044, 0x00000001, D_80240664_B7DF84, 0x00000008, 0x00000001, 0x0000002D, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00430000, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802407A0_B7E0C0
.word 0x00000000, 0x0014001C, D_80240618_B7DF38, D_80240694_B7DFB4, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_802407CC_B7E0EC
.word 0x00000058, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000005, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00360001, 0x00000008, 0x00000001, 0x0000000F, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00360005, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00360006, 0x00000008, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000005, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360001, 0x00000008, 0x00000001, 0x0000000F, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360005, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360006, 0x00000008, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000059, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000005, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360001, 0x00000008, 0x00000001, 0x0000000F, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360005, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360006, 0x00000008, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802409F4_B7E314
.word 0x0000000A, 0x00000002, 0xF8406079, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000022, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001000BB, 0x00000140, 0x0000003C, 0x00000024, 0x00000002, 0xF8406079, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000013, 0x00000000, 0x00000045, 0x00000002, D_802407CC_B7E0EC, 0xFE363C89, 0x00000043, 0x00000004, AwaitPlayerApproach, 0x00000190, 0xFFFFFFF6, 0x00000087, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000049, 0x00000001, 0xFE363C89, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00360001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360001, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360001, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360004, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C80, 0x00000018, 0x00000043, 0x00000005, SetNpcRotation, 0x00000002, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000002, 0x000003B1, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360001, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00360004, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C80, 0x00000018, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000020B1, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00360001, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360004, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C80, 0x00000018, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000001, 0x000020B1, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360001, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00360004, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360004, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360004, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000C, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000002, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000020B2, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000C, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000002, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000020B2, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000C, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000002, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000020B2, 0x00000000, 0x00000005, 0x00000001, 0x00000003, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000020B3, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00360005, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360005, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360005, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00360006, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00360006, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00360006, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000003B2, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, StartBossBattle, 0x00000003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241080_B7E9A0
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000013, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410E8_B7EA08
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000013, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802409F4_B7E314, 0x00000043, 0x00000003, BindNpcHit, 0xFFFFFFFF, D_80241080_B7E9A0, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241194_B7EAB4
.word 0x00000000, D_802405C0_B7DEE0, 0x43B68000, 0x00000000, 0xC2340000, 0x00040800, D_802410E8_B7EA08, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0003, 0x33322666, 0x33320003, 0x33323FFF, 0x33320003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802405C0_B7DEE0, 0x43A28000, 0x00000000, 0x00000000, 0x00040800, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0003, 0x33322666, 0x33320003, 0x33323FFF, 0x33320003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_802405C0_B7DEE0, 0x43BB8000, 0x00000000, 0x42340000, 0x00040800, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0003, 0x33322666, 0x33320003, 0x33323FFF, 0x33320003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00360001, 0x00360002, 0x00360003, 0x00360003, 0x00360001, 0x00360001, 0x0036000E, 0x0036000E, 0x00360018, 0x00360017, 0x00360005, 0x00360006, 0x00360007, 0x00360001, 0x00360001, 0x00360001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241764_B7F084
.word 0x00000003, D_802407A0_B7E0C0, 0xC3370000, 0x00000000, 0x423C0000, 0x00408905, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00000000, 0x00000000, 0x00000000, 0x001A00D3

dlabel D_80241954_B7F274
.word 0x00000004, D_802407A0_B7E0C0, 0xC2F80000, 0x00000000, 0x41A00000, 0x00408905, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00430000, 0x00000000, 0x00000000, 0x00000000, 0x001A00D3, 0x00000003, D_80241194_B7EAB4, 0x15030005, 0x00000001, D_80241764_B7F084, 0x00000000, 0x00000001, D_80241954_B7F274, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
