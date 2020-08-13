.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80071930
/* 04CD30 80071930 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CD34 80071934 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CD38 80071938 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CD3C 8007193C AFA60018 */  sw    $a2, 0x18($sp)
/* 04CD40 80071940 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CD44 80071944 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CD48 80071948 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CD4C 8007194C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CD50 80071950 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CD54 80071954 0C016959 */  jal   play_effect
/* 04CD58 80071958 24040057 */   addiu $a0, $zero, 0x57
/* 04CD5C 8007195C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CD60 80071960 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CD64 80071964 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CD68 80071968 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CD6C 8007196C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CD70 80071970 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CD74 80071974 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CD78 80071978 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CD7C 8007197C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CD80 80071980 3C018008 */  lui   $at, 0x8008
/* 04CD84 80071984 8C21FA38 */  lw    $at, -0x5c8($at)
/* 04CD88 80071988 00200008 */  jr    $at
/* 04CD8C 8007198C 00000000 */   nop   
