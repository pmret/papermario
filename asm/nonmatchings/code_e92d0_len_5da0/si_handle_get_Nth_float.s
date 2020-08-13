.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_get_Nth_float
/* 0EAAFC 802C614C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EAB00 802C6150 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAB04 802C6154 0080802D */  daddu $s0, $a0, $zero
/* 0EAB08 802C6158 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EAB0C 802C615C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EAB10 802C6160 8E02000C */  lw    $v0, 0xc($s0)
/* 0EAB14 802C6164 8C450004 */  lw    $a1, 4($v0)
/* 0EAB18 802C6168 0C0B1EAF */  jal   get_variable
/* 0EAB1C 802C616C 8C510000 */   lw    $s1, ($v0)
/* 0EAB20 802C6170 0200202D */  daddu $a0, $s0, $zero
/* 0EAB24 802C6174 8C830138 */  lw    $v1, 0x138($a0)
/* 0EAB28 802C6178 00021080 */  sll   $v0, $v0, 2
/* 0EAB2C 802C617C 00431021 */  addu  $v0, $v0, $v1
/* 0EAB30 802C6180 C4420000 */  lwc1  $f2, ($v0)
/* 0EAB34 802C6184 468010A0 */  cvt.s.w $f2, $f2
/* 0EAB38 802C6188 44061000 */  mfc1  $a2, $f2
/* 0EAB3C 802C618C 0C0B2190 */  jal   set_float_variable
/* 0EAB40 802C6190 0220282D */   daddu $a1, $s1, $zero
/* 0EAB44 802C6194 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EAB48 802C6198 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAB4C 802C619C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAB50 802C61A0 24020002 */  addiu $v0, $zero, 2
/* 0EAB54 802C61A4 03E00008 */  jr    $ra
/* 0EAB58 802C61A8 27BD0020 */   addiu $sp, $sp, 0x20

