.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel playFX_41
/* 4C4F0 800710F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C4F4 800710F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C4F8 800710F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C4FC 800710FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4C500 80071100 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C504 80071104 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C508 80071108 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C50C 8007110C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C510 80071110 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C514 80071114 0C016959 */  jal       load_effect
/* 4C518 80071118 24040041 */   addiu    $a0, $zero, 0x41
/* 4C51C 8007111C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C520 80071120 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C524 80071124 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C528 80071128 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C52C 8007112C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C530 80071130 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C534 80071134 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C538 80071138 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C53C 8007113C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C540 80071140 3C018008 */  lui       $at, %hi(gEffectTable+0x618)
/* 4C544 80071144 8C21F828 */  lw        $at, %lo(gEffectTable+0x618)($at)
/* 4C548 80071148 00200008 */  jr        $at
/* 4C54C 8007114C 00000000 */   nop
