.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070CD0
/* 04C0D0 80070CD0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C0D4 80070CD4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C0D8 80070CD8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C0DC 80070CDC AFA60018 */  sw    $a2, 0x18($sp)
/* 04C0E0 80070CE0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C0E4 80070CE4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C0E8 80070CE8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C0EC 80070CEC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C0F0 80070CF0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C0F4 80070CF4 0C016959 */  jal   play_effect
/* 04C0F8 80070CF8 24040036 */   addiu $a0, $zero, 0x36
/* 04C0FC 80070CFC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C100 80070D00 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C104 80070D04 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C108 80070D08 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C10C 80070D0C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C110 80070D10 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C114 80070D14 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C118 80070D18 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C11C 80070D1C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C120 80070D20 3C018008 */  lui   $at, 0x8008
/* 04C124 80070D24 8C21F720 */  lw    $at, -0x8e0($at)
/* 04C128 80070D28 00200008 */  jr    $at
/* 04C12C 80070D2C 00000000 */   nop   
