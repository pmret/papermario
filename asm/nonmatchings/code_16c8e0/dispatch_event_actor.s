.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel dispatch_event_actor
/* 1A5A40 80277160 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A5A44 80277164 AFB00010 */  sw    $s0, 0x10($sp)
/* 1A5A48 80277168 0080802D */  daddu $s0, $a0, $zero
/* 1A5A4C 8027716C AFBF001C */  sw    $ra, 0x1c($sp)
/* 1A5A50 80277170 AFB20018 */  sw    $s2, 0x18($sp)
/* 1A5A54 80277174 AFB10014 */  sw    $s1, 0x14($sp)
/* 1A5A58 80277178 8E1201D8 */  lw    $s2, 0x1d8($s0)
/* 1A5A5C 8027717C 8E0201C8 */  lw    $v0, 0x1c8($s0)
/* 1A5A60 80277180 8E1101E8 */  lw    $s1, 0x1e8($s0)
/* 1A5A64 80277184 1040000A */  beqz  $v0, .L802771B0
/* 1A5A68 80277188 0040202D */   daddu $a0, $v0, $zero
/* 1A5A6C 8027718C A20501F0 */  sb    $a1, 0x1f0($s0)
/* 1A5A70 80277190 2405000A */  addiu $a1, $zero, 0xa
/* 1A5A74 80277194 0C0B0CF8 */  jal   start_script
/* 1A5A78 80277198 24060020 */   addiu $a2, $zero, 0x20
/* 1A5A7C 8027719C AE0201D8 */  sw    $v0, 0x1d8($s0)
/* 1A5A80 802771A0 8C430144 */  lw    $v1, 0x144($v0)
/* 1A5A84 802771A4 86040192 */  lh    $a0, 0x192($s0)
/* 1A5A88 802771A8 AE0301E8 */  sw    $v1, 0x1e8($s0)
/* 1A5A8C 802771AC AC440148 */  sw    $a0, 0x148($v0)
.L802771B0:
/* 1A5A90 802771B0 8E0201D4 */  lw    $v0, 0x1d4($s0)
/* 1A5A94 802771B4 10400006 */  beqz  $v0, .L802771D0
/* 1A5A98 802771B8 00000000 */   nop   
/* 1A5A9C 802771BC 0C0B11E4 */  jal   get_script_by_index
/* 1A5AA0 802771C0 8E0401E4 */   lw    $a0, 0x1e4($s0)
/* 1A5AA4 802771C4 0C0B102B */  jal   kill_script_by_ID
/* 1A5AA8 802771C8 8E0401E4 */   lw    $a0, 0x1e4($s0)
/* 1A5AAC 802771CC AE0001D4 */  sw    $zero, 0x1d4($s0)
.L802771D0:
/* 1A5AB0 802771D0 12400003 */  beqz  $s2, .L802771E0
/* 1A5AB4 802771D4 00000000 */   nop   
/* 1A5AB8 802771D8 0C0B102B */  jal   kill_script_by_ID
/* 1A5ABC 802771DC 0220202D */   daddu $a0, $s1, $zero
.L802771E0:
/* 1A5AC0 802771E0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1A5AC4 802771E4 8FB20018 */  lw    $s2, 0x18($sp)
/* 1A5AC8 802771E8 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A5ACC 802771EC 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A5AD0 802771F0 03E00008 */  jr    $ra
/* 1A5AD4 802771F4 27BD0020 */   addiu $sp, $sp, 0x20

