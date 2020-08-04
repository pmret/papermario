.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80072890
/* 04DC90 80072890 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DC94 80072894 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DC98 80072898 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DC9C 8007289C AFA60018 */  sw    $a2, 0x18($sp)
/* 04DCA0 800728A0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DCA4 800728A4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DCA8 800728A8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DCAC 800728AC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DCB0 800728B0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DCB4 800728B4 0C016959 */  jal   play_effect
/* 04DCB8 800728B8 24040080 */   addiu $a0, $zero, 0x80
/* 04DCBC 800728BC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DCC0 800728C0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DCC4 800728C4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DCC8 800728C8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DCCC 800728CC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DCD0 800728D0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DCD4 800728D4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DCD8 800728D8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DCDC 800728DC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DCE0 800728E0 3C018008 */  lui   $at, 0x8008
/* 04DCE4 800728E4 8C21FE10 */  lw    $at, -0x1f0($at)
/* 04DCE8 800728E8 00200008 */  jr    $at
/* 04DCEC 800728EC 00000000 */   nop   
