.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072930
/* 4DD30 80072930 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DD34 80072934 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DD38 80072938 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DD3C 8007293C AFA60018 */  sw        $a2, 0x18($sp)
/* 4DD40 80072940 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DD44 80072944 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DD48 80072948 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DD4C 8007294C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DD50 80072950 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DD54 80072954 0C016885 */  jal       func_8005A214
/* 4DD58 80072958 24040082 */   addiu    $a0, $zero, 0x82
/* 4DD5C 8007295C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DD60 80072960 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DD64 80072964 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DD68 80072968 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DD6C 8007296C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DD70 80072970 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DD74 80072974 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DD78 80072978 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DD7C 8007297C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DD80 80072980 3C018008 */  lui       $at, %hi(D_8007FE10)
/* 4DD84 80072984 8C21FE10 */  lw        $at, %lo(D_8007FE10)($at)
/* 4DD88 80072988 00200008 */  jr        $at
/* 4DD8C 8007298C 00000000 */   nop
