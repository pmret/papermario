.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80033874
/* 00EC74 80033874 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00EC78 80033878 AFB00010 */  sw    $s0, 0x10($sp)
/* 00EC7C 8003387C 3C108007 */  lui   $s0, 0x8007
/* 00EC80 80033880 2610419C */  addiu $s0, $s0, 0x419c
/* 00EC84 80033884 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00EC88 80033888 8E020000 */  lw    $v0, ($s0)
/* 00EC8C 8003388C 844200B6 */  lh    $v0, 0xb6($v0)
/* 00EC90 80033890 44820000 */  mtc1  $v0, $f0
/* 00EC94 80033894 00000000 */  nop   
/* 00EC98 80033898 46800020 */  cvt.s.w $f0, $f0
/* 00EC9C 8003389C 44050000 */  mfc1  $a1, $f0
/* 00ECA0 800338A0 0C04DF62 */  jal   func_80137D88
/* 00ECA4 800338A4 0000202D */   daddu $a0, $zero, $zero
/* 00ECA8 800338A8 8E020000 */  lw    $v0, ($s0)
/* 00ECAC 800338AC 904500B9 */  lbu   $a1, 0xb9($v0)
/* 00ECB0 800338B0 904600BB */  lbu   $a2, 0xbb($v0)
/* 00ECB4 800338B4 904700BD */  lbu   $a3, 0xbd($v0)
/* 00ECB8 800338B8 0C04DF84 */  jal   func_80137E10
/* 00ECBC 800338BC 0000202D */   daddu $a0, $zero, $zero
/* 00ECC0 800338C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00ECC4 800338C4 8FB00010 */  lw    $s0, 0x10($sp)
/* 00ECC8 800338C8 03E00008 */  jr    $ra
/* 00ECCC 800338CC 27BD0018 */   addiu $sp, $sp, 0x18

