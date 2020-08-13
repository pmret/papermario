.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80071510
/* 04C910 80071510 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C914 80071514 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C918 80071518 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C91C 8007151C AFA60018 */  sw    $a2, 0x18($sp)
/* 04C920 80071520 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C924 80071524 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C928 80071528 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C92C 8007152C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C930 80071530 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C934 80071534 0C016959 */  jal   play_effect
/* 04C938 80071538 2404004C */   addiu $a0, $zero, 0x4c
/* 04C93C 8007153C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C940 80071540 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C944 80071544 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C948 80071548 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C94C 8007154C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C950 80071550 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C954 80071554 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C958 80071558 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C95C 8007155C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C960 80071560 3C018008 */  lui   $at, 0x8008
/* 04C964 80071564 8C21F930 */  lw    $at, -0x6d0($at)
/* 04C968 80071568 00200008 */  jr    $at
/* 04C96C 8007156C 00000000 */   nop   
