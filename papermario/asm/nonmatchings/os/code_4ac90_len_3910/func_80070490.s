.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070490
/* 04B890 80070490 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B894 80070494 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B898 80070498 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B89C 8007049C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B8A0 800704A0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B8A4 800704A4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B8A8 800704A8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B8AC 800704AC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B8B0 800704B0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B8B4 800704B4 0C016959 */  jal   play_effect
/* 04B8B8 800704B8 24040020 */   addiu $a0, $zero, 0x20
/* 04B8BC 800704BC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B8C0 800704C0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B8C4 800704C4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B8C8 800704C8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B8CC 800704CC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B8D0 800704D0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B8D4 800704D4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B8D8 800704D8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B8DC 800704DC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B8E0 800704E0 3C018008 */  lui   $at, 0x8008
/* 04B8E4 800704E4 8C21F510 */  lw    $at, -0xaf0($at)
/* 04B8E8 800704E8 00200008 */  jr    $at
/* 04B8EC 800704EC 00000000 */   nop   
