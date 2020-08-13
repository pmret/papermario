.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024BEF4
/* 13F234 8024BEF4 8FA50020 */  lw    $a1, 0x20($sp)
/* 13F238 8024BEF8 2408000A */  addiu $t0, $zero, 0xa
/* 13F23C 8024BEFC AFA80010 */  sw    $t0, 0x10($sp)
/* 13F240 8024BF00 24080001 */  addiu $t0, $zero, 1
/* 13F244 8024BF04 0C04993B */  jal   draw_string
/* 13F248 8024BF08 AFA80014 */   sw    $t0, 0x14($sp)
/* 13F24C 8024BF0C 26500004 */  addiu $s0, $s2, 4
/* 13F250 8024BF10 00108080 */  sll   $s0, $s0, 2
/* 13F254 8024BF14 3C088027 */  lui   $t0, 0x8027
/* 13F258 8024BF18 25080640 */  addiu $t0, $t0, 0x640
/* 13F25C 8024BF1C 02088021 */  addu  $s0, $s0, $t0
/* 13F260 8024BF20 8E040000 */  lw    $a0, ($s0)
/* 13F264 8024BF24 0C051308 */  jal   func_80144C20
/* 13F268 8024BF28 3C053F00 */   lui   $a1, 0x3f00
/* 13F26C 8024BF2C 03D63021 */  addu  $a2, $fp, $s6
/* 13F270 8024BF30 8FA80054 */  lw    $t0, 0x54($sp)
/* 13F274 8024BF34 8E040000 */  lw    $a0, ($s0)
/* 13F278 8024BF38 0C051261 */  jal   set_icon_render_pos
/* 13F27C 8024BF3C 2505000C */   addiu $a1, $t0, 0xc
/* 13F280 8024BF40 8E040000 */  lw    $a0, ($s0)
/* 13F284 8024BF44 0C0511F8 */  jal   func_801447E0
/* 13F288 8024BF48 00000000 */   nop   
/* 13F28C 8024BF4C 12200017 */  beqz  $s1, .L8024BFAC
/* 13F290 8024BF50 0220202D */   daddu $a0, $s1, $zero
/* 13F294 8024BF54 03D43021 */  addu  $a2, $fp, $s4
/* 13F298 8024BF58 24070001 */  addiu $a3, $zero, 1
/* 13F29C 8024BF5C 8FA80054 */  lw    $t0, 0x54($sp)
/* 13F2A0 8024BF60 240200FF */  addiu $v0, $zero, 0xff
/* 13F2A4 8024BF64 AFA20014 */  sw    $v0, 0x14($sp)
/* 13F2A8 8024BF68 24020003 */  addiu $v0, $zero, 3
/* 13F2AC 8024BF6C AFA20018 */  sw    $v0, 0x18($sp)
/* 13F2B0 8024BF70 2505007D */  addiu $a1, $t0, 0x7d
/* 13F2B4 8024BF74 2408000A */  addiu $t0, $zero, 0xa
/* 13F2B8 8024BF78 0C049DA7 */  jal   draw_number
/* 13F2BC 8024BF7C AFA80010 */   sw    $t0, 0x10($sp)
/* 13F2C0 8024BF80 1A20000A */  blez  $s1, .L8024BFAC
/* 13F2C4 8024BF84 03D73021 */   addu  $a2, $fp, $s7
/* 13F2C8 8024BF88 8FA80054 */  lw    $t0, 0x54($sp)
/* 13F2CC 8024BF8C 3C048027 */  lui   $a0, 0x8027
/* 13F2D0 8024BF90 8C840640 */  lw    $a0, 0x640($a0)
/* 13F2D4 8024BF94 0C051261 */  jal   set_icon_render_pos
/* 13F2D8 8024BF98 25050086 */   addiu $a1, $t0, 0x86
