.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802D7460
/* 0FBE10 802D7460 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FBE14 802D7464 24E2001E */  addiu $v0, $a3, 0x1e
/* 0FBE18 802D7468 44820000 */  mtc1  $v0, $f0
/* 0FBE1C 802D746C 00000000 */  nop   
/* 0FBE20 802D7470 46800020 */  cvt.s.w $f0, $f0
/* 0FBE24 802D7474 000717C2 */  srl   $v0, $a3, 0x1f
/* 0FBE28 802D7478 00E23821 */  addu  $a3, $a3, $v0
/* 0FBE2C 802D747C 00073843 */  sra   $a3, $a3, 1
/* 0FBE30 802D7480 24E7000A */  addiu $a3, $a3, 0xa
/* 0FBE34 802D7484 44861000 */  mtc1  $a2, $f2
/* 0FBE38 802D7488 44056000 */  mfc1  $a1, $f12
/* 0FBE3C 802D748C 44067000 */  mfc1  $a2, $f14
/* 0FBE40 802D7490 2402001E */  addiu $v0, $zero, 0x1e
/* 0FBE44 802D7494 AFA70018 */  sw    $a3, 0x18($sp)
/* 0FBE48 802D7498 44071000 */  mfc1  $a3, $f2
/* 0FBE4C 802D749C 24040001 */  addiu $a0, $zero, 1
/* 0FBE50 802D74A0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0FBE54 802D74A4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0FBE58 802D74A8 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0FBE5C 802D74AC 0C01C154 */  jal   func_80070550
/* 0FBE60 802D74B0 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0FBE64 802D74B4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0FBE68 802D74B8 03E00008 */  jr    $ra
/* 0FBE6C 802D74BC 27BD0028 */   addiu $sp, $sp, 0x28

