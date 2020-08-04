.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024651C
/* 13985C 8024651C 00B02821 */  addu  $a1, $a1, $s0
/* 139860 80246520 8CA5F434 */  lw    $a1, -0xbcc($a1)
/* 139864 80246524 0C0511FF */  jal   set_menu_icon_script
/* 139868 80246528 0220202D */   daddu $a0, $s1, $zero
/* 13986C 8024652C 0220202D */  daddu $a0, $s1, $zero
/* 139870 80246530 27C6004B */  addiu $a2, $fp, 0x4b
/* 139874 80246534 02158021 */  addu  $s0, $s0, $s5
/* 139878 80246538 00108080 */  sll   $s0, $s0, 2
/* 13987C 8024653C 2610008C */  addiu $s0, $s0, 0x8c
/* 139880 80246540 8FA80084 */  lw    $t0, 0x84($sp)
/* 139884 80246544 3C058025 */  lui   $a1, 0x8025
/* 139888 80246548 8CA5F47C */  lw    $a1, -0xb84($a1)
/* 13988C 8024654C 01108021 */  addu  $s0, $t0, $s0
/* 139890 80246550 0C051261 */  jal   set_icon_render_pos
/* 139894 80246554 02052821 */   addu  $a1, $s0, $a1
/* 139898 80246558 12800005 */  beqz  $s4, .L80246570
/* 13989C 8024655C 00000000 */   nop   
/* 1398A0 80246560 0C0511F8 */  jal   func_801447E0
/* 1398A4 80246564 0220202D */   daddu $a0, $s1, $zero
/* 1398A8 80246568 0809195E */  j     func_80246578
/* 1398AC 8024656C 0000A02D */   daddu $s4, $zero, $zero

.L80246570:
/* 1398B0 80246570 0C0511F1 */  jal   draw_icon_1
/* 1398B4 80246574 0220202D */   daddu $a0, $s1, $zero
