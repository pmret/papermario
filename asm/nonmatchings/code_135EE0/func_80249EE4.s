.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80249EE4
/* 13D224 80249EE4 8FA40068 */  lw    $a0, 0x68($sp)
/* 13D228 80249EE8 0C09265A */  jal   func_80249968
/* 13D22C 80249EEC 00000000 */   nop   
/* 13D230 80249EF0 02E0202D */  daddu $a0, $s7, $zero
/* 13D234 80249EF4 8FAA00AC */  lw    $t2, 0xac($sp)
/* 13D238 80249EF8 24500069 */  addiu $s0, $v0, 0x69
/* 13D23C 80249EFC 01508021 */  addu  $s0, $t2, $s0
/* 13D240 80249F00 0C092656 */  jal   func_80249958
/* 13D244 80249F04 02148021 */   addu  $s0, $s0, $s4
/* 13D248 80249F08 0220202D */  daddu $a0, $s1, $zero
/* 13D24C 80249F0C 0200282D */  daddu $a1, $s0, $zero
/* 13D250 80249F10 8FAB00B0 */  lw    $t3, 0xb0($sp)
/* 13D254 80249F14 24420017 */  addiu $v0, $v0, 0x17
/* 13D258 80249F18 01621021 */  addu  $v0, $t3, $v0
/* 13D25C 80249F1C 0C051261 */  jal   set_icon_render_pos
/* 13D260 80249F20 00553021 */   addu  $a2, $v0, $s5
/* 13D264 80249F24 8FAA0054 */  lw    $t2, 0x54($sp)
/* 13D268 80249F28 15400005 */  bnez  $t2, .L80249F40
/* 13D26C 80249F2C 00000000 */   nop   
/* 13D270 80249F30 0C0511F8 */  jal   func_801447E0
/* 13D274 80249F34 0220202D */   daddu $a0, $s1, $zero
/* 13D278 80249F38 080927D2 */  j     func_80249F48
/* 13D27C 80249F3C 00000000 */   nop   

.L80249F40:
/* 13D280 80249F40 0C0511F1 */  jal   draw_icon_1
/* 13D284 80249F44 0220202D */   daddu $a0, $s1, $zero
