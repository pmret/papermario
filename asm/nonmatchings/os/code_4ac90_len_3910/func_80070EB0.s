.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070EB0
/* 04C2B0 80070EB0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C2B4 80070EB4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C2B8 80070EB8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C2BC 80070EBC AFA60018 */  sw    $a2, 0x18($sp)
/* 04C2C0 80070EC0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C2C4 80070EC4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C2C8 80070EC8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C2CC 80070ECC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C2D0 80070ED0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C2D4 80070ED4 0C016959 */  jal   play_effect
/* 04C2D8 80070ED8 2404003B */   addiu $a0, $zero, 0x3b
/* 04C2DC 80070EDC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C2E0 80070EE0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C2E4 80070EE4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C2E8 80070EE8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C2EC 80070EEC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C2F0 80070EF0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C2F4 80070EF4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C2F8 80070EF8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C2FC 80070EFC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C300 80070F00 3C018008 */  lui   $at, 0x8008
/* 04C304 80070F04 8C21F798 */  lw    $at, -0x868($at)
/* 04C308 80070F08 00200008 */  jr    $at
/* 04C30C 80070F0C 00000000 */   nop   
