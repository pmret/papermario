.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80072770
/* 04DB70 80072770 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DB74 80072774 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DB78 80072778 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DB7C 8007277C AFA60018 */  sw    $a2, 0x18($sp)
/* 04DB80 80072780 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DB84 80072784 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DB88 80072788 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DB8C 8007278C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DB90 80072790 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DB94 80072794 0C016959 */  jal   play_effect
/* 04DB98 80072798 2404007D */   addiu $a0, $zero, 0x7d
/* 04DB9C 8007279C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DBA0 800727A0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DBA4 800727A4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DBA8 800727A8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DBAC 800727AC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DBB0 800727B0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DBB4 800727B4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DBB8 800727B8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DBBC 800727BC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DBC0 800727C0 3C018008 */  lui   $at, 0x8008
/* 04DBC4 800727C4 8C21FDC8 */  lw    $at, -0x238($at)
/* 04DBC8 800727C8 00200008 */  jr    $at
/* 04DBCC 800727CC 00000000 */   nop   
