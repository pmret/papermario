.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800729B0
/* 04DDB0 800729B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DDB4 800729B4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DDB8 800729B8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DDBC 800729BC AFA60018 */  sw    $a2, 0x18($sp)
/* 04DDC0 800729C0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DDC4 800729C4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DDC8 800729C8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DDCC 800729CC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DDD0 800729D0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DDD4 800729D4 0C016959 */  jal   play_effect
/* 04DDD8 800729D8 24040083 */   addiu $a0, $zero, 0x83
/* 04DDDC 800729DC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DDE0 800729E0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DDE4 800729E4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DDE8 800729E8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DDEC 800729EC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DDF0 800729F0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DDF4 800729F4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DDF8 800729F8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DDFC 800729FC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DE00 80072A00 3C018008 */  lui   $at, 0x8008
/* 04DE04 80072A04 8C21FE58 */  lw    $at, -0x1a8($at)
/* 04DE08 80072A08 00200008 */  jr    $at
/* 04DE0C 80072A0C 00000000 */   nop   
