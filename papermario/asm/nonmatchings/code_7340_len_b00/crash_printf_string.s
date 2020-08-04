.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel crash_printf_string
/* 007608 8002C208 AFA60008 */  sw    $a2, 8($sp)
/* 00760C 8002C20C AFA7000C */  sw    $a3, 0xc($sp)
/* 007610 8002C210 27BDFED0 */  addiu $sp, $sp, -0x130
/* 007614 8002C214 AFB20118 */  sw    $s2, 0x118($sp)
/* 007618 8002C218 0080902D */  daddu $s2, $a0, $zero
/* 00761C 8002C21C AFB50124 */  sw    $s5, 0x124($sp)
/* 007620 8002C220 00A0A82D */  daddu $s5, $a1, $zero
/* 007624 8002C224 3C048003 */  lui   $a0, 0x8003
/* 007628 8002C228 2484C1D4 */  addiu $a0, $a0, -0x3e2c
/* 00762C 8002C22C 27A50010 */  addiu $a1, $sp, 0x10
/* 007630 8002C230 27A7013C */  addiu $a3, $sp, 0x13c
/* 007634 8002C234 AFBF0128 */  sw    $ra, 0x128($sp)
/* 007638 8002C238 AFB40120 */  sw    $s4, 0x120($sp)
/* 00763C 8002C23C AFB3011C */  sw    $s3, 0x11c($sp)
/* 007640 8002C240 AFB10114 */  sw    $s1, 0x114($sp)
/* 007644 8002C244 0C0192A8 */  jal   _Printf
/* 007648 8002C248 AFB00110 */   sw    $s0, 0x110($sp)
/* 00764C 8002C24C 0040802D */  daddu $s0, $v0, $zero
/* 007650 8002C250 1A000010 */  blez  $s0, .L8002C294
/* 007654 8002C254 27B10010 */   addiu $s1, $sp, 0x10
/* 007658 8002C258 3C148007 */  lui   $s4, 0x8007
/* 00765C 8002C25C 26947210 */  addiu $s4, $s4, 0x7210
/* 007660 8002C260 241300FF */  addiu $s3, $zero, 0xff
.L8002C264:
/* 007664 8002C264 92220000 */  lbu   $v0, ($s1)
/* 007668 8002C268 3042007F */  andi  $v0, $v0, 0x7f
/* 00766C 8002C26C 00541021 */  addu  $v0, $v0, $s4
/* 007670 8002C270 90460000 */  lbu   $a2, ($v0)
/* 007674 8002C274 10D30003 */  beq   $a2, $s3, .L8002C284
/* 007678 8002C278 0240202D */   daddu $a0, $s2, $zero
/* 00767C 8002C27C 0C00B015 */  jal   func_8002C054
/* 007680 8002C280 02A0282D */   daddu $a1, $s5, $zero
.L8002C284:
/* 007684 8002C284 26520006 */  addiu $s2, $s2, 6
/* 007688 8002C288 2610FFFF */  addiu $s0, $s0, -1
/* 00768C 8002C28C 1E00FFF5 */  bgtz  $s0, .L8002C264
/* 007690 8002C290 26310001 */   addiu $s1, $s1, 1
.L8002C294:
/* 007694 8002C294 8FBF0128 */  lw    $ra, 0x128($sp)
/* 007698 8002C298 8FB50124 */  lw    $s5, 0x124($sp)
/* 00769C 8002C29C 8FB40120 */  lw    $s4, 0x120($sp)
/* 0076A0 8002C2A0 8FB3011C */  lw    $s3, 0x11c($sp)
/* 0076A4 8002C2A4 8FB20118 */  lw    $s2, 0x118($sp)
/* 0076A8 8002C2A8 8FB10114 */  lw    $s1, 0x114($sp)
/* 0076AC 8002C2AC 8FB00110 */  lw    $s0, 0x110($sp)
/* 0076B0 8002C2B0 03E00008 */  jr    $ra
/* 0076B4 8002C2B4 27BD0130 */   addiu $sp, $sp, 0x130

