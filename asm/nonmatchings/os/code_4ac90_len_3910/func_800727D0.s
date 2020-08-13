.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800727D0
/* 04DBD0 800727D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DBD4 800727D4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DBD8 800727D8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DBDC 800727DC AFA60018 */  sw    $a2, 0x18($sp)
/* 04DBE0 800727E0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DBE4 800727E4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DBE8 800727E8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DBEC 800727EC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DBF0 800727F0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DBF4 800727F4 0C016959 */  jal   play_effect
/* 04DBF8 800727F8 2404007E */   addiu $a0, $zero, 0x7e
/* 04DBFC 800727FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DC00 80072800 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DC04 80072804 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DC08 80072808 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DC0C 8007280C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DC10 80072810 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DC14 80072814 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DC18 80072818 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DC1C 8007281C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DC20 80072820 3C018008 */  lui   $at, 0x8008
/* 04DC24 80072824 8C21FDE0 */  lw    $at, -0x220($at)
/* 04DC28 80072828 00200008 */  jr    $at
/* 04DC2C 8007282C 00000000 */   nop   
