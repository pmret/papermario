.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072AB0
/* 4DEB0 80072AB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4DEB4 80072AB4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4DEB8 80072AB8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4DEBC 80072ABC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DEC0 80072AC0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DEC4 80072AC4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DEC8 80072AC8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DECC 80072ACC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DED0 80072AD0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DED4 80072AD4 0C016885 */  jal       func_8005A214
/* 4DED8 80072AD8 24040086 */   addiu    $a0, $zero, 0x86
/* 4DEDC 80072ADC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DEE0 80072AE0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DEE4 80072AE4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DEE8 80072AE8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DEEC 80072AEC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DEF0 80072AF0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DEF4 80072AF4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DEF8 80072AF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DEFC 80072AFC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DF00 80072B00 3C018008 */  lui       $at, %hi(D_8007FE70)
/* 4DF04 80072B04 8C21FE70 */  lw        $at, %lo(D_8007FE70)($at)
/* 4DF08 80072B08 00200008 */  jr        $at
/* 4DF0C 80072B0C 00000000 */   nop
