.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071B50
/* 4CF50 80071B50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CF54 80071B54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CF58 80071B58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CF5C 80071B5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CF60 80071B60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CF64 80071B64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CF68 80071B68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CF6C 80071B6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CF70 80071B70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CF74 80071B74 0C016885 */  jal       func_8005A214
/* 4CF78 80071B78 2404005D */   addiu    $a0, $zero, 0x5d
/* 4CF7C 80071B7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CF80 80071B80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CF84 80071B84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CF88 80071B88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CF8C 80071B8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CF90 80071B90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CF94 80071B94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CF98 80071B98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CF9C 80071B9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CFA0 80071BA0 3C018008 */  lui       $at, %hi(D_8007FA98)
/* 4CFA4 80071BA4 8C21FA98 */  lw        $at, %lo(D_8007FA98)($at)
/* 4CFA8 80071BA8 00200008 */  jr        $at
/* 4CFAC 80071BAC 00000000 */   nop
