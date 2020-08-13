.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247D44
/* 13B084 80247D44 0C091CAA */  jal   func_802472A8
/* 13B088 80247D48 02E0202D */   daddu $a0, $s7, $zero
/* 13B08C 80247D4C 02C0202D */  daddu $a0, $s6, $zero
/* 13B090 80247D50 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13B094 80247D54 2450006B */  addiu $s0, $v0, 0x6b
/* 13B098 80247D58 01708021 */  addu  $s0, $t3, $s0
/* 13B09C 80247D5C 0C091CA6 */  jal   func_80247298
/* 13B0A0 80247D60 02128021 */   addu  $s0, $s0, $s2
/* 13B0A4 80247D64 0220202D */  daddu $a0, $s1, $zero
/* 13B0A8 80247D68 0200282D */  daddu $a1, $s0, $zero
/* 13B0AC 80247D6C 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13B0B0 80247D70 24420017 */  addiu $v0, $v0, 0x17
/* 13B0B4 80247D74 01421021 */  addu  $v0, $t2, $v0
/* 13B0B8 80247D78 0C051261 */  jal   set_icon_render_pos
/* 13B0BC 80247D7C 00543021 */   addu  $a2, $v0, $s4
/* 13B0C0 80247D80 8FAB0058 */  lw    $t3, 0x58($sp)
/* 13B0C4 80247D84 15600005 */  bnez  $t3, .L80247D9C
/* 13B0C8 80247D88 00000000 */   nop   
/* 13B0CC 80247D8C 0C0511F8 */  jal   func_801447E0
/* 13B0D0 80247D90 0220202D */   daddu $a0, $s1, $zero
/* 13B0D4 80247D94 08091F69 */  j     func_80247DA4
/* 13B0D8 80247D98 00000000 */   nop   

.L80247D9C:
/* 13B0DC 80247D9C 0C0511F1 */  jal   draw_icon_1
/* 13B0E0 80247DA0 0220202D */   daddu $a0, $s1, $zero
