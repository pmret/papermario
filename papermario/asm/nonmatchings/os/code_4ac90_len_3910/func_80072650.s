.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80072650
/* 04DA50 80072650 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DA54 80072654 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DA58 80072658 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DA5C 8007265C AFA60018 */  sw    $a2, 0x18($sp)
/* 04DA60 80072660 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DA64 80072664 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DA68 80072668 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DA6C 8007266C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DA70 80072670 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DA74 80072674 0C016959 */  jal   play_effect
/* 04DA78 80072678 2404007A */   addiu $a0, $zero, 0x7a
/* 04DA7C 8007267C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DA80 80072680 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DA84 80072684 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DA88 80072688 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DA8C 8007268C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DA90 80072690 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DA94 80072694 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DA98 80072698 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DA9C 8007269C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DAA0 800726A0 3C018008 */  lui   $at, 0x8008
/* 04DAA4 800726A4 8C21FD80 */  lw    $at, -0x280($at)
/* 04DAA8 800726A8 00200008 */  jr    $at
/* 04DAAC 800726AC 00000000 */   nop   
