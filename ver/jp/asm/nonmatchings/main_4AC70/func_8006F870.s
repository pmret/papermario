.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F870
/* 4AC70 8006F870 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AC74 8006F874 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AC78 8006F878 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AC7C 8006F87C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AC80 8006F880 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AC84 8006F884 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AC88 8006F888 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AC8C 8006F88C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AC90 8006F890 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AC94 8006F894 0C016885 */  jal       func_8005A214
/* 4AC98 8006F898 24040000 */   addiu    $a0, $zero, 0
/* 4AC9C 8006F89C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4ACA0 8006F8A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4ACA4 8006F8A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4ACA8 8006F8A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4ACAC 8006F8AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4ACB0 8006F8B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4ACB4 8006F8B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4ACB8 8006F8B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4ACBC 8006F8BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4ACC0 8006F8C0 3C018008 */  lui       $at, %hi(D_8007F1E0)
/* 4ACC4 8006F8C4 8C21F1E0 */  lw        $at, %lo(D_8007F1E0)($at)
/* 4ACC8 8006F8C8 00200008 */  jr        $at
/* 4ACCC 8006F8CC 00000000 */   nop
