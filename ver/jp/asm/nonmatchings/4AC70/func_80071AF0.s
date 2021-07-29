.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071AF0
/* 4CEF0 80071AF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CEF4 80071AF4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CEF8 80071AF8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CEFC 80071AFC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CF00 80071B00 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CF04 80071B04 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CF08 80071B08 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CF0C 80071B0C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CF10 80071B10 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CF14 80071B14 0C016885 */  jal       func_8005A214
/* 4CF18 80071B18 2404005C */   addiu    $a0, $zero, 0x5c
/* 4CF1C 80071B1C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CF20 80071B20 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CF24 80071B24 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CF28 80071B28 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CF2C 80071B2C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CF30 80071B30 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CF34 80071B34 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CF38 80071B38 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CF3C 80071B3C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CF40 80071B40 3C018008 */  lui       $at, %hi(D_8007FA80)
/* 4CF44 80071B44 8C21FA80 */  lw        $at, %lo(D_8007FA80)($at)
/* 4CF48 80071B48 00200008 */  jr        $at
/* 4CF4C 80071B4C 00000000 */   nop
