.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800702B0
/* 04B6B0 800702B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B6B4 800702B4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B6B8 800702B8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B6BC 800702BC AFA60018 */  sw    $a2, 0x18($sp)
/* 04B6C0 800702C0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B6C4 800702C4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B6C8 800702C8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B6CC 800702CC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B6D0 800702D0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B6D4 800702D4 0C016959 */  jal   play_effect
/* 04B6D8 800702D8 2404001B */   addiu $a0, $zero, 0x1b
/* 04B6DC 800702DC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B6E0 800702E0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B6E4 800702E4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B6E8 800702E8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B6EC 800702EC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B6F0 800702F0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B6F4 800702F4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B6F8 800702F8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B6FC 800702FC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B700 80070300 3C018008 */  lui   $at, 0x8008
/* 04B704 80070304 8C21F498 */  lw    $at, -0xb68($at)
/* 04B708 80070308 00200008 */  jr    $at
/* 04B70C 8007030C 00000000 */   nop   
