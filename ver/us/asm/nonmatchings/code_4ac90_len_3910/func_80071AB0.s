.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071AB0
/* 4CEB0 80071AB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CEB4 80071AB4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CEB8 80071AB8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CEBC 80071ABC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CEC0 80071AC0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CEC4 80071AC4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CEC8 80071AC8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CECC 80071ACC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CED0 80071AD0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CED4 80071AD4 0C016959 */  jal       load_effect
/* 4CED8 80071AD8 2404005B */   addiu    $a0, $zero, 0x5b
/* 4CEDC 80071ADC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CEE0 80071AE0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CEE4 80071AE4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CEE8 80071AE8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CEEC 80071AEC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CEF0 80071AF0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CEF4 80071AF4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CEF8 80071AF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CEFC 80071AFC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CF00 80071B00 3C018008 */  lui       $at, %hi(gEffectTable+0x888)
/* 4CF04 80071B04 8C21FA98 */  lw        $at, %lo(gEffectTable+0x888)($at)
/* 4CF08 80071B08 00200008 */  jr        $at
/* 4CF0C 80071B0C 00000000 */   nop
