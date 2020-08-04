.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800525A0
/* 02D9A0 800525A0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 02D9A4 800525A4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 02D9A8 800525A8 0080982D */  daddu $s3, $a0, $zero
/* 02D9AC 800525AC AFB10014 */  sw    $s1, 0x14($sp)
/* 02D9B0 800525B0 0000882D */  daddu $s1, $zero, $zero
/* 02D9B4 800525B4 AFB20018 */  sw    $s2, 0x18($sp)
/* 02D9B8 800525B8 24121320 */  addiu $s2, $zero, 0x1320
/* 02D9BC 800525BC AFBF0020 */  sw    $ra, 0x20($sp)
/* 02D9C0 800525C0 AFB00010 */  sw    $s0, 0x10($sp)
.L800525C4:
/* 02D9C4 800525C4 02728021 */  addu  $s0, $s3, $s2
/* 02D9C8 800525C8 92020042 */  lbu   $v0, 0x42($s0)
/* 02D9CC 800525CC 50400007 */  beql  $v0, $zero, .L800525EC
/* 02D9D0 800525D0 26310001 */   addiu $s1, $s1, 1
/* 02D9D4 800525D4 0C015BBA */  jal   func_80056EE8
/* 02D9D8 800525D8 322400FF */   andi  $a0, $s1, 0xff
/* 02D9DC 800525DC A2000042 */  sb    $zero, 0x42($s0)
/* 02D9E0 800525E0 AE00001C */  sw    $zero, 0x1c($s0)
/* 02D9E4 800525E4 A2000045 */  sb    $zero, 0x45($s0)
/* 02D9E8 800525E8 26310001 */  addiu $s1, $s1, 1
.L800525EC:
/* 02D9EC 800525EC 2A220018 */  slti  $v0, $s1, 0x18
/* 02D9F0 800525F0 1440FFF4 */  bnez  $v0, .L800525C4
/* 02D9F4 800525F4 26520048 */   addiu $s2, $s2, 0x48
/* 02D9F8 800525F8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 02D9FC 800525FC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 02DA00 80052600 8FB20018 */  lw    $s2, 0x18($sp)
/* 02DA04 80052604 8FB10014 */  lw    $s1, 0x14($sp)
/* 02DA08 80052608 8FB00010 */  lw    $s0, 0x10($sp)
/* 02DA0C 8005260C 03E00008 */  jr    $ra
/* 02DA10 80052610 27BD0028 */   addiu $sp, $sp, 0x28

