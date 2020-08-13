.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800700D0
/* 04B4D0 800700D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B4D4 800700D4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B4D8 800700D8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B4DC 800700DC AFA60018 */  sw    $a2, 0x18($sp)
/* 04B4E0 800700E0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B4E4 800700E4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B4E8 800700E8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B4EC 800700EC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B4F0 800700F0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B4F4 800700F4 0C016959 */  jal   play_effect
/* 04B4F8 800700F8 24040016 */   addiu $a0, $zero, 0x16
/* 04B4FC 800700FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B500 80070100 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B504 80070104 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B508 80070108 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B50C 8007010C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B510 80070110 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B514 80070114 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B518 80070118 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B51C 8007011C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B520 80070120 3C018008 */  lui   $at, 0x8008
/* 04B524 80070124 8C21F420 */  lw    $at, -0xbe0($at)
/* 04B528 80070128 00200008 */  jr    $at
/* 04B52C 8007012C 00000000 */   nop   
