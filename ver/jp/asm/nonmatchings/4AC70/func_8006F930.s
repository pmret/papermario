.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F930
/* 4AD30 8006F930 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AD34 8006F934 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AD38 8006F938 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AD3C 8006F93C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AD40 8006F940 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AD44 8006F944 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AD48 8006F948 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AD4C 8006F94C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AD50 8006F950 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AD54 8006F954 0C016885 */  jal       func_8005A214
/* 4AD58 8006F958 24040002 */   addiu    $a0, $zero, 2
/* 4AD5C 8006F95C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AD60 8006F960 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AD64 8006F964 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AD68 8006F968 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AD6C 8006F96C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AD70 8006F970 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AD74 8006F974 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AD78 8006F978 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AD7C 8006F97C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AD80 8006F980 3C018008 */  lui       $at, %hi(D_8007F210)
/* 4AD84 8006F984 8C21F210 */  lw        $at, %lo(D_8007F210)($at)
/* 4AD88 8006F988 00200008 */  jr        $at
/* 4AD8C 8006F98C 00000000 */   nop
