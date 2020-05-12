.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "globals.inc"

play_ambient_sounds:
/* 0DDA68 80147368 3C028007 */  lui   $v0, 0x8007
/* 0DDA6C 8014736C 8C42419C */  lw    $v0, 0x419c($v0)
/* 0DDA70 80147370 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DDA74 80147374 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DDA78 80147378 3C108016 */  lui   $s0, 0x8016
/* 0DDA7C 8014737C 2610C7C0 */  addiu $s0, $s0, -0x3840
/* 0DDA80 80147380 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DDA84 80147384 8042007A */  lb    $v0, 0x7a($v0)
/* 0DDA88 80147388 14400009 */  bnez  $v0, .L801473B0
/* 0DDA8C 8014738C 0200302D */   daddu $a2, $s0, $zero
/* 0DDA90 80147390 8E040008 */  lw    $a0, 8($s0)
/* 0DDA94 80147394 0C015529 */  jal   func_800554A4
/* 0DDA98 80147398 00000000 */   nop   
/* 0DDA9C 8014739C 96030000 */  lhu   $v1, ($s0)
/* 0DDAA0 801473A0 24020001 */  addiu $v0, $zero, 1
/* 0DDAA4 801473A4 3063FFFE */  andi  $v1, $v1, 0xfffe
/* 0DDAA8 801473A8 08051CF5 */  j     .L801473D4
/* 0DDAAC 801473AC A6030000 */   sh    $v1, ($s0)

.L801473B0:
/* 0DDAB0 801473B0 8CC20008 */  lw    $v0, 8($a2)
/* 0DDAB4 801473B4 10440006 */  beq   $v0, $a0, .L801473D0
/* 0DDAB8 801473B8 24020001 */   addiu $v0, $zero, 1
/* 0DDABC 801473BC 0040182D */  daddu $v1, $v0, $zero
/* 0DDAC0 801473C0 ACC40008 */  sw    $a0, 8($a2)
/* 0DDAC4 801473C4 ACC50004 */  sw    $a1, 4($a2)
/* 0DDAC8 801473C8 08051CF5 */  j     .L801473D4
/* 0DDACC 801473CC A4C30002 */   sh    $v1, 2($a2)

.L801473D0:
/* 0DDAD0 801473D0 24020002 */  addiu $v0, $zero, 2
.L801473D4:
/* 0DDAD4 801473D4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DDAD8 801473D8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DDADC 801473DC 03E00008 */  jr    $ra
/* 0DDAE0 801473E0 27BD0018 */   addiu $sp, $sp, 0x18
