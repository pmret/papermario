.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071B70
/* 4CF70 80071B70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CF74 80071B74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CF78 80071B78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CF7C 80071B7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CF80 80071B80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CF84 80071B84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CF88 80071B88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CF8C 80071B8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CF90 80071B90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CF94 80071B94 0C016959 */  jal       play_effect
/* 4CF98 80071B98 2404005D */   addiu    $a0, $zero, 0x5d
/* 4CF9C 80071B9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CFA0 80071BA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CFA4 80071BA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CFA8 80071BA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CFAC 80071BAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CFB0 80071BB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CFB4 80071BB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CFB8 80071BB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CFBC 80071BBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CFC0 80071BC0 3C018008 */  lui       $at, 0x8008
/* 4CFC4 80071BC4 8C21FAC8 */  lw        $at, -0x538($at)
/* 4CFC8 80071BC8 00200008 */  jr        $at
/* 4CFCC 80071BCC 00000000 */   nop      
