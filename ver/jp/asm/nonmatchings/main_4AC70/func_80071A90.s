.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071A90
/* 4CE90 80071A90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CE94 80071A94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CE98 80071A98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CE9C 80071A9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CEA0 80071AA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CEA4 80071AA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CEA8 80071AA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CEAC 80071AAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CEB0 80071AB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CEB4 80071AB4 0C016885 */  jal       func_8005A214
/* 4CEB8 80071AB8 2404005B */   addiu    $a0, $zero, 0x5b
/* 4CEBC 80071ABC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CEC0 80071AC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CEC4 80071AC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CEC8 80071AC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CECC 80071ACC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CED0 80071AD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CED4 80071AD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CED8 80071AD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CEDC 80071ADC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CEE0 80071AE0 3C018008 */  lui       $at, %hi(D_8007FA68)
/* 4CEE4 80071AE4 8C21FA68 */  lw        $at, %lo(D_8007FA68)($at)
/* 4CEE8 80071AE8 00200008 */  jr        $at
/* 4CEEC 80071AEC 00000000 */   nop
